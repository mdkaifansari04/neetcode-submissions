class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> countMap;
        vector<int> result;
        int n = nums.size();

        for (int i : nums)
            countMap[i]++;


        vector<pair<int, int>> arr(countMap.begin(), countMap.end());

            sort(arr.begin(), arr.end(), [](auto &a, auto &b) {
                return a.second > b.second;
            });
        int count =0;
        for(auto i: arr){
            if(count < k){
                result.push_back(i.first);
                count++;
            }
        }

        // [{0: 0, 1: 1, 2:2, 3:3}] 
        return result;
    }
};
