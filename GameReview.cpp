#include "GameReview.h"

GameReview::GameReview()
{
}

GameReview::GameReview(string index, string userName, string rating, string comment, string internalId, string gameName)
{
	this->SetInfo(index, userName, rating, comment, internalId, gameName);
}

GameReview::~GameReview()
{
}

int GameReview::GetIndex()
{
	int number;
	istringstream iss(Index);
	iss >> number;
	return number;
}

string GameReview::GetUserName()
{
	return UserName;
}

string GameReview::GetRating()
{
	return Rating;
}

string GameReview::GetComment()
{
	return Comment;
}

int GameReview::GetInternalId()
{
	int number;
	istringstream iss(InternalId);
	iss >> number;
	return number;
}

string GameReview::GetGameName()
{
	return GameName;
}

void GameReview::SetInfo(string index, string userName, string rating, string comment, string internalId, string gameName)
{
	this->Index = index;
	this->UserName = userName;
	this->Rating = rating;
	this->Comment = comment;
	this->InternalId = internalId;
	this->GameName = gameName;
}

void GameReview::PrintInfo()
{
	cout << "------------ Review Info ------------" << endl;
	cout << "Index: " << Index << endl;
	cout << "User Name: " << UserName << endl;
	cout << "Rating: " << Rating << endl;
	cout << "Comment: " << Comment << endl;
	cout << "Game Name: " << GameName << endl;
	cout << endl;
}

void GameReview::PrintMainInfo()
{
	cout << InternalId << ", " << GameName << ", " << Rating << endl;
}

void GameReview::PrintInternalId()
{
	cout << "Internal Id:" << InternalId << endl;
}

