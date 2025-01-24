#include "HugeInteger.h"
#include <stdint.h>
#include <sstream>
#include <iostream>

const uint32_t MAX_INT32 = 1000000000;

HugeInteger HugeInteger::operator=(HugeInteger& h) {
	integers.clear();
	for (auto& number : h.integers ) {
		integers.push_back(number);
	}
	isPositive = h.isPositive;
	return *this;
}

void HugeInteger::checkString(const std::string& val) {
	if (val.size() == 0) {
		throw std::exception();
	}
	for (size_t i = 0; i < val.size(); i++)
	{
		auto number = val.at(i);
		if ( number == '-' && i == 0 && val.size() != 1 ) {
			continue;
		}
		if ( number > '9' || number < '0' ) {
			throw std::exception();
		}
	}
}

void HugeInteger::parseFromString(const std::string& val) {
	checkString(val);
	auto numbers = val;
	if ( val.at(0) == '-') {
		isPositive = false;
		numbers = val.substr(1);
	}
	uint32_t value;
	int begin = (int)numbers.size() - 9;
	for ( ; begin > 0; begin -= 9)
	{
		value = atoi(numbers.substr(begin, 9).c_str());
		integers.push_back(value);
	}
	value = atoi(numbers.substr(0, 9 + begin).c_str());
	integers.push_back(value);
}

HugeInteger::HugeInteger(const std::string& val) {
	parseFromString(val);
}

HugeInteger::HugeInteger(int n) {
	if ( n < 1 ) {
		throw std::exception();
	}
	std::stringstream ss;
	do {
		int value = random()%10;
		if (value > 0 ) {
			ss << value;
			break;
		}
	} while (true);
	for (int i = 1; i < n; i++) {
		ss << random()%10;
	}
	parseFromString(ss.str());
}

void HugeInteger::addSingle(std::vector<uint32_t>& list, int postion, uint32_t number) {
	while (postion > list.size() - 1 || list.size() == 0 ) {
		list.push_back(0);
	}
	uint64_t sum = (uint64_t)list[postion] + (uint64_t)number;
	if ( sum > MAX_INT32 ) {
		addSingle(list, postion + 1, sum / MAX_INT32);
	}
	list[postion] = sum % MAX_INT32;
}

void HugeInteger::addInt(const HugeInteger& h) {
	for (size_t i = 0; i < h.integers.size(); i++) {
		addSingle(integers, i, h.integers.at(i));
	}
}

HugeInteger HugeInteger::add(const HugeInteger& h) {
	if (isPositive == h.isPositive) {
		addInt(h);
	} else {
		subInt(h);
	}
	return *this;
}

void HugeInteger::subSingle(std::vector<uint32_t>& list, int postion, uint32_t number) {
	if (list[postion] < number ) {
		subSingle(list, postion + 1, 1);
		list[postion] += MAX_INT32;
	}
	list[postion] -= number;
}

void HugeInteger::subInt(const HugeInteger& h) {
	auto ret = compare(h.integers);
	if ( ret < 0 ) {
		std::vector<uint32_t> temp = h.integers;
		for (size_t i = 0; i < integers.size(); i++) {
			subSingle(temp, i, integers.at(i));
		}
		isPositive = !isPositive;
		integers = temp;
	} else {
		for (size_t i = 0; i < h.integers.size(); i++) {
			subSingle(integers, i, h.integers.at(i));
		}
	}
	while (integers.back() == 0 && integers.size() > 0 ) {
		integers.pop_back();
	}
}

HugeInteger HugeInteger::subtract(const HugeInteger& h) {
	if (isPositive == h.isPositive) {
		subInt(h);
	} else {
		addInt(h);
	}
	return *this;
}

void HugeInteger::mulSingle(std::vector<uint32_t>& list, int postion, uint32_t number) {
	for (size_t i = 0; i < integers.size(); i++) {
		uint64_t mul = (uint64_t)number * (uint64_t)integers[i];
		addSingle(list, postion + i, mul % MAX_INT32);
		auto high = mul / MAX_INT32;
		if (high > 0 ) {
			addSingle(list, postion + i + 1, high);
		}
	}
}

HugeInteger HugeInteger::multiply(const HugeInteger& h) {
	if ( isPositive != h.isPositive ) {
		isPositive = false;
	} else {
		isPositive = true;
	}
	std::vector<uint32_t> result;
	for (size_t i = 0; i < h.integers.size(); i++) {
		mulSingle(result, i, h.integers.at(i));
	}
	integers = result;
	while (integers.back() == 0 && integers.size() > 0 ) {
		integers.pop_back();
	}
	if ( integers.size() == 1 && integers[0] == 0 ) {
		isPositive = true;
	}
	return *this;
}

int HugeInteger::compare(const std::vector<uint32_t>& list) {
	if (integers.size() > list.size()) {
		return 1;
	}
	if (integers.size() < list.size()) {
		return -1;
	}
	for (int i = (int)integers.size() - 1; i >= 0; i--)
	{
		if (integers[i] > list[i]) {
			return 1;
		}
		if (integers[i] < list[i]) {
			return -1;
		}
	}
	return 0;
}

int HugeInteger::compareTo(const HugeInteger& h) {
	if (isPositive && !h.isPositive) {
		return 1;
	}
	if (!isPositive && h.isPositive) {
		return -1;
	}
	int ret = compare(h.integers);
	if ( ret == 0 ) {
		return 0;
	}
	if (!isPositive && !h.isPositive) {
		return ret == 1 ? -1 : 1;
	}
	return ret;
}

std::string HugeInteger::uintToString(uint32_t value, bool first) {
	char buff[12];
	if ( !first ) {
		snprintf(buff, sizeof(buff), "%09u", value);
	} else {
		snprintf(buff, sizeof(buff), "%u", value);
	}
	return std::string(buff);
}

std::string HugeInteger::toString() {
	std::stringstream ss;
	if (!isPositive) {
		ss << "-";
	}
	if (integers.size() == 0) {
		return "0";
	}
	int i = (int)integers.size() - 1;
	ss << uintToString(integers[i], true);
	for ( i-- ; i >= 0; i--) {
		ss << uintToString(integers[i], false);
	}
	return ss.str();
}
