#include <iostream>
#include "Randomer.h"

using namespace std;

Randomer::Randomer() { // constructor
    number++; // 静态数据成员
    // cout << number << endl; // used for test
    // cout << getTimeStamp() + number << endl; // used for test
    srand(getTimeStamp() + number); // 初始化随机数生成器(种子为当前毫秒数+number)
}

int Randomer::getRand(int a, int b) { // 生成a至b区间的随机数
    // rand为整数, RAND_MAX == 2147483647
    return ((double(rand()) / RAND_MAX) * (b - a) + a);
}

char Randomer::getChar() { // 由随机数生成 '+' 或 '-'
    if (getRand(1, 10) >= 6) {
        return '+';
    } else {
        return '-';
    }
}

time_t Randomer::getTimeStamp() {
    // 将当前系统时间点(ns为单位)转化为以当前系统时间点(ms为单位)
    chrono::time_point<chrono::system_clock, chrono::milliseconds> tp = chrono::time_point_cast<chrono::milliseconds>(chrono::system_clock::now());
    
    // 记录将当前时间点至原点的时长
    // chrono::milliseconds tmp = chrono::duration_cast<chrono::milliseconds>(tp.time_since_epoch()); // abolished
    // time_t timeStamp = tmp.count(); // abolished
    time_t timeStamp = tp.time_since_epoch().count();

    return timeStamp; // 返回当前时间点至原点时长(ms)
}

unsigned int Randomer::number = 0;