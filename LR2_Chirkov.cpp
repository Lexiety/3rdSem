#include <iostream>
using namespace std;
int r = 5;	
int sum = 0;
int con = 1;
int simm = 1;
int nul = 0;
int edin = 0;
int ran = 0;

class Matrix
{
protected:
	bool** data = new bool* [r];
public:
	Matrix()
	{
		for (int i = 0; i < r; i++) 
		{
			data[i] = new bool[r]; 
		}
	}
	void Random()
	{
		for (int i = 0; i < r; i++)
		{
			for (int j = 0; j < r; j++) 
			{
				data[i][j] = rand()%2;
			}
		}
	}

	void Manual()
	{
		cout << "Вводите данные построчно" << endl;
		int a = 0;
		for (int i = 0; i < r; i++) 
		{	
			cin >> a;
			for (int j = r-1; j > -1; j--)
			{
				data[i][j] = a % 10;
				a = a / 10;
			}
		}
	}

	void Print() 
	{
		cout << "   ";
		int T;
		for (int i = 0, T = 'A'; i < r; i++, ++T)
		{
			printf("%c   ", T, T);
		}
		cout << endl;
		for (int i = 0, T = 'A'; i < r; i++, ++T)  
		{
			printf("%c ", T, T);
			for (int j = 0; j < r; j++)
			{
				cout << "[" << data[i][j] << "] ";
			}
			cout << endl << endl;
		}
	}

	void Reflexivity()
	{

		for (int i = 0; i < r; i++)
		{
			sum = sum + data[i][i];
			con = con * data[i][i];
		}
		if (sum == 0) { cout << "Матрица антирефлексивна" << endl; }
		if ((con == 1)&&(sum>0)) { cout << "Матрица рефлексивна" << endl; }
		if ((con == 0) && (sum > 0)) { cout << "Матрица нерефлексивна" << endl; }
		

	}
	void Symmetry()

	{

		for (int i = 0; i < r; i++)
		{
			for (int j = 0; j < r; j++)
			{
				if (data[i][j] != data[j][i])
				{
					simm = 0;
				}
				if (data[i][j] == data[j][i])
				{
					if (data[i][j] == 0) { nul = 1; }
					else edin = 1;
				}
			}
		}
		int ch = 0;
		if (simm == 1) { cout << "Матрица симметрична" << endl; ch = 1; }
		if ((nul == 1) && (edin == 0) && (sum == 1)) { cout << "Матрица антисимметрична" << endl; ch = 1; }
		if ((simm == 0) && (edin == 0) && (sum == 1)) { cout << "Матрица ассимметрична" << endl; ch = 1; }
		if (ch==0) { cout << "Матрица несимметрична" << endl; }

	}

	void Transivity()

	{
		bool trans = true;
		for (int i = 0; i < r; ++i)
			for (int j = 0; j < r; ++j)
			{
				if (i != j)
				{
					if (data[i][j])
					{
						for (int k = 0; k < r; ++k)
						{
							if (k != i && k != j)
							{
								if (data[j][k] != 0)
								{
									if (data[i][k] == 0)
									{
										trans = false;
									}
								}
							}
						}
					}
				}
			}

		if (trans)
			cout << "Транзитивная" << endl;
		else cout << "Нетранзитивная" << endl;

	}


	~Matrix()
	{
		for (int i = 0; i < r; i++)
		{
			delete[]data[i];
		}
		delete[]data;
	}
};

int main()
{
	setlocale(LC_ALL, "rus");
	int check = 0;
	srand(time(NULL));
	cout << "0 - ввод матрицы вручную, 1 - рандом" << endl;
	cin>> check;
	Matrix A;
	if (check == 1) { A.Random(); }
	else { A.Manual(); }
	A.Print();
	A.Reflexivity();
	 A.Symmetry();
	 A.Transivity();
	 if (nul==0) { cout << "Полная" << endl; }
	 else { cout << "Неполная" << endl; }
}