class Solution {
public:
    int maxArea(vector<int>& heights) {
        int l=0;
        int r=heights.size()-1;
        int volume=0;
        int max_volume=0;
        while(l<r){
            int min_height=min(heights[l],heights[r]);
            volume=min_height*(r-l);
            max_volume=max(volume,max_volume);
            if(heights[l]<=heights[r]){
                l++;
            }
            else{
                r--;
            }
        }
        return max_volume;
    }
};
