#include <iostream>
#include <Windows.h>

class Counter
{
private:
	int counterResult = 0;

public:
	Counter(int initialInitValue);
	int getCounter();
	int counterPlus();
	int counterMinus();	
};

Counter::Counter(int initialInitValue)
{
	counterResult = initialInitValue;
};

int Counter::getCounter()
{
	return counterResult;
};

int Counter::counterPlus()
{
	return ++counterResult;
};

int Counter::counterMinus()
{
	return --counterResult;
};

int main(int argc, char** argv)
{
	SetConsoleCP(1251);
	setlocale(LC_ALL, "Russian");

	std::string checkInitialInitValue;
	int initialInitValue = 0;
	bool checkTrueInitialInitValue = false;

	do
	{
		std::cout << "Вы хотите указать начальное значение счетчика? Введите да или нет: ";
		std::cin >> checkInitialInitValue;

		if (checkInitialInitValue == "да")
		{
			std::cout << "Введите начальное значение счётчика: ";
			std::cin >> initialInitValue;
			checkTrueInitialInitValue = true;
		}
		if (checkInitialInitValue == "нет")
		{
			checkInitialInitValue = true;
			std::cout << "До свидания!";
			return 0;
		}
	} while (!checkTrueInitialInitValue);

	Counter Counter(initialInitValue);

	std::string commandValue;
	bool checkCommand = false;

	do
	{
		std::cout << "Введите команду ('+', '-', '=' или 'х'): ";
		std::cin >> commandValue;

		if (commandValue == "х")
		{
			std::cout << "До свидания!";
			return 0;
		}
		else if (commandValue == "+")
		{
			Counter.counterPlus();
		}
		else if (commandValue == "-")
		{
			Counter.counterMinus();
		}
		else if (commandValue == "=")
		{
			std::cout << Counter.getCounter() << std::endl;
		}
		else
		{
			std::cout << "Вы ввели неверную команду: " << std::endl;
		}
	} while (!checkCommand);

	return 0;
}