#include <iostream>
using namespace std;

class CircularQueue {

    int* arr;
    int currSize, cap;
    int f, r;

public:

    CircularQueue(int size) {

        cap = size;
        currSize = 0;

        arr = new int[cap];

        f = 0;
        r = -1;
    }

    // PUSH
    void push(int data) {

        if(currSize == cap) {
            cout << "CQ is FULL\n";
            return;
        }

        r = (r + 1) % cap;
        arr[r] = data;
        currSize++;
    }

    // POP
    void pop() {

        if(currSize == 0) {
            cout << "CQ is EMPTY\n";
            return;
        }

        cout << arr[f] << " deleted\n";

        f = (f + 1) % cap;
        currSize--;
    }

    // FRONT
    int front() {

        if(currSize == 0) {
            cout << "CQ is EMPTY\n";
            return -1;
        }

        return arr[f];
    }

    // EMPTY
    bool empty() {
        return currSize == 0;
    }

    // DISPLAY
    void display() {

        if(currSize == 0) {
            cout << "CQ is EMPTY\n";
            return;
        }

        int i = f;

        for(int count = 0; count < currSize; count++) {
            cout << arr[i] << " ";
            i = (i + 1) % cap;
        }

        cout << endl;
    }
};

int main() {

    CircularQueue q(5);

    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);

    q.display();

    q.pop();

    q.display();

    q.push(50);
    q.push(60);

    q.display();

    cout << "Front Element : " << q.front() << endl;

    return 0;
}