#include <iostream>
#include <chrono>
#include <ctime>


#include "BigInt.h"

using namespace std::chrono;

void AddTest(long i_start, long i_end, long j_start, long j_end) {
	std::cout << "AddTest: ";

	long count = 0;
	double total = 0;

	for (long i = i_start; i <= i_end; i++) {
		for (long j = j_start; j <= j_end; j++) {
			BigInt a = i;
			BigInt b = j;

			auto startTime = high_resolution_clock::now();
			BigInt c = a + b;
			auto t = high_resolution_clock::now() - startTime;
			total += (double) duration_cast<nanoseconds>(t).count();

			count++;

			if (c != i + j)
				std::cout << a << " + " << b << " != " << c << std::endl;
		}
	}
	
	double avg = total / count / 1000;

	std::cout << (total / 1000000) << " ms for " << count << " add operations (average: " << avg << " us)\n";
}

void SubTest(long i_start, long i_end, long j_start, long j_end) {
	std::cout << "SubTest: ";

	long count = 0;
	double total = 0;

	for (long i = i_start; i <= i_end; i++) {
		for (long j = j_start; j <= j_end; j++) {
			BigInt a = i;
			BigInt b = j;

			auto startTime = high_resolution_clock::now();
			BigInt c = a - b;
			auto t = high_resolution_clock::now() - startTime;
			total += (double) duration_cast<nanoseconds>(t).count();

			count++;

			if (c != i - j)
				std::cout << a << " - " << b << " != " << c << std::endl;
		}
	}
	
	double avg = total / count / 1000;

	std::cout << (total / 1000000) << " ms for " << count << " sub operations (average: " << avg << " us)\n";
}

void DivTest(long n_max, long i_max) {
	std::cout << "DivTest: ";

	long count = 0;
	double total = 0;

	for (long n = -n_max; n <= n_max; n++) {
		for (long i = -i_max; i <= i_max; i++) {
			if (!n)
				continue;

			BigInt a = i;
			BigInt b = n;
			
			auto startTime = high_resolution_clock::now();
			BigInt c = a / b;
			auto t = high_resolution_clock::now() - startTime;
			total += (double) duration_cast<nanoseconds>(t).count();

			count++;

			if (c != i / n)
				std::cout << a << " / " << b << " != " << c << std::endl;
		}
	}

	double avg = total / count / 1000;

	std::cout << (total / 1000000) << " ms / " << count << " div operations (average: " << avg << " us)\n";
}

void ModTest(long n_max, long i_max) {
	std::cout << "ModTest: ";

	long count = 0;
	double total = 0;

	for (long n = -n_max; n <= n_max; n++) {
		for (long i = -i_max; i <= i_max; i++) {
			if (!n)
				continue;

			BigInt a = i;
			BigInt b = n;
			
			auto startTime = high_resolution_clock::now();
			BigInt c = a % b;
			auto t = high_resolution_clock::now() - startTime;
			total += (double) duration_cast<nanoseconds>(t).count();

			count++;

			if (c != i % n)
				std::cout << a << " % " << b << " != " << c << std::endl;
		}
	}

	double avg = total / count / 1000;

	std::cout << (total / 1000000) << " ms / " << count << " mod operations (average: " << avg << " us)\n";
}

void MulTest(long n_max, long i_max) {
	std::cout << "MulTest: ";
	
	long count = 0;
	double total = 0;

	for (long n = -n_max; n <= n_max; n++) {
		for (long i = -i_max; i <= i_max; i++) {
			BigInt a = i;
			BigInt b = n;
			
			auto startTime = high_resolution_clock::now();
			BigInt c = a * b;
			auto t = high_resolution_clock::now() - startTime;
			total += (double) duration_cast<nanoseconds>(t).count();

			count++;

			if (c != i * n)
				std::cout << a << " * " << b << " != " << c << std::endl;
		}
	}

	double avg = total / count / 1000;

	std::cout << (total / 1000000) << " ms / " << count << " mul operations (average: " << avg << " us)\n";
}

void FactTest(int n, bool print = false) {
	std::cout << std::endl << "FactTest: ";

	BigInt a = 1;

	auto startTime = high_resolution_clock::now();

	for (int i = 1; i <= n; i++) {
		a *= i;

		if (print)
			std::cout << std::endl << i << "! = " << a;
	}

	auto endTime = high_resolution_clock::now();
	auto t = endTime - startTime;

	if (print)
		std::cout << std::endl;

	std::cout << duration_cast<microseconds>(t).count() << " us" << std::endl;
}

int main(int argc, const char **argv) {
	srand(time(NULL));

	try {
		int v = 1000;
		AddTest(-v, v, -v, v);
		SubTest(-v, v, -v, v);
		MulTest(v, v);
		DivTest(v, v);
		ModTest(v, v);
		FactTest(50, true);
	}
	catch (std::string msg) {
		std::cout << "Exception: " << msg << std::endl;
	}
}
