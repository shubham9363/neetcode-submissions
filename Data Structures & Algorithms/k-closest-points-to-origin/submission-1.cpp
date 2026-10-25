class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        using P = pair<int, int>;
        // using max-heap
        priority_queue<P, vector<P>>pq;
        // pq({distance, index})
        for(int p = 0; p<points.size(); p++){
            int x = points[p][0];
            int y = points[p][1];
            int distance = x*x + y*y;
            pq.push({distance, p});

            if(pq.size() > k){
                pq.pop();
            }
        }

        vector<vector<int>>ans;
        while(!pq.empty()){
            ans.push_back(points[pq.top().second]);
            pq.pop();
        }

        return ans;
    }
};
