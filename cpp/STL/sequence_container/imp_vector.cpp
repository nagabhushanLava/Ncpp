#include<iostream>
#include<bits/stdc++.h>
using namespace std; 

template <class T>
class vecdata{
    public : T v[];
    int size;
     int capacity ;
     void push_back_();
     void pop_back_();
     void insert_(int index, T value);          
        void erase_(int index);
        void resize_(int new_size); 
        void clear_();
        void print_();

};

template <class T>
void vecdata<T>::push_back_() {
    if (size == capacity) {
        capacity *= 2;
        T* new_v = new T[capacity];
        for (int i = 0; i < size; i++) {
            new_v[i] = v[i];
        }
        delete[] v;
        v = new_v;
    }
    v[size++] = T();
}       

