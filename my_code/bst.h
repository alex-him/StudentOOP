#include <iostream>

void indent(int level) {
    // indent more at each level:
    for (int i = 0; i < level; i++) std::cout << "  ";
}

template <typename T>
class Bst {
    
    friend void print_bst(const Bst<T>& bst, int level=0) //you are calling the const reference bst, initially starting at level 0
    {
        indent(level); //this places spaces so that it's easier to see our tree
        level++; //the level increments at each level
        std::cout << "data --> " << bst.data << std::endl; // the data will be called by calling std.data
        indent(level + 1); //why are we incrementing +1 here? --> A: We are showing the next level of the tree L and R sides
        std::cout << "left: ";
        if (!bst.left) std::cout << "nullptr"<< std::endl; //if there is nothing to the left then output nullptr
        else {
            std::cout << std::endl;
            indent(level); //indent the level
            print_bst(*bst.left,level); //recursively call the bst to print.
        }
        std::cout << "right: ";
        if (!bst.right) std::cout << "nullptr" <<std::endl; //you are going to output the nullptr if there is nothing to the right
        else {
            std::cout << std::endl;
            indent(level); //indent the level
            print_bst(*bst.right,level); //recursively call the level.
        }
        std::cout << std::endl;
    }
    /*
    friend T min(Bst<T>& bst)
    {
        if (!bst.left) {
            return bst.data;
        }
        else {
            return min(*bst.left);
        }
    }
    */
    public:
    Bst(T d, Bst* p=nullptr,Bst* l=nullptr,Bst* r=nullptr) : data(d),parent(p),left(l),right(r) {} //constructor
    
    T min() {
        if (!left) {
            return data;
        }
        else {
            return left -> min();
        }
    }
    
    T max() {
        if (!right) {
            return data;
        }
        else {
            return right -> max();
        }
    }
    
    Bst<T>* search(T d) {
        if (d == data ) return this; //note
        else if (d < data) {
            if (!left) {
                return nullptr;
            }
            else {
                return left -> search(d);
            }
        }
        else {
            if (!right) {
                return nullptr;
            }
            else {
                return right -> search(d);
            }
        }
    }
    
    Bst<T>* insert(const T d) {
        if (d == data) return nullptr;
        else if (d < data) {
            if (!left) {
            
                left = new Bst(d, this);
                return left;
            }
            else {
                
                return left -> insert(d);
           
            }
        }
        else {
       
            if (!right) {
                right = new Bst(d, this);
                return right;
            }
            else {
                return right ->insert(d); 
            }
        }
    }
    
    T predecessor(T d) {
        Bst<T>* node = search(d);

        if (node->left) {
            return node->left->max(); 
        }
        else {
            Bst<T>* parent = node->parent; 
            while (parent) {
                if (parent->data < d) {
                  
                    return parent->data;
                }
                parent = parent->parent; 
            }
            return d; 
        }
    }
    
    T successor(T d) {
        Bst<T>* node = search(d);
        if (node->right) {
            return node->right->min(); 
        }
        else {
            Bst<T>* parent = node->parent;
            while (parent) {
                if (parent->data > d) {
                    break;
                }
                parent = parent -> parent; 
                }
            return parent->data;
        }
    }
    
    T get_val() const {
        return data;
        }
    
    private:
        T data;
        Bst* parent;
        Bst* left;
        Bst* right;
};
