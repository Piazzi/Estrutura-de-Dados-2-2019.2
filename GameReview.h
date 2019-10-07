#if !defined(__GAMEREVIEW_H__)
#define __GAMEREVIEW_H__
#include <iostream>
#include <sstream>
#include <string> 
//#include <cstdlib> 
using namespace std;

class GameReview
{
public:
	GameReview();
	GameReview(string index, string userName, string rating, string comment, string internalId, string gameName);

	~GameReview();

	int GetIndex();
	string GetUserName();
	string GetRating();
	string GetComment();
	int GetInternalId();
	string GetGameName();

	void SetInfo(string index, string userName, string rating, string comment, string internalId, string gameName);
	void PrintInfo();
	void PrintMainInfo();
	void PrintInternalId();

private:
	string Index;
	string UserName;
	string Rating;
	string Comment;
	string InternalId;
	string GameName;
};
#endif
