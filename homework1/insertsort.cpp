/*
Reed Boeshans
4/5/20
Homework 1, CS 325
insertsort.cpp
*/


#include <iostream>
#include <fstream>
#include <vector>

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
  ifstream inputf;
  ofstream outputf;

  vector<int> list;

  inputf.open("data.txt");

  if(inputf.is_open()) {
    int num;
    while(!inputf.eof()) {
      inputf >> num;
      list.push_back(num);
    }
    list.pop_back();    //last element in list is being counted twice for some reason so this removes it

    insertsort(list);

    inputf.close();
    outputf.open("insert.out");
    for(int i=1; i<list.size(); i++){
      outputf << list[i] << " ";
    }

    outputf.close();
  }
  else
    cout << "ERROR: File data.txt could not be opened!" << endl;

    return 0;
}
