//
// Created by pavle on 26-May-23.
//

#ifndef LEET_CODE_BINARYTREE_H
#define LEET_CODE_BINARYTREE_H

#include "TreeNode.h"

class BinaryTree {
private:
    TreeNode* root = nullptr;
    int diameter(TreeNode* curr);
    int balanced(TreeNode* curr);
    int recursionTemp = -1;
public:
    void add(int val);
    void levelOrder() const;
    TreeNode* invertTree();
    int maxDepth();
    int diameterOfBinaryTree();
    bool isBalanced();
};


#endif //LEET_CODE_BINARYTREE_H
