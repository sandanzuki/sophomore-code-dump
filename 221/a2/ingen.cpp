//Output for powers of 10

#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

int main(){
	srand(time(0));
	int power, vsz;
	string order, infile = "input.txt";

	cout << "What power of 10 would you like to output to a file.txt?";
	cin >> power;
	
	vsz = pow(10.0,power);

	vector<int> vec(vsz);

	cout << "Would you like random, increasing order, or decreasing order?";
	cin >> order;

	if(order == "random"){
		for(int i = 0; i<vec.size(); ++i){
			vec[i] = (rand() % 100000);
		}
	}
	if(order == "increasing"){
		for(int i = 0; i < vec.size(); ++i){
			vec[i] = i;
		}
	}
	if(order == "decreasing"){
		for(int i = 0; vsz >= 0; ++i){
			vec[i] = vsz;
			--vsz;
		}
	}

	ofstream os;
		os.open(infile.c_str());

	os << vec.size() << endl;
	for(int i = 0; i < vec.size(); ++i)
		os << vec[i] << endl;

		os.close();
}
