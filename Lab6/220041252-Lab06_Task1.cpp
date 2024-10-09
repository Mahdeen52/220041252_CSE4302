#include <iostream>
#include <cmath>

using namespace std;

class Matrix3D {
private:
    double matrix[3][3]; 
    int increment;      
    int count;   
    
public:
    Matrix3D(double mat[3][3], int inc = 1) : increment(inc), count(0) {
        if (inc < 0) increment = 1;
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                matrix[i][j] = mat[i][j];
            }
        }
    }

    ~Matrix3D() {}
    
    double determinant(const double mat[3][3]) const {
        return mat[0][0] * (mat[1][1] * mat[2][2] - mat[1][2] * mat[2][1]) -
               mat[0][1] * (mat[1][0] * mat[2][2] - mat[1][2] * mat[2][0]) +
               mat[0][2] * (mat[1][0] * mat[2][1] - mat[1][1] * mat[2][0]);
    }

    void inverseMatrix(const double mat[3][3], double invMat[3][3]) const {
        double det = determinant(mat);
        if (det == 0) {
            cout << "Matrix is singular and cannot be inverted." << endl;
            return;
        }

        invMat[0][0] = (mat[1][1] * mat[2][2] - mat[1][2] * mat[2][1]) / det;
        invMat[0][1] = (mat[0][2] * mat[2][1] - mat[0][1] * mat[2][2]) / det;
        invMat[0][2] = (mat[0][1] * mat[1][2] - mat[0][2] * mat[1][1]) / det;
        invMat[1][0] = (mat[1][2] * mat[2][0] - mat[1][0] * mat[2][2]) / det;
        invMat[1][1] = (mat[0][0] * mat[2][2] - mat[0][2] * mat[2][0]) / det;
        invMat[1][2] = (mat[0][2] * mat[1][0] - mat[0][0] * mat[1][2]) / det;
        invMat[2][0] = (mat[1][0] * mat[2][1] - mat[1][1] * mat[2][0]) / det;
        invMat[2][1] = (mat[0][1] * mat[2][0] - mat[0][0] * mat[2][1]) / det;
        invMat[2][2] = (mat[0][0] * mat[1][1] - mat[0][1] * mat[1][0]) / det;
    }

    

    double det() const {
        return determinant(matrix);
    }

    Matrix3D inverse() const {
        double invMat[3][3];
        inverseMatrix(matrix, invMat);
        return Matrix3D(invMat, increment);
    }

    void setIncrement(int val) {
        if (count == 0) {
            if (val >= 0) increment = val;
        }
        else {
            cout << "Cannot set increment." << endl;
        }
    }

    void getMatrix() const {
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                cout << matrix[i][j] << " ";
            }
            cout << endl;
        }
    }

    void incrementMatrix() {
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                matrix[i][j] += increment;
                count++;
            }
        }
    }

    Matrix3D operator+(const Matrix3D &rightSideMatrix) const {
        double result[3][3];
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                result[i][j] = matrix[i][j] + rightSideMatrix.matrix[i][j];
            }
        }
        return Matrix3D(result, increment);
    }

    Matrix3D operator-(const Matrix3D &rightSideMatrix) const {
        double result[3][3];
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                result[i][j] = matrix[i][j] - rightSideMatrix.matrix[i][j];
            }
        }
        return Matrix3D(result, increment);
    }

    Matrix3D operator*(const Matrix3D &rightSideMatrix) const {
        double result[3][3] = {0};
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                for (int k = 0; k < 3; k++) {
                    result[i][j] += matrix[i][k] * rightSideMatrix.matrix[k][j];
                }
            }
        }
        return Matrix3D(result, increment);
    }

    bool operator>(const Matrix3D &rightSideMatrix) const {
        return det() > rightSideMatrix.det();
    }

    bool operator<(const Matrix3D &rightSideMatrix) const {
        return det() < rightSideMatrix.det();
    }

    bool operator>=(const Matrix3D &rightSideMatrix) const {
        return det() >= rightSideMatrix.det();
    }

    bool operator<=(const Matrix3D &rightSideMatrix) const {
        return det() <= rightSideMatrix.det();
    }

    bool operator==(const Matrix3D &rightSideMatrix) const {
        return det() == rightSideMatrix.det();
    }

    bool operator!=(const Matrix3D &rightSideMatrix) const {
        return det() != rightSideMatrix.det();
    }
};

int main() {
    double mat1[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    double mat2[3][3] = {{1,3,5}, {6, 7, 8}, {3, 2, 1}};

    Matrix3D matrix1(mat1, 5);
    Matrix3D matrix2(mat2, 10);

    cout << "Matrix 1:" << endl;
    matrix1.getMatrix();
    matrix1.incrementMatrix();
    cout << "Matrix 1 after increment:" << endl;
    matrix1.getMatrix();
    
    cout<<"Matrix 2:"<<endl;
    matrix2.getMatrix();
    matrix2.incrementMatrix();
    cout << "Matrix 2 after increment:" << endl;
    matrix2.getMatrix();

    Matrix3D sumMatrix = matrix1 + matrix2;
    cout << "Sum matrix:" << endl;
    sumMatrix.getMatrix();

    if (matrix1 > matrix2) {
        cout << "Matrix 1 has a greater determinant." << endl;
    } 
    else if(matrix1<matrix2){
        cout << "Matrix 2 has a greater determinant." << endl;
    }
    
    else if(matrix1==matrix2) {
        cout<<"The matrices are equal"<<endl;
    }
    
    else if(matrix1!=matrix2) {
        cout<<"The matrices are unequal"<<endl;
    }
    
    else if(matrix1>=matrix2) {
        cout<<"Matrix 1 is greater or equal to Matrix 2"<<endl;
    }
    
    else if(matrix1<=matrix2) {
        cout<<"Matrix 2 is greater or equal to Matrix 2"<<endl;
    }

    return 0;
}
