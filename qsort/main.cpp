//
//  main.cpp
//  qsort
//
//  Created by Yabing Liu on 13-11-24.
//  Copyright (c) 2013年 Yabing Liu. All rights reserved.
//

#include <iostream>

template <typename T>
void swap(T &left, T &right)
{
    T mid = left;
    left = right;
    right = mid;
}

template <typename T>
void qsort (T in[], size_t size)
{
    // input check
    if ( NULL == in || size <= 0) {
        return;
    }
    size_t magicPos = 0;
    size_t head = 0;
    size_t tail = size - 1;
    
    T magic = in[magicPos];
    // put bigger one to right side
    for (; head < tail; head++) {
        if (in[head] > magic) {
            while (in[tail] > magic && tail > head) {
                tail--;
            }
            if (tail > head) {
                swap(in[head], in[tail]);
            }
        }
    }
    // sort left sub
    qsort(in, head+1);
    // sort right sub
    qsort(in + head, size - head - 1);
    
}


int main(int argc, const char * argv[])
{

    const size_t testSize = 10;
    int test[testSize];
    
    for (size_t i = 0; i < testSize && std::cin >> test[i]; i++) {
        
    }
    qsort<int>(test, testSize);
    std::cout << test << "\n";
    return 0;
}

