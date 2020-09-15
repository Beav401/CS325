/*
Author: Reed Boeshans
Date: 4/12/20
Homework 2
CS325
*/

#include <iostream>
#include <fstream>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <cstdlib>
#include <string.h>
#include <chrono>


using namespace std;
using namespace std::chrono;


//This is the function that performs the sorting algorithm
void badsort(vector<int> &list, float alpha, int min, int max) {
  int temp;
  if((max-min+1 == 2) && (list[min] > list[min+1])) {
      //swap first and second elements
      temp = list[min+1];
      list[min+1] = list[min];
      list[min] = temp;
  }
  else if(max-min+1 > 2) {
    int m = (alpha*(max-min));
    badsort(list, alpha, min, min + m);   //sort bottom portion
    badsort(list, alpha, (max-m),  max);  //sort upper portion
    badsort(list, alpha, min, min + m);   //sort bottom portion
  }
  return;
}




int main() {
  srand(time(NULL));
  float alpha = .75;
  int size = 500;
  vector<int> list;
  int num;
  for(int i=0; i<size; i++) {
    num = rand();
    list.push_back(num);
  }
  auto start = high_resolution_clock::now();

  badsort(list, alpha, 0, list.size()-1);

  auto stop = high_resolution_clock::now();
  auto duration = duration_cast<milliseconds>(stop - start);

  cout << "When  n=" << size << ", time: " << duration.count() << " ms" << endl;

  return 0;
}
