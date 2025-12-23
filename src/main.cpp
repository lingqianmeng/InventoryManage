#include <iostream>
#include "InventoryManager.h"
#include "InventoryItem.h"

int main()
{
    std::cout << " --- Inventory Management System --- " << std::endl;

    // Create an InventoryManager with a capacity of 10 items
    InventoryManager managerHygie(10);
    // Add some items to the inventory
    managerHygie.addItem(101, "Tisse", 5);
    managerHygie.addItem(102, "Toilet Paper", 10);
    managerHygie.addItem(103, "Moist Toilet Paper", 3);
    managerHygie.addItem(104, "Toothpaste", 7);
    // Display all items
    managerHygie.displayAllItems();
    // Update an item
    managerHygie.updateItem(102, "Premium Toilet Paper", 15);
    // Display all items again
    managerHygie.displayAllItems();
    // Remove an item
    managerHygie.removeItem(103);
    // Display all items again
    managerHygie.displayAllItems();
    // Display item by name
    managerHygie.displayByName("Toothpaste"); // Existing item
    managerHygie.displayByName("Toothbrash"); // Non-existing item
    // Get item count
    std::cout << "Total items in inventory: " << managerHygie.getItemCount() << std::endl;
    // Program end
    // The InventoryManager destructor will be called automatically here
    // cleaning up all dynamically allocated memory
    // End of program
    // Return success
    return 0;
}