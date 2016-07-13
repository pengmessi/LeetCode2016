//
// Created by hf46p on 2016/5/20.
// https://leetcode.com/problems/smallest-rectangle-enclosing-black-pixels/
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
private:
    int colSum(vector<vector<char>>& image, int col){
        int s=0;
        for (int i=0;i<image.size(); ++i)
            if (image[i][col] == '1') {
                s = 1;
                break;
            }
        return s;
    }

    int rowSum(vector<vector<char>>& image, int row){
        int s=0;
        for (int i=0;i<image[0].size(); ++i)
            if (image[row][i] == '1') {
                s = 1;
                break;
            }
        return s;
    }

    int search_col_l(vector<vector<char>>& image, int l, int r){
        while (l<r) {
            int mid = (l+r)/2;
            if (colSum(image, mid)==1) r = mid;
            else l = mid + 1;
        }
        return l;
    }

    int search_col_r(vector<vector<char>>& image, int l, int r){
        while (l<r) {
            int mid = (l+r+1)/2;
            if (colSum(image, mid)==1) l = mid;
            else r = mid - 1;
        }
        return l;
    }

    int search_row_u(vector<vector<char>>& image, int l, int r){
        while (l<r) {
            int mid = (l+r)/2;
            if (rowSum(image, mid)==1) r = mid;
            else l = mid + 1;
        }
        return l;
    }

    int search_row_d(vector<vector<char>>& image, int l, int r){
        while (l<r) {
            int mid = (l+r+1)/2;
            if (rowSum(image, mid)==1) l = mid;
            else r = mid - 1;
        }
        return l;
    }

public:
    int minArea(vector<vector<char>>& image, int x, int y) {
        if (image.empty() || image[0].empty()) return 0;

        int lcol = search_col_l(image, 0, y);
        int rcol = search_col_r(image, y, (int)image[0].size()-1);
        int urow = search_row_u(image, 0, x);
        int drow = search_row_d(image, x, (int)image.size()-1);

        return (rcol - lcol +1 ) * (drow - urow + 1);
    }
};