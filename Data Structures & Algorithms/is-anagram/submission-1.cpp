class Solution {
public:
    bool isAnagram(string s, string t) {
        // int sCount = 0, tCount = 0;

        // for(char c: s){
        //     sCount+= (int)c;
        // }
        
        // for(char c: t){
        //     tCount+= (int)c;
        // }
        // return sCount == tCount;

    unordered_map<char, int> sMap;
    unordered_map<char, int> tMap;

    for (char i : s)
        sMap[i]++;

    for (char i : t)
        tMap[i]++;

    return sMap == tMap;
    }
};
