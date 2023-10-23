#include <fstream>
#include <iostream>
#include <string>
using namespace std;

const int max_size = 100;

bool readMatrix(const char *filename, int matrix[max_size][max_size], int &N) {
  std::ifstream file(filename);
  if (!file.is_open()) {
    std::cout << "File not found." << std::endl;
    return false;
  }

  file >> N;

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      if (!(file >> matrix[i][j])) {
        std::cout << "Can't read data." << std::endl;
        return false;
      }
    }
  }

  file.close();
  return true;
}

bool readMatrix2(const char *filename, int matrix[max_size][max_size], int N) {
  std::ifstream file(filename);
  if (!file.is_open()) {
    std::cout << "File not found." << std::endl;
    return false;
  }

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      int temp;
      if (!(file >> temp)) {
        std::cout << "Can't read data." << std::endl;
        return false;
      }
      matrix[i][j] = temp;
    }
  }

  std::string line;
  std::getline(file, line);

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      if (!(file >> matrix[i][j])) {
        std::cout << "Can't read data." << std::endl;
        return false;
      }
    }
  }

  file.close();
  return true;
}

void printMatrix(const int matrix[max_size][max_size], int N) {
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      std::cout << matrix[i][j] << ' ';
    }
    std::cout << std::endl;
  }
  std::cout << "\n" << std::endl;
}

void matrixSum(const int matrix[max_size][max_size],
               const int matrix2[max_size][max_size],
               int sumResult[max_size][max_size], int N) {
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      sumResult[i][j] = matrix[i][j] + matrix2[i][j];
    }
  }
}

void matrixProduct(const int matrix[max_size][max_size],
                   const int matrix2[max_size][max_size],
                   int productResult[max_size][max_size], int N) {
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      for (int k = 0; k < N; k++) {
        productResult[i][j] += matrix[i][k] * matrix2[k][j];
      }
    }
  }
}

void matrixDifference(const int matrix[max_size][max_size],
                      const int matrix2[max_size][max_size],
                      int productResult[max_size][max_size], int N) {
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      productResult[i][j] = matrix[i][j] - matrix2[i][j];
    }
  }
}

int main() {
  int matrix[max_size][max_size];
  int matrix2[max_size][max_size];
  int N;
  int sumResult[max_size][max_size];
  int productResult[max_size][max_size];
  int differenceResult[max_size][max_size];

  std::string filename;
  std::cout << "Enter the file: ";
  std::cin >> filename;

  if (readMatrix(filename.c_str(), matrix, N) &&
      readMatrix2(filename.c_str(), matrix2, N)) {
    std::cout << "\nMikaela Navarro\nLab #6 Matrix Manipulatin\n" << std::endl;

    std::cout << "Matrix A:" << std::endl;
    printMatrix(matrix, N);

    std::cout << "Matrix B:" << std::endl;
    printMatrix(matrix2, N);

    matrixSum(matrix, matrix2, sumResult, N);
    std::cout << "Matrix Sum (A + B):" << std::endl;
    printMatrix(sumResult, N);

    matrixProduct(matrix, matrix2, productResult, N);
    std::cout << "Matrix Product (A * B):" << std::endl;
    printMatrix(productResult, N);

    matrixDifference(matrix, matrix2, differenceResult, N);
    std::cout << "Matrix Difference (A - B):" << std::endl;
    printMatrix(differenceResult, N);
  }

  return 0;
}
