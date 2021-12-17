#include <string>
#include <iostream>
#include <time.h>
using namespace std;

	string round(string p1, string p2)
	{
		cout << "Game: " << p1 << " vs. " << p2 << endl;
		int p1p = 0; //points 0, 15, 30, 40, win
		int p2p = 0; 
		
		int s;

		while (p1p < 41 && p2p < 41)
		{
			cout << p1p << "/" << p2p << endl;
			s = rand() & 1;
			switch (s)
			{
			case 0:
				switch (p1p)
				{
				case 0: 
				case 15: 
					p1p += 15;
					break;
				case 30: 
				case 40: 
					p1p += 10;
				}
				break;
			case 1:
				switch (p2p)
				{
				case 0:
				case 15:
					p2p += 15;
					break;
				case 30:
				case 40:
					p2p += 10;
				}
				break;
			}
		}
		
		if (p1p > 41)
		{
			cout << p1 << " Wins " << endl;
			return p1;
		}
		else
		{
			cout << p2 << " Wins " << endl;
			return p2;
		}
	}

	int main()
	{

		srand(time(NULL));
		string* r1 = new string[8];
		cout << "Please Enter 8 names: " << endl;
		for (int i = 1; i < 9; i++)
		{
			cout << i << ": ";
			cin >> r1[i-1];
		}

		cout << endl << "First Round: 8 players" << endl;

		string* r2 = new string[4];
		r2[0] = round(r1[0], r1[1]);
		r2[1] = round(r1[2], r1[3]);
		r2[2] = round(r1[4], r1[5]);
		r2[3] = round(r1[6], r1[7]);

		cout << endl << "Second Round: 4 players: " << r2[0] << ", " << r2[1] << ", " << r2[3] << ", " << r2[2] << endl;

		string* r3 = new string[2];
		r3[0] = round(r2[0], r2[1]);
		r3[1] = round(r2[2], r2[3]);

		cout << endl << "Third Round: 2 players: " << r3[0] << ", " << r3[1] << endl;

		string winner = round(r3[0], r3[1]);

		cout << endl << endl << "The Final Winner: " << winner << endl;
		system("PAUSE");
	}
