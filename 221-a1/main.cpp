// Jessica Fang
// main.cpp
//Tests all functionality of the My_vec class.

#include <iostream>
#include <stdexcept>
#include "My_vec.h"
#include "My_vector.h"

int main(){
    try{
		//testing My_vec class
		My_vec v; // define an object v of My_vec type
        v.insert_at_rank(0, 'B');// insert 'B' at the rank 0 into the vector v
        cout << v << endl;// use the overloaded operator << to display vector elements
        cout << v.get_size() << endl;// display the vector v size

        v.insert_at_rank(0, 'A');// insert 'A' at the rank 0 into the vector v
        cout << v << endl; // use the overloaded operator << to display vector elements
        cout << v.get_size() << endl;// display the vector v size
        
        int temp = 0;
        while(temp < 10){
            v.insert_at_rank(v.get_size(), 'C' + temp);
            temp++;
        }

        cout << v << endl;

        v.insert_at_rank(10, 'D');// insert 'D' at the rank 10 into the vector v
        cout << v << endl; // use the overloaded operator << to display vector elements
        cout << v.get_size() << endl;// display the vector v size

        v.remove_at_rank(2);// remove a character at the rank 2 from the vector v
        cout << v << endl;// use the overloaded operator << to display vector elements
        cout << v.get_size() << endl;// display the vector v size

        v.replace_at_rank(2, 'E');// replace a character at the rank 2 by the character 'E' 
        cout << v << endl;// use the overloaded operator << to display vector elements
        cout << v.get_size() << endl;// display the vector v size

        My_vec v1(v);// create a copy v1 of the vector v using a copy constructor
        cout << v1 << endl;// use the overloaded operator << to display the vector v1
        v1.replace_at_rank(2, 'Y');// replace a character at the rank 2 of the vector v1 with the character 'Y'
        cout << v1 << endl;// use the overloaded operator << to display vector v1 elements

        My_vec v2;// define an object v2 of My_vec type
        v2.insert_at_rank(0, 'K');// insert 'K' at the rank 0 into the vector v2
        cout << v2 << endl;// use the overloaded operator << to display vector elements
        cout << v2.get_size() << endl;// display the vector v2 size

        v2 = v1;// test the assignment operator and copy the vector v1 to v2 
        cout << v2 << endl;// use the overloaded operator << to display vector v2
        cout << v2.get_size() << endl;// display the vector v2 size

        cout << find_max_index(v2, v2.get_size()) << endl;// test the function find_max_index using v2
        sort_max(v2);// test the function sort_max using v2
        cout << v2 << endl;
        
		temp = 0;
        while(temp < 10){
            v2.insert_at_rank(v2.get_size(), 'C' + temp);
            temp++;
        }

		v2.replace_at_rank(14, 'S');// replace in the vector v2 a character at the rank 14 with 'S'
        cout << v2 << endl;

        cout << "integers" << endl;	
		//testing My_vector class using template int
		My_vector <int> vec; // define an object v of My_vec type
        vec.insert_at_rank(0, 2);// insert 2 at the rank 0 into the vector v
        cout << vec << endl;// use the overloaded operator << to display vector elements
        cout << vec.get_size() << endl;// display the vector v size

        vec.insert_at_rank(0, 1);// insert 1 at the rank 0 into the vector v
        cout << vec << endl; // use the overloaded operator << to display vector elements
        cout << vec.get_size() << endl;// display the vector v size
        
        temp = 0;
        while(temp < 10){
			vec.insert_at_rank(vec.get_size(), (3 + temp));
			temp++;
        }

        cout << vec << endl;

        vec.insert_at_rank(10, 4);// insert 4 at the rank 10 into the vector v
        cout << vec << endl; // use the overloaded operator << to display vector elements
        cout << vec.get_size() << endl;// display the vector v size

        vec.remove_at_rank(2);// remove a number at the rank 2 from the vector v
        cout << vec << endl;// use the overloaded operator << to display vector elements
        cout << vec.get_size() << endl;// display the vector v size

        vec.replace_at_rank(2, 5);// replace a number at the rank 2 by the number 5
        cout << vec << endl;// use the overloaded operator << to display vector elements
        cout << vec.get_size() << endl;// display the vector v size

        My_vector <int> vec1(vec);// create a copy v1 of the vector v using a copy constructor
        cout << vec1 << endl;// use the overloaded operator << to display the vector v1
        vec1.replace_at_rank(2, 25);// replace a number at the rank 2 of the vector v1 with the number 25
        cout << vec1 << endl;// use the overloaded operator << to display vector v1 elements

        My_vector <int> vec2;// define an object v2 of My_vec type
        vec2.insert_at_rank(0, 11);// insert 11 at the rank 0 into the vector v2
        cout << vec2 << endl;// use the overloaded operator << to display vector elements
        cout << vec2.get_size() << endl;// display the vector v2 size

        vec2 = vec1;// test the assignment operator and copy the vector v1 to v2 
        cout << vec2 << endl;// use the overloaded operator << to display vector v2
        cout << vec2.get_size() << endl;// display the vector v2 size
	
        cout << find_max_index(vec2, vec2.get_size()) << endl;// test the function find_max_index using v2
        sort_max(vec2);// test the function sort_max using v2
        cout << vec2 << endl;
        
		temp = 0;
        while(temp < 10){
            vec2.insert_at_rank(vec2.get_size(), 3 + temp);
            temp++;
        }

		vec2.replace_at_rank(14, 19);// replace in the vector v2 a character at the rank 14 with 19
        cout << vec2 << endl;

        cout << "doubles" << endl;
        //testing My_vector class using template double
	My_vector <double> vector; // define an object v of My_vec type
        vector.insert_at_rank(0, 2.0);// insert 2 at the rank 0 into the vector v
        cout << vector << endl;// use the overloaded operator << to display vector elements
        cout << vector.get_size() << endl;// display the vector v size

        vector.insert_at_rank(0, 1.0);// insert 1 at the rank 0 into the vector v
        cout << vector << endl; // use the overloaded operator << to display vector elements
        cout << vector.get_size() << endl;// display the vector v size
        
        double temp1 = 0;
        while(temp1 < 10){
			vector.insert_at_rank(vector.get_size(), (3.0 + temp1));
			temp1++;
        }

        cout << vector << endl;

        vector.insert_at_rank(10, 4.0);// insert 4 at the rank 10 into the vector v
        cout << vector << endl; // use the overloaded operator << to display vector elements
        cout << vector.get_size() << endl;// display the vector v size

        vector.remove_at_rank(2);// remove a number at the rank 2 from the vector v
        cout << vector << endl;// use the overloaded operator << to display vector elements
        cout << vector.get_size() << endl;// display the vector v size

        vec.replace_at_rank(2, 5.0);// replace a number at the rank 2 by the number 5
        cout << vector << endl;// use the overloaded operator << to display vector elements
        cout << vector.get_size() << endl;// display the vector v size

        My_vector <double> vector1(vector);// create a copy v1 of the vector v using a copy constructor
        cout << vector1 << endl;// use the overloaded operator << to display the vector v1
        vector1.replace_at_rank(2, 25.0);// replace a number at the rank 2 of the vector v1 with the number 25
        cout << vector1 << endl;// use the overloaded operator << to display vector v1 elements

        My_vector <double> vector2;// define an object v2 of My_vec type
        vector2.insert_at_rank(0, 11.0);// insert 11 at the rank 0 into the vector v2
        cout << vector2 << endl;// use the overloaded operator << to display vector elements
        cout << vector2.get_size() << endl;// display the vector v2 size

        vector2 = vector1;// test the assignment operator and copy the vector v1 to v2 
        cout << vector2 << endl;// use the overloaded operator << to display vector v2
        cout << vector2.get_size() << endl;// display the vector v2 size
	
        cout << find_max_index(vector2, vector2.get_size()) << endl;// test the function find_max_index using v2
        sort_max(vector2);// test the function sort_max using v2
        cout << vector2 << endl;
        
	temp1 = 0;
        while(temp1 < 10){
            vector2.insert_at_rank(vector2.get_size(), 3.0 + temp1);
            temp1++;
        }

		vector2.replace_at_rank(14, 19.0);// replace in the vector v2 a character at the rank 14 with 19
        cout << vector2 << endl;
    }catch(exception &error){
        cerr << "Error: " << error.what() << endl;
    }
}
