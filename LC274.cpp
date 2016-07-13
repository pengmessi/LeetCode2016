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
    bool operator () (const int i, const int j) {
        return (i>j);
    }

    int hIndex(vector<int>& citations) {
        if (citations.empty()) return 0;

        sort(citations.begin(), citations.end(), *this);
        int ans = 0, n = citations.size();
        for (int i = n; i >= 1; -- i) {
            if (citations[i-1] >= i && (i == n || citations[i] <= i)) {
                ans = i;
                break;
            }
        }
        return ans;
    }
};