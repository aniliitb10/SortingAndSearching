#pragma once

#include <random>

#include "Util.h"

class QuickSort
{
public:
  QuickSort() = delete;

  template <typename Itr>
  static void sort(const Itr& begin_, const Itr& end_)
  {
    // Shuffling to ensure competitive performance even with sorted list
    std::random_device rd{};
    std::mt19937_64 engine{rd()};
    std::shuffle(begin_, end_, engine);

    auto size {std::distance(begin_, end_)};
    sortImpl(begin_, static_cast<decltype(size)>(0), size-1);
  }

private:
  template <typename Itr, typename DiffType = ItrDiffType<Itr>>
  static void sortImpl(const Itr& begin_, DiffType lo_, DiffType hi_)
  {
    if (lo_ >= hi_) return;

    auto pi = partition(begin_, lo_, hi_);
    sortImpl(begin_, lo_, pi-1);
    sortImpl(begin_, pi+1, hi_);
  }

  template <typename Itr, typename DiffType = ItrDiffType<Itr>>
  static DiffType partition(const Itr& begin_, const DiffType lo_, const DiffType hi_)
  {

    // Some comments on the values of i and j
    // i is initialized with lo_ but that value is never used in the while loop
    // - while loop starts from ++i => hence, effectively, while loop runs with i = lo_+1
    // - which is okay and expected, because the value at lo_ is used as the pivot
    // Similarly, j is initialized with hi_+1 but while loop runs with --j
    // - Hence, effectively, while loop runs with j = hi_
    // So, with these non-intuitive initializations:
    // - value at lo_ is used as pivot
    // - while loop runs for [lo_+1, hi_]

    auto i = lo_;
    auto j = hi_ + 1;
    const auto v = at(begin_, lo_); // must not be referenced

    while(true)
    {
      while(at(begin_, ++i) < v)
      {
        if (i == hi_) break;
      }

      while(v < at(begin_, --j))
      {
        if (j == lo_) break; // redundant
      }

      if (i >= j) break;
      std::swap(at(begin_, i), at(begin_, j));
    }

    std::swap(at(begin_, lo_), at(begin_, j));
    return j;
  }
};