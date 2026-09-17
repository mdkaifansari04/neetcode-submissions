class Solution {
public:
// Brute force appraoch
// time complesity: O(n sq)
// space complexity : O(1)

    // vector<int> productExceptSelf(vector<int>& nums) {
    //     vector<int> resultProduct;
    //     int n=nums.size();
    //     int count = 0;

    //     for(int i=0; i<n; i++){
    //         int product = 1;
    //         for(int j=0; j<n; j++){ 
    //             if(count == j)continue;
    //             product*=nums[j];
    //         }
    //         count+=1;
    //         resultProduct.push_back(product);
    //     }
    //     return resultProduct;
    // }

    // this works but not for the numbers containing zeros in nums
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        int prefix = 1, postfix = 1;
        vector<int> result(n);

        // prefix run
        for(int i=0; i<n; i++){
            result[i] = prefix;
            prefix *= nums[i];
        }
        // postfix run
        for(int i=n-1; i>=0; i--){
            result[i] = postfix * result[i];
            postfix *= nums[i];
        }

        return result;
    }
};
