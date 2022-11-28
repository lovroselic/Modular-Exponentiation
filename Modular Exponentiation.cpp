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

std::string NumberToBin(int n);
int BinToNumber(std::string bin);

int main() {
	auto t1 = high_resolution_clock::now();
	cout << "Modular Exponentiation v" << VERSION << "!\n\n";
	string path = "Test.txt";
	//string path = "Try.txt";
	vector<string> raw_data = loadData(path);
	vector<string> solution;

	for (int i = 1; i < raw_data.size(); i++) {
		vector<int> line = splitToInt(raw_data[i], " ");
		printVector(line);
	}

	cout << "\nSolution: " << joinVector(solution, " ") << endl;

	/***********************/

	vector<int> test = { 7,8,65,1 , 16 };
	for (auto& i : test) {
		cout << i;
		cout << " : ";
		string bin = NumberToBin(i);
		cout << bin;
		cout << " : ";
		cout << BinToNumber(bin);
		cout << " : ";
		cout << endl;
	}

	/***********************/
	auto t2 = high_resolution_clock::now();
	auto ms_int = duration_cast<milliseconds>(t2 - t1);
	cout << "Execution time: " << ms_int.count() << " ms" << endl;
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