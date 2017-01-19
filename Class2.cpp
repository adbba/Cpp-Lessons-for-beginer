#include "stdafx.h"
#include "string.h"
#include "ClassIndex.h"
#include <locale.h>

#define OP_ADD  1  //�[�k
#define OP_SUB  2  //��k
#define OP_MUTP 3  //���k
#define OP_DIV  4  //���k

void goClass2(int nExpNumber)
{
	bool blContinue = true;
	int nAns = -1;
	switch (nExpNumber)
	{
		case 1:
			nAns = C2_ex1_functionReturn(10, 1000, OP_DIV); //���ըϥ� OP_ADD,OP_SUB,OP_MUTP,OP_DIV
			printf("[goClass2]�o�쵪��:(%d)\n",nAns);
			break;
		case 2:
			C2_ex2_Pointer1();
			break;
		case 3:
			C2_ex3_Pointer2(100);
			break;
		case 4:
			C2_ex4_Pointer3();
			break;
		case 5:
			C2_ex5_Pointer4();
			break;
		case 6:
			C2_ex6_Pointer5();
			break;
		case 7:
			printLottery();
				break;
		case 8:
			printLottery_Homework();
			break;
		default:
			return;
			break;	
	}
	printf("\n�qclass2�^��D�禡(��Jbye����)...\n");

}
int C2_ex1_functionReturn(int nNumber1, int nNumber2,int nOpSelect)
{
	int nAns = -1;
	switch (nOpSelect)
	{
	case OP_ADD:
		nAns = nNumber1 + nNumber2;
		printf("����[�k(%d): [%d]+[%d]=[%d]\n", nOpSelect, nNumber1, nNumber2, nAns);
		
		break;
	case OP_SUB:
		nAns = nNumber1 - nNumber2;
		printf("�����k(%d): [%d]-[%d]=[%d]\n", nOpSelect, nNumber1, nNumber2, nAns);

		break;
	case OP_MUTP:
		nAns = nNumber1 * nNumber2;
		printf("���歼�k(%d): [%d]*[%d]=[%d]\n", nOpSelect, nNumber1, nNumber2, nAns);

		break;
	case OP_DIV:
		nAns = nNumber1 / nNumber2;
		printf("���氣�k(%d): [%d]/[%d]=[%d]\n", nOpSelect, nNumber1, nNumber2, nAns);

		break;
	}

	return nAns;
}
void C2_ex2_Pointer1()
{
	int nBePointerNumber = 300;
	printf("nBePointerNumber=%d Addr=0x%X\n", nBePointerNumber, &nBePointerNumber);
	int* pnNumber = NULL;
	//printf("*pnNumber=%d\n", *pnNumber); //why?
	printf("pnNumber=0x%X Addr=0x%X\n",  pnNumber, &pnNumber);
	
	pnNumber = &nBePointerNumber;
	printf("��[pnNumber�����Ȥ���]\n");
	printf("*pnNumber=%d\n", *pnNumber); //why?
	printf("pnNumber=0x%X Addr=0x%X\n", pnNumber, &pnNumber);

	/*======================================================================
		�@���ܼ�
		int nNumber = 123;
		nNumber=>�ƭ�
		&nNumber=>�ܼƦb�O���餤����}

		����
		int* pnNumber=&nNumber;
		pnNumber=>�s��[�ܼƦb�O���餤����}]
		&pnNumber => ���Цb�O���餤����}
		*pnNumber => ���X (�s��b pnNumber �� [�ܼƦb�O���餤����}] ��) �ƭ�


		��}       �ܼ�
		0x1DFD2C    300
		0x1DFD20   0x1DFD2C
	
		 pnNumber ���� &nNumber
		*pnNumber ����  nNumber
	===================================================================*/

	*pnNumber = 900;
	printf("��[����pnNumber�O�s��}���ܼƭȤ���]\n");
	printf("nBePointerNumber=%d Addr=0x%X\n", nBePointerNumber, &nBePointerNumber);
	
	printf("*pnNumber=%d\n", *pnNumber); //why?
	printf("pnNumber=0x%X Addr=0x%X\n", pnNumber, &pnNumber);

}


void C2_ex3_Pointer2(int nArraySize)
{
	if (nArraySize < 100)
		nArraySize += 100; //why?

	///�ŧi���Ы��V�@��nArraySize��int�j�p���O����
	int *pnNumAry = new int[nArraySize]; 
	memset(pnNumAry, 0, nArraySize*4); ///��l��

	///�ŧi�@���O����j�p�� 4* nArraySize byte
	int *pnMemory = (int*)malloc(4* nArraySize);
	memset(pnMemory, 0, nArraySize*4);//��l��

	///�ŧi�@�Ӧ�100��int�j�p���}�C
	int  nNumAry[100] = {0}; 

	///�ŧi�@�ӫ��Ы��Vint�}�C nNumAry
	int* pnNumber = nNumAry;

	printf("sizeof(pnNumAry)=%d Addr:0x%X\n", sizeof(pnNumAry), pnNumAry);
	printf("sizeof(nNumAry)=%d �� Addr:0x%X\n", sizeof(nNumAry), nNumAry);
	printf("sizeof(pnNumber)=%d Addr:0x%X\n", sizeof(pnNumber), pnNumber);
	printf("sizeof(pnMemory)=%d Addr:0x%X\n", sizeof(pnMemory), pnMemory);

	/*================================================
		int  nAryNumber[];
		int* paryNumber;
		  paryNumber     ���� nAryNumber 
		*(paryNumber+0)  ���� nAryNumber[0] ���� *(nAryNumber+0)
		*(paryNumber+1)  ���� nAryNumber[1] ���� *(nAryNumber+1)

	=================================================*/

	//�A�U���o��]�w[���_�I]
	for (int i = 0; i < 100; i++) 
	{
		*(pnNumber+i) = i;
		pnNumAry[i] = i;
		pnMemory[i] = i;
	}

	for (int j = 0; j < 100; j++)
	{
		printf("<%d>\n",j);
		printf("[nNumAry]�ƭȰ}�C\n");
		printf("nNumAry[%d]=%d (Addr:0x%X (nNumAry+%d))\n"  , j, nNumAry[j], nNumAry + j, j);
		printf("[pnNumber]���Ы��VnNumAry�ƭȰ}�C\n");
		printf("pnNumber[%d]=%d (Addr:0x%X (pnNumber+%d))\n", j,pnNumber[j],pnNumber + j, j);
		printf("*(pnNumber+%d)[%d]=%d (Addr:0x%X (pnNumber+%d))\n", j, j, *(pnNumber + j), pnNumber + j, j);
		printf("[pnNumAry]���Ыŧi���V�}�C\n");
		printf("pnNumAry[%d]=%d (Addr:0x%X (pnNumAry+%d))\n", j, pnNumAry[j], pnNumAry + j, j);
		printf("*(pnNumAry+%d)[%d]=%d (Addr:0x%X (pnNumAry+%d))\n", j, j, *(pnNumAry + j), pnNumAry + j, j);
		printf("[pnMemory]���Ыŧi���V�O����\n");
		printf("pnMemory[%d]=%d (Addr:0x%X (pnMemory+%d))\n", j, pnMemory[j], pnMemory + j, j);
		printf("*(pnMemory+%d)[%d]=%d (Addr:0x%X (pnMemory+%d))\n", j, j, *(pnMemory + j), pnMemory + j, j);

		
	}
	delete []pnNumAry;
	free(pnMemory);

}

void C2_ex4_Pointer3()
{
	int nNumber1=100;
	int* pnNumber1 = &nNumber1;
	int** ppnNumber1 = &pnNumber1;

	printf("nNumber1=%d Addr=0x%X\n", nNumber1, &nNumber1);
	printf("*pnNumber1=%d pnNumber1=0x%X Addr=0x%X\n", *pnNumber1,pnNumber1, &pnNumber1);
	printf("**ppnNumber1=%d *ppnNumber1=0x%X ppnNumber1=0x%X Addr=0x%X\n", **ppnNumber1, *ppnNumber1, ppnNumber1, &ppnNumber1);

}

void C2_ex5_Pointer4()
{
	int* pNumArry[10]; //�}�C ���C�Ӥ������Oint����
	int(*pArryNum)[10]; //���� ���V�@��int[10]���}�C
	int AryNum[10] = {0};
	for (int i = 0; i < 10; i++)
	{
		*(AryNum + i) = i; ///why?
		pNumArry[i] = (AryNum + i);
	}

	pArryNum = &AryNum;


	for (int j = 0; j < 10; j++)
	{
		printf("====<%d>=====\n",j);
		printf("AryNum[%d]=%d Addr[AryNum+%d]=0x%X Addr(AryNum)=0x%X\n", j, AryNum[j], j, AryNum + j, AryNum);
		printf("*(AryNum+%d)=%d Addr[AryNum+%d]=0x%X\n", j, (*AryNum+j), j, AryNum + j);
		printf("*(pNumArry[%d])=%d pNumArry[%d] =0x%X  Addr=0x%X\n", 
			j, *(pNumArry[j]), j, pNumArry[j], pNumArry+j);
		printf("*pArryNum[%d]=%d pArryNum=0x%X\n",
			j, (*pArryNum)[j], pArryNum);


	}

	//Q: pArryNum+1==??


	/*
	������[�f�Z]������
	��
	()[]�O�Ĥ@�u���v�����X,
	�����X=> x()[] ==> (x<-())<-[]

	��
	��*�O�ĤG�u���v�k���X�C
	�k���X=> **x =>  *->(*->x)

	�b���ܼƫŧi��,�p�P�B�⦡�����t�L�{,������uC�{���y����*()[]���u���v�w�q�C���U�ӽ�Ū�̭I�w�U�����f�Z

	* �ݨ�[]�N��array[] of (�@�Ӱ}�C�̭���...)
	* �ݨ�*�N��pointer to (�@�ӫ��Ы��V...)
	* �ݨ��ܼƫ᭱��()�N��function() returning (�@�Ө禡�^��...)

	�W�z�f�Z�t�X*()[]���u���v,�̧ǧ�X����檺����,�C�ݨ�B��Ÿ��N��o�X�y�f�Z���X�ӡC�]���ܼƪ��N�q�p�U���d��

	char *x; // x: a pointer to char (�@�ӫ��Ы��V....char)
	char x[3]; // x: an array[3] of char (�@�Ӱ}�C�̭���....char)
	char x(); // x: a function() returning char (�@�Ө禡�^��...char)
	char *x[3]; // x: an array[3] of pointer to char (�@�Ӱ}�C�̭���...�@�ӫ��Ы��V....char)
	char (*x)[3]; // x: a pointer to array[3] of char (�@�ӫ��Ы��V...�@�Ӱ}�C�̭���...char)
	char **x; // x: a pointer to pointer to char
	char *x(); // x: a function() returning pointer to char
	char *x()[3]; // x: a function() returning array[3] of pointer to char
	char (*x[])(); // x: an array[] of pointer to function() returning char
	char (*x())(); // x: a function() returning pointer to function() returning char
	char (*(*x)[])(int, int); // x: a pointer to array[] of pointer to function(int,int) returning char

	*/
}

void C2_ex6_Pointer5()
{
	/*
				[0]---->[0][0]='A', [0][1]='B'
	the2DArray
				[1]---->[1][0]=2, [1][1]=4, [1][2]=6, ....
	*/
	char the2DArray[2][10] = { {'A','B'}, {2,4,6,8,10,12,14,16,18,20} };
	char* ptheArray_D0 = the2DArray[0];
	char* ptheArray_D1 = the2DArray[1];
	char* pPointArray[2] = { ptheArray_D0, ptheArray_D1 };
	char** ppPointToPointArray = pPointArray;

	printf("�C�L�}�C the2DArray[2][10]....\n");
	for (int nD1 = 0; nD1 < 2; nD1++)
	{
		for (int nD2 = 0; nD2 < 10; nD2++)
			printf("the2DArray[%d][%d]=%d\n", nD1, nD2, the2DArray[nD1][nD2]);
	}
	printf("�C�L���� ptheArray_D0 �P ptheArray_D1....\n");
	for (int nD1 = 0; nD1 < 2; nD1++)
	{
		for (int nD2 = 0; nD2 < 10; nD2++)
		{
			if (nD1==0)
				printf("ptheArray_D0[%d][%d]=%d (%c)\n", nD1, nD2, *(ptheArray_D0 + nD2), *(ptheArray_D0 + nD2));
			if (nD1 == 1)
				printf("ptheArray_D1[%d][%d]=%d\n", nD1, nD2, *(ptheArray_D1 + nD2));
		}
	}

	printf("�C�L�}�C���� pPointArray....\n");
	for (int nD1 = 0; nD1 < 2; nD1++)
	{
		for (int nD2 = 0; nD2 < 10; nD2++)
		{
			
			printf("pPointArray[%d][%d]=%d\n", nD1, nD2, *(pPointArray[nD1] + nD2));
		}
	}

	printf("�C�L�������� ppPointToPointArray....\n");
	for (int nD1 = 0; nD1 < 2; nD1++)
	{
		for (int nD2 = 0; nD2 < 10; nD2++)
		{

			printf("pPointArray[%d][%d]=%d\n", nD1, nD2, *(*(ppPointToPointArray+nD1) + nD2));
		}
	}

}

void printLottery()
{
	//�O�_�i�H�βΤ@�o�������Ӵ��N?������?

	setlocale(LC_ALL, ""); //�]�w����
	//wchar_t aryLty1051104[2][10] = { { L"��1051104��" }, { 16, 14, 22, 23, 30, 31 } };

	//�n��ܼe�r��(wchar_t)�r��A�e��n��L""�Ӫ��
	wchar_t aryLty1051104[2][10] = { { 0 }, { 0 } };
	memcpy_s(aryLty1051104[0], 10 * 2, L"��1051104��", sizeof(L"��1051104��"));
	aryLty1051104[1][0] = 16;
	aryLty1051104[1][1] = 14;
	aryLty1051104[1][2] = 22;
	aryLty1051104[1][3] = 23;
	aryLty1051104[1][4] = 30;
	aryLty1051104[1][5] = 31;

	wchar_t aryLty1051111[2][10] = { { L"��1051111��" }, { 2, 8, 25, 29, 30, 41 } };
	wchar_t aryLty1051118[2][10] = { { L"��1051118��" }, { 3, 14, 17, 19, 20, 31 } };
	wchar_t aryLty1051125[2][10] = { { L"��1051125��" }, { 18, 20, 22, 27, 31, 35 } };
	wchar_t(*paryAll[4])[2][10]; //�мg�X�ԭz�A�o�O�ƻ�ŧi?
	paryAll[0] = &aryLty1051104;
	paryAll[1] = &aryLty1051111;
	paryAll[2] = &aryLty1051118;
	paryAll[3] = &aryLty1051125;

	for (int i = 0; i < 4; i++)
	{

		printf("\n<%d> [%S]====\n", i, ((*(paryAll[i]))[0]));
		for (int j = 0; j <10; j++)
		{
			int nNubmer = (*(paryAll[i]))[1][j];
			if (nNubmer > 0)
				printf("[%02d]", nNubmer);
		}

	}

}


/*
�@�~:
�NprintLottery()�Ϋ��Ч�g�}�C

*/



