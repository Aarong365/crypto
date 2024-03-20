#define _CRT_SECURE_NO_WARNINGS

// author：AaRong

#include<stdio.h>
#include<string.h>
void Crypto_system()
{
	char encrypt[27] = "DESTINYABCFGHJKLMOPQRUVWXZ"; // 密文集 
	char ciphertext[100]; // 求解的密文 
	int index[100]; // 记录密文的 ascii值 
	int pos; // 定位密文对应密文集的ascii值 
	int i = 0, f, n;

	gets(ciphertext);
	n = strlen(ciphertext);
	for (int j = 0; j < n; j++) //检测非法输入 
	{
		if (('Z' < ciphertext[j] && ciphertext[j] < 'A') || ('z' < ciphertext[j] && ciphertext[j] < 'a'))
		{
			printf("error! please input right ciphertext!\n");
			break;
		}
		else //转换为原字符 
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
					if ('a' <= ciphertext[i] && ciphertext[i] <= 'z') // 密文为小写 
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
					else if ('A' <= ciphertext[i] && ciphertext[i] <= 'Z') // 密文为大写 
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
