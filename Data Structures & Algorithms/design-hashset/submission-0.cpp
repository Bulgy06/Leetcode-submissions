class MyHashSet {
private:
    struct node{
            struct node* next;
            int value;
    };
    struct node* arr[10000];
public:
    MyHashSet() {
        for(int i = 0; i < 10000; i++){
        arr[i] = NULL;
        }
    }
    
    void add(int key) {
        int location=key%10000;
        struct node* Node=(struct node*)malloc(sizeof(struct node));
        Node->value=key;
        Node->next=NULL;
        if(!contains(key)){
            if(arr[location]==NULL){
                arr[location]=Node;
            }
            else{
                struct node* temp=arr[location];
                while(temp->next!=NULL){
                    temp=temp->next;
                }
                temp->next=Node;
            }
        }    
    }
    
    void remove(int key) {
        struct node* temp=arr[key%10000];
        struct node* prev=NULL;
        while(temp!=NULL){
            if(temp->value==key && temp==arr[key%10000]){
                arr[key%10000]=temp->next;
                free(temp);
                return;
            }
            else if(temp->value==key){
                prev->next=temp->next;
                temp->next=NULL;
                free(temp);
                return;
            }
            else{
                prev=temp;
                temp=temp->next;
            }
        }
    }
    
    bool contains(int key) {
        struct node* temp=arr[key%10000];
        while(temp!=NULL){
            if(temp->value==key){
                return true;
            }
            temp=temp->next;
        }
        return false;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */