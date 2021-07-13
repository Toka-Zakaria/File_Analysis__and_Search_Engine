/****************************
 * [FILE NAME]: a2.cpp
 *
 * [AUTHOR]: Toka Zakaria Mohamed Ramadan
 *
 * [DATE CREATED]: May 3, 2021
 *
 * [Description]: To implement a tool that analyzes a text file and returns information about its
                  content. It also allows a simple search for words in the file.
 *****************************/

/*******************************************************************************
 *                               Preprocessor Hashes                           *
 *******************************************************************************/
#include <iostream>
#include <fstream>
#include<sstream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include<cstring>
#include <string.h>
#include<algorithm>
using namespace std;

#include"inord_list.h"
/*********************************************************************************
 *                          Functions Prototypes                               *
 ********************************************************************************/
#define FALSE  0
#define TRUE   1
/***************************/
inord_list dataList;

int main (int argumentsNumber, char** argument)
{
	/*******************************************************************************
	 *                                Data file                                    *
	 *******************************************************************************/

	ifstream included_dataFile;

	included_dataFile.open (argument[1]);

	if ( included_dataFile.is_open() == FALSE)
	{
		printf ("File not found\n");
		return 0 ;
	}
	else if ( (argumentsNumber < 3) || (argumentsNumber > 3) )
	{
		printf("Incorrect number of arguments\n");
		return 0;
	}
	/******************************************************************************
	 *                    Storing data from file in a list                         *
	 ******************************************************************************/

	string line;
	string word;
	string wordStore;


	int line_number = 1;

	char dataLetter;
	//inord_list dataList;
	char temp=0;
	/*
	 * condition on the while loop to read the whole
	 * file to check if the file ends or not
	 */
	while ( ! ( included_dataFile.eof() )  )
	{
		/*
		 * to read the file character by character
		 */
		included_dataFile.get(dataLetter);
		temp++;

		/*to check if the line ended or not*/
		if (dataLetter == '\n')
		{
			dataLetter = ' ';
			word = word + dataLetter;

			if (word == " ")
			{
				/*
				 * increment the number of lines if the line ends
				 */
				line_number = line_number + 1 ; //to calculate the empty lines

				word.clear();
				continue;
			}
			else
			{
				upper_to_lower_case(word);
				word.erase(word.size() - 1); //to remove null from every string //very important to countWord
				dataList.insert(word,line_number);
				word.clear();
				/*
				 * increment the number of lines if the line ends
				 */
				line_number = line_number + 1 ; //calculate the lines that contain words
			}


		}/*end of new line*/

		/*check if the word ends or not by check of the separators*/
		if ( (dataLetter == '(') || (dataLetter == ')') || (dataLetter == '{') ||
				(dataLetter == '}') || (dataLetter == '[') || (dataLetter == ']') ||
				(dataLetter == '.') || (dataLetter == '"') || (dataLetter == '&') ||
				(dataLetter == '`') || (dataLetter == ':') || (dataLetter == ';') ||
				(dataLetter == ',') || (dataLetter == ' ') || (dataLetter == '\'')
				|| (dataLetter == '!') || (dataLetter == '?') || (dataLetter == '	') )
		{
			dataLetter = ' ';
			word = word + dataLetter;


			if (word == " ")
			{
				word.clear();
				continue;
			}
			else
			{
				upper_to_lower_case(word);
				word.erase(word.size() - 1); //to remove null from every string //very important to countWord
				dataList.insert(word,line_number);
				word.clear();
			}/*End of else condition*/
		}/*end of if condition*/
		else
		{
			word = word + dataLetter;
		}

	}/*End of while loop that read the data file line by line*/

	/*print linkedlist*/
	//dataList.printList();

	/*
	 * close the opened file of data
	 */
	included_dataFile.close();
	/********************************************************************************
	 *                            Instruction File                                  *
	 ********************************************************************************/

	ifstream included_commandsFile;

	included_commandsFile.open (argument[2]);

	if ( included_commandsFile.is_open() == FALSE)
	{
		printf ("File not found\n");
		return 0 ;
	}

	/********************************************************************************
	 *                     Reading commands from commands file                      *
	 *********************************************************************************/

	//char commandLetter;
	string command;
	string commandLine;
	unsigned int numberOfWords=0;
	unsigned int numberOf_distinctWords=0;
	unsigned int numberOf_characters=0;
	unsigned int numberOf_wantedWord =0;

	//( included_commandsFile >> command )

	//string line;
	while( getline(included_commandsFile,commandLine) )
	{
		istringstream Line(commandLine); //to get word by word from line

		  //get the first word and store it in command string

		if( !(Line >> command) ) //get the command and check if it is empty line or not
		{
			command.clear();
			continue;
		}
		else
		{
			/********************************************************************************
			 *                                 wordCount                                     *
			 *********************************************************************************/
			if(command.compare("wordCount") == 0)
			{
				numberOfWords =	dataList.wordCount(); //calculate the number of words in the list

				/*check if there is operands or not*/

				if( !(Line >> command) ) //get another word from the line
				{
					printf("%d words\n", numberOfWords);
					command.clear();
					continue;
				}
				else
				{
					printf("Incorrect number of arguments\n");
					command.clear();
					continue;
				}

			}/*end of wordCount*/
			/********************************************************************************
			 *                                 distWords                                     *
			 *********************************************************************************/
			else if(command.compare("distWords") == 0)
			{
				numberOf_distinctWords = dataList.distWords(numberOfWords); //get number of distWords

				/*check if there is operands or not*/

				if( !(Line >> command) )  //get another word from the line
				{
					printf("%d distinct words\n", numberOf_distinctWords);
					command.clear();
					continue;
				}
				else
				{
					printf("Incorrect number of arguments\n");
					command.clear();
					continue;
				}

			}/*end of distWords*/
			/********************************************************************************
			 *                                 charCount                                    *
			 *********************************************************************************/
			else if(command.compare("charCount") == 0)
			{
				numberOf_characters = dataList.charCount(argument); //get the number of characters

				/*check if there is operands or not*/

				if( !(Line >> command) ) //get another word from the line
				{
					printf("%d characters\n", numberOf_characters );
					command.clear();
					continue;
				}
				else
				{
					printf("Incorrect number of arguments\n");
					command.clear();
					continue;
				}

			}/*end of charCount*/
			/********************************************************************************
			 *                                 frequentWord                                    *
			 *********************************************************************************/
			else if(command.compare("frequentWord") == 0)
			{

				if( !(Line >> command) ) //get another word from the line
				{

					dataList.frequentWord();
					command.clear();
					continue;
				}
				else
				{
					printf("Incorrect number of arguments\n");
					command.clear();
					continue;
				}

			}/*end of frequentWord*/
			/********************************************************************************
			 *                                  countWord                                   *
			 *********************************************************************************/
			else if(command.compare("countWord") == 0)
			{
				string temp;

				if( !(Line >> command)) //get another word from the line //condition that there is no operands
				{
					printf("Incorrect number of arguments\n");
					command.clear();
					continue;
				}
				else
				{
					temp = command; //to store the first command was got from condition

					if( !(Line >> command) ) //to make sure there is one operand
					{
						upper_to_lower_case(temp);
						numberOf_wantedWord = dataList.countWord( temp );
						cout<<temp<<" is repeated "<<numberOf_wantedWord<<" times"<<endl;
						command.clear();
						continue;
					}
					else
					{
						printf("Incorrect number of arguments\n");
						command.clear();
						continue;
					}
				}


			}/*end of countWord*/
			/********************************************************************************
			 *                                   starting                                   *
			 *********************************************************************************/
			else if(command.compare("starting") ==0)
			{

				string temp;

				if( !(Line >> command)) //get another word from the line //condition that there is no operands
				{
					printf("Incorrect number of arguments\n");
					command.clear();
					continue;
				}
				else
				{
					temp = command; //to store the first command was got from condition

					if( !(Line >> command) ) //to make sure there is one operand
					{
						upper_to_lower_case(temp);
						dataList.starting(temp);
						command.clear();
						continue;
					}
					else
					{
						printf("Incorrect number of arguments\n");
						command.clear();
						continue;
					}
				}

			}/*end of starting*/
			/********************************************************************************
			 *                                 containing                                   *
			 *********************************************************************************/
			else if(command.compare("containing") ==0)
			{


				string temp;

				if( !(Line >> command)) //get another word from the line //condition that there is no operands
				{
					printf("Incorrect number of arguments\n");
					command.clear();
					continue;
				}
				else
				{
					temp = command; //to store the first command was got from condition

					if( !(Line >> command) ) //to make sure there is one operand
					{
						upper_to_lower_case(temp);
						dataList.containing(temp);
						command.clear();
						continue;
					}
					else
					{
						printf("Incorrect number of arguments\n");
						command.clear();
						continue;
					}
				}

			}/*end of containing*/
			/********************************************************************************
			 *                                    search                                     *
			 *********************************************************************************/
			else if(command.compare("search") ==0)
			{

				string temp;

				if( !(Line >> command)) //get another word from the line //condition that there is no operands
				{
					printf("Incorrect number of arguments\n");
					command.clear();
					continue;
				}
				else
				{
					temp = command; //to store the first command was got from condition

					if( !(Line >> command) ) //to make sure there is one operand
					{
						upper_to_lower_case(temp);
						dataList.search(temp);
						command.clear();
						continue;
					}
					else
					{
						printf("Incorrect number of arguments\n");
						command.clear();
						continue;
					}
				}
			}/*end of search*/
			/********************************************************************************
			 *                                 No commands                                   *
			 *********************************************************************************/
			else
			{
				printf("Undefined command\n");
				command.clear();
				continue;
			}

		}//end of that there is no empty line

	}//end of while

	/*close instruction file*/
	included_commandsFile.close();
	return 0;
}/*End of main_function*/
