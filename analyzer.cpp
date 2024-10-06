#include <iostream>
#include <chrono>
#include "StringData.h"

int linear_search(const std::vector<std::string>& container, const std::string& element) {
    for (size_t i = 0; i < container.size(); ++i) {
        if (element == container[i]) {
            return i;
        }
    }
    return -1;
}

int binary_search(const std::vector<std::string>& container, const std::string& element) {
    int low = 0, high = container.size() - 1;

    while (low <= high) {
        int mid = (low + high) / 2;
        if (element == container[mid]) {
            return mid;
        } else if (element < container[mid]) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return -1;
}

int main() {
    std::vector<std::string> dataset = getStringData();

    auto begin_time = std::chrono::system_clock::now();
    linear_search(dataset, "not_here");
    auto end_time = std::chrono::system_clock::now();
    std::cout << "Time taken for linear search for 'not here': " << end_time - begin_time << " seconds" << std::endl;

    begin_time = std::chrono::system_clock::now();
    binary_search(dataset, "not_here");
    end_time = std::chrono::system_clock::now();
    std::cout << "Time taken for binary search for 'not here': " << end_time - begin_time << " seconds" << std::endl;

    begin_time = std::chrono::system_clock::now();
    linear_search(dataset, "mzzzz");
    end_time = std::chrono::system_clock::now();
    std::cout << "Time taken for linear search for 'mzzzz': " << end_time - begin_time << " seconds" << std::endl;

    begin_time = std::chrono::system_clock::now();
    binary_search(dataset, "mzzzz");
    end_time = std::chrono::system_clock::now();
    std::cout << "Time taken for binary search for 'mzzzz': " << end_time - begin_time << " seconds" << std::endl;

    begin_time = std::chrono::system_clock::now();
    linear_search(dataset, "aaaaa");
    end_time = std::chrono::system_clock::now();
    std::cout << "Time taken for linear search for 'aaaaa': " << end_time - begin_time << " seconds" << std::endl;

    begin_time = std::chrono::system_clock::now();
    binary_search(dataset, "aaaaa");
    end_time = std::chrono::system_clock::now();
    std::cout << "Time taken for binary search for 'aaaaa': " << end_time - begin_time << " seconds" << std::endl;

    return 0;
}