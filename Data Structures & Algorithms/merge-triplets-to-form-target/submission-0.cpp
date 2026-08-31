class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        vector<vector<int>> consider;
        for(int i=0;i<triplets.size();i++){
            if(triplets[i][0]<=target[0] && triplets[i][1]<=target[1] && triplets[i][2]<=target[2]){
                consider.push_back(triplets[i]);
            }
        }

        int count0=0;
        int count1=0;
        int count2=0;
        for(int i=0;i<consider.size();i++){
            if(consider[i][0]==target[0]){
                count0++;
            }
            if(consider[i][1]==target[1]){
                count1++;
            }
            if(consider[i][2]==target[2]){
                count2++;
            }
        }
        if(count0 && count1 && count2) return true;
        else return false;
    }
};
