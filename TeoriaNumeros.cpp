/*Elaborar un algoritomo que permite conocer los multiplos de un numero, determine los divisores, los numeros primos, el MCM y el MCD
Con un menú que diga:	
1.-Múltiplos
2.-Divisores
3.-Número primo
4.-MCM
5.-MCD
6.-Decimal a Binario
7.- Binario a decimal
8.- Decimal a Hexadecimal
9.- Hexadecimal a Decimal
10.- Decimal a Octal
11.- Octal a Decimal
12.- Suma Decimal
13.- Suma Binaria
14.- Suma Hexadecimal
*/

#include <iostream>
#include <windows.h>
#include <conio.h>
#include <string.h>
#include <clocale>
#include <cmath>

#define ARRIBA 72
#define ABAJO 80
#define ENTER 13

using namespace std;

HANDLE l = GetStdHandle(STD_OUTPUT_HANDLE);

string nombre="";
// Muestra la salida del CMD en las coordenadas x y
void gotoxy(int x, int y){
	HANDLE hCon;
	hCon = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD dwPos;
	dwPos.X = x;
	dwPos.Y = y;
	
	SetConsoleCursorPosition(hCon, dwPos);
}

// Oculta la posición del Cursor
void OcultarCursor(){
	HANDLE hCon;
	hCon = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO cci;
	cci.dwSize = 2;
	cci.bVisible = FALSE;
	
	SetConsoleCursorInfo(hCon, &cci);
}

// Muesta la Posición del Cursor
void MostrarCursor(){
	HANDLE hCon;
	hCon = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO cci;
	cci.dwSize = 2;
	cci.bVisible = TRUE;
	
	SetConsoleCursorInfo(hCon, &cci);
}

// Presenta a la inicio del programa un pequeño banner del tema
void Dos(){
	int y=240;
	OcultarCursor();
	while(kbhit()==false){
		OcultarCursor();
		SetConsoleTextAttribute(l,y);
		cout<<"\t\t_|_|_|_|_|  _|_|_|_|    _|_|    _|_|_|    _|_|_|    _|_|    \n";
		cout<<"\t\t    _|      _|        _|    _|  _|    _|    _|    _|    _|  \n";
		cout<<"\t\t    _|      _|_|_|    _|    _|  _|_|_|      _|    _|_|_|_|  \n";
		cout<<"\t\t    _|      _|        _|    _|  _|    _|    _|    _|    _|  \n";
		cout<<"\t\t    _|      _|_|_|_|    _|_|    _|    _|  _|_|_|  _|    _|  \n";
		cout<<"\t\t                    \n";
		cout<<"\t\t_|_|_|    _|_|_|_|  \n";
		cout<<"\t\t_|    _|  _|        \n";
		cout<<"\t\t_|    _|  _|_|_|    \n";
		cout<<"\t\t_|    _|  _|        \n";
		cout<<"\t\t_|_|_|    _|_|_|_|  \n";
		cout<<"                    \n";
		cout<<"\t\t_|      _|  _|    _|  _|      _|  _|_|_|_|  _|_|_|      _|_|      _|_|_|  \n";
		cout<<"\t\t_|_|    _|  _|    _|  _|_|  _|_|  _|        _|    _|  _|    _|  _|        \n";
		cout<<"\t\t_|  _|  _|  _|    _|  _|  _|  _|  _|_|_|    _|_|_|    _|    _|    _|_|    \n";
		cout<<"\t\t_|    _|_|  _|    _|  _|      _|  _|        _|    _|  _|    _|        _|  \n";
		cout<<"\t\t_|      _|    _|_|    _|      _|  _|_|_|_|  _|    _|    _|_|    _|_|_|    \n";
		cout<<"\t\t   ____  _  _  _   \n";
		cout<<"\t\t  (  _ \\( \\/ )(_)\n";  
		cout<<"\t\t   ) _ ( )  /  _   \n";
		cout<<"\t\t  (____/(__/  (_) \n";
		cout<<"\t\t     ____                     _   ______           _             \n";
		cout<<"\t\t    / __ \\                   | | |___  /          (_)            \n";
		cout<<"\t\t   | |  | |___ _ __ ___   ___| |    / /_   _ _ __  _  __ _  __ _ \n";
		cout<<"\t\t   | |  | / __| '_ ` _ \\ / _ \\ |   / /| | | | '_ \\| |/ _` |/ _` |\n";
		cout<<"\t\t   | |__| \\__ \\ | | | | |  __/ |  / /_| |_| | | | | | (_| | (_| |\n";
		cout<<"\t\t    \\____/|___/_| |_| |_|\\___|_| /_____\\__,_|_| |_|_|\\__, |\\__,_|\n";
		cout<<"\t\t                                                      __/ |      \n";
		cout<<"\t\t                                                     |___/       \n";
		y++;
    	if ( y >254) y=240;
        Sleep(500);
        system("cls");
	}
	getch();
	system("cls");
}

// Da una breve bienvenida al usuario y le da a entender el funcionamiento del programa, así como también le solicita un nombre de Usuario
void Bienvenida(){
	SetConsoleTextAttribute(l,241);
	cout<<"\t\tBienvenido al programa de Teoría de números.\n\n";
	SetConsoleTextAttribute(l,240);
	cout<<"Esté programa consiste en una serie de opciones, las cuales le permitirá calcular los múltplos, divisores, primos, mcd,\nmcm de un número,\
	\b\b\b\b\b\btambién, le ayudará a convertir bases, ya sea de Base10 a Base8, Base2 a Base10...\nPara terminar, también le dejará sumar números decimales, binarios y\
	\b\b\bhexadecimales.\n";
	cout<<"\n\nPor favor, ingrese su nombre para continuar. \"Lo puede dejar vacio\" \n";
	SetConsoleTextAttribute(l,241);
	cout<<"Nombre: ";
	SetConsoleTextAttribute(l,240);
	MostrarCursor();
	getline(cin,nombre);
	
	cout<<"\nMUCHAS GRACIAS POR USAR EL PROGRAMA!!!";
	Sleep(200);
//	getch();
	system("cls");
}

// En está función tiene un único propisito, el cual es finalizar el programa cuando el usuario presione alguna tecla
void WaitKey(){
	int y=240;
//	SetConsoleTextAttribute(l,175);
	while(kbhit()==false){
		SetConsoleTextAttribute(l,y);
    	gotoxy(54,14);cout<<"PRESS ANY KEY";
    	y++;
    	if ( y >254) y=240;
        Sleep(250);
        system("cls");
	}
	gotoxy(54,14);exit(0);
    SetConsoleTextAttribute(l,240);
}

// En está función tiene un único propisito, el cual es mostrar un mensaje cuando se regrese al menú principal
void Menu(){
	SetConsoleTextAttribute(l,230);
	system("cls");
	cout<<"[INFO] Regresando al Menú principal .";
	Sleep(500);
	system("cls");
	cout<<"[INFO] Regresando al Menú principal . .";
	Sleep(500);
	system("cls");
	cout<<"[INFO] Regresando al Menú principal . . .";
	Sleep(500);
	system("cls");
	system("color F0");
	SetConsoleTextAttribute(l,240);
}

// En está función tiene un único propisito, el cual es mostrar un mensaje cuando se regrese al Sub-menú
void SubMenu(){
	SetConsoleTextAttribute(l,230);
	system("cls");
	cout<<"[INFO] Regresando al Sub-Menú .";
	Sleep(500);
	system("cls");
	cout<<"[INFO] Regresando al Sub-Menú . .";
	Sleep(500);
	system("cls");
	cout<<"[INFO] Regresando al Sub-Menú . . .";
	Sleep(500);
	system("cls");
	system("color F0");
	SetConsoleTextAttribute(l,240);
}

// Está función tiene un único proposito el cual es solicitarle los datos al usuario y enviarlos a la función seleccionado en el menú correspodiente
void Pedir(long long &numUno, long long &numDos, int subOp, int op){
	MostrarCursor();
	bool validar=true;
	do{
		if(op==1){
			if(subOp!=4 and subOp!=5 and subOp!=6){
				SetConsoleTextAttribute(l,249);
				cout<<"Ingrese un número entero: ";
				SetConsoleTextAttribute(l,240);
				cin>>numUno;
			}else{
				SetConsoleTextAttribute(l,249);
				cout<<"Ingrese un número entero: ";
				SetConsoleTextAttribute(l,240);
				cin>>numUno;
				SetConsoleTextAttribute(l,249);
				cout<<"Ingrese otro número entero: ";
				SetConsoleTextAttribute(l,240);
				cin>>numDos;
			}
			
		}else if(op==2){
			SetConsoleTextAttribute(l,249);
			cout<<"Ingrese un número entero: ";
			SetConsoleTextAttribute(l,240);
				cin>>numUno;
		}else if(op==3){
			SetConsoleTextAttribute(l,249);
			cout<<"Ingrese un número entero: ";
			SetConsoleTextAttribute(l,240);
			cin>>numUno;
			SetConsoleTextAttribute(l,249);
			cout<<"Ingrese otro número entero: ";
			SetConsoleTextAttribute(l,240);
			cin>>numDos;
		}
		
		if(cin.fail()){
			Sleep(100);
			system("cls");
			SetConsoleTextAttribute(l,207);
			cout<<"El dato ingresado no es valido, ingrese un dato valido.\n\n";
			SetConsoleTextAttribute(l,240);
			cin.clear();
			cin.ignore();
			system("pause");
			system("cls");
			validar = false;
		}else{
			validar = true;
		}
	}while(!validar);
	OcultarCursor();
	Sleep(100);
	system("cls");
}

// En está función se hacen los procesos necesarios para calcular x cantidad de Múltiplos de x número
void Multiplos(long long numUno){
	int cant,mult=0;
	bool validar=true;
	do{
		SetConsoleTextAttribute(l,249);
		cout<<"Ingrese la cantidad de múltiplos a mostrar: ";
		SetConsoleTextAttribute(l,240);
		cin>>cant;
		
		if(cin.fail()){
			Sleep(100);
			system("cls");
			SetConsoleTextAttribute(l,207);
			cout<<"El cantidad ingresada no es valida, ingrese un valor valido.\n\n";
			SetConsoleTextAttribute(l,240);
			cin.clear();
			cin.ignore();
			system("pause");
			system("cls");
			validar = false;
		}else{
			validar = true;
		}
		
	}while(!validar);
	Sleep(100);
	system("cls");
	SetConsoleTextAttribute(l,249);
	cout<<"Los ";
	SetConsoleTextAttribute(l,240);
	cout<<cant;
	SetConsoleTextAttribute(l,249);
	cout<<" primeros múltiplos del ";
	SetConsoleTextAttribute(l,240);
	cout<<numUno<<endl;
	for(int i=1;i<=cant;i++){
		mult = numUno*i;
		cout<<mult<<", "; 
	}
	cout<<"\b\b ";
}

// En está función se hacen los procesos necesarios para calcular los divisores de x número
void Divisores(long long numUno){
	int resto;
	SetConsoleTextAttribute(l,249);
	cout<<"Divisores del "<<numUno<<endl;
	SetConsoleTextAttribute(l,240);
	for(int i=1;i<=numUno;i++){
		resto=numUno%i;
		if(resto==0){
			cout<<i<<", ";
		}
	}
	cout<<"\b\b ";
}

// En está función se hacen los procesos necesarios para calcular si x número es primo o compuesto
void PrimoCompuesto(long long numUno){
	int cont=0;
	if(numUno == 0 or numUno == 1){
		cout<<"|"<<numUno<<"|";
		SetConsoleTextAttribute(l,249);
		cout<<" es un número especial.\n";
	} 
	for(int i=2;i<numUno;i++){
		if(numUno%i==0) cont++;
	}
	if(cont<1 and numUno!=1 and numUno!=0){
		cout<<"|"<<numUno<<"|";
		SetConsoleTextAttribute(l,249);
		cout<<" es un número primo.";
	}else if(numUno!=1 and numUno!=0){
		cout<<"|"<<numUno<<"|";
		SetConsoleTextAttribute(l,249);
		cout<<" es un número compuesto.";	
	}
	SetConsoleTextAttribute(l,240);
}

// En está función se hacen los procesos necesarios para calcular los números primos y compuestos de un rango x y
void PrimoCompuestoNM(long long numUno, long long numDos){
	int total=0;
	SetConsoleTextAttribute(l,249);
	cout<<"Número Primos de ("<<numUno<<","<<numDos<<")\n";
	SetConsoleTextAttribute(l,240);
	for(int i=numUno;i<=numDos;i++){
		
		int cont=0;
		for(int j=2;j<=i/2;j++){
			if(i%j==0){
				cont++;
				break;
			}
		}
		if(cont<1 and i!=1 and i!=0){
			cout<<i<<", ";
			total++;
		}
	}
	cout<<"\b\b ";
	SetConsoleTextAttribute(l,249);
	cout<<"\nHay un total de "<<total<<" números primos.\n\nNúmeros Compuestos("<<numUno<<","<<numDos<<")\n";
	total=0;
	SetConsoleTextAttribute(l,240);
	for(int i=numUno;i<=numDos;i++){
		
		int cont=0;
		for(int j=2;j<=i/2;j++){
			if(i%j==0){
				cont++;
			}
		}
		
		if(cont<1);
		else if(i!=1 and i!=0){
			cout<<i<<", ";
			total++;
		}
	}
	if(numUno==10 and numDos==50) cout<<"\b ";
	else cout<<"\b\b ";
	SetConsoleTextAttribute(l,249);
	cout<<"\nHay un total de "<<total<<" números compuestos.";
	SetConsoleTextAttribute(l,240);
}

// En está función se hacen los procesos necesarios para calcular el MCM de dos números digitados
void MCM(long long numUno, long long numDos){
	long long mcm=0, mcd=0, aux=0; 
	int resto;
	mcd=numUno;
	aux=numDos;
	if(!numUno==0 and !numDos==0){
		do{
			resto=mcd%aux;
			mcd=aux;
			aux=resto;
		}while(resto!=0);
		mcm=numUno*numDos/mcd;
	}
	SetConsoleTextAttribute(l,249);
	cout<<"El MCM(";
	SetConsoleTextAttribute(l,240);
	cout<<numUno;
	SetConsoleTextAttribute(l,249);
	cout<<",";
	SetConsoleTextAttribute(l,240);
	cout<<numDos;
	SetConsoleTextAttribute(l,249);
	cout<<") = ";
	SetConsoleTextAttribute(l,240);
	cout<<mcm;
}

// En está función se hacen los procesos necesarios para calcular el MCD de dos números digitados
void MCD(long long numUno, long long numDos){
	long long mcd=0, aux=0; 
	int resto;
	mcd=numUno;
	aux=numDos;
	if(!numUno==0 and !numDos==0){
		do{
			resto=mcd%aux;
			mcd=aux;
			aux=resto;
		}while(resto!=0);
	}
	SetConsoleTextAttribute(l,249);
	cout<<"El MCD(";
	SetConsoleTextAttribute(l,240);
	cout<<numUno;
	SetConsoleTextAttribute(l,249);
	cout<<",";
	SetConsoleTextAttribute(l,240);
	cout<<numDos;
	SetConsoleTextAttribute(l,249);
	cout<<") = ";
	SetConsoleTextAttribute(l,240);
	cout<<mcd;
}

// En está función se hacen los procesos necesarios para convertir números de Decimal a Binario
string Base10Bas2(long long numUno){
	long long dividendo; 
	int resto, divisor = 2;
	string binario = "";
	dividendo = numUno;
	while(dividendo >= divisor){
		resto = dividendo % 2;
		if(resto == 1) binario = "1" + binario;
		else binario = "0" + binario;
		dividendo = dividendo/divisor;
	}
	if(dividendo == 1) binario = "1" + binario;
	else binario = "0" + binario;
	SetConsoleTextAttribute(l,249);
	cout<<"Decimal: ";
	SetConsoleTextAttribute(l,240);
	cout<<numUno;
	SetConsoleTextAttribute(l,249);
	cout<<"\nBinario: ";
	SetConsoleTextAttribute(l,240);
	cout<<binario;
	
	return binario;
}

// En está función se hacen los procesos necesarios para convertir números de Binario a Decimal
long long Base2Bas10(){
	bool validar=true;
	string num="";
	do{
		SetConsoleTextAttribute(l,249);
		cout<<"Ingrese el número binario: ";
		SetConsoleTextAttribute(l,240);
		MostrarCursor();
		cin>>num;
		OcultarCursor();
		int tam=num.length();
		char bin[tam];
		strcpy(bin, num.c_str());
		long long decimal=0;
		int mult=1;
		bool error=true;
		for(int i=tam-1;i>=0;i--){
			if(bin[i]>=48 and bin[i]<=49){
				if(bin[i]=='1'){
					decimal+=mult;
				}
			}else{
				error=false; 
				break;
			}
			mult*=2;
		}
		Sleep(100);
		system("cls");
		if(error){
			SetConsoleTextAttribute(l,249);
			cout<<"Binario: ";
			SetConsoleTextAttribute(l,240);
			cout<<bin;
			SetConsoleTextAttribute(l,249);
			cout<<"\nDecimal: ";
			SetConsoleTextAttribute(l,240);
			cout<<decimal;
			return decimal;
			validar=true;
		}else{
			SetConsoleTextAttribute(l,207);
			cout<<"[ERROR] Hay uno o varios digitos no validos.\n";
			SetConsoleTextAttribute(l,240);
			cout<<"Sistema binario: 01\n\n";
			system("pause");
			system("cls");
			validar=false;
		}
	}while(!validar);
}

// En está función se hacen los procesos necesarios para convertir números de Decimal a Hexadecimal
string Base10Bas16(long long numUno){
	string hexa = "";
	int residuo;
	long long decimal=numUno;
	while(numUno>0){
		residuo=numUno%16;
		if(residuo>9){
			switch(residuo){
				case 10: hexa = "A" + hexa; break;
				case 11: hexa = "B" + hexa; break;
				case 12: hexa = "C" + hexa; break;
				case 13: hexa = "D" + hexa; break;
				case 14: hexa = "E" + hexa; break;
				case 15: hexa = "F" + hexa; break;
			}
		}else{
			hexa=char(residuo+48)+hexa;
		}
		numUno/=16;
	}
	if(hexa=="") cout<<"0";
	else{
		SetConsoleTextAttribute(l,249);
		cout<<"Decimal: ";
		SetConsoleTextAttribute(l,240);
		cout<<decimal;
		SetConsoleTextAttribute(l,249);
		cout<<"\nHexadecimal: ";
		SetConsoleTextAttribute(l,240);
		cout<<hexa;
	} 
	return hexa;
}

// En está función se hacen los procesos necesarios para convertir números de Hexadecimal a Decimal
long long Base16Bas10(){
	bool validar=true;
	string num="";
	do{
		SetConsoleTextAttribute(l,249);
		cout<<"Ingrese el número en hexadecimal: ";
		SetConsoleTextAttribute(l,240);
		MostrarCursor();
		cin>>num;
		OcultarCursor();
		int tam=num.length();
		char hexa[tam];
		strcpy(hexa, num.c_str());
		for (int i=0; i<strlen(hexa); i++)
	        hexa[i]=putchar(toupper(hexa[i]));
		int potencia=-1;
		long long decimal=0;
		bool error=true;
		for(int i=tam-1; i>=0 ;i--){
			if((hexa[i]>=65 and hexa[i]<=70) or (hexa[i]>=48 and hexa[i]<=57)){
				switch(hexa[i]){
					case '0':
						potencia++;
						decimal+=0*pow(16,potencia);
					break;
					case '1':
						potencia++;
						decimal+=1*pow(16,potencia);
					break;
					case '2':
						potencia++;
						decimal+=2*pow(16,potencia);
					break;
					case '3':
						potencia++;
						decimal+=3*pow(16,potencia);
					break;
					case '4':
						potencia++;
						decimal+=4*pow(16,potencia);
					break;
					case '5':
						potencia++;
						decimal+=5*pow(16,potencia);
					break;
					case '6':
						potencia++;
						decimal+=6*pow(16,potencia);
					break;
					case '7':
						potencia++;
						decimal+=7*pow(16,potencia);
					break;
					case '8':
						potencia++;
						decimal+=8*pow(16,potencia);
					break;
					case '9':
						potencia++;
						decimal+=9*pow(16,potencia);
					break;
					case 'A':
						potencia++;
						decimal+=10*pow(16,potencia);
					break;
					case 'B':
						potencia++;
						decimal+=11*pow(16,potencia);
					break;
					case 'C':
						potencia++;
						decimal+=12*pow(16,potencia);
					break;
					case 'D':
						potencia++;
						decimal+=13*pow(16,potencia);
					break;
					case 'E':
						potencia++;
						decimal+=14*pow(16,potencia);
					break;
					case 'F':
						potencia++;
						decimal+=15*pow(16,potencia);
					break;
				}
			}else{
				error=false;
				break;
			}
		}
		Sleep(100);
		system("cls");
		if(error){
			SetConsoleTextAttribute(l,249);
			cout<<"Hexadecimal: ";
			SetConsoleTextAttribute(l,240);
			cout<<hexa;
			SetConsoleTextAttribute(l,249);
			cout<<"\nDecimal: ";
			SetConsoleTextAttribute(l,240);
			cout<<decimal;
			return decimal;
			validar=true;
		}else{
			SetConsoleTextAttribute(l,207);
			cout<<"[ERROR] Hay uno o varios digitos no validos.\n";
			SetConsoleTextAttribute(l,240);
			cout<<"Sistema hexadecimal: 0123456789ABCDEF\n\n";
			system("pause");
			system("cls");
			validar=false;
		}
	}while(!validar);
}

// En está función se hacen los procesos necesarios para convertir números de Decimal a Octal
void Base10Base8(long long numUno){
	int resto=0;
	long long octal=0, i=1;
	long long decimal=numUno;
	while(decimal!=0){
		resto = decimal%8;
		decimal/=8;
		octal+=resto*i;
		i*=10;
	}
	
	Sleep(100);
	system("cls");
	SetConsoleTextAttribute(l,249);
	cout<<"Decimal: ";
	SetConsoleTextAttribute(l,240);
	cout<<numUno;
	SetConsoleTextAttribute(l,249);
	cout<<"\nOctal: ";
	SetConsoleTextAttribute(l,240);
	cout<<octal;
}

// En está función se hacen los procesos necesarios para convertir números de Octal a Decimal
void Base8Base10(long long numUno){
	int resto=0;
	long long octal=numUno;
	long long decimal=0, i=0;
	
	while (octal!=0){
        resto=octal%10;
        octal/=10;
        decimal+=resto*pow(8, i);
        ++i;
    }
    Sleep(100);
	system("cls");
	SetConsoleTextAttribute(l,249);
	cout<<"Octal: ";
	SetConsoleTextAttribute(l,240);
	cout<<numUno;
	SetConsoleTextAttribute(l,249);
	cout<<"\nDecimal: ";
	SetConsoleTextAttribute(l,240);
	cout<<decimal;
}

// En está función hacen los procesos necesarios para calcular la suma decimal de 2 números ingresados
long long SumaDecimal(long long numUno, long long numDos){
	long long suma=0;
	
	suma = numUno+numDos;
	Sleep(100);
	system("cls");
	SetConsoleTextAttribute(l,249);
	cout<<"   SUMA DECIMAL";
	SetConsoleTextAttribute(l,240);
	cout<<"\n\n  "<<numUno;
	SetConsoleTextAttribute(l,249);
	cout<<"\n+\n";
	SetConsoleTextAttribute(l,240);
	cout<<"  "<<numDos;
	SetConsoleTextAttribute(l,249);
	cout<<"\n______________\n";
	SetConsoleTextAttribute(l,240);
	cout<<"  "<<suma;
	SetConsoleTextAttribute(l,249);
	cout<<"\n\nResultado: ";
	SetConsoleTextAttribute(l,240);
	cout<<suma;
	
	return suma;
}

// En está función se muestra los resultados de la suma binaria y/o hexadecimal
void MostrarSumas(string d1, string d2, string num, string tipo){
	Sleep(100);
	system("cls");
	SetConsoleTextAttribute(l,249);
	cout<<"   "<<tipo;
	SetConsoleTextAttribute(l,240);
	cout<<"\n\n  "<<d1;
	SetConsoleTextAttribute(l,249);
	cout<<"\n+\n";
	SetConsoleTextAttribute(l,240);
	cout<<"  "<<d2;
	SetConsoleTextAttribute(l,249);
	cout<<"\n______________\n";
	SetConsoleTextAttribute(l,240);
	cout<<"  "<<num;
	SetConsoleTextAttribute(l,249);
	cout<<"\n\nResultado: ";
	SetConsoleTextAttribute(l,240);
	cout<<num;
}

// Está es una función, la cual tiene un único proposito y es darle un delimitado a las opciones del menú
void PintarLimites(){
	for(int i=38;i<82;i++){
		gotoxy(i,7); cout<<"*";
		gotoxy(i,19); cout<<"*";
	}
	
	for(int i=8;i<19;i++){
		gotoxy(38,i); cout<<"*";
		gotoxy(81,i); cout<<"*";
	}
	
	gotoxy(38,7); cout<<"*";

}

// Está es toda la estructura de los Menús aquí es dónde se muestran las opciones de cada menú así como la estética de los mismos
int MenuOpciones(const char *titulo, const char *opciones[], int n){
	int opSelect=1, tecla;
	bool repite = true;
	
	do{
		SetConsoleTextAttribute(l,229);
		gotoxy(42,4);cout<<"Introducción a la Teoría de Números.\n\n";
		SetConsoleTextAttribute(l,153);
		PintarLimites();
		SetConsoleTextAttribute(l,250);
		gotoxy(42,10 + opSelect); cout<<""<<char(26);
		SetConsoleTextAttribute(l,252);
		gotoxy(52,9); cout<<titulo;
		SetConsoleTextAttribute(l,243);
		for(int i=0;i<n;i++){
			gotoxy(47, 11+i); cout<<"|"<<i+1<<"| - "<<opciones[i];
		}
//		SetConsoleTextAttribute(l,249);
		do{
			tecla=getch();
		}while(tecla != ARRIBA and tecla != ABAJO and tecla != ENTER);
		if(tecla==ARRIBA){
			opSelect--;
			if(opSelect<1){
				opSelect=n;
				gotoxy(42,10 + opSelect-(n-1)); cout<<" ";
			}
		}
				
		if(tecla==ABAJO){
			opSelect++;
			if(opSelect>n){
				opSelect=1;
				gotoxy(42,10+ opSelect+(n-1)); cout<<" ";
			}
		}
				
		if (tecla==ENTER){
			repite = false;
		}
		gotoxy(42,10 + opSelect-1); cout<<" ";
		gotoxy(42,10 + opSelect+1); cout<<" ";
	}while(repite);
	SetConsoleTextAttribute(l,240);
	return opSelect;
}

// Está es una función la cual permitirá al usuario ingresar otros datos sin la necesidad de volver al menú y seleccionar la misma opción
int Repetir(){
	int conf;
	cout<<endl<<endl;
	system("pause");
	system("cls");
	const char *titulo = "Ingresar otros datos?";
	const char *opciones[]={"Sí","No"};
	int n=2;
	conf=MenuOpciones(titulo, opciones, n);
	Sleep(100);
	system("cls");
	return conf;
}

// Esté es el Sub-Menú de Números dónde aparecen las respectivas opciones de este apartado
void MenuNumeros(int op){
	long long numUno=0, numDos=0;
	int subOp;
	const char *titulo ="SUB-MENÚ";
	const char *opciones[] = {"Múltiplos.","Divisores.","Número primo o compuesto.","Primos y Compuestos (x,y).","MCM.","MCD.","Regresar."};
	int n=7;
	do{
		subOp=MenuOpciones(titulo, opciones, n);
		Sleep(100);
		system("cls");
		switch(subOp){
			case 1:
				do{
					Pedir(numUno, numDos, subOp, op); 
					Multiplos(numUno);
				}while(Repetir()!=2);
				SubMenu();
			break;
						
			case 2:
				do{
					Pedir(numUno, numDos, subOp, op);
					Divisores(numUno);
				}while(Repetir()!=2);
				SubMenu();
			break;
						
			case 3:
				do{
					Pedir(numUno, numDos, subOp, op);
					PrimoCompuesto(numUno);
				}while(Repetir()!=2);
				SubMenu();
			break;
						
			case 4:
				do{
					Pedir(numUno, numDos, subOp, op);
					PrimoCompuestoNM(numUno, numDos);
				}while(Repetir()!=2);
				SubMenu();
			break;
						
			case 5:
				do{
					Pedir(numUno, numDos, subOp, op);
					MCM(numUno, numDos);
				}while(Repetir()!=2);
				SubMenu();
			break;
						
			case 6:
				do{
					Pedir(numUno, numDos, subOp, op);
					MCD(numUno, numDos);
				}while(Repetir()!=2);
				SubMenu();
			break;
						
			case 7: Menu(); break;
				
			default:
				SetConsoleTextAttribute(l,207);
				cout<<"[ERROR] Opción no valida.";
				Sleep(1000);
				SubMenu();
			break;
		}
	}while(subOp!=7);
}

// Esté es el Sub-Menú del Converitor de bases dónde aparecen las respectivas opciones de este apartado
void MenuConvertidor(int op){
	long long numUno=0, numDos=0;
	int subOp;
	const char *titulo ="SUB-MENÚ";
	const char *opciones[] = {"Decimal a Binario.","Binario a Decimal.","Decimal a Hexadecimal.","Hexadecimal a Decimal.","Decimal a Octal.","Octal a Decimal.","Regresar."};
	int n=7;
	do{
		subOp=MenuOpciones(titulo, opciones, n);
		Sleep(100);
		system("cls");
		switch(subOp){
			case 1:
				do{
					Pedir(numUno, numDos, subOp, op);
					Base10Bas2(numUno);
				}while(Repetir()!=2);
				SubMenu();
			break;
			
			case 2:
				do{
					Base2Bas10();
				}while(Repetir()!=2);
				SubMenu();
			break;
						
			case 3:
				do{
					Pedir(numUno, numDos, subOp, op);
					Base10Bas16(numUno);
				}while(Repetir()!=2);
				SubMenu();
			break;
						
			case 4:
				do{
					Base16Bas10();
				}while(Repetir()!=2);
				SubMenu();
			break;
						
			case 5:
				do{
					Pedir(numUno, numDos, subOp, op);
					Base10Base8(numUno);
				}while(Repetir()!=2);
				SubMenu();
			break;
						
			case 6:
				do{
					Pedir(numUno, numDos, subOp, op);
					Base8Base10(numUno);
				}while(Repetir()!=2);
				SubMenu();
			break;
						
			case 7: Menu(); break;
						
			default:
				SetConsoleTextAttribute(l,207);
				cout<<"[ERROR] Opción no valida.";
				Sleep(1000);
				SubMenu();
			break;
		}
	}while(subOp!=7);
}

// Esté es el Sub-Menú de Sumas dónde aparecen las respectivas opciones de este apartado
void MenuSumas(int op){
	long long numUno=0, numDos=0, suma=0;
	int subOp;
	string num="", d1="", d2="", tipo="";
	const char *titulo ="SUB-MENÚ";
	const char *opciones[] = {"Suma Decimal.","Suma Binaria.","Suma Hexadecimal.","Regresar."};
	int n=4;
	do{	
		subOp=MenuOpciones(titulo, opciones, n);
		Sleep(100);
		system("cls");
		switch(subOp){
			case 1:
				do{
					Pedir(numUno, numDos, subOp, op);
					SumaDecimal(numUno, numDos);
				}while(Repetir()!=2);
				SubMenu();
			break;
					
			case 2:
				do{
					tipo="SUMA BINARIA";
					numUno=Base2Bas10();
					system("cls");
					numDos=Base2Bas10();
					system("cls");
					suma=SumaDecimal(numUno, numDos);
					d1 = Base10Bas2(numUno);
					d2 = Base10Bas2(numDos);
					system("cls");
					Sleep(100);
					num=Base10Bas2(suma);
					MostrarSumas(d1, d2, num, tipo);
				}while(Repetir()!=2);
				SubMenu();
			break;
						
			case 3:
				do{
					tipo="SUMA HEXADECIMAL";
					numUno=Base16Bas10();
					system("cls");
					numDos=Base16Bas10();
					system("cls");
					suma=SumaDecimal(numUno, numDos);
					d1 = Base10Bas16(numUno);
					d2 = Base10Bas16(numDos);
					system("cls");
					Sleep(100);	
					num=Base10Bas16(suma);
					MostrarSumas(d1, d2, num, tipo);
				}while(Repetir()!=2);
				SubMenu();
			break;
						
			case 4: Menu(); break;
				
			default:
				SetConsoleTextAttribute(l,207);
				cout<<"[ERROR] Opción no valida.";
				Sleep(1000);
				SubMenu();
				break;
		}
	}while(subOp!=4);
}

// Esté es el Menú principal dónde se mostraran las principales opciones
void MenuPrincipal(){
	bool repetir=true;
	int op;
	const char *titulo = "MENÚ PRINCIPAL";
	const char *opciones[] = {"NÚMEROS.","CONVERTIDOR DE BASES.","SUMAS.","FINALIZAR."};
	int n=4;
	do{
		op=MenuOpciones(titulo, opciones, n);
		Sleep(100);
		system("cls");
		switch(op){
			
			case 1:
				MenuNumeros(op);
			break;
			
			case 2:
				MenuConvertidor(op);
			break;
				
			case 3:
				MenuSumas(op);
			break;
			
			case 4:  repetir=false; break;
			
			default:
				SetConsoleTextAttribute(l,207);
				cout<<"[ERROR] Opción no valida.";
				Sleep(1000);
				Menu();
			break;
		}
	}while(repetir);
}

// Función principal del programa
int main(){
	system("color F0");
	setlocale(LC_ALL,"");
	Dos();
	Bienvenida();
	OcultarCursor();
	SetConsoleTextAttribute(l,229);
	MenuPrincipal();
	if(nombre==""){
		nombre="DESCONCIDO";
	}
	SetConsoleTextAttribute(l,249);
	cout<<"Muchas gracias Sr(a) ";
	SetConsoleTextAttribute(l,240);
	cout<<nombre;
	SetConsoleTextAttribute(l,249);
	cout<<" por usar el programa. \nEspero le haya sido de utilidad.\n\n";
	SetConsoleTextAttribute(l,240);
	system("pause");
	system("cls");
	WaitKey();
	return 0;
}
