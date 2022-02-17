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

TreeNode* getMin(TreeNode * root) {
    TreeNode* cur = root;

    while (cur->left != NULL) {
        cur = cur->left;
    }
    
    return cur;
}


TreeNode * successor(TreeNode *root, int val, TreeNode* parent) {
    if (root == NULL) {
        return NULL;
    }
    if (root->val == val) {
        if (root->right == NULL)
            return parent;
        else
            return getMin(root->right);
    }

    if (val < root->val) {
        return successor(root->left, val, root);
    } else {
        return successor(root->right, val, parent);
    }
}


TreeNode * precessor(TreeNode *root, int val) {
return root;

}

int main()
{
   
TreeNode* root = constructTree();
TreeNode* suc = successor(root, 3, NULL);
cout << "expected: 4, actual: " << suc->val<< endl;
suc = successor(root, 7, NULL);
cout << "expected: 8, actual: " << suc->val<< endl;
   
   
TreeNode* pre = precessor(root, 3);
cout << "expected: 1, actual: " << pre->val<< endl;
pre = precessor(root, 13);
cout << "expected: 8, actual: " << pre->val<< endl;
   
return 0;
}
