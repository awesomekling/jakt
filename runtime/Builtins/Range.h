#include <Jakt/Optional.h>

namespace JaktInternal {
using namespace Jakt;

template<typename T>
struct Range {
    using IndexType = T;
    T start {};
    T end {};
    T current {};
    bool forwards { true };
    bool is_inclusive { false };
    bool has_reached_end { false };

    Range(T start, T end, bool inclusive = false)
        : start(start)
        , end(end)
        , current(start)
        , is_inclusive(inclusive)
    {
        normalize();
    }

    Optional<T> next()
    {
        if (current == end) {
            if (is_inclusive) {
                if (has_reached_end)
                    return {};
                has_reached_end = true;
                return end;
            }

            return {};
        }

        if (forwards)
            return current++;

        return current--;
    }

    Range inclusive()
    {
        return Range { start, end, true };
    }

    Range exclusive()
    {
        return Range { start, end, false };
    }

private:
    void normalize()
    {
        if (start > end)
            forwards = false;
    }
};

}
