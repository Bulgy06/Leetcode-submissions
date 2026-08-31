class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq;
        for(int i=0;i<stones.size();i++) pq.push(stones[i]);
        while(pq.size()>1){
            int stone1=pq.top();
            pq.pop();
            int stone2=pq.top();
            pq.pop();
            if(abs(stone1-stone2)>0) pq.push(abs(stone1-stone2));
        }
        return !pq.empty()? pq.top():0;
    }
};
