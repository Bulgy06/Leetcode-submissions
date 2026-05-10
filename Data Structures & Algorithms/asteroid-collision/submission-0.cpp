class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> myStack;
        for(int i=0;i<asteroids.size();i++){
            bool destroyed=false;
            while(!myStack.empty() && myStack.top()>0 && asteroids[i]<0){
                if(abs(myStack.top())==abs(asteroids[i])){
                    myStack.pop();
                    destroyed=true;
                    break;
                }
                else if(abs(myStack.top())<abs(asteroids[i])){
                    myStack.pop();
                }
                else{
                    destroyed=true;
                    break;
                }
            }
            if(!destroyed){
                myStack.push(asteroids[i]);
            }
        }
        vector<int> v;
        v.reserve(myStack.size());
        while(!myStack.empty()){
            v.push_back(myStack.top());
            myStack.pop();
        }
        reverse(v.begin(),v.end());
        return v;
    }
};