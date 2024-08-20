// Using DFS Method
class Solution {
public:
    void preorder(TreeNode* root,int level ,vector<int>& ans ){
        if(root == NULL) return;
        if(ans.size() < level) ans.push_back(root->val);
        preorder(root->right,level+1,ans);
        preorder(root->left,level+1,ans);
    }
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        preorder(root,1,ans);
        return ans;
    }
};

//Using BFS ( level order Traversal)

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        if(root == NULL) return ans;

        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            int size = q.size();
            TreeNode* rightNode = nullptr;
            for(int i = 0; i < size ;i++){
                rightNode = q.front();
                q.pop();
                if(rightNode->left)q.push(rightNode->left);
                if(rightNode->right)q.push(rightNode->right);
            }
            ans.push_back(rightNode->val);
        }
        return ans;
    }
};
