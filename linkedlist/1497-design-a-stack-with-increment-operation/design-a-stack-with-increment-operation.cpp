class CustomStack {
public:
    int maxSize;
    int *arr;
    int cnt;

    CustomStack(int maxSize) {
        this->maxSize = maxSize;
        arr = new int[maxSize]; // Correctly initialize the array
        cnt = 0; // Initialize count correctly
    }

    void push(int x) {
        if (cnt < maxSize) { // Check if the stack is not full
            arr[cnt] = x;
            cnt++;
        }
    }

    int pop() {
        if (cnt > 0) { // Check if the stack is not empty
            cnt--;
            return arr[cnt]; // Decrement before returning
        } else {
            return -1; // Return -1 if the stack is empty
        }
    }

    void increment(int k, int val) {
        int limit = min(k, cnt); // Increment only up to the minimum of k or cnt
        for (int i = 0; i < limit; i++) {
            arr[i] += val;
        }
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */
