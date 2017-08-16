#ifndef NAGARE_STREAM_HPP
#define NAGARE_STREAM_HPP

#include <nagare/config.hpp>

namespace nagare {

    template <typename Iterator>
    class stream
    {
        Iterator begin_;
        Iterator end_;

    public:
        constexpr stream(Iterator begin, Iterator end)
            : begin_{begin}, end_{end}
        {
        }

        NAGARE_CXX14_CONSTEXPR Iterator begin()
        {
            return begin_;
        }

        constexpr Iterator begin() const
        {
            return begin_;
        }

        NAGARE_CXX14_CONSTEXPR Iterator end()
        {
            return end_;
        }

        constexpr Iterator end() const
        {
            return end_;
        }

        template <typename F>
        void each(F f)
        {
            for (auto it = begin_; it != end_; ++it) {
                f(*it);
            }
        }
    };
}

#endif
