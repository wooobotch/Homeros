CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++17
LDFLAGS =

SOURCES := $(bash scripts/sourcesGenerator.sh)
OBJECTS := $(SOURCES:.cpp=.o)
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

all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $@ $^ $(LDFLAGS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJECTS) $(EXECUTABLE) scripts/sources.cmake

.PHONY: all clean
