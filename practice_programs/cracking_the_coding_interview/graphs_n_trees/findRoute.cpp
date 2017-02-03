#include <iostream>
#include <string>
#include <stack>
#include <queue>
#include <list>
#include <vector>

enum State {
    unvisited,
    visited
};

std::vector<std::list<int>> graph;
std::vector<State> state;

bool findRoute(int v1, int v2) {
    state[v1] = visited;
    std::queue<int> *q = new std::queue<int>();
    q->push(v1);
    while (!q->empty()) {
        int i = q->front();
        q->pop();
        std::list<int>::iterator itr = graph[i].begin();
        while(itr != graph[i].end()) {
            if (*itr == v2) {
                return true;
            }
            if (state[*itr] == unvisited) {
                    state[*itr] = visited;
                    q->push(*itr);
            }
            itr++;
        }
    }
    return false;
}

int main() {
    int v;
    std::cout << "Enter number of vertices\n";
    std::cin >> v;
    for (int i = 0; i < v; i++) {
        state.push_back(unvisited);
        std::list<int> list;
        graph.push_back(list);
        std::cout << "Enter the number of edges from vertex " << i << "\n";
        int e;
        std::cin >> e;
        for (int j = 0; j < e; j++) {
            std::cout << "Enter the edge \n";
            int num;
            std::cin >> num;
            graph[i].push_back(num);
        }
    }
    std::cout << "find foute from 1 to 3: " << findRoute(1, 3) << "\n";
    return 0;
}
