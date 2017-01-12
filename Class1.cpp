#include "stdafx.h"
#include "ClassIndex.h"


void goClass1(int nExpNumber)
{
	bool blContinue = true;

	switch (nExpNumber)
	{
	case 1:
		C1_ex1_testPrint(); //�d�Ҥ@: �C�L
		break;
	case 2:
		C1_ex2_forloop();
		break;
	case 3:
		C1_ex3_while(123);
		break;
	case 4:
		C1_ex4_switch();
		break;
	case 5:
		///���а���I���禡����blContinue��false
		while (blContinue == true)
		{
			blContinue = class1_homework();
		}
		printf("���}�I���禡�C\n");
		
		break;
	default:
		return;
		break;
	}
	printf("\n�qclass1 �^��D�禡(��Jbye����)...\n");

}


void C1_ex1_testPrint()
{
	/*
	�d�Ҥ@: �C�L
	�ؼ�:
	- �F�Ѹ�ƫ��A: �㦳�j�p�A�O����t�m
	- �F�Ѧp��C�L���G�A�{�����n��debug������q
	�ѦҸ��:
	��ƫ��A(DataType)�j�p: https://msdn.microsoft.com/en-us/library/s3f49ktz(v=vs.80).aspx
	�C�L(printf)�榡: http://www.cplusplus.com/reference/cstdio/printf/


	*/
	printf("��[testPrint()]============\n\n");
	printf("��=====[char]============\n");
	char caString[20] = { "jimmy is good!" };
	printf("�r��:%s\n", caString);
	printf("��r:%c\n", caString[0]);
	//printf("%s\n",caString[0]); //why?
	printf("�j�p:%d\n", sizeof(caString));
	printf("��}:0x%x\n", caString);
	printf("��}:0x%X\n", caString);
	printf("��=====[wchar_t]============\n");
	wchar_t szString[20] = { L"jimmy is good!" };
	printf("�r��:%S\n", szString);
	printf("��r:%C\n", szString[0]);
	printf("��r:%c\n", szString[0]);
	printf("�j�p:%d\n", sizeof(szString));
	printf("��}:0x%X\n", szString);

	printf("��=====[int]============\n");
	int nNumber = 123;
	printf("�ƭ�:%d\n", nNumber);
	printf("�j�p:%d\n", sizeof(nNumber));
	printf("�ƭ�:0x%X\n", nNumber);
	printf("��}:0x%X\n", &nNumber);

	printf("��=====[short]============\n");
	short sNumber = 123;
	printf("�ƭ�:%d\n", sNumber);
	printf("�j�p:%d\n", sizeof(sNumber));
	printf("�ƭ�:0x%X\n", sNumber);
	printf("��}:0x%X\n", &sNumber);

	printf("��=====[long]============\n");
	long lNumber = 123;
	printf("�ƭ�:%d\n", lNumber);
	printf("�j�p:%d\n", sizeof(lNumber));
	printf("�ƭ�:0x%X\n", lNumber);
	printf("��}:0x%X\n", &lNumber);

	printf("��=====[float]============\n");
	float fNumber = 123.123;
	printf("�ƭ�:%f\n", fNumber);
	printf("�j�p:%d\n", sizeof(fNumber));
	printf("�ƭ�:0x%X\n", fNumber);
	printf("��}:0x%X\n", &fNumber);

	printf("��=====[bool]============\n");
	bool blFlagTrue = false;
	printf("�ƭ�:%d\n", blFlagTrue);
	printf("�j�p:%d\n", sizeof(blFlagTrue));
	printf("�ƭ�:0x%X\n", blFlagTrue);
	printf("��}:0x%X\n", &blFlagTrue);

	printf("��=====[bool]============\n");
	bool blFlagFalse = false;
	printf("�ƭ�:%d\n", blFlagFalse);
	printf("�j�p:%d\n", sizeof(blFlagFalse));
	printf("��}:0x%X\n", &blFlagFalse);


	return;
}

void C1_ex2_forloop()
{
	int nLoop = 0;
	//(for(�_�l���A;  �פ����  ; �C������))
	for (nLoop = 0; nLoop<100; nLoop++)
		//for(nLoop=0;;nLoop++) //�S��[�פ����]??
	{
		if (nLoop % 2 == 0)//���H2�l�Ƭ�0
			printf("nLoop: %d \n", nLoop);
		if (nLoop>1000)
			break;
	}
}

void C1_ex3_while(int nMaxNumber)
{
	int nWhileLoop = 0;
	while (nWhileLoop<nMaxNumber)
	{
		if (nWhileLoop % 2 == 0)//���H2�l�Ƭ�0
			printf("nWhileLoop: %d \n", nWhileLoop);
		if (nWhileLoop>1000)
			break;
		nWhileLoop++;
	}

}


void C1_ex4_switch()
{
	int nArray[100] = { 0 };
	char caName[][123] = { "Jimmy", "Dog", "Jazzdog" };
	for (int i = 0; i<100; i++)
	{
		nArray[i] = i;
	}
	for (int i = 0; i<100; i++)
	{
		int nResult = nArray[i] % 3;
		switch (nResult)
		{
		case 0:
			printf("%s : %d\n", caName[nResult], nArray[i]);
			break;
		case 1:
			printf("%s : %d\n", caName[nResult], nArray[i]);
			break;
		case 2:
			printf("%s : %d\n", caName[nResult], nArray[i]);
			break;
		default:
			printf("%s : %d\n", caName[nResult], nArray[i]);
			break;
		}
	}
}

/*
�]�p�o���I���\��
http://invoice.etax.nat.gov.tw/

1. �w�]�������X
2. ��J8�ӼƦr
��X���G �����H�Ϊ��B

*/

