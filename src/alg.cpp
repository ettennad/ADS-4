// Copyright 2021 NNTU-CS
int countPairs1(int *arr, int size, int targetSum) {
    int count = 0;
    for (int i = 0; i < size - 1; i++) {
        for (int j = i + 1; j < size; j++) {
            if (arr[i] + arr[j] == targetSum) {
                count++;
            }
        }
    }
    return count;
}

int countPairs2(int* arr, int len, int value) {
    int count = 0;
    int left = 0;
    int right = len - 1;
    
    while (left < right) {
        int sum = arr[left] + arr[right];
        if (sum == value) {
            count++;
            left++;
            right--;
        } else if (sum < value) {
            left++;
        } else {
            right--;
        }
    }
    
    return count;
}

int findMatches(int *arr, int start, int end, int target) {
    int firstOccurrence = -1;
    int left = start;
    int right = end;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] >= target) {
            if (arr[mid] == target) firstOccurrence = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    if (firstOccurrence == -1) return 0;
    int lastOccurrence = firstOccurrence;
    left = firstOccurrence;
    right = end;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] <= target) {
            if (arr[mid] == target) lastOccurrence = mid;
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return lastOccurrence - firstOccurrence + 1;
}

int countPairs3(int *arr, int size, int targetSum) {
    int pairCount = 0;
    for (int i = 0; i < size; i++) {
        int complement = targetSum - arr[i];
        if (complement < 0) continue;
        pairCount += findMatches(arr, i + 1, size - 1, complement);
    }
    return pairCount;
}
