class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int first = firstOcc(nums, target);
        int last = lastOcc(nums, target);
        return {first, last};
    }

private:
    int firstOcc(vector<int>& nums, int target) {
        int start = 0;
        int end = nums.size() - 1;
        int mid = start + (end - start) / 2;  // ✅ Corrected
        int first = -1;
        while (start <= end) {
            if (nums[mid] == target) {
                first = mid;
                end = mid - 1;
            }
            else if (target > nums[mid]) {
                start = mid + 1;
            }
            else if(target<nums[mid]) {  
                end = mid - 1;
            }
            mid = start + (end - start) / 2;
        }
        return first;
    }

    int lastOcc(vector<int>& nums, int target) {
        int start = 0;
        int end = nums.size() - 1;
        int mid = start + (end - start) / 2;  
        int last = -1;
        while (start <= end) {
            if (nums[mid] == target) {
                last = mid;
                start = mid + 1;
            }
            else if (target > nums[mid]) {
                start = mid + 1;
            }
            else if(target<nums[mid]){  
                end = mid - 1;
            }
            mid = start + (end - start) / 2; 
        }
        return last;
    }
};
