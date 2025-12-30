/* modified with C++ 11*/
#pragma once
#include <string>

/**
 * Represents an inventory item with ID, name, and quantity.
 */
class InventoryItem 
{
private:
    int id_;
    std::string name_;
    int quantity_;   
public:
    /* Default constructor */
    InventoryItem() = default;

    /* Parameterized constructor */
    InventoryItem(int id, const std::string& name, int quantity);
    
    /* Destructor*/
    ~InventoryItem() = default;
    
    /* Getters */
    int getId() const noexcept;
    std::string getName() const noexcept;
    int getQuantity() const noexcept; 
    void display() const;
    
    /* Setters */   
    void setName(const std::string& name);
    void setQuantity(int quantity);
};