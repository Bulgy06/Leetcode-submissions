class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        unordered_map<int,int> r;
        double time=0;
        int answer=1;
        for(int i=0;i<position.size();i++){
            r[position[i]]=speed[i];
        }
        sort(position.begin(),position.end());
        for(int i =position.size()-1;i>=0;i--){
            if(i==position.size()-1){
                time=(target-position[i])/(double)r[position[i]];
            }
            if((target-position[i])/(double)r[position[i]]>time){
                answer++;
                time=(target-position[i])/(double)r[position[i]];
            }
        }
        return answer;
    }
};
