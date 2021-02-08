//B�i tap 12. Lap tr�nh tr�n ng�n ngo t�y chon C++/Java/C# voi y�u cau sau:
//Viet 1 h�m gom 1 v�ng lap nhap 1 k� tu tu b�n ph�m, ghi k� tu l�n 1 file  dulieu.txt. Neu k� tu l� '!' th� tho�t khoi v�ng lop.  �at h�m v�o 1 luong, dich chuong tr�nh.

#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<conio.h>

void *func1(void *data)
{
	char c;
	FILE *fpt;
	fpt = fopen("dulieu.txt","w");
	while(1)
	{
		if(fpt==NULL)
		{
			printf("file ko ton tai!");
			exit(1);
		}
		c = getch();
		if(c == 33)
			break;
		printf("nhap ky tu:"); scanf("%c", &c);
		fflush(stdin);
		fprintf(fpt,"%c",c);
	}
	fclose(fpt);
}
int main(int argc, char *argv[])
{
	int status;
    // creating thread objects
    pthread_t thrd_1;
    // create thread
    pthread_create(&thrd_1,NULL,func1,NULL);
	   
    pthread_join(thrd_1, (void **)&status);
    system("PAUSE");
    return 1;
}
