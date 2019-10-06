#pragma once

#include <random>

#include "Util.h"
#include "InsertionSort.h"

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
    static constexpr DiffType INSERTION_SORT_CUTOFF = 16;

    if (lo_ >= hi_) return;

    if ((hi_-lo_) <= INSERTION_SORT_CUTOFF)
    {
      InsertionSort::sort(std::next(begin_, lo_), std::next(begin_, hi_ + 1));
      return;
    }

    auto pi = partition(begin_, lo_, hi_);
    sortImpl(begin_, lo_, pi-1);
    sortImpl(begin_, pi+1, hi_);
  }

  template <typename Itr, typename DiffType = ItrDiffType<Itr>>
  static DiffType partition(const Itr& begin_, DiffType lo_, DiffType hi_)
  {
    auto i = lo_;
    auto j = hi_ + 1;
    const auto v = at(begin_, lo_); // must not be reference

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