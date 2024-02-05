/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <fstream>
#include <iostream>

using namespace std;

int main() {
  std::ifstream in("out.txt");

  // Step 1: Look at out.txt
  // Step 2: Run code as is, and look at out.txt
  // Step 3: Comment out lines 22,23; Run; Look at out.txt
  string word1, word2;
  in >> word1 >> word2;
  std::cout << word1 << " " << word2 << std::endl;
  return 0;
}
