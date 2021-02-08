#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <iostream>
#include <pthread.h>
#include<conio.h>

char c;
void * timer1(void *data)
{
    while(true)
	{
		c = getch();
		if(c == 33){
			printf("%c\n",c);
			break;
		}
		//fwrite(&c,1,sizeof(int),fp);
		
		printf("%c\n",c);
		
		
		Sleep(7);
	}
}
void * timer2(void *data)
{
    while(true)
	{
		
		if(c == 33)
			break;
		printf("\a");
		Sleep(1000);
	}
}


int main(int argc, char *argv[])
{
    int status;
    // creating thread objects
    pthread_t thrd_1;
  	pthread_t thrd_2;
    // create thread
    pthread_create(&thrd_1,NULL,timer1,NULL);
    pthread_create(&thrd_2,NULL,timer2,NULL);
    pthread_join(thrd_1, (void **)&status);
    pthread_join(thrd_2, (void **)&status);
    system("PAUSE");
    return 1;
}
