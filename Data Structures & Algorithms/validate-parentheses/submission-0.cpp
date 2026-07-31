class Solution {
public:
    bool isValid(string s) {
        //add open brackets to stack, check for corresponding when close bracket
        stack<char> stack;
        for(char c : s){
            if(c == '(' || c == '[' || c == '{'){
                //open brackets so we add
                stack.push(c);
            }else{
                //close brackets so we check
                if(c == ')'){
                    if(stack.empty() || stack.top() != '('){
                        return false; //not a match
                    }
                    stack.pop();
                }else if(c == ']'){
                    if(stack.empty() || stack.top() != '['){
                        return false; //not a match
                    }
                    stack.pop();
                }else{
                    if(stack.empty() || stack.top() != '{'){
                        return false; //not a match
                    }
                    stack.pop();
                }
            }
        }
        return stack.empty();//if empty then true, can't have remaining
    }
};