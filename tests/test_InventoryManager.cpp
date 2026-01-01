#include <gtest/gtest.h>
#include "../src/core/InventoryItem.h"   // Include your actual headers
#include "../src/core/InventoryManager.h"

class InventoryManagerTests : public ::testing::Test {
protected:
    std::unique_ptr<InventoryManager> Invmptr;
    void SetUp() override {
        // Code here will be called immediately after the constructor (right before each test).
        Invmptr = std::make_unique<InventoryManager>(5);
    }

    void TearDown() override {
        // Code here will be called immediately after each test (right before the destructor).
        Invmptr.reset();
    }
};

TEST_F(InventoryManagerTests, CheckInventoryManagerCreation) {
    EXPECT_EQ(Invmptr->getItemCount(), 0);
    Invmptr->addItem(101, "Mouse", 50);
    EXPECT_EQ(Invmptr->getItemCount(), 1);
}

TEST_F(InventoryManagerTests, CheckAddItemExceedCapacity) {
    EXPECT_TRUE(Invmptr->addItem(101, "Item1", 10));
    EXPECT_TRUE(Invmptr->addItem(102, "Item2", 20));
    EXPECT_TRUE(Invmptr->addItem(103, "Item3", 30));
    EXPECT_TRUE(Invmptr->addItem(104, "Item4", 40));
    EXPECT_TRUE(Invmptr->addItem(105, "Item5", 50));
    // This addition should fail as it exceeds capacity
    EXPECT_FALSE(Invmptr->addItem(106, "Item6", 60));
    EXPECT_EQ(Invmptr->getItemCount(), 5);
}

TEST_F(InventoryManagerTests, CheckAddItemDuplicateID) {
    EXPECT_TRUE(Invmptr->addItem(101, "Item1", 10));
    // This addition should fail as ID 101 already exists
    EXPECT_FALSE(Invmptr->addItem(101, "ItemDuplicate", 20));
    EXPECT_EQ(Invmptr->getItemCount(), 1);
}

TEST_F(InventoryManagerTests, CheckGetItemById) {
    Invmptr->addItem(101, "Keyboard", 15);
    InventoryItem* item = Invmptr->getItemById(101);
    ASSERT_NE(item, nullptr);
    EXPECT_EQ(item->getName(), "Keyboard");
    EXPECT_EQ(item->getQuantity(), 15);

    // Test for non-existing ID
    EXPECT_EQ(Invmptr->getItemById(999), nullptr);
}

TEST_F(InventoryManagerTests, CheckRemoveItem) {
    Invmptr->addItem(101, "Monitor", 25);
    EXPECT_EQ(Invmptr->getItemCount(), 1);

    // Remove existing item
    EXPECT_TRUE(Invmptr->removeItem(101));
    EXPECT_EQ(Invmptr->getItemCount(), 0);

    // Attempt to remove non-existing item
    EXPECT_FALSE(Invmptr->removeItem(999));
}

TEST_F(InventoryManagerTests, CheckUpdateItem) {
    Invmptr->addItem(101, "Tablet", 30);

    // Update existing item
    EXPECT_TRUE(Invmptr->updateItem(101, "Updated Tablet", 35));
    InventoryItem* item = Invmptr->getItemById(101);
    ASSERT_NE(item, nullptr);
    EXPECT_EQ(item->getName(), "Updated Tablet");
    EXPECT_EQ(item->getQuantity(), 35);

    // Attempt to update non-existing item
    EXPECT_FALSE(Invmptr->updateItem(999, "NonExistent", 0));
}

TEST_F(InventoryManagerTests, CheckSearchByName) {
    Invmptr->addItem(101, "Webcam", 12);
    Invmptr->addItem(102, "Headset", 8);

    // Search for existing item
    InventoryItem* item = Invmptr->searchByName("Headset");
    ASSERT_NE(item, nullptr);
    EXPECT_EQ(item->getId(), 102);
    EXPECT_EQ(item->getQuantity(), 8);

    // Search for non-existing item
    EXPECT_EQ(Invmptr->searchByName("NonExistentItem"), nullptr);
}

TEST_F(InventoryManagerTests, CheckDisplayAllItems) {
    Invmptr->addItem(101, "Charger", 5);
    Invmptr->addItem(102, "Power Bank", 10);

    testing::internal::CaptureStdout();
    Invmptr->displayAllItems();
    std::string output = testing::internal::GetCapturedStdout();

    std::string expectedOutput = 
        "---Display On---\n"
        "Item ID: 101, Name: Charger, Quantity: 5\n"
        "Item ID: 102, Name: Power Bank, Quantity: 10\n"
        "---Display Off---\n";

    EXPECT_EQ(output, expectedOutput);
}

TEST_F(InventoryManagerTests, CheckGetItemCount) {
    EXPECT_EQ(Invmptr->getItemCount(), 0);
    Invmptr->addItem(101, "Item1", 10);
    EXPECT_EQ(Invmptr->getItemCount(), 1);
    Invmptr->addItem(102, "Item2", 20);
    EXPECT_EQ(Invmptr->getItemCount(), 2);
    Invmptr->removeItem(101);
    EXPECT_EQ(Invmptr->getItemCount(), 1);
}


TEST_F(InventoryManagerTests, CheckAddItemNegativeQuantity) {
    // Attempt to add item with negative quantity
    EXPECT_TRUE(Invmptr->addItem(101, "ItemNegative", -10));
    InventoryItem* item = Invmptr->getItemById(101);
    ASSERT_NE(item, nullptr);
    // Quantity should be set to 0
    EXPECT_EQ(item->getQuantity(), 0);
}


TEST_F(InventoryManagerTests, CheckUpdateItemNegativeQuantity) {
    Invmptr->addItem(101, "ItemToUpdate", 20);

    // Attempt to update item with negative quantity
    EXPECT_TRUE(Invmptr->updateItem(101, "ItemToUpdate", -5));
    InventoryItem* item = Invmptr->getItemById(101);
    ASSERT_NE(item, nullptr);
    // Quantity should remain unchanged
    EXPECT_EQ(item->getQuantity(), 20);
}

TEST_F(InventoryManagerTests, CheckDisplayAllItemsEmptyInventory) {
    testing::internal::CaptureStdout();
    Invmptr->displayAllItems();
    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_EQ(output, "---Display On---\nInventory is empty.\n");
}

TEST_F(InventoryManagerTests, CheckRemoveItemFromEmptyInventory) {
    // Attempt to remove item from empty inventory
    EXPECT_FALSE(Invmptr->removeItem(101));
}

TEST_F(InventoryManagerTests, CheckSearchByNameInEmptyInventory) {
    // Attempt to search for an item in empty inventory
    EXPECT_EQ(Invmptr->searchByName("NonExistent"), nullptr);
}

TEST_F(InventoryManagerTests, CheckGetItemByIdInEmptyInventory) {
    // Attempt to get an item by ID in empty inventory
    EXPECT_EQ(Invmptr->getItemById(101), nullptr);
}

TEST_F(InventoryManagerTests, CheckUpdateItemInEmptyInventory) {
    // Attempt to update an item in empty inventory
    EXPECT_FALSE(Invmptr->updateItem(101, "NonExistent", 10));
}


