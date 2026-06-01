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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry=0;
        int sum=0;
        int count=0;
        if(l1==NULL) return l2;
        if(l2==NULL) return l1;
        ListNode* head=NULL;
        ListNode* prev=NULL;
        while(l1!=NULL && l2!=NULL){
            ListNode* temp=new ListNode(0);
            sum=l1->val+l2->val+carry;
            temp->val=sum%10;
            carry=sum/10;
            l1=l1->next;
            l2=l2->next;
            if(count==0){
                head=temp;
                prev=temp;
            }
            else{
                prev->next=temp;
                prev=temp;
            }
            count++;
        }
        while(l1!=NULL){
            ListNode* temp=new ListNode(0);
            sum=l1->val+carry;
            temp->val=sum%10;
            carry=sum/10;
            prev->next=temp;
            prev=temp;
            l1=l1->next;
        }
        while(l2!=NULL){
            ListNode* temp=new ListNode(0);
            sum=l2->val+carry;
            temp->val=sum%10;
            carry=sum/10;
            prev->next=temp;
            prev=temp;
            l2=l2->next;
        }
        if(carry != 0){
            ListNode* temp =new ListNode(carry);
            prev->next=temp;
        }
        return head;
    }
};
