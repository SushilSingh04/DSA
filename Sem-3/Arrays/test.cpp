// CPP program to demonstrate use of
// std :: set_intersection
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

// Driver code
int main()
{
	string first[] = { "Sachin", "Rakesh", "Sandeep", "Serena" };
	string second[] = { "Vaibhav", "Sandeep", "Rakesh", "Neha" };
	int n = sizeof(first) / sizeof(first[0]);

	// Print students of first list
	cout << "Students in first class :";
	for (int i = 0; i < n; i++)
		cout << " " << first[i];
	cout << "\n";

	// Print students of second list
	cout << "Students in second class :";
	for (int i = 0; i < n; i++)
		cout << " " << second[i];
	cout << "\n\n";

	vector<string> v(10);
	vector<string>::iterator it, st;

	// Sorting both the list
	sort(first, first + n);
	sort(second, second + n);

	// Using default operator<
	it = set_intersection(first, first + n, second, second + n, v.begin());

	cout << "Students attending both the classes only are :\n";
	for (st = v.begin(); st != it; ++st)
		cout << ' ' << *st;
	cout << '\n';

	return 0;
}
