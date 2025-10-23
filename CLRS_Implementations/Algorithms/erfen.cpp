#include "erfen.h"
using namespace clrs;
using namespace algo;
int erfen_1(int zuo, int you) {
	while (zuo < you) {
		int mid = zuo + you >> 1;
		if (check(mid)) you = mid;
		else zuo = you + 1;
	}
	return 0;
}
int erfen_2(int zuo, int you) {
	while (zuo < you) {
		int mid = zuo + you + 1 >> 1;
		if (check(mid))zuo = mid;
		else you = mid - 1;
	}
}
double double_erfen(double zuo, double you) {
	while (you-zuo>eps) {
		double mid = (zuo+you)/2;
		if (check(mid))zuo = mid;
		else you = mid;
	}
}
//erfen.cpp