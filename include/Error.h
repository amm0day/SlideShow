#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <iomanip>
using namespace std;


class RisingError {
public:
	static void invalidPizzaMatrix() {
		cout << "Pizza shape don't correspond with description." << endl;
		exit(1);
	}
	static void invalidIngredient() {
		cout << "Found invalid ingredient (symbol)." << endl;
		exit(1);
	}
	static void invalidMinMax() {
		cout << "Minimum ingredients limit per slice is bigest than Maximum" << endl;
		exit(1);
	}
	static void invalidPizza() {
		cout << "Pizza could not be cut. Invalid Pizza." << endl;
		exit(1);
	}
	static void invalidFileFormat() {
		cout << "Invalid file format. File should be (*.in)" << endl;
		exit(1);
	}
	static void toMuchIngredients() {
		cout << "Found to much one type ingredients.\nMake another Pizza;)" << endl;
		exit(1);
	}
	static void invalidHeader() {
		cout << "File header not valid." << endl;
		exit(1);
	}
	static void notOpened() {
		cout << "Error file open. Access denied." << endl;
		exit(1);
	}
	static void undefinedMinOrMax() {
		cout << "Can't set Divs, MIN or MAX are undefined!!!" << endl;
		exit(1);
	}
	static void undefinedXOrY() {
		cout << "Can't set Mask, X or Y are undefined!!!" << endl;
		exit(1);
	}
	static void pizzaHasNoSolution() {
		cout << "Given Pizza has no solution without \"free_spaces_allowed\"!!!"
		<< "\nMake another Pizza;) or use key \"-fsa true\"" << endl;
		exit(1);
	}
	static void argvError() {
		cout << "<optional \"-fsna\" - free spaces not allowed, \"-pmask\" for printing mask>"
		<< " <pizza input file *in>" << endl;
		exit(1);
	}
};
