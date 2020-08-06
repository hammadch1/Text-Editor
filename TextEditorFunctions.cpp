#include<iostream>
#include<fstream>

using namespace std;
void Toupper(char a[100]);
void Tolower(char a[100]);
void F3asensitve(char w[100], char Fn[100], char of[100]);
void F3bsensitve(char w[100], char Fn[100], char of[100]);
void findingScentence(char sentence[100], char fn[100], char ot[100]);
void FindingSubword(char sub[100], char fn[100], char out[100]);
void changingFirstWord(char word[100], char changingWord[100], char filename[100], char outputFilname[100]);
void changingAllWords(char word[100], char changingWord[100], char filename[100], char outputFilname[100]);
int AverageWordLenght(char In[100]);
void countingSubword(char sub[100], char fn[100], char out[100]);
int specialcharcter(char in[100]);
int NumberofSenctenceCount(char in[100]);
int largestWord(char in[100]);
void prefix(char w[], char w2[100], char out[100]);
void postfix(char w[], char w2[100], char out[100]);
int smallestWord(char in[100]);
void MergingFile(char in1[100], char in2[100], char out2[100]);
void paracounting(char file[100], char out[100]);
int main()
{
	ifstream Rdr("Testcases.txt");
	int choice;
	while (true)
	{
		Rdr >> choice;
		switch (choice)
		{
		case 1:
		{
				  char a[100], filename[100];
				  Rdr >> a >> filename;
				  Toupper(a);
				  ofstream Wr(filename);
				  Wr << a << endl;
				  break;
		}
		case 2:
		{
				  char a[100], filename[100];
				  Rdr >> a >> filename;
				  Tolower(a);
				  ofstream Wr(filename);
				  Wr << a << endl;
				  break;
		}
		case 3:
		{
				  char option;
				  char w[100];
				  char Inputfile[100];
				  char Outputfile[100];
				  Rdr >> option;
				  if (option == 'a')
				  {
					  Rdr >> w >> Inputfile >> Outputfile;
					  F3asensitve(w, Inputfile, Outputfile);
					  break;
				  }
				  if (option == 'b')
				  {
					  Rdr >> w >> Inputfile >> Outputfile;
					  F3bsensitve(w, Inputfile, Outputfile);
					  break;
				  }
				  break;
		}
		case 4:
		{
				  char sentence[100];
				  char filename[100];
				  char outputfile[100];
				  Rdr.ignore();
				  Rdr.getline(sentence, 100, '.');
				  Rdr >> filename >> outputfile;
				  findingScentence(sentence, filename, outputfile);
				  break;
		}
		case 5:
		{
				  char Sub[100];
				  char filename[100];
				  char outputfile[100];
				  Rdr >> Sub >> filename >> outputfile;
				  FindingSubword(Sub, filename, outputfile);
				  break;
		}
		case 6:
		{
				  char opt;
				  char word[100];
				  char changingWord[100];
				  char filename[100];
				  char outputFilname[100];
				  Rdr >> opt;
				  if (opt == 'a')
				  {
					  Rdr >> word >> changingWord >> filename >> outputFilname;
					  changingFirstWord(word, changingWord, filename, outputFilname);
					  break;
				  }
				  if (opt == 'b')
				  {
					  Rdr >> word >> changingWord >> filename >> outputFilname;
					  changingAllWords(word, changingWord, filename, outputFilname);
					  break;
				  }
				  break;
		}
		case 7:
		{
				  char filename[100];
				  char output[100];
				  Rdr >> filename >> output;
				  int v = AverageWordLenght(filename);
				  ofstream Wr(output);
				  Wr << v;
				  break;
		}
		case 8:
		{
				  char Sub[100];
				  char filename[100];
				  char outputfile[100];
				  Rdr >> Sub >> filename >> outputfile;
				  countingSubword(Sub, filename, outputfile);
				  break;
		}
		case 9:
		{
				  char filename[100];
				  char output[100];
				  Rdr >> filename >> output;
				  int v = specialcharcter(filename);
				  ofstream Wr(output);
				  Wr << v;
				  break;
		}
		case 10:
		{
				   char filename[100];
				   char output[100];
				   Rdr >> filename >> output;
				   int v = NumberofSenctenceCount(filename);
				   ofstream Wr(output);
				   Wr << v;
				   break;
		}
		case 11:
		{
				   char filename[100];
				   char output[100];
				   Rdr >> filename >> output;
				   int v = largestWord(filename);
				   ofstream Wr(output);
				   Wr << v;
				   break;
		}
		case 12:
		{
				   char w[100];
				   char w2[100];
				   char output[100];
				   Rdr >> w >> w2 >> output;
				   prefix(w, w2, output);
				   break;
		}
		case 13:
		{
				   char w[100];
				   char w2[100];
				   char output[100];
				   Rdr >> w >> w2 >> output;
				   postfix(w, w2, output);
				   break;
		}
		case 14:
		{
				   char filename[100];
				   char output[100];
				   Rdr >> filename >> output;
				   int v = smallestWord(filename);
				   ofstream Wr(output);
				   Wr << v;
				   break;
		}
		case 15:
		{
				   char filename1[100];
				   char filename2[100];
				   char ouputfile[100];
				   Rdr >> filename1 >> filename2 >> ouputfile;
				   MergingFile(filename1, filename2, ouputfile);
				   break;
		}
		case 16:
		{
				   char filename[100];
				   char output[100];
				   Rdr >> filename >> output;
				   paracounting(filename, output);
				   break;
		}
		}
	}
	return 0;
}
void Toupper(char a[100])
{
	for (int i = 0; i < strlen(a); i++)
	{
		a[i] = toupper(*(a + i));
	}
}
void Tolower(char a[100])
{
	for (int i = 0; i < strlen(a); i++)
	{
		a[i] = tolower(*(a + i));
	}
}
void F3asensitve(char w[100], char Fn[100], char of[100])
{
	ifstream Rdr(Fn);
	ofstream Wr(of);
	char s[100];
	int  Wc = 0;
	while (Rdr >> s)
	{
		if (strcmp(s, w) == 0)
		{
			Wr << Wc << " ";
		}
		Wc++;

	}
}
void F3bsensitve(char w[100], char Fn[100], char of[100])
{
	ifstream Rdr(Fn);
	ofstream Wr(of);
	char s[100];
	int  Wc = 0;
	Toupper(w);
	while (Rdr >> s)
	{
		Toupper(s);
		if (strcmp(s, w) == 0)
		{
			Wr << Wc << " ";
		}
		Wc++;

	}
}
void findingScentence(char sentence[100], char fn[100], char ot[100])
{
	ifstream Rdr(fn);
	ofstream Wr(ot);
	char s[100];
	int Wc = 0;
	while (Rdr.getline(s, 100, '.'))
	{
		Rdr.ignore();
		if (strcmp(s, sentence) == 0)
		{
			Wr << Wc << " ";
		}
		Wc++;
	}
}
void FindingSubword(char sub[100], char fn[100], char out[100])
{
	ifstream Rdr(fn);
	ofstream Wr(out);
	char s[100];
	int wc = 0;
	int counter = 0;
	while (Rdr >> s)
	{
		for (int k = 0; k < strlen(s); k++)
		{
			if (sub[0] == s[k])
			{
				for (int j = 0; j < strlen(sub); j++)
				{
					if (s[k] == sub[j])
					{
						counter++;
						k++;
					}
					else
					{
						k--;
						counter = 0;
						break;
					}
				}
				if (counter == strlen(sub))
				{
					Wr << wc << " ";
					counter = 0;
				}
			}
		}
		wc++;
	}
}
void changingFirstWord(char word[100], char changingWord[100], char filename[100], char outputFilname[100])
{
	ifstream Rdr(filename);
	ofstream Wr(outputFilname);
	char s[100];
	int counter = 0;
	int x = 1;
	int counter2 = 0;
	while (Rdr >> s)
	{
		for (int k = 0; k < strlen(word);)
		{
			if (s[k] == word[k])
			{
				counter++;
				k++;
			}
			else
			{
				break;
			}
		}
		if (x == 1)
		{
			if (counter == strlen(word))
			{
				for (int i = 0; i < strlen(changingWord); i++)
				{
					s[i] = changingWord[i];
					counter2++;
					if (counter2 == strlen(changingWord))
					{
						for (int i = counter2; i < strlen(s); i++)
						{
							s[i] = '\0';
						}
					}
				}
				counter = 0;
				x++;
			}
		}
		for (int i = 0; i < strlen(s); i++)
		{
			Wr << s[i];
			if (s[i] == '.')
			{
				Wr << endl;
			}
		}
		Wr << " ";
	}
}
void changingAllWords(char word[100], char changingWord[100], char filename[100], char outputFilname[100])
{
	ifstream Rdr(filename);
	ofstream Wr(outputFilname);
	char s[100];
	int counter = 0;
	int counter2 = 0;
	while (Rdr >> s)
	{
		for (int k = 0; k < strlen(word);)
		{
			if (s[k] == word[k])
			{
				counter++;
				k++;
			}
			else
			{
				counter = 0;
				break;
			}
		}
		if (counter == strlen(s))
		{
			for (int i = 0; i < strlen(changingWord); i++)
			{
				s[i] = changingWord[i];
				counter2++;
				if (counter2 == strlen(changingWord))
				{
					for (int i = counter2; i <= strlen(s); i++)
					{
						s[i] = '\0';
					}
				}
			}
			counter2 = 0;
			counter = 0;
		}
		for (int i = 0; i < strlen(s); i++)
		{
			Wr << s[i];
			if (s[i] == '.')
			{
				Wr << endl;
				Rdr.ignore();
			}
		}
		counter = 0;
		Wr << " ";
	}
}
int AverageWordLenght(char In[100])
{
	ifstream Rdr(In);
	char s[100];
	int sum = 0;
	int count = 0;
	while (Rdr >> s)
	{
		sum = sum + strlen(s);
		count++;
	}
	int div = sum / count;
	return div;
}
void countingSubword(char sub[100], char fn[100], char out[100])
{
	ifstream Rdr(fn);
	ofstream Wr(out);
	char s[100];
	int wc = 0;
	int counter = 0;
	int counter2 = 1;
	while (Rdr >> s)
	{
		for (int k = 0; k < strlen(s); k++)
		{
			if (sub[0] == s[k])
			{
				for (int j = 0; j < strlen(sub); j++)
				{
					if (s[k] == sub[j])
					{
						counter++;
						k++;
					}
					else
					{
						k--;
						counter = 0;
						break;
					}
				}
				if (counter == strlen(sub))
				{
					/*Wr << wc << " ";
					counter = 0;*/
					counter2++;
				}
			}
		}
		wc++;
	}
	Wr << counter2;
}
int specialcharcter(char in[100])
{
	ifstream Rdr(in);
	char s[100];
	int counter = 0;
	while (Rdr >> s)
	{
		for (int i = 0; i < strlen(s);)
		{
			if ((s[i] >= 'a'&& s[i] <= 'z') || (s[i] >= 'A'&& s[i] <= 'Z'))
			{
				i++;
			}
			else if (s[i] >= '1'&& s[i] <= '9')
			{
				i++;
			}
			else
			{
				counter++;
				i++;
			}
		}
	}
	return counter;
}
int NumberofSenctenceCount(char in[100])
{
	ifstream Rdr(in);
	char s[100];
	int counter = 0;
	Rdr.getline(s, 100, '\0');
	for (int i = 0; i < strlen(s); i++)
	{
		if (((s[i] == '.') && (s[i + 1] == ' ')) || (s[i] == '.') && (s[i + 1] == '\0'))
		{
			counter++;
		}
	}

	return counter;
}
int largestWord(char in[100])
{
	ifstream Rdr(in);
	char s[100];
	int sum = 0;
	int count = 0;
	Rdr >> s;
	sum = strlen(s);
	while (Rdr >> s)
	{
		for (int i = 0; i < strlen(s); i++)
		{
			if (s[i] == '.')
			{
				count++;
				break;
			}
			count = 0;
		}
		if (sum < strlen(s))
		{
			sum = strlen(s);
			if (count == 1)
			{
				sum--;
			}
		}

	}
	return sum;
}
void prefix(char w[], char w2[100], char out[100])
{
	int i = 0;
	int j = 0;
	int k = 0;
	char*temp = new char[strlen(w) + strlen(w2)];
	for (i = 0; i < strlen(w2); i++)
	{
		*(temp + i) = w2[j];
		j++;
	}
	for (i = j; i < strlen(w) + j; i++)
	{
		*(temp + i) = w[k];
		k++;
	}
	ofstream Wr(out);
	for (int i = 0; i < (strlen(w) + strlen(w2)); i++)
	{
		Wr << temp[i];
	}
	//	delete[]temp;
}
void postfix(char w[], char w2[100], char out[100])
{
	int i = 0;
	int j = 0;
	int k = 0;
	char*temp = new char[strlen(w) + strlen(w2)];
	for (i = 0; i < strlen(w); i++)
	{
		*(temp + i) = w[j];
		j++;
	}
	for (i = j; i < strlen(w2) + j; i++)
	{
		*(temp + i) = w2[k];
		k++;
	}
	ofstream Wr(out);
	for (int i = 0; i < (strlen(w) + strlen(w2)); i++)
	{
		Wr << temp[i];
	}
	//	delete[]temp;
}
void MergingFile(char in1[100], char in2[100], char out2[100])
{
	ifstream Rdr(in1);
	ifstream Rdr2(in2);
	ofstream Wr(out2);
	char s[100];
	char s2[100];
	Rdr.getline(s, 100, '\0');
	Rdr2.getline(s2, 100, '\0');
	Wr << "F1:" << endl;
	for (int i = 0; i < strlen(s); i++)
	{
		Wr << s[i];
	}
	Wr << "\nF2" << endl;
	for (int i = 0; i < strlen(s2); i++)
	{
		Wr << s2[i];
	}

}
int smallestWord(char in[100])
{
	ifstream Rdr(in);
	char s[100];
	int sum = 0;
	int count = 0;
	Rdr >> s;
	sum = strlen(s);
	while (Rdr >> s)
	{
		for (int i = 0; i < strlen(s); i++)
		{
			if (s[i] == '.')
			{
				count++;
				break;
			}
			count = 0;
		}
		if (sum > strlen(s))
		{
			sum = strlen(s);
			if (count == 1)
			{
				sum--;
			}
		}

	}
	return sum;
}
void paracounting(char file[100], char out[100])
{
	ifstream Rdr(file);
	ofstream Wr(out);
	char s[100];
	int counter = 0;
	Rdr.getline(s, 100, '\0');
	for (int i = 0; i < strlen(s); i++)
	{
		if ((s[i] == '\n') && (s[i + 1] == '\n'))
		{
			counter++;
		}
	}
	Wr << counter;
}