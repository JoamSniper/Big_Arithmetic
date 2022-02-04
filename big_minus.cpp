#include <iostream>
#include <string.h>

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

void front_push_back(char buf[], int _length, int _d)
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

void super_computer_operation(char A_array[], char B_array[], char result_array[], int _Max_String_Len, int& checked)
{
	//�˰��� �ۼ�
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

bool Negative_decision(char* A_array, int A_String_Len ,char* B_array, int B_String_Len ,int _Max_String_Len)
{
	int total_score = 0;
	int A_score = 0;
	int B_score = 0;
	//1) B���̰� �� ū��?
	if (A_String_Len < B_String_Len)
	{
		return true;
	}
	//���̰� ���ٸ�
	else if(A_String_Len == B_String_Len)
	{
		//A�� B�� ū �� � �ִ��� Ȯ��
		for (int i = 0; i < _Max_String_Len; i++)
		{
			//A���� B���� ũ�ٸ�
			if (A_array[i] > B_array[i])
			{
				//������ �߰�
				A_score += 1;
			}
			//���ٸ� ������ ����
			else if (A_array[i] == B_array[i])
			{
				continue;
			}
			//B���� A������ ũ�ٸ�
			else
			{
				B_score += 1;
			}
		}

		//���������� ���� �� ū�� Ȯ��
		//B_score�� �� ���ٴ°� ū���� �� ���ٴ� �ǹ��̹Ƿ� �����̴�.
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
int main(void)
{
	char cCcode[1001] = { '\x00' };

	char A_array[1001] = { '\x00' };
	char B_array[1001] = { '\x00' };

	//step1 : ���ڿ� 2�� �Է� ����
	scanf_s("%s %s", A_array, 1001, B_array, 1001);

	//0�� �Ǵ��� Ȯ��.
	if (strcmp(A_array, B_array) == 0)
	{
		printf("0");
		return 0;
	}
	//step2 : ���ڿ� ���� ���� 2�� ���ϱ�
	int A_string_len = mystrlen(A_array);
	int B_string_len = mystrlen(B_array);
	
	//step2[0] : ū �� ���� ����
	int Maximum_len = MMM_L(A_string_len, B_string_len);
	int chcked = 0;

	//step3 : ���ڿ� -> ������ ��ȯ
	Change_string_to_integer(A_array, B_array, A_string_len, B_string_len);

	//step4 : �ڸ��� �ȸ´� �κ� 0���� ä���
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

	//step4 : a < b�� ��
	if (A_string_len < B_string_len)
	{
		front_push_back(A_array, A_string_len, d);
		super_computer_operation(B_array, A_array, cCcode, Maximum_len, chcked);
	}
	//step5 : a > b�� ��
	if (A_string_len > B_string_len)
	{
		front_push_back(B_array, B_string_len, d);
		super_computer_operation(A_array, B_array, cCcode, Maximum_len, chcked);
	}
	//step6 : a == b�� �� 
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
	//�տ� 0���� �ϱ� ����, 0�� �ƴ� ���� ���������� ��� count��.
	for (int i = 0; i < Maximum_len; i++)
	{
		if (cCcode[i] != '\x00')
		{
			break;
		}
		count++;
	}
	//step8 : ��������
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