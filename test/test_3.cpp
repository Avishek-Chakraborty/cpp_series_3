#include <iostream>
#include <vector>

std::vector<std::vector<int>> generatePascalsTriangle(int numRows) {
  std::vector<std::vector<int>> triangle;

  for (int i = 0; i < numRows; ++i) {
    std::vector<int> row(i + 1, 1);

    for (int j = 1; j < i; ++j) {
      row[j] = triangle[i - 1][j - 1] + triangle[i - 1][j];
    }

    triangle.push_back(row);
  }

  return triangle;
}

void printPascalsTriangle(const std::vector<std::vector<int>>& triangle) {
  for (const auto& row : triangle) {
    for (int num : row) {
      std::cout << num << " ";
    }
    std::cout << std::endl;
  }
}

int main() {
  int numRows;
  std::cout << "Enter the number of rows for Pascal's Triangle: ";
  std::cin >> numRows;

  std::vector<std::vector<int>> triangle = generatePascalsTriangle(numRows);

  std::cout << "Pascal's Triangle:" << std::endl;
  printPascalsTriangle(triangle);

  return 0;
}
