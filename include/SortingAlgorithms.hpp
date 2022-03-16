#ifndef SORTINGALGORITHMS_HPP
#define SORTINGALGORITHMS_HPP

// List of Algorithm Header files
#include "Algorithms/SelectionSort.hpp"
#include "Algorithms/BubbleSort.hpp"
#include "Algorithms/InsertionSort.hpp"

namespace Sorting {
    // List of Available Algorithms
    enum Algorithms {
        SELECTIONSORT,
        BUBBLESORT,
        INSERTIONSORT,
        // MERGESORT,
        // BMERGESORT,
        // HEAPSORT,
        // QUICKSORT,
        NUM_OF_ALGORITHMS
    };
}

#endif