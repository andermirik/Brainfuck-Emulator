#include <iostream>
#include <fstream>
#include <vector>
#include <windows.h>

int main()
{
	std::ifstream fin("bublesort.txt");
	
	std::vector<char> commands;

	while (fin)
	{
		char c = fin.get();
		if (c == '\n' || c == -1)
		{
			continue;
		}
		commands.push_back(c);
	}
	fin.close();

	char memory[30000];
	memset(memory, 0, 30000 * sizeof(char));

	int pos = 0;
	int brc = 0;

	for (int i=0; i<commands.size(); i++)
	{
		if (commands[i] == '>')
		{
			++pos;
		}
		if (commands[i] == '<')
		{
			--pos;
		}
		if (commands[i] == '+')
		{
			++memory[pos];
		}
		if (commands[i] == '-')
		{
			--memory[pos];
		}
		if (commands[i] == '.')
		{
			std::cout << (int)memory[pos]<<" ";
		}
		if (commands[i] == ',')
		{
			std::cin >> memory[pos];
			memory[pos] -= 48;
		}
		if (commands[i] == '[')
		{
			if (memory[pos] == 0)
			{
				++brc;

				while (brc) {
					++i;
					if (commands[i] == '[')
						++brc;
					if (commands[i] == ']')
						--brc;
				}
			}
			else
				continue;
		}
		if (commands[i] == ']')
		{
			if (memory[pos] == 0)
			{
				continue;
			}
			else
			{
				if (commands[i] == ']')
				{
					brc++;
				}
				while (brc)
				{
					--i;
					if (commands[i] == '[')
					{
						brc--;
					}
					if (commands[i] == ']')
					{
						brc++;
					}
				}
				--i;
			}
		}
	}


	system("pause");
	return 0;
}