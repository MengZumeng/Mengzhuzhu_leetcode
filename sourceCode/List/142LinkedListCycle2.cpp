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
    ListNode *detectCycle(ListNode *head) {
        ListNode* ret = NULL;
        ListNode* slowNode = head;
        ListNode* fastNode = head;

        while(fastNode != NULL && fastNode->next != NULL){
            slowNode = slowNode->next;
            fastNode = fastNode->next->next;
            if(fastNode == slowNode){
                ListNode* index1 = fastNode;
                ListNode* index2 = head;
                while(index1 != index2){
                    index1=index1->next;
                    index2=index2->next;
                }
                ret = index2;
                break;
            }
        }

        return ret;
    }
};