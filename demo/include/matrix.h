#include<iostream>
#include<vector>
using std::vector;
using std::ostream;

class matrix
{
private:
    int rows;
    int cols;
    vector<vector<double>> data;

public:
    vector<vector<double>> getData() const;
    matrix();
    matrix(int rows,int cols);
    matrix(int rows,int cols,double value);
    matrix(vector<vector<double>>);
    matrix(const matrix &m);

    // 友元运算符声明
    friend matrix operator+(const matrix &m, const matrix &n);
    friend matrix operator*(const matrix &m, const matrix &n);
    friend ostream &operator<<(ostream &os, const matrix &m);

    bool at(int row,int col);
    int getRows() const;
    int getCols() const;
    //friend bool is_same_dimension(const matrix &m,const matrix &n);
    bool is_multiplicable(const matrix &m,const matrix &n);
    matrix &operator=(const matrix &m){
        if (this != &m) {
            rows = m.rows;
            cols = m.cols;
            data = m.data;
        }
        return *this;
    }
};




