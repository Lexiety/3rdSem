#include<iostream>
#include <string>
#include <vector>
using namespace std;

void set_vector(vector<vector<bool>>& matrix, vector <bool> bool_vector)
{
	for (int i = 0; i < 16; i++)
	{
		matrix[i][4] = bool_vector[i];
	}
}

void Print_matrix(vector<vector<bool>> matrix)
{
	cout << "Таблица истиности:" << endl;
	cout << "x y z w   f" << endl;
	for (int i = 0; i < 16; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			if (j == 4)
			{
				cout << "  ";
			}
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}
}

vector<string> SDNF(vector<vector<bool>> matrix)
{
	vector <string> sdnf;
	string s = "";
	for (int i = 0; i < 16; i++)
	{
		s = "";
		if (matrix[i][4])
		{
			if (matrix[i][0])
				s += "x";
			else
				s += "X";

			if (matrix[i][1])
				s += "y";
			else
				s += "Y";

			if (matrix[i][2])
				s += "z";
			else
				s += "Z";

			if (matrix[i][3])
				s += "w";
			else
				s += "W";
			sdnf.push_back(s);
		}
	}
	cout << endl;

	cout << "СДНФ: " << endl;
	for (int i = 0; i < sdnf.size(); i++)
	{
		cout << sdnf[i];
		if (i != sdnf.size() - 1)
			cout << " v ";
	}
	cout << endl;

	return sdnf;
}

bool test_mdnf(vector<vector<string>> table, string mdnf, string s, string answer)
{
	for (int j = 0; j < table.size(); j++)
	{
		if (mdnf.find(table[j][0]) != string::npos)
		{
			for (int i = 1; i < table[0].size(); i++)
			{
				if (table[j][i] == "  1 ")
				{
					s[i - 1] = '+';
				}
			}
		}
	}
	if (s == answer)
		return 1;
	else
		return 0;
}


void MDNF(vector<vector<string>> table)
{
	vector<string> table_tmp;
	string mdnf;
	int mdnf_len = 0;
	string s = "", answer = "";
	for (int i = 0; i < table[0].size() - 1; i++)
	{
		s += "-";
		answer += "+";
	}

	int n = table.size() - 1;
	vector<vector<int> > COMBS(n, vector<int>(1 << n));

	unsigned num_to_fill = 1U << (n - 1);
	for (unsigned col = 0; col < n; ++col, num_to_fill >>= 1U)
	{
		for (unsigned row = num_to_fill; row < (1U << n); row += (num_to_fill * 2))
		{
			fill_n(&COMBS[col][row], num_to_fill, 1);
		}
	}
	for (unsigned x = 0; x < (1 << n); ++x)
	{
		for (unsigned y = 0; y < n; ++y)
		{
			if (COMBS[y][x])
			{
				mdnf = mdnf + table[y + 1][0] + " v ";
			}
		}
		unsigned index;
		if (test_mdnf(table, mdnf, s, answer))
		{
			if (mdnf.size() != 0)
			{
				mdnf.pop_back();
				mdnf.pop_back();
			}
			cout << "МДНФ: " << mdnf << endl;
			break;
		}
		mdnf = "";
	}
}



vector<string> Connect(vector<string> conn)
{
	
	vector <string> new_skleiki;

	for (int i = 0; i < conn.size(); i++)
	{
		for (int j = i + 1; j < conn.size(); j++)
		{
			string s = conn[i];
			int delete_index;
			int count = 0;
			for (int index = 0; index < min(conn[i].size(), conn[j].size()); index++)
			{
				if (conn[j].find(conn[i][index]) == string::npos)
				{
					delete_index = index;
					count++;
				}
			}
			if (count == 1)
			{
				if (s[delete_index] == 'X' && conn[j].find('x') != string::npos)
				{
					s.erase(delete_index, 1);
					new_skleiki.push_back(s);
				}
				else if (s[delete_index] == 'Y' && conn[j].find('y') != string::npos)
				{
					s.erase(delete_index, 1);
					new_skleiki.push_back(s);
				}
				else if (s[delete_index] == 'Z' && conn[j].find('z') != string::npos)
				{
					s.erase(delete_index, 1);
					new_skleiki.push_back(s);
				}
				else if (s[delete_index] == 'W' && conn[j].find('w') != string::npos)
				{
					s.erase(delete_index, 1);
					new_skleiki.push_back(s);
				}
			}
		}
	}
	return new_skleiki;
}


void implikated_matrix(vector<vector<bool>> matrix, vector <string> sdnf)
{
	vector <string> conn = sdnf; 
	vector <string> used = sdnf;

	while (conn.size() > 1)
	{
		conn = Connect(conn); 
		for (int i = 0; i < conn.size(); i++)
		{
			used.push_back(conn[i]); 
		}
	}

	conn.clear();
	conn.push_back(used[used.size() - 1]);
	for (int i = used.size() - 1; i > -1; i--)
	{
		int v_skolki = 0;
		for (int j = 0; j < conn.size(); j++)
		{
			int count = 0;
			for (int index = 0; index < min(used[i].size(), conn[j].size()); index++)
			{
				if (used[i].find(conn[j][index]) != string::npos)
				{
					count++;
				}
			}
			if (count == conn[j].size())
			{
				v_skolki++;
			}
		}
		if (v_skolki == 0)
		{
			conn.push_back(used[i]);
		}
	}

	while (used[used.size() - 1].size() < 4)
	{
		used.pop_back();
	}

	vector < vector <string> > table(conn.size() + 1, vector <string>(used.size() + 1));

	for (int i = 1; i < used.size() + 1; i++)
	{
		table[0][i] = used[i - 1];
	}
	for (int i = 1; i < conn.size() + 1; i++)
	{
		table[i][0] = conn[i - 1];
	}

	for (int i = 1; i < table.size(); i++)
	{
		for (int j = 1; j < table[0].size(); j++)
		{
			int t = 0;
			for (int k = 0; k < table[i][0].size(); k++)
			{
				if (table[0][j].find(table[i][0][k]) != -1)
				{
					t++;
				}
			}
			if (t == table[i][0].size())
			{
				table[i][j] = "  1 ";
			}
		}
	}

	cout << "Имплицированная матрица:" << endl;
	for (int i = 0; i < table.size(); i++)
	{
		for (int j = 0; j < table[0].size(); j++)
		{
			for (int k = 0; k < 4 - table[i][j].size(); k++)
			{
				cout << " ";
			}
			cout << table[i][j] << " ";
		}
		cout << endl;
	}
	MDNF(table);
}




int main()
{
	setlocale(LC_ALL, "rus");
	vector < vector <bool> > matrix(16, vector <bool>(5));
	vector <bool> bool_vector;


	int i = 0, j = 0;
	for (int x = 0; x < 2; x++)
	{
		for (int y = 0; y < 2; y++)
		{
			for (int z = 0; z < 2; z++)
			{
				for (int w = 0; w < 2; w++)
				{
					matrix[i][j] = x;
					matrix[i][j + 1] = y;
					matrix[i][j + 2] = z;
					matrix[i][j + 3] = w;
					i++;
				}
			}
		}
	}


	
	string s = "";
	cout << "Введите вектор функции: ";
	cin >> s;
	cout << s << endl;
	for (int i = 0; i < 16; i++)
	{
		if (s[i] == '0')
			bool_vector.push_back(false);
		else
			bool_vector.push_back(true);
	}
	set_vector(matrix, bool_vector);
	Print_matrix(matrix);
	implikated_matrix(matrix, SDNF(matrix));
	
}
