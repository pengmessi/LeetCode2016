//
// Created by hf46p on 2016/5/17.
// 146. LRU Cache
// https://leetcode.com/problems/lru-cache/
//

#include <map>
#include <set>
#include <list>
#include <unordered_map>
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

class LRUCache{
private:
    int cap;
    list<pair<int,int>> LRU_list;
    unordered_map<int, list<pair<int,int>>::iterator> LRU_map;
public:
    LRUCache(int capacity): cap(capacity){

    }

    int get(int key) {
        int value;
        if (LRU_map.find(key) != LRU_map.end()) {
            list<pair<int,int>>::iterator it = LRU_map[key];
            value = it->second;
            LRU_list.erase(it);
            LRU_list.push_front(pair<int,int>(key, value));
            LRU_map[key] = LRU_list.begin();
        }
        else value = -1;

        return value;
    }

    void set(int key, int value) {
        if (LRU_map.find(key) != LRU_map.end()) {
            list<pair<int,int>>::iterator it = LRU_map[key];
            LRU_list.erase(it);
            LRU_list.push_front(pair<int,int>(key, value));
        }
        else {
            LRU_list.push_front(pair<int,int>(key, value));
            if (LRU_list.size() > cap) {
                int k = LRU_list.back().first;
                LRU_list.pop_back();
                LRU_map.erase(k);
            }
        }
        LRU_map[key] = LRU_list.begin();
    }
};
//
//int main() {
//    LRUCache lru(1);
//    lru.set(2,1);
//    cout << lru.get(2) << endl;
//    lru.set(3,2);
//    cout << lru.get(2) << endl;
//    cout << lru.get(3) << endl;
//    return 0;
//}