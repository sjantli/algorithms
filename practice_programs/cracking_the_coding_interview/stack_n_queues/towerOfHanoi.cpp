#include <iostream>
#include <string>
#include <stack>

class tower {
  private:
    std::stack<int> disks;
    int idx;
  public:
    tower(int i) {
        idx = i;
    }

    int index() {
        return idx;
    }

    void add(int d) {
        if (!disks.empty() && disks.top() <= d) {
            std::cout << "\n Error adding disk " << d << "to tower " << index() << "\n";
        } else {
            disks.push(d);
        }
    }

    void moveTopTo(tower *t) {
        int top = disks.top();
        disks.pop();
        t->add(top);
        std::cout << "move disk " << top << " from " << index() << " to " << t->index() << "\n";
    }

    void moveDisks(int n, tower *dest, tower *buffer) {
        if (n > 0) {
            // Move n-1 disks from this(origin) to buffer using dest as buffer
            moveDisks(n-1, buffer, dest);
            // move top from this(origin) to destination
            moveTopTo(dest);
            // move n-1 disks from buffer to destination using this(origin) as buffer
            buffer->moveDisks(n-1, dest, this);
        }
    }
    void printStack() {
        if (!disks.empty()) {
            int item = disks.top();
            std::cout << "\t" << item;
            disks.pop();
            printStack();
            disks.push(item);
        }
    }
};

int main() {
    std::cout << "Enter the number of disks to move from origin to dest\n";
    int n;
    std::cin >> n;
    tower* t[3];
    for (int i = 0; i < 3; i++) {
        t[i] = new tower(i);
    }

    for(int i = n-1; i >= 0; i--) {
        t[0]->add(i);
    }

    // move disks from origin to dest
    t[0]->moveDisks(n, t[2], t[1]);
    std::cout << "tower0 contents:\n";
    t[0]->printStack();
    std::cout << "tower1 contents:\n";
    t[1]->printStack();
    std::cout << "tower2 contents:\n";
    t[2]->printStack();
    std::cout << std::endl;
}
