//
// Created by hf46p on 2016/6/21.
//
#include "IncludeHelper.h";

class Solution {
private:
    int ans;

    int foo(vector<int> &a, int k) {
        int m = INT_MIN;

        unsigned long n = a.size() + 1;
        vector<int> s(n,0);
        for (int i=1;i<=a.size();++i)
            s[i] = s[i-1] + a[i-1];
        sort(s.begin(), s.end());
        for (int c:s) cout << c << ",";
        cout << endl;
        int j=0;
        for (int i=0;i<n;++i) {
            int key = s[i] + k;
            while (j<n && s[j] <= key) {
                if (j!=i && s[j]-s[i]<=k) m = max(m, s[j] - s[i]);
                ++j;
            }
            --j;
        }

        return m;
    }

public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        if (matrix.empty() || matrix[0].empty()) return 0;

        int nrow = matrix.size(), ncol = matrix[0].size();
        ans = INT_MIN;
        for (int col1 = 0; col1 < ncol; ++ col1) {
            vector<int> a(nrow, 0);
            for (int col2 = col1; col2 < ncol; ++col2) {
                for (int i = 0; i < nrow; ++i)
                    a[i] += matrix[i][col2];
                //cout << a[0] << endl;
                int tmp = foo(a, k);

                ans = max(ans, tmp);
                if (ans==3) cout << col1 << "~" << col2 << endl;
                if (ans == k) return ans;
            }
        }

        return ans;
    }
};