#include <stdio.h>
#include <winsock2.h>
#include <conio.h>

int main()
{
	WSADATA wsaData;
	SOCKADDR_IN rAddr;
	int iRc;
	iRc = WSAStartup(MAKEWORD(2, 2), &wsaData);
	SOCKET sk = socket(AF_INET, SOCK_STREAM, 0);
	rAddr.sin_family = AF_INET;
	rAddr.sin_addr.s_addr = inet_addr("127.0.0.1");
	rAddr.sin_port = htons(100);
	iRc = connect(sk, (LPSOCKADDR)&rAddr, sizeof(rAddr));

	while(1)
	{
		char st[256]; // nhap mang ky tu
		int a[100]; // nhap mang so nguyen n phan tu
		int n;
		char c; // nhap mot ky tu
		/*printf("nhap so phan tu:");// code phan nhap mang so nguyen
		scanf("%d",&n);
		for(int i=0;i <n;i++){
			scanf("%d",&a[i]);
		}
		for(int i=0;i<=n/2;i++){
			int temp = a[i];
			a[i] = a[n-i-1];
			a[n-i-1] = temp;
		}*/
		c = getch();
			
		send(sk,(const char*)&c, sizeof(256), 0);// lenh gui c sang server
		if(c == 27)
			break;
		printf("\n%c",c);
		Sleep(10);
		//send(sk,(const char*)a, n*sizeof(int), 0);
	}
	/* Ðóng socket và gi?i phóng tài nguyên */
	closesocket(sk);
	WSACleanup();

	getch();	
    return 0;
}
