#include <Windows.h>
#include <iostream>
#include <conio.h>


void setPosition(int x, int y) 
{ 
    COORD pos = {x, y};
    HANDLE output = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(output, pos);
}

int main()
{
	char ascii[255];

	for(int i = 0; i < 255; ++i)
	{
		ascii[i] = i;
	}

	int rows = 255 /6;
	int yy = 255 % 11;

	int iterator = 0;

	for(int y = 0; y <= rows; ++y)
	{
		for(int x = 0; x <= 70; x += 14, ++iterator)
		{
			setPosition(x, y);
			std::cout << iterator << ". " << ascii[iterator] << "\t";

			if(iterator == 255) 
				break;
		}

		setPosition(51, y);
		std::cout << '\n';

		if(iterator == 255) 
			break;
	}


	_getch();

	return 0;
}