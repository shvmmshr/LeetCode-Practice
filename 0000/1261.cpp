class FindElements {
public:
    TreeNode* newRoot;
    unordered_set<int> cur;
    void dfs(TreeNode* root, int par, bool left) {
        if (root == nullptr) return;
        root->val = left ? (2 * par + 1) : (2 * par + 2);
        cur.insert(root->val);
        
        dfs(root->left, root->val, true);
        dfs(root->right, root->val, false);
    }
    FindElements(TreeNode* root) {
        root->val = 0;
        cur.insert(0);
        dfs(root->left, 0, true);
        dfs(root->right, 0, false);
    }
    bool find(int target) {
        return cur.count(target);
    }
};