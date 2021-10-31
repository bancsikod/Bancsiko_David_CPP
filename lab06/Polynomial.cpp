//
// Created by David on 10/28/2021.
//

#include "Polynomial.h"
#define X 10

Polynomial::Polynomial(int degree, const double *coefficients)
: capacity(degree+1)
, coefficients(new double[degree+1]) {

}

Polynomial::Polynomial(const Polynomial &that)
: capacity(that.capacity)
, coefficients(new double[that.capacity]) {
    copy(that.coefficients, that.coefficients + capacity, coefficients);
}

Polynomial::Polynomial(Polynomial &&that)
: capacity(0)
, coefficients(nullptr) {
    coefficients = that.coefficients;
    capacity = that.capacity;

    that.coefficients = nullptr;
    that.capacity = 0;
}

Polynomial::~Polynomial() {
    delete[] coefficients;
}

int Polynomial::degree() const {
    for (int i = capacity-1; i >= 0; --i) {
        if (coefficients[i] != 0){
            return i;
        }
    }
    return 0; //return -1 this should mean f(x) = 0 => degree is undefined
}

double Polynomial::evaluate(double x) const {
    int dgr = degree();
    double rslt = coefficients[dgr];
    for (int i = dgr - 1; i >= 0; --i) {
        rslt = rslt * x + coefficients[i];
    }
    return rslt;
}

Polynomial Polynomial::derivative() const {
    Polynomial der(degree()-1, nullptr);
    for (int i = 0; i < degree(); ++i) {
        der.coefficients[i] = coefficients[i+1] * (i+1);
    }
    return der;
}

double Polynomial::operator[](int index) const {
    if (index >= capacity) {
        return 0;
    }
    return coefficients[index];
}

Polynomial operator-(const Polynomial &a) {
    Polynomial rslt(a.capacity, nullptr);
    for (int i = 0; i < rslt.capacity; ++i) {
        rslt.coefficients[i] = a[i] * -1;
    }
    return rslt;
}

Polynomial operator+(const Polynomial &a, const Polynomial &b) {
    Polynomial rslt(max(a.degree(),b.degree()), nullptr);
    for (int i = 0; i < rslt.capacity; ++i) {
        rslt.coefficients[i] = a[i] + b[i];
    }
    return rslt;
}

Polynomial operator-(const Polynomial &a, const Polynomial &b) {
    Polynomial rslt(max(a.capacity,b.capacity), nullptr);
    for (int i = 0; i < rslt.capacity; ++i) {
        rslt.coefficients[i] = a[i] - b[i];
    }
    return rslt;
}

Polynomial operator*(const Polynomial &a, const Polynomial &b) {
    Polynomial prdct(a.degree() + b.degree() + 1, nullptr);
    for (int i = 0; i < prdct.capacity; ++i) {
        prdct.coefficients[i] = 0;
    }
    for (int i = 0; i <= a.degree(); ++i) {
        for (int j = 0; j <= b.degree(); ++j) {
            prdct.coefficients[i + j] += a[i] * b[j];
        }
    }
    return prdct;
}

istream &operator>>(istream &in, const Polynomial &what) {
    for (int i = what.capacity - 1; i >= 0; --i) {
        in >> what.coefficients[i];
    }
    return in;
}

ostream &operator<<(ostream &out, const Polynomial &what) {
    out << "f(x) = { ";
    for (int i = what.degree(); i >= 0; --i) {
        out << what.coefficients[i] << " ";
    }
    out << "};" <<endl;

//    out << "f(x) = ";
//    for (int i = 0; i <= what.degree(); ++i) {
//        if (what.coefficients[i] != 0) {
//            if(i == 0) {
//                out << what.coefficients[i];
//            } else if (i == 1) {
//                out << " + " << what.coefficients[i] << "x";
//            } else {
//                out << " + " << what.coefficients[i] << "x^" << i;
//            }
//        }
//    }
//    out << ";" <<endl;
    return out;
}








