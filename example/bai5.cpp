//Bai tap 5 
//Viet chuong trinh gom 1 ham co 1 vong lap Than vong lap thuc hien nhap phim tu ban phim neu nguoi dung nhan phim ESCAPE thi thoat khoi vong lap trai lai thi nap ki tu vao 1 hang doi queue 
//Khi thoat khoi vong lap thi in tat ca cac ki tu trong hang doi 
//Viet ham main goi ham de thu chuong trinh

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

//void 

int main( )
{
	char c;
    queue<char> Q;//4
   
    tao_hangdoi_kitu(Q);
  
    while(Q.empty()==false)
	{
		c=Q.front();
		printf("%c\n",c);
    	Q.pop();//6
	}
}
