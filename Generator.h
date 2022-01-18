#pragma once // 避免文件重复包含
#ifndef GENERATOR_H // 避免文件重复包含
#define GENERATOR_H
#include <string>
#include "Randomer.h"
#include "Calculator.h"
#include "Scorer.h" // Result
#include "ConsoleShow.h"

class Generator {
public:
    Generator() {}
    ~Generator() {}

    void start();
private:
    int num1 = 0, num2 = 0, num3 = 0, num = 0; // num为题数, 其余为操作数
    char ch1 = '+', ch2 = '+'; // ??????

    Result resAndExpr; // 结果
    Randomer ran; // 随机
    Calculator cal; // 计算
    Scorer sco; // 计分
    ConsoleShow console; // 显示

    void inputAndJudge(); // 输入与判定
    void generateAddExpr(); // 生成加法
    void generateSubExpr(); // 生成减法
    void generateMixExpr(); // 生成加减
    void showRamainingQuestion(int n); // 显示剩余问题数
};

#endif