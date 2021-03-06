//Auth: Jakub Kleban
#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include "Bajt.h"

using namespace std;

vector <Bajt> filter(string file);

int main(int argc, char* argv[])
{
	// Check the number of parameters
	if (argc < 2) {
		// Tell the user how to run the program
		cerr << "Type in CMD!" << endl;
		cerr << "Usage: " << argv[0] << " <file_name>" << endl;
		system("pause"); return 1;
	}
	
	string file = argv[1];
	vector <Bajt> even, odd, filtered = filter(file);

	for (Bajt n : filtered)
	{
		if (n.isEvenNumOfOnes())
			even.push_back(n);
		else
			odd.push_back(n);
	}
	
	sort(even.begin(), even.end());
	sort(odd.begin(), odd.end(), greater<Bajt>());

	for (Bajt n: even)
	{
		cout << n.getBinary() << "(bin) " <<  n.getHex() << "(hex)\n" ;
	} cout << "\n";
	for (Bajt n : odd)
	{
		cout << n.getBinary() << "(bin) " << n.getHex() << "(hex)\n" ;
	}

	system("pause"); return 0;
}

vector <Bajt> filter(string file)
{
	vector <Bajt> tab;
	string line;
	ifstream myfile(file);
	if (myfile.is_open())
	{
		char count = 0; int n1, n2;

		while (getline(myfile, line))
		{
			for (int i = 0; i < line.length(); i++)
			{
				//filter hex ascii
				if ((line[i] > 47 && line[i] < 58) || (line[i] > 64 && line[i] < 71) || (line[i] > 96 && line[i] < 103))
				{
					if (line[i] > 96 && line[i] < 103)
						line[i] = toupper(line[i]); //uppercase small chars ( a -> A )

					string x = string(1, line[i]);
					if (count == 0)
					{
						istringstream(x) >> hex >> n1; //char(hex) to dec
						count++;
					}
					else
					{
						istringstream(x) >> hex >> n2; //char(hex) to dec
						tab.push_back(Bajt(n1, n2));

						count = 0;
					}
				}
			}
		}
		myfile.close();

		if (count != 0) //if not even number of hex chars
			tab.push_back(Bajt(n1));
	}
	else
		cout << "Unable to open file";

	return tab;
}
