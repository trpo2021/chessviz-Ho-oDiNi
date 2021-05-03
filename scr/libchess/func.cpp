#include <iostream>
#include <string>
#include "func.h"

using namespace std; 

extern char buff; 
extern bool flag_buff; 
extern char table[][9]; 
extern bool table_b[][9];
extern bool table_h[][9]; 
extern int sum_hod, y_error, x_error; 

struct Figura // Фигуры
{   
    public:
    char K, k, Q, q, R, r, N, n, B, b, P, p;  
} f;

void table_default() // Начальное положение
{  
	f.K = 'K'; f.Q = 'Q'; f.R = 'R'; f.N = 'N'; f.B = 'B'; f.P = 'P'; 
	f.k = 'k'; f.q = 'q'; f.r = 'r'; f.n = 'n'; f.b = 'b'; f.p = 'p'; 
    for (int i = 0; i < 8; i++)
    {   
        for (int j = 1; j < 9; j++)
        {           
            table[i][j] = ' ';
            table_b[i][j] = 0;
            table_h[i][j] = 0;
        }   
    }
    for (int i = 1; i < 9; i++)
    {                                                       
        table[1][i] = f.p ; table_b[1][i] = 1;
        table[6][i] = f.P ; table_b[6][i] = 1;
    }
    table[0][1] = table[0][8] = f.b; table_b[0][1] = table_b[0][8] = 1;
    table[7][1] = table[7][8] = f.B; table_b[7][1] = table_b[7][8] = 1;
    table[0][2] = table[0][7] = f.n; table_b[0][2] = table_b[0][7] = 1;
    table[7][2] = table[7][7] = f.N; table_b[7][2] = table_b[7][7] = 1;
    table[0][3] = table[0][6] = f.r; table_b[0][3] = table_b[0][6] = 1;
    table[7][3] = table[7][6] = f.R; table_b[7][3] = table_b[7][6] = 1;
    table[0][4] = f.q; table_b[0][4] = 1;
    table[0][5] = f.k; table_b[0][5] = 1;
    table[7][4] = f.Q; table_b[7][4] = 1;
    table[7][5] = f.K; table_b[7][5] = 1;
    
    PrintTable(); 
}

void PrintTable() // Вывод доски
{
    system("cls"); 
    cout << "|Выход 'Ctrl+Z'|" << endl;
    cout  << "\t\t\tПример хода: 'e2 e4' через пробел" << endl;
    cout << "\n\n\n";
    for (int i = 0; i < 8; i++)
    {
        cout << "\t\t\t\t " << 8 - i;
        for (int j = 0; j < 9; j++)
        {
        	printf(" %c",table[i][j]);
        }
        cout << endl;
    }
    cout << "\t\t\t\t   ";
    
    char num = 'a';
    for (int i = 1; i < 9; i++)
    {
        cout << " " << num;
        ++num;
    }
    if (sum_hod % 2 == 0 & sum_hod > 0 | sum_hod == 1) 
        cout << endl << "Ход черных: "; 
    else 
        cout << endl << "Ход белых: ";
}

void zero_table_h()
{
	for (int i = 0; i < 9; i++)    
    for (int j = 0; j < 9; j++)              
        table_h[i][j] = 0;
}

void hod_Peshka_white(int x, int y)          
{
	if((y == 2)&&(table_b[6 - y][8 - (104 - x)]==0)&&(table_b[7 - y][8 - (104 - x)]==0))   //Первый ход пешки
		table_h[6 - y][8 - (104 - x)] = 1;
			
	if(table_b[7 - y][8 - (104 - x)]==0)	//Остальные ходы
		table_h[7 - y][8 - (104 - x)] = 1;
	else 
	{
		table_h[7 - y][8 - (104 - x)] = 0;
		cout  << "\n\nПешка так не рубит" << endl;
		cout  << "Введите ход заного" << endl;
	}
	
	if(table_b[7 - y][7 - (104 - x)]==1)	//Рубить
		table_h[7 - y][7 - (104 - x)] = 1;
		
	if(table_b[7 - y][9 - (104 - x)]==1)
		table_h[7 - y][9 - (104 - x)] = 1;
	
	table_h[8 - y][8 - (104 - x)] = 1;	
}

void hod_Peshka_black(int x, int y)
{
	if((y == 7)&&(table_b[8 - y+1][8 - (104 - x)]==0)&&(table_b[8 - y+2][8 - (104 - x)]==0))   //Первый ход пешки
	{	
		table_h[10 - y][8 - (104 - x)] = 1;
	}	
	if(table_b[9 - y][8 - (104 - x)]==0)	//Остальные ходы
	{
		table_h[9 - y][8 - (104 - x)] = 1;
	}	
	else 
	{
		table_h[9 - y][8 - (104 - x)] = 0;
		cout  << "\n\nПешка так не рубит" << endl;
		cout  << "Введите ход заного" << endl;
	}
	
	if(table_b[9 - y][7 - (104 - x)]==1)	//Рубить
		table_h[9 - y][7 - (104 - x)] = 1;
		
	if(table_b[9 - y][9 - (104 - x)]==1)
		table_h[9 - y][9 - (104 - x)] = 1;
	
	table_h[8 - y][8 - (104 - x)] = 1;	
}

int table_hod(int x, int y)                                                                        
{
	int error = 1;          																						
    if ((table_b[8 - y][8 - (104 - x)] == 1)&&(flag_buff==false)) // Берем фигуру
	{ 
        buff = table[8 - y][8 - (104 - x)];
		if(buff=='P')                                            
			hod_Peshka_white(x, y);
		if(buff=='p')                                            
			hod_Peshka_black(x, y);
        table[8 - y][8 - (104 - x)] = ' ';
        table_b[8 - y][8 - (104 - x)] = 0; 
        flag_buff = true;   
        x_error=x;
        y_error=y;
    }

    else 
	if(flag_buff==true) // Ставим или рубим
	{         
		if(table_h[8 - y][8 - (104 - x)] == 1)   
		{   
			if((table[8 - y][8 - (104 - x)]=='P')&&(buff=='P'))	
				return -1;
			if((table[8 - y][8 - (104 - x)] == 'p')&&(buff=='p'))
				return -1;
			table[8 - y][8 - (104 - x)] = buff; 
			table_b[8 - y][8 - (104 - x)] = 1; 
			buff = ' ';              
			flag_buff = false;      
			PrintTable();
			zero_table_h();   
		}  
		else return -1; 
	}   
	else return 0;
    ++sum_hod; // увелечение полухода
    return 1;
}
