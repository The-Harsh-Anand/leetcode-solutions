class MyCircularQueue {
private:
    vector<int> q;
    int size=0,limit=0;
    int front=0,rear=0;

public:
    MyCircularQueue(int k) {
        limit = k;
        q.resize(k);
    }
    
    bool enQueue(int value) {
        if(isFull()) return false;
        q[rear] = value;
        rear++;
        rear%=limit;
        size++;
        return true;
    }
    
    bool deQueue() {
        if(isEmpty()) return false;
        front++;
        front%=limit;
        size--;
        return true;
    }
    
    int Front() {
        if(size==0) return -1;
        return q[front];
    }
    
    int Rear() {
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
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */