#ifndef Location_HPP
#define Location_HPP

#include "Header.h"

class Location {

public:
	Location() {
		x = 0;
		y = 0;
	}

	Location(int x, int y) {
		this->x = x;
		this->y = y;
	}

	Location(Location &L) {
		this->x = L.x;
		this->y = L.y;
	}

	~Location() {
		this->x = 0;
		this->y = 0;
	}

	Location operator= (Location &location) {
		this->x = location.x;
		this->y = location.y;
	}

	void setLocation(int x, int y) {
		this->x = x;
		this->y = y;
	}

	void setAbsis(int x) {
		this->x = x;
	}

	void setOrdinat(int y) {
		this->y = y;
	}

	int getAbsis() {
		return x;
	}

	int getOrdinat() {
		return y;
	}

	bool isEqual(Location L) {
		return (L.x == this->x && L.y == this->y);
	}
	
	void move(int dx, int dy) {
		this->x += dx;
		this->y += dy;
	}

private:
	int x;
	int y;
};

#endif