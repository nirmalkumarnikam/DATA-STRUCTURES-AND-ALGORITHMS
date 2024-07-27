#include<iostream>
using namespace std;


//Heap is complete Binary tree with Heap Order Property.
//  1)max heap: Parent is always bigger
//  2)min heap: Parent is always smaller


// MAX HEAP:

// Heap implementation in form of array:
    //         60
    //       /    \     
    //     50      40 
    //    /  \ 
    //  30    20

    // Arr: X  60  50  40  30  20
    //      0   1   2   3   4   5

    // Node => ith index
    // left child => 2*i index
    // right child => 2*i + 1 index
    // Parent => i/2 index

    class heap{
        public:
            int arr[100];
            int size;

            heap(){
                arr[0] = -1;
                size = 0;
            }    


// // Insertion:
            // 1)insert element at last position
            // 2)compare it with parent element and if inserted element is bigger than parent then swap
            void insert(int val){
                size = size+1;
                int index = size;
                arr[index] = val;       //insert at last

                while(index > 1){       //check with parent
                    int parent = index/2;

                    if(arr[parent]<arr[index]){
                        swap(arr[parent],arr[index]); //if parent is smaller then swap
                        index = parent;
                    }
                    else{
                        return;
                    }
                }
            }

// // Deletion:   
            // 1)Swap First element of array with last element
            // 2)Delete Last element
            // 3)put First element at its respective position in array
            void deleteEle(){
                if(size == 0){
                    cout<<"Nothing to delete"<<endl;
                }
                arr[1] = arr[size]; //Swap First element of array with last element
                size--; //Delete Last element

                int i = 1;  //put First element at its respective position in array
                while(i<size){  
                    int leftIndex = 2*i;
                    int rightIndex = 2*i+1;
                    
                    if(leftIndex < size &&  arr[i] < arr[leftIndex]){   //'leftIndex < size' so that it doesn't go out of bound
                        swap(arr[i], arr[leftIndex]);
                        i = leftIndex;
                    }
                    else if(rightIndex < size && arr[i] < arr[rightIndex]){ //'rihgtIndex < size' so that it doesn't go out of bound
                        swap(arr[i], arr[rightIndex]);
                        i = rightIndex;
                    }
                    else{
                        break;
                    }
                }
            }         

// // Display:
            void print(){
                for(int i = 1; i<=size; i++){
                    cout<<arr[i]<<" ";
                    
                }cout<<endl;
            }
    };

int main(){

    heap h;
    h.insert(1);
    h.insert(2);
    h.insert(3);
    h.insert(4);
    h.insert(5);
    h.insert(6);
    h.insert(7);
    h.insert(8);

    h.print();

    h.deleteEle();

    h.print();
    return 0;
}



//     7
//    4 6
// 1 3  2 5
