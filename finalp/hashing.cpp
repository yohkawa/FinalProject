#include "hashing.hpp"
#include <string>
using namespace std;

/**
 * TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO
 *
 * What is the big-O analysis for this function? Briefly justify your answer.
 *
 * Answer: T(n), linear time. There is a for loop that is dependent on the size of the string.
 * the for loop will loop itself n times = s.length().
 *
 * TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO
 */
int base256conversion(const string &s) {
    // TODO
	int sum=0;
	int tot = 0;
	int exp = s.length()-1;
	for (unsigned int i=0; i<s.length(); i++) {
		sum = (int(s[i]) * (pow(256, exp)));
		tot += sum;
		exp--;
	}
	return tot;
}

/**
 * TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO
 *
 * What is the big-O analysis for this function? Briefly justify your answer.
 *
 * Answer: T(n), this function is similar to the previous function. The for loop in the
 * function is dependent on the length of the string. Therefore, this function's time
 * complexity is linear.
 *
 * TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO
 */
int hashString(const string &s, int foldNum) {
    // TODO
	int sum=0;
	int tot = 0;
	for (unsigned int i=0; i<s.length(); i=i+foldNum) {
		string x = s.substr(i, foldNum);
		sum = base256conversion(x);
		tot += sum;
	}

	return tot;
}
