class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int> prefixMax(n);
        vector<int> suffixMax(n);
        // prefixMax and suffixMax   ---> Space complexity ==> O(2 * N)
        prefixMax[0] = height[0];
        suffixMax[n - 1] = height[n - 1];

        for(int i = 1; i < n; i++){
            prefixMax[i] = max(prefixMax[i - 1], height[i]);
        }
        for(int i = n - 2; i>=0; i--){
            suffixMax[i] = max(suffixMax[i + 1], height[i]);
        }

        // final calculations
        int total = 0;
        for(int i = 0; i<n; i++){
            total = total + min(prefixMax[i], suffixMax[i]) - height[i];
        }
        return total;
    }
};
