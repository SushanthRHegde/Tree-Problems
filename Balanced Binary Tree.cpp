
class Solution {
public:
    int check(TreeNode* root){
        // Same maxDepth code with some modifications
        if(root == NULL) return 0; 

        int lh = check(root->left);
        if(lh == -1) return -1;//false
        int rh = check(root->right);
        if(rh == -1) return -1;

        if(abs(rh - lh) > 1) return -1;
        return max(lh,rh) + 1;

    }
    bool isBalanced(TreeNode* root) {

        return check(root) != -1;
    }
};
