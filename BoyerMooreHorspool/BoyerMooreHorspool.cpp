// BoyerMooreHorspool.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <vector>
#include <string>
#include <queue>

int Ord(char ch) {
	return (ch - 'a');
};

int  *CreateRtOccurence(std::string pattern, int s)
{
	int *rt = new int(pattern.length());
	int m = pattern.length();
	for (int i = 0; i <= s; i++) {
		rt[i] = m;
	};

	for (int i = 0; i < m; i++) {
		rt[Ord(pattern[i])] = m - i - 1;
	}
	return rt;
};

std::deque<int> *BoyerMooreHorspool(std::string pattern, std::string text, int s)
{
	std::deque<int> *q = new std::deque<int>();
	int m = pattern.length();
	int n = text.length();
	int *rt = CreateRtOccurence(pattern, s);
	int i = 0;
	while (i <= (n - m)) {
		j = m - 1;
		while ((j >= 0) && (t[i + j] == pattern[j])) {
			j--;
		}
		if (j < 0) {
			q.push_back(i);
		}
		c = t[i + m - i];
		i = i + rt[Ord(c)];
	}
};

int main()
{
    std::cout << "Hello World!\n"; 
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
