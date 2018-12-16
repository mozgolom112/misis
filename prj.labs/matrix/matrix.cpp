#include "matrix.h";
#include <iostream>;
#include <stdexcept>;

Matrix::Matrix() {
    numline_ = 0;
    numcolumn_ = 0;
    matrix_ = new double *[numline_];
    matrix_[numline_] = new double[numcolumn_];
}

Matrix::Matrix(const int numline, const int numcolumn) {

    if (numline < 0) throw std::exception("Invalid argument for number of line. It can't be nagative.");
    if (numcolumn < 0) throw std::exception("Invalid argiment for number of column. It can't be nagative.");
    numline_ = numline;
    numcolumn_ = numcolumn;
    matrix_ = new double *[numline_];
    for (int n(0); n < numline_; n++) {
        matrix_[n] = new double[numcolumn_]{0.0};
    }
}

Matrix::Matrix(const Matrix &copy) {
    /*//ne obyzatelino, t.k. mi ne mozem ix sosdat takimi
    if (copy.numline_ < 0) throw std::exception("Invalid argument for number of line. It can't be nagative.");
    if (copy.numcolumn_ < 0) throw std::exception("Invalid argiment for number of column. It can't be nagative.");
    */
    numline_ = copy.numline_;
    numcolumn_ = copy.numcolumn_;
    matrix_ = new double *[numline_];
    for (int i(0); i < numline_; i++) {
        matrix_[i] = new double[numcolumn_];
        for (int j(0); j < numcolumn_; j++) {
            matrix_[i][j] = copy.matrix_[i][j];
        }
    }

}


Matrix::~Matrix() {
    for (int i(0); i < numline_; i++) {
        delete[] matrix_[i];
    }
    delete[] matrix_;
    matrix_ = {nullptr};
}


double &Matrix::at(const int line, const int column) const {
    if ((line > numline_) || (column > numcolumn_) || (line < 0) || (column < 0)) {
        throw std::out_of_range("Out of range in matrix");
    }

    return matrix_[line][column];
}

double &Matrix::at(const int line, const int column) {
    if ((line > numline_) || (column > numcolumn_) || (line < 0) || (column < 0)) {
        throw std::out_of_range("Out of range in matrix");
    }

    return matrix_[line][column];
}

int Matrix::numline() const {
    return numline_;
}


int Matrix::numcolumn() const {
    return numcolumn_;
}


void Matrix::resize(int newline, int newcolumn) {

    if (newline < 0) throw std::exception("Invalid argument for number of line. It can't be nagative.");
    if (newcolumn < 0) throw std::exception("Invalid argument for number of column. It can't be nagative.");

    int minnumberline = numline_;
    int minnumbercolumn = numcolumn_;

    if (newline <= numline_) {
        minnumberline = newline;
        for (int z(minnumberline); z < numline_; z++) //vse chto nizhe v nazhem matrix
        {
            delete[] matrix_[z]; //udalaem ostavshiesy strok

        }
    }

    if (newcolumn <= numcolumn_) minnumbercolumn = newcolumn;
    if ((newline <= numline_) && (newcolumn <= numcolumn_)) {

    } else {
        double **drop = new double *[newline];
        for (int n(0); n < newline; n++) {
            drop[n] = new double[newcolumn]{0.0};
        }
        for (int n(0); n < minnumberline; n++) {
            for (int q(0); q < minnumbercolumn; q++) {
                drop[n][q] = matrix_[n][q];
            }
            delete[] matrix_[n];
        }


        delete[] matrix_;
        matrix_ = drop;
    }
    numline_ = newline;
    numcolumn_ = newcolumn;

}

Matrix &Matrix::operator=(const Matrix &rhs) {
    if (this != &rhs) {

        double **drop = new double *[rhs.numline_];
        for (int n(0); n < rhs.numline_; n++) {
            drop[n] = new double[rhs.numcolumn_]{0.0};
            for (int q(0); q < rhs.numcolumn_; q++) {
                drop[n][q] = rhs.matrix_[n][q];
            }
        }
        for (int n(0); n < numline_; n++) {
            delete[] matrix_[n];
        }
        matrix_ = drop;
        numline_ = rhs.numline_;
        numcolumn_ = rhs.numcolumn_;


    }
    return *this;
}
