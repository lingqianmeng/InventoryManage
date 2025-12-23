#include <iostream>     
#include "InventoryManager.h"

// Constructor
InventoryManager::InventoryManager(std::size_t capacity)
{
    // Initialize member variables
    this->capacity = capacity;
    itemCount = 0;
    items = new InventoryItem *[capacity]; // Allocate memory for array of pointers

    // Initialize all pointers to nullptr
    for (std::size_t i = 0; i < capacity; ++i)
    {
        items[i] = nullptr;
    }
}

// Destructor
InventoryManager::~InventoryManager()
{
    // Clean up dynamically allocated memory
    // 1. Delete each InventoryItem object
    for (std::size_t i = 0; i < itemCount; ++i)
    {
        delete items[i]; 
    }

    // 2. Delete the array of pointers
    delete[] items; 
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
    if (itemCount >= capacity)
    {
        // output error message
        std::cout << "Inventory is full. Can not add any more Items." << std::endl;
        return false;
    }

    // Check if the Item ID already exists
    for (std::size_t i = 0; i < itemCount; ++i)
    {
        if (items[i]->getId() == id)
        {
            // output error message
            std::cout << "Item with ID " << id << " already exists." << std::endl;
            return false;
        }
    }

    // Create a new InventoryItem object
    items[itemCount] = new InventoryItem(id, name, quantity);
    itemCount++;

    // output success message
    std::cout << "Item with ID " << id << " added successfully." << std::endl;
    // output current item count
    std::cout << "Current item count: " << itemCount << std::endl;

    return true;
}

// Get an item by ID
InventoryItem* InventoryManager::getItemById(int id)
{
    // TODO: Find and return the item with the specified ID
    // 1. Loop through the items array
    // 2. Check each item's ID
    // 3. Return the pointer if found, or nullptr if not found
    // Check if an item with the same ID 
    for (std::size_t i = 0; i < itemCount; ++i)
    {
        if (items[i]->getId() == id)
        {
            return items[i]; // Duplicate ID
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
    if (itemCount == 0)
    {
        std::cout << "Inventory is empty." << std::endl;
        return;
    }

    // 2. Loop through the items and display each one
    for (std::size_t i = 0; i < itemCount; ++i)
    {
        items[i] -> display();
    }

    std::cout << "---Display Off---" << std::endl;
}

// Get the item count
std::size_t InventoryManager::getItemCount() const
{
    return itemCount;
}

// Search for an item by name
InventoryItem* InventoryManager::searchByName(const std::string& name) const
{
    for (std::size_t i = 0; i < itemCount; ++i)
    {
        if (items[i] -> getName() == name)
        {
            return items[i];
        }
    }

    return nullptr;
}

void InventoryManager::displayByName(const std::string& name) const
{
    InventoryItem* searchResult = this->searchByName(name);
    if (searchResult != nullptr)
    {
        searchResult->display();
    }
    else
    {
        std::cout << "Item with name " << name << " not found." << std::endl;
    }
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
    if (item -> getName() != name && !name.empty())
    {
        item -> setName(name);
    }

    // - update the quantity if a valid new quantity was provided
    if (item -> getQuantity() != quantity && quantity >= 0)
    {
        item -> setQuantity(quantity);
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

    for (std::size_t i = 0; i < itemCount; ++i)
    {
        if (items[i] -> getId() == id)
        {
            delete items[i];
            // Shift remaining pointers
            for (std::size_t j = i; j < itemCount - 1; ++j)
            {
                items[j] = items[j + 1];
            }
            // Optional: set last pointer to nullptr, if the item is not the last one in the array.
            if (i < itemCount - 1)
            {
                items[itemCount - 1] = nullptr;
            }
            itemCount--;
        }
    }

    std::cout << "Item with ID " << id << " is now removed." << std::endl;
    return true;
}