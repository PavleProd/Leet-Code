#include <bits/stdc++.h>
#include "Trees/TreeNode.h"
#include "Trees/BinaryTree.h"

using namespace std;

int main() {
    BinaryTree tree;
    vector<int> values{3, 9, 20, 15, 7};
    for(int val: values) {
        tree.add(val);
    }

    tree.levelOrder();
    cout << tree.maxDepth();
}
