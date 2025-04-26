// Copyright 2021 NNTU-CS
// Copyright 2021 NNTU-CS
#include <algorithm>

int countPairs1(int* arr, int len, int value) {
    int count = 0;
    for (int i = 0; i < len; ++i) {
        for (int j = i + 1; j < len; ++j) {
            if (arr[i] + arr[j] == value) {
                ++count;
            }
        }
    }
    return count;
}

int countPairs2(int* arr, int len, int value) {
  int count = 0;
  int left = 0;
  int right = len - 1;

  while (left < right && arr[left] + arr[right] < value) {
    ++left;
  }
  while (left < right && arr[right] > value) {
    --right;
  }

  for (int i = left; i < right; ++i) {
    for (int j = i + 1; j <= right; ++j) {
      if (arr[i] + arr[j] == value) {
        ++count;
      }
    }
  }
  return count;
}

int countPairs3(int* arr, int len, int value) {
    int count = 0;
    for (int i = 0; i < len - 1; ++i) {
        int target = value - arr[i];
        const int* pos = std::lower_bound(arr + i + 1, arr + len, target);
        if (pos != arr + len && *pos == target) {
            ++count;
        }
    }
    return count;
}
