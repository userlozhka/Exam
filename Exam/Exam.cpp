#include <iostream>

// Function to find the index of the maximum element in the array
int findMaxIndex(const int arr[], int size) {
    int maxElement = arr[0];
    int maxIndex = 0;

    for (int i = 1; i < size; ++i) {
        if (arr[i] > maxElement) {
            maxElement = arr[i];
            maxIndex = i;
        }
    }

    return maxIndex;
}

// Function to find the product of elements between the first and second zero elements
int productBetweenZeros(const int arr[], int size) {
    int firstZeroIndex = -1;
    int secondZeroIndex = -1;
    int product = 1;

    for (int i = 0; i < size; ++i) {
        if (arr[i] == 0) {
            if (firstZeroIndex == -1)
                firstZeroIndex = i;
            else {
                secondZeroIndex = i;
                break;
            }
        }
    }

    if (firstZeroIndex != -1 && secondZeroIndex != -1) {
        for (int i = firstZeroIndex + 1; i < secondZeroIndex; ++i) {
            product *= arr[i];
        }
    }
    else {
        // If there are less than two zeros, return 0 or choose another default value
        return 0;
    }

    return product;
}

int main() {
    const int size = 10;
    int array[size] = { 3, 7, 2, 0, 4, 6, 0, 9, 5, 8 };

    int maxIndex = findMaxIndex(array, size);
    std::cout << "Index of maximum element: " << maxIndex << std::endl;

    int product = productBetweenZeros(array, size);
    std::cout << "Product of elements between the first and second zeros: " << product << std::endl;

    // Transforming the array
    int temp[size];
    int oddIndex = 0;
    int evenIndex = size / 2;

    for (int i = 0; i < size; ++i) {
        if (i % 2 == 0)
            temp[oddIndex++] = array[i];
        else
            temp[evenIndex++] = array[i];
    }

    // Copying back to the original array
    for (int i = 0; i < size; ++i) {
        array[i] = temp[i];
    }

    // Displaying the modified array
    std::cout << "Transformed array: ";
    for (int i = 0; i < size; ++i) {
        std::cout << array[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}
