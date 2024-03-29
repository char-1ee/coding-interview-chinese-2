#include "List.h"
#include <cstdio>
#include <iostream>

// Insert a new node into the end of list
void AddToTail(ListNode** root, int new_value) {
    ListNode* node = new ListNode(new_value);

    if (*root == nullptr) {
        *root = node;
    } else {
        ListNode* tmp = *root;
        while (tmp->next != nullptr) {
            tmp = tmp->next;
        }
        tmp->next = node;
    }
}

// Print out the list
void PrintList(ListNode* root) {
    if (root == nullptr) {
        std::cout << "Empty" << std::endl;
    }

    ListNode* curr = root;
    while (curr->next != nullptr) {
        std::cout << curr->val << "->";
        curr = curr->next;
    }
    std::cout << curr->val << std::endl;
}

// Create a linked list given a value list
ListNode* CreateList(int values[], int length) {
    if (values == nullptr || length < 1) {
        return nullptr;
    }

    ListNode* head = new ListNode();
    ListNode* curr = head;

    for (int i = 0; i < length; i++) {
        ListNode* node = new ListNode(values[i]);
        curr->next = node;
        curr = curr->next;
    }

    return head->next; 
}

// Destroy the list (avoid `free(): double free detected in tcache 2`)
void DestroyList(ListNode* head) {
    while (head != nullptr) {
        ListNode* tmp = head;
        head = head->next;
        delete tmp;
    }
}