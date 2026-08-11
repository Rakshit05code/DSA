class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int n = nums.size();

        int sum = nums[0];
        int i = 1;

        while (i < n && nums[i] == nums[i-1] + 1) {
            sum += nums[i];
            i++;
        }

        unordered_set<int> st;

        for (int x : nums) {
            st.insert(x);
        }

        int ans = sum;

        while (st.find(ans) != st.end()) {
            ans++;
        }

        return ans;
    }
};