#pragma once
#include "Generator.cpp"

class UCIcom
{
private:
	PositionGenerator engine;
	string input, LastWord;
public:
	//UCIcom();
	string ExtractFW(string& line);
	//void GetBestMove(int a);
	void Run();
};