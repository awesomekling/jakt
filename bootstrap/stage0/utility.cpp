#include "utility.h"
namespace Jakt {
namespace utility {
bool is_ascii_binary(u8 const c) {
{
return (((c == '0') || (c == '1')));
}
}

bool is_ascii_alpha(u8 const c) {
{
return ((((c >= 'a') && (c <= 'z')) || ((c >= 'A') && (c <= 'Z'))));
}
}

bool is_whitespace(u8 const byte) {
{
return ((((byte == ' ') || (byte == '\t')) || (byte == '\r')));
}
}

ErrorOr<JaktInternal::DynamicArray<DeprecatedString>> prepend_to_each(JaktInternal::DynamicArray<DeprecatedString> const strings,DeprecatedString const prefix) {
{
JaktInternal::DynamicArray<DeprecatedString> output = (TRY((DynamicArray<DeprecatedString>::create_with({}))));
{
JaktInternal::ArrayIterator<DeprecatedString> _magic = ((strings).iterator());
for (;;){
JaktInternal::Optional<DeprecatedString> _magic_value = ((_magic).next());
if ((!(((_magic_value).has_value())))){
break;
}
DeprecatedString str = (_magic_value.value());
{
TRY((((output).push((prefix + str)))));
}

}
}

return (output);
}
}

bool is_ascii_digit(u8 const c) {
{
return (((c >= '0') && (c <= '9')));
}
}

void todo(DeprecatedString const message) {
{
warnln(Jakt::DeprecatedString("TODO: {}"sv),message);
abort();
}
}

bool is_ascii_alphanumeric(u8 const c) {
{
return ((utility::is_ascii_alpha(c) || utility::is_ascii_digit(c)));
}
}

ErrorOr<DeprecatedString> interpret_escapes(DeprecatedString const s) {
{
DeprecatedStringBuilder builder = TRY((DeprecatedStringBuilder::create()));
bool in_escape = false;
{
DeprecatedStringCodePointIterator _magic = ((s).code_points());
for (;;){
JaktInternal::Optional<u32> _magic_value = ((_magic).next());
if ((!(((_magic_value).has_value())))){
break;
}
u32 cp = (_magic_value.value());
{
JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_AT_LOOP(([&]() -> JaktInternal::ExplicitValueOrControlFlow<void,ErrorOr<DeprecatedString>>{
auto __jakt_enum_value = (cp);
if (__jakt_enum_value == (infallible_integer_cast<u32>(('\\')))) {
{
if (in_escape){
TRY((((builder).append('\\'))));
(in_escape = false);
}
else {
(in_escape = true);
}

}
return JaktInternal::ExplicitValue<void>();
}
else if (__jakt_enum_value == (infallible_integer_cast<u32>(('"')))) {
{
if (in_escape){
TRY((((builder).append_code_point(cp))));
(in_escape = false);
}
}
return JaktInternal::ExplicitValue<void>();
}
else if (__jakt_enum_value == (infallible_integer_cast<u32>(('\'')))) {
{
if (in_escape){
TRY((((builder).append_code_point(cp))));
(in_escape = false);
}
}
return JaktInternal::ExplicitValue<void>();
}
else if (__jakt_enum_value == (infallible_integer_cast<u32>(('n')))) {
{
if (in_escape){
TRY((((builder).append('\n'))));
(in_escape = false);
}
else {
TRY((((builder).append_code_point(cp))));
}

}
return JaktInternal::ExplicitValue<void>();
}
else {
{
TRY((((builder).append_code_point(cp))));
(in_escape = false);
}
return JaktInternal::ExplicitValue<void>();
}
return JaktInternal::ExplicitValue<void>();
}()))
;
}

}
}

return (TRY((((builder).to_string()))));
}
}

ErrorOr<JaktInternal::DynamicArray<DeprecatedString>> append_to_each(JaktInternal::DynamicArray<DeprecatedString> const strings,DeprecatedString const suffix) {
{
JaktInternal::DynamicArray<DeprecatedString> output = (TRY((DynamicArray<DeprecatedString>::create_with({}))));
{
JaktInternal::ArrayIterator<DeprecatedString> _magic = ((strings).iterator());
for (;;){
JaktInternal::Optional<DeprecatedString> _magic_value = ((_magic).next());
if ((!(((_magic_value).has_value())))){
break;
}
DeprecatedString str = (_magic_value.value());
{
TRY((((output).push((str + suffix)))));
}

}
}

return (output);
}
}

ErrorOr<void> write_to_file(DeprecatedString const data,DeprecatedString const output_filename) {
{
NonnullRefPtr<File> outfile = TRY((File::open_for_writing(output_filename)));
JaktInternal::DynamicArray<u8> bytes = (TRY((DynamicArray<u8>::create_with({}))));
{
JaktInternal::Range<size_t> _magic = (JaktInternal::Range<size_t>{static_cast<size_t>(static_cast<size_t>(0ULL)),static_cast<size_t>(((data).length()))});
for (;;){
JaktInternal::Optional<size_t> _magic_value = ((_magic).next());
if ((!(((_magic_value).has_value())))){
break;
}
size_t i = (_magic_value.value());
{
TRY((((bytes).push(((data).byte_at(i))))));
}

}
}

TRY((((outfile)->write(bytes))));
}
return {};
}

DeprecatedString join(JaktInternal::DynamicArray<DeprecatedString> const strings,DeprecatedString const separator) {
{
DeprecatedString output = Jakt::DeprecatedString(""sv);
size_t i = static_cast<size_t>(0ULL);
{
JaktInternal::ArrayIterator<DeprecatedString> _magic = ((strings).iterator());
for (;;){
JaktInternal::Optional<DeprecatedString> _magic_value = ((_magic).next());
if ((!(((_magic_value).has_value())))){
break;
}
DeprecatedString s = (_magic_value.value());
{
(output += s);
if ((i < (JaktInternal::checked_sub<size_t>(((strings).size()),static_cast<size_t>(1ULL))))){
(output += separator);
}
((i++));
}

}
}

return (output);
}
}

bool is_ascii_octdigit(u8 const c) {
{
return (((c >= '0') && (c <= '7')));
}
}

bool is_ascii_hexdigit(u8 const c) {
{
return (((((c >= '0') && (c <= '9')) || ((c >= 'a') && (c <= 'f'))) || ((c >= 'A') && (c <= 'F'))));
}
}

[[noreturn]] void panic(DeprecatedString const message) {
{
warnln(Jakt::DeprecatedString("internal error: {}"sv),message);
abort();
}
}

ErrorOr<DeprecatedString> escape_for_quotes(DeprecatedString const s) {
{
DeprecatedStringBuilder builder = TRY((DeprecatedStringBuilder::create()));
{
DeprecatedStringCodePointIterator _magic = ((s).code_points());
for (;;){
JaktInternal::Optional<u32> _magic_value = ((_magic).next());
if ((!(((_magic_value).has_value())))){
break;
}
u32 cp = (_magic_value.value());
{
JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_AT_LOOP(([&]() -> JaktInternal::ExplicitValueOrControlFlow<void,ErrorOr<DeprecatedString>>{
auto __jakt_enum_value = (cp);
if (__jakt_enum_value == (infallible_integer_cast<u32>(('"')))) {
{
TRY((((builder).append_string(Jakt::DeprecatedString("\\\""sv)))));
}
return JaktInternal::ExplicitValue<void>();
}
else if (__jakt_enum_value == (infallible_integer_cast<u32>(('\\')))) {
{
TRY((((builder).append_string(Jakt::DeprecatedString("\\\\"sv)))));
}
return JaktInternal::ExplicitValue<void>();
}
else if (__jakt_enum_value == (infallible_integer_cast<u32>(('\n')))) {
{
TRY((((builder).append_string(Jakt::DeprecatedString("\\n"sv)))));
}
return JaktInternal::ExplicitValue<void>();
}
else {
{
TRY((((builder).append_code_point(cp))));
}
return JaktInternal::ExplicitValue<void>();
}
return JaktInternal::ExplicitValue<void>();
}()))
;
}

}
}

return (TRY((((builder).to_string()))));
}
}

ErrorOr<DeprecatedString> utility::Span::debug_description() const { auto builder = MUST(DeprecatedStringBuilder::create());TRY(builder.append("Span("sv));{
JaktInternal::PrettyPrint::ScopedLevelIncrease increase_indent {};
TRY(JaktInternal::PrettyPrint::output_indentation(builder));TRY(builder.append("file_id: "sv));TRY(builder.appendff("{}, ", file_id));
TRY(JaktInternal::PrettyPrint::output_indentation(builder));TRY(builder.append("start: "sv));TRY(builder.appendff("{}, ", start));
TRY(JaktInternal::PrettyPrint::output_indentation(builder));TRY(builder.append("end: "sv));TRY(builder.appendff("{}", end));
}
TRY(builder.append(")"sv));return builder.to_string(); }
bool utility::Span::contains(utility::Span const span) const {
{
return ((((((*this).file_id)).equals(((span).file_id))) && ((((span).start) >= ((*this).start)) && (((span).end) <= ((*this).end)))));
}
}

bool utility::Span::is_in_offset_range(size_t const start,size_t const end) const {
{
return (((start <= ((*this).start)) && (end >= ((*this).end))));
}
}

utility::Span::Span(utility::FileId a_file_id, size_t a_start, size_t a_end) :file_id(a_file_id), start(a_start), end(a_end){}

ErrorOr<DeprecatedString> utility::FileId::debug_description() const { auto builder = MUST(DeprecatedStringBuilder::create());TRY(builder.append("FileId("sv));{
JaktInternal::PrettyPrint::ScopedLevelIncrease increase_indent {};
TRY(JaktInternal::PrettyPrint::output_indentation(builder));TRY(builder.append("id: "sv));TRY(builder.appendff("{}", id));
}
TRY(builder.append(")"sv));return builder.to_string(); }
bool utility::FileId::equals(utility::FileId const rhs) const {
{
return ((((*this).id) == ((rhs).id)));
}
}

utility::FileId::FileId(size_t a_id) :id(a_id){}

}
} // namespace Jakt
