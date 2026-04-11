class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        sort(nums.begin(),nums.end());
        int n=nums.size();
        if(n<4) return res;
        for(int i=0;i<n-3;i++){
            if(nums[i]==nums[i-1] && i>0) continue;
            for(int j=i+1;j<n-2;j++){
                if(j>i+1 && nums[j]==nums[j-1]) continue;
                int left=j+1;
                int right=n-1;
                long long newtarget=(long long)target-(nums[i]+nums[j]);
                while(left<right){
                    long long curSum=(long long)nums[left]+nums[right];
                    if(curSum==newtarget){
                        int leftval=nums[left];
                        int rightval=nums[right];
                        res.push_back({nums[i],nums[j],leftval,rightval});
                        while(left<right && nums[left]==leftval) left++;
                        while(left<right && nums[right]==rightval) right--;
                    }
                    else if(curSum<newtarget) left++;
                    else right--;
                }
            }
        }
        return res;
    }
};