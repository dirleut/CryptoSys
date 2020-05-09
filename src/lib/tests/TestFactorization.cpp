#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>
#include "../Analysis.h"
#include <string>

// g++ -std=c++11 -I <каталог include вместе с catch> -o TestFactorization
// "TestFactorization.cpp" "../Analysis.cpp" "../SymCyphers.cpp"

TEST_CASE("Factorization function test")
{
	SECTION("Prime number") {
		long long prime_number = 564232451;
		std::vector<long long> factors = factorize(prime_number);

		REQUIRE(factors.size() == 1);
		REQUIRE(factors[0] == prime_number);
	}

	SECTION("Nubmer 2^32") {
		long long number = 4294967296;
		std::vector<long long> factors = factorize(number);

		REQUIRE(factors.size() == 32);

		for (size_t i = 0; i < 32; ++i) {
			REQUIRE(factors[i] == 2);
		}
	}

	SECTION("Random number") {
		long long number = 234591951;
		std::vector<long long> factors = factorize(number);

		REQUIRE(factors.size() == 5);

		REQUIRE(factors[0] == 3);
		REQUIRE(factors[1] == 11);
		REQUIRE(factors[2] == 37);
		REQUIRE(factors[3] == 229);
		REQUIRE(factors[4] == 839);
	}
}