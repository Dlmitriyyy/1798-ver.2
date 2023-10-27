#include <iostream>
#include <string>
#include <ctime>
using namespace std;
void sort_letters()
{
	srand(time(0));
	int mass_size = rand() % 9 + 25;
	char* mass_letters = new char[mass_size];

	cout << "Випадково сгенерований масив англійських букв: ";

	for (int a = 0; a < mass_size; a++)
	{
		mass_letters[a] = 'a' + rand() % 26;
		cout << mass_letters[a] << " ";
	}
	
	char* letters = mass_letters + 1;
	int letters_count = (mass_size - 1) / 2;

	for (char* a = letters; a < letters + letters_count * 2; a += 2)
	{
		for (char* b = a; b < letters + letters_count * 2; b += 2)
		{
			if (*a > *b)
			{
				char temporary = *a;
				*a = *b;
				*b = temporary;
			}
		}
	}

	for (char* a = mass_letters; a < mass_letters + mass_size; a += 2)
	{
		for (char* b = a; b < mass_letters + mass_size; b += 2)
		{
			if (*a > *b)
			{
				char temporary = *a;
				*a = *b;
				*b = temporary;
			}
		}
	}

	cout << endl << "Масив непарних букв відсортований за алфавітом: ";

	for (int a = 0; a < mass_size; a += 2)
	{
		cout << mass_letters[a] << " ";
	}

	delete[] mass_letters;
}
int main()
{
	system("chcp 1251 > nul");
	sort_letters();
}