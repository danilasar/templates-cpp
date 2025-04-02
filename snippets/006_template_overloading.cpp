#include <iostream>

template<typename T, typename U>
void f(T, U)     { std::cout << 1; }

template<typename T>
void f(T, T)     { std::cout << 2; }

template<>
void f(int, int) { std::cout << 3; }

void f(int, int) { std::cout << 4; }

int main() {
	f(0, 0);
    return 0;
}