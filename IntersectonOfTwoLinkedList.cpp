//Time complexity O(n*M)
class Solution {
public:
	ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
		ListNode *temp;
		while(headA != NULL){
			temp = headB;
			while(temp != NULL){
				if(headA == temp){
					return headA;
				}
				temp = temp -> next;
			}
			headA = headA -> next;
		}
		return NULL;
	}
};

//Time complexity O(n + M)

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(!headA || !headB) return NULL;

        ListNode * temp1 = headA;
        ListNode * temp2 = headB;

        while(temp1 != temp2)
        {
            if(temp1 == NULL)
             temp1 = headB;
            else temp1 = temp1->next;
            if(temp2 == NULL)
             temp2 = headA;
            else temp2 = temp2->next;
        }

        return temp1;
    }
};
