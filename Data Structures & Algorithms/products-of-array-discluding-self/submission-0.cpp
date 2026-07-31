class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        //easy - multiple everything together in first pass
        //then divide by number each time on second pass

        //followup
        //First array contains products of left
        //Seocn array contains product of right
        //Multiple left and right together
        vector<int> lefts(nums.size(), 1);
        vector<int> rights(nums.size(), 1);
        for(int i = 1 ; i < nums.size(); i++){
            lefts.at(i) = lefts.at(i-1) * nums.at(i-1);
        }
        for(int i = nums.size()-1-1; i >=0; i--){
            rights.at(i) = rights.at(i+1) * nums.at(i+1);
        }

        for(int i = 0 ; i < nums.size(); i++){
            lefts.at(i) *= rights.at(i);
        }
        return lefts;
    }
};
