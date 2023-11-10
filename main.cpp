#include <iostream>
#include <cstdlib>
#include <ctime>

struct Matrix {
    int** data_ = nullptr;
    size_t n_ = 0u;
    size_t m_ = 0u;
};

void Construct(Matrix& out, size_t n, size_t m) {
    out.n_ = n;
    out.m_ = m;
    out.data_ = new int*[n];
    for (size_t i = 0; i < n; ++i) {
        out.data_[i] = new int[m]();
    }
}

void Destruct(Matrix& in) {
    for (size_t i = 0; i < in.n_; ++i) {
        delete[] in.data_[i];
    }
    delete[] in.data_;
    in.data_ = nullptr;
    in.n_ = 0;
    in.m_ = 0;
}

Matrix Copy(const Matrix& matrix) {
    Matrix copy;
    Construct(copy, matrix.n_, matrix.m_);
    for (size_t i = 0; i < matrix.n_; ++i) {
        for (size_t j = 0; j < matrix.m_; ++j) {
            copy.data_[i][j] = matrix.data_[i][j];
        }
    }
    return copy;
}

Matrix Add(const Matrix& a, const Matrix& b) {

    Matrix result;
    Construct(result, a.n_, a.m_);
    for (size_t i = 0; i < a.n_; ++i) {
        for (size_t j = 0; j < a.m_; ++j) {
            result.data_[i][j] = a.data_[i][j] + b.data_[i][j];
        }
    }
    return result;
}

Matrix Sub(const Matrix& a, const Matrix& b) {

    Matrix result;
    Construct(result, a.n_, a.m_);
    for (size_t i = 0; i < a.n_; ++i) {
        for (size_t j = 0; j < a.m_; ++j) {
            result.data_[i][j] = a.data_[i][j] - b.data_[i][j];
        }
    }
    return result;
}

Matrix Mult(const Matrix& a, const Matrix& b) {

    Matrix result;
    Construct(result, a.n_, b.m_);
    for (size_t i = 0; i < a.n_; ++i) {
        for (size_t j = 0; j < b.m_; ++j) {
            result.data_[i][j] = 0;
            for (size_t k = 0; k < a.m_; ++k) {
                result.data_[i][j] += a.data_[i][k] * b.data_[k][j];
            }
        }
    }
    return result;
}

void Transposition(Matrix& matrix) {
    Matrix transposed;
    Construct(transposed, matrix.m_, matrix.n_);
    for (size_t i = 0; i < matrix.n_; ++i) {
        for (size_t j = 0; j < matrix.m_; ++j) {
            transposed.data_[j][i] = matrix.data_[i][j];
        }
    }
    Destruct(matrix);
    matrix = transposed;
}

bool operator==(const Matrix& a, const Matrix& b) {
    if (a.n_ != b.n_ || a.m_ != b.m_) {
        return false;
    }
    for (size_t i = 0; i < a.n_; ++i) {
        for (size_t j = 0; j < a.m_; ++j) {
            if (a.data_[i][j] != b.data_[i][j]) {
                return false;
            }
        }
    }
    return true;
}

void FillRandom(Matrix& matrix) {
    for (size_t i = 0; i < matrix.n_; ++i) {
        for (size_t j = 0; j < matrix.m_; ++j) {
            matrix.data_[i][j] = rand() % 100;
        }
    }
}

int main() {
    srand(static_cast<unsigned>(time(0)));

    size_t n, m;
    std::cout << "rows: ";
    std::cin >> n;
    std::cout << "columns: ";
    std::cin >> m;

    Matrix mat1;
    Construct(mat1, n, m);
    FillRandom(mat1);

    Matrix mat2;
    Construct(mat2, n, m);
    FillRandom(mat2);

    Matrix sum = Add(mat1, mat2);
    Matrix difference = Sub(mat1, mat2);
    Matrix product = Mult(mat1, mat2);

    // Output
    std::cout << "Matrix 1:\n";
    for (size_t i = 0; i < mat1.n_; ++i) {
        for (size_t j = 0; j < mat1.m_; ++j) {
            std::cout << mat1.data_[i][j] << " ";
        }
        std::cout << std::endl;
    }

    std::cout << "Matrix 2:\n";
    for (size_t i = 0; i < mat2.n_; ++i) {
        for (size_t j = 0; j < mat2.m_; ++j) {
            std::cout << mat2.data_[i][j] << " ";
        }
        std::cout << std::endl;
    }

    std::cout << "    (+)\n";
    for (size_t i = 0; i < sum.n_; ++i) {
        for (size_t j = 0; j < sum.m_; ++j) {
            std::cout << sum.data_[i][j] << " ";
        }
        std::cout << std::endl;
    }

    std::cout << "    (-)\n";
    for (size_t i = 0; i < difference.n_; ++i) {
        for (size_t j = 0; j < difference.m_; ++j) {
            std::cout << difference.data_[i][j] << " ";
        }
        std::cout << std::endl;
    }

    std::cout << "    (*)\n";
    for (size_t i = 0; i < product.n_; ++i) {
        for (size_t j = 0; j < product.m_; ++j) {
            std::cout << product.data_[i][j] << " ";
        }
        std::cout << std::endl;
    }

    Destruct(mat1);
    Destruct(mat2);
    Destruct(sum);
    Destruct(difference);
    Destruct(product);

    return 0;
}
