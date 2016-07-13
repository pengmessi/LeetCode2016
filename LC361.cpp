//
// Created by hf46p on 2016/6/21.
//
#include "IncludeHelper.h";

class Solution {
private:
    vector<vector<short>> rowSum, colSum;

    int RowSum(int r, int j0, int j1) {
        if (j0>0) return rowSum[r][j1] - rowSum[r][j0-1];
        else return rowSum[r][j1];
    }

    int ColSum(int c, int i0, int i1) {
        if (i0>0) return colSum[i1][c] - colSum[i0-1][c];
        else return colSum[i1][c];
    }

public:
    int maxKilledEnemies(vector<vector<char>>& grid) {
        if (grid.empty() || grid[0].empty()) return 0;

        unsigned long m = grid.size(), n = grid[0].size();
        vector<vector<short>> left(m, vector<short>(n)), right(m, vector<short>(n)), up(m, vector<short>(n)) ,down(m, vector<short>(n));
        rowSum.resize(m, vector<short>(n));
        colSum.resize(m, vector<short>(n));

        for (int i=0;i<m;++i)
            for (int j=0;j<n;++j) {
                if (j==0) rowSum[i][j] = (short)(grid[i][j] == 'E');
                else rowSum[i][j] = rowSum[i][j-1] + (short)(grid[i][j] == 'E');
                if (i==0) colSum[i][j] = (short)(grid[i][j] == 'E');
                else colSum[i][j] = colSum[i-1][j] + (short)(grid[i][j] == 'E');
            }

        for (int i=0; i<m; ++i)
            for (int j=0; j<n; ++j) {
                if (j==0 || grid[i][j-1] == 'W') left[i][j] = j;
                else left[i][j] = left[i][j-1];

                if (i==0 || grid[i-1][j] == 'W') up[i][j] = i;
                else up[i][j] = up[i-1][j];
            }

        for (int i=m-1; i>=0; --i)
            for (int j=n-1; j>=0; --j) {
                if (j==n-1 || grid[i][j+1] == 'W') right[i][j] = j;
                else right[i][j] = right[i][j+1];

                if (i==m-1 || grid[i+1][j] == 'W') down[i][j] = i;
                else down[i][j] = down[i+1][j];
            }

        int ans = 0;
        for (int i=0;i<m;++i)
            for (int j=0;j<n;++j)
                if (grid[i][j] == '0') {
                    ans = max(ans, RowSum(i, left[i][j], j) + RowSum(i, j, right[i][j])
                                   + ColSum(j, up[i][j], i) + ColSum(j, i, down[i][j]) );
                }

        return ans;
    }
};

//0E000E00
//E0WEE0WE
//0E000E00