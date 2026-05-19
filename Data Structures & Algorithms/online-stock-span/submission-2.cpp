class StockSpanner {
private:
    int prefix[10000];
    int top;
public:
    StockSpanner() {
        top=-1;
    }
    
    int next(int price) {
        prefix[++top]=price;
        if(top==0){
            return 1;
        }
        if(price<prefix[top-1]) return 1;
        else{
            int count=1;
            int temp=top-1;
            while(temp>=0 && price>=prefix[temp]){
                count++;
                temp--;
            }
            return count;
        }
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */