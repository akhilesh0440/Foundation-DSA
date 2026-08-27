#include <iostream>
  
int f[100], expo[100], len;

using namespace std;

void primeFactor(int n) {
	int d = 2;

	while (d * d <= n && n > 1) {
		int k = 0;

		while (n % d == 0) {
			k++;
			n /= d;
		}

		if (k > 0) {
			f[len] = d;
			expo[len] = k;
			len++;
		}
		d++;

	}

	if (n > 1) {
		f[len] = n;
		expo[len] = 1;
		len++;
	}
}

int main() {
	primeFactor(100);
	for (int i = 0; i <= len; i++) {
		cout << f[i] << " " << expo[i] << endl;
	}
}