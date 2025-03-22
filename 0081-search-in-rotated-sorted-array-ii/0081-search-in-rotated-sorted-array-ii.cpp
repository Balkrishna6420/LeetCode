class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int n = nums.size();
        
        // Special case: If there's only one element
        if (n == 1) return nums[0] == target;

        int pivot = getPivot(nums, n);
        
        // If array is not rotated (pivot is 0), search in the entire array
        if (pivot == 0 || (target >= nums[pivot] && target <= nums[n - 1])) {
            return binarysearch(nums, pivot, n - 1, target);
        } else {
            return binarysearch(nums, 0, pivot - 1, target);
        }
        
    }
private:
    bool binarysearch(vector<int>& nums, int s, int e, int key) {
        int start = s, end = e;
        while (start <= end) {
            int mid = start + (end - start) / 2;
            if (nums[mid] == key) {
                return true;
            } else if (key < nums[mid]) {
                end = mid - 1;
            } else {
                start = mid + 1;
            }
        }
        return false;
    }

    int getPivot(vector<int>& nums, int n) {
        int start = 0, end = n - 1;
        while (start < end) {
            int mid = start + (end - start) / 2;
            if (nums[mid] > nums[end]) {
                start = mid + 1;  
            } else if (nums[mid] < nums[end]) {
                end = mid;  
            } else { 
                if (nums[start] == nums[mid] && nums[mid] == nums[end]) {
                    for (int i = start; i < end; i++) {
                        if (nums[i] > nums[i + 1]) return i + 1;
                    }
                    return start;
                }
                end--;
            }
        }
        return start;
    }
};