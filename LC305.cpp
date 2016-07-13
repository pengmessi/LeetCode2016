//
// Created by hf46p on 2016/5/19.
// 305. Number of Islands II
// https://leetcode.com/problems/number-of-islands-ii/
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

struct SimpleHash {
    size_t operator()(const pair<int, int>& p) const {
        return (hash<int>()(p.first) + hash<int>()(p.second));
    }
};

class UnionFind {
private:
    unordered_map<pair<int,int>, pair<int,int>, SimpleHash> father;
    int size = 0;
public:
//    UnionFind(vector<pair<int, int>>& positions){
//        for (auto pos: positions) {
//            father[pos] = pos;
//        }
//    }
    UnionFind(){
    }

    void add(pair<int,int> a){
        father[a] = a;
        ++ size;
    }

    pair<int,int> findRoot(pair<int,int> a) {
        pair<int,int> i = a;
        while (father[i] != i) i = father[i];
        pair<int,int> root = i;
        i = a;
        while (i != root) {
            pair<int,int> next = father[i];
            father[i] = root;
            i = next;
        }

        return root;
    };

    void merge(pair<int, int> a, pair<int,int> b){
        pair<int, int> rootA = findRoot(a);
        pair<int, int> rootB = findRoot(b);
        if (rootA!=rootB){
            father[rootA] = rootB;
            -- size;
        }
    }

    int countSet(){
        return size;
    }
};

class Solution {
private:
    unordered_set<pair<int,int>, SimpleHash>  S;

public:
    vector<int> numIslands2(int m, int n, vector<pair<int, int>>& positions) {
        UnionFind uni;
        vector<int> res;

        for (int i=0; i<positions.size(); ++i) {
            auto pos = positions[i];
            int r = pos.first;
            int c = pos.second;

            S.insert(positions[i]);
            uni.add(positions[i]);

            if (S.find(pair<int,int>(r-1, c)) != S.end()) {
                uni.merge(pair<int,int>(r-1,c), pair<int,int>(r,c));
            }
            if (S.find(pair<int,int>(r, c+1)) != S.end()) {
                uni.merge(pair<int,int>(r,c+1), pair<int,int>(r,c));
            }
            if (S.find(pair<int,int>(r+1, c)) != S.end()) {
                uni.merge(pair<int,int>(r+1,c), pair<int,int>(r,c));
            }
            if (S.find(pair<int,int>(r, c-1)) != S.end()) {
                uni.merge(pair<int, int>(r, c - 1), pair<int, int>(r, c));
            }
            res.push_back(uni.countSet());
        }
        return res;
    }
};
//
//int main(){
//    Solution sln;
//    vector<pair<int, int>> p;
//    p.push_back(pair<int,int>(0,0));
//    p.push_back(pair<int,int>(0,1));
//    p.push_back(pair<int,int>(1,2));
//    p.push_back(pair<int,int>(2,1));
//
//    vector<int> ans = sln.numIslands2(3,3, p);
//    for (auto i : ans)
//        cout << i << " ";
//    cout << endl;
//    return 0;
//}