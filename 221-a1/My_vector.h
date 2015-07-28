/*My_vector.h
Jessica Fang
Header file for a vector data structure.
*/
#ifndef MY_VECTOR_H
#define MY_VECTOR_H
#include <ostream>
#include <cstring>

using namespace std;

template <class T>
class My_vector{
private:	
	//member variables
	int size, capacity;
	T *ptr;
    class Range{};
    
public:	
	//member functions
	My_vector();
	~My_vector();
	My_vector(const My_vector<T>& vec);
	My_vector& operator=(const My_vector<T>& vec);
	int get_size() const;
	int get_capacity() const;
	T& operator[](int i) const;
	T& operator[](int i);
	bool is_empty() const;
	T& elem_at_rank(int r) const;
	void insert_at_rank(int r, const T& elem);
	void replace_at_rank(int r, const T& elem);
	void remove_at_rank(int r);
	
};
	template <class T>
	ostream& operator<<(ostream& out, const My_vector<T>& vec);
	template <class T>
	int find_max_index(const My_vector<T>& v, int size);
	template <class T>
	void sort_max(My_vector<T>& vec);

    template <class T>
    My_vector<T>::My_vector(){
        size = 0;
        capacity = 1;
        ptr = new T[capacity];
    }

    template <class T>
    My_vector<T>::~My_vector(){
        delete ptr;
    }

    template <class T>
    My_vector<T>::My_vector(const My_vector<T>& vec){
        size = vec.get_size();
        capacity = vec.get_capacity();
        ptr = new T[capacity];
        for(int i=0; i < size; ++i){
            ptr[i]=vec[i];
        }
    }

    template <class T>
    My_vector<T>& My_vector<T>::operator=(const My_vector<T>& vec){
        size = vec.get_size();
        capacity = vec.get_capacity();
        delete ptr;
	ptr = new T[capacity];
        for(int i=0; i < size; ++i){
            ptr[i]=vec[i];
        }
        return *this;
    }

    template <class T>
    int My_vector<T>::get_size() const{
        return size;
    }

    template <class T>
    int My_vector<T>::get_capacity() const{
        return capacity;
    }

    template <class T>
    T& My_vector<T>::operator[](int i) const{
        if(i < 0 || size <= i) throw Range();
        return ptr[i]; 
    }

    template <class T>
    T& My_vector<T>::operator[](int i){
        if(i < 0 || size <= i) throw Range();
        return ptr[i];
    }

    template <class T>
    bool My_vector<T>::is_empty() const{
        return size==0;
    }

    template <class T>
    T& My_vector<T>::elem_at_rank(int r) const{
        if(r < 0 || size <= r) throw Range();
        return ptr[r];
    }

    template <class T>
    void print_array(T* array, int size) {
        for (int i = 0; i < size; ++i) {
            cout << array[i] << ", ";
        }
		
		cout << endl;
    }

    template <class T>
    void My_vector<T>::insert_at_rank(int r, const T& elem){
        size++;
        if(size == capacity){
            capacity *= 2;
            T* temp = new T[capacity];
			for(int i = 0; i < size; i++){
				temp[i]= ptr[i];
			}
            //memcpy(temp, ptr, capacity + 1);
            delete ptr;
            ptr = temp;
            
        }
        
        if(r == size + 1){
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

    template <class T>
    void My_vector<T>::replace_at_rank(int r, const T& elem){
        if(r < 0 || size <= r) throw Range();
        ptr[r] = elem;
    }

    template <class T>
    void My_vector<T>::remove_at_rank(int r){
        if(r < 0 || size <= r) throw Range();
        for(int temp = r; temp < size; ++temp){
            ptr[temp] = ptr[temp+1];
        }
        size--; 

    }

    template <class T>
    ostream& operator<<(ostream& out, const My_vector<T>& vec){
        out << "[ ";
        for(int i = 0; i < vec.get_size(); ++i){
            out << vec[i] << ' ';
        }
        out << ']';
        return out;
    }

    template <class T>
    int find_max_index(const My_vector<T>& v,int size){
        T max = 0;
        int index = -1;
        for(int i = 0; i < size; ++i){
            if(v[i] > max){
                max = v[i];
                index = i;
            }
        }
        return index;
    }

    template <class T>
    void sort_max(My_vector<T>& vec){
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


#endif
