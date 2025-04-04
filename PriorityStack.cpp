#include <iostream>
#include <string>
using namespace std;

template <class T>
class PriorityStack {
    int topIndex;
    int maxSize;
    T* arr;

public:
    PriorityStack(int size) {
        maxSize = size;
        arr = new T[maxSize];
        topIndex = -1;
    }

    int getPriority(T item) {
        if (item[0] == 'P' || item[0] == 'p') return 3;
        if (item[0] == 'T' || item[0] == 't') return 2;
        return 1;
    }

    bool isEmpty() {
        return (topIndex == -1);
    }

    bool isFull() {
        return (topIndex == maxSize - 1);
    }

    void push(T newvalue) {
        if (isFull()) {
            cout << "Stack is full" << endl;
            return;
        }

        // Find correct position based on priority
        int i;
        for (i = topIndex; i >= 0 && getPriority(arr[i]) < getPriority(newvalue); i--) {
            arr[i + 1] = arr[i];
        }

        // Insert at correct position
        arr[i + 1] = newvalue;
        topIndex++;
        cout << newvalue << " is pushed into the Priority Stack." << endl;
    }

    void pop() {
        if (isEmpty()) {
            cout << "Stack is empty" << endl;
            return;
        }

        cout << arr[topIndex] << " is popped from the Priority Stack." << endl;
        topIndex--;
    }

    T top() {
        if (isEmpty()) {
            cout << "Stack is empty" << endl;
            return "";
        }
        return arr[topIndex];
    }

    void display() {
        if (isEmpty()) {
            cout << "Stack is empty" << endl;
            return;
        }
        cout << "Priority Stack: ";
        for (int i = topIndex; i >= 0; i--) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    ~PriorityStack() {
        delete[] arr;
    }
};

int main() {
    PriorityStack<string> ps(5);

    ps.push("S1");
    ps.push("S2");
    ps.push("T2");
    ps.push("P1");
    ps.push("P2");

    ps.display();

    ps.pop();
    ps.display();

    cout << "Top element: " << ps.top() << endl;

    return 0;
}
