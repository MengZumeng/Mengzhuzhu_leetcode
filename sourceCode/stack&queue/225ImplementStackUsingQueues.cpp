class MyStack {
public:
    queue<int> queueFirst;
    queue<int> queueSecond;
    MyStack() {
    }
    
    void push(int x) {
        queueFirst.push(x);
    }
    
    int pop() {
        int temp,ret;
        while(queueFirst.size()>1){
            temp = queueFirst.front();
            queueFirst.pop();
            queueSecond.push(temp);
        }
        ret = queueFirst.front();
        queueFirst.pop();

        while(not queueSecond.empty()){
            temp = queueSecond.front();
            queueSecond.pop();
            queueFirst.push(temp);
        }
        return ret;
    }
    
    int top() {
        return queueFirst.back();
    }
    
    bool empty() {
        return queueFirst.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */