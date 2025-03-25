class Solution {
public:
    string reverseWords(string s) {
        // Step 1: Remove leading and trailing spaces
        int left = 0, right = s.length() - 1;
        while (left <= right && s[left] == ' ') left++;
        while (right >= left && s[right] == ' ') right--;

        // Step 2: Reverse the entire string
        reverse(s.begin() + left, s.begin() + right + 1);

        // Step 3: Reverse each word in place
        int start = left;
        for (int i = left; i <= right; i++) {
            if (s[i] == ' ' || i == right) {
                reverse(s.begin() + start, s.begin() + (i == right ? i + 1 : i));
                start = i + 1; // Move to the next word
            }
        }

        // Step 4: Remove extra spaces between words
        string result;
        int i = left;
        while (i <= right) {
            if (s[i] != ' ' || (result.length() > 0 && result.back() != ' ')) {
                result += s[i];
            }
            i++;
        }

        return result;
    }
};
