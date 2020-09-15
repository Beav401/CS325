/*
Reed Boeshans
CS325
5/8/20
Homework 5
*/

#include <iostream>
#include <fstream>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <cstdlib>
#include <math.h>

using namespace std;


//this function is used to see if a wrestler is already part of a vector
bool partOF(vector<string> vec, string str) {
  for(int i=0; i<vec.size(); i++) {
    if(vec[i] == str) {
      return true;
    }
  }
  return false;
}



int main(int argc, char* argv[]) {
  if (argc != 2) {    //makes sure a second argument was entered in command line
    cout << "ERROR: file was not provided in command line" << endl;
  }
  else {
    ifstream inputf;
    inputf.open(argv[1]);
    if(inputf.is_open()) {    // checks that file provided can be openned
      int num_wrestlers = 0;
      int num_rivalries = 0;
      inputf >> num_wrestlers;          //getting the number of wrestlers
      vector<vector<string> > matrix;
      for(int i=0; i<num_wrestlers; i++) {    //for number of wrestlers
        vector<string> temp_vect;       //add a vector for each wrestler
        string temp;
        inputf >> temp;
        temp_vect.push_back(temp);
        matrix.push_back(temp_vect);    // add wrestler names to first row in table
      }
      inputf >> num_rivalries;
      //adds all rivalries to matrix.  rival will be placed in column of wrestler lested first in rivalry
      for(int i=0; i<num_rivalries; i++) { //for every rivalry
        string temp1, temp2;
        inputf >> temp1;   //a vs.
        inputf >> temp2;   //b
        for(int j=0; j<num_wrestlers; j++) {    //finds correct column to place b under a
          if(matrix[j][0] == temp1) {
            matrix[j].push_back(temp2);
            for(int k=0; k<num_wrestlers;k++) {  //finds correct column to place a under b
              if(matrix[k][0] == temp2) {
                matrix[k].push_back(temp1);
                break;
              }
            } //end of for k
            break;
          }
        }  //end of for j
      }    //end of for i

  /*  for(int i=0; i<num_wrestlers; i++) {
        for(int j=0; j<matrix[i].size(); j++) {
          cout << matrix[i][j] << " ";
        }
        cout << endl;
      }
      */

      //algorithm portion
      vector<string> babyface;
      vector<string> heel;

      for(int i=0; i< num_wrestlers; i++) {    //for every wrestler or every column in table
        if(partOF(babyface, matrix[i][0])) {    //checks if wrestler is already in babyface
          for(int j=1;j<matrix[i].size();j++) {     //if so all wrestlers below are placed in the heels if not already there
            if(partOF(heel, matrix[i][j]) == false) {
              heel.push_back(matrix[i][j]);
            }
          }
        }
        else if(partOF(heel, matrix[i][0])) {   //checks if wrestler is already in heels.
          for(int j=1;j<matrix[i].size();j++) {   //if so all wrestlers below it are placed in babyface if not already there
            if(partOF(babyface, matrix[i][j]) == false) {
              babyface.push_back(matrix[i][j]);
            }
          }
        }
        else {                                     //if wrestler is not part of either group yet it is defaulted to babyface
          babyface.push_back(matrix[i][0]);
          for(int j=1;j<matrix[i].size();j++) {     //all wrestlers below are placed into heels if not already there
            if(partOF(heel, matrix[i][j]) == false) {
              heel.push_back(matrix[i][j]);
            }
          }

        }
      } //end of for i

/*      for(int i=0; i<babyface.size(); i++) {
        cout << babyface[i] << " ";
      }
      cout << endl;
      for(int i=0; i<heel.size(); i++) {
        cout << heel[i] << " ";
      }*/

      //There is a possibility if sum of babyfaces and heels is equal to the number of wrestlers.
      //if the sum is greater, one wrestler is listed in both groups so there are no possibilities
      if((babyface.size() + heel.size()) != num_wrestlers) {
        cout << "NO possibilities" << endl;
      }
      else {
        cout << "YES" << endl << "Babyfaces: ";
        for(int i=0; i<babyface.size(); i++) {    //prints all of babyfaces
          cout << babyface[i] << " ";
        }
        cout << endl << "Heels: ";
        for(int i=0; i<heel.size(); i++) {      //prints all of heels
          cout << heel[i] << " ";
        }
        cout << endl << endl;
      }
    }
    else
      cout << "ERROR: file provided could not be openned" << endl;
  }

  return 0;
}
