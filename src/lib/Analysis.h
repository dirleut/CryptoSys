#pragma once
#include <map>
#include <string>
#include <vector>

static std::map<char, double> english_frequencies = {
    {'A', 0.086}, {'B', 0.014}, {'C', 0.028}, {'D', 0.028},
    {'E', 0.130}, {'F', 0.029}, {'G', 0.010}, {'H', 0.053},
    {'I', 0.063}, {'J', 0.011}, {'K', 0.004}, {'L', 0.034},
    {'M', 0.055}, {'N', 0.061}, {'O', 0.070}, {'P', 0.030},
    {'Q', 0.001}, {'R', 0.065}, {'S', 0.061}, {'T', 0.105},
    {'U', 0.025}, {'V', 0.009}, {'W', 0.005}, {'X', 0.002},
    {'Y', 0.020}, {'Z', 0.001}
};

static double pirson_border = 44.3;
static double english_coincidence_index = 0.0685;
static double error = 0.0012;

double calculatePirsonTest(const std::string& text);
uint8_t findCaesarCiperKey(const std::string& msg);
std::string findVigenereCipherKey(const std::string& msg);

std::vector<long long> factorize(long long number);
