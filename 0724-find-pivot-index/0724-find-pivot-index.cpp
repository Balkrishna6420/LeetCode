class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int totalSum = accumulate(nums.begin(), nums.end(), 0);
        int leftSum = 0;

        for (int i = 0; i < nums.size(); i++) {
            if (leftSum == totalSum - leftSum - nums[i]) {
                return i; // Found the pivot index
            }
            leftSum += nums[i]; // Update left sum
        }

        return -1; // No pivot index found
    }
};
