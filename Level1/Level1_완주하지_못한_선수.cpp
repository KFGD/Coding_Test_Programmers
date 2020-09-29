#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

namespace Level1_완주하지_못한_선수
{

string solution(vector<string> participant, vector<string> completion) {
	string answer = "";

	unordered_map<string, int> participantMap;
	for (auto person : participant)
	{
		auto iter = participantMap.find(person);
		if (participantMap.end() == iter)
			participantMap.emplace(person, 1);
		else
			iter->second += 1;
	}

	for (auto person : completion)
	{
		auto iter = participantMap.find(person);
		iter->second -= 1;
		if (0 == iter->second)
			participantMap.erase(iter);
	}

	return participantMap.begin()->first;
}

}