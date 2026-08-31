class Solution {
public:
    int candy(vector<int>& ratings) {
        vector<int> candies(ratings.size(),1);
        int ans=0;
        for(int i=0;i<ratings.size();i++){
            if((i-1)>=0 && ratings[i]>ratings[i-1]){
                candies[i]=candies[i-1]+1;
            }
        }
        for(int i=ratings.size()-1;i>=0;i--){
            if((i+1)<ratings.size() && ratings[i]>ratings[i+1]){
                candies[i]=max(candies[i],candies[i+1]+1);
            }
        }
        for(int i=0;i<candies.size();i++){
            ans+=candies[i];
        }
        return ans;
    }
};