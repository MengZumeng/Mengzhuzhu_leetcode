class MyQueue {
public:
    stack<int> stkIn;
    stack<int> stkOut;
    MyQueue() {

    }
    
    void push(int x) {
        stkIn.push(x);
    }
    
    int pop() {
        int ret;
        if (stkOut.empty()){
            while(!stkIn.empty()){
                stkOut.push(stkIn.top());
                stkIn.pop();
            }
        }
        ret = stkOut.top();
        stkOut.pop();
        return ret;
    }
    
    int peek() {
        int ret = this->pop();
        stkOut.push(ret);
        return ret;
    }
    
    bool empty() {
        if(stkOut.empty() && stkIn.empty()){
            return true;
        } 
        return false;
    }
};