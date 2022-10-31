# include <iostream>
# include <stdlib.h>
# include <assert.h>
# include <ctime>
using namespace std;

/* Input: A_alive indicates Aaron is alive true for alive, false for dead
* B_alive indicates Bob is alive
* C_alive indicates Charlie is alive
* Return: true if at least two are alive otherwise return false */
bool at_least_two_alive(bool A_alive, bool B_alive, bool C_alive);
void Aaron_shoots1(bool& B_alive, bool& C_alive);
void Bob_shoots(bool& A_alive, bool& C_alive);
void Charlie_shoots(bool& A_alive, bool& B_alive);   
void Aaron_shoots2(bool& B_alive, bool& C_alive);
   

// TEST PROTOTYPES
void test_at_least_two_alive(void);
void test_Aaron_shoots1(void);
void test_Bob_shoots(void);
void test_Charlie_shoots(void);
void test_Aaron_shoots2(void);

// Simple method to implement pause function in linux void 
void Press_any_key(void) {
cout << "Press any key to continue..."; cin.ignore().get();
}

// VARIABLES
bool A_alive;
bool B_alive;
bool C_alive;
bool True = true;
bool False = false;

int TOTAL_RUNS = 10000;
int aaronChanceOfWinning = 33;
int bobChanceOfWinning = 50;
int aaronWins1;
int aaronWins2;
int bobWins;
int charlieWins;

string victim;

// Initializes Random number generator's seed and calls test functions
int main() {
cout << "*** Welcome to Jon's Duel Simulator ***\n"; srand(time(0));
   test_at_least_two_alive();
   Press_any_key();
   test_Aaron_shoots1();
   Press_any_key();
   test_Bob_shoots();
   Press_any_key();
   test_Charlie_shoots();
   Press_any_key();
   test_Aaron_shoots2();
   Press_any_key();

// Starts strategy 1 and runs 10,000 times
cout << "Ready to test strategy 1 (run 10000 times):\n"; Press_any_key();

for (int i = 0; i < TOTAL_RUNS; i++) {
   A_alive = B_alive = C_alive = true;
   do {
      if (A_alive) {
            Aaron_shoots1(B_alive, C_alive);
      }
      if (B_alive) {
         Bob_shoots(A_alive, C_alive);
      }
      if (C_alive) {
         Charlie_shoots(A_alive, B_alive);
      }
      } while (at_least_two_alive(A_alive, B_alive, C_alive));
      if (A_alive) {
         aaronWins1 += 1;
      }
      if (B_alive) {
         bobWins += 1;
      }
      if (C_alive) {
         charlieWins += 1;
      }
   }
   cout << "Aaron won " << aaronWins1 << "/10000 duels or " << static_cast<double>(aaronWins1) / TOTAL_RUNS * 100 << "%\n"
   << "Bob won " << bobWins << "/10000 duels or " << static_cast<double>(bobWins) / TOTAL_RUNS * 100 << "%\n"
   << "Charlie won " << charlieWins << "/10000 duels or " << static_cast<double>(charlieWins) / TOTAL_RUNS * 100 << "%\n"
   << endl;

// Reinitializes variables and starts strategy 2 to run 10,000 times
   cout << "Ready to test strategy 2 (run 10000 times):\n"; Press_any_key();
   bobWins = 0;
   charlieWins = 0;
   for (int i = 0; i < TOTAL_RUNS; i++) {
      A_alive = B_alive = C_alive = true;
      do {
         if (A_alive) {
            Aaron_shoots2(B_alive, C_alive);
         }
         if (B_alive) {
            Bob_shoots(A_alive, C_alive);
         }
         if (C_alive) {
            Charlie_shoots(A_alive, B_alive);
         }
         } while (at_least_two_alive(A_alive, B_alive, C_alive));
            if (A_alive) {
            aaronWins2 += 1;
         }
            if (B_alive) {
            bobWins += 1;
         }
            if (C_alive) {
            charlieWins += 1;
         }
   }
   cout << "Aaron won " << aaronWins2 << "/10000 duels or " << static_cast<double>(aaronWins2) / TOTAL_RUNS * 100 << "%\n"
   << "Bob won " << bobWins << "/10000 duels or " << static_cast<double>(bobWins) / TOTAL_RUNS * 100 << "%\n"
   << "Charlie won " << charlieWins << "/10000 duels or " << static_cast<double>(charlieWins) / TOTAL_RUNS * 100 << "%\n"
   << endl;

   if (aaronWins2 < aaronWins1) {
      cout << "Strategy 1 is better than strategy 2.\n";
   }
   else {
      cout << "Strategy 2 is better than strategy 1.\n";
   }
}

// Implementation of functions
bool at_least_two_alive(bool A_alive, bool B_alive, bool C_alive) {
   int count = 0;

   if (A_alive) {
      count++;
   }
   if (B_alive) {
      count++;
   }
   if (C_alive) {
      count++;
   }

   if (count > 1) {
      return true;
   }
   else {
      return false;
   }
}

// Implementation of Aaron_shoots1() 
void Aaron_shoots1(bool& B_alive, bool& C_alive) {
   int generateRandomNumber = rand()%100;

   if (C_alive) {
      victim = "Charlie";
   }
   else {
      victim = "Bob";
   }

   if (generateRandomNumber <= aaronChanceOfWinning) {
      if (victim == "Charlie") {
         C_alive = false;
         return;
      }
      else {
         B_alive = false;
         return;
      }
   }
}

// Implementation of Bob_shoots()
void Bob_shoots(bool& A_alive, bool& C_alive) {
   int generateRandomNumber = rand()%100;
   
   if (C_alive) {
      victim = "Charlie";
   }
   else {
      victim = "Aaron";
   }

   if (generateRandomNumber <= bobChanceOfWinning) {
      if (victim == "Charlie") {
         C_alive = false;
      }
      else {
         A_alive = false;
      }
   }
}

// Implementation of Charlie_shoots()
void Charlie_shoots(bool& A_alive, bool& B_alive) {
   if (B_alive) {
      B_alive = false;
      victim = "Bob";
   }
   else {
      A_alive = false;
      victim = "Aaron";
   }
}

// Implementation of Aaron_shoots2() 
void Aaron_shoots2(bool& B_alive, bool& C_alive) {
   int generateRandomNumber = rand()%100;

   if ((B_alive == true) && (C_alive == true)) {
      return;
   }

   if (C_alive) {
      victim = "Charlie";
   }
   else {
      victim = "Bob";
   }

   if (generateRandomNumber <= aaronChanceOfWinning) {
      if (victim == "Charlie") {
         C_alive = false;
         return;
      }
      else {
         B_alive = false;
         return;
      }
   }
}

// TEST FUNCTION DEFINITIONS
void test_at_least_two_alive(void) {
   cout << "Unit Testing 1: Function - at_least_two_alive()\n";
   cout << "\tCase 1: Aaron alive, Bob alive, Charlie alive\n";
   assert(true == at_least_two_alive(true, true, true));
   cout << "\tCase passed ...\n";
   cout << "\tCase 2: Aaron dead, Bob alive, Charlie alive\n";
   assert(true == at_least_two_alive(false, true, true));
   cout << "\tCase passed ...\n";
   cout << "\tCase 3: Aaron alive, Bob dead, Charlie alive\n";
   assert(true == at_least_two_alive(true, false, true));
   cout << "\tCase passed ...\n";
   cout << "\tCase 4: Aaron alive, Bob alive, Charlie dead\n";
   assert(true == at_least_two_alive(true, true, false));
   cout << "\tCase passed ...\n";
   cout << "\tCase 5: Aaron dead, Bob dead, Charlie alive\n";
   assert(false == at_least_two_alive(false, false, true));
   cout << "\tCase passed ...\n";
   cout << "\tCase 6: Aaron dead, Bob alive, Charlie dead\n";
   assert(false == at_least_two_alive(false, true, false));
   cout << "\tCase passed ...\n";
   cout << "\tCase 7: Aaron alive, Bob dead, Charlie dead\n";
   assert(false == at_least_two_alive(true, false, false));
   cout << "\tCase passed ...\n";
   cout << "\tCase 8: Aaron dead, Bob dead, Charlie dead\n";
   assert(false == at_least_two_alive(false, false, false));
   cout << "\tCase passed ...\n";
}

// Test case for Aaron_shoots1()
void test_Aaron_shoots1(void) {
   cout << "\nUnit Testing 2: Function Aaron_shoots1(Bob_alive, Charlie_alive)\n";
   cout << "\tCase 1: Bob alive, Charlie alive\n";
   cout << "\t\tAaron is shooting at Charlie\n";
   Aaron_shoots1(True, True);
   cout << "\tCase 2: Bob dead, Charlie alive\n";
   cout << "\t\tAaron is shooting at Charlie\n";
   Aaron_shoots1(False, True);
   cout << "\tCase 3: Bob alive, Charlie dead\n";
   cout << "\t\tAaron is shooting at Bob\n";
   Aaron_shoots1(True, False);
}

// Test case for Bob_shoots()
void test_Bob_shoots(void) {
   cout << "\nUnit Testing 3: Function Bob_shoots(Aaron_alive, Charlie_alive)\n";
   cout << "\tCase 1: Aaron alive, Charlie alive\n";
   cout << "\t\tBob is shooting at Charlie\n";
   Bob_shoots(True, True);
   cout << "\tCase 2: Aaron dead, Charlie alive\n";
   cout << "\t\tBob is shooting at Charlie\n";
   Bob_shoots(False, True);
   cout << "\tCase 3: Aaron alive, Charlie dead\n";
   cout << "\t\tBob is shooting at Aaron\n";
   Bob_shoots(True, False);
}

// Test case for Charlie_shoots()
void test_Charlie_shoots(void) {
   cout << "\nUnit Testing 4: Function Charlie_shoots(Aaron_alive, Bob_alive)\n";
   cout << "\tCase 1: Aaron alive, Bob alive\n";
   cout << "\t\tCharlie is shooting at Bob\n";
   Charlie_shoots(True, True);
   cout << "\tCase 2: Aaron dead, Bob alive\n";
   cout << "\t\tCharlie is shooting at Bob\n";
   Charlie_shoots(False, True);
   cout << "\tCase 3: Aaron alive, Bob dead\n";
   cout << "\t\tCharlie is shooting at Aaron\n";
   Charlie_shoots(True, False);
}

// Test case for Aaron_shoots2()
void test_Aaron_shoots2(void) {
   cout << "\nUnit Testing 5: Function Aaron_shoots2(Bob_alive, Charlie_alive)\n";
   cout << "\tCase 1: Bob alive, Charlie alive\n";
   cout << "\t\tAaron intentionally misses his first shot\n";
   cout << "\t\tBoth Bob and Charlie are alive.\n";
   Aaron_shoots2(True, True);
   cout << "\tCase 2: Bob dead, Charlie alive\n";
   cout << "\t\tAaron is shooting at Charlie\n";
   Aaron_shoots2(False, True);
   cout << "\tCase 3: Bob alive, Charlie dead\n";
   cout << "\t\tAaron is shooting at Bob\n";
   Aaron_shoots2(True, False);
}