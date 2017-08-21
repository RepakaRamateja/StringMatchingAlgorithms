#pragma once
#include <queue>

using namespace std;

std::vector<int> out;

std::vector<int> f;

std::vector<std::vector<int>> g;


int buildMatchingMachine(string arr[], int k)
{
	memset(out, 0, sizeof out);
	memset(g, -1, sizeof g);
	int states = 1;
	for (int i = 0; i < k; ++i)
	{
		const string &word = arr[i];
		int currentState = 0;

		// Insert all characters of current word in arr[]
		for (int j = 0; j < word.size(); ++j)
		{
			int ch = word[j] - 'a';
			if (g[currentState][ch] == -1)
				g[currentState][ch] = states++;
			currentState = g[currentState][ch];
		}
		// Add current word in output function
		out[currentState] |= (1 << i);
	}

	for (int ch = 0; ch < MAXC; ++ch)
		if (g[0][ch] == -1)
			g[0][ch] = 0;
	memset(f, -1, sizeof f);
	queue<int> q;
	for (int ch = 0; ch < MAXC; ++ch)
	{
		if (g[0][ch] != 0)
		{
			f[g[0][ch]] = 0;
			q.push(g[0][ch]);
		}
	}
	while (q.size())
	{
		int state = q.front();
		q.pop();
		for (int ch = 0; ch <= MAXC; ++ch)
		{
			if (g[state][ch] != -1)
			{
				int failure = f[state];
				while (g[failure][ch] == -1)
					failure = f[failure];
				failure = g[failure][ch];
				f[g[state][ch]] = failure;
				out[g[state][ch]] |= out[failure];
				q.push(g[state][ch]);
			}
		}
	}
	return states;
}