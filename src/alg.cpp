// Copyright 2021 NNTU-CS
#include <iostream>

int countPairs1(int *arr, int len, int value) {
    int count = 0;
    for (int i = 0; i < len; ++i) {
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

int countPairs2(int *arr, int len, int value) {
    int count = 0;
    int left = 0;
    int right = len - 1;

    while (left < right) {
        int sum = arr[left] + arr[right];
        if (sum == value) {
            if (arr[left] == arr[right]) {
                int n = right - left + 1;
                count += n * (n - 1) / 2;
                break;
            } else {
                int left_val = arr[left];
                int right_val = arr[right];
                int cnt_left = 0, cnt_right = 0;

                while (left <= right && arr[left] == left_val) {
                    cnt_left++;
                    left++;
                }
                while (right >= left && arr[right] == right_val) {
                    cnt_right++;
                    right--;
                }
                count += cnt_left * cnt_right;
            }
        } else if (sum < value) {
            left++;
        } else {
            right--;
        }
    }

    return count;
}

int countOccurrences(int *arr, int left, int right, int target) {
    int first = -1, last = -1;

    int l = left, r = right;
    while (l <= r) {
        int m = l + (r - l) / 2;
        if (arr[m] == target) {
            first = m;
            r = m - 1;
        } else if (arr[m] < target) {
            l = m + 1;
        } else {
            r = m - 1;
        }
    }
    if (first == -1) return 0;

    l = first, r = right;
    while (l <= r) {
        int m = l + (r - l) / 2;
        if (arr[m] == target) {
            last = m;
            l = m + 1;
        } else if (arr[m] < target) {
            l = m + 1;
        } else {
            r = m - 1;
        }
    }

    return last - first + 1;
}

int countPairs3(int *arr, int len, int value) {
    int count = 0;
    for (int i = 0; i < len; ++i) {
        int complement = value - arr[i];
        if (complement < arr[i]) {
            continue;
        }
        count += countOccurrences(arr, i + 1, len - 1, complement);
    }
    return count;
}
