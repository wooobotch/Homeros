#!/usr/bin/env bash

SOURCE_DIRS=(
    "../src/"
)

OUTPUT_FILE="sources.cmake"

echo "Generando $OUTPUT_FILE..."

echo "set(SOURCES" > "$OUTPUT_FILE"

for dir in "${SOURCE_DIRS[@]}"; do
    if [ -d "$dir" ]; then
        find "$dir" -type f -name "*.cpp" | sort | while read -r file; do
            # Convertir \ a / por compatibilidad (no siempre necesario en Linux)
            file="${file//\\/\/}"
            echo "    $file" >> "$OUTPUT_FILE"
        done
    else
        echo "Directorio no encontrado: $dir"
    fi
done

echo ")" >> "$OUTPUT_FILE"

echo "$OUTPUT_FILE generado correctamente."

