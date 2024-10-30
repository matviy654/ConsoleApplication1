#include <iostream>
#include <algorithm>
#include <vector>

template <typename T>
T findMax(const std::vector<T>& arr) {
    T maxVal = arr[0];
    for (const auto& elem : arr) {
        if (elem > maxVal) {
            maxVal = elem;
        }
    }
    return maxVal;
}

template <typename T>
T findMin(const std::vector<T>& arr) {
    T minVal = arr[0];
    for (const auto& elem : arr) {
        if (elem < minVal) {
            minVal = elem;
        }
    }
    return minVal;
}

template <typename T>
void sortArray(std::vector<T>& arr) {
    std::sort(arr.begin(), arr.end());
}

template <typename T>
int binarySearch(const std::vector<T>& arr, T target) {
    int left = 0;
    int right = arr.size() - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == target) {
            return mid; 
        }
        else if (arr[mid] < target) {
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }
    return -1;
}

template <typename T>
void replaceElement(std::vector<T>& arr, int index, T value) {
    if (index >= 0 && index < arr.size()) {
        arr[index] = value;
    }
    else {
        std::cerr << "Index out of bounds\n";
    }
}

int main() {
    std::vector<int> arr = { 5, 2, 9, 1, 5, 6 };

    std::cout << "Max: " << findMax(arr) << "\n";

    std::cout << "Min: " << findMin(arr) << "\n";

    sortArray(arr);
    std::cout << "Sorted array: ";
    for (const auto& elem : arr) {
        std::cout << elem << " ";
    }
    std::cout << "\n";

    int target = 5;
    int index = binarySearch(arr, target);
    if (index != -1) {
        std::cout << "Element " << target << " found at index: " << index << "\n";
    }
    else {
        std::cout << "Element " << target << " not found\n";
    }

    replaceElement(arr, 2, 10);
    std::cout << "Array after replacement: ";
    for (const auto& elem : arr) {
        std::cout << elem << " ";
    }
    std::cout << "\n";

    return 0;
}
