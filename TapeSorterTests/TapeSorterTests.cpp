#include <gtest/gtest.h>
#include "../TapeSorter/TapeSorter.h"
#include "MockTape.h"
#include <algorithm>
#include <random>
#include <filesystem>

class TapeSorterTest : public ::testing::Test {
protected:
    void SetUp() override {
        std::filesystem::create_directories("tmp");
    }

    void TearDown() override {
        std::filesystem::remove_all("tmp");
    }

    bool isSorted(const std::vector<int>& data) {
        return std::is_sorted(data.begin(), data.end());
    }

    std::vector<int> generateRandomData(size_t size, int min_val = -1000, int max_val = 1000) {
        std::vector<int> data(size);
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<int> dist(min_val, max_val);
        
        for (size_t i = 0; i < size; ++i) {
            data[i] = dist(gen);
        }
        return data;
    }
};

TEST_F(TapeSorterTest, EmptyArray) {
    MockTape input;
    MockTape output;
    TapeSorter sorter(1024);
    
    sorter.sort(input, output);
    
    EXPECT_TRUE(output.getData().empty());
}

TEST_F(TapeSorterTest, SingleElement) {
    MockTape input({42});
    MockTape output;
    TapeSorter sorter(1024);
    
    sorter.sort(input, output);
    
    ASSERT_EQ(output.getData().size(), 1);
    EXPECT_EQ(output.getData()[0], 42);
}

TEST_F(TapeSorterTest, AlreadySorted) {
    std::vector<int> data = {1, 2, 3, 4, 5};
    MockTape input(data);
    MockTape output;
    TapeSorter sorter(1024);
    
    sorter.sort(input, output);
    
    ASSERT_EQ(output.getData().size(), data.size());
    EXPECT_TRUE(isSorted(output.getData()));
    EXPECT_EQ(output.getData(), data);
}

TEST_F(TapeSorterTest, ReverseSorted) {
    std::vector<int> data = {5, 4, 3, 2, 1};
    MockTape input(data);
    MockTape output;
    TapeSorter sorter(1024);
    
    sorter.sort(input, output);
    
    ASSERT_EQ(output.getData().size(), data.size());
    EXPECT_TRUE(isSorted(output.getData()));
}

TEST_F(TapeSorterTest, RandomArray) {
    auto data = generateRandomData(1000);
    MockTape input(data);
    MockTape output;
    TapeSorter sorter(1024);
    
    sorter.sort(input, output);
    
    ASSERT_EQ(output.getData().size(), data.size());
    EXPECT_TRUE(isSorted(output.getData()));
}

TEST_F(TapeSorterTest, DuplicateElements) {
    std::vector<int> data = {3, 1, 4, 1, 5, 9, 2, 6, 5, 3, 5};
    MockTape input(data);
    MockTape output;
    TapeSorter sorter(1024);
    
    sorter.sort(input, output);
    
    ASSERT_EQ(output.getData().size(), data.size());
    EXPECT_TRUE(isSorted(output.getData()));
}

TEST_F(TapeSorterTest, DifferentMemorySizes) {
    auto data = generateRandomData(1000);
    MockTape input(data);
    MockTape output;
    
    std::vector<size_t> memory_sizes = {64, 128, 256, 512, 1024};
    for (size_t memory_size : memory_sizes) {
        TapeSorter sorter(memory_size);
        input.setData(data);
        output.setData({});
        
        sorter.sort(input, output);
        
        ASSERT_EQ(output.getData().size(), data.size());
        EXPECT_TRUE(isSorted(output.getData()));
    }
}

TEST_F(TapeSorterTest, LargeArray) {
    auto data = generateRandomData(10000);
    MockTape input(data);
    MockTape output;
    TapeSorter sorter(1024);
    
    sorter.sort(input, output);
    
    ASSERT_EQ(output.getData().size(), data.size());
    EXPECT_TRUE(isSorted(output.getData()));
}

TEST_F(TapeSorterTest, NegativeNumbers) {
    auto data = generateRandomData(1000, -1000, 1000);
    MockTape input(data);
    MockTape output;
    TapeSorter sorter(1024);
    
    sorter.sort(input, output);
    
    ASSERT_EQ(output.getData().size(), data.size());
    EXPECT_TRUE(isSorted(output.getData()));
} 