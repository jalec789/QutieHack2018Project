#include <iostream>
using namespace std;
int main() {

	int temp =0;
	int rem =0;
	cout << "hello\n";
	for(int i = 0; i <= 9; i++) {
		temp = i;
		for(int len = 0; len < 4; len++) {
			cout << temp % 2;
			temp = temp / 2;
		}
		cout << endl;
	}


	return 0;
}