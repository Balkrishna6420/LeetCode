class Solution {
public:
    int mySqrt(int x) {
        return binarysqrt(x);
    }
    int binarysqrt(int n){
        int s=0;
        int e=n;
        long long int mid=s+(e-s)/2;
        long long int ans=-1;
        while(s<=e){
            long long int square=mid*mid;
            if(square==n){
                return mid;
            }
            else if(square<n){
                ans=mid;
                s=mid+1;
            }else if(square>n){
                e=mid-1;
            }
            mid=s+(e-s)/2;
        }
        return ans;
    }
};