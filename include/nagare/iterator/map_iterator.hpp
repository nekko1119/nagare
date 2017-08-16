#ifndef NAGARE_ITERATOR_MAP_ITERATOR_HPP
#define NAGARE_ITERATOR_MAP_ITERATOR_HPP

#include <nagare/config.hpp>
#include <iterator>
#include <memory>
#include <type_traits>

namespace nagare {
    template <typename Iterator, typename F>
    class map_iterator
    {
    public:
        using iterator_category = std::input_iterator_tag;
        using reference         = typename std::result_of<F(
            typename std::iterator_traits<Iterator>::reference)>::type;
        using difference_type = std::ptrdiff_t;
        using value_type      = typename std::remove_reference<reference>::type;
        using pointer         = value_type*;

    private:
        Iterator iterator_;
        F f_;

        // Input iterators are required to have operator->() by the standard.
        // We need to hold a current value because operator->() should return
        // pointer to lvalue.
        mutable value_type current_;

    public:
        constexpr map_iterator(Iterator iterator, F f)
            : iterator_{iterator}, f_{f}, current_{}
        {
        }

        NAGARE_CXX14_CONSTEXPR reference operator*() const
        {
            current_ = f_(*iterator_);
            return current_;
        }

        NAGARE_CXX14_CONSTEXPR map_iterator& operator++()
        {
            ++iterator_;
            return *this;
        }

        NAGARE_CXX14_CONSTEXPR map_iterator const operator++(int)
        {
            auto temp = *this;
            ++(*this);
            return temp;
        }

        constexpr pointer operator->() const noexcept
        {
            return std::addressof(current_);
        }

        constexpr bool operator==(map_iterator const& right) const
        {
            return iterator_ == right.iterator_;
        }

        constexpr bool operator!=(map_iterator const& right) const
        {
            return !(*this == right);
        }
    };

    template <typename Iterator, typename F>
    map_iterator<Iterator, F> make_map_iterator(Iterator iterator, F f)
    {
        return map_iterator<Iterator, F>(iterator, f);
    }
}

#endif
