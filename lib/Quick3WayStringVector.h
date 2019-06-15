#pragma once

#include <vector>
#include <string>

class Quick3WayStringVector
{
public:
  using List = std::vector<std::string>;

  static void sort(List& list_)
  {
    sort(list_, 0, list_.size() - 1, 0);
    /*if (!std::is_sorted(std::begin(list_), std::end(list_)))
    {
      throw std::runtime_error("Still not sorted!");
    }*/
  }

private:
  static int getChar(const std::string& str_, const size_t pos_)
  {
    return (pos_ < str_.size()) ? str_.at(pos_) : -1;
  }

  static void sort(List& list_, const size_t lo_, const size_t hi_, const size_t d_)
  {
    static constexpr size_t max_hi = std::numeric_limits<size_t>::max();
    if (hi_ <= lo_ || hi_ == max_hi) return;

    size_t i = lo_ + 1, lt = lo_, gt = hi_;
    const int value = getChar(list_[lo_], d_);

    while(i <= gt)
    {
      const int cmp =   getChar(list_[i], d_) - value;
      if (cmp < 0)      std::swap(list_[i++], list_[lt++]);
      else if (cmp > 0) std::swap(list_[i], list_[gt--]);
      else              i++;
    }

    sort(list_, lo_, lt -1, d_);
    if (value >= 0) sort(list_, lt, gt, d_ + 1);
    sort(list_, gt + 1, hi_,  d_);
  }
};