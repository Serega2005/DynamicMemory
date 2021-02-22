#pragma once
#include<iostream>
using std::cin;
using std::cout;
using std::endl;


template<typename T>T** Allocate(const int m, const int n);
template<typename T>void Clear(T** arr, const int m);

template<typename T>void Random(T& variable);

void FillRand(int arr[], const int n, int minRand = 0, int maxRand = 100);
void FillRand(float arr[], const int n, int minRand = 0, int maxRand = 100);
void FillRand(double arr[], const int n, int minRand = 0, int maxRand = 100);
void FillRand(char arr[], const int n, int minRand = 0, int maxRand = 100);
void FillRand(int** arr, const int m, const int n);
void FillRand(double** arr, const int m, const int n);
void FillRand(float** arr, const int m, const int n);
void FillRand(char** arr, const int m, const int n);

template<typename T>void Print(T arr[], const int n);
template<typename T>void Print(T** arr, const int m, const int n);

template<typename T>void push_back_mutable(T*& arr, int& n, T value);
template<typename T>void push_front_mutable(T*& arr, int& n, T value);

template<typename T>void insert(T*& arr, int& n, T value, int index);
template<typename T>void insert_row(T**& arr, int& m, const int n, int index);
template<typename T>void insert_col(T** arr, const int m, int& n, int index);

template<typename T>void pop_row_back(T**& arr, int& m, const int n);
template<typename T>void pop_row_front(T**& arr, int& m, const int n);
template<typename T>void pop_col_back(T**& arr, const int m, int& n);
template<typename T>void pop_col_front(T**& arr, const int m, int& n);
template<typename T>void pop_back(T*& arr, int& n);
template<typename T>void pop_front(T*& arr, int& n);

template<typename T>void erase(T*& arr, int& n, int index, T value);
template<typename T>void erase_row(T** arr, int& m, const int n, int index);

template<typename T>void push_row_back(T**& arr, int& m, const int n);
template<typename T>void push_row_front(T**& arr, int& m, const int n);

template<typename T>void push_col_back(T** arr, const int m, int& n);
template<typename T>void push_col_front(T** arr, const int m, int& n);