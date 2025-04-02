template<typename T = int, size_t N = 69>
struct Foo {
	T bar[N];
};
int main() {
	Foo foo1 = Foo(); // то же, что и Foo<int, 69>
	Foo<bool, 1> foo2 = Foo<bool, 1>();
	return 0;
}