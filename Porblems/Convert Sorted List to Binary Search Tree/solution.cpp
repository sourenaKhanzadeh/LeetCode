//
// Created by sourena khanzadeh on 2023-03-11.
//
#include "../../Preliminaries/pre.hpp"
#include <stdio.h>

class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        if (head == NULL)
            return NULL;
        if (head->next == NULL)
            return new TreeNode(head->val, NULL, NULL);
        ListNode * middle = getMiddle(head);
        TreeNode * root = new TreeNode(middle->val, NULL, NULL);
        root->right = sortedListToBST(middle->next);
        middle->next = NULL;
        root->left = sortedListToBST(head);
        return root;
    }

    ListNode* getMiddle(ListNode* head){
        ListNode * prev = NULL;
        ListNode * slow = head;
        ListNode * fast = head;
        while(fast != NULL && fast->next != NULL){
            fast = fast->next->next;
            prev = slow;
            slow = slow->next;
        }
        if(prev != NULL)
            prev->next = NULL;
        return slow;
    }
};