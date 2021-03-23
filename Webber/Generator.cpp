#include "core.h"

class PositionGenerator
{
public:
	PositionGenerator()
	{
		CurrentPos = ChessPosition();
		//CurrentPos.BAttackedSquares;
	}
	void DiagnosticPrint()
	{
		for (int i = 0; i < 8; i++)
		{
			for (int j = 0; j < 8; j++)
			{
				cout << CurrentPos.ChessBoard[i][j] << " ";
			}
			cout << endl;
		}
		cout << endl;
		for (int i = 0; i < 8; i++)
		{
			for (int j = 0; j < 8; j++)
			{
				cout << CurrentPos.BAttackedSquares[i][j] << " ";
			}
			cout << endl;
		}
		cout << endl;
		for (int i = 0; i < 8; i++)
		{
			for (int j = 0; j < 8; j++)
			{
				cout << CurrentPos.WAttackedSquares[i][j] << " ";
			}
			cout << endl;
		}
	}
	void GenerateNextLevel()
	{
		ChessPosition Positions = CurrentPos;
		int xAsis, yAsis;
		int x, y;
		if (Positions.Turn)
		{
			for (int i = 0; i < 8; i++)
			{
				yAsis = i;
				for (int j = 0; j < 8; j++)
				{
					xAsis = j;
					switch (Positions.ChessBoard[i][j]) // Movement for White pieces.
					{
					case 'R':
						for (int x = xAsis + 1; x < 8; x++)
						{
							if (Positions.ChessBoard[i][x] > 91 || Positions.ChessBoard[i][x] == ' ')
							{
								AddAndMove(j, i, x, i);
							}
							else break;
							if (Positions.ChessBoard[i][x] != ' ') break;
						}
						for (int x = xAsis - 1; x >= 0; x--)
						{
							if (Positions.ChessBoard[i][x] > 91 || Positions.ChessBoard[i][x] == ' ')
							{
								AddAndMove(j, i, x, i);
							}
							else break;
							if (Positions.ChessBoard[i][x] != ' ') break;
						}
						for (int y = yAsis + 1; y < 8; y++)
						{
							if (Positions.ChessBoard[y][j] > 91 || Positions.ChessBoard[y][j] == ' ')
							{
								AddAndMove(j, i, j, y);
							}
							else break;
							if (Positions.ChessBoard[y][j] != ' ') break;
						}
						for (int y = yAsis - 1; y >= 0; y--)
						{
							if (Positions.ChessBoard[y][j] > 91 || Positions.ChessBoard[y][j] == ' ')
							{
								AddAndMove(j, i, j, y);
							}
							else break;
							if (Positions.ChessBoard[y][j] != ' ') break;
						}
						break;
					case 'N':
						if (yAsis + 2 < 8)
						{
							if (xAsis + 1 < 8)
							{
								if (Positions.ChessBoard[yAsis + 2][xAsis + 1] > 91 || Positions.ChessBoard[yAsis + 2][xAsis + 1] == ' ')
								{
									AddAndMove(j, i, xAsis + 1, yAsis + 2);
								}
							}
							if (xAsis - 1 >= 0)
							{
								if (Positions.ChessBoard[yAsis + 2][xAsis - 1] > 91 || Positions.ChessBoard[yAsis + 2][xAsis - 1] == ' ')
								{
									AddAndMove(j, i, xAsis - 1, yAsis + 2);
								}
							}
						}
						if (yAsis - 2 >= 0)
						{
							if (xAsis + 1 < 8)
							{
								if (Positions.ChessBoard[yAsis - 2][xAsis + 1] > 91 || Positions.ChessBoard[yAsis - 2][xAsis + 1] == ' ')
								{
									AddAndMove(j, i, xAsis + 1, yAsis - 2);
								}
							}
							if (xAsis - 1 >= 0)
							{
								if (Positions.ChessBoard[yAsis - 2][xAsis - 1] > 91 || Positions.ChessBoard[yAsis - 2][xAsis - 1] == ' ')
								{
									AddAndMove(j, i, xAsis - 1, yAsis - 2);
								}
							}
						}
						if (xAsis + 2 < 8)
						{
							if (yAsis + 1 < 8)
							{
								if (Positions.ChessBoard[yAsis + 1][xAsis + 2] > 91 || Positions.ChessBoard[yAsis + 1][xAsis + 2] == ' ')
								{
									AddAndMove(j, i, xAsis + 2, yAsis + 1);
								}
							}
							if (yAsis - 1 >= 0)
							{
								if (Positions.ChessBoard[yAsis - 1][xAsis + 2] > 91 || Positions.ChessBoard[yAsis - 1][xAsis + 2] == ' ')
								{
									AddAndMove(j, i, xAsis + 2, yAsis - 1);
								}
							}
						}
						if (xAsis - 2 < 8)
						{
							if (yAsis + 1 < 8)
							{
								if (Positions.ChessBoard[yAsis + 1][xAsis - 2] > 91 || Positions.ChessBoard[yAsis + 1][xAsis - 2] == ' ')
								{
									AddAndMove(j, i, xAsis - 2, yAsis + 1);
								}
							}
							if (yAsis - 1 >= 0)
							{
								if (Positions.ChessBoard[yAsis - 1][xAsis - 2] > 91 || Positions.ChessBoard[yAsis - 1][xAsis - 2] == ' ')
								{
									AddAndMove(j, i, xAsis - 2, yAsis - 1);
								}
							}
						}
						break;
					case 'B':
						x = xAsis + 1;
						y = yAsis + 1;
						while (x < 8 && y < 8)
						{
							if (Positions.ChessBoard[y][x] > 91 || Positions.ChessBoard[y][x] == ' ')
							{
								AddAndMove(j, i, x, y);
							}
							else break;
							if (Positions.ChessBoard[y][x] != ' ') break;
							x++;
							y++;
						}
						x = xAsis - 1;
						y = yAsis - 1;
						while (x >= 0 && y >= 0)
						{
							if (Positions.ChessBoard[y][x] > 91 || Positions.ChessBoard[y][x] == ' ')
							{
								AddAndMove(j, i, x, y);
							}
							else break;
							if (Positions.ChessBoard[y][x] != ' ') break;
							x--;
							y--;
						}
						x = xAsis - 1;
						y = yAsis + 1;
						while (y < 8 && x >= 0)
						{
							if (Positions.ChessBoard[y][x] > 91 || Positions.ChessBoard[y][x] == ' ')
							{
								AddAndMove(j, i, x, y);
							}
							else break;
							if (Positions.ChessBoard[y][x] != ' ') break;
							x--;
							y++;
						}
						x = xAsis + 1;
						y = yAsis - 1;
						while (y >= 0 && x < 8)
						{
							if (Positions.ChessBoard[y][x] > 91 || Positions.ChessBoard[y][x] == ' ')
							{
								AddAndMove(j, i, x, y);
							}
							else break;
							if (Positions.ChessBoard[y][x] != ' ') break;
							x++;
							y--;
						}
						break;
					case 'Q':
						for (int x = xAsis + 1; x < 8; x++)
						{
							if (Positions.ChessBoard[i][x] > 91 || Positions.ChessBoard[i][x] == ' ')
							{
								AddAndMove(j, i, x, i);
							}
							else break;
							if (Positions.ChessBoard[i][x] != ' ') break;
						}
						for (int x = xAsis - 1; x >= 0; x--)
						{
							if (Positions.ChessBoard[i][x] > 91 || Positions.ChessBoard[i][x] == ' ')
							{
								AddAndMove(j, i, x, i);
							}
							else break;
							if (Positions.ChessBoard[i][x] != ' ') break;
						}
						for (int y = yAsis + 1; y < 8; y++)
						{
							if (Positions.ChessBoard[y][j] > 91 || Positions.ChessBoard[y][j] == ' ')
							{
								AddAndMove(j, i, j, y);
							}
							else break;
							if (Positions.ChessBoard[y][j] != ' ') break;
						}
						for (int y = yAsis - 1; y >= 0; y--)
						{
							if (Positions.ChessBoard[y][j] > 91 || Positions.ChessBoard[y][j] == ' ')
							{
								AddAndMove(j, i, j, y);
							}
							else break;
							if (Positions.ChessBoard[y][j] != ' ') break;
						}
						x = xAsis + 1;
						y = yAsis + 1;
						while (x < 8 && y < 8)
						{
							if (Positions.ChessBoard[y][x] > 91 || Positions.ChessBoard[y][x] == ' ')
							{
								AddAndMove(j, i, x, y);
							}
							else break;
							if (Positions.ChessBoard[y][x] != ' ') break;
							x++;
							y++;
						}
						x = xAsis - 1;
						y = yAsis - 1;
						while (x >= 0 && y >= 0)
						{
							if (Positions.ChessBoard[y][x] > 91 || Positions.ChessBoard[y][x] == ' ')
							{
								AddAndMove(j, i, x, y);
							}
							else break;
							if (Positions.ChessBoard[y][x] != ' ') break;
							x--;
							y--;
						}
						x = xAsis - 1;
						y = yAsis + 1;
						while (y < 8 && x >= 0)
						{
							if (Positions.ChessBoard[y][x] > 91 || Positions.ChessBoard[y][x] == ' ')
							{
								AddAndMove(j, i, x, y);
							}
							else break;
							if (Positions.ChessBoard[y][x] != ' ') break;
							x--;
							y++;
						}
						x = xAsis + 1;
						y = yAsis - 1;
						while (y >= 0 && x < 8)
						{
							if (Positions.ChessBoard[y][x] > 91 || Positions.ChessBoard[y][x] == ' ')
							{
								AddAndMove(j, i, x, y);
							}
							else break;
							if (Positions.ChessBoard[y][x] != ' ') break;
							x++;
							y--;
						}
						break;
					case 'K':
						if (i + 1 < 8)
						{
							if (j + 1 < 8)
							{
								if (Positions.ChessBoard[i + 1][j + 1] > 91 || Positions.ChessBoard[y][x] == ' ')
								{
									AddAndMove(j, i, j + 1, i + 1);
								}
								if (Positions.ChessBoard[i][j + 1] > 91 || Positions.ChessBoard[y][x] == ' ')
								{
									AddAndMove(j, i, j + 1, i);
								}
							}
							if (j - 1 >= 0)
							{
								if (Positions.ChessBoard[i + 1][j - 1] > 91 || Positions.ChessBoard[y][x] == ' ')
								{
									AddAndMove(j, i, j - 1, i + 1);
								}
							}
							if (Positions.ChessBoard[i + 1][j] > 91 || Positions.ChessBoard[y][x] == ' ')
							{
								AddAndMove(j, i, j, i + 1);
							}
						}
						break;
					case 'P':
						if (yAsis == 7)
						{
							if (Positions.ChessBoard[yAsis - 1][xAsis] == ' ' && Positions.ChessBoard[yAsis - 2][xAsis] == ' ')
							{
								AddAndMove(j, i, j, i - 2);
							}
						}
						if (yAsis - 1 >= 0)
						{
							if (Positions.ChessBoard[yAsis - 1][xAsis] == ' ')
							{
								AddAndMove(j, i, j, i - 1);
							}
							if (xAsis + 1 < 8)
							{
								if (Positions.ChessBoard[yAsis - 1][xAsis + 1] < 91 && Positions.ChessBoard[yAsis - 1][xAsis + 1] != ' ')
								{
									AddAndMove(j, i, j + 1, i - 1);
								}
							}
							if (xAsis - 1 >= 0)
							{
								if (Positions.ChessBoard[yAsis - 1][xAsis - 1] < 91 && Positions.ChessBoard[yAsis - 1][xAsis - 1] != ' ')
								{
									AddAndMove(j, i, j - 1, i - 1);
								}
							}
						}
						break;
					default:
						break;
					}
				}
			}
		}
		else
		{
			for (int i = 0; i < 8; i++)
			{
				yAsis = i;
				for (int j = 0; j < 8; j++)
				{
					xAsis = j;
					switch (Positions.ChessBoard[i][j]) // Movement for Black pieces.
					{
					case 'r':
						for (int x = xAsis + 1; x < 8; x++)
						{
							if (Positions.ChessBoard[i][x] < 91)
							{
								AddAndMove(j, i, x, i);
							}
							else break;
							if (Positions.ChessBoard[i][x] != ' ') break;
						}
						for (int x = xAsis - 1; x >= 0; x--)
						{
							if (Positions.ChessBoard[i][x] < 91)
							{
								AddAndMove(j, i, x, i);
							}
							else break;
							if (Positions.ChessBoard[i][x] != ' ') break;
						}
						for (int y = yAsis + 1; y < 8; y++)
						{
							if (Positions.ChessBoard[y][j] < 91)
							{
								AddAndMove(j, i, j, y);
							}
							else break;
							if (Positions.ChessBoard[y][j] != ' ') break;
						}
						for (int y = yAsis - 1; y >= 0; y--)
						{
							if (Positions.ChessBoard[y][j] < 91)
							{
								AddAndMove(j, i, j, y);
							}
							else break;
							if (Positions.ChessBoard[y][j] != ' ') break;
						}
						break;
					case 'n':
						if (yAsis + 2 < 8)
						{
							if (xAsis + 1 < 8)
							{
								if (Positions.ChessBoard[yAsis + 2][xAsis + 1] < 91)
								{
									AddAndMove(j, i, xAsis + 1, yAsis + 2);
								}
							}
							if (xAsis - 1 >= 0)
							{
								if (Positions.ChessBoard[yAsis + 2][xAsis - 1] < 91)
								{
									AddAndMove(j, i, xAsis - 1, yAsis + 2);
								}
							}
						}
						if (yAsis - 2 >= 0)
						{
							if (xAsis + 1 < 8)
							{
								if (Positions.ChessBoard[yAsis - 2][xAsis + 1] < 91)
								{
									AddAndMove(j, i, xAsis + 1, yAsis - 2);
								}
							}
							if (xAsis - 1 >= 0)
							{
								if (Positions.ChessBoard[yAsis - 2][xAsis - 1] < 91)
								{
									AddAndMove(j, i, xAsis - 1, yAsis - 2);
								}
							}
						}
						if (xAsis + 2 < 8)
						{
							if (yAsis + 1 < 8)
							{
								if (Positions.ChessBoard[yAsis + 1][xAsis + 2] < 91)
								{
									AddAndMove(j, i, xAsis + 2, yAsis + 1);
								}
							}
							if (yAsis - 1 >= 0)
							{
								if (Positions.ChessBoard[yAsis - 1][xAsis + 2] < 91)
								{
									AddAndMove(j, i, xAsis + 2, yAsis - 1);
								}
							}
						}
						if (xAsis - 2 >= 0)
						{
							if (yAsis + 1 < 8)
							{
								if (Positions.ChessBoard[yAsis + 1][xAsis - 2] < 91)
								{
									AddAndMove(j, i, xAsis - 2, yAsis + 1);
								}
							}
							if (yAsis - 1 >= 0)
							{
								if (Positions.ChessBoard[yAsis - 1][xAsis - 2] < 91)
								{
									AddAndMove(j, i, xAsis - 2, yAsis - 1);
								}
							}
						}
						break;
					case 'b':

						x = xAsis + 1;
						y = yAsis + 1;
						while (x < 8 && y < 8)
						{
							if (Positions.ChessBoard[y][x] < 91)
							{
								AddAndMove(j, i, x, y);
							}
							else break;
							if (Positions.ChessBoard[y][x] != ' ') break;
							x++;
							y++;
						}
						x = xAsis - 1;
						y = yAsis - 1;
						while (x >= 0 && y >= 0)
						{
							if (Positions.ChessBoard[y][x] < 91)
							{
								AddAndMove(j, i, x, y);
							}
							else break;
							if (Positions.ChessBoard[y][x] != ' ') break;
							x--;
							y--;
						}
						x = xAsis - 1;
						y = yAsis + 1;
						while (y < 8 && x >= 0)
						{
							if (Positions.ChessBoard[y][x] < 91)
							{
								AddAndMove(j, i, x, y);
							}
							else break;
							if (Positions.ChessBoard[y][x] != ' ') break;
							x--;
							y++;
						}
						x = xAsis + 1;
						y = yAsis - 1;
						while (y >= 0 && x < 8)
						{
							if (Positions.ChessBoard[y][x] < 91)
							{
								AddAndMove(j, i, x, y);
							}
							else break;
							if (Positions.ChessBoard[y][x] != ' ') break;
							x++;
							y--;
						}
						break;
					case 'q':
						for (int x = xAsis + 1; x < 8; x++)
						{
							if (Positions.ChessBoard[i][x] < 91)
							{
								AddAndMove(j, i, x, i);
							}
							else break;
							if (Positions.ChessBoard[i][x] != ' ') break;
						}
						for (int x = xAsis - 1; x >= 0; x--)
						{
							if (Positions.ChessBoard[i][x] < 91)
							{
								AddAndMove(j, i, x, i);
							}
							else break;
							if (Positions.ChessBoard[i][x] != ' ') break;
						}
						for (int y = yAsis + 1; y < 8; y++)
						{
							if (Positions.ChessBoard[y][j] < 91)
							{
								AddAndMove(j, i, j, y);
							}
							else break;
							if (Positions.ChessBoard[y][j] != ' ') break;
						}
						for (int y = yAsis - 1; y >= 0; y--)
						{
							if (Positions.ChessBoard[y][j] < 91)
							{
								AddAndMove(j, i, j, y);
							}
							else break;
							if (Positions.ChessBoard[y][j] != ' ') break;
						}
						//int x, y;
						x = xAsis + 1;
						y = yAsis + 1;
						while (x < 8 && y < 8)
						{
							if (Positions.ChessBoard[y][x] < 91)
							{
								AddAndMove(j, i, x, y);
							}
							else break;
							if (Positions.ChessBoard[y][x] != ' ') break;
							x++;
							y++;
						}
						x = xAsis - 1;
						y = yAsis - 1;
						while (x >= 0 && y >= 0)
						{
							if (Positions.ChessBoard[y][x] < 91)
							{
								AddAndMove(j, i, x, y);
							}
							else break;
							if (Positions.ChessBoard[y][x] != ' ') break;
							x--;
							y--;
						}
						x = xAsis - 1;
						y = yAsis + 1;
						while (y < 8 && x >= 0)
						{
							if (Positions.ChessBoard[y][x] < 91)
							{
								AddAndMove(j, i, x, y);
							}
							else break;
							if (Positions.ChessBoard[y][x] != ' ') break;
							x--;
							y++;
						}
						x = xAsis + 1;
						y = yAsis - 1;
						while (y >= 0 && x < 8)
						{
							if (Positions.ChessBoard[y][x] < 91)
							{
								AddAndMove(j, i, x, y);
							}
							else break;
							if (Positions.ChessBoard[y][x] != ' ') break;
							x++;
							y--;
						}
						break;
					case 'k':
						if (i + 1 < 8)
						{
							if (j + 1 < 8)
							{
								if (Positions.ChessBoard[i + 1][j + 1] < 91)
								{
									AddAndMove(j, i, j + 1, i + 1);
								}
								if (Positions.ChessBoard[i][j + 1] < 91)
								{
									AddAndMove(j, i, j + 1, i);
								}
							}
							if (j - 1 >= 0)
							{
								if (Positions.ChessBoard[i + 1][j - 1] < 91)
								{
									AddAndMove(j, i, j - 1, i + 1);
								}
							}
							if (Positions.ChessBoard[i + 1][j] < 91)
							{
								AddAndMove(j, i, j, i + 1);
							}
						}
						if (i - 1 >= 0)
						{
							if (j - 1 >= 0)
							{
								if (Positions.ChessBoard[i - 1][j - 1] < 91)
								{
									AddAndMove(j, i, j - 1, i - 1);
								}
								if (Positions.ChessBoard[i][j - 1] < 91)
								{
									AddAndMove(j, i, j - 1, i);
								}
							}
							if (j + 1 < 8)
							{
								if (Positions.ChessBoard[i - 1][j + 1] < 91)
								{
									AddAndMove(j, i, j + 1, i - 1);
								}
							}
							if (Positions.ChessBoard[i - 1][j] < 91)
							{
								AddAndMove(j, i, j, i - 1);
							}
						}
						break;
					case 'p':
						if (yAsis == 1)
						{
							if (Positions.ChessBoard[yAsis + 1][xAsis] == ' ' && Positions.ChessBoard[yAsis + 2][xAsis] == ' ')
							{
								AddAndMove(j, i, j, i + 2);
							}
						}
						if (yAsis + 1 < 8)
						{
							if (Positions.ChessBoard[yAsis + 1][xAsis] == ' ')
							{
								AddAndMove(j, i, j, i + 1);
							}
							if (xAsis + 1 < 8)
							{
								if (Positions.ChessBoard[yAsis + 1][xAsis + 1] < 91 && Positions.ChessBoard[yAsis + 1][xAsis + 1] != ' ')
								{
									AddAndMove(j, i, j + 1, i + 1);
								}
							}
							if (xAsis - 1 >= 0)
							{
								if (Positions.ChessBoard[yAsis + 1][xAsis - 1] < 91 && Positions.ChessBoard[yAsis + 1][xAsis - 1] != ' ')
								{
									AddAndMove(j, i, j - 1, i + 1);
								}
							}
						}
						break;
					default:
						break;
					}
				}
			}
		}
	}
	void AddAndMove(int x, int y, int x1, int y1)
	{
		ChessPosition tempPos = CurrentPos;
		tempPos.ChessBoard[y1][x1] = tempPos.ChessBoard[y][x];
		tempPos.ChessBoard[y][x] = ' ';
		tempPos.NextPositions.clear();
		string a = { char(x + 97), char(8 - y + 48), char(x1 + 97), char(8 - y1 + 48) };
		tempPos.LastMove = a;
		CurrentPos.NextPositions.emplace_back(tempPos);

	}
	string GetMove()  //////////////////////////////////////
	{
		string tempMove;
		if (CurrentPos.NextPositions.size() > 0)
		{
			srand(time(NULL));
			auto r = rand() % CurrentPos.NextPositions.size();
			tempMove = CurrentPos.NextPositions[r].LastMove;
			CurrentPos = CurrentPos.NextPositions[r];
			CurrentPos.LastMove = tempMove;
			CurrentPos.NextPositions.clear();
		}
		return CurrentPos.LastMove;
	}
	void MoveWhite(string Move)
	{
		CurrentPos.ChessBoard[7 - (Move[3] - 49)][Move[2] - 97] = CurrentPos.ChessBoard[7 - (Move[1] - 49)][Move[0] - 97];
		CurrentPos.ChessBoard[7 - (Move[1] - 49)][Move[0] - 97] = ' ';
		CurrentPos.Turn = 0;
	}
	void MoveBlack()
	{

	}
	~PositionGenerator()
	{

	}

private:
	ChessPosition CurrentPos;
};