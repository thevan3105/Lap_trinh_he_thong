#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <iostream>
#include <pthread.h>

void * timer1(void *data)
{
    while(true)
	{
		FILE *fp=fopen("vd.dat","w+b");
		if(fp==NULL)
			continue;//bo qua
			
		int a=rand();
		fwrite(&a,sizeof(int),1,fp);
		fclose(fp);
		Sleep(10);
	}
}

int main(int argc, char *argv[])
{
    int status;
    // creating thread objects
    pthread_t thrd_1;
  
    // create thread
    pthread_create(&thrd_1,NULL,timer1,NULL);
    pthread_join(thrd_1, (void **)&status);
    system("PAUSE");
    return 1;
}

