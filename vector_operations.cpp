#include <iostream>;
#include <cmath>;


class Vector {
private:
	double x;
	double y;
	double z;
public:
	Vector() {
		x = 0;
		y = 0;
		z = 0;
	}
	Vector(double x_value, double y_value, double z_value) {
		x = x_value;
		y = y_value;
		z = z_value;
	}
	
	void print() {
		std::cout << '(' << x << ", " << y << ", " << z << ')' << std::endl;
	}

	Vector operator + (const Vector& other) {
		Vector temp;
		temp.x = this->x + other.x;
		temp.y = this->y + other.y;
		temp.z = this->z + other.z;
		return temp;
	}

	Vector operator - (const Vector& other) {
		Vector temp;
		temp.x = this->x - other.x;
		temp.y = this->y - other.y;
		temp.z = this->z - other.z;
		return temp;
	}

	Vector operator * (const Vector& other) {							// векторное произведение
		Vector temp;
		temp.x = (this->y) * other.z - (this->z) * other.y;				// раскрыл определитель, определяющий векторное умножение
		temp.y = (this->z) * other.x - (this->x) * other.z;
		temp.z = (this->x) * other.y - (this->y) * other.x;
		return temp;
	}

	friend double scalar_product(const Vector& vector1, const Vector& vector2);
	friend double cosinus(const Vector& vector1, const Vector& vector2);
};

double scalar_product(const Vector& vector1, const Vector& vector2) {
	return (vector1.x) * (vector2.x) + (vector1.y) * (vector2.y) + (vector1.z) * (vector2.z);
}

double cosinus(const Vector& vector1, const Vector& vector2) {
	double length_first = sqrt(pow(vector1.x, 2) + pow(vector1.y, 2) + pow(vector1.z, 2));
	double length_second = sqrt(pow(vector2.x, 2) + pow(vector2.y, 2) + pow(vector2.z, 2));
	return (scalar_product(vector1, vector2)) / (length_first * length_second);								// cos = (a,b) / (|a| * |b|)
}

int main() {
	setlocale(LC_ALL, "ru");
	Vector a(3, 5, 1);
	Vector b(-4, 0, 2);
	Vector e(7, 3, 9);
	Vector k(-5, -7, 4);
	Vector p(3, 2, 1);
	Vector z(-5, 7, -4);
	Vector c = a + b + e;
	Vector v = k - p - z;
	std::cout << "a + b + e:" << std::endl;
	c.print();
	std::cout << "k - p - z:" << std::endl;
	v.print();
	std::cout << "Скалярное произведение a на b:" << std::endl;
	std::cout << scalar_product(a, b) << std::endl;
	std::cout << "косинус между k и p:" << std::endl;
	std::cout << cosinus(k, p) << std::endl;
	Vector d;
	d = a * b;
	std::cout << "Векторное произведение a на b (получившийся вектор):" << std::endl;
	d.print();
	return 0;
}