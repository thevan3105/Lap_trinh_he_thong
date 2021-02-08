#include<stdio.h>
#include<conio.h>
#include<pthread.h>
#include <windows.h>
// phan a
void *Vonglap(void *data)
{
	
	while(1)
	{
		char c;
		FILE *file;
		file = fopen("E:\\dulieu.txt","w");
		c = getch();
		if(c == 33){
			fprintf(file,"%c\n",c);
			break;
		}
		fprintf(file,"%c",c);
		fclose(file);
		printf("%c\n",c);
		Sleep(10);
	}
	
}
int main(int argc, char *argv[])
{
	int status;
	//phan b
	pthread_t thrd_1;
	
	pthread_create(&thrd_1,NULL,Vonglap,NULL);
	//Vonglap();
	pthread_join(thrd_1, (void **)&status);
	return 1;
}
