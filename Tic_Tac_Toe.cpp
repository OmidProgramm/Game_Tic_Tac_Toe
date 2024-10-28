#include <iostream>
#include <windows.h>
#include<iomanip>
#include <conio.h>

using namespace std;
char zahl[]={'1','2','3','4','5','6','7','8','9'}; 
int Dran = 1;//
int punkt[2]={0,0};
int runde=0;
string Spieler[2];//
void spielerName(void);
void gotoxy(int,int);
void setColor(int);
string werDran(void);
char DieRunde(void);//
void ANZEIGE(void);//
void Eingabe(void);//
bool Gewinner(void);//
bool tableFull(void);
bool SpielEnde(void);//
string Ergibnis(void);//
int Punkt(void);//
void result(void);
void zuruckGesetzt(void);
void endeSeason(void);
void spielStand(void);
int main(void)
{
	char temp;  
	spielerName();
	do
	{
		runde++;
		system("cls");
		while(SpielEnde())
		{
			ANZEIGE();
			Eingabe();
			system("cls");		
		}
		ANZEIGE();
		cout<<endl<<"\n\t\t\t"<<Ergibnis()<< " hat gewonnen."<<endl;
		Punkt();
		setColor(15);
		result();
		do{
			system("cls");
			cout << "\nWollen Sie weiter spielen: j oder n: ";
			temp=getch();
			temp = toupper(temp);
		}while(!(temp=='J'||temp=='N'));
		if(temp!='N')zuruckGesetzt();
	}while(temp!='N');
	setColor(7);
	endeSeason();
	return 0;
}
void gotoxy(int x, int y)
{
  COORD coord;
  coord.X = x;
  coord.Y = y;
  SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
void setColor(int color)
{
  HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
  SetConsoleTextAttribute(hConsole, color);
}
void spielerName()
{
	string temp;
	setColor(15);
	cout << "gib den Namen des ersten Spielers ein : ";
	cin >>temp;
	if(temp[0]>='a' && temp[0]<='z')temp[0]=toupper(temp[0]); 
	
	for(int i=1; i<temp.length();i++)
	{
		if(temp[i]>='A' && temp[i]<='Z')temp[i]=tolower(temp[i]);
	}
	Spieler[0]=temp;
	cout << "gib den Namen des zweiten Spielers ein : ";
	cin >>temp;
	if(temp[0]>='a' && temp[0]<='z')temp[0]=toupper(temp[0]);
	
	for(int i=1; i<temp.length();i++)
	{
		if(temp[i]>='A' && temp[i]<='Z')temp[i]=tolower(temp[i]);
	}
	Spieler[1]=temp;	
}
void ANZEIGE()
{
	gotoxy(10,3);
	setColor(15);
	cout << "Spieler 1 ist: "<<Spieler[0]<<" \t\tSpieler 2 ist: "<<Spieler[1];
	gotoxy(30,5);
	setColor(15);
	cout << "-------------------";
	gotoxy(30,6);
	cout << "|  "<<"   |  "<<"   |  "<<"   |";
	gotoxy(30,7);
	cout << "-------------------";
	gotoxy(30,8);
	cout << "|  "<<"   |  "<<"   |  "<<"   |";
	gotoxy(30,9);
	cout << "-------------------";
	gotoxy(30,10);
	cout << "|  "<<"   |  "<<"   |  "<<"   |";
	gotoxy(30,11);
	cout << "-------------------";
	int x=33,y=6;
	for(int i=0;i<9;i++)
	{
		gotoxy(x,y);
		if(zahl[i]=='X')setColor(10);
		else if(zahl[i]=='O')setColor(14);
		else
			setColor(15);
			cout <<zahl[i];
		x+=6;
		if(x>=48)
		{
			y+=2;
			x=33;
		}
	}
	spielStand();	
}
char DieRunde(){
	if(Dran%2==0)return 'X';
	else
		return 'O';	
}
string werDran()
{
	if(DieRunde()=='X')return Spieler[0];
	else
		return Spieler[1];
}
void Eingabe()
{
	char eingabe;
	do
	{
		gotoxy(5,13); 
		setColor(15);
		cout << werDran() << " -> "<< DieRunde()<< " : ";	
		eingabe = getch();

	}while(!(eingabe>='1' && eingabe<='9') ||zahl[eingabe-49]=='X' || zahl[eingabe-49]=='O');
	zahl[eingabe-49]= DieRunde();
}
bool tableFull()
{
	for(int i=0; i<9;i++)
	{
		if(zahl[i]!='X' && zahl[i]!='O')return false;
	}
	return true;
}
bool Gewinner()
{
	if(zahl[0] == zahl[1] && zahl[1] ==  zahl[2]) return true;
	if(zahl[3] == zahl[4] && zahl[4] ==  zahl[5]) return true;
	if(zahl[6] == zahl[7] && zahl[7] ==  zahl[8]) return true;
	if(zahl[0] == zahl[4] && zahl[4] ==  zahl[8]) return true;
	if(zahl[2] == zahl[4] && zahl[4] ==  zahl[6]) return true;
	if(zahl[0] == zahl[3] && zahl[3] ==  zahl[6]) return true;
	if(zahl[1] == zahl[4] && zahl[4] ==  zahl[7]) return true;
	if(zahl[2] == zahl[5] && zahl[5] ==  zahl[8]) return true;
	else {
		return false;
	}
}
bool SpielEnde() 
{
	if(Gewinner() || tableFull()) return false;
	else
	{
		Dran++;
		return true;
	}
}
string Ergibnis()
{ 
	if(tableFull())return "keiner ";
	else
		return werDran();
}
void result()
{
	system("cls");
	string temp = Ergibnis();
	string test = Spieler[0];
	string test2 = Spieler[1];
	if(temp==test)cout << test << " hat drei Punkte bekommen.\n";
	else if(temp==test2)cout << test2 << " hat drei Punkte bekommen.\n";
	else
	{
		cout << test << " hat 1 Punkte bekommen.\n";
		cout << test2 << " hat 1 Punkte bekommen.\n";
	}
}
int Punkt()
{
	system("cls");
	string temp = Ergibnis();
	string test = Spieler[0];
	string test2 = Spieler[1];
	if(temp==test)
	{
		punkt[0] +=3;
		return punkt[0];
	}
	else if(temp==test2)
	{
		punkt[1] +=3;
		return punkt[1];
	}
	else
	{
		punkt[0]+=1;
		punkt[1]+=1;
		return punkt[0],punkt[1];
	}
}
void zuruckGesetzt()
{
	for(int i=0;i<9;i++){
		zahl[i]=49+i;
	}
	Dran+1;
}
void endeSeason(){
	system("cls");
	setColor(15);
	cout<<runde<<" Runde sind gespielt.";
	cout<<endl<<"\n"<<Spieler[0] << " hat " << punkt[0]<< " Punkte bekommen\n";
	cout<<endl<<"\n"<<Spieler[1] << " hat " << punkt[1]<< " Punkte bekommen\n";
	if(punkt[0]>punkt[1])cout<<"\nder Gewinner ist: "<<Spieler[0] <<endl;
	else if(punkt[1]>punkt[0])cout<<"\nder Gewinner ist: "<<Spieler[1] <<endl;
	else
		cout << "\nEs ist unentschieden.\n";
}
void spielStand(){
	gotoxy(85,5);
	setColor(15);
	cout << "SPIELSTAND\n";
	gotoxy(85,7);
	setColor(15);
	cout << Spieler[0] << " --> "<< punkt[0]<<endl;
	gotoxy(85,9);
	setColor(15);
	cout << Spieler[1] << " --> "<< punkt[1]<<endl;
}
