class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int left = 0;
        int right = arr.size() - 1;

        // binary search (lower_bound)
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (arr[mid] < x) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }

        // setup expansion pointers
        right = left;
        left = left - 1;

        // expand window
        while (right - left - 1 < k) {
            if (left < 0) {
                right++;
            } else if (right >= arr.size()) {
                left--;
            } else if (abs(arr[left] - x) <= abs(arr[right] - x)) {
                left--;
            } else {
                right++;
            }
        }

        return vector<int>(arr.begin() + left + 1, arr.begin() + right);
    }
};