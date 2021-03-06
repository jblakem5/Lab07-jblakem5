

#include "pch.h"
#include "Lab07-jblakem5.h"
#include "RandomUtilities.h"
#include "winTimer.h"
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<double>
getNums(size_t listSize, double minNum, double maxNum)
{
	vector<double> theList;
	for (size_t i = 0; i < listSize; ++i)
	{
		theList.push_back(randReal(minNum, maxNum));
	}

	return theList;
}

int main()
{
	while (true)
	{
		cout << "Enter size for numbers: ";
		int n = 0;
		cin >> n;
		if (n <= 0)
			break;

		cout << "Enter seed for rand: ";
		unsigned int seed;
		cin >> seed;
		srand(seed);

		// Construct a list of numbers
		Timer get;
		get.start();
		vector<double> numbers = getNums(n, 1, 500);
		get.stop();
		cout << "Constructed in " << get() << " seconds"
			<< endl;

		//for (size_t i = 0; i < numbers.size(); ++i) {
		//	cout << numbers.at(i) << ", ";
		//}
		//cout << endl << endl;


		Timer bub;
		bub.start();
		quickSort(0, numbers.size() - 1, numbers);
		bub.stop();
		cout << "Sorted " << numbers.size() << " numbers in " << bub() << " seconds"
			<< endl;

		/*for (size_t i = 0; i < numbers.size(); ++i) {
			cout << numbers.at(i) << ", ";
		}
		cout << endl << endl;*/


	}
	return 0;
}