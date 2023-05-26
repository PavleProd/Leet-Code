//
// Created by pavle on 26-May-23.
//

#ifndef LEET_CODE_BINARYTREE_H
#define LEET_CODE_BINARYTREE_H

#include "TreeNode.h"

class BinaryTree {
private:
    TreeNode* root = nullptr;
public:
    void add(int val);
    void levelOrder() const;
    TreeNode* invertTree();
    int maxDepth();
};


#endif //LEET_CODE_BINARYTREE_H
