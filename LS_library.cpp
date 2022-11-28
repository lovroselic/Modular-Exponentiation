/*
	v 0.4
*/
#include <vector>
#include <numeric>
#include <cmath>
#include <string>
#include "LS_library.h";
#define PI 3.14159265

double average(std::vector<int>& vect) {
	auto const count = static_cast<float>(vect.size());
	return std::accumulate(vect.begin(), vect.end(), 0.0) / count;
}
double average(std::vector<double>& vect) {
	auto const count = static_cast<double>(vect.size());
	return std::accumulate(vect.begin(), vect.end(), 0.0) / count;
}

double st_dev(std::vector<int>& vect) {
	const double avg = average(vect);
	auto const count = static_cast<float>(vect.size());
	double sum = 0.0;
	for (const auto& v : vect) {
		sum += (v - avg) * (v - avg);
	}
	return std::sqrt(sum / count);
}

double st_dev(std::vector<int>& vect, double avg) {
	auto const count = static_cast<float>(vect.size());
	double sum = 0.0;
	for (const auto& v : vect) {
		sum += (v - avg) * (v - avg);
	}
	return std::sqrt(sum / count);
}
double to_radians(double deg) {
	return deg * PI / 180;
}
double to_degree(double rad) {
	return rad * 180 / PI;
}

std::string NumberToBin(int n) {
	std::string bin = "";
	do {
		int bit = n % 2;
		bin = std::to_string(bit) + bin;
		n /= 2;
	} while (n > 0);
	return bin;
}

int BinToNumber(std::string bin) {
	int n = 0;
	for (int i = 0; i < bin.size(); i++) {
		int j = bin.size() - 1 - i;
		if (bin[j] == '1') {
			n += std::pow(2, i);
		}
	}
	return n;
}