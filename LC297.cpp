//
// Created by hf46p on 2016/5/20.
// https://leetcode.com/problems/serialize-and-deserialize-binary-tree/
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

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        queue<TreeNode*> que;
        string serial;
        que.push(root);
        while (!que.empty()) {
            TreeNode* node = que.front();
            que.pop();

            if (!node)
                serial += "#,";
            else {
                serial += to_string(node->val) + ",";
                que.push(node->left);
                que.push(node->right);
            }
        }
        return serial;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data=="" || data=="#,") return NULL;

        stringstream ss(data);
        string item;

        int p = 0;
        getline(ss,item,',');

        TreeNode* root = new TreeNode(atoi(item.c_str()));

        queue<TreeNode*> que;
        que.push(root);
        while (!que.empty()) {
            TreeNode* node = que.front();
            que.pop();

            if (getline(ss, item, ',') && item!="#") {
                node->left = new TreeNode(atoi(item.c_str()));
                que.push(node->left);
            }

            if (getline(ss, item, ',') && item!="#") {
                node->right= new TreeNode(atoi(item.c_str()));
                que.push(node->right);
            }
        }

        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));

