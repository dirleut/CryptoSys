#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>
#include "../Encoding.h"
#include <string>

// g++ -std=c++11 -I <каталог include вместе с catch> -o TestEncoding "TestEncoding.cpp" "../Encoding.cpp"

TEST_CASE("Encoding functions tests")
{
	std::string hex_string = "d092d0b2d0b5d0b4d0b8d182d0b0b8d184d180d0bed0b2d0b0d0bdd0b8d18f2e2e2e";
	std::string binary_string = "000101011110001011001000101010101001";

	SECTION("Checking if string contains only required characters")
	{
		REQUIRE(isHex(hex_string));
		hex_string += "Not hexadecimal characters";
		REQUIRE(!isHex(hex_string));

		REQUIRE(isBinary(binary_string));
		binary_string += "Not binary characters";
		REQUIRE(!isBinary(binary_string));
	}

	SECTION("Encoding binary into hex and vise versa")
	{
		std::string initial_string = binary_string;

		REQUIRE(binaryToHex(binary_string));
		REQUIRE(binary_string == "15e2c8aa9");

		REQUIRE(hexToBinary(binary_string));
		REQUIRE(binary_string == initial_string);
	}

	SECTION("Encoding UTF-8 into binary and vise versa")
	{
		std::string utf8_string = "Мороз и солнце; день чудесный!";
		std::string initial_string = utf8_string;

		REQUIRE(UTF8ToBinary(utf8_string));
		REQUIRE(utf8_string == "11010000100111001101000010111110110100011000000011010000"
							"10111110110100001011011100100000110100001011100000100000110"
							"10001100000011101000010111110110100001011101111010000101111"
							"01110100011000011011010000101101010011101100100000110100001"
							"01101001101000010110101110100001011110111010001100011000010"
							"00001101000110000111110100011000001111010000101101001101000"
							"01011010111010001100000011101000010111101110100011000101111"
							"0100001011100100100001");

		REQUIRE(binaryToUTF8(utf8_string));
		REQUIRE(utf8_string == initial_string);
	}
}
