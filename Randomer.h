#pragma once
#ifndef RANDOMER_H
#define RANDOMER_H
#include <chrono>

class Randomer {
public:
    Randomer();
    ~Randomer() {}
    int getRand(int a, int b);
    char getChar();
private:
    int getRand() {return rand();}
    static unsigned int number;
    time_t getTimeStamp();
};

#endif // !RANDOMER_H