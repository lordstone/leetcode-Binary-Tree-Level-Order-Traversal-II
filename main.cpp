/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> arr, arrR, arrL;
        if(root == NULL) return arr;// trvial case
        arrR = levelOrderBottom(root->right);
        arrL = levelOrderBottom(root->left);
        if(!(arrR.size() == 0 && arrL.size() == 0)){
            for(int i = ((arrR.size() > arrL.size())? arrR.size():arrL.size()); i > 0 ; i--){
                if(i <= arrL.size()) {
                    arr.push_back(arrL[arrL.size() - i]);
                    if(i <= arrR.size()) arr[((arrR.size() > arrL.size())? arrR.size():arrL.size()) - i].insert(arr[((arrR.size() > arrL.size())? arrR.size():arrL.size()) - i].end(), arrR[arrR.size() - i].begin(), arrR[arrR.size() - i].end());
                    continue;
                }else if(i <= arrR.size()){
                    arr.push_back(arrR[arrR.size() - i]);
                }
            }//end for i
        }
        vector<int> tmp(1, root->val);
        arr.push_back(tmp);
        return arr;
    }
};
