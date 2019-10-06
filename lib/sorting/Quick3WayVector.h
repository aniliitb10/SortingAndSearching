#pragma once

#include <iterator>
#include <cstddef>
#include <vector>
#include <algorithm>

// This is general and is not exploiting std::string
class Quick3WayVector
{
public:
  using List = std::vector<std::string>;

  static void sort(List& list_)
  {
    sort(list_, 0, list_.size() - 1);
    /*if (!std::is_sorted(std::begin(list_), std::end(list_)))
    {
      throw std::runtime_error("Still not sorted!");
    }*/
  }

private:
  static void sort(List& list_, const size_t lo_, const size_t hi_)
  {
    static constexpr size_t max_hi = std::numeric_limits<size_t>::max();
    if (hi_ <= lo_ || hi_ == max_hi) return;

    size_t lt = lo_, gt = hi_, i = lo_ + 1;
    const std::string value = list_[lo_];

    while (i <= gt)
    {
      if      (list_[i] < value) std::swap(list_[i++], list_[lt++]);
      else if (list_[i] > value) std::swap(list_[i], list_[gt--]);
      else                       i++;
    }

    sort(list_, lo_, lt-1);
    sort(list_, gt+1, hi_);
  }
};