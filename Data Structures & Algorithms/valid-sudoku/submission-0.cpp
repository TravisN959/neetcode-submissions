class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        //check rows - go through each and add to set, must be 0-9, we need a set for each row
        //check columns - same as rows
        //check squares - set for each squares, but how do we determine which square?
        // 0,0; 0,1; 0,2 are in square 0 (1st row)
        // also 0,0 1,0 2,0 2,2 (1st column)
        // divide (row/ 3) * 3 + column/ 3 to get square?
        // first square would be 0
        //second square has 0,3 2,3 2,5 = 1
        // last square 8,8 2+2 = 4
        vector<unordered_set<int>> rowSets(9);
        vector<unordered_set<int>> colSets(9);
        vector<unordered_set<int>> sqSets(9);
        for(int i = 0; i < 9; i++){//row
            for(int j=0; j < 9; j++){//column
                char c = board.at(i).at(j);
                if(c >= '0' && c <= '9'){
                    //valid digit
                    //row
                    auto [itR, successR] = rowSets.at(i).insert(c);
                    if(!successR)
                        return false;

                    //column
                    auto [itC, successC] = colSets.at(j).insert(c);
                    if(!successC)
                        return false;

                    //get square value
                    int sq= ((i/3) * 3 ) + (j/3);
                    auto [itSQ, successSQ] = sqSets.at(sq).insert(c);
                    if(!successSQ)
                        return false;

                }else if(c != '.'){
                    return false; //invalid input
                }
            }
        }
        return true; //passed all checks
    }
};
