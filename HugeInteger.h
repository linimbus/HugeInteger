#ifndef HUGEINTEGER_H_
#define HUGEINTEGER_H_
#include <iostream>
#include <vector>
#include <stdint.h>

class HugeInteger
{
private:
	bool isPositive = true;
    std::vector<uint32_t> integers;
	std::string uintToString(uint32_t value, bool first);
	void parseFromString(const std::string&);
	void checkString(const std::string&);
	void addSingle(std::vector<uint32_t>& list, int postion, uint32_t number);
	void subSingle(std::vector<uint32_t>& list, int postion, uint32_t number);
	void subInt(const HugeInteger& h);
	void addInt(const HugeInteger& h);
	void mulSingle(std::vector<uint32_t>& list, int postion, uint32_t number);

	int compare(const std::vector<uint32_t>& list);

public:
	HugeInteger operator=(HugeInteger&);

	// Required methods
	HugeInteger(const std::string& val);
	HugeInteger(int n);
	HugeInteger add(const HugeInteger& h);
	HugeInteger subtract(const HugeInteger& h);
	HugeInteger multiply(const HugeInteger& h);
	int compareTo(const HugeInteger& h);
	std::string toString();
};

#endif /* HUGEINTEGER_H_ */
