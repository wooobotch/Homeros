BUILD_DIR = build

all: generate_sources cmake_build

generate_sources:
	@echo "Generando sources.cmake..."
	python3 scripts/sourcesGenerator.py

cmake_build:
	@echo "Configurando y compilando con CMake..."
	mkdir -p $(BUILD_DIR)
	cd $(BUILD_DIR) && cmake .. && make

clean:
	rm -rf $(BUILD_DIR)
	rm -f scripts/sources.cmake
	rm -f sources.cmake

.PHONY: all generate_sources cmake_build clean
