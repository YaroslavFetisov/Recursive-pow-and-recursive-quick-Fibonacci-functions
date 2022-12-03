#include <iostream>
using namespace std;
unsigned int recQuickFibCounter;

template <typename Type>
const Type& quickPower
(const Type& base, const int exponent, const Type& y = 1) {
	if (exponent == 0) {
		recQuickFibCounter++;
		return y;
	}
	if (exponent % 2 == 0) {
		recQuickFibCounter++;
		return quickPower(base * base, exponent / 2, y);
	}
	recQuickFibCounter++;
	return quickPower(base, exponent - 1, y * base);
}

struct Matrix2x2 {
		int _11, _12, _21, _22;
};

struct Vector2 {
	int _1, _2;
};

const Matrix2x2 operator*
(const Matrix2x2& a, const Matrix2x2& b) {
	Matrix2x2 res = { a._11 * b._11 + a._12 * b._21,a._11 * b._21 + a._12 * b._22,
	a._21 * b._11 + a._22 * b._21,a._21 * b._21 + a._22 * b._22 };
	return res;
}

const Vector2 operator*
(const Matrix2x2& a, const Vector2& v) {
	Vector2 res = { a._11 * v._1 + a._12 * v._2, a._21 * v._1 + a._22 * v._2 };
	return res;
}
const Matrix2x2 unitMatrix = { 1,0,0,1 };

//Works for 3 < n < 47. For n > 47: integer overflowes
int quickFib(int n) {
	recQuickFibCounter = 0;
	Matrix2x2 fibMatrix = { 1,1,1,0 }; Vector2 fibVector = { 1, 0 };
	Vector2 fibRes = quickPower(fibMatrix, n - 1, unitMatrix) * fibVector;
	cout << "\n" << "Call's number: \t" << recQuickFibCounter << endl;
	return fibRes._1;
}