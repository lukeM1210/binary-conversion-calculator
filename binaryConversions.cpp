#include <iostream>
#include <math.h>
#include <list>
#include <string>


using namespace std;

// Functions used in the program
list<int> decimalToBinary(double input);
double binaryToDecimal(int input);

int main(){

string toFromChoice; // Users answer (to/from)
string originalInput; // Input the user wants to convert
bool continueProgram = true; // Flag to control the loop
  
cout << "Welcome to the binary conversion calculator!\n\n";

do{
cout << "Would you like to convert to binary or from binary(to/from)?: ";
cin >> toFromChoice;

cin.ignore();

if( toFromChoice == "to" || toFromChoice == "To" || toFromChoice == "TO"){
  cout << "What decimal form number would you like converted to binary?: ";

  getline(cin,originalInput);
  double input = stod(originalInput); // input in double form
  // call the function to convert into binary...
  list<int> intList = decimalToBinary(input);

  // Output the binary representation
  cout << "The base 2 binary representation of " << originalInput << " is ";
  for(auto it = intList.rbegin(); it != intList.rend(); ++it){
      cout << *it;
  }
  cout << endl;

}else if( toFromChoice == "from" || toFromChoice == "From"){
  cout << "What binary number would you like put into decimal form?: ";

  getline(cin,originalInput);
  int input = stoi(originalInput); // input in integer form
  // call the function to convert into decimal...
  double decimalValue = binaryToDecimal(input);
  cout << "The decimal representation of " << originalInput << " is: " << decimalValue << endl;

}else{
  cout << "Your command " << toFromChoice << " is not a known command.";
}

  string userChoice; // user input for performing another conversion
  cout << "Do you want to perform another conversion? (yes/no): ";
  cin >> userChoice;
  cin.ignore();

  if(userChoice != "yes" && userChoice != "Yes" && userChoice != "YES"){
    continueProgram = false; // Set flag to false if user answers anything but yes, Yes, or YES
  }

} while(continueProgram); // Continue the loop if the user wants to

  cout << "Thank you for using the binary conversion calculator! Goodbye!" << endl;

  return 0;

}

// Function to convert a decimal number to binary
list<int> decimalToBinary(double input) {
    list<int> intList;
    double divisor = 2.0;

    // Convert the base 10 number to binary by dividing and holding remainders
    if(input == 0){
      intList.push_back(0);
    }
    while (input >= 1.0) {
        if (fmod(input, divisor) == 0.0) {
            intList.push_back(0);  // Add the binary 0 to back of the list (no remainder)
            input = input / divisor;  // Set input to original input divided by 2
        } else {
            intList.push_back(1);  // Add the binary 1 to back of the list (has remainder)
            input = (input - 1) / divisor;
        }
    }

    // Return the list of binary digits
    return intList;
}

// Function to convert a binary number to decimal
double binaryToDecimal(int input){

  double decimalValue = 0.0; // To store the decimal result

  int base = 1; // Initialize base value to 1

  int temp = input;

  // Convert by summing the products of digits and powers of 2
  while(temp){
    int lastDigit = temp % 10; // Last digit should be 0 or 1
    temp = temp / 10;

    decimalValue += lastDigit * base; // Multiple by corresponding power of 2

    base = base * 2; // Update base (increment by powers of 2)
  }
  return decimalValue;
}








