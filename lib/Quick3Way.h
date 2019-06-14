#pragma once

class Quick3Way
{
public:
  Quick3Way() = delete;

  template <typename Itr>
  static void sort(const Itr& begin_, const Itr& end_)
  {
    auto size = std::distance(begin_, end_);
    sortImpl(begin_, static_cast<decltype(size)>(0), size-1);
  }

private:
  template <typename Itr, typename SizeType = typename std::iterator_traits<Itr>::difference_type>
  static void sortImpl(const Itr& begin_, SizeType lo_, SizeType hi_)
  {
    if (lo_ >= hi_) return;

    SizeType lt = lo_;
    SizeType gt = hi_;
    SizeType index = lo_ + 1;
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
    assert(isSorted(std::next(begin_, lo_), std::next(begin_, hi_)));
  }
};