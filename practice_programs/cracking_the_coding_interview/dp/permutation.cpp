#include <iostream>
#include <string>
#include <stack>
#include <vector>
#include <sstream>

std::string insertCharAt(std::string str, int index, char c) {
    std::string start = str.substr(0, index);
    std::string end = str.substr(index);
    std::stringstream ss;
    ss << start << c << end;
    return ss.str();
}

std::vector<std::string> getPermutations(std::string str) {
    std::vector<std::string> permutations;
    if (str.length() == 0) {
        // base case, add empty string
        permutations.push_back("");
        return permutations;
    }
    char first = str.at(0);
    std::string remainder = str.substr(1);
    std::vector<std::string> words = getPermutations(remainder);
    for (std::string s : words) {
        for (int i = 0; i <= s.length(); i++) {
            // insert first char at every index in this word
            std::string res = insertCharAt(s, i, first);
            permutations.push_back(res);
        }
    }
    return permutations;
}

int main() {
    std::string str = "abcde";
    std::vector<std::string> perms = getPermutations(str);
    auto itr = perms.begin();
    while (itr != perms.end()) {
        std::cout << *itr << "\n";
        itr++;
    }
    return 0;
}
