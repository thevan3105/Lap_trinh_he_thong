//Luong co vung nho rieng 
//
//Bai tap 15 Viet chuong trinh tao 2 luong Thr1 va Thr2 moi luong gom 1 vong lap sao cho
// Trong ham main khai bao 2 bien mang a va b cua cac so nguyen mang khong qua 10 phan tu 
// Thr1 co vung nho rieng la vung nho cho a 
// Thr2 co vung nho rieng la vung nho cho b 
//Khi Thr1 hoat dong thi nguoi dung nhap so phan tu cua mang a va Thr2 sinh ra so n ngau nhien va tiep tuc n phan tu cua mang b Khi nhap so phan tu khong vuot qua 0 thi Thread tung ung dung

#include <iostream>
#include <pthread.h>

void * fun_thread1(void *data)
{
	int *pa=(int*)data;
	
	while(true)
	{
		int n;
		printf("n=");
		scanf("%d",&n);
		if(n<=0 || n> 10)
			break;
		for(int i=0; i <n;i++)
		{
			printf("phan tu thu %d",i);
			scanf("%d",&(pa[i]));
		}//for
	}//while
}
void * fun_thread2(void *data)
{
     int *pb=(int*)data;
     
     while(true)
	 {
		int n=rand();
                if(n> 10)
                    break;
              for(int i=0; i <n;i++)
                   pb[i]=rand();
	}//while
}
int main(int argc, char *argv[])
{
     int a[10];
     int b[10];
    int status;
    pthread_t thrd_1,thrd_2;// thread objects
    // create thread
    pthread_create(&thrd_1,NULL,fun_thread1,&a);
    pthread_create(&thrd_2,NULL,fun_thread2,&b);    
    pthread_join(thrd_1, (void **)&status);
    pthread_join(thrd_2, (void **)&status);
    system("PAUSE");
    return 1;
}
