#include "main.h"
namespace Jakt {
ErrorOr<void> format_output(jakt__path::Path const file_path,JaktInternal::DynamicArray<lexer::Token> const tokens,JaktInternal::Optional<FormatRange> const format_range,bool const format_debug,bool const format_inplace) {
{
DeprecatedStringBuilder formatted_file = TRY((DeprecatedStringBuilder::create()));
bool on_new_line = true;
{
formatter::Formatter _magic = TRY((formatter::Formatter::for_tokens(tokens,format_debug,static_cast<size_t>(120ULL))));
for (;;){
JaktInternal::Optional<JaktInternal::DynamicArray<formatter::FormattedToken>> _magic_value = TRY((((_magic).next())));
if ((!(((_magic_value).has_value())))){
break;
}
JaktInternal::DynamicArray<formatter::FormattedToken> formatted_line = (_magic_value.value());
{
{
JaktInternal::ArrayIterator<formatter::FormattedToken> _magic = ((formatted_line).iterator());
for (;;){
JaktInternal::Optional<formatter::FormattedToken> _magic_value = ((_magic).next());
if ((!(((_magic_value).has_value())))){
break;
}
formatter::FormattedToken formatted_token = (_magic_value.value());
{
if ((!(((((((formatted_token).token)).span())).is_in_offset_range((((format_range.value())).start),(((format_range.value())).end)))))){
continue;
}
{
JaktInternal::ArrayIterator<u8> _magic = ((((formatted_token).preceding_trivia)).iterator());
for (;;){
JaktInternal::Optional<u8> _magic_value = ((_magic).next());
if ((!(((_magic_value).has_value())))){
break;
}
u8 byte = (_magic_value.value());
{
TRY((((formatted_file).append(byte))));
}

}
}

JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_AT_LOOP(([&]() -> JaktInternal::ExplicitValueOrControlFlow<void, ErrorOr<void>>{
auto&& __jakt_match_variant = ((formatted_token).token);
switch(__jakt_match_variant.index()) {
case 56: {
auto&& __jakt_match_value = __jakt_match_variant.template get<lexer::Token::Eol>();JaktInternal::Optional<DeprecatedString> const& comment = __jakt_match_value.comment;
{
if (((comment).has_value())){
u8 next_char = ' ';
if (((((comment.value())).length()) != static_cast<size_t>(0ULL))){
(next_char = (((comment.value())).byte_at(static_cast<size_t>(0ULL))));
}
DeprecatedString const space = JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_AT_LOOP_NESTED_MATCH(([&]() -> JaktInternal::ExplicitValueOrControlFlow<DeprecatedString,ErrorOr<void>>{
auto __jakt_enum_value = (next_char);
if (__jakt_enum_value == ' ') {
return JaktInternal::ExplicitValue(Jakt::DeprecatedString(""sv));
}
else if (__jakt_enum_value == '\t') {
return JaktInternal::ExplicitValue(Jakt::DeprecatedString(""sv));
}
else if (__jakt_enum_value == '/') {
return JaktInternal::ExplicitValue(Jakt::DeprecatedString(""sv));
}
else {
return JaktInternal::ExplicitValue(Jakt::DeprecatedString(" "sv));
}
}()))
;
DeprecatedString const lhs_space = JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_AT_LOOP_NESTED_MATCH(([&]() -> JaktInternal::ExplicitValueOrControlFlow<DeprecatedString,ErrorOr<void>>{
auto __jakt_enum_value = (on_new_line);
if (__jakt_enum_value == true) {
return JaktInternal::ExplicitValue(TRY((indent(((formatted_token).indent)))));
}
else {
return JaktInternal::ExplicitValue(Jakt::DeprecatedString(" "sv));
}
}()))
;
TRY((((formatted_file).append_string(TRY((__jakt_format(Jakt::DeprecatedString("{}//{}{}"sv),lhs_space,space,(comment.value()))))))));
}
(on_new_line = true);
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 109: {
auto&& __jakt_match_value = __jakt_match_variant.template get<lexer::Token::Garbage>();JaktInternal::Optional<DeprecatedString> const& consumed = __jakt_match_value.consumed;
{
if (((consumed).has_value())){
TRY((((formatted_file).append_string(TRY((__jakt_format(Jakt::DeprecatedString("{}"sv),(consumed.value()))))))));
}
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
default: {
{
if (on_new_line){
TRY((((formatted_file).append_string(TRY((__jakt_format(Jakt::DeprecatedString("{}"sv),TRY((indent(((formatted_token).indent)))))))))));
}
TRY((((formatted_file).append_string(TRY((__jakt_format(Jakt::DeprecatedString("{}"sv),TRY((((formatted_token).token_text()))))))))));
(on_new_line = false);
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
}/*switch end*/
}()
));
{
JaktInternal::ArrayIterator<u8> _magic = ((((formatted_token).trailing_trivia)).iterator());
for (;;){
JaktInternal::Optional<u8> _magic_value = ((_magic).next());
if ((!(((_magic_value).has_value())))){
break;
}
u8 byte = (_magic_value.value());
{
TRY((((formatted_file).append_string(TRY((__jakt_format(Jakt::DeprecatedString("{:c}"sv),byte)))))));
}

}
}

if (((((formatted_token).token)).index() == 56 /* Eol */)){
TRY((((formatted_file).append_string(Jakt::DeprecatedString("\n"sv)))));
}
}

}
}

}

}
}

if (format_inplace){
TRY((utility::write_to_file(TRY((((formatted_file).to_string()))),((file_path).to_string()))));
}
else {
out(Jakt::DeprecatedString("{}"sv),TRY((((formatted_file).to_string()))));
}

}
return {};
}

ErrorOr<DeprecatedString> indent(size_t const level) {
{
DeprecatedString output = Jakt::DeprecatedString(""sv);
{
JaktInternal::Range<size_t> _magic = (JaktInternal::Range<size_t>{static_cast<size_t>(static_cast<size_t>(0ULL)),static_cast<size_t>(level)});
for (;;){
JaktInternal::Optional<size_t> _magic_value = ((_magic).next());
if ((!(((_magic_value).has_value())))){
break;
}
size_t i = (_magic_value.value());
{
(output += Jakt::DeprecatedString("    "sv));
}

}
}

return (output);
}
}

DeprecatedString help() {
{
DeprecatedString output = Jakt::DeprecatedString("Flags:\n"sv);
(output += Jakt::DeprecatedString("  -h,--help\t\t\t\tPrint this help and exit.\n"sv));
(output += Jakt::DeprecatedString("  -O\t\t\t\t\tBuild an optimized executable.\n"sv));
(output += Jakt::DeprecatedString("  -dl\t\t\t\t\tPrint debug info for the lexer.\n"sv));
(output += Jakt::DeprecatedString("  -dp\t\t\t\t\tPrint debug info for the parser.\n"sv));
(output += Jakt::DeprecatedString("  -dt\t\t\t\t\tPrint debug info for the typechecker.\n"sv));
(output += Jakt::DeprecatedString("  -S\t\t\t\t\tOnly output source (do not build).\n"sv));
(output += Jakt::DeprecatedString("  -T,--target-triple TARGET\t\tSpecify the target triple used for the build, defaults to native.\n"sv));
(output += Jakt::DeprecatedString("  --runtime-library-path PATH\t\tSpecify the path to the runtime library.\n"sv));
(output += Jakt::DeprecatedString("  -J,--jobs NUMBER\t\t\tSpecify the number of jobs to run in parallel, defaults to 2 (1 on windows).\n"sv));
(output += Jakt::DeprecatedString("  -cr, --compile-run\t\t\tBuild and run an executable file.\n"sv));
(output += Jakt::DeprecatedString("  -r, --run\t\t\t\tRun the given file without compiling it (all positional arguments after the file name will be passed to main).\n"sv));
(output += Jakt::DeprecatedString("  -d\t\t\t\t\tInsert debug statement spans in generated C++ code.\n"sv));
(output += Jakt::DeprecatedString("  --debug-print\t\t\t\tOutput debug print.\n"sv));
(output += Jakt::DeprecatedString("  -p --prettify-cpp-source\t\tRun emitted C++ source through clang-format.\n"sv));
(output += Jakt::DeprecatedString("  -S,--emit-cpp-source-only\t\tWrite the C++ source to file, even when not building.\n"sv));
(output += Jakt::DeprecatedString("  -c,--check-only\t\t\tOnly check the code for errors.\n"sv));
(output += Jakt::DeprecatedString("  -j,--json-errors\t\t\tEmit machine-readable (JSON) errors.\n"sv));
(output += Jakt::DeprecatedString("  -H,--type-hints\t\t\tEmit machine-readable type hints (for IDE integration).\n"sv));
(output += Jakt::DeprecatedString("  -f,--format\t\t\t\tFormat a file or directory and output the result.\n"sv));
(output += Jakt::DeprecatedString("  -fi,--format-inplace\t\t\t\tFormat a file or directory and save the result inplace.\n"sv));
(output += Jakt::DeprecatedString("  -fd,--format-debug\t\t\tOutput debug info for the formatter.\n"sv));
(output += Jakt::DeprecatedString("  -fr,--format-range\t\t\tEmit part of the document with formatting applied.\n"sv));
(output += Jakt::DeprecatedString("  --try-hints\t\t\t\tEmit machine-readable try hints (for IDE integration).\n"sv));
(output += Jakt::DeprecatedString("  --repl\t\t\t\tStart a Read-Eval-Print loop session.\n"sv));
(output += Jakt::DeprecatedString("  --print-symbols\t\t\tEmit a machine-readable (JSON) symbol tree.\n"sv));
(output += Jakt::DeprecatedString("\nOptions:\n"sv));
(output += Jakt::DeprecatedString("  -F,--clang-format-path PATH\t\tPath to clang-format executable.\n\t\t\t\t\tDefaults to clang-format\n"sv));
(output += Jakt::DeprecatedString("  -D,--dot-clang-format-path PATH\tPath to the .clang-format file to use.\n\t\t\t\t\tDefaults to none, invoking clangs default .clang-format file handling.\n"sv));
(output += Jakt::DeprecatedString("  -R,--runtime-path PATH\t\tPath of the Jakt runtime headers.\n\t\t\t\t\tDefaults to $PWD/runtime.\n"sv));
(output += Jakt::DeprecatedString("  -B,--binary-dir PATH\t\t\tOutput directory for compiled files.\n\t\t\t\t\tDefaults to $PWD/build.\n"sv));
(output += Jakt::DeprecatedString("  -C,--cxx-compiler-path PATH\t\tPath of the C++ compiler to use when compiling the generated sources.\n\t\t\t\t\tDefaults to clang++.\n"sv));
(output += Jakt::DeprecatedString("  -I PATH\t\t\t\tAdd PATH to compiler's include list. Can be specified multiple times.\n"sv));
(output += Jakt::DeprecatedString("  -L PATH\t\t\t\tAdd PATH to linker's search list. Can be specified multiple times.\n"sv));
(output += Jakt::DeprecatedString("  -l,--link-with LIB\t\t\tLink executable with LIB. Can be specified multiple times.\n"sv));
(output += Jakt::DeprecatedString("  -o,--output-filename FILE\t\tName of the output binary.\n\t\t\t\t\tDefaults to the input-filename without the extension.\n"sv));
(output += Jakt::DeprecatedString("  -g,--goto-def INDEX\t\t\tReturn the span for the definition at index.\n"sv));
(output += Jakt::DeprecatedString("  -t,--goto-type-def INDEX\t\tReturn the span for the type definition at index.\n"sv));
(output += Jakt::DeprecatedString("  -e,--hover INDEX\t\t\tReturn the type of element at index.\n"sv));
(output += Jakt::DeprecatedString("  -m,--completions INDEX\t\tReturn dot completions at index.\n"sv));
(output += Jakt::DeprecatedString("  --create NAME\t\tCreate sample project in $PWD/NAME\n"sv));
(output += Jakt::DeprecatedString("  --ak-is-my-only-stdlib\t\tForget about interop, AK is the one and only STL.\n"sv));
return (output);
}
}

DeprecatedString usage() {
{
return (Jakt::DeprecatedString("usage: jakt [-h] [OPTIONS] <filename>"sv));
}
}

ErrorOr<JaktInternal::Optional<FormatRange>> parse_format_range(DeprecatedString const range,size_t const input_file_length) {
{
JaktInternal::DynamicArray<DeprecatedString> const parts = ((range).split(':'));
if (((parts).is_empty())){
return (FormatRange(static_cast<size_t>(0ULL),input_file_length));
}
JaktInternal::Optional<u32> const start_input = ((((parts)[static_cast<i64>(0LL)])).to_uint());
if ((!(((start_input).has_value())))){
return (JaktInternal::OptionalNone());
}
size_t const start = (infallible_integer_cast<size_t>(((start_input.value()))));
size_t const end = JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<size_t,ErrorOr<JaktInternal::Optional<FormatRange>>>{
auto __jakt_enum_value = (((parts).size()));
if (__jakt_enum_value == static_cast<size_t>(1ULL)) {
return JaktInternal::ExplicitValue(input_file_length);
}
else if (__jakt_enum_value == static_cast<size_t>(2ULL)) {
return JaktInternal::ExplicitValue(({ Optional<size_t> __jakt_var_766; {
JaktInternal::Optional<u32> const end_input = ((((parts)[static_cast<i64>(1LL)])).to_uint());
if ((!(((end_input).has_value())))){
return (JaktInternal::OptionalNone());
}
__jakt_var_766 = (infallible_integer_cast<size_t>(((end_input.value())))); goto __jakt_label_687;

}
__jakt_label_687:; __jakt_var_766.release_value(); }));
}
else {
{
return (JaktInternal::OptionalNone());
}
}
}()))
;
return (FormatRange(start,end));
}
}

ErrorOr<int> main(JaktInternal::DynamicArray<DeprecatedString> const args) {


            #ifdef _WIN32
            SetConsoleOutputCP(CP_UTF8);
            // Enable buffering to prevent VS from chopping up UTF-8 byte sequences
            setvbuf(stdout, nullptr, _IOFBF, 1000);
            #endif
{
if ((((args).size()) <= static_cast<size_t>(1ULL))){
warnln(Jakt::DeprecatedString("{}"sv),usage());
return (static_cast<i64>(1LL));
}
jakt__arguments::ArgsParser args_parser = TRY((jakt__arguments::ArgsParser::from_args(args)));
if (TRY((((args_parser).flag((TRY((DynamicArray<DeprecatedString>::create_with({Jakt::DeprecatedString("-h"sv), Jakt::DeprecatedString("--help"sv)}))))))))){
outln(Jakt::DeprecatedString("{}\n"sv),usage());
outln(Jakt::DeprecatedString("{}"sv),help());
return (static_cast<i64>(0LL));
}
if (TRY((((args_parser).flag((TRY((DynamicArray<DeprecatedString>::create_with({Jakt::DeprecatedString("-v"sv), Jakt::DeprecatedString("--version"sv)}))))))))){
outln(Jakt::DeprecatedString("unreleased"sv));
return (static_cast<i64>(0LL));
}
jakt__path::Path const current_executable_path = TRY((jakt__path::Path::from_string(TRY((File::current_executable_path())))));
jakt__path::Path const install_base_path = TRY((((TRY((((current_executable_path).parent())))).parent())));
jakt__path::Path const default_runtime_path = TRY((((install_base_path).join(Jakt::DeprecatedString("include/runtime"sv)))));
jakt__path::Path const default_runtime_library_path = TRY((((install_base_path).join(Jakt::DeprecatedString("lib"sv)))));
DeprecatedString const default_compiler_path = JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<DeprecatedString,ErrorOr<int>>{
auto __jakt_enum_value = (false);
if (__jakt_enum_value == true) {
return JaktInternal::ExplicitValue(Jakt::DeprecatedString("clang-cl"sv));
}
else {
return JaktInternal::ExplicitValue(Jakt::DeprecatedString("clang++"sv));
}
}()))
;
bool const optimize = TRY((((args_parser).flag((TRY((DynamicArray<DeprecatedString>::create_with({Jakt::DeprecatedString("-O"sv)}))))))));
bool const lexer_debug = TRY((((args_parser).flag((TRY((DynamicArray<DeprecatedString>::create_with({Jakt::DeprecatedString("-dl"sv)}))))))));
bool const parser_debug = TRY((((args_parser).flag((TRY((DynamicArray<DeprecatedString>::create_with({Jakt::DeprecatedString("-dp"sv)}))))))));
bool const typechecker_debug = TRY((((args_parser).flag((TRY((DynamicArray<DeprecatedString>::create_with({Jakt::DeprecatedString("-dt"sv)}))))))));
bool const build_executable = (!(TRY((((args_parser).flag((TRY((DynamicArray<DeprecatedString>::create_with({Jakt::DeprecatedString("-S"sv)}))))))))));
bool const run_executable = TRY((((args_parser).flag((TRY((DynamicArray<DeprecatedString>::create_with({Jakt::DeprecatedString("-cr"sv), Jakt::DeprecatedString("--compile-run"sv)}))))))));
bool const codegen_debug = TRY((((args_parser).flag((TRY((DynamicArray<DeprecatedString>::create_with({Jakt::DeprecatedString("-d"sv)}))))))));
bool const debug_print = TRY((((args_parser).flag((TRY((DynamicArray<DeprecatedString>::create_with({Jakt::DeprecatedString("--debug-print"sv)}))))))));
bool const prettify_cpp_source = TRY((((args_parser).flag((TRY((DynamicArray<DeprecatedString>::create_with({Jakt::DeprecatedString("-p"sv), Jakt::DeprecatedString("--prettify-cpp-source"sv)}))))))));
bool const json_errors = TRY((((args_parser).flag((TRY((DynamicArray<DeprecatedString>::create_with({Jakt::DeprecatedString("-j"sv), Jakt::DeprecatedString("--json-errors"sv)}))))))));
bool const dump_type_hints = TRY((((args_parser).flag((TRY((DynamicArray<DeprecatedString>::create_with({Jakt::DeprecatedString("-H"sv), Jakt::DeprecatedString("--type-hints"sv)}))))))));
bool const dump_try_hints = TRY((((args_parser).flag((TRY((DynamicArray<DeprecatedString>::create_with({Jakt::DeprecatedString("--try-hints"sv)}))))))));
bool const check_only = TRY((((args_parser).flag((TRY((DynamicArray<DeprecatedString>::create_with({Jakt::DeprecatedString("-c"sv), Jakt::DeprecatedString("--check-only"sv)}))))))));
bool const write_source_to_file = TRY((((args_parser).flag((TRY((DynamicArray<DeprecatedString>::create_with({Jakt::DeprecatedString("-S"sv), Jakt::DeprecatedString("--emit-cpp-source-only"sv)}))))))));
JaktInternal::Optional<DeprecatedString> const generate_depfile = TRY((((args_parser).option((TRY((DynamicArray<DeprecatedString>::create_with({Jakt::DeprecatedString("-M"sv), Jakt::DeprecatedString("--dep-file"sv)}))))))));
JaktInternal::Optional<DeprecatedString> const target_triple = TRY((((args_parser).option((TRY((DynamicArray<DeprecatedString>::create_with({Jakt::DeprecatedString("-T"sv), Jakt::DeprecatedString("--target-triple"sv)}))))))));
DeprecatedString const runtime_library_path = TRY((((args_parser).option((TRY((DynamicArray<DeprecatedString>::create_with({Jakt::DeprecatedString("-RLP"sv), Jakt::DeprecatedString("--runtime-library-path"sv)})))))))).value_or_lazy_evaluated([&] { return ((default_runtime_library_path).to_string()); });
DeprecatedString compiler_job_count = TRY((((args_parser).option((TRY((DynamicArray<DeprecatedString>::create_with({Jakt::DeprecatedString("-J"sv), Jakt::DeprecatedString("--jobs"sv)})))))))).value_or_lazy_evaluated([&] { return Jakt::DeprecatedString("2"sv); });
if (false){
(compiler_job_count = Jakt::DeprecatedString("1"sv));
}
DeprecatedString const clang_format_path = TRY((((args_parser).option((TRY((DynamicArray<DeprecatedString>::create_with({Jakt::DeprecatedString("-F"sv), Jakt::DeprecatedString("--clang-format-path"sv)})))))))).value_or_lazy_evaluated([&] { return Jakt::DeprecatedString("clang-format"sv); });
DeprecatedString const runtime_path = TRY((((args_parser).option((TRY((DynamicArray<DeprecatedString>::create_with({Jakt::DeprecatedString("-R"sv), Jakt::DeprecatedString("--runtime-path"sv)})))))))).value_or_lazy_evaluated([&] { return ((default_runtime_path).to_string()); });
jakt__path::Path const binary_dir = TRY((jakt__path::Path::from_string(TRY((((args_parser).option((TRY((DynamicArray<DeprecatedString>::create_with({Jakt::DeprecatedString("-B"sv), Jakt::DeprecatedString("--binary-dir"sv)})))))))).value_or_lazy_evaluated([&] { return Jakt::DeprecatedString("build"sv); }))));
JaktInternal::Optional<DeprecatedString> const dot_clang_format_path = TRY((((args_parser).option((TRY((DynamicArray<DeprecatedString>::create_with({Jakt::DeprecatedString("-D"sv), Jakt::DeprecatedString("--dot-clang-format-path"sv)}))))))));
DeprecatedString const cxx_compiler_path = TRY((((args_parser).option((TRY((DynamicArray<DeprecatedString>::create_with({Jakt::DeprecatedString("-C"sv), Jakt::DeprecatedString("--cxx-compiler-path"sv)})))))))).value_or_lazy_evaluated([&] { return default_compiler_path; });
JaktInternal::Optional<DeprecatedString> const archiver_path = TRY((((args_parser).option((TRY((DynamicArray<DeprecatedString>::create_with({Jakt::DeprecatedString("-A"sv), Jakt::DeprecatedString("--archiver"sv)}))))))));
JaktInternal::Optional<DeprecatedString> const link_archive = TRY((((args_parser).option((TRY((DynamicArray<DeprecatedString>::create_with({Jakt::DeprecatedString("-a"sv), Jakt::DeprecatedString("--link-archive"sv)}))))))));
JaktInternal::DynamicArray<DeprecatedString> const extra_include_paths = TRY((((args_parser).option_multiple((TRY((DynamicArray<DeprecatedString>::create_with({Jakt::DeprecatedString("-I"sv)}))))))));
JaktInternal::DynamicArray<DeprecatedString> const extra_lib_paths = TRY((((args_parser).option_multiple((TRY((DynamicArray<DeprecatedString>::create_with({Jakt::DeprecatedString("-L"sv)}))))))));
JaktInternal::DynamicArray<DeprecatedString> const extra_link_libs = TRY((((args_parser).option_multiple((TRY((DynamicArray<DeprecatedString>::create_with({Jakt::DeprecatedString("-l"sv)}))))))));
JaktInternal::Optional<DeprecatedString> const set_output_filename = TRY((((args_parser).option((TRY((DynamicArray<DeprecatedString>::create_with({Jakt::DeprecatedString("-o"sv), Jakt::DeprecatedString("--output-filename"sv)}))))))));
JaktInternal::Optional<DeprecatedString> const goto_def = TRY((((args_parser).option((TRY((DynamicArray<DeprecatedString>::create_with({Jakt::DeprecatedString("-g"sv), Jakt::DeprecatedString("--goto-def"sv)}))))))));
JaktInternal::Optional<DeprecatedString> const goto_type_def = TRY((((args_parser).option((TRY((DynamicArray<DeprecatedString>::create_with({Jakt::DeprecatedString("-t"sv), Jakt::DeprecatedString("--goto-type-def"sv)}))))))));
JaktInternal::Optional<DeprecatedString> const hover = TRY((((args_parser).option((TRY((DynamicArray<DeprecatedString>::create_with({Jakt::DeprecatedString("-e"sv), Jakt::DeprecatedString("--hover"sv)}))))))));
JaktInternal::Optional<DeprecatedString> const completions = TRY((((args_parser).option((TRY((DynamicArray<DeprecatedString>::create_with({Jakt::DeprecatedString("-m"sv), Jakt::DeprecatedString("--completions"sv)}))))))));
bool const print_symbols = TRY((((args_parser).flag((TRY((DynamicArray<DeprecatedString>::create_with({Jakt::DeprecatedString("--print-symbols"sv)}))))))));
JaktInternal::Optional<DeprecatedString> const project_name = TRY((((args_parser).option((TRY((DynamicArray<DeprecatedString>::create_with({Jakt::DeprecatedString("--create"sv)}))))))));
bool const interpret_run = TRY((((args_parser).flag((TRY((DynamicArray<DeprecatedString>::create_with({Jakt::DeprecatedString("-r"sv), Jakt::DeprecatedString("--run"sv)}))))))));
bool const format = TRY((((args_parser).flag((TRY((DynamicArray<DeprecatedString>::create_with({Jakt::DeprecatedString("-f"sv), Jakt::DeprecatedString("--format"sv)}))))))));
bool const format_inplace = TRY((((args_parser).flag((TRY((DynamicArray<DeprecatedString>::create_with({Jakt::DeprecatedString("-fi"sv), Jakt::DeprecatedString("--format-inplace"sv)}))))))));
bool const format_debug = TRY((((args_parser).flag((TRY((DynamicArray<DeprecatedString>::create_with({Jakt::DeprecatedString("-fd"sv), Jakt::DeprecatedString("--format-debug"sv)}))))))));
DeprecatedString const input_format_range = TRY((((args_parser).option((TRY((DynamicArray<DeprecatedString>::create_with({Jakt::DeprecatedString("-fr"sv), Jakt::DeprecatedString("--format-range"sv)})))))))).value_or_lazy_evaluated([&] { return Jakt::DeprecatedString(""sv); });
bool const ak_stdlib = TRY((((args_parser).flag((TRY((DynamicArray<DeprecatedString>::create_with({Jakt::DeprecatedString("--ak-is-my-only-stdlib"sv)}))))))));
size_t const max_concurrent = (infallible_integer_cast<size_t>((({ Optional<u32> __jakt_var_767;
auto __jakt_var_768 = [&]() -> ErrorOr<u32> { return TRY((value_or_throw<u32>(((compiler_job_count).to_uint())))); }();
if (__jakt_var_768.is_error()) {{
warnln(Jakt::DeprecatedString("error: invalid value for --jobs: {}"sv),compiler_job_count);
return (static_cast<i64>(1LL));
}
} else {__jakt_var_767 = __jakt_var_768.release_value();
}
__jakt_var_767.release_value(); }))));
if (TRY((((args_parser).flag((TRY((DynamicArray<DeprecatedString>::create_with({Jakt::DeprecatedString("--repl"sv)}))))))))){
repl::REPL repl = TRY((repl::REPL::create(TRY((jakt__path::Path::from_parts((TRY((DynamicArray<DeprecatedString>::create_with({runtime_path, Jakt::DeprecatedString("jaktlib"sv)}))))))),target_triple)));
TRY((((repl).run())));
return (static_cast<i64>(0LL));
}
JaktInternal::DynamicArray<DeprecatedString> const positional_arguments = TRY((((args_parser).remaining_arguments())));
if (((project_name).has_value())){
project::Project const project = project::Project((project_name.value()));
TRY((((project).populate())));
return (static_cast<i64>(0LL));
}
JaktInternal::Optional<DeprecatedString> file_name = JaktInternal::OptionalNone();
bool first_arg = true;
JaktInternal::DynamicArray<DeprecatedString> interpreted_main_arguments = (TRY((DynamicArray<DeprecatedString>::create_with({}))));
{
JaktInternal::ArrayIterator<DeprecatedString> _magic = ((positional_arguments).iterator());
for (;;){
JaktInternal::Optional<DeprecatedString> _magic_value = ((_magic).next());
if ((!(((_magic_value).has_value())))){
break;
}
DeprecatedString arg = (_magic_value.value());
{
if (first_arg){
(first_arg = false);
continue;
}
if ((!(((file_name).has_value())))){
(file_name = arg);
continue;
}
if ((!(interpret_run))){
warnln(Jakt::DeprecatedString("Extra unknown argument '{}', you can only pass one source file (was '{}')"sv),arg,file_name);
warnln(Jakt::DeprecatedString("{}"sv),usage());
return (static_cast<i64>(1LL));
}
TRY((((interpreted_main_arguments).push(arg))));
}

}
}

if ((!(((file_name).has_value())))){
warnln(Jakt::DeprecatedString("you must pass a source file"sv));
warnln(Jakt::DeprecatedString("{}"sv),usage());
return (static_cast<i64>(1LL));
}
jakt__path::Path const file_path = TRY((jakt__path::Path::from_string((file_name.value()))));
DeprecatedString const guessed_output_filename = TRY((((file_path).basename(true))));
DeprecatedString const output_filename = ((TRY((((binary_dir).join(set_output_filename.value_or_lazy_evaluated([&] { return guessed_output_filename; })))))).to_string());
JaktInternal::DynamicArray<error::JaktError> errors = (TRY((DynamicArray<error::JaktError>::create_with({}))));
NonnullRefPtr<compiler::Compiler> compiler = TRY((compiler::Compiler::create((TRY((DynamicArray<jakt__path::Path>::create_with({})))),(TRY((Dictionary<DeprecatedString, utility::FileId>::create_with_entries({})))),(TRY((DynamicArray<error::JaktError>::create_with({})))),JaktInternal::OptionalNone(),(TRY((DynamicArray<u8>::create_with({})))),lexer_debug,parser_debug,false,debug_print,TRY((jakt__path::Path::from_parts((TRY((DynamicArray<DeprecatedString>::create_with({runtime_path, Jakt::DeprecatedString("jaktlib"sv)}))))))),extra_include_paths,json_errors,dump_type_hints,dump_try_hints,optimize,target_triple)));
TRY((((compiler)->load_prelude())));
if (((format || format_debug) || format_inplace)){
NonnullRefPtr<jakt__file_iterator::RecursiveFileIterator> const directory_or_file_paths = TRY((jakt__file_iterator::RecursiveFileIterator::make(file_path,Jakt::DeprecatedString("jakt"sv))));
{
NonnullRefPtr<jakt__file_iterator::RecursiveFileIterator> _magic = directory_or_file_paths;
for (;;){
JaktInternal::Optional<jakt__path::Path> _magic_value = TRY((((_magic)->next())));
if ((!(((_magic_value).has_value())))){
break;
}
jakt__path::Path directory_or_file_path = (_magic_value.value());
{
utility::FileId const file_id = TRY((((compiler)->get_file_id_or_register(directory_or_file_path))));
bool const file_is_set = ((compiler)->set_current_file(file_id));
if ((!(file_is_set))){
return (static_cast<i64>(1LL));
}
JaktInternal::Optional<FormatRange> const format_range = TRY((parse_format_range(input_format_range,((((compiler)->current_file_contents)).size()))));
if ((!(((format_range).has_value())))){
warnln(Jakt::DeprecatedString("invalid format range '{}', expected <start>(:<end>?)"sv),input_format_range);
return (static_cast<i64>(1LL));
}
JaktInternal::DynamicArray<lexer::Token> const tokens = TRY((lexer::Lexer::lex(compiler)));
TRY((format_output(directory_or_file_path,tokens,format_range,format_debug,format_inplace)));
}

}
}

return (static_cast<i64>(0LL));
}
utility::FileId const main_file_id = TRY((((compiler)->get_file_id_or_register(file_path))));
bool const file_is_set = ((compiler)->set_current_file(main_file_id));
if ((!(file_is_set))){
return (static_cast<i64>(1LL));
}
JaktInternal::DynamicArray<lexer::Token> const tokens = TRY((lexer::Lexer::lex(compiler)));
if (lexer_debug){
{
JaktInternal::ArrayIterator<lexer::Token> _magic = ((tokens).iterator());
for (;;){
JaktInternal::Optional<lexer::Token> _magic_value = ((_magic).next());
if ((!(((_magic_value).has_value())))){
break;
}
lexer::Token token = (_magic_value.value());
{
outln(Jakt::DeprecatedString("token: {}"sv),token);
}

}
}

}
parser::ParsedNamespace const parsed_namespace = TRY((parser::Parser::parse(compiler,tokens)));
if (parser_debug){
outln(Jakt::DeprecatedString("{:#}"sv),parsed_namespace);
}
if (print_symbols){
JaktInternal::DynamicArray<ide::JaktSymbol> const symbols = TRY((ide::find_symbols_in_namespace(parsed_namespace)));
JaktInternal::DynamicArray<DeprecatedString> symbol_representations = (TRY((DynamicArray<DeprecatedString>::create_with({}))));
{
JaktInternal::ArrayIterator<ide::JaktSymbol> _magic = ((symbols).iterator());
for (;;){
JaktInternal::Optional<ide::JaktSymbol> _magic_value = ((_magic).next());
if ((!(((_magic_value).has_value())))){
break;
}
ide::JaktSymbol symbol = (_magic_value.value());
{
TRY((((symbol_representations).push(TRY((((symbol).to_json())))))));
}

}
}

outln(Jakt::DeprecatedString("[{}]"sv),utility::join(symbol_representations,Jakt::DeprecatedString(","sv)));
return (static_cast<i64>(0LL));
}
NonnullRefPtr<types::CheckedProgram> const checked_program = TRY((typechecker::Typechecker::typecheck(compiler,parsed_namespace)));
if (interpret_run){
NonnullRefPtr<interpreter::Interpreter> interpreter = TRY((interpreter::Interpreter::create(compiler,checked_program,(TRY((DynamicArray<utility::Span>::create_with({})))))));
types::ScopeId const prelude_scope_id = types::ScopeId(types::ModuleId(static_cast<size_t>(0ULL)),static_cast<size_t>(0ULL));
JaktInternal::Optional<types::FunctionId> main_function_id = JaktInternal::OptionalNone();
{
JaktInternal::ArrayIterator<NonnullRefPtr<types::Module>> _magic = ((((checked_program)->modules)).iterator());
for (;;){
JaktInternal::Optional<NonnullRefPtr<types::Module>> _magic_value = ((_magic).next());
if ((!(((_magic_value).has_value())))){
break;
}
NonnullRefPtr<types::Module> module = (_magic_value.value());
{
{
JaktInternal::ArrayIterator<NonnullRefPtr<types::Scope>> _magic = ((((module)->scopes)).iterator());
for (;;){
JaktInternal::Optional<NonnullRefPtr<types::Scope>> _magic_value = ((_magic).next());
if ((!(((_magic_value).has_value())))){
break;
}
NonnullRefPtr<types::Scope> scope = (_magic_value.value());
{
if ((!(((((scope)->parent)).map([&](auto& _value) { return _value.equals(prelude_scope_id); })).value_or_lazy_evaluated([&] { return false; })))){
continue;
}
{
JaktInternal::DictionaryIterator<DeprecatedString,JaktInternal::DynamicArray<types::FunctionId>> _magic = ((((scope)->functions)).iterator());
for (;;){
JaktInternal::Optional<JaktInternal::Tuple<DeprecatedString,JaktInternal::DynamicArray<types::FunctionId>>> _magic_value = ((_magic).next());
if ((!(((_magic_value).has_value())))){
break;
}
JaktInternal::Tuple<DeprecatedString,JaktInternal::DynamicArray<types::FunctionId>> function_name__overload_set__ = (_magic_value.value());
{
JaktInternal::Tuple<DeprecatedString,JaktInternal::DynamicArray<types::FunctionId>> const jakt__function_name__overload_set__ = function_name__overload_set__;
DeprecatedString const function_name = ((jakt__function_name__overload_set__).template get<0>());
JaktInternal::DynamicArray<types::FunctionId> const overload_set = ((jakt__function_name__overload_set__).template get<1>());

if ((function_name == Jakt::DeprecatedString("main"sv))){
(main_function_id = ((overload_set)[static_cast<i64>(0LL)]));
break;
}
}

}
}

if (((main_function_id).has_value())){
break;
}
}

}
}

if (((main_function_id).has_value())){
break;
}
}

}
}

if ((!(((main_function_id).has_value())))){
warnln(Jakt::DeprecatedString("Error: No main function found in program"sv));
return (static_cast<i64>(1LL));
}
JaktInternal::DynamicArray<types::ResolvedNamespace> const namespace_ = (TRY((DynamicArray<types::ResolvedNamespace>::create_with({}))));
utility::Span const call_span = utility::Span(utility::FileId(static_cast<size_t>(0ULL)),static_cast<size_t>(0ULL),static_cast<size_t>(0ULL));
JaktInternal::Optional<types::CheckedParameter> const first_main_param = ((((((checked_program)->get_function((main_function_id.value()))))->params)).first());
JaktInternal::DynamicArray<types::Value> const arguments = JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<JaktInternal::DynamicArray<types::Value>,ErrorOr<int>>{
auto __jakt_enum_value = (((first_main_param).has_value()));
if (__jakt_enum_value == true) {
return JaktInternal::ExplicitValue(({ Optional<JaktInternal::DynamicArray<types::Value>> __jakt_var_769; {
JaktInternal::DynamicArray<types::Value> passed_arguments = (TRY((DynamicArray<types::Value>::create_with({types::Value(TRY((types::ValueImpl::template create<typename types::ValueImpl::JaktString>((file_name.value())))),call_span)}))));
{
JaktInternal::ArrayIterator<DeprecatedString> _magic = ((interpreted_main_arguments).iterator());
for (;;){
JaktInternal::Optional<DeprecatedString> _magic_value = ((_magic).next());
if ((!(((_magic_value).has_value())))){
break;
}
DeprecatedString argument = (_magic_value.value());
{
TRY((((passed_arguments).push(types::Value(TRY((types::ValueImpl::template create<typename types::ValueImpl::JaktString>(argument))),call_span)))));
}

}
}

__jakt_var_769 = (TRY((DynamicArray<types::Value>::create_with({types::Value(TRY((types::ValueImpl::template create<typename types::ValueImpl::JaktArray>(passed_arguments,(((((first_main_param.value())).variable))->type_id)))),call_span)})))); goto __jakt_label_688;

}
__jakt_label_688:; __jakt_var_769.release_value(); }));
}
else {
return JaktInternal::ExplicitValue((TRY((DynamicArray<types::Value>::create_with({})))));
}
}()))
;
interpreter::ExecutionResult const main_result = TRY((((interpreter)->execute((main_function_id.value()),namespace_,JaktInternal::OptionalNone(),arguments,call_span,JaktInternal::OptionalNone()))));
JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<void, ErrorOr<int>>{
auto&& __jakt_match_variant = main_result;
switch(__jakt_match_variant.index()) {
case 0: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename interpreter::ExecutionResult::Return>();
types::Value const& x = __jakt_match_value.value;
return (JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<void, ErrorOr<int>>{
auto&& __jakt_match_variant = *((x).impl);
switch(__jakt_match_variant.index()) {
case 16: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::CInt>();
int const& ret_val = __jakt_match_value.value;
{
return (ret_val);
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 9: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::I64>();
i64 const& ret_val = __jakt_match_value.value;
{
return (ret_val);
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 0: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::Void>();
{
return (static_cast<i64>(0LL));
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
default: {
{
warnln(Jakt::DeprecatedString("Error: Main function must return an integer"sv));
return (static_cast<i64>(1LL));
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
}/*switch end*/
}()
))), JaktInternal::ExplicitValue<void>();
};/*case end*/
case 1: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename interpreter::ExecutionResult::Throw>();
types::Value const& x = __jakt_match_value.value;
{
warnln(Jakt::DeprecatedString("Error: Main function threw: {}"sv),TRY((repl::serialize_ast_node(TRY((interpreter::value_to_checked_expression(x,interpreter)))))));
return (static_cast<i64>(1LL));
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
default: VERIFY_NOT_REACHED();}/*switch end*/
}()
));
}
if (((goto_def).has_value())){
size_t const index = (infallible_integer_cast<size_t>((((((goto_def.value())).to_uint()).value()))));
utility::Span const result = TRY((ide::find_definition_in_program(checked_program,utility::Span(utility::FileId(static_cast<size_t>(1ULL)),index,index))));
if ((((((result).file_id)).id) == static_cast<size_t>(1ULL))){
outln(Jakt::DeprecatedString("{{\"start\": {}, \"end\": {}}}"sv),((result).start),((result).end));
}
else {
JaktInternal::Optional<jakt__path::Path> const file_path = TRY((((compiler)->get_file_path(((result).file_id)))));
outln(Jakt::DeprecatedString("{{\"start\": {}, \"end\": {}, \"file\": \"{}\"}}"sv),((result).start),((result).end),TRY((utility::escape_for_quotes((((file_path.value())).to_string())))));
}

return (static_cast<i64>(0LL));
}
if (((goto_type_def).has_value())){
size_t const index = (infallible_integer_cast<size_t>((((((goto_type_def.value())).to_uint()).value()))));
utility::Span const result = TRY((ide::find_type_definition_in_program(checked_program,utility::Span(utility::FileId(static_cast<size_t>(1ULL)),index,index))));
if ((((((result).file_id)).id) == static_cast<size_t>(1ULL))){
outln(Jakt::DeprecatedString("{{\"start\": {}, \"end\": {}}}"sv),((result).start),((result).end));
}
else {
JaktInternal::Optional<jakt__path::Path> const file_path = TRY((((compiler)->get_file_path(((result).file_id)))));
outln(Jakt::DeprecatedString("{{\"start\": {}, \"end\": {}, \"file\": \"{}\"}}"sv),((result).start),((result).end),TRY((utility::escape_for_quotes((((file_path.value())).to_string())))));
}

return (static_cast<i64>(0LL));
}
if (((hover).has_value())){
size_t const index = (infallible_integer_cast<size_t>((((((hover.value())).to_uint()).value()))));
JaktInternal::Optional<DeprecatedString> const result = TRY((ide::find_typename_in_program(checked_program,utility::Span(utility::FileId(static_cast<size_t>(1ULL)),index,index))));
if (((result).has_value())){
outln(Jakt::DeprecatedString("{{\"hover\": \"{}\"}}"sv),(result.value()));
}
return (static_cast<i64>(0LL));
}
if (((completions).has_value())){
size_t const index = (infallible_integer_cast<size_t>((((((completions.value())).to_uint()).value()))));
JaktInternal::DynamicArray<DeprecatedString> const result = TRY((ide::find_dot_completions(checked_program,utility::Span(utility::FileId(static_cast<size_t>(1ULL)),index,index))));
out(Jakt::DeprecatedString("{{\"completions\": ["sv));
bool first = true;
{
JaktInternal::ArrayIterator<DeprecatedString> _magic = ((result).iterator());
for (;;){
JaktInternal::Optional<DeprecatedString> _magic_value = ((_magic).next());
if ((!(((_magic_value).has_value())))){
break;
}
DeprecatedString completion = (_magic_value.value());
{
if ((!(first))){
out(Jakt::DeprecatedString(", "sv));
}
else {
(first = false);
}

out(Jakt::DeprecatedString("\"{}\""sv),completion);
}

}
}

outln(Jakt::DeprecatedString("]}}"sv));
return (static_cast<i64>(0LL));
}
if (typechecker_debug){
outln(Jakt::DeprecatedString("{:#}"sv),checked_program);
}
TRY((((compiler)->print_errors())));
if ((!(((((compiler)->errors)).is_empty())))){
return (static_cast<i64>(1LL));
}
if (check_only){
return (static_cast<i64>(0LL));
}
JaktInternal::Dictionary<DeprecatedString,JaktInternal::Tuple<DeprecatedString,DeprecatedString>> const codegen_result = TRY((codegen::CodeGenerator::generate(compiler,checked_program,codegen_debug)));
DeprecatedStringBuilder depfile_builder = TRY((DeprecatedStringBuilder::create()));
if ((!(((binary_dir).exists())))){
TRY((jakt__platform__unknown_fs::make_directory(((binary_dir).to_string()))));
}
{
JaktInternal::DictionaryIterator<DeprecatedString,JaktInternal::Tuple<DeprecatedString,DeprecatedString>> _magic = ((codegen_result).iterator());
for (;;){
JaktInternal::Optional<JaktInternal::Tuple<DeprecatedString,JaktInternal::Tuple<DeprecatedString,DeprecatedString>>> _magic_value = ((_magic).next());
if ((!(((_magic_value).has_value())))){
break;
}
JaktInternal::Tuple<DeprecatedString,JaktInternal::Tuple<DeprecatedString,DeprecatedString>> file__contents_and_path__ = (_magic_value.value());
{
JaktInternal::Tuple<DeprecatedString,JaktInternal::Tuple<DeprecatedString,DeprecatedString>> const jakt__file__contents_and_path__ = file__contents_and_path__;
DeprecatedString const file = ((jakt__file__contents_and_path__).template get<0>());
JaktInternal::Tuple<DeprecatedString,DeprecatedString> const contents_and_path = ((jakt__file__contents_and_path__).template get<1>());

JaktInternal::Tuple<DeprecatedString,DeprecatedString> const contents_module_file_path_ = contents_and_path;
DeprecatedString const contents = ((contents_module_file_path_).template get<0>());
DeprecatedString const module_file_path = ((contents_module_file_path_).template get<1>());

jakt__path::Path const path = TRY((((binary_dir).join(file))));
auto __jakt_var_771 = [&]() -> ErrorOr<void> { return TRY((utility::write_to_file(contents,((path).to_string())))), ErrorOr<void>{}; }();
if (__jakt_var_771.is_error()) {auto error = __jakt_var_771.release_error();
{
warnln(Jakt::DeprecatedString("Error: Could not write to file: {} ({})"sv),file,error);
return (static_cast<i64>(1LL));
}
}
;
if ((((generate_depfile).has_value()) && ((file).ends_with(Jakt::DeprecatedString(".cpp"sv))))){
DeprecatedString const escaped = ((file).replace(Jakt::DeprecatedString(" "sv),Jakt::DeprecatedString("\\ "sv)));
DeprecatedString const escaped_module_file_path = ((module_file_path).replace(Jakt::DeprecatedString(" "sv),Jakt::DeprecatedString("\\ "sv)));
TRY((((depfile_builder).append_string(TRY((__jakt_format(Jakt::DeprecatedString("{} {}.h: {}"sv),escaped,((escaped).substring(static_cast<size_t>(0ULL),(JaktInternal::checked_sub<size_t>(((file).length()),static_cast<size_t>(4ULL))))),escaped_module_file_path)))))));
TRY((((depfile_builder).append('\n'))));
}
}

}
}

if (((generate_depfile).has_value())){
auto __jakt_var_772 = [&]() -> ErrorOr<void> {{
TRY((utility::write_to_file(TRY((((depfile_builder).to_string()))),(generate_depfile.value()))));
}

;return {};}();
if (__jakt_var_772.is_error()) {auto error = __jakt_var_772.release_error();{
warnln(Jakt::DeprecatedString("Error: Could not write to file list ({})"sv),error);
return (static_cast<i64>(1LL));
}
};
}
if ((build_executable || run_executable)){
JaktInternal::DynamicArray<DeprecatedString> files = (TRY((DynamicArray<DeprecatedString>::create_with({}))));
{
JaktInternal::DictionaryIterator<DeprecatedString,JaktInternal::Tuple<DeprecatedString,DeprecatedString>> _magic = ((codegen_result).iterator());
for (;;){
JaktInternal::Optional<JaktInternal::Tuple<DeprecatedString,JaktInternal::Tuple<DeprecatedString,DeprecatedString>>> _magic_value = ((_magic).next());
if ((!(((_magic_value).has_value())))){
break;
}
JaktInternal::Tuple<DeprecatedString,JaktInternal::Tuple<DeprecatedString,DeprecatedString>> file_name_____ = (_magic_value.value());
{
JaktInternal::Tuple<DeprecatedString,JaktInternal::Tuple<DeprecatedString,DeprecatedString>> const jakt__file_name_____ = file_name_____;
DeprecatedString const file_name = ((jakt__file_name_____).template get<0>());
JaktInternal::Tuple<DeprecatedString,DeprecatedString> const _ = ((jakt__file_name_____).template get<1>());

if (((file_name).ends_with(Jakt::DeprecatedString(".h"sv)))){
continue;
}
TRY((((files).push(file_name))));
}

}
}

build::Builder builder = TRY((build::Builder::for_building(files,max_concurrent)));
JaktInternal::DynamicArray<DeprecatedString> extra_compiler_flags = (TRY((DynamicArray<DeprecatedString>::create_with({Jakt::DeprecatedString("-c"sv)}))));
if (ak_stdlib){
TRY((((extra_compiler_flags).push(Jakt::DeprecatedString("-DJAKT_USING_AK_AS_STANDARD_LIBRARY=1"sv)))));
}
auto __jakt_var_774 = [&]() -> ErrorOr<void> { return TRY((((builder).build_all(binary_dir,(([cxx_compiler_path, runtime_path, extra_include_paths, optimize, extra_compiler_flags](DeprecatedString input_filename, DeprecatedString output_filename) -> ErrorOr<JaktInternal::DynamicArray<DeprecatedString>> {
{
return (TRY((jakt__platform__unknown_compiler::run_compiler(cxx_compiler_path,input_filename,output_filename,runtime_path,extra_include_paths,(TRY((DynamicArray<DeprecatedString>::create_with({})))),(TRY((DynamicArray<DeprecatedString>::create_with({})))),optimize,extra_compiler_flags))));
}
}
)))))), ErrorOr<void>{}; }();
if (__jakt_var_774.is_error()) {{
return (static_cast<i64>(1LL));
}
}
;
if (((link_archive).has_value())){
auto __jakt_var_776 = [&]() -> ErrorOr<void> { return TRY((((builder).link_into_archive(archiver_path.value_or_lazy_evaluated([&] { return Jakt::DeprecatedString("ar"sv); }),(link_archive.value()))))), ErrorOr<void>{}; }();
if (__jakt_var_776.is_error()) {{
return (static_cast<i64>(1LL));
}
}
;
}
else {
JaktInternal::DynamicArray<DeprecatedString> extra_arguments = (TRY((DynamicArray<DeprecatedString>::create_with({}))));
jakt__path::Path const runtime_lib_path = TRY((jakt__path::Path::from_string(runtime_library_path)));
TRY((((extra_arguments).push(((TRY((((runtime_lib_path).join(Jakt::DeprecatedString("libjakt_main.a"sv)))))).to_string())))));
TRY((((extra_arguments).push(((TRY((((runtime_lib_path).join(Jakt::DeprecatedString("libjakt_runtime.a"sv)))))).to_string())))));
{
JaktInternal::ArrayIterator<DeprecatedString> _magic = ((extra_lib_paths).iterator());
for (;;){
JaktInternal::Optional<DeprecatedString> _magic_value = ((_magic).next());
if ((!(((_magic_value).has_value())))){
break;
}
DeprecatedString path = (_magic_value.value());
{
TRY((((extra_arguments).push(Jakt::DeprecatedString("-L"sv)))));
TRY((((extra_arguments).push(path))));
}

}
}

{
JaktInternal::ArrayIterator<DeprecatedString> _magic = ((extra_link_libs).iterator());
for (;;){
JaktInternal::Optional<DeprecatedString> _magic_value = ((_magic).next());
if ((!(((_magic_value).has_value())))){
break;
}
DeprecatedString lib = (_magic_value.value());
{
TRY((((extra_arguments).push(Jakt::DeprecatedString("-l"sv)))));
TRY((((extra_arguments).push(lib))));
}

}
}

if ((false && (TRY((((TRY((jakt__path::Path::from_string(cxx_compiler_path)))).basename(false)))) == Jakt::DeprecatedString("clang-cl"sv)))){
TRY((((extra_arguments).push(Jakt::DeprecatedString("/link"sv)))));
TRY((((extra_arguments).push(Jakt::DeprecatedString("/subsystem:console"sv)))));
}
auto __jakt_var_778 = [&]() -> ErrorOr<void> { return TRY((((builder).link_into_executable(cxx_compiler_path,output_filename,extra_arguments)))), ErrorOr<void>{}; }();
if (__jakt_var_778.is_error()) {{
return (static_cast<i64>(1LL));
}
}
;
}

}
if (run_executable){
return (system(((output_filename).characters())));
}
}
return 0;
}

ErrorOr<DeprecatedString> FormatRange::debug_description() const { auto builder = MUST(DeprecatedStringBuilder::create());TRY(builder.append("FormatRange("sv));{
JaktInternal::PrettyPrint::ScopedLevelIncrease increase_indent {};
TRY(JaktInternal::PrettyPrint::output_indentation(builder));TRY(builder.append("start: "sv));TRY(builder.appendff("{}, ", start));
TRY(JaktInternal::PrettyPrint::output_indentation(builder));TRY(builder.append("end: "sv));TRY(builder.appendff("{}", end));
}
TRY(builder.append(")"sv));return builder.to_string(); }
FormatRange::FormatRange(size_t a_start, size_t a_end) :start(a_start), end(a_end){}

} // namespace Jakt
