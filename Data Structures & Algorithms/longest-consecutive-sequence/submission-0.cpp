class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        //how do we do this by pass and not sort
        //use a set to get rid of duplicates? //pass 1
        //but how do we check for consecutive?
        //what if after we inser into set, we check if there exists a number before it, if not, then first number in set // pass 2
        //then we increment to highest number found in set // pass 3
        unordered_set<int> set;
        for(int n : nums){
            set.insert(n);
        }
        int longest = 0;
        for(int n : set){
            int currentCount {1};
            if(!set.contains(n-1)){
                //lowest value in sequence
                //now we increment
                while(set.contains(n + currentCount)){
                    currentCount++;
                }
                if(currentCount > longest)
                    longest = currentCount;
            }
        }
        return longest;
    }
};