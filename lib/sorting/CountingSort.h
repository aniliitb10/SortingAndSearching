#include <vector>
#include <type_traits>

class CountingSort {
public:
  CountingSort() = delete;

  template <typename Itr>
  static auto sort(Itr begin, Itr end, size_t max) -> std::enable_if_t<std::is_same_v<size_t,
                                                      typename std::iterator_traits<Itr>::value_type>> {
    std::vector<size_t> aux{begin, end};
    const size_t R = max+1; // [0, max] => max+1 elements
    std::vector<size_t> count(R+1, 0);

    // counting frequencies
    for (auto itr = begin; itr != end; ++itr) {
      count.at(*itr + 1)++; // this additional 1 is just to make the calculation easier
    }

    // assigning indices
    for (size_t r = 0; r < R; ++r) {
      count.at(r+1) += count.at(r);
    }

    // distributing values
    for (auto itr = begin; itr != end; ++itr) {
      aux.at(count.at(*itr)++) = *itr;
    }

    // copying back
    std::move(std::begin(aux), std::end(aux), begin);
  }
};