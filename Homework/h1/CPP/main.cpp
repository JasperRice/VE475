#include <ctime>
#include <gmpxx.h>
#include <iostream>
#include <utility>
using namespace std;

struct pair_s {
	pair<mpz_class, mpz_class> R;
	pair<mpz_class, mpz_class> S;
	pair<mpz_class, mpz_class> T;
};

pair_s extendedEuclidean(const mpz_class& a, const mpz_class& b) {
	pair_s P;
	pair<mpz_class, mpz_class> R = make_pair(a, b);
	pair<mpz_class, mpz_class> S = make_pair(0, 1);
	pair<mpz_class, mpz_class> T = make_pair(1, 0);
	while (R.first != 0) {
		mpz_class q = R.second / R.first;
		R = make_pair(R.first, R.second - q * R.first);
		S = make_pair(S.first, S.second - q * S.first);
		T = make_pair(T.first, T.second - q * T.first);
	}
	P.R = R;
	R.S = S;
	R.T = T;
	return P;
}

int main(int argc, char const *argv[]) {
	// Generate random seed
	gmp_randclass randclass(gmp_randinit_default);
	randclass.seed((unsigned long) time(nullptr));

	// Generate a and b
	mpz_class a, b, r;
	a = randclass.get_z_bits(4096);
	b = randclass.get_z_bits(4096);

	pair_s P = extendedEuclidean(a, b);
	mpz_class r1 = P.R.first;
	mpz_class r1_lib = gcd(a, b);

	std::cout << "A: " << a << "; B: " << b << ".\n";
	if (r1 == r1_lib) cout << "The results are same.\n";
	else cout << "The results are different.\n";
	return 0;
}
