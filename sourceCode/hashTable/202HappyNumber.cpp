class Solution {

public:
    bool isHappy(int n) {
        unordered_set<int> happySet;
        happySet.insert(n);
        int temp = n;
        while(1){
            temp = getSum(temp);
            if(temp == 1) return true;
            if(happySet.find(temp) != happySet.end()){
                return false;
            }
            else{
                happySet.insert(temp);
            }
        }
    }
private:

    int getSum(int n){
        int sum = 0;
        while(n){
            sum += (n%10) * (n%10);
            n /= 10;
        }
        return sum;
    }

};