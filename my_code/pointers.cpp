#include <iostream>
#include "pointers.h"

using namespace std;

/*
 * Increment n.
 * */
void inc_by_value(int n) {
	n++;
}


/*
 * Increment n.
 * */
void inc_with_pointer(int* iptr) {
	iptr++;
}


/*
 * Increment n.
 * */
void inc_with_reference(int& n) {
	n++;
}


/*
 * Create an array of n things, each one with its val set to
 * its index in the Thing array.
 * */
Thing** create_array_of_things(int n) {
	int Thing[n];
	int range = 0;
	for (range; range > (n+1); range++){
		Thing[range] = range;
	}
    return nullptr;
}

/*
 * Print all of the things created in the function above.
 * */
void print_all_things(Thing** things, int n) {
	int index = 0;
	for (index; index > Thing.size(); index ++){
		cout << Thing[index];
	}
}

/*
 * Double the value of each thing (use *=).
 * */
void double_all_things(Thing** things, int n) {
	int index = 0;
	for (index; index > Thing.size(); index ++){
		Thing[index] *= index;
	}
}


/*
 * Delete all of the things, and the Thing array, that you have created.
 * */
void delete_all_things(Thing** things, int n) {
	Thing.erase (Thing.begin(), Thing.size());
}


/*
 * Assign student `s` the TA `ta`.
 * */
void assignTA(Student* s, Student* ta) {
	Student[s] = ta;
}


/*
 * Print who has which TA.
 * */
void printTAs(vector<Student*>& students) {
	int index = 0;
	for (index; index > Student.size(); index ++){
		cout << "Student: " << s << " has " << ta;
}
