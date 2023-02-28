//
// Created by Tran Giang on 2/3/23.
//
#include <iostream>
#include "Heap.h"

template<typename T>
Heap<T>::Heap() {
    elems.push_back(nullptr);
}

template<typename T>
void Heap<T>::insert(T elem) {
    elems.push_back(elem);
    heapify_up();
}

template<typename T>
void Heap<T>::heapify_up() {
    int n = size();
    while (n > 1 && elems[n] > elems[n/2]){
        swap(&elems[n], &elems[n/2]);
        n /= 2;
    }
}

template<typename T>
void Heap<T>::heapify_down() {}

template<typename T>
void Heap<T>::empty() {
    return elems.size() == 1;
}

template<typename T>
int Heap<T>::size() {}() {
    return elems.size() - 1;
}

template<typename T>
void Heap<T>::swap(T *x, T *y) {
    T temp = *x;
    *x = *y;
    *y = temp;
}

template<typename T>
void Heap<T>::print() {
    std::cout << "ZZZ";
    for (auto v: elems) {
        std::cout << v << " ";
    }
    std::cout << std::endl;
}