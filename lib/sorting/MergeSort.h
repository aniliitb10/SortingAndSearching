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

    std::vector<ItrValueType<Itr>> auxVec(size);
    sortImplIncl(begin_, static_cast<decltype(size)>(0), size - 1, auxVec);
  }

private:
  template <typename Itr, typename DiffType = ItrDiffType<Itr>, typename ValType = ItrValueType<Itr>>
  static void sortImplIncl(const Itr& begin_, DiffType lo_, DiffType hi_, std::vector<ValType>& aux_)
  {
    if (lo_ >= hi_) return;

    auto mid = lo_ + (hi_ - lo_) / 2;

    sortImplIncl(begin_, lo_, mid, aux_);
    sortImplIncl(begin_, mid + 1, hi_, aux_);
    mergeIncl(begin_, lo_, mid, hi_, aux_);
  }

  template <typename Itr, typename DiffType = ItrDiffType<Itr>, typename ValType = ItrValueType<Itr>>
  static void mergeIncl(const Itr& begin_, DiffType lo_, DiffType mid_, DiffType hi_, std::vector<ValType>& aux_)
  {
    // merge [lo..mid] and [mid+1..hi]
    auto leftBegin = lo_, rightBegin = mid_ + 1;

    std::move(std::next(begin_, lo_), std::next(begin_, hi_ + 1), std::next(std::begin(aux_), lo_));

    for (auto index = lo_; index <= hi_; ++index)
    {
      auto& target  = at(begin_, index);

      if      (leftBegin > mid_)  target = std::move(aux_[rightBegin++]);
      else if (rightBegin > hi_)  target = std::move(aux_[leftBegin++]);
      else if (aux_[leftBegin] < aux_[rightBegin]) target = std::move(aux_[leftBegin++]); // keeps it stable
      else                        target = std::move(aux_[rightBegin++]);
    }
  }
};