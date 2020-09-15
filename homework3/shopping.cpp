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
#include <string.h>
#include <algorithm>

using namespace std;


// W = number of items in knapSack
// W[] =

int knapSack(vector<int> price, vector<int> weight, int num_items, int maxWeight, vector<int> &items) {
  //This part of the knapsack algoritm was taken from the lecture notes provided
    int table[num_items + 1][maxWeight + 1];

    // Build ing table
    for(int i = 0; i <= num_items; i++)
    {
        for(int w = 0; w <= maxWeight; w++)
        {
            if (i == 0 || w == 0)
                table[i][w] = 0;
            else if (weight[i - 1] <= w)
                table[i][w] = max(price[i - 1] + table[i - 1][w - weight[i - 1]], table[i - 1][w]);
            else
                table[i][w] = table[i - 1][w];
        }
    }
    //this portion of the algorithm is added to keep track of what items were selected
  int weight2 = maxWeight;
  int maxprice = table[num_items][maxWeight];

  for (int i=num_items; i>0; i--) {  //for each item starting at teh last one
    if(maxprice <=0)  //if we have selected all items and ran out of money
      break;
    else if (maxprice != table[i-1][weight2]) {  //if item was chosen
      items.push_back(i);   //add to list
      maxprice -= price[i-1];   //adjust new weight and price values
      weight2 -= weight[i-1];
    }
  }
    return table[num_items][maxWeight];  //highest price we can reach
}



int main() {
  ifstream inputf;
  ofstream outputf;
  int num_cases;
  int num_items;
  int p_temp;
  int w_temp;
  int fam_size;
  int max_weight;
  int maxprice;
  vector<int> price;
  vector<int> weight;
  vector<int> max;
  vector<int> items;

  inputf.open("shopping.txt");
  outputf.open("results.txt");
  if(inputf.is_open()) {
    inputf >> num_cases;            //reads in the number of cases
    for(int i=0; i<num_cases; i++) {  //for number of cases
      inputf >> num_items;
      outputf << "Test Case: " << i+1 << endl;
      price.clear();      //clearing vectors so they can be used in a new test case
      weight.clear();
      max.clear();
      maxprice = 0;

      for(int j=0; j<num_items; j++) {    //for the number of items
        inputf >> p_temp;         //read in price
        inputf >> w_temp;         //read in weight
        price.push_back(p_temp);
        weight.push_back(w_temp);
      }
      inputf >> fam_size;
      outputf << "Member items: " << endl;
      for(int k=0;k<fam_size;k++) {   //for each family member
        items.clear();            //empty items vector
        inputf >> max_weight;
        max.push_back(max_weight);
        maxprice += knapSack(price, weight, num_items, max[k], items);      //runs knapsack algorithim on ith family member
                                                                            //result is added together to create a family total
        outputf << k+1 << ": ";
        for(int l=0; l<items.size();l++) {      //outputs each family members items
          outputf << items[l] << " ";
        }
        outputf << endl;
      }
      outputf << "Total Price: " << maxprice << endl << endl;       //output family's total price
    }
  }


}
