/****************************************************************************************
** Class Filename: List.hpp
** Author: Parker Howell
** Date: 1-29-16
** Description: Creates a List object to store and manipulate Item objects.
** Input: See specific functions
** Output: See specific functions
****************************************************************************************/

#include "List.hpp"
#include <iostream>
#include <iomanip>
#include <string>


/***************************************************************************************
** Function: List()  -  default constructor
** Description: Creates a List object with a 4 item empty array of Items.
** Parameters: None.
** Pre-Conditions: None.
** Post-Conditions: Creates a List object with a 4 item empty array of Items.
***************************************************************************************/
List::List()
{
	setNumOfItems(0);
	setIndex(0);
	setArrMax(4);
	ptr2Item = new Item[4];
}




/***************************************************************************************
** Function: printL()
** Description: Prints all of the Item objects to the screen.
** Parameters: None.
** Pre-Conditions: numOfItems > 0.
** Post-Conditions: prints a list header. Then loops through each item in the array,
**                  printing a number and calling each items individual print function.
**                  Then prints the total cost of all items in the list.
***************************************************************************************/
void List::printL()
{
	// header for list
	std::cout << "| ";
	std::cout << std::right << std::setw(3) << "#";
	std::cout << std::right << std::setw(1) << " ";
	std::cout << std::right << std::setw(10) << "Item Name";
	std::cout << std::right << std::setw(11) << "Unit";
	std::cout << std::right << std::setw(12) << "Quantity";
	std::cout << std::right << std::setw(10) << "Price";
	std::cout << std::right << std::setw(13) << "Ext Price";
	std::cout << " |" << std::endl;
	std::cout << "|                                                              |"
		      << std::endl;

	// for all items in list, prints out item number and calls item print function 
	for (int i = 0; i < numOfItems; i++){
		std::cout << "| ";
		std::cout << std::right << std::setw(2) << i + 1 << ".";
		ptr2Item[i].printI();
		std::cout << " |" << std::endl;
	}

	// prints out total cost of all items in the list
	std::cout << "----------------------------------------------------------------"
		<< std::endl;
	std::cout << "|                                          TOTAL:  $" 
		      << std::left << std::setw(10) << getTotal() << " |" << std::endl;

}




/***************************************************************************************
** Function: addItem(std::string, std::string, int, double)
** Description: Adds an Item object to the list
** Parameters: string for name of item.
**             string for unit of item.
**             int for quantity of item.
**             double for price of item.
** Pre-Conditions: passed a valid arguments.
** Post-Conditions: If theres room in the array, adds a new Item object to it at the
**                  index location. If array is full, will call dblList(), then add
**                  the new Item. If items already exist based on Item name and 
**                  unit, the already existing item will have it's quantitiy added to.
***************************************************************************************/
void List::addItem(std::string n, std::string u, int q, double p, int max)
{
	// if the list is full, double it's size
	if (numOfItems == max){
		ptr2Item = dblList(ptr2Item, max);
	}

	// make a fresh Item called "it"
	Item it(n, u, q, p);

	// set item flag to not existing
	bool itemExists = 0;

	for (int i = 0; i < numOfItems; i++){

		// if item name and unit match
		if (it == ptr2Item[i]){
			std::cout << std::endl << "You already have this item on your list."
				<< " The quantities will be combined." << std::endl;
			std::cout << "Press \"Enter\" to continue." << std::endl;
			std::cin.ignore();
			std::cin.get();

			ptr2Item[i].setQuantity(ptr2Item[i].getQuantity() + it.getQuantity());
			itemExists = 1;
		}
	}

	// if the item didn't already exist, or the array was empty, add it
	if (!itemExists){
		ptr2Item[index] = it;
		numOfItems++;
		index++;
	}
}




/***************************************************************************************
** Function: deleteItem(int)
** Description: Deletes an item object from the list
** Parameters: int  -  which array index to delete.
** Pre-Conditions: passed a valid int.
** Post-Conditions: effectivly deletes a Item object by moving all array values greater
**                  than the deleted item to the left by one, and then decriments 
**                  numOfItems and index.
***************************************************************************************/
void List::deleteItem(int i)
{
	// if item to be deleted is the last one in the array
	if (i == numOfItems - 1){
		numOfItems--;
		index--;
	}
	// not the last item in array
	else{
		for (i; i < numOfItems; i++){
			ptr2Item[i] = ptr2Item[i + 1];
		}
		numOfItems--;
		index--;
	}
}




/***************************************************************************************
** Function: getTotal()
** Description: Totals all of the Item's extended prices.
** Parameters: None.
** Pre-Conditions: Valid Items exist
** Post-Conditions: Returns a double of all of the Items extended prices in the list.
***************************************************************************************/
double List::getTotal()
{
	double temp = 0;
	for (int i = 0; i < numOfItems; i++){
		temp += ptr2Item[i].getExtPrice();
	}

	return temp;
}




/***************************************************************************************
** Function: * dblList(Item *[])
** Description: doubles the size of the ptr2Item array.
** Parameters: Item arr[]  -  an array of items.
**             int m  -  the size of the passed in array
** Pre-Conditions: valid array
** Post-Conditions: retruns a pointer to an array double the size of the one passed in
**                  containing the same elements. The passed in array is deleted.
***************************************************************************************/

Item* List::dblList(Item arr[], int m)
{
	Item *temp = new Item[m * 2];
	for (int i = 0; i < m; i++){
		temp[i] = arr[i];
	}
	delete[] arr;
	arrMax *= 2;

	return temp;
}                    




// getters
int List::getNumOfItems()
{
	return numOfItems;
}

int List::getIndex()
{
	return index;
} 

int List::getArrMax()
{
	return arrMax;
}

// end getters



// setters
void List::setNumOfItems(int n)
{
	numOfItems = n;
}

void List::setIndex(int i)
{
	index = i;
}

void List::setArrMax(int m)
{
	arrMax = m;
}
// end setters
