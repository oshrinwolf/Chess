/*
This file servers as an example of how to use Pipe.h file.
It is recommended to use the following code in your project, 
in order to read and write information from and to the Backend
*/

#include "Pipe.h"
#include <iostream>
#include <thread>
#include "Board.h"
#include "Piece.h"
#include "Pawn.h"

using std::cout;
using std::endl;
using std::string;


void main()
{
	int thor = 0;
	srand(time_t(NULL));

	
	Pipe p;
	bool isConnect = p.connect();
	
	string ans;
	while (!isConnect)
	{
		cout << "cant connect to graphics" << endl;
		cout << "Do you try to connect again or exit? (0-try again, 1-exit)" << endl;
		std::cin >> ans;

		if (ans == "0")
		{
			cout << "trying connect again.." << endl;
			Sleep(5000);
			isConnect = p.connect();
		}
		else 
		{
			p.close();
			return;
		}
	}
	

	char msgToGraphics[1024];
	Board* new_board = new Board();
	// msgToGraphics should contain the board string accord the protocol
	// YOUR CODE

	strcpy_s(msgToGraphics, "rnbkqbnrpppppppp################################PPPPPPPPRNBKQBNR1"); // just example...
	
	p.sendMessageToGraphics(msgToGraphics);   // send the board string

	// get message from graphics
	string msgFromGraphics = p.getMessageFromGraphics();

	while (msgFromGraphics != "quit")
	{
		// should handle the string the sent from graphics
		// according the protocol. Ex: e2e4           (move e2 to e4)
		
		// YOUR CODE
		//strcpy_s(msgToGraphics, "YOUR CODE"); // msgToGraphics should contain the result of the operation

		///******* JUST FOR EREZ DEBUGGING ******/
		//int r = rand() % 10; // just for debugging......
		//msgToGraphics[0] = (char)(1 + '0');
		//msgToGraphics[1] = 0;
		/******* JUST FOR EREZ DEBUGGING ******/
		int a = new_board->moveInBoard(msgFromGraphics);
		if (a == -1)
		{
			int r = rand() % 10; // just for debugging......
			msgToGraphics[0] = (char)(6 + '0');
			msgToGraphics[1] = 0;
		}
		else if (a == -2)
		{
			int r = rand() % 10; // just for debugging......
			msgToGraphics[0] = (char)(2 + '0');
			msgToGraphics[1] = 0;
		}
		// return result to graphics		
		else
		{
			int r = rand() % 10; // just for debugging......
			msgToGraphics[0] = (char)(1 + '0');
			msgToGraphics[1] = 0;
		}

		std::cout << "message_new: " << msgToGraphics[0] << msgToGraphics[1] << std::endl;
		p.sendMessageToGraphics(msgToGraphics);

		// get message from graphics
		msgFromGraphics = p.getMessageFromGraphics();
	}

	p.close();
}





