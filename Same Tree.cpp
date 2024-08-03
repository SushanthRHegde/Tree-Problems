class Solution {
    public boolean isSameTree(TreeNode p, TreeNode q) {
        return fun(p , q);
    }

    public static boolean fun(TreeNode p ,TreeNode q){
        if(p == null || q == null) return  p==q;
        if(p == null && q == null) return true;
        if(p.val != q.val) return false;
               return fun(p.left,q.left) && fun(p.right,q.right);
    }
}
