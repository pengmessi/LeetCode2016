//
// Created by hf46p on 2016/5/24.
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

// Forward declaration of isBadVersion API.
bool isBadVersion(int version) {
    return (version >= 1702766719);
}

class Solution {
public:
    int firstBadVersion(int n) {
        long long l = 1, r = n;
        while (l < r) {
            long long mid = (l+r)/2;
            if (isBadVersion(mid)) r = mid;
            else l = mid+1;
        }
        return (int)l;
    }
};

//int main(){
//    Solution sln;
//    cout << sln.firstBadVersion(2126753390) << endl;
//    return 0;
//}