/*========================================================================================================================================
Program			: Ladda_Friska_Meta.c
Deskripsi		: Permainan Ludo yang dimainkan 1 orang user dan 1 bot (2 player) atau 3 bot (4 player).
Author			: Friska Intan Muta'alliy & Meta Arda Nabila
Versi/Tanggal	: 0.5 30/12/2019
Compiler		: MinGW64
Note			: Game ini dibuat untuk memenuhi Tugas Besar Mata Kuliah Dasar-Dasar Pemrograman
					D4 Teknik Informatika Politeknik Negeri Bandung Tahun Akademik 2019/2020.
========================================================================================================================================*/
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>
#include <string.h>
#include <stdbool.h>

/*===========================================================MODULE DECLARATIONS========================================================*/
//Description		: Menentukan posisi cursor
//Initial State		: Cursor terletak setelah karakter terakhir
//Final State		: Cursor terletak di koordinat yang telah ditentukan
//Author			: M Taufiq Pratama & Tria Yuda Purnama
//Reference			: -
//Calling Module	: 
//Called Module		: -
void gotoxy(int x, int y);

//Description		: Menentukan warna karakter yang ditampilkan di layar. 
//Initial State		: Karakter belum tertampil di layar.
//Final State		: Karakter tertampil di layar dengan warna yang telah diatur.
//Author			: M Taufiq Pratama & Tria Yuda Purnama
//Reference			: -
//Calling Module	: papan().
//Called Module		: -
void setcolor(unsigned short color);

//Description		: Menampilkan tampilan awal game.
//Initial State		: Tampilan awal game belum tertampil di layar.
//Final State		: Tampilan awal game tertampil di laya.
//Author			: Friska Intan Muta'alliy (edited by: Meta Arda Nabila)
//Reference			: -
//Calling Module	: main().
//Called Module		: gotoxy().
void Ladda_screen();

//Description		: Menampilkan  menu.
//Initial State		: Tampilan menu belum tertampil.
//Final State		: Tampilan menu tertampil.
//Author			: Friska Intan Muta'alliy
//Reference			: tmp_project.c (prototype di moodle)
//Calling Module	: main()
//Called Module		: menu_input()
void menu_screen();

//Description		: Menerima input pilihan menu dan mengarahkan menuju menu yang dipilih.
//Inistial State	: Menu belum terpilih.
//Final State		: Menu yang dipilih tertampil di layar.
//Author			: Friska Intan Muta'alliy
//Reference			: -
//Calling Module	: menu_screen()
//Called Module		: menu_screen(), new_game(), load_game(), how_to_play(), highscore(), credits(), about().
int menu_choose();

//Description		: Menerima input data-data yang diperlukan untuk memulai game dari keyboard.
//Inistial State	: Data belum diinputkan.
//Final State		: Data tersimpan dalam variabel penampungnya.
//Author			: Friska Intan Muta'alliy
//Reference			: -
//Calling Module	: menu_choose()
//Called Module		: load_screen()
void new_game();

//Description		: Menerima input data-data yang diperlukan untuk memulai game dari file savedGame.txt.
//Inistial State	: Data belum diinputkan.
//Final State		: Data tersimpan dalam variabel penampungnya.
//Author			: Friska Intan Muta'alliy
//Reference			: -
//Calling Module	: menu_choose()
//Called Module		: load_screen()
void load_game();

//Description		: Menampilkan petunjuk cara memainkan Ladda
//Initial State		: Tampilan petunjuk belum tertampil di layar
//Final State		: Tampilan petunjuk tertampil di layar
//Author			: Friska Intan Muta'alliy
//Reference			: -
//Calling Module	: menu_input()
//Called Module		: -
void how_to_play();

//Description		: Menampilkan highscore
//Initial State		: Tampilan highscore belum tertampil di layar
//Final State		: Tampilan highscore tertampil di layar
//Author			: Friska Intan Muta'alliy
//Reference			: -
//Calling Module	: menu_input()
//Called Module		: -
void highscore();

//Description		: Menampilkan credits
//Initial State		: Tampilan credits belum tertampil di layar
//Final State		: Tampilan credits tertampil di layar
//Author			: Friska Intan Muta'alliy
//Reference			: -
//Calling Module	: menu_input()
//Called Module		: -
void credits();

//Description		: Menampilkan About Ladda di layar.
//Initial State		: Tampilan About Ladda belum tertampil di layar
//Final State		: Tampilan About Ladda tertampil di layar
//Author			: Friska Intan Muta'alliy
//Reference			: -
//Calling Module	: menu_input()
//Called Module		: -
void about();

//Description		: Menampilkan tampilan "Terima kasih telah memainkan Ladda" sebelum user keluar dari program.
//Initial State		: Tampilan tampilan "Terima kasih telah memainkan Ladda" belum tertampil di layar
//Final State		: Tampilan tampilan "Terima kasih telah memainkan Ladda" tertampil di layar
//Author			: Friska Intan Muta'alliy
//Reference			: -
//Calling Module	: menu_input()
//Called Module		: -
void thanks();

//Description		: Menampilkan tampilan load game sebelum user bermain.
//Initial State		: Tampilan tampilan load game belum tertampil di layar
//Final State		: Tampilan tampilan load game tertampil di layar
//Author			: Friska Intan Muta'alliy
//Reference			: -
//Calling Module	: new_game(), load_game()
//Called Module		: 
void load_screen();

void papan();

void visual_home_pion();

void play();
void save_game();
int random_dadu(int countRandomDadu);
int check_kondisi();
bool check_canMove();
void visual_dadu(int dadu);
int pion_choose(int dadu);
void move_pion(int dadu, int selected);
void visual_move_pion();
bool check_win();
bool randomAgain(int countRandomDadu, int dadu);
bool safezone(int position);
bool check_kill(); 
void killing();
void game_over();
int noOneHome(int dadu);



/*=====================================================GLOBAL VARIABLE DECLARATIONS=====================================================*/

struct player
{
	char name[10];
	int selectedPion;
	int position[4];
	int lastPosition[4];
	bool onTrackPion[4];
	int moveable[4];
	int mode;
	int countStep;
};
struct player nowPlayer[4];


int jmlPlayer;
int indexPlayer;
int countRandomDadu;
int level, jmlPlayer;



 /*=================================================================MAIN================================================================*/
int main()
 {
 	system("MODE 190,56");
	Ladda_screen();
	menu_screen();
 }
 
 
 /*================================================================MODULES==============================================================*/
void gotoxy(int x, int y)
{
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void Ladda_screen()
{
	char Ladda [11][100];
	int i, j, k;
	strcpy(Ladda [0], " .----------------.  .----------------.  .----------------.  .----------------.  .----------------. ");
	strcpy(Ladda [1], "| .--------------. || .--------------. || .--------------. || .--------------. || .--------------. |");
	strcpy(Ladda [2], "| |   _____      | || |      __      | || |  ________    | || |  ________    | || |      __      | |");
	strcpy(Ladda [3], "| |  |_   _|     | || |     /  \\     | || | |_   ___ `.  | || | |_   ___ `.  | || |     /  \\     | |");
	strcpy(Ladda [4], "| |    | |       | || |    / /\\ \\    | || |   | |   `. \\ | || |   | |   `. \\ | || |    / /\\ \\    | |");
	strcpy(Ladda [5], "| |    | |   _   | || |   / ____ \\   | || |   | |    | | | || |   | |    | | | || |   / ____ \\   | |");
	strcpy(Ladda [6], "| |   _| |__/ |  | || | _/ /    \\ \\_ | || |  _| |___.' / | || |  _| |___.' / | || | _/ /    \\ \\_ | |");
	strcpy(Ladda [7], "| |  |________|  | || ||____|  |____|| || | |________.'  | || | |________.'  | || ||____|  |____|| |");
	strcpy(Ladda [8], "| |              | || |              | || |              | || |              | || |              | |");
	strcpy(Ladda [9], "| '--------------' || '--------------' || '--------------' || '--------------' || '--------------' |");
	strcpy(Ladda [10]," '----------------'  '----------------'  '----------------'  '----------------'  '----------------' ");
	
	for(i=0; i<11; i++)
	{
		for(j=0; j<100; j++)
		{
			gotoxy(35+j,15+i);
			printf("%c", Ladda[i][j]);
			for(k=0; k<1000000; k++){}
		}
		printf("\n");	
	}
	gotoxy(65,28);
	system("pause");
	return;
}

void menu_screen()
{
 	int i, j=0;
 	
 	system("cls");
 	FILE *menu = fopen("menu.txt", "r");
 	char ch[512];
	while((fgets(ch, 512, menu)) != NULL)
	{
		gotoxy(60, 15+j);
		printf("%s", ch);
		for(i=0; i<50000000; i++){}
		j++;
	}
 	fclose(menu);
 	printf("\n");
 	menu_choose();
 	return;
}
 
int menu_choose()
{
	int menu;
	scanf("%d", &menu);
	if(menu == 1)
	{
		new_game();
	}
	else if(menu == 2)
	{
		load_game();
	}
	else if(menu == 3)
	{
		how_to_play();
	}
	else if(menu == 4)
	{
		highscore();
	}
	else if(menu == 5)
	{
		credits();
		sleep(1);
	}
	else if(menu == 6)
	{
		about();
	}
	else if(menu == 7)
	{
		thanks();
		exit(0);
	}
	else
	{
		printf("Menu invalid. Silahkan ulangi.\n");
	}
	system("pause");
	menu_screen();
}

void new_game()
{
	int i=0; int j=0;
	system("cls");
	FILE*ladda = fopen("ladda.txt","r");
	char ch[512];
	while((fgets(ch, 512, ladda)) != NULL)
	{
		gotoxy(60,15+i);
		printf("%s", ch);
		i++;
	}
 	fclose(ladda);
	input_level: gotoxy(60,20); printf("Pilih level:\n");
	gotoxy(60,21); printf("1. Easy\n");
	gotoxy(60,22); printf("2. Medium\n");
	gotoxy(60,23); printf("3. Hard\n");
	gotoxy(73,20); scanf("%d", &level);
	if((level < 1) || (level >3))
	{
		gotoxy(75,20);printf("Level invalid. Silahkan ulangi.");
		goto input_level;
	}
	for(i=0; i<45; i++)
	{
		gotoxy(75+i,20);
		printf(" ");
	}
	input_jmlPlayer : gotoxy(60,25); printf("Masukkan jumlah pemain: \n");
	gotoxy(84,25); scanf("%d", &jmlPlayer);
	if(jmlPlayer != 2)
	{
		if(jmlPlayer != 4)
		{
			gotoxy(86,25);printf("Jumlah pemain invalid. Silahkan ulangi.");
			goto input_jmlPlayer;
		}	
	}
	
	for(i=0; i<45; i++)
	{
		gotoxy(86+i,25);
		printf(" ");
	}
	
	gotoxy(60,27); printf("Masukkan nickname: ");
	gotoxy(80,27); scanf("%s", nowPlayer[0].name);

	for(i=0; i<4; i++)
	{
		for(j=0; j<4; j++)
		{
			nowPlayer[i].position[j] = -1;
			nowPlayer[i].onTrackPion[j] = false;
			nowPlayer[i].moveable[j] = '\0';
			nowPlayer[i].countStep = 0;
		}
	}
	strcpy(nowPlayer[1].name, "COMP 1");
	strcpy(nowPlayer[2].name, "COMP 2");
	strcpy(nowPlayer[3].name, "COMP 3");
	
	nowPlayer[0].mode = -1;
	switch(jmlPlayer)
	{
		case 2:
			for(i=1; i<4; i++)
			{
				nowPlayer[i].mode = level;
			}
			break;
			
		case 4:
			if(level == 1)
			{
				nowPlayer[1].mode = 1;
					nowPlayer[2].mode = 1;
					nowPlayer[3].mode = 2;
			}
			else if(level == 2)
			{
				nowPlayer[1].mode = 1;
				nowPlayer[2].mode = 2;
				nowPlayer[3].mode = 3;
			}
			else if(level == 3)
			{
				nowPlayer[1].mode = 3;
				nowPlayer[2].mode = 3;
				nowPlayer[3].mode = 2;
			}
			
			break;
	}
	
	load_screen();
	play();
}

void load_game()
{
	char ch[512];
	int i,j;
	int onTrack;
	FILE *load = fopen("savedGame.dat", "rb");
//	printf("belum tersedia."); //put your code here
	while((fgets(ch, 512, load)) != NULL)
	{
		for(i=0; i<jmlPlayer; i++)
		{
			for(j=0; j<4; j++)
			{
				
				fscanf(load, "%s %d %d %d %d %d %d %d %d %d\n" ,nowPlayer[i].name, level, jmlPlayer, onTrack, nowPlayer[i].countStep, nowPlayer[i].mode, nowPlayer[i].selectedPion, nowPlayer[i].position[j], nowPlayer[i].moveable[j], nowPlayer[i].lastPosition[j]);
				if(onTrack == 1)
				{
					nowPlayer[i].onTrackPion[j] = true;
				}
				else if(onTrack == 0)
				{
					nowPlayer[i].onTrackPion[j] = false;
				}
			}
			printf("%s\n", nowPlayer[i].name);
		}
	}
	fclose(load);
	load_screen();
	play();
}

void how_to_play()
{
	int i,j=0;
 	system("cls");
 	FILE *htp = fopen("howToPlay.txt", "r");
 	char ch[512];
	while((fgets(ch, 512, htp)) != NULL)
	{
		gotoxy(60,10+j);
		printf("%s", ch);
		for(i=0; i<50000000; i++){}
		j++;
	}
 	fclose(htp);
 	printf("\n");
 	return;
}

void highscore()
{
	int i, j=0;
 	system("cls");
 	FILE *hsh = fopen("highscoreHead.txt", "r");
 	char ch[512];
	while((fgets(ch, 512, hsh)) != NULL)
	{
		gotoxy(60,15+j);
		printf("%s", ch);
		for(i=0; i<50000000; i++){}
		j++;
	}
	j=0;
 	fclose(hsh);
 	gotoxy(60,23); printf("Rank    Name     Score    Title\n");
 	gotoxy(60,24); printf("--------------------------------\n");
 	FILE *hs = fopen("highscore.txt", "r");
 	char c[512];
	while((fgets(c, 512, hs)) != NULL)
	{
		gotoxy(60, 25+j);
		printf("%s", c);
		for(i=0; i<50000000; i++){}
		j++;
	}
 	fclose(hs);
 	printf("\n");
 	return;
}

void credits()
{
	int i, j=0;
 	system("cls");
 	FILE *credits = fopen("credits.txt", "r");
 	char ch[512];
	while((fgets(ch, 512, credits)) != NULL)
	{
		gotoxy(60,10+j);
		printf("%s", ch);
		for(i=0; i<50000000; i++){}
		j++;
	}
 	fclose(credits);
 	printf("\n");
 	return;
}

void about()
{
	int i, j=0;
 	system("cls");
 	FILE *ab = fopen("about.txt", "r");
 	char ch[512];
	while((fgets(ch, 512, ab)) != NULL)
	{
		gotoxy(60,10+j);
		printf("%s", ch);
		for(i=0; i<50000000; i++){}
		j++;
	}
 	fclose(ab);
 	printf("\n");
 	return;
}

void thanks()
{
	int i, j=0;
 	system("cls");
 	FILE *th = fopen("thanks.txt", "r");
 	char ch[512];
	while((fgets(ch, 512, th)) != NULL)
	{
		gotoxy(50,10+j);
		printf("%s", ch);
		for(i=0; i<50000000; i++){}
		j++;
	}
 	fclose(th);
 	printf("\n");
 	return;
}

void load_screen()
{
	int i,j,k;
	system("cls");
	gotoxy(75,15); printf("Please wait...");
	
	gotoxy(59,18); printf("Ú");
	gotoxy(104,18); printf("¿");
	gotoxy(59,20); printf("À");
	gotoxy(104,20); printf("Ù");
	gotoxy(59,19); printf("³");
	gotoxy(104,19); printf("³");
	for(i=60; i<104; i++)
	{
		gotoxy(i,18); printf("Ä");
		gotoxy(i,20); printf("Ä");
	}
	k=0;
	for(i=1; i<=42; i+=4)
	{
		for(j=0; j<100000000; j++){}
		gotoxy(i+60, 19); printf("þþ");
		gotoxy(80,22); printf("%d %%", k*10);
		k++;
	}
	gotoxy(67,28);	
	system("pause");
	system("cls");
}

void setcolor(unsigned short color)
{
HANDLE hCon = GetStdHandle(STD_OUTPUT_HANDLE);

SetConsoleTextAttribute(hCon,color);

}

void papan()
{
	int i, j;
	setcolor(15);
	//=====================================================PAPAN LUDO=================================================================
	gotoxy(0,0);printf("É"); 						//sudut papan ludo
	gotoxy(70,0);printf("»");
	gotoxy(0,55);printf("È");
	gotoxy(70,55);printf("¼");
	
	for(i=1; i<=54; i++)
	{
		gotoxy(0,i);printf("º");					//garis papan vertikal
		gotoxy(70,i);printf("º");					//garis papan vertikal
	}
	for(i=1; i<=69; i++)
	{
		gotoxy(i,0);printf("Í");					//garis papan horizontal
		gotoxy(i,55);printf("Í");					//garis papan horizontal
	}
	
	//base_Finish================================================================
	gotoxy(28,22);printf("É"); 						//sudut base finish
	gotoxy(42,22);printf("»");
	gotoxy(28,33);printf("È");
	gotoxy(42,33);printf("¼");
	
	for(i=23; i<=32; i++)
	{
		gotoxy(28,i);printf("º");					//garis vertikal
		gotoxy(42,i);printf("º");
	}
	
	for(i=29; i<=41; i++)
	{
		gotoxy(i,22);printf("Í");					//garis horizontal
		gotoxy(i,33);printf("Í");
	}
	for(i=1; i<=10; i++)
	{
		gotoxy(i+29,i+22);printf("ÛÛ");				//diagonal
		gotoxy(i+29,33-i);printf("ÛÛ");
	}
	
	//Jalur pion=======================================================
	//jalur atas
	for(j=1; j<=3; j++)
	{
		for(i=1; i<=5; i++)
		{
			gotoxy(j*5+23,i*4-2);printf("ÉÍÍÍ»");
			gotoxy(j*5+23,i*4-1);printf("º   º");		
			gotoxy(j*5+23,i*4);printf("º   º");
			gotoxy(j*5+23,i*4+1);printf("ÈÍÍÍ¼");
		}
	}
	//jalur bawah
	for(j=1; j<=3; j++)
	{
		for(i=1; i<=5; i++)
		{
			gotoxy(j*5+23,i*4+30);printf("ÉÍÍÍ»");
			gotoxy(j*5+23,i*4+31);printf("º   º");		
			gotoxy(j*5+23,i*4+32);printf("º   º");
			gotoxy(j*5+23,i*4+33);printf("ÈÍÍÍ¼");
		}
	}
	//jalur kiri
	for(j=1; j<=3; j++)
	{
		for(i=1; i<=5; i++)
		{
			gotoxy(i*5-2,j*4+18);printf("ÉÍÍÍ»");
			gotoxy(i*5-2,j*4+19);printf("º   º");		
			gotoxy(i*5-2,j*4+20);printf("º   º");
			gotoxy(i*5-2,j*4+21);printf("ÈÍÍÍ¼");
		}
	}
	//jalur kanan
	for(j=1; j<=3; j++)
	{
		for(i=1; i<=5; i++)
		{
			gotoxy(i*5+38,j*4+18);printf("ÉÍÍÍ»");
			gotoxy(i*5+38,j*4+19);printf("º   º");		
			gotoxy(i*5+38,j*4+20);printf("º   º");
			gotoxy(i*5+38,j*4+21);printf("ÈÍÍÍ¼");
		}
	}
	//jalur khusus
		//com1
		setcolor(12);
		gotoxy(8,22);printf("ÉÍÍÍ»");
		gotoxy(8,23);printf("º   º");		
		gotoxy(8,24);printf("º   º");
		gotoxy(8,25);printf("ÈÍÍÍ¼");
		for(i=1; i<=4; i++)
		{
			gotoxy(i*5+3,26);printf("ÉÍÍÍ»");
			gotoxy(i*5+3,27);printf("º   º");		
			gotoxy(i*5+3,28);printf("º   º");
			gotoxy(i*5+3,29);printf("ÈÍÍÍ¼");
		}
		//com2
		setcolor(10);
		gotoxy(38,6);printf("ÉÍÍÍ»");
		gotoxy(38,7);printf("º   º");		
		gotoxy(38,8);printf("º   º");
		gotoxy(38,9);printf("ÈÍÍÍ¼");
		for(i=1; i<=4; i++)
		{
			gotoxy(33,i*4+2);printf("ÉÍÍÍ»");
			gotoxy(33,i*4+3);printf("º   º");		
			gotoxy(33,i*4+4);printf("º   º");
			gotoxy(33,i*4+5);printf("ÈÍÍÍ¼");
		}
		//com3
		setcolor(14);
		gotoxy(58,30);printf("ÉÍÍÍ»");
		gotoxy(58,31);printf("º   º");		
		gotoxy(58,32);printf("º   º");
		gotoxy(58,33);printf("ÈÍÍÍ¼");
		for(i=1; i<=4; i++)
		{
			gotoxy(i*5+38,26);printf("ÉÍÍÍ»");
			gotoxy(i*5+38,27);printf("º   º");		
			gotoxy(i*5+38,28);printf("º   º");
			gotoxy(i*5+38,29);printf("ÈÍÍÍ¼");
		}
		//Player
		setcolor(9);
		gotoxy(28,46);printf("ÉÍÍÍ»");
		gotoxy(28,47);printf("º   º");		
		gotoxy(28,48);printf("º   º");
		gotoxy(28,49);printf("ÈÍÍÍ¼");
		for(i=1; i<=4; i++)
		{
			gotoxy(33,i*4+30);printf("ÉÍÍÍ»");
			gotoxy(33,i*4+31);printf("º   º");		
			gotoxy(33,i*4+32);printf("º   º");
			gotoxy(33,i*4+33);printf("ÈÍÍÍ¼");
		}
	//safe zone==================================================================
	setcolor(8);
	gotoxy(28,10);printf("ÉÍÍÍ»");
	gotoxy(28,11);printf("º   º");		
	gotoxy(28,12);printf("º   º");
	gotoxy(28,13);printf("ÈÍÍÍ¼");
	
	gotoxy(13,30);printf("ÉÍÍÍ»");
	gotoxy(13,31);printf("º   º");		
	gotoxy(13,32);printf("º   º");
	gotoxy(13,33);printf("ÈÍÍÍ¼");
	
	gotoxy(53,22);printf("ÉÍÍÍ»");
	gotoxy(53,23);printf("º   º");		
	gotoxy(53,24);printf("º   º");
	gotoxy(53,25);printf("ÈÍÍÍ¼");
	
	gotoxy(38,42);printf("ÉÍÍÍ»");
	gotoxy(38,43);printf("º   º");		
	gotoxy(38,44);printf("º   º");
	gotoxy(38,45);printf("ÈÍÍÍ¼");
	
	//homebase 1 (komputer)======================================================
	setcolor(12);									//homebase com1 (Merah)
	gotoxy(5,5);printf("É"); 						//sudut homebase
	gotoxy(22,5);printf("»");
	gotoxy(5,17);printf("È");
	gotoxy(22,17);printf("¼");
	
	for(i=6; i<=16; i++)
	{		
		gotoxy(5,i);printf("º");					//garis homebase vertikal
		gotoxy(22,i);printf("º");					//garis homebase vertikal
	}	
	for(i=6; i<=21; i++)
	{
		gotoxy(i,5);printf("Í");					//garis homebase horizontal
		gotoxy(i,17);printf("Í");					//garis homebase horizontal
	}
	//home_base_pion============================================
	for(i=1; i<=2; i++)
	{
		gotoxy(i*7+1,7);printf("ÉÍÍÍ»");
		gotoxy(i*7+1,12);printf("ÉÍÍÍ»");
		gotoxy(i*7+1,8);printf("º   º");
		gotoxy(i*7+1,13);printf("º   º");		
		gotoxy(i*7+1,9);printf("º   º");		
		gotoxy(i*7+1,14);printf("º   º");
		gotoxy(i*7+1,10);printf("ÈÍÍÍ¼");
		gotoxy(i*7+1,15);printf("ÈÍÍÍ¼");
	}
	
	
	//homebase 2 (komputer)=====================================================
	setcolor(10);									//homebase com2 (Hijau)
	gotoxy(48,5);printf("É"); 						//sudut homebase
	gotoxy(65,5);printf("»");
	gotoxy(48,17);printf("È");
	gotoxy(65,17);printf("¼");
	
	for(i=6; i<=16; i++)
	{		
		gotoxy(48,i);printf("º");					//garis homebase vertikal
		gotoxy(65,i);printf("º");					//garis homebase vertikal
	}	
	for(i=49; i<=64; i++)
	{
		gotoxy(i,5);printf("Í");					//garis homebase horizontal
		gotoxy(i,17);printf("Í");					//garis homebase horizontal
	}
	//home_base_pion============================================
	for(i=1; i<=2; i++)
	{
		gotoxy(i*7+44,7);printf("ÉÍÍÍ»");
		gotoxy(i*7+44,12);printf("ÉÍÍÍ»");
		gotoxy(i*7+44,8);printf("º   º");
		gotoxy(i*7+44,13);printf("º   º");		
		gotoxy(i*7+44,9);printf("º   º");		
		gotoxy(i*7+44,14);printf("º   º");
		gotoxy(i*7+44,10);printf("ÈÍÍÍ¼");
		gotoxy(i*7+44,15);printf("ÈÍÍÍ¼");
	}
	//homebase 3 (player)=======================================================
	setcolor(9);									//homebase player(Biru)
	gotoxy(5,38);printf("É"); 						//sudut homebase
	gotoxy(23,38);printf("»");
	gotoxy(5,50);printf("È");
	gotoxy(23,50);printf("¼");

	for(i=39; i<=49; i++)
	{		
		gotoxy(5,i);printf("º");					//garis homebase vertikal
		gotoxy(23,i);printf("º");					//garis homebase vertikal
	}	
	for(i=6; i<=22; i++)
	{
		gotoxy(i,38);printf("Í");					//garis homebase horizontal
		gotoxy(i,50);printf("Í");					//garis homebase horizontal
	}
	//home_base_pion============================================
	for(i=1; i<=2; i++)
	{
		gotoxy(i*7+1,40);printf("ÉÍÍÍ»");
		gotoxy(i*7+1,45);printf("ÉÍÍÍ»");
		gotoxy(i*7+1,41);printf("º   º");
		gotoxy(i*7+1,46);printf("º   º");		
		gotoxy(i*7+1,42);printf("º   º");		
		gotoxy(i*7+1,47);printf("º   º");
		gotoxy(i*7+1,43);printf("ÈÍÍÍ¼");
		gotoxy(i*7+1,48);printf("ÈÍÍÍ¼");
	}
	//homebase 4 (komputer)=================================================
	setcolor(14);									//homebase com3 (Kuning)
	gotoxy(48,38);printf("É"); 						//sudut homebase
	gotoxy(65,38);printf("»");
	gotoxy(48,50);printf("È");
	gotoxy(65,50);printf("¼");
	
	for(i=39; i<=49; i++)
	{		
		gotoxy(48,i);printf("º");					//garis homebase vertikal
		gotoxy(65,i);printf("º");					//garis homebase vertikal
	}	
	for(i=49; i<=64; i++)
	{
		gotoxy(i,38);printf("Í");					//garis homebase horizontal
		gotoxy(i,50);printf("Í");					//garis homebase horizontal
	}
	//home_base_pion============================================
	for(i=1; i<=2; i++)
	{
		gotoxy(i*7+44,40);printf("ÉÍÍÍ»");
		gotoxy(i*7+44,45);printf("ÉÍÍÍ»");
		gotoxy(i*7+44,41);printf("º   º");
		gotoxy(i*7+44,46);printf("º   º");		
		gotoxy(i*7+44,42);printf("º   º");		
		gotoxy(i*7+44,47);printf("º   º");
		gotoxy(i*7+44,43);printf("ÈÍÍÍ¼");
		gotoxy(i*7+44,48);printf("ÈÍÍÍ¼");
	}
	setcolor(15);
}

void play()
{
	int i,j;
    int kondisi;
    int dadu;
    char respond;
    bool canMove;
    bool again;
    bool win = false;
    bool over = false;
    bool kill;
    int selected;
    char enter;
    int indexPion;
    int countMovement;
    papan();
    gotoxy(6,4);printf("%s", nowPlayer[0].name);
    gotoxy(50,4);printf("%s", nowPlayer[1].name);
    gotoxy(6,37);printf("%s", nowPlayer[3].name);
    gotoxy(50,37);printf("%s", nowPlayer[2].name);
	while (over == false)
    {
        for (indexPlayer = 0; indexPlayer < jmlPlayer; indexPlayer++)
        {
        	for(i=0; i<jmlPlayer; i++)
        	{
        		for(j=0; j<4; j++)
        		{
        			visual_move_pion(i,j);
				}
			}
            countRandomDadu = 0;
            gotoxy(75,5);printf("Giliran: %s\n", nowPlayer[indexPlayer].name);
//            gotoxy(72,6);printf("mode: %d", nowPlayer[indexPlayer].mode);

        random_again:
        	if(indexPlayer == 0)
        	{
        		gotoxy(75,7);printf("Press any key to random the dice...");
        		gotoxy(75,8);printf("Press S to save your progress...");
        		gotoxy(75,9);printf("Press P to pause the game...");
            	respond = getch();
			}
			
			if((respond == 'S') || (respond == 's'))
			{
				save_game();
				menu_screen();
			}
			else if((respond == 'P') || (respond == 'p'))
			{
				gotoxy(75,11);printf("Permainan dijeda...\n");
				gotoxy(75,12);printf("Press any key to resume...\n");
				getch();
			}
			respond = '\0';
            gotoxy(75,6);printf("                                                                    ");
            gotoxy(75,7);printf("                                                                    ");
            gotoxy(75,8);printf("                                                                    ");
            gotoxy(75,9);printf("                                                                    ");
            gotoxy(75,10);printf("                                                                    ");
            gotoxy(75,11);printf("                                                                    ");
            gotoxy(75,12);printf("                                                                    ");
            dadu = random_dadu(countRandomDadu);

//            printf("dadu: %d\n", dadu);
            countMovement = 0;
            // perulangan biar bisa ngecek mana aja pion yang bisa jalan
            for (indexPion = 0; indexPion < 4; indexPion++)
            {
                kondisi = check_kondisi(dadu, indexPion);
                canMove = check_canMove(dadu, kondisi, indexPion);
                if (canMove)
                {
                    countMovement++;
                }
            }

            if (countMovement == 0)
            {
                continue;
            }
            if(nowPlayer[indexPlayer].mode == -1)
            {
            	selected = pion_choose(dadu);
			}
			else if(nowPlayer[indexPlayer].mode == 1)
			{
				selected = noOneHome(dadu);
			}
			else if(nowPlayer[indexPlayer].mode == 2)
			{
				selected = furtherMost(dadu);
			}
			else if(nowPlayer[indexPlayer].mode == 3)
			{
				selected = killer(dadu);
			}
            
            move_pion(dadu, selected);
            kill = check_kill();
            if(kill == true)
            {
            	killing();
			}
			
            again = false;
            again = randomAgain(countRandomDadu, dadu);
            if (again == true)
            {
                goto random_again;
            }
            else
            {
                continue;
            }
        }
    }
    game_over();
}

void save_game()
{
	int i,j;
	int onTrack;
	gotoxy(75,11);printf("Data anda sedang disimpan...\n");
	FILE*save = fopen("savedGame.dat", "wb");
	for(i=0; i<jmlPlayer; i++)
	{
		for(j=0; j<4; j++)
		{
			if(nowPlayer[i].onTrackPion[j] == true)
			{
				onTrack = 1;
			}
			else if(nowPlayer[i].onTrackPion[j] == false)
			{
				onTrack = 0;
			}
			fprintf(save, "%s %d %d %d %d %d %d %d %d %d\n" ,nowPlayer[i].name, level, jmlPlayer, onTrack, nowPlayer[i].countStep, nowPlayer[i].mode, nowPlayer[i].selectedPion, nowPlayer[i].position[j], nowPlayer[i].moveable[j], nowPlayer[i].lastPosition[j]);
		}
	}
	fclose(save);
	gotoxy(72,12);system("pause");
}

int random_dadu(int countRandomDadu)
{
	int dadu;
	while(countRandomDadu < 3)
	{
		srand(time(0));
		dadu = (rand() % 6) + 1;
		countRandomDadu++;
		visual_dadu(dadu);
	
		return dadu;	
	}

}

void visual_dadu(int dadu)
{
	int k;
	gotoxy(80,14);printf("+-----+");
	gotoxy(80,15);printf("|     |");
	gotoxy(80,16);printf("| %c %c |",1,1);
	gotoxy(80,17);printf("|     |");
	gotoxy(80,18);printf("+-----+");
	for(k=0; k<100000000; k++){}
	gotoxy(80,14);printf("+-----+");
	gotoxy(80,15);printf("|     |");
	gotoxy(80,16);printf("|  %c  |",1);
	gotoxy(80,17);printf("|     |");
	gotoxy(80,18);printf("+-----+");
	for(k=0; k<100000000; k++){}
	gotoxy(80,14);printf("+-----+");
	gotoxy(80,15);printf("| %c %c |",1,1);
	gotoxy(80,16);printf("| %c %c |",1,1);
	gotoxy(80,17);printf("| %c %c |",1,1);
	gotoxy(80,18);printf("+-----+");
	for(k=0; k<100000000; k++){}
	gotoxy(80,14);printf("+-----+");
	gotoxy(80,15);printf("|  %c  |",1);
	gotoxy(80,16);printf("|  %c  |",1);
	gotoxy(80,17);printf("|  %c  |",1);
	gotoxy(80,18);printf("+-----+");
	for(k=0; k<100000000; k++){}
	gotoxy(80,14);printf("+-----+");
	gotoxy(80,15);printf("| %c %c |",1,1);
	gotoxy(80,16);printf("|  %c  |",1);
	gotoxy(80,17);printf("| %c %c |",1,1);
	gotoxy(80,18);printf("+-----+");
	for(k=0; k<100000000; k++){}
	gotoxy(80,14);printf("+-----+");
	gotoxy(80,15);printf("|  %c  |",1);
	gotoxy(80,16);printf("|  %c  |",1);
	gotoxy(80,17);printf("|  %c  |",1);
	gotoxy(80,18);printf("+-----+");
	for(k=0; k<100000000; k++){}
	gotoxy(80,14);printf("+-----+");
	gotoxy(80,15);printf("| %c %c |",1,1);
	gotoxy(80,16);printf("|     |",1);
	gotoxy(80,17);printf("| %c %c |",1,1);
	gotoxy(80,18);printf("+-----+");
	for(k=0; k<100000000; k++){}
			
	switch(dadu)
	{
		case 1:
			gotoxy(80,14);printf("+-----+");
			gotoxy(80,15);printf("|     |");
			gotoxy(80,16);printf("|  %c  |",1);
			gotoxy(80,17);printf("|     |");
			gotoxy(80,18);printf("+-----+");
			break;
			
		case 2:
			gotoxy(80,14);printf("+-----+");
			gotoxy(80,15);printf("|     |");
			gotoxy(80,16);printf("| %c %c |",1,1);
			gotoxy(80,17);printf("|     |");
			gotoxy(80,18);printf("+-----+");
			break;
			
		case 3:
			gotoxy(80,14);printf("+-----+");
			gotoxy(80,15);printf("|  %c  |",1);
			gotoxy(80,16);printf("|  %c  |",1);
			gotoxy(80,17);printf("|  %c  |",1);
			gotoxy(80,18);printf("+-----+");
			break;
			
		case 4:
			gotoxy(80,14);printf("+-----+");
			gotoxy(80,15);printf("| %c %c |",1,1);
			gotoxy(80,16);printf("|     |",1);
			gotoxy(80,17);printf("| %c %c |",1,1);
			gotoxy(80,18);printf("+-----+");
			break;
			
		case 5:
			gotoxy(80,14);printf("+-----+");
			gotoxy(80,15);printf("| %c %c |",1,1);
			gotoxy(80,16);printf("|  %c  |",1);
			gotoxy(80,17);printf("| %c %c |",1,1);
			gotoxy(80,18);printf("+-----+");
			break;
			
		case 6:
			gotoxy(80,14);printf("+-----+");
			gotoxy(80,15);printf("| %c %c |",1,1);
			gotoxy(80,16);printf("| %c %c |",1,1);
			gotoxy(80,17);printf("| %c %c |",1,1);
			gotoxy(80,18);printf("+-----+");
			break;
	}
	printf("\n");
	sleep(1);
}

int check_kondisi(int dadu, int indexPion)
{

    nowPlayer[indexPlayer].moveable[indexPion] = -1;

    if (nowPlayer[indexPlayer].position[indexPion] == -1) //di home
    {
        return 1;
    }
    else if ((nowPlayer[indexPlayer].position[indexPion] >= 0) && (nowPlayer[indexPlayer].position[indexPion] + dadu < 47)) //on track
    {
        nowPlayer[indexPlayer].onTrackPion[indexPion] = true;
        if (nowPlayer[indexPlayer].onTrackPion[indexPion] == true)
        {
            nowPlayer[indexPlayer].moveable[indexPion] = indexPion;
        }
        return 2;
    }
    else if (nowPlayer[indexPlayer].position[indexPion] + dadu == 47) //on track, bisa finish
    {
        nowPlayer[indexPlayer].onTrackPion[indexPion] = true;
        if (nowPlayer[indexPlayer].onTrackPion[indexPion] == true)
        {
            nowPlayer[indexPlayer].moveable[indexPion] = indexPion;
        }
        return 3;
    }
    else if (nowPlayer[indexPion].position[indexPion] == 47) //finish
    {
        nowPlayer[indexPlayer].onTrackPion[indexPion] = false;
        return 4;
    }
    else if (nowPlayer[indexPlayer].position[indexPion] + dadu > 47) //on track namun jika maju lebih dari finifh
    {
        nowPlayer[indexPlayer].onTrackPion[indexPion] = true;
        return 5;
    }
}

bool check_canMove(int dadu, int kondisi, int indexPion)
{
    if (dadu < 6)
    {
        switch (kondisi)
        {
        case 1:
        case 4:
        case 5:
            return false;

        case 2:
        case 3:
            return true;
        }
    }
    else if (dadu == 6)
    {
        switch (kondisi)
        {

        case 4:
        case 5:
            return false;

        case 1:
        case 2:
        case 3:
            nowPlayer[indexPlayer].moveable[indexPion] = indexPion;
            return true;
        }
    }
}

int pion_choose(int dadu)
{
    int selected;
    int indexPion;
    int found = 0;
    char enter;

input_selectedPion:
    //printf("%s Pilih pion yang akan dijalankan (%d %d %d %d) : ", nowPlayer[indexPlayer].name, nowPlayer[indexPlayer].moveable[0]+1, nowPlayer[indexPlayer].moveable[1]+1, nowPlayer[indexPlayer].moveable[2]+1, nowPlayer[indexPlayer].moveable[3]+1);

    gotoxy(77,6); printf("%s Pilih pion yang akan dijalankan (", nowPlayer[indexPlayer].name);
    for (indexPion = 0; indexPion < 4; indexPion++)
    {
        // yang ini diubah biar enakan liatnya
        if (nowPlayer[indexPlayer].moveable[indexPion] == -1)
        {
            printf("-");
        }
        else
        {
            printf("%d", indexPion + 1);
        }

        if (indexPion < 3)
        {
            printf(" ");
        }
        else
        {
            printf(") : ");
        }
    }
    scanf("%d%c", &selected, &enter);
    gotoxy(75,6);printf("                                                                    ");
    nowPlayer[indexPlayer].selectedPion = selected - 1;
    if (nowPlayer[indexPlayer].moveable[nowPlayer[indexPlayer].selectedPion] == nowPlayer[indexPlayer].selectedPion)
    {
        return selected;
    }
    else if (nowPlayer[indexPlayer].selectedPion == 8)
    {
        play();
    }
    else if (nowPlayer[indexPlayer].moveable[nowPlayer[indexPlayer].selectedPion] != nowPlayer[indexPlayer].selectedPion)
    {
		
        gotoxy(77,7); printf("Pion %d milik %s tidak bisa maju.\n", selected, nowPlayer[indexPlayer].name);
		gotoxy(77,8); printf("Silahkan ulangi atau skip (Tekan 9).\n");
        goto input_selectedPion;
    }
}

void move_pion(int dadu, int selected)
{
    int i;
    int Player, Pion;
    nowPlayer[indexPlayer].lastPosition[nowPlayer[indexPlayer].selectedPion] = nowPlayer[indexPlayer].position[nowPlayer[indexPlayer].selectedPion];
    if (nowPlayer[indexPlayer].position[nowPlayer[indexPlayer].selectedPion] == -1)
    {
		nowPlayer[indexPlayer].position[nowPlayer[indexPlayer].selectedPion] = 0;
		
		Player = indexPlayer;
		Pion = nowPlayer[indexPlayer].selectedPion;
		visual_move_pion(Player, Pion);
		
        nowPlayer[indexPlayer].onTrackPion[nowPlayer[indexPlayer].selectedPion] = true;
        nowPlayer[indexPlayer].countStep += 1 ;
        gotoxy(75,7);
		printf("pion %d milik %s keluar dari home\n", selected, nowPlayer[indexPlayer].name);
		sleep(1);
		
		
		gotoxy(75,7);printf("                                                                    ");
//		printf("pion %d milik %s berada di posisi %d\n", selected, nowPlayer[indexPlayer].name, nowPlayer[indexPlayer].position[nowPlayer[indexPlayer].selectedPion]);

    }
    else if ((nowPlayer[indexPlayer].position[nowPlayer[indexPlayer].selectedPion] >= 0) && (nowPlayer[indexPlayer].position[nowPlayer[indexPlayer].selectedPion] + dadu < 47))
    {
        nowPlayer[indexPlayer].position[nowPlayer[indexPlayer].selectedPion] += dadu;
        nowPlayer[indexPlayer].countStep += dadu ;
        
        Player = indexPlayer;
		Pion = nowPlayer[indexPlayer].selectedPion;
		visual_move_pion(Player, Pion);
		
        gotoxy(75,7);
		printf("pion %d milik %s berada di posisi: %d\n", selected, nowPlayer[indexPlayer].name, nowPlayer[indexPlayer].position[nowPlayer[indexPlayer].selectedPion]);
        gotoxy(75,7);printf("                                                                    ");
        sleep(1);
    }
    else if (nowPlayer[indexPlayer].position[nowPlayer[indexPlayer].selectedPion] + dadu == 47)
    {
        nowPlayer[indexPlayer].position[nowPlayer[indexPlayer].selectedPion] += dadu;
        nowPlayer[indexPlayer].countStep += dadu ;
        nowPlayer[indexPlayer].onTrackPion[nowPlayer[indexPlayer].selectedPion] = false;
        
        Player = indexPlayer;
		Pion = nowPlayer[indexPlayer].selectedPion;
        visual_move_pion(Player, Pion);
        
        gotoxy(75,7);
		printf("pion %d milik %s finish!\n", selected, nowPlayer[indexPlayer].name);
		gotoxy(75,7);printf("                                                                    ");
		sleep(1);
        check_win();
    }
    else if (nowPlayer[indexPlayer].position[nowPlayer[indexPlayer].selectedPion] + dadu > 47)
    {
        //		nowPlayer[indexPlayer].moveable[nowPlayer[indexPlayer].selectedPion] = '\0';
        nowPlayer[indexPlayer].position[nowPlayer[indexPlayer].selectedPion] = nowPlayer[indexPlayer].position[nowPlayer[indexPlayer].selectedPion];
        gotoxy(75,7);
		printf("pion %d milik %s tidak bisa maju\n", selected, nowPlayer[indexPlayer].name);
		gotoxy(75,7);printf("                                                                    ");
        pion_choose(dadu);
    }
}

void visual_move_pion(Player, Pion)
{
	
	switch(Player)
	{
		case 0:
			switch(nowPlayer[Player].position[Pion])
			{
				case -1:
					if(Pion == 0){gotoxy(10,8);printf("Ï");}
					else if(Pion == 1){gotoxy(17,8);printf("Ï");}
					else if(Pion == 2){gotoxy(10,13);printf("Ï");}
					else if(Pion == 3){gotoxy(17,13);printf("Ï");}
					break;
				case 0: gotoxy(10,23); printf("Ï");break;
				case 1: gotoxy(15,23); printf("Ï");break;
				case 2: gotoxy(20,23); printf("Ï");break;
				case 3: gotoxy(25,23); printf("Ï");break;
				case 4: gotoxy(30,19); printf("Ï");break;
				case 5: gotoxy(30,15); printf("Ï");break;
				case 6: gotoxy(30,11); printf("Ï");break;
				case 7: gotoxy(30,7); printf("Ï");break;
				case 8: gotoxy(30,3); printf("Ï");break;
				case 9: gotoxy(35,3); printf("Ï");break;
				case 10: gotoxy(40,3); printf("Ï");break;
				case 11: gotoxy(40,7); printf("Ï");break;
				case 12: gotoxy(40,11); printf("Ï");break;
				case 13: gotoxy(40,15); printf("Ï");break;
				case 14: gotoxy(40,19); printf("Ï");break;
				case 15: gotoxy(45,23); printf("Ï");break;
				case 16: gotoxy(50,23); printf("Ï");break;
				case 17: gotoxy(55,23); printf("Ï");break;
				case 18: gotoxy(60,23); printf("Ï");break;
				case 19: gotoxy(65,23); printf("Ï");break;
				case 20: gotoxy(65,27); printf("Ï");break;
				case 21: gotoxy(65,31); printf("Ï");break;
				case 22: gotoxy(60,31); printf("Ï");break;
				case 23: gotoxy(55,31); printf("Ï");break;
				case 24: gotoxy(50,31); printf("Ï");break;
				case 25: gotoxy(45,31); printf("Ï");break;
				case 26: gotoxy(40,35); printf("Ï");break;
				case 27: gotoxy(40,39); printf("Ï");break;
				case 28: gotoxy(40,43); printf("Ï");break;
				case 29: gotoxy(40,47); printf("Ï");break;
				case 30: gotoxy(40,51); printf("Ï");break;
				case 31: gotoxy(35,51); printf("Ï");break;
				case 32: gotoxy(30,51); printf("Ï");break;
				case 33: gotoxy(30,47); printf("Ï");break;
				case 34: gotoxy(30,43); printf("Ï");break;
				case 35: gotoxy(30,39); printf("Ï");break;
				case 36: gotoxy(30,35); printf("Ï");break;
				case 37: gotoxy(25,31); printf("Ï");break;
				case 38: gotoxy(20,31); printf("Ï");break;
				case 39: gotoxy(15,31); printf("Ï");break;
				case 40: gotoxy(10,31); printf("Ï");break;
				case 41: gotoxy(5,31); printf("Ï");break;
				case 42: gotoxy(5,27); printf("Ï");break;
				case 43: gotoxy(10,27); printf("Ï");break;
				case 44: gotoxy(15,27); printf("Ï");break;
				case 45: gotoxy(20,27); printf("Ï");break;
				case 46: gotoxy(25,27); printf("Ï");break;
				case 47: 
					if(nowPlayer[indexPlayer].selectedPion == 0) {gotoxy(29,27); printf("Ï");break;}
					else if(nowPlayer[indexPlayer].selectedPion == 1) {gotoxy(31,27); printf("Ï");break;}
					else if(nowPlayer[indexPlayer].selectedPion == 0) {gotoxy(29,28); printf("Ï");break;}
					else if(nowPlayer[indexPlayer].selectedPion == 0) {gotoxy(31,28); printf("Ï");break;}
			}
			switch(nowPlayer[Player].lastPosition[Pion])
			{
				case -1:
					if(Pion == 0){gotoxy(10,8);printf(" ");}
					else if(Pion == 1){gotoxy(17,8);printf(" ");}
					else if(Pion == 2){gotoxy(10,13);printf(" ");}
					else if(Pion == 3){gotoxy(17,13);printf(" ");}
					break;
				case 0: gotoxy(10,23); printf(" ");break;
				case 1: gotoxy(15,23); printf(" ");break;
				case 2: gotoxy(20,23); printf(" ");break;
				case 3: gotoxy(25,23); printf(" ");break;
				case 4: gotoxy(30,19); printf(" ");break;
				case 5: gotoxy(30,15); printf(" ");break;
				case 6: gotoxy(30,11); printf(" ");break;
				case 7: gotoxy(30,7); printf(" ");break;
				case 8: gotoxy(30,3); printf(" ");break;
				case 9: gotoxy(35,3); printf(" ");break;
				case 10: gotoxy(40,3); printf(" ");break;
				case 11: gotoxy(40,7); printf(" ");break;
				case 12: gotoxy(40,11); printf(" ");break;
				case 13: gotoxy(40,15); printf(" ");break;
				case 14: gotoxy(40,19); printf(" ");break;
				case 15: gotoxy(45,23); printf(" ");break;
				case 16: gotoxy(50,23); printf(" ");break;
				case 17: gotoxy(55,23); printf(" ");break;
				case 18: gotoxy(60,23); printf(" ");break;
				case 19: gotoxy(65,23); printf(" ");break;
				case 20: gotoxy(65,27); printf(" ");break;
				case 21: gotoxy(65,31); printf(" ");break;
				case 22: gotoxy(60,31); printf(" ");break;
				case 23: gotoxy(55,31); printf(" ");break;
				case 24: gotoxy(50,31); printf(" ");break;
				case 25: gotoxy(45,31); printf(" ");break;
				case 26: gotoxy(40,35); printf(" ");break;
				case 27: gotoxy(40,39); printf(" ");break;
				case 28: gotoxy(40,43); printf(" ");break;
				case 29: gotoxy(40,47); printf(" ");break;
				case 30: gotoxy(40,51); printf(" ");break;
				case 31: gotoxy(35,51); printf(" ");break;
				case 32: gotoxy(30,51); printf(" ");break;
				case 33: gotoxy(30,47); printf(" ");break;
				case 34: gotoxy(30,43); printf(" ");break;
				case 35: gotoxy(30,39); printf(" ");break;
				case 36: gotoxy(30,35); printf(" ");break;
				case 37: gotoxy(25,31); printf(" ");break;
				case 38: gotoxy(20,31); printf(" ");break;
				case 39: gotoxy(15,31); printf(" ");break;
				case 40: gotoxy(10,31); printf(" ");break;
				case 41: gotoxy(5,31); printf(" ");break;
				case 42: gotoxy(5,27); printf(" ");break;
				case 43: gotoxy(10,27); printf(" ");break;
				case 44: gotoxy(15,27); printf(" ");break;
				case 45: gotoxy(20,27); printf(" ");break;
				case 46: gotoxy(25,27); printf(" ");break;
			}
			break;
		case 1:
			switch(nowPlayer[Player].position[Pion])
			{
				case -1:
					if(Pion == 0){gotoxy(53,8);printf("Ð");}
					else if(Pion == 1){gotoxy(60,8);printf("Ð");}
					else if(Pion == 2){gotoxy(53,13);printf("Ð");}
					else if(Pion == 3){gotoxy(60,13);printf("Ð");}
					break;
				case 0: gotoxy(40,7); printf("Ð");break;
				case 1: gotoxy(40,11); printf("Ð");break;
				case 2: gotoxy(40,15); printf("Ð");break;
				case 3: gotoxy(40,19); printf("Ð");break;
				case 4: gotoxy(45,23); printf("Ð");break;
				case 5: gotoxy(50,23); printf("Ð");break;
				case 6: gotoxy(55,23); printf("Ð");break;
				case 7: gotoxy(60,23); printf("Ð");break;
				case 8: gotoxy(65,23); printf("Ð");break;
				case 9: gotoxy(65,27); printf("Ð");break;
				case 10: gotoxy(65,31); printf("Ð");break;
				case 11: gotoxy(60,31); printf("Ð");break;
				case 12: gotoxy(55,31); printf("Ð");break;
				case 13: gotoxy(50,31); printf("Ð");break;
				case 14: gotoxy(45,31); printf("Ð");break;
				case 15: gotoxy(40,35); printf("Ð");break;
				case 16: gotoxy(40,39); printf("Ð");break;
				case 17: gotoxy(40,43); printf("Ð");break;
				case 18: gotoxy(40,47); printf("Ð");break;
				case 19: gotoxy(40,51); printf("Ð");break;
				case 20: gotoxy(35,51); printf("Ð");break;
				case 21: gotoxy(30,51); printf("Ð");break;
				case 22: gotoxy(30,47); printf("Ð");break;
				case 23: gotoxy(30,43); printf("Ð");break;
				case 24: gotoxy(30,39); printf("Ð");break;
				case 25: gotoxy(30,35); printf("Ð");break;
				case 26: gotoxy(25,31); printf("Ð");break;
				case 27: gotoxy(20,31); printf("Ð");break;
				case 28: gotoxy(15,31); printf("Ð");break;
				case 29: gotoxy(10,31); printf("Ð");break;
				case 30: gotoxy(5,31); printf("Ð");break;
				case 31: gotoxy(5,27); printf("Ð");break;
				case 32: gotoxy(5,23); printf("Ð");break;
				case 33: gotoxy(10,23); printf("Ð");break;
				case 34: gotoxy(15,23); printf("Ð");break;
				case 35: gotoxy(20,23); printf("Ð");break;
				case 36: gotoxy(25,23); printf("Ð");break;
				case 37: gotoxy(30,19); printf("Ð");break;
				case 38: gotoxy(30,15); printf("Ð");break;
				case 39: gotoxy(30,11); printf("Ð");break;
				case 40: gotoxy(30,7); printf("Ð");break;
				case 41: gotoxy(30,3); printf("Ð");break;
				case 42: gotoxy(35,3); printf("Ð");break;
				case 43: gotoxy(35,7);printf("Ð");break;
				case 44: gotoxy(35,11);printf("Ð");break;
				case 45: gotoxy(35,15);printf("Ð");break;
				case 46: gotoxy(35,29);printf("Ð");break;
				case 47: 
					if(nowPlayer[indexPlayer].selectedPion == 0) {gotoxy(34,23); printf("Ð");break;}
					else if(nowPlayer[indexPlayer].selectedPion == 1) {gotoxy(36,23); printf("Ð");break;}
					else if(nowPlayer[indexPlayer].selectedPion == 0) {gotoxy(34,24); printf("Ð");break;}
					else if(nowPlayer[indexPlayer].selectedPion == 0) {gotoxy(36,24); printf("Ð");break;}
			}
			switch(nowPlayer[Player].lastPosition[Pion])
			{
				case -1:
					if(Pion == 0){gotoxy(53,8);printf(" ");}
					else if(Pion == 1){gotoxy(60,8);printf(" ");}
					else if(Pion == 2){gotoxy(53,13);printf(" ");}
					else if(Pion == 3){gotoxy(60,13);printf(" ");}
					break;
				case 0: gotoxy(40,7); printf(" ");break;
				case 1: gotoxy(40,11); printf(" ");break;
				case 2: gotoxy(40,15); printf(" ");break;
				case 3: gotoxy(40,19); printf(" ");break;
				case 4: gotoxy(45,23); printf(" ");break;
				case 5: gotoxy(50,23); printf(" ");break;
				case 6: gotoxy(55,23); printf(" ");break;
				case 7: gotoxy(60,23); printf(" ");break;
				case 8: gotoxy(65,23); printf(" ");break;
				case 9: gotoxy(65,27); printf(" ");break;
				case 10: gotoxy(65,31); printf(" ");break;
				case 11: gotoxy(60,31); printf(" ");break;
				case 12: gotoxy(55,31); printf(" ");break;
				case 13: gotoxy(50,31); printf(" ");break;
				case 14: gotoxy(45,31); printf(" ");break;
				case 15: gotoxy(40,35); printf(" ");break;
				case 16: gotoxy(40,39); printf(" ");break;
				case 17: gotoxy(40,43); printf(" ");break;
				case 18: gotoxy(40,47); printf(" ");break;
				case 19: gotoxy(40,51); printf(" ");break;
				case 20: gotoxy(35,51); printf(" ");break;
				case 21: gotoxy(30,51); printf(" ");break;
				case 22: gotoxy(30,47); printf(" ");break;
				case 23: gotoxy(30,43); printf(" ");break;
				case 24: gotoxy(30,39); printf(" ");break;
				case 25: gotoxy(30,35); printf(" ");break;
				case 26: gotoxy(25,31); printf(" ");break;
				case 27: gotoxy(20,31); printf(" ");break;
				case 28: gotoxy(15,31); printf(" ");break;
				case 29: gotoxy(10,31); printf(" ");break;
				case 30: gotoxy(5,31); printf(" ");break;
				case 31: gotoxy(5,27); printf(" ");break;
				case 32: gotoxy(5,23); printf(" ");break;
				case 33: gotoxy(10,23); printf(" ");break;
				case 34: gotoxy(15,23); printf(" ");break;
				case 35: gotoxy(20,23); printf(" ");break;
				case 36: gotoxy(25,23); printf(" ");break;
				case 37: gotoxy(30,19); printf(" ");break;
				case 38: gotoxy(30,15); printf(" ");break;
				case 39: gotoxy(30,11); printf(" ");break;
				case 40: gotoxy(30,7); printf(" ");break;
				case 41: gotoxy(30,3); printf(" ");break;
				case 42: gotoxy(35,3); printf(" ");break;
				case 43: gotoxy(35,7);printf(" ");break;
				case 44: gotoxy(35,11);printf(" ");break;
				case 45: gotoxy(35,15);printf(" ");break;
				case 46: gotoxy(35,20);printf(" ");break;
			}
			break;
		case 2:
			switch(nowPlayer[Player].position[Pion])
			{
				case -1:
					if(Pion == 0){gotoxy(53,41);printf("þ");}
					else if(Pion == 1){gotoxy(60,41);printf("þ");}
					else if(Pion == 2){gotoxy(53,46);printf("þ");}
					else if(Pion == 3){gotoxy(60,46);printf("þ");}
					break;
				case 0: gotoxy(60,31); printf("þ");break;
				case 1: gotoxy(55,31); printf("þ");break;
				case 2: gotoxy(50,31); printf("þ");break;
				case 3: gotoxy(45,31); printf("þ");break;
				case 4: gotoxy(40,35); printf("þ");break;
				case 5: gotoxy(40,39); printf("þ");break;
				case 6: gotoxy(40,43); printf("þ");break;
				case 7: gotoxy(40,47); printf("þ");break;
				case 8: gotoxy(40,51); printf("þ");break;
				case 9: gotoxy(35,51); printf("þ");break;
				case 10: gotoxy(30,51); printf("þ");break;
				case 11: gotoxy(30,47); printf("þ");break;
				case 12: gotoxy(30,43); printf("þ");break;
				case 13: gotoxy(30,39); printf("þ");break;
				case 14: gotoxy(30,35); printf("þ");break;
				case 15: gotoxy(25,31); printf("þ");break;
				case 16: gotoxy(20,31); printf("þ");break;
				case 17: gotoxy(15,31); printf("þ");break;
				case 18: gotoxy(10,31); printf("þ");break;
				case 19: gotoxy(5,31); printf("þ");break;
				case 20: gotoxy(5,27); printf("þ");break;
				case 21: gotoxy(5,23); printf("þ");break;
				case 22: gotoxy(10,23); printf("þ");break;
				case 23: gotoxy(15,23); printf("þ");break;
				case 24: gotoxy(20,23); printf("þ");break;
				case 25: gotoxy(25,23); printf("þ");break;
				case 26: gotoxy(30,19); printf("þ");break;
				case 27: gotoxy(30,15); printf("þ");break;
				case 28: gotoxy(30,11); printf("þ");break;
				case 29: gotoxy(30,7); printf("þ");break;
				case 30: gotoxy(30,3); printf("þ");break;
				case 31: gotoxy(35,3); printf("þ");break;
				case 32: gotoxy(40,3); printf("þ");break;
				case 33: gotoxy(40,7); printf("þ");break;
				case 34: gotoxy(40,11); printf("þ");break;
				case 35: gotoxy(40,15); printf("þ");break;
				case 36: gotoxy(40,19); printf("þ");break;
				case 37: gotoxy(45,23); printf("þ");break;
				case 38: gotoxy(50,23); printf("þ");break;
				case 39: gotoxy(55,23); printf("þ");break;
				case 40: gotoxy(60,23); printf("þ");break;
				case 41: gotoxy(65,23); printf("þ");break;
				case 42: gotoxy(65,27); printf("þ");break;
				case 43: gotoxy(60,27); printf("þ");break;
				case 44: gotoxy(56,27); printf("þ");break;
				case 45: gotoxy(52,27); printf("þ");break;
				case 46: gotoxy(48,27); printf("þ");break;
				case 47: 
					if(nowPlayer[indexPlayer].selectedPion == 0) {gotoxy(44,27); printf("þ");break;}
					else if(nowPlayer[indexPlayer].selectedPion == 1) {gotoxy(42,27); printf("þ");break;}
					else if(nowPlayer[indexPlayer].selectedPion == 0) {gotoxy(44,28); printf("þ");break;}
					else if(nowPlayer[indexPlayer].selectedPion == 0) {gotoxy(42,28); printf("þ");break;}
			}
			switch(nowPlayer[Player].lastPosition[Pion])
			{
				
				case -1:
					if(Pion == 0){gotoxy(53,41);printf(" ");}
					else if(Pion == 1){gotoxy(60,41);printf(" ");}
					else if(Pion == 2){gotoxy(53,46);printf(" ");}
					else if(Pion == 3){gotoxy(60,46);printf(" ");}
					break;
				case 0: gotoxy(60,31); printf(" ");break;
				case 1: gotoxy(55,31); printf(" ");break;
				case 2: gotoxy(50,31); printf(" ");break;
				case 3: gotoxy(45,31); printf(" ");break;
				case 4: gotoxy(40,35); printf(" ");break;
				case 5: gotoxy(40,39); printf(" ");break;
				case 6: gotoxy(40,43); printf(" ");break;
				case 7: gotoxy(40,47); printf(" ");break;
				case 8: gotoxy(40,51); printf(" ");break;
				case 9: gotoxy(35,51); printf(" ");break;
				case 10: gotoxy(30,51); printf(" ");break;
				case 11: gotoxy(30,47); printf(" ");break;
				case 12: gotoxy(30,43); printf(" ");break;
				case 13: gotoxy(30,39); printf(" ");break;
				case 14: gotoxy(30,35); printf(" ");break;
				case 15: gotoxy(25,31); printf(" ");break;
				case 16: gotoxy(20,31); printf(" ");break;
				case 17: gotoxy(15,31); printf(" ");break;
				case 18: gotoxy(10,31); printf(" ");break;
				case 19: gotoxy(5,31); printf(" ");break;
				case 20: gotoxy(5,27); printf(" ");break;
				case 21: gotoxy(5,23); printf(" ");break;
				case 22: gotoxy(10,23); printf(" ");break;
				case 23: gotoxy(15,23); printf(" ");break;
				case 24: gotoxy(20,23); printf(" ");break;
				case 25: gotoxy(25,23); printf(" ");break;
				case 26: gotoxy(30,19); printf(" ");break;
				case 27: gotoxy(30,15); printf(" ");break;
				case 28: gotoxy(30,11); printf(" ");break;
				case 29: gotoxy(30,7); printf(" ");break;
				case 30: gotoxy(30,3); printf(" ");break;
				case 31: gotoxy(35,3); printf(" ");break;
				case 32: gotoxy(40,3); printf(" ");break;
				case 33: gotoxy(40,7); printf(" ");break;
				case 34: gotoxy(40,11); printf(" ");break;
				case 35: gotoxy(40,15); printf(" ");break;
				case 36: gotoxy(40,19); printf(" ");break;
				case 37: gotoxy(45,23); printf(" ");break;
				case 38: gotoxy(50,23); printf(" ");break;
				case 39: gotoxy(55,23); printf(" ");break;
				case 40: gotoxy(60,23); printf(" ");break;
				case 41: gotoxy(65,23); printf(" ");break;
				case 42: gotoxy(65,27); printf(" ");break;
				case 43: gotoxy(60,27); printf(" ");break;
				case 44: gotoxy(55,27); printf(" ");break;
				case 45: gotoxy(51,27); printf(" ");break;
				case 46: gotoxy(47,27); printf(" ");break;
			}
			break;
		case 3:
			switch(nowPlayer[Player].position[Pion])
			{
				
				case -1:
					if(Pion == 0){gotoxy(10,41);printf("è");}
					else if(Pion == 1){gotoxy(17,41);printf("è");}
					else if(Pion == 2){gotoxy(10,46);printf("è");}
					else if(Pion == 3){gotoxy(17,46);printf("è");}
					break;
				case 0: gotoxy(30,47); printf("è");break;
				case 1: gotoxy(30,43); printf("è");break;
				case 2: gotoxy(30,39); printf("è");break;
				case 3: gotoxy(30,35); printf("è");break;
				case 4: gotoxy(25,31); printf("è");break;
				case 5: gotoxy(20,31); printf("è");break;
				case 6: gotoxy(15,31); printf("è");break;
				case 7: gotoxy(10,31); printf("è");break;
				case 8: gotoxy(5,31); printf("è");break;
				case 9: gotoxy(5,27); printf("è");break;
				case 10: gotoxy(5,23); printf("è");break;
				case 11: gotoxy(10,23); printf("è");break;
				case 12: gotoxy(15,23); printf("è");break;
				case 13: gotoxy(20,23); printf("è");break;
				case 14: gotoxy(25,23); printf("è");break;
				case 15: gotoxy(30,19); printf("è");break;
				case 16: gotoxy(30,15); printf("è");break;
				case 17: gotoxy(30,11); printf("è");break;
				case 18: gotoxy(30,7); printf("è");break;
				case 19: gotoxy(30,3); printf("è");break;
				case 20: gotoxy(35,3); printf("è");break;
				case 21: gotoxy(40,3); printf("è");break;
				case 22: gotoxy(40,7); printf("è");break;
				case 23: gotoxy(40,11); printf("è");break;
				case 24: gotoxy(40,15); printf("è");break;
				case 25: gotoxy(40,19); printf("è");break;
				case 26: gotoxy(45,23); printf("è");break;
				case 27: gotoxy(50,23); printf("è");break;
				case 28: gotoxy(55,23); printf("è");break;
				case 29: gotoxy(60,23); printf("è");break;
				case 30: gotoxy(65,23); printf("è");break;
				case 31: gotoxy(65,27); printf("è");break;
				case 32: gotoxy(65,31); printf("è");break;
				case 33: gotoxy(60,31); printf("è");break;
				case 34: gotoxy(55,31); printf("è");break;
				case 35: gotoxy(50,31); printf("è");break;
				case 36: gotoxy(45,31); printf("è");break;
				case 37: gotoxy(40,35); printf("è");break;
				case 38: gotoxy(40,39); printf("è");break;
				case 39: gotoxy(40,43); printf("è");break;
				case 40: gotoxy(40,47); printf("è");break;
				case 41: gotoxy(40,51); printf("è");break;
				case 42: gotoxy(35,51); printf("è");break;
				case 43: gotoxy(35,47); printf("è");break;
				case 44: gotoxy(35,43); printf("è");break;
				case 45: gotoxy(35,39); printf("è");break;
				case 46: gotoxy(35,35); printf("è");break;
				case 47: 
					if(nowPlayer[indexPlayer].selectedPion == 0) {gotoxy(34,31); printf("è");break;}
					else if(nowPlayer[indexPlayer].selectedPion == 1) {gotoxy(36,31); printf("è");break;}
					else if(nowPlayer[indexPlayer].selectedPion == 0) {gotoxy(34,32); printf("è");break;}
					else if(nowPlayer[indexPlayer].selectedPion == 0) {gotoxy(36,32); printf("è");break;}
			}
			switch(nowPlayer[Player].lastPosition[Pion])
			{
				
				case -1:
					if(Pion == 0){gotoxy(10,41);printf(" ");}
					else if(Pion == 1){gotoxy(17,41);printf(" ");}
					else if(Pion == 2){gotoxy(10,46);printf(" ");}
					else if(Pion == 3){gotoxy(17,46);printf(" ");}
					break;
				case 0: gotoxy(30,47); printf(" ");break;
				case 1: gotoxy(30,43); printf(" ");break;
				case 2: gotoxy(30,39); printf(" ");break;
				case 3: gotoxy(30,35); printf(" ");break;
				case 4: gotoxy(25,31); printf(" ");break;
				case 5: gotoxy(20,31); printf(" ");break;
				case 6: gotoxy(15,31); printf(" ");break;
				case 7: gotoxy(10,31); printf(" ");break;
				case 8: gotoxy(5,31); printf(" ");break;
				case 9: gotoxy(5,27); printf(" ");break;
				case 10: gotoxy(5,23); printf(" ");break;
				case 11: gotoxy(10,23); printf(" ");break;
				case 12: gotoxy(15,23); printf(" ");break;
				case 13: gotoxy(20,23); printf(" ");break;
				case 14: gotoxy(25,23); printf(" ");break;
				case 15: gotoxy(30,19); printf(" ");break;
				case 16: gotoxy(30,15); printf(" ");break;
				case 17: gotoxy(30,11); printf(" ");break;
				case 18: gotoxy(30,7); printf(" ");break;
				case 19: gotoxy(30,3); printf(" ");break;
				case 20: gotoxy(35,3); printf(" ");break;
				case 21: gotoxy(40,3); printf(" ");break;
				case 22: gotoxy(40,7); printf(" ");break;
				case 23: gotoxy(40,11); printf(" ");break;
				case 24: gotoxy(40,15); printf(" ");break;
				case 25: gotoxy(40,19); printf(" ");break;
				case 26: gotoxy(45,23); printf(" ");break;
				case 27: gotoxy(50,23); printf(" ");break;
				case 28: gotoxy(55,23); printf(" ");break;
				case 29: gotoxy(60,23); printf(" ");break;
				case 30: gotoxy(65,23); printf(" ");break;
				case 31: gotoxy(65,27); printf(" ");break;
				case 32: gotoxy(65,31); printf(" ");break;
				case 33: gotoxy(60,31); printf(" ");break;
				case 34: gotoxy(55,31); printf(" ");break;
				case 35: gotoxy(50,31); printf(" ");break;
				case 36: gotoxy(45,31); printf(" ");break;
				case 37: gotoxy(40,35); printf(" ");break;
				case 38: gotoxy(40,39); printf(" ");break;
				case 39: gotoxy(40,43); printf(" ");break;
				case 40: gotoxy(40,47); printf(" ");break;
				case 41: gotoxy(40,51); printf(" ");break;
				case 42: gotoxy(35,51); printf(" ");break;
				case 43: gotoxy(35,47); printf(" ");break;
				case 44: gotoxy(35,43); printf(" ");break;
				case 45: gotoxy(35,39); printf(" ");break;
				case 46: gotoxy(35,35); printf(" ");break;
			}
			break;
	}
}

bool check_win()
{
	int finish = 0;
	int indexPion;
	for(indexPion=0; indexPion<4; indexPion++)
	{
		if(nowPlayer[indexPlayer].position[indexPion] == 47)
		{
			finish++;
		}
	}
	
	if(finish == 4)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool randomAgain(int countRandomDadu, int dadu)
{
	if((dadu == 6) && (countRandomDadu < 3))
	{
		return true;
	}
	else
	{
		return false;
	}
	
}

bool check_kill(int dadu)
{
	int i, j;
	bool safe;
//	int otherPlayerPosition;
	int otherPlayerStart;
	int start;
	for(i=0; i<4; i++)
	{
		// handle pembunuhan
		if (i != indexPlayer)
		{
			otherPlayerStart = 0 + (11 * (i - 0));
			start = 0 + (11 * (indexPlayer - 0));
			
			for(j=0; j<4; j++)
			{
				if (nowPlayer[i].onTrackPion[j])
				{
					if (nowPlayer[i].position[j] + otherPlayerStart > 43)
					{
						otherPlayerStart -= 44;	
					}
					
					if (nowPlayer[indexPlayer].position[nowPlayer[indexPlayer].selectedPion] + start > 43)
					{
						start -= 44;	
					}
					
					if((nowPlayer[i].position[j] - start) == (nowPlayer[indexPlayer].position[nowPlayer[indexPlayer].selectedPion] - otherPlayerStart))
					{
						safe = safezone(nowPlayer[indexPlayer].position[nowPlayer[indexPlayer].selectedPion]);
						if(safe == true)
						{
							return false;
						}
						else if(safe == false)
						{
							return true;
						}	
					}	
				}
			}
		}
	}
	
}

bool safezone(int position)
{
	switch(position)
	{
		case 0:
		case 6: 
		case 11:
		case 17:
		case 22:
		case 28:
		case 33:
		case 39:
		case 43:
		case 44:
		case 45:
		case 46:
			return true;
			break;
			
		default:
			return false;
			break;
	}
}

void killing(int dadu)
{
	int i, j;
//	int otherPlayerPosition;
	int otherPlayerStart;
	int start;
	int Player, Pion;
	for(i=0; i<4; i++)
	{
		// handle pembunuhan
		if (i != indexPlayer)
		{
			otherPlayerStart = 0 + (11 * (i - 0));
			start = 0 + (11 * (indexPlayer - 0));
			
			for(j=0; j<4; j++)
			{
				if (nowPlayer[i].onTrackPion[j])
				{
					if (nowPlayer[i].position[j] + otherPlayerStart > 43)
					{
						otherPlayerStart -= 44;	
					}
					
					if (nowPlayer[indexPlayer].position[nowPlayer[indexPlayer].selectedPion] + start > 43)
					{
						start -= 44;	
					}
	
					if((nowPlayer[i].position[j] - start) == (nowPlayer[indexPlayer].position[nowPlayer[indexPlayer].selectedPion] - otherPlayerStart))
					{
						nowPlayer[i].position[j] = -1;
						nowPlayer[i].onTrackPion[j] = false;
						Player = i;
						Pion = j;
						gotoxy(75,6);printf("                                                                    ");
						gotoxy(75,6);printf("Pion %d milik %s kembali ke Home.", j+1, nowPlayer[i].name);
						visual_move_pion(Player, Pion);
						gotoxy(75,7);system("pause");
					}	
				}
			}
		}
	}
}

void game_over()
{
	int score;
	if(indexPlayer == 0)
	{
		int i, j=0;
	 	system("cls");
	 	FILE *credits = fopen("congratulation.txt", "r");
	 	char ch[512];
		while((fgets(ch, 512, credits)) != NULL)
		{
			gotoxy(45,10+j);
			printf("%s", ch);
			for(i=0; i<50000000; i++){}
			j++;
		}
	 	fclose(credits);
//	 	score = check_score();
	 	printf("\n");
	 	printf("%s memenangkan permainan!", nowPlayer[indexPlayer].name);
//	 	printf("Score: %d", score);
	 	return;
	}
	else
	{
		int i, j=0;
	 	system("cls");
	 	FILE *credits = fopen("gameOver.txt", "r");
	 	char ch[512];
		while((fgets(ch, 512, credits)) != NULL)
		{
			gotoxy(60,10+j);
			printf("%s", ch);
			for(i=0; i<50000000; i++){}
			j++;
		}
	 	fclose(credits);
	 	printf("\n");
	 	printf("%s memenangkan permainan.\n", nowPlayer[indexPlayer].name);
	 	printf("Jangan menyerah!");
	 	return;
	}
}

int noOneHome(int dadu)
{
	int allHome = 0;
	int indexPion;
	int selected;
	int mostBehind;
	if(dadu == 6)
	{
		for(indexPion=0; indexPion<4; indexPion++)
		{
			if(nowPlayer[indexPlayer].position[indexPion] == -1)			//kalau masih ada yang di home, keluarkan
			{
				allHome++;
				nowPlayer[indexPlayer].selectedPion = indexPion;
				selected = indexPion+1;
				return selected;
			}
		}
		if(allHome == 0)		//noOneHome, everyone onTrack
		{
			mostBehind = nowPlayer[indexPlayer].position[0];
			for(indexPion=0; indexPion<4; indexPion++)
			{
				if((nowPlayer[indexPlayer].position[indexPion] != -1) && (nowPlayer[indexPlayer].position[indexPion] < mostBehind))		//pilih pion moveable paling belakang.
				{
					mostBehind = nowPlayer[indexPlayer].position[indexPion];
					nowPlayer[indexPlayer].selectedPion = indexPion;
					selected = indexPion+1;
				}
			}
			return selected;
		}
	}
	if(dadu < 6)
	{
		mostBehind = nowPlayer[indexPlayer].position[0];
		for(indexPion=0; indexPion<4; indexPion++)
		{
			if((nowPlayer[indexPlayer].position[indexPion] != -1) && (nowPlayer[indexPlayer].position[indexPion] < mostBehind))		//pilih pion moveable paling belakang.
			{
				mostBehind = nowPlayer[indexPlayer].position[indexPion];
				nowPlayer[indexPlayer].selectedPion = indexPion;
				selected = indexPion+1;
			}
		}
		return selected;
	}
}

int furtherMost(int dadu)
{
	int indexPion;
	int selected;
	for(indexPion=0; indexPion<4; indexPion++)
	{
		if(nowPlayer[indexPlayer].moveable[indexPion] == indexPion)
		{
			nowPlayer[indexPlayer].selectedPion = indexPion;
			selected = indexPion+1;
			return selected;
		}
	}
}
	
int killer(int dadu)
{
	//versi 5 (edited by: Rey Rizki)
	int selected;
	int indexPion;
	int otherPlayerPosition;
	int otherPlayerStart;
	int start;
	int canKill = 0;
	int i,j,k,l;
	
	for(indexPion=0; indexPion<4; indexPion++)
	{
		if(nowPlayer[indexPlayer].moveable[indexPion] == indexPion)
		{
			break;
		}
		else
		{
			// ini diubah jadi continue
			continue;
		}
	}
	
	for(i=0; i<jmlPlayer; i++)
	{
		if (i != indexPlayer)
		{
			otherPlayerStart = 0 + (11 * (i - 0));
			start = 0 + (11 * (indexPlayer - 0));
			
			// hitung banyak pembunuhan yang bisa dilakukan
			for(j=0; j<4; j++)
			{
				for(k=0; k<4; k++)
				{
					if(nowPlayer[indexPlayer].moveable[k] == k)
					{
						if (nowPlayer[i].onTrackPion[j])
						{
							if(((nowPlayer[i].position[j] - start) - ((nowPlayer[indexPlayer].position[k] - otherPlayerStart)+dadu)) == 0 )
							{
								canKill++;
								// ini jadi indexPlayer yak, bukan indexPion
								nowPlayer[indexPlayer].selectedPion = k;
								selected = k+1;
								return selected;
							}	
						}
					}
				}	
			}
		}
	}
	
	if (canKill == 0)
	{
		for(i=0; i<jmlPlayer; i++)
		{
			if (i != indexPlayer)
			{
				otherPlayerStart = 0 + (11 * (i - 0));
				start = 0 + (11 * (indexPlayer - 0));
				
				for(j=0; j<4; j++)
				{
					for(k=0; k<4; k++)
					{
						if(nowPlayer[indexPlayer].moveable[k] == k)
						{
							if(((nowPlayer[i].position[j] - start) - ((nowPlayer[indexPlayer].position[k] - otherPlayerStart) + dadu)) <= 6 )
							{
								// ini juga harusnya indexPlayer
								nowPlayer[indexPlayer].selectedPion = k;
								selected = k+1;
								return selected;
								break;
							}
							
						}
						
					}
				}
			}
		}
	}
	
	int further = -1;
	int select = 0;
	for(k=3; k>=0; k--)
	{
		if(nowPlayer[indexPlayer].position[k] > further)
		{
			further = nowPlayer[indexPlayer].position[k];
			select = k;
		}
	}
	nowPlayer[indexPlayer].selectedPion = select;
	selected = select + 1;
	return selected;
		
		/*
		if (i != indexPlayer)
		{
			if(i == 0)
			{
				otherPlayerStart = 0;
			}
			else if(i == 1)
			{
				otherPlayerStart = 11;
			}
			else if(i == 2)
			{
				otherPlayerStart = 22;
			}
			else if(i == 3)
			{
				otherPlayerStart = 33;
			}
		}
		else if(i == indexPlayer)
		{
			if(i == 0)
			{
				start = 0;
			}
			else if(i == 1)
			{
				start = 11;
			}
			else if(i == 2)
			{
				start = 22;
			}
			else if(i == 3)
			{
				start = 33;
			}
		}
		
		// hitung banyak pembunuhan yang bisa dilakukan
		for(j=0; j<4; j++)
		{
			for(k=0; k<4; k++)
			{
				if(nowPlayer[indexPlayer].moveable[k] == k)
				{
					if (nowPlayer[i].onTrackPion[j])
					{
						if(((nowPlayer[i].position[j]-otherPlayerStart) - ((nowPlayer[indexPlayer].position[k]-start)+dadu)) == 0 )
						{
							canKill++;
							// ini jadi indexPlayer yak, bukan indexPion
							nowPlayer[indexPlayer].selectedPion = k;
							selected = k+1;
							return selected;
						}	
					}
				}
				
			}	
		}
	}
	*/
	
	/*
	// mendekati calon korban
	if(canKill == 0)
	{
		for(i=0; i<jmlPlayer; i++)
		{
			if (i != indexPlayer)
			{
				if(i == 0)
				{
					otherPlayerStart = 0;
				}
				else if(i == 1)
				{
					otherPlayerStart = 11;
				}
				else if(i == 2)
				{
					otherPlayerStart = 22;
				}
				else if(i == 3)
				{
					otherPlayerStart = 33;
				}
			}
			else if(i == indexPlayer)
			{
				if(i == 0)
				{
					start = 0;
				}
				else if(i == 1)
				{
					start = 11;
				}
				else if(i == 2)
				{
					start = 22;
				}
				else if(i == 3)
				{
					start = 33;
				}
			}
			for(j=0; j<4; j++)
			{
				for(k=0; k<4; k++)
				{
					if(nowPlayer[indexPlayer].moveable[k] == k)
					{
						if(((nowPlayer[i].position[j]-otherPlayerStart) - ((nowPlayer[indexPlayer].position[k]-start)+dadu)) <= 6 )
						{
							// ini juga harusnya indexPlayer
							nowPlayer[indexPlayer].selectedPion = k;
							selected = k+1;
							return selected;
							break;
						}
						
					}
					
				}
			}
		}
	}
	*/
	// berjalan seperti Yamaha
	
	/*
	else
	{
		int further = -1;
//		int further = nowPlayer[indexPlayer].position[0];
		int select = 0;
		for(k=3; k>=0; k--)
		{
			if(nowPlayer[indexPlayer].position[k] > further)
			{
				further = nowPlayer[indexPlayer].position[k];
				select = k;
			}
		}
		nowPlayer[indexPlayer].selectedPion = select;
		selected = select + 1;
		return selected;
	}
	*/
	
	

	//versi 4
//	int selected;
//	int indexPion;
//	int otherPlayerPosition;
//	int otherPlayerStart;
//	int start;
//	int canKill = 0;
//	int i,j,k,l;
//	
//	for(indexPion=0; indexPion<4; indexPion++)
//	{
//		if(nowPlayer[indexPlayer].moveable[indexPion] == indexPion)
//		{
//			break;
//		}
//		else if(nowPlayer[indexPlayer].moveable[indexPion] != indexPion)
//		{
//			nowPlayer[indexPlayer].selectedPion = indexPion;
//			selected = indexPion+1;		
//			return selected;
//			break;
//		}
//	}
//	for(i=0; i<jmlPlayer; i++)
//	{
//		if (i != indexPlayer)
//		{
//			if(i == 0)
//			{
//				otherPlayerStart = 0;
//			}
//			else if(i == 1)
//			{
//				otherPlayerStart = 11;
//			}
//			else if(i == 2)
//			{
//				otherPlayerStart = 22;
//			}
//			else if(i == 3)
//			{
//				otherPlayerStart = 33;
//			}
//		}
//		else if(i == indexPlayer)
//		{
//			if(i == 0)
//			{
//				start = 0;
//			}
//			else if(i == 1)
//			{
//				start = 11;
//			}
//			else if(i == 2)
//			{
//				start = 22;
//			}
//			else if(i == 3)
//			{
//				start = 33;
//			}
//		}
//		for(j=0; j<4; j++)
//		{
//			for(k=0; k<4; k++)
//			{
//				if(nowPlayer[indexPlayer].moveable[k] == k)
//				{
//					if((nowPlayer[i].position[j]-otherPlayerStart) - ((nowPlayer[indexPlayer].position[k]-start)+dadu) == 0 )
//					{
//						canKill++;
//						nowPlayer[indexPion].selectedPion = k;
//						selected = k+1;
//						return selected;
//						break;
//					}
//					
//				}
//				
//			}
//			
//		}
//	}
//	if(canKill == 0)
//	{
//		for(i=0; i<jmlPlayer; i++)
//		{
//			if (i != indexPlayer)
//			{
//				if(i == 0)
//				{
//					otherPlayerStart = 0;
//				}
//				else if(i == 1)
//				{
//					otherPlayerStart = 11;
//				}
//				else if(i == 2)
//				{
//					otherPlayerStart = 22;
//				}
//				else if(i == 3)
//				{
//					otherPlayerStart = 33;
//				}
//			}
//			else if(i == indexPlayer)
//			{
//				if(i == 0)
//				{
//					start = 0;
//				}
//				else if(i == 1)
//				{
//					start = 11;
//				}
//				else if(i == 2)
//				{
//					start = 22;
//				}
//				else if(i == 3)
//				{
//					start = 33;
//				}
//			}
//			for(j=0; j<4; j++)
//			{
//				for(k=0; k<4; k++)
//				{
//					if(nowPlayer[indexPlayer].moveable[k] == k)
//					{
//						if((nowPlayer[i].position[j]-otherPlayerStart) - ((nowPlayer[indexPlayer].position[k]-start)+dadu) < 7 )
//						{
//							nowPlayer[indexPion].selectedPion = k;
//							selected = k+1;
//							return selected;
//							break;
//						}
//						
//					}
//					
//				}
//				
//			}
//		}
//	}
//	else
//	{
//		int further = nowPlayer[indexPlayer].position[0];
//		int select = 0;
//		for(k=1; k<4; k++)
//		{
//			if(nowPlayer[indexPlayer].position[k] > further)
//			{
//				further = nowPlayer[indexPlayer].position[k];
//				select = k;
//			}
//		}
//		nowPlayer[indexPlayer].selectedPion = select;
//		selected = select + 1;
//		return selected;
//		
//	}

//	for(indexPion=0; indexPion <4; indexPion ++)
//	{
//		if(nowPlayer[indexPlayer].onTrackPion[indexPion] == true)
//		{
//			for(j=0; j<jmlPlayer; j++)
//			{
//				if(indexPlayer == 1)
//				{
//					if(nowPlayer[indexPlayer].position[indexPion]+dadu == nowPlayer[j].position[k]+11)			//versi 3
//					{
//						nowPlayer[indexPlayer].selectedPion = indexPion;
//						selected = indexPion+1;
//						return selected;
//					}
//				}
//				else if(indexPlayer == 2)
//				{
//					if(nowPlayer[indexPlayer].position[indexPion]+dadu == nowPlayer[j].position[k]+22)
//					{
//						nowPlayer[indexPlayer].selectedPion = indexPion;
//						selected = indexPion+1;
//						return selected;
//					}
//				}
//				else if(indexPlayer == 3)
//				{
//					if(nowPlayer[j].position[k] <= 42)
//					{
//						otherPlayerPosition = nowPlayer[j].position[k];
//						
//						if(otherPlayerPosition > 33)
//						{
//							otherPlayerPosition -= 33;
//						}
//						else if(otherPlayerPosition)
//						
//						if(nowPlayer[indexPlayer].position[indexPion]+dadu <= otherPlayerPosition)
//						{
//							nowPlayer[indexPlayer].selectedPion = indexPion;
//							selected = indexPion+1;
//							return selected;
//						}
//					}
//				}
//			}
//		}
//	}
	
	
	
	
	
	
	
//	if(nowPlayer[indexPlayer].onTrackPion[indexPion] == true)
//	{
//		
//		if(indexPlayer = 1)
//		{
//			if(nowPlayer[indexPlayer].position[indexPion]+dadu == nowPlayer[0].position[k]+11)						//versi 2
//			{
//				nowPlayer[indexPlayer].selectedPion = indexPion;
//				selected = indexPion+1;
//				return selected;
//			}
//		}
//		else if(indexPlayer = 2)
//		{
//			if(nowPlayer[indexPlayer].position[indexPion]+dadu == nowPlayer[0].position[k]+22)
//			{
//			nowPlayer[indexPlayer].selectedPion = indexPion;
//			selected = indexPion+1;
//			return selected;
//			}
//		}
//		else if(indexPlayer = 3)
//		{
//			if(nowPlayer[indexPlayer].position[indexPion]+dadu == nowPlayer[0].position[k]+33)
//			{
//				nowPlayer[indexPlayer].selectedPion = indexPion;
//				selected = indexPion+1;
//				return selected;
//			}
//		}	
//	}
//	
//
//	
//	if(dadu == 6)
//	{
//		
//		for(indexPion=0; indexPion<4; indexPion++)
//		{
//			if(nowPlayer[indexPlayer].onTrackPion[indexPion] == true)
//			{
//				for(k=0; k<4; k++)			//index setiap pion milik user
//				{
//					if(indexPlayer = 1)
//					{
//						if(nowPlayer[indexPlayer].position[indexPion]+dadu == nowPlayer[0].position[k]+11)
//						{
//							nowPlayer[indexPlayer].selectedPion = indexPion;
//							selected = indexPion+1;
//							return selected;
//						}
//						
//					}
//					else if(indexPlayer = 2)
//					{
//						if(nowPlayer[indexPlayer].position[indexPion]+dadu == nowPlayer[0].position[k]+22)					//versi 1
//						{
//							nowPlayer[indexPlayer].selectedPion = indexPion;
//							selected = indexPion+1;
//							return selected;
//						}
//						
//					}
//					else if(indexPlayer = 3)
//					{
//						if(nowPlayer[indexPlayer].position[indexPion]+dadu == nowPlayer[0].position[k]+33)
//						{
//							nowPlayer[indexPlayer].selectedPion = indexPion;
//							selected = indexPion+1;
//							return selected;
//						}
//						
//					}
//				}	
//			}
//			else if(nowPlayer[indexPlayer].onTrackPion[indexPion] == false)
//			{
//				nowPlayer[indexPlayer].selectedPion = indexPion;
//				selected = indexPion+1;
////				notOnHome ++;
//				return selected;
//			}
//		}
//			
//	}
//	else if(dadu < 6)
//	{
//		for(indexPion=0; indexPion<4; indexPion++)
//		{
//			if(nowPlayer[indexPlayer].onTrackPion[indexPion] == true)
//			{
//				for(j=0; j<4; j++)				//index player lain
//				{
//					for(k=0; k<4; k++)			//index setiap pion milik pemain lain
//					{
//						if(j != indexPlayer)
//						{
//							if(nowPlayer[indexPlayer].position[indexPion]+dadu == nowPlayer[j].position[k])
//							{
//								nowPlayer[indexPlayer].selectedPion = indexPion;
//								selected = indexPion+1;
//								return selected;
//							}
//							
//						}
//					}
//					
//				}	
//			}
//
//		}
//	}
}


