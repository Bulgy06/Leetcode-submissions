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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(left==right) return head;
        int l=1;
        int r=2;
        ListNode* prev=NULL;
        ListNode* cur=head;
        ListNode* end=head->next;
        while(l!=left || r!=right){
            if(l!=left){
                l++;
                prev=cur;
                cur=cur->next;
            }
            if(r!=right){
                r++;
                end=end->next;
            }
        }
        int step=0;
        int count=right-left;
        ListNode* temp=cur;
        while(step!=count){
            temp=temp->next;
            cur->next=end->next;
            end->next=cur;
            step++;
            cur=temp;
        }
        if(left>1)prev->next=end;
        if(left>1)return head;
        else return end;
    }
};