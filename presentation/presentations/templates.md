# Беды с
# шаблонами

---

## Метапрограммирование

Программы создаются метапрограммами,
а метапрограммы создаются метапрограммистами

---

![Самоидентификация и генерация](assets/metaprogramming.svg)

--

![Макросы и шаблоны](assets/macroses-and-templates.svg)

---

## Макросы

![Макрос vec!](assets/rust_macro.png)

--
<!-- .slide: data-auto-animate -->
## Шаблоны

<div class="eq_blocks">

<div class="left">

```cpp[]
	template<typename T>
	struct Foo {
		T bar;
	};
	Foo<int> foo1 = Foo<int>();
	Foo<std::string> foo2 = Foo<std::string>();
```

</div>

<div class="arrow">
	<img src="assets/then.png" />
</div>

<div class="right">

```cpp[]
struct Foo<int> {
	int bar;
};
struct Foo<std::string> {
	std::string bar;
};
Foo<int> foo1 = Foo<int>();
Foo<std::string> foo2 = Foo<std::string>();
```

</div>

</div>

--
<!-- .slide: data-auto-animate -->
## Шаблоны


<div class="eq_blocks">

<div class="left">

```cpp[2-4]
	template<typename T>
	struct Foo {
		T bar;
	};
	Foo<int> foo1 = Foo<int>();
	Foo<std::string> foo2 = Foo<std::string>();
```

</div>

<div class="arrow">
	<img src="assets/then.png" />
</div>

<div class="right">

```cpp[]
struct Foo<int> {
	int bar;
};
struct Foo<std::string> {
	std::string bar;
};
Foo<int> foo1 = Foo<int>();
Foo<std::string> foo2 = Foo<std::string>();
```

</div>

</div>

--
<!-- .slide: data-auto-animate -->
## Шаблоны


<div class="eq_blocks">

<div class="left">

```cpp[1]
	template<typename T>
	struct Foo {
		T bar;
	};
	Foo<int> foo1 = Foo<int>();
	Foo<std::string> foo2 = Foo<std::string>();
```

</div>

<div class="arrow">
	<img src="assets/then.png" />
</div>

<div class="right">

```cpp[]
struct Foo<int> {
	int bar;
};
struct Foo<std::string> {
	std::string bar;
};
Foo<int> foo1 = Foo<int>();
Foo<std::string> foo2 = Foo<std::string>();
```

</div>

</div>

--
<!-- .slide: data-auto-animate -->
## Шаблоны


<div class="eq_blocks">

<div class="left">

```cpp[1-4]
	template<typename T>
	struct Foo {
		T bar;
	};
	Foo<int> foo1 = Foo<int>();
	Foo<std::string> foo2 = Foo<std::string>();
```

</div>

<div class="arrow">
	<img src="assets/then.png" />
</div>

<div class="right">

```cpp[7]
struct Foo<int> {
	int bar;
};
struct Foo<std::string> {
	std::string bar;
};
	
Foo<int> foo1 = Foo<int>();
Foo<std::string> foo2 = Foo<std::string>();
```

</div>

</div>

--
<!-- .slide: data-auto-animate -->
## Шаблоны


<div class="eq_blocks">

<div class="left">

```cpp[5-6]
	template<typename T>
	struct Foo {
		T bar;
	};
	Foo<int> foo1 = Foo<int>();
	Foo<std::string> foo2 = Foo<std::string>();
```

</div>

<div class="arrow">
	<img src="assets/then.png" />
</div>

<div class="right">

```cpp[1-6]
struct Foo<int> {
	int bar;
};
struct Foo<std::string> {
	std::string bar;
};
	
Foo<int> foo1 = Foo<int>();
Foo<std::string> foo2 = Foo<std::string>();
```

</div>

</div>

---
<!-- .slide: data-auto-animate -->
## Явное инстанцирование

<div class="eq_blocks">

<div class="left">

```cpp[5]
template<typename T>
struct Foo {
	T bar;
};
template struct Foo<void*>();
Foo<int> foo1 = Foo<int>();
Foo<std::string> foo2 = Foo<std::string>();
```

</div>

<div class="arrow">
	<img src="assets/then.png" />
</div>

<div class="right">



```cpp[7-9]
struct Foo<int> {
	int bar;
};
struct Foo<std::string> {
	std::string bar;
};
struct Foo<void*> {
	void* bar;
};
Foo<int> foo1 = Foo<int>();
Foo<std::string> foo2 = Foo<std::string>();
```

</div>

</div>

--
<!-- .slide: data-auto-animate -->
## Множественные аргументы

<div class="eq_blocks">

<div class="left">

```cpp[]
template<typename T, size_t N>
struct Foo {
	T bar[N];
};
auto foo = Foo<int, 69>();
```

</div>

<div class="arrow">
	<img src="assets/then.png" />
</div>

<div class="right">

```cpp[]
struct Foo<int, 69> {
	int bar[69];
};
Foo<int, 69> foo = Foo<int, 69>();
```

</div>

</div>

--
<!-- .slide: data-auto-animate -->
## Аргументы по умолчанию

<div class="eq_blocks">

<div class="left">

```cpp[]
template<typename T = int, size_t N = 69>
struct Foo {
	T bar[N];
};
Foo foo1 = Foo(); // то же, что и Foo<int, 69>
Foo<bool, 1> foo2 = Foo<bool, 1>();
```

</div>

<div class="arrow">
	<img src="assets/then.png" />
</div>

<div class="right">

```cpp[]
struct Foo<int, 69> {
	int bar[69];
};
struct Foo<bool, 1> {
	bool bar[1];
};
Foo<int, 69> foo1 = Foo<int, 69>();
Foo<bool, 1> foo2 = Foo<bool, 1>();
```

</div>

</div>

---
<!-- .slide: data-auto-animate -->
## Специализации шаблона
<div class="eq_blocks">

<div class="left">

```cpp[]
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
Foo<bool, 3> foo1 = Foo<bool, 3>();
Foo<int32_t, 2> foo2 = Foo<int32_t, 2>();
Foo<char, 42> foo3 = Foo<char, 42>();
```

</div>

<div class="arrow">
	<img src="assets/then.png" />
</div>

<div class="right">

```cpp[]
struct Foo<bool, 3> {
	bool bar[3];
};
struct Foo<int32_t, 2> {
	int64_t bar;
};
struct Foo<char, N> {
	std::string bar = std::string(N);
};
Foo<bool, 3> foo1 = Foo<bool, 3>();
Foo<int32_t, 2> foo2 = Foo<int32_t, 2>();
Foo<char, 42> foo3 = Foo<char, 42>();
```

</div>

</div>

--
<!-- .slide: data-auto-animate -->
## Специализации шаблона
<div class="eq_blocks">

<div class="left">

```cpp[1-4,15]
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
Foo<bool, 3> foo1 = Foo<bool, 3>();
Foo<int32_t, 2> foo2 = Foo<int32_t, 2>();
Foo<char, 42> foo3 = Foo<char, 42>();
```

</div>

<div class="arrow">
	<img src="assets/then.png" />
</div>

<div class="right">

```cpp[1-3,10]
struct Foo<bool, 3> {
	bool bar[3];
};
struct Foo<int32_t, 2> {
	int64_t bar;
};
struct Foo<char, N> {
	std::string bar = std::string(N);
};
Foo<bool, 3> foo1 = Foo<bool, 3>();
Foo<int32_t, 2> foo2 = Foo<int32_t, 2>();
Foo<char, 42> foo3 = Foo<char, 42>();
```

</div>

</div>

--
<!-- .slide: data-auto-animate -->
## Специализации шаблона
<div class="eq_blocks">

<div class="left">

```cpp[5-9,17]
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
Foo<bool, 3> foo1 = Foo<bool, 3>();
Foo<int32_t, 2> foo2 = Foo<int32_t, 2>();
Foo<char, 42> foo3 = Foo<char, 42>();
```

</div>

<div class="arrow">
	<img src="assets/then.png" />
</div>

<div class="right">

```cpp[7-9,12]
struct Foo<bool, 3> {
	bool bar[3];
};
struct Foo<int32_t, 2> {
	int64_t bar;
};
struct Foo<char, N> {
	std::string bar = std::string(N);
};
Foo<bool, 3> foo1 = Foo<bool, 3>();
Foo<int32_t, 2> foo2 = Foo<int32_t, 2>();
Foo<char, 42> foo3 = Foo<char, 42>();
```

</div>

</div>

--
<!-- .slide: data-auto-animate -->
## Специализации шаблона
<div class="eq_blocks">

<div class="left">

```cpp[10-14,16]
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
Foo<bool, 3> foo1 = Foo<bool, 3>();
Foo<int32_t, 2> foo2 = Foo<int32_t, 2>();
Foo<char, 42> foo3 = Foo<char, 42>();
```

</div>

<div class="arrow">
	<img src="assets/then.png" />
</div>

<div class="right">

```cpp[4-6,11]
struct Foo<bool, 3> {
	bool bar[3];
};
struct Foo<int32_t, 2> {
	int64_t bar;
};
struct Foo<char, N> {
	std::string bar = std::string(N);
};
Foo<bool, 3> foo1 = Foo<bool, 3>();
Foo<int32_t, 2> foo2 = Foo<int32_t, 2>();
Foo<char, 42> foo3 = Foo<char, 42>();
```

</div>

</div>

--
<!-- .slide: data-auto-animate -->
## Специализации шаблона
<div class="eq_blocks">

<div class="left">

```cpp
// полная специализация
template<>
struct Foo<int32_t, 2> {
	int64_t bar;
};
// шаблон
template<typename T, size_t N>
struct Foo {
	T bar[N];
};
// частичная специализация
template<size_t N>
struct Foo<char, N> {
	std::string bar = std::string(N);
};
Foo<bool, 3> foo1 = Foo<bool, 3>();
Foo<int32_t, 2> foo2 = Foo<int32_t, 2>();
Foo<char, 42> foo3 = Foo<char, 42>();
```

</div>

<div class="arrow">
	<img src="assets/then.png" />
</div>

<div class="right">

```
2:8: error: ‘Foo’ is not a typename template
    2 | struct Foo<int32_t, 2> {
      |        ^~~
      |                        ^
7:8: error: ‘Foo’ is not a template
    7 | struct Foo {
      |        ^~~
2:8: note: previous declaration here
    2 | struct Foo<int32_t, 2> {
      |        ^~~
12:8: error: ‘Foo’ is not a typename template
   12 | struct Foo<char, N> {
      |        ^~~
12:18: error: ‘N’ was not declared in this scope
   12 | struct Foo<char, N> {
      |                  ^
12:19: error: ‘Foo’ is not a template
   12 | struct Foo<char, N> {
      |                   ^
2:8: note: previous declaration here
    2 | struct Foo<int32_t, 2> {
      |        ^~~
```

</div>

</div>
--
<!-- .slide: data-auto-animate -->
## Специализации шаблона

```cpp
template<typename T> typename Vector;        // общий шаблон
template<typename T> typename Vector<T*>;    // специализация для любых указателей
template<>           typename Vector<void*>; // специализация для void*
```

---
<!-- .slide: data-auto-animate -->
## Беды с шаблонами
--
<!-- .slide: data-auto-animate -->
## Беды с шаблонами

- Перегрузка шабона, эвристика работы компилятора

--
<!-- .slide: data-auto-animate -->
## Беды с шаблонами

- Перегрузка шабона, эвристика работы компилятора
- Бесконечность не предел: пакеты параметров и сжатые выражения

--
<!-- .slide: data-auto-animate -->
## Беды с шаблонами

- Перегрузка шабона, эвристика работы компилятора
- Бесконечность не предел: пакеты параметров и сжатые выражения
- Шаблонные шаблоны

--
<!-- .slide: data-auto-animate -->
## Беды с шаблонами

- Перегрузка шабона, эвристика работы компилятора
- Бесконечность не предел: пакеты параметров и сжатые выражения
- Шаблонные шаблоны
- ОП --- НО: Почему ошибка подстановки --- не ошибка?

--
<!-- .slide: data-auto-animate -->
## Беды с шаблонами

- Перегрузка шабона, эвристика работы компилятора
- Бесконечность не предел: пакеты параметров и сжатые выражения
- Шаблонные шаблоны
- ОП --- НО: Почему ошибка подстановки --- не ошибка?
- Условная компиляция

--
<!-- .slide: data-auto-animate -->
## Беды с шаблонами

- Перегрузка шабона, эвристика работы компилятора
- Бесконечность не предел: пакеты параметров и сжатые выражения
- Шаблонные шаблоны
- ОП --- НО: Почему ошибка подстановки --- не ошибка?
- Условная компиляция
- Вычисления на этапе компиляции

--
<!-- .slide: data-auto-animate -->
## Беды с шаблонами

- Перегрузка шабона, эвристика работы компилятора
- Бесконечность не предел: пакеты параметров и сжатые выражения
- Шаблонные шаблоны
- ОП --- НО: Почему ошибка подстановки --- не ошибка?
- Условная компиляция
- Вычисления на этапе компиляции
- Метафункции

--
<!-- .slide: data-auto-animate -->
## Беды с шаблонами

- Перегрузка шабона, эвристика работы компилятора
- Бесконечность не предел: пакеты параметров и сжатые выражения
- Шаблонные шаблоны
- ОП --- НО: Почему ошибка подстановки --- не ошибка?
- Условная компиляция
- Вычисления на этапе компиляции
- Метафункции
- Любопытно повторяющийся шаблонный шаблон

--
<!-- .slide: data-auto-animate -->
## Беды с шаблонами

- Перегрузка шабона, эвристика работы компилятора
- Бесконечность не предел: пакеты параметров и сжатые выражения
- Шаблонные шаблоны
- ОП --- НО: Почему ошибка подстановки --- не ошибка?
- Условная компиляция
- Вычисления на этапе компиляции
- Метафункции
- Любопытно повторяющийся шаблонный шаблон
- Шаблонные переменные

--
<!-- .slide: data-auto-animate -->
## Беды с шаблонами

- Перегрузка шабона, эвристика работы компилятора
- Бесконечность не предел: пакеты параметров и сжатые выражения
- Шаблонные шаблоны
- ОП --- НО: Почему ошибка подстановки --- не ошибка?
- Условная компиляция
- Вычисления на этапе компиляции
- Метафункции
- Любопытно повторяющийся шаблонный шаблон
- Шаблонные переменные
- Зависимые имена

---
<!-- .slide: data-auto-animate -->

## Загадка от Жака Фреско

```cpp
template<typename T, typename U>
void f(T, U)     { std::cout << 1; }

template<typename T>
void f(T, T)     { std::cout << 2; }

template<>
void f(int, int) { std::cout << 3; }

void f(int, int) { std::cout << 4; }

int main() {
	f(0, 0);
}
```

--
<!-- .slide: data-auto-animate -->

## Перегрузка шаблонов

```cpp
template<typename T, typename U>
void f(T, U)     { std::cout << 1; }

template<typename T>
void f(T, T)     { std::cout << 2; }

template<>
void f(int, int) { std::cout << 3; }

void f(int, int) { std::cout << 4; }

int main() {
	f(0, 0); // 4
}
```

--
<!-- .slide: data-auto-animate -->

## Перегрузка шаблонов

```cpp
template<typename T, typename U>
void f(T, U)     { std::cout << 1; }

template<typename T>
void f(T, T)     { std::cout << 2; }

template<>
void f(int, int) { std::cout << 3; }

int main() {
	f(0, 0);
}
```

--
<!-- .slide: data-auto-animate -->

## Перегрузка шаблонов

```cpp
template<typename T, typename U>
void f(T, U)     { std::cout << 1; }

template<typename T>
void f(T, T)     { std::cout << 2; }

template<>
void f(int, int) { std::cout << 3; }

int main() {
	f(0, 0); // 3
}
```

--
<!-- .slide: data-auto-animate -->

## Перегрузка шаблонов

```cpp
template<typename T, typename U>
void f(T, U)     { std::cout << 1; }

template<>
void f(int, int) { std::cout << 3; }

template<typename T>
void f(T, T)     { std::cout << 2; }

int main() {
	f(0, 0);
}
```

--
<!-- .slide: data-auto-animate -->

## Перегрузка шаблонов

```cpp
template<typename T, typename U>
void f(T, U)     { std::cout << 1; }

template<>
void f(int, int) { std::cout << 3; }

template<typename T>
void f(T, T)     { std::cout << 2; }

int main() {
	f(0, 0); // 2
}
```

--
<!-- .slide: data-auto-animate -->

## Перегрузка шаблонов

```cpp
template<typename T, typename U>
void f(T, U)     { std::cout << 1; }


template<typename T>
void f(T, T)     { std::cout << 2; }

int main() {
	f(0, 0); // 2
}
```

--
<!-- .slide: data-auto-animate -->

## Перегрузка шаблонов

```cpp
template<typename T, typename U>
void f(T, U)     { std::cout << 1; }

int main() {
	f(0, 0); // 1
}
```

--
<!-- .slide: data-auto-animate -->

## Перегрузка шаблонов

1. Сначала делается перегрузка между шаблонами
2. Из шаблона выбирается подходящая версия
3. В выбранный шаблон подставляются аргументы
4. Происходит перегрузка между получившимися функицями

Порядок объявлений специализацией может повлиять на то, кто чьей специализацией является.

Как следствие, в данном коде приоритеты определятся следующим образом: 4 &rarr; 3 &rarr; 2 &rarr; 1.

---

## Шаблонные шаблоны

```cpp[]
template<typename T>
struct MyContainer;

template<typename T, template<typename> typename Container = MyContainer<T>>
struct Pod {
	Container<T> container;
};

Pod<int> pod = Pod<int>(); // T = int, Container = MyContainer<int>
```

---

## Условная компиляция


<div class="eq_blocks">

```cpp
constexpr int i = 1;
if constexpr (i == 1) {
	std::cout << "Гойда";
} else {
	std::cout << "Не гойда";
}
```

<div class="arrow">
	<img src="assets/then.png" />
</div>

```cpp
const int i = 1;
std::cout << "Гойда";
```

</div>

---
<!-- .slide: data-auto-animate -->

## Вычисления на этапе компиляции

```cpp[]
template<int N>
struct Fibonacci {
	static const int value = Fibonacci<N - 1>::value + Fibonacci<N - 2>::value;
};

std::cout << Fibonacci<20>::value;
```
--

```
In instantiation of ‘const int Fibonacci<-879>::value’:
recursively required from ‘const int Fibonacci<19>::value’
	 static const int value = Fibonacci<N - 1>::value + Fibonacci<N - 2>::value;
                                              ^~~~~
required from ‘const int Fibonacci<20>::value’
required from here
	 std::cout << Fibonacci<20>::value;
                               ^~~~~
fatal error: template instantiation depth exceeds maximum of 900 (use ‘-ftemplate-depth=’ to increase the maximum)
	 static const int value = Fibonacci<N - 1>::value + Fibonacci<N - 2>::value;
                                              ^~~~~
compilation terminated.
```


--

```sh
g++ -ftemplate-depth=100000000 -o main main.cpp
```

--

```
g++-14: internal compiler error: Segmentation fault signal terminated program cc1plus
Please submit a full bug report, with preprocessed source (by using -freport-bug).
See <file:///usr/share/doc/gcc-14/README.Bugs> for instructions.
```

--
<!-- .slide: data-auto-animate -->

## Вычисления на этапе компиляции

```cpp[]
template<int N> 
struct Fibonacci { 
  static const int value = Fibonacci<N - 1>::value + Fibonacci<N - 2>::value; 
}; 
template<> 
struct Fibonacci<1> { 
  static const int value = 1; 
}; 
template<> 
struct Fibonacci<0> { 
  static const int value = 0; 
}; 
std::cout << Fibonacci<20>::value;
```

--
<!-- .slide: data-auto-animate -->

## Вычисления на этапе компиляции

```cpp[]
template<int N> requires (N >= 0) 
struct Fibonacci { 
  static const int value = Fibonacci<N - 1>::value + Fibonacci<N - 2>::value; 
}; 
template<> 
struct Fibonacci<1> { 
  static const int value = 1; 
}; 
template<> 
struct Fibonacci<0> { 
  static const int value = 0; 
}; 
std::cout << Fibonacci<20>::value;
```

---

## requires

```cpp[]
template<class T>
struct is_integral : std::bool_constant<
    requires (T t, T* p, void (*f)(T)) // T* исключает ссылочные типы
    {
        reinterpret_cast<T>(t); // Исключить классы
        f(0); // Исключить перечислимые типы
        p + t; // Исключить из оставшегося всё, что не интегральное
    }> {};
```
--
<!-- .slide: data-auto-animate -->

## Вычисления на этапе компиляции

```cpp[]
template<int N> requires (N >= 0) 
struct Fibonacci { 
  static const int value = Fibonacci<N - 1>::value + Fibonacci<N - 2>::value; 
}; 
template<> 
struct Fibonacci<1> { 
  static const int value = 1; 
}; 
template<> 
struct Fibonacci<0> { 
  static const int value = 0; 
}; 
std::cout << Fibonacci<-15>::value;
```

--


```cpp[]
In function ‘int main()’:
error: template constraint failure for ‘template  requires  N >= 0 struct Fibonacci’
    std::cout << Fibonacci<-20>::value;
                              ^
note: constraints not satisfied
In substitution of ‘template<int N>  requires  N >= 0 struct Fibonacci [with int N = -15]’:
   required from here
   required by the constraints of ‘template  requires  N >= 0 struct Fibonacci’
note: the expression ‘N >= 0 [with N = -15]’ evaluated to ‘false’
    template<int N> requires (N >= 0)
                         ~~~^~~~~
```

--

## Вычисления на этапе компиляции

```cpp[]
template<int N> requires (N >= 0)
struct Fibonacci {
	static const int value = Fibonacci<N - 1>::value + Fibonacci<N - 2>::value;
};
template<>
struct Fibonacci<1> {
	static const int value = 1;
};
template<>
struct Fibonacci<0> {
	static const int value = 0;
};
std::cout << Fibonacci<5>::value;
```

--


```cpp[]
struct Fibonacci<0> {
	static const int value = 0;
};

struct Fibonacci<1> {
	static const int value = 1;
};
struct Fibonacci<2> {
	static const int value = Fibonacci<1>::value + Fibonacci<0>::value; // 1
};
struct Fibonacci<3> {
	static const int value = Fibonacci<2>::value + Fibonacci<1>::value; // 2
};
struct Fibonacci<4> {
	static const int value = Fibonacci<3>::value + Fibonacci<2>::value; // 3
};
struct Fibonacci<5> {
	static const int value = Fibonacci<4>::value + Fibonacci<3>::value; // 5
};
std::cout << Fibonacci<5>::value; // 5
```

--

## Вычисления на этапе компиляции

```cpp[]
template<int N> requires (N >= 0)
struct Fibonacci {
	static constexpr const int value = Fibonacci<N - 1>::value + Fibonacci<N - 2>::value;
};
template<>
struct Fibonacci<1> {
	static const int value = 1;
};
template<>
struct Fibonacci<0> {
	static const int value = 0;
};
std::cout << Fibonacci<5>::value;
```

--

```cpp[]
struct Fibonacci<0> {
	static const int value = 0;
};

struct Fibonacci<1> {
	static const int value = 1;
};
struct Fibonacci<2> {
	static constexpr const int value = 1;
};
struct Fibonacci<3> {
	static constexpr const int value = 2;
};
struct Fibonacci<4> {
	static constexpr const int value = 3;
};
struct Fibonacci<5> {
	static constexpr const int value = 5;
};
std::cout << Fibonacci<5>::value; // 5
```
---
<!-- .slide: data-auto-animate -->

## Метафункции

--
<!-- .slide: data-auto-animate -->

## Метафункции

```cpp[]
template<bool B, class T, class F>
struct conditional {
	using type = T;
};
 
template<class T, class F>
struct conditional<false, T, F> {
	using type = F;
};

// шаблонный using для удобства
template<bool B, class T, class F>
using conditional_t = typename conditional<B, T, F>::type;
```

--
<!-- .slide: data-auto-animate -->

```cpp[2-7]
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
using conditional_t = typename conditional<B, T = true_type, F = false_type>::type;

// сделаем функцию сравнения чисел на этапе компиляции
template<int A, int B, typename Z = conditional_t<A <= B>>
void f() {
	// условная компиляция
	if constexpr (Z::value) {
		std::cout << "Меньше или равно";   
	} else {
	  // даже не попадёт в выходной бинарник
		std::cout << "Больше";
	}
}

int main() {
	f<2, 3>();
}
```

--
<!-- .slide: data-auto-animate -->

```cpp[14-20]
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
using conditional_t = typename conditional<B, T = true_type, F = false_type>::type;

// сделаем функцию сравнения чисел на этапе компиляции
template<int A, int B, typename Z = conditional_t<A <= B>>
void f() {
	// условная компиляция
	if constexpr (Z::value) {
		std::cout << "Меньше или равно";   
	} else {
	  // даже не попадёт в выходной бинарник
		std::cout << "Больше";
	}
}

int main() {
	f<2, 3>();
}
```

--
<!-- .slide: data-auto-animate -->

```cpp[22-32]
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
using conditional_t = typename conditional<B, T = true_type, F = false_type>::type;

// сделаем функцию сравнения чисел на этапе компиляции
template<int A, int B, typename Z = conditional_t<A <= B>>
void f() {
	// условная компиляция
	if constexpr (Z::value) {
		std::cout << "Меньше или равно";   
	} else {
	  // даже не попадёт в выходной бинарник
		std::cout << "Больше";
	}
}

int main() {
	f<2, 3>(); // Меньше или равно
}
```

--
<!-- .slide: data-auto-animate -->

```cpp[34-36]
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
using conditional_t = typename conditional<B, T = true_type, F = false_type>::type;

// сделаем функцию сравнения чисел на этапе компиляции
template<int A, int B, typename Z = conditional_t<A <= B>>
void f() {
	// условная компиляция
	if constexpr (Z::value) {
		std::cout << "Меньше или равно";   
	} else {
	  // даже не попадёт в выходной бинарник
		std::cout << "Больше";
	}
}

int main() {
	f<2, 3>();
}
```

---
<!-- .slide: data-auto-animate -->

## is_same


```cpp[]
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
```
--
<!-- .slide: data-auto-animate -->

```cpp[|8-16|18-25]
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
```


---
<!-- .slide: data-auto-animate -->

## remove_const

```cpp[]
#include <iostream>
template<typename T>
struct remove_const {
	using type = T;
};
template<typename T>
struct remove_const<const T> {
	using type = T;
};
template<typename T>
using remove_const_t = remove_const<T>::type;

template<typename T>
void f(T& a) {
	const_cast<remove_const_t<T>&>(a) = 69;
}

int main() {
	int i = 42;
	const int& rci = i;
	f(rci);
	std::cout << i; // 42 или 69?
}
```

--
<!-- .slide: data-auto-animate -->

```cpp[2-11|13-15|18-23]
#include <iostream>
template<typename T>
struct remove_const {
	using type = T;
};
template<typename T>
struct remove_const<const T> {
	using type = T;
};
template<typename T>
using remove_const_t = remove_const<T>::type;

template<typename T>
void f(T& a) {
	const_cast<remove_const_t<T>&>(a) = 69;
}

int main() {
	int i = 42;
	const int& rci = i;
	f(rci);
	std::cout << i; // 42 или 69?
}
```

---

## А что дальше?

<style>
.eq_blocks {
	padding: 1em;
	display: flex;
	flex-direction: row;
	gap: 1rem;
	align-items: center;
	justify-content: center;
}

.left, .right {
	min-width: 480px;
}

.arrow {
	width: 82px !important;
	min-width: 82px;
	height: 61px;
}

.slides {
	width: 1280px !important;
}
</style>
