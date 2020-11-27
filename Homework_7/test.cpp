//
// Created by 87569 on 2020/11/27.
//

#include "MyAlgorithm.h"

int a[500050];

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
    }
    printf("%d", getMinTickets(a, n));
    return 0;
}

