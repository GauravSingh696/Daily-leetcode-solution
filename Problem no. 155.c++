#define MAX 30000  

class MinStack {
private:
    int arr[MAX];    
    int minArr[MAX]; 
    int topIndex;    

public:
    MinStack() {
        topIndex = -1;
    }

    void push(int val) {
        if (topIndex >= MAX - 1) return;
        arr[++topIndex] = val;
        minArr[topIndex] = (topIndex == 0) ? val : min(val, minArr[topIndex - 1]);
    }

    void pop() {
        topIndex--;
    }

    int top() {
        return arr[topIndex];
    }

    int getMin() {
        return minArr[topIndex];
    }
};
