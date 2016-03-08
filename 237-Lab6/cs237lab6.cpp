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
Optional input: string, int
Output: a string
*/
string reverse_rec(string const &original, string result = "", int n = 0);


/*
Calculates the nth Tribonacci number.
Input: an integer
Optional: 4 integers
Output: An integer
*/
int tribonacci(int n, int sum = 0, int n1 = 1, int n2 = 1, int n3 = 1);

void pause_237(bool);

int Trib_Count;

int main()
{
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
	cout << "Number of function calls: " << Trib_Count;


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

int tribonacci(int n, int sum, int n1, int n2, int n3) {
	Trib_Count++;
	// Test for explicitly defined numbers
	if (n <= 2) {
		if (n == 2) {
			return 1;
		}
		else if (n == 1) {
			return 1;
		}
		else if (n == 0) {
			return 1;
		}
	}
	else {
		return tribonacci(n - 1) + tribonacci(n - 2) + tribonacci(n - 3);
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