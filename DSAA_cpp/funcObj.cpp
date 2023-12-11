#include <iostream>
#include <vector>
#include <string>
#include <cstring>    //strcmp

using namespace std;

template <typename Object, typename Compar>
const Object &findMax(const vector<Object> &arr, Compar cmp)
{
	int maxIndex = 0;
	for (int i = 1; i < arr.size(); i++)
		if (cmp.isLessThan(arr[maxIndex], arr[i]))
			maxIndex = i;
	return arr[maxIndex];
}

class CaseInsensitiveCompare
{
public:
	//function object: a class with no data member, only one func member
	bool isLessThan(const string &lhs, const string & rhs) const
	{ return strcmp(lhs.c_str(), rhs.c_str()) < 0; }
};

int main()
{
	vector<string> arr(3);
	arr[0] = "ZEBRA"; arr[1] = "alligator"; arr[2] = "crocodile";
	//use operator override to call isLessThan function
	cout << findMax(arr, CaseInsensitiveCompare()) << endl;

	return 0;
}
