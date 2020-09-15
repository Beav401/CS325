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

using namespace std;

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

//the main function handles the file input and output and calls the badsort function for each array of numbers
int main(int argc, char* argv[]) {
  if(argc != 2) {
    cout << "alpha value was not provided in program call" << endl;
  }
  else {
    float alpha = atof(argv[1]);    //changing the value from a charater array to float

    ifstream inputf;
    ofstream outputf;

    vector<vector<int> > list;  //2D vector to store the arrays of numbers

    inputf.open("data.txt");  //opening data file
    int array_size;
    int arr_num = 0;
    int num;

    if(inputf.is_open()) {  //if file is opened
      vector<int> temp;
      while(!inputf.eof()) {
        temp.clear();
        inputf >> array_size;   //gets teh first number listed which is the number of elements in array
        for(int i=0; i<array_size; i++) { //loops for that number of elements
          inputf >> num;
          temp.push_back(num);    //adding number to array
        }
        list.push_back(temp);  //pushing array bback to the 2D array
        arr_num++;
      }
    list.pop_back();  //counted last array twice for some reason so this removes it
    arr_num--;

  /*  for(int t=0; t<arr_num; t++) {    //used for testing
      for(int k=0; k<list[t].size(); k++) {
        cout << list[t][k] << " ";
      }
      cout << endl;
    }
  */
    for(int i=0; i<arr_num; i++) {
      badsort(list[i], alpha, 0, list[i].size()-1);
    }

  /* for(int t=0; t<arr_num; t++) {         //used for testing
      for(int k=0; k<list[t].size(); k++) {
        cout << list[t][k] << " ";
      }
      cout << endl;
    }
    */

    inputf.close();
    outputf.open("bad.out");  //opening output file
    for(int j=0; j<arr_num; j++) { //loop for changing array
      for(int i=0; i<list[j].size(); i++){    //loop for each array element
        outputf << list[j][i] << " ";
      }
      outputf << endl;
    }
    outputf.close();
  }
  else
    cout << "ERROR: File data.txt could not be opened!" << endl;
  }

  return 0;
}
