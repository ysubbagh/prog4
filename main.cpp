//include header files
#include <iostream>
#include <vector> 
#include <fstream>
#include "biz.h"

using namespace std;

int main() {

/*

   create a biz class

   read in files into the biz class, add customers and movies

   do some transactions for testing (print stocks between too)

   print out customer history

   print out movie infos

*/
   //create the shop
   Biz shop;

   //load in the movies into the movie shop
   string line;
   ifstream infile1("data4movies.txt");
   if (!infile1) {
      cout << "File could not be opened." << endl;
      return 1;
   }
   //do stuff for movies
   for (;;) {
      if (infile1.eof()) break;
      //stuff
      getline(infile1, line);
      shop.buildMovie(line);
   }

   // load in customers into the moveie shop
   ifstream infile2("data4customers.txt");
   if (!infile2) {
      cout << "File could not be opened." << endl;
      return 1;
   }
   //do stuff for customer
   for (;;) {
      if (infile2.eof()) break;
      //stuff
      getline(infile2, line);
      shop.buildCust(line);
   }

   //load in the commands for the transaction history
   ifstream infile3("data4commands.txt");
   if (!infile3) {
      cout << "File could not be opened." << endl;
      return 1;
   }
   //do transaction stuff
   for (;;) {
      if (infile3.eof()) break;
      //stuff
      getline(infile3, line);
      shop.transaction(line);
   }

   //print out output

}