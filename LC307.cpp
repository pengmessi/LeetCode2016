//
// Created by hf46p on 2016/5/17.
// 307. Range Sum Query - Mutable
// https://leetcode.com/problems/range-sum-query-mutable/
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

class NumArray {
private:
    int lowbit(int x){
        return x&(-x);
    }

    int sum(int i){
        int s = 0;
        for (int k = i+1;k>0;k-=lowbit(k))
            s += indexTree[k];
        return s;
    }

    vector<int> indexTree;
    vector<int> a;
    unsigned long n;
public:


    NumArray(vector<int> &nums): n(nums.size()) {
        a.resize(n+1);
        indexTree.resize(n+1);
        for (int i=0;i<n; ++i)
            update(i, nums[i]);
    }

    void update(int i, int val) {
        int old_val = a[i+1];
        for (int k=i+1;k<=n;k+=lowbit(k)) {
            indexTree[k] += (val - old_val);
        }
        a[i+1] = val;
    }

    int sumRange(int i, int j) {
        return sum(j) - sum(i-1);
    }
};

int lowbit(int x){
    return x&(-x);
}
// Your NumArray object will be instantiated and called as such:
// NumArray numArray(nums);
// numArray.sumRange(0, 1);
// numArray.update(1, 10);
// numArray.sumRange(1, 2);

//int main() {
//
//    int k = 9;
//    cout << k + lowbit(k) << endl;
//    cout << k - lowbit(k) << endl;
//    return 0;
//}
