class Solution {
public:
    void reverseString(vector<char>& s) {
        int iHead=0,iTail=s.size()-1;
        while(iHead < iTail){
            char temp = s[iHead];
            s[iHead] = s[iTail];
            s[iTail] = temp;
            iHead++;
            iTail--;
        }
    }
};