class Solution {
public:
int solve(vector<int>& nums1, vector<int>& nums2){
    int n=nums1.size();
    int Swap=0;
    int noSwap=0;
    int currSwap=0;
    int currnoSwap=0;
    for(int index=n-1;index>=1;index--){
        for(int swapped=1;swapped>=0;swapped--){
            int ans=INT_MAX;
            int prev1=nums1[index-1];
            int prev2=nums2[index-1];
            if(swapped){
                swap(prev1,prev2);
            }
            //no swap
            if(nums1[index]>prev1 && nums2[index]>prev2){
                ans=noSwap;
            }
            //swap
            if(nums1[index]>prev2 && nums2[index]>prev1){
                ans=min(ans,1+Swap);
            }
            if(swapped){
                currSwap=ans;
            }else{
                currnoSwap=ans;
            }
        }
        Swap=currSwap;
        noSwap=currnoSwap;
    }
    return min(Swap,noSwap);
}
    int minSwap(vector<int>& nums1, vector<int>& nums2) {
        nums1.insert(nums1.begin(),-1);
        nums2.insert(nums2.begin(),-1);
        bool swapped=0;
        
        return solve(nums1,nums2);
    }
};