#include "mainwindow.h"
#include <QApplication>
#include <form.h>
#include <QCoreApplication>
#include <Windows.h>
#include <iostream>
#include <QDebug>
#include <qdebug.h>

#pragma comment(lib,"user32.lib")

int main(int argc, char *argv[])
{
   // QApplication a(argc, argv);
  //  MainWindow w;
  //  w.show();
    RegisterHotKey(NULL,1,MOD_CONTROL | MOD_NOREPEAT,0x43); // ctrl + c
    RegisterHotKey(NULL,2,MOD_CONTROL | MOD_NOREPEAT,0x58); // ctrl+ x
    RegisterHotKey(NULL,3,MOD_CONTROL | MOD_NOREPEAT,0x56); // xctrl + v
    RegisterHotKey(NULL,4,MOD_CONTROL | MOD_NOREPEAT,0x50); // ctrl + p
   // RegisterHotKey(NULL,2,MOD_CONTROL | MOD_NOREPEAT,0x44); // print scn
    RegisterHotKey(NULL,5,NULL,VK_SNAPSHOT);  // print scn
    RegisterHotKey(NULL,6,NULL,VK_PRINT); // print
    RegisterHotKey(NULL,7,MOD_ALT | MOD_NOREPEAT,VK_SNAPSHOT); // alt + print scn
    //RegisterHotKey(NULL,6,NULL,VK_LEFT); // print
    RegisterHotKey(NULL,8,NULL,VK_RIGHT); // print



    QApplication a(argc, argv);
   // MainWindow w;
   // w.show();
    Form f;
    f.show();
    QApplication::processEvents();

    MSG msg;

    while(GetMessage(&msg,NULL,0,0)){
        TranslateMessage(&msg);
        DispatchMessage(&msg);
        if (msg.message == WM_HOTKEY){

            if (msg.wParam == 1)
            {
                qDebug() << "Hot Key activated : CTRL + C";
                MessageBox(NULL,(LPCWSTR)L"CTRL + C is not allowed?",
                                (LPCWSTR)L"Restricted Action",
                                MB_ICONWARNING | MB_CANCELTRYCONTINUE | MB_DEFBUTTON2
                );
            }
            if (msg.wParam == 2)
            {
                qDebug() << "Hot Key activated : CTRL + X";
                MessageBox(NULL,(LPCWSTR)L"CTRL + X is not allowed?",
                                (LPCWSTR)L"Restricted Action",
                                MB_ICONWARNING | MB_CANCELTRYCONTINUE | MB_DEFBUTTON2
                );
            }
            if (msg.wParam == 3)
            {
                qDebug() << "Hot Key activated : CTRL + V";
                MessageBox(NULL,(LPCWSTR)L"CTRL + V is not allowed?",
                                (LPCWSTR)L"Restricted Action",
                                MB_ICONWARNING | MB_CANCELTRYCONTINUE | MB_DEFBUTTON2
                );
            }
            if (msg.wParam == 4)
            {
                qDebug() << "Hot Key activated : CTRL + P";
                MessageBox(NULL,(LPCWSTR)L"CTRL + P is not allowed?",
                                (LPCWSTR)L"Restricted Action",
                                MB_ICONWARNING | MB_CANCELTRYCONTINUE | MB_DEFBUTTON2
                );
            }
            if (msg.wParam == 5)
            {
                qDebug() << "Hot Key activated : Print SCN";
                MessageBox(NULL,(LPCWSTR)L"Print SCN is not allowed?",
                                (LPCWSTR)L"Restricted Action",
                                MB_ICONWARNING | MB_CANCELTRYCONTINUE | MB_DEFBUTTON2
                );
            }
            if (msg.wParam == 6)
            {
                qDebug() << "Hot Key activated : PRINT";
                MessageBox(NULL,(LPCWSTR)L"Print page is not allowed?",
                                (LPCWSTR)L"Restricted Action",
                                MB_ICONWARNING | MB_CANCELTRYCONTINUE | MB_DEFBUTTON2
                );
            }
            if (msg.wParam == 7)
            {
                qDebug() << "Hot Key activated : PRINT Screen";
                MessageBox(NULL,(LPCWSTR)L"ALT + Print Scn is not allowed?",
                                (LPCWSTR)L"Restricted Action",
                                MB_ICONWARNING | MB_CANCELTRYCONTINUE | MB_DEFBUTTON2
                );
            }
            if (msg.wParam == 8)
            {
                qDebug() << "Hot Key activated : Right click";
                MessageBox(NULL,(LPCWSTR)L"Right Click is not allowed?",
                                (LPCWSTR)L"Restricted Action",
                                MB_ICONWARNING | MB_CANCELTRYCONTINUE | MB_DEFBUTTON2
                );
            }

        }
    }
    //return msg.wParam;
    a.exec();
}
