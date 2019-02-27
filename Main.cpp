/****************************************************************************************
** Author: Parker Howell
** Date: 1-29-16
** Description: Creates a List object and then uses a menu system to either add or remove
**              items, or exit. Will print list after each change to list object as well 
**              total cost for the whole list. Duplicate items (same name and unit) will 
**              have quantities combined, while keeping the price of the original item.      
****************************************************************************************/

#include <iostream>
#include <string>
#include <cstdlib>
#include "Item.hpp"
#include "List.hpp"


// Note: system("CLS") works with win / visual studio. Use "clear" for *nix...
#define CLEAR_SCREEN "clear"


int main(){

	List myList;            // create a default List object

	int listSize,           // how many items in list
		choice,             // which Main Menu choice is selected
		quantity,           // how many of user created item
		toDelete;           // item to be removed from list.
	std::string name,       // name of user created item
	        	unit;       // type of user created item (pounds, box, bag, etc...
	double price;           // dollar cost per unit of user created item



	// Main menu 
	do {
		listSize = myList.getNumOfItems();
		system(CLEAR_SCREEN);

		// Header if list is empty 
		if (listSize == 0){
			std::cout << "****************************************************************"
				      << std::endl;
			std::cout << "|                                                              |"
				      << std::endl;
			std::cout << "|                    Your List is Empty                        |"
				      << std::endl;
			std::cout << "|                                                              |"
				      << std::endl;
			std::cout << "****************************************************************"
				      << std::endl << std::endl;
		}
		else{ // Header if list has items
			std::cout << "**************     - Welcome to your List! -      **************" 
				      << std::endl;
			std::cout << "|                                                              |"
			          << std::endl;

			// print out contents of list
			myList.printL();

			std::cout << "****************************************************************"
				<< std::endl << std::endl;
		}


		// print Menu options and get user choice
		std::cout << "1. Add an Item" << std::endl;
		
		if (listSize != 0){
			std::cout << "2. Remove an Item" << std::endl;
		}
		std::cout << "3. Exit" << std::endl;
		std::cin >> choice;


		// validate choice
		if (listSize != 0){
			// if there are items to delete...
			while (choice < 1 || choice > 3){
				std::cout << "Please select 1 - 3." << std::endl;
				std::cin >> choice;
			}
		}
		else { // if there aren't items to delete...
			while (choice != 1 && choice != 3){
				std::cout << "Please select either 1 or 3." << std::endl;
				std::cin >> choice;
			}
		}


		//if the user didn't exit
		if (choice != 3){

			// add an item
			if (choice == 1){
				std::cout << "What is the name of your item?" << std::endl;
				std::cin.ignore();
				std::getline(std::cin, name);


				std::cout << "What is the unit of your item? (pound, ounce,"
					      << "box, bag, etc.)" << std::endl;
				std::getline(std::cin, unit);


				std::cout << "How many of them do you want?" << std::endl;
				std::cin >> quantity;

				while (quantity <= 0){
					std::cout << "Please enter a quantitiy of 1 or greater. " << std::endl;
					std::cin >> quantity;
				}


				std::cout << "How much does each unit of your item cost?" << std::endl;
				std::cin >> price;

				while (price <= 0){
					std::cout << "Please enter a price greater than 0.00" << std::endl;
					std::cin >> price;
				}

				myList.addItem(name, unit, quantity, price, myList.getArrMax());
			}



			// delete an item
			else // (choice == 2)
			{
				// if there's only 1 item in the list
				if (listSize == 1){
					std::cout << "This will empty your list." << std::endl;
					std::cout << "Press enter to continue. ";
					std::cin.ignore();
					std::cin.get();

					myList.deleteItem(0);
				}

				// if there's multiple items in the list
				else{
					std::cout << "Which item number would you like to delete?" << std::endl;
					std::cout << "Please select between 1 - "
					          << listSize << std::endl;
					std::cin.get();
					std::cin >> toDelete;

					// validate item to be deleted
					while (toDelete < 1 || toDelete > listSize){
						std::cout << "Please select 1 - " << listSize << std::endl;
						std::cin >> toDelete;
					}

					// delete the item
					myList.deleteItem(toDelete - 1);
				}
			}
		}

	// did the user quit?
	} while (choice != 3);

	return 0;
}