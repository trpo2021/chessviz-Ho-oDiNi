#include<iostream>
#include <stdlib.h>
#include "func.h"

using namespace std; 
 
char buff; // буфер хранения фигуры
bool flag_buff = false; // флаг фигуры
char table[9][9]; // массив представления фигур
bool table_b[9][9]; // массив нахождения фигур
bool table_h[9][9]; // массив хода фигур
int sum_hod = 0, y_error, x_error; // полуходы
 
int main() 
{
    setlocale(0, "Russian");
    table_default();    
    int y = 0, error = 1, y_error2 = 0;
    char x = 0, x_error2 = 0;
    do
    {
    	cin >> x >> y;
        error = table_hod(x, y);
        if(error==0)
        {
        	cin >> x_error2 >> y_error2;
        	PrintTable();  
			cout  << "\n\nВы не взяли фигуру" << endl;
			cout  << "Введите ход заного" << endl;   
		}	
        if(error==-1)
        {
        	PrintTable(); 
        	error = table_hod(x_error, y_error); 
			cout  << "\n\nФигура так не ходит" << endl;
			cout  << "Введите ход заного" << endl;
		}
	} while (x,y);         
    return 0;
}
