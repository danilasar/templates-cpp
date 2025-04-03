#include <iostream>
template<bool B>
struct bool_type {
	static constexpr bool value = B;
};
typedef bool_type<true> true_type;
typedef bool_type<false> false_type;

template<typename T, typename U>
struct is_same : false_type;

template<typename T>
struct is_same<T, T> : true_type;

// шаблонные переменные появились в C++14
template<typename T, typename U>
bool is_same_v = is_same<T, U>::value;

template<typename T, typename U>
bool compare_types(const T& l, const U& r) {
	if constexpr (is_same_v<T, U>) {
		std::cout << "Это один и тот же тип";
	} else {
		std::cout << "Это разные типы";
	}
}
int main() {
    std::cout << compare_types(1, 'a');
    std::cout << compare_types(1, 1);
	return 0;
}