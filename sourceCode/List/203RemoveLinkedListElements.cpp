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
    ListNode* removeElements(ListNode* head, int val) {
        if(head == nullptr) return head;
        ListNode* lnVirtualNode = new ListNode(0);
        lnVirtualNode->next = head;
        ListNode* lnCurNode = lnVirtualNode;
        while(lnCurNode->next != nullptr){
            if(lnCurNode->next->val == val){
                ListNode *temp = lnCurNode ->next;
                lnCurNode->next = lnCurNode->next->next;
                delete temp; 
            }
           else{
               lnCurNode=lnCurNode->next;
           };
        }
        head = lnVirtualNode->next;
        delete lnVirtualNode;
        return head;

    }
};