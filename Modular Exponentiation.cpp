//https://www.codeabbey.com/index/task_view/modular-exponentiation
// https://www.geeksforgeeks.org/modular-exponentiation-power-in-modular-arithmetic/
//https://www.khanacademy.org/computing/computer-science/cryptography/modarithmetic/a/fast-modular-exponentiation

#include <iostream>
#include <sstream>
#include <iomanip>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <chrono>
#include <cmath>
#include <cassert>
#include <limits>
#include <numeric>

#include "Console.h"
#include "CodeAbbey.h"
#include "LS_library.h"
#define VERSION "1.0"

using namespace std;

using std::chrono::high_resolution_clock;
using std::chrono::duration_cast;
using std::chrono::duration;
using std::chrono::milliseconds;

unsigned long long FastModularExponentiation(unsigned long long A, unsigned long long B, unsigned long long M);
unsigned long long QuickMod(unsigned long long A, unsigned long long B);

int main() {
	auto t1 = high_resolution_clock::now();
	cout << "Modular Exponentiation v" << VERSION << "!\n\n";
	//string path = "Test.txt";
	string path = "Try.txt";
	vector<string> raw_data = loadData(path);
	vector<unsigned long long> solution;

	for (int i = 1; i < raw_data.size(); i++) {
		vector<int> line = splitToInt(raw_data[i], " ");

		long A = line[0];
		long B = line[1];
		long M = line[2];

		unsigned long long result = FastModularExponentiation(A, B, M);
		cout << A << "^" << B << " mod " << M << " = " << result << endl;

		solution.push_back(result);
	}

	cout << "\nSolution: " << joinVector(solution, " ") << endl;

	/***********************/
	auto t2 = high_resolution_clock::now();
	auto ms_int = duration_cast<milliseconds>(t2 - t1);
	cout << "Execution time: " << ms_int.count() << " ms" << endl;
}

unsigned long long QuickMod(unsigned long long A, unsigned long long B) {
	return A - B * (A / B);
}

unsigned long long FastModularExponentiation(unsigned long long A, unsigned long long B, unsigned long long M) {
	string bin = NumberToBin(B);
	vector<unsigned long long> MODS(bin.size());

	MODS[0] = QuickMod(A, M);
	for (int k = 1; k < bin.size(); k++) {
		MODS[k] = (MODS[k - 1] * MODS[k - 1]) % M;
	}

	unsigned long long mul = 1;
	for (int k = 0; k < bin.size(); k++) {
		int i = bin.size() - 1 - k;
		if (bin[i] == '1') {
			mul *= MODS[k];
			mul = QuickMod(mul, M);
		}
	}

	return mul % M;
}
