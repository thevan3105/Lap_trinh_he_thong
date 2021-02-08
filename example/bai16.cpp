//Bai tap 16 2 luong chung 1 vung nho 1 luong thay doi vung nho 1 luong thi chi doc noi dung vung nho 
//Viet chuong trinh gom 2 luong moi luong co 1 vong lap 
// Luong 1 thuc hien nhap phim tu ban phim neu nguoi dung nhan phim ESCAPE thi thoat khoi vong lap trai lai thi nap ki tu vao 1 hang doi queue 
// Luong 2 hien thi ki tu trong hang doi ban phim theo thu tu luu tru vao hang doi 
// Khi luong 1 dung thi luong 2 cung dung 
// Viet ham main khoi tao va kich hoat cac luong tren Dich va chay chuong trinh 
// tham khao bai tap 5

#include <stdio.h>
#include <conio.h>
#include <queue>//1
using namespace std;//2

void tao_hangdoi_kitu(queue<char> &Q)
{
    char c;
    while(1)
    {
        c=getch();
        if(c==27)
        //printf("%c",c)
        	break;
        Q.push(c);
    }
}

int main()
	{
		
	}
