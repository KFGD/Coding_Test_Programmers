#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int solution(string s) {
	int answer = 0;

	int minimumLength = 2147483647;
	for (int i = 1; i <= s.size(); ++i)
	{
		int length = 0;

		string curSelSubStr;
		curSelSubStr.resize(i, '\0');

		int index = 0;
		int duplicated = 0;

		while ((index + i) <= s.length())
		{
			const string substr = s.substr(index, i);

			if (substr == curSelSubStr)
				++duplicated;
			else
			{
				if (0 != duplicated)
					length += to_string(duplicated + 1).length();
				duplicated = 0;

				curSelSubStr = substr;
				length += i;
			}

			index += i;
		}

		if (0 != duplicated)
			length += to_string(duplicated + 1).length();

		length += (s.length() - index);

		if (minimumLength > length)
			minimumLength = length;
	}

	answer = minimumLength;

	return answer;
}