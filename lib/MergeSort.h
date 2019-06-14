#pragma once

#include <iterator>
#include <vector>
#include "Util.h"

class MergeSort
{
public:

  MergeSort() = delete;

  template <typename Itr>
  static auto sort(const Itr& begin_, const Itr& end_) ->
  std::enable_if_t</*is_random_access_itr<Itr>*/ true, void>
  {
    auto size = std::distance(begin_, end_);
    if (size <= 0) return;

    using valType = typename std::iterator_traits<Itr>::value_type;
    std::vector<valType> auxVec(size);
    sortImplIncl(begin_, 0, size - 1, auxVec);
  }

private:
  template <typename Itr, typename ValType = typename std::iterator_traits<Itr>::value_type>
  static void sortImplIncl(const Itr& begin_, size_t lo_, size_t hi_, std::vector<ValType>& aux_)
  {
    if (lo_ >= hi_) return;

    size_t mid = lo_ + (hi_ - lo_) / 2;

    sortImplIncl(begin_, lo_, mid, aux_);
    sortImplIncl(begin_, mid + 1, hi_, aux_);
    mergeIncl(begin_, lo_, mid, hi_, aux_);
  }

  template <typename Itr, typename ValType = typename std::iterator_traits<Itr>::value_type>
  static void mergeIncl(const Itr& begin_, size_t lo_, size_t mid_, size_t hi_, std::vector<ValType>& aux_)
  {
    // merge [lo..mid] and [mid+1..hi]
    size_t i = lo_, j = mid_ + 1;

    std::copy(std::next(begin_, lo_), std::next(begin_, hi_ + 1), std::next(std::begin(aux_), lo_));

    for (size_t index = lo_; index <= hi_; ++index)
    {
      auto& target  = at(begin_, index);

      if      (i > mid_)          target = aux_[j++];
      else if (j > hi_)           target = aux_[i++];
      else if (aux_[i] < aux_[j]) target = aux_[i++];
      else                        target = aux_[j++];
    }
  }
};