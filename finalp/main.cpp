/*
 * main.cpp
 *
 *  Created on: Dec 15, 2023
 *      Author: ohkaw
 */

// Includes
#include <iostream>
#include <vector>
#include <fstream>
#include <iomanip>

// List ADT/Queue ADT
#include "ArrayQueue.hpp"
#include "Queue.hpp"

#include "LinkedList.hpp"

// Dictionary ADT
#include "hashing.hpp"
#include "StringHashTableOpen.hpp"

#include "ArrayListDictionary.hpp"


using namespace std;

/**
 * TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO
 *
 * What is the big-O analysis for this function? Briefly justify your answer.
 *
 * Answer: T(1), no matter how large T arr[] is, the function will always swap once, constant.
 * Therefore, the time complexity is constant.
 *
 * TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO
 */
template<typename T>
void swap(T arr[], int i, int j) {
    T temp;
    temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}


/**
 * TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO
 *
 * What is the big-O analysis for this function? Briefly justify your answer.
 *
 * Answer: T(n), main() is linear time. If we set the number of times the user has gone through the menu
 * as n, the main function will run the same amount of times as the times the user has looped through the menu.
 * Therefore, this function's time complexity is linear.
 *
 * TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO
 */
int main() {
	vector<ArrayQueue<string>> userVector;
	string inputRecord;
	string userFile = "data.txt";
	ifstream inputFile;
	string temp;

	inputFile.open(userFile);

	while (inputFile.fail()) {
		cout << "Error opening input file" << endl;
		break;
	} //while

	//file reading
	while (!inputFile.eof()) {
		ArrayQueue<string> tempQ(8);
		getline(inputFile, inputRecord);
		stringstream strstream(inputRecord);
		getline(strstream, temp, ',');
		tempQ.enqueue(temp);
		getline(strstream, temp, ',');
		tempQ.enqueue(temp);
		getline(strstream, temp, ',');
		tempQ.enqueue(temp);
		getline(strstream, temp, ',');
		tempQ.enqueue(temp);
		getline(strstream, temp, ',');
		tempQ.enqueue(temp);
		getline(strstream, temp, ',');
		tempQ.enqueue(temp);
		getline(strstream, temp, ',');
		tempQ.enqueue(temp);
		getline(strstream, temp, ',');
		tempQ.enqueue(temp);
		userVector.push_back(tempQ);
	}

	inputFile.close();


	int choice;
	cout << "Welcome to my program, WALK!" << endl;
	do {
		cout << "1. Print all schedules" << endl;
		cout << "2. Search a user's schedule" << endl;
		cout << "3. Sort schedules" << endl;
		cout << "4. Match schedules" << endl;
		cout << "5. Exit program" << endl;
		cout << "Enter your selection: ";
		cin >> choice;
		cin.clear();

		switch (choice) {
		case 1:
		{
			//print function

			ArrayQueue<string> temp(8);
			cout << endl;
			cout << "Printing all users' availabilities..." << endl;
			cout << right << setw(15) << "NAME";
			cout << right << setw(10) << "MON" << setw(10) << "TUES" << setw(10) << "WED" << setw(10) << "THURS" << setw(10) << "FRI" << setw(10) << "SAT" << setw(10) << "SUN" << endl;
			cout << "--------------------------------------------------------------------------------------------" << endl;
			for (unsigned int i=0; i<userVector.size(); i++) {
				temp = userVector[i];
				cout << right << setw(15) << temp.front() << ":";
				temp.dequeue();
				for (int j=0; j<userVector[0].getLength()-1; j++) {
					cout << right << setw(10) << temp.front();
					temp.dequeue();
				}
				cout << endl;
			}
			cout << endl;
			break;
		}

		case 2:
		{
			//search function

			ArrayListDictionary<string, ArrayQueue<string>> dict(SearchImpl::SEQ_REC, 10);

			string userWord;

			cout << endl;
			cout << "Searching a user's availability..." << endl;


			for (unsigned int i=0; i<userVector.size(); i++) {
				string dictKey;
				dictKey = userVector[i].front();		// inserting names of the users into temp string
				dict.insert(dictKey, userVector[i]);	// inserting key = string, value = arrayqueue
			}

			while (true) {
				try {
					cout << "Enter a key to search my dictionary (or -1 to stop): ";
					cin >> userWord;
					if (userWord == "-1") {
						break;
					}
					cout << right << setw(15) << "NAME";
					cout << right << setw(10) << "MON" << setw(10) << "TUES" << setw(10) << "WED" << setw(10) << "THURS" << setw(10) << "FRI" << setw(10) << "SAT" << setw(10) << "SUN" << endl;
					cout << "--------------------------------------------------------------------------------------------" << endl;
					ArrayQueue<string> temp(10);
					temp = dict.find(userWord);
					cout << right << setw(15) << temp.front() << ":";
					temp.dequeue();
					for (int j=0; j<userVector[0].getLength()-1; j++) {
						cout << right << setw(10) << temp.front();
						temp.dequeue();
					}
					cout << endl;
					cout << endl;
				} catch (const string &e) {
					cout << e << endl;
				}
			}

			cout << endl;
			break;

		}
		case 3:
		{
			//sort function

			ArrayQueue<string> arr[userVector.size()];

			cout << endl;
			cout << "Sorting users' availabilities in alphabetical order..." << endl;
			for (unsigned int i=0; i<userVector.size(); i++) {
				arr[i] = userVector[i];

			}

			for (unsigned int i=0; i<userVector.size(); i++) {
				for (unsigned int j=0; j<userVector.size()-i-1; j++) {
					if (((arr[j].front()) < (arr[j+1].front())) == false) {
						swap(arr, j, j+1);
					}
				}
			}

			ArrayQueue<string> temp(8);
			cout << right << setw(15) << "NAME";
			cout << right << setw(10) << "MON" << setw(10) << "TUES" << setw(10) << "WED" << setw(10) << "THURS" << setw(10) << "FRI" << setw(10) << "SAT" << setw(10) << "SUN" << endl;
			cout << "--------------------------------------------------------------------------------------------" << endl;
			for (unsigned int i=0; i<userVector.size(); i++) {
				temp = arr[i];
				cout << right << setw(15) << temp.front() << ":";
				temp.dequeue();
				for (int j=0; j<userVector[0].getLength()-1; j++) {
					cout << right << setw(10) << temp.front();
					temp.dequeue();
				}
				cout << endl;
			}
			cout << endl;
			break;
		}
		case 4:
		{
			//match function

			cout << endl;




			//-------------------------------------------------------
			//User loop tracker, use of circular linked list
			//-------------------------------------------------------

			LinkedList<string> user;
			for (int i=userVector.size()-1; i>=0; i--) {
				user.append(userVector[i].front());
			}
			//when appending, append backwards and then before incrementing through the list, goNext() once
			user.goNext();
			for (unsigned int i=0; i<userVector.size(); i++) {
				user.goNext();
			}


			//variables to use to compare with the loop tracker
			//------------------------------------------------------

			vector<ArrayQueue<string>> a(10);
			vector<string> s(10);
			for (unsigned int i=0; i<userVector.size(); i++) {
				a[i] = userVector[i];
			}

			for (unsigned int i=0; i<userVector.size(); i++) {
				s[i] = a[i].front(); // bob kevin stuart, bobs stuff, kevins stuff, stuarts stuff
			}

			// can compare data using a as the userVector

			//------------------------------------------------------

	//DAY COMPARISON===============================================

			// Comparison Queue input data
			ArrayQueue<string> q;
			while (!a[0].isEmpty()) {	// just the days now
				for (unsigned int k=0; k<userVector.size(); k++) {
					a[k].dequeue();
				}
				for (unsigned int j=0; j<userVector.size(); j++) {

					if (a[j].front() == " Morning") {
						q.enqueue("M");
					}
					else if (a[j].front() == " Evening") {
						q.enqueue("E");
					}
					else if (a[j].front() == " Both") {
						q.enqueue("B");
					}
					else if (a[j].front() == " None") {
						q.enqueue("N");
					}
				}
			}

			ArrayQueue<string> g = q;

			//walk counter for each day
			vector<unsigned int> b(7);
			unsigned int p;
			for (int i=0; i<7; i++) {	// for each day
				p=0;
				for (unsigned j=0; j<userVector.size(); j++) {	// for each user
					if (q.front() == "B") {
						p = p+2;
					}
					if (q.front() == "M") {
						p = p+1;
					}
					if (q.front() == "E") {
						p = p+1;
					}
					else if (q.front() == "N"){
						p = p+0;
					}
					q.dequeue();
				}
				b[i] = p;
			}

			// PRINTING-------------------------------------------------
			cout << "Creating schedule based on all users' availabilities..." << endl;
			for (int i=0; i<7; i++) {
				string day;
				if (i==0) {
					day = "MONDAY: ";
				}
				else if (i==1) {
					day = "TUESDAY: ";
				}
				else if (i==2) {
					day = "WEDNESDAY: ";
				}
				else if (i==3) {
					day = "THURSDAY: ";
				}
				else if (i==4) {
					day = "FRIDAY: ";
				}
				else if (i==5) {
					day = "SATURDAY: ";
				}
				else {
					day = "SUNDAY: ";
				}

				if (b[i] == (userVector.size()*2)) {
					// All available all times, everyone is B
					cout << right << setw(15) << day << "All available at all times" << endl;
					for (unsigned int j=0; j<userVector.size(); j++) {
						g.dequeue();
					}
				}

				else if((b[i] > (userVector.size())) && (b[i] < (userVector.size()*2))) {
					// walk counter is less than the max and more than half

					ArrayQueue<string> tempQ;
					unsigned int mCounter = 0;
					unsigned int eCounter = 0;
					unsigned int bCounter = 0;
					unsigned int nCounter = 0;

					for (unsigned int j=0; j<userVector.size(); j++) {
						if (g.front() == "M") {
							mCounter++;
							tempQ.enqueue("M");
						}
						else if (g.front() == "E") {
							eCounter++;
							tempQ.enqueue("E");
						}
						else if (g.front() == "B") {
							tempQ.enqueue("B");
							bCounter++;
						}
						else if (g.front() == "N") {
							tempQ.enqueue("N");
							nCounter++;
						}
						g.dequeue();
					}

					cout << right << setw(15) << day;


					Dictionary<string, string> *dictionary = new StringHashTableOpen<string>(10, 2);
					for (unsigned int k=0; k<userVector.size(); k++) {
						dictionary->insert(s[k], tempQ.front());
						tempQ.dequeue();
					}
					for (int h=0; h<2; h++) {
						if (dictionary->find(user.getCurrent()) == "N") {
							user.goNext();
						}
						else if (dictionary->find(user.getCurrent()) == "B") {
							cout << right << setw(25) <<  user.getCurrent() << " can go both";
							user.goNext();
						}
						else if (dictionary->find(user.getCurrent()) == "M") {
							cout << right << setw(25) << user.getCurrent() << " can go morning";
							user.goNext();
						}
						else if (dictionary->find(user.getCurrent()) == "E") {
							cout << right << setw(25) << user.getCurrent() << " can go evening";
							user.goNext();
						}
					}
					cout << endl;
				}

				else if (b[i] == (userVector.size())) {
					// walk counter is half the max

					ArrayQueue<string> tempQ;
					unsigned int mCounter = 0;
					unsigned int eCounter = 0;
					unsigned int bCounter = 0;
					unsigned int nCounter = 0;

					for (unsigned int j=0; j<userVector.size(); j++) {
						if (g.front() == "M") {
							mCounter++;
							tempQ.enqueue("M");
						}
						else if (g.front() == "E") {
							eCounter++;
							tempQ.enqueue("E");
						}
						else if (g.front() == "B") {
							tempQ.enqueue("B");
							bCounter++;
						}
						else if (g.front() == "N") {
							tempQ.enqueue("N");
							nCounter++;
						}
						g.dequeue();
					}

					// all m or all e
					if (mCounter == userVector.size()) {
						cout << right << setw(15) << day << "All available in the morning, none available in the evening" << endl;
					}
					else if (eCounter == userVector.size()){
						cout << right << setw(15) << day << "All available in the evening, none available in the morning" << endl;
					}
					// matching function
					else {
						cout << right << setw(15) << day;

						Dictionary<string, string> *dictionary = new StringHashTableOpen<string>(10, 2);
						for (unsigned int k=0; k<userVector.size(); k++) {
							dictionary->insert(s[k], tempQ.front());
							tempQ.dequeue();
						}
						for (int h=0; h<2; h++) {
							if (dictionary->find(user.getCurrent()) == "N") {
								user.goNext();
							}
							else if (dictionary->find(user.getCurrent()) == "B") {
								cout << right << setw(25) << user.getCurrent() << " can go both";
								user.goNext();
							}
							else if (dictionary->find(user.getCurrent()) == "M") {
								cout << right << setw(25) << user.getCurrent() << " can go morning";
								user.goNext();
							}
							else if (dictionary->find(user.getCurrent()) == "E") {
								cout << right << setw(25) << user.getCurrent() << " can go evening";
								user.goNext();
							}
						}
						cout << endl;

					}

					tempQ.clear();

				}

				else if((b[i] < (userVector.size())) && (b[i] > 0)) {
					// walk counter is less than half the max and more than 0

					ArrayQueue<string> tempQ;
					unsigned int mCounter = 0;
					unsigned int eCounter = 0;
					unsigned int bCounter = 0;
					unsigned int nCounter = 0;

					for (unsigned int j=0; j<userVector.size(); j++) {
						if (g.front() == "M") {
							mCounter++;
							tempQ.enqueue("M");
						}
						else if (g.front() == "E") {
							eCounter++;
							tempQ.enqueue("E");
						}
						else if (g.front() == "B") {
							tempQ.enqueue("B");
							bCounter++;
						}
						else if (g.front() == "N") {
							tempQ.enqueue("N");
							nCounter++;
						}
						g.dequeue();
					}

					cout << right << setw(15) << day;


						Dictionary<string, string> *dictionary = new StringHashTableOpen<string>(10, 2);
						for (unsigned int k=0; k<userVector.size(); k++) {
							dictionary->insert(s[k], tempQ.front());
							tempQ.dequeue();
						}
						for (unsigned int h=0; h<userVector.size(); h++) {
							if (dictionary->find(user.getCurrent()) == "N") {
								user.goNext();
							}
							else if (dictionary->find(user.getCurrent()) == "B") {
								cout << right << setw(25) << user.getCurrent() << " can go both";
								user.goNext();
							}
							else if (dictionary->find(user.getCurrent()) == "M") {
								cout << right << setw(25) << user.getCurrent() << " can go morning";
								user.goNext();
							}
							else if (dictionary->find(user.getCurrent()) == "E") {
								cout << right << setw(25) << user.getCurrent() << " can go evening";
								user.goNext();
							}
						}
						cout << endl;


					}
				else if(b[i] == 0) {
					// walk counter is 0, noone available
					cout << right << setw(10) <<day << "None available at all times" << endl;
				}
			}

			cout << endl;
			break;
		}

		case 5:
		{
			//end program

			cout << "Ending program..." << endl;
			break;
		}

	}


	} while (choice > 0 && choice < 5);
	return 0;
}

