// aproach 1

class Solution
{
public:
    vector<int> arr; 
    bool isPalindrome(ListNode *head)
    {
        ListNode* current = head;

        while (current != nullptr)
        {
            arr.push_back(current->val);
            current = current->next;
        }

        int n = arr.size();
        int i = 0;
        int j = n - 1;

        while (i < j)
        {
            if (arr[i] != arr[j])
            {
                return false; =
            }
            i++;
            j--;
        }

        return true; 
    }
};


//Aproch 2
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(!head || !head->next)
            return head;
        
        ListNode* last = reverseList(head->next);
        head->next->next = head;
        head->next = NULL;
        return last;
    }

    bool isPalindrome(ListNode* head) {
        if(!head || !head->next) {
            return true;
        }

        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* prev = NULL;

        while(fast && fast->next) {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* revhead = reverseList(slow);
        prev->next = NULL;
        
        while(revhead != NULL && head != NULL) {
            if(revhead->val != head->val) {
                return false;
            }

            revhead = revhead->next;
            head = head->next;
        }

        return true;
    }
};
