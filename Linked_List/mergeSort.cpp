// Question link -> https://www.naukri.com/code360/problems/mergesort-linked-list_630514

// MergeSort Linked List

// Problem statement
// For a given Singly Linked List of integers, sort the list using the 'Merge Sort' algorithm.

// Detailed explanation ( Input/output format, Notes, Images )
// Constraints :
// 1 <= N <= 10^5
// 1 <= DATA <= 10^9

// Where 'DATA' denotes the value of node of Linked List.

// Time Limit: 1sec





/********************************************************************

    Following is the representation of the Singly Linked List Node:

    class node{
        public:
            int data;
            node * next;
            node(int data){
                this->data=data;
                this->next=NULL;
            }
    };
    
********************************************************************/
node* findmid(node* head) {
    node* slow = head;
    node* fast = head->next;
    while(fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

node* merge(node* left, node* right) {
    if(!left) return right;
    if(!right) return left;

    node* dummy = new node(0);
    node* tail = dummy;
    while(left && right) {
        if(left->data < right->data) {
            node* temp = left->next;
            tail->next = left;
            tail = left;
            tail->next = NULL;
            left = temp;
        } else {
            node* temp = right->next;
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

node* mergeSort(node *head) {
    if(!head || !head->next) return head;

    node* mid = findmid(head);
    node* left = head;
    node* right = mid->next;
    mid->next = NULL;

    left = mergeSort(left);
    right = mergeSort(right);

    node* ans = merge(left, right);
    return ans; 
}
