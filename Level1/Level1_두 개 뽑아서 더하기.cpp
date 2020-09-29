#include <string>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

namespace Level1_두_개_뽑아서_더하기
{

vector<int> solution(vector<int> numbers) {
	vector<int> answer;
	
	set<int> resultList;
	const int size = numbers.size();
	for (int i = 0; i < size; ++i)
	{
		for (int j = i + 1; j < size; ++j)
		{
			const int result = numbers[i] + numbers[j];
			resultList.emplace(result);
		}
	}
	
	answer.assign(resultList.begin(), resultList.end());

	return answer;
}

}