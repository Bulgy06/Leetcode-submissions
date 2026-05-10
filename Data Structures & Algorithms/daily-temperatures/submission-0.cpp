class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int> indices;
        vector<int> res(temperatures.size());
        stack<int> values;
        for(int i=temperatures.size()-1;i>=0;i--){
            while(!values.empty() && temperatures[i]>=values.top()){
                values.pop();
                indices.pop();
            }
            if(!indices.empty()){
                res[i]=indices.top()-i;
            }
            else{
                res[i]=0;
            }
            values.push(temperatures[i]);
            indices.push(i);
        }
        return res;

    }
};
