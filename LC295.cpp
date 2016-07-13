//
// Created by hf46p on 2016/5/21.
// https://leetcode.com/problems/find-median-from-data-stream/
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

class MedianFinder {
private:
    priority_queue<int> max_q;
    priority_queue<int, vector<int>, greater<int>> min_q;

public:

    // Adds a number into the data structure.
    void addNum(int num) {
        if (!max_q.empty() && num <= max_q.top()) max_q.push(num);
        else min_q.push(num);

        if (max_q.size() > min_q.size()) {
            int tmp = max_q.top();
            max_q.pop();
            min_q.push(tmp);
        }
        else if (min_q.size() > max_q.size() + 1) {
            int tmp = min_q.top();
            min_q.pop();
            max_q.push(tmp);
        }
//        cout << "\naddNum\n" << min_q.size() << " " << max_q.size() << endl;
    }

    // Returns the median of current data stream
    double findMedian() {
        if (min_q.size() == max_q.size())
            return 0.5 * (min_q.top() + max_q.top());
        else
            return min_q.top();
    }
};

//int main(){
//    MedianFinder mf;
//    mf.addNum(1);
//    mf.addNum(2);
//    cout << mf.findMedian();
//    mf.addNum(5);
//    cout << mf.findMedian();
//    return 0;
//}

// Your MedianFinder object will be instantiated and called as such:
// MedianFinder mf;
// mf.addNum(1);
// mf.findMedian();