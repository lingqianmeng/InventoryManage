/* modified with C++ 11*/
#include <iostream>     
#include "InventoryManager.h"

// Constructor
InventoryManager::InventoryManager(std::size_t capacity) :
    capacity_(capacity),
    items_()
{
    items_.reserve(capacity_);
}

// Add a new item to inventory
bool InventoryManager::addItem(int id, const std::string& name, int quantity)
{
    // TODO: Create a new InventoryItem and add it to the array
    // 1. Check if there's room in the inventory
    // 2. Check if the Item ID already exists. If not, create a new InventoryItem object using 'new'
    // 3. Add the pointer to the items array
    // 4. Update itemCount
    // 5. Return true if successful, false otherwise

    // Check if the inventory is full
    if (items_.size() >= capacity_)
    {
        // output error message
        std::cout << "Inventory capacity exceeded. Can not add Item." << std::endl;
        return false;
    }

    // Check if the Item ID already exists
    if (getItemById(id))
    {
        // Item with the same ID already exists
        std::cout << "Item with ID " << id << " already exists." << std::endl;
        return false;
    }

    // Create a new InventoryItem object
    auto item = std::make_unique<InventoryItem>(id, name, quantity);
    items_.push_back(std::move(item));

    // output success message
    std::cout << "Item with ID " << id << " added successfully." << std::endl;
    // output current item count
    std::cout << "Current item count: " << items_.size() << std::endl;

    return true;
}

// Get an item by ID
InventoryItem* InventoryManager::getItemById(int id) noexcept
{
    // TODO: Find and return the item with the specified ID
    // 1. Loop through the items array
    // 2. Check each item's ID
    // 3. Return the pointer if found, or nullptr if not found
    // Check if an item with the same ID 
    for (const auto& item : items_)
    {
        if (item && item->getId() == id)
        {
            return item.get(); // found
        }
    }
    // not found
    return nullptr; 
}

// Display all items
void InventoryManager::displayAllItems() const
{
    std::cout << "---Display On---" << std::endl;
    // Display all items in the inventory
    // 1. Check if the inventory is empty
    if (items_.empty())
    {
        std::cout << "Inventory is empty." << std::endl;
        return;
    }

    // 2. Loop through the items and display each one
    for (const auto& item : items_)
    {
        if (item)
        {
            item->display();
        }
    }
    std::cout << "---Display Off---" << std::endl;
}

// Get the item count
std::size_t InventoryManager::getItemCount() const noexcept
{
    return items_.size();
}

// Search for an item by name
InventoryItem* InventoryManager::searchByName(const std::string& name) const    
{
    for (auto const& item : items_)
    {
        if (item && item->getName() == name)
        {
            item->display();
            return item.get(); // found
        }
    }
    // not found
    std::cout << "Item with name " << name << " not found." << std::endl;
    return nullptr;
}

// Update an item's properties
bool InventoryManager::updateItem(int id, const std::string& name, int quantity)
{
    // Update an InventoryItem stored in the items array
    // 1. Find the item by ID
    InventoryItem* item = getItemById(id);

    // 2. Return false if the item was not found
    if (item == nullptr)
    {
        std::cout << "Item with ID" << id << " not found." << std::endl;
        return false;
    }

    // 3. If the item is found:
    // - update the name if a new name was provided
    if (item->getName() != name && !name.empty())
    {
        item->setName(name);
    }

    // - update the quantity if a valid new quantity was provided
    if (item->getQuantity() != quantity && quantity >= 0)
    {
        item->setQuantity(quantity);
    }

    // 4. Return true
    return true;
}

// Remove an item
bool InventoryManager::removeItem(int id)
{
    // Remove the item with the specified ID
    // 1. Find the item in the array
    // 2. Delete the InventoryItem object
    // 3. Shift the remaining pointers to fill the gap
    // 4. Update itemCount
    // 5. Return true if successful, false otherwise

    InventoryItem* item = getItemById(id);
    if (item == nullptr)
    {
        std::cout << "Item with ID " << id << " not found." << std::endl;
        return false;
    }

    for (auto it = items_.begin(); it != items_.end(); ++it)
    {
        if ((*it)->getId() == id)
        {
            items_.erase(it);
            std::cout << "Item with ID " << id << " removed successfully." << std::endl;
            return true;
        }
    }

    std::cout << "Failed to remove item with ID " << id << "." << std::endl;
    return false;
}