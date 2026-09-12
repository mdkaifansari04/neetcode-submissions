class Solution {
public:
  vector<vector<string>> groupAnagrams(vector<string> &strs)
    {
        vector<vector<string>> result;
        // vector<string>.length
        int n = strs.size();
        if (n <= 1)
            return {strs};
        // we will sort that and store it in their respective hash,
        // {
        //     ate : ["eat", "tea", "ate"],
        // }

        unordered_map<string, vector<string>> sortedStringMap(n);
        for (string s : strs)
        {
            string sortedSting = s;

            sort(sortedSting.begin(), sortedSting.end());
            if (sortedStringMap.find(sortedSting) != sortedStringMap.end()) // key found
                sortedStringMap[sortedSting].push_back(s);
            else
                sortedStringMap[sortedSting] = {s};
        }

        // sort(sortedStringMap.begin(), sortedStringMap.end());
        for (const auto &[key, value] : sortedStringMap)
        {
            result.push_back(value);
        }

        return result;
    }
};
