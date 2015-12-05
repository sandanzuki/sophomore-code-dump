//Output for powers of 10

#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <stdio.h>      
#include <stdlib.h>     
#include <time.h>       

using namespace std;

int main(){
	srand(time(0));
	string type, infile = "input.txt";
	int power, num;
	
	cout<<"What would you like your output file to be called"<<endl;
	cin>>infile;
	
	infile = infile+".txt";
	cout << "Input what power of 10 to output to your file?"<<endl;
	cout<<" Ex, 10^1 = 10 numbers... 10^2 = 100 numbers"<<endl;
	cin >> power;
	
	num = pow(10.0,power); // make number 10^power

	vector<int> vec(num);  //vector to hold numbers

	cout << "Choose the order of output: random, increasing , or decreasing?";
	cin >> type;

	if(type == "random"||type == "Random"){    
		for(int i = 0; i<vec.size(); ++i){
			vec[i] = (rand() % 100000);
		}
	}
	if(type == "increasing"||type == "Increasing"){
		for(int i = 0; i < vec.size(); ++i){
			vec[i] = i;
		}
	}
	if(type == "decreasing"||type == "Decreasing"){
		for(int i = 0; num >= 0; ++i){
			vec[i] = num;
			--num;
		}
	}

	ofstream os;
		os.open(infile.c_str());

	os << vec.size() << endl;
	for(int i = 0; i < vec.size(); ++i)
		os << vec[i] << endl;

		os.close();
}
