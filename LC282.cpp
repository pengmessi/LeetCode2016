//
// Created by hf46p on 2016/5/24.
// https://leetcode.com/problems/expression-add-operators/
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
    void dfs(string rest, string gen, long long diff, long long cur, vector<string>& res, long long target) {
        if (rest=="") {
            if  (cur == target) {
                cout << "cur = " << cur << " target = " << target << endl;
                res.push_back(gen);
                return;
            }
        }
        else {

        }
        if (gen!="") {
            for (size_t i=0;i<rest.size();++i) {
                long long num = atoll(rest.substr(0,i+1).c_str());
                dfs(rest.substr(i+1), gen + "*" + rest.substr(0,i+1), diff*num, (cur-diff) + diff * num, res, target);
                dfs(rest.substr(i+1), gen + "+" + rest.substr(0,i+1), num, cur+num, res, target);
                dfs(rest.substr(i+1), gen + "-" + rest.substr(0,i+1), -num, cur-num, res, target);

                if (rest[0] == '0') break;
            }
        }
        else {
            for (size_t i=0;i<rest.size();++i) {
                long long num = atoll(rest.substr(0,i+1).c_str());
                dfs(rest.substr(i+1), rest.substr(0,i+1), num, num, res, target);
                if (rest[0] == '0') break;
            }
        }
    }

    vector<string> addOperators(string num, long long target) {
        vector<string> res;
        dfs(num, "", 0, 0, res, target);
        return res;
    }
};

//int main() {
//    Solution sln;
//    vector<string> a = sln.addOperators("2147483648", -2147483648);
//    for (auto i : a) cout << i << endl;
//    return 0;
//}