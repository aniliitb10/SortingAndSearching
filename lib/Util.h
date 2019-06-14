#include <iterator>
#include <iostream>

template <typename Itr>
constexpr bool is_random_access_itr = std::is_same_v<std::iterator_traits<Itr>::iterator_category,std::random_access_iterator_tag>;

template <typename Itr>
static decltype(auto) at(const Itr& itr, size_t index_)
{
  return *std::next(itr, index_);
}

template <typename Itr>
static bool isSorted(const Itr& begin_, const Itr& end_)
{
  Itr current = begin_;
  Itr next = std::next(begin_);
  while (next != end_)
  {
    if (*(current++) > *(next++))
    {
      return false;
    }
  }

  return true;
}

template <typename Itr>
static void print(Itr begin_, Itr end_)
{
  while(begin_ != end_)
  {
    std::cout << *(begin_++) << " ";
  }
  std::cout << *end_ << std::endl;
}