// PS : Given a sorted array, convert it into a balanced binary search tree
// Explanation : Take middle element of the array as the root and then divide the array into left and right segment w.r.t the root. Obtain the left subtree from the left segment and right subtree
// from the right segment. Repeat this process recursively

#include <bits/stdc++.h>
using namespace std;

class TreeNode {
public:
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int _val) {
        val = _val;
        left = nullptr;
        right = nullptr;
    }
};

TreeNode* convertToBST(vector<int> &nums, int l, int r) {
    if(l > r) return nullptr;
    if(l == r)
        return new TreeNode(nums[l]);
    else {
        int mid = (l+r)/2;
        TreeNode* root = new TreeNode(nums[mid]);
        root->left = convertToBST(nums, l, mid-1);
        root->right = convertToBST(nums, mid+1, r);
        return root;
    }
}

TreeNode* sortedArrayToBST(vector<int>& nums) {
    return convertToBST(nums, 0, nums.size()-1);
}

void inorderPrint(TreeNode* root) {
    if(root == nullptr) return;
    inorderPrint(root->left);
    cout << root->val << " ";
    inorderPrint(root->right);
}

int main() {
    vector<int> nums = {3,4,6,7,8,9,12,14,16,19};
    TreeNode* root = sortedArrayToBST(nums);
    inorderPrint(root);
}
