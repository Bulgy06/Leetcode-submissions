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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int length=0;
        ListNode* temp=head;
        while(temp!=NULL){
            length++;
            temp=temp->next;
        }
        ListNode* prev=NULL;
        temp=head;
        if(length-n==0){
            temp=temp->next;
            free(head);
            return temp;
        }
        int to_remove=0;
        while(to_remove!=length-n){
            prev=temp;
            to_remove++;
            temp=temp->next;
        }
        prev->next=temp->next;
        return head;
        

    }
};
