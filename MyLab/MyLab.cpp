//
// Created by 87569 on 2020/12/11.
//

#include "cmath"
#include "cstdio"
#include "vector"

using namespace std;

#include "sys/time.h"

const float precision = 1e-11;

const int array_len = 50;

double newTonRoot(double);

void shuffle(int *shuffle, int len);

/* 小顶堆求最大的N个数 */
class min_heap {
private:
    int *heap{};
    int heap_len{};
    int index{};

    void heap_up();

    void heap_down();

    int remove_top();

public:
    explicit min_heap(int len);

    void insert(int n);

    vector<int> sort_v();

    int *sort_i();

    ~min_heap() {
        delete heap;
    }
};

void min_heap::heap_up() {
    int child = index;
    int parent = (child - 1) / 2;
    int tmp;
    while (child > 0) {
        if (heap[parent] > heap[child]) {
            tmp = heap[child];
            heap[child] = heap[parent];
            heap[parent] = tmp;

            child = parent;
            parent = (parent - 1) / 2;
        } else break;
    }
}

void min_heap::heap_down() {
    int parent = 0;
    int child = 2 * parent + 1;
    int tmp;
    while (child <= index) {
        if (child < index && heap[child + 1] < heap[child]) {
            child++;
        }
        if (heap[parent] > heap[child]) {
            tmp = heap[child];
            heap[child] = heap[parent];
            heap[parent] = tmp;

            parent = child;
            child = 2 * child + 1;
        } else break;
    }
}

int min_heap::remove_top() {
    if (index <= 0)
        return -1;
    int r_node = heap[0];
    index--;
    heap[0] = heap[index];
    heap_down();
    return r_node;
}

min_heap::min_heap(int len) : heap_len(len) {
    this->heap = new int[len];
    this->index = 0;
}

void min_heap::insert(int n) {
    if (index == heap_len) {
        if (n <= heap[0])
            return;
        remove_top();
    }
    heap[index] = n;
    heap_up();
    index++;
}

vector<int> min_heap::sort_v() {
    vector<int> res;
    res.reserve(heap_len);
    for (int i = 0; i < heap_len; i++) {
        res.push_back(remove_top());
    }
    return res;
}

int *min_heap::sort_i() {
    int *res = new int[heap_len];
    for (int i = 0; i < heap_len; i++) {
        res[i] = remove_top();
    }
    return res;
}

/* 大顶堆求最小的N个数 */
class max_heap {
private:
    int *heap{};

    /* 指示当前heap待插入节点的下标
     * 最大值为 heap_len-1 */
    int index{};

    int heap_len{};

    /* 上浮 */
    void heap_up();

    /* 下沉 */
    void heap_down();

    /* 删除堆顶元素 */
    int remove_top();

public:
    explicit max_heap(int len);

    ~max_heap() {
        delete heap;
    }

    void insert(int n);

    void heap_print() const;

    vector<int> sort_v();

    int *sort_i();
};

max_heap::max_heap(int len) : heap_len(len) {
    this->index = 0;
    this->heap = new int[len];
}

void max_heap::heap_up() {
    /* 注意下标越界问题 */
    int child = index;
    /* 父节点 */
    int parent = (child - 1) / 2;
    int tmp;
    while (child > 0) {
        /* 如果父节点比子节点小 */
        if (heap[parent] < heap[child]) {
            /* 交换值 */
            tmp = heap[child];
            heap[child] = heap[parent];
            heap[parent] = tmp;

            /* 向上取下标 */
            child = parent;
            parent = (parent - 1) / 2;

        } else break;
    }
}

void max_heap::heap_down() {
    int parent = 0;
    int child = 2 * parent + 1;
    int tmp;
    /* 注意减1 */
    while (child <= index) {
        /* 如果左右子树同时存在查找最大值 */
        if (child < index && heap[child] < heap[child + 1]) {
            child++;
        }
        /* 如果子节点比父节点大 */
        if (heap[child] > heap[parent]) {
            /* 交换值 */
            tmp = heap[child];
            heap[child] = heap[parent];
            heap[parent] = tmp;

            parent = child;
            child = 2 * child + 1;
        } else break;       // 尼玛你是傻逼吗，这个都会忘
    }
}

/* 返回堆顶元素 */
int max_heap::remove_top() {
    /* 如果堆为空 */
    if (index <= 0)
        return -1;
    int r_node = heap[0];
    index--;
    heap[0] = heap[index];
    /* 下沉 */
    heap_down();
    return r_node;
}

/* 插入节点 */
void max_heap::insert(int n) {
    /* 先考虑堆是否已满 */
    if (index == heap_len) {
        /* 如果比堆顶的最大值还大
         * 插入后一定不会满足最小的N个数 */
        if (n >= heap[0])
            return;
        /* 如果堆已满，删除 */
        remove_top();
    }
    /* 插入 */
    heap[index] = n;
    /* 上浮 */
    heap_up();
    index++;
}


vector<int> max_heap::sort_v() {
    vector<int> res;
    for (int i = heap_len - 1; i >= 0; i--) {
        res.push_back(remove_top());
    }
    return res;
}

int *max_heap::sort_i() {
    int *res = new int[heap_len];
    for (int i = heap_len - 1; i >= 0; i--) {
        res[i] = remove_top();
    }
    return res;
}

void max_heap::heap_print() const {
    for (int i = 0; i < this->heap_len; ++i) {
        printf("%d-", heap[i]);
    }
}

void quickSort(int *array, int lo, int hi);

int partition(int *array, int lo, int hi);

void swap(int *array, int lo, int hi);

int main() {
    srand(time(nullptr));

    int n;
    scanf("%d", &n);
    printf("%.20f", newTonRoot(n));

    return 0;
}

/* x * x - num = 0 */
double newTonRoot(double num) {
    if (num <= 0 || num == 1)
        return num;
    /* 计算x0 */
    /* 取x0 = num / 3 */
    double x0 = num / 3;
    double x1 = x0 - ((x0 * x0 - num) / (2 * x0));
    while (std::abs(x0 - x1) > precision) {
        x0 = x1;
        x1 = x0 - ((x0 * x0 - num) / (2 * x0));
    }
    return x1;
}

void shuffle(int *shuffle, int len) {
    int tail = len - 1;
    int random;
    int tmp;
    /* 注意大于等于0 */
    while (tail > 0) {
        /* 生成随机下标 */
        /* 如果等于0进入循环会除零异常 */
        random = rand() % tail;
        /* 交换下标的牌和数组末尾元素 */
        tmp = shuffle[tail];
        shuffle[tail] = shuffle[random];
        shuffle[random] = tmp;
        /* 次数减少1 */
        tail--;
    }
}

void quickSort(int *array, int lo, int hi) {
    if (hi <= lo)
        return;
    int j = partition(array, lo, hi);
    quickSort(array, lo, j - 1);
    quickSort(array, j + 1, hi);
}

int partition(int *array, int lo, int hi) {
    int i = lo, j = hi + 1;
    int v = array[lo];
    while (true) {
        while (array[++i] < v) if (i == hi) break;
        while (array[--j] > v) if (j == lo) break;
        if (i >= j) break;
        swap(array, i, j);
    }
    swap(array, lo, j);
    return j;
}

inline void swap(int *array, int lo, int hi) {
    int tmp = array[hi];
    array[hi] = array[lo];
    array[lo] = tmp;
}
