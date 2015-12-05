/*My_vec.cpp
Jessica Fang
Cpp file for a vector data structure.
*/

#include "My_vec.h"

My_vec::My_vec(){
    size = 0;
    capacity = 1;
    ptr = new char[capacity];
}

My_vec::~My_vec(){
    delete ptr;
}

My_vec::My_vec(const My_vec& vec){
    size = vec.get_size();
    capacity = vec.get_capacity();
    ptr = new char[capacity];
    for(int i=0; i < size; ++i){
        ptr[i]=vec[i];
    }
}

My_vec& My_vec::operator=(const My_vec& vec){
    size = vec.get_size();
    capacity = vec.get_capacity();
    if(ptr != NULL){
        delete []ptr;
    }
    ptr = new char[size];
    for(int i=0; i < size; ++i){
        ptr[i]=vec[i];
    }
    return *this;
}

int My_vec::get_size() const{
    return size;
}

int My_vec::get_capacity() const{
    return capacity;
}

char& My_vec::operator[](int i) const{
    if(i < 0 || size <= i) throw Range();
    return ptr[i]; 
}

char& My_vec::operator[](int i){
    if(i < 0 || size <= i) throw Range();
    return ptr[i];
}

bool My_vec::is_empty() const{
    return size==0;
}

char& My_vec::elem_at_rank(int r) const{
    if(r < 0 || size <= r) throw Range();
    return ptr[r];
}

void My_vec::insert_at_rank(int r, const char& elem){
    if(size == capacity){
	capacity *= 2;
	char* temp = new char[capacity];
	memcpy(temp, ptr, size);
	delete ptr;
	ptr = temp;
    }
    size++;
    if(r == size+1){
        ptr[r]=elem;        
    }else if(r < 0 || size <= r){
        throw Range();
    }else{
        for(int temp = size; temp > r; --temp){
            ptr[temp] = ptr[temp-1];
        }
        ptr[r] = elem;
    }
}

void My_vec::replace_at_rank(int r, const char& elem){
    if(r < 0 || size <= r) throw Range();
    ptr[r] = elem;
}

void My_vec::remove_at_rank(int r){
    if(r < 0 || size <= r) throw Range();
    for(int temp = r; temp < size; ++temp){
        ptr[temp] = ptr[temp+1];
    }
    size--; 
    
}

ostream& operator<<(ostream& out, const My_vec& vec){
    out << "[ ";
    for(int i = 0; i < vec.get_size(); ++i){
        out << vec[i] << ' ';
    }
    out << ']';
    return out;
}

int find_max_index(const My_vec& v,int size){
    char max = 0;
    int index = -1;
    for(int i = 0; i < size; ++i){
        if(v[i] > max){
            max = v[i];
            index = i;
        }
    }
    return index;
}

void sort_max(My_vec& vec){
    int i, j, temp, min_index;
    for( i = 0; i < vec.get_size()-1; ++i){
        min_index = i;
        for(j = i+1; j < vec.get_size(); ++j){
                if(vec[min_index] > vec[j]){
                    min_index = j;
                }
            }
        if(min_index != i){
            temp = vec[i];
            vec[i] = vec[min_index];
            vec[min_index] = temp;
        }    
    }
}
