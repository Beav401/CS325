/*
Reed Boeshans
4/5/20
Homework 1, CS 325
mergesort.cpp
*/

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;


void merge(vector<int> &list,int min,int mid,int max) {
  int n1 = mid-min+1;
  int n2 = max - mid;
  int left[n1];
  int right[n2];
  for(int i=0; i<n1; i++) {
    left[i] = list[min+i];
  }
  for(int j=0; j<n2; j++) {
    right[j] = list[mid+j+1];
  }

  int i=0;
  int j=0;
  int k=min;
  while(i<n1 && j<n2) {
    if(left[i] <= right[j]) {
      list[k] = left[i];
      i++;
    }
    else {
      list[k] = right[j];
      j++;
    }
    k++;
  }

  while (i < n1) {
    list[k] = left[i];
    i++;
    k++;
  }
  while (j<n2) {
    list[k] = right[j];
    j++;
    k++;
  }
}





void mergesort(vector<int> &list, int min, int max) {
  int mid;
  if (min < max) {
    mid = ((min+max)/2);
    mergesort(list, min, mid);
    mergesort(list, mid+1, max);
    merge(list, min, mid, max);
  }
}


int main() {
  ifstream inputf;
  ofstream outputf;

  vector<int> list;

  inputf.open("data.txt");

  if(inputf.is_open()) {
    int num;
    int check = 1;
    while(!inputf.eof()) {
      inputf >> num;
      if(check != 1) {
        list.push_back(num);
      }
      else
        check =0;
    }
    list.pop_back();      //last element is getting counted twice for some reason
    int max = (list.size()-1);
    mergesort(list, 0, max);

    inputf.close();
    outputf.open("merge.out");
    for(int i=0; i<list.size(); i++){
      outputf << list[i] << " ";
    }

    outputf.close();
  }
  else
    cout << "ERROR: File data.txt could not be opened!" << endl;

    return 0;
}
