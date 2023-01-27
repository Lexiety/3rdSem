#include<iostream>
#include <string>
#include <vector>
using namespace std;

void Print_matrix(vector < vector <bool> > matrix_S)
{
	cout << "  ";
	for (int i = 0; i < matrix_S.size(); i++)
	{cout << char(65 + i) << " ";}
	cout << endl;
	for (int i = 0; i < matrix_S.size(); i++)
	{
		cout << char(65 + i) << " ";
		for (int j = 0; j < matrix_S[0].size(); j++)
		{
		 cout << matrix_S[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}

void Subgraph(vector < vector <bool> > matrix)
{
	for (int i = 0; i < matrix.size(); i++)
	{matrix[i][i] = 1;}
	vector < vector <bool> > matrix_T;
	matrix_T = matrix;
	for (int i = 0; i < matrix.size(); i++)
	{
		for (int j = 0; j < matrix.size(); j++)
		{
			matrix_T[i][j] = matrix[j][i];
		}
	}
	vector <string> subgraphs(0);
	vector <bool> tmp(0);

	string Name = "";
	for (int i = 0; i < matrix.size(); i++)
	{
		Name += char(65 + i);
	}
	string s = "";

	for (int i = 0; i < matrix.size(); i++)
	{
		tmp = matrix[i];
		s = "";
		for (int j = 0; j < matrix.size(); j++)
		{
			tmp[j] = matrix_T[i][j] + matrix[i][j];
		}
		for (int j = 0; j < matrix.size(); j++)
		{
			if (tmp[j] && (Name[j] != '+'))
			{
				s = s + Name[j] + "-";
				Name[j] = '+';
			}
		}
		if (s != "")
		{
			s.pop_back();
		}
		if (!(find(subgraphs.begin(), subgraphs.end(), s) != subgraphs.end()) && s != "")
		{
			subgraphs.push_back(s);
		}
	}
	cout << " || ";
	for (int i = 0; i < subgraphs.size(); i++)
	{
		cout << subgraphs[i] << " || ";
	}
	if (Name[Name.size() - 1] != '+')
	{
		cout << Name[Name.size() - 1];
	}
	cout << endl;
}
vector < vector <bool> > Strong_connect(vector < vector <bool> > Reachability_matrix)
{
	vector < vector <bool> > Strong_connect_matrix = Reachability_matrix;
	for (int i = 0; i < Reachability_matrix.size(); i++) {
		for (int j = 0; j < Reachability_matrix.size(); j++) {
			Strong_connect_matrix[i][j] = false;
		}
	}

	for (int i = 0; i < Reachability_matrix.size(); i++) {
		for (int j = 0; j < Reachability_matrix.size(); j++) {
			if (Reachability_matrix[i][j] == true && Reachability_matrix[j][i] == true)
			{
				Strong_connect_matrix[i][j] = Strong_connect_matrix[j][i] = true;
			}
		}
	}
	return Strong_connect_matrix;
}

vector < vector <bool> > Reachability(vector < vector <bool> > matrix_1)
{
	vector < vector <bool> > Reachability_matrix;
	vector < vector <bool> > matrix_2;
	vector < vector <bool> > matrix_3;
	Reachability_matrix = matrix_2 = matrix_3 = matrix_1;
	for (int Degree = 0; Degree < matrix_1.size() - 1; Degree++)
	{
		for (int i = 0; i < matrix_1.size(); i++) {
			for (int j = 0; j < matrix_1.size(); j++) {
				matrix_3[i][j] = 0;
				for (int k = 0; k < matrix_1.size(); k++)
					matrix_3[i][j] = matrix_3[i][j] + matrix_2[i][k] * matrix_1[k][j];
			}
		}
		matrix_2 = matrix_3;
		for (int i = 0; i < matrix_1.size(); i++) {
			for (int j = 0; j < matrix_1.size(); j++) {
				Reachability_matrix[i][j] = Reachability_matrix[i][j] + matrix_3[i][j];
			}
		}
	}

	for (int i = 0; i < matrix_1.size(); i++) 
	{Reachability_matrix[i][i] = 1;}
	return Reachability_matrix;
}

int main()
{
		system("color F0");
		srand(time(NULL));
		setlocale(LC_ALL, "Rus");
		int n;
		cout << "Введите размер матрицы: ";
		cin >> n;
		vector < vector < bool > > matrix_S(n, vector <bool>(n)); 
		string tmp;
		int check = 0;
		cout << "0 - ввод матрицы вручную, 1 - рандом" << endl;
		cin >> check;
		if (check == 0) {
			for (int i = 0; i < n; i++)
			{
				cin >> tmp;
				for (int j = 0; j < n; j++)
				{
					if (tmp[j] == '0') { matrix_S[i][j] = 0; }
					else { matrix_S[i][j] = 1; }
				}
			}
		}
		else 
		{
			int p = 0;
			for (int i = 0; i < n; i++)
			{
				for (int j = 0; j < n; j++)
				{
					p = rand() % 2;
					if (p == 0) { matrix_S[i][j] = 0; }
					else { matrix_S[i][j] = 1; }
				}
			}
		}

	cout << "Матрица" << endl;
	Print_matrix(matrix_S);

	cout << "Матрица достижимости (Reachability)" << endl;
	Print_matrix(Reachability(matrix_S));

	cout << "Матрица сильной связности (Strong connection)" << endl;
	Print_matrix(Strong_connect(Reachability(matrix_S)));

	cout << "Компоненты связности: ";
	Subgraph(Reachability(matrix_S));
	
	return 0;
}