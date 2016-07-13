//
// Created by hf46p on 2016/5/23.
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
    vector<int> singleNumber(vector<int>& nums) {
        int value = 0;
        for (int i=0; i<nums.size(); ++i) {
            value ^= nums[i];
        }
        int bit = 1;
        while ((value & bit)==0) {
            bit <<= 1;
        }


        value = 0;
        int value1 = 0;
        for (auto i: nums)
            if (i & bit) value ^= i;
            else
                value1 ^= i;
        return vector<int>({value, value1});
    }
};

//int main(){
//    Solution sln;
//    vector<int> a({0,1,1,2});
//    sln.singleNumber(a);
//    return 0;
//}