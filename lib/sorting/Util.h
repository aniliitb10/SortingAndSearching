#pragma once

#include <iterator>
#include <iostream>

template <typename Itr>
constexpr bool is_random_access_itr = std::is_same_v<typename std::iterator_traits<Itr>::iterator_category,std::random_access_iterator_tag>;

template <typename Itr>
using ItrDiffType = typename std::iterator_traits<Itr>::difference_type;

template <typename Itr>
using ItrValueType = typename std::iterator_traits<Itr>::value_type;

template <typename Itr, typename DiffType = ItrDiffType<Itr>>
inline static decltype(auto) at(const Itr& itr, DiffType index_)
{
  return *std::next(itr, index_);
}

template <typename Itr>
static void print(Itr begin_, Itr end_)
{
  while(begin_ != end_)
  {
    std::cout << *(begin_++) << " ";
  }
  std::cout << std::endl;
}

