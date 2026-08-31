class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if(hand.size()%groupSize!=0) return false;
        sort(hand.begin(),hand.end());
        map<int,int> count;
        for(int i=0;i<hand.size();i++){
            count[hand[i]]+=1;
        }

        for(int num: hand){
            if(count[num]>0){
                for(int i=num;i<num+groupSize;i++){
                    if(count[i]==0) return false;
                    count[i]--;
                }
            }
        }
        return true;
        

    }
};
