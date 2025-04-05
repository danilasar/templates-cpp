#include <iostream>

template<bool B>
struct bool_type {
    static constexpr bool value = B;
};
typedef bool_type<true> true_type;
typedef bool_type<false> false_type;
 
template<typename T, typename U>
struct is_same : false_type {};
 
template<typename T>
struct is_same<T, T> : true_type {};
 
// шаблонные переменные появились в C++14
template<typename T, typename U>
constexpr bool is_same_v = is_same<T, U>::value;
 
template<typename T, typename U>
bool compare_types(const T& l, const U& r) {
    if constexpr (is_same_v<T, U>) {
        std::cout << "Это один и тот же тип\n";
				return true;
    } else {
        std::cout << "Это разные типы\n";
				return false;
    }
}

struct A {};
struct B : A {};

int main() {
	compare_types(0.1f, 0.2);
	auto* a = new A();
	auto* b = new B();
	compare_types(A(), B());
	compare_types(a, b);
}
