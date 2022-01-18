#include <iostream>
#include <string>
#include "ConsoleShow.h"

using namespace std;

void ConsoleShow::initialization() {
    system("title 小学生算术运算练习系统");
    system("mode con cols=68 lines=25");
    system("color 03");
    cout << "****************小学生算术运算练习系统****************" << endl;
    cout << "*                                                    *" << endl;
    cout << "*                                                    *" << endl;
    cout << "*                   1.单项加法练习                   *" << endl;
    cout << "*                                                    *" << endl;
    cout << "*                   2.单项减法练习                   *" << endl;
    cout << "*                                                    *" << endl;
    cout << "*                   3.加减混合练习                   *" << endl;
    cout << "*                                                    *" << endl;
    cout << "*                   4.退出系统                       *" << endl;
    cout << "*                                                    *" << endl;
    cout << "*                                                    *" << endl;
    cout << "******************************************************" << endl;
}

void ConsoleShow::screenColor(char ch) { // ????????????????????????
    string tmp = "color" + ch + 'f';
    system(tmp.data());
}
