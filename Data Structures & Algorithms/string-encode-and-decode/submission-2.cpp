class Solution {
public:
    const string delimiter = "#%jakan@5*hsaklai%#";
    string encode(vector<string> &strs)
    {
        string encodedStrs = "";
        int n = strs.size();
        if(n==0) return "0#0#";
        if (n == 1 && strs[0] == "")
            return encodedStrs;

        for (string s : strs)
        {
            reverse(s.begin(), s.end());
            encodedStrs += s + delimiter;
        }

        return encodedStrs;
    }

    // Hello#%jakan@5*hsaklai%#World
    // olleH#%jakan@5*hsaklai%#dlroW
    // [olleH, %jakan@5*hsaklai%, dlroW]


    vector<string> decode(string s)
    {   
        if(s == "0#0#") return {};
        if (s == "") return {""};
        vector<string> decodedStrArray;
        size_t start = 0;
        size_t end = s.find(delimiter);

        while (end != string::npos)
        {
            string decoded = s.substr(start, end - start);
            reverse(decoded.begin(), decoded.end());
            decodedStrArray.push_back(decoded);
            start = end + delimiter.length();
            end = s.find(delimiter, start);
        }

        return decodedStrArray;
    }
};
