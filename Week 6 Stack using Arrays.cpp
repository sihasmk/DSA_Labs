#include <iostream>
#include <time.h>
#define MAX 50
using namespace std;


int stack_arr[MAX];
int top = -1;

bool IsEmpty() {
    if (top==-1) {
        return true;
    }

    return false;
}

bool IsFull() {
    if (top==MAX-1) {
        return true;
    }

    return false;
}

void Push(int x) {
    if (IsFull()) {
        cout << "Error : Stack Overflow..." << endl;
        exit(1);
    }
    top++;
    stack_arr[top] = x;
}

int Pop() {
    if (IsEmpty()) {
        cout << "Error : Stack Underflow..." << endl;
        exit(1);
    }
    top--;
    return stack_arr[top+1];
}

void Display() {
    if (IsEmpty()) {
        cout << "Error : Stack Underflow..." << endl;
        return;
    }
    cout << "The elements of the stack are: ";
    for (int i=top; i>=0; i--) {
        cout << stack_arr[i] << " ";
    }
    cout << "\n";
}

int StackTop() {
    if (IsEmpty()) {
        cout << "Error : Stack Underflow..." << endl;
        exit(1);
    }
    return stack_arr[top];
}


int main() {

    struct timespec begin,end;

    clock_gettime(CLOCK_REALTIME, &end);

    Push(8);
    Push(10);
    Push(5);
    Push(11);
    Push(15);
    Push(23);
    Push(6);
    Push(18);
    Push(20);
    Push(17);
    Display();
    Pop();
    Pop();
    Pop();
    Pop();
    Pop();
    Display();
    Push(4);
    Push(30);
    Push(3);
    Push(1);
    Display();


    clock_gettime(CLOCK_REALTIME, &end);

    long secs = end.tv_sec - begin.tv_sec;
    long nanosecs = end.tv_nsec - begin.tv_nsec;

    double elapsed = secs*1e9 + nanosecs;

    cout << "Time taken for operations on stack implemented using Array = " << elapsed << "ns" << endl;

    return 0;
}
