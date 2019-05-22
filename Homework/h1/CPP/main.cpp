#include <ctime>
#include <gmpxx.h>
#include <iostream>
using namespace std;

typedef struct pair_s {
	pair<mpz_class, mpz_class> R;
	pair<mpz_class, mpz_class> S;
	pair<mpz_class, mpz_class> T;
} pair_s;

pair_s extendedEuclidean(const mpz_class& a, const mpz_class& b) {
	pair_s P;
	pair<mpz_class, mpz_class> R = make_pair(a, b);
	pair<mpz_class, mpz_class> S = make_pair(0, 1);
	pair<mpz_class, mpz_class> T = make_pair(1, 0);
	while (R.first != 0) {
		mpz_class q = R.second / R.first;
		R = make_pair(R.second - q * R.first, R.first);
		S = make_pair(S.second - q * S.first, S.first);
		T = make_pair(T.second - q * T.first, T.first);
	}
	P.R = R;
	P.S = S;
	P.T = T;
	return P;
}

int main(int argc, char const *argv[]) {
	// Generate random seed
	gmp_randclass randclass(gmp_randinit_default);
	randclass.seed((unsigned long) time(nullptr));

	// Generate a and b
	mpz_class a, b, r, r_lib;
	a = randclass.get_z_bits(4096);
	b = randclass.get_z_bits(4096);

	pair_s P = extendedEuclidean(a, b);
	r = P.R.second;
	r_lib = gcd(a, b);

	// Show a, b, and results
	cout << "A: " << a
		<< "\nB: " << b
		<< "\ngcd(a,b): " << r
		<< "\nlibgcd(a,b): " << r_lib << '\n';
	if (r == r_lib) cout << "The results are same.\n";
	else cout << "The results are different.\n";
	return 0;
}
