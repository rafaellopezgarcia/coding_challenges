#include <vector>

struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
 };
 
class LinkedList {
public:
    LinkedList(std::vector<int>& elements) {
        ListNode * node = nullptr;
        head = nullptr;
        for (int element : elements) {
            if (head == nullptr) {
                node = new ListNode(element);
                head = node;
            }
            else {
                node->next = new ListNode(element);
                node = node->next;
            }

        }
    }
    ~LinkedList() {
        ListNode * node = nullptr;
        while(head != nullptr) {
            node = head;
            head = head->next;
            delete node;
        }
    }
    ListNode * head;

};