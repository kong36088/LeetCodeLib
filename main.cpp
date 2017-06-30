#include <iostream>
#include <unordered_map>
#include "StringUtils.h"
#include "BinaryTree.h"
#include "VectorHelper.h"
#include "ListNode.h"

using namespace std;

class Solution {
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        if (l1 == NULL) {
            return l2;
        }
        if (l2 == NULL) {
            return l1;
        }
        stack<int> s1, s2;
        ListNode *p1 = l1, *p2 = l2;
        ListNode *result = NULL;
        while (p1 != NULL) {
            s1.push(p1->val);
            p1 = p1->next;
        }
        while (p2 != NULL) {
            s2.push(p2->val);
            p2 = p2->next;
        }
        int increase = 0;

        while (!s1.empty() && !s2.empty()) {
            int v1 = s1.top();
            int v2 = s2.top();
            s1.pop();
            s2.pop();

            int sum;
            if (v1 + v2 + increase > 9) {
                sum = v1 + v2 - 10 + increase;
                increase = 1;
            } else {
                sum = v1 + v2 + increase;
                increase = 0;
            }

            if (result == NULL) {
                result = new ListNode(sum);
                result->next = NULL;
            } else {
                ListNode *newNode = new ListNode(sum);
                newNode->next = result;
                result = newNode;
            }
        }
        while (!s1.empty()) {
            int sum = s1.top() + increase;
            s1.pop();
            increase = 0;
            if(sum > 9){
                sum -=10;
                increase = 1;
            }

            if (result == NULL) {
                result = new ListNode(sum);
                result->next = NULL;
            } else {
                ListNode *newNode = new ListNode(sum);
                newNode->next = result;
                result = newNode;
            }
        }
        while (!s2.empty()) {
            int sum = s2.top() + increase;
            s2.pop();
            increase = 0;
            if(sum > 9){
                sum -=10;
                increase = 1;
            }

            if (result == NULL) {
                result = new ListNode(sum);
                result->next = NULL;
            } else {
                ListNode *newNode = new ListNode(sum);
                newNode->next = result;
                result = newNode;
            }
        }
        if (increase != 0) {
            ListNode *newNode = new ListNode(1);
            newNode->next = result;
            result = newNode;
        }

        return result;
    }

};


int main() {
    string test = "[1,2,3,4,5,6,7,8,9,null,10,11,null,12]";
    TreeNode root(test);

    string t1String = "[1,2,3,4]";
    string t2String = "[2,1,3,null,4,null,7]";
    string t3String = "[1,2,3,null,4]";
    TreeNode t1(t1String);
    TreeNode t2(t2String);
    TreeNode t3(t3String);
    TreeNode *t4 = new TreeNode(t3String);

    ListNode l1("[5]");
    ListNode l2("[5,5]");


    Solution *s = new Solution();
    cout << endl;
    ListNode *r = s->addTwoNumbers(&l1, &l2);


    t4->destroy();
    if (r != NULL) {
        r->traverse();
    }
    r->destory();
    delete s;

}