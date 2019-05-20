#include <ctime>
#include <iostream>
#include <utility>
using namespace std;

pair_s extendedEuclidean(const mpz_class& a, const mpz_class& b);

struct pair_s {
	pair<mpz_class> R;
	pair<mpz_class> S;
	pair<mpz_class> T;
};

int main(int argc, char const *argv[]) {
	// Random seed here

	mpz_class a, b;
	a = randclass.get_z_bits(4096);
	b = randclass.get_z_bits(4096);
	pair_s P = extendedEuclidean(a, b);

	????? = gcd(a, b);

	mpz_class r1 = P.R.?????;

	if (????? == ?????) {
		/* code */
	}

	return 0;
}

pair_s extendedEuclidean(const mpz_class& a, const mpz_class& b) {
	pair_s P;
	pair R = make_pair(a, b);
	pair S = make_pair(0, 1);
	pair T = make_pair(1, 0);
	while (R.????? != 0) {
		mpz_class q = R.1????? / R.0?????;
		R = make_pair(R.0?????, R.1????? - q * R.0?????);
		S = make_pair(S.0?????, S.1????? - q * S.0?????);
		T = make_pair(T.0?????, T.1????? - q * T.0?????);
	}
	P.R = R;
	R.S = S;
	R.T = T;
	return P;
}
