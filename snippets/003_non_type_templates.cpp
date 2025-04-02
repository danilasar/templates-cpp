template<typename T, size_t N>
struct Foo {
	T bar[N];
};
int main() {
	auto foo = Foo<int, 69>();
	return 0;
}