class Solution {
public:
    int calPoints(vector<string>& operations) {
        struct stack{
            int arr[1000];
            int top;
        };
        struct stack* s=(struct stack*)malloc(sizeof(struct stack));
        s->top=-1;
        for(int i=0;i<operations.size();i++){
            if(operations[i]=="+"){
                int k=s->top - 1;
                int ne=s->arr[s->top]+s->arr[k];
                s->top++;
                s->arr[s->top]=ne;
            }
            else if((operations[i])=="C"){
                s->top--;
            }
            else if((operations[i])=="D"){
                int prev=s->arr[s->top];
                s->top++;
                s->arr[s->top]=2*prev;
            }
            else if(operations[i]!="+" && operations[i]!="C" && operations[i]!="D"){
                int val=stoi(operations[i]);
                s->arr[++(s->top)]=val;
            }
        }
        int j=0;
        int sum=0;
        while(j<=s->top){
            sum+=s->arr[j];
            j++;
        }
        return sum;
    }

};