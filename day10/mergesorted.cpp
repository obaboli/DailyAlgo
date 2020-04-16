#include <algorithm> // std::sort
#include <array>
#include <cstring>
#include <iostream>

void mergeSortedArray(int* mergedArr, int* arr, size_t arrSize, int* arr2, size_t arr2Size)
{

    if (mergedArr == nullptr || arr == nullptr || arr2 == nullptr) {
        return;
    }

    size_t arrIndex = 0;
    size_t arr2Index = 0;
    size_t mergeIndex = 0;

    while (arrIndex < arrSize || arr2Index < arr2Size) {

        if (arrIndex >= arrSize) {
            mergedArr[mergeIndex++] = arr2[arr2Index++];
        } else if (arr2Index >= arr2Size) {
            mergedArr[mergeIndex++] = arr[arrIndex++];
        } else {
            if (arr[arrIndex] < arr2[arr2Index]) {
                mergedArr[mergeIndex++] = arr[arrIndex++];
            } else {
                mergedArr[mergeIndex++] = arr2[arr2Index++];
            }
        }
    }
}

template <typename T, size_t mergeSize, size_t arrSize, size_t arr2Size>
void mergeSortedArrayT(T (&mergedArr)[mergeSize], T (&arr)[arrSize], T (&arr2)[arr2Size])
{

    size_t arrIndex = 0;
    size_t arr2Index = 0;
    size_t mergeIndex = 0;

    while (arrIndex < arrSize || arr2Index < arr2Size) {

        if (arrIndex >= arrSize) {
            mergedArr[mergeIndex++] = arr2[arr2Index++];
        } else if (arr2Index >= arr2Size) {
            mergedArr[mergeIndex++] = arr[arrIndex++];
        } else {
            if (arr[arrIndex] < arr2[arr2Index]) {
                mergedArr[mergeIndex++] = arr[arrIndex++];
            } else {
                mergedArr[mergeIndex++] = arr2[arr2Index++];
            }
        }
    }
}

int main()
{
    int arr[] = { 1, 10, 3, 8, 6, 7, 24 };
    int arr2[] = { 2, 5, 9, 1, 30 };

    const size_t arrSize = sizeof(arr) / sizeof(*arr);
    const size_t arr2Size = sizeof(arr2) / sizeof(*arr2);

    std::sort(arr, arr + arrSize);
    std::sort(arr2, arr2 + arr2Size);

    std::cout << "Two sorted arrays \n";

    for (size_t i = 0; i < arrSize; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << "\n";

    for (size_t i = 0; i < arr2Size; i++) {
        std::cout << arr2[i] << " ";
    }
    std::cout << "\n";

    std::cout << "Merged arrays \n";

    int arrMerged[arrSize + arr2Size] = {};

    mergeSortedArray(arrMerged, arr, arrSize, arr2, arr2Size);

    size_t mergedSize = sizeof(arrMerged) / sizeof(*arrMerged);

    for (size_t i = 0; i < mergedSize; i++) {
        std::cout << arrMerged[i] << " ";
    }
    std::cout << "\n";

    std::memset(&arrMerged, 0, sizeof(arrMerged));
    mergeSortedArrayT(arrMerged, arr, arr2);

    for (size_t i = 0; i < mergedSize; i++) {
        std::cout << arrMerged[i] << " ";
    }
    std::cout << "\n\n";

    //Doing the same task as above but with std::array

    std::array<int, 7> arrS1{ 1, 10, 3, 8, 6, 7, 24 };
    std::array<int, 5> arrS2{ 2, 5, 9, 1, 30 };

    std::sort(arrS1.begin(), arrS1.end());
    std::sort(arrS2.begin(), arrS2.end());

    std::array<int, (arrS1.size() + arrS2.size())> arrSM{};
    std::merge(arrS1.begin(), arrS1.end(), arrS2.begin(), arrS2.end(), arrSM.begin());

    for (const auto i : arrSM)
        std::cout << i << ' ';
    std::cout << "\n";

    arrSM.fill(0);

    return 0;
}
