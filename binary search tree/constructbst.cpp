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

bool isSameTree(TreeNode * root1, TreeNode *root2) {
    if (root1 == NULL && root2 == NULL) return true;
    else if (root1 != NULL && root2 != NULL) {
        return (root1->val == root2->val) && 
                isSameTree(root1->left, root2->left) &&
                isSameTree(root1->right, root2->right);
    }
    else {
        return false;
    }
}

void construct(TreeNode* root, int num) {
    if (num < root->val) {
        if (root->left == NULL) {
            TreeNode* add = new TreeNode(num);
            root->left = add;
        } else {
            construct(root->left, num);
        }
    } else {
        if (root->right == NULL) {
            TreeNode* add = new TreeNode(num);
            root->right = add;
        } else {
            construct(root->right, num);
        }
    }
}

TreeNode * constructBST(const vector<int> &data) {
    if (data.size() == 0) return NULL;
    TreeNode *root = new TreeNode(data[0]);

    for (int i=1; i<data.size(); i++) {
        construct(root, data[i]);
    }

    return root;
}

void constructItr(TreeNode* root, int num) {
    TreeNode* cur = root;

    while (cur != NULL) {
        if (num < cur->val) {
            cur = cur->left;
        } else {
            cur = cur->right;
        }
    }

    TreeNode* add = new TreeNode(num);
    cur = add;
}

void constructItr1 (TreeNode* root, int num) {
    TreeNode* cur = root;

    while (cur != NULL) {
        if (num < cur->val) {
            if (cur->left == NULL) {
                TreeNode* add = new TreeNode(num);
                cur->left = add;
                break;
            } else {
                cur = cur->left;
            }
        } else {
            if (cur->right == NULL) {
                TreeNode* add = new TreeNode(num);
                cur->right = add;
                break;
            } else {
                cur = cur->right;
            }
        }
    }
}

TreeNode * constructBSTItr(const vector<int> &data) {
    if (data.size() == 0) return NULL;
    
    TreeNode *root = new TreeNode(data[0]);

    for (int i=1; i<data.size(); i++) {
        constructItr(root, data[i]);
    }
   
    return root;
}

void inorder(TreeNode *root) {
    if (root == NULL) return;
    inorder(root->left);
    cout<<root->val<<", ";
    inorder(root->right);
}

int main()
{
vector<int> data{8, 3, 10, 1, 6, 14, 4, 7, 13};
   
TreeNode* root1 = constructTree();
TreeNode* root2 = constructBST(data);
bool result = isSameTree(root1, root2);
cout << "expected: 1, actual: " << result << endl;
inorder(root1);
cout<<endl;
inorder(root2);

cout<<endl;
TreeNode* root3 = constructBSTItr(data);
result = isSameTree(root1, root3);
cout << "expected: 1, actual: " << result << endl;
inorder(root3);
   
return 0;
   
   
}
