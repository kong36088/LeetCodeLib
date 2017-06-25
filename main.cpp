#include <iostream>
#include "StringUtils.h"
#include "BinaryTree.h"

using namespace std;

// leetcode https://leetcode.com/problems/merge-two-binary-trees/
class Solution {
public:
    TreeNode *mergeTrees(TreeNode *t1, TreeNode *t2) {
        if (t1 == NULL) {
            return t2;
        }
        if (t2 == NULL) {
            return t1;
        }

        return mergeExcute(t1, t2);
    }

    TreeNode *mergeExcute(TreeNode *t1, TreeNode *t2) {
        TreeNode *lptr = NULL;
        TreeNode *rptr = NULL;
        TreeNode *result = NULL;

        if (t1 == NULL && t2 == NULL) {
            return NULL;
        } else if (t1 != NULL && t2 == NULL) {
            lptr = mergeExcute(t1->left, NULL);
            rptr = mergeExcute(t1->right, NULL);
            result = new TreeNode(t1->val);
        } else if (t2 != NULL && t1 == NULL) {
            lptr = mergeExcute(NULL, t2->left);
            rptr = mergeExcute(NULL, t2->right);
            result = new TreeNode(t2->val);
        } else {
            lptr = mergeExcute(t1->left, t2->left);
            rptr = mergeExcute(t1->right, t2->right);
            result = new TreeNode(t2->val + t1->val);
        }
        result->left = lptr;
        result->right = rptr;
        return result;
    }

};


int main() {
    string test = "[1,2,3,4,5,6,7,8,9,null,10,11,null,12]";
    TreeNode root(test);

    string t1String = "[1,3,2,5]";
    string t2String = "[2,1,3,null,4,null,7]";
    TreeNode t1(t1String);
    TreeNode t2(t2String);

    Solution *s = new Solution();
    TreeNode *result = s->mergeTrees(&t1, &t2);
    result->traverse();

    result->traverse();

    delete s, t1, t2;

}