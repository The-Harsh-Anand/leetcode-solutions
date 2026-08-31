class MyCircularDeque {
private:
    vector<int> q;
    int size=0,limit=0;
    int front=0,rear=0;

public:
    MyCircularDeque(int k) {
        limit = k;
        q.reserve(k);
    }
    
    bool insertFront(int value) {
        if(isFull()) return false;
        front = (front-1+limit)%limit;
        q[front] = value;
        size++;
        return true;
    }
    
    bool insertLast(int value) {
        if(isFull()) return false;
        q[rear] = value;
        rear++;
        rear%=limit;
        size++;
        return true;
    }
    
    bool deleteFront() {
        if(isEmpty()) return false;
        front++;
        front%=limit;
        size--;
        return true;
    }
    
    bool deleteLast() {
        if(isEmpty()) return false;
        rear = (rear-1+limit)%limit;
        size--;
        return true;
    }
    
    int getFront() {
        if(size==0) return -1;
        return q[front];
    }
    
    int getRear() {
        if(size==0) return -1;
        return q[(rear-1+limit)%limit];
    }
    
    bool isEmpty() {
        return size==0;
    }
    
    bool isFull() {
        return size==limit;
    }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */