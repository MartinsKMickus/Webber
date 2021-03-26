#include "UCIcom.h"
#include "Valuation.h"

atomic<bool> ExitThreadFlag1 = false;

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
void GetBestMoveTime(PositionGenerator& PG, string& bMove)
{
	Valuation v(PG);
	//int temp = -1000;
	for (int i = 0; i < 4; i++)
	{
		v.TimeAnalysis(i);
	}
	
	bMove = PG.GetMove();
	cout << "info score cp ";
	if (PG.CurrentPos->Turn) cout << PG.CurrentPos->valuation;
	else cout << -PG.CurrentPos->valuation;
	cout << "\n";
}
void GetBestMoveDepth(PositionGenerator& PG, string& bMove, int depth)
{
	Valuation v(PG);
	//int temp = -1000;
	for (int i = 0; i < depth; i++)
	{
		v.TimeAnalysis(i);
	}

	bMove = PG.GetMove();
	cout << "info score cp ";
	if (PG.CurrentPos->Turn) cout << PG.CurrentPos->valuation;
	else cout << -PG.CurrentPos->valuation;
	cout << "\n";
}
void CallAnalyseWait(PositionGenerator& PG, int ms)
{
	
	string bMove;
	thread t2(GetBestMoveTime, ref(PG), ref(bMove));
	
	Sleep(ms);
	//ExitThreadFlag1 = true;
	t2.join();
	//ExitThreadFlag1 = false;
	cout << "bestmove " << bMove << "\n";
	
}
void CallAnalyseDepth(PositionGenerator& PG, int depth)
{

	string bMove;
	thread t2(GetBestMoveDepth, ref(PG), ref(bMove), depth);

	//Sleep(ms);
	//ExitThreadFlag1 = true;
	t2.join();
	//ExitThreadFlag1 = false;
	cout << "bestmove " << bMove << "\n";

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
					for (LastWord = ExtractFW(input); LastWord.size() > 0; LastWord = ExtractFW(input))
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
			LastWord = ExtractFW(input);
			if (LastWord == "movetime")
			{
				int time = stoi(ExtractFW(input));
				
				thread t1(CallAnalyseWait, ref(engine), time);
				t1.join();
			}
			else if (LastWord == "depth")
			{
				int depth = stoi(ExtractFW(input));

				thread t1(CallAnalyseDepth, ref(engine), depth);
				t1.join();
			}
			//thread t1(engine.GetMove());
			///t1.join();
		}
		else if (LastWord == "Diag")
		{
			engine.DiagnosticPrint();
		}
		else if (LastWord == "stop")
		{
			
		}
		else if (LastWord == "quit")
		{
			return;
		}
		else
		{
			cout << "Wrong command!\n";
			input.erase();
		}
	}
}
