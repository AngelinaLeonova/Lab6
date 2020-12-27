// ConsoleApplication9.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <string>
#include <locale>
#include <iomanip>
using namespace std;

class Admin
{
	char* name; // наименование отдела
public:
	Admin(char* NAME)
	{
		name = new char[strlen(NAME) + 1];
		strcpy_s(name, strlen(NAME) + 1, NAME);
		cout << "Конструктор - Администрирование" << endl;
	}
	~Admin()
	{
		delete[] name;
		cout << "Деструктор класса администрирование" << endl;
	}
	void adminprnt() { cout << "Наименование отдела: "  << name << endl; }
};


class Info : virtual public Admin
{
protected:
	char* spezial; // специализация отдела
	int sotr; // количество сотрудников
public:
	Info(char* NAME, char* SPEZIAL, int SOTR) : Admin(NAME), sotr(SOTR)
	{
		spezial = new char[strlen(SPEZIAL) + 1];
		strcpy_s(spezial, strlen(SPEZIAL) + 1, SPEZIAL);
		cout << "Конструктор - Информация" << endl;
	}
	~Info()
	{
		delete[] spezial; ;
		cout << "Деструктор класса Информация" << endl;
	}
	void adminprnt()
	{

		cout << "Специализация отдела: " << spezial << "\n" "Количество сотрудников: " << sotr << endl;
	}
};


class Strategy : virtual public Admin
{
protected:
	int year; // год выполнения
	double count; // количество задач
public:
	Strategy(char* NAME, int YEAR, double COUNT) : Admin(NAME), year(YEAR), count(COUNT)
	{
		cout << "Конструктор - Стратегия" << endl;
	};
	~Strategy() { cout << "Деструктор класса Стратегия" << endl; }

	void adminprnt()
	{

		cout << "Год выполнения: " << year <<"\n" "Количество задач: " << count << endl;
	}
};


class Director : public Info, public Strategy
{
	char* secondName; // Фaмилия руководителя
public: Director(char* NAME, char* JANR, int SOTR, int YEAR, double COUNT, char* DIRECTOR) :
	Info(NAME, JANR, SOTR), Strategy(NAME, YEAR, COUNT), Admin(NAME)
{
	secondName = new char[strlen(DIRECTOR) + 1];
	strcpy_s(secondName, strlen(DIRECTOR) + 1, DIRECTOR);
	cout << "Конструктор - Руководитель" << endl;
}
	  ~Director()
	  {
		  delete[] secondName;
		  cout << "Деструктор класса Руководитель" << endl;
	  }

};


int main()
{
	setlocale(LC_ALL, "Russian");
	system("chcp 1251");
	system("cls");
	char* name = new char[29];
	cout << "Введите наименование отдела: " << endl;
	cin >> name;

	char* col = new char[29];
	cout << "Введите специализацию отдела: "  << endl;
	cin >> col;


	char* nm = new char[29];
	cout << "Введите фамилию руководителя: " << endl;
	cin >> nm;

	int ses = 0;
	cout << "Введите количество сотрудников: " << endl;
	while (!(cin >> ses))
	{
		cin.clear();
		while (cin.get() != '\n');
		cout << "Повторите попытку: ";
	}

	int god = 0;
	cout << "Введите год выполнения: " << endl;
	while (!(cin >> god))
	{
		cin.clear();
		while (cin.get() != '\n');
		cout << "Повторите попытку: ";
	}

	int coun = 0;
	cout << "Введите количество задач: " << endl;
	while (!(cin >> coun))
	{
		cin.clear();
		while (cin.get() != '\n');
		cout << "Повторите попытку: ";
	}


	Director cart(name, col, ses, god, coun, nm); // объект класса Director
	Director* ptr = &cart; // указатель на созданный объект. 
	cart.Admin::adminprnt();
	cart.Info::adminprnt();
	cart.::Strategy::adminprnt();
	return 0;
}
// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
