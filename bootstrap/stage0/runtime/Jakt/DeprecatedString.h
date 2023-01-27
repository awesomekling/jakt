#include <Jakt/AKIntegration.h>

#include <AK/CheckedFormatString.h>
#include <AK/DeprecatedString.h>
#include <AK/Utf8View.h>

namespace Jakt {
template<typename... Ts>
inline ErrorOr<DeprecatedString> __jakt_format(CheckedFormatString<Ts...> fmt, Ts const&... args)
{
    return DeprecatedString::formatted(fmt.view(), args...);
}

inline DeprecatedString operator+(DeprecatedString const& a, DeprecatedString const& b)
{
    return DeprecatedString::formatted("{}{}", a, b);
}

inline DeprecatedString& operator+=(DeprecatedString& a, DeprecatedString const& b)
{
    auto result = DeprecatedString::formatted("{}{}", a, b);
    *bit_cast<RefPtr<StringImpl>*>(&a) = result.impl(); // I'm sorry.
    return a;
}
}
