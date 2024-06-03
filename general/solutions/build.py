#!/usr/bin/env python3
import os
import subprocess

# Ruta de la carpeta de destino
carpeta_destino = "exe"

# Crear la carpeta de destino si no existe
os.makedirs(carpeta_destino, exist_ok=True)

# Recorrer todos los archivos en la carpeta actual
for archivo in os.listdir():
    # Verificar si el archivo es un archivo C++
    if archivo.endswith(".cpp"):
        ruta_archivo = archivo
        nombre_ejecutable = os.path.splitext(archivo)[0]
        ruta_ejecutable = os.path.join(carpeta_destino, nombre_ejecutable)

        # Comandos para compilar
        compile_cmd = ["g++", ruta_archivo, "-o", ruta_ejecutable]

        try:
            # Compilar el archivo
            subprocess.run(compile_cmd, check=True)
            print(f"Compilación exitosa: {ruta_ejecutable}")
        except subprocess.CalledProcessError as e:
            print(f"Error al compilar {ruta_archivo}: {e}")
