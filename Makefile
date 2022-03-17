CXX = g++
LIB_FLAGS = -lsfml-graphics -lsfml-window -lsfml-system
INCLUDE = include/
SRC = src/
ALGO_DIR = $(SRC)Algorithms/
ALGO_FILES = $(ALGO_DIR)SortingAlgorithm.cpp $(ALGO_DIR)SelectionSort.cpp $(ALGO_DIR)BubbleSort.cpp $(ALGO_DIR)InsertionSort.cpp $(ALGO_DIR)MergeSort.cpp $(ALGO_DIR)HeapSort.cpp $(ALGO_DIR)QuickSort.cpp

SRC_FILES = $(SRC)SortingAlgorithms.cpp $(ALGO_FILES) 

Main: Main.cpp
	$(CXX) Main.cpp $(SRC_FILES) -o Main $(LIB_FLAGS)