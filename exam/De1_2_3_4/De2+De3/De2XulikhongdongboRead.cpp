#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <iostream>
#include <pthread.h>
#include <conio.h>
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
		//printf("%c\n",c);
		
		fclose(fp);
		Sleep(10);
	}
}

void * timer2(void *data)
{
    while(true)
	{
		FILE *fp=fopen("vd.txt","rb");
		if(fp==NULL)
			continue;//bo qua
			
		char c;
		fread(&c,sizeof(char),1,fp);
		if(c == 33){
			printf("%c\n",c);
			break;
			}
		fclose(fp);
		printf("%c\n",c);
		Sleep(5);
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

