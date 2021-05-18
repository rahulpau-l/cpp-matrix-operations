//
// Created by Rahul on 2021-05-16.
//

#ifndef _MATRIXX_H
#define _MATRIXX_H

#include <iostream>
#include <vector>
#include <stdexcept>

template <typename T>
class Matrix {
    template<typename U>
    friend std::ostream  &operator<<(std::ostream &os, const Matrix<U> &rhs);
private:
    std::vector<std::vector<T>> mat;
    int row;
    int col;

public:
    Matrix();
    Matrix(const Matrix<T> &m);
    Matrix(int row, int col, std::vector<std::vector<T>> &m);
    Matrix(std::vector<std::vector<T>> m);

    Matrix &operator=(Matrix<T> &rhs);
    Matrix &operator=(Matrix<T> &&rhs);
    Matrix operator+(const Matrix<T> &rhs);
    Matrix operator-(const Matrix<T> &rhs);
    bool operator==(const Matrix<T> &rhs) const;
    Matrix operator*(const Matrix<T> &rhs);

    int getCol() const;
    int getRow() const;

    void transpose();


};

template <typename T>
Matrix<T>::Matrix(const Matrix<T> &m) {
    mat = m.mat;
    row = m.getRow();
    col = m.getCol();
}

template <typename T>
Matrix<T>::Matrix(int row, int col, std::vector<std::vector<T>> &m): row(row), col(col), mat(std::move(m)) {

}

template <typename T>
Matrix<T>::Matrix(std::vector<std::vector<T>> m): mat(std::move(m)) {
    col = mat.size();
    row = mat[0].size();
}

template <typename T>
Matrix<T> &Matrix<T>::operator=(Matrix<T> &rhs) {
    mat = rhs.mat;
    row = rhs.getRow();
    col = rhs.getCol();

    return *this;
}

template <typename T>
Matrix<T> &Matrix<T>::operator=(Matrix<T> &&rhs) {
    mat = rhs.mat;
    row = rhs.getRow();
    col = rhs.getCol();

    return *this;
}

template <typename T>
Matrix<T> Matrix<T>::operator+(const Matrix<T> &rhs) {
    if(col != rhs.getCol() || row != rhs.getRow()){
        throw std::domain_error("Matrices not the same size");
    }

    for(int i = 0; i < rhs.mat.size(); i++){
        for(int j = 0; j < rhs.mat[j].size(); j++){
            this->mat[i][j] = this->mat[i][j] + rhs.mat[i][j];
        }
    }

    return *this;
}

template <typename T>
Matrix<T> Matrix<T>::operator-(const Matrix<T> &rhs) {

    if(col != rhs.getCol() || row != rhs.getRow()){
        throw std::domain_error("Matrices not the same size");
    }

    for(int i = 0; i < rhs.mat.size(); i++){
        for(int j = 0; j < rhs.mat[j].size(); j++){
            this->mat[i][j] = this->mat[i][j] - rhs.mat[i][j];
        }
    }

    return *this;
}

template <typename T>
bool Matrix<T>::operator==(const Matrix<T> &rhs) const{

    for(int i = 0; i < mat.size(); i++){
        for(int k = 0; k < mat[i].size(); k++){
            if(mat[i][k] != rhs.mat[i][k]){
                return false;
            }
        }
    }

    return true;
}

template <typename T>
Matrix<T> Matrix<T>::operator*(const Matrix<T> &rhs) {
    if(col != rhs.getRow()){
        throw std::domain_error("Columns don't match");
    }

    std::vector<std::vector<T>> result(mat.size(), std::vector<T>(rhs.mat.at(0).size()));


    for(std::size_t i = 0; i < result.size(); ++i) {
        for(std::size_t j = 0; j < result.at(0).size(); ++j) {
            result.at(i).at(j) = 0;
            for(std::size_t k = 0; k < rhs.mat.size(); ++k) {
                result.at(i).at(j) += mat.at(i).at(k) * rhs.mat.at(k).at(j);
            }
        }
    }

    Matrix u(result);
    return u;
}



template <typename T>
int Matrix<T>::getCol() const {
    return col;
}

template <typename T>
int Matrix<T>::getRow() const {
    return row;
}

template <typename T>
void Matrix<T>::transpose() {

    std::vector<std::vector<T>> tpose(mat[0].size(), std::vector<int>(mat.size()));

    for(int i = 0; i < mat.size(); i++){
        for(int j = 0; j < mat.size(); j++){
            tpose.at(i).at(j) = mat.at(j).at(i);
        }
    }

    mat = std::move(tpose);

}

template <typename U>
std::ostream &operator<<(std::ostream &os, const Matrix<U> &rhs) {
    for(int i = 0; i < rhs.mat.size(); i++){
        for(int j = 0; j < rhs.mat[i].size(); j++){
            os << rhs.mat[i][j] << " " ;
        }
        os << std::endl;

    }
    return os;
}

#endif //_MATRIXX_H
