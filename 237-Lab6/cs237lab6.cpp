/*

CS237 Lab 6
Joe Opseth
3/l0/2016

Recursively compute the reverse of a string
and calculate nth 'Tribonacci' numbers

*/

#include <iostream>
#include <string>


using namespace std;

/*
Reverses a string.
Input: a const reference to a string
Optional: string, int
Output: a string
*/
string reverse_rec(string const &original, string result = "", int n = 0);


/*
Calculates the nth Tribonacci number.
Input: an integer
Optional: 4 integers
Output: An integer
*/
int tribonacci(int n, int x = 1, int n1 = 1, int n2 = 1, int n3 = 1);

void pause_237(bool);

int Trib_Count;

int main()
{
	Trib_Count = 0;
	string input;
	int n;

	cout << "Enter a string to reverse: ";
	cin >> input;
	cout << "Original String: " << input << endl;
	cout << "Reverse String: " << reverse_rec(input) << endl;

	pause_237(true);
	
	cout << "Enter an integer n to find the nth Tribonacci number: ";
	cin >> n;
	cout << "Result: " << tribonacci(n) << endl;
	cout << "Number of function calls: " << Trib_Count << endl;

	Trib_Count = 0;
	cout << endl << "25th Tribonacci number: " << tribonacci(25) << endl;
	cout << "Trib Count for this call only: " << Trib_Count << endl;
	Trib_Count = 0;
	cout << endl << "26th Tribonacci number: " << tribonacci(26) << endl;
	cout << "Trib Count for this call only: " << Trib_Count << endl;
	Trib_Count = 0;
	cout << endl << "28th Tribonacci number: " << tribonacci(28) << endl;
	cout << "Trib Count for this call only: " << Trib_Count << endl;
	Trib_Count = 0;
	cout << endl << "30th Tribonacci number: " << tribonacci(30) << endl;
	cout << "Trib Count for this call only: " << Trib_Count << endl;

	pause_237(true);

	return 0;
}

string reverse_rec(string const &original, string result, int n) {

	// return result if the end of the string has been reached
	if (original.length() == n) {
		return result;
	}
	else {
		// put the nth character at the start of the result string and increment n
		return reverse_rec(original, original.at(n) + result, n + 1);
	}
}

int tribonacci(int n, int x, int n1, int n2, int n3) {
	Trib_Count++;
	// Return when done (> to prevent overflow in case of bad call to function)
	if (x >= n)
		return n1 + n2 + n3;
	else if (x <= 2) {
		if (n >= 0) {
			switch (n) {
			case 0:
				return 1;
			case 1:
				return 1;
			case 2:
				return 1;
			default:
				return tribonacci(n, 3, 1, 1, 1);
			}
		}
		else {
			return 0; // return 0 for bad n parameter
		}
	}
	else {
		// recursive step
		// increment x and pass the next 3 tribonacci numbers
		return tribonacci(n, x + 1, n2, n3, n1 + n2 + n3);
	}
}

void pause_237(bool have_newline)
{
	if (have_newline) {
		// Ignore the newline after the user's previous input.
		cin.ignore(200, '\n');
	}

	// Prompt for the user to press ENTER, then wait for a newline.
	cout << endl << "Press ENTER to continue." << endl;
	cin.ignore(200, '\n');
}