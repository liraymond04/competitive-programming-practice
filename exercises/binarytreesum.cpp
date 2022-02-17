#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <math.h>

using namespace std;
class TreeNode {
public:
    TreeNode(int d) {
        data = d;
        left = NULL;
        right = NULL;
    }
    int data;
    TreeNode* left;
    TreeNode* right;
};

TreeNode* constructTree() {
    TreeNode* root = new TreeNode(2);
    TreeNode* leftNode = new TreeNode(7);
    TreeNode* rightNode = new TreeNode(5);
    root->left = leftNode;
    root->right = rightNode;
    
    TreeNode* node = new TreeNode(2);
    leftNode->left = node;
    
    node = new TreeNode(6);
    leftNode->right = node;
    
    leftNode = node;
    node = new TreeNode(5);
    leftNode->left = node;
    
    node = new TreeNode(11);
    leftNode->right = node;
    
    node = new TreeNode(9);
    rightNode->right = node;
    
    rightNode = node;
    node = new TreeNode(4);
    rightNode->left = node;
    
    return root;
}

int preOrder(TreeNode* root) {
    int count = 0;
    stack<TreeNode*> s;

    s.push(root);

    while (!s.empty()) {
        count += s.top()->data;
        TreeNode* left = s.top()->left;
        TreeNode* right = s.top()->right;
        s.pop();
        if (right != NULL)
            s.push(right);
        if (left != NULL)
            s.push(left);
    }

    return count;
}

int main() {
    TreeNode* root;
    root = constructTree();

    cout << abs(preOrder(root->left) - preOrder(root->right));

    return 0;
}