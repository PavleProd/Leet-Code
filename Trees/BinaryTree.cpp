//
// Created by pavle on 26-May-23.
//

#include "BinaryTree.h"
#include <queue>
#include <iostream>

using namespace std;

void BinaryTree::add(int val) {
    auto* node = new TreeNode(val);
    if(!root) {
        root = node;
        return;
    }

    TreeNode* curr = root, *prev = nullptr;
    while(curr) {
        prev = curr;
        if(val <= curr->val) {
            curr = curr->left;
            if(!curr) prev->left = node;
        }
        else {
            curr = curr->right;
            if(!curr) prev->right = node;
        }
    }

}

void BinaryTree::levelOrder() const {
    if(!root) return;
    queue<TreeNode*> nodes;
    nodes.push(root);

    while(!nodes.empty()) {
        TreeNode* node = nodes.front();
        nodes.pop();
        cout << node->val << " ";
        if(node->left) nodes.push(node->left);
        if(node->right) nodes.push(node->right);
    }
    cout << "\n";
}

TreeNode *BinaryTree::invertTree() {
    if(!root) return nullptr;
    queue<TreeNode*> nodes;
    nodes.push(root);

    while(!nodes.empty()) {
        TreeNode* node = nodes.front();
        nodes.pop();
        TreeNode* left = node->left;
        TreeNode* right = node->right;
        node->left = right;
        node->right = left;
        if(right) nodes.push(right);
        if(left) nodes.push(left);
    }

    return root;
}

int BinaryTree::maxDepth() {
    if(!root) return 0;
    int levels = 0;
    queue<TreeNode*> nodes;
    nodes.push(root);
    nodes.push(nullptr); // nullptr kao obelezivac da smo stigli do kraja nivoa
    while(!nodes.empty()) {
        TreeNode* node = nodes.front();
        nodes.pop();
        if(node->left) nodes.push(node->left);
        if(node->right) nodes.push(node->right);
        if(nodes.front() == nullptr) {
            nodes.pop();
            levels++;
            if(!nodes.empty()) { // ako je prazan znaci da smo dosli do kraja stabla
                nodes.push(nullptr);
            }
        }
    }

    return levels;
}
