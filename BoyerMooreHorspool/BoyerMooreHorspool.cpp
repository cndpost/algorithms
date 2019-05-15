// BoyerMooreHorspool.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <vector>
#include <string>
#include <queue>

//#define DEBUG 1

int Ord(char ch) {
	return (ch - 'a')+1;
};

int  *CreateRtOccurence(std::string pattern, int s)
{
	std::cout << "CreateRtOccurence for BMH algorithm with pattern: " << pattern << " alphabet size " << s << std::endl;
	int *rt = new int[s];
	int m = pattern.length();
	for (int i = 0; i <= s; i++) {
		rt[i] = m;
	};

	for (int i = 0; i < m; i++) {
		rt[Ord(pattern[i])] = m - i - 1;
	}

#ifdef DEBUG
	for (int i = 0; i < s; i++) {
		std::cout << rt[i] << std::endl;
	}
	std::cin >> m;
#endif

	return rt;

};

int max (int a, int b)
{
	if (a >= b)
		return a;
	else
		return b;
};

std::deque<int> *BoyerMooreHorspool(std::string pattern, std::string text, int s)
{
	std::cout << "using BMH algorithm to find " << pattern << " in " << text << " assuming lower case alphabet size " << s << std::endl;

	std::deque<int> *q = new std::deque<int>();
	int m = pattern.length();
	int n = text.length();
	int *rt = CreateRtOccurence(pattern, s);
	int i = 0, j;
	char c;
	while (i <= (n - m)) {
#ifdef DEBUG
		std::cout << "while 1 i = " << i << std::endl;
#endif
		j = m - 1;
		while ((j >= 0) && (text[i + j] == pattern[j])) {
#ifdef DEBUG
			std::cout << "while 2 j =" << j << std::endl;
#endif
			j--;
		}
		if (j < 0) {
			q->push_back(i);
		}
		c = text[i + m - 1];
		i = i + max(1,rt[Ord(c)]); //this change to the book's algorithm allows a minimum increase of i by 1 so no infinite loop
	};

//	delete[] rt;
	return q;
};

int main()
{
	std::cout << "Boyer Moore Horspool Algorithm\n";

	//take text and pattern from stdin
	//output all index that have pattern shown in text
	std::cout << "enter text:";
	std::string text;
	std::cin >> text;

	std::cout << "enter pattern:";
	std::string pattern;
	std::cin >> pattern;
	int s = 26; //assuming we only use lower case a-z
	std::deque<int> *q = BoyerMooreHorspool(pattern, text, s);
	std::cout << "size of the output is " << q->size() << std::endl;
	while (!q->empty()) {
		std::cout << q->front() << std::endl;
		q->pop_front();
	};
	delete q;
	return 0;
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
