class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<long long, vector<int>>> pq;

        for(vector<int> point : points) {
            long long dist = 1LL * point[0] * point[0]
                           + 1LL * point[1] * point[1];

            pq.push({dist, point});

            if(pq.size() > k)
                pq.pop();
        }

        vector<vector<int>> ans;

        while(!pq.empty()) {
            ans.push_back(pq.top().second);
            pq.pop();
        }

        return ans;
    }
};