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
    ListNode* swapPairs(ListNode* head) {
        if(head == nullptr) return head;
        ListNode* virtualNode =new ListNode(0,head);
        ListNode* preNode1 = nullptr ;
        ListNode* preNode2 = virtualNode  ;
        ListNode* curNode = head;
        ListNode* ret;

        int flag = 0;
        while(curNode != nullptr){
            ListNode* temp = curNode->next;
            if((flag %2) == 1){
                preNode2->next=temp;
                curNode->next = preNode2;
                preNode1->next = curNode;

                preNode1 =curNode;
                curNode = temp;
                flag++;
                continue;
            }
            preNode1 = preNode2;
            preNode2 = curNode;
            curNode = temp;
            flag++;
        }
        ret = virtualNode->next;
        delete virtualNode;
        return ret;

    }
};