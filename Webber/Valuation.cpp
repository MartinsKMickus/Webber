#include "Valuation.h"

Valuation::Valuation(PositionGenerator& e)
{
	engine = &e;
	engine->SyncAnalyzeMove();
}
void Valuation::TimeAnalysis(int depth = 0)
{
	if (depth == 0)
	{
		if (engine->CurrentPos->NextPositions.size() == 0)
		{
			engine->GenerateNextLevel();
			if (engine->CurrentPos->NextPositions.size() == 0)
			{
				if (engine->CurrentPos->Turn)
				{
					engine->CurrentPos->valuation = -900;
				}
				else
				{
					engine->CurrentPos->valuation = 900;
				}
			}
		}

		// Place for board valuation.

		if (engine->CurrentPos->PreviousPosition != NULL)
		{
			if (engine->CurrentPos->Turn) // If current valuation move is for white.
			{
				if (engine->CurrentPos->PreviousPosition->valuation > engine->CurrentPos->valuation) // If previous valuation is higher and this lower then previous as for black is better.
				{
					engine->CurrentPos->PreviousPosition->valuation = engine->CurrentPos->valuation;
				}
			}
			else
			{
				if (engine->CurrentPos->PreviousPosition->valuation < engine->CurrentPos->valuation)
				{
					engine->CurrentPos->PreviousPosition->valuation = engine->CurrentPos->valuation;
				}
			}
		}
		if (!engine->CheckAnalyzeSync())
		{
			engine->CurrentPos = engine->CurrentPos->PreviousPosition;
		}
		return;
	}
	else
	{
		if (engine->CurrentPos->PreviousPosition != NULL)
		{
			if (engine->CurrentPos->Turn) // If current valuation move is for white.
			{
				if (engine->CurrentPos->PreviousPosition->valuation > engine->CurrentPos->valuation) // If previous valuation is higher and this lower then previous as for black is better.
				{
					engine->CurrentPos->PreviousPosition->valuation = engine->CurrentPos->valuation;
				}
			}
			else
			{
				if (engine->CurrentPos->PreviousPosition->valuation < engine->CurrentPos->valuation)
				{
					engine->CurrentPos->PreviousPosition->valuation = engine->CurrentPos->valuation;
				}
			}
		}
		for (int i = 0; i < engine->CurrentPos->NextPositions.size(); i++)
		{
			engine->CurrentPos = &engine->CurrentPos->NextPositions[i];
			TimeAnalysis(depth - 1);
		}
	}
	if (!engine->CheckAnalyzeSync())
	{
		engine->CurrentPos = engine->CurrentPos->PreviousPosition;
	}
	return;
}