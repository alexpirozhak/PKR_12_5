#include "Stack.h"

Stack::~Stack() {
    while (top != nullptr) {
        Node *temp = top;
        top = top->next;
        delete temp;
    }
}

void Stack::push(int value) {
    Node *newNode = new Node(value);
    newNode->next = top;
    top = newNode;
}

void Stack::pop() {
    if (top != nullptr) {
        Node *temp = top;
        top = top->next;
        delete temp;
    }
}

int Stack::peek() {
    if (top != nullptr) {
        return top->data;
    }
    return -1; // Повертаємо -1, якщо стек порожній
}

bool Stack::isEmpty() {
    return top == nullptr;
}

void Stack::printStack() {
    cout << toString() << endl;
}

string Stack::toString() const {
    stringstream sout;

    Node *current = top;
    while (current != nullptr) {
        sout << current->data << " ";
        current = current->next;
    }

    return sout.str();
}

Stack readStackFromFile(const string &filename) {
    ifstream infile(filename);
    Stack s;

    if (infile.is_open()) {
        int number;
        while (infile >> number) {
            s.push(number);
        }
        infile.close();
    } else {
        cerr << "Не вдалося відкрити файл." << endl;
    }

    return s;
}

Stack copyNElements(Stack &original, int n) {
    Stack newStack;
    Stack tempStack;

    for (int i = 0; i < n && !original.isEmpty(); ++i) {
        tempStack.push(original.peek());
        original.pop();
    }

    while (!tempStack.isEmpty()) {
        int value = tempStack.peek();
        newStack.push(value);
        original.push(value);
        tempStack.pop();
    }

    return newStack;
}

void removeMElements(Stack &s, int m) {
    for (int i = 0; i < m && !s.isEmpty(); ++i) {
        s.pop();
    }
}
