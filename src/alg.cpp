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
            if (arr[left] == arr[right]) {
                int n = right - left + 1;
                count += n * (n - 1) / 2;
                break;
            } else {
                int left_val = arr[left];
                int right_val = arr[right];
                int left_count = 0, right_count = 0;
                while (left <= right && arr[left] == left_val) {
                    left_count++;
                    left++;
                }
                while (right >= left && arr[right] == right_val) {
                    right_count++;
                    right--;
                }
                count += left_count * right_count;
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
    int count = 0;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == target) {
            count = 1;
            int i = mid + 1;
            while (i <= right && arr[i] == target) {
                count++;
                i++;
            }
            i = mid - 1;
            while (i >= left && arr[i] == target) {
                count++;
                i--;
            }
            break;
        } else if (arr[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return count;
}

int countPairs3(int *arr, int len, int value) {
    int count = 0;
    for (int i = 0; i < len; ++i) {
        int complement = value - arr[i];
        int occur = countOccurrences(arr, i + 1, len - 1, complement);
        count += occur;
    }
    return count;
}
