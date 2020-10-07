#include <cmath>

using namespace std;

long long gcd(long long a, long long b)
{
	while (b != 0)
	{
		int r = a % b;
		a = b;
		b = r;
	}

	return a;
}

long long solution(int w, int h) {
	long long answer = 1;

	long long count = (long long)w * h;

	answer = count - (w + h - gcd(w, h));

	return answer;
}