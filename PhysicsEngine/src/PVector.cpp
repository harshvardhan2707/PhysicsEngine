#include <cmath>
class PVector {
	public:
		float x, y;
		PVector() {
			x = 0; y = 0;
		}
		PVector(float x, float y) {
			this->x = x;
			this->y = y;
		}
		PVector operator+(PVector& other) {
			return PVector(x + other.x, y + other.y);
		}
		PVector operator-(PVector& other) {
			return PVector(x -other.x, y -other.y);
		}
		PVector operator*(float f) {
			return PVector(x * f, y * f);
		}
		PVector operator/(float f) {
			return PVector(x / f, y / f);
		}
		float mag() {
			return std::sqrt(x * x + y * y);
		}
		PVector normalize() {
			float Mag = mag();
			return PVector(x / Mag, y / Mag);
		}

};