/****************************************************************************************
** Class Filename: List.hpp
** Author: Parker Howell
** Date: 1-29-16
** Description: Creates a List object to store and manipulate Item objects.
** Input: See specific functions
** Output: See specific functions
****************************************************************************************/

#ifndef LIST_H
#define LIST_H

#include "Item.hpp"

class List
{
private:

	int numOfItems,      // how many items the list has.
		index,           // tracks location in ptr2Item array.
		arrMax;          // tracks size of List array.
	Item *ptr2Item;      // pointer to dynamic array of Item objects.


public:

	/***************************************************************************************
	** Function: List()  -  default constructor
	** Description: Creates a List object with a 4 item empty array of Items.
	** Parameters: None.
	** Pre-Conditions: None.
	** Post-Conditions: Creates a List object with a 4 item empty array of Items.
	***************************************************************************************/
	List();



	/***************************************************************************************
	** Function: printL()
	** Description: Prints all of the Item objects to the screen.
	** Parameters: None.
	** Pre-Conditions: numOfItems > 0.
	** Post-Conditions: prints a list header. Then loops through each item in the array,
	**                  printing a number and calling each items individual print function.
	**                  Then prints the total cost of all items in the list.
	***************************************************************************************/
	void printL();       




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
	void addItem(std::string, std::string, int, double, int);




	/***************************************************************************************
	** Function: deleteItem(int)
	** Description: Deletes an item object from the list
	** Parameters: int  -  which array index to delete.
	** Pre-Conditions: passed a valid int.
	** Post-Conditions: effectivly deletes a Item object by moving all array values greater
	**                  than the deleted item to the left by one, and then decriments
	**                  numOfItems and index.
	***************************************************************************************/
	void deleteItem(int);




	/***************************************************************************************
	** Function: getTotal()
	** Description: Totals all of the Item's extended prices.
	** Parameters: None.
	** Pre-Conditions: Valid Items exist
	** Post-Conditions: Returns a double of all of the Items extended prices in the list.
	***************************************************************************************/
	double getTotal();




	/***************************************************************************************
	** Function: * dblList(Item *[])
	** Description: doubles the size of the ptr2Item array.
	** Parameters: Item arr[]  -  an array of items.
	**             int m  -  the size of the passed in array
	** Pre-Conditions: valid array
	** Post-Conditions: retruns a pointer to an array double the size of the one passed in
	**                  containing the same elements. The passed in array is deleted.
	***************************************************************************************/
	Item* dblList(Item [], int);




    // getters
	int getNumOfItems();
	int getIndex();
	int getArrMax();


	// setters
	void setNumOfItems(int);
	void setIndex(int);
	void setArrMax(int);

};

#endif
