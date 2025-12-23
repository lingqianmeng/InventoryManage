#pragma once

/**
 * Represents an inventory item with ID, name, and quantity.
 */
class InventoryItem 
{
private:
    int id;
    std::string name;
    int quantity;   
public:
    /* Default constructor */
    InventoryItem();

    /* Parameterized constructor */
    InventoryItem(int id, const std::string& name, int quantity);
    
    /* Destructor*/
    ~InventoryItem();
    
    /* Getters */
    int getId() const;
    std::string getName() const;
    int getQuantity() const; 
    void display() const;
    
    /* Setters */   
    void setName(const std::string& name);
    void setQuantity(int quantity);
};