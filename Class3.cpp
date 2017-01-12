#include "stdafx.h"
#include "string.h"
#include "ClassIndex.h"
#include <locale.h>
#include <ctime>
#include<cmath> 

#define _TOSTR(x)			  #x    //�J��#���|�A�Q�i�}
#define  TOSTR(x)			  _TOSTR(x)


/*
#define�w�q�`�ΥB�T�w���禡�H²�Ƶ{���A�W�[�{����[�\Ū��]
*/
#define PRINT_VAR(V)  printf("[��][ %s]==> v(%8d) a(0x%X)\n",TOSTR(V),V,&V);
//#define PRINT_PTR(p)  printf("[��][*%s]==> v(0x%X) a(0x%X)--->*(%d)\n",TOSTR(p),p,&p,*p); //����Ь�NULL�|�X��
#define PRINT_PTR(p)  if(p!=NULL){printf("[��][*%s]==> v(0x%X) a(0x%X)--->*(%d)\n",TOSTR(p),p,&p,*p);}else{printf("[��][*%s]==> NULL !!\n",TOSTR(p));}
#define TAB			  printf("%s",Tab);
#define TABL(x)	      for(int n=0;n<x;n++){printf("%s",Tab);}
char Tab[6] = { 0 };
void goClass3(int nExpNumber)
{
	//for (int n = 0; n < 6; n++)//�ոլ�:�|�o�ͬƻ��?������?
	for (int n = 0; n < 5; n++)
	{
		Tab[n] = 32;
	}

	int nAns = -1;
	switch (nExpNumber)
	{
	case 1:
	{
		/* [C3_ex1_functionWithPoint]=========================================================
			�Ѧ�[����O�ǭ�call by value�B�ǧ}call by address�B�ǰѦ�call by reference]
			http://wp.mlab.tw/?p=176
		*/
		C3_ex1_functionWithPoint();
		break;
	}
	case 2:
	{
		C3_ex2_functionDefaultValue();
		break;
	}
	case 3:
	{
		C3_ex3_ByteOp();
		break;
	}
	case 4:
	{
		C3_ex4_BitOp();
		break;
	}
	case 5:
	{
		class3_Homework();
		
		break;
	}
	default:
		return;
		break;
	}
	printf("\n�qclass3�^��D�禡(��Jbye����)...\n");

}

//===================================================================
//[class3][Ex1]�禡�ǧ}: �ХJ�Ӥ���C���ܼƪ�[��]�P[��}]���ܤ�!!
//===================================================================
void C3_ex1_functionWithPoint()
{
	
	
	printf("================================================================\n");
	printf("[class3][Ex1]�禡�ǧ}: �ХJ�Ӥ���C���ܼƪ�[��]�P[��}]���ܤ�!!\n");
	printf("================================================================\n");
	int nAddr = 200;
	int nNumb = 99; //�Ψӵ����Ы��w����Ƽƭ�
	int*pNumb = &nNumb;
	int nLocl = 300;

	printf("\n�ǤJ���e: \n");
	PRINT_VAR(nAddr);
	PRINT_VAR(nNumb);
	PRINT_PTR(pNumb);
	PRINT_VAR(nLocl);

	//����:�Nif���ק�0��1
	//�[��[�NnAddr�PpNumb���]��
	//==> �ѼƦ]���禡�]�w�Ѽƪ�(�ǰ�)(�ǧ})�A�p��ק�g�J�覡
	if (0)
	{
		printf("\n[�ǤJ]_C3_ex1_functionWithPoint(nAddr(�ǰ�), pNumb(�ǧ}), nLocl(�ǭ�))\n");
		_C3_ex1_functionWithPoint(nAddr, pNumb, nLocl);
	}
	else
	{
	
		printf("\n[�ǤJ]_C3_ex1_functionWithPoint(*pNumb(�ǰ�), &nAddr(�ǧ}), nLocl(�ǭ�))\n");
		_C3_ex1_functionWithPoint(*pNumb, &nAddr, nLocl); 
	}

	printf("\n�ǤJ����: \n");
	PRINT_VAR(nAddr);
	PRINT_VAR(nNumb);
	PRINT_PTR(pNumb);
	PRINT_VAR(nLocl);
}
/*========================================================================================================================
�Ѽ�:
[int& _refVar] : �ǤJ[�ܼƪ���}](�ǰѦ�call by reference, C++ only) == > << �۰� >> ����ܼƥ�����[��}] = >�ǧ}
[int* _addVar]: �ǤJ[��ƫ���](�ǧ}call by address) == > �����O�@��[����ܼ�]��[��}], �ܼƪ���}!�ܼƪ���}!�ܼƪ���}!(�ܭ��n)
[int _varVar]:     �ǤJ[���](�ǭ�call by value) == > �N�O�ܼƥ�����[��]
========================================================================================================================*/
void _C3_ex1_functionWithPoint(int& _refVar, int* _addVar, int _varVar)
{
	//printf("\n�b[C3_ex1_functionWithPoint]���ܤ��e:\n _refVar:[%d:0x%X]\n _addVar:[���V�ƭ�:%d,�x�s��}:0x%X ,���Х�����}: 0x%X]\n _varVar:[%d:0x%X]\n\n",
	//	_refVar, &_refVar, *_addVar, _addVar, &_addVar, _varVar, &_varVar);
	//����W�����g�k...��#define�{���N�j�T[��Ū] �B[����]!!!
	TAB printf("==========================================\n");
	TAB printf("[_C3_ex1_functionWithPoint]�ק�e.... \n");
	TAB PRINT_VAR(_refVar);
	TAB PRINT_PTR(_addVar);
	TAB PRINT_VAR(_varVar);
	
	//�N�U�ǤJ���ѼƧ@�ƭȪ��ܤ� (�`�N�g�k &,*,...)
	printf("\n");
	TAB  printf("�ק�U��....\n");
	TAB  printf(" _refVar(%d)+1000\n",_refVar);
	TAB  printf("*_addVar(%d)+2000\n", *_addVar);
	TAB  printf(" _varVar(%d)+3000\n", _varVar);
	
	 _refVar += 1000;
	*_addVar += 2000;
	 _varVar += 3000;

	printf("\n");
	TAB printf("[_C3_ex1_functionWithPoint]�ק��.... \n");
	TAB PRINT_VAR(_refVar);
	TAB PRINT_PTR(_addVar);
	TAB PRINT_VAR(_varVar);
	TAB printf("==========================================\n");

}


//===================================================================
//[class3][Ex2]�禡 �ǤJ�Ѽƹw�]�� �H�� �^�ǫ���!!
//===================================================================
/*
�禡�ŧi�b�̫�[�W��l��
int* _C3_ex2_functionDefaultValue(int* pValue,int nValue=100);
�p��_C3_ex2_functionDefaultValue�N�u�ݶ�J�Ĥ@�ӰѼ�
�������ĤG�ӰѼ�nValue�Y�O����A�h�H�w�]��100������

�`�N:
��ƹw�]�ȥ�����b�Ѽƪ��̫�
void myfuc(int v1, int v2, int v3=100);		//=>OK
void myfuc(int v1, int v2=50, int v3=100);	//=>OK
void myfuc(int v1, int v2=50, int v3);		//=>���~

*/
void C3_ex2_functionDefaultValue()
{
	printf("================================================================\n");
	printf("[class3][Ex2]�禡 �ǤJ�Ѽƹw�]�� �H�� �^�ǫ���\n");
	TAB printf("�禡�ŧi:\n");
	TABL(2) printf("int* _C3_ex2_functionDefaultValue(int* pValue, int nValue = 100)\n");
	printf("================================================================\n");

	int nNumber = 5;
	int* pNumber = NULL;
	printf("��[Ex2]�Ѽƪ�l:\n");
	PRINT_VAR(nNumber);
	PRINT_PTR(pNumber);
	
	printf("\n================================================================\n");
	printf("��[Ex2]�禡=>�Ĥ@��::(NULL,   )\n");
	PRINT_VAR(nNumber);
	PRINT_PTR(pNumber);
	printf("================================================================\n");
	int* pRetru1 = _C3_ex2_functionDefaultValue(pNumber);
	printf("��[Ex2]�禡=>�Ĥ@���^��::\n");
	PRINT_VAR(nNumber);
	PRINT_PTR(pNumber);
	PRINT_PTR(pRetru1);



	pNumber = &nNumber;
	printf("\n\n================================================================\n");
	printf("��[Ex2]�禡=>�ĤG��:: (pNumber = &nNumber)\n");
	PRINT_VAR(nNumber);
	PRINT_PTR(pNumber);
	printf("================================================================\n");
	int* pRetru2 = _C3_ex2_functionDefaultValue(pNumber);
	printf("��[Ex2]�禡=>�ĤG���^��::\n");
	PRINT_VAR(nNumber);
	PRINT_PTR(pNumber);
	PRINT_PTR(pRetru2);
	//[?]pRetru2 == pNumber?? ��̬O�_�ۦP? ������?

	printf("\n\n================================================================\n");
	printf("��[Ex2]�禡=>�ĤT��::\n");
	PRINT_VAR(nNumber);
	PRINT_PTR(pNumber);
	printf("================================================================\n");
	
	int* pRetru3 = _C3_ex2_functionDefaultValue(pNumber, nNumber);
	printf("��[Ex2]�禡=>�ĤT���^��::\n");
	PRINT_VAR(nNumber);
	PRINT_PTR(pNumber);
	PRINT_PTR(pRetru3);
	//[?]�ҥHC3_ex2_functionDefaultValue�^�Ǫ�[int*]���N�䬰��?
	//[?]�A�^�Y�ݬ�C3_ex1 �ݬݦ�[�ǧ}]

	for (int i = 0; i < 10; i++)
	{
		int* pRetru = _C3_ex2_functionDefaultValue(pNumber, nNumber);
		printf("��[Ex2]�禡=>��[%d]���^��::\n",i+4);
		PRINT_VAR(nNumber);
		PRINT_PTR(pNumber);
		PRINT_PTR(pRetru);
	}

}


/* [C3_ex2_functionDefaultValue]=========================================================
	�Ѽ�:
	[int* pValue]:  �ǤJ���V�ƭȱo����
	[int nValue]: ���Ы��V��[�ƭ�]���[�W����
	�^��:
	[int*]:  �N�ǤJ��(????)�A�^�Ǧ^�h
*/
int* _C3_ex2_functionDefaultValue(int* pValue, int nValue)
{
	int* pValu2 = pValue;
	static int nLoop = 0;
	nLoop++;
	if (pValue == NULL)
	{
		//printf("\n[C3_ex2_functionDefaultValue] pValue��NULL! nValue=%d\n", nValue);
		TABL(2) printf("%d> [C3_ex2_functionDefaultValue] pValue��NULL!\n",nLoop);
		TABL(2) PRINT_VAR(nValue);
		TABL(2) printf("�^��:\n");
		TABL(2) PRINT_PTR(pValue);
		TABL(2) PRINT_PTR(pValu2);
	}
	else
	{
		TABL(2) printf("%d> [C3_ex2_functionDefaultValue]�ק�Ȥ��e:\n", nLoop);
		TABL(2) PRINT_VAR(nValue);
		TABL(2) PRINT_PTR(pValue);
		
		printf("\n");
		TABL(3) printf("�ק��===>[*pValue(%d) += nValue(%d)]\n", *pValue, nValue);
		*pValue += nValue;
		printf("\n");
		TABL(2) printf("%d> [C3_ex2_functionDefaultValue]�ק�Ȥ���:\n", nLoop);
		TABL(2) PRINT_VAR(nValue);
		TABL(2) PRINT_PTR(pValue);
		TABL(2) printf("�^��:\n");
		TABL(2) PRINT_PTR(pValue);
		TABL(2) PRINT_PTR(pValu2);
		//[?] pValue �P pValu2 ��������}?
	}
	return pValue;

}
/*
^: XOR
!: NOT
*/
void C3_ex3_ByteOp()
{
	printf("================================================================\n");
	printf("[class3][Ex3] �줸�ާ@ �P �޿�B��\n");
	printf("================================================================\n");

	int nNum1 = 85;
	int nNum2 = 204;
	int nAns0 = 0;
	char caNum1[33] = { ' ' };
	char caNum2[33] = { ' ' };
	char caAns0[33] = { ' ' };

	_itoa_s(nNum1, caNum1,33, 2);
	_itoa_s(nNum2, caNum2,33, 2);

	printf("\n================================\n");
	printf("AND==>[&]\n");
	printf("================================\n");
	printf("nNum1(%8d): %10s\n", nNum1, caNum1);
	printf("&\n");
	printf("nNum2(%8d): %10s\n", nNum2, caNum2);
	nAns0 = nNum1 & nNum2;
	_itoa_s(nAns0, caAns0,33, 2);
	printf("-------------------------------\n"); 
	printf("nAns0(%8d): %10s\n", nAns0, caAns0);

	printf("\n================================\n");
	printf("OR==>[|]\n");
	printf("================================\n");
	printf("nNum1(%8d): %10s\n", nNum1, caNum1);
	printf("|\n");
	printf("nNum2(%8d): %10s\n", nNum2, caNum2);
	nAns0 = nNum1 | nNum2;
	_itoa_s(nAns0, caAns0, 33, 2);
	printf("-------------------------------\n");
	printf("nAns0(%8d): %10s\n", nAns0, caAns0);

	printf("\n================================\n");
	printf("XOR==>[^] (���P��1)\n");
	printf("================================\n");
	printf("nNum1(%8d): %10s\n", nNum1, caNum1);
	printf("^\n");
	printf("nNum2(%8d): %10s\n", nNum2, caNum2);
	nAns0 = nNum1 ^ nNum2;
	_itoa_s(nAns0, caAns0, 33, 2);
	printf("-------------------------------\n");
	printf("nAns0(%8d): %10s\n", nAns0, caAns0);
	

	printf("\n================================\n");
	printf("����==>[<<] (��2)\n");
	printf("================================\n");
	printf("nNum1(%8d): %10s\n", nNum1, caNum1);
	printf(">>1\n");
	nNum1 = nNum1 << 1;
	_itoa_s(nNum1, caNum1, 33, 2);
	printf("-------------------------------\n");
	printf("nNum1(%8d): %10s\n", nNum1, caNum1);


	printf("\n================================\n");
	printf("�k��==>[>>] (��2)\n");
	printf("================================\n");
	printf("nNum2(%8d): %10s\n", nNum2, caNum2);
	printf(">>1\n");
	nNum2 = nNum2 >> 1;
	_itoa_s(nNum2, caNum2, 33, 2);
	printf("-------------------------------\n");
	printf("nNum2(%8d): %10s\n", nNum2, caNum2);

}


void C3_ex4_BitOp()
{
	printf("================================================================\n");
	printf("[class3][Ex4] �������i���줸�ޡ�����\n");
	printf("[!]�ȥ����x�줸�ഫ�A�ާ@�A�H�Ϋ���[���A]�P[�p��]!!!\n");
	printf("================================================================\n");

	int nAarryRandNum[3] = { 0 }; //�x�s�ü�
	int* pAarryRandNum = nAarryRandNum; //���VnAarryRandNum�Ӿާ@(int����)
	char bMask = 0x01; //�B�n�A�ΨӨ��o1��bit�����

	//���դ����H�[��üƥH�Φ줸���ާ@�ܰ�
	for (int i = 0; i < 5; i++)
	{
		printf("======\n============[���Ͷü�(%d��)]==========\n======\n", i);
		char caAarryRandNumBinary[50 * 3] = { 0 }; //�����ƭȪ�2�i����
		int nRandNumber = 0;
		int nRandRang = pow(2, 31) - 1; //�ü�

		//---------------------
		//�����ü�
		nRandNumber = GetRandomNumber(nRandRang);
		nAarryRandNum[0] = nRandNumber;

		nRandNumber = GetRandomNumber(nRandRang);
		nAarryRandNum[1] = nRandNumber;

		nRandNumber = GetRandomNumber(nRandRang);
		nAarryRandNum[2] = nRandNumber;

		//---------------------
		//�N[�ü�]�ഫ���G�i��(binary)��ܡA��K����H�έp��
		char* pAByte_Source = (char*)nAarryRandNum;			//���V�üƭȨӷ����H[char*]���V[int�}�C] !!! why???
		char* pAByte_Target = (char*)caAarryRandNumBinary;  //���V�n[�g�J]���G�i���ܪ�[�r��buffer]
		
		for (int nIDinInt = 0; nIDinInt < 4*3; nIDinInt++) //4*3??? why??
		{
			char caBinaryStringTemp[40] = { 0 }; ///�x�s�Ȯ��ഫ�r��

			//��K�\Ū�C4��byte==>����!!
			if (nIDinInt>0 && nIDinInt % 4 == 0)
			{
				pAByte_Target--;
				sprintf_s(pAByte_Target, 4, "\n\0");//�W�[����Ÿ� (���@�w�n�[�W"\0"�r�굲���A�H��Kstrlen()�ӭp��[�r�����])
				pAByte_Target = caAarryRandNumBinary + strlen(caAarryRandNumBinary); //�NpAByte_Target���V[�U�@��]�g�J��buffer��m
			}
			//printf("���ഫ�ƭ�: 0x%X\n", (*pAByte_Source & 0x00FF)); //���}����H���Ҹ�ƬO�_���T

			_itoa_s((*pAByte_Source & 0x00FF), caBinaryStringTemp, 33, 2); //�C���ഫ1��byte���ƭȬ��G�i����,why?���U�軡��
			/*
			�i���ഫ�ޥ�:

				10�i��(1085550060) 
				=16�줸���=> 0x40B42DEC 
				=2�i����=>  1000000101101000010110111101100

				���===>
						    0x    40       B4       2D       EC
				=2�i����=>  01000000-10110100-00101101-11101100 //byte���}(8-bit)

							0x  4     0   B    4   2     D   E     C
				=2�i����=>  0100 0000-1011 0100-0010 1101-1110 1100 //�C4-bit���}
				
				���C4-bit�N�O��ܤ@��8�i�[��]��

			*/

			/*
			0x0c =>"1100"
			                       0    1    2     3   4    5    6    7
			caBinaryStringTemp[]=[0x31 0x31 0x30 0x30 0x00 0xfe 0xfe 0xfe]
			                       '1'  '1'  '0'  '0'  '\0'  ?    ?    ?
			���B 0x31=>'1' 0x30=>'0'
			�ڭ̧Ʊ檺��ܤ�k�৹�����8-bit�Ҧ� => "0000 11000"
			�]���n�NcaBinaryStringTemp�줸��m���վ�==>�V��� 
			�r�����4 ("1100"==>strlen(caBinaryStringTemp)=4) 
			�]���n�V���8-4�Ӯt�Z(nOffset)
			
			�B�n�q��[3]��}�l�h��(����-1==>(strlen(caBinaryStringTemp) - 1)==> 4-1)
			�_�h�|�\���e�������(�Ҧp[0]-->[3]�h�쥻[3]����ƨӤ��ηh�N�Q[0]�\���F)

			                       0    1    2    3    4    5    6    7     8
			caBinaryStringTemp[]=[0x30 0x30 0x30 0x30 0x31 0x31 0x30 0x30  0x00 ] //[8]�����Ÿ��H��K�p��r�����(strlen())
								  '0'  '0'   '0'  '0'   '1'  '1'  '0'  '0'  '\0' 
			�h����e���쥻��ƪ���m(nOffset)�ݭn��W0x30=>'0'

			*/
			if (strlen(caBinaryStringTemp) < 8)
			{
				int nIndex = 0;
				int nOffset = 8 - strlen(caBinaryStringTemp); //�V������t�Z
				///��ƦV��[��]==>�h��
				for (nIndex = (strlen(caBinaryStringTemp) - 1); nIndex >=0; nIndex--)
				{
					caBinaryStringTemp[nIndex + nOffset] = caBinaryStringTemp[nIndex]; 
				}
				///�e��쥻��ƪ���m��J'0'
				for (nIndex = 0; nIndex < nOffset; nIndex++)
				{
					caBinaryStringTemp[nIndex] = 0x30; //'0'
				}
				caBinaryStringTemp[8] = 0; //'\0' ��J�r�굲���Ÿ�
			}
			//printf("�ק��2�i����: %s\n", caBinaryStringTemp); ///���}�i�H�����ഫ�᪺���G
			sprintf_s(pAByte_Target, 9, "%s", caBinaryStringTemp); //�N��ƶ�JpAByte_Target�A�Y�̲���ܦr�ꪺbuffer,caAarryRandNumBinary[]
			
			pAByte_Target = caAarryRandNumBinary + strlen(caAarryRandNumBinary); ///�NpAByte_Target���V[�U�@��]�g�J��buffer��m
			
			///�Cbyte�W�[���j�u'-'��K�\Ū
			if (nIDinInt<4*3-1)
				sprintf_s(pAByte_Target, 3, "-\0");//�W�[���j�u
			pAByte_Target = caAarryRandNumBinary + strlen(caAarryRandNumBinary); ///�NpAByte_Target���V[�U�@��]�g�J��buffer��m
			pAByte_Source++;
		}
		
		printf("�H���ƭ�:\n[%0.10d  (0x%0.8X)]\n[%0.10d  (0x%0.8X)]\n[%0.10d  (0x%0.8X)]\n", nAarryRandNum[0], nAarryRandNum[0], nAarryRandNum[1], nAarryRandNum[1], nAarryRandNum[2], nAarryRandNum[2]);
		printf("�H���ƭ�(2�i��)==>\n%s\n",caAarryRandNumBinary);


		///�̷ӤT���H���ƭȱo�̤pbit 0��1�@�r����
		/*
			���F�üơA�H�����C�ӶüƳ̫�(�C)bit��@���޷�@��ܺX��
			10�i��(1085550060)
			=16�줸���=> 0x40B42DEC
			=2�i����=>  100000010110100001011011110110[0]
			=�O������=> 0x30 0x30 0x31 0x31 0x30.....(��V�ۤ�!!)
			              ^^^^
			caBinaryStringTemp[]=[0x30 0x30 0x31 0x31 0x30 ... ] �P�O�����ܬۦP
			                     ^^^^^
		*/
		char caWho[30] = { 0 };
		sprintf_s(caWho, "[%s]", ((*pAarryRandNum & bMask) == 0) ? ("Jimmy(0)") : ("Kai(1)"));
		char caWhere[30] = { 0 };
		sprintf_s(caWhere, "[%s]", ((*(pAarryRandNum+1) & bMask) == 0) ? ("Home(0)") : ("Park(1)"));
		char caDoing[30] = { 0 };
		sprintf_s(caDoing, "[%s]", ((*(pAarryRandNum+2) & bMask) == 0) ? ("Playing(0)") : ("Sleeping(1)"));
		printf("���ͥy�l==> %s at %s to %s.\n\n", caWho, caWhere, caDoing);
		///�ոլ�:�p�G�n�令���̫��[3]��bit�n����? (����:bMask)



		//�̷ӤT���H���ƭȧCbyte�B�̧C[4-bit]��@���B�Ʀr
		char caLuckNumber[3] = { 0 };
		memcpy(caLuckNumber, pAarryRandNum, 1);
		memcpy(caLuckNumber+1, (pAarryRandNum+1), 1);
		memcpy(caLuckNumber + 2, (pAarryRandNum + 2), 1);
		printf("[�C4-bit]�ƭ�:[%8d][%8d][%8d]\n", caLuckNumber[0] & 0xF, caLuckNumber[1] & 0xF, caLuckNumber[2] & 0xF);


		//�̷ӤT���H���ƭ�[�ĤG�C]byte�զX���@��int(4)
		int nBigNumber = 0;
		char* pDataBuffer = (char*)nAarryRandNum;
		char* pBigNumber = (char*)&nBigNumber; //��������char�h��int ������
		memcpy(pBigNumber, pDataBuffer + 1, 1);		///??? +1
		memcpy(pBigNumber + 1, pDataBuffer + 5, 1);	///??? +5
		memcpy(pBigNumber + 2, pDataBuffer + 9, 1); ///??? +9
		char _caBigNumber[33] = { 0 };
		_itoa_s(nBigNumber, _caBigNumber, 33, 2);
		printf("\n[�ĤG�C]byte�զX�ƭ�:%d(0x%0.8X) (%s)\n\n", nBigNumber, nBigNumber, _caBigNumber);



	}
}


int GetRandomNumber(int rangeMax,bool blZero)
{
	int randomNumber1 = 0;
	int randomNumber2 = 0;
	int randomNumber3 = 0;
	SYSTEMTIME stimeptr;
	GetLocalTime(&stimeptr);
	int nRetRandNumber = 0;
	while (randomNumber1 == 0)
	{
		srand((unsigned int)time(NULL) + stimeptr.wMilliseconds + rand() % rangeMax);
		randomNumber1 = rand() % (4);
	}
	GetLocalTime(&stimeptr);
	srand((unsigned int)time(NULL) + stimeptr.wMilliseconds + rand() % rangeMax);
	randomNumber2 = rand() ;
	GetLocalTime(&stimeptr);
	srand((unsigned int)time(NULL) + stimeptr.wMilliseconds + rand() % rangeMax);
	randomNumber3 = rand() ;

	

	if (rangeMax < 0)
		nRetRandNumber =(randomNumber1*randomNumber2*randomNumber3);
	else
		nRetRandNumber = ((randomNumber1*randomNumber2*randomNumber3) % (rangeMax));
	if (nRetRandNumber == 0 && blZero == false)
	{
		return GetRandomNumber(rangeMax, blZero);
	}
	else
		return nRetRandNumber;
};


//=============================================================================
//=============================================================================
/*[Class3] [Homework]�ѽX*/
//=============================================================================
//=============================================================================
/*
	�{�����ͤ@�q�[�K�᪺��ơA�бN��ƸѱK�C�L�X��Ƥ��e(���w���r��)

	1. ��encryptData()�T�w���ͤ@�][�H���[�K]600bytes����ƫʥ]
	2. �иg�ѫʥ]�榡�A�N��600bytes����ƫʥ]�ѽX�A�٭�䤤�]�t����Ʀr��
	------------------
	�N����Ĥ@�ӽ������{��:
	a.�Х��@�߬����ʥ]���s�@�覡(�@��!�@��!�@��!)
	b.�z�ѫʥ]�榡����A�b�ۤ�[���]�p���٭�ʥ]���(���ᶶ�ǫܭ��n!!)
	c.�ѩ�ʥ]���e�H�����͡A�Цh����X���A���Ҧۤv����ƬO���T(�D�B��n���n�Ѷ}!)

	[�[�K����]
	https://goo.gl/UKrpwi

	byteA         XOR theKeyA = byteA_Encrypt //�H�_��theKeyA��byteA�@XOR�ұo�ƭ� �Y�O[�[�K���(byteA_Encrypt)]
	byteA_Encrypt XOR theKeyA = byteA         //�H�_��theKeyA��byteA_Encrypt�@XOR�ұo�ƭ� �Y�O[�ѱK�٭���(byteA)]



*/


///�N��J����ƨ̷�byte����찵XOR���ާ@
/*�å�pEncryptDataOut��^
char caKey ��J�n��XOR�� �_��
char* pdata ��l����ơA�Hchar*�Φ���J 
int nSizeByte ��ƪ���
char* pEncryptDataOut �[�K�L������x�s��buffer
*/
bool xorData(char caKey, char* pdata, int nSizeByte, char* pEncryptDataOut)
{
	char _cakey = caKey;
	//��J��Ƭ�NULL�A�Ϊ��פ����`(<=0)�άO�S���]�w��Xbuffer�A
	//=>�h���B�z�^��NULL
	if (pdata == NULL || nSizeByte <= 0 || pEncryptDataOut == NULL)
	{
		return false; 
	}
	char* pDataPos = pdata;			  //���V��l��ơA�H���o�ثe�ާ@��l��Ʀ�}
	char* pDataOut = pEncryptDataOut; //���V��Xbuffer,�H���o�ثe�ާ@�g�J���G��}

	//�N�Hbyte�����A�B�z�[�K�A�üg�J��X���
	for (int n = 0; n < nSizeByte; n++)
	{
		char theCode = (*pDataPos & 0x00FF) ^ _cakey;
		memcpy(pDataOut, &theCode, 1);
		pDataPos++;
		pDataOut++;
	}

	pDataPos = NULL;
	pDataOut = NULL;
	return true;
}


/*
�ʥ]�榡:

   caKeyUseage(1)                  caTheKey_DataStartPos(1)			caTheKey_DataEncrypt(1)
		^									 ^								^                    
|----------------|----------------|----------------|----------------|----------------|-------.-------.-------.-------.-------.-------.-------.--------|-----------
					 v									 v													v     
			caTheKey_DataLenth(1)		      caTheKey_Key4DEncry(1)								nDataStartPos(4)


-------------|-------.-------.-------.-------.-------.-------.-------.--------|--------   .....  ----------|-----
										v
								    nDataLen(4)										caDataEncrypt(nDataLen)
�ʥ]:
byte0 : caKeyUseage => [�[�K�W�h]���O�_�n�ϥΥ[�K? (1 byte)
		 �u���w���̥�3 bit�����O�_�n��  caTheKey_DataLenth, caTheKey_DataStartPos,caTheKey_Key4DEncry
		 �Ҧp:
			caKeyUseage=0xB9 =>(1011 1001)=>���̥��T��(001)=>�R�W(cba)
			(a)=>��'1'�h=> �ϥ�caTheKey_DataLenth 
			(b)=>��'1'�h=> �ϥ�caTheKey_DataStartPos 
			(b)=>��'1'�h=> �ϥ�caTheKey_Key4DEncry 

byte1 : caTheKey_DataLenth		=> �[�K[��ƪ���]���_�͡A��caKeyUseage�M�w�O�_�ϥ�(1 byte)
byte2 : caTheKey_DataStartPos	=> �[�K[��ư_�l��m]���_�͡A��caKeyUseage�M�w�O�_�ϥ�(1 byte)
byte3 : caTheKey_Key4DEncry		=> �[�K[��ƥ[�K�_��]���_�͡A��caKeyUseage�M�w�O�_�ϥ�(1 byte)
byte4 : caTheKey_DataEncrypt    => �[�K[���]���_�� �@�w�ϥ�(1 byte)�A�YcaKeyUseage�]�w��1�A�h��caTheKey_Key4DEncry�[�K

byte5~8: nDataStartPos			=> ��ư_�l��m�A�����ĴX��byte����ư_�l��m�A��int�e��4 byte
								  �A�YcaKeyUseage�]�w��1�A�h��caTheKey_DataStartPos�[�K
byte([��ư_�l��m(nDataStartPos)] �e��4��byte) : nDataLen  => ��ƪ���,�����[��ư_�l��m]�e��4��byte�A��int�e��4 byte
								�YcaKeyUseage�]�w��1�A�h��caTheKey_DataLenth�[�K
byte([��ư_�l��m(nDataStartPos)]) : caDataEncrypt, ��ƥ����A��caTheKey_DataEncrypt�[�K

������[���� �W�h]������
[�ʥ]���]��[�r��] �B�r�ꥲ���p��256 bytes
[�[�K�W�h]�H��[�[�K�_��x4] =>���H�����ͤ�1-byte���!�C�������P!
[��ư_�l��m]			   =>���H�����ͤ�4-byte���!�C�������P!
                             ��d��N�b21 ~ (600 - nDataLen)����
							 ���N�b�ʥ]�_�l��byte5~8
[�ʥ]���]�N�H���\��b�ʥ]��
[��ƪ���]���N���[�ʥ]���]���e��4byte
*/

//�N��J�����(�r�꭭�w)�A�@���[�K�ʥ]
//�åB�ѳ]�w����Xbuffer(pDataOut)�^�ǵ��G
bool encryptData(char* pData, char* pDataOut)
{

	//��J�榡�����A���B�z
	if (pData == NULL || strlen(pData) <= 0 || strlen(pData)>256)
		return NULL;

	char caOutputData[600] = { 0 };

	//�קK�ʥ]���e�ө���A��ƥ���J�H����
	for (int i = 0; i < 600; i++)
	{
		caOutputData[i] = (char)GetRandomNumber(255 - (i % 100), false) & 0x000000FF;
		if (i % 100 == 0)
			Sleep(1);
		caOutputData[i] &= 0x000000FF;
	}

	///�����_��
	char caTheKey_DataLenth = (char)GetRandomNumber(255, false) & 0x000000FF;
	Sleep(1);
	char caTheKey_DataStartPos = (char)GetRandomNumber(255, false) & 0x000000FF;
	Sleep(1);
	char caTheKey_Key4DEncry = (char)GetRandomNumber(255, false) & 0x000000FF;
	Sleep(1);
	char caTheKey_DataEncrypt = (char)GetRandomNumber(255, false) & 0x000000FF;
	Sleep(1);
	caTheKey_DataLenth &= 0x000000FF;
	caTheKey_DataStartPos &= 0x000000FF;
	caTheKey_Key4DEncry &= 0x000000FF;
	caTheKey_DataEncrypt &= 0x000000FF;
	//printf("[Enc]Key: D.Len=0x%X S.Pos=0x%X K.Ecry=0x%X Data=0x%X \n", caTheKey_DataLenth, caTheKey_DataStartPos, caTheKey_Key4DEncry, caTheKey_DataEncrypt);


	//����[�[�K�W�h]
	char caKeyUseage = (char)GetRandomNumber(255, false) & 0x000000FF;
	bool blUseKey_DataLenth = ((caKeyUseage & 0x01) == 0) ? false : true;
	bool blUseKey_DataStartPos = ((caKeyUseage & 0x02) == 0) ? false : true;
	bool blUseKey_Key4DEncry = ((caKeyUseage & 0x04) == 0) ? false : true;
	//printf("[Enc]blKey: D.Len=%d S.Pos=%d K.Ecry=%d\n", blUseKey_DataLenth, blUseKey_DataStartPos, blUseKey_Key4DEncry);

	//��ƪ���
	int nDataLen = strlen(pData) + 1; //why? +1
	//��ư_�l��m
	int nDataStartPos = GetRandomNumber(600 - nDataLen);
	while (nDataStartPos < 20)
	{
		nDataStartPos = GetRandomNumber(600 - nDataLen);
	}
	//�[�K���
	char* caDataEncrypt = new char[nDataLen];
	memset(caDataEncrypt, 0, nDataLen);
	xorData(caTheKey_DataEncrypt, pData, nDataLen, caDataEncrypt);

	memcpy_s(caOutputData, 600, &caKeyUseage, 1);
	memcpy_s(caOutputData + nDataStartPos, 600, caDataEncrypt, nDataLen); ///�N��ƽƻs��caOutputData


	//�[�K=>��ƪ���
	int nDataLenEncrypt = 0;
	if (blUseKey_DataLenth == true)
		xorData(caTheKey_DataLenth, (char*)&nDataLen, 4, (char*)&nDataLenEncrypt);
	else
		nDataLenEncrypt = nDataLen;

	memcpy_s(caOutputData + nDataStartPos - 4, 600, &nDataLenEncrypt, 4);

	//�[�K=>�_�l��m
	int nDataStartPosEncrypt = 0;
	if (blUseKey_DataStartPos == true)
		xorData(caTheKey_DataStartPos, (char*)&nDataStartPos, 4, (char*)&nDataStartPosEncrypt);
	else
		nDataStartPosEncrypt = nDataStartPos;



	//�[�K=>��ƥ[�K�_��
	char caTheKey_DataEncrypt_Encrypt = 0;
	if (blUseKey_Key4DEncry == true)
		xorData(caTheKey_Key4DEncry, &caTheKey_DataEncrypt, 1, &caTheKey_DataEncrypt_Encrypt);
	else
		caTheKey_DataEncrypt_Encrypt = caTheKey_DataEncrypt;

	memcpy_s(caOutputData + 1, 600, &caTheKey_DataLenth, 1);
	memcpy_s(caOutputData + 2, 600, &caTheKey_DataStartPos, 1);
	memcpy_s(caOutputData + 3, 600, &caTheKey_Key4DEncry, 1);
	memcpy_s(caOutputData + 4, 600, &caTheKey_DataEncrypt_Encrypt, 1);
	memcpy_s(caOutputData + 5, 600, &nDataStartPosEncrypt, 4);


	///�B�z�o�ͤ��i�w�����ƥ�(���쵥)
	try
	{
		memcpy_s(pDataOut, 600, caOutputData, 600);
	}
	catch (...)
	{
		pDataOut = NULL;
		return false;
	}
	return true;

}

void class3_Homework()
{
	printf("================================================================\n");
	printf("[class3][Homework] ��ƸѽX\n");
	printf("================================================================\n");
	for (int i = 0; i < 5; i++)
	{
		printf("������[��ƸѽX][%0.2d]==================\n", i + 1);
		char caMyDATA[] = { "Jimmy  is good!\n���ιB��l�`�@���󬰽������[�K�t��k���զ������C���䥻���ӻ��A�p�G�ϥΤ��_���ƪ����_�A�Q���W�v���R�N�i�H�}�ѳo��²�檺���αK�X�C\0" };
		printf("��J�r�ꬰ:%s\n����:%d byte\n", caMyDATA, strlen(caMyDATA));

		char caEncryptData[600] = { 0 };
		encryptData(caMyDATA, caEncryptData);

		/*
			 �ϥ�caEncryptData�ӸѽX�A�٭���!
		*/
		

	}
}
