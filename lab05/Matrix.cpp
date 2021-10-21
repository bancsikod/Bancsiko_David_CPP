//
// Created by David on 10/21/2021.
//

#include "Matrix.h"

Matrix::Matrix(int rows, int cols) {
    this->mRows = rows;
    this->mCols = cols;
    this->mElements = new double *[rows];
    for (int i = 0; i < rows; ++i) {
        mElements[i] = new double [cols];
    }
}

Matrix::~Matrix() {
    for (int i = 0; i < mRows; ++i) {
        delete [] mElements[i];
    }
    delete[] mElements;
}

Matrix::Matrix(const Matrix &what) {
    mRows = what.mRows;
    mCols = what.mCols;
    mElements = new double *[mRows];
    for (int i = 0; i < mRows; ++i) {
        mElements[i] = new double [mRows];
        for (int j = 0; j < mCols; ++j) {
            mElements[i][j] = what.mElements[i][j];
        }
    }
}

void Matrix::fillMatrix(double value) {

}

void Matrix::randomMatrix(int a, int b) {

}

void Matrix::printMatrix(ostream &os) const {

}

Matrix operator+(const Matrix &x, const Matrix &y) {
    if (x.mRows != y.mRows || x.mCols != y.mCols) {
        throw out_of_range("nem osszeadhato matrixok");
    }
    Matrix result(x.mRows,x.mCols);
    for (int i = 0; i < result.mRows; ++i) {
        for (int j = 0; j < result.mCols; ++j) {
            result.mElements[i][j] = x.mElements[i][j] + y.mElements[i][j];
        }
    }
    return result;
}

double *Matrix::operator[](int index) {
    return mElements[index];
}

ostream &operator<<(ostream &os, const Matrix &mat) {

}

Matrix &Matrix::operator=(const Matrix &mat) {
    if (mRows != mat.mRows || mCols != mat.mCols) {
        throw out_of_range("nem jok a dimenziok");
    }

    if (this != &mat) {
        return *this;
    }

    for (int i = 0; i < mRows; ++i) {
        for (int j = 0; j < mCols; ++j) {
            mElements[i][j] = mat.mElements[i][j];
        }
    }

    return *this;
}


