#pragma once
#include "UCIcom.h"
#include <string>

//UCIcom::UCIcom()
//{
//}

string UCIcom::ExtractFW(string& line)
{
	string TempS;
	while (0 < line.length())
	{
		if (line[0] != ' ')
		{
			TempS += line[0];
			line.erase(line.begin());
			
		}
		else break;
	}
	while (0 < line.length())
	{
		if (line[0] == ' ')
		{
			line.erase(line.begin());
		}
		else break;
	}
	return TempS;
}

string GetBestMoveInfinite(PositionGenerator PG)
{
	
	return PG.GetMove();
}
void GetBestMoveTime(PositionGenerator PG, int ms)
{
	//Sleep(ms);
	cout << "bestmove " << PG.GetMove() << "\n";
}

void UCIcom::Run()
{
	while (true)
	{
		getline(cin, input);
		LastWord = ExtractFW(input);
		if (LastWord == "uci")
		{
			cout << "id name Webber\n";
			cout << "id author Martins Mickus\n";
			input.erase();
		}
		else if (LastWord == "isready")
		{
			cout << "readyok\n"; ///////////////////////
			input.erase();
		}
		else if (LastWord == "ucinewgame")
		{
			engine.Reset();
			input.erase();
		}
		else if (LastWord == "position")
		{
			if (ExtractFW(input) == "startpos")
			{
				if (ExtractFW(input) == "moves")
				{
					engine.Reset();
					for (LastWord = ExtractFW(input); LastWord.size() == 4; LastWord = ExtractFW(input)) // Promotion not working yet
					{
						engine.Move(LastWord); /////////////////////////
					}
				}
			}
			else
			{
				input.erase();
			}
		}
		else if (LastWord == "go")
		{
			if (ExtractFW(input) == "movetime")
			{
				int time = stoi(ExtractFW(input));
				thread t1(GetBestMoveTime, ref(engine), time);
				t1.join();
			}
			//thread t1(engine.GetMove());
			///t1.join();
		}
		else if (LastWord == "Diag")
		{
			engine.DiagnosticPrint();
		}
		else
		{
			cout << "Wrong command!\n";
			input.erase();
		}
	}
}
