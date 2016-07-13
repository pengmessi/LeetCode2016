//
// Created by hf46p on 2016/7/7.
//

#include "IncludeHelper.h";

/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
class Solution {
private:
    int minusSum = 0;
    int maxLayer = 0;
    int sum = 0;

    void foo(vector<NestedInteger>& nestedList, int layer) {
        maxLayer = max(maxLayer, layer);
        for (auto e : nestedList) {
            if (e.isInteger()) {
                int tmp = e.getInteger();
                sum += tmp;
                minusSum += layer * tmp;
            } else {
                foo(e.getList(), layer + 1);
            }
        }
    }

public:
    int depthSumInverse(vector<NestedInteger>& nestedList) {
        foo(nestedList,1);
        return sum * (maxLayer + 1) - minusSum;
    }
};