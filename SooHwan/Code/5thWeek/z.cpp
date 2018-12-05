#include <iostream>
#include <cmath>

unsigned int zSearch(unsigned int N, unsigned int r, unsigned int c);

int main() {

	unsigned int N, r, c;

	std::cin >> N >> r >> c;

	std::cout << zSearch(N, r, c) << "\n";
	return 0;
}

unsigned int zSearch(unsigned int N, unsigned int r, unsigned int c) {


	if (N == 1) {
		return static_cast<unsigned int>(2 * r + c);
	}
	else {
		unsigned int centerline = static_cast<unsigned int>(pow(2, N - 1));
		unsigned int NofQuadrant = centerline * centerline;

		if (r < centerline) {
			if (c < centerline)
				return zSearch(N - 1, r, c);
			else
				return NofQuadrant + zSearch(N - 1, r, c - centerline);
		}
		else {
			if (c < centerline)
				return NofQuadrant * 2 + zSearch(N - 1, r - centerline, c);
			else
				return NofQuadrant * 3 + zSearch(N - 1, r - centerline, c - centerline);
		}
	}
}