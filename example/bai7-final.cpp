//Bai tap 7 Viet ham copy 1 file nhi phan khong gioi han kich thuoc sang 1 file co ten khac 
//Viet lenh goi ham copy trong ham main

#include <stdio.h>
int len_file(const char *ten_file)
{
	FILE *fp=fopen(ten_file,"rb");
	if(fp==NULL) return -1;
	fseek(fp,0,SEEK_END);
	int len=ftell(fp);
	fseek(fp,0,SEEK_SET);
	fclose(fp);fp=NULL;
	return len;
}// len_file

int copy_file(const char *src,const char *dest)
{
	FILE *fp1=fopen(src,"rb");
	if(fp1==NULL) return -1;
	
	FILE *fp2=fopen(dest,"w+b");
	if(fp2==NULL)
	{
		fclose(fp1);fp1=NULL;
		return -1;
	}//if
	
	unsigned char buff[32];
	while(1)
	{
		int so_byte_docduoc=fread(buff,sizeof(unsigned char),32,fp1);
		if(so_byte_docduoc<=0)
			break;
		fwrite(buff,sizeof(unsigned char),so_byte_docduoc,fp2);
			
	}// while
	

	fclose(fp1);fp1=NULL;
	fclose(fp2);fp2=NULL;
	return 1;
	
}// copy_file

int main()
{
	int count_byte=len_file("ma_hoa_file.cpp");
	// goi ham
	copy_file("ma_hoa_file.cpp","ma_hoa_file-Copy.cpp");
}// main
