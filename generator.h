#pragma once
#include <vector>

class Generator {

    std::vector<int> x;
    std::vector<int> sampleResult;
    std::vector<int> index;

public:
    int n, k;
    int rec = 1;
    int defoult = 1;
    Generator(int n, int k);
    void Generate();
    bool Check(std::vector<int>, int);
    void Rec(int, int);
    void Print(std::vector<int>);
    std::vector<int> Reset(int id);
    void clear();
};

