#include <iostream>
#include <string>
#include <stack>
#include <vector>

#define MAX(a, b) (a > b) ? a : b
#define MIN(a, b) (a < b) ? a : b

std::vector<std::vector<int> *>* getSubsets(std::vector<int> *set, int index) {
    std::vector<std::vector<int> *> *allsubsets;
    if (index == set->size()) {
        // new empty set
        allsubsets = new std::vector<std::vector<int> *>();
        allsubsets->push_back(new std::vector<int>());
    } else {
        allsubsets = getSubsets(set, index+1);
        int item = set->at(index);
        std::vector<std::vector<int> *> *moresubsets = new std::vector<std::vector<int> *>();
        std::vector<std::vector<int> *>::iterator itr1 = allsubsets->begin();
        while (itr1 != allsubsets->end()) {
            std::vector<int> *newsubset = new std::vector<int>();
            newsubset->insert(newsubset->begin(), (*itr1)->begin(), (*itr1)->end());
            newsubset->push_back(item);
            moresubsets->push_back(newsubset);
            itr1++;
        }
        allsubsets->insert(allsubsets->end(), moresubsets->begin(), moresubsets->end());
    }
    return allsubsets;
}

int main() {
    std::vector<int> *set = new std::vector<int>();
    set->push_back(1);
    set->push_back(2);
//    set->push_back(3);
    std::vector<std::vector<int> *> *results = getSubsets(set, 0);
    std::vector<std::vector<int> *>::iterator itr1 = results->begin();
    while (itr1 != results->end()) {
        std::vector<int> *sub = *itr1;
        std::vector<int>::iterator itr2 = sub->begin();
        while (itr2 != sub->end()) {
            std::cout << *itr2 << "\t";
            itr2++;
        }
        std::cout << "\n";
        itr1++;
    }
    std::cout << "\n";
}
