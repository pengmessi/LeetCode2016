//
// Created by hf46p on 2016/5/19.
//
#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
using namespace std;


class NumMatrix {
private:
    vector<vector<int>> summ;
    unsigned long n,m;
public:
    NumMatrix(vector<vector<int>> &matrix){
        if (matrix.empty()) return;
        n = matrix.size();
        m = matrix[0].size();
        summ.resize(n+1, vector<int>(m+1));
        for (int i=1;i<=n;++i)
            for (int j=1;j<=m;++j)
                summ[i][j] = summ[i-1][j] + summ[i][j-1] + matrix[i-1][j-1] - summ[i-1][j-1];
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        return (summ[row1][col1] + summ[row2+1][col2+1] - summ[row1][col2+1] - summ[row2+1][col1]);
    }
};