// https://www.acmicpc.net/problem/10871

#include <iostream>
#include <limits>
#include <sstream>
#include <vector>

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    int N, X;
    std::vector<int> v(N);
    std::string line;

    std::cin >> N >> X;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    getline(std::cin, line);

    std::stringstream ss(line);

    int value;
    int count;
    while (ss >> value) {
        v.push_back(value);
        if (value < X) {
            std::cout << value << " ";
        }
        count++;
        if (count == N) {
            break;
        }
    }

    return 0;
}