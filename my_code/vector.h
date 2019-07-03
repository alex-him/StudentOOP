#ifndef vector_hpp
#define vector_hpp

const int DEF_CAPACITY = 10;

class MyVec {
public:
    class Iterator {
        /*
         * This class supports ranged for loops.
         * It includes:
         * Iterator(int*)
         * operator++
         * operator*
         * operator!=
         * */
        friend bool operator!=(Iterator& rhs, Iterator& lhs) {
            return (rhs.iptr != lhs.iptr);
        }
        
    public:
        Iterator(int* ip) : iptr(ip) {}
        
        Iterator& operator++() {
            iptr = iptr + 1;
            return *this;
        }
        
        int operator*() { return *iptr; }
        
    private:
        int* iptr;
    };
    
    MyVec();
    MyVec(int sz, int val=0);
    
    MyVec(const MyVec& v2);
    ~MyVec();
    MyVec& operator=(const MyVec& v2);
    
    void push_back(int val);
    int size() const { return sz; }
    int operator[](int i) const;
    int& operator[](int i);
    Iterator begin() const;
    Iterator end() const;
private:
    int* data;
    int sz;
    int capacity;
};


void print_vector(const MyVec& v);

bool operator==(MyVec& v1, MyVec& v2);

#endif /* vector_hpp */