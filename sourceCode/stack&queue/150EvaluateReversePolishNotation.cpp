class Solution {
public:
    //重复代码过多
    int evalRPN(vector<string>& tokens) {
        stack<int> staRPN;
        int temp,ret;
        for(auto it = tokens.begin();it < tokens.end();it++){
            if (*it == "+"){
                temp = staRPN.top();
                staRPN.pop();
                temp = temp + staRPN.top();
                staRPN.pop();
                staRPN.push(temp);
            }
            else if (*it == "-"){
                temp = staRPN.top();
                staRPN.pop();
                temp = staRPN.top() - temp;
                staRPN.pop();
                staRPN.push(temp);
            }
            else if (*it == "*"){
                temp = staRPN.top();
                staRPN.pop();
                temp = temp * staRPN.top();
                staRPN.pop();
                staRPN.push(temp);
            }
            else if (*it == "/"){
                //除零检测
                temp = staRPN.top();
                staRPN.pop();
                temp = staRPN.top() / temp;
                staRPN.pop();
                staRPN.push(temp);
            }
            else {
                staRPN.push(stoi(*it));
            }
        }

        ret = staRPN.top();
        staRPN.pop();
        return ret;
    }
};