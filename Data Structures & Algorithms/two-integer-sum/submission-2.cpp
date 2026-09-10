class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        unordered_map<int, int> prevMap(n); // {value: index}

            for (int i = 0; i < n; i++)
            {
                int diff = target - nums[i];
                auto it = prevMap.find(diff);

                if (it != prevMap.end()) // if the diff is found
                    return {it->second, i};
                else
                    prevMap[nums[i]] = i;
            }

        return {};
    }
};
