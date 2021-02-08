//Bai tap 10 Viet chuong trinh khi chay tao mot tien trinh de nap va chay chuong trinh Notepad exe 
//So sanh su khac nhau cua ky thuat tao tien trinh va ky thuat goi 1 ung dung cua bai 9

//#include <iostream.h>
#include <windows.h>
#include <stdio.h>
#include <stdlib.h>

// Goi notepad.exe va mo luon file abc.txt
int main()
{
  STARTUPINFO stgStartupInfo;         
  PROCESS_INFORMATION stgProcessInfo;
  DWORD ExitCode;                       

  ZeroMemory(&stgStartupInfo,sizeof(STARTUPINFO));
  stgStartupInfo.cb = sizeof(STARTUPINFO);
  
  char sz[256]="c:\\windows\\notepad.exe c:\\abc.txt";
  //if(CreateProcess(NULL,"c:\\windows\\notepad.exe c:\\abc.txt",
  if(CreateProcess(NULL,sz,
                NULL,NULL,false,
                CREATE_DEFAULT_ERROR_MODE | NORMAL_PRIORITY_CLASS,
                NULL,NULL,&stgStartupInfo,&stgProcessInfo)==TRUE)
  {
    CloseHandle(stgProcessInfo.hThread);  
    WaitForInputIdle(stgProcessInfo.hProcess, INFINITE);
    
    while(WaitForSingleObject(stgProcessInfo.hProcess, 100) == WAIT_TIMEOUT)
    {
    }
    GetExitCodeProcess(stgProcessInfo.hProcess, &ExitCode);
    CloseHandle(stgProcessInfo.hProcess); 
  }
  STARTUPINFO stgStartupInfo2;         
  PROCESS_INFORMATION stgProcessInfo2;

  DWORD ExitCode2;                    

  ZeroMemory(&stgStartupInfo2,sizeof(STARTUPINFO));
  stgStartupInfo2.cb = sizeof(STARTUPINFO);
 
  //if(CreateProcess(NULL,"c:\\windows\\notepad.exe c:\\abc.bat",
  if(CreateProcess(NULL,sz,
                NULL,NULL,false,
                CREATE_DEFAULT_ERROR_MODE | NORMAL_PRIORITY_CLASS,
                NULL,NULL,&stgStartupInfo2,&stgProcessInfo2)==TRUE)
  {
    CloseHandle(stgProcessInfo2.hThread);  
    WaitForInputIdle(stgProcessInfo.hProcess, INFINITE);
    while(WaitForSingleObject(stgProcessInfo2.hProcess, 100) == WAIT_TIMEOUT)
    {
    }
    GetExitCodeProcess(stgProcessInfo2.hProcess, &ExitCode2);
    CloseHandle(stgProcessInfo2.hProcess); 
  }
  
  return 0;
}
