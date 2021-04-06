#pragma once
#include "Core.h"
#include "Generator.h"

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