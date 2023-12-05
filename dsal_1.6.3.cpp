#include <iostream>
#include <string>
#include <vector>

using namespace std;

template <typename T>
const T &findMax(const vector<T> &a)
{
	int maxIndex = 0;
	for (int i = 1; i < a.size(); i++) {
		if (a[maxIndex] < a[i])
			maxIndex = i;
	}
	return a[maxIndex];
}

class Employee
{
public:
	void setValue(const string &n, double s)
	{ name = n; salary = s; }

	const string &getName() const { return name; }

	void print(ostream &out) const 
	{ out << name << " (" << salary << ") "; }

	bool operator<(const Employee &rhs) const
	{ return salary < rhs.salary; }

private:
	string name;
	double salary;
};

//Why is there no scope symbol here? like ostream::operator...
ostream &operator<<(ostream &out, const Employee &rhs)
{
	rhs.print(out);
	return out;
}

int main()
{
	vector<Employee> v(3);

	v[0].setValue("helly", 40000.00);
	v[1].setValue("bill", 2222.33);
	v[2].setValue("john", 1300000.00);
	cout << findMax(v) << endl;

	return 0;
}
