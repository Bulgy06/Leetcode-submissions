class Solution {
private:
    vector<vector<int>> res;
    void backtracking(vector<int> &subset,vector<int> &nums,int i,unordered_map<int,int> hashMap){
        if(subset.size()==nums.size()){
            res.push_back(subset);
            return;
        }
        for(int j=0;j<nums.size();j++){
            if(hashMap.find(nums[j])==hashMap.end()){subset.push_back(nums[j]);
            hashMap[nums[j]]=1;
            backtracking(subset,nums,j+1,hashMap);
            hashMap.erase(nums[j]);
            subset.pop_back();}
            else{
                continue;
            }
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> subset;
        unordered_map<int,int> hashMap;
        backtracking(subset,nums,0,hashMap);
        return res;

    }
};
