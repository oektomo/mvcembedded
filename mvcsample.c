#include <stdio.h>

void copyChar(char* src, char* dst);

int main()
{
	typedef struct {
		int stateNumber;
		char namaMenu[30];
		int atas;
		int bawah;
		} menu;
	menu Menu[10];
	char temp[30] = "menu pertama";
	copyChar(temp, Menu[0].namaMenu);
	char temp1[30] = "menu kedua";
	copyChar(temp1, Menu[1].namaMenu);
	printf("nama menu state ke 0: %s \n",Menu[0].namaMenu);
	printf("nama menu state ke 1: %s \n",Menu[1].namaMenu);
	
return 0;
}

void copyChar(char* src, char* dst)
{
	for (int i = 0; i < 30; i++) {
		dst[i] = src[i];
		if (src[i] == '\0') break;
	}
}
