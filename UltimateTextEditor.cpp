#include <iostream>
#include <fstream>
#include <conio.h>
#include <windows.h>
#include <cstring>
//#include <cstdlib>

using namespace std;

void gotoRowCol(int rpos, int cpos)
{
	COORD scrn;
	HANDLE hOuput = GetStdHandle(STD_OUTPUT_HANDLE);
	scrn.X = cpos;
	scrn.Y = rpos;
	SetConsoleCursorPosition(hOuput, scrn);
}

struct Line
{
	int S;
	char* Cs;
};

struct Document
{
	Line* Lines;
	int NOL;
};

void INIT(Document &D, int &Cr, int &Cc)
{
	D.NOL = 1;
	D.Lines = new Line[D.NOL];
	Cr = Cc = 0;
	D.Lines[Cr].S = 0;
	D.Lines[Cr].Cs = NULL;
	//D.Lines[Cr].Cs = new char[1];
}

void PrintALine(int Cr, int Cc, Document D)
{
	cout << D.Lines[Cr].Cs;
}

void ReGrow(Document &D, int Cr, int Cc,int s)
{
	char* copy = new char[Cc];
	for (int i = 0; i < Cc; i++)
	{
		copy[i] = D.Lines[Cr].Cs[i];
	}
	D.Lines[Cr].Cs = copy;
}

void AddCharInALine(Document &D,int Cr, int &Cc, int s)
{
	D.Lines[Cr].Cs[Cc] = s;
	Cc++;
	D.Lines[Cr].Cs[Cc]  = '\0';
	for (int i = D.Lines[Cr].S; i < D.Lines[Cr].S + 1; i++)
	{
		cout << D.Lines[Cr].Cs[i];
	}
		
	D.Lines[Cr].S++;
}


void AddANewLine(int &Cr, int &Cc, Document &D,int s)
{
	Document CopyD;
	CopyD.Lines = D.Lines;
	D.NOL += 1;
	D.Lines = new Line[D.NOL];
	for (int i = Cr; i < D.NOL-1; i++)
	{
		D.Lines[i].Cs = CopyD.Lines[i].Cs;
	}
	Cr++;
	Cc = 0;
	D.Lines[Cr].S = 0;
	D.Lines[Cr].Cs = NULL;
	ReGrow(D, Cr, Cc, s);
	D.Lines[Cr].Cs = &D.Lines[Cr].Cs[Cc];
}

void arrowfunctions(int s, int &Cr, int &Cc)
{
		s = _getch();
		switch (s)
		{
		case 72:
			if (Cr > 0)
				Cr--;
			break;
		case 75:
			if (Cc > 0)
				Cc--;
			break;
		case 77:
			if (Cc < 80)
				Cc++;
			break;
		case 80:
			if (Cr < 80)
				Cr++;
			break;
		}
}

void BackSpace(Document D, int s, int &Cr, int &Cc)
{
	if (Cc > 0 && Cr > 0)
	{
		Cc--;
	}
	else if (Cc == 0 && Cr > 0)
	{
		D.NOL--;
		Cr--;
		Cc = D.Lines[Cr].S;
	}
	else if (Cc == 0 && Cr == 0)
	{
		Cc = 0;
		cout << ' ';
	}
	else
	{
		Cc -= 2;
		cout << ' ';
		Cc++;;
	}
}

void WritingData(Document D, char* filename)
{
	cout << "\nEnter Filename: ";
	cin >> filename;
	ofstream fout(filename);
	fout << D.NOL << endl;

	for (int i = 0; i < D.NOL; i++)
	{
		for (int j = 0; j < D.Lines[i].S; j++)
		{
			fout << D.Lines[i].Cs[j];
		}
		fout << endl;
	}
}

void CasesOfKeys(Document& D,int s, int &Cr, int &Cc,char *filename)
{
	switch (s)
	{
	case 224:
		arrowfunctions(s, Cr, Cc);
		break;
	case 8:
		BackSpace(D, s, Cr, Cc);
		break;
	case 4:
		cout << "\nDo you wanna save the document(CTRL+s for yes and CTRL+n for No): ";
	case 13:
		AddANewLine(Cr, Cc, D,s);
		break;
	case 14:
		cout << "\nThe Document Has Closed Without Saving\n";
		exit(1);
	case 19:
		WritingData(D, filename);
		cout << "\nThe Document Has Saved\n";
		break;
	default:
		AddCharInALine(D, Cr, Cc, s);
	//	PrintALine(Cr, Cc, D);
	}
}

int main()
{
	int Cr, Cc;
	int s;
	char filename[10];
	Document D;
	INIT(D, Cr, Cc);
	gotoRowCol(0, 99);
	cout << "Press Ctrl+d to close";
	gotoRowCol(0, 0);
	while (true)
	{
		if (_kbhit())
		{
			s = _getch();
			if (s!=13)
				ReGrow(D, Cr, Cc,s); 
			CasesOfKeys(D, s, Cr, Cc, filename); //Switch for Keys 
			gotoRowCol(Cr, Cc);
		}
	}
	system("pause");
	return 0;
}
