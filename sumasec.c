// sumasec.c
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Uso: %s numero_de_hijos\n", argv[0]);
        exit(1);
    }
    
    int n = atoi(argv[1]);
    if (n <= 0) {
        printf("El número de hijos debe ser positivo\n");
        exit(1);
    }
    
    pid_t pid;
    int status;
    pid_t *pids = malloc(n * sizeof(pid_t)); // Arreglo para guardar los PIDs
    
    // Crear n hijos
    for (int i = 0; i < n; i++) {
        pid = fork();
        
        if (pid < 0) {
            perror("Error en fork");
            exit(1);
        } else if (pid == 0) { // Hijo
            int inicio = i; // Valor inicial
            int fin = 2 * (i + 1) - 1; // Valor final
            int suma = 0;
            
            printf("Listado de números impresos por proceso %d\n", getpid());
            for (int j = inicio; j <= fin; j++) {
                printf("Proceso %d, secuencia %d\n", getpid(), j);
                suma += j;
            }
            
            exit(suma); // El hijo devuelve la suma de su secuencia
        } else {
            pids[i] = pid; // Guardar PID del hijo
        }
    }
    
    // Padre espera a todos los hijos y muestra sus resultados
    for (int i = 0; i < n; i++) {
        waitpid(pids[i], &status, 0);
        if (WIFEXITED(status)) {
            printf("Hijo %d terminó con suma: %d\n", pids[i], WEXITSTATUS(status));
        }
    }
    
    free(pids); // Liberar memoria
    return 0;
}