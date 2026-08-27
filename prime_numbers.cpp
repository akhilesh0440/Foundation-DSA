#include <iostream>
#include <vector>

using namespace std;

const int Nmax = 100001;

vector<bool> isPrime(Nmax, true);

void sieveOfEratosthenes(int n) {
	for (int i = 2; i <= n / 2; i++) {
		if (isPrime[i] == true) {
			for (int j = i * 2; j <= n; j += i) {
				isPrime[j] = false;
			}
		}
	}
}

/*int main() {
	sieveOfEratosthenes(100);
	for (int i = 2; i <= 100; i++) {
		if (isPrime[i] == true) {
			cout << i << " ";
		}
	}
	return 0;
}*/