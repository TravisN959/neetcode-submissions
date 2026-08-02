class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        //add values to stack, when operation we pop last two and do operation, then put value at top 
        std:stack<int> stack;
        for(string s : tokens){
            if(s == "+"){
                int first = stack.top();
                stack.pop();
                int second = stack.top();
                stack.pop();
                stack.push(first+second);
            }else if(s == "-"){
                int first = stack.top();
                stack.pop();
                int second = stack.top();
                stack.pop();
                stack.push(second-first);
            }else if(s=="/"){
                int denom = stack.top();
                stack.pop();
                int num = stack.top();
                stack.pop();
                stack.push(num/denom);
            }else if(s=="*"){
                int first = stack.top();
                stack.pop();
                int second = stack.top();
                stack.pop();
                stack.push(first*second);
            }else{
                //number
                stack.push(stoi(s));
            }
        }
        return stack.top();
    }
};