#include <iostream>
using namespace std;

class Array {
private:
    int *A;
    int size;
    int length;
public:
    Array() {
        size = 10;
        A = new int[10];
        length = 0;
    }

    Array(int sz, int len) {
        size = sz;
        length = len;
        A = new int[size];
    }

    ~Array() {
        delete []A;
    }

    void fill();
    void display();
    void append(int t);
    void insert(int t, int idx);
    void deleteAt(int idx);
    int search(int t);
    int get(int idx);
    void set(int t, int idx);
    int max();
    int min();
    int sum();
    double avg();
    void reverse();
    void rotate_left(int t);
    void rotate_right(int t);
};

void Array::fill() {
    for(int i=0; i<length; i++) {
        int t;
        cin >> t;
        A[i] = t;
    }
}

void Array::display() {
    for(int i=0; i<length; i++) {
        cout << A[i] << " ";
    }
    cout << endl;
    return;
}

void Array::append(int t) {
    if(length == size)
        cout << "Can't append, maximum limit reached";
    else {
        A[length] = t;
        length++;
    }
}

void Array::insert(int t, int idx) {
    if(length == size)
        cout << "Array has reached size limit. No more elements can be added\n";
    else if(idx > length)
        cout << "Index does not lie in the array range\n";
    else {
        for(int i=length-1; i>=idx; i--)
            A[i+1] = A[i];
        A[idx] = t;
        length++;
    }
    cout << "Array after insertion : ";
    display();
}

void Array::deleteAt(int idx) {
    if(idx >= length)
        cout << "Index lies beyond length of array\n";
    else {
        for(int i=idx; i<length; i++)
            A[i] = A[i+1];
        length--;
        cout << "Array after deletion : ";
        display();
    }
}

int Array::search(int t) {
    for(int i=0; i<length; i++) {
        if(A[i] == t)
            return i;
    }
    return -1;
}

int Array::get(int idx) {
    if(idx >= length) {
        cout << "The index does not exist in the array\n";
        return -1;
    }
    else {
        return A[idx];
    }
}

void Array::set(int t, int idx) {
    if(idx >= length)
        cout << "The index does not exist in the array\n";
    else
        A[idx] = t;
    cout << "New array : ";
    display();
}

int Array::max() {
    int t = A[0];
    for(int i=0; i<length; i++) {
        if(A[i] > t)
            t = A[i];
    }
    return t;
}

int Array::min() {
    int t = A[0];
    for(int i=0; i<length; i++) {
        if(A[i] < t)
            t = A[i];
    }
    return t;
}

int Array::sum() {
    int t = 0;
    for(int i=0; i<length; i++) {
        t += A[i];
    }
    return t;
}

double Array::avg() {
    return (double)sum()/length;
}

void Array::reverse() {
    int i = 0;
    int j = length-1;
    while(i<j) {
        swap(A[i], A[j]);
        i++;
        j--;
    }
    display();
}

void Array::rotate_left(int t) {
    t = t%length;
    Array y(10, 0);
    for(int i=t; i<length; i++) {
        y.append(A[i]);
    }
    for(int i=0; i<t; i++) {
        y.append(A[i]);
    }
    for(int i=0; i<length; i++) {
        A[i] = y.A[i];
    }
    display();
}

void Array::rotate_right(int t) {
    t = t%length;
    Array y(10, 0);
    for(int i=length-1; i>length-1-t; i--) {
        y.append(A[i]);
    }
    for(int i=0; i<length-t; i++) {
        y.append(A[i]);
    }
    for(int i=0; i<length; i++) {
        A[i] = y.A[i];
    }
    display();
}

int main() {
    int a=10,b=2;
    while(a>b) {
        cout << "Enter length of array : ";
        cin >> a;
        cout << "Enter maximum size of the array : ";
        cin >> b;
        if(a>b)
            cout << "\nArray length can't be greater than maximum size\n\n";
    }
    Array arr(b,a);

    cout << "Enter elements of the array : ";
    arr.fill();
    cout << "\n";

    cout << "The array created is : ";
    arr.display();
    cout << "\n";

    cout << "Enter value to append at the end : ";
    cin >> a;
    arr.append(a);
    cout << "The modified array is : ";
    arr.display();
    cout << "\n";

    cout << "Enter value to insert in the array : ";
    cin >> a;
    cout << "Enter index at which you want to insert this value : ";
    cin >> b;
    arr.insert(a,b);
    cout << "\n";

    cout << "Enter index that you wish to delete : ";
    cin >> a;
    arr.deleteAt(a);
    cout << "\n";

    cout << "Enter value you wish to search for : ";
    cin >> a;
    b = arr.search(a);
    if(b==-1)
        cout << "This element is not present in the array";
    else
        cout << "Given element is present at index : " << b;
    cout << "\n\n";

    cout << "Enter index to get value at that index : ";
    cin >> a;
    b = arr.get(a);
    if(b!=-1)
        cout << "Value at given index is : " << b;
    cout << "\n\n";

    cout << "Enter value that you want to set in the array : ";
    cin >> a;
    cout << "Enter index : ";
    cin >> b;
    arr.set(a,b);
    cout << "\n";

    cout << "Max element : " << arr.max() << "\nMinimum element : " << arr.min() << "\nSum of all elements : " << arr.sum() << "\nAverage : "  << arr.avg();

    cout << "\n\nReverse of the array is : ";
        arr.reverse();
    cout << "\n";

    cout << "Enter value by which you wish to left rotate the array : ";
    cin >> a;
    cout << "Original array : ";
    arr.display();
    cout << "Rotated array : ";
    arr.rotate_left(a);
    cout << "\n";

    cout << "Enter value by which you wish to right rotate the array : ";
    cin >> a;
    cout << "Original array : ";
    arr.display();
    cout << "Rotated array : ";
    arr.rotate_right(a);
}
