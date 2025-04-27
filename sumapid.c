// sumapid.c
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <time.h>

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
    int suma = 0;
    pid_t *pids = malloc(n * sizeof(pid_t)); // Arreglo para guardar los PIDs
    
    // Crear n hijos
    for (int i = 0; i < n; i++) {
        pid = fork();
        
        if (pid < 0) {
            perror("Error en fork");
            exit(1);
        } else if (pid == 0) { // Hijo
            srand(getpid()); // Inicializar semilla con PID
            int valor = rand() % 10; // Número aleatorio entre 0 y 9
            printf("Hijo: PID = %d, valor aleatorio calculado %d\n", getpid(), valor);
            exit(valor); // El hijo devuelve el valor generado
        } else {
            pids[i] = pid; // Guardar PID del hijo
        }
    }
    
    // Padre espera a los hijos en orden de creación
    for (int i = 0; i < n; i++) {
        waitpid(pids[i], &status, 0); // Esperar al hijo específico
        if (WIFEXITED(status)) {
            int valor_hijo = WEXITSTATUS(status);
            printf("PADRE de PID = %d, HIJO de PID = %d terminado, st = %d\n", 
                   getpid(), pids[i], valor_hijo);
            suma += valor_hijo;
        }
    }
    
    printf("La suma es %d\n", suma);
    free(pids); // Liberar memoria
    
    return 0;
}