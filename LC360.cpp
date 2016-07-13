//
// Created by hf46p on 2016/6/21.
//

#include "IncludeHelper.h";

class Solution {
private:
    int foo(int x, int a, int b, int c) {
        return a*x*x + b*x + c;
    }

public:
  vector<int> sortTransformedArray(vector<int>& nums, int a, int b, int c) {
        vector<int> res;
        if (nums.empty()) return res;

        double y = -(double)b/(a*2);

        int i = 0, j = nums.size()- 1;
        if (a >= 0) {
            while (i<=j) {
                if (foo(nums[i], a, b, c) > foo(nums[j], a, b, c)) {
                    res.push_back(foo(nums[i++], a, b, c));
                } else {
                    res.push_back(foo(nums[j--], a, b, c));
                }
            }
            for (int i=0;i<res.size()/2;++i) {
                int t = res[i];
                res[i] = res[res.size()-i-1];
                res[res.size()-i-1] = t;
            }

        } else if (a < 0) {
            while (i<=j) {
                if (foo(nums[i], a, b, c) < foo(nums[j], a, b, c)) {
                    res.push_back(foo(nums[i++], a, b, c));
                } else {
                    res.push_back(foo(nums[j--], a, b, c));
                }
            }
        }

        return res;
    }
};