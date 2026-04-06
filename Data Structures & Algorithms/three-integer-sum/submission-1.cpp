class Solution {
public:
    vector<vector<int>> twoSum(vector<int>& numbers, int l, int r, int target) {
        vector<vector<int>> res;
        while (l < r) {
            int sum = numbers[l] + numbers[r];
            if (sum == target) {
                int leftVal = numbers[l];
                int rightVal = numbers[r];
                res.push_back({leftVal, rightVal});
                while (l < r && numbers[l] == leftVal) l++;
                while (l < r && numbers[r] == rightVal) r--;
            }
            else if (sum < target) l++;
            else r--;
        }
        return res;
    }

    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> v;
        int n = nums.size();
        if (n < 3) return v;

        sort(nums.begin(), nums.end());
        for (int i = 0; i < n - 2; i++) {
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            vector<vector<int>> pairs = twoSum(nums, i + 1, n - 1, -nums[i]);
            for (auto &p : pairs) {
                v.push_back({nums[i], p[0], p[1]});
            }
        }

        return v;
    }
};