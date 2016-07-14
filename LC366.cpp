//
// Created by hf46p on 2016/7/13.
//


#include "IncludeHelper.h";

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

struct TreeNode {
         int val;
         TreeNode *left;
         TreeNode *right;
         TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    unordered_map<TreeNode*, TreeNode*> father;
    unordered_map<TreeNode*, TreeNode*> numOfC;
    unordered_set<TreeNode*> nodeSet;

    void foo(TreeNode* node) {
        nodeSet.insert(node);

        if (node->left) {
            father[node->left] = node;
            numOfC[node] ++;
            foo(node->left);
        }
        if (node->right) {
            father[node->right] = node;
            numOfC[node] ++;
            foo(node->right);
        }
    }

    vector<vector<int>> findLeaves(TreeNode* root) {
        vector<vector<int>> ans;
        if (!root) return ans;

        foo(root);

        vector<TreeNode*> tmp;
        for (auto node : nodeSet) {
            if (numOfC[node] == 0) {
                tmp.push_back(node);
            }
        }

        while (!tmp.empty()) {
            vector<int> numTmp;
            for (auto e:tmp)
                numTmp.push_back(e->val);
            ans.push_back(numTmp);

            vector<TreeNode*> next(tmp);
            tmp.clear();
            for (auto node : next) {
                numOfC[father[node]] --;
                if (numOfC[father[node]] == 0) {
                    tmp.push_back(father[node]);
                }
            }
        }

        return  ans;
    }
};