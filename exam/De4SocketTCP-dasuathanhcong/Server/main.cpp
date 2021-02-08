#include <iostream>
#include <stdio.h>
#include <winsock2.h>
#include <conio.h>
#include <stdlib.h>
#include<pthread.h>

void *fun_thread(void *data){
	WSADATA wsaData;
	SOCKADDR_IN serAddr, cliAddr;
	int iRc;
	int adsize;
	char buffer[256];

	iRc = WSAStartup(MAKEWORD(2, 2), &wsaData);
	SOCKET ssk = socket(AF_INET, SOCK_STREAM, 0);

	serAddr.sin_family = AF_INET;
	serAddr.sin_addr.s_addr = inet_addr("127.0.0.1");
	serAddr.sin_port = htons(100);

	iRc = bind(ssk, (LPSOCKADDR)&serAddr, sizeof(serAddr)); // tao ket noi lang nghe tren dia chi cài o trên
	iRc = listen(ssk, 5); // max ket noi vs 5 socket client
	adsize = sizeof(cliAddr);
	SOCKET sk = accept(ssk, (LPSOCKADDR)&cliAddr, &adsize);
	while(1)
	{
		int n;
		int a[100];
		char c;
		recv(sk,(char*)&c, sizeof(256), 0);
		if(c == 27)
			break;
		printf("c =%c\n",c);

		printf("\n");
		Sleep(10);
		
	}
	closesocket(sk);
	closesocket(ssk);
	WSACleanup();
}

int main()
{
	int status;
	pthread_t thrd_1;
	pthread_create(&thrd_1,NULL,fun_thread,NULL);
	pthread_join(thrd_1, (void **)&status);
	system("PAUSE");
	getch();
	return 0;
}
