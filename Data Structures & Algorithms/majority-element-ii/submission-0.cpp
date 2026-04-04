class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        unordered_map<int,int> ft;
        int n=nums.size();
        for(int i=0;i<n;i++){
            ft[nums[i]]++;
        }
        nums.clear();
        for(auto const& pair:ft){
            if(pair.second>n/3){
                nums.push_back(pair.first);
            }
        }
        return nums;
    }
};