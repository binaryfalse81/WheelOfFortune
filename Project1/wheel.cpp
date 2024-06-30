#include <iostream>
#include <string>
#include <vector>
using namespace std;

const int MAX_QUEUE_DEPTH = 26;
const int MAX_LIST_CNT = 5;
const int MAX_LENGTH = 50;
const int UNKNOWN = 0;
const int CLEAR = 1;
const int FIRST_PRIZE = 1000;
const int SECOND_PRIZE = 2000;
const int BASIC_PRIZE = 100;

class Wheel
{
public:
    Wheel()
    {
        for (int nList = 0; nList < MAX_LIST_CNT; nList++)
        {
            abFirstChance[nList] = true;
        }
    }

    int Solve(vector<string> strs, string CharQueue)
    {
        int nTotalPrize = 0;
        int nComboCnt = 0;

        for (int nIdx = 0; nIdx < MAX_QUEUE_DEPTH; nIdx++)
        {
            char c = CharQueue[nIdx];

            int nPassCnt = GetPassCnt(strs, c);
            if (nPassCnt == 0)
            {
                nComboCnt = 0;
                for (int nList = 0; nList < MAX_LIST_CNT; nList++)
                {
                    abSecondChance[nList] = false;
                }

                continue;
            }

            nTotalPrize += Get2000Won(strs, c);

            nTotalPrize += Get1000Won(strs, c);

            nComboCnt++;
            nTotalPrize += Get100Won(nComboCnt, nPassCnt);
        }

        return nTotalPrize;
    }

    int Get100Won(int nComboCnt, int nPassCnt)
    {
        int nWon = 0;

        nWon += (nComboCnt * BASIC_PRIZE) * nPassCnt;

        return nWon;
    }

    int Get2000Won(vector<string>& strs, char ch)
    {
        int nWon = 0;

        for (int nRow = 0; nRow < strs.size(); nRow++)
        {
            if (abSecondChance[nRow])
            {
                abSecondChance[nRow] = false;

                for (int nCol = 0; nCol < strs[nRow].size(); nCol++)
                {
                    if (map[nRow][nCol] == UNKNOWN && strs[nRow][nCol] == ch)
                    {
                        nWon += SECOND_PRIZE;
                        break;
                    }
                }
            }
        }

        return nWon;
    }

    int Get1000Won(vector<string>& strs, char ch)
    {
        int nWon = 0;

        for (int nRow = 0; nRow < strs.size(); nRow++)
        {
            for (int nCol = 0; nCol < strs[nRow].size(); nCol++)
            {
                if (map[nRow][nCol] == CLEAR) continue;

                if (strs[nRow][nCol] == ch)
                {
                    if (abFirstChance[nRow] == true)
                    {
                        abFirstChance[nRow] = false;

                        if (nCol == 0)
                        {
                            nWon += FIRST_PRIZE;
                            abSecondChance[nRow] = true;
                        }
                    }

                    map[nRow][nCol] = CLEAR;
                    strs[nRow][nCol] = '_';
                }
            }
        }

        return nWon;
    }

    int GetPassCnt(vector<string>& strs, char ch)
    {
        int nPassCnt = 0;

        for (int nRow = 0; nRow < strs.size(); nRow++)
        {
            for (int nCol = 0; nCol < strs[nRow].size(); nCol++)
            {
                if (map[nRow][nCol] == CLEAR) continue;

                if (strs[nRow][nCol] == ch)
                {
                    nPassCnt++;
                }
            }
        }

        return nPassCnt;
    }

private:
    bool abFirstChance[MAX_LIST_CNT];
    bool abSecondChance[MAX_LIST_CNT] = { false, };
    int map[MAX_LIST_CNT][MAX_LENGTH] = { UNKNOWN, };
};