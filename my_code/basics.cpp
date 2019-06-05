#include <iostream>
#include <string>
#include <vector>
#include "basics.h"

using namespace std;

/*
 * increment arg passed by copy
 * */
void inc_pass_copy(int j) {
	j = j + 1;
}

/*
 * increment arg passed by reference
 * */
void inc_pass_ref(int& j) {
	j = j + 1;
}

/*
 * Fill a vector with n elements from 1 to n.
 * 1st item == 1, 2nd item == 2, etc.
 * 0 filled for you.
 * Use `push_back()` to fill the vector.
 * */
void fill_vector(vector<int>& v, int n) {
	int i = 1;
	for(i; i < (n+1); i++){
		v.push_back(i);
	}
}

/*
 * Print all elements in a vector. Use a ranged for!
 * */
void print_vector(const vector<int>& v){
	int i = 0;
	for (i; i < v.size(); i++){
		std::cout << v[i] << ' ';
	}
	cout << endl;
}


/*
 * Print a pair of coordinates.
 / Output should look  like "x = 9, y = 2"
 * */
void print_coords(coord pos) {
	std::cout << "x = " << pos.x << ", y = " << pos.y << endl;
}

/*s
 * Square an integer.
 * */
int square(int n) {
    int result;
    result = n*n;
    return result;
}

/*
 * Square a double.
 * */
double square(double d) {
	double result;
	result = d * d;
    return result;
}

/*
 * Get the absolute value of a number.
 * */
int my_abs(int n) {
	if (n > 0)
		return n;
    return -n;
}

/*
 * Sum from 0 to n using a `while` loop.
 * */
int sum(int n) {
	int counter = 1;
	int sum = 0;
	while (counter != n) {
		sum = sum + counter;
		counter ++;
		}
    return sum;
}

/*
 * Sum from 0 to n using a `for` loop.
 * */
int sum2(int n) {
	int sum = 0;
    for(int counter = 0; counter != n; counter ++){
    	sum = sum + counter;
    }
    return sum;
}

/*
 * say() is built for you!
 * */
void say(std::string s) {
    cout << s << endl;
}


/*
 * Use a ranged for to pull a string apart into its bits.
 * */
void pull_apart_string(std::string s) {
	int i = 0;
	for (i; i<s.size(); i++)
		cout << s[i] << ' ';
	cout << endl;
}
