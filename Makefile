CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++17
LDFLAGS =

# Generar sources.cmake antes de compilar
scripts/sources.cmake: scripts/sourcesGenerator.py
	python3 scripts/sourcesGenerator.py

# Obtener lista de fuentes desde el script
SOURCES := $(shell python3 scripts/sourcesGenerator.py)
OBJECTS := $(SOURCES:src/%.cpp=obj/%.o)
EXECUTABLE = Homeros

# Detección de sistema
ifeq ($(OS),Windows_NT)
    LDFLAGS += -lws2_32
else
    UNAME_S := $(shell uname -s)
    ifeq ($(UNAME_S),Linux)
        LDFLAGS += -lpthread
    endif
endif

# Asegurar que obj/ exista
$(shell mkdir -p obj)

all: scripts/sources.cmake $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $@ $^ $(LDFLAGS)

obj/%.o: src/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJECTS) $(EXECUTABLE) scripts/sources.cmake
