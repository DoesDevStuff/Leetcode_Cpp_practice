#include <bits/stdc++.h>
using namespace std;

/*
// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
*/
void printList(ListNode *head) {
    ListNode *tmp;
    tmp = head;
    if (tmp == NULL)
        cout << "empty list";
    else {
        while (tmp != NULL) {
            cout << tmp->val;
            tmp = tmp->next;
            if (tmp)
                cout << ", ";
        }
        cout << endl;
    }
}

void reversingList(ListNode **head, int val) {
    ListNode *node = new ListNode(val);
    if (!*head) {
        *head = node;
    }
    else {
        ListNode *tmp = *head;
        while (tmp->next)
            tmp = tmp->next;
        tmp->next = node;
    }
}


class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int sum, carry_over = 0;
        ListNode* ans = nullptr;
        // vector<int> temp;
        while (l1 || l2) {
            if (l1 && l2) 
                sum = l1->val + l2->val + carry_over;
            
            else if (l1) 
                sum = l1->val + carry_over;
            
            else if (l2) 
                sum = l2->val + carry_over;
            
            carry_over = sum >= 10 ? 1 : 0;
            sum = sum % 10;
            // temp.push_back(sum);
            reversingList(&ans, sum);
            if (l1)
                l1 = l1->next;
            if (l2)
                l2 = l2->next;
        }
        if (carry_over)
            reversingList(&ans, 1);
        return ans;
    }
};
