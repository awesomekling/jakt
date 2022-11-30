#include <lib.h>

int main(int argc, char** argv)
{
    auto args = MUST(Jakt::Array<Jakt::String>::create_empty());
    for (int i = 0; i < argc; ++i) {
        MUST(args.push(MUST(Jakt::String::copy(Jakt::StringView(argv[i], strlen(argv[i]))))));
    }
    auto result = Jakt::main(move(args));
    if (result.is_error()) {
        warnln("Runtime error: {}", result.error());
        return 1;
    }
    return result.value();
}
