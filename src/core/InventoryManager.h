#pragma once
#include "InventoryItem.h"

/**
 * @class InventoryManager
 * @brief Manages a collection of inventory items
 *
 * This class is responsible for maintaining a collection of InventoryItem objects.
 * It demonstrates the use of pointers for dynamic memory management in an
 * object-oriented context.
 */
class InventoryManager 
{
private:
    InventoryItem **items; // Array of pointers to InventoryItem objects
    std::size_t capacity;  // Maximum number of items the manager can hold
    std::size_t itemCount; // Current number of items in the manager
public:
    /**
     * @brief Constructor - initializes the inventory manager with a given capacity
     * @param capacity The maximum number of items the manager can hold
     */
    explicit InventoryManager(std::size_t capacity);

    /**
     * @brief Destructor - responsible for cleaning up dynamically allocated memory
     */
    ~InventoryManager();

    /**
     * @brief Get an item by its ID
     * @param id The ID of the item to retrieve
     * @return Pointer to the found item, or nullptr if not found
     */
    InventoryItem *getItemById(int id);

    /**
     * @brief Display all items in the inventory
     */
    void displayAllItems() const;

    /**
     * @brief Get the current number of items in the inventory
     * @return The item count
     */
    std::size_t getItemCount() const;

    /**
     * @brief Search for an item by name
     * @param name The name to search for
     * @return Pointer to the first matching item, or nullptr if not found
     */
    InventoryItem *searchByName(const std::string &name) const;
    
    /**
     * @brief Find and display item by name
     * @param name The name to search from inventory and display
     */
    void displayByName(const std::string& name) const;

    /**
     * @brief Add a new item to the inventory
     * @param id The ID of the new item
     * @param name The name of the new item
     * @param quantity The quantity of the new item
     * @return true if the item was added successfully, false otherwise
     */
    bool addItem(int id, const std::string &name, int quantity);

    /**
     * @brief Update an item's properties
     * @param id The ID of the item to update
     * @param newName The new name (empty string to keep current name)
     * @param newQuantity The new quantity (-1 to keep current quantity)
     * @return true if the update was successful, false otherwise
     */
    bool updateItem(int id, const std::string &newName, int newQuantity);

    /**
     * @brief Remove an item from the inventory by ID
     * @param id The ID of the item to remove
     * @return true if the item was removed successfully, false otherwise
     */
    bool removeItem(int id);
};