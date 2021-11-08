class Solution {
public:
    string replaceSpace(string s) {
        if(s.size()==0) return s;
        string sRet;
        for(int i= 0; i <s.size();i++){
            if(s[i] == ' '){
                    sRet.push_back('%');
                    sRet.push_back('2');
                    sRet.push_back('0');
                    continue;
                }
            sRet.push_back(s[i]);
        }
        return sRet;
    }
    
};