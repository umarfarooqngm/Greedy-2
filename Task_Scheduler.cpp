// Time Complexity : O(n) as we are travelling throught the array only once
// Space Complexity : O(n) for the hashmap created but if we initialize what with size 26 for alphabets it is o(1)
// Did this code successfully run on Leetcode : Yes
// Any problem you faced while coding this : no issues as of now.. Learning

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int size = tasks.size();
        
        
        if(size == 0) return 0;
        
        int max_count = 0;
        
        int max_freq = 0;
        
        map<char, int>  mymap;
        
    // creating a hashmap and also keeping track of max_frequency i.e task with high frequency.
        
        for( int i = 0; i <size; i++){
            
            mymap[tasks[i]] +=1;
            
            
            if( mymap[tasks[i]] > max_freq){
                
                max_freq = mymap[tasks[i]];
            }
            
        
        }
        
        // getting max_count values with help of max_freq
        for ( int i = 0; i <mymap.size(); i++){
            if( mymap[i] == max_freq){
                
                max_count += 1;
            }
            
        }
        
        
        int partition =  max_freq -1; // number of empty spaces between the high freq adjsutment
        
        int empty = (n - (max_count -1) )* partition; // if there are multiple same freq emelemts with higest frequency then we will arrange them in together
        // so n - (count -1) // -1 because we had arrangement for atleast one already before partitions
        
        int pending = size - (max_freq*max_count); // remaining positions which needs to be added into the line, we have a;ready added the max elements
        
        int idle = max( 0, empty - pending); // sometimes the this might give negative when max lements are less.. so using the max function with "0"
        
        
        
       return (idle + size); 
    }
};