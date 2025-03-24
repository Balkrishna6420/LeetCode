class Solution {
public:
    void reverseString(vector<char>& s) {
        int start=0;
        int end=s.size()-1;
        for(int i=0;i<s.size()-1;i++){
            while(start<=end){
                swap(s[start],s[end]);
                start++;
                end--;
            }
        }
    }
};