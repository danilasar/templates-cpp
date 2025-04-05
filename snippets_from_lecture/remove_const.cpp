#include <iostream>

template<typename T>
void f(T& a) {
	//a = 5;
	const_cast<T&>(a) = 69;
}

void f(const int& a) {
	//a = 5;
	const_cast<int&>(a) = 69;
}

int main() {
	const int a = 5;
	const int& b = a;
	f(b);
	std::cout << a;
}
