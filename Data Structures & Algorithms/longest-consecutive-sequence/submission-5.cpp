class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        // [2,20,4,10,3,4,5]
        // we gonna create a set from thsi array

        // 2,20,4,10,3,5
        // now we needed to create a line segnment and put all numbers and group them based on sequece. 
        // 2,3,4,5    10      20
        // 0 1 2 3.    4.      5. //index
        // so we every element we see this whether the element number contains left consicutive if yes then number is not the start of the sequence, if no we check after doinf +1 till we dont find the longest subsequence, and store the max and return the longest.


        int longest=1;
        int n = nums.size();
        if(n == 0) return 0;
        set<int> sequence(nums.begin(), nums.end());

        for(int i=0; i<n; i++){
            int longestSeq =1;
            // start of the sequece
            if(!sequence.contains(nums[i]-1)){
                bool nextConsecutive = true;
                int count=1; 
                while(nextConsecutive){
                    int next = nums[i] + count;
                    if(sequence.contains(next)){
                        count++;
                        longestSeq++;
                    }else{
                     nextConsecutive = false;
                    }
                }
            }
            longest = max(longest,longestSeq);
        }
        return longest;
    }
};
