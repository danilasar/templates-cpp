#include <string>
template<typename T>
struct Foo {
	T bar;
};
template struct Foo<void*>();
int main() {
	Foo<int> foo1 = Foo<int>();
	Foo<std::string> foo2 = Foo<std::string>();
	return 0;
}