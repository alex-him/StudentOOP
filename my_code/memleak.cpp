#include <iostream>
struct Thing{
	int * iarr;
	Thing(int n){
		iarr = new int[n];

	}

	~Thing() {
		delete []iarr;
		iarr = nullptr;
	}
};

const int OUTER = 1000000;
const int INNER = 1000;

int main() {
	for (int i = 0; i < OUTER; i ++){
		Thing** things = new Thing*[INNER];
		for (int j = 0; j < INNER; j++){
			things[j] = new Thing(INNER);
		}

		for (int j = 0; j < INNER; j++){
			delete things[j];
			things[j] = nullptr;
	 	}
	 	delete []things;
	 	things = nullptr
	}






}
