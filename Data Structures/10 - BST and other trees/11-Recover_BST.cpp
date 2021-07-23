// PS : Given a binary search tree with 2 nodes interchanged, our goal is to find out the two nodes such that when they are changed back, then it would generate a valid Binary Search Tree.
// No extra space allowed
// Explanation : Finding the solution with extra space is quite easy as we simply need to create a vector and then check which elements are in wrong position. However, since we need to find
// the answer in O(1) space, we have to use Morris Traversal. We'll traverse twice - first time to find the larger element and second time to find the smaller element. We can find the larger
// element by keeping track of the largest element up till now. As soon as we encoutner a number smaller than the largest number, then the current largest number becomes one of the required
// numbers. Then in the 2nd Morris Traversal, we have to find the last number smaller than the selected number, which lies towards it's right
// Eg - 1 2 3 8 5 6 7 4 10 -> Here 8 and 5 is not the correct answer, 8 and 4 is, hence we need to find the rightmost smaller element
// NOTE : Once you find the desired element in first traversal, do not break out of loop because Morris Traversal mutates the tree and needs to be run till completion for the tree to be back
// to original

vector<int> Solution::recoverTree(TreeNode* A) {
    int el = -1;
    TreeNode* cur = A;
    TreeNode* pre;
    int prev = -1;
    while(cur) {
        if(!cur->left) {
            int t = cur->val;
            if(t < prev && el == -1) el = prev;
            prev = max(prev, t);
            cur = cur->right;
        }
        else {
            pre = cur->left;
            while(pre->right && pre->right != cur) pre = pre->right;
            if(!pre->right) {
                pre->right = cur;
                cur = cur->left;
            }
            else {
                pre->right = nullptr;
                int t = cur->val;
                if(t < prev && el == -1) el = prev;
                prev = max(prev, t);
                cur = cur->right;
            }
        }
    }

    int x = -1;
    bool b = false;
    cur = A, pre = nullptr;
    while(cur) {
        if(!cur->left) {
            int t = cur->val;
            if(t == el) b = true;
            else if(t < el && b) x = t;
            cur = cur->right;
        }
        else {
            pre = cur->left;
            while(pre->right && pre->right != cur) pre = pre->right;
            if(!pre->right) {
                pre->right = cur;
                cur = cur->left;
            }
            else {
                pre->right = nullptr;
                int t = cur->val;
                if(t == el) b = true;
                if(t < el && b) x = t;
                cur = cur->right;
            }
        }
    }
    return {x ,el};
}
