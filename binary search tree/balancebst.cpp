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
    TreeNode* root = new TreeNode(3);
    TreeNode* leftNode = new TreeNode(1);
    TreeNode* rightNode = new TreeNode(5);
    root->left = leftNode;
    root->right = rightNode;
    
    TreeNode* node = new TreeNode(2);
    leftNode->right = node;
    
    node = new TreeNode(6);
    rightNode->right = node;
  
    node = new TreeNode(4);
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

TreeNode * constructBST(const vector<int> &data, int start, int end) {
    if (end < start) {
        return NULL;
    }
    int pos = (end + start) / 2;
    TreeNode* root = new TreeNode(data[pos]);
    
    root->left = constructBST(data, start, pos-1);
    root->right = constructBST(data, pos+1, end);
    
    return root;
}

int main()
{
vector<int> data{1, 2, 3, 4, 5, 6};
   
TreeNode* root1 = constructTree();
TreeNode* root2 = constructBST(data, 0, data.size() - 1);
bool result = isSameTree(root1, root2);
cout << "expected: 1, actual: " << result << endl;
 
return 0;
   
   
}
