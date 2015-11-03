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

            if (msg.wParam == 1) qDebug() << "Hot Key activated : CTRL + C";
            if (msg.wParam == 2) qDebug() << "Hot Key activated : CTRL + X";
            if (msg.wParam == 3) qDebug() << "Hot Key activated : CTRL + V";
            if (msg.wParam == 4) qDebug() << "Hot Key activated : CTRL + P";
            if (msg.wParam == 5) qDebug() << "Hot Key activated : Print SCN";
            if (msg.wParam == 6) qDebug() << "Hot Key activated : PRINT";



        }
    }
    //return msg.wParam;
    a.exec();
}
