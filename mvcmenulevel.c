#include <stdio.h>

	typedef struct {
		int stateNumber;
		char namaMenu[30];
		int pointer;
		int levelAtas;
		int levelBawah[5];
		int levelBawahPanjang;
		} menu;

void copyChar(char* src, char* dst);
void fillMenu(menu* Menu, int levelAtas);
void cetakMenu(menu* Menu, int stateNumber);
int keypressed(menu* Menu, int* statePointer);

int main()
{
	menu Menu[10];
	int statePointer = 0;
	fillMenu(Menu, 10);
	int status = 1;
	int keypress;
	while(status) {
		cetakMenu(Menu, statePointer);
		status = keypressed(Menu, &statePointer);
	}
	printf("terima kasih\n");
	
return 0;
}

void copyChar(char* src, char* dst)
{
	for (int i = 0; i < 30; i++) {
		dst[i] = src[i];
		if (src[i] == '\0') break;
	}
}

void initializeState(menu* Menu, int levelAtas)
{
	Menu->pointer = 0;
	Menu->levelAtas = levelAtas;
	Menu->levelBawah[0] = 0;
	Menu->levelBawah[1] = 0;
	Menu->levelBawah[2] = 0;
	Menu->levelBawah[3] = 0;
	Menu->levelBawah[4] = 0;
}

void fillMenu(menu* Menu, int levelAtas)
{
	initializeState(&Menu[0], 0);
	Menu[0].pointer = 0;
	Menu[0].levelBawah[0] = 1;
	Menu[0].levelBawah[1] = 2;
	Menu[0].levelBawah[2] = 3;
	{ char temp[30] = "level 1";
	copyChar(temp, Menu[0].namaMenu); }

	initializeState(&Menu[1], 0);
	Menu[1].pointer = 0;
	Menu[1].levelBawah[0] = 4;
	Menu[1].levelBawah[1] = 5;
	Menu[1].levelBawah[2] = 6;
	{ char temp[30] = "menu 1";
	copyChar(temp, Menu[1].namaMenu); }

	initializeState(&Menu[2], 0);
	Menu[2].pointer = 0;
	Menu[2].levelBawah[0] = 7;
	Menu[2].levelBawah[1] = 8;
	Menu[2].levelBawah[2] = 9;
	{ char temp[30] = "menu 2";
	copyChar(temp, Menu[2].namaMenu); }

	initializeState(&Menu[3], 0);
	Menu[3].pointer = 0;
	Menu[3].levelBawah[0] = 10;
	Menu[3].levelBawah[1] = 11;
	Menu[3].levelBawah[2] = 12;
	{ char temp[30] = "menu 3";
	copyChar(temp, Menu[3].namaMenu); }

	initializeState(&Menu[4], 1);
	Menu[4].pointer = 0;
	Menu[4].levelBawah[0] = 13;
	Menu[4].levelBawah[1] = 14;
	Menu[4].levelBawah[2] = 15;
	{ char temp[30] = "menu 1.1";
	copyChar(temp, Menu[4].namaMenu); }

	initializeState(&Menu[5], 1);
	Menu[5].pointer = 0;
	Menu[5].levelBawah[0] = 16;
	Menu[5].levelBawah[1] = 17;
	Menu[5].levelBawah[2] = 18;
	{ char temp[30] = "menu 1.2";
	copyChar(temp, Menu[5].namaMenu); }

	initializeState(&Menu[6], 1);
	Menu[6].pointer = 0;
	Menu[6].levelBawah[0] = 19;
	Menu[6].levelBawah[1] = 20;
	Menu[6].levelBawah[2] = 21;
	{ char temp[30] = "menu 1.3";
	copyChar(temp, Menu[6].namaMenu); }
}

void cetakMenu(menu* Menu, int stateNumber)
{
	printf("%s \n", Menu[stateNumber].namaMenu);
	for(int i = 0; i < 5; i++) {
		int menuBawah = Menu[stateNumber].levelBawah[i];
		if (menuBawah == 0) break;
		printf("%d. %s ",i+1, Menu[menuBawah].namaMenu);
		if ( i == (Menu[stateNumber].pointer) ) printf ("*");
		printf("\n");
	}
	printf("W = arahkan pointer ke atas\n");
	printf("S = arahkan pointer ke bawah\n");
	printf("A = kembali ke menu sebelum\n");
	printf("D = masuk ke menu terpilih pointer\n");
	printf("Respon :");
}

int keypressed(menu* Menu, int* statePointer)
{
	char keypress;
	scanf("%c", &keypress);
	printf("Respon input=%c\n", keypress);
	if (keypress == 'q')
		return 0;
	else if (keypress == 'a')
		*statePointer = Menu[*statePointer].levelAtas;
	else if (keypress == 'w')
		Menu[*statePointer].pointer--;
	else if (keypress == 's') {
		Menu[*statePointer].pointer++;
		Menu[*statePointer].pointer = Menu[*statePointer].pointer % 3;
	} else if (keypress == 'd')
		*statePointer = Menu[*statePointer].levelBawah[Menu[*statePointer].pointer];
	return 1;

}

