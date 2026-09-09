class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
    unordered_set<int> nonDuplicates;
    nonDuplicates.reserve(nums.size());

    for (int i : nums)
    {
        // this takes O(1) time in average case.
        if (nonDuplicates.contains(i))
        {
            return true;
        }
        nonDuplicates.insert(i);
    }

    return false;
    }
};