class MinStack {
private:
    int topi;
    int count;
    int arr[10000];
    stack<int> min;
public:
    MinStack() {
        topi=-1;
        count=0;
    }
    
    void push(int val) {
        if(topi==-1){
            topi++;
            arr[topi]=val;
            min.push(val);
            count++;
        }
        else{
            val<min.top()? min.push(val):min.push(min.top());
            topi++;
            arr[topi]=val;
        }
    }
    
    void pop() {
        min.pop();
        topi--;
    }
    
    int top() {
        return arr[topi];
    }
    
    int getMin() {
        return min.top();
    }
};
