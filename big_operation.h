#pragma once
#include <iostream>
class big_operation
{
private:
	char A_array_reverse[1001] = { '\x00' };
	char B_array_reverse[1001] = { '\x00' };
private:
	//-
	int mystrlen(const char* str);
	void Change_string_to_integer(char str[], char Str[], int str_index, int Str_index);
	int MMM_L(int str1_len, int str2_len);
	void front_push_back(char buf[], int _length, int _d);
	void super_computer_operation(char A_array[], char B_array[], char result_array[], int _Max_String_Len, int& checked);
	bool Negative_decision(char* A_array, int A_String_Len, char* B_array, int B_String_Len, int _Max_String_Len);
	//+
public:
	void calculate_plus(char A_array[], char B_array[], char cCcode[]);

public:
	void calculate_minus(char A_array[], char B_array[], char cCcode[]);
public:
	big_operation(){}
	~big_operation(){}
};

void big_operation::super_computer_operation(char A_array[], char B_array[], char result_array[], int _Max_String_Len, int& checked)
{
	//알고리즘 작성
	int carray = 0;
	for (int i = _Max_String_Len - 1; i >= 0; i--)
	{
		if (A_array[i] < B_array[i])
		{
			carray = 1;
			result_array[i] = (10 - (B_array[i] - A_array[i])) + result_array[i];
			result_array[i - 1] -= carray;
		}
		else if (A_array[i] == B_array[i])
		{
			carray = 1;
			result_array[i] = (A_array[i] - B_array[i] + result_array[i]);
			if (result_array[i] < 0)
			{
				result_array[i] = 9;
				result_array[i - 1] -= carray;
			}
		}
		else
		{
			result_array[i] = (A_array[i] - B_array[i]) + result_array[i];
		}
		carray = 0;
	}
}
void big_operation::front_push_back(char buf[], int _length, int _d)
{
	for (int i = _length - 1; i >= 0; i--)
	{
		buf[i + _d] = buf[i];
	}
	for (int i = 0; i < _d; i++)
	{
		buf[i] = 0;
	}
}
int big_operation::MMM_L(int str1_len, int str2_len)
{
	if (str1_len > str2_len)
	{
		return str1_len;
	}
	else
	{
		return str2_len;
	}
}

void big_operation::Change_string_to_integer(char str[], char Str[], int str_index, int Str_index)
{
	int i;
	for (i = 0; i < (str_index > Str_index ? str_index : Str_index); i++)
	{
		if (i < str_index)
			str[i] -= 48;
		if (i < Str_index)
			Str[i] -= 48;
	}
}

int big_operation::mystrlen(const char* str)
{
	int c = 0;
	for (int i = 0; str[i] != '\x00'; i++)
	{
		c++;
	}
	return c;
}

bool big_operation::Negative_decision(char* A_array, int A_String_Len, char* B_array, int B_String_Len, int _Max_String_Len)
{
	int total_score = 0;
	int A_score = 0;
	int B_score = 0;
	//1) B길이가 더 큰가?
	if (A_String_Len < B_String_Len)
	{
		return true;
	}
	//길이가 같다면
	else if (A_String_Len == B_String_Len)
	{
		//A와 B중 큰 값 몇개 있는지 확인
		for (int i = 0; i < _Max_String_Len; i++)
		{
			//A값이 B보다 크다면
			if (A_array[i] > B_array[i])
			{
				//가산점 추가
				A_score += 1;
			}
			//같다면 가산점 없음
			else if (A_array[i] == B_array[i])
			{
				continue;
			}
			//B값이 A값보다 크다면
			else
			{
				B_score += 1;
			}
		}

		//최종적으로 누가 더 큰지 확인
		//B_score가 더 많다는건 큰값이 더 많다는 의미이므로 음수이다.
		if (B_score > A_score)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	else
	{
		return false;
	}

}


void big_operation::calculate_minus(char A_array[], char B_array[], char cCcode[])
{
	//0이 되는지 확인.
	if (strcmp(A_array, B_array) == 0)
	{
		printf("0");
		exit(0);
	}
	//step2 : 문자열 길이 각각 2개 구하기
	int A_string_len = mystrlen(A_array);
	int B_string_len = mystrlen(B_array);

	//step2[0] : 큰 값 길이 저장
	int Maximum_len = MMM_L(A_string_len, B_string_len);
	int chcked = 0;

	//step3 : 문자열 -> 정수로 변환
	Change_string_to_integer(A_array, B_array, A_string_len, B_string_len);

	//step4 : 자릿수 안맞는 부분 0으로 채우기
	int d = (A_string_len - B_string_len);
	if (d < 0)
	{
		d = -d;
	}

	for (int i = 0; i < d; i++)
	{
		if (A_string_len == B_string_len)
		{
			break;
		}
		else if (A_string_len > B_string_len)
		{
			B_array[B_string_len + i] = 0;
		}
		else
		{
			A_array[A_string_len + i] = 0;
		}

	}

	//step4 : a < b일 
	if (A_string_len < B_string_len)
	{
		front_push_back(A_array, A_string_len, d);
		super_computer_operation(B_array, A_array, cCcode, Maximum_len, chcked);
	}
	//step5 : a > b일 
	if (A_string_len > B_string_len)
	{
		front_push_back(B_array, B_string_len, d);
		super_computer_operation(A_array, B_array, cCcode, Maximum_len, chcked);
	}
	//step6 : a == b일  
	int sum_A = 0;
	int sum_B = 0;
	for (int i = 0; i < Maximum_len; i++)
	{
		sum_A += A_array[i];
		sum_B += B_array[i];
	}
	if (A_string_len == B_string_len)
	{
		if (sum_A < sum_B)
		{
			super_computer_operation(B_array, A_array, cCcode, Maximum_len, chcked);
		}
		else
		{
			super_computer_operation(A_array, B_array, cCcode, Maximum_len, chcked);
		}
	}

	int count = 0;
	//앞에 0제거 하기 위해, 0이 아닌 수를 만날까지 계속 count함.
	for (int i = 0; i < Maximum_len; i++)
	{
		if (cCcode[i] != '\x00')
		{
			break;
		}
		count++;
	}
	//step8 : 음수판정
	if (Negative_decision(A_array, A_string_len, B_array, B_string_len, Maximum_len))
	{
		printf("-");
		for (int i = count; i < Maximum_len; i++)
		{
			printf("%d", cCcode[i]);
		}
	}
	else
	{
		for (int i = count; i < Maximum_len; i++)
		{
			printf("%d", cCcode[i]);
		}
	}
}

void big_operation::calculate_plus(char A_array[], char B_array[], char cCcode[])
{
	//step2 : 문자열 길이 각각 2개 구하기
	int A_string_len = mystrlen(A_array);
	int B_string_len = mystrlen(B_array);

	//step2[0] : 큰 값 길이 저장
	int Maximum_len = MMM_L(A_string_len, B_string_len);

	//step3 : 문자열 -> 정수로 변환
	Change_string_to_integer(A_array, B_array, A_string_len, B_string_len);

	//step4 : 자릿수 안맞는 부분 0으로 채우기
	int d = (A_string_len - B_string_len);
	if (d < 0)
	{
		d = -d;
	}


	for (int i = 0; i < d; i++)
	{
		if (A_string_len == B_string_len)
		{
			break;
		}
		else if (A_string_len > B_string_len)
		{
			B_array[B_string_len + i] = 0;
		}
		else
		{
			A_array[A_string_len + i] = 0;
		}
	}



	//step5 : 문자열 역순으로 바꾸기
	for (int i = 0; i < A_string_len; i++)
	{
		A_array_reverse[i] = A_array[A_string_len - i - 1];
	}
	for (int i = 0; i < B_string_len; i++)
	{
		B_array_reverse[i] = B_array[B_string_len - i - 1];
	}


	char result[1001] = { '\x00' };

	//step 6 : 덧셈 알고리즘 Write.
	int carray = 0;
	int check = 1;
	for (int i = 0; i < Maximum_len; i++)
	{
		//마지막 더하는 부분
		if (i == Maximum_len - 1 && A_array_reverse[i] + B_array_reverse[i] + result[i] >= 10)
		{
			check = 0;
		}
		//반올림이 되는가?
		if (A_array_reverse[i] + B_array_reverse[i] + result[i] >= 10)
		{
			carray = 1;
			result[i] = (A_array_reverse[i] + B_array_reverse[i] + result[i]) % 10;
			result[i + 1] += carray;
		}
		else
		{

			result[i] = (A_array_reverse[i] + B_array_reverse[i] + result[i]);
		}
		carray = 0;
	}
	/*
	12345678910111213
	2839287
	*/
	//step 7 : 출력
	if (check == 1)
	{
		for (int i = 0; i < Maximum_len; i++)
		{
			cCcode[i] = result[(Maximum_len)-i - 1];
		}
		for (int i = 0; i < Maximum_len; i++)
		{
			printf("%d", cCcode[i]);
		}
	}
	else
	{
		for (int i = 0; i < Maximum_len + 1; i++)
		{
			cCcode[i] = result[(Maximum_len + 1) - i - 1];
		}
		for (int i = 0; i < Maximum_len + 1; i++)
		{
			printf("%d", cCcode[i]);
		}
	}
}