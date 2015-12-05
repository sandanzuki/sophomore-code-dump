#include "sparsematrix.h"

SparseMatrix::SparseMatrix(int m, int n){
    rows = My_vec<RowLinkedList>();
    
    nrows = n;
    for(int i = 0; i < nrows; i++){
        rows.insert_at_rank(i, RowLinkedList());
    }
    
    ncols = m;
}

SparseMatrix::~SparseMatrix(){
}

SparseMatrix::SparseMatrix(const SparseMatrix& input){
    rows = My_vec<RowLinkedList>();
    this->set_rows(input.nrows);
    this->set_cols(input.ncols);
    for(int i = 0; i < input.nrows; i++){
        rows.insert_at_rank(i, RowLinkedList(input.rows[i]));
    }
}

SparseMatrix& SparseMatrix::operator=(const SparseMatrix& input){
    rows = My_vec<RowLinkedList>();
    this->set_rows(input.nrows);
    this->set_cols(input.ncols);
    for(int i = 0; i < input.nrows; i++){
        rows.insert_at_rank(i, RowLinkedList(input.row(i)));   
    }
    return *this;
}

double SparseMatrix::get_element_at(int i, int j) const{
    DListNode<Element> *temp = row(i).getFirst();
    while(temp != NULL && temp->getElem().col != j){
        temp = temp->getNext();        
    }
    if(temp != NULL && temp->getElem().col == j) return temp->getElem().val;
    else return 0;
}

void SparseMatrix::set_element_at(int i, int j, double n){
    Element temp = Element(j,n);
    bool exist = false;
    DListNode<Element> *trav = row(i).getFirst();
    while(trav != NULL && trav != row(i).getAfterLast()){
        if(trav->getElem().col == j){
            exist = true;
            trav->getElemRef()->setVal(n);
        }
        trav = trav->getNext();
    }
    if(!exist) row(i).insertLast(temp);
}

double& SparseMatrix::operator()(int i, int j){
    Element temp = Element(j,0);
    bool exist = false;
    DListNode<Element> *trav = row(i).getFirst();
    while(trav != NULL && trav != row(i).getAfterLast()){
        if(trav->getElem().col == j){
            exist = true;
            break;
        }
        trav = trav->getNext();
    }
    if(!exist) row(i).insertLast(temp);
    trav = row(i).getFirst();
    while(trav != NULL && trav != row(i).getAfterLast()){
        if(trav->getElem().col == j){
            break;
        }
        trav = trav->getNext();
    }
    return trav->getElemRef()->val;
}

double SparseMatrix::operator()(int i, int j) const{
    double num;
    DListNode<Element> *temp = row(i).getFirst();
    while(temp != NULL && temp->getElem().col != j){
        temp = temp->getNext();        
    }
    if(temp != NULL && temp->getElem().col == j){
        num = (temp->getElem().val);
    }else num=0;
    return num;
    
}

SparseMatrix& SparseMatrix::operator+(const SparseMatrix& input) const{
    if(ncols != input.ncols || nrows != input.nrows){
        throw Dimension();
    }
    SparseMatrix& newMatrix = *(new SparseMatrix(nrows, ncols));
    for(int i = 0; i < nrows; i++){
        for(int j = 0; j < ncols; j++){
            newMatrix.set_element_at(i,j,(this->operator()(i,j) + input(i,j)));
        }
    }
    return newMatrix;
}

SparseMatrix& SparseMatrix::operator-(const SparseMatrix& input) const{
    if(ncols != input.ncols || nrows != input.nrows){
        throw Dimension();
    }
    SparseMatrix& newMatrix = *(new SparseMatrix(nrows, ncols));
    for(int i = 0; i < nrows; i++){
        for(int j = 0; j < ncols; j++){
            newMatrix(i,j) = this->operator()(i,j) - input(i,j);
        }
    }
    return newMatrix;
}

DenseVector& SparseMatrix::operator*(const DenseVector& input) const{
    if(ncols != input.get_size()){
        throw Dimension();
    }
    DenseVector& newVector = *(new DenseVector(nrows));
    for(int i = 0; i < nrows; i++){
        for(int j = 0; j < ncols; j++){
            newVector[i] += this->operator()(i,j);
        }
    }
    return newVector;
}

SparseMatrix& SparseMatrix::operator*(const SparseMatrix& input) const{
    if(ncols != input.nrows){
        throw Dimension();
    }
    SparseMatrix& newMatrix = *(new SparseMatrix(nrows, input.ncols));
    for(int i = 0; i < newMatrix.nrows; i++){
        for(int j = 0; j < newMatrix.ncols; j++){
            for(int k = 0; k < this->ncols; k++){
                newMatrix(i,j) += this->operator()(i,k)*input(k,j);
            }
        }
    }
    return newMatrix;
}

void SparseMatrix::transpose(){
    SparseMatrix temp = SparseMatrix(*this);
    this->set_cols(temp.nrows);
    this->set_rows(temp.ncols);
    for(int i = 0; i < nrows; i++){
        for(int j = 0; j < ncols; j++){
            this->set_element_at(i,j,temp(j,i));
        }
    }
}

void SparseMatrix::consolidate(){
    SparseMatrix temp = SparseMatrix(*this);
    this->set_cols(temp.ncols);
    this->set_rows(temp.nrows);
    for(int i = 0; i < nrows; i++){
        for(int j = 0; j < ncols; j++){
            if(temp(i,j) != 0) this->set_element_at(i,j,temp(i,j));
        }
    }
}

void SparseMatrix::print(const string &title){
    cout << title << endl;
    for(int i = 0; i < nrows; i++){
        for(int j = 0; j < ncols; j++){
            printf("%8.4f ", this->get_element_at(i,j));
        }
    cout << endl;
    }
    cout << "end" << endl;
}
