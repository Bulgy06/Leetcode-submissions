class Solution {
private:
    bool binarySearch(vector<int>& nums,int l,int r,int key){
        while(l<=r){
            int mid=(l+r)/2;
            if(nums[mid]==key) return true;
            else if(nums[mid]>key) r=mid-1;
            else l=mid+1;
        }
        return false;
    }
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int left=0;
        int right=matrix.size()-1;
        int n;
        while(left<=right){
            int middle=(left+right)/2;
            n=matrix[middle].size()-1;
            if(target>=matrix[middle][0] && target<=matrix[middle][n]){
                return binarySearch(matrix[middle],0,n,target);
            }
            else if(target>matrix[middle][n]){
                left=middle+1;
            }
            else{
                right=middle-1;
            }
        }
        return false;
    }
};
