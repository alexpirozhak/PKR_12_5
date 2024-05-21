#include <iostream>
#include <fstream>
#include "Stack.h"
using namespace std;

int main() {
    // Зчитуємо стек з файлу
    string filename = "numbers.txt";
    Stack originalStack = readStackFromFile(filename);

    // Виводимо вхідний стек
    cout << "Вхідний стек: ";
    originalStack.printStack();

    // Вводимо n та m
    int n, m;
    cout << "Введіть n: ";
    cin >> n;
    cout << "Введіть m: ";
    cin >> m;

    // Копіюємо n елементів у новий стек
    Stack newStack = copyNElements(originalStack, n);

    // Видаляємо m верхніх елементів з нового стеку
    removeMElements(newStack, m);

    // Виводимо результати
    cout << "Новий стек: ";
    newStack.printStack();

    return 0;
}
