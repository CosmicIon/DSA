// 445. Add Two Numbers II

// You are given two non-empty linked lists representing two non-negative integers. The most significant digit comes first and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.

// You may assume the two numbers do not contain any leading zero, except the number 0 itself.

 

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
#include <bits/stdc++.h>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


class Solution {
private:
    ListNode* reverse(ListNode* head) {
        //reverse the linked list.
        ListNode* curr = head;
        ListNode* prev = NULL;
        while(curr) {
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* num1 = reverse(l1);
        ListNode* num2 = reverse(l2);
        ListNode* result = NULL;
        ListNode* resultTail = NULL;

        ListNode* curr1 = num1;
        ListNode* curr2 = num2;
        int carry = 0;

        while(curr1 || curr2 || carry) {
            int sum = carry;
            if(curr1) {
                sum += curr1->val;
                curr1 = curr1->next;
            }
            if(curr2) {
                sum += curr2->val;
                curr2 = curr2->next;
            }
            ListNode* newNode = new ListNode(sum % 10);
            carry = sum / 10;
            if(!result) {
                result = newNode;
                resultTail = result;
            } else {
                resultTail->next = newNode;
                resultTail = newNode;
            }
        }
        result = reverse(result);
        return result;
    }
};