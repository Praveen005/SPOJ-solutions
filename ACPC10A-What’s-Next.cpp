#include<iostream>
using namespace std;
int main() {
	while (true) {
		int a, b, c;
		cin >> a >> b >> c;
		//CONDITION TO EXIT LOOP
		if ((a == b) && (b == c) && (a == 0)) {
			break;
		}
		//In an AP : (A+C)/2 == B  also (B-A)  == (C-B)
		if ((((a + c) / 2) == b) && ((b - a) == (c - b))) {
			cout << "AP " << (c + (c - b)) << endl;
		}
		// for a GP : C*A ==B^2   also  B/A == C/B
		if (((a * c) == (b * b)) && ((b / a) == (c / b))) {
			cout << "GP " << (c * (c / b)) << endl;
		}
	}
}
