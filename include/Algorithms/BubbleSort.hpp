#ifndef BUBBLESORT_HPP
#define BUBBLESORT_HPP

#include "../../include/Algorithms/SortingAlgorithm.hpp"

namespace Sorting {
    class BubbleSort : public SortingAlgorithm {
        public:
            /**
             * @brief Construct a new Bubble Sort object
             * 
             * @param int Length of Data
             */
            BubbleSort(int len) : SortingAlgorithm(len) {
                elapsed = 0;
            }

        private:
            int elapsed;

            // Resets values to default
            void set_default();

            // Runs a sort iteration
            void sort();
    };
}

#endif