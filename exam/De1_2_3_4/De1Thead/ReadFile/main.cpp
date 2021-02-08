#include <pthread.h>
#include <string.h>
#include <stdio.h>
#include<conio.h>
#include <windows.h>

void * fun_thread1(void *data)
{
	while(true)
	{
		FILE *fp=fopen("E:\\dulieu.txt","rb");
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
		Sleep(100);
	}
}
int main(int argc, char *argv[])
{
    int status;
    
    // creating thread objects
    pthread_t thrd_1;
    
    // create thread
    pthread_create(&thrd_1,NULL,fun_thread1,(void *)0);
      
    pthread_join(thrd_1, (void **)&status);
    
    system("PAUSE");
    return 1;
} 
