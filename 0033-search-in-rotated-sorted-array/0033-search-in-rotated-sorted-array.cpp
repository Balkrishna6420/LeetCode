class Solution {
public:
    int search(vector<int>& nums, int target) {
        if (nums.size() == 1) return (nums[0] == target)? 0 : -1;
        int pivot=getPivot(nums,nums.size());
        if (pivot == 0 || target >= nums[pivot] && target <= nums[nums.size() - 1]){
            return binarysearch(nums,pivot,nums.size()-1,target);
        }else{
            return binarysearch(nums,0,pivot-1,target);
        }
    }
private:
int binarysearch(vector<int>& nums,int s,int e,int key){
        int start=s;
        int end=e;
        int mid=start+(end-start)/2;
        while(start<=end){
            if(nums[mid]==key){
                return mid;
            }else if(key>nums[mid]){
                start=mid+1;
            }else if(key<nums[mid]){
                end=mid-1;
            }
            mid=start+(end-start)/2;
        }
        return -1;
    }
    int getPivot(vector<int>& nums, int n){
        int start=0;
        int end=n-1;
        int mid=start+(end-start)/2;
        while(start<end){
            if(nums[mid]>=nums[0]){
                start=mid+1;
            }else{
                end=mid;
            }
            mid=start+(end-start)/2;
        }
        return start;
    }

    
};