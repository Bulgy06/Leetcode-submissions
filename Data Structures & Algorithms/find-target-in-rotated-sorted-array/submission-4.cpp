class Solution {
private:
    int binarySearch(vector<int>& nums,int l,int r,int key){
        while(l<=r){
            int mid=(l+r)/2;
            if(nums[mid]==key) return mid;
            else if(nums[mid]>key) r=mid-1;
            else l=mid+1;
        }
        return -1;
    }
public:
    int search(vector<int>& nums, int target) {
        int minimum=nums[0];
        int l=0;
        int r=nums.size()-1;
        int index=0;
        while(l<=r){
            int mid=(l+r)/2;
            if(nums[mid]>=minimum){
                l=mid+1;
            }
            else{
                r=mid-1;
                minimum=nums[mid];
                index=mid;
            }
        }

        if(index==0) return binarySearch(nums,0,nums.size()-1,target);
        int detect1, detect2=-1;
        detect1=binarySearch(nums,0,index-1,target);
        detect2=binarySearch(nums,index,nums.size()-1,target);
        if(detect1==-1 && detect2==-1) return -1;
        else return detect1+detect2+1;


    }
};
