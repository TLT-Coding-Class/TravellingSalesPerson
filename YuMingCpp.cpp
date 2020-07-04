// sale.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
	ifstream filein;
	filein.open("salein.txt");
	int distance[3] = {};
	for (int i = 0; i < 3; i++)
	{
		string line;
		getline(filein, line);
		distance[i] = stoi(line);
	}
	filein.close();
	ofstream fileout;
	fileout.open("saleout.txt");
	if (distance[0] < distance[1] && distance[0] < distance[2])
	{
		string ans = to_string(distance[1] + distance[2]);
		fileout << ans;
	}
	if (distance[1] < distance[0] && distance[1] < distance[2])
	{
		string ans = to_string(distance[0] + distance[2]);
		fileout << ans;
	}
	if (distance[2] < distance[0] && distance[2] < distance[1])
	{
		string ans = to_string(distance[0] + distance[1]);
		fileout << ans;
	}
}
