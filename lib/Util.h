#include <iterator>

template <typename Itr>
constexpr bool is_random_access_itr = std::is_same_v<std::iterator_traits<Itr>::iterator_category,std::random_access_iterator_tag>;

template <typename Itr>
static decltype(auto) at(const Itr& itr, size_t index_)
{
  return *std::next(itr, index_);
}