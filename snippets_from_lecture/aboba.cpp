template<typename T>
struct MyContainer;

template<typename T, template<typename> typename Container>
struct Pod {
	Container<> container;
};

int main() {
	auto pod = Pod<int, MyContainer<bool>>();
	return 0;
}
