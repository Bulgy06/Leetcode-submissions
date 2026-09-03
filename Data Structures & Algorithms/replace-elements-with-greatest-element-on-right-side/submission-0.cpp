class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        vector<int> copy(arr.size(),0);
        for(int i=0;i<arr.size()-1;i++){
            for(int j=i+1;j<arr.size();j++){
                copy[i]=max(copy[i],arr[j]);
            }
        }
        copy[arr.size()-1]=-1;
        return copy;
    }
};