#pragma once
#ifndef SCORE_H
#define SCORE_H
#include <vector>
#include <string>

struct Result {
    int res = 0; // 正确结果
    std::string expr = ""; // 表达式
    int ans = 0; // 输入结果
};

class Scorer {
public: 
    Scorer() {}
    ~Scorer() {}
    void addScores() {scores++;}
    int getScores() {return scores;}
    void addWrongAnswer(Result results);
    void statistics(int num);
    void fileProcess(int num);
private:
    double scores = 0;
    std::vector<Result> wrongAnswers;
};

#endif // !SCORE_H