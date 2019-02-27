/****************************************************************************************
** Class Filename: Item.hpp
** Author: Parker Howell
** Date: 1-29-16
** Description: Item object to be stored in a list object.
** Input: Valid name, init, quantitiy, and price variables.
** Output: returns an Item object.
****************************************************************************************/

#ifndef ITEM_HPP
#define ITEM_HPP

#include <string>

class Item
{
private:
	std::string name,       // name of the item.
		unit;               // type of item (box, bag, can, pound, ounce, etc.)
	int quantity;           // how many units of the item to buy.
	double price;           // cost of each unit.


public:
	Item();          // default constructor - do I really need this if I dont use it?




	/***************************************************************************************
	** Overloaded Constructor: Item(std::string n, std::string u, int q, double p)
	** Description: Creates an Item object.
	** Parameters: std::string n  -  name of item
	**             std::string u  -  unit of item (box, bag, can, pound, ounce, etc.)
	**             int q  -  quantity of items to buy
	**             double p  -  price of each unit
	** Pre-Conditions: valid parameters
	** Post-Conditions: creates an item object with passed in parameters.
	***************************************************************************************/
	Item(std::string, std::string, int, double);   




	/***************************************************************************************
	** Overloaded Operator: ==
	** Description: allows two Item objects to be compared for the same name and unit.
	** Parameters: Item  &arrItem  -  a reference to an Item.
	**             ("this->" refers to left hand side Item object of equation.)
	** Pre-Conditions: used with 2 valid Item objects.
	** Post-Conditions: returns "true" if both item have the same name and same unit.
	**                  returns "false" if either differ.
	***************************************************************************************/
	bool operator==(Item  &arrItem);




	/***************************************************************************************
	** Function: getExtPrice()
	** Description: returns extended price (price * quantity) for an item
	** Parameters: None.
	** Pre-Conditions: numOfItems > 0.
	** Post-Conditions: returns a double representing the cost of all of the items in the
	**                  list.
	***************************************************************************************/
	double getExtPrice();   




	/***************************************************************************************
	** Function: printI()
	** Description: prints an individual item's information to the screen
	** Parameters: None.
	** Pre-Conditions: numOfItems > 0.
	** Post-Conditions: Prints the name, unit, quantity, price, and extended price for an
	**                  Item.
	***************************************************************************************/
	void printI();            




	// getters
	std::string getName();
	std::string getUnit();
	int getQuantity();
	double getPrice();



	// setters
	void setName(std::string);
	void setUnit(std::string);
	void setQuantity(int);
	void setPrice(double);

};

#endif