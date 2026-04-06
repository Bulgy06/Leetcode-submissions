class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int x;
        for(int i=0;i<k;i++){
            x=nums.back();
            nums.pop_back();
            nums.insert(nums.begin(),x);
        }
    }
};