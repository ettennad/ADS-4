// Copyright 2021 NNTU-CS
#include <algorithm>

int countPairs1(int* arr, int len, int value) {
    int count = 0;
    for (int i = 0; i < len; ++i) {
        if (i > 0 && arr[i] == arr[i-1]) continue;
        for (int j = i + 1; j < len; ++j) {
            if (j > i + 1 && arr[j] == arr[j-1]) continue;
            if (arr[i] + arr[j] == value) {
                ++count;
            }
        }
    }
    return count;
}

int countPairs2(int* arr, int len, int value) {
    int count = 0;
    int left = 0, right = len - 1;
    while (left < right) {
        int sum = arr[left] + arr[right];
        if (sum == value) {
            ++count;
            int last_left = arr[left];
            int last_right = arr[right];
            while (left < right && arr[left] == last_left) ++left;
            while (left < right && arr[right] == last_right) --right;
        } else if (sum < value) {
            ++left;
        } else {
            --right;
        }
    }
    return count;
}

int countPairs3(int* arr, int len, int value) {
    int count = 0;
    for (int i = 0; i < len; ++i) {
        if (i > 0 && arr[i] == arr[i-1]) continue;
        int target = value - arr[i];
        const int* pos = std::lower_bound(arr + i + 1, arr + len, target);
        if (pos != arr + len && *pos == target) {
            ++count;
        }
    }
    return count;
}
