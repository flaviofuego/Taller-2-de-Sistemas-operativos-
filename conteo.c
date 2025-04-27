// conteo.c
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Uso: %s numero\n", argv[0]);
        exit(1);
    }
    
    int n = atoi(argv[1]);
    if (n <= 10 || n >= 18) {
        printf("El número debe estar entre 11 y 17\n");
        exit(1);
    }
    
    pid_t pid = fork();
    int status;
    
    if (pid < 0) {
        // Error al crear el proceso
        perror("Error en fork");
        exit(1);
    } else if (pid == 0) {
        // Proceso hijo
        printf("Proceso hijo y pid %d\n", getpid());
        for (int i = 0; i <= 8; i++) {
            printf("%d\n", i);
        }
        exit(0); // El hijo termina con status 0
    } else {
        // Proceso padre
        printf("Proceso padre y pid %d\n", getpid());
        for (int i = 9; i <= 19; i++) {
            printf("%d\n", i);
            if (i == n) {
                // Esperar al hijo cuando llegue al número n
                wait(&status);
                if (WIFEXITED(status)) {
                    printf("Hijo terminado y valor status %d\n", WEXITSTATUS(status));
                }
            }
        }
    }
    
    return 0;
}