// Programa que demuestra al ejecución del wait()
#include<stdio.h>
#include<stdlib.h>
#include<sys/wait.h>
#include<unistd.h>

int main()
{
	pid_t cpid;
	int status;
	if (fork()== 0)
	{
		int ret;

		printf("Aparece el hijo %d\n", getpid());
		srand(getpid());
		ret = rand() % 10;
		printf("El hijo genera un aleatorio y duerme esa cifra en segs. %d\n", ret);
		sleep(ret);  // duerme un tiempo de ret segs.
		exit(ret);  // termina hijo y devuelve el aleatorio al padre.
	}
	else
	{
		printf("Aparece el padre %d\n", getpid());
		cpid = wait(&status); /*  Padre */
		printf("Vuelve el padre %d\n", getpid());
	}
	printf("pid Padre = %d\n", getpid());
	printf("pid hijo = %d, lo imprime el padre %d, ya que el hijo terminó con aleatorio %d\n", cpid, getpid(), WEXITSTATUS(status));

	return 0;
}
