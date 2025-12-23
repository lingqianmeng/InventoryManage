#include <iostream>
#include "InventoryItem.h"

// Constructor
InventoryItem::InventoryItem() : id(0), name(""), quantity(0)
{
    // Default constructor body (if needed)
}

// Parameterized constructor
InventoryItem::InventoryItem(int id, const std::string& name, int quantity)
{
    this->id = id;
    this->name = name;
    this->quantity = quantity < 0 ? 0 : quantity;
}

InventoryItem::~InventoryItem()
{
       // Destructor body (if needed)
}

// Getters
int InventoryItem::getId() const
{
    return id;
}

std::string InventoryItem::getName() const
{
    return name;
}

int InventoryItem::getQuantity() const
{
    return quantity;
}

// Setters
void InventoryItem::setName(const std::string& newName)
{
    this->name = newName;
}

void InventoryItem::setQuantity(int newQuantity)
{
    if (newQuantity >= 0)
    {
        this->quantity = newQuantity;
    }
    else 
    {
        // Optionally handle invalid quantity (e.g., log an error)
        std::cout << "Quantity cannot be negative. No changes made." << std::endl;
    }
}

// Display item details
void InventoryItem::display() const
{
    std::cout << "Item ID: " << id << ", Name: " << name << ", Quantity: " << quantity << std::endl;
}