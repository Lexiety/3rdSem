#include <iostream>
using namespace std;
int n;
int i;
int A[101];
int B[101];
int C[101];
int D[101];
int E[101];
int mas1[101];
int mas2[101];
int res[101];
int variant;
int variant2;
int variant3;
int d, j, f;

int get_variant()
{
	cin >> variant;
	return variant;
}

void printmas(int* arr)

{
	int conty = 0;
	for (i = 0; i < 101; i++)
	{
		if (arr[i] == 1) { cout << i - 50 << ", "; conty++; }
	}
	cout << "Total - " << conty << endl;
}

void Complement1(int* arr)
{
	for (i = 0; i < 101; i++)
	{
		arr[i] = arr[i] * (-1) + 1;
	}

	cout << endl;
	for (i = 0; i < 101; i++)
	{
		if (arr[i] == 1) { cout << i - 50 << ", "; }
	}
}

void summas()
{
	for (i = 0; i < 101; i++)
	{
		if ((mas1[i] == 1) || (mas2[i] == 1)) { res[i] = 1; }
	}
	cout << endl;
	for (i = 0; i < 101; i++)
	{
		if (res[i] == 1) { cout << i - 50 << ", "; }
	}
}

void cross()
{
	for (i = 0; i < 101; i++)
	{
		if ((mas1[i] == 1) && (mas2[i] == 1)) { res[i] = 1; }
	}
	cout << endl;
	for (i = 0; i < 101; i++)
	{
		if (res[i] == 1) { cout << i - 50 << ", "; }
	}
}

void substr()
{
	for (i = 0; i < 101; i++)
	{
		if ((mas1[i] == 1) && (mas2[i] != 1)) { res[i] = 1; }
	}
	cout << endl;
	for (i = 0; i < 101; i++)
	{
		if (res[i] == 1) { cout << i - 50 << ", "; }
	}
}

void simsubstr()
{
	for (i = 0; i < 101; i++)
	{
		if (((mas1[i] == 1) || (mas2[i] == 1)) && (mas1[i] * mas2[i] == 0)) { res[i] = 1; }
	}
	cout << endl;
	for (i = 0; i < 101; i++)
	{
		if (res[i] == 1) { cout << i - 50 << ", "; }
	}
}

void enter(int* arr)
{
	for (i = 0; i < 101; i++)
	{
		arr[i] = 0;
	}
	cin >> n;
	while (n != 51)
	{
		if ((n < 51) && (n > -49)) { arr[n + 50] = 1; }
		else { cout << "Invalid number" << endl; }
		cin >> n;
	}
}

void Complement2()
{
	cout << "Which array to change?" << endl;
	cout << "1. A" << endl;
	cout << "2. B" << endl;
	cout << "3. C" << endl;
	cout << "4. D" << endl;
	cout << "5. E" << endl;
	cin >> d;
	switch (d)
	{
	case 1:
		Complement1(A);
		break;
	case 2:
		Complement1(B);
		break;
	case 3:
		Complement1(C);
		break;
	case 4:
		Complement1(D);
		break;
	case 5:
		Complement1(E);
		break;
	}
}



void print_menu()
{
	system("cls");
	cout << "What do you want to do?" << endl;
	cout << "1. ArrayInput" << endl;
	cout << "2. Maths" << endl;
	cout << "3. Complement" << endl;
	cout << "4. end" << endl;
}


void main2()
{
	cout << "Which array to change?" << endl;
	cout << "1. A" << endl;
	cout << "2. B" << endl;
	cout << "3. C" << endl;
	cout << "4. D" << endl;
	cout << "5. E" << endl;
	cin >> d;
	switch (d)
	{
	case 1:
		enter(A);
		break;
	case 2:
		enter(B);
		break;
	case 3:
		enter(C);
		break;
	case 4:
		enter(D);
		break;
	case 5:
		enter(E);
		break;
	}

}
int ran;
void randomiz(int* arr)
{
	for (i = 0; i < 101; i++)
	{
		arr[rand() % 100] = 1;
		if (rand() % 25 == 23) { break; }
	}

}

void uslovia(int* arr)
{
	for (i = 0; i < 101; i++)
	{
		arr[i] = 0;
	}

	cout << endl;
	cout << "3HAK (0=+) - ";
	int p, o, y, left1, right1;
	cin >> p;
	cout << "4etHocTb (1=4et) - ";
	cin >> o;
	cout << "KpaTHocTb(ot 1 do 50) - ";
	cin >> y;
	cout << "Left border - ";
	cin >> left1;
	cout << "Right border - ";
	cin >> right1;
	int you = 0;
	if (((p == 1) || (p == 0)) && ((o == 1) || (o == 0)) && ((y > 0) && (y < 51)) && (left1 - 1 < right1))
	{
		you = 1;
	}

	if (you == 1)
	{
		if (p == 0)
		{
			for (i = 50; i < 101; i++)
			{
				arr[i] = 1;
			}
		}
		else {
			for (i = 0; i < 51; i++)
			{
				arr[i] = 1;
			}
		}

		if (o == 1)
		{
			for (i = 0; i < 101; i++)
			{
				if ((i % 2 == 1) && (arr[i] == 1)) { arr[i] = 0; }
			}
		}
		else {
			for (i = 0; i < 101; i++)
			{
				if ((i % 2 == 0) && (arr[i] == 1)) { arr[i] = 0; }
			}
		}

		for (i = 0; i < 101; i++)
		{
			if (((i - 50) % y != 0) && (arr[i] == 1)) { arr[i] = 0; }
		}

		for (i = 0; i < left1 + 50; i++)
		{
			arr[i - 50] = 0;
		}

		for (i = right1 + 51; i < 101; i++)
		{
			arr[i - 50] = 0;
		}
	}
}


void main3()
{
	cout << "Which array 1?" << endl;
	cout << "1. A" << endl;
	cout << "2. B" << endl;
	cout << "3. C" << endl;
	cout << "4. D" << endl;
	cout << "5. E" << endl;
	cin >> d;

	cout << "Which array 2?" << endl;
	cout << "1. A" << endl;
	cout << "2. B" << endl;
	cout << "3. C" << endl;
	cout << "4. D" << endl;
	cout << "5. E" << endl;
	cin >> j;

	cout << "Which operation?" << endl;
	cout << "1. Sum" << endl;
	cout << "2. Cross" << endl;
	cout << "3. Substruction" << endl;
	cout << "4. SimSubstruction" << endl;
	cin >> f;

	switch (d)
	{
	case 1:
		for (i = 0; i < 101; i++) { mas1[i] = A[i]; }
		break;
	case 2:
		for (i = 0; i < 101; i++) { mas1[i] = B[i]; }
		break;
	case 3:
		for (i = 0; i < 101; i++) { mas1[i] = C[i]; }
		break;
	case 4:
		for (i = 0; i < 101; i++) { mas1[i] = D[i]; }
		break;
	case 5:
		for (i = 0; i < 101; i++) { mas1[i] = E[i]; }
		break;
	}

	switch (j)
	{
	case 1:
		for (i = 0; i < 101; i++) { mas2[i] = A[i]; }
		break;
	case 2:
		for (i = 0; i < 101; i++) { mas2[i] = B[i]; }
		break;
	case 3:
		for (i = 0; i < 101; i++) { mas2[i] = C[i]; }
		break;
	case 4:
		for (i = 0; i < 101; i++) { mas2[i] = D[i]; }
		break;
	case 5:
		for (i = 0; i < 101; i++) { mas2[i] = E[i]; }
		break;
	}

	switch (f)
	{
	case 1:
		summas();
		break;
	case 2:
		cross();
		break;
	case 3:
		substr();
		break;
	case 4:
		simsubstr();
		break;
	}


}
int ter;
void change1()
{
	cout << endl;
	cout << "How?" << endl;
	cout << "1. Manual" << endl;
	cout << "2. Setup" << endl;
	cout << "3. Random" << endl;
	cin >> ter;
	cout << endl;
	switch (ter)
	{
	case 1:
		main2();
		break;
	case 2:
		cout << "Which array to change?" << endl;
		cout << "1. A" << endl;
		cout << "2. B" << endl;
		cout << "3. C" << endl;
		cout << "4. D" << endl;
		cout << "5. E" << endl;
		cin >> d;
		switch (d)
		{
		case 1:
			uslovia(A);
			break;
		case 2:
			uslovia(B);
			break;
		case 3:
			uslovia(C);
			break;
		case 4:
			uslovia(D);
			break;
		case 5:
			uslovia(E);
			break;
		}
		break;
	case 3:
		cout << "Which array to change?" << endl;
		cout << "1. A" << endl;
		cout << "2. B" << endl;
		cout << "3. C" << endl;
		cout << "4. D" << endl;
		cout << "5. E" << endl;
		cin >> d;
		switch (d)
		{
		case 1:
			randomiz(A);
			break;
		case 2:
			randomiz(B);
			break;
		case 3:
			randomiz(C);
			break;
		case 4:
			randomiz(D);
			break;
		case 5:
			randomiz(E);
			break;
		}
		break;
	}
}


int main()
{


	do {
		system("color F0");
		for (i = 0; i < 101; i++)
		{
			mas1[i] = 0;
			mas2[i] = 0;
			res[i] = 0;
		}

		print_menu();

		cout << endl << "A = ";
		printmas(A);
		cout << endl << "B = ";
		printmas(B);
		cout << endl << "C = ";
		printmas(C);
		cout << endl << "D = ";
		printmas(D);
		cout << endl << "E = ";
		printmas(E);
		cout << endl;

		get_variant();
		switch (variant) {
		case 1:
			change1();
			break;

		case 2:
			main3();
			break;

		case 3:
			Complement2();
			break;
		}


		if ((variant < 4) and (variant > 0))
			system("pause");

	} while (variant != 4);
}
