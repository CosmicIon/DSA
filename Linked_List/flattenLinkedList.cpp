// Question link -> https://www.naukri.com/code360/problems/flatten-a-linked-list_1112655

// Flatten A Linked List

// Problem statement
// You are given a linked list containing 'n' 'head' nodes, where every node in the linked list contains two pointers:

// (1) ‘next’ which points to the next node in the list
// (2) ‘child’ pointer to a linked list where the current node is the head.

// Each of these child linked lists is in sorted order and connected by 'child' pointer.
// Your task is to flatten this linked such that all nodes appear in a single layer or level in a 'sorted order'.



/*
 * Definition for linked list.
 * class Node {
 *  public:
 *		int data;
 *		Node *next;
 * 		Node *child;
 *		Node() : data(0), next(nullptr), child(nullptr){};
 *		Node(int x) : data(x), next(nullptr), child(nullptr) {}
 *		Node(int x, Node *next, Node *child) : data(x), next(next), child(child) {}
 * };
 */

Node* merge(Node* a, Node* b) {
    if(!a) return b;
    if(!b) return a;

    Node* result;

    if(a->data < b->data) {
        result = a;
        result->child = merge(a->child, b);
    } else {
        result = b;
        result->child = merge(a, b->child);
    }

    result->next = NULL;
    return result;
}

Node* flattenLinkedList(Node* head) {
    if(!head || !head->next) return head;

    head->next = flattenLinkedList(head->next);
    
    head = merge(head, head->next);

    return head;
}