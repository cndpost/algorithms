// KnuthMorrisPratt.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <string>
#include <vector>
#include <queue>


std::vector<int> FindBorders(std::string pattern)
{
	int m = pattern.length();
	std::vector<int> b;
	int j = 0;
	b.push_back(0);
	b.push_back(1);
	for (int i = 1; i <= m; i++) {
		while ((j > 0) && (pattern[j] != pattern[i])) {
			j = b[j];
		}
		if (pattern[j] == pattern[i]) { //if matched a char, move both pattern and target indices, push the index itself
			j++;
		}
		b.push_back(j);
	}
	return b;
};

std::deque<int>  *KnuthMorrisPratt(std::string pattern, std::string text) 
{
	std::cout << "using KMP algorithm to find " << pattern << " in " << text << std::endl;
	std::deque<int> *q = new std::deque<int>();
	int m = pattern.length();
	int n = text.length();
	std::vector<int> b = FindBorders(pattern);
	int j = 0;
	for (int i = 0; i <= n; i++) {
		while ((j > 0) && (pattern[j] != text[i]))
			j = b[j];
		if (pattern[j] == text[i])
			j++;
		if (j == m) {
			q->push_back((i - j) + 1);
			j = b[j];
		}
	}
	return q;
}


int main(int argc, std::string argv[])
{
    std::cout << "KnuthMorrisPratt Algorithm\n"; 

	//take text and pattern from stdin
	//output all index that have pattern shown in text
	std::cout << "enter text:";
	std::string text;
	std::cin >> text;

	std::cout << "enter pattern:";
	std::string pattern;
	std::cin >> pattern;
	std::deque<int> *q = KnuthMorrisPratt(pattern, text);
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
