#include "matrix.h"
#include <iostream>
using namespace std;

int main()
{
    matrix m1(2, 3, 1.0);
    matrix m2(3, 2, 2.0);
    matrix m4(2, 3, 3.0);
    matrix m3 = m1 * m2;
    cout << m3 << endl;
    cout << m1 << endl;
    cout << m4 + m1 << endl;
    m1 = m4;
    cout << m1 << endl;
    cout<< m1 + m2<<endl;
    cout<<m1*m4<<endl;
}