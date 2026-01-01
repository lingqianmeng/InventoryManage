#include <gtest/gtest.h>
#include <memory>
#include <string>
#include "../src/core/InventoryItem.h"


class InventoryItemTests : public ::testing::Test {
protected:
    std::unique_ptr<InventoryItem> itemptr;
    void SetUp() override {
        // Code here will be called immediately after the constructor (right before each test).
        itemptr = std::make_unique<InventoryItem>(101, "Monitor", 20);
    }

    void TearDown() override {
        // Code here will be called immediately after each test (right before the destructor).
        // itemptr.reset();
    }
};

TEST_F(InventoryItemTests, CheckInventoryItemCreation) {
    EXPECT_EQ(itemptr->getId(), 101);
    EXPECT_EQ(itemptr->getName(), "Monitor");
    EXPECT_EQ(itemptr->getQuantity(), 20);
}

TEST_F(InventoryItemTests, CheckInventoryItemSetters) {
    itemptr->setName("Keyboard");
    itemptr->setQuantity(15);
    EXPECT_EQ(itemptr->getName(), "Keyboard");
    EXPECT_EQ(itemptr->getQuantity(), 15);
}

TEST_F(InventoryItemTests, CheckInventoryItemNegativeQuantity) {
    itemptr->setQuantity(-5);
    EXPECT_EQ(itemptr->getQuantity(), 20); // Quantity should remain unchanged
}

TEST_F(InventoryItemTests, CheckInventoryItemDisplay) {
    testing::internal::CaptureStdout();
    itemptr->display();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "Item ID: 101, Name: Monitor, Quantity: 20\n");
}
