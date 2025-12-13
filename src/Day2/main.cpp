/**
 * @copyright Copyright (c) 2025 eggebee6
 *
 * @file main.cpp
 *
 * @brief Advent of Code 2025, Day 2
 */

#include "InputReader.hpp"
#include "ProductId.hpp"
#include "Range.hpp"

#include <cstdlib>
#include <iostream>

int main()
{
  try
  {
    InputReader reader{"Input.txt"};

    auto ranges = reader.ReadRanges();

    unsigned long long total = 0;
    for (const auto& range : ranges)
    {
      // Display range
      std::cout << range.GetFirstId() << " - " << range.GetLastId() << std::endl;

      // Get invalid IDs in range
      auto invalidIds = ProductId::GenerateInvalidIds(range.GetFirstId(), range.GetLastId());
      for (const auto& id : invalidIds)
      {
        // Display invalid ID
        std::cout << "  " << id << std::endl;

        try
        {
          // Add ID to total
          total += std::stoull(id);
        }
        catch (const std::exception& ex)
        {
          std::cerr << "Failed to convert ID to integer:  " << id << std::endl;
          throw;
        }
      }
    }

    // Display total
    std::cout << "Total:  " << total << std::endl;

    return EXIT_SUCCESS;
  }
  catch (const std::exception& ex)
  {
    std::cerr << "Failed due to unhandled exception:  " << ex.what() << std::endl;

    return EXIT_FAILURE;
  }
}
