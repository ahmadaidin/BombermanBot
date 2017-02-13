#ifndef Location_HPP
#define Location_HPP

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

private:
	int x;
	int y;
};

#endif