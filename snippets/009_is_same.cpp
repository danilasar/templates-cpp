#include <iostream>
template<typename T, typename U>
struct is_same {
	static constexpr bool value = false;
};
template<typename T>
struct is_same<T, T> {
	static constexpr bool value = true;
};
template<typename T, typename U>
bool is_same_v = is_same<T, U>::value;

template<typename T, typename U>
bool compare_types(const T& l, const U& r) {
	return is_same_v<T, U>;
}
int main() {
    std::cout << compare_types(1, 'a');
    std::cout << compare_types(1, 1);
	return 0;
}