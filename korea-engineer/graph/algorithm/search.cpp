#include "../graph.cpp"

/**
 * 두 지점의 경로 찾기
 */

/**
 *   0
 *  /
 * 1 -- 3    7
 * |  / |   /
 * | /  |  5
 * 2 -- 4    \
 *            6 - 8
 */
int main() {
    Graph<int> g = Graph<int>(9);
    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(2, 4);
    g.addEdge(2, 3);
    g.addEdge(3, 4);
    // g.addEdge(3, 5);
    g.addEdge(5, 6);
    g.addEdge(5, 7);
    g.addEdge(6, 8);

    bool a = g.search(1, 4);  // true
    bool b = g.search(1, 8);  // false

    std::cout << a << std::endl;
    std::cout << b << std::endl;
}