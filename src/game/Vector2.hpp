#pragma once
#include <string>
#include <sstream>
//This namespace should get renamed lol
//I dont think i can actually do it like this but i want to put something down and this feels intuitively how this would work
struct vector2 {
	public:
		//x and y components of the vector
		float x;
		float y;
		//standard constructor accepts float for parameters x, y
		constexpr vector2(float x = 0.0f, float y = 0.0f) : x(x), y(y) {};

		//converts vector2 to string in (x,y) format
		std::string toString() const {
			std::ostringstream ss;
			ss << "(" << x << "," << y << ")";
			return ss.str();
		}
	
		//directional set and standard vectors
		static const vector2 zero;
		static const vector2 one;
		static const vector2 up;
		static const vector2 down;
		static const vector2 left;
		static const vector2 right;
		//OPERATORS 
		//vector + vector
		vector2 operator+(const vector2& other) {
			return vector2(x + other.x, y + other.y);
		}
		//vector - vector
		vector2 operator-(const vector2& other) {
			return vector2(x - other.x, y - other.y);
		}
		//vector divide by vector
		vector2 operator/(const vector2& other) {
			return vector2(x/other.x, y/other.y)
		}
		//vector multiply by scalar
		vector2 operator*(float scalar) {
			return vector2(x * scalar, y * scalar);
		}
		//vector divide by scalar
		vector2 operator/(float scalar) {
			return vector2(x / scalar, y / scalar)
		}

		//MEMBER FUNC
		// 
		//vector dot product
		float Dot(vector2 v1, vector2 v2) {
			return (v1.x * v2.x + v1.y * v2.y);
		}
		//cross product i dont think we need
		//returns float magn
		float magnitude{
			return SDL_sqrt(x * x + y * y);
		}
			float sqr_magnitude{
					return x * x + y * y;
		}
		//returns a normalized vector based on current vector
		vector2 normalize{
			vector2 result = vector2(x, y);
			result.Normalize();
			return result;
		}
		//sets vector magnitude to 1, or 0
		void Normalize(){
			float num = this.magnitude;
			if (num > 1E-05f){
				this /= num;
			}
			else{
				this = zero;
			}
		}
		//lerp
		//move towards
};
//maps standard and directional vectors
const vector2 vector2::zero = vector2(0.0f, 0.0f);
const vector2 vector2::one = vector2(1.0f, 1.0f);
const vector2 vector2::up = vector2(0.0f, 1.0f);
const vector2 vector2::down = vector2(0.0f, -1.0f);
const vector2 vector2::left = vector2(-1.0f, 0.0f);
const vector2 vector2::right = vector2(1.0f, 0.0f);