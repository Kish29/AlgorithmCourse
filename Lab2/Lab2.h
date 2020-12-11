//
// Created by 87569 on 2020/12/11.
//

#ifndef ALGORITHMCOURSE_LAB2_H
#define ALGORITHMCOURSE_LAB2_H

const int max_n = 1e5 + 5;

#include "cstdio"

void getMaxCash();

int max(int lo, int hi);

int doSearch(const int *a, int lo, int hi);

int getMinCompressSong();

void quickSort(int *array, int lo, int hi);

int partition(int *array, int lo, int hi);

void swap(int *array, int lo, int hi);

#endif //ALGORITHMCOURSE_LAB2_H
