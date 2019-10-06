#pragma once

#include <random>

#include "Util.h"

class Quick3Way
{
public:
  Quick3Way() = delete;

  template <typename Itr>
  static void sort(const Itr& begin_, const Itr& end_)
  {
    // Shuffling to ensure competitive performance even with sorted list
    std::random_device rd{};
    std::mt19937_64 engine{rd()};
    std::shuffle(begin_, end_, engine);

    auto size = std::distance(begin_, end_);
    sortImpl(begin_, static_cast<decltype(size)>(0), size-1);
  }

private:
  template <typename Itr, typename DiffType = ItrDiffType<Itr>>
  static void sortImpl(const Itr& begin_, DiffType lo_, DiffType hi_)
  {
    if (lo_ >= hi_) return;

    auto lt = lo_;
    auto gt = hi_;
    auto index = lo_ + 1;
    const auto v = at(begin_, lo_);

    while(index <= gt)
    {
      const auto& ai = at(begin_, index);

      if      (ai < v) std::swap(at(begin_, index++), at(begin_, lt++));
      else if (v < ai) std::swap(at(begin_, index), at(begin_, gt--));
      else             index++;
    }

    sortImpl(begin_, lo_, lt-1);
    sortImpl(begin_, gt+1, hi_);
  }
};