class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        
        for(int j = 0 ; j <nums.size() ; j++){
            nums[j]= nums[j]*nums[j];
            }
        
        sort(nums.begin() , nums.end());
        return nums;
    }
};