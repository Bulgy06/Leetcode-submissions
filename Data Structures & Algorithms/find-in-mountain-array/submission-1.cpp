/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
private:
    int binarySearchAsc(MountainArray &mountainArr,int l,int r,int key){
        while(l<=r){
            int mid=l+(r-l)/2;
            int val=mountainArr.get(mid);
            if(val==key){
                return mid;
            }
            else if(val>key){
                r=mid-1;
            }
            else{
                l=mid+1;
            }
        }
        return -1;
    }

    int binarySearchDsc(MountainArray &mountainArr,int l,int r,int key){
        while(l<=r){
            int mid=l+(r-l)/2;
            int val=mountainArr.get(mid);
            if(val==key){
                return mid;
            }
            else if(val>key){
                l=mid+1;
            }
            else{
                r=mid-1;
            }
        }
        return -1;
    }

    int findPivot(MountainArray &mountainArr) {
        int l=1;
        int r=mountainArr.length()-2;
        while(l<=r){
            int m=l+(r-l)/2;
            int left=mountainArr.get(m-1);
            int right=mountainArr.get(m+1);
            int middle=mountainArr.get(m);
            if(left<middle && middle<right){
                l=m+1;
            }
            else if(left>middle && middle>right){
                r=m-1;
            }
            else{
                return m;
            }
        }
    }
public:
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int n=mountainArr.length()-1;
        int pivot=findPivot(mountainArr);
        int maxi=mountainArr.get(pivot);
        if(target>maxi) return -1;
        else if(target==maxi) return pivot;
        else{
            int find=binarySearchAsc(mountainArr,0,pivot-1,target);
            if(find==-1){
                return binarySearchDsc(mountainArr,pivot+1,n,target);
            }
            return find;
        }  
    }
};