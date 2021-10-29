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
public:
    ListNode* reverseList(ListNode* head) {
        //ListNode* virtualNode = new ListNode(0,head);
        if(head == nullptr) return head;
        ListNode* lnPreNode = head;
        ListNode* lnCurNode = head->next;
        lnPreNode->next = nullptr;
        while(lnCurNode != nullptr){
            ListNode* temp= lnCurNode->next;
            lnCurNode->next = lnPreNode;

            lnPreNode = lnCurNode;
            lnCurNode = temp;
        }
        //delete virtualNode;
        return lnPreNode;
    }
};