#include <iostream>
#include <vector>

// Функція для знаходження номеру максимального елемента масиву
int findMaxIndex(const std::vector<int>& arr) {
    int maxIndex = 0;
    for (int i = 1; i < arr.size(); ++i) {
        if (arr[i] > arr[maxIndex]) {
            maxIndex = i;
        }
    }
    return maxIndex;
}

// Функція для обчислення добутку елементів масиву між першим і другим нульовими елементами
int productBetweenZeros(const std::vector<int>& arr) {
    int firstZeroIndex = -1, secondZeroIndex = -1;
    for (int i = 0; i < arr.size(); ++i) {
        if (arr[i] == 0) {
            if (firstZeroIndex == -1) {
                firstZeroIndex = i;
            }
            else {
                secondZeroIndex = i;
                break;
            }
        }
    }

    if (firstZeroIndex == -1 || secondZeroIndex == -1) {
        std::cout << "Немає двох нульових елементів у масиві.\n";
        return 0;
    }

    int product = 1;
    for (int i = firstZeroIndex + 1; i < secondZeroIndex; ++i) {
        product *= arr[i];
    }
    return product;
}

int main() {
    std::vector<int> array = { 1, 3, 0, 5, 7, 2, 4, 0, 6, 8 };

    // Знаходження номеру максимального елемента
    int maxIndex = findMaxIndex(array);
    std::cout << "Номер максимального елемента: " << maxIndex << std::endl;

    // Обчислення добутку елементів між першим і другим нульовими елементами
    int product = productBetweenZeros(array);
    std::cout << "Добуток елементів між нулями: " << product << std::endl;

    // Перетворення масиву
    std::vector<int> transformedArray(array.size());
    int oddIndex = 0, evenIndex = array.size() / 2;
    for (int i = 0; i < array.size(); ++i) {
        if (i % 2 == 0) {
            transformedArray[evenIndex] = array[i];
            evenIndex++;
        }
        else {
            transformedArray[oddIndex] = array[i];
            oddIndex++;
        }
    }

    // Виведення перетвореного масиву
    std::cout << "Перетворений масив: ";
    for (const auto& elem : transformedArray) {
        std::cout << elem << " ";
    }
    std::cout << std::endl;

    return 0;
}