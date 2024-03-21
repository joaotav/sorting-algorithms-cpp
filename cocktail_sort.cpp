#include<iostream>
#include<fstream>
#include<vector>
#include<cstdlib>

/* Implemented by João Chervinski (2018) */

using namespace std;

void swap(int *x, int *y){
    int aux = *x;
    *x = *y;
    *y = aux;
}

int main(int argc, char* argv[]){
  string filename = argv[1];
  ifstream input_file;
  ofstream output_file;
  int number, swapped;
  vector <int> numbers;

  input_file.open(filename.c_str());

  if (!input_file){
    cout << "[+] Usage: " << argv[0] << " <input_file>" << endl;
    exit(1);
  }

  output_file.open("output.txt");

  // Reads numbers from input file
  while(true){
    input_file >> number;
    if (input_file.eof()) break; // Stop when end of file is reached
    numbers.push_back(number);
  }

  for (int i = 0; i < numbers.size() - 1; i++){
    swapped = 0;
    for (int j = 0; j < numbers.size() - i - 1; j++){
      if (numbers[j] > numbers[j + 1]){
        swap(&numbers[j], &numbers[j + 1]);
        swapped = 1;
      }
    }
    if (!swapped) break;
    swapped = 0;
    for (int j = numbers.size() - 2 - i; j > i; j --){
      if (numbers[j] < numbers[j-1]){
        swap(&numbers[j], &numbers[j - 1]);
        swapped = 1;
      }
    }
  }

  for(int i = 0; i < numbers.size(); i++){
    output_file << numbers[i] << endl;
  }

  cout << "Output data stored in 'output.txt'." << endl;

  input_file.close();
  output_file.close();
}
