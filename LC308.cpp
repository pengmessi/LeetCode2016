//
// Created by hf46p on 2016/5/18.
// 308. Range Sum Query 2D - Mutable
// https://leetcode.com/problems/range-sum-query-2d-mutable/
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
    int lowbit(int x){
        return x&(-x);
    }
    vector<vector<int>> mat;
    vector<vector<int>> index;
    unsigned long n,m;

public:
    NumMatrix(vector<vector<int>> &matrix) {
        if (matrix.empty() || matrix[0].empty()) return;
        n = matrix.size();
        m = matrix[0].size();
        mat.resize(n+1, vector<int>(m+1));
        index.resize(n+1, vector<int>(m+1));
        for (int i=0;i<n;++i)
            for (int j=0;j<m;++j)
                update(i,j,matrix[i][j]);
    }

    void update(int row, int col, int val) {
        int old_val = mat[row+1][col+1];
        for (int i=row+1; i<=n; i+=lowbit(i))
            for (int j = col+1; j<=m; j+=lowbit(j)){

                index[i][j] -= old_val;
                index[i][j] += val;
            }
        mat[row+1][col+1] = val;
    }

    int sum(int row, int col){
        int s = 0;
        for (int i=row+1;i>0;i-=lowbit(i))
            for (int j=col+1;j>0;j-=lowbit(j))
                s += index[i][j];
        return s;
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        return (sum(row2,col2) - sum(row1-1, col2) - sum(row2, col1-1) + sum(row1-1, col1-1));
    }
};
//3 0 1 4 2
//5 6 3 2 1
//1 2 0 1 5
//4 1 0 1 7
//1 0 3 0 5

//int main() {
//    vector<vector<int>> a;
//    a.push_back(vector<int>({1,1,1,1,1}));
//    a.push_back(vector<int>({1,1,1,1,1}));
//    a.push_back(vector<int>({1,1,1,1,1}));
//    a.push_back(vector<int>({1,1,1,1,1}));
//    a.push_back(vector<int>({1,1,1,1,1}));
//    NumMatrix numMatrix(a);
//    cout << numMatrix.sumRegion(0, 1, 2, 3) << endl;
//    numMatrix.update(1, 1, 10);
//    cout << numMatrix.sumRegion(1, 2, 3, 4) << endl;
//
//    return 0;
//}