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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>>ans;
        queue<TreeNode* >st;
        if(root==NULL)return ans;
        // TreeNode* temp=root;
        st.push(root);
        while(!st.empty()){
            int size=st.size();
            vector<int>level;
            for(int i=0;i<size;i++){
                TreeNode* t=st.front();
                st.pop();
                if(t->left) st.push(t->left);
                if(t->right) st.push(t->right);
                level.push_back(t->val);
            }
            ans.push_back(level);
        }
        return ans;
    }
};