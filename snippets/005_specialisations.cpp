#include <string>
template<typename T, size_t N>
struct Foo {
	T bar[N];
};
// частичная специализация
template<size_t N>
struct Foo<char, N> {
	std::string bar = std::string(N);
};
// полная специализация
template<>
struct Foo<int32_t, 2> {
	int64_t bar;
};
int main() {
	Foo<bool, 3> foo1 = Foo<bool, 3>();
	Foo<int32_t, 2> foo2 = Foo<int32_t, 2>();
	Foo<char, 42> foo3 = Foo<char, 42>();
	return 0;
}