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
		std::cout << "�� ������ ������� ��������� �������� ��������? ������� �� ��� ���: ";
		std::cin >> checkInitialInitValue;

		if (checkInitialInitValue == "��")
		{
			std::cout << "������� ��������� �������� ��������: ";
			std::cin >> initialInitValue;
			checkTrueInitialInitValue = true;
		}
		if (checkInitialInitValue == "���")
		{
			checkInitialInitValue = true;
			std::cout << "�� ��������!";
			return 0;
		}
	} while (!checkTrueInitialInitValue);

	Counter Counter(initialInitValue);

	std::string commandValue;
	bool checkCommand = false;

	do
	{
		std::cout << "������� ������� ('+', '-', '=' ��� '�'): ";
		std::cin >> commandValue;

		if (commandValue == "�")
		{
			std::cout << "�� ��������!";
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
			std::cout << "�� ����� �������� �������: " << std::endl;
		}
	} while (!checkCommand);

	return 0;
}