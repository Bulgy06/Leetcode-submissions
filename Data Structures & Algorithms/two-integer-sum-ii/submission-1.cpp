class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        if(numbers.empty()) return {};
        int l=0;
        int r=numbers.size()-1;
        int curSum=0;
        while(l<r){
            curSum=numbers[l]+numbers[r];
            if(curSum==target) return {l+1,r+1};
            else if(curSum<target) l++;
            else r--;
        }
        return {};
    }
};
