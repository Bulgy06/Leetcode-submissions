class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> max_slide;
        if(k>=nums.size()){
            int value=*max_element(nums.begin(),nums.end());
            max_slide.push_back(value);
            return max_slide;
        }
        priority_queue<pair<int,int>> pq;
        for(int i=0;i<nums.size();i++){
            pq.push({nums[i],i});
            while(!pq.empty() && pq.top().second<=i-k) pq.pop();
            if(i>=k-1){
                max_slide.push_back(pq.top().first);
            }

        }
        return max_slide;

        
    }
};
