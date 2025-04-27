// Copyright 2021 NNTU-CS
int countPairs1(int* arr, int len, int value) {
    int count = 0;
    for (int i = 0; i < len - 1; ++i) {
        if (i > 0 && arr[i] == arr[i - 1]) continue;
        for (int j = i + 1; j < len; ++j) {
            if (j > i + 1 && arr[j] == arr[j - 1]) continue;
            if (arr[i] + arr[j] == value) {
                ++count;
            } else if (arr[i] + arr[j] > value) {
                break;
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
            int leftValue = arr[left], rightValue = arr[right];
            while (left < right && arr[left] == leftValue) ++left;
            while (left < right && arr[right] == rightValue) --right;
        } else if (sum < value) {
            ++left;
        } else {
            --right;
        }
    }
    return count;
}

#include <algorithm>
int countPairs3(int* arr, int len, int value) {
    int count = 0;
    for (int i = 0; i < len - 1; ++i) {
        if (i > 0 && arr[i] == arr[i - 1]) continue;
        int target = value - arr[i];
        auto pos = std::lower_bound(arr + i + 1, arr + len, target);
        if (pos != arr + len && *pos == target) {
            if (pos == arr + i + 1 || *(pos - 1) != target) {
                ++count;
            }
        }
    }
    return count;
}
