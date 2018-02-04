#include <iostream>
using std::cout;
using std::endl;
using std::swap;

template <typename Type> class Heap {
private:
    Type *data;
    int size;
    void update(int pos, int n) {
        int lchild = 2 * pos + 1, rchild = 2 * pos + 2;
        int max_value = pos;
        if (lchild < n && data[lchild] > data[max_value]) {
            max_value = lchild;
        }
        if (rchild < n && data[rchild] > data[max_value]) {
            max_value = rchild;
        }
        if (max_value != pos) {
            swap(data[pos], data[max_value]);
            update(max_value, n);
        }
    }
public:
    Heap(int length_input) {
        data = new Type[length_input];
        size = 0;
    }
    ~Heap() {
        delete[] data;
    }
    void push(Type value) {
        data[size] = value;
        int current = size;
        int father = (current - 1) / 2;
        while (data[current] > data[father]) {
            swap(data[current], data[father]);
            current = father;
            father = (current - 1) / 2;
        }
        size++;
    }
    void output() {
        for (int i = 0; i < size; i++) {
            cout << data[i] << " ";
        }
        cout << endl;
    }
    Type top() {
        return data[0];
    }
    void pop() {
        swap(data[0], data[size - 1]);
        size--;
        update(0, size);
    }
    // 请在下面实现堆排序方法 heap_sort
    void heap_sort(){
        for(int i = size - 1; i >= 1; i--){
            swap(data[i],data[0]);
            update(0,i);
        }
    }
};
int main() {
    int arr[10] = { 12, 9, 30, 24, 30, 4, 55, 64, 22, 37 };
    Heap<int> heap(100);
    for (int i = 0; i < 10; i++) {
        heap.push(arr[i]);
    }
    heap.output();
    cout << heap.top() << endl;
    heap.pop();
    heap.output();
    heap.heap_sort();
    heap.output();
    return 0;
}
