/* modified with C++ 11*/

#include <iostream>
#include "InventoryItem.h"

// Parameterized constructor
InventoryItem::InventoryItem(int id, const std::string& name, int quantity) : id_(id), name_(name), quantity_(quantity < 0 ? 0 : quantity)
{
}

// Getters
int InventoryItem::getId() const noexcept
{
    return id_;
}

std::string InventoryItem::getName() const noexcept
{
    return name_;
}

int InventoryItem::getQuantity() const noexcept
{
    return quantity_;
}

// Setters
void InventoryItem::setName(const std::string& newName)
{
    this->name_ = newName;
}

void InventoryItem::setQuantity(int newQuantity)
{
    if (newQuantity >= 0)
    {
        this->quantity_ = newQuantity;
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
    std::cout << "Item ID: " << id_ << ", Name: " << name_ << ", Quantity: " << quantity_ << std::endl;
}