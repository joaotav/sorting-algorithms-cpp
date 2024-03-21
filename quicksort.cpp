#include <iostream>
#include <fstream>
#include <cstdlib>
#include <vector>

/* Implemented by João Chervinski (2018) */

using namespace std;

int partition(vector<int> &numbers, int start, int end){
  int p = start, i = start + 1;
  for(int j = i; j <= end; j ++){
    if (numbers[j] <= numbers[p]){
      swap(numbers[j], numbers[i]);
      i++;
    }
  }
  swap(numbers[p], numbers[i - 1]);
  return (i - 1);
}

void quickSort(vector<int> &numbers, int start, int end){
  if (start < end) { 
    int pivot = start + rand() % (end - start + 1); // Choose a pseudo-random pivot
    swap(numbers[start], numbers[pivot]);
    int c = partition(numbers, start, end);
    quickSort(numbers, start, c - 1);
    quickSort(numbers, c + 1, end);
  }
}

int main(int argc, char* argv[]){
  ifstream input_file;
  ofstream output_file;
  int number;
  vector<int> numbers;

  if (argc < 3){
    cout << "[+] Usage: " << argv[0] << " <input_file> <output_file>" << endl;
    exit(1);
  }

  input_file.open(argv[1]);
  output_file.open(argv[2]);

  if (!input_file.is_open()){
    cout << "[+] Could not open input file." << endl;
    exit(1);
  }

  while(input_file >> number){
    numbers.push_back(number);
  }

  input_file.close();

  quickSort(numbers, 0, numbers.size() - 1);

  for(size_t index = 0; index < numbers.size(); index++){
    output_file << numbers[index] << endl;
  }

  cout << "Output data stored in 'output.txt'." << endl;
  
  output_file.close();
  return 0;
}

