#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int BestBridgeCrossing(vector<int>& persons)
{
	auto size = persons.size();
	if (size <= 2)	// 1 or 2 persons, cross the bridge together once
		return persons[size - 1];

	//3 persons: the fastest two cross (persons[1]), the fastest one back (persons[0]), then last two cross (persons[2])
	else if (size == 3)
		return persons[0] + persons[1] + persons[2];

	// move the last two persons accross the bridge
	auto last = persons.back();
	persons.pop_back();		//remove last, O(1)
	auto secondToLast = persons.back();
	persons.pop_back();		//remove 2nd to last, O(1)

	//way 1: the fastest person takes them one by one
	auto fastest1by1 = persons[0] + last + persons[0] + secondToLast;

	//way 2: the fastest two cross first, and back for the last two cross together
	auto fastest2 = persons[1] + persons[0] + last + persons[1];

	auto fastest = (fastest1by1 > fastest2) ? fastest2 : fastest1by1;

	return fastest + BestBridgeCrossing(persons);
}

int main()
{
	vector<int> persons = { 1,2,10,7 };
	sort(persons.begin(), persons.end());

    std::cout << "Minimum time used to cross the bridge: " << BestBridgeCrossing(persons) << endl;
}
