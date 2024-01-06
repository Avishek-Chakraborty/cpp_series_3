#include <iostream>
#include <unordered_set>

void printPairsWithSum(const int arr[], int size, int targetSum) {
    // Create a set to store visited elements
    std::unordered_set<int> visited;

    // Iterate through the array
    for (int i = 0; i < size; ++i) {
        // Calculate the complement needed to reach the target sum
        int complement = targetSum - arr[i];

        // Check if the complement is in the set
        if (visited.find(complement) != visited.end()) {
            // If found, print the pair
            std::cout << "Pair with sum " << targetSum << ": (" << complement << ", " << arr[i] << ")\n";
        }

        // Add the current element to the set
        visited.insert(arr[i]);
    }
}

int main() {
    int arr[] = {2, 5, 8, 3, 9, 1};
    int size = sizeof(arr) / sizeof(arr[0]);
    int targetSum = 10;

    printPairsWithSum(arr, size, targetSum);

    return 0;
}
