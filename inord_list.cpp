/****************************
 * [FILE NAME]: inord_list.cpp
 *
 * [AUTHOR]: Toka Zakaria Mohamed Ramadan
 *
 * [DATE CREATED]: May 3, 2021
 *
 * [Description]:
 *****************************/
#include "inord_list.h"
#include <iostream>
#include <cstdlib>
#include<stdlib.h>
#include <string.h>
#include <fstream>
#include<sstream>
using namespace std;

/********************************************************************************
 *                                   Constructor                                 *
 *********************************************************************************/
inord_list::inord_list()
{
	head=NULL;
	tail=NULL;
	current=NULL;
}
/********************************************************************************
 *                                   Destructor                                 *
 *********************************************************************************/
inord_list::~inord_list()
{
	Link nextPtr;
	Link currentPtr;

	if(head != NULL)
	{
		currentPtr = head;
		nextPtr = head;


	while( currentPtr != NULL )
	{
		nextPtr = currentPtr->next;
		delete currentPtr;
		head = nextPtr;
		currentPtr = head;
	}
	head = NULL;

	}
}
/********************************************************************************
 *                                   insert                                     *
 *********************************************************************************/
bool inord_list::insert(const ListElemType &e,int lineNumber)
{
	Link addedNode;
	Link pred;
	addedNode = new Node;
	if(addedNode == NULL )
	{
		return false;

	}/*end of if condition*/
	else
	{
		addedNode->item = e;
		addedNode->lineNumber_ofData =lineNumber;
	}
	if(head==NULL || (e.compare(head->item))< 0 )
	{
		addedNode->next=head;
		head=addedNode;
		return true;

	}
	else{
		pred=head;
		while( ( (pred ->next) !=NULL) && ( ( (pred->next->item).compare(addedNode->item) )<=0 ) )
		{
			pred=pred->next;

		}
		addedNode->next = pred->next;
		pred->next=addedNode;
		return true;

	}
}/*End of insert function*/

/********************************************************************************
 *                              printList to check                              *
 *********************************************************************************/
/*function to turn every capital word into small words*/
void inord_list:: printList()
{

	unsigned char i;
	struct Node *ptr= head;

	for(i=1 ; ptr!= NULL ; i++)
	{
		cout<< (ptr->item) << " " << (ptr->lineNumber_ofData)<<endl;

		ptr = ptr->next;
	}

}/*end of print function*/

/********************************************************************************
 *                 printMaximumList to use it in frquentWord                     *
 *********************************************************************************/
void inord_list :: printMaximumList (void) //special print to print the item one time
{

	Link pointerCheck = head;
	string tempString= "just a start to compare to print first element";


	printf("Most frequent word is:");

	while(pointerCheck != NULL)
	{
		if( (pointerCheck->item) != tempString)
		{
			printf(" ");
			cout<<(pointerCheck->item);

		}

		tempString = pointerCheck->item;
		pointerCheck = pointerCheck->next;

	}//end of while loop

	printf("\n");

}/*End of printMaximumList Function*/

/********************************************************************************
 *                                   charCount                                 *
 *********************************************************************************/

unsigned int inord_list:: charCount(char **arg)
{

	ifstream included_dataFile;

	included_dataFile.open(arg[1]);

	char letter;
	int letterCounter=0;

	if ( head == NULL)
	{
		return 0;
	}
	else
	{
		/*
		 * condition on the while loop to read the whole
		 * file to check if the file ends or not
		 */
		while ( !(included_dataFile.eof())  )
		{
			/*
			 * to read the file character by character
			 */
			included_dataFile.get(letter);

			letterCounter++;
		}

		included_dataFile.close();


		return (letterCounter-1);

	}//end of else that there is a list and head != NULL

}/*End of charCount Function*/

/********************************************************************************
 *                                   wordCount                                 *
 *********************************************************************************/
unsigned int inord_list:: wordCount(void)
{

	struct Node *ptr =head;

	int wordCounter=0;

	if(head == NULL)
	{
		return 0;
	}/*End of if condition*/
	else
	{
		while (ptr != NULL)
		{
			wordCounter++;

			ptr= ptr-> next;
		}/*end of while loop*/

		return wordCounter;
	}/*end of else condition*/

}/*End of wordCount Function*/

/********************************************************************************
 *                                   distWords                                 *
 *********************************************************************************/
unsigned int inord_list:: distWords(unsigned int numberOfWords_inFile)
{

	unsigned int repeatedItem=0;
	unsigned int distWord  =0;
	struct Node * ptr = head;
	string tempString;

	if(head == NULL)
	{
		return distWord;
	}
	else
	{

		tempString = (ptr->item);

		for(unsigned int i=0; ( (ptr->next) != NULL) ; i++)
		{

			if( ( tempString.compare(ptr->next->item) ) == 0 )
			{
				repeatedItem++;
			}

			ptr = ptr->next;
			tempString = (ptr->item);

		}/*End of for loop*/


		distWord = numberOfWords_inFile - repeatedItem;

		return distWord;

	}//end of else there is a list and head != NULL

}/*End of distWords Function*/

/********************************************************************************
 *                                   countWord                                 *
 *********************************************************************************/
unsigned int inord_list:: countWord(const string &e)
{
	unsigned int repeatanceOfWord = 0;
	Link ptr  = head;

	if(head == NULL)
	{
		return 0;
	}/*end of head null check*/
	else
	{
		for (unsigned int i=0; ptr!= NULL; i++)
		{

			if( (ptr->item) == e)
			{
				repeatanceOfWord++;
			}

			ptr = ptr-> next;
		}

		return repeatanceOfWord;
	}//end of else that there is a list and head != NULL

}/*end of countWord*/

/********************************************************************************
 *                                to deleteList                                 *
 *********************************************************************************/
void inord_list:: deleteList()
{

	head=NULL;
	tail=NULL;
	current=NULL;

}/*end of deleteList*/


/********************************************************************************
 *                                   frquentWord                                 *
 *********************************************************************************/
void inord_list:: frequentWord(void)
{
	int occur=0;
	int max=0;
	string temp;
	inord_list tempList_forMaximum;
	string maxString;
	struct Node *ptr = head;

	if (head == NULL)
	{
		printf("Word not found\n");
	}
	else
	{

		temp = ptr->item;

		while( (ptr->next) != NULL)
		{


			occur = dataList.countWord(temp);

			if( (max<occur) && (temp != "a") && (temp != "an") && (temp != "the")
					&& (temp != "in") && (temp != "on") && (temp != "of")
					&& (temp != "and") && (temp != "is") && (temp != "are") )
			{
				max = occur;

				tempList_forMaximum.deleteList();
				tempList_forMaximum.insert(temp,occur);
			}
			if( (max==occur) && (temp != "a") && (temp != "an") && (temp != "the")
					&& (temp != "in") && (temp != "on") && (temp != "of")
					&& (temp != "and") && (temp != "is") && (temp != "are") )
			{

				tempList_forMaximum.insert(temp,occur);
			}
			ptr = ptr->next;
			temp = ptr->item;

		}//end of while
		/***********************Handling the last case*********************/
		occur = dataList.countWord(temp);

		if( (max<occur) && (temp != "a") && (temp != "an") && (temp != "the")
				&& (temp != "in") && (temp != "on") && (temp != "of")
				&& (temp != "and") && (temp != "is") && (temp != "are") )
		{
			max = occur;

			tempList_forMaximum.deleteList();
			tempList_forMaximum.insert(temp,occur);
		}
		if( (max==occur) && (temp != "a") && (temp != "an") && (temp != "the")
				&& (temp != "in") && (temp != "on") && (temp != "of")
				&& (temp != "and") && (temp != "is") && (temp != "are") )
		{

			tempList_forMaximum.insert(temp,occur);
		}
		/***********************************************************/
		tempList_forMaximum.printMaximumList();

	}//end of else that there is no list and head != NULL

}/*End of frequentWord Function*/
/********************************************************************************
 *                                   starting                                 *
 *********************************************************************************/
void inord_list:: starting(ListElemType &e)
{

	struct Node*ptr ;

	ptr = head;
	unsigned int occur;
	bool wordFound = false;
	string tempString;

	if(head == NULL)
	{
		printf("Word not found\n");
	}
	else
	{
		tempString = (ptr->item);

		while( (ptr->next) != NULL)
		{

			if( tempString.find(e) == 0 ) //to find the first characters in the word
			{

				wordFound = true;

				if( tempString.compare((ptr->next->item)) != 0 ) //to make sure to print each word one time
				{
					occur = countWord( tempString );
					cout<< tempString << ": "<<occur<<"\t";
				}

			}

			ptr = ptr->next;

			tempString = (ptr->item);

		}//end of while loop

		/************to ask for the last node**************************/
		if( tempString.find(e) == 0 ) //to find the first characters in the word
		{
			occur = countWord( tempString );
			cout<< tempString << ": "<<occur;
		}
		/***********************************************************************/
		if( !wordFound )
		{
			printf("Word not found");
		}//end of wordFound

		printf("\n");

	}//end of else that there is a list and head != NULL


}//end of starting function
/********************************************************************************
 *                                   containing                                 *
 *********************************************************************************/
void inord_list:: containing(string& e)
{
	struct Node*ptr = head;
	unsigned int occur;
	unsigned int containingStringLength;
	unsigned int itemLength;
	bool wordFound = false;
	string tempSubString;
	string tempString;


	if(head == NULL)
	{
		printf("Word not found\n");
	}
	else
	{

		tempString = (ptr->item);

		containingStringLength = e.length(); //get the length of containing string

		while( (ptr->next) != NULL)
		{

			itemLength = tempString.length(); //get length of every item in the list

			for(unsigned int i =0 ; i<=itemLength; i++) //loop to search for the given string in all string length
			{

				tempSubString = tempString.substr(i,containingStringLength); //get the sub string from position i till length of the given string

				if ( tempSubString == e )
				{
					wordFound = true;

					//this condition print the last one of the group of the same words
					//as this condition won't be true until it reaches the last item of the same words
					if( tempString.compare((ptr->next->item)) != 0 ) //to make sure to print each word one time
					{

						occur = countWord( tempString  ); //get the number of occurrence of the word
						cout<< tempString << ": "<<occur<<"\t";
						break; //to break from loop after getting it
					}

				}//end of if condition to find the word

			}//end of for loop

			ptr = ptr->next;
			tempString = (ptr->item);
		}//end of while loop


		/***************Handling the last case******************/
		itemLength = tempString.length(); //get length of every item in the list

		for(unsigned int i =0 ; i<=itemLength; i++) //loop to search for the given string in all string length
		{

			tempSubString = tempString.substr(i,containingStringLength); //get the sub string from position i till length of the given string

			if ( tempSubString == e )
			{
				wordFound = true;

				occur = countWord( tempString  ); //get the number of occurrence of the word
				cout<< tempString << ": "<<occur;

				break; //to break from loop after getting it

			}//end of if condition to find the word

		}//end of for loop

		/**********************************************************************************/

		if( !wordFound )
		{
			printf("Word not found");
		}//end of wordFound

		printf("\n");

	}//end of else that there is a list and head != NULL

}//end of containing function

/********************************************************************************
 *                                       search                                 *
 *********************************************************************************/
void inord_list:: search(string &e)  //same as containing just add to print line
{

	struct Node*ptr = head;
	unsigned int containingStringLength;
	unsigned int itemLength;
	int repeatedLine = 0;
	bool wordFound = false;
	string tempSubString;
	string tempNextString = "just a start to compare to compare from first not last like containing";
	string temp;

	if(head == NULL)
	{
		printf("Word not found\n");
	}
	else
	{

		temp = (ptr->item);
		containingStringLength = e.length(); //get the length of containing string

		while( (ptr->next) != NULL)
		{
			itemLength = temp.length(); //get length of every item in the list

			for(unsigned int i =0 ; i<=itemLength; i++) //loop to search for the given string in all string length
			{

				tempSubString = temp.substr(i,containingStringLength); //get the sub string from position i till length of the given string

				if ( (tempSubString == e) && (temp.compare(tempNextString) != 0)  )
				{
					wordFound = true;

					cout<< temp << ":"<<"	"<<"lines"<<" "<<(ptr->lineNumber_ofData)<<" ";
					repeatedLine = (ptr->lineNumber_ofData);
					tempNextString = (ptr->item);

					// internal loop to print all lines
					//to print all lines

					while( (ptr->item) == (ptr->next->item))
					{
						if ((ptr->next->lineNumber_ofData) != repeatedLine)
						{
							cout<< (ptr->next->lineNumber_ofData) << " ";
						}
						repeatedLine = (ptr->next->lineNumber_ofData);

						ptr = (ptr->next);

					}//end of internal loop to print all lines

					cout<<endl;

				}//end of if condition to find the word

			}//end of for loop which is responsible to search in the string element by element

			ptr = ptr->next;
			temp = (ptr->item);

		}//end of while loop

		/****************************Handling the last case*******************************/

		itemLength = temp.length(); //get length of every item in the list

		for(unsigned int i =0 ; i<=itemLength; i++) //loop to search for the given string in all string length
		{

			tempSubString = temp.substr(i,containingStringLength); //get the sub string from position i till length of the given string

			if ( (tempSubString == e) && (temp.compare(tempNextString) != 0)  )
			{
				wordFound = true;

				cout<< temp << ":"<<"	"<<"lines"<<" "<<(ptr->lineNumber_ofData);
				repeatedLine = (ptr->lineNumber_ofData);
				tempNextString = (ptr->item);

				cout<<endl;

			}//end of if condition to find the word

		}//end of for loop which is responsible to search in the string element by element


		/**********************************************************************************/


		if( !wordFound )
		{
			printf("Word not found\n");
		}//end of wordFound

	}//end of else that there is a list and head != NULL


}//end of search function

/********************************************************************************
 *                          upper_to_lower_case                                 *
 *********************************************************************************/
void upper_to_lower_case(std::string& word)
{
	unsigned int counter;
	unsigned int wordLength =0;

	wordLength = word.length();

	for(counter=0; counter< wordLength; counter++)
	{

		if(word.at(counter) >= 'A' && word.at(counter) <= 'Z')
		{
			word.at(counter) = word.at(counter) + 32;
		}

	}/*End of for loop*/

}/*end of upper_to_lower_case Function*/
/*************************************************************************************/



