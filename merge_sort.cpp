#include <iostream>
#include <fstream>
#include <cmath>
#include <cstdlib>
#include <vector>

/* Implemented by João Chervinski (2018) */

using namespace std;

void merge(vector <int> &array, int start, int end, int middle, vector <int> &aux){
  int auxIndex = start; // Auxiliary index to traverse the array during sorting
  int firstHalfIndex = start; // Index of the first subarray
  int secondHalfIndex = middle + 1; // Index of the second subarray

  for(int i = start; i <= end; i++){
    aux[i] = array[i];
  }

  while(firstHalfIndex <= middle && secondHalfIndex <= end){
    // While the index of the first subarray is not in the middle or the index
    // of the second subarray is not in the final position, continue
    if (aux[secondHalfIndex] >= aux[firstHalfIndex]){
      // The value at the current position of the second subarray is greater than the value
      // at the current position of the first subarray
      array[auxIndex] = aux[firstHalfIndex]; // Move the smaller value to the sorted array
      firstHalfIndex++;
    }
    else{
      // The value at the current position of the first subarray is greater than the value at the
      // current position of the second subarray
      array[auxIndex] = aux[secondHalfIndex]; // Move the smaller value to the sorted array
      secondHalfIndex++;
    }
    auxIndex++;
  }

  if(secondHalfIndex > end){
    // If the second subarray reaches the end first, copy the remaining items in
    // the first subarray to the sorted array
    for(int i = firstHalfIndex; i <= middle; i++){
      array[auxIndex] = aux[i];
      auxIndex++;
    }
  }

  else if(firstHalfIndex > middle){
    // If the first subarray reaches the end first, copy the remaining items in
    // the second subarray to the sorted array
    for(int i = secondHalfIndex; i <= end; i++){
      array[auxIndex] = aux[i];
      auxIndex++;
    }
  }
}


void mergeSort(vector<int> &array, int start, int end, vector <int> &aux){
  if (end > start){
    int middle = floor((start + end)/2);

    // Calls sort for each of the halves
    mergeSort(array, start, middle, aux);
    mergeSort(array, middle+1, end, aux);

    // Merges the halves
    merge(array, start, end, middle, aux);
  }
}

int main(int argc, char* argv[]){
  ifstream input_file;
  ofstream output_file;
  int number;
  vector <int> aux;
  vector <int> numbers;

  if (argc < 3){
    cout << "[+] Usage: " << argv[0] << " <input_file> <output_file>" << endl;
    exit(1);
  }

  string input = argv[1];
  string output = argv[2];

  input_file.open(input.c_str());
  output_file.open(output.c_str());

  if (!input_file || !output_file){
    cout << "[+] Usage: " << argv[0] << " <input_file> <output_file>" << endl;
    exit(1);
  }

  // Reads the values from the input file
  while(true){
    input_file >> number;
    if (input_file.eof()) break; // Stops at the end of the file
    numbers.push_back(number);
    aux.push_back(number);
  }

  input_file.close();

  mergeSort(numbers, 0, numbers.size()-1, aux);

  // Stores the data in the output file
  for(int i = 0; i < numbers.size(); i++)
    output_file << numbers[i] << endl;

  cout << "Output data stored in 'output.txt'." << endl;
  
  output_file.close();

}

