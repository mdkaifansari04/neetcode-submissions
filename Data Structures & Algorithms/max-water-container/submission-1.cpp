class Solution {
public:
    int maxArea(vector<int>& heights) {
        int maxArea = 0;
        int n = heights.size();
        int i=0, j=n-1;

        // [1,7,2,5,12,3,500,500,7,8,4,7,3,6]
        //. i                              j
        //    i                            j
        //    i                        j

        while(i<j){
            int width = j-i;
            int minHeight = min(heights[i], heights[j]);
            maxArea = max(maxArea, (width * minHeight));

            if(heights[i] > heights[j]){ j--; } else { i++;}
        }
        return maxArea;
    }
};
