#include <iostream>
#include <time.h>
#define MAX 50

int length=0;

struct node {
    int data;
    struct node* link;
} *top = NULL;

using namespace std;

bool IsEmpty() {
    if (top==NULL) {
        return true;
    }
    return false;
}

bool IsFull() {
    if (length == MAX) {
        return true;
    }
    return false;
}

void Push(int data) {
    if (IsFull()) {
        cout << "Error: Stack Overflow..." << endl;
        return;
    }
    struct node* newNode = new node;
    newNode->data = data;
    newNode->link = NULL;

    newNode->link = top;
    top = newNode;
    length++; 
}

void Display() {
    struct node* temp;
    temp = top;
    cout << "The elements of the stack are: ";
    while(temp != NULL) {
        cout << temp->data << " ";
        temp = temp->link;
    } 
    cout << "\n";
}

int StackTop() {
    if (IsEmpty()) {
        cout << "Error: Stack Underflow..." << endl;
        exit(1);
    }
    return top->data;
}

int Pop() {
    
    if (IsEmpty()) {
        cout << "Error: Stack Underflow..." << endl;
        exit(1);
    }

    struct node* temp;
    temp = top;
    int data = temp->data;

    top = top->link; 
    delete temp;
    length--;
    return data;
}

int main() {

    struct timespec begin,end;

    clock_gettime(CLOCK_REALTIME, &begin);

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

    cout << "Time taken for operations on stack implemented using Linked List = " << elapsed << "ns" << endl;

    return 0;
}
  


    