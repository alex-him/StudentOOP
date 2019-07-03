#ifndef TVECTOR_H
#define TVECTOR_H

#include <iostream>
#include <string>
#include <vector>

const int DEF_CAPACITY = 10;

template <typename DATA>
class MyVec {
public:
    MyVec() {
        data = new DATA[DEF_CAPACITY];
        sz = 0;
        capacity = DEF_CAPACITY;
    }
    
    MyVec(int sz, DATA val=0):sz(sz){
        data = new DATA[std::max(DEF_CAPACITY, 2 * sz)];
        capacity = 2 * sz;
        for(int i=0; i < sz; i++){
            data[i] = val;
        }
    }
    
    MyVec(const MyVec<DATA>& v2) {
        capacity = v2.capacity;
        sz = v2.sz;
        data = new DATA[capacity];
        for(int i=0; i < sz; i++){
            data[i] = v2[i];
        }
    }
    
    ~MyVec() {
        delete[] data;
    }
    
    MyVec<DATA>& operator=(const MyVec<DATA>& v2) {
        if(this == &v2){ return *this; }
        delete[] data;
        capacity = v2.capacity;
        sz = v2.sz;
        data = new DATA[capacity];
        for(int i=0; i < sz; i++){
            data[i] = v2[i];
        }
        return *this;
    }
    
    void push_back(DATA val) {
    if(sz == capacity) {
        capacity *= 2;
        DATA* new_data = new DATA[capacity];
        for(int i =0; i < sz; i++){
            new_data[i] = data[i];
        }
        delete[] data;
        data = new_data;
    }
    data[sz] = val;
    sz ++;
    }
    int size() const { return sz; }
    DATA operator[](int i) const {
        return data[i];
    }
    
    DATA& operator[](int i) {
        return data[i];
    }
    
private:
    DATA* data;
    int sz;
    int capacity;
};

template <typename DATA>
void print_vector(const MyVec<DATA>& v){
    std::cout << "[";
    for(int i = 0; i < v.size(); i++){
        std::cout << v[i];
        if(i != (v.size() - 1)){ std::cout <<  ",";}
    }
    std::cout << "]" << std::endl;
}

template <typename DATA>
bool operator==(MyVec<DATA>& v1, MyVec<DATA>& v2) {
    if(v1.size() != v2.size()){ return false; }
    for(int i =0; i < v1.size(); i++){
        if(v1[i] != v2[i]){ return false; }
    }
    return true;
}

#endif