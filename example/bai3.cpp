//Bai tap 3 
//Viet chuong trinh gom 1 ham co 1 vong lap Than vong lap thuc hien nhap phim tu ban phim neu nguoi dung nhan phim ESCAPE thi thoat khoi vong lap 
//Viet ham main goi ham de thu chuong trinh

#include <stdio.h>
#include <conio.h>
void nhap_phim()
{
	char c;
	while(1)
	{
		c=getch();
		if(c==27)
			break;
		printf("%c",c);	
	}//while	
}

int main()
{
	nhap_phim();	
}// main
