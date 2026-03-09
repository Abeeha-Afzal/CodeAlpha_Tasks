#include <iostream>
using namespace std;

class Array {
    int size;      
    int *arr;  
    public:
    Array(int s) {
        size = s;
        arr = new int[size];

        cout << "Enter " << size << " elements:\n";
        for(int i = 0; i < size; i++) {
            cin >> arr[i];
        }
    }
    Array(const Array &c) {
        size = c.size;
        arr = new int[size];

        for(int i = 0; i < size; i++) {
            arr[i] = c.arr[i];
        }
    }
    int sum() {
        int total = 0;
        for(int i = 0; i < size; i++) {
            total += arr[i];
        }
        return total;
    }
    ~Array() {
        delete[] arr;
    }
};

int main() {
    int n;
    cout << "Enter size of array: ";
    cin >> n;

    Array a1(n);       
    Array a2 = a1;      

    cout << "Sum of elements (a1): " << a1.sum() << endl;
    cout << "Sum of elements (a2): " << a2.sum() << endl;

    return 0;
}
