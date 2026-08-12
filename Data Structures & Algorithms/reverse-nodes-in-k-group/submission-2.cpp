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
private:
    pair<ListNode*,ListNode*> reverse(ListNode* left,ListNode* right,int k){
        int l=0;
        int r=k-1;
        ListNode* dummy=new ListNode(-1);
        dummy->next=left;
        ListNode* tail=left;
        while(l!=r){
            dummy->next=dummy->next->next;
            left->next=right->next;
            right->next=left;
            left=dummy->next;
            l++;   
        }
        delete(dummy);
        return {right,tail};
    }
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(k==1) return head;
        int size=0;
        ListNode* temp=head;
        while(temp!=NULL){
            size++;
            temp=temp->next;
        }
        int step=size/k;
        int counter=0;

        ListNode* left=head;
        ListNode* right=head->next;
        ListNode* previous;
        while(counter!=step){
            int l=0;
            int r=1;
            while(r-l+1!=k){
                right=right->next;
                r++;
            }
            pair<ListNode*,ListNode*> t=reverse(left,right,k);
            if(counter==0){
                temp=t.first;
                previous=t.second;
            }
            else{
                previous->next=t.first;
                previous=t.second;
            }
            counter++;
            left=t.second->next;
            if(left!=NULL)right=left->next;
        }
        return temp;
    }
};
