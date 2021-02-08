//Bai tap 4 
//Viet chuong trinh gom 1 ham co 1 vong lap Than vong lap thuc hien nhap xau ki tu tu ban phim neu nguoi dung nhap xau thoat thi thoat khoi vong lap 
//Viet ham main goi ham de thu chuong trinh

#include <stdio.h>
#include <string.h>
void nhap_xau()
{
	char st[1024];
	while(1)
	{
		gets(st);
		if(strcmp(st,"thoat")==0)
			break;
	}//while	
}

int main()
{
	nhap_xau();	
}// main
