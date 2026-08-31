class MyCircularDeque {
private:
    class Node{
        public: 
            int val;
            Node* prev;
            Node* next;

            Node(int val){
                this->val = val;
            }
    };

    void addNode(Node* head, Node* newNode) {
        Node *temp = head->next;

        newNode->next = temp;
        temp->prev = newNode;

        newNode->prev = head;
        head->next = newNode;
    }

    void deleteNode(Node* delNode) {
        Node* prevv = delNode->prev;
        Node* nextt = delNode->next;

        prevv->next = nextt;
        nextt->prev = prevv;
    }

    Node* front = new Node(-1);
    Node* rear = new Node(-1);

    int size = 0, limit=0;

public:

    MyCircularDeque(int k) {
        limit = k;
        front->prev = rear;
        rear->next = front;
    }
    
    bool insertFront(int value) {
        if(size==limit) return false;
        Node *node = new Node(value);
        addNode(front->prev,node);
        size++;
        return true;
    }
    
    bool insertLast(int value) {
        if(size==limit) return false;
        Node* node = new Node(value);
        addNode(rear,node);
        size++;
        return true;
    }
    
    bool deleteFront() {
        if(size==0) return false;
        size--;
        deleteNode(front->prev);
        return true;
    }
    
    bool deleteLast() {
        if(size==0) return false;
        size--;
        deleteNode(rear->next);
        return true;
    }
    
    int getFront() {
        return front->prev->val;
    }
    
    int getRear() {
        return rear->next->val;
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