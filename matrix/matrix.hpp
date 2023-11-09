#ifndef MATRIX 
#define MATRIX

#include <vector>
#include <cassert>
#include <algorithm>
#include <ostream>
#include "general/fixed_integer.hpp"
#include "std_extension/vector.hpp"

template <typename T> 
class Matrix {
private:
    using MAT = std::vector<std::vector<T>>;
    MAT resize(MAT A, i32 sizeH, i32 sizeW) {
        for(auto &u : A) u.resize(sizeW);
        A.resize(sizeH,std::vector<T>(sizeW));
        return A;
    }
    std::tuple<MAT,MAT,MAT,MAT> divide(MAT A) {
        i32 N = A.size();
        MAT A11(N/2,std::vector<T>(N/2)), A12 = A11, A21 = A11, A22 = A11;
        for(i32 i = 0; i < N; i++) {
            for(i32 j = 0; j < N; j++) {
                if (i < N/2 && j < N/2) {
                    A11[i][j] = A[i][j];
                }
                else if (i < N/2) {
                    A12[i][j - N/2] = A[i][j];
                }
                else if (j < N/2) {
                    A21[i - N/2][j] = A[i][j];
                }
                else {
                    A22[i - N/2][j - N/2] = A[i][j];
                }
            }
        }
        return make_tuple(A11,A12,A21,A22);
    } 
    MAT join(MAT A11, MAT A12, MAT A21, MAT A22) {
        i32 N = A11.size() * 2;
        MAT ret(N, std::vector<T>(N));
        for(i32 i = 0; i < N; i++) {
            for(i32 j = 0; j < N; j++) {
                if (i < N/2 && j < N/2) {
                    ret[i][j] = A11[i][j];
                }
                else if (i < N/2) {
                    ret[i][j] = A12[i][j - N/2];
                }
                else if (j < N/2) {
                    ret[i][j] = A21[i - N/2][j];
                }
                else {
                    ret[i][j] = A22[i - N/2][j - N/2];
                }
            }
        }
        return ret;
    }
    MAT prod(MAT A, MAT B) {
        if (A.size() == 1) {
            return MAT{{A[0][0]*B[0][0]}};
        }
        auto [A11, A12, A21, A22] = divide(A);
        auto [B11, B12, B21, B22] = divide(B);

        MAT M1 = prod(A11 + A22, B11 + B22);
        MAT M2 = prod(A21 + A22, B11);
        MAT M3 = prod(A11, B12 - B22);
        MAT M4 = prod(A22, B21 - B11);
        MAT M5 = prod(A11 + A12, B22);
        MAT M6 = prod(A21 - A11, B11 + B12);
        MAT M7 = prod(A12 - A22, B21 + B22);

        return join(M1 + M4 - M5 + M7, M3 + M5, M2 + M4, M1 - M2 + M3 + M6);
    }
public:
    i32 H, W;
    MAT mat;
    Matrix(MAT vec) : mat(vec) {
        H = vec.size();
        assert(H != 0);
        W = vec[0].size();
        for(std::vector<T> &u : vec) {
            assert(u.size() == W);
        }
    }
    //copy constructor
    Matrix(const Matrix &r) : mat(r.mat), H(r.H), W(r.W) {}

    Matrix operator +() {
        return Matrix(mat);
    }
    Matrix operator -() {
        MAT tmat = mat;
        for(std::vector<T> &u : tmat) {
            for(T &v: u) {
                v = -v;
            }
        }
        return Matrix(tmat);
    }
    Matrix operator +(const Matrix &r) {
        return Matrix(*this)+=r;
    }
    Matrix operator -(const Matrix &r) {
        return Matrix(*this)-=r;
    }
    Matrix operator *(const Matrix &r) {
        return Matrix(*this)*=r;
    }
    Matrix &operator +=(const Matrix &r) {
        assert(H == r.H && W == r.W);
        for(i32 i = 0; i < H; i++) {
            for(i32 j = 0; j < W; j++) {
                mat[i][j] += r.mat[i][j];
            }
        }
        return *this;
    }
    Matrix &operator -=(const Matrix &r) {
        assert(H == r.H && W == r.W);
        for(i32 i = 0; i < H; i++) {
            for(i32 j = 0; j < W; j++) {
                mat[i][j] -= r.mat[i][j];
            }
        }
        return *this;
    }
    Matrix &operator *=(const Matrix &r) {
        assert(W == r.H);
        //TODO min 2beki number de kousokuka dekiru
        i32 mx = std::max(H, std::max(W, r.W)), size = 1;
        while(size < mx) size *= 2;
        W = r.W;
        mat = resize(prod(resize(mat, size, size), resize(r.mat,size,size)), H, W);
        return *this;
    }

    friend std::ostream& operator<<(std::ostream &os, const Matrix &m) {
        for(auto u : m.mat) {
            for(auto v : u) {
                os << v << " ";
            }
            os << std::endl;
        }
        return os;
    }

};


#endif