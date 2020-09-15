/*
Author: Reed Boeshans
Date: 4/19/20
Homework 3
CS325
*/

#include <iostream>
#include <fstream>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <cstdlib>
#include <math.h>

using namespace std;

int main() {
  ifstream inputf;
  ofstream outputf;
  inputf.open("data.txt");
  outputf.open("change.txt");
  if(inputf.is_open()) {
      int c;
      inputf >> c;          //only used on the first line
    while(!inputf.eof()){
      int k, n, f;
      inputf >> k;          //gets rest of input values
      inputf >> n;
      outputf << "Data input: c= " << c << ", k= "<< k << ", n= "<< n << endl;
      int denom, count;
      //this is the beginning of the actual algorithm
      for(int i=0; i<(k+1); i++) {        //loops through each coin denomination
        if (n==0) {
          count = 0;
          denom = pow(c, (k-i));          //gets the Denomintion starting at the highest coin value
        }
        else {
          denom = pow(c, (k-i));          //c^(k-i)
          count = (n/denom);              //gets the number of this coin fits in n
        }
          outputf << "Denomintion: " << denom << " Quantity: " << count << endl;
          n = n - (count*denom);        //updating n value after subtracting coin value*count
      }
      outputf << endl;
      inputf >> c;      //gets next c value
    }

  }
  else
    cout << "unable to open data.txt" << endl;

  return 0;
}
