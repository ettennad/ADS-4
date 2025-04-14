// Copyright 2021 NNTU-CS
int countPairs1(int *arr, int len, int value) {
  int count = 0;
  for (int = 0; i < len; ++i) {
    for (int j = i + 1; j < len; ++j) {
    if (arr[i] + arr[j] == value) {
      count++;
      while (j + 1 < len && arr[j] == arr[j + 1]) {
        j++;
      }
    }
    }
  }
return count;
}

int countPairs2(int *arr, int len, int value) {
  int count = 0;
  bool foundPairs[len]  = {false};
  for (int i = 0; i < len; ++i) {
    for (int j = i + 1; j < len; ++j) {
      if (arr[i] + arr[j] == value && !foundPairs[i] && !foundPairs[j]) {
        count++;
        foundPairs[i] == true;
        foundPairs[j] == true;
      }
    }
  }
  return count;
}

int countpairs3(int *arr, int len, int value) {
  int count = 0;
  for (int = 0; i < len; ++i) {
    for (int j = i + 1; j < len; ++j) {
    if (arr[i] + arr[j] == value) {
      count++;
      while (j + 1 < len && arr[j] == arr[j + 1]) {
        j++;
      }
    }
    }
  }
  return count;
}
