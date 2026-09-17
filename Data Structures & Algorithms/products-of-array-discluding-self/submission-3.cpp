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

        vector<int> prefix(n);
        vector<int> postfix(n); 
        vector<int> result(n);


        // prefix product
        for (int i=0; i<n; i++){
            if(i ==0){ 
                prefix[i] = nums[i];
            }else{  
                prefix[i] = prefix[i-1] * nums[i];
            }
        }

        // postfix product
        for (int i=n-1; i>=0; i--){
            if(i ==n-1){ 
                postfix[i] = nums[i];
            }else {
                postfix[i] = postfix[i+1] * nums[i];
            }
        }

        // result product
       for (int i=0; i<n; i++){
                if(i ==0) {
                    result[i] = postfix[i+1];
                }else if(i==n-1){
                    result[i] = prefix[i-1];
                }else{ 
                      result[i] = prefix[i-1] * postfix[i+1];
                }
        }
        return result;
    }
};
    