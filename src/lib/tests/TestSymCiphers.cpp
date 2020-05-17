#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>
#include "../SymCiphers.h"
#include <string>

// g++ -std=c++11 -I <каталог include вместе с catch> -o TestSymCiphers
// "TestSymCiphers.cpp" "../SymCiphers.cpp"

TEST_CASE("Basic symmetric ciphers test")
{
	std::string message = "MEETINGATELEVENOCLOCK";

	SECTION("Caesar cipher")
	{
		std::string init_message = message;
		int key = 12;

		caesar(message, key);
		REQUIRE(message == "YQQFUZSMFQXQHQZAOXAOW");

		// 26 - 12 = 14
		caesar(message, LAT_ALPHABET_SIZE - 12);
		REQUIRE(message == init_message);
	}

	SECTION("Scytale cipher")
	{
		std::string init_message = message;
		int key = 5;

		scytale(message, key, ENCRYPT);
		REQUIRE(message == "MNLOKEGEC0EAVL0TTEO0IENC0");

		scytale(message, message.size() / key, DECRYPT);
		REQUIRE(message == init_message);
	}

	SECTION("Vigenere cipher")
	{
		std::string init_message = message;
		std::string key = "SECRETKEY";

		vigenere(message, key, ENCRYPT);
		REQUIRE(message == "EIGKMGQERWPGMIGYGJGGM");

		vigenere(message, key, DECRYPT);
		REQUIRE(message == init_message);
	}

	SECTION("Leaving only letters")
	{
		std::string text = "Security controls should be tailored to the specifics"
			"of an organisation by means of risk-based approach.";
		leaveLettersOnly(text);

		REQUIRE(text == "SECURITYCONTROLSSHOULDBETAILOREDTOTHESPECIFICS"
			"OFANORGANISATIONBYMEANSOFRISKBASEDAPPROACH");
	}
}