// Programa que demuestra al ejecución del wait() sin exit() y no devulve status
#include<stdio.h>
#include<sys/wait.h>
#include<unistd.h>

int main()
{
	if (fork()== 0)
		printf("HH: Hola desde el hijo %d\n", getpid());
	else
	{
		//wait(NULL);
		printf("HP: Hola desde el padre %d\n", getpid());
		wait(NULL);
		printf("EP: Vuelve el padre\n");
		printf("HT: Hijo ha terminado\n");
	}

	printf("Adiós desde %d\n", getpid());
	return 0;
}
