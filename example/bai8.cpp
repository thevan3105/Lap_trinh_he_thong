//Bai tap 8 Viet ham mo 1 file nhi phan co ten file cho truoc doc tung khoi khong qua 32 byte cua file va hien thi ma hexa cua tung byte trong khoi Het khoi xuong dong 
//Viet lenh goi ham trong ham main Dich va chay chuong trinh 
// ky thuat tren goi la dump file


///////////////////////////////////////////////////////////////////////
#include <stdio.h>
#include <stdlib.h>

int dump_hexa(const char *fileName)
{
	FILE *fp;
	unsigned char buff[32];
	
	fp=fopen(fileName,"rb");
	if(fp==NULL)
		return -1;//loi
	while(1)	
	{
		int so_byte_doc_duoc=fread(buff,1,32,fp);
		if(so_byte_doc_duoc<=0)
			break;
		for(int i=0; i < so_byte_doc_duoc;i++)
		{
			// hien thu buff[i] duoi dang hexa
			char st[3];
			itoa(buff[i],st,16);
			printf("%s ",st);
		}
		printf("\n");
	}
	fclose(fp);
	return 1;
}

int main()
{
	dump_hexa("I04.jpg");
	
}

