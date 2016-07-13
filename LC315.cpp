//
// Created by hf46p on 2016/5/22.
// https://leetcode.com/problems/count-of-smaller-numbers-after-self/
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
#include <unordered_set>
#include <unordered_map>

using namespace std;

class Solution {
private:
    vector<int> index;

    int lowbit(int x){
        return x&(-x);
    }
    void update(int k) {
        for (int i=k+1;i<index.size();i+=lowbit(i))
            ++ index[i];
    }
    int sum(int k) {
        int s = 0;
        for (int i=k+1;i>0;i-=lowbit(i))
            s += index[i];
        return s;
    }

public:
    vector<int> countSmaller(vector<int>& nums) {
        unordered_set<int> numset;
        vector<int> lst;
        for (auto i: nums) {
            numset.insert(i);
        }
        for (auto i : numset) {
            lst.push_back(i);
        }
        sort(lst.begin(), lst.end());
        unordered_map<int,int> mp;
        for (int i=0;i<lst.size(); ++i)
            mp[lst[i]] = i;

        vector<int> res;
        index.resize(lst.size()+1);
        res.resize(nums.size());
        for (int i=nums.size()-1; i>=0; --i) {
            res[i] = sum(mp[nums[i]]-1);
            update(mp[nums[i]]);
        }

        return res;
    }
};