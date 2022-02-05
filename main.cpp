#include "big_operation.h"
#include <iostream>

int main(void)
{

	char cCcode[1001] = { '\x00' };

	char A_array[1001] = { '\x00' };
	char B_array[1001] = { '\x00' };

	big_operation result;

	//step1 : 문자열 2개 입력 받음
	scanf_s("%s %s", A_array, 1001, B_array, 1001);
	std::cout << "[plus]" << std::endl;

	std::cout << "<----------------->" << std::endl;
	std::cout << std::endl;
	result.calculate_plus(A_array, B_array, cCcode);
	std::cout << std::endl;
	std::cout << std::endl;

	std::cout << "<----------------->" << std::endl;


	char cCcode1[1001] = { '\x00' };
	char A_array1[1001] = { '\x00' };
	char B_array1[1001] = { '\x00' };
	scanf_s("%s %s", A_array1, 1001, B_array1, 1001);
	std::cout << "\n[minus]" << std::endl;
	std::cout << "<----------------->" << std::endl;
	result.calculate_minus(A_array1, B_array1, cCcode1);
	std::cout << std::endl;
	std::cout << "<----------------->" << std::endl;
	return 0;
}