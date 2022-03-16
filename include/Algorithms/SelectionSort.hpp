#ifndef SELECTIONSORT_HPP
#define SELECTIONSORT_HPP

#include "../../include/Algorithms/SortingAlgorithm.hpp"

namespace Sorting {
    class SelectionSort : public SortingAlgorithm {
        public:
            /**
             * @brief Construct a new Selection Sort object
             * 
             * @param int Length of Data
             */
            SelectionSort(int len) : SortingAlgorithm(len) {
                elapsed = currentIndex + 1;
                minIndex = currentIndex;
            }
        private:
            int elapsed;
            int minIndex;

            // Resets values to default
            void set_default();

            // Runs a sort iteration
            void sort();
    };
}

#endif