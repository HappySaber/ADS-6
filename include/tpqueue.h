#pragma once
// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_
#include <string>

template <typename T, int size>
class TPQueue {
 private:
  T* arr;
  int first, last, count;
 public:
  TPQueue() : first(0), last(0), count(0) { arr =new T[size]; }
  bool isEmpty() const {
    return 0 == count;
  }
  bool isFull() const {
    return size == count;
  }
  const T& pop() {
    if (isEmpty()) {
      throw std::string("Empty!");
    } else {
      count--;
      return arr[first++ % size];
    }
  }
  void push(const T& value) {
    if (isFull()) {
      throw std::string("Full!");
    } else {
      int l = last;
      arr[last % size] = value;
      T temp = arr[l % size];
      while (arr[l % size].prior > arr[(l-1)%size].prior && l > first) {
        temp = arr[l % size];
        arr[l % size] = arr[(l - 1) % size];
        arr[(l - 1) % size] = temp;
        l--;
      }
      count++;
      last++;
    }
  }
};

struct SYM {
  char ch;
  int prior;
};

#endif  // INCLUDE_TPQUEUE_H_
