#include <iostream>
#include <cmath>
#include <vector>

#include "linked_list.hpp"

using namespace std;

class Solution {
public:

    int count(ListNode* head) {
        int n = 0;
        while(head != nullptr) {
            ++n;
            head = head->next;
        }                                                   
        return n;
    }

    void print(ListNode* head) {
        while(head != nullptr) {
            cout << head->val << " ";
            head = head->next;
        }
        cout << endl;
    }

    void split(ListNode* head, ListNode*& left, ListNode*& right) {
        int n = count(head);
        int half = static_cast<int>(ceil(n/2.0));
        
        left = head;
        ListNode* dummy = head;
        for (int i = 0; i < half-1; ++ i) {
            dummy = dummy->next;
        }
        right = dummy->next;
        dummy->next = nullptr;
    }

    ListNode* merge(ListNode* left, ListNode* right) {
        ListNode dummy(0);
        ListNode* out = &dummy;
        while(left != nullptr or right != nullptr) {
            if (left != nullptr and (right == nullptr or left->val < right->val)) {
                out->next = left;
                left = left->next;
            }
            else {
                out->next = right;
                right = right->next;
            }
            out = out->next;
        }
        
        return dummy.next;
    }

    ListNode* merge_sort(ListNode* head) {
        if (head == nullptr or head->next == nullptr) {
            return head;
        }

        ListNode* left;
        ListNode* right;
        split(head, left, right);

        ListNode* ordered_left = merge_sort(left);
        ListNode* ordered_right = merge_sort(right);
        return merge(ordered_left, ordered_right);
    }

    ListNode* sortList(ListNode* head) {    
        return merge_sort(head);
    }
};


int main() {
    vector<int> v = {4,5,6,0,1};
    LinkedList list(v);
    Solution s;
    s.print(list.head);

    ListNode* a = s.merge_sort(list.head);
    s.print(a);
    return 0;
}