class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        if(k==0) return false;
        int l=0;
        int r=1;
        unordered_set<int> mp;
        while(r<nums.size()){
            mp.insert(nums[l]);
            while(abs(l-r)<=k){
                if(!mp.count(nums[r])){
                    mp.insert(nums[r]);
                    r++;
                }
                else{
                    return true;
                }
            }
            mp.erase(nums[l]);
            l++;
        }
        return false;
    }
};