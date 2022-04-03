#include <iostream>

using namespace std;

#define MAX 100

class Node{
public:
    int data;
    Node *next;
    Node(int x, Node *n){
        data = x;
        next = n;
    }
};

class Stack{
private:
    Node *top;
    int stackSize;

public:
    Stack(){
        top = nullptr;
        stackSize = 0;
    }
    bool pushInt(int x);
    bool popItem();
    void topItem();
    bool isEmpty();
    int size();
    void printStack();

};

bool Stack:: pushInt(int x){
    if (size() == MAX){
        cout << "Stack is full!" << endl;
        return false;
    }else if (isEmpty()){
        top = new Node(x, nullptr);
        stackSize++;
        return true;
    }
    else{
        Node* newTop = new Node(x, nullptr);
        newTop -> next = top;
        top = newTop;
        stackSize++;
        return true;
    }
}

bool Stack:: popItem(){
    if (isEmpty()){
        cout << "Stack is empty." << endl;
        return false;
    } else{
        Node* newTop = top->next;
        top->next = nullptr;
        top = newTop;
        stackSize--;
        return true;
    }
}

void Stack:: topItem(){
    if (isEmpty()){
        cout << "Stack is empty!" << endl;
    } else{
        cout << "Value at the top is: " << top->data << endl;
    }
}

bool Stack:: isEmpty(){
    if (top == nullptr){
        return true;
    } else{
        return false;
    }
}

int Stack:: size(){
    if (isEmpty()){
        return 0;
    } else{
        return stackSize;
    }
}

void Stack::printStack() {
    cout << "Stack: " << endl;
    Node* currentNode = top;
    while(currentNode != nullptr){
        cout << currentNode->data << " ";
        currentNode = currentNode->next;
    }
    cout << endl;
}

int main() {
    Stack s;
    int input = -1;
    do {
        cout << "Enter a node value/Enter -1 to exit: ";
        cin >> input;
        cout << endl;
        if (input != -1){
            s.pushInt(input);
        }
    } while (input != -1 && s.size()!=MAX);

    s.printStack();
    s.topItem();
    cout << "Stack's size is: " << s.size() << endl;
    cout << "Popping item from the stack..." << endl;
    if (s.popItem()){
        cout << "Popped successfully!" << endl;
    } else{
        cout << "Failed to pop!" << endl;
    }
    s.printStack();
    s.topItem();
    cout << "Stack's size is: " << s.size() << endl;
    return 0;
}
