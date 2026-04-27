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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1==NULL && list2==NULL) return NULL;
        else if(list1==NULL){
            return list2;
        }
        else if(list2==NULL){
            return list1;
        }
        struct ListNode* l1=list1;
        struct ListNode* l2=list2;
        struct ListNode* head;
        struct ListNode* prev;
        int count=0;
        while(l1!=NULL && l2!=NULL){
            struct ListNode* temp=(struct ListNode*)malloc(sizeof(struct ListNode));
            if(count==0){
                prev=(struct ListNode*)malloc(sizeof(struct ListNode));
                if(l1->val<=l2->val){
                    prev->val=l1->val;
                    l1=l1->next;
                }
                else{
                    prev->val=l2->val;
                    l2=l2->next;
                }
                head=prev;
                count++;
                prev->next=NULL;
            }
            else{
                if(l1->val<=l2->val){
                    temp->val=l1->val;
                    l1=l1->next;
                    prev->next=temp;
                    temp->next=NULL;
                    prev=temp;
                }
                else{
                    temp->val=l2->val;
                    l2=l2->next;
                    prev->next=temp;
                    temp->next=NULL;
                    prev=temp;
                }
            }
            
        }
        while(l1!=NULL){
            struct ListNode* temp=(struct ListNode*)malloc(sizeof(struct ListNode));
            temp->val=l1->val;
            prev->next=temp;
            temp->next=NULL;
            prev=temp;
            l1=l1->next;
        }
        while(l2!=NULL){
            struct ListNode* temp=(struct ListNode*)malloc(sizeof(struct ListNode));
            temp->val=l2->val;
            prev->next=temp;
            temp->next=NULL;
            prev=temp;
            l2=l2->next;
        }
        return head;
    }    
};
