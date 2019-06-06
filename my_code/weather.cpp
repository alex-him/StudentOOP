#include <iostream>
#include <string>
#include "weather.h"

using namespace std;

/*
 * A constructor for weather class.
 * */
Weather::Weather(std::string nm, GPS loc) :
    station_nm(nm), my_loc(loc) {
}

string Weather::get_name() const{
    return station_nm;
}

int Weather::get_rating() const{
	return rating;
}

void Weather::set_rating(int new_rating){
	rating = new_rating;
}

ostream& operator<<(ostream& os, const Weather& w){
	int rat = w.get_rating();
	os << "name: " << w.station_nm << " rating: " << rat << " latitude: " << w.my_loc.latitude << " longitude: " << w.my_loc.longitude << endl;
	return os;
}