#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

bool solution(vector<string> phone_book) {
	bool answer = true;

	sort(phone_book.begin(), phone_book.end());

	for (auto iter = phone_book.begin() + 1; iter != phone_book.end(); ++iter)
	{
		auto pre = iter - 1;
		const size_t preLength = pre->size();

		if (0 == strncmp(pre->c_str(), iter->c_str(), preLength))
		{
			answer = false;
			break;
		}

	}

	return answer;
}