#include <iostream>
#include "vector.h"

using namespace std;

void print_vector(const MyVec& v) {
    cout << "[";
    for(int i = 0; i < v.size(); i++){
        cout << v[i];
        if(i != (v.size() - 1)){ cout <<  ",";}
    }
    cout << "]" << endl;
}


MyVec::MyVec(int sz, int val) : sz{sz} {
    data = new int[max(DEF_CAPACITY, 2 * sz)];
    capacity = 2 * sz;
    for(int i=0; i < sz; i++){
        data[i] = val;
    }
}

MyVec::Iterator MyVec::begin() const {
    return MyVec::Iterator(data);
}

MyVec::Iterator MyVec::end() const {
    return MyVec::Iterator(data+sz);
}


MyVec::MyVec() {
    data = new int[DEF_CAPACITY];
    sz = 0;
    capacity = DEF_CAPACITY;
}

MyVec::MyVec(const MyVec& v2) {
    capacity = v2.capacity;
    sz = v2.sz;
    data = new int[capacity];
    for(int i=0; i < sz; i++){
        data[i] = v2[i];
    }
}

MyVec::~MyVec() {
    delete[] data;
}

MyVec& MyVec::operator=(const MyVec& v2) {
    if(this == &v2){ return *this; }
    delete[] data;
    capacity = v2.capacity;
    sz = v2.sz;
    data = new int[capacity];
    for(int i=0; i < sz; i++){
        data[i] = v2[i];
    }
    return *this;
}


/*
 * == is true when every element of the vectors are the same in
 * the same order. (Thus they must be the same size.)
 * */
bool operator==(MyVec& v1, MyVec& v2) {
    if(v1.size() != v2.size()){ return false; }
    for(int i =0; i < v1.size(); i++){
        if(v1[i] != v2[i]){ return false; }
    }
    return true;
}

/*
 * Puts an element at the back of a vector.
 * */
void MyVec::push_back(int val) {
    if(sz == capacity) {
        capacity *= 2;
        int* new_data = new int[capacity];
        for(int i =0; i < sz; i++){
            new_data[i] = data[i];
        }
        delete[] data;
        data = new_data;
    }
    data[sz] = val;
    sz ++;
}

/*
 * this [] is for reading items from the MyVec:
 * It returns the i-th element.
 * */
int MyVec::operator[](int i) const {
    return data[i];
}

/*
 * this [] allows write access to items in the MyVec:
 * It returns a reference to the i-th element.
 * */
int& MyVec::operator[](int i) {
    return data[i];
}

/*
 * == is true when every element of the vectors are the same in
 * the same order. (Thus they must be the same size.)
 * */
bool operator==(MyVec& v1, MyVec& v2) {
    if (v1.size() != v2.size()) {
        return false;
    } 
    else {  // v1.size() == v2.size()
        for (int i = 0; i < v1.size();  i++) {
            if (v1[i] != v2[i]) {
                return false;
            }
        }
        return true;
    }
}

MyVec::Iterator MyVec::begin() const {
    return MyVec::Iterator(data);
}

MyVec::Iterator MyVec::end() const {
    return MyVec::Iterator(data + size());
}

void MyVec::copy(const MyVec& v2) {
    sz = v2.sz;
    capacity = v2.capacity;
    data = new int[capacity];
    for (int i = 0; i < sz; i++) {
        data[i] = v2.data[i];
    }
}