//
// Created by Tran Giang on 2/3/23.
//

#ifndef ALGORITHMS_HEAP_H
#define ALGORITHMS_HEAP_H
#include <vector>

template<typename T>
class Heap {
public:
    Heap(){}
    void from_arr(T *arr){}
    void insert(T elem){}
    void remove(T elem){}
    void pop(){}
    void empty(){}
    int size(){}
    void print(){}
private:
    std::vector<T> elems;
    void swap(T *x, T *y){}
    void heapify_up(){}
    void heapify_down(){}
};


#endif //ALGORITHMS_HEAP_H
