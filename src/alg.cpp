// Copyright 2021 NNTU-CS
#include <iostream>

int countPairs1(int *arr, int len, int value) {
    int count = 0;
    for (int i = 0; i < len; ++i) {
        for (int j = i + 1; j < len; ++j) {
            if (arr[i] + arr[j] == value) {
                count++;
            } else if (arr[i] + arr[j] > value) {
                break;
            }
        }
    }
    return count;
}

int countPairs2(int *arr, int len, int value) {
    int count = 0;
    int left = 0, right = len - 1;
    while (left < right) {
        int sum = arr[left] + arr[right];
        if (sum == value) {
            int left_val = arr[left];
            int right_val = arr[right];
            int left_count = 1;
            int right_count = 1;
            left++;
            right--;
            while (left <= right && arr[left] == left_val) {
                left_count++;
                left++;
            }
            while (right >= left && arr[right] == right_val) {
                right_count++;
                right--;
            }

            count += left_count * right_count;
        } else if (sum < value) {
            left++;
        } else {
            right--;
        }
    }
    return count;
}

int binarySearchFirst(int *arr, int left, int right, int target) {
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == target) {
            while (mid > left && arr[mid - 1] == target) {
                mid--;
            }
            return mid;
        } else if (arr[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return -1;
}

int countPairs3(int *arr, int len, int value) {
    int count = 0;
    for (int i = 0; i < len; ++i) {
        int complement = value - arr[i];
        int idx = binarySearchFirst(arr, i + 1, len - 1, complement);
        if (idx != -1) {
            int j = idx;
            while (j < len && arr[j] == complement) {
                count++;
                j++;
            }
        }
    }
    return count;
}
