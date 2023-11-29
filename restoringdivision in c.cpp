#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
string add(string A, string M) {
int carry = 0;
string Sum;
for (int i = A.length() - 1; i >= 0; i--) {
int temp = A[i] - '0' + M[i] - '0' + carry;
		if (temp > 1) {
			Sum.push_back('0' + (temp % 2));
			carry = 1;
		}
		else {
			Sum.push_back('0' + temp);
			carry = 0;
		}
	}
	reverse(Sum.begin(), Sum.end());
	return Sum;
}
string complement(string m) {
	string M;
	for (int i = 0; i < m.length(); i++) {
		M.push_back('0' + ((m[i] - '0' + 1) % 2));
	}
	M = add(M, "0001");
	return M;
}
void restoringDivision(string Q, string M, string A) {
	int count = M.length();
	cout << "Initial Values: A:" << A << " Q:" << Q << " M:" << M << endl;
	while (count > 0) {
		cout << "\nstep:" << (M.length() - count + 1) << endl;
		A = A.substr(1) + Q[0];
		string comp_M = complement(M);
		A = add(A, comp_M);
		cout << "Left Shift and Subtract: ";
		cout << " A:" << A << endl;
		cout << "A:" << A << " Q:" << Q.substr(1) << "_";
		if (A[0] == '1') {
			Q = Q.substr(1) + '0';
			cout << " -Unsuccessful" << endl;
			A = add(A, M);
			cout << "A:" << A << " Q:" << Q << " -Restoration" << endl;
		}
		else {
			Q = Q.substr(1) + '1';
			cout << " Successful" << endl;
			cout << "A:" << A << " Q:" << Q << " -No Restoration" << endl;
		}
		count--;
	}
	cout << "\nQuotient(Q):" << Q << " Remainder(A):" << A << endl;
}

int main() {
string dividend = "0110";
string divisor = "0100";
string accumulator
= string(dividend.length(), '0');
restoringDivision(dividend, divisor, accumulator);
return 0;
}