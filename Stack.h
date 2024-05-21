#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int value) : data(value), next(nullptr) {}
};

class Stack {
private:
    Node* top;

public:
    Stack() : top(nullptr) {}

    ~Stack();

    void push(int value);

    void pop();

    int peek();

    bool isEmpty();

    void printStack();

    string toString() const;
};

Stack readStackFromFile(const string &filename);

Stack copyNElements(Stack &original, int n);

// Функція для видалення m верхніх елементів зі стеку
void removeMElements(Stack &s, int m);
