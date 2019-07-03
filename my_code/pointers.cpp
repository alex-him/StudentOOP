#include <iostream>
#include "pointers.h"
#include <vector>

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
	*iptr = ((*iptr)+1);
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
Thing** create_array_of_things(int n)  {
	Thing** array_of_things = new Thing*[n];

	for (int i = 0; i < n; i++){
		array_of_things[i] = new Thing(i);
	}
    return array_of_things;
}

/*
 * Print all of the things created in the function above.
 * */
void print_all_things(Thing** things, int n) {
	for (int i = 0; i < n; i ++){
		cout << things[i]->val << ' ';
	}
	cout << endl;
}

/*
 * Double the value of each thing (use *=).
 * */
void double_all_things(Thing** things, int n) {
	for (int index = 0; index < n; index ++){
		things[index]->val *= 2;
	}
}


/*
 * Delete all of the things, and the Thing array, that you have created.
 * */
void delete_all_things(Thing** things, int n) {
	for (int index = 0; index < n; index ++){
		delete things[index];
	}
	delete things;
}


/*
 * Assign student `s` the TA `ta`.
 * */
void assignTA(Student* s, Student* ta) {
	s->ta = ta;
}


/*
 * Print who has which TA.
 * */
void printTAs(vector<Student*>& students) {
	vector ref_vec = students;
	for (int i = 0; i < ref_vec.size(); i++){
		Student *student_ref = ref_vec[i];
		string stu_name = student_ref->name;
		cout << stu_name << endl ; //<< ta_name;
} }


