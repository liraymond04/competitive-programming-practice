#include <iostream>
#include <vector>
#include <queue>
#include <stack>

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

void preOrder(TreeNode* root) {
    if (root == NULL) return;
    cout << root->data << " ";
    preOrder(root->left);
    preOrder(root->right);
}

void inOrder(TreeNode* root) {
    if (root == NULL) return;
    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);
}

void postOrder(TreeNode* root) {
    if (root == NULL) return;
    postOrder(root->left);
    postOrder(root->right);
    cout << root->data << " ";
}

void preOrderIterative(TreeNode* root) {
    stack<TreeNode*> s;

    s.push(root);

    while (!s.empty()) {
        cout << s.top()->data << " ";
        TreeNode* left = s.top()->left;
        TreeNode* right = s.top()->right;
        s.pop();
        if (right != NULL)
            s.push(right);
        if (left != NULL)
            s.push(left);
    }
}

void inOrderIterative(TreeNode* root) {
    stack<TreeNode*> s;

    TreeNode* cur;
    cur = root;
    while(!s.empty() || cur != NULL) {
        while (cur != NULL) {
            s.push(cur);
            cur = cur->left;
        }
        cout << s.top()->data << " ";
        cur = s.top();
        s.pop();
        cur = cur->right;
    }
}
void postOrderIterative(TreeNode* root) {
  
}

void levelTraversal(TreeNode* root) {
    queue<TreeNode*> q;
    
    q.push(root);

    while (!q.empty()) {
        TreeNode* cur = q.front();
        cout << cur->data << " ";
        if (cur->left != NULL)
            q.push(cur->left);
        if (cur->right != NULL)
            q.push(cur->right);
        q.pop();
    }
}

int main()
{
    TreeNode * root = constructTree();
    preOrder(root);
    cout<<endl;
    inOrder(root);
    cout<<endl;
    postOrder(root);
    cout<<endl;
    inOrderIterative(root);
    cout<<endl;
    levelTraversal(root);

    return 0;
}
