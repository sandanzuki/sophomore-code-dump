#include <iostream>
#include <fstream>
#include "sparsematrix.h"

int main(int argc, char **argv) {
  try {
    SparseMatrix A;

    // read a test matrix file
    ifstream fin("test.mat");
    fin >> A;
    fin.close();

    // display the matrix
    A.print("A");

    // show the element at (0, 0)
    cout << A.get_element_at(0, 0) << endl;

    // change the element at (0, 0) to 5.0
    A.set_element_at(0, 0, 5.0);
    A.print("A");

    // show the element at (5, 7)
    cout << A(5, 7) << endl;
    // set the element at (5, 7) to 1.0
    A(5, 7) = 1.0;
    A.print("A");

    // create another matrix B
    SparseMatrix B(A.get_rows(), A.get_cols());
    // fill ones in the diagonal
    for(int i=0;i<B.get_rows();++i) B(i, i) = 1.0;
    B.print("B");

    // A + B
    SparseMatrix C = A + B;
    C.print("C = A + B");

    // C - A, should be the same as B
    SparseMatrix D = C - A;
    D.print("D = C - A");
    
    // C * v, v is a dense vector with all 1.0s
    DenseVector v(C.get_cols());
    for(int i=0;i<C.get_cols();++i) v[i] = 1.0;

    DenseVector Cv = C * v;
    cout << "v = " << v << endl;
    cout << "C * v = "<< Cv << endl;

    // transpose
    D.transpose();
    D.print("D transpose");
    
    // C * B, this is optional
    // uncomment the following two lines if you work on it
    SparseMatrix E = C * B;
    E.print("E");

    return 0;
  }
  catch(exception &e) {
    return -1;
  }
}
