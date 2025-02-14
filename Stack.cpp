#include <iostream>

using namespace std;

class Stack {
private:
	int* arr;	//Указатель на динамически выделенный массив, а память под массив будет выделенна в конструкторе 
	int top;	//Индекс верхнего элемента
	int capacity;	//Максимальная вместимость очереди
public:
	//Конструктор
	Stack(int capacity) {
		this->capacity = capacity; //Устанавливаем макс вместимость стека
		arr = new int(capacity);	//Выделение памяти под массив размером capacity
		top = -1; //Индекс верхнего элемента -1
	}

	//Деструктор 
	~Stack() {
		delete[] arr; //Освобождение памяти
	}
	//Проверка пуст ли стек
	bool isEmpty() {
		return top == -1; //Возвращаем true, если размер равен -1, false в противном случае
	}
	//Проверка полон ли стек
	bool isFull() {
		return top == capacity;//Возвращает true, если индекс верхнего элемента равен макс вместимости, false в противном случае
	}
	//Метод push: добавляет элемент в стек
	void push(int element) {
		//Проверяет полон ли стек
		if (isFull()) {
			cout << "Ошибка! Стек переполнен!" << endl; //Выводит ошибку в случае, если полон
			return;
		}
		top++;	//Увеличивает `top` на 1
		arr[top] = element;	//Добавляет элемент в стек
	}
	//Метод pop: удаляет элемент из стека
	int pop() {
		//Проверка пуст ли стек
		if (isEmpty()) {
			cout << "Ошибка! Стек пуст!" << endl;	//Выводит ошибку в случае, если пуст
			return -1;
		}
		int element = arr[top];	//Сохраняет значение элемента, находящегося на вершине стека
		top--;	//Уменьшает индекс верхнего элемента на 1
		return element;	//Возвращает значение элемента
	}
	//Метод peek: выводит элемент на вершине стека
	int peek() {
		//Проверка пуст ли стек
		if (isEmpty()) {
			cout << "Ошибка! Стек пуст!" << endl;	//Если пуст, выводит ошибку
			return -1;
		}
		return arr[top];	//Возвращает значение верхнего элемента
	}
	//Метод getSize: выводит кол-во элементов в стеке
	int getSize() const {
		return top + 1; //+1 тк индексация в массиве начинается с 0
	}
	//Метод clear: очишает стек
	void clear() {
		top = - 1;	//Устанавливает индекс первого элемента -1, то есть сделает его пустым
	}
	//метод printStack: выводит элементы стека 
	void printStack() {
		//Проверка пуст ли стек
		if (isEmpty()) {
			cout << "Ошибка! Стек пуст!" << endl;	//Если пуст, выводит ошибку
			return;
		}

		cout << "Наполнение стека: ";
		for (int i = top; i >= 0; i--) {	//Последний добавленный элемент(вершина) выводится первым, затем идут ранее добавленные
			cout << arr[i] << " ";	//Выводит элементы стека через пробел
		}
		cout << endl;
	}
};

int main() {
	Stack s(5); 
	//Создание стека :
	//- Создается объект `s` класса `Stack`.
	//- `Stack(5)`: Вызывается конструктор класса `Stack` с аргументом 5.
	//- Аргумент 5 указывает на то, что стек будет иметь вместимость 5 элементов (максимальное количество элементов, которое он может хранить).
	//- Внутри конструктора выделяется память под массив `arr` размером 5.
	//- `top` инициализируется значением -1 (стек пуст).

	//Добавляют элементы в стек
	s.push(10);
	s.push(20);
	s.push(30);
	s.push(40);
	s.push(50); //Вершина стека

	s.printStack();	//Выводит все элементы стека

	cout << "Верхний элемент: " << s.peek() << endl;
	cout << "Удаленный элемент: " << s.pop() << endl;

	cout << "Новый верхний элемент после удаления: " << s.peek() << endl;

	cout << "Размер стека: " << s.getSize() << endl;

	s.clear();	//Очишает стек

	cout << "Стек пуст: " << s.isEmpty() << endl;	

	s.printStack();	//Выдаст ошибку, тк стек пуст, чисто на проверку закинул функцию

	return 0;
}