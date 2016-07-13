//
// Created by hf46p on 2016/5/20.
// https://leetcode.com/problems/game-of-life/
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

class Solution {
public:
    void addinfo(vector<vector<int>>& board, int r, int c) {
        if (r>=0 && r<board.size() && c>=0 && c<board[0].size())
            board[r][c] += 2;
    }


    void gameOfLife(vector<vector<int>>& board) {
        if (board.empty() || board[0].empty()) return;
        unsigned long m = board.size(), n = board[0].size();
        int d[8][2] = {{-1,-1}, {-1,0}, {-1,1}, {0,-1}, {0,1}, {1,-1}, {1,0}, {1,1}};

        for (int i=0; i<m; ++i)
            for (int j=0; j<n; ++j)
                if (board[i][j] & 1) {
                    for (int k = 0; k<8; ++k)
                        addinfo(board, i+d[k][0], j+d[k][1]);
                }

        for (int i=0; i<m; ++i)
            for (int j=0; j<n; ++j) {
                int num = board[i][j] >> 1;

                if (num <= 1 || num > 3) board[i][j] = 0;
                else if (num == 3) board[i][j] = 1;
                else board[i][j] = board[i][j] & 1;

            }
    }
};
