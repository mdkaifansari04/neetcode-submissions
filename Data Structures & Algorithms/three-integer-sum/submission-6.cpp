class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>>result; 

        // time complexity: O(n sq)
        // space : O(1)
       // [-1,0,1,2,-1,-4]
       // -4,-1,-1,0,1,2
       //  i. j.       k == -3 > 0
     //.   i. j.     k  == -2 > 0
     //    i. j.   

     // [0,0,0,0]
     //  i.j.  k
     //    i j k
        sort(nums.begin(), nums.end());

        for(int i=0; i<n; i++){
            int j=i+1, k=n-1;
            while(j<k){
                int sum = nums[i] + nums[j] + nums[k];
                if(sum == 0) {  
                    vector<int> threeSum = {nums[i], nums[j], nums[k]};
                    if(find(result.begin(), result.end(),threeSum ) ==  result.end()){
                        result.push_back(threeSum);
                    }
                    j++; k--;
                }
                if(sum > 0) k--;
                if(sum < 0) j++;
            }
        }

        return result;
    }
};
