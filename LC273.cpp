//
// Created by hf46p on 2016/5/24.
// https://leetcode.com/problems/integer-to-english-words/
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
private:
    const string word[10] = {"Zero", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine"};
    const string word10[10] = {"N/A", "Ten", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
    const string wordTeen[10] = {"Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};

    string get_read(int n) {
        int num100 = n / 100;
        int num10  = (n / 10) % 10;
        int num1   = n % 10;
        string s;
        if (num100) s += word[num100] + " Hundred ";
        if (num10 == 1) {
            s += wordTeen[num1] + " ";
        }
        else {
            if (num10) s += word10[num10] + " ";
            if (num1)  s += word[num1]  + " ";
        }

        return s;
    }

public:
    string numberToWords(int num) {
        int billion = num / 1000000000;
        int million = (num / 1000000) % 1000;
        int thousand = (num / 1000) % 1000;
        int rest = num % 1000;
        string str;
        if (billion) str += get_read(billion) + "Billion ";
        if (million) str += get_read(million) + "Million ";
        if (thousand) str += get_read(thousand) + "Thousand ";
        if (rest) str += get_read(rest);

        if (str == "") str = word[0];
        else {
            if (str[str.size()-1]==' ') str = str.substr(0,str.size()-1);
        }

        return str;
    }
};

