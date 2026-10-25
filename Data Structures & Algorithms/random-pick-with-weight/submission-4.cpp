class Solution {
    vector<int>prefixSum;
    int maxEle;
    
public:
    Solution(vector<int>& w) {
        prefixSum.reserve(w.size());
        maxEle = 0;
        for(int i : w){
            maxEle = maxEle + i;
            prefixSum.push_back(maxEle);
        }
    }
    
    int pickIndex() {
        int target = rand() % maxEle + 1;
        int low = 0, high = prefixSum.size() - 1;

        while(low < high){
            int mid = low + (high - low)/2;
        
            if(prefixSum[mid] >= target) high = mid;
            else low = mid + 1;
        }

        return low;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */