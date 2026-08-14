class Solution {
private:
    int target;
    bool backtracking(vector<int> &nums,vector<int> &parts,int k,int i){
        if(i==nums.size()){
            for(int j=0;j<parts.size()-1;j++){
                if(parts[j]!=parts[j+1]) return false;
            }
            return true;
        }
        bool res=false;
        for(int j=0;j<k;j++){
            if(j>0 && parts[j]== parts[j-1]) continue;
            if(parts[j]+nums[i]<=target){
                parts[j]+=nums[i];
                res=res||backtracking(nums,parts,k,i+1);
                parts[j]-=nums[i];
            }
            if(parts[j]==0) break;
        }
        return res;
    }
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        target=accumulate(nums.begin(),nums.end(),0);
        if(target%k!=0) return false;
        target=target/k;
        sort(nums.rbegin(),nums.rend());
        vector<int> parts(k,0);
        return backtracking(nums,parts,k,0);
    }
};