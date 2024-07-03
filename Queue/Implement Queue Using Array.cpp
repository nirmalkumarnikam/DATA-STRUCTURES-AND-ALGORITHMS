#include <iostream>
using namespace std;

class queue {
public:
    int *arr;
    int size;
    int left;
    int right;
    
    queue() : size(10000001), left(0), right(0) {
        arr = new int[size];
    }

    ~queue() {
        delete[] arr;
    }
    
    void push(int element) {
        if (right == size) {
            cout << "queue overflow" << endl;
            return;
        }
        arr[right] = element;
        right++;
    }
    
    void front() {
        if (left == right) {
            cout << "queue is empty" << endl;
            return;
        }
        cout << "element at front: " << arr[left] << endl;
    }
    
    void back() {
        if (left == right) {
            cout << "queue is empty" << endl;
            return;
        }
        cout << "element at back: " << arr[right - 1] << endl;
    }
    
    void pop() {
        if (left == right) {
            cout << "queue underflow" << endl;
            left = 0;
            right = 0;
        } else {
            left++;
        }
    }
    
    bool isempty() {
        return left == right;
    }
};

int main() {
    queue q;
    
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);
    q.front();
    q.back();
    cout << "queue is empty: " << q.isempty() << endl;
    q.pop();
    q.pop();
    q.pop();
    q.pop();
    q.pop();
    cout << "queue is empty: " << q.isempty() << endl;
    
    return 0;
}
