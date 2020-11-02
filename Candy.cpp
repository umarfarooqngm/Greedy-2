// Time Complexity : O(n) as we are travelling throught the array only 3 times
// Space Complexity : O(n) as we are creating an extra vector for candies count here
// Did this code successfully run on Leetcode : Yes
// Any problem you faced while coding this : no issues as of now.. Learning

class Solution {
public:
    int candy(vector<int>& ratings) {
        
        int size = ratings.size();
        
        if(size == 0) return 0;
        
        
      vector<int> candies(size,1);
       
        
        for (int i = 1; i < size; i++){
            
            if(ratings[i]>ratings[i-1]){
                
                
                candies[i] = candies[i-1] +1;
            }
        }
        
        
        for( int i = size-2;  i >=0; i--){
            
            if(ratings[i] > ratings[i+1]){
                
                candies[i] = max(candies[i+1] +1, candies[i]);
            }
        }
        
        int result = 0;
        
        for ( int i = 0; i <size; i++){
            
            result = result + candies[i];
        }
        
        return result;
        
    }
};