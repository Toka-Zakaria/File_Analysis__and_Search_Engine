/****************************
 * [FILE NAME]: inord_list.h
 *
 * [AUTHOR]: Toka Zakaria Mohamed Ramadan
 *
 * [DATE CREATED]: May 3, 2021
 *
 * [Description]:
 *****************************/

#ifndef INORD_LIST_H_
#define INORD_LIST_H_

#include <iostream>
#include <cstdlib>
#include<stdlib.h>
#include <string.h>
#include <fstream>
#include<sstream>
using namespace std;



void upper_to_lower_case(std::string& word);




typedef string ListElemType;


class inord_list
{

public:

	inord_list();
    ~inord_list();
	bool insert(const ListElemType &e, int lineNumber); //to insert the new node
	//bool first(ListElemType &e);
	//bool next(ListElemType &e);
	void printList(void);
	void printMaximumList(void);
	void deleteList(void);
	unsigned int charCount(char**arg);
	unsigned int wordCount(void);
	unsigned int distWords(unsigned int numberOfWords_inFile);
	unsigned int countWord(const ListElemType &e);
	void frequentWord(void);
	void starting(ListElemType &e);
	void containing(ListElemType &e);
	void search(ListElemType &e);


private:
	struct Node;
	typedef Node* Link;
	struct Node
	{
		ListElemType item;
		Link next;
		int lineNumber_ofData;
	};
	Link head;
	Link tail;
	Link current;

};


extern inord_list dataList;




#endif /* INORD_LIST_H_ */
