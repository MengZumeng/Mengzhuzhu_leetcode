class Solution {
public:
    bool isValid(string s) {
        stack<char> StaValid;
        for(int i =0;i <= s.size()-1;i++){
            if(s[i] != '(' && s[i] != '[' && s[i] != '{' && not StaValid.empty()){
                if(StaValid.top() == '(' && s[i] == ')'){
                    StaValid.pop();
                }
                else if(StaValid.top() == '{' && s[i] == '}'){
                    StaValid.pop();
                }
                else if(StaValid.top() == '[' && s[i] == ']'){
                    StaValid.pop();
                }
                else{
                    return false;
                }

            }
            else{
                StaValid.push(s[i]);
            }
        }
        return StaValid.empty();
    }
};