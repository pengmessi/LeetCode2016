//
// Created by hf46p on 2016/5/17.
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
    int findDuplicate(vector<int>& nums) {
        int l = 1, r = nums.size();
        while (l < r) {
            int mid = (l+r)/2;
            int cnt = 0;
            for (auto i:nums)
                cnt += (i <= mid);
            if (cnt <= mid)
                l = mid + 1;
            else
                r = mid;
        }

        return l;
    }
};

//int main() {
//    Solution sln;
//    vector<int> a({1,1,2,4,3});
//    cout << sln.findDuplicate(a);
//    return 0;
//}

/*
 *   1 2 3 4 5 6
 *   2 3 4 1 6 5
 *
 *
 */