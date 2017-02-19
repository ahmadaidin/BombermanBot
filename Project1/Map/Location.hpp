#ifndef Location_HPP
#define Location_HPP

#include "../Header.h"

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

	Location(const Location &L) {
		this->x = L.x;
		this->y = L.y;
	}

	~Location() {
		this->x = 0;
		this->y = 0;
	}

	Location& operator= (const Location &location) {
		this->x = location.x;
		this->y = location.y;

		return *this;
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

	Location getLeft() {
		Location location(x-1, y);
		return location;
	}

	Location getRight() {
		Location location(x+1, y);
		return location;
	}

	Location getUp() {
		Location location(x, y-1);
		return location;
	}

	Location getDown() {
		Location location(x, y+1);
		return location;
	}

	Location getLeftUp() {
		Location location(x-1, y-1);
		return location;
	}

	Location getLeftDown() {
		Location location(x-1, y+1);
		return location;
	}

	Location getRightUp() {
		Location location(x+1, y-1);
		return location;
	}

	Location getRightDown() {
		Location location(x+1, y+1);
		return location;
	}

	float getDistance(Location location) {
		int x1 = location.getAbsis();
		int y1 = location.getOrdinat();
		return sqrt(abs((x - x1)*(x - x1) + (y - y1)*(y - y1)));
	}

	string toString() {
		return "(X:{" + to_string(getAbsis()) + "}, Y:{" + to_string(getOrdinat()) + "})";
	}

	Location getNearestLocation(vector<Location> options) {
		Location nearestLocation = options[0];
		for (int i = 1; i<options.size(); i++) {
			float distance = getDistance(options[i]);
			if (getDistance(options[i])<distance) {
				nearestLocation = options[i];
			}
		}
		return nearestLocation;
	}
	
	string getDirection(Location location) {
		if (x == location.x) {
			if (y == location.y) {
				return SAME_LOC;
			}
			else if (y < location.y) {
				return ABOVE;
			}
			else {
				return BELOW;
			}
		}
		else if(x > location.x){
			if (y == location.y) {
				return RIGHT;
			}
			else return DIAGONAL;
		}
		else if (x < location.x) {
			if (y == location.y) {
				return LEFT;
			}
			else return DIAGONAL;
		} 
	}

	bool isAbove(Location location) {
		return (location.y > y && location.x == x);
	}
	bool isBelow(Location location) {
		return (location.y < y && location.x == x);
	}
	bool isRight(Location location) {
		return (location.y == y && location.x < x);
	}
	bool isLeft(Location location) {
		return (location.y == y && location.x > x);
	}

	bool isRightAbove(Location location) {
		return (location.y > y && location.x < x);
	}
	bool isRightBelow(Location location) {
		return (location.y < y && location.x < x);
	}
	bool isLeftAbove(Location location) {
		return (location.y > y && location.x > x);
	}
	bool isLeftBelow(Location location) {
		return (location.y < y && location.x > x);
	}


private:
	int x;
	int y;
};

#endif