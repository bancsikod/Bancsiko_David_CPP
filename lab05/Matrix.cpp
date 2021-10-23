//
// Created by David on 10/21/2021.
//

#include "Matrix.h"

Matrix::Matrix(int rows, int cols) : mRows (rows), mCols (cols) {
    mElements = new double *[rows];
    for (int i = 0; i < rows; ++i) {
        mElements[i] = new double [cols];
    }
}

Matrix::Matrix(const Matrix &what) : mRows(what.mRows), mCols(what.mCols) {
    mElements = new double *[mRows];
    for (int i = 0; i < mRows; ++i) {
        mElements[i] = new double [mCols];
        for (int j = 0; j < mCols; ++j) {
            mElements[i][j] = what.mElements[i][j];
        }
    }
}

Matrix::~Matrix() {
    for (int i = 0; i < mRows; ++i) {
        delete[] mElements[i];
    }
    delete[] mElements;
}

void Matrix::fillMatrix(double value) {
    for (int i = 0; i < mRows; ++i) {
        for (int j = 0; j < mCols; ++j) {
            mElements[i][j] = value;
        }
    }
}

void Matrix::randomMatrix(int a, int b) {
    srand(time(nullptr));
    for (int i = 0; i < mRows; ++i) {
        for (int j = 0; j < mCols; ++j) {
            mElements[i][j] = (double)(rand() % (b - a)) + a;
        }
    }
}

void Matrix::printMatrix(ostream &os) const {
    for (int i = 0; i < mRows; ++i) {
        for (int j = 0; j < mCols; ++j) {
            os << mElements[i][j] << "\t";
        }
        os << endl;
    }
}

Matrix operator+(const Matrix &x, const Matrix &y) {
    if (x.mRows != y.mRows || x.mCols != y.mCols) {
        throw out_of_range("Fault(+): operation is not permitted");
    }

    Matrix rslt(x.mRows,x.mCols);
    for (int i = 0; i < rslt.mRows; ++i) {
        for (int j = 0; j < rslt.mCols; ++j) {
            rslt.mElements[i][j] = x.mElements[i][j] + y.mElements[i][j];
        }
    }
    return rslt;
}

Matrix operator*(const Matrix &x, const Matrix &y) {
    if (x.mCols != y.mRows) {
        throw out_of_range("Fault(*): operation is not permitted");
    }

    Matrix rslt(x.mRows,y.mCols);
    for (int i = 0; i < x.mRows; ++i) {
        for (int j = 0; j < y.mCols; ++j) {
            rslt[i][j] = 0;
            for (int k = 0; k < y.mRows; ++k) {
                rslt[i][j] += x.mElements[i][k] * y.mElements[k][j];
            }
        }
    }

    return rslt;
}

istream &operator>>(istream &is, Matrix &mat) {
    for (int i = 0; i < mat.mRows; ++i) {
        for (int j = 0; j < mat.mCols; ++j) {
            is >> mat.mElements[i][j];
        }
    }
    return is;
}

ostream &operator<<(ostream &os, const Matrix &mat) {
    mat.printMatrix(os);
    return os;
}

Matrix &Matrix::operator=(const Matrix &mat) {
    if (mRows != mat.mRows || mCols != mat.mCols) {
        throw out_of_range("Fault(=): operation is not permitted");
    }

    if (this == &mat) {
        return *this;
    }

    for (int i = 0; i < mRows; ++i) {
        for (int j = 0; j < mCols; ++j) {
            mElements[i][j] = mat.mElements[i][j];
        }
    }

    return *this;
}


