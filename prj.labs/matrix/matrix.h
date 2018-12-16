#pragma once
#pragma once
#ifndef MATRIX 15102018
#define MATRIX 15102018


class Matrix {
public:
    Matrix();

    Matrix(const int i, const int j);

    Matrix(const Matrix &copy);

    //вместо оператора [] написал в добавок метод at
    double &at(const int line, const int column) const;

    double &at(const int line, const int column);

    int numline() const;

    int numcolumn() const;

    ~Matrix();

    void resize(const int newline, const int newcolumn);

    Matrix &operator=(const Matrix &copy);


private:
    int numline_{};
    int numcolumn_{};
    double **matrix_{nullptr};


};

#endif // !Matrix 15102018
