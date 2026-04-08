class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(),people.end());
        int remaining=0;
        int l=0;
        int r=people.size()-1;
        int res=0;
        while(l<=r){
            remaining=limit-people[r--];
            res++;
            if(l<=r && remaining>=people[l]){
                l++;
            }
        }
        return res;
    }
};