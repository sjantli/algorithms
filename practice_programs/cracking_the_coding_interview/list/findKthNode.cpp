// Example program
#include <iostream>
#include <string>
#include <forward_list>
#include <iterator>

void printlist(std::forward_list<int> *list)
{
    std::forward_list<int>::iterator itr = list->begin();
    while(itr != list->end()) {
        std::cout << *itr << "\t";
        itr++;
    }
    std::cout << "\n";
}

std::forward_list<int>::iterator findKthNodeSLLRecursive(std::forward_list<int>::iterator start, std::forward_list<int>::iterator end, int k, int &index)
{
    std::cout << "inside recursive func \n";
    if (start == end) {
        std::cout << "End of list\n";
        return end;
    }
    std::forward_list<int>::iterator it = findKthNodeSLLRecursive(next(start, 1), end, k, index);
    index++;
    if (index == k) {
        std::cout << "index equals k \n";
        return start;
    }
    return it;
}

int main()
{
  std::string name;
  std::forward_list<int>* list = new std::forward_list<int>();
  std::forward_list<int>::iterator itr;
  std::cout << "enter the number of elements:\n";
  int n;
  std::cin >> n;
  std::cout << "Enter the elements:\n";
  for (int i = 0; i < n; i++) {
      int item;
      std::cin >> item;
      list->push_front(item);
  }
  printlist(list);
  std::cout << "enter K:\n";
  int k;
  std::cin >> k;
  int index = 0;
  std::cout << "k is:" << k << "\n";
  itr = findKthNodeSLLRecursive(list->begin(), list->end(), k, index);
  if (itr != list->end()) {
      std::cout << "kth node: " << *itr << "\n";
  } else {
      std::cout << "kth node is greater than the size of the list\n";
  }
  printlist(list);
}
