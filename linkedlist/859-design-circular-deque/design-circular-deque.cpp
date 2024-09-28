class MyCircularDeque {
public:
    int *arr;
    int backindex;
    int frontindex;
    int length;
    int k;

    MyCircularDeque(int k) {
        this->k = k;
        arr = new int[k];
        backindex = -1;
        frontindex = 0;
        length = 0;
    }
    
    bool insertFront(int value) {
       if (length == k) {
            return false;
       } else {
            frontindex = (frontindex - 1 + k) % k;
            arr[frontindex] = value;
            length++;
            if (length == 1) backindex = frontindex; // Set backindex when inserting the first element
            return true;
       }
    }
    
    bool insertLast(int value) {
       if (length == k) {
            return false;
       } else {
            backindex = (backindex + 1) % k;
            arr[backindex] = value;
            length++;
            return true;
       }
    }
    
    bool deleteFront() {
        if (length == 0) {
            return false;
        } else {
            frontindex = (frontindex + 1) % k;
            length--;
            return true;
        }
    }
    
    bool deleteLast() {
        if (length == 0) {
            return false;
        } else {
            backindex = (backindex - 1 + k) % k;
            length--;
            return true;
        }
    }
    
    int getFront() {
       if (length == 0) {
            return -1;
       } else {
            return arr[frontindex];
       }
    }
    
    int getRear() {
        if (length == 0) {
            return -1;
        } else {
            return arr[backindex];
        }
    }
    
    bool isEmpty() {
       return length == 0;
    }
    
    bool isFull() {
        return length == k;
    }
};
