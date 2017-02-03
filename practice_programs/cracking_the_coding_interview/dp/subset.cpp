#include <iostream>
#include <string>
#include <stack>
#include <vector>

void printSubsets(std::vector<std::vector<int>> results) {
    std::vector<std::vector<int>>::iterator itr1 = results.begin();
    while (itr1 != results.end()) {
        std::vector<int>::iterator itr2 = (*itr1).begin();
        while (itr2 != (*itr1).end()) {
            std::cout << *itr2 << "\t";
            itr2++;
        }
        std::cout << "\n";
        itr1++;
    }
    std::cout << "\n";
}

std::vector<std::vector<int>> getSubsets(std::vector<int> set, int index) {
    std::vector<std::vector<int>> allsubsets;
    if (index == set.size()) {
        // new empty set
        std::vector<int> a;
        allsubsets.push_back(a);
    } else {
        allsubsets = getSubsets(set, index+1);
        int item = set[index];
        std::vector<std::vector<int>> moresubsets;
        std::vector<std::vector<int>>::iterator itr1 = allsubsets.begin();
        while (itr1 != allsubsets.end()) {
            std::vector<int> newsubset;
            newsubset.insert(newsubset.begin(), (*itr1).begin(), (*itr1).end());
            newsubset.push_back(item);
            moresubsets.push_back(newsubset);
            itr1++;
        }
        allsubsets.insert(allsubsets.end(), moresubsets.begin(), moresubsets.end());
    }
    return allsubsets;
}

std::vector<int> convertIntToSet(int val, std::vector<int> set) {
    std::vector<int> subset;
    int index = 0;
    for (int i = val; i > 0; i >>= 1) {
        if (i & 1) {
            subset.push_back(set[index]);
        }
        index++;
    }
    return subset;
}

std::vector<std::vector<int>> getSubsets2(std::vector<int> set) {
    std::vector<std::vector<int>> allsubsets;
    // compute 2^n, where n is the size of the set
    int max = 1 << set.size();
    for (int i = 0; i < max; i++) {
        std::vector<int> subset = convertIntToSet(i, set);
        allsubsets.push_back(subset);
    }
    return allsubsets;
}

int main() {
    std::vector<int> set;
    set.push_back(1);
    set.push_back(2);
    set.push_back(3);
    std::vector<std::vector<int>> results = getSubsets(set, 0);
    printSubsets(results);
    results = getSubsets2(set);
    printSubsets(results);
}
