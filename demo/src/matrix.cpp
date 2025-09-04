#include "matrix.h"

matrix::matrix()
{
    this->rows=0;
    this->cols=0;
}

matrix::matrix(int rows,int cols)
{
    this->rows=rows;
    this->cols=cols;
    data.resize(rows,vector<double>(cols,0));
}

matrix::matrix(int rows,int cols,double value)
{
    this->rows=rows;
    this->cols=cols;
    data.resize(rows,vector<double>(cols,value));
}

matrix::matrix(vector<vector<double>> d)
{
    this->rows=d.size();
    this->cols=d[0].size();
    data=d;
}

bool matrix::at(int row,int col)
{
    if(row>=0 && row<rows && col>=0 && col<cols)
        return 1;
    else throw std::out_of_range("Invalid matrix indices");   
}
int matrix::getRows() const
{
    return rows;
}
int matrix::getCols() const
{
    return cols;
}
vector<vector<double>> matrix::getData() const
{
    return data;
}
bool is_same_dimension(const matrix &m,const matrix &n)
{
    return (m.getRows()==n.getRows() && m.getCols()==n.getCols());
}


//matrix operator*(const matrix &m, const matrix &n)
//{
  //  matrix temp;
   // if(!temp.is_multiplicable(m,n))
    //    throw std::invalid_argument("Incompatible matrix dimensions");
    //else {
      //  temp.getData().resize(m.getRows());
       // for (int i = 0; i < m.getRows(); i++) {
         //   temp.getData()[i].resize(n.getCols());
           // for (int j = 0; j < n.getCols(); j++) {
             //   temp.getData()[i][j] = 0.0;
               // for (int k = 0; k < m.getCols(); k++) {
                 //   temp.getData()[i][j] += m.getData()[i][k] * n.getData()[k][j];
                //}
            //}
       // }
    //}
    //return temp;
//}
matrix operator*(const matrix &m, const matrix &n)
{
    if (m.cols != n.rows)
        throw std::invalid_argument("Incompatible matrix dimensions");

    matrix temp(m.rows, n.cols); // 直接初始化好大小
    for (int i = 0; i < m.rows; ++i) {
        for (int j = 0; j < n.cols; ++j) {
            temp.data[i][j] = 0.0;
            for (int k = 0; k < m.cols; ++k) {
                temp.data[i][j] += m.data[i][k] * n.data[k][j];
            }
        }
    }
    return temp;
}

ostream &operator<<(ostream &os,const matrix &m)
{
    for (const auto &row : m.getData()) {
        for (const auto &elem : row) {
            os << elem << " ";
        }
        os << "\n";
    }
    return os;
}
matrix operator+(const matrix &m, const matrix &n)
{
    if(!is_same_dimension(m,n))
        throw std::invalid_argument("Incompatible matrix dimensions");
    matrix temp(m.rows,m.cols);
    for(int i=0;i<m.rows;i++)
        for(int j=0;j<m.cols;j++)
            temp.data[i][j]=m.data[i][j]+n.data[i][j];
    return temp;
}

