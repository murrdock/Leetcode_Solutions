class MyCircularDeque {
    vector<int> ve;
    int n, f,r;
public:
    /** Initialize your data structure here. Set the size of the deque to be k. */
    MyCircularDeque(int k) {
        n = k+1;
        ve.resize(n);
        f=r=0;
    }

    /** Adds an item at the front of Deque. Return true if the operation is successful. */
    bool insertFront(int value) {
        if(isFull()) return false;
        f = (n+f-1)%n;
        ve[f] = value;
        return true;
    }

    /** Adds an item at the rear of Deque. Return true if the operation is successful. */
    bool insertLast(int value) {
        if(isFull()) return false;
        ve[r] = value;
        r = (r+1)%n;
        return true;
    }

    /** Deletes an item from the front of Deque. Return true if the operation is successful. */
    bool deleteFront() {
        if(isEmpty()) return false;
        f = (f+1)%n;
        return true;
    }

    /** Deletes an item from the rear of Deque. Return true if the operation is successful. */
    bool deleteLast() {
        if(isEmpty()) return false;
        r = (n+r-1)%n;
        return true;
    }

    /** Get the front item from the deque. */
    int getFront() {
        if(isEmpty()) return -1;
        return ve[f];
    }

    /** Get the last item from the deque. */
    int getRear() {
        if(isEmpty()) return -1;
        return ve[(n+r-1)%n];
    }

    /** Checks whether the circular deque is empty or not. */
    bool isEmpty() {
        return f==r;
    }

    /** Checks whether the circular deque is full or not. */
    bool isFull() {
        return (r+1)%n == f;
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
