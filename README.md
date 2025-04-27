# Taller-2-de-Sistemas-operativos-

Requisitos para correr el taller
1. Tener Docker instalad

CMD COMMANDS:
1. docker build -t taller-procesos-linux .
2. docker run -it --name taller-procesos -v ${PWD}:/app taller-procesos-linux
3. docker exec -it taller-proceso bash /// Este para abrir una terminal en el contenedor
4. ejecuta ./recompile.sh dentro del contenedor después de modificar cualquier archivo fuente.
5. Reiniciar el contenedor// docker start -i taller-procesos
