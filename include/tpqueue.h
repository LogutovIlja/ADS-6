// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_

template<typename T, int size>
class TPQueue {
private:
    T a[100];
    int begin;
    int end;

public:
    TPQueue() : begin(0), end(0) { }
    void push(T x) {
        int cif = end++;
        for (cif; (x.prior > a[cif % size].prior) && (begin <= --cif);) {
            a[(cif + 1) % size] = a[cif % size];
        }
        a[(cif + 1) % size] = x;
    }
    T pop() {
        return a[(begin++) % size];
    }
};

struct SYM {
  char ch;
  int prior;
};

#endif  // INCLUDE_TPQUEUE_H_
