// 147. Insertion Sort List

// Given the head of a singly linked list, sort the list using insertion sort, and return the sorted list's head.

// The steps of the insertion sort algorithm:

// Insertion sort iterates, consuming one input element each repetition and growing a sorted output list.
// At each iteration, insertion sort removes one element from the input data, finds the location it belongs within the sorted list and inserts it there.
// It repeats until no input elements remain.

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
class Solution {
private:
    ListNode* findmid(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head->next;
        while(fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }

    ListNode* merge(ListNode* left, ListNode* right) {
        if(!left) return right;
        if(!right) return left;

        ListNode* dummy = new ListNode(0);
        ListNode* tail = dummy;
        while(left && right) {
            if(left->val < right->val) {
                ListNode* temp = left->next;
                tail->next = left;
                tail = left;
                tail->next = NULL;
                left = temp;
            } else {
                ListNode* temp = right->next;
                tail->next = right;
                tail = right;
                tail->next = NULL;
                right = temp;
            }
        }
        if(left) {
            tail->next = left;
        }
        if(right) {
            tail->next = right;
        }
        return dummy->next;
    }
public:
    ListNode* insertionSortList(ListNode* head) {
        if(!head || !head->next) return head;

        ListNode* mid = findmid(head);
        ListNode* left = head;
        ListNode* right = mid->next;
        mid->next = NULL;

        left = insertionSortList(left); // actually it is merge sort.
        right = insertionSortList(right); // MERGE SORT.

        ListNode* ans = merge(left, right);
        return ans; 
    }
};