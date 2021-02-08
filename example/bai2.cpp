//Bai tap 2 
//2a Viet chuong trinh nhap vao 2 so nguyen khong dau 1 byte a va b 
//2b In bieu dien bit cua a va b 
//2c In bieu dien hexa cua a va b 
//2d In gia tri a b a or b a xor b a 2 b 2


#include <stdio.h>
#include <stdlib.h>

int main()
{
	//2a
	//unsigned char a,b;
	int a,b;
	printf("a=");
	scanf("%d",&a);
		
	printf("b=");
	scanf("%d",&b);
	//2b-2c
	char st[256];
	itoa(a,st,2); 
	printf("bieu dien nhi phan cua a=%s bieu dien hexa=%0x\n",st,a);
	itoa(b,st,2); 
	printf("bieu dien nhi phan cua b=%s bieu dien hexa=%0x\n",st,b);
	//2d
	printf("a&b=%d\n",a&b);
	printf("a or b=%d\n",a|b);
	printf("a xor b=%d\n",a^b);
	printf("a <<2=%d\n",a<<2);
	printf("b >>2=%d\n",b>>2);
}
