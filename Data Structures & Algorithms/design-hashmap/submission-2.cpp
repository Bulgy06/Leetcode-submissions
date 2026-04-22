class MyHashMap {
private:
    struct node{
        int k;
        int v;
        struct node* next;
    };
    struct node* arr[10000];
public:
    MyHashMap() {
        for(int i=0;i<10000;i++){
            arr[i]=NULL;
        }
    }
    
    void put(int key, int value) {
        int location=key%10000;
        struct node* Node=(struct node*)malloc(sizeof(struct node));
        Node->k=key;
        Node->v=value;
        Node->next=NULL;
        if(arr[location]==NULL){
            arr[location]=Node;
        }
        else{
            struct node* temp=arr[location];
            struct node* prev=NULL;
            while(temp!=NULL){
                if(temp->k==key){
                    temp->v=value;
                    return;
                }
                prev=temp;
                temp=temp->next;
            }
            prev->next=Node;
        }
        return;

    }
    
    int get(int key) {
        int location=key%10000;
        if(arr[location]==NULL) return -1;
        else{
            struct node* temp=arr[location];
            while(temp!=NULL){
                if(temp->k==key){
                    return temp->v;
                }
                temp=temp->next;
            }
            return -1;
        }
    }
    
    void remove(int key) {
        int location=key%10000;
        struct node* temp=arr[location];
        if(temp==NULL) return;
        else if(temp->next==NULL){
            if(temp->k==key){
                free(temp);
                arr[location]=NULL;
            }
        }
        else{
            struct node* prev=NULL;
            while(temp!=NULL){
                if(temp->k==key){
                    prev->next=temp->next;
                    temp->next=NULL;
                    free(temp);
                }
                else{
                    prev=temp;
                    temp=temp->next;
                }
            }
        }
        return;
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */