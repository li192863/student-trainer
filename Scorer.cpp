#include <iostream>
#include <fstream>
#include "Scorer.h"

using namespace std;

void Scorer::statistics(int num) { // 统计得分
    cout << endl << "总共 " << num << " 道题， 正确 " << scores << " 道题， 错误 " << num - scores << " 道题。" << endl;
    cout << "总分 100 分， 你的得分 " << scores / num * 100 << " 分" << endl << endl;
    if (scores != num) {
        cout << "错题请打开输出文件 Statistics.txt 查看。" << endl << endl;
    } else {
        cout << "全对，真厉害！" << endl;
    }
}

void Scorer::addWrongAnswer(Result results) { // 添加错题
    wrongAnswers.push_back(results);
    // cout << wrongAnswers.size() << endl; // used for test
}

void Scorer::fileProcess(int num) { // 文件输出
    fstream file("Statistics.txt", ios::out | ios::trunc);
    file << "总共 " << num << " 道题， 正确 " << scores << " 道题， 错误 " << num - scores << " 道题。" << endl;
    if (!wrongAnswers.empty()) {
        file << "错误结果：" << endl;
    }
    for (auto it = wrongAnswers.begin(); it != wrongAnswers.end(); it++) {
        file << "算式：" << it -> expr << endl;
        file << "正确结果：" << it -> res << "，你的答案：" << it -> ans << endl << endl;
    }
    file.close();
}