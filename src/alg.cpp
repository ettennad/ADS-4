// Copyright 2021 NNTU-CS
#include <algorithm>

int countPairs1(int* arr, int len, int value) {
    int count = 0;
    for (int i = 0; i < len - 1; ++i) {
        for (int j = i + 1; j < len; ++j) {
            int sum = arr[i] + arr[j];
            if (sum == value) {
                count++;
            } else if (sum > value) {
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
            if (arr[left] == arr[right]) {
                int n = right - left + 1;
                count += n * (n - 1) / 2;
                break;
            } else {
                int l = 1, r = 1;
                while (left + l < right && arr[left + l] == arr[left]) ++l;
                while (right - r > left && arr[right - r] == arr[right]) ++r;
                count += l * r;
                left += l;
                right -= r;
            }
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
    for (int i = 0; i < len - 1; ++i) {
        int complement = value - arr[i];
        if (complement < arr[i]) continue;
        auto range = std::equal_range(arr + i + 1, arr + len, complement);
        count += range.second - range.first;
    }
    return count;
}
