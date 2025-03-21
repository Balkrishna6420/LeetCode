class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int low = 0, high = nums.size() - 1;
        
        while (low < high) {
            int mid = (low + high) / 2;
            
            // Adjust mid to be even (so we can check pairs correctly)
            if (mid % 2 == 1) mid--;
            
            // XOR technique to check pairs
            if (nums[mid] == nums[mid ^ 1]) {
                low = mid + 2;  // Move right
            } else {
                high = mid;  // Move left
            }
        }
        
        return nums[low];  // Unique element found
    }
};
