/*
Reed Boeshans
4/5/20
Homework 1, CS 325
insertTime.cpp
*/


#include <iostream>
#include <fstream>
#include <vector>
#include <stdlib.h>
#include <time.h>

using namespace std;


void insertsort(vector<int> &list) {
  int j, key, i;
  for(j=1; j<list.size(); j++) {
    key = list[j];
    i = j-1;
    while(i>0 && list[i] > key) {
      list[i+1] = list[i];
      i = i-1;
    }
    list[i+1] = key;
  }
}


int main() {
  srand(time(NULL));
  int size = 35000;
  double diff;
  vector<int> list;
  int num;
  for(int i=0; i<size; i++) {
    num = rand();
    list.push_back(num);
  }

  time_t start, end;
  time (&start);
  insertsort(list);
  time (&end);
  diff = difftime(start, end);
  cout << "The time that has passed for n= " << size << " is: " << diff << endl;
  return 0;
}
