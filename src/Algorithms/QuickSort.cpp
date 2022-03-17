#include "../../include/Algorithms/QuickSort.hpp"

namespace Sorting {
    /**
     * @brief Resets values back to default
     * 
     */
    void QuickSort::set_default() {
        sorted = false;
        process = process2 = innerProcess = currentIndex = 0;

        low = 0;
        high = length - 1;
        delete[] stack;
    }

    /**
     * @brief Runs an iteration (step) in the algorithm
     * 
     */
    void QuickSort::sort() {
        quicksort();
        sf::sleep(sf::milliseconds(5));
    }

    /**
     * @brief 
     * 
     */
    void QuickSort::quicksort() {
        if (process == 0) {
            stack = new int[high - low + 1];
            top = -1;
            stack[++top] = low;
            stack[++top] = high;
            
            process++;
        }
        if (process == 1) {
            if (process2 == 0) {
                high = stack[top--];
                low = stack[top--];

                process2++;
            }
            if (process2 == 1) {
                if (innerProcess != 3)
                    partition();
                else {
                    innerProcess = 0;
                    process2++;
                }
            }
            else if (process2 == 2) {
                if (pi - 1 > low) {
                    stack[++top] = low;
                    stack[++top] = pi - 1;
                }

                if (pi + 1 < high) {
                    stack[++top] = pi + 1;
                    stack[++top] = high;
                }

                if (top < 0) {
                    sorted = true;
                    currentIndex = length;
                }
                else
                    process2 = 0;
            }
        }
    }

    /**
     * @brief 
     * 
     */
    void QuickSort::partition() {
        if (innerProcess == 0) {
            pivot = data[high].getSize().y;
            i = (low - 1);
            currentIndex = low;

            innerProcess++;
        }
        if (innerProcess == 1) {
            if (currentIndex <= high - 1) {
                int current = data[currentIndex].getSize().y;
                if (current <= pivot) {
                    i++;
                    swap(data[i], data[currentIndex]);
                }
                currentIndex++;
            }
            else
                innerProcess++;
        }
        if (innerProcess == 2) {
            swap(data[i + 1], data[high]);
            pi = (i+1);

            innerProcess++;
        }
    }
}