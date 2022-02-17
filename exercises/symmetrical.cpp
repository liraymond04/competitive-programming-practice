#include <iostream>

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

TreeNode* constructSymmetricTree() {
    TreeNode* root = new TreeNode(1);
    TreeNode* leftNode = new TreeNode(2);
    TreeNode* rightNode = new TreeNode(2);
    root->left = leftNode;
    root->right = rightNode;
    
    TreeNode* node = new TreeNode(3);
    leftNode->left = node;
    
    node = new TreeNode(4);
    leftNode->right = node;

    node = new TreeNode(3);
    rightNode->right = node;

    node = new TreeNode(4);
    rightNode->left = node;
    
    return root;
}

TreeNode* constructNonSymmetricTree() {
    TreeNode* root = new TreeNode(1);
    TreeNode* leftNode = new TreeNode(2);
    TreeNode* rightNode = new TreeNode(2);
    root->left = leftNode;
    root->right = rightNode;
    
    TreeNode* node = new TreeNode(3);
    leftNode->right = node;

    node = new TreeNode(3);
    rightNode->right = node;

    return root;
}

bool isSymmetrical(TreeNode* left, TreeNode* right) {
    if (left == NULL && right == NULL) {
        return true;
    } else if (left == NULL || right == NULL) {
        return false;
    }
    
    return (left->data == right->data && isSymmetrical(left->left, right->right) && isSymmetrical(left->right, right->left));
}

int main() {
    TreeNode* root;
    bool result;
    
    root = constructSymmetricTree();
    result = isSymmetrical(root, root);
    cout << result << endl;

    root = constructNonSymmetricTree();
    result = isSymmetrical(root, root);
    cout << result << endl;
    
    return 0;
}