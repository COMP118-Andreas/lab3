
#include <iostream>
#include <cassert>
using namespace std;

// Function prototypes
int printMenu();
void fillInArray(int[], const int);
void multArrays(const int[], const double[], int[], const int);
void displayArray(const double[], const int);
int sumOddArray(const int[], const int);
bool isAllPositive(const int[], const int);
void avgOddArray(const int[], const int, int&);

/**
 * <code>main</code> is the main function of this program.
 * <BR>
 * @return Returns 0 if success, any other value otherwise.
 */

int main() {
	int choice;
	const int SIZE = 10;

	// Initialize array price
	int price[SIZE] = { 12, 4, 8, 1, 17, 2, 4, 2, 9, 1 };
	// Declare array quantity and total
	int quantity[SIZE];
	double total[9];

	int oddArr[SIZE] = { 1,2,3,4,5,6,7,8,9,10 };
	int sumOdd = 0;
	bool isPositive = false;
	int  avg;

	// Interactive menu
	do {
		choice = printMenu();

		switch (choice) {
			// Enter quantity
		case 1:
			fillInArray(quantity, 11);
			break;
			// Calculate total
		case 2:
			multArrays(quantity, total, price, SIZE);
			break;
			// Print total
		case 3:
			displayArray(total, SIZE);
			break;
			// Exit
		case 4:
			// No code needed
			break;
		case 5:
			sumOdd = sumOddArray(oddArr, SIZE);
			break;
		case 6:
			isPositive = isAllPositive(oddArr, SIZE);
			break;
		case 7:
			avgOddArray(oddArr, SIZE, avg);
			break;
		default:
			assert(true);
		}
	} while (choice != 4);

	cout << "\nHave a nice day:)" << endl;
	return 0;
}

/**
 * <code>printMenu</code> shows a menu and accepts the choice
 * from the user which is returned.
 * <BR>
 * @return Returns the menu choice
 */
int printMenu() {
	int choice;

	do {
		cout << "\n == MENU ==";
		cout << "\n1) Enter quantity";
		cout << "\n2) Calculate total";
		cout << "\n3) Print total";
		cout << "\n4) Exit";
		cout << "\n5) sumOddArray";
		cout << "\n6) isAllPositive";
		cout << "\n7) avgOddArray";

		cout << "\nEnter the choice: ";
		cin >> choice;

		if (choice < 1 || choice > 7) {
			cout << "\nWrong choice, try again.";
		}
	} while (choice > 1 && choice < 8);
	return choice;
}

/**
 * <code>fillInArray</code> is a function that will
 * fill in the elements of an array.
 * <BR>
 * @param arr The array to be filled in.
 * @param size The size of the array.
 */
void fillInArray(int arr[], const int size) {
	assert(size > 1);

	for (int i = 0; i < size; ++i) {
		cout << "\nEnter an element for the array at " << i << ": ";
		cin >> arr[i];
	}
}

/**
 * <code>multArrays</code> multiplies the value of elements of the source array
 * to the corresponding value at the destination array. NOTE: precondition
 * is that the arrays have the same size.
 * <BR>
 * @param arrSource The array containing the destination elements.
 * @param arrDest The array containing the source elements.
 * @param size The size of the arrays.
 */
void multArrays(const int arrQuantity[], const int arrPrice[], double arrTotal[], const int size) {
	assert(size > 0);
	const double VAT = 0.21;

	for (int i = 0; i <= size; ++i) {
		arrTotal[i] = double(arrQuantity[i] * (arrPrice[i] + VAT));
	}
}
// Sums the odd numbers in the array and returns the result
int sumOddArray(const int arr[], const int size) {
	int sum = 0;
	for (int i = 0; i <= size; i++)
	{
		if ((arr[i] % 2) == 1)
			sum += arr[i];
	}

	return sum;
}

// If all the values in the array are positive return true
bool isAllPositive(const int arr[], const int size) {

	for (int i = 0; i < size; i++)
	{
		if (arr[i] <= 0)
		{
			return false;
		}
	}
	return true;

}

// Finds the average of all the odd numbers in the array and stores this in the last argument
void avgOddArray(const int arr[], const int size, int& avgOdd) {
	int sum = 0;
	for (int i = 0; i < size; i++) {
		sum += arr[i];

	}
	avgOdd = sum / size;
}