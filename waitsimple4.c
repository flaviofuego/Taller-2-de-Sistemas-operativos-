// Programa que demuestra al ejecución del waitpid() generando n procesos
#include<stdio.h>
#include<stdlib.h>
#include<sys/wait.h>
#include<unistd.h>

int main()
{
	int i, stat;
	pid_t pid[5];
	for (i=0; i<5; i++)
	{
		if ((pid[i] = fork()) == 0)
		{
			int ret;

			srand(getpid());
			ret = rand() % 10;
			sleep(ret);  // duerme un tiempo de ret segs.
			exit(ret);
		}
	}

	// Uso de waitpid() e impresión de status de hijo (aleatorio ret)

	for (i=0; i<5; i++)
	{
		pid_t cpid = waitpid(pid[i], &stat, 0);
		if (WIFEXITED(stat))
			printf("Hijo %d finalizó con status(aleatorio): %d\n",
				cpid, WEXITSTATUS(stat));
	}
	return 0;
}