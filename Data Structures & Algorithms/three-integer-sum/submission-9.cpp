class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        int n = nums.size();
        vector<vector<int>> result;

        // time complexity: O(n sq)
        // space : O(1)

        sort(nums.begin(), nums.end());

        for (int i = 0; i < n; i++)
        {
            int j = i + 1, k = n - 1;
            while (j < k)
            {
                int sum = nums[i] + nums[j] + nums[k];
                if (sum == 0)
                {
                    vector<int> threeSum = {nums[i], nums[j], nums[k]};
                    if (find(result.begin(), result.end(), threeSum) == result.end())
                    {
                        result.push_back(threeSum);
                    }
                    j++;
                    k--;
                }
                if (sum > 0)
                    k--;
                if (sum < 0)
                    j++;
            }
        }

        return result;
    }
};
