#define _CRT_SECURE_NO_WARNINGS

// author��AaRong

#include<stdio.h>
#include<string.h>
void Crypto_system()
{
	char encrypt[27] = "DESTINYABCFGHJKLMOPQRUVWXZ"; // ���ļ� 
	char ciphertext[100]; // �������� 
	int index[100]; // ��¼���ĵ� asciiֵ 
	int pos; // ��λ���Ķ�Ӧ���ļ���asciiֵ 
	int i = 0, f, n;

	gets(ciphertext);
	n = strlen(ciphertext);
	for (int j = 0; j < n; j++) //���Ƿ����� 
	{
		if (('Z' < ciphertext[j] && ciphertext[j] < 'A') || ('z' < ciphertext[j] && ciphertext[j] < 'a'))
		{
			printf("error! please input right ciphertext!\n");
			break;
		}
		else //ת��Ϊԭ�ַ� 
		{
			while (ciphertext[i] != '\0')
			{
				if (ciphertext[i] == ' ')
				{
					printf(" ");
					i++;
				}
				else
				{
					if ('a' <= ciphertext[i] && ciphertext[i] <= 'z') // ����ΪСд 
					{
						ciphertext[i] = ciphertext[i] - 32;
						index[i] = ciphertext[i];
						for (pos = 0;; pos++)
						{
							if (index[i] == encrypt[pos])
								break;
						}
						f = pos + 65;
						printf("%c", f);
					}
					else if ('A' <= ciphertext[i] && ciphertext[i] <= 'Z') // ����Ϊ��д 
					{
						index[i] = ciphertext[i];
						for (pos = 0;; pos++)
						{
							if (index[i] == encrypt[pos])
								break;
						}
						f = pos + 65;
						printf("%c", f);
					}
					i++;
				}
			}
		}
	}

}

int main() {
	Crypto_system();
}
