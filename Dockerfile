# Usar una imagen base de Ubuntu
FROM ubuntu:20.04

# Evitar interacciones durante la instalación de paquetes
ENV DEBIAN_FRONTEND=noninteractive

# Actualizar repositorios e instalar herramientas necesarias
RUN apt-get update && apt-get install -y \
    build-essential \
    procps \
    gcc \
    make \
    vim \
    nano \
    && rm -rf /var/lib/apt/lists/*

# Establecer el directorio de trabajo
WORKDIR /app

# Copiar los archivos del proyecto al contenedor
COPY . /app

# Compilar los programas de ejemplo proporcionados
RUN gcc -o waitsimple1 waitsimple1.c || echo "Archivo no encontrado"
RUN gcc -o waitsimple2 waitsimple2.c || echo "Archivo no encontrado"
RUN gcc -o waitsimple4 waitsimple4.c || echo "Archivo no encontrado"

# Comandos para compilar los programas que crearás para el taller
# Los condicionamos con || echo para que no falle la construcción si aún no existen
RUN gcc -o conteo conteo.c || echo "conteo.c no encontrado, compilar después"
RUN gcc -o suma suma.c || echo "suma.c no encontrado, compilar después"
RUN gcc -o sumapid sumapid.c || echo "sumapid.c no encontrado, compilar después"
RUN gcc -o sumasec sumasec.c || echo "sumasec.c no encontrado, compilar después"

# Iniciar en un shell interactivo para poder probar los ejecutables
CMD ["/bin/bash"]