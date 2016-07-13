#include "IncludeHelper.h"
#include "LC363.cpp"

int main() {
    Solution sln;
    vector<vector<int>> mat;
//    mat.push_back(vector<int>({5,-4,-3,-4}));
//    mat.push_back(vector<int>({-3,-4,4,5}));
//    mat.push_back(vector<int>({5,1,5,-4}));
    mat.push_back(vector<int>({5}));
    mat.push_back(vector<int>({-3}));
    mat.push_back(vector<int>({5}));
    cout << sln.maxSumSubmatrix(mat, 3);

    return 0;
}

