#include <iostream>

template <typename T>
class Matrix {
   private:
    T** matrix;
    int n;

   public:
    Matrix<T>(int _n) {
        n = _n;
        matrix = new T*[n];
        for (int i = 0; i < n; i++) {
            matrix[i] = new T[n];
        }
    }

    void set(int x, int y, T val) { matrix[x][y] = val; }

    T get(int x, int y) { return matrix[x][y]; }

    const Matrix operator*(Matrix& matrix2) const {
        Matrix<T> resultMatrix = Matrix(n);

        for (int x = 0; x < n; x++) {
            for (int y = 0; y < n; y++) {
                int res = 0;
                for (int i = 0; i < n; i++) {
                    res += matrix[x][i] * matrix2.get(i, y);
                }
                resultMatrix.set(x, y, res);
            }
        }
        return resultMatrix;
    }

    friend std::ostream& operator<<(std::ostream& os, Matrix matrix) {
        for (int x = 0; x < matrix.n; x++) {
            for (int y = 0; y < matrix.n; y++) {
                os << matrix.get(x, y) << " ";
            }
            os << std::endl;
        }
        return os;
    }

    ~Matrix() { delete matrix; }
};