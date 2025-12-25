#include <gtest/gtest.h>
#include "../src/core/InventoryItem.h"   // Include your actual headers
#include "../src/core/InventoryManager.h"

// Example Test 1: Testing the InventoryItem class
TEST(InventoryItemTests, CheckInventoryItemCreation) {
    InventoryItem p(1, "Laptop", 10);
    EXPECT_EQ(p.getId(), 1);
    EXPECT_EQ(p.getName(), "Laptop");
    EXPECT_EQ(p.getQuantity(), 10);
}

// Example Test 2: Testing InventoryManager Logic
TEST(InventoryManagerTests, CheckInventoryManagerCreation) {
    InventoryManager inv(5);
    inv.addItem(1, "Mouse", 50);
    EXPECT_EQ(inv.getItemCount(), 1);
}