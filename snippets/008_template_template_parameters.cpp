template<typename T>
struct MyContainer;

template<typename T, template<typename> typename Container = MyContainer<T>>
struct Pod {
	Container<T> container;
};
int main() {
	Pod<int> pod = Pod<int>(); // T = int, Container = MyContainer<int>
	return 0;
}