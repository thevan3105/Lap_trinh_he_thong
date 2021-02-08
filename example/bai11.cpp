//Loai lap trinh da luong
//Nguyen ly he dieu hanh tieu trinh thread 
//Tai sao lai can xay dung cac chuong trinh multi thread 
//Vi du 1 1 ung dung khi chay thi mo 1 file dung luong lon cho rat lau moi tai xong trang thai waiting rat lau lang phi time tham chi nguoi su dung chuong trinh treo 
//Giai quyet trong khi cho mo file thi chuong trinh nen thuc hien tiep cac thao tac don gian khac 
//Vi du 2 co nhieu yeu cau phuc vu can duoc dap ung dong thoi chuong trinh khong xu ly tuan tu 
//Vi du 3 1 he thong co nhieu loi core nhieu vi xu ly co nen khai thac het de tang toc do chuong trinh khong 
//
//Nhung yeu cau nay dan den lam chu ky nang xu ly song song parallel processing xu ly dong hanh concurrent processing da tien trinh multi process da tac vu multi tasks da luong multi threads 
//
//Lap trinh da luong 
//Bai tap 11 Viet 1 chuong trinh gom 2 thu tuc 
//Thu tuc 1 vong lap vo han in ra xau Hello 1 
//Thu tuc 2 vong lap vo han in ra xau Hello 2

#include <iostream>
#include <pthread.h>


void *func1(void *data)
{
    while(1)
	{
		printf("hello 1\n");
	}
	
}
void *func2(void *data)
{
   while(1)
	{
		printf("hello 2\n");
	}
}
int main(int argc, char *argv[])
{
    int status;
    // creating thread objects
    pthread_t thrd_1;
    pthread_t thrd_2;
    // create thread
    pthread_create(&thrd_1,NULL,func1,NULL);
    pthread_create(&thrd_2,NULL,func2,NULL); 
	   
    pthread_join(thrd_1, (void **)&status);
    pthread_join(thrd_2, (void **)&status);
    system("PAUSE");
    return 1;
}

//Bài tâp 11. Viêt 1 chuong trình, gom 2 thu tuc. 
//Thu tuc 1,vòng lap vô han, in ra xâu "Hello 1".
//Thu tuc 2, vòng lap vô han, in ra xâu "Hello 2".

//Thu tuc 1 và thu tuc 2 cùng thuc hien de tao ra thu tu xuat hien xâu "Hello 1", "Hello 2" mot cách ngau nhiên trên màn hình.
