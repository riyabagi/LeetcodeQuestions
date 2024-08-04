#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
    int val;          
    ListNode* next;   

    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

ListNode* createLinkedList(const vector<int>& values) {
    if (values.empty()) return nullptr;

    ListNode* head = new ListNode(values[0]);
    ListNode* current = head;

    for (size_t i = 1; i < values.size(); ++i) {
        current->next = new ListNode(values[i]);
        current = current->next;
    }
    return head;
}

class Solution {
public:
    void printFrequency(ListNode* head) {
        int frequency[10] = {0};

        ListNode* current = head;

        while (current != nullptr) {
            frequency[current->val]++;
            current = current->next;
        }

        for (int i = 0; i < 10; ++i) {
            if (frequency[i] > 0) {
                cout << "Value: " << i << ", Frequency: " << frequency[i] << endl;
            }
        }
    }
};

int main() {
    vector<int> values = {1, 2, 3, 2, 1, 1, 3, 4}; 
    ListNode* head = createLinkedList(values);
    
    Solution sol;
    sol.printFrequency(head);
    
    // Free the linked list memory
    while (head != nullptr) {
        ListNode* temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}
