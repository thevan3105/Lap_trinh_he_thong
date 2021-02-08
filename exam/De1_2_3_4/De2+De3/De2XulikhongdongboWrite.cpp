#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <iostream>
#include <pthread.h>
#include<conio.h>

void * timer1(void *data)
{
    while(true)
	{
		FILE *fp=fopen("vd.txt","w+b");
		if(fp==NULL)
			continue;//bo qua
		char c;	
		c = getch();
		if(c == 33){
			fprintf(fp,"%c",c);
			break;
		}
		//fwrite(&c,1,sizeof(int),fp);
		fprintf(fp,"%c",c);
		printf("%c\n",c);
		
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
