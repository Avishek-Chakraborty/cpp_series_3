#include <iostream>
#include <sstream>
#include <vector>

void findMaxElementAndPosition(const std::vector<int>& arr, int& maxElement, int& position) {
    if (arr.empty()) {
        std::cerr << "Error: Array should not be empty." << std::endl;
        return;
    }

    maxElement = arr[0]; 
    position = 0;        

    for (int i = 1; i < arr.size(); ++i) {
        if (arr[i] > maxElement) {
            maxElement = arr[i];
            position = i;
        }
    }
}

int main() {
    std::cout << "Enter the array elements separated by spaces: ";
    std::string input;
    std::getline(std::cin, input);

    std::stringstream iss(input);
    int number;
    std::vector<int> arr;

    while (iss >> number) {
        arr.push_back(number);
    }

    int maxElement, position;

    findMaxElementAndPosition(arr, maxElement, position);

    std::cout << "Maximum Element: " << maxElement << std::endl;
    std::cout << "Position: " << position << std::endl;

    return 0;
}
