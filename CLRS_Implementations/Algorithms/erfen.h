#pragma once
#include <iostream>
using namespace std;
constexpr double eps = 1e-6;
namespace clrs {
	namespace algo {
		template <typename P>
		bool check(P x) {
			return true;
		};
		//must注意：check具体的实现需要手动加入。
		int erfen_1(int zuo, int you);
		int erfen_2(int zuo, int you);
		double double_erfen(double zuo, double you);
	}
}
//erfen.h