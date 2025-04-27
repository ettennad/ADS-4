// Copyright 2021 NNTU-CS
#include <algorithm>

int countPairs1(int* arr, int len, int value) {
        int pairCount = 0;
    int left = 0;
    int right = len - 1;
    while (left < right) {
        int sum = arr[left] + arr[right];
        if (sum == value) {
            int l_val = arr[left];
            int r_val = arr[right];
            if (l_val == r_val) {
                int count = right - left + 1;
                pairCount += (count * (count - 1)) / 2;
                break;
            } else {
                int countLeft = 1;
                int countRight = 1;
                while (left + 1 < right && arr[left + 1] == l_val) {
                    countLeft++;
                    left++;
                }
                while (right - 1 > left && arr[right - 1] == r_val) {
                    countRight++;
                    right--;
                }
                pairCount += countLeft * countRight;
                left++;
                right--;
            }
        } else if (sum < value) {
            left++;
        } else {
            right--;
        }
    }
    return pairCount;
}

int countPairs2(int* arr, int len, int value) {
        int pairCount = 0;
    for (int i = 0; i < len - 1; i++) {
        for (int j = i + 1; j < len; j++) {
            if (arr[i] + arr[j] == value) {
                pairCount++;
            }
        }
    }
    return pairCount;
}

int findMatches(int* arr, int start, int end, int target) {
    int first = -1, last = -1;
    int left = start, right = end;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] >= target) {
            if (arr[mid] == target) first = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    if (first == -1) return 0;
    left = first;
    right = end;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] <= target) {
            if (arr[mid] == target) last = mid;
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return last - first + 1;
}

int countPairs3(int* arr, int len, int value) {
    int pairCount = 0;
    for (int i = 0; i < len - 1; ++i) {
        int complement = value - arr[i];
        if (complement < 0) continue;
        pairCount += findMatches(arr, i + 1, len - 1, complement);
    }
    return pairCount;
}
