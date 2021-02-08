//Tien trinh process luong thread va lap trinh da luong
//Bai tap 9 Viet 1 chuong trinh khi chay thi goi 1 chuong trinh khac vi du notepad exe

#include <stdlib.h>

int main()
{
    system( "notepad.exe" );
}

//C++:
//#include<stdio.h>
//#include<windows.h>
//
//int main()
//{
//	printf("goi notepad.exe");
//	WinExec("notepad.exe",SW_SHOW);
//}// main
//
//// Java
//package LapTrinhHeThong;
//import java.io.IOException;
//
//public class NotepadRun
//{
//    public static void main(String[] args)
//    {
//        Runtime runtime = Runtime.getRuntime();
//
//        try
//        {
//            runtime.exec("notepad.exe");    
//        }
//        catch (IOException e)
//        {
//            e.printStackTrace();
//        }
//    }
//}
