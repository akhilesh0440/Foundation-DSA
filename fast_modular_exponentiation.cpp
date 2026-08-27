#include <iostream>

using namespace std;

int fastExpo(int a, long long n, int MOD) {
	/// --> (a^n) % MOD
	/// (2, 100, 13) --> (2, 50, 13) --> (2, 25, 13) --> ....
	/// if recursion is being used, lot stack memory will be taken over
	int ans = 1; 
	/// 1. n is add: (2 ^ 12), a = 2, n = 12, ans = 2;
	/// 2. n is even: ((4)^6), a = 4, n = 6, ans = 2;
	/// 3. n is even: ((16) ^ 3, a = 16, n = 2, ans = 2
	/// 4. n is odd: 16^2; a = 16, n = 2, ans = 32;
	/// 5. nis even: 256^1, a = 256, n = 1, ans = 32
	/// 6. n is add: 256^0, a = 256, n = 0, ans = 32 * 256
	while (n >= 1) {
		if (n % 2 == 0) {
			a = (1LL * a * a) % MOD;
			n /= 2;
		}
		else {
			ans = (1LL * ans * a) % MOD;
			n--;
		}
		return ans;
	}
}


/*int main() {
	
	return 0;
}*/