class MyLinkedList {
public:

    struct ListNode{
        int val;
        ListNode* next;
        ListNode():val(0),next(nullptr){}
        ListNode(int x):val(x),next(nullptr){}
        ListNode(int x,ListNode* tempPtr):val(x),next(tempPtr){}
    };
    MyLinkedList() {
        _VirtualHead = new ListNode(0);
        _size = 0;
    }
    
    int get(int index) {
        if(index >(_size-1) || index <0){
            return -1;
        }
        ListNode* CurNode = _VirtualHead->next;
        while(index--){
            CurNode = CurNode->next;
        }
        return CurNode->val;
    }
    
    void addAtHead(int val) {
        ListNode * temp = _VirtualHead->next;
        ListNode * NewNode = new ListNode(val,temp);
        _VirtualHead->next = NewNode;
        _size++;
    }
    
    void addAtTail(int val) {
        ListNode * NewNode =  new ListNode(val);
        ListNode * CurNode = _VirtualHead;
        while(CurNode->next != nullptr){
            CurNode = CurNode->next;
        }
        CurNode->next = NewNode;
        _size++;
    }
    
    void addAtIndex(int index, int val) {
        if(index >_size || index <0){
            return ;
        }
        ListNode* NewNode = new ListNode(val);
        ListNode* CurNode = _VirtualHead;
        while(index--){
            CurNode = CurNode->next;
        }
        NewNode->next = CurNode->next;
        CurNode->next = NewNode;
        _size++;
    }
    
    void deleteAtIndex(int index) {
        if(index >_size-1 || index <0){
            return ;
        }
        ListNode* CurNode = _VirtualHead;
        while(index--){
            CurNode = CurNode->next;
        }
        ListNode* temp = CurNode->next;
        CurNode->next = temp->next;
        delete temp;
        _size--;
    }

private:
    int _size;
    ListNode* _VirtualHead;
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */