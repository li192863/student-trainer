#include <iostream>
#include "Generator.h"

using namespace std;

void Generator::generateAddExpr() { // 生成加法表达式
    num = ran.getRand(1, 10); // 共1~10题不等
    int tmp = num; // 当前未答题目数
    while (tmp-- > 0) { // 当还有未答题目时
        showRamainingQuestion(num - tmp); // 显示当前题号与题目总数

        num1 = ran.getRand(1, 20); // 生成数1
        num2 = ran.getRand(1, 20); // 生成数2
        cout << num1 << " + " << num2 << " = " ; // 输出算式

        resAndExpr.expr = to_string(num1) + " + " + to_string(num2); // 生成表达式
        resAndExpr.res = cal.add(num1, num2); // 生成计算结果
        
        inputAndJudge(); // 数据输入及判断
    }
}

void Generator::generateSubExpr() { // 生成减法表达式
    num = ran.getRand(1, 10); // 共1~10题不等
    int tmp = num; // 当前未答题目数
    while (tmp-- > 0) { // 当还有未答题目时
        showRamainingQuestion(num - tmp); // 显示当前题号与题目总数

        num1 = ran.getRand(1, 20); // 生成数1
        num2 = ran.getRand(1, 20); // 生成数2

        if (num1 >= num2) { // 输出算式
            cout << num1 << " - " << num2 << " = " ;
            resAndExpr.expr = to_string(num1) + " - " + to_string(num2); // 生成表达式
        } else {
            cout << num2 << " - " << num1 << " = " ;
            resAndExpr.expr = to_string(num2) + " - " + to_string(num1); // 生成表达式
        }
        resAndExpr.res = cal.sub(num1, num2); // 生成计算结果

        inputAndJudge(); // 数据输入及判断
    }
}

void Generator::generateMixExpr() { // 生成加减混合表达式
    num = ran.getRand(1, 10); // 共1~10题不等
    int tmp = num; // 当前未答题目数
    while (tmp-- > 0) { // 当还有未答题目时
        showRamainingQuestion(num - tmp); // 显示当前题号与题目总数

        num1 = ran.getRand(1, 20); // 生成数1
        num2 = ran.getRand(1, 20); // 生成数2
        num3 = ran.getRand(1, 20); // 生成数3
        ch1 = ran.getChar(); // 生成运算符1
        ch2 = ran.getChar(); // 生成运算符2

        while (num1 < num2 && ch1 == '-') { // 当首步计算结果为负时
            num1 = ran.getRand(1, 20); // 重新生成数1
            num2 = ran.getRand(1, 20); // 重新生成数2
        } // 直至数1 >= 数2时退出

        int tmp = cal.process(num1, ch1, num2); // 计算中间结果(num1 ch1 num2)

        while (tmp < num3 && ch2 == '-') { // 当次步计算结果为负时
            num1 = ran.getRand(1, 20); // 重新生成数1
            num2 = ran.getRand(1, 20); // 重新生成数2
            while (num1 < num2 && ch1 == '-') { // 当首步计算结果为负时
                num1 = ran.getRand(1, 20); // 重新生成数1
                num2 = ran.getRand(1, 20); // 重新生成数2
            } // 直至数1 >= 数2时退出
            num3 = ran.getRand(1, 20); // 重新生成数3
            tmp = cal.process(num1, ch1, num2); // 再次计算中间结果(num1 ch1 num2)
        } // 直至中间结果 >= 数3时退出
        
        // 执行至此可保证计算结果非负
        cout << num1 << " " << ch1 << " " << num2 << " " << ch2 << " " << num3 << " = "; // 输出算式

        resAndExpr.expr = to_string(num1) + " " + ch1 + " " + to_string(num2) + " " + ch2 + " " + to_string(num3); // 生成表达式
        resAndExpr.res = cal.process(tmp, ch2, num3); // 生成计算结果
        
        inputAndJudge(); // 数据输入及判断
    }
}

void Generator::inputAndJudge() { // 数据输入及判断
    cin >> resAndExpr.ans; // 输入结果
    if (resAndExpr.ans == resAndExpr.res) { // 若结果正确
        sco.addScores(); // 更新成绩
        cout << "正确！" << endl; // 反馈
    } else {
        sco.addWrongAnswer(resAndExpr); // 添加错题
        cout << "错误！" << endl; // 反馈
    }
}

void Generator::start() { // 启动
    console.initialization(); // 初始化

    int cmd;
    cout << endl << "请选择功能(1~4)：";
    cin >> cmd;
    system("cls");

    switch(cmd) {
        case 1: generateAddExpr(); break;
        case 2: generateSubExpr(); break;
        case 3: generateMixExpr(); break;
        case 4: exit(0); break;
        default: cout << "非法输入！" << endl;
    }

    sco.fileProcess(num); // 文件输出
    sco.statistics(num); // 统计得分
}

void Generator::showRamainingQuestion(int n) { // 显示当前题号与题目总数
    cout << endl << "第 " << n << " 题" << "， 共 " << num << " 题" << endl;
}
