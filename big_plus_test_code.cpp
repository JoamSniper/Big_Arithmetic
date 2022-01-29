#include <iostream>


int mystrlen(const char* str)
{
	int c = 0;
	for (int i = 0; str[i] != '\x00'; i++)
	{
		c++;
	}
	return c;
}

void Change_string_to_integer(char str[], char Str[], int str_index, int Str_index)
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

int MMM_L(int str1_len, int str2_len)
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
int main(void)
{

	char A_array_reverse[1001] = { '\x00' };
	char B_array_reverse[1001] = { '\x00' };
	char cCcode[1001] = { '\x00' };

	char A_array[1001] = { '\x00' };
	char B_array[1001] = { '\x00' };

	//step1 : 문자열 2개 입력 받음
	scanf_s("%s %s", A_array, 1001, B_array, 1001);

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
	//점검해보기
	printf("\nd : %d", d);

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


	//점검 해보기
	printf("\n\n<-----------------reverse Before----------------->\n");
	printf("[A_array]\n");
	for (int i = 0; i < Maximum_len; i++)
	{
		printf("%d ", A_array[i]);
	}
	printf("\n\n");
	printf("[B_array]\n");
	for (int i = 0; i < Maximum_len; i++)
	{
		printf("%d ", B_array[i]);
	}
	printf("\n");

	//step5 : 문자열 역순으로 바꾸기
	for (int i = 0; i < A_string_len; i++)
	{
		A_array_reverse[i] = A_array[A_string_len - i - 1];
	}
	for (int i = 0; i < B_string_len; i++)
	{
		B_array_reverse[i] = B_array[B_string_len - i - 1];
	}

	//점검 해보기
	printf("\n\n<-----------------reverse After----------------->\n");
	printf("[A_array]\n");
	for (int i = 0; i < Maximum_len; i++)
	{
		printf("%d ", A_array_reverse[i]);
	}
	printf("\n\n");
	printf("[B_array]\n");
	for (int i = 0; i < Maximum_len; i++)
	{
		printf("%d ", B_array_reverse[i]);
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
	printf("\n");
	for (int i = 0; i < Maximum_len; i++)
	{
		printf("%d", result[i]);
	}
	printf("\n\n");
	if (check == 1)
	{
		for (int i = 0; i < Maximum_len; i++)
		{
			cCcode[i] = result[(Maximum_len)-i - 1];
		}
		printf("\n<--------------------[result]------------------->\n");
		for (int i = 0; i < Maximum_len; i++)
		{
			printf("%d", cCcode[i]);
		}
		printf("\n\n");
	}
	else
	{
		for (int i = 0; i < Maximum_len + 1; i++)
		{
			cCcode[i] = result[(Maximum_len + 1) - i - 1];
		}
		printf("\n<--------------------[result]------------------->\n");
		for (int i = 0; i < Maximum_len + 1; i++)
		{
			printf("%d", cCcode[i]);
		}
		printf("\n\n");
	}

	return 0;
}