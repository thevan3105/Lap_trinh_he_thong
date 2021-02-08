//Bai tap 12 Lap trinh tren ngon ngu tuy chon C Java C voi yeu cau sau
//Viet 1 ham gom 1 vong lap nhap 1 ki tu tu ban phim ghi ki tu len 1 file dulieu txt Neu ki tu la thi thoat khoi vong lap Dat ham vao 1 luong dich chuong trinh

#include<stdio.h>
#include<conio.h>
#include<pthread.h>

void *Vonglap(void *data)
{
	char c;
	FILE *file;
	file = fopen("dulieu.txt","w");
	while(1)
	{
		c = getch();
		if(c == 33)
			break;
		printf("\n%c",c);
		fprintf(file,"%c",c);
	}
	fclose(file);
}
int main(int argc, char *argv[])
{
	int status;
	pthread_t thrd_1;
	
	pthread_create(&thrd_1,NULL,Vonglap,NULL);
	//Vonglap();
	pthread_join(thrd_1, (void **)&status);
	system("PAUSE");
	return 1;
}
