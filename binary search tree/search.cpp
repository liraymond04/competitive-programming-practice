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


TreeNode* search(TreeNode * root, int val) {
    if (root == NULL) {
        return root;
    }
    if (root->val == val) {
        return root;
    }

    if (root->val < val) {
        return search(root->right, val);
    } else {
        return search(root->left, val);
    }
}

TreeNode* searchItr(TreeNode * root, int val) {
    TreeNode* cur = root;

    while (cur != NULL) {
        if (cur->val == val) {
            return cur;
        }

        if (cur->val < val) {
            cur = cur->right;
        } else {
            cur = cur->left;
        }
    }
  
    return cur;
}



int main()
{
TreeNode * root = constructTree();
TreeNode * result = search(root, 7);
cout << "expected: 7, actual: " << result->val << endl;
result = search(root, 12);
cout << "expected: NULL, actual: " << result << endl;
   
result = searchItr(root, 7);
cout << "expected: 7, actual: " << result->val << endl;
result = searchItr(root, 12);
cout << "expected: NULL, actual: " << result << endl;

return 0;
}
