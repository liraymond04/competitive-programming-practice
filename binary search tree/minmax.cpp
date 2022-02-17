#include <iostream>
#include <vector>
#include <queue>
#include <stack>

using namespace std;
class TreeNode {
public:
    TreeNode(int v) {
        val = v;
        left = NULL;
        right = NULL;
    }
    int val;
    TreeNode* left;
    TreeNode* right;
};

TreeNode* constructTree() {
    TreeNode* root = new TreeNode(8);
    TreeNode* leftNode = new TreeNode(3);
    TreeNode* rightNode = new TreeNode(10);
    root->left = leftNode;
    root->right = rightNode;
    
    TreeNode* node = new TreeNode(1);
    leftNode->left = node;
    
    node = new TreeNode(6);
    leftNode->right = node;
    
    leftNode = node;
    node = new TreeNode(4);
    leftNode->left = node;
    
    node = new TreeNode(7);
    leftNode->right = node;
    
    node = new TreeNode(14);
    rightNode->right = node;
    
    rightNode = node;
    node = new TreeNode(13);
    rightNode->left = node;
    
    return root;
    
}


int getMin(TreeNode * root) {
    TreeNode* cur = root;

    while (cur->left != NULL) {
        cur = cur->left;
    }
    
    return cur->val;
}

int getMax(TreeNode * root) {
    TreeNode* cur = root;

    while (cur->right != NULL) {
        cur = cur->right;
    }
    
    return cur->val;
}


int main()
{
TreeNode * root = constructTree();
cout << "expected min: 1, actual: " << getMin(root) << endl;
cout << "expected max: 14, actual: " << getMax(root) << endl;
   
return 0;
   
   
}
