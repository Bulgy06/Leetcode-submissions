class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        if(numbers.empty()) return {};
        auto n=numbers.begin();
        for(int i=0;i<numbers.size();i++){
            n=find(numbers.begin(),numbers.end(),target-numbers[i]);
            if(n!=numbers.end() && int(n-numbers.begin())!=i){
                return {i+1,int(n-numbers.begin())+1};
            }
        }
        return {};
    }
};
