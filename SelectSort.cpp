#include <iostream>
using namespace std;

// http://www.codeceo.com/article/3-sort-quick-sort-improve.html
// random select pivot
int randomSelcet(int * num, int l, int r) {
    int len = r - l + 1;
    return l = rand() % len;
}

// median of three
void medianOfThree(int * num, int l, int r) {
    int mid = l + (r - l) / 2;
    if (num[mid] > num[r]) swap(num[mid], num[r]);
    if (num[l] > num[r]) swap(num[l], num[r]);
    if (num[l] < num[mid]) swap(num[l], num[mid]);
}

// scan from left to right
// use the last num as pivot
int partrition(int * num, int l, int r) {
    int pivot = num[r];
    // i point to the first num that bigger than pivot
    // j point to the current num
    int i = l, j = l;
    while (j < r) {
        if (num[j] <= pivot) {
            swap(num[i], num[j]);
            ++i;
        }
        ++j;
    }
    // swap the pivot to the right place
    swap(num[i], num[r]);
    return i;
}

// scan from two directions
// pit fill method
int partritionII(int * num, int l, int r) {
    int i = l, j = r;
    int pivot = num[l];
    for ( ; i < j; ) {
        // i is the pit ,find the num less than pivot to fill the pit(i)
        while (i < j && num[j] > pivot) {
            --j;
        }
        if (i < j) {
            num[i++] = num[j];
        }
        // then j becomes the new pit, from i to find the num larger than pivot
        while (i < j && num[i] <= pivot) {
            ++i;
        }
        if (i < j) {
           num[j--] = num[i];
        }
    }
    num[i] = pivot;
    return i;
}

void select_sort(int * num, int l, int r) {
    if (l < r) {
        int p = partritionII(num, l, r);
        select_sort(num, l, p-1);
        select_sort(num, p+1, r);
    }
}

void print(int * a, int n) {
    for (int i = 0; i < n; ++i) {
        cout << a[i] << " ";
    }
    cout << endl;
}

int main() {
    int a[9] = {5,4,6,3,2,7,8,10,3};
    print(a, 9);
    select_sort(a, 0, 8);
    print(a, 9);
    return 0;
}

