class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        if(k==0) return false;
        int r=0;
        unordered_set<int> mp;
        while(r<nums.size()){
            if(mp.count(nums[r])) return true;
            mp.insert(nums[r]);
            if(mp.size()>k) mp.erase(nums[r-k]);
            r++;
        }
        return false;
    }
};
