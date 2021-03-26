#pragma once
#include "Core.h"
#include "Generator.h"

class Valuation
{
private:
	PositionGenerator* engine;
	int Depth = 0;
public:
	Valuation(PositionGenerator& e);
	void TimeAnalysis(int depth);
};