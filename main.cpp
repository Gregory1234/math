#include <math.h>
#include <climits>
#include <fstream>
#include <time.h>
#include <iostream>
typedef unsigned long long u_llong;
typedef unsigned int u_int;
#define bigTypeSize ULLONG_MAX
#define smallTypeSize 1000
using namespace std;
bool check(u_llong);

void main() {
	u_int a = 0;
	ofstream file;
	file.open("output.txt");
	char old = 0;
	clock_t tStart = clock();
	for (u_llong i = 0; i < bigTypeSize && a < smallTypeSize; i++) {
		if (check(i)) {
			a++;
			file << i << endl;
		}
	}
	cout << "Generated " << a << " numbers in " << (double)(clock() - tStart) / CLOCKS_PER_SEC << " seconds" << endl;
	file.close();
	
	if (a == smallTypeSize)
		cout << "Ended because of small limit" << endl;
	else
		cout << "Ended because of big limit" << endl;
	cin.ignore();
	cin.get();
}

bool check(u_llong l) {
	if (fmod(sqrt(l - 1), 1) != 0)
		return false;
	if (l < 2) return false;
	for (u_llong i = 2; i <= sqrtl(l); i++) {
		if (fmod(l, i) == 0) {
			return false;
		}
	}
	return true;
}
