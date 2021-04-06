#pragma once
#include "Core.h"

class PositionGenerator
{
public:
	PositionGenerator();
	void DiagnosticPrint();
	void GenerateNextLevel();
	bool KingCheck(ChessPosition CP, int j, int i);
	void AddNextMove(int x, int y, int x1, int y1);
	void AddNextMovePawn(int x, int y, int x1, int y1);
	void AddNextMoveCas(int opt);
	void AddNextMoveEnPassant(int x, int y, int x1, int y1);
	void AddNextMoveProm(int x, int y, int x1, int y1, char Fig);
	string GetMove();
	void Move(string Move);
	void SyncAnalyzeMove();
	bool CheckAnalyzeSync();
	void Reset();
	~PositionGenerator();
	ChessPosition* CurrentPos;
private:
	ChessPosition* Start, * ReferencePos;
};