/****************************************************************************************
** Class Filename: Item.hpp
** Author: Parker Howell
** Date: 1-29-16
** Description: Item object to be stored in a list object.
** Input: Valid name, init, quantitiy, and price variables.
** Output: returns an Item object.
****************************************************************************************/

#include "Item.hpp"
#include <iostream>
#include <iomanip>

// default constructor. Do I need it if I don't use it?
Item::Item()
{
	setName("");
	setUnit("");
	setQuantity(0);
	setPrice(0.00);
}




/***************************************************************************************
** Function: Item(std::string n, std::string u, int q, double p)
** Description: Creates an Item object.
** Parameters: std::string n  -  name of item
**             std::string u  -  unit of item (box, bag, can, pound, ounce, etc.)
**             int q  -  quantity of items to buy
**             double p  -  price of each unit
** Pre-Conditions: valid parameters
** Post-Conditions: creates an item object with passed in parameters.
***************************************************************************************/
Item::Item(std::string n, std::string u, int q, double p)
{
	setName(n);
	setUnit(u);
	setQuantity(q);
	setPrice(p);
}




/***************************************************************************************
** Overloaded Operator: ==
** Description: allows two Item objects to be compared for the same name and unit.
** Parameters: Item  &arrItem  -  a reference to an Item.
**             ("this->" refers to left hand side Item object of equation.)
** Pre-Conditions: used with 2 valid Item objects.
** Post-Conditions: returns "true" if both item have the same name and same unit.
**                  returns "false" if either differ.
***************************************************************************************/
bool Item::operator==(Item  &arrItem)
{
	return ((this->name == arrItem.name) && this->unit == arrItem.unit);
}




/***************************************************************************************
** Function: getExtPrice()
** Description: returns extended price (price * quantity) for an item
** Parameters: None.
** Pre-Conditions: numOfItems > 0.
** Post-Conditions: returns a double representing the cost of all of the items in the 
**                  list.
***************************************************************************************/
double Item::getExtPrice()
{
	return this->quantity * this->price;
}




/***************************************************************************************
** Function: printI()
** Description: prints an individual item's information to the screen
** Parameters: None.
** Pre-Conditions: numOfItems > 0.
** Post-Conditions: Prints the name, unit, quantity, price, and extended price for an 
**                  Item.
***************************************************************************************/
void Item::printI()
{
	std::cout << std::showpoint << std::fixed << std::setprecision(2);
	std::cout << std::right << std::setw(11) << this->name;
	std::cout << std::right << std::setw(11) << this->unit;
	std::cout << std::right << std::setw(12) << this->quantity;
	std::cout << std::right << std::setw(10) << this->price;
	std::cout << std::right << std::setw(13) << this->getExtPrice();
}




// getters
std::string Item::getName()
{
	return name;
}

std::string Item::getUnit()
{
	return unit;
}

int Item::getQuantity()
{
	return quantity;
}

double Item::getPrice()
{
	return price;
}
// end getters



// setters
void Item::setName(std::string n)
{
	name = n;
}

void Item::setUnit(std::string u)
{
	unit = u;
}

void Item::setQuantity(int q)
{
	quantity = q;
}

void Item::setPrice(double p)
{
	price = p;
}
// end setters

