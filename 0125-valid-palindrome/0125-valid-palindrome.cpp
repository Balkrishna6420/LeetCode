class Solution {
public:
    bool isPalindrome(string s) {
       return checkPalindrome(s,0,s.length()-1); 
    }

private:
bool checkPalindrome(string& s,int start,int end) {
        //base case
        if(start>end){
            return true;
        }
        if(s==" "){
            return true;
        }
        // Skip non-alphanumeric characters
        while (start < end && !isalnum(s[start])) start++;
        while (start < end && !isalnum(s[end])) end--;
        if(tolower (s[start])!=tolower (s[end])){
            return false;
        }else{
            //recursion
            return checkPalindrome(s,start+1,end-1);
        } 
    }
};
