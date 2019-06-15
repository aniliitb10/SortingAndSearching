#include <iostream>
#include <vector>
#include <fstream>
#include <random>

#include "../lib/Util.h"

using List = std::vector<std::string>;

struct Util
{
  List static readFile(const std::string& fileName_)
  {
    std::ifstream fileHandle(fileName_, std::ios::in);
    if (!fileHandle.good()) throw std::runtime_error("Couldn't open file: " + fileName_);

    List strings;
    for (std::string line; std::getline(fileHandle, line);)
    {
      strings.push_back(std::move(line));
    }

    return strings;
  }

  class RandomGen
  {
  public:
    explicit RandomGen(List list_):
    _words(std::move(list_))
    {
      std::shuffle(std::begin(_words), std::end(_words), g);
    }

    const List& getRandomizedList() const { return _words; }

  private:
    std::random_device rd;
    std::mt19937 g{rd()};
    List _words;
  };

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
};