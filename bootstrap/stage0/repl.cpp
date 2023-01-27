#include "repl.h"
namespace Jakt {
namespace repl {
DeprecatedString serialize_unary_operation(types::CheckedUnaryOperator const op,DeprecatedString const expr) {
{
return (JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<DeprecatedString, DeprecatedString>{
auto&& __jakt_match_variant = op;
switch(__jakt_match_variant.index()) {
case 0: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::CheckedUnaryOperator::PreIncrement>();
return JaktInternal::ExplicitValue((Jakt::DeprecatedString("++"sv) + expr));
};/*case end*/
case 1: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::CheckedUnaryOperator::PostIncrement>();
return JaktInternal::ExplicitValue((expr + Jakt::DeprecatedString("++"sv)));
};/*case end*/
case 2: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::CheckedUnaryOperator::PreDecrement>();
return JaktInternal::ExplicitValue((Jakt::DeprecatedString("--"sv) + expr));
};/*case end*/
case 3: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::CheckedUnaryOperator::PostDecrement>();
return JaktInternal::ExplicitValue((expr + Jakt::DeprecatedString("--"sv)));
};/*case end*/
case 4: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::CheckedUnaryOperator::Negate>();
return JaktInternal::ExplicitValue((Jakt::DeprecatedString("-"sv) + expr));
};/*case end*/
case 5: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::CheckedUnaryOperator::Dereference>();
return JaktInternal::ExplicitValue((Jakt::DeprecatedString("*"sv) + expr));
};/*case end*/
case 6: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::CheckedUnaryOperator::RawAddress>();
return JaktInternal::ExplicitValue((Jakt::DeprecatedString("&raw "sv) + expr));
};/*case end*/
case 7: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::CheckedUnaryOperator::Reference>();
return JaktInternal::ExplicitValue((Jakt::DeprecatedString("&"sv) + expr));
};/*case end*/
case 8: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::CheckedUnaryOperator::MutableReference>();
return JaktInternal::ExplicitValue((Jakt::DeprecatedString("&mut "sv) + expr));
};/*case end*/
case 9: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::CheckedUnaryOperator::LogicalNot>();
return JaktInternal::ExplicitValue((Jakt::DeprecatedString("not "sv) + expr));
};/*case end*/
case 10: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::CheckedUnaryOperator::BitwiseNot>();
return JaktInternal::ExplicitValue((Jakt::DeprecatedString("~"sv) + expr));
};/*case end*/
default: {
return JaktInternal::ExplicitValue(((Jakt::DeprecatedString("(<Unimplemented unary operator> "sv) + expr) + Jakt::DeprecatedString(")"sv)));
};/*case end*/
}/*switch end*/
}()
)));
}
}

ErrorOr<DeprecatedString> serialize_ast_node(NonnullRefPtr<typename types::CheckedExpression> const node) {
{
return (JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<DeprecatedString, ErrorOr<DeprecatedString>>{
auto&& __jakt_match_variant = *node;
switch(__jakt_match_variant.index()) {
case 0: {
auto&& __jakt_match_value = __jakt_match_variant.template get<types::CheckedExpression::Boolean>();bool const& val = __jakt_match_value.val;
return JaktInternal::ExplicitValue(TRY((__jakt_format(Jakt::DeprecatedString("{}"sv),val))));
};/*case end*/
case 1: {
auto&& __jakt_match_value = __jakt_match_variant.template get<types::CheckedExpression::NumericConstant>();types::CheckedNumericConstant const& val = __jakt_match_value.val;
return JaktInternal::ExplicitValue(JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<DeprecatedString, ErrorOr<DeprecatedString>>{
auto&& __jakt_match_variant = val;
switch(__jakt_match_variant.index()) {
case 0: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::CheckedNumericConstant::I8>();
i8 const& value = __jakt_match_value.value;
return JaktInternal::ExplicitValue(TRY((__jakt_format(Jakt::DeprecatedString("{}i8"sv),value))));
};/*case end*/
case 1: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::CheckedNumericConstant::I16>();
i16 const& value = __jakt_match_value.value;
return JaktInternal::ExplicitValue(TRY((__jakt_format(Jakt::DeprecatedString("{}i16"sv),value))));
};/*case end*/
case 2: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::CheckedNumericConstant::I32>();
i32 const& value = __jakt_match_value.value;
return JaktInternal::ExplicitValue(TRY((__jakt_format(Jakt::DeprecatedString("{}i32"sv),value))));
};/*case end*/
case 3: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::CheckedNumericConstant::I64>();
i64 const& value = __jakt_match_value.value;
return JaktInternal::ExplicitValue(TRY((__jakt_format(Jakt::DeprecatedString("{}i64"sv),value))));
};/*case end*/
case 4: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::CheckedNumericConstant::U8>();
u8 const& value = __jakt_match_value.value;
return JaktInternal::ExplicitValue(TRY((__jakt_format(Jakt::DeprecatedString("{}u8"sv),value))));
};/*case end*/
case 5: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::CheckedNumericConstant::U16>();
u16 const& value = __jakt_match_value.value;
return JaktInternal::ExplicitValue(TRY((__jakt_format(Jakt::DeprecatedString("{}u16"sv),value))));
};/*case end*/
case 6: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::CheckedNumericConstant::U32>();
u32 const& value = __jakt_match_value.value;
return JaktInternal::ExplicitValue(TRY((__jakt_format(Jakt::DeprecatedString("{}u32"sv),value))));
};/*case end*/
case 7: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::CheckedNumericConstant::U64>();
u64 const& value = __jakt_match_value.value;
return JaktInternal::ExplicitValue(TRY((__jakt_format(Jakt::DeprecatedString("{}u64"sv),value))));
};/*case end*/
case 9: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::CheckedNumericConstant::F32>();
f32 const& value = __jakt_match_value.value;
return JaktInternal::ExplicitValue(TRY((__jakt_format(Jakt::DeprecatedString("{}f32"sv),value))));
};/*case end*/
case 10: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::CheckedNumericConstant::F64>();
f64 const& value = __jakt_match_value.value;
return JaktInternal::ExplicitValue(TRY((__jakt_format(Jakt::DeprecatedString("{}f64"sv),value))));
};/*case end*/
case 8: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::CheckedNumericConstant::USize>();
u64 const& value = __jakt_match_value.value;
return JaktInternal::ExplicitValue(TRY((__jakt_format(Jakt::DeprecatedString("{}uz"sv),value))));
};/*case end*/
default: VERIFY_NOT_REACHED();}/*switch end*/
}()
)));
};/*case end*/
case 2: {
auto&& __jakt_match_value = __jakt_match_variant.template get<types::CheckedExpression::QuotedString>();types::CheckedStringLiteral const& val = __jakt_match_value.val;
return JaktInternal::ExplicitValue(JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<DeprecatedString,ErrorOr<DeprecatedString>>{
auto __jakt_enum_value = (((((val).type_id)).equals(types::builtin( types::BuiltinType { typename types::BuiltinType::JaktString() } ))));
if (__jakt_enum_value == true) {
return JaktInternal::ExplicitValue(TRY((__jakt_format(Jakt::DeprecatedString("\"{}\""sv),((val).to_string())))));
}
else {
return JaktInternal::ExplicitValue(TRY((__jakt_format(Jakt::DeprecatedString("(overloaded) \"{}\""sv),((val).to_string())))));
}
}()))
);
};/*case end*/
case 3: {
auto&& __jakt_match_value = __jakt_match_variant.template get<types::CheckedExpression::ByteConstant>();DeprecatedString const& val = __jakt_match_value.val;
return JaktInternal::ExplicitValue(TRY((__jakt_format(Jakt::DeprecatedString("b'{}'"sv),val))));
};/*case end*/
case 4: {
auto&& __jakt_match_value = __jakt_match_variant.template get<types::CheckedExpression::CharacterConstant>();DeprecatedString const& val = __jakt_match_value.val;
return JaktInternal::ExplicitValue(TRY((__jakt_format(Jakt::DeprecatedString("'{}'"sv),val))));
};/*case end*/
case 5: {
auto&& __jakt_match_value = __jakt_match_variant.template get<types::CheckedExpression::UnaryOp>();NonnullRefPtr<typename types::CheckedExpression> const& expr = __jakt_match_value.expr;
types::CheckedUnaryOperator const& op = __jakt_match_value.op;
return JaktInternal::ExplicitValue(repl::serialize_unary_operation(op,TRY((repl::serialize_ast_node(expr)))));
};/*case end*/
case 7: {
auto&& __jakt_match_value = __jakt_match_variant.template get<types::CheckedExpression::JaktTuple>();JaktInternal::DynamicArray<NonnullRefPtr<typename types::CheckedExpression>> const& vals = __jakt_match_value.vals;
return JaktInternal::ExplicitValue(({ Optional<DeprecatedString> __jakt_var_691; {
DeprecatedStringBuilder builder = TRY((DeprecatedStringBuilder::create()));
TRY((((builder).append_string(Jakt::DeprecatedString("("sv)))));
{
JaktInternal::Range<size_t> _magic = (JaktInternal::Range<size_t>{static_cast<size_t>(static_cast<size_t>(0ULL)),static_cast<size_t>(((vals).size()))});
for (;;){
JaktInternal::Optional<size_t> _magic_value = ((_magic).next());
if ((!(((_magic_value).has_value())))){
break;
}
size_t i = (_magic_value.value());
{
if ((i != static_cast<size_t>(0ULL))){
TRY((((builder).append_string(Jakt::DeprecatedString(", "sv)))));
}
TRY((((builder).append_string(TRY((repl::serialize_ast_node(((vals)[i]))))))));
}

}
}

TRY((((builder).append_string(Jakt::DeprecatedString(")"sv)))));
__jakt_var_691 = TRY((((builder).to_string()))); goto __jakt_label_629;

}
__jakt_label_629:; __jakt_var_691.release_value(); }));
};/*case end*/
case 8: {
auto&& __jakt_match_value = __jakt_match_variant.template get<types::CheckedExpression::Range>();JaktInternal::Optional<NonnullRefPtr<typename types::CheckedExpression>> const& from = __jakt_match_value.from;
JaktInternal::Optional<NonnullRefPtr<typename types::CheckedExpression>> const& to = __jakt_match_value.to;
return JaktInternal::ExplicitValue(({ Optional<DeprecatedString> __jakt_var_692; {
DeprecatedString from_output = Jakt::DeprecatedString(""sv);
if (((from).has_value())){
(from_output = TRY((repl::serialize_ast_node((from.value())))));
}
DeprecatedString to_output = Jakt::DeprecatedString(""sv);
if (((to).has_value())){
(to_output = TRY((repl::serialize_ast_node((to.value())))));
}
__jakt_var_692 = TRY((__jakt_format(Jakt::DeprecatedString("{}..{}"sv),from_output,to_output))); goto __jakt_label_630;

}
__jakt_label_630:; __jakt_var_692.release_value(); }));
};/*case end*/
case 9: {
auto&& __jakt_match_value = __jakt_match_variant.template get<types::CheckedExpression::JaktArray>();JaktInternal::DynamicArray<NonnullRefPtr<typename types::CheckedExpression>> const& vals = __jakt_match_value.vals;
return JaktInternal::ExplicitValue(({ Optional<DeprecatedString> __jakt_var_693; {
DeprecatedStringBuilder builder = TRY((DeprecatedStringBuilder::create()));
TRY((((builder).append_string(Jakt::DeprecatedString("["sv)))));
{
JaktInternal::Range<size_t> _magic = (JaktInternal::Range<size_t>{static_cast<size_t>(static_cast<size_t>(0ULL)),static_cast<size_t>(((vals).size()))});
for (;;){
JaktInternal::Optional<size_t> _magic_value = ((_magic).next());
if ((!(((_magic_value).has_value())))){
break;
}
size_t i = (_magic_value.value());
{
if ((i != static_cast<size_t>(0ULL))){
TRY((((builder).append_string(Jakt::DeprecatedString(", "sv)))));
}
TRY((((builder).append_string(TRY((repl::serialize_ast_node(((vals)[i]))))))));
}

}
}

TRY((((builder).append_string(Jakt::DeprecatedString("]"sv)))));
__jakt_var_693 = TRY((((builder).to_string()))); goto __jakt_label_631;

}
__jakt_label_631:; __jakt_var_693.release_value(); }));
};/*case end*/
case 10: {
auto&& __jakt_match_value = __jakt_match_variant.template get<types::CheckedExpression::JaktSet>();JaktInternal::DynamicArray<NonnullRefPtr<typename types::CheckedExpression>> const& vals = __jakt_match_value.vals;
return JaktInternal::ExplicitValue(({ Optional<DeprecatedString> __jakt_var_694; {
DeprecatedStringBuilder builder = TRY((DeprecatedStringBuilder::create()));
TRY((((builder).append_string(Jakt::DeprecatedString("{"sv)))));
{
JaktInternal::Range<size_t> _magic = (JaktInternal::Range<size_t>{static_cast<size_t>(static_cast<size_t>(0ULL)),static_cast<size_t>(((vals).size()))});
for (;;){
JaktInternal::Optional<size_t> _magic_value = ((_magic).next());
if ((!(((_magic_value).has_value())))){
break;
}
size_t i = (_magic_value.value());
{
if ((i != static_cast<size_t>(0ULL))){
TRY((((builder).append_string(Jakt::DeprecatedString(", "sv)))));
}
TRY((((builder).append_string(TRY((repl::serialize_ast_node(((vals)[i]))))))));
}

}
}

TRY((((builder).append_string(Jakt::DeprecatedString("}"sv)))));
__jakt_var_694 = TRY((((builder).to_string()))); goto __jakt_label_632;

}
__jakt_label_632:; __jakt_var_694.release_value(); }));
};/*case end*/
case 11: {
auto&& __jakt_match_value = __jakt_match_variant.template get<types::CheckedExpression::JaktDictionary>();JaktInternal::DynamicArray<JaktInternal::Tuple<NonnullRefPtr<typename types::CheckedExpression>,NonnullRefPtr<typename types::CheckedExpression>>> const& vals = __jakt_match_value.vals;
return JaktInternal::ExplicitValue(({ Optional<DeprecatedString> __jakt_var_695; {
DeprecatedStringBuilder builder = TRY((DeprecatedStringBuilder::create()));
TRY((((builder).append_string(Jakt::DeprecatedString("["sv)))));
{
JaktInternal::Range<size_t> _magic = (JaktInternal::Range<size_t>{static_cast<size_t>(static_cast<size_t>(0ULL)),static_cast<size_t>(((vals).size()))});
for (;;){
JaktInternal::Optional<size_t> _magic_value = ((_magic).next());
if ((!(((_magic_value).has_value())))){
break;
}
size_t i = (_magic_value.value());
{
if ((i != static_cast<size_t>(0ULL))){
TRY((((builder).append_string(Jakt::DeprecatedString(", "sv)))));
}
JaktInternal::Tuple<NonnullRefPtr<typename types::CheckedExpression>,NonnullRefPtr<typename types::CheckedExpression>> const val = ((vals)[i]);
TRY((((builder).append_string(TRY((repl::serialize_ast_node(((val).template get<0>()))))))));
TRY((((builder).append_string(Jakt::DeprecatedString(": "sv)))));
TRY((((builder).append_string(TRY((repl::serialize_ast_node(((val).template get<1>()))))))));
}

}
}

TRY((((builder).append_string(Jakt::DeprecatedString("]"sv)))));
__jakt_var_695 = TRY((((builder).to_string()))); goto __jakt_label_633;

}
__jakt_label_633:; __jakt_var_695.release_value(); }));
};/*case end*/
case 12: {
auto&& __jakt_match_value = __jakt_match_variant.template get<types::CheckedExpression::IndexedExpression>();NonnullRefPtr<typename types::CheckedExpression> const& expr = __jakt_match_value.expr;
NonnullRefPtr<typename types::CheckedExpression> const& index = __jakt_match_value.index;
return JaktInternal::ExplicitValue(TRY((__jakt_format(Jakt::DeprecatedString("{}[{}]"sv),TRY((repl::serialize_ast_node(expr))),TRY((repl::serialize_ast_node(index)))))));
};/*case end*/
case 13: {
auto&& __jakt_match_value = __jakt_match_variant.template get<types::CheckedExpression::IndexedDictionary>();NonnullRefPtr<typename types::CheckedExpression> const& expr = __jakt_match_value.expr;
NonnullRefPtr<typename types::CheckedExpression> const& index = __jakt_match_value.index;
return JaktInternal::ExplicitValue(TRY((__jakt_format(Jakt::DeprecatedString("{}[{}]"sv),TRY((repl::serialize_ast_node(expr))),TRY((repl::serialize_ast_node(index)))))));
};/*case end*/
case 14: {
auto&& __jakt_match_value = __jakt_match_variant.template get<types::CheckedExpression::IndexedTuple>();NonnullRefPtr<typename types::CheckedExpression> const& expr = __jakt_match_value.expr;
size_t const& index = __jakt_match_value.index;
return JaktInternal::ExplicitValue(TRY((__jakt_format(Jakt::DeprecatedString("{}.{}"sv),TRY((repl::serialize_ast_node(expr))),index))));
};/*case end*/
case 15: {
auto&& __jakt_match_value = __jakt_match_variant.template get<types::CheckedExpression::IndexedStruct>();NonnullRefPtr<typename types::CheckedExpression> const& expr = __jakt_match_value.expr;
DeprecatedString const& index = __jakt_match_value.index;
return JaktInternal::ExplicitValue(TRY((__jakt_format(Jakt::DeprecatedString("{}.{}"sv),TRY((repl::serialize_ast_node(expr))),index))));
};/*case end*/
case 21: {
auto&& __jakt_match_value = __jakt_match_variant.template get<types::CheckedExpression::NamespacedVar>();JaktInternal::DynamicArray<types::CheckedNamespace> const& namespaces = __jakt_match_value.namespaces;
NonnullRefPtr<types::CheckedVariable> const& var = __jakt_match_value.var;
return JaktInternal::ExplicitValue(({ Optional<DeprecatedString> __jakt_var_696; {
DeprecatedStringBuilder builder = TRY((DeprecatedStringBuilder::create()));
{
JaktInternal::ArrayIterator<types::CheckedNamespace> _magic = ((namespaces).iterator());
for (;;){
JaktInternal::Optional<types::CheckedNamespace> _magic_value = ((_magic).next());
if ((!(((_magic_value).has_value())))){
break;
}
types::CheckedNamespace namespace_ = (_magic_value.value());
{
TRY((((builder).append_string(((namespace_).name)))));
TRY((((builder).append_string(Jakt::DeprecatedString("::"sv)))));
}

}
}

TRY((((builder).append_string(((var)->name)))));
__jakt_var_696 = TRY((((builder).to_string()))); goto __jakt_label_634;

}
__jakt_label_634:; __jakt_var_696.release_value(); }));
};/*case end*/
case 22: {
auto&& __jakt_match_value = __jakt_match_variant.template get<types::CheckedExpression::Var>();NonnullRefPtr<types::CheckedVariable> const& var = __jakt_match_value.var;
return JaktInternal::ExplicitValue(((var)->name));
};/*case end*/
case 23: {
auto&& __jakt_match_value = __jakt_match_variant.template get<types::CheckedExpression::OptionalNone>();return JaktInternal::ExplicitValue(Jakt::DeprecatedString("None"sv));
};/*case end*/
case 24: {
auto&& __jakt_match_value = __jakt_match_variant.template get<types::CheckedExpression::OptionalSome>();NonnullRefPtr<typename types::CheckedExpression> const& expr = __jakt_match_value.expr;
return JaktInternal::ExplicitValue(TRY((__jakt_format(Jakt::DeprecatedString("Some({})"sv),TRY((repl::serialize_ast_node(expr)))))));
};/*case end*/
case 25: {
auto&& __jakt_match_value = __jakt_match_variant.template get<types::CheckedExpression::ForcedUnwrap>();NonnullRefPtr<typename types::CheckedExpression> const& expr = __jakt_match_value.expr;
return JaktInternal::ExplicitValue(TRY((__jakt_format(Jakt::DeprecatedString("{}!"sv),TRY((repl::serialize_ast_node(expr)))))));
};/*case end*/
case 19: {
auto&& __jakt_match_value = __jakt_match_variant.template get<types::CheckedExpression::Call>();types::CheckedCall const& call = __jakt_match_value.call;
return JaktInternal::ExplicitValue(({ Optional<DeprecatedString> __jakt_var_697; {
DeprecatedStringBuilder builder = TRY((DeprecatedStringBuilder::create()));
{
JaktInternal::ArrayIterator<types::ResolvedNamespace> _magic = ((((call).namespace_)).iterator());
for (;;){
JaktInternal::Optional<types::ResolvedNamespace> _magic_value = ((_magic).next());
if ((!(((_magic_value).has_value())))){
break;
}
types::ResolvedNamespace namespace_ = (_magic_value.value());
{
TRY((((builder).append_string(((namespace_).name)))));
TRY((((builder).append_string(Jakt::DeprecatedString("::"sv)))));
}

}
}

TRY((((builder).append_string(((call).name)))));
TRY((((builder).append_string(Jakt::DeprecatedString("("sv)))));
{
JaktInternal::Range<size_t> _magic = (JaktInternal::Range<size_t>{static_cast<size_t>(static_cast<size_t>(0ULL)),static_cast<size_t>(((((call).args)).size()))});
for (;;){
JaktInternal::Optional<size_t> _magic_value = ((_magic).next());
if ((!(((_magic_value).has_value())))){
break;
}
size_t i = (_magic_value.value());
{
if ((i != static_cast<size_t>(0ULL))){
TRY((((builder).append_string(Jakt::DeprecatedString(", "sv)))));
}
JaktInternal::Tuple<DeprecatedString,NonnullRefPtr<typename types::CheckedExpression>> const arg = ((((call).args))[i]);
if ((!(((((arg).template get<0>())).is_empty())))){
TRY((((builder).append_string(((arg).template get<0>())))));
TRY((((builder).append_string(Jakt::DeprecatedString(": "sv)))));
}
TRY((((builder).append_string(TRY((repl::serialize_ast_node(((arg).template get<1>()))))))));
}

}
}

TRY((((builder).append_string(Jakt::DeprecatedString(")"sv)))));
__jakt_var_697 = TRY((((builder).to_string()))); goto __jakt_label_635;

}
__jakt_label_635:; __jakt_var_697.release_value(); }));
};/*case end*/
case 30: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::CheckedExpression::Garbage>();
return JaktInternal::ExplicitValue(Jakt::DeprecatedString("<Garbage>"sv));
};/*case end*/
default: {
return JaktInternal::ExplicitValue(Jakt::DeprecatedString("<Unimplemented>"sv));
};/*case end*/
}/*switch end*/
}()
)));
}
}

ErrorOr<DeprecatedString> repl::Editor::debug_description() const { auto builder = MUST(DeprecatedStringBuilder::create());TRY(builder.append("Editor("sv));{
JaktInternal::PrettyPrint::ScopedLevelIncrease increase_indent {};
TRY(JaktInternal::PrettyPrint::output_indentation(builder));TRY(builder.append("standard_input_file: "sv));TRY(builder.appendff("{}, ", standard_input_file));
TRY(JaktInternal::PrettyPrint::output_indentation(builder));TRY(builder.append("line_pointer: "sv));TRY(builder.appendff("{}, ", line_pointer));
TRY(JaktInternal::PrettyPrint::output_indentation(builder));TRY(builder.append("prompt: "sv));TRY(builder.appendff("\"{}\"", prompt));
}
TRY(builder.append(")"sv));return builder.to_string(); }
ErrorOr<repl::Editor> repl::Editor::create(DeprecatedString const prompt) {
{
FILE* std_in = fopen(((Jakt::DeprecatedString("/dev/stdin"sv)).characters()),((Jakt::DeprecatedString("r"sv)).characters()));
if ((std_in == utility::null<FILE>())){
warnln(Jakt::DeprecatedString("Could not open /dev/stdin for reading"sv));
return Error::from_errno(static_cast<i32>(42));
}
repl::Editor const editor = repl::Editor(std_in,utility::allocate<char>(static_cast<size_t>(4096ULL)),prompt);
return (editor);
}
}

void repl::Editor::destroy() {
{
fclose(((*this).standard_input_file));
{
free(line_pointer);
}

}
}

repl::Editor::Editor(FILE* a_standard_input_file, char* a_line_pointer, DeprecatedString a_prompt) :standard_input_file(a_standard_input_file), line_pointer(a_line_pointer), prompt(a_prompt){}

ErrorOr<repl::LineResult> repl::Editor::get_line() {
{
warn(Jakt::DeprecatedString("{}"sv),((*this).prompt));
DeprecatedStringBuilder builder = TRY((DeprecatedStringBuilder::create()));
{
char* const c_string = fgets(((*this).line_pointer),static_cast<size_t>(4096ULL),((*this).standard_input_file));
if ((c_string == utility::null<char>())){
return ( repl::LineResult { typename repl::LineResult::Eof() } );
}
TRY((((builder).append_c_string(c_string))));
}

return ( repl::LineResult { typename repl::LineResult::Line(TRY((((builder).to_string())))) } );
}
}

ErrorOr<DeprecatedString> repl::REPL::debug_description() const { auto builder = MUST(DeprecatedStringBuilder::create());TRY(builder.append("REPL("sv));{
JaktInternal::PrettyPrint::ScopedLevelIncrease increase_indent {};
TRY(JaktInternal::PrettyPrint::output_indentation(builder));TRY(builder.append("compiler: "sv));TRY(builder.appendff("{}, ", *compiler));
TRY(JaktInternal::PrettyPrint::output_indentation(builder));TRY(builder.append("typechecker: "sv));TRY(builder.appendff("{}, ", typechecker));
TRY(JaktInternal::PrettyPrint::output_indentation(builder));TRY(builder.append("root_scope_id: "sv));TRY(builder.appendff("{}, ", root_scope_id));
TRY(JaktInternal::PrettyPrint::output_indentation(builder));TRY(builder.append("root_interpreter_scope: "sv));TRY(builder.appendff("{}, ", *root_interpreter_scope));
TRY(JaktInternal::PrettyPrint::output_indentation(builder));TRY(builder.append("file_id: "sv));TRY(builder.appendff("{}", file_id));
}
TRY(builder.append(")"sv));return builder.to_string(); }
ErrorOr<repl::REPL> repl::REPL::create(jakt__path::Path const runtime_path,JaktInternal::Optional<DeprecatedString> const target_triple) {
{
NonnullRefPtr<compiler::Compiler> compiler = TRY((compiler::Compiler::create((TRY((DynamicArray<jakt__path::Path>::create_with({})))),(TRY((Dictionary<DeprecatedString, utility::FileId>::create_with_entries({})))),(TRY((DynamicArray<error::JaktError>::create_with({})))),JaktInternal::OptionalNone(),(TRY((DynamicArray<u8>::create_with({})))),false,false,false,false,runtime_path,(TRY((DynamicArray<DeprecatedString>::create_with({})))),false,false,false,false,target_triple)));
TRY((((compiler)->load_prelude())));
utility::FileId const file_id = TRY((((compiler)->get_file_id_or_register(TRY((jakt__path::Path::from_string(Jakt::DeprecatedString("<repl>"sv))))))));
types::ModuleId const placeholder_module_id = types::ModuleId(static_cast<size_t>(0ULL));
DeprecatedString const root_module_name = Jakt::DeprecatedString("repl"sv);
typechecker::Typechecker typechecker = typechecker::Typechecker(compiler,TRY((types::CheckedProgram::create(compiler,(TRY((DynamicArray<NonnullRefPtr<types::Module>>::create_with({})))),(TRY((Dictionary<DeprecatedString, types::LoadedModule>::create_with_entries({}))))))),placeholder_module_id,types::TypeId::none(),JaktInternal::OptionalNone(),false,static_cast<size_t>(0ULL),false,((compiler)->dump_type_hints),((compiler)->dump_try_hints),static_cast<u64>(0ULL),types::GenericInferences((TRY((Dictionary<DeprecatedString, DeprecatedString>::create_with_entries({}))))),JaktInternal::OptionalNone(),root_module_name);
(((compiler)->current_file) = file_id);
TRY((((typechecker).include_prelude())));
types::ModuleId const root_module_id = TRY((((typechecker).create_module(root_module_name,true,JaktInternal::OptionalNone()))));
(((typechecker).current_module_id) = root_module_id);
TRY((((((typechecker).program))->set_loaded_module(root_module_name,types::LoadedModule(root_module_id,file_id)))));
types::ScopeId const PRELUDE_SCOPE_ID = ((typechecker).prelude_scope_id());
types::ScopeId const root_scope_id = TRY((((typechecker).create_scope(PRELUDE_SCOPE_ID,true,Jakt::DeprecatedString("root"sv)))));
NonnullRefPtr<interpreter::InterpreterScope> const root_interpreter_scope = TRY((interpreter::InterpreterScope::create((TRY((Dictionary<DeprecatedString, types::Value>::create_with_entries({})))),JaktInternal::OptionalNone(),(TRY((Dictionary<DeprecatedString, types::TypeId>::create_with_entries({})))))));
return (repl::REPL(compiler,typechecker,root_scope_id,root_interpreter_scope,file_id));
}
}

ErrorOr<void> repl::REPL::run() {
{
repl::Editor editor = TRY((repl::Editor::create(Jakt::DeprecatedString("> "sv))));
ScopeGuard __jakt_var_698([&] {
((editor).destroy());
});
for (;;){
if ((!(((((((*this).compiler))->errors)).is_empty())))){
TRY((((((*this).compiler))->print_errors())));
JaktInternal::DynamicArray<error::JaktError> const arr = (TRY((DynamicArray<error::JaktError>::create_with({}))));
(((((*this).compiler))->errors) = arr);
}
repl::LineResult const line_result = ({ Optional<repl::LineResult> __jakt_var_699;
auto __jakt_var_700 = [&]() -> ErrorOr<repl::LineResult> { return TRY((((editor).get_line()))); }();
if (__jakt_var_700.is_error()) {auto error = __jakt_var_700.release_error();
{
return {};
}
} else {__jakt_var_699 = __jakt_var_700.release_value();
}
__jakt_var_699.release_value(); });
if (((line_result).index() == 0 /* Line */)){
DeprecatedString const line = ((line_result).get<repl::LineResult::Line>()).value;
if ((line == Jakt::DeprecatedString(".exit\n"sv))){
break;
}
size_t pos = static_cast<size_t>(0ULL);
JaktInternal::DynamicArray<u8> bytes_ = (TRY((DynamicArray<u8>::create_with({}))));
TRY((((bytes_).ensure_capacity(((line).length())))));
while ((pos < ((line).length()))){
TRY((((bytes_).push(((line).byte_at(pos))))));
(++(pos));
}
(((((*this).compiler))->current_file) = ((*this).file_id));
(((((*this).compiler))->current_file_contents) = bytes_);
JaktInternal::DynamicArray<lexer::Token> const tokens = ({ Optional<JaktInternal::DynamicArray<lexer::Token>> __jakt_var_701;
auto __jakt_var_702 = [&]() -> ErrorOr<JaktInternal::DynamicArray<lexer::Token>> { return TRY((lexer::Lexer::lex(((*this).compiler)))); }();
if (__jakt_var_702.is_error()) {{
continue;
}
} else {__jakt_var_701 = __jakt_var_702.release_value();
}
__jakt_var_701.release_value(); });
if (((tokens).is_empty())){
continue;
}
parser::Parser parser = parser::Parser(static_cast<size_t>(0ULL),tokens,((*this).compiler),true);
lexer::Token const first_token = (((tokens).first()).value());
if (((((((((((first_token).index() == 75 /* Function */) || ((first_token).index() == 76 /* Comptime */)) || ((first_token).index() == 94 /* Struct */)) || ((first_token).index() == 66 /* Class */)) || ((first_token).index() == 71 /* Enum */)) || ((first_token).index() == 63 /* Boxed */)) || ((first_token).index() == 85 /* Namespace */)) || ((first_token).index() == 78 /* Import */)) || ((first_token).index() == 108 /* Trait */))){
parser::ParsedNamespace const parsed_namespace = ({ Optional<parser::ParsedNamespace> __jakt_var_703;
auto __jakt_var_704 = [&]() -> ErrorOr<parser::ParsedNamespace> { return TRY((((parser).parse_namespace()))); }();
if (__jakt_var_704.is_error()) {{
TRY((((*this).handle_possible_error())));
continue;
}
} else {__jakt_var_703 = __jakt_var_704.release_value();
}
__jakt_var_703.release_value(); });
if (TRY((((*this).handle_possible_error())))){
continue;
}
auto __jakt_var_706 = [&]() -> ErrorOr<void> { return TRY((((((*this).typechecker)).typecheck_module(parsed_namespace,((*this).root_scope_id))))), ErrorOr<void>{}; }();
if (__jakt_var_706.is_error()) {{
TRY((((*this).handle_possible_error())));
continue;
}
}
;
TRY((((*this).handle_possible_error())));
continue;
}
NonnullRefPtr<typename parser::ParsedStatement> const parsed_statement = ({ Optional<NonnullRefPtr<typename parser::ParsedStatement>> __jakt_var_707;
auto __jakt_var_708 = [&]() -> ErrorOr<NonnullRefPtr<typename parser::ParsedStatement>> { return TRY((((parser).parse_statement(true)))); }();
if (__jakt_var_708.is_error()) {{
TRY((((*this).handle_possible_error())));
continue;
}
} else {__jakt_var_707 = __jakt_var_708.release_value();
}
__jakt_var_707.release_value(); });
if (TRY((((*this).handle_possible_error())))){
continue;
}
NonnullRefPtr<typename types::CheckedStatement> const checked_statement = ({ Optional<NonnullRefPtr<typename types::CheckedStatement>> __jakt_var_709;
auto __jakt_var_710 = [&]() -> ErrorOr<NonnullRefPtr<typename types::CheckedStatement>> { return TRY((((((*this).typechecker)).typecheck_statement(parsed_statement,((*this).root_scope_id), types::SafetyMode { typename types::SafetyMode::Safe() } ,JaktInternal::OptionalNone())))); }();
if (__jakt_var_710.is_error()) {{
TRY((((*this).handle_possible_error())));
continue;
}
} else {__jakt_var_709 = __jakt_var_710.release_value();
}
__jakt_var_709.release_value(); });
if (TRY((((*this).handle_possible_error())))){
continue;
}
NonnullRefPtr<interpreter::Interpreter> interpreter = TRY((interpreter::Interpreter::create(((*this).compiler),((((*this).typechecker)).program),(TRY((DynamicArray<utility::Span>::create_with({})))))));
interpreter::StatementResult const result = ({ Optional<interpreter::StatementResult> __jakt_var_711;
auto __jakt_var_712 = [&]() -> ErrorOr<interpreter::StatementResult> { return TRY((((interpreter)->execute_statement(checked_statement,((*this).root_interpreter_scope),utility::Span(((*this).file_id),static_cast<size_t>(0ULL),((line).length())))))); }();
if (__jakt_var_712.is_error()) {{
TRY((((*this).handle_possible_error())));
continue;
}
} else {__jakt_var_711 = __jakt_var_712.release_value();
}
__jakt_var_711.release_value(); });
if (TRY((((*this).handle_possible_error())))){
continue;
}
JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_AT_LOOP(([&]() -> JaktInternal::ExplicitValueOrControlFlow<void, ErrorOr<void>>{
auto&& __jakt_match_variant = result;
switch(__jakt_match_variant.index()) {
case 0: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename interpreter::StatementResult::Return>();
types::Value const& value = __jakt_match_value.value;
{
if (((((value).impl))->index() == 0 /* Void */)){
return JaktInternal::LoopContinue{};
}
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 5: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename interpreter::StatementResult::JustValue>();
types::Value const& value = __jakt_match_value.value;
{
if (((((value).impl))->index() == 0 /* Void */)){
return JaktInternal::LoopContinue{};
}
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 1: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename interpreter::StatementResult::Throw>();
types::Value const& value = __jakt_match_value.value;
{
if (((((value).impl))->index() == 0 /* Void */)){
return JaktInternal::LoopContinue{};
}
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 4: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename interpreter::StatementResult::Break>();
{
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 3: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename interpreter::StatementResult::Continue>();
{
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 2: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename interpreter::StatementResult::Yield>();
{
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
default: VERIFY_NOT_REACHED();}/*switch end*/
}()
));
DeprecatedString const output = JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_AT_LOOP(([&]() -> JaktInternal::ExplicitValueOrControlFlow<DeprecatedString, ErrorOr<void>>{
auto&& __jakt_match_variant = result;
switch(__jakt_match_variant.index()) {
case 0: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename interpreter::StatementResult::Return>();
types::Value const& value = __jakt_match_value.value;
return JaktInternal::ExplicitValue(TRY((repl::serialize_ast_node(TRY((interpreter::value_to_checked_expression(value,interpreter)))))));
};/*case end*/
case 5: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename interpreter::StatementResult::JustValue>();
types::Value const& value = __jakt_match_value.value;
return JaktInternal::ExplicitValue(TRY((repl::serialize_ast_node(TRY((interpreter::value_to_checked_expression(value,interpreter)))))));
};/*case end*/
case 1: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename interpreter::StatementResult::Throw>();
types::Value const& value = __jakt_match_value.value;
return JaktInternal::ExplicitValue((Jakt::DeprecatedString("throw "sv) + TRY((repl::serialize_ast_node(TRY((interpreter::value_to_checked_expression(value,interpreter))))))));
};/*case end*/
case 4: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename interpreter::StatementResult::Break>();
{
return JaktInternal::LoopContinue{};
}
};/*case end*/
case 3: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename interpreter::StatementResult::Continue>();
{
return JaktInternal::LoopContinue{};
}
};/*case end*/
case 2: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename interpreter::StatementResult::Yield>();
{
return JaktInternal::LoopContinue{};
}
};/*case end*/
default: VERIFY_NOT_REACHED();}/*switch end*/
}()
));
outln(Jakt::DeprecatedString("= {}"sv),output);
}
else {
break;
}

}
}
return {};
}

repl::REPL::REPL(NonnullRefPtr<compiler::Compiler> a_compiler, typechecker::Typechecker a_typechecker, types::ScopeId a_root_scope_id, NonnullRefPtr<interpreter::InterpreterScope> a_root_interpreter_scope, utility::FileId a_file_id) :compiler(a_compiler), typechecker(a_typechecker), root_scope_id(a_root_scope_id), root_interpreter_scope(a_root_interpreter_scope), file_id(a_file_id){}

ErrorOr<bool> repl::REPL::handle_possible_error() {
{
TRY((((((*this).compiler))->print_errors())));
bool const has_error = (((((((*this).compiler))->errors)).size()) > static_cast<size_t>(0ULL));
JaktInternal::DynamicArray<error::JaktError> const arr = (TRY((DynamicArray<error::JaktError>::create_with({}))));
(((((*this).compiler))->errors) = arr);
return (has_error);
}
}

ErrorOr<DeprecatedString> repl::LineResult::debug_description() const {
auto builder = TRY(DeprecatedStringBuilder::create());
switch (this->index()) {case 0 /* Line */: {
[[maybe_unused]] auto const& that = this->template get<LineResult::Line>();
TRY(builder.append("LineResult::Line"sv));
TRY(builder.appendff("(\"{}\")", that.value));
break;}
case 1 /* Eof */: {
[[maybe_unused]] auto const& that = this->template get<LineResult::Eof>();
TRY(builder.append("LineResult::Eof"sv));
break;}
}
return builder.to_string();
}
}
} // namespace Jakt
