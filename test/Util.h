#include <iostream>
#include <vector>
#include <fstream>
#include <random>
#include <numeric>
#include <type_traits>

#include "../lib/sorting/Util.h"

using List = std::vector<std::string>;

struct Util
{
  template <typename type = std::string>
  auto static readFile(const std::string& fileName_) -> std::vector<type>
  {
    std::ifstream fileHandle(fileName_, std::ios::in);
    if (!fileHandle.good()) throw std::runtime_error("Couldn't open file: " + fileName_);

    std::vector<type> values;
    for (std::string line; std::getline(fileHandle, line);)
    {
      if constexpr (std::is_same_v<std::decay_t<type>, size_t>)
      {
        values.push_back(std::stoul(line));
      }
      else
      {
        values.push_back(std::move(line));
      }
    }

    return values;
  }

  template <typename Itr>
  void static writeToFile(Itr begin, Itr end, const std::string& fileName)
  {
    std::ofstream fileHandle{fileName, std::ios::out|std::ios::trunc};
    if (!fileHandle.good()) throw std::runtime_error{"Couldn't open the file: " + fileName};

    for (; begin != end; ++begin) {
      fileHandle << (*begin) << "\n";
    }
  }

  template <typename OItr, typename ValueType = ItrValueType<OItr>>
  static void randomNumGenerator(OItr oItr_, size_t count_, ValueType from_, ValueType end_)
  {
    std::random_device seed{};
    std::mt19937 engine{seed()};
    std::uniform_int_distribution<ValueType> dist{from_, end_};

    for (size_t index = 0; index < count_; ++index)
    {
      oItr_ = dist(engine);
    }
  }

  static std::vector<size_t> getRandomNumbers(size_t count, size_t min, size_t max)
  {
    std::vector<size_t> numbers{};
    randomNumGenerator(std::back_inserter(numbers), count, min, max);
    /*writeToFile(std::cbegin(numbers), std::cend(numbers),
      "../test/" + std::to_string(count)+ "numbers" + std::to_string(min) + "To" + std::to_string(max) + ".txt");*/

    return numbers;
  }

};

