class Solution {
public:
    bool isPalindrome(string s) {
        string str = s;
        // remove the space
        str.erase(remove(str.begin(), str.end(), ' '), str.end());
        // remove the special char

        regex specialChar("[^a-zA-Z0-9]");
        transform(str.begin(), str.end(), str.begin(), ::tolower);
        str = regex_replace(str, specialChar, "");

        string reverseStr = str;

        // now create a forward map. and reverse map, check both are equals
        for (int i = str.size() - 1; i >= 0; i--)
        {
        reverseStr[str.size() - 1 - i] = str[i];
        }

        return str == reverseStr;
    }
};
