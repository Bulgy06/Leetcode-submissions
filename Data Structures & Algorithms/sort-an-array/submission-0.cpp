class Solution {
public:
    int partition(vector<int>& nums,int left,int right){
        int i=left-1;
        int j=left;
        int pivot=nums[right];
        int temp;
        while(i<j && j<right){
            if(nums[j]<=pivot){
                i=i+1;
                temp=nums[i];
                nums[i]=nums[j];
                nums[j]=temp;
            }
                j++;
        }   
        temp=nums[i+1];
        nums[i+1]=pivot;
        nums[right]=temp;
        return i+1;
    }
    void quicksort(vector<int>& nums,int left,int right){
        if(left<right){
            int pi=partition(nums,left,right);
            quicksort(nums,left,pi-1);
            quicksort(nums,pi+1,right);
        }
    }

    vector<int> sortArray(vector<int>& nums) {
        quicksort(nums,0,nums.size()-1);
        return nums;
    }
};