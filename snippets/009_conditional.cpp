#include <iostream>
template<bool B>
struct bool_type {
	static constexpr bool value = B;
};
typedef bool_type<true> true_type;
typedef bool_type<false> false_type;

template<bool B, class T, class F>
struct conditional {
	using type = T;
};
 
template<class T, class F>
struct conditional<false, T, F> {
	using type = F;
};

template<bool B, class T, class F>
using conditional_t = typename conditional<B, T, F>::type;

// сделаем функцию сравнения чисел на этапе компиляции
template<int A, int B, typename Z = conditional_t<A <= B, true_type, false_type>>
void f() {
    // условная компиляция
    if constexpr (Z::value) {
        std::cout << "Меньше или равно";   
    } else {
        // даже не будет в выходном бинарнике
	    std::cout << "Больше";
    }
}

int main() {
    f<2, 3>();
}