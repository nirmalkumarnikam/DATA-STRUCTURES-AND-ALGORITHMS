// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;
class stack{
    public:
    int *arr;
    int size;
    int top;
    stack(int size){
        this -> size = size;
        arr = new int [size];
        top = -1;
    }
    
    void push(int element){
        if(size-top>1){
            top++;
            arr[top] = element;
        }else{
            cout<<"Stack Overflow"<<endl;
        }
    }
    
    void pop(){
        if(top>-1){
            top--;
        }else{
            cout<<"Stack Underflow"<<endl;
        }
    }
    
    int peek(){
        if(top>-1 && top < size){
            return arr[top];
        }else{
            cout<<"Stack Empty"<<endl;
            return -1;
        }
    }
    
    bool isempty(){
        if(top>-1){
            return false;
        }else{
            return true;
        }
    }
};

int main() {
    // Write C++ code here
    
    stack st(5);
    
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    cout<<"top element "<<st.peek()<<endl;
    st.pop();
    st.pop();
    st.pop();
    cout<<"stack is empty "<<st.isempty()<<endl;
    st.pop();
    cout<<"stack is empty "<<st.isempty()<<endl;
    return 0;
}

