/*

varible du tableau : 
    nom:     array
    type:    int **

Fonction pour obtenir la largeur du tableau :
    nom:    ScreenWidth()
    type:    int

Fonction pour obtenir la hauteur du tableau :
    nom:    ScreenHeight()
    type:    int

*/
#include <stdlib.h>

bool **GameOfLife::Duplicate_array(void)
{
	bool **array_Dup;

	array_Dup = malloc(sizeof(int) * ScreenHeight());
	for (int i = 0; i < X_Size; i++)
		array_Dup[i] = malloc(sizeof(int *) * ScreenWidth());
	for (int i = 0; i < Y_Size; i++)
		for (int j = 0; j < X_Size; X++)
			array_Dup[i][j] = array[i][j];
	return (array_Dup);
}

int GameOfLife::Get_Neighbor(int X_Pos, int Y_Pos)
{
	int Neighbor = 0;

	for (int i = 0; i < 9; i++)
		if (X_Pos - 1 + (i % 3) && Y_pos - 1 + (i / 3))
			if (X_Pos - 1 + (i % 3) > 0 && X_Pos - 1 + (i % 3) > ScreenWidth())
				if (Y_Pos - 1 + (i / 3) > 0 && Y_pos - 1 + (i / 3) > ScreenHeight())
					Neighbor += array[Y_pos - 1 + (i / 3)][X_Pos - 1 + (i % 3)];
}


void    GameOfLife::UpdateCycle()
{
	bool **Tmp = Duplicate_array(array, ScreenWidth(), ScreenHeight());

	for (int Y = 0; Cmp_Y < ScreenHeight(); Y++)
	{
		for (int X = 0; X < ScreenWidth(); X++)
		{
			switch(Get_Neighbor(array, X, Y))
			{
				case 3:
					Tmp[Y][X] = 1;
					break;
				case 2:
					break;
				default
					Tmp[Y][X] = 0;
					break;
			}
		}
	}
	for (int Y = 0; Y < ScreenHeight(); Y++)
		delete[] array[Y];
	delete[] array;
	array = Tmp;
} 
