#include<iostream>
#include<vector>

int main() {
    std::vector<std::vector<int>> *vec = new std::vector<std::vector<int>>();
    std::vector<int> x;
    vec->push_back(x);
    std::vector<std::vector<int> *> *vecptr = new std::vector<std::vector<int> *>();
    vecptr->push_back(new std::vector<int>());
    (vecptr->at(0))->push_back(1);
    std::vector<int> *abc = new std::vector<int>();
    int a = 4;
    int b = 5;
    abc->push_back(a);
    abc->push_back(b);
    return 0;
}
