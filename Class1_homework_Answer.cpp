#include "stdafx.h"
#include <string>
#include "ClassIndex.h"



/*
�]�p�o���I���\��
http://invoice.etax.nat.gov.tw/

1. �w�]�������X
2. ��J8�ӼƦr
��X���G �����H�Ϊ��B

*/
bool class1_homework()
{
	printf("\n�п�J���X(��Jover����)\n");
	char caInputNumber[9] = { 0 }; ///�x�s�o�����X8��Ʀr(�w�d�����Ÿ�+1)�A�@�@9�ӪŶ�
	fgets(caInputNumber, 9, stdin); ///���ݿ�J

	if (caInputNumber[0] == 10) ///�Y��J�Ĥ@�Ӧr����10(0x0A ��ASCII����Ÿ��A�����}�����禡
		return true; ///�^��true�Ϧ��I���禡��A������

	///ASCII �Ѧ� https://zh.wikipedia.org/zh-tw/ASCII

	///�Y��J"over"�h�^�Ǭ�false�H���}���а��檺while �j��
	int nstrCmp = strcmp(caInputNumber, "over");
	if (nstrCmp >= 0)
		return false;


	///�������N��J���r��(char[9])�ର�ƭ�(int)
	int nNumber = atoi(caInputNumber);

	///�w�]����
	int nFirstSpacailNumber = 91909013;
	int nSpecailNumber = 95976127;
	int nFirstNumbers[3] = { 54845444, 41876525, 86331065 };//200,1000,4000,10000,40000,
	int nExtalNumbers[4] = { 352, 672, 731, 214 }; //200

	///�P�Ĥ@�S�������ۦP
	if (nNumber == nFirstSpacailNumber)
	{
		printf("%d=>1,000W", nFirstSpacailNumber);
		return true;
	}

	///�P�S�O�������ۦP
	if (nNumber == nSpecailNumber)
	{
		printf("%d=>200W", nSpecailNumber);
		return true;
	}

	///�P���@�Y�������X�����ۦP
	for (int n = 0; n<3; n++)
	{
		if (nNumber == nFirstNumbers[n])
		{
			printf("%d =>20W", nFirstNumbers[n]);
			return true;
		}
	}
	///�P���@�Y��������7�X�ۦP
	for (int n = 0; n<3; n++)
	{
		int nMod = 10000000;
		int nLast7 = nFirstNumbers[n] % nMod;
		int nInputLast7 = nNumber % nMod;
		if (nInputLast7 == nLast7)
		{
			printf("%d:[%d]=>40000", nFirstNumbers[n], nLast7);
			return true;
		}
	}

	///�P���@�Y��������6�X�ۦP
	for (int n = 0; n<3; n++)
	{
		int nMod = 1000000;
		int nLast6 = nFirstNumbers[n] % nMod;
		int nInputLast6 = nNumber % nMod;
		if (nInputLast6 == nLast6)
		{
			printf("%d:[%d]=>10000", nFirstNumbers[n], nLast6);
			return true;
		}
	}

	///�P���@�Y��������5�X�ۦP
	for (int n = 0; n<3; n++)
	{

		int nMod = 100000;
		int nLast5 = nFirstNumbers[n] % nMod;
		int nInputLast5 = nNumber % nMod;
		if (nInputLast5 == nLast5)
		{
			printf("%d:[%d]=>4000", nFirstNumbers[n], nLast5);
			return true;
		}
	}

	///�P���@�Y��������4�X�ۦP
	for (int n = 0; n<3; n++)
	{
		int nMod = 10000;
		int nLast4 = nFirstNumbers[n] % nMod;
		int nInputLast4 = nNumber % nMod;
		if (nInputLast4 == nLast4)
		{
			printf("%d:[%d]=>1000", nFirstNumbers[n], nLast4);
			return true;
		}
	}

	///�P���@�Y��������3�X�ۦP
	for (int n = 0; n<3; n++)
	{
		int nMod = 1000;
		int nLast3 = nFirstNumbers[n] % nMod;
		int nInputLast3 = nNumber % nMod;
		if (nInputLast3 == nLast3)
		{
			printf("%d:[%d]=>200", nFirstNumbers[n], nLast3);
			return true;
		}
	}

	///�P���@�W�[��������3�X�ۦP
	for (int n = 0; n<4; n++)
	{
		int nMod = 1000;
		int nInputLast3 = nNumber % nMod;
		if (nInputLast3 == nExtalNumbers[n])
		{
			printf("%d:[%d]=>200", nExtalNumbers[n], nInputLast3);
			return true;
		}
	}

	printf("�i��!�z�����X[%d]�S������\n", nNumber);
	return true;

}

///�Q�@�Q�O�_�٦���k��N���I���L�{�ΰj��²�u�{���X?
