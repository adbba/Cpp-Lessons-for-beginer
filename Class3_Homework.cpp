#include "stdafx.h"
#include "string.h"
#include "ClassIndex.h"
#include <locale.h>
#include <ctime>
#include<cmath> 

///��ƸѽX
void decryptData(char* pEncryptDataData, char* ptheData)
{
	printf("\n�ʥ]�ѽX------------------------------\n");
	//�����X[�[�K�W�h]
	char caKeyUseage = 0;
	memcpy_s(&caKeyUseage, 1, pEncryptDataData, 1);
	bool blUseKey_DataLenth = ((caKeyUseage & 0x01) == 0) ? false : true;
	bool blUseKey_DataStartPos = ((caKeyUseage & 0x02) == 0) ? false : true;
	bool blUseKey_Key4DEncry = ((caKeyUseage & 0x04) == 0) ? false : true;

	//���X�_��x4
	char caTheKey_DataLenth = 0;
	memcpy_s(&caTheKey_DataLenth, 1, pEncryptDataData+1, 1);
	char caTheKey_DataStartPos = 0;
	memcpy_s(&caTheKey_DataStartPos, 1, pEncryptDataData + 2, 1);
	char caTheKey_Key4DEncry = 0;
	memcpy_s(&caTheKey_Key4DEncry, 1, pEncryptDataData + 3, 1);
	char caTheKey_DataEncrypt = 0;
	memcpy_s(&caTheKey_DataEncrypt, 1, pEncryptDataData + 4, 1);
	
	char caTheKey_DataEncrypt_decode = 0;
	if (blUseKey_Key4DEncry == true)
		xorData(caTheKey_Key4DEncry, &caTheKey_DataEncrypt,1, &caTheKey_DataEncrypt_decode);
	else
		caTheKey_DataEncrypt_decode = caTheKey_DataEncrypt;


	printf("[�[�K�_��]--------\n��ƪ���Key=0x%X \n��ư_�lKey=0x%X \n��ƥ[�K�_��=0x%X \n��ƥ[�K=0x%X \n", caTheKey_DataLenth, caTheKey_DataStartPos, caTheKey_Key4DEncry, caTheKey_DataEncrypt_decode);
	char caKeyUsageBinary[33] = { 0 };
	_itoa(caKeyUseage, caKeyUsageBinary, 2);
	printf("[�[�K�W�h] 0x%X (%s)--------\n��ƪ���=%d \n��ư_�l=%d \n��ƥ[�K�_��=%d\n", caKeyUseage, caKeyUsageBinary,blUseKey_DataLenth, blUseKey_DataStartPos, blUseKey_Key4DEncry);
	int nDataStartPos = 0;
	
	memcpy_s(&nDataStartPos, 4, pEncryptDataData + 5, 4);
	int nDataStartPos_Decode = 0;
	if (blUseKey_DataStartPos == true)
		xorData(caTheKey_DataStartPos, (char*)&nDataStartPos, 4, (char*)&nDataStartPos_Decode);
	else
		nDataStartPos_Decode = nDataStartPos;

	int nDataLenth = 0;
	memcpy_s(&nDataLenth, 4, pEncryptDataData + nDataStartPos_Decode - 4, 4);
	int nDataLenth_Decode = 0;
	if (blUseKey_DataLenth == true)
		xorData(caTheKey_DataLenth, (char*)&nDataLenth, 4, (char*)&nDataLenth_Decode);
	else
		nDataLenth_Decode = nDataLenth;

	char* pDataDecode = new char[nDataLenth_Decode];
	memset(pDataDecode, 0, nDataLenth_Decode);
	memcpy_s(pDataDecode, nDataLenth_Decode, pEncryptDataData + nDataStartPos_Decode , nDataLenth_Decode);

	char* pDataDecode_decode = new char[nDataLenth_Decode+1];
	memset(pDataDecode_decode, 0, nDataLenth_Decode);

	xorData(caTheKey_DataEncrypt_decode, pDataDecode, nDataLenth_Decode, pDataDecode_decode);

	printf("�٭���------\n[%s]\n����: %d\n\n\n", pDataDecode_decode, nDataLenth_Decode);
	ptheData = pDataDecode;

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

		char caDecodeData[600] = { 0 };
		decryptData(caEncryptData, caDecodeData); //�ЧV�O

	}
}