class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {

        sort(nums.begin(), nums.end());

        vector<int> ans;

        int n = nums.size();

        int start = nums[0];
        int end = nums[n-1];

        int j = 0;

        for(int i = start; i <= end; i++){

            while(j < n && nums[j] < i)
                j++;

            if(j >= n || nums[j] != i)
                ans.push_back(i);
        }

        return ans;
    }
};