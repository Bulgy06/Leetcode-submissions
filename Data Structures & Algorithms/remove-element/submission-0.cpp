class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        vector<int> ne;
        for(int i=0;i<nums.size();i++){
            if(nums[i]!=val){
                ne.push_back(nums[i]);
            }
        }
        for(int j=0;j<ne.size();j++){
            nums[j]=ne[j];
        }
        return ne.size();
    }
};