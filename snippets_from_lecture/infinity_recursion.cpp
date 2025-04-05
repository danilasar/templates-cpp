#include<iostream>

template<short N>
struct Fibonacci {
    static const short value = Fibonacci<N - 1>::value + Fibonacci<N - 2>::value;
};
 
int main() {
	std::cout << Fibonacci<20>::value;
	return 0;
}
