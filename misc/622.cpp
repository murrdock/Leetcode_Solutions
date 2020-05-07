class MyCircularQueue {
    vector<int> ve;
    int f, r;
    int n;
public:
    /** Initialize your data structure here. Set the size of the queue to be k. */
    MyCircularQueue(int k) {
        n = k+1;
        ve.resize(n);
        f = r = 0;
    }

    /** Insert an element into the circular queue. Return true if the operation is successful. */
    bool enQueue(int value) {
        if(isFull()) return false;
        ve[r] = value;
        r = (r+1)%n;
        return true;
    }

    /** Delete an element from the circular queue. Return true if the operation is successful. */
    bool deQueue() {
        if(isEmpty()) return false;
        f = (f+1)%n;
        return true;
    }

    /** Get the front item from the queue. */
    int Front() {
        if(isEmpty()) return -1;
        return ve[f];
    }

    /** Get the last item from the queue. */
    int Rear() {
        if(isEmpty()) return -1;
        return ve[(n+r-1)%n];
    }

    /** Checks whether the circular queue is empty or not. */
    bool isEmpty() {
        return f == r;
    }

    /** Checks whether the circular queue is full or not. */
    bool isFull() {
        return (r+1)%n == f;
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
