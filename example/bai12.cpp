//Bài tap 12. Lap trình trên ngôn ngo tùy chon C++/Java/C# voi yêu cau sau:
//Viet 1 hàm gom 1 vòng lap nhap 1 kí tu tu bàn phím, ghi kí tu lên 1 file  dulieu.txt. Neu kí tu là '!' thì thoát khoi vòng lop.  Ðat hàm vào 1 luong, dich chuong trình.

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
