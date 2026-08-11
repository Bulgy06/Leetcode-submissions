class Solution {
private:
    vector<vector<int>> res;
    void backtracking(vector<int> &subset,int i,int n,int k){
        if(subset.size()==k){
            res.push_back(subset);
            return;
        }
        if(subset.size()>k ||i>n) return;
        subset.push_back(i);
        backtracking(subset,i+1,n,k);
        subset.pop_back();
        backtracking(subset,i+1,n,k);
    }
public:
    vector<vector<int>> combine(int n, int k) {
        vector<int> subset;
        backtracking(subset,1,n,k);
        return res;
    }
};