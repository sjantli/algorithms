#include <iostream>
#include <string>
#include <stack>

std::stack<int> stacknew;
std::stack<int> stackold;

void shiftstacks() {
    if (stackold.empty()) {
        while(!stacknew.empty()) {
            int item = stacknew.top();
            stacknew.pop();
            stackold.push(item);
        }
    }
}

void enqueue(int item) {
    stacknew.push(item);
}

int dequeue() {
    shiftstacks();
    int item = stackold.top();
    stackold.pop();
    return item;
}

int peek() {
    shiftstacks();
    return stackold.top();
}

int size() {
    return stackold.size() + stacknew.size();
}
std::stack<int> printStack(std::stack<int> s) {
    if (s.empty()) {
        return s;
    }
    int item = s.top();
    std::cout << "\t" << item;
    s.pop();
    printStack(s);
    s.push(item);
    return s;
}

int main() {
    enqueue(8);
    enqueue(2);
    enqueue(6);
    enqueue(3);
    std::cout << "peek():" << peek() << "\n";
    std::cout << "dequeue():" << dequeue() << "\n";
    std::cout << "dequeue():" << dequeue() << "\n";
    std::cout << "peek():" << peek() << "\n";
    enqueue(5);
    enqueue(9);
    std::cout << "peek():" << peek() << "\n";
    std::cout << "dequeue():" << dequeue() << "\n";
    std::cout << "dequeue():" << dequeue() << "\n";
    std::cout << "dequeue():" << dequeue() << "\n";
    std::cout << "peek():" << peek() << "\n";
    return 0;
}

