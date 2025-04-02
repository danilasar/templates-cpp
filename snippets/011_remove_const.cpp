#include <iostream>
template<typename T>
struct remove_const {
	using type = T;
};
template<typename T>
struct remove_const<const T> {
	using type = T;
};
template<typename T>
using remove_const_t = remove_const<T>::type;

template<typename T>
void f(T& a) {
	const_cast<remove_const_t<T>&>(a) = 69;
}

int main() {
	int i = 42;
	const int& rci = i;
	f(rci);
	std::cout << i; // 42 или 69?
}