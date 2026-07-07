class Solution {
private:
    int canEat(vector<int> &piles,int h, int speed){
        int hours=0;
        for(int p: piles){
            hours+=ceil(static_cast<double>(p)/speed);
            if(hours>h){
                return false;
            }
        }
        return true;
    }
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int l=1;
        int r=*max_element(piles.begin(),piles.end());
        int res=r;
        while(l<=r){
            int speed=(l+r)/2;
            if(canEat(piles,h,speed)){
                res=speed;
                r=speed-1;
            }
            else{
                l=speed+1;
            }
        }
        return res;
    }
};
