class Solution {
public:
    void sortColors(vector<int>& nums) {
        vector<int> Count(3,0);
        for(int i=0;i<nums.size();i++){
            Count[nums[i]]++;
        }
        int index=0;
        for(int j=0;j<3;j++){
            for(int k=0;k<Count[j];k++){
                nums[index++]=j;
            }
        }
    }
};