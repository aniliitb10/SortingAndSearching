#pragma once

class QuickSort
{
public:
  QuickSort() = delete;

  template <typename Itr>
  static void sort(const Itr& begin_, const Itr& end_)
  {
    size_t size = std::distance(begin_, end_);
    sortImpl(begin_, 0, size-1);
  }

private:
  template <typename Itr>
  static void sortImpl(const Itr& begin_, size_t lo_, size_t hi_)
  {
    if (lo_ >= hi_) return;

    size_t pi = partition(begin_, lo_, hi_);
    sortImpl(begin_, lo_, pi-1);
    sortImpl(begin_, pi+1, hi_);
  }

  template <typename Itr>
  static size_t partition(const Itr& begin_, size_t lo_, size_t hi_)
  {
    size_t i = lo_;
    size_t j = hi_ + 1;
    const typename std::iterator_traits<Itr>::reference v = at(begin_, lo_);

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