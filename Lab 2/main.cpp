#include <iostream>
#include <cmath>
#include <vector>
#include <string>

using namespace std;

int rootCeiling(int n)
{
	int split;
	split = n / 2;
	int left = 0;
	int right = n;
	int ret = 0;
	while (left <= right)
	{

		if ((split * split) == n)
		{
			return split;
		}

		if ((split * split) < n)
		{
			left = split;
			split = ceil(double(left + right) / double(2));
			ret = split;
		}
		else if ((split * split) > n)
		{
			right = split;
			split = floor(double(left + right) / double(2));
			ret = split;
		}
		if (right - left == 1)
		{
			return right;
		}

	}
	return ret;
}

int binarySearch(vector<int> arr)
{

	int split = 0;
	split = arr.size() / 2;
	int left;
	int right;
	if (arr[0] == 1)
		return 0;
	for (int i = 0; i < 100; i++)
	{

		left = split - 1;
		right = split + 1;
		if (arr[split] == 0)
		{
			split = (split + arr.size()) / 2;
		}
		else if (arr[split] == 1)
		{
			if (arr[left] == 0)
				return split;
			else
				split = (arr.size() - split) / 2;
		}
	}
	return -1;
}

int main()
{
	int n;
	vector<int> arr;
	string biNum;

	cout << "Please enter an integer: ";
	cin >> n;
	cout << endl;
	cout << "The ceiling of square root n is: " << rootCeiling(n) << endl;

	cout << "Please enter binary number string: ";
	cin >> biNum;
	for (int i = 0; i < biNum.length(); i++)
	{
		arr.push_back((biNum[i] - '0'));
	}
	cout << endl;

	cout << "The first 1 is at: " << binarySearch(arr);

	return 0;
}