# A collection of sorting algorithms in C++

This repository contains implementations of popular sorting algorithms in C++. Each algorithm is implemented in a separate file as a standalone C++ program.

## Algorithms Included

- **Bubble Sort**: A comparison-based algorithm that repeatedly steps through the list of values, compares adjacent elements, and swaps them if they are in the wrong order.
- **Cocktail Sort**: An extension of bubble sort that sorts in both directions on each pass through the list.
- **Merge Sort**: A divide-and-conquer algorithm that divides the list into n sublists, each containing one element, then repeatedly merges sublists to produce new sorted sublists until there is only one list remaining.
- **Quick Sort**: An algorithm that works by partitioning an array into two parts, then sorting the parts independently.

### Input and Output

The input should be a text file (`<input_file>`) containing integers to be sorted, with one integer per line.

## Compilation and Execution

Ensure you have a C++ compiler (like `g++`) installed on your system. Compile the source code using the following command:

`g++ <sorting_algorithm>.cpp -o executable`

Where `<sorting_algorithm>` is the desired sorting algorithm implementation.

To execute, run the following command, specifying an input file with the unsorted data and an output file to store the sorted data:  

 `./executable <input_file> <output_file>`


