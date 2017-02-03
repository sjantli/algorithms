#include <iostream>
#include <string>
#include <stack>

std::stack<int> sortStack(std::stack<int> s) {
    std::stack<int> r;
    while (!s.empty()) {
        int temp = s.top();
        s.pop();
        while (!r.empty() && r.top() > temp) {
            s.push(r.top());
            r.pop();
        }
        r.push(temp);
    }
    return r;
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
    std::stack<int> s;
    s.push(8);
    s.push(2);
    s.push(6);
    s.push(3);
    s.push(5);
    s.push(9);
    std::cout << "stack before sort: \n";
    printStack(s);
    s = sortStack(s);
    std::cout << "\nstack after sort: \n";
    printStack(s);
    std::cout << std::endl;
    return 0;
}

