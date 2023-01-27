#include "interpreter.h"
namespace Jakt {
namespace interpreter {
ErrorOr<types::Value> cast_value_to_type(types::Value const this_value,types::TypeId const type_id,NonnullRefPtr<interpreter::Interpreter> const interpreter,bool const saturating) {
{
NonnullRefPtr<typename types::Type> const type = ((((interpreter)->program))->get_type(type_id));
bool const is_optional = JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<bool, ErrorOr<types::Value>>{
auto&& __jakt_match_variant = *type;
switch(__jakt_match_variant.index()) {
case 19: {
auto&& __jakt_match_value = __jakt_match_variant.template get<types::Type::GenericInstance>();types::StructId const& id = __jakt_match_value.id;
return JaktInternal::ExplicitValue(((id).equals(TRY((((((interpreter)->program))->find_struct_in_prelude(Jakt::DeprecatedString("Optional"sv))))))));
};/*case end*/
default: {
return JaktInternal::ExplicitValue(false);
};/*case end*/
}/*switch end*/
}()
));
return (JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<types::Value, ErrorOr<types::Value>>{
auto&& __jakt_match_variant = *type;
switch(__jakt_match_variant.index()) {
case 2: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::Type::U8>();
return JaktInternal::ExplicitValue(JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<types::Value, ErrorOr<types::Value>>{
auto&& __jakt_match_variant = *((this_value).impl);
switch(__jakt_match_variant.index()) {
case 3: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::U16>();
u16 const& value = __jakt_match_value.value;
return JaktInternal::ExplicitValue(types::Value(TRY((types::ValueImpl::template create<typename types::ValueImpl::U8>((infallible_integer_cast<u8>((value)))))),((this_value).span)));
};/*case end*/
case 4: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::U32>();
u32 const& value = __jakt_match_value.value;
return JaktInternal::ExplicitValue(types::Value(TRY((types::ValueImpl::template create<typename types::ValueImpl::U8>((infallible_integer_cast<u8>((value)))))),((this_value).span)));
};/*case end*/
case 5: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::U64>();
u64 const& value = __jakt_match_value.value;
return JaktInternal::ExplicitValue(types::Value(TRY((types::ValueImpl::template create<typename types::ValueImpl::U8>((infallible_integer_cast<u8>((value)))))),((this_value).span)));
};/*case end*/
case 12: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::USize>();
size_t const& value = __jakt_match_value.value;
return JaktInternal::ExplicitValue(types::Value(TRY((types::ValueImpl::template create<typename types::ValueImpl::U8>((infallible_integer_cast<u8>((value)))))),((this_value).span)));
};/*case end*/
default: {
return JaktInternal::ExplicitValue(JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<types::Value,ErrorOr<types::Value>>{
auto __jakt_enum_value = (is_optional);
if (__jakt_enum_value == true) {
return JaktInternal::ExplicitValue(types::Value(TRY((types::ValueImpl::template create<typename types::ValueImpl::OptionalSome>(this_value))),((this_value).span)));
}
else {
return JaktInternal::ExplicitValue(this_value);
}
}()))
);
};/*case end*/
}/*switch end*/
}()
)));
};/*case end*/
case 3: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::Type::U16>();
return JaktInternal::ExplicitValue(JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<types::Value, ErrorOr<types::Value>>{
auto&& __jakt_match_variant = *((this_value).impl);
switch(__jakt_match_variant.index()) {
case 2: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::U8>();
u8 const& value = __jakt_match_value.value;
return JaktInternal::ExplicitValue(types::Value(TRY((types::ValueImpl::template create<typename types::ValueImpl::U16>((infallible_integer_cast<u16>((value)))))),((this_value).span)));
};/*case end*/
case 4: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::U32>();
u32 const& value = __jakt_match_value.value;
return JaktInternal::ExplicitValue(types::Value(TRY((types::ValueImpl::template create<typename types::ValueImpl::U16>((infallible_integer_cast<u16>((value)))))),((this_value).span)));
};/*case end*/
case 5: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::U64>();
u64 const& value = __jakt_match_value.value;
return JaktInternal::ExplicitValue(types::Value(TRY((types::ValueImpl::template create<typename types::ValueImpl::U16>((infallible_integer_cast<u16>((value)))))),((this_value).span)));
};/*case end*/
case 12: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::USize>();
size_t const& value = __jakt_match_value.value;
return JaktInternal::ExplicitValue(types::Value(TRY((types::ValueImpl::template create<typename types::ValueImpl::U16>((infallible_integer_cast<u16>((value)))))),((this_value).span)));
};/*case end*/
default: {
return JaktInternal::ExplicitValue(JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<types::Value,ErrorOr<types::Value>>{
auto __jakt_enum_value = (is_optional);
if (__jakt_enum_value == true) {
return JaktInternal::ExplicitValue(types::Value(TRY((types::ValueImpl::template create<typename types::ValueImpl::OptionalSome>(this_value))),((this_value).span)));
}
else {
return JaktInternal::ExplicitValue(this_value);
}
}()))
);
};/*case end*/
}/*switch end*/
}()
)));
};/*case end*/
case 4: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::Type::U32>();
return JaktInternal::ExplicitValue(JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<types::Value, ErrorOr<types::Value>>{
auto&& __jakt_match_variant = *((this_value).impl);
switch(__jakt_match_variant.index()) {
case 2: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::U8>();
u8 const& value = __jakt_match_value.value;
return JaktInternal::ExplicitValue(types::Value(TRY((types::ValueImpl::template create<typename types::ValueImpl::U32>((infallible_integer_cast<u32>((value)))))),((this_value).span)));
};/*case end*/
case 3: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::U16>();
u16 const& value = __jakt_match_value.value;
return JaktInternal::ExplicitValue(types::Value(TRY((types::ValueImpl::template create<typename types::ValueImpl::U32>((infallible_integer_cast<u32>((value)))))),((this_value).span)));
};/*case end*/
case 5: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::U64>();
u64 const& value = __jakt_match_value.value;
return JaktInternal::ExplicitValue(types::Value(TRY((types::ValueImpl::template create<typename types::ValueImpl::U32>((infallible_integer_cast<u32>((value)))))),((this_value).span)));
};/*case end*/
case 12: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::USize>();
size_t const& value = __jakt_match_value.value;
return JaktInternal::ExplicitValue(types::Value(TRY((types::ValueImpl::template create<typename types::ValueImpl::U32>((infallible_integer_cast<u32>((value)))))),((this_value).span)));
};/*case end*/
default: {
return JaktInternal::ExplicitValue(JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<types::Value,ErrorOr<types::Value>>{
auto __jakt_enum_value = (is_optional);
if (__jakt_enum_value == true) {
return JaktInternal::ExplicitValue(types::Value(TRY((types::ValueImpl::template create<typename types::ValueImpl::OptionalSome>(this_value))),((this_value).span)));
}
else {
return JaktInternal::ExplicitValue(this_value);
}
}()))
);
};/*case end*/
}/*switch end*/
}()
)));
};/*case end*/
case 5: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::Type::U64>();
return JaktInternal::ExplicitValue(JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<types::Value, ErrorOr<types::Value>>{
auto&& __jakt_match_variant = *((this_value).impl);
switch(__jakt_match_variant.index()) {
case 2: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::U8>();
u8 const& value = __jakt_match_value.value;
return JaktInternal::ExplicitValue(types::Value(TRY((types::ValueImpl::template create<typename types::ValueImpl::U64>((infallible_integer_cast<u64>((value)))))),((this_value).span)));
};/*case end*/
case 3: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::U16>();
u16 const& value = __jakt_match_value.value;
return JaktInternal::ExplicitValue(types::Value(TRY((types::ValueImpl::template create<typename types::ValueImpl::U64>((infallible_integer_cast<u64>((value)))))),((this_value).span)));
};/*case end*/
case 4: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::U32>();
u32 const& value = __jakt_match_value.value;
return JaktInternal::ExplicitValue(types::Value(TRY((types::ValueImpl::template create<typename types::ValueImpl::U64>((infallible_integer_cast<u64>((value)))))),((this_value).span)));
};/*case end*/
case 12: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::USize>();
size_t const& value = __jakt_match_value.value;
return JaktInternal::ExplicitValue(types::Value(TRY((types::ValueImpl::template create<typename types::ValueImpl::U64>((infallible_integer_cast<u64>((value)))))),((this_value).span)));
};/*case end*/
default: {
return JaktInternal::ExplicitValue(JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<types::Value,ErrorOr<types::Value>>{
auto __jakt_enum_value = (is_optional);
if (__jakt_enum_value == true) {
return JaktInternal::ExplicitValue(types::Value(TRY((types::ValueImpl::template create<typename types::ValueImpl::OptionalSome>(this_value))),((this_value).span)));
}
else {
return JaktInternal::ExplicitValue(this_value);
}
}()))
);
};/*case end*/
}/*switch end*/
}()
)));
};/*case end*/
case 6: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::Type::I8>();
return JaktInternal::ExplicitValue(JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<types::Value, ErrorOr<types::Value>>{
auto&& __jakt_match_variant = *((this_value).impl);
switch(__jakt_match_variant.index()) {
case 7: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::I16>();
i16 const& value = __jakt_match_value.value;
return JaktInternal::ExplicitValue(types::Value(TRY((types::ValueImpl::template create<typename types::ValueImpl::I8>((infallible_integer_cast<i8>((value)))))),((this_value).span)));
};/*case end*/
case 8: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::I32>();
i32 const& value = __jakt_match_value.value;
return JaktInternal::ExplicitValue(types::Value(TRY((types::ValueImpl::template create<typename types::ValueImpl::I8>((infallible_integer_cast<i8>((value)))))),((this_value).span)));
};/*case end*/
case 9: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::I64>();
i64 const& value = __jakt_match_value.value;
return JaktInternal::ExplicitValue(types::Value(TRY((types::ValueImpl::template create<typename types::ValueImpl::I8>((infallible_integer_cast<i8>((value)))))),((this_value).span)));
};/*case end*/
default: {
return JaktInternal::ExplicitValue(JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<types::Value,ErrorOr<types::Value>>{
auto __jakt_enum_value = (is_optional);
if (__jakt_enum_value == true) {
return JaktInternal::ExplicitValue(types::Value(TRY((types::ValueImpl::template create<typename types::ValueImpl::OptionalSome>(this_value))),((this_value).span)));
}
else {
return JaktInternal::ExplicitValue(this_value);
}
}()))
);
};/*case end*/
}/*switch end*/
}()
)));
};/*case end*/
case 7: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::Type::I16>();
return JaktInternal::ExplicitValue(JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<types::Value, ErrorOr<types::Value>>{
auto&& __jakt_match_variant = *((this_value).impl);
switch(__jakt_match_variant.index()) {
case 6: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::I8>();
i8 const& value = __jakt_match_value.value;
return JaktInternal::ExplicitValue(types::Value(TRY((types::ValueImpl::template create<typename types::ValueImpl::I16>((infallible_integer_cast<i16>((value)))))),((this_value).span)));
};/*case end*/
case 8: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::I32>();
i32 const& value = __jakt_match_value.value;
return JaktInternal::ExplicitValue(types::Value(TRY((types::ValueImpl::template create<typename types::ValueImpl::I16>((infallible_integer_cast<i16>((value)))))),((this_value).span)));
};/*case end*/
case 9: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::I64>();
i64 const& value = __jakt_match_value.value;
return JaktInternal::ExplicitValue(types::Value(TRY((types::ValueImpl::template create<typename types::ValueImpl::I16>((infallible_integer_cast<i16>((value)))))),((this_value).span)));
};/*case end*/
default: {
return JaktInternal::ExplicitValue(JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<types::Value,ErrorOr<types::Value>>{
auto __jakt_enum_value = (is_optional);
if (__jakt_enum_value == true) {
return JaktInternal::ExplicitValue(types::Value(TRY((types::ValueImpl::template create<typename types::ValueImpl::OptionalSome>(this_value))),((this_value).span)));
}
else {
return JaktInternal::ExplicitValue(this_value);
}
}()))
);
};/*case end*/
}/*switch end*/
}()
)));
};/*case end*/
case 8: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::Type::I32>();
return JaktInternal::ExplicitValue(JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<types::Value, ErrorOr<types::Value>>{
auto&& __jakt_match_variant = *((this_value).impl);
switch(__jakt_match_variant.index()) {
case 6: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::I8>();
i8 const& value = __jakt_match_value.value;
return JaktInternal::ExplicitValue(types::Value(TRY((types::ValueImpl::template create<typename types::ValueImpl::I32>((infallible_integer_cast<i32>((value)))))),((this_value).span)));
};/*case end*/
case 7: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::I16>();
i16 const& value = __jakt_match_value.value;
return JaktInternal::ExplicitValue(types::Value(TRY((types::ValueImpl::template create<typename types::ValueImpl::I32>((infallible_integer_cast<i32>((value)))))),((this_value).span)));
};/*case end*/
case 9: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::I64>();
i64 const& value = __jakt_match_value.value;
return JaktInternal::ExplicitValue(types::Value(TRY((types::ValueImpl::template create<typename types::ValueImpl::I32>((infallible_integer_cast<i32>((value)))))),((this_value).span)));
};/*case end*/
default: {
return JaktInternal::ExplicitValue(JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<types::Value,ErrorOr<types::Value>>{
auto __jakt_enum_value = (is_optional);
if (__jakt_enum_value == true) {
return JaktInternal::ExplicitValue(types::Value(TRY((types::ValueImpl::template create<typename types::ValueImpl::OptionalSome>(this_value))),((this_value).span)));
}
else {
return JaktInternal::ExplicitValue(this_value);
}
}()))
);
};/*case end*/
}/*switch end*/
}()
)));
};/*case end*/
case 9: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::Type::I64>();
return JaktInternal::ExplicitValue(JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<types::Value, ErrorOr<types::Value>>{
auto&& __jakt_match_variant = *((this_value).impl);
switch(__jakt_match_variant.index()) {
case 6: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::I8>();
i8 const& value = __jakt_match_value.value;
return JaktInternal::ExplicitValue(types::Value(TRY((types::ValueImpl::template create<typename types::ValueImpl::I64>((infallible_integer_cast<i64>((value)))))),((this_value).span)));
};/*case end*/
case 7: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::I16>();
i16 const& value = __jakt_match_value.value;
return JaktInternal::ExplicitValue(types::Value(TRY((types::ValueImpl::template create<typename types::ValueImpl::I64>((infallible_integer_cast<i64>((value)))))),((this_value).span)));
};/*case end*/
case 8: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::I32>();
i32 const& value = __jakt_match_value.value;
return JaktInternal::ExplicitValue(types::Value(TRY((types::ValueImpl::template create<typename types::ValueImpl::I64>((infallible_integer_cast<i64>((value)))))),((this_value).span)));
};/*case end*/
default: {
return JaktInternal::ExplicitValue(JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<types::Value,ErrorOr<types::Value>>{
auto __jakt_enum_value = (is_optional);
if (__jakt_enum_value == true) {
return JaktInternal::ExplicitValue(types::Value(TRY((types::ValueImpl::template create<typename types::ValueImpl::OptionalSome>(this_value))),((this_value).span)));
}
else {
return JaktInternal::ExplicitValue(this_value);
}
}()))
);
};/*case end*/
}/*switch end*/
}()
)));
};/*case end*/
case 12: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::Type::Usize>();
return JaktInternal::ExplicitValue(JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<types::Value, ErrorOr<types::Value>>{
auto&& __jakt_match_variant = *((this_value).impl);
switch(__jakt_match_variant.index()) {
case 5: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::U64>();
u64 const& value = __jakt_match_value.value;
return JaktInternal::ExplicitValue(types::Value(TRY((types::ValueImpl::template create<typename types::ValueImpl::USize>((infallible_integer_cast<size_t>((value)))))),((this_value).span)));
};/*case end*/
default: {
return JaktInternal::ExplicitValue(JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<types::Value,ErrorOr<types::Value>>{
auto __jakt_enum_value = (is_optional);
if (__jakt_enum_value == true) {
return JaktInternal::ExplicitValue(types::Value(TRY((types::ValueImpl::template create<typename types::ValueImpl::OptionalSome>(this_value))),((this_value).span)));
}
else {
return JaktInternal::ExplicitValue(this_value);
}
}()))
);
};/*case end*/
}/*switch end*/
}()
)));
};/*case end*/
default: {
return JaktInternal::ExplicitValue(JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<types::Value,ErrorOr<types::Value>>{
auto __jakt_enum_value = (is_optional);
if (__jakt_enum_value == true) {
return JaktInternal::ExplicitValue(JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<types::Value, ErrorOr<types::Value>>{
auto&& __jakt_match_variant = *((this_value).impl);
switch(__jakt_match_variant.index()) {
case 24: {
auto&& __jakt_match_value = __jakt_match_variant.template get<types::ValueImpl::OptionalSome>();return JaktInternal::ExplicitValue(this_value);
};/*case end*/
case 25: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::OptionalNone>();
return JaktInternal::ExplicitValue(this_value);
};/*case end*/
default: {
return JaktInternal::ExplicitValue(types::Value(TRY((types::ValueImpl::template create<typename types::ValueImpl::OptionalSome>(this_value))),((this_value).span)));
};/*case end*/
}/*switch end*/
}()
)));
}
else {
return JaktInternal::ExplicitValue(this_value);
}
}()))
);
};/*case end*/
}/*switch end*/
}()
)));
}
}

ErrorOr<NonnullRefPtr<typename types::CheckedExpression>> value_to_checked_expression(types::Value const this_value,NonnullRefPtr<interpreter::Interpreter> interpreter) {
{
return (JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<NonnullRefPtr<typename types::CheckedExpression>, ErrorOr<NonnullRefPtr<typename types::CheckedExpression>>>{
auto&& __jakt_match_variant = *((this_value).impl);
switch(__jakt_match_variant.index()) {
case 0: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::Void>();
{
TRY((((interpreter)->error(Jakt::DeprecatedString("Cannot convert void to expression"sv),((this_value).span)))));
return Error::from_errno((infallible_integer_cast<i32>((interpreter::InterpretError::InvalidType))));
}
};/*case end*/
case 1: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::Bool>();
bool const& x = __jakt_match_value.value;
return JaktInternal::ExplicitValue(TRY((types::CheckedExpression::template create<typename types::CheckedExpression::Boolean>(x,((this_value).span)))));
};/*case end*/
case 2: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::U8>();
u8 const& x = __jakt_match_value.value;
return JaktInternal::ExplicitValue(TRY((types::CheckedExpression::template create<typename types::CheckedExpression::NumericConstant>( types::CheckedNumericConstant { typename types::CheckedNumericConstant::U8(x) } ,((this_value).span),types::builtin( types::BuiltinType { typename types::BuiltinType::U8() } )))));
};/*case end*/
case 3: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::U16>();
u16 const& x = __jakt_match_value.value;
return JaktInternal::ExplicitValue(TRY((types::CheckedExpression::template create<typename types::CheckedExpression::NumericConstant>( types::CheckedNumericConstant { typename types::CheckedNumericConstant::U16(x) } ,((this_value).span),types::builtin( types::BuiltinType { typename types::BuiltinType::U16() } )))));
};/*case end*/
case 4: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::U32>();
u32 const& x = __jakt_match_value.value;
return JaktInternal::ExplicitValue(TRY((types::CheckedExpression::template create<typename types::CheckedExpression::NumericConstant>( types::CheckedNumericConstant { typename types::CheckedNumericConstant::U32(x) } ,((this_value).span),types::builtin( types::BuiltinType { typename types::BuiltinType::U32() } )))));
};/*case end*/
case 5: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::U64>();
u64 const& x = __jakt_match_value.value;
return JaktInternal::ExplicitValue(TRY((types::CheckedExpression::template create<typename types::CheckedExpression::NumericConstant>( types::CheckedNumericConstant { typename types::CheckedNumericConstant::U64(x) } ,((this_value).span),types::builtin( types::BuiltinType { typename types::BuiltinType::U64() } )))));
};/*case end*/
case 6: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::I8>();
i8 const& x = __jakt_match_value.value;
return JaktInternal::ExplicitValue(TRY((types::CheckedExpression::template create<typename types::CheckedExpression::NumericConstant>( types::CheckedNumericConstant { typename types::CheckedNumericConstant::I8(x) } ,((this_value).span),types::builtin( types::BuiltinType { typename types::BuiltinType::I8() } )))));
};/*case end*/
case 7: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::I16>();
i16 const& x = __jakt_match_value.value;
return JaktInternal::ExplicitValue(TRY((types::CheckedExpression::template create<typename types::CheckedExpression::NumericConstant>( types::CheckedNumericConstant { typename types::CheckedNumericConstant::I16(x) } ,((this_value).span),types::builtin( types::BuiltinType { typename types::BuiltinType::I16() } )))));
};/*case end*/
case 8: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::I32>();
i32 const& x = __jakt_match_value.value;
return JaktInternal::ExplicitValue(TRY((types::CheckedExpression::template create<typename types::CheckedExpression::NumericConstant>( types::CheckedNumericConstant { typename types::CheckedNumericConstant::I32(x) } ,((this_value).span),types::builtin( types::BuiltinType { typename types::BuiltinType::I32() } )))));
};/*case end*/
case 9: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::I64>();
i64 const& x = __jakt_match_value.value;
return JaktInternal::ExplicitValue(TRY((types::CheckedExpression::template create<typename types::CheckedExpression::NumericConstant>( types::CheckedNumericConstant { typename types::CheckedNumericConstant::I64(x) } ,((this_value).span),types::builtin( types::BuiltinType { typename types::BuiltinType::I64() } )))));
};/*case end*/
case 10: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::F32>();
f32 const& x = __jakt_match_value.value;
return JaktInternal::ExplicitValue(TRY((types::CheckedExpression::template create<typename types::CheckedExpression::NumericConstant>( types::CheckedNumericConstant { typename types::CheckedNumericConstant::F32(x) } ,((this_value).span),types::builtin( types::BuiltinType { typename types::BuiltinType::F32() } )))));
};/*case end*/
case 11: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::F64>();
f64 const& x = __jakt_match_value.value;
return JaktInternal::ExplicitValue(TRY((types::CheckedExpression::template create<typename types::CheckedExpression::NumericConstant>( types::CheckedNumericConstant { typename types::CheckedNumericConstant::F64(x) } ,((this_value).span),types::builtin( types::BuiltinType { typename types::BuiltinType::F64() } )))));
};/*case end*/
case 12: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::USize>();
size_t const& x = __jakt_match_value.value;
return JaktInternal::ExplicitValue(TRY((types::CheckedExpression::template create<typename types::CheckedExpression::NumericConstant>( types::CheckedNumericConstant { typename types::CheckedNumericConstant::USize((infallible_integer_cast<u64>((x)))) } ,((this_value).span),types::builtin( types::BuiltinType { typename types::BuiltinType::Usize() } )))));
};/*case end*/
case 13: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::JaktString>();
DeprecatedString const& x = __jakt_match_value.value;
return JaktInternal::ExplicitValue(TRY((types::CheckedExpression::template create<typename types::CheckedExpression::QuotedString>(types::CheckedStringLiteral( types::StringLiteral { typename types::StringLiteral::Static(TRY((utility::escape_for_quotes(x)))) } ,types::builtin( types::BuiltinType { typename types::BuiltinType::JaktString() } ),true),((this_value).span)))));
};/*case end*/
case 14: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::StringView>();
DeprecatedString const& x = __jakt_match_value.value;
return JaktInternal::ExplicitValue(TRY((types::CheckedExpression::template create<typename types::CheckedExpression::QuotedString>(types::CheckedStringLiteral( types::StringLiteral { typename types::StringLiteral::Static(TRY((utility::escape_for_quotes(x)))) } ,types::builtin( types::BuiltinType { typename types::BuiltinType::JaktString() } ),true),((this_value).span)))));
};/*case end*/
case 15: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::CChar>();
char const& x = __jakt_match_value.value;
return JaktInternal::ExplicitValue(TRY((types::CheckedExpression::template create<typename types::CheckedExpression::CharacterConstant>(TRY((__jakt_format(Jakt::DeprecatedString("{}"sv),x))),((this_value).span)))));
};/*case end*/
case 16: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::CInt>();
int const& x = __jakt_match_value.value;
return JaktInternal::ExplicitValue(TRY((types::CheckedExpression::template create<typename types::CheckedExpression::NumericConstant>( types::CheckedNumericConstant { typename types::CheckedNumericConstant::I32((infallible_integer_cast<i32>((x)))) } ,((this_value).span),types::builtin( types::BuiltinType { typename types::BuiltinType::CInt() } )))));
};/*case end*/
case 25: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::OptionalNone>();
return JaktInternal::ExplicitValue(TRY((types::CheckedExpression::template create<typename types::CheckedExpression::OptionalNone>(((this_value).span),types::unknown_type_id()))));
};/*case end*/
case 24: {
auto&& __jakt_match_value = __jakt_match_variant.template get<types::ValueImpl::OptionalSome>();types::Value const& value = __jakt_match_value.value;
return JaktInternal::ExplicitValue(({ Optional<NonnullRefPtr<typename types::CheckedExpression>> __jakt_var_140; {
NonnullRefPtr<typename types::CheckedExpression> const expr = TRY((interpreter::value_to_checked_expression(value,interpreter)));
types::TypeId const inner_type_id = ((expr)->type());
types::StructId const optional_struct_id = TRY((((((interpreter)->program))->find_struct_in_prelude(Jakt::DeprecatedString("Optional"sv)))));
NonnullRefPtr<typename types::Type> const type = TRY((types::Type::template create<typename types::Type::GenericInstance>(optional_struct_id,(TRY((DynamicArray<types::TypeId>::create_with({inner_type_id})))))));
types::TypeId const type_id = TRY((((interpreter)->find_or_add_type_id(type))));
__jakt_var_140 = TRY((types::CheckedExpression::template create<typename types::CheckedExpression::OptionalSome>(expr,((this_value).span),type_id))); goto __jakt_label_137;

}
__jakt_label_137:; __jakt_var_140.release_value(); }));
};/*case end*/
case 26: {
auto&& __jakt_match_value = __jakt_match_variant.template get<types::ValueImpl::JaktTuple>();JaktInternal::DynamicArray<types::Value> const& fields = __jakt_match_value.fields;
types::TypeId const& type_id = __jakt_match_value.type_id;
return JaktInternal::ExplicitValue(({ Optional<NonnullRefPtr<typename types::CheckedExpression>> __jakt_var_141; {
JaktInternal::DynamicArray<NonnullRefPtr<typename types::CheckedExpression>> vals = (TRY((DynamicArray<NonnullRefPtr<typename types::CheckedExpression>>::create_with({}))));
{
JaktInternal::ArrayIterator<types::Value> _magic = ((fields).iterator());
for (;;){
JaktInternal::Optional<types::Value> _magic_value = ((_magic).next());
if ((!(((_magic_value).has_value())))){
break;
}
types::Value field = (_magic_value.value());
{
TRY((((vals).push(TRY((interpreter::value_to_checked_expression(field,interpreter)))))));
}

}
}

__jakt_var_141 = TRY((types::CheckedExpression::template create<typename types::CheckedExpression::JaktTuple>(vals,((this_value).span),type_id))); goto __jakt_label_138;

}
__jakt_label_138:; __jakt_var_141.release_value(); }));
};/*case end*/
case 17: {
auto&& __jakt_match_value = __jakt_match_variant.template get<types::ValueImpl::Struct>();JaktInternal::DynamicArray<types::Value> const& fields = __jakt_match_value.fields;
types::StructId const& struct_id = __jakt_match_value.struct_id;
JaktInternal::Optional<types::FunctionId> const& constructor = __jakt_match_value.constructor;
return JaktInternal::ExplicitValue(({ Optional<NonnullRefPtr<typename types::CheckedExpression>> __jakt_var_142; {
if ((!(((constructor).has_value())))){
TRY((((interpreter)->error_with_hint(Jakt::DeprecatedString("Cannot convert struct to expression without constructor"sv),((this_value).span),Jakt::DeprecatedString("Given struct cannot be created from its contents in any known way"sv),((this_value).span)))));
return Error::from_errno((infallible_integer_cast<i32>((interpreter::InterpretError::InvalidType))));
}
JaktInternal::DynamicArray<NonnullRefPtr<typename types::CheckedExpression>> materialised_fields = (TRY((DynamicArray<NonnullRefPtr<typename types::CheckedExpression>>::create_with({}))));
{
JaktInternal::ArrayIterator<types::Value> _magic = ((fields).iterator());
for (;;){
JaktInternal::Optional<types::Value> _magic_value = ((_magic).next());
if ((!(((_magic_value).has_value())))){
break;
}
types::Value field = (_magic_value.value());
{
TRY((((materialised_fields).push(TRY((interpreter::value_to_checked_expression(field,interpreter)))))));
}

}
}

types::CheckedStruct const struct_ = ((((interpreter)->program))->get_struct(struct_id));
JaktInternal::DynamicArray<types::ResolvedNamespace> reversed_namespace = (TRY((DynamicArray<types::ResolvedNamespace>::create_with({}))));
JaktInternal::Optional<types::ScopeId> scope_id = ((struct_).scope_id);
while (((scope_id).has_value())){
NonnullRefPtr<types::Scope> const scope = TRY((((((interpreter)->program))->get_scope((scope_id.value())))));
if (((((scope)->namespace_name)).has_value())){
TRY((((reversed_namespace).push(types::ResolvedNamespace((((scope)->namespace_name).value()),JaktInternal::OptionalNone(),JaktInternal::OptionalNone())))));
}
(scope_id = ((scope)->parent));
}
JaktInternal::DynamicArray<types::ResolvedNamespace> namespace_ = (TRY((DynamicArray<types::ResolvedNamespace>::create_with({}))));
{
JaktInternal::Range<size_t> _magic = (JaktInternal::Range<size_t>{static_cast<size_t>(((reversed_namespace).size())),static_cast<size_t>(static_cast<size_t>(0ULL))});
for (;;){
JaktInternal::Optional<size_t> _magic_value = ((_magic).next());
if ((!(((_magic_value).has_value())))){
break;
}
size_t i = (_magic_value.value());
{
TRY((((namespace_).push(((reversed_namespace)[(JaktInternal::checked_sub<size_t>(i,static_cast<size_t>(1ULL)))])))));
}

}
}

DeprecatedString const name = ((struct_).name);
JaktInternal::DynamicArray<JaktInternal::Tuple<DeprecatedString,NonnullRefPtr<typename types::CheckedExpression>>> args = (TRY((DynamicArray<JaktInternal::Tuple<DeprecatedString,NonnullRefPtr<typename types::CheckedExpression>>>::create_with({}))));
{
JaktInternal::Range<size_t> _magic = (JaktInternal::Range<size_t>{static_cast<size_t>(static_cast<size_t>(0ULL)),static_cast<size_t>(((materialised_fields).size()))});
for (;;){
JaktInternal::Optional<size_t> _magic_value = ((_magic).next());
if ((!(((_magic_value).has_value())))){
break;
}
size_t i = (_magic_value.value());
{
NonnullRefPtr<typename types::CheckedExpression> const arg = ((materialised_fields)[i]);
DeprecatedString const label = ((((((interpreter)->program))->get_variable(((((((struct_).fields))[i])).variable_id))))->name);
TRY((((args).push((Tuple{label, arg})))));
}

}
}

NonnullRefPtr<types::CheckedFunction> const callee = ((((interpreter)->program))->get_function((constructor.value())));
types::CheckedCall const call = types::CheckedCall(namespace_,name,args,(TRY((DynamicArray<types::TypeId>::create_with({})))),constructor,((struct_).type_id),((callee)->can_throw),JaktInternal::OptionalNone());
__jakt_var_142 = TRY((types::CheckedExpression::template create<typename types::CheckedExpression::Call>(call,((this_value).span),((struct_).type_id)))); goto __jakt_label_139;

}
__jakt_label_139:; __jakt_var_142.release_value(); }));
};/*case end*/
case 18: {
auto&& __jakt_match_value = __jakt_match_variant.template get<types::ValueImpl::Class>();JaktInternal::DynamicArray<types::Value> const& fields = __jakt_match_value.fields;
types::StructId const& struct_id = __jakt_match_value.struct_id;
JaktInternal::Optional<types::FunctionId> const& constructor = __jakt_match_value.constructor;
return JaktInternal::ExplicitValue(({ Optional<NonnullRefPtr<typename types::CheckedExpression>> __jakt_var_143; {
if ((!(((constructor).has_value())))){
TRY((((interpreter)->error_with_hint(Jakt::DeprecatedString("Cannot convert struct to expression without constructor"sv),((this_value).span),Jakt::DeprecatedString("Given struct cannot be created from its contents in any known way"sv),((this_value).span)))));
return Error::from_errno((infallible_integer_cast<i32>((interpreter::InterpretError::InvalidType))));
}
JaktInternal::DynamicArray<NonnullRefPtr<typename types::CheckedExpression>> materialised_fields = (TRY((DynamicArray<NonnullRefPtr<typename types::CheckedExpression>>::create_with({}))));
{
JaktInternal::ArrayIterator<types::Value> _magic = ((fields).iterator());
for (;;){
JaktInternal::Optional<types::Value> _magic_value = ((_magic).next());
if ((!(((_magic_value).has_value())))){
break;
}
types::Value field = (_magic_value.value());
{
TRY((((materialised_fields).push(TRY((interpreter::value_to_checked_expression(field,interpreter)))))));
}

}
}

types::CheckedStruct const struct_ = ((((interpreter)->program))->get_struct(struct_id));
JaktInternal::DynamicArray<types::ResolvedNamespace> reversed_namespace = (TRY((DynamicArray<types::ResolvedNamespace>::create_with({}))));
JaktInternal::Optional<types::ScopeId> scope_id = ((struct_).scope_id);
while (((scope_id).has_value())){
NonnullRefPtr<types::Scope> const scope = TRY((((((interpreter)->program))->get_scope((scope_id.value())))));
if (((((scope)->namespace_name)).has_value())){
TRY((((reversed_namespace).push(types::ResolvedNamespace((((scope)->namespace_name).value()),JaktInternal::OptionalNone(),JaktInternal::OptionalNone())))));
}
(scope_id = ((scope)->parent));
}
JaktInternal::DynamicArray<types::ResolvedNamespace> namespace_ = (TRY((DynamicArray<types::ResolvedNamespace>::create_with({}))));
{
JaktInternal::Range<size_t> _magic = (JaktInternal::Range<size_t>{static_cast<size_t>(((reversed_namespace).size())),static_cast<size_t>(static_cast<size_t>(0ULL))});
for (;;){
JaktInternal::Optional<size_t> _magic_value = ((_magic).next());
if ((!(((_magic_value).has_value())))){
break;
}
size_t i = (_magic_value.value());
{
TRY((((namespace_).push(((reversed_namespace)[(JaktInternal::checked_sub<size_t>(i,static_cast<size_t>(1ULL)))])))));
}

}
}

DeprecatedString const name = ((struct_).name);
JaktInternal::DynamicArray<JaktInternal::Tuple<DeprecatedString,NonnullRefPtr<typename types::CheckedExpression>>> args = (TRY((DynamicArray<JaktInternal::Tuple<DeprecatedString,NonnullRefPtr<typename types::CheckedExpression>>>::create_with({}))));
{
JaktInternal::Range<size_t> _magic = (JaktInternal::Range<size_t>{static_cast<size_t>(static_cast<size_t>(0ULL)),static_cast<size_t>(((materialised_fields).size()))});
for (;;){
JaktInternal::Optional<size_t> _magic_value = ((_magic).next());
if ((!(((_magic_value).has_value())))){
break;
}
size_t i = (_magic_value.value());
{
NonnullRefPtr<typename types::CheckedExpression> const arg = ((materialised_fields)[i]);
DeprecatedString const label = ((((((interpreter)->program))->get_variable(((((((struct_).fields))[i])).variable_id))))->name);
TRY((((args).push((Tuple{label, arg})))));
}

}
}

NonnullRefPtr<types::CheckedFunction> const callee = ((((interpreter)->program))->get_function((constructor.value())));
types::CheckedCall const call = types::CheckedCall(namespace_,name,args,(TRY((DynamicArray<types::TypeId>::create_with({})))),constructor,((struct_).type_id),((callee)->can_throw),JaktInternal::OptionalNone());
__jakt_var_143 = TRY((types::CheckedExpression::template create<typename types::CheckedExpression::Call>(call,((this_value).span),((struct_).type_id)))); goto __jakt_label_140;

}
__jakt_label_140:; __jakt_var_143.release_value(); }));
};/*case end*/
case 19: {
auto&& __jakt_match_value = __jakt_match_variant.template get<types::ValueImpl::Enum>();JaktInternal::DynamicArray<types::Value> const& fields = __jakt_match_value.fields;
types::EnumId const& enum_id = __jakt_match_value.enum_id;
types::FunctionId const& constructor = __jakt_match_value.constructor;
return JaktInternal::ExplicitValue(({ Optional<NonnullRefPtr<typename types::CheckedExpression>> __jakt_var_144; {
JaktInternal::DynamicArray<NonnullRefPtr<typename types::CheckedExpression>> materialised_fields = (TRY((DynamicArray<NonnullRefPtr<typename types::CheckedExpression>>::create_with({}))));
{
JaktInternal::ArrayIterator<types::Value> _magic = ((fields).iterator());
for (;;){
JaktInternal::Optional<types::Value> _magic_value = ((_magic).next());
if ((!(((_magic_value).has_value())))){
break;
}
types::Value field = (_magic_value.value());
{
TRY((((materialised_fields).push(TRY((interpreter::value_to_checked_expression(field,interpreter)))))));
}

}
}

types::CheckedEnum const enum_ = ((((interpreter)->program))->get_enum(enum_id));
JaktInternal::DynamicArray<types::ResolvedNamespace> reversed_namespace = (TRY((DynamicArray<types::ResolvedNamespace>::create_with({}))));
JaktInternal::Optional<types::ScopeId> scope_id = ((enum_).scope_id);
while (((scope_id).has_value())){
NonnullRefPtr<types::Scope> const scope = TRY((((((interpreter)->program))->get_scope((scope_id.value())))));
if (((((scope)->namespace_name)).has_value())){
TRY((((reversed_namespace).push(types::ResolvedNamespace((((scope)->namespace_name).value()),JaktInternal::OptionalNone(),JaktInternal::OptionalNone())))));
}
(scope_id = ((scope)->parent));
}
JaktInternal::DynamicArray<types::ResolvedNamespace> namespace_ = (TRY((DynamicArray<types::ResolvedNamespace>::create_with({}))));
{
JaktInternal::Range<size_t> _magic = (JaktInternal::Range<size_t>{static_cast<size_t>(((reversed_namespace).size())),static_cast<size_t>(static_cast<size_t>(0ULL))});
for (;;){
JaktInternal::Optional<size_t> _magic_value = ((_magic).next());
if ((!(((_magic_value).has_value())))){
break;
}
size_t i = (_magic_value.value());
{
TRY((((namespace_).push(((reversed_namespace)[(JaktInternal::checked_sub<size_t>(i,static_cast<size_t>(1ULL)))])))));
}

}
}

TRY((((namespace_).push(types::ResolvedNamespace(((enum_).name),JaktInternal::OptionalNone(),JaktInternal::OptionalNone())))));
DeprecatedString const name = ((enum_).name);
JaktInternal::DynamicArray<JaktInternal::Tuple<DeprecatedString,NonnullRefPtr<typename types::CheckedExpression>>> args = (TRY((DynamicArray<JaktInternal::Tuple<DeprecatedString,NonnullRefPtr<typename types::CheckedExpression>>>::create_with({}))));
{
JaktInternal::Range<size_t> _magic = (JaktInternal::Range<size_t>{static_cast<size_t>(static_cast<size_t>(0ULL)),static_cast<size_t>(((materialised_fields).size()))});
for (;;){
JaktInternal::Optional<size_t> _magic_value = ((_magic).next());
if ((!(((_magic_value).has_value())))){
break;
}
size_t i = (_magic_value.value());
{
NonnullRefPtr<typename types::CheckedExpression> const arg = ((materialised_fields)[i]);
TRY((((args).push((Tuple{Jakt::DeprecatedString(""sv), arg})))));
}

}
}

NonnullRefPtr<types::CheckedFunction> const callee = ((((interpreter)->program))->get_function(constructor));
types::CheckedCall const call = types::CheckedCall(namespace_,((callee)->name),args,(TRY((DynamicArray<types::TypeId>::create_with({})))),constructor,((enum_).type_id),((callee)->can_throw),JaktInternal::OptionalNone());
__jakt_var_144 = TRY((types::CheckedExpression::template create<typename types::CheckedExpression::Call>(call,((this_value).span),((enum_).type_id)))); goto __jakt_label_141;

}
__jakt_label_141:; __jakt_var_144.release_value(); }));
};/*case end*/
case 20: {
auto&& __jakt_match_value = __jakt_match_variant.template get<types::ValueImpl::JaktArray>();JaktInternal::DynamicArray<types::Value> const& values = __jakt_match_value.values;
types::TypeId const& type_id = __jakt_match_value.type_id;
return JaktInternal::ExplicitValue(({ Optional<NonnullRefPtr<typename types::CheckedExpression>> __jakt_var_145; {
JaktInternal::DynamicArray<NonnullRefPtr<typename types::CheckedExpression>> vals = (TRY((DynamicArray<NonnullRefPtr<typename types::CheckedExpression>>::create_with({}))));
{
JaktInternal::ArrayIterator<types::Value> _magic = ((values).iterator());
for (;;){
JaktInternal::Optional<types::Value> _magic_value = ((_magic).next());
if ((!(((_magic_value).has_value())))){
break;
}
types::Value value = (_magic_value.value());
{
TRY((((vals).push(TRY((interpreter::value_to_checked_expression(value,interpreter)))))));
}

}
}

types::TypeId const inner_type_id = JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<types::TypeId, ErrorOr<NonnullRefPtr<typename types::CheckedExpression>>>{
auto&& __jakt_match_variant = *((((interpreter)->program))->get_type(type_id));
switch(__jakt_match_variant.index()) {
case 19: {
auto&& __jakt_match_value = __jakt_match_variant.template get<types::Type::GenericInstance>();JaktInternal::DynamicArray<types::TypeId> const& args = __jakt_match_value.args;
return JaktInternal::ExplicitValue(((args)[static_cast<i64>(0LL)]));
};/*case end*/
default: {
{
utility::panic(Jakt::DeprecatedString("Expected generic instance of Array while materialising an array"sv));
}
};/*case end*/
}/*switch end*/
}()
));
__jakt_var_145 = TRY((types::CheckedExpression::template create<typename types::CheckedExpression::JaktArray>(vals,JaktInternal::OptionalNone(),((this_value).span),type_id,inner_type_id))); goto __jakt_label_142;

}
__jakt_label_142:; __jakt_var_145.release_value(); }));
};/*case end*/
case 21: {
auto&& __jakt_match_value = __jakt_match_variant.template get<types::ValueImpl::JaktDictionary>();JaktInternal::DynamicArray<types::Value> const& keys = __jakt_match_value.keys;
JaktInternal::DynamicArray<types::Value> const& values = __jakt_match_value.values;
types::TypeId const& type_id = __jakt_match_value.type_id;
return JaktInternal::ExplicitValue(({ Optional<NonnullRefPtr<typename types::CheckedExpression>> __jakt_var_146; {
JaktInternal::DynamicArray<JaktInternal::Tuple<NonnullRefPtr<typename types::CheckedExpression>,NonnullRefPtr<typename types::CheckedExpression>>> vals = (TRY((DynamicArray<JaktInternal::Tuple<NonnullRefPtr<typename types::CheckedExpression>,NonnullRefPtr<typename types::CheckedExpression>>>::create_with({}))));
{
JaktInternal::Range<size_t> _magic = (JaktInternal::Range<size_t>{static_cast<size_t>(static_cast<size_t>(0ULL)),static_cast<size_t>(((keys).size()))});
for (;;){
JaktInternal::Optional<size_t> _magic_value = ((_magic).next());
if ((!(((_magic_value).has_value())))){
break;
}
size_t i = (_magic_value.value());
{
TRY((((vals).push((Tuple{TRY((interpreter::value_to_checked_expression(((keys)[i]),interpreter))), TRY((interpreter::value_to_checked_expression(((values)[i]),interpreter)))})))));
}

}
}

JaktInternal::Tuple<types::TypeId,types::TypeId> const key_type_id_value_type_id_ = JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<JaktInternal::Tuple<types::TypeId,types::TypeId>, ErrorOr<NonnullRefPtr<typename types::CheckedExpression>>>{
auto&& __jakt_match_variant = *((((interpreter)->program))->get_type(type_id));
switch(__jakt_match_variant.index()) {
case 19: {
auto&& __jakt_match_value = __jakt_match_variant.template get<types::Type::GenericInstance>();JaktInternal::DynamicArray<types::TypeId> const& args = __jakt_match_value.args;
return JaktInternal::ExplicitValue((Tuple{((args)[static_cast<i64>(0LL)]), ((args)[static_cast<i64>(1LL)])}));
};/*case end*/
default: {
{
utility::panic(Jakt::DeprecatedString("Expected generic instance of Dictionary while materialising an array"sv));
}
};/*case end*/
}/*switch end*/
}()
));
types::TypeId const key_type_id = ((key_type_id_value_type_id_).template get<0>());
types::TypeId const value_type_id = ((key_type_id_value_type_id_).template get<1>());

__jakt_var_146 = TRY((types::CheckedExpression::template create<typename types::CheckedExpression::JaktDictionary>(vals,((this_value).span),type_id,key_type_id,value_type_id))); goto __jakt_label_143;

}
__jakt_label_143:; __jakt_var_146.release_value(); }));
};/*case end*/
case 22: {
auto&& __jakt_match_value = __jakt_match_variant.template get<types::ValueImpl::JaktSet>();JaktInternal::DynamicArray<types::Value> const& values = __jakt_match_value.values;
types::TypeId const& type_id = __jakt_match_value.type_id;
return JaktInternal::ExplicitValue(({ Optional<NonnullRefPtr<typename types::CheckedExpression>> __jakt_var_147; {
JaktInternal::DynamicArray<NonnullRefPtr<typename types::CheckedExpression>> vals = (TRY((DynamicArray<NonnullRefPtr<typename types::CheckedExpression>>::create_with({}))));
{
JaktInternal::Range<size_t> _magic = (JaktInternal::Range<size_t>{static_cast<size_t>(static_cast<size_t>(0ULL)),static_cast<size_t>(((values).size()))});
for (;;){
JaktInternal::Optional<size_t> _magic_value = ((_magic).next());
if ((!(((_magic_value).has_value())))){
break;
}
size_t i = (_magic_value.value());
{
TRY((((vals).push(TRY((interpreter::value_to_checked_expression(((values)[i]),interpreter)))))));
}

}
}

types::TypeId const value_type_id = JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<types::TypeId, ErrorOr<NonnullRefPtr<typename types::CheckedExpression>>>{
auto&& __jakt_match_variant = *((((interpreter)->program))->get_type(type_id));
switch(__jakt_match_variant.index()) {
case 19: {
auto&& __jakt_match_value = __jakt_match_variant.template get<types::Type::GenericInstance>();JaktInternal::DynamicArray<types::TypeId> const& args = __jakt_match_value.args;
return JaktInternal::ExplicitValue(((args)[static_cast<i64>(0LL)]));
};/*case end*/
default: {
{
utility::panic(Jakt::DeprecatedString("Expected generic instance of Set while materialising an array"sv));
}
};/*case end*/
}/*switch end*/
}()
));
__jakt_var_147 = TRY((types::CheckedExpression::template create<typename types::CheckedExpression::JaktSet>(vals,((this_value).span),type_id,value_type_id))); goto __jakt_label_144;

}
__jakt_label_144:; __jakt_var_147.release_value(); }));
};/*case end*/
case 27: {
auto&& __jakt_match_value = __jakt_match_variant.template get<types::ValueImpl::Function>();JaktInternal::Dictionary<DeprecatedString,types::Value> const& captures = __jakt_match_value.captures;
bool const& can_throw = __jakt_match_value.can_throw;
types::TypeId const& return_type_id = __jakt_match_value.return_type_id;
types::TypeId const& type_id = __jakt_match_value.type_id;
types::CheckedBlock const& block = __jakt_match_value.block;
JaktInternal::DynamicArray<types::CheckedParameter> const& checked_params = __jakt_match_value.checked_params;
return JaktInternal::ExplicitValue(({ Optional<NonnullRefPtr<typename types::CheckedExpression>> __jakt_var_148; {
NonnullRefPtr<types::Scope> const parent_scope = TRY((((((interpreter)->program))->get_scope(((block).scope_id)))));
types::ScopeId const inherited_scope_id = TRY((((((interpreter)->program))->create_scope(((block).scope_id),((parent_scope)->can_throw),TRY((__jakt_format(Jakt::DeprecatedString("synthetic({})"sv),((parent_scope)->debug_name)))),((type_id).module)))));
NonnullRefPtr<types::Scope> inherited_scope = TRY((((((interpreter)->program))->get_scope(inherited_scope_id))));
JaktInternal::DynamicArray<NonnullRefPtr<typename types::CheckedStatement>> statements = (TRY((DynamicArray<NonnullRefPtr<typename types::CheckedStatement>>::create_with({}))));
{
JaktInternal::DictionaryIterator<DeprecatedString,types::Value> _magic = ((captures).iterator());
for (;;){
JaktInternal::Optional<JaktInternal::Tuple<DeprecatedString,types::Value>> _magic_value = ((_magic).next());
if ((!(((_magic_value).has_value())))){
break;
}
JaktInternal::Tuple<DeprecatedString,types::Value> capture = (_magic_value.value());
{
NonnullRefPtr<typename types::CheckedExpression> const value = TRY((interpreter::value_to_checked_expression(((capture).template get<1>()),interpreter)));
types::VarId const var_id = TRY((((((((interpreter)->program))->get_module(((type_id).module))))->add_variable(TRY((types::CheckedVariable::create(((capture).template get<0>()),((value)->type()),false,((this_value).span),JaktInternal::OptionalNone(), types::CheckedVisibility { typename types::CheckedVisibility::Public() } ,JaktInternal::OptionalNone())))))));
TRY((((statements).push(TRY((types::CheckedStatement::template create<typename types::CheckedStatement::VarDecl>(var_id,value,((this_value).span))))))));
TRY((((((inherited_scope)->comptime_bindings)).set(((capture).template get<0>()),((capture).template get<1>())))));
}

}
}

TRY((((statements).push_values(((((block).statements)))))));
types::CheckedBlock const new_block = types::CheckedBlock(statements,inherited_scope_id,((block).control_flow),((block).yielded_type),((block).yielded_none));
{
JaktInternal::ArrayIterator<types::CheckedParameter> _magic = ((checked_params).iterator());
for (;;){
JaktInternal::Optional<types::CheckedParameter> _magic_value = ((_magic).next());
if ((!(((_magic_value).has_value())))){
break;
}
types::CheckedParameter param = (_magic_value.value());
{
outln(Jakt::DeprecatedString("Param: {}"sv),TRY((((((interpreter)->program))->type_name(((((param).variable))->type_id),false)))));
}

}
}

__jakt_var_148 = TRY((types::CheckedExpression::template create<typename types::CheckedExpression::Function>((TRY((DynamicArray<types::CheckedCapture>::create_with({})))),checked_params,can_throw,return_type_id,new_block,((this_value).span),type_id,JaktInternal::OptionalNone()))); goto __jakt_label_145;

}
__jakt_label_145:; __jakt_var_148.release_value(); }));
};/*case end*/
default: {
{
TRY((((interpreter)->error(TRY((__jakt_format(Jakt::DeprecatedString("Cannot materialise the type {}"sv),((this_value).impl)))),((this_value).span)))));
return Error::from_errno((infallible_integer_cast<i32>((interpreter::InterpretError::Unimplemented))));
}
};/*case end*/
}/*switch end*/
}()
)));
}
}

ErrorOr<DeprecatedString> interpreter::Interpreter::debug_description() const { auto builder = MUST(DeprecatedStringBuilder::create());TRY(builder.append("Interpreter("sv));{
JaktInternal::PrettyPrint::ScopedLevelIncrease increase_indent {};
TRY(JaktInternal::PrettyPrint::output_indentation(builder));TRY(builder.append("compiler: "sv));TRY(builder.appendff("{}, ", *compiler));
TRY(JaktInternal::PrettyPrint::output_indentation(builder));TRY(builder.append("program: "sv));TRY(builder.appendff("{}, ", *program));
TRY(JaktInternal::PrettyPrint::output_indentation(builder));TRY(builder.append("spans: "sv));TRY(builder.appendff("{}, ", spans));
TRY(JaktInternal::PrettyPrint::output_indentation(builder));TRY(builder.append("current_function_id: "sv));TRY(builder.appendff("{}", current_function_id));
}
TRY(builder.append(")"sv));return builder.to_string(); }
ErrorOr<bool> interpreter::Interpreter::get_prelude_function(types::ScopeId const scope_id) const {
{
types::ScopeId current_scope_id = scope_id;
types::ScopeId const prelude_scope_id = ((((*this).program))->prelude_scope_id());
for (;;){
if (((current_scope_id).equals(prelude_scope_id))){
return (true);
}
NonnullRefPtr<types::Scope> const scope = TRY((((((*this).program))->get_scope(current_scope_id))));
if (((((scope)->parent)).has_value())){
(current_scope_id = (((scope)->parent).value()));
continue;
}
return (false);
}
}
}

ErrorOr<interpreter::StatementResult> interpreter::Interpreter::call_prelude_function(DeprecatedString const prelude_function,JaktInternal::DynamicArray<types::ResolvedNamespace> const namespace_,JaktInternal::Optional<types::Value> const this_argument,JaktInternal::DynamicArray<types::Value> const arguments,utility::Span const call_span,JaktInternal::Dictionary<DeprecatedString,types::TypeId> const type_bindings) {
{
if ((((namespace_).size()) != static_cast<size_t>(1ULL))){
return (JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<interpreter::StatementResult,ErrorOr<interpreter::StatementResult>>{
auto __jakt_enum_value = (prelude_function);
if (__jakt_enum_value == Jakt::DeprecatedString("format"sv)) {
return JaktInternal::ExplicitValue(({ Optional<interpreter::StatementResult> __jakt_var_149; {
DeprecatedString const format_string = JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<DeprecatedString, ErrorOr<interpreter::StatementResult>>{
auto&& __jakt_match_variant = *((((arguments)[static_cast<i64>(0LL)])).impl);
switch(__jakt_match_variant.index()) {
case 13: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::JaktString>();
DeprecatedString const& x = __jakt_match_value.value;
return JaktInternal::ExplicitValue(x);
};/*case end*/
default: {
{
TRY((((*this).error(TRY((__jakt_format(Jakt::DeprecatedString("Expected string as first argument to format, got {}"sv),((((arguments)[static_cast<i64>(0LL)])).impl)))),call_span))));
return Error::from_errno((infallible_integer_cast<i32>((interpreter::InterpretError::InvalidType))));
}
};/*case end*/
}/*switch end*/
}()
));
__jakt_var_149 =  interpreter::StatementResult { typename interpreter::StatementResult::JustValue(types::Value(TRY((types::ValueImpl::template create<typename types::ValueImpl::JaktString>(JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<DeprecatedString,ErrorOr<interpreter::StatementResult>>{
auto __jakt_enum_value = (((arguments).size()));
if (__jakt_enum_value == static_cast<size_t>(1ULL)) {
return JaktInternal::ExplicitValue(TRY((__jakt_format(format_string))));
}
else if (__jakt_enum_value == static_cast<size_t>(2ULL)) {
return JaktInternal::ExplicitValue(JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<DeprecatedString, ErrorOr<interpreter::StatementResult>>{
auto&& __jakt_match_variant = *((((arguments)[static_cast<i64>(1LL)])).impl);
switch(__jakt_match_variant.index()) {
case 1: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::Bool>();
bool const& x = __jakt_match_value.value;
return JaktInternal::ExplicitValue(TRY((__jakt_format(format_string,x))));
};/*case end*/
case 2: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::U8>();
u8 const& x = __jakt_match_value.value;
return JaktInternal::ExplicitValue(TRY((__jakt_format(format_string,x))));
};/*case end*/
case 3: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::U16>();
u16 const& x = __jakt_match_value.value;
return JaktInternal::ExplicitValue(TRY((__jakt_format(format_string,x))));
};/*case end*/
case 4: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::U32>();
u32 const& x = __jakt_match_value.value;
return JaktInternal::ExplicitValue(TRY((__jakt_format(format_string,x))));
};/*case end*/
case 5: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::U64>();
u64 const& x = __jakt_match_value.value;
return JaktInternal::ExplicitValue(TRY((__jakt_format(format_string,x))));
};/*case end*/
case 6: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::I8>();
i8 const& x = __jakt_match_value.value;
return JaktInternal::ExplicitValue(TRY((__jakt_format(format_string,x))));
};/*case end*/
case 7: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::I16>();
i16 const& x = __jakt_match_value.value;
return JaktInternal::ExplicitValue(TRY((__jakt_format(format_string,x))));
};/*case end*/
case 8: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::I32>();
i32 const& x = __jakt_match_value.value;
return JaktInternal::ExplicitValue(TRY((__jakt_format(format_string,x))));
};/*case end*/
case 9: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::I64>();
i64 const& x = __jakt_match_value.value;
return JaktInternal::ExplicitValue(TRY((__jakt_format(format_string,x))));
};/*case end*/
case 10: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::F32>();
f32 const& x = __jakt_match_value.value;
return JaktInternal::ExplicitValue(TRY((__jakt_format(format_string,x))));
};/*case end*/
case 11: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::F64>();
f64 const& x = __jakt_match_value.value;
return JaktInternal::ExplicitValue(TRY((__jakt_format(format_string,x))));
};/*case end*/
case 12: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::USize>();
size_t const& x = __jakt_match_value.value;
return JaktInternal::ExplicitValue(TRY((__jakt_format(format_string,x))));
};/*case end*/
case 13: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::JaktString>();
DeprecatedString const& x = __jakt_match_value.value;
return JaktInternal::ExplicitValue(TRY((__jakt_format(format_string,x))));
};/*case end*/
case 15: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::CChar>();
char const& x = __jakt_match_value.value;
return JaktInternal::ExplicitValue(TRY((__jakt_format(format_string,x))));
};/*case end*/
case 16: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::CInt>();
int const& x = __jakt_match_value.value;
return JaktInternal::ExplicitValue(TRY((__jakt_format(format_string,x))));
};/*case end*/
default: {
{
TRY((((*this).error(TRY((__jakt_format(Jakt::DeprecatedString("comptime format can only format primitves, got {}"sv),((((arguments)[static_cast<i64>(1LL)])).impl)))),call_span))));
return Error::from_errno((infallible_integer_cast<i32>((interpreter::InterpretError::InvalidType))));
}
};/*case end*/
}/*switch end*/
}()
)));
}
else {
{
TRY((((*this).error(TRY((__jakt_format(Jakt::DeprecatedString("comptime format accepts at most two arguments, but got {}"sv),((arguments).size())))),call_span))));
return Error::from_errno((infallible_integer_cast<i32>((interpreter::InterpretError::InvalidType))));
}
}
}()))
))),call_span)) } ; goto __jakt_label_146;

}
__jakt_label_146:; __jakt_var_149.release_value(); }));
}
else if (__jakt_enum_value == Jakt::DeprecatedString("println"sv)) {
return JaktInternal::ExplicitValue(({ Optional<interpreter::StatementResult> __jakt_var_150; {
DeprecatedString const format_string = JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<DeprecatedString, ErrorOr<interpreter::StatementResult>>{
auto&& __jakt_match_variant = *((((arguments)[static_cast<i64>(0LL)])).impl);
switch(__jakt_match_variant.index()) {
case 13: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::JaktString>();
DeprecatedString const& x = __jakt_match_value.value;
return JaktInternal::ExplicitValue(x);
};/*case end*/
default: {
{
TRY((((*this).error(TRY((__jakt_format(Jakt::DeprecatedString("println expects a string as its first argument, but got {}"sv),((((arguments)[static_cast<i64>(0LL)])).impl)))),call_span))));
return Error::from_errno((infallible_integer_cast<i32>((interpreter::InterpretError::InvalidType))));
}
};/*case end*/
}/*switch end*/
}()
));
JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<void,ErrorOr<interpreter::StatementResult>>{
auto __jakt_enum_value = (((arguments).size()));
if (__jakt_enum_value == static_cast<size_t>(1ULL)) {
return (JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<void,ErrorOr<interpreter::StatementResult>>{
auto __jakt_enum_value = (prelude_function);
if (__jakt_enum_value == Jakt::DeprecatedString("println"sv)) {
return (outln(format_string)), JaktInternal::ExplicitValue<void>();
}
else if (__jakt_enum_value == Jakt::DeprecatedString("eprintln"sv)) {
return (warnln(format_string)), JaktInternal::ExplicitValue<void>();
}
else if (__jakt_enum_value == Jakt::DeprecatedString("print"sv)) {
return (out(format_string)), JaktInternal::ExplicitValue<void>();
}
else {
return (warn(format_string)), JaktInternal::ExplicitValue<void>();
}
return JaktInternal::ExplicitValue<void>();
}()))
), JaktInternal::ExplicitValue<void>();
}
else if (__jakt_enum_value == static_cast<size_t>(2ULL)) {
return (JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<void, ErrorOr<interpreter::StatementResult>>{
auto&& __jakt_match_variant = *((((arguments)[static_cast<i64>(1LL)])).impl);
switch(__jakt_match_variant.index()) {
case 1: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::Bool>();
bool const& x = __jakt_match_value.value;
return (JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<void,ErrorOr<interpreter::StatementResult>>{
auto __jakt_enum_value = (prelude_function);
if (__jakt_enum_value == Jakt::DeprecatedString("println"sv)) {
return (outln(format_string,x)), JaktInternal::ExplicitValue<void>();
}
else if (__jakt_enum_value == Jakt::DeprecatedString("eprintln"sv)) {
return (warnln(format_string,x)), JaktInternal::ExplicitValue<void>();
}
else if (__jakt_enum_value == Jakt::DeprecatedString("print"sv)) {
return (out(format_string,x)), JaktInternal::ExplicitValue<void>();
}
else {
return (warn(format_string,x)), JaktInternal::ExplicitValue<void>();
}
return JaktInternal::ExplicitValue<void>();
}()))
), JaktInternal::ExplicitValue<void>();
};/*case end*/
case 2: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::U8>();
u8 const& x = __jakt_match_value.value;
return (JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<void,ErrorOr<interpreter::StatementResult>>{
auto __jakt_enum_value = (prelude_function);
if (__jakt_enum_value == Jakt::DeprecatedString("println"sv)) {
return (outln(format_string,x)), JaktInternal::ExplicitValue<void>();
}
else if (__jakt_enum_value == Jakt::DeprecatedString("eprintln"sv)) {
return (warnln(format_string,x)), JaktInternal::ExplicitValue<void>();
}
else if (__jakt_enum_value == Jakt::DeprecatedString("print"sv)) {
return (out(format_string,x)), JaktInternal::ExplicitValue<void>();
}
else {
return (warn(format_string,x)), JaktInternal::ExplicitValue<void>();
}
return JaktInternal::ExplicitValue<void>();
}()))
), JaktInternal::ExplicitValue<void>();
};/*case end*/
case 3: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::U16>();
u16 const& x = __jakt_match_value.value;
return (JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<void,ErrorOr<interpreter::StatementResult>>{
auto __jakt_enum_value = (prelude_function);
if (__jakt_enum_value == Jakt::DeprecatedString("println"sv)) {
return (outln(format_string,x)), JaktInternal::ExplicitValue<void>();
}
else if (__jakt_enum_value == Jakt::DeprecatedString("eprintln"sv)) {
return (warnln(format_string,x)), JaktInternal::ExplicitValue<void>();
}
else if (__jakt_enum_value == Jakt::DeprecatedString("print"sv)) {
return (out(format_string,x)), JaktInternal::ExplicitValue<void>();
}
else {
return (warn(format_string,x)), JaktInternal::ExplicitValue<void>();
}
return JaktInternal::ExplicitValue<void>();
}()))
), JaktInternal::ExplicitValue<void>();
};/*case end*/
case 4: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::U32>();
u32 const& x = __jakt_match_value.value;
return (JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<void,ErrorOr<interpreter::StatementResult>>{
auto __jakt_enum_value = (prelude_function);
if (__jakt_enum_value == Jakt::DeprecatedString("println"sv)) {
return (outln(format_string,x)), JaktInternal::ExplicitValue<void>();
}
else if (__jakt_enum_value == Jakt::DeprecatedString("eprintln"sv)) {
return (warnln(format_string,x)), JaktInternal::ExplicitValue<void>();
}
else if (__jakt_enum_value == Jakt::DeprecatedString("print"sv)) {
return (out(format_string,x)), JaktInternal::ExplicitValue<void>();
}
else {
return (warn(format_string,x)), JaktInternal::ExplicitValue<void>();
}
return JaktInternal::ExplicitValue<void>();
}()))
), JaktInternal::ExplicitValue<void>();
};/*case end*/
case 5: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::U64>();
u64 const& x = __jakt_match_value.value;
return (JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<void,ErrorOr<interpreter::StatementResult>>{
auto __jakt_enum_value = (prelude_function);
if (__jakt_enum_value == Jakt::DeprecatedString("println"sv)) {
return (outln(format_string,x)), JaktInternal::ExplicitValue<void>();
}
else if (__jakt_enum_value == Jakt::DeprecatedString("eprintln"sv)) {
return (warnln(format_string,x)), JaktInternal::ExplicitValue<void>();
}
else if (__jakt_enum_value == Jakt::DeprecatedString("print"sv)) {
return (out(format_string,x)), JaktInternal::ExplicitValue<void>();
}
else {
return (warn(format_string,x)), JaktInternal::ExplicitValue<void>();
}
return JaktInternal::ExplicitValue<void>();
}()))
), JaktInternal::ExplicitValue<void>();
};/*case end*/
case 6: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::I8>();
i8 const& x = __jakt_match_value.value;
return (JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<void,ErrorOr<interpreter::StatementResult>>{
auto __jakt_enum_value = (prelude_function);
if (__jakt_enum_value == Jakt::DeprecatedString("println"sv)) {
return (outln(format_string,x)), JaktInternal::ExplicitValue<void>();
}
else if (__jakt_enum_value == Jakt::DeprecatedString("eprintln"sv)) {
return (warnln(format_string,x)), JaktInternal::ExplicitValue<void>();
}
else if (__jakt_enum_value == Jakt::DeprecatedString("print"sv)) {
return (out(format_string,x)), JaktInternal::ExplicitValue<void>();
}
else {
return (warn(format_string,x)), JaktInternal::ExplicitValue<void>();
}
return JaktInternal::ExplicitValue<void>();
}()))
), JaktInternal::ExplicitValue<void>();
};/*case end*/
case 7: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::I16>();
i16 const& x = __jakt_match_value.value;
return (JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<void,ErrorOr<interpreter::StatementResult>>{
auto __jakt_enum_value = (prelude_function);
if (__jakt_enum_value == Jakt::DeprecatedString("println"sv)) {
return (outln(format_string,x)), JaktInternal::ExplicitValue<void>();
}
else if (__jakt_enum_value == Jakt::DeprecatedString("eprintln"sv)) {
return (warnln(format_string,x)), JaktInternal::ExplicitValue<void>();
}
else if (__jakt_enum_value == Jakt::DeprecatedString("print"sv)) {
return (out(format_string,x)), JaktInternal::ExplicitValue<void>();
}
else {
return (warn(format_string,x)), JaktInternal::ExplicitValue<void>();
}
return JaktInternal::ExplicitValue<void>();
}()))
), JaktInternal::ExplicitValue<void>();
};/*case end*/
case 8: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::I32>();
i32 const& x = __jakt_match_value.value;
return (JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<void,ErrorOr<interpreter::StatementResult>>{
auto __jakt_enum_value = (prelude_function);
if (__jakt_enum_value == Jakt::DeprecatedString("println"sv)) {
return (outln(format_string,x)), JaktInternal::ExplicitValue<void>();
}
else if (__jakt_enum_value == Jakt::DeprecatedString("eprintln"sv)) {
return (warnln(format_string,x)), JaktInternal::ExplicitValue<void>();
}
else if (__jakt_enum_value == Jakt::DeprecatedString("print"sv)) {
return (out(format_string,x)), JaktInternal::ExplicitValue<void>();
}
else {
return (warn(format_string,x)), JaktInternal::ExplicitValue<void>();
}
return JaktInternal::ExplicitValue<void>();
}()))
), JaktInternal::ExplicitValue<void>();
};/*case end*/
case 9: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::I64>();
i64 const& x = __jakt_match_value.value;
return (JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<void,ErrorOr<interpreter::StatementResult>>{
auto __jakt_enum_value = (prelude_function);
if (__jakt_enum_value == Jakt::DeprecatedString("println"sv)) {
return (outln(format_string,x)), JaktInternal::ExplicitValue<void>();
}
else if (__jakt_enum_value == Jakt::DeprecatedString("eprintln"sv)) {
return (warnln(format_string,x)), JaktInternal::ExplicitValue<void>();
}
else if (__jakt_enum_value == Jakt::DeprecatedString("print"sv)) {
return (out(format_string,x)), JaktInternal::ExplicitValue<void>();
}
else {
return (warn(format_string,x)), JaktInternal::ExplicitValue<void>();
}
return JaktInternal::ExplicitValue<void>();
}()))
), JaktInternal::ExplicitValue<void>();
};/*case end*/
case 10: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::F32>();
f32 const& x = __jakt_match_value.value;
return (JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<void,ErrorOr<interpreter::StatementResult>>{
auto __jakt_enum_value = (prelude_function);
if (__jakt_enum_value == Jakt::DeprecatedString("println"sv)) {
return (outln(format_string,x)), JaktInternal::ExplicitValue<void>();
}
else if (__jakt_enum_value == Jakt::DeprecatedString("eprintln"sv)) {
return (warnln(format_string,x)), JaktInternal::ExplicitValue<void>();
}
else if (__jakt_enum_value == Jakt::DeprecatedString("print"sv)) {
return (out(format_string,x)), JaktInternal::ExplicitValue<void>();
}
else {
return (warn(format_string,x)), JaktInternal::ExplicitValue<void>();
}
return JaktInternal::ExplicitValue<void>();
}()))
), JaktInternal::ExplicitValue<void>();
};/*case end*/
case 11: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::F64>();
f64 const& x = __jakt_match_value.value;
return (JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<void,ErrorOr<interpreter::StatementResult>>{
auto __jakt_enum_value = (prelude_function);
if (__jakt_enum_value == Jakt::DeprecatedString("println"sv)) {
return (outln(format_string,x)), JaktInternal::ExplicitValue<void>();
}
else if (__jakt_enum_value == Jakt::DeprecatedString("eprintln"sv)) {
return (warnln(format_string,x)), JaktInternal::ExplicitValue<void>();
}
else if (__jakt_enum_value == Jakt::DeprecatedString("print"sv)) {
return (out(format_string,x)), JaktInternal::ExplicitValue<void>();
}
else {
return (warn(format_string,x)), JaktInternal::ExplicitValue<void>();
}
return JaktInternal::ExplicitValue<void>();
}()))
), JaktInternal::ExplicitValue<void>();
};/*case end*/
case 12: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::USize>();
size_t const& x = __jakt_match_value.value;
return (JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<void,ErrorOr<interpreter::StatementResult>>{
auto __jakt_enum_value = (prelude_function);
if (__jakt_enum_value == Jakt::DeprecatedString("println"sv)) {
return (outln(format_string,x)), JaktInternal::ExplicitValue<void>();
}
else if (__jakt_enum_value == Jakt::DeprecatedString("eprintln"sv)) {
return (warnln(format_string,x)), JaktInternal::ExplicitValue<void>();
}
else if (__jakt_enum_value == Jakt::DeprecatedString("print"sv)) {
return (out(format_string,x)), JaktInternal::ExplicitValue<void>();
}
else {
return (warn(format_string,x)), JaktInternal::ExplicitValue<void>();
}
return JaktInternal::ExplicitValue<void>();
}()))
), JaktInternal::ExplicitValue<void>();
};/*case end*/
case 13: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::JaktString>();
DeprecatedString const& x = __jakt_match_value.value;
return (JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<void,ErrorOr<interpreter::StatementResult>>{
auto __jakt_enum_value = (prelude_function);
if (__jakt_enum_value == Jakt::DeprecatedString("println"sv)) {
return (outln(format_string,x)), JaktInternal::ExplicitValue<void>();
}
else if (__jakt_enum_value == Jakt::DeprecatedString("eprintln"sv)) {
return (warnln(format_string,x)), JaktInternal::ExplicitValue<void>();
}
else if (__jakt_enum_value == Jakt::DeprecatedString("print"sv)) {
return (out(format_string,x)), JaktInternal::ExplicitValue<void>();
}
else {
return (warn(format_string,x)), JaktInternal::ExplicitValue<void>();
}
return JaktInternal::ExplicitValue<void>();
}()))
), JaktInternal::ExplicitValue<void>();
};/*case end*/
case 15: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::CChar>();
char const& x = __jakt_match_value.value;
return (JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<void,ErrorOr<interpreter::StatementResult>>{
auto __jakt_enum_value = (prelude_function);
if (__jakt_enum_value == Jakt::DeprecatedString("println"sv)) {
return (outln(format_string,x)), JaktInternal::ExplicitValue<void>();
}
else if (__jakt_enum_value == Jakt::DeprecatedString("eprintln"sv)) {
return (warnln(format_string,x)), JaktInternal::ExplicitValue<void>();
}
else if (__jakt_enum_value == Jakt::DeprecatedString("print"sv)) {
return (out(format_string,x)), JaktInternal::ExplicitValue<void>();
}
else {
return (warn(format_string,x)), JaktInternal::ExplicitValue<void>();
}
return JaktInternal::ExplicitValue<void>();
}()))
), JaktInternal::ExplicitValue<void>();
};/*case end*/
case 16: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::CInt>();
int const& x = __jakt_match_value.value;
return (JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<void,ErrorOr<interpreter::StatementResult>>{
auto __jakt_enum_value = (prelude_function);
if (__jakt_enum_value == Jakt::DeprecatedString("println"sv)) {
return (outln(format_string,x)), JaktInternal::ExplicitValue<void>();
}
else if (__jakt_enum_value == Jakt::DeprecatedString("eprintln"sv)) {
return (warnln(format_string,x)), JaktInternal::ExplicitValue<void>();
}
else if (__jakt_enum_value == Jakt::DeprecatedString("print"sv)) {
return (out(format_string,x)), JaktInternal::ExplicitValue<void>();
}
else {
return (warn(format_string,x)), JaktInternal::ExplicitValue<void>();
}
return JaktInternal::ExplicitValue<void>();
}()))
), JaktInternal::ExplicitValue<void>();
};/*case end*/
default: {
{
TRY((((*this).error(TRY((__jakt_format(Jakt::DeprecatedString("comptime format can only format primitves, got {}"sv),((((arguments)[static_cast<i64>(1LL)])).impl)))),call_span))));
return Error::from_errno((infallible_integer_cast<i32>((interpreter::InterpretError::InvalidType))));
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
}/*switch end*/
}()
))), JaktInternal::ExplicitValue<void>();
}
else {
{
TRY((((*this).error(TRY((__jakt_format(Jakt::DeprecatedString("comptime format accepts at most two arguments, but got {}"sv),((arguments).size())))),call_span))));
return Error::from_errno((infallible_integer_cast<i32>((interpreter::InterpretError::InvalidType))));
}
return JaktInternal::ExplicitValue<void>();
}
return JaktInternal::ExplicitValue<void>();
}()))
;
__jakt_var_150 =  interpreter::StatementResult { typename interpreter::StatementResult::JustValue(types::Value(TRY((types::ValueImpl::template create<typename types::ValueImpl::Void>())),call_span)) } ; goto __jakt_label_147;

}
__jakt_label_147:; __jakt_var_150.release_value(); }));
}
else if (__jakt_enum_value == Jakt::DeprecatedString("eprintln"sv)) {
return JaktInternal::ExplicitValue(({ Optional<interpreter::StatementResult> __jakt_var_151; {
DeprecatedString const format_string = JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<DeprecatedString, ErrorOr<interpreter::StatementResult>>{
auto&& __jakt_match_variant = *((((arguments)[static_cast<i64>(0LL)])).impl);
switch(__jakt_match_variant.index()) {
case 13: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::JaktString>();
DeprecatedString const& x = __jakt_match_value.value;
return JaktInternal::ExplicitValue(x);
};/*case end*/
default: {
{
TRY((((*this).error(TRY((__jakt_format(Jakt::DeprecatedString("println expects a string as its first argument, but got {}"sv),((((arguments)[static_cast<i64>(0LL)])).impl)))),call_span))));
return Error::from_errno((infallible_integer_cast<i32>((interpreter::InterpretError::InvalidType))));
}
};/*case end*/
}/*switch end*/
}()
));
JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<void,ErrorOr<interpreter::StatementResult>>{
auto __jakt_enum_value = (((arguments).size()));
if (__jakt_enum_value == static_cast<size_t>(1ULL)) {
return (JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<void,ErrorOr<interpreter::StatementResult>>{
auto __jakt_enum_value = (prelude_function);
if (__jakt_enum_value == Jakt::DeprecatedString("println"sv)) {
return (outln(format_string)), JaktInternal::ExplicitValue<void>();
}
else if (__jakt_enum_value == Jakt::DeprecatedString("eprintln"sv)) {
return (warnln(format_string)), JaktInternal::ExplicitValue<void>();
}
else if (__jakt_enum_value == Jakt::DeprecatedString("print"sv)) {
return (out(format_string)), JaktInternal::ExplicitValue<void>();
}
else {
return (warn(format_string)), JaktInternal::ExplicitValue<void>();
}
return JaktInternal::ExplicitValue<void>();
}()))
), JaktInternal::ExplicitValue<void>();
}
else if (__jakt_enum_value == static_cast<size_t>(2ULL)) {
return (JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<void, ErrorOr<interpreter::StatementResult>>{
auto&& __jakt_match_variant = *((((arguments)[static_cast<i64>(1LL)])).impl);
switch(__jakt_match_variant.index()) {
case 1: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::Bool>();
bool const& x = __jakt_match_value.value;
return (JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<void,ErrorOr<interpreter::StatementResult>>{
auto __jakt_enum_value = (prelude_function);
if (__jakt_enum_value == Jakt::DeprecatedString("println"sv)) {
return (outln(format_string,x)), JaktInternal::ExplicitValue<void>();
}
else if (__jakt_enum_value == Jakt::DeprecatedString("eprintln"sv)) {
return (warnln(format_string,x)), JaktInternal::ExplicitValue<void>();
}
else if (__jakt_enum_value == Jakt::DeprecatedString("print"sv)) {
return (out(format_string,x)), JaktInternal::ExplicitValue<void>();
}
else {
return (warn(format_string,x)), JaktInternal::ExplicitValue<void>();
}
return JaktInternal::ExplicitValue<void>();
}()))
), JaktInternal::ExplicitValue<void>();
};/*case end*/
case 2: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::U8>();
u8 const& x = __jakt_match_value.value;
return (JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<void,ErrorOr<interpreter::StatementResult>>{
auto __jakt_enum_value = (prelude_function);
if (__jakt_enum_value == Jakt::DeprecatedString("println"sv)) {
return (outln(format_string,x)), JaktInternal::ExplicitValue<void>();
}
else if (__jakt_enum_value == Jakt::DeprecatedString("eprintln"sv)) {
return (warnln(format_string,x)), JaktInternal::ExplicitValue<void>();
}
else if (__jakt_enum_value == Jakt::DeprecatedString("print"sv)) {
return (out(format_string,x)), JaktInternal::ExplicitValue<void>();
}
else {
return (warn(format_string,x)), JaktInternal::ExplicitValue<void>();
}
return JaktInternal::ExplicitValue<void>();
}()))
), JaktInternal::ExplicitValue<void>();
};/*case end*/
case 3: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::U16>();
u16 const& x = __jakt_match_value.value;
return (JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<void,ErrorOr<interpreter::StatementResult>>{
auto __jakt_enum_value = (prelude_function);
if (__jakt_enum_value == Jakt::DeprecatedString("println"sv)) {
return (outln(format_string,x)), JaktInternal::ExplicitValue<void>();
}
else if (__jakt_enum_value == Jakt::DeprecatedString("eprintln"sv)) {
return (warnln(format_string,x)), JaktInternal::ExplicitValue<void>();
}
else if (__jakt_enum_value == Jakt::DeprecatedString("print"sv)) {
return (out(format_string,x)), JaktInternal::ExplicitValue<void>();
}
else {
return (warn(format_string,x)), JaktInternal::ExplicitValue<void>();
}
return JaktInternal::ExplicitValue<void>();
}()))
), JaktInternal::ExplicitValue<void>();
};/*case end*/
case 4: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::U32>();
u32 const& x = __jakt_match_value.value;
return (JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<void,ErrorOr<interpreter::StatementResult>>{
auto __jakt_enum_value = (prelude_function);
if (__jakt_enum_value == Jakt::DeprecatedString("println"sv)) {
return (outln(format_string,x)), JaktInternal::ExplicitValue<void>();
}
else if (__jakt_enum_value == Jakt::DeprecatedString("eprintln"sv)) {
return (warnln(format_string,x)), JaktInternal::ExplicitValue<void>();
}
else if (__jakt_enum_value == Jakt::DeprecatedString("print"sv)) {
return (out(format_string,x)), JaktInternal::ExplicitValue<void>();
}
else {
return (warn(format_string,x)), JaktInternal::ExplicitValue<void>();
}
return JaktInternal::ExplicitValue<void>();
}()))
), JaktInternal::ExplicitValue<void>();
};/*case end*/
case 5: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::U64>();
u64 const& x = __jakt_match_value.value;
return (JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<void,ErrorOr<interpreter::StatementResult>>{
auto __jakt_enum_value = (prelude_function);
if (__jakt_enum_value == Jakt::DeprecatedString("println"sv)) {
return (outln(format_string,x)), JaktInternal::ExplicitValue<void>();
}
else if (__jakt_enum_value == Jakt::DeprecatedString("eprintln"sv)) {
return (warnln(format_string,x)), JaktInternal::ExplicitValue<void>();
}
else if (__jakt_enum_value == Jakt::DeprecatedString("print"sv)) {
return (out(format_string,x)), JaktInternal::ExplicitValue<void>();
}
else {
return (warn(format_string,x)), JaktInternal::ExplicitValue<void>();
}
return JaktInternal::ExplicitValue<void>();
}()))
), JaktInternal::ExplicitValue<void>();
};/*case end*/
case 6: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::I8>();
i8 const& x = __jakt_match_value.value;
return (JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<void,ErrorOr<interpreter::StatementResult>>{
auto __jakt_enum_value = (prelude_function);
if (__jakt_enum_value == Jakt::DeprecatedString("println"sv)) {
return (outln(format_string,x)), JaktInternal::ExplicitValue<void>();
}
else if (__jakt_enum_value == Jakt::DeprecatedString("eprintln"sv)) {
return (warnln(format_string,x)), JaktInternal::ExplicitValue<void>();
}
else if (__jakt_enum_value == Jakt::DeprecatedString("print"sv)) {
return (out(format_string,x)), JaktInternal::ExplicitValue<void>();
}
else {
return (warn(format_string,x)), JaktInternal::ExplicitValue<void>();
}
return JaktInternal::ExplicitValue<void>();
}()))
), JaktInternal::ExplicitValue<void>();
};/*case end*/
case 7: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::I16>();
i16 const& x = __jakt_match_value.value;
return (JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<void,ErrorOr<interpreter::StatementResult>>{
auto __jakt_enum_value = (prelude_function);
if (__jakt_enum_value == Jakt::DeprecatedString("println"sv)) {
return (outln(format_string,x)), JaktInternal::ExplicitValue<void>();
}
else if (__jakt_enum_value == Jakt::DeprecatedString("eprintln"sv)) {
return (warnln(format_string,x)), JaktInternal::ExplicitValue<void>();
}
else if (__jakt_enum_value == Jakt::DeprecatedString("print"sv)) {
return (out(format_string,x)), JaktInternal::ExplicitValue<void>();
}
else {
return (warn(format_string,x)), JaktInternal::ExplicitValue<void>();
}
return JaktInternal::ExplicitValue<void>();
}()))
), JaktInternal::ExplicitValue<void>();
};/*case end*/
case 8: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::I32>();
i32 const& x = __jakt_match_value.value;
return (JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<void,ErrorOr<interpreter::StatementResult>>{
auto __jakt_enum_value = (prelude_function);
if (__jakt_enum_value == Jakt::DeprecatedString("println"sv)) {
return (outln(format_string,x)), JaktInternal::ExplicitValue<void>();
}
else if (__jakt_enum_value == Jakt::DeprecatedString("eprintln"sv)) {
return (warnln(format_string,x)), JaktInternal::ExplicitValue<void>();
}
else if (__jakt_enum_value == Jakt::DeprecatedString("print"sv)) {
return (out(format_string,x)), JaktInternal::ExplicitValue<void>();
}
else {
return (warn(format_string,x)), JaktInternal::ExplicitValue<void>();
}
return JaktInternal::ExplicitValue<void>();
}()))
), JaktInternal::ExplicitValue<void>();
};/*case end*/
case 9: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::I64>();
i64 const& x = __jakt_match_value.value;
return (JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<void,ErrorOr<interpreter::StatementResult>>{
auto __jakt_enum_value = (prelude_function);
if (__jakt_enum_value == Jakt::DeprecatedString("println"sv)) {
return (outln(format_string,x)), JaktInternal::ExplicitValue<void>();
}
else if (__jakt_enum_value == Jakt::DeprecatedString("eprintln"sv)) {
return (warnln(format_string,x)), JaktInternal::ExplicitValue<void>();
}
else if (__jakt_enum_value == Jakt::DeprecatedString("print"sv)) {
return (out(format_string,x)), JaktInternal::ExplicitValue<void>();
}
else {
return (warn(format_string,x)), JaktInternal::ExplicitValue<void>();
}
return JaktInternal::ExplicitValue<void>();
}()))
), JaktInternal::ExplicitValue<void>();
};/*case end*/
case 10: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::F32>();
f32 const& x = __jakt_match_value.value;
return (JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<void,ErrorOr<interpreter::StatementResult>>{
auto __jakt_enum_value = (prelude_function);
if (__jakt_enum_value == Jakt::DeprecatedString("println"sv)) {
return (outln(format_string,x)), JaktInternal::ExplicitValue<void>();
}
else if (__jakt_enum_value == Jakt::DeprecatedString("eprintln"sv)) {
return (warnln(format_string,x)), JaktInternal::ExplicitValue<void>();
}
else if (__jakt_enum_value == Jakt::DeprecatedString("print"sv)) {
return (out(format_string,x)), JaktInternal::ExplicitValue<void>();
}
else {
return (warn(format_string,x)), JaktInternal::ExplicitValue<void>();
}
return JaktInternal::ExplicitValue<void>();
}()))
), JaktInternal::ExplicitValue<void>();
};/*case end*/
case 11: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::F64>();
f64 const& x = __jakt_match_value.value;
return (JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<void,ErrorOr<interpreter::StatementResult>>{
auto __jakt_enum_value = (prelude_function);
if (__jakt_enum_value == Jakt::DeprecatedString("println"sv)) {
return (outln(format_string,x)), JaktInternal::ExplicitValue<void>();
}
else if (__jakt_enum_value == Jakt::DeprecatedString("eprintln"sv)) {
return (warnln(format_string,x)), JaktInternal::ExplicitValue<void>();
}
else if (__jakt_enum_value == Jakt::DeprecatedString("print"sv)) {
return (out(format_string,x)), JaktInternal::ExplicitValue<void>();
}
else {
return (warn(format_string,x)), JaktInternal::ExplicitValue<void>();
}
return JaktInternal::ExplicitValue<void>();
}()))
), JaktInternal::ExplicitValue<void>();
};/*case end*/
case 12: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::USize>();
size_t const& x = __jakt_match_value.value;
return (JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<void,ErrorOr<interpreter::StatementResult>>{
auto __jakt_enum_value = (prelude_function);
if (__jakt_enum_value == Jakt::DeprecatedString("println"sv)) {
return (outln(format_string,x)), JaktInternal::ExplicitValue<void>();
}
else if (__jakt_enum_value == Jakt::DeprecatedString("eprintln"sv)) {
return (warnln(format_string,x)), JaktInternal::ExplicitValue<void>();
}
else if (__jakt_enum_value == Jakt::DeprecatedString("print"sv)) {
return (out(format_string,x)), JaktInternal::ExplicitValue<void>();
}
else {
return (warn(format_string,x)), JaktInternal::ExplicitValue<void>();
}
return JaktInternal::ExplicitValue<void>();
}()))
), JaktInternal::ExplicitValue<void>();
};/*case end*/
case 13: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::JaktString>();
DeprecatedString const& x = __jakt_match_value.value;
return (JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<void,ErrorOr<interpreter::StatementResult>>{
auto __jakt_enum_value = (prelude_function);
if (__jakt_enum_value == Jakt::DeprecatedString("println"sv)) {
return (outln(format_string,x)), JaktInternal::ExplicitValue<void>();
}
else if (__jakt_enum_value == Jakt::DeprecatedString("eprintln"sv)) {
return (warnln(format_string,x)), JaktInternal::ExplicitValue<void>();
}
else if (__jakt_enum_value == Jakt::DeprecatedString("print"sv)) {
return (out(format_string,x)), JaktInternal::ExplicitValue<void>();
}
else {
return (warn(format_string,x)), JaktInternal::ExplicitValue<void>();
}
return JaktInternal::ExplicitValue<void>();
}()))
), JaktInternal::ExplicitValue<void>();
};/*case end*/
case 15: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::CChar>();
char const& x = __jakt_match_value.value;
return (JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<void,ErrorOr<interpreter::StatementResult>>{
auto __jakt_enum_value = (prelude_function);
if (__jakt_enum_value == Jakt::DeprecatedString("println"sv)) {
return (outln(format_string,x)), JaktInternal::ExplicitValue<void>();
}
else if (__jakt_enum_value == Jakt::DeprecatedString("eprintln"sv)) {
return (warnln(format_string,x)), JaktInternal::ExplicitValue<void>();
}
else if (__jakt_enum_value == Jakt::DeprecatedString("print"sv)) {
return (out(format_string,x)), JaktInternal::ExplicitValue<void>();
}
else {
return (warn(format_string,x)), JaktInternal::ExplicitValue<void>();
}
return JaktInternal::ExplicitValue<void>();
}()))
), JaktInternal::ExplicitValue<void>();
};/*case end*/
case 16: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::CInt>();
int const& x = __jakt_match_value.value;
return (JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<void,ErrorOr<interpreter::StatementResult>>{
auto __jakt_enum_value = (prelude_function);
if (__jakt_enum_value == Jakt::DeprecatedString("println"sv)) {
return (outln(format_string,x)), JaktInternal::ExplicitValue<void>();
}
else if (__jakt_enum_value == Jakt::DeprecatedString("eprintln"sv)) {
return (warnln(format_string,x)), JaktInternal::ExplicitValue<void>();
}
else if (__jakt_enum_value == Jakt::DeprecatedString("print"sv)) {
return (out(format_string,x)), JaktInternal::ExplicitValue<void>();
}
else {
return (warn(format_string,x)), JaktInternal::ExplicitValue<void>();
}
return JaktInternal::ExplicitValue<void>();
}()))
), JaktInternal::ExplicitValue<void>();
};/*case end*/
default: {
{
TRY((((*this).error(TRY((__jakt_format(Jakt::DeprecatedString("comptime format can only format primitves, got {}"sv),((((arguments)[static_cast<i64>(1LL)])).impl)))),call_span))));
return Error::from_errno((infallible_integer_cast<i32>((interpreter::InterpretError::InvalidType))));
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
}/*switch end*/
}()
))), JaktInternal::ExplicitValue<void>();
}
else {
{
TRY((((*this).error(TRY((__jakt_format(Jakt::DeprecatedString("comptime format accepts at most two arguments, but got {}"sv),((arguments).size())))),call_span))));
return Error::from_errno((infallible_integer_cast<i32>((interpreter::InterpretError::InvalidType))));
}
return JaktInternal::ExplicitValue<void>();
}
return JaktInternal::ExplicitValue<void>();
}()))
;
__jakt_var_151 =  interpreter::StatementResult { typename interpreter::StatementResult::JustValue(types::Value(TRY((types::ValueImpl::template create<typename types::ValueImpl::Void>())),call_span)) } ; goto __jakt_label_148;

}
__jakt_label_148:; __jakt_var_151.release_value(); }));
}
else if (__jakt_enum_value == Jakt::DeprecatedString("print"sv)) {
return JaktInternal::ExplicitValue(({ Optional<interpreter::StatementResult> __jakt_var_152; {
DeprecatedString const format_string = JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<DeprecatedString, ErrorOr<interpreter::StatementResult>>{
auto&& __jakt_match_variant = *((((arguments)[static_cast<i64>(0LL)])).impl);
switch(__jakt_match_variant.index()) {
case 13: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::JaktString>();
DeprecatedString const& x = __jakt_match_value.value;
return JaktInternal::ExplicitValue(x);
};/*case end*/
default: {
{
TRY((((*this).error(TRY((__jakt_format(Jakt::DeprecatedString("println expects a string as its first argument, but got {}"sv),((((arguments)[static_cast<i64>(0LL)])).impl)))),call_span))));
return Error::from_errno((infallible_integer_cast<i32>((interpreter::InterpretError::InvalidType))));
}
};/*case end*/
}/*switch end*/
}()
));
JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<void,ErrorOr<interpreter::StatementResult>>{
auto __jakt_enum_value = (((arguments).size()));
if (__jakt_enum_value == static_cast<size_t>(1ULL)) {
return (JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<void,ErrorOr<interpreter::StatementResult>>{
auto __jakt_enum_value = (prelude_function);
if (__jakt_enum_value == Jakt::DeprecatedString("println"sv)) {
return (outln(format_string)), JaktInternal::ExplicitValue<void>();
}
else if (__jakt_enum_value == Jakt::DeprecatedString("eprintln"sv)) {
return (warnln(format_string)), JaktInternal::ExplicitValue<void>();
}
else if (__jakt_enum_value == Jakt::DeprecatedString("print"sv)) {
return (out(format_string)), JaktInternal::ExplicitValue<void>();
}
else {
return (warn(format_string)), JaktInternal::ExplicitValue<void>();
}
return JaktInternal::ExplicitValue<void>();
}()))
), JaktInternal::ExplicitValue<void>();
}
else if (__jakt_enum_value == static_cast<size_t>(2ULL)) {
return (JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<void, ErrorOr<interpreter::StatementResult>>{
auto&& __jakt_match_variant = *((((arguments)[static_cast<i64>(1LL)])).impl);
switch(__jakt_match_variant.index()) {
case 1: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::Bool>();
bool const& x = __jakt_match_value.value;
return (JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<void,ErrorOr<interpreter::StatementResult>>{
auto __jakt_enum_value = (prelude_function);
if (__jakt_enum_value == Jakt::DeprecatedString("println"sv)) {
return (outln(format_string,x)), JaktInternal::ExplicitValue<void>();
}
else if (__jakt_enum_value == Jakt::DeprecatedString("eprintln"sv)) {
return (warnln(format_string,x)), JaktInternal::ExplicitValue<void>();
}
else if (__jakt_enum_value == Jakt::DeprecatedString("print"sv)) {
return (out(format_string,x)), JaktInternal::ExplicitValue<void>();
}
else {
return (warn(format_string,x)), JaktInternal::ExplicitValue<void>();
}
return JaktInternal::ExplicitValue<void>();
}()))
), JaktInternal::ExplicitValue<void>();
};/*case end*/
case 2: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::U8>();
u8 const& x = __jakt_match_value.value;
return (JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<void,ErrorOr<interpreter::StatementResult>>{
auto __jakt_enum_value = (prelude_function);
if (__jakt_enum_value == Jakt::DeprecatedString("println"sv)) {
return (outln(format_string,x)), JaktInternal::ExplicitValue<void>();
}
else if (__jakt_enum_value == Jakt::DeprecatedString("eprintln"sv)) {
return (warnln(format_string,x)), JaktInternal::ExplicitValue<void>();
}
else if (__jakt_enum_value == Jakt::DeprecatedString("print"sv)) {
return (out(format_string,x)), JaktInternal::ExplicitValue<void>();
}
else {
return (warn(format_string,x)), JaktInternal::ExplicitValue<void>();
}
return JaktInternal::ExplicitValue<void>();
}()))
), JaktInternal::ExplicitValue<void>();
};/*case end*/
case 3: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::U16>();
u16 const& x = __jakt_match_value.value;
return (JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<void,ErrorOr<interpreter::StatementResult>>{
auto __jakt_enum_value = (prelude_function);
if (__jakt_enum_value == Jakt::DeprecatedString("println"sv)) {
return (outln(format_string,x)), JaktInternal::ExplicitValue<void>();
}
else if (__jakt_enum_value == Jakt::DeprecatedString("eprintln"sv)) {
return (warnln(format_string,x)), JaktInternal::ExplicitValue<void>();
}
else if (__jakt_enum_value == Jakt::DeprecatedString("print"sv)) {
return (out(format_string,x)), JaktInternal::ExplicitValue<void>();
}
else {
return (warn(format_string,x)), JaktInternal::ExplicitValue<void>();
}
return JaktInternal::ExplicitValue<void>();
}()))
), JaktInternal::ExplicitValue<void>();
};/*case end*/
case 4: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::U32>();
u32 const& x = __jakt_match_value.value;
return (JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<void,ErrorOr<interpreter::StatementResult>>{
auto __jakt_enum_value = (prelude_function);
if (__jakt_enum_value == Jakt::DeprecatedString("println"sv)) {
return (outln(format_string,x)), JaktInternal::ExplicitValue<void>();
}
else if (__jakt_enum_value == Jakt::DeprecatedString("eprintln"sv)) {
return (warnln(format_string,x)), JaktInternal::ExplicitValue<void>();
}
else if (__jakt_enum_value == Jakt::DeprecatedString("print"sv)) {
return (out(format_string,x)), JaktInternal::ExplicitValue<void>();
}
else {
return (warn(format_string,x)), JaktInternal::ExplicitValue<void>();
}
return JaktInternal::ExplicitValue<void>();
}()))
), JaktInternal::ExplicitValue<void>();
};/*case end*/
case 5: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::U64>();
u64 const& x = __jakt_match_value.value;
return (JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<void,ErrorOr<interpreter::StatementResult>>{
auto __jakt_enum_value = (prelude_function);
if (__jakt_enum_value == Jakt::DeprecatedString("println"sv)) {
return (outln(format_string,x)), JaktInternal::ExplicitValue<void>();
}
else if (__jakt_enum_value == Jakt::DeprecatedString("eprintln"sv)) {
return (warnln(format_string,x)), JaktInternal::ExplicitValue<void>();
}
else if (__jakt_enum_value == Jakt::DeprecatedString("print"sv)) {
return (out(format_string,x)), JaktInternal::ExplicitValue<void>();
}
else {
return (warn(format_string,x)), JaktInternal::ExplicitValue<void>();
}
return JaktInternal::ExplicitValue<void>();
}()))
), JaktInternal::ExplicitValue<void>();
};/*case end*/
case 6: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::I8>();
i8 const& x = __jakt_match_value.value;
return (JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<void,ErrorOr<interpreter::StatementResult>>{
auto __jakt_enum_value = (prelude_function);
if (__jakt_enum_value == Jakt::DeprecatedString("println"sv)) {
return (outln(format_string,x)), JaktInternal::ExplicitValue<void>();
}
else if (__jakt_enum_value == Jakt::DeprecatedString("eprintln"sv)) {
return (warnln(format_string,x)), JaktInternal::ExplicitValue<void>();
}
else if (__jakt_enum_value == Jakt::DeprecatedString("print"sv)) {
return (out(format_string,x)), JaktInternal::ExplicitValue<void>();
}
else {
return (warn(format_string,x)), JaktInternal::ExplicitValue<void>();
}
return JaktInternal::ExplicitValue<void>();
}()))
), JaktInternal::ExplicitValue<void>();
};/*case end*/
case 7: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::I16>();
i16 const& x = __jakt_match_value.value;
return (JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<void,ErrorOr<interpreter::StatementResult>>{
auto __jakt_enum_value = (prelude_function);
if (__jakt_enum_value == Jakt::DeprecatedString("println"sv)) {
return (outln(format_string,x)), JaktInternal::ExplicitValue<void>();
}
else if (__jakt_enum_value == Jakt::DeprecatedString("eprintln"sv)) {
return (warnln(format_string,x)), JaktInternal::ExplicitValue<void>();
}
else if (__jakt_enum_value == Jakt::DeprecatedString("print"sv)) {
return (out(format_string,x)), JaktInternal::ExplicitValue<void>();
}
else {
return (warn(format_string,x)), JaktInternal::ExplicitValue<void>();
}
return JaktInternal::ExplicitValue<void>();
}()))
), JaktInternal::ExplicitValue<void>();
};/*case end*/
case 8: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::I32>();
i32 const& x = __jakt_match_value.value;
return (JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<void,ErrorOr<interpreter::StatementResult>>{
auto __jakt_enum_value = (prelude_function);
if (__jakt_enum_value == Jakt::DeprecatedString("println"sv)) {
return (outln(format_string,x)), JaktInternal::ExplicitValue<void>();
}
else if (__jakt_enum_value == Jakt::DeprecatedString("eprintln"sv)) {
return (warnln(format_string,x)), JaktInternal::ExplicitValue<void>();
}
else if (__jakt_enum_value == Jakt::DeprecatedString("print"sv)) {
return (out(format_string,x)), JaktInternal::ExplicitValue<void>();
}
else {
return (warn(format_string,x)), JaktInternal::ExplicitValue<void>();
}
return JaktInternal::ExplicitValue<void>();
}()))
), JaktInternal::ExplicitValue<void>();
};/*case end*/
case 9: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::I64>();
i64 const& x = __jakt_match_value.value;
return (JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<void,ErrorOr<interpreter::StatementResult>>{
auto __jakt_enum_value = (prelude_function);
if (__jakt_enum_value == Jakt::DeprecatedString("println"sv)) {
return (outln(format_string,x)), JaktInternal::ExplicitValue<void>();
}
else if (__jakt_enum_value == Jakt::DeprecatedString("eprintln"sv)) {
return (warnln(format_string,x)), JaktInternal::ExplicitValue<void>();
}
else if (__jakt_enum_value == Jakt::DeprecatedString("print"sv)) {
return (out(format_string,x)), JaktInternal::ExplicitValue<void>();
}
else {
return (warn(format_string,x)), JaktInternal::ExplicitValue<void>();
}
return JaktInternal::ExplicitValue<void>();
}()))
), JaktInternal::ExplicitValue<void>();
};/*case end*/
case 10: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::F32>();
f32 const& x = __jakt_match_value.value;
return (JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<void,ErrorOr<interpreter::StatementResult>>{
auto __jakt_enum_value = (prelude_function);
if (__jakt_enum_value == Jakt::DeprecatedString("println"sv)) {
return (outln(format_string,x)), JaktInternal::ExplicitValue<void>();
}
else if (__jakt_enum_value == Jakt::DeprecatedString("eprintln"sv)) {
return (warnln(format_string,x)), JaktInternal::ExplicitValue<void>();
}
else if (__jakt_enum_value == Jakt::DeprecatedString("print"sv)) {
return (out(format_string,x)), JaktInternal::ExplicitValue<void>();
}
else {
return (warn(format_string,x)), JaktInternal::ExplicitValue<void>();
}
return JaktInternal::ExplicitValue<void>();
}()))
), JaktInternal::ExplicitValue<void>();
};/*case end*/
case 11: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::F64>();
f64 const& x = __jakt_match_value.value;
return (JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<void,ErrorOr<interpreter::StatementResult>>{
auto __jakt_enum_value = (prelude_function);
if (__jakt_enum_value == Jakt::DeprecatedString("println"sv)) {
return (outln(format_string,x)), JaktInternal::ExplicitValue<void>();
}
else if (__jakt_enum_value == Jakt::DeprecatedString("eprintln"sv)) {
return (warnln(format_string,x)), JaktInternal::ExplicitValue<void>();
}
else if (__jakt_enum_value == Jakt::DeprecatedString("print"sv)) {
return (out(format_string,x)), JaktInternal::ExplicitValue<void>();
}
else {
return (warn(format_string,x)), JaktInternal::ExplicitValue<void>();
}
return JaktInternal::ExplicitValue<void>();
}()))
), JaktInternal::ExplicitValue<void>();
};/*case end*/
case 12: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::USize>();
size_t const& x = __jakt_match_value.value;
return (JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<void,ErrorOr<interpreter::StatementResult>>{
auto __jakt_enum_value = (prelude_function);
if (__jakt_enum_value == Jakt::DeprecatedString("println"sv)) {
return (outln(format_string,x)), JaktInternal::ExplicitValue<void>();
}
else if (__jakt_enum_value == Jakt::DeprecatedString("eprintln"sv)) {
return (warnln(format_string,x)), JaktInternal::ExplicitValue<void>();
}
else if (__jakt_enum_value == Jakt::DeprecatedString("print"sv)) {
return (out(format_string,x)), JaktInternal::ExplicitValue<void>();
}
else {
return (warn(format_string,x)), JaktInternal::ExplicitValue<void>();
}
return JaktInternal::ExplicitValue<void>();
}()))
), JaktInternal::ExplicitValue<void>();
};/*case end*/
case 13: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::JaktString>();
DeprecatedString const& x = __jakt_match_value.value;
return (JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<void,ErrorOr<interpreter::StatementResult>>{
auto __jakt_enum_value = (prelude_function);
if (__jakt_enum_value == Jakt::DeprecatedString("println"sv)) {
return (outln(format_string,x)), JaktInternal::ExplicitValue<void>();
}
else if (__jakt_enum_value == Jakt::DeprecatedString("eprintln"sv)) {
return (warnln(format_string,x)), JaktInternal::ExplicitValue<void>();
}
else if (__jakt_enum_value == Jakt::DeprecatedString("print"sv)) {
return (out(format_string,x)), JaktInternal::ExplicitValue<void>();
}
else {
return (warn(format_string,x)), JaktInternal::ExplicitValue<void>();
}
return JaktInternal::ExplicitValue<void>();
}()))
), JaktInternal::ExplicitValue<void>();
};/*case end*/
case 15: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::CChar>();
char const& x = __jakt_match_value.value;
return (JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<void,ErrorOr<interpreter::StatementResult>>{
auto __jakt_enum_value = (prelude_function);
if (__jakt_enum_value == Jakt::DeprecatedString("println"sv)) {
return (outln(format_string,x)), JaktInternal::ExplicitValue<void>();
}
else if (__jakt_enum_value == Jakt::DeprecatedString("eprintln"sv)) {
return (warnln(format_string,x)), JaktInternal::ExplicitValue<void>();
}
else if (__jakt_enum_value == Jakt::DeprecatedString("print"sv)) {
return (out(format_string,x)), JaktInternal::ExplicitValue<void>();
}
else {
return (warn(format_string,x)), JaktInternal::ExplicitValue<void>();
}
return JaktInternal::ExplicitValue<void>();
}()))
), JaktInternal::ExplicitValue<void>();
};/*case end*/
case 16: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::CInt>();
int const& x = __jakt_match_value.value;
return (JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<void,ErrorOr<interpreter::StatementResult>>{
auto __jakt_enum_value = (prelude_function);
if (__jakt_enum_value == Jakt::DeprecatedString("println"sv)) {
return (outln(format_string,x)), JaktInternal::ExplicitValue<void>();
}
else if (__jakt_enum_value == Jakt::DeprecatedString("eprintln"sv)) {
return (warnln(format_string,x)), JaktInternal::ExplicitValue<void>();
}
else if (__jakt_enum_value == Jakt::DeprecatedString("print"sv)) {
return (out(format_string,x)), JaktInternal::ExplicitValue<void>();
}
else {
return (warn(format_string,x)), JaktInternal::ExplicitValue<void>();
}
return JaktInternal::ExplicitValue<void>();
}()))
), JaktInternal::ExplicitValue<void>();
};/*case end*/
default: {
{
TRY((((*this).error(TRY((__jakt_format(Jakt::DeprecatedString("comptime format can only format primitves, got {}"sv),((((arguments)[static_cast<i64>(1LL)])).impl)))),call_span))));
return Error::from_errno((infallible_integer_cast<i32>((interpreter::InterpretError::InvalidType))));
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
}/*switch end*/
}()
))), JaktInternal::ExplicitValue<void>();
}
else {
{
TRY((((*this).error(TRY((__jakt_format(Jakt::DeprecatedString("comptime format accepts at most two arguments, but got {}"sv),((arguments).size())))),call_span))));
return Error::from_errno((infallible_integer_cast<i32>((interpreter::InterpretError::InvalidType))));
}
return JaktInternal::ExplicitValue<void>();
}
return JaktInternal::ExplicitValue<void>();
}()))
;
__jakt_var_152 =  interpreter::StatementResult { typename interpreter::StatementResult::JustValue(types::Value(TRY((types::ValueImpl::template create<typename types::ValueImpl::Void>())),call_span)) } ; goto __jakt_label_149;

}
__jakt_label_149:; __jakt_var_152.release_value(); }));
}
else if (__jakt_enum_value == Jakt::DeprecatedString("eprint"sv)) {
return JaktInternal::ExplicitValue(({ Optional<interpreter::StatementResult> __jakt_var_153; {
DeprecatedString const format_string = JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<DeprecatedString, ErrorOr<interpreter::StatementResult>>{
auto&& __jakt_match_variant = *((((arguments)[static_cast<i64>(0LL)])).impl);
switch(__jakt_match_variant.index()) {
case 13: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::JaktString>();
DeprecatedString const& x = __jakt_match_value.value;
return JaktInternal::ExplicitValue(x);
};/*case end*/
default: {
{
TRY((((*this).error(TRY((__jakt_format(Jakt::DeprecatedString("println expects a string as its first argument, but got {}"sv),((((arguments)[static_cast<i64>(0LL)])).impl)))),call_span))));
return Error::from_errno((infallible_integer_cast<i32>((interpreter::InterpretError::InvalidType))));
}
};/*case end*/
}/*switch end*/
}()
));
JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<void,ErrorOr<interpreter::StatementResult>>{
auto __jakt_enum_value = (((arguments).size()));
if (__jakt_enum_value == static_cast<size_t>(1ULL)) {
return (JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<void,ErrorOr<interpreter::StatementResult>>{
auto __jakt_enum_value = (prelude_function);
if (__jakt_enum_value == Jakt::DeprecatedString("println"sv)) {
return (outln(format_string)), JaktInternal::ExplicitValue<void>();
}
else if (__jakt_enum_value == Jakt::DeprecatedString("eprintln"sv)) {
return (warnln(format_string)), JaktInternal::ExplicitValue<void>();
}
else if (__jakt_enum_value == Jakt::DeprecatedString("print"sv)) {
return (out(format_string)), JaktInternal::ExplicitValue<void>();
}
else {
return (warn(format_string)), JaktInternal::ExplicitValue<void>();
}
return JaktInternal::ExplicitValue<void>();
}()))
), JaktInternal::ExplicitValue<void>();
}
else if (__jakt_enum_value == static_cast<size_t>(2ULL)) {
return (JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<void, ErrorOr<interpreter::StatementResult>>{
auto&& __jakt_match_variant = *((((arguments)[static_cast<i64>(1LL)])).impl);
switch(__jakt_match_variant.index()) {
case 1: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::Bool>();
bool const& x = __jakt_match_value.value;
return (JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<void,ErrorOr<interpreter::StatementResult>>{
auto __jakt_enum_value = (prelude_function);
if (__jakt_enum_value == Jakt::DeprecatedString("println"sv)) {
return (outln(format_string,x)), JaktInternal::ExplicitValue<void>();
}
else if (__jakt_enum_value == Jakt::DeprecatedString("eprintln"sv)) {
return (warnln(format_string,x)), JaktInternal::ExplicitValue<void>();
}
else if (__jakt_enum_value == Jakt::DeprecatedString("print"sv)) {
return (out(format_string,x)), JaktInternal::ExplicitValue<void>();
}
else {
return (warn(format_string,x)), JaktInternal::ExplicitValue<void>();
}
return JaktInternal::ExplicitValue<void>();
}()))
), JaktInternal::ExplicitValue<void>();
};/*case end*/
case 2: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::U8>();
u8 const& x = __jakt_match_value.value;
return (JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<void,ErrorOr<interpreter::StatementResult>>{
auto __jakt_enum_value = (prelude_function);
if (__jakt_enum_value == Jakt::DeprecatedString("println"sv)) {
return (outln(format_string,x)), JaktInternal::ExplicitValue<void>();
}
else if (__jakt_enum_value == Jakt::DeprecatedString("eprintln"sv)) {
return (warnln(format_string,x)), JaktInternal::ExplicitValue<void>();
}
else if (__jakt_enum_value == Jakt::DeprecatedString("print"sv)) {
return (out(format_string,x)), JaktInternal::ExplicitValue<void>();
}
else {
return (warn(format_string,x)), JaktInternal::ExplicitValue<void>();
}
return JaktInternal::ExplicitValue<void>();
}()))
), JaktInternal::ExplicitValue<void>();
};/*case end*/
case 3: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::U16>();
u16 const& x = __jakt_match_value.value;
return (JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<void,ErrorOr<interpreter::StatementResult>>{
auto __jakt_enum_value = (prelude_function);
if (__jakt_enum_value == Jakt::DeprecatedString("println"sv)) {
return (outln(format_string,x)), JaktInternal::ExplicitValue<void>();
}
else if (__jakt_enum_value == Jakt::DeprecatedString("eprintln"sv)) {
return (warnln(format_string,x)), JaktInternal::ExplicitValue<void>();
}
else if (__jakt_enum_value == Jakt::DeprecatedString("print"sv)) {
return (out(format_string,x)), JaktInternal::ExplicitValue<void>();
}
else {
return (warn(format_string,x)), JaktInternal::ExplicitValue<void>();
}
return JaktInternal::ExplicitValue<void>();
}()))
), JaktInternal::ExplicitValue<void>();
};/*case end*/
case 4: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::U32>();
u32 const& x = __jakt_match_value.value;
return (JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<void,ErrorOr<interpreter::StatementResult>>{
auto __jakt_enum_value = (prelude_function);
if (__jakt_enum_value == Jakt::DeprecatedString("println"sv)) {
return (outln(format_string,x)), JaktInternal::ExplicitValue<void>();
}
else if (__jakt_enum_value == Jakt::DeprecatedString("eprintln"sv)) {
return (warnln(format_string,x)), JaktInternal::ExplicitValue<void>();
}
else if (__jakt_enum_value == Jakt::DeprecatedString("print"sv)) {
return (out(format_string,x)), JaktInternal::ExplicitValue<void>();
}
else {
return (warn(format_string,x)), JaktInternal::ExplicitValue<void>();
}
return JaktInternal::ExplicitValue<void>();
}()))
), JaktInternal::ExplicitValue<void>();
};/*case end*/
case 5: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::U64>();
u64 const& x = __jakt_match_value.value;
return (JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<void,ErrorOr<interpreter::StatementResult>>{
auto __jakt_enum_value = (prelude_function);
if (__jakt_enum_value == Jakt::DeprecatedString("println"sv)) {
return (outln(format_string,x)), JaktInternal::ExplicitValue<void>();
}
else if (__jakt_enum_value == Jakt::DeprecatedString("eprintln"sv)) {
return (warnln(format_string,x)), JaktInternal::ExplicitValue<void>();
}
else if (__jakt_enum_value == Jakt::DeprecatedString("print"sv)) {
return (out(format_string,x)), JaktInternal::ExplicitValue<void>();
}
else {
return (warn(format_string,x)), JaktInternal::ExplicitValue<void>();
}
return JaktInternal::ExplicitValue<void>();
}()))
), JaktInternal::ExplicitValue<void>();
};/*case end*/
case 6: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::I8>();
i8 const& x = __jakt_match_value.value;
return (JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<void,ErrorOr<interpreter::StatementResult>>{
auto __jakt_enum_value = (prelude_function);
if (__jakt_enum_value == Jakt::DeprecatedString("println"sv)) {
return (outln(format_string,x)), JaktInternal::ExplicitValue<void>();
}
else if (__jakt_enum_value == Jakt::DeprecatedString("eprintln"sv)) {
return (warnln(format_string,x)), JaktInternal::ExplicitValue<void>();
}
else if (__jakt_enum_value == Jakt::DeprecatedString("print"sv)) {
return (out(format_string,x)), JaktInternal::ExplicitValue<void>();
}
else {
return (warn(format_string,x)), JaktInternal::ExplicitValue<void>();
}
return JaktInternal::ExplicitValue<void>();
}()))
), JaktInternal::ExplicitValue<void>();
};/*case end*/
case 7: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::I16>();
i16 const& x = __jakt_match_value.value;
return (JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<void,ErrorOr<interpreter::StatementResult>>{
auto __jakt_enum_value = (prelude_function);
if (__jakt_enum_value == Jakt::DeprecatedString("println"sv)) {
return (outln(format_string,x)), JaktInternal::ExplicitValue<void>();
}
else if (__jakt_enum_value == Jakt::DeprecatedString("eprintln"sv)) {
return (warnln(format_string,x)), JaktInternal::ExplicitValue<void>();
}
else if (__jakt_enum_value == Jakt::DeprecatedString("print"sv)) {
return (out(format_string,x)), JaktInternal::ExplicitValue<void>();
}
else {
return (warn(format_string,x)), JaktInternal::ExplicitValue<void>();
}
return JaktInternal::ExplicitValue<void>();
}()))
), JaktInternal::ExplicitValue<void>();
};/*case end*/
case 8: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::I32>();
i32 const& x = __jakt_match_value.value;
return (JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<void,ErrorOr<interpreter::StatementResult>>{
auto __jakt_enum_value = (prelude_function);
if (__jakt_enum_value == Jakt::DeprecatedString("println"sv)) {
return (outln(format_string,x)), JaktInternal::ExplicitValue<void>();
}
else if (__jakt_enum_value == Jakt::DeprecatedString("eprintln"sv)) {
return (warnln(format_string,x)), JaktInternal::ExplicitValue<void>();
}
else if (__jakt_enum_value == Jakt::DeprecatedString("print"sv)) {
return (out(format_string,x)), JaktInternal::ExplicitValue<void>();
}
else {
return (warn(format_string,x)), JaktInternal::ExplicitValue<void>();
}
return JaktInternal::ExplicitValue<void>();
}()))
), JaktInternal::ExplicitValue<void>();
};/*case end*/
case 9: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::I64>();
i64 const& x = __jakt_match_value.value;
return (JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<void,ErrorOr<interpreter::StatementResult>>{
auto __jakt_enum_value = (prelude_function);
if (__jakt_enum_value == Jakt::DeprecatedString("println"sv)) {
return (outln(format_string,x)), JaktInternal::ExplicitValue<void>();
}
else if (__jakt_enum_value == Jakt::DeprecatedString("eprintln"sv)) {
return (warnln(format_string,x)), JaktInternal::ExplicitValue<void>();
}
else if (__jakt_enum_value == Jakt::DeprecatedString("print"sv)) {
return (out(format_string,x)), JaktInternal::ExplicitValue<void>();
}
else {
return (warn(format_string,x)), JaktInternal::ExplicitValue<void>();
}
return JaktInternal::ExplicitValue<void>();
}()))
), JaktInternal::ExplicitValue<void>();
};/*case end*/
case 10: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::F32>();
f32 const& x = __jakt_match_value.value;
return (JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<void,ErrorOr<interpreter::StatementResult>>{
auto __jakt_enum_value = (prelude_function);
if (__jakt_enum_value == Jakt::DeprecatedString("println"sv)) {
return (outln(format_string,x)), JaktInternal::ExplicitValue<void>();
}
else if (__jakt_enum_value == Jakt::DeprecatedString("eprintln"sv)) {
return (warnln(format_string,x)), JaktInternal::ExplicitValue<void>();
}
else if (__jakt_enum_value == Jakt::DeprecatedString("print"sv)) {
return (out(format_string,x)), JaktInternal::ExplicitValue<void>();
}
else {
return (warn(format_string,x)), JaktInternal::ExplicitValue<void>();
}
return JaktInternal::ExplicitValue<void>();
}()))
), JaktInternal::ExplicitValue<void>();
};/*case end*/
case 11: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::F64>();
f64 const& x = __jakt_match_value.value;
return (JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<void,ErrorOr<interpreter::StatementResult>>{
auto __jakt_enum_value = (prelude_function);
if (__jakt_enum_value == Jakt::DeprecatedString("println"sv)) {
return (outln(format_string,x)), JaktInternal::ExplicitValue<void>();
}
else if (__jakt_enum_value == Jakt::DeprecatedString("eprintln"sv)) {
return (warnln(format_string,x)), JaktInternal::ExplicitValue<void>();
}
else if (__jakt_enum_value == Jakt::DeprecatedString("print"sv)) {
return (out(format_string,x)), JaktInternal::ExplicitValue<void>();
}
else {
return (warn(format_string,x)), JaktInternal::ExplicitValue<void>();
}
return JaktInternal::ExplicitValue<void>();
}()))
), JaktInternal::ExplicitValue<void>();
};/*case end*/
case 12: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::USize>();
size_t const& x = __jakt_match_value.value;
return (JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<void,ErrorOr<interpreter::StatementResult>>{
auto __jakt_enum_value = (prelude_function);
if (__jakt_enum_value == Jakt::DeprecatedString("println"sv)) {
return (outln(format_string,x)), JaktInternal::ExplicitValue<void>();
}
else if (__jakt_enum_value == Jakt::DeprecatedString("eprintln"sv)) {
return (warnln(format_string,x)), JaktInternal::ExplicitValue<void>();
}
else if (__jakt_enum_value == Jakt::DeprecatedString("print"sv)) {
return (out(format_string,x)), JaktInternal::ExplicitValue<void>();
}
else {
return (warn(format_string,x)), JaktInternal::ExplicitValue<void>();
}
return JaktInternal::ExplicitValue<void>();
}()))
), JaktInternal::ExplicitValue<void>();
};/*case end*/
case 13: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::JaktString>();
DeprecatedString const& x = __jakt_match_value.value;
return (JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<void,ErrorOr<interpreter::StatementResult>>{
auto __jakt_enum_value = (prelude_function);
if (__jakt_enum_value == Jakt::DeprecatedString("println"sv)) {
return (outln(format_string,x)), JaktInternal::ExplicitValue<void>();
}
else if (__jakt_enum_value == Jakt::DeprecatedString("eprintln"sv)) {
return (warnln(format_string,x)), JaktInternal::ExplicitValue<void>();
}
else if (__jakt_enum_value == Jakt::DeprecatedString("print"sv)) {
return (out(format_string,x)), JaktInternal::ExplicitValue<void>();
}
else {
return (warn(format_string,x)), JaktInternal::ExplicitValue<void>();
}
return JaktInternal::ExplicitValue<void>();
}()))
), JaktInternal::ExplicitValue<void>();
};/*case end*/
case 15: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::CChar>();
char const& x = __jakt_match_value.value;
return (JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<void,ErrorOr<interpreter::StatementResult>>{
auto __jakt_enum_value = (prelude_function);
if (__jakt_enum_value == Jakt::DeprecatedString("println"sv)) {
return (outln(format_string,x)), JaktInternal::ExplicitValue<void>();
}
else if (__jakt_enum_value == Jakt::DeprecatedString("eprintln"sv)) {
return (warnln(format_string,x)), JaktInternal::ExplicitValue<void>();
}
else if (__jakt_enum_value == Jakt::DeprecatedString("print"sv)) {
return (out(format_string,x)), JaktInternal::ExplicitValue<void>();
}
else {
return (warn(format_string,x)), JaktInternal::ExplicitValue<void>();
}
return JaktInternal::ExplicitValue<void>();
}()))
), JaktInternal::ExplicitValue<void>();
};/*case end*/
case 16: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::CInt>();
int const& x = __jakt_match_value.value;
return (JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<void,ErrorOr<interpreter::StatementResult>>{
auto __jakt_enum_value = (prelude_function);
if (__jakt_enum_value == Jakt::DeprecatedString("println"sv)) {
return (outln(format_string,x)), JaktInternal::ExplicitValue<void>();
}
else if (__jakt_enum_value == Jakt::DeprecatedString("eprintln"sv)) {
return (warnln(format_string,x)), JaktInternal::ExplicitValue<void>();
}
else if (__jakt_enum_value == Jakt::DeprecatedString("print"sv)) {
return (out(format_string,x)), JaktInternal::ExplicitValue<void>();
}
else {
return (warn(format_string,x)), JaktInternal::ExplicitValue<void>();
}
return JaktInternal::ExplicitValue<void>();
}()))
), JaktInternal::ExplicitValue<void>();
};/*case end*/
default: {
{
TRY((((*this).error(TRY((__jakt_format(Jakt::DeprecatedString("comptime format can only format primitves, got {}"sv),((((arguments)[static_cast<i64>(1LL)])).impl)))),call_span))));
return Error::from_errno((infallible_integer_cast<i32>((interpreter::InterpretError::InvalidType))));
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
}/*switch end*/
}()
))), JaktInternal::ExplicitValue<void>();
}
else {
{
TRY((((*this).error(TRY((__jakt_format(Jakt::DeprecatedString("comptime format accepts at most two arguments, but got {}"sv),((arguments).size())))),call_span))));
return Error::from_errno((infallible_integer_cast<i32>((interpreter::InterpretError::InvalidType))));
}
return JaktInternal::ExplicitValue<void>();
}
return JaktInternal::ExplicitValue<void>();
}()))
;
__jakt_var_153 =  interpreter::StatementResult { typename interpreter::StatementResult::JustValue(types::Value(TRY((types::ValueImpl::template create<typename types::ValueImpl::Void>())),call_span)) } ; goto __jakt_label_150;

}
__jakt_label_150:; __jakt_var_153.release_value(); }));
}
else if (__jakt_enum_value == Jakt::DeprecatedString("as_saturated"sv)) {
return JaktInternal::ExplicitValue(({ Optional<interpreter::StatementResult> __jakt_var_154; {
NonnullRefPtr<types::CheckedFunction> const function_ = ((((*this).program))->get_function((((TRY((((((*this).program))->find_functions_with_name_in_scope(((((*this).program))->prelude_scope_id()),Jakt::DeprecatedString("as_saturated"sv))))).value()))[static_cast<i64>(0LL)])));
JaktInternal::Optional<types::TypeId> const output_type_id = ((type_bindings).get(TRY((((((((((((function_)->generics))->params))[static_cast<i64>(0LL)])).type_id())).to_string())))));
__jakt_var_154 =  interpreter::StatementResult { typename interpreter::StatementResult::JustValue(TRY((interpreter::cast_value_to_type(((arguments)[static_cast<i64>(0LL)]),(output_type_id.value()),*this,true)))) } ; goto __jakt_label_151;

}
__jakt_label_151:; __jakt_var_154.release_value(); }));
}
else if (__jakt_enum_value == Jakt::DeprecatedString("unchecked_mul"sv)) {
return JaktInternal::ExplicitValue(({ Optional<interpreter::StatementResult> __jakt_var_155; {
types::Value const lhs_value = ((arguments)[static_cast<i64>(0LL)]);
types::Value const rhs_value = ((arguments)[static_cast<i64>(1LL)]);
utility::Span const span = call_span;
__jakt_var_155 =  interpreter::StatementResult { typename interpreter::StatementResult::JustValue(types::Value(JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<NonnullRefPtr<typename types::ValueImpl>, ErrorOr<interpreter::StatementResult>>{
auto&& __jakt_match_variant = *((lhs_value).impl);
switch(__jakt_match_variant.index()) {
case 2: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::U8>();
u8 const& x = __jakt_match_value.value;
return JaktInternal::ExplicitValue(JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<NonnullRefPtr<typename types::ValueImpl>, ErrorOr<interpreter::StatementResult>>{
auto&& __jakt_match_variant = *((rhs_value).impl);
switch(__jakt_match_variant.index()) {
case 2: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::U8>();
u8 const& y = __jakt_match_value.value;
return JaktInternal::ExplicitValue(TRY((types::ValueImpl::template create<typename types::ValueImpl::U8>(unchecked_mul<u8>(x,y)))));
};/*case end*/
default: {
{
TRY((((*this).error(TRY((__jakt_format(Jakt::DeprecatedString("Invalid operands '{}' and '{}' to binary operation"sv),((lhs_value).type_name()),((rhs_value).type_name())))),span))));
return Error::from_errno((infallible_integer_cast<i32>((interpreter::InterpretError::InvalidType))));
}
};/*case end*/
}/*switch end*/
}()
)));
};/*case end*/
case 3: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::U16>();
u16 const& x = __jakt_match_value.value;
return JaktInternal::ExplicitValue(JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<NonnullRefPtr<typename types::ValueImpl>, ErrorOr<interpreter::StatementResult>>{
auto&& __jakt_match_variant = *((rhs_value).impl);
switch(__jakt_match_variant.index()) {
case 3: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::U16>();
u16 const& y = __jakt_match_value.value;
return JaktInternal::ExplicitValue(TRY((types::ValueImpl::template create<typename types::ValueImpl::U16>(unchecked_mul<u16>(x,y)))));
};/*case end*/
default: {
{
TRY((((*this).error(TRY((__jakt_format(Jakt::DeprecatedString("Invalid operands '{}' and '{}' to binary operation"sv),((lhs_value).type_name()),((rhs_value).type_name())))),span))));
return Error::from_errno((infallible_integer_cast<i32>((interpreter::InterpretError::InvalidType))));
}
};/*case end*/
}/*switch end*/
}()
)));
};/*case end*/
case 4: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::U32>();
u32 const& x = __jakt_match_value.value;
return JaktInternal::ExplicitValue(JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<NonnullRefPtr<typename types::ValueImpl>, ErrorOr<interpreter::StatementResult>>{
auto&& __jakt_match_variant = *((rhs_value).impl);
switch(__jakt_match_variant.index()) {
case 4: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::U32>();
u32 const& y = __jakt_match_value.value;
return JaktInternal::ExplicitValue(TRY((types::ValueImpl::template create<typename types::ValueImpl::U32>(unchecked_mul<u32>(x,y)))));
};/*case end*/
default: {
{
TRY((((*this).error(TRY((__jakt_format(Jakt::DeprecatedString("Invalid operands '{}' and '{}' to binary operation"sv),((lhs_value).type_name()),((rhs_value).type_name())))),span))));
return Error::from_errno((infallible_integer_cast<i32>((interpreter::InterpretError::InvalidType))));
}
};/*case end*/
}/*switch end*/
}()
)));
};/*case end*/
case 5: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::U64>();
u64 const& x = __jakt_match_value.value;
return JaktInternal::ExplicitValue(JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<NonnullRefPtr<typename types::ValueImpl>, ErrorOr<interpreter::StatementResult>>{
auto&& __jakt_match_variant = *((rhs_value).impl);
switch(__jakt_match_variant.index()) {
case 5: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::U64>();
u64 const& y = __jakt_match_value.value;
return JaktInternal::ExplicitValue(TRY((types::ValueImpl::template create<typename types::ValueImpl::U64>(unchecked_mul<u64>(x,y)))));
};/*case end*/
default: {
{
TRY((((*this).error(TRY((__jakt_format(Jakt::DeprecatedString("Invalid operands '{}' and '{}' to binary operation"sv),((lhs_value).type_name()),((rhs_value).type_name())))),span))));
return Error::from_errno((infallible_integer_cast<i32>((interpreter::InterpretError::InvalidType))));
}
};/*case end*/
}/*switch end*/
}()
)));
};/*case end*/
case 6: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::I8>();
i8 const& x = __jakt_match_value.value;
return JaktInternal::ExplicitValue(JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<NonnullRefPtr<typename types::ValueImpl>, ErrorOr<interpreter::StatementResult>>{
auto&& __jakt_match_variant = *((rhs_value).impl);
switch(__jakt_match_variant.index()) {
case 6: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::I8>();
i8 const& y = __jakt_match_value.value;
return JaktInternal::ExplicitValue(TRY((types::ValueImpl::template create<typename types::ValueImpl::I8>(unchecked_mul<i8>(x,y)))));
};/*case end*/
default: {
{
TRY((((*this).error(TRY((__jakt_format(Jakt::DeprecatedString("Invalid operands '{}' and '{}' to binary operation"sv),((lhs_value).type_name()),((rhs_value).type_name())))),span))));
return Error::from_errno((infallible_integer_cast<i32>((interpreter::InterpretError::InvalidType))));
}
};/*case end*/
}/*switch end*/
}()
)));
};/*case end*/
case 7: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::I16>();
i16 const& x = __jakt_match_value.value;
return JaktInternal::ExplicitValue(JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<NonnullRefPtr<typename types::ValueImpl>, ErrorOr<interpreter::StatementResult>>{
auto&& __jakt_match_variant = *((rhs_value).impl);
switch(__jakt_match_variant.index()) {
case 7: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::I16>();
i16 const& y = __jakt_match_value.value;
return JaktInternal::ExplicitValue(TRY((types::ValueImpl::template create<typename types::ValueImpl::I16>(unchecked_mul<i16>(x,y)))));
};/*case end*/
default: {
{
TRY((((*this).error(TRY((__jakt_format(Jakt::DeprecatedString("Invalid operands '{}' and '{}' to binary operation"sv),((lhs_value).type_name()),((rhs_value).type_name())))),span))));
return Error::from_errno((infallible_integer_cast<i32>((interpreter::InterpretError::InvalidType))));
}
};/*case end*/
}/*switch end*/
}()
)));
};/*case end*/
case 8: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::I32>();
i32 const& x = __jakt_match_value.value;
return JaktInternal::ExplicitValue(JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<NonnullRefPtr<typename types::ValueImpl>, ErrorOr<interpreter::StatementResult>>{
auto&& __jakt_match_variant = *((rhs_value).impl);
switch(__jakt_match_variant.index()) {
case 8: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::I32>();
i32 const& y = __jakt_match_value.value;
return JaktInternal::ExplicitValue(TRY((types::ValueImpl::template create<typename types::ValueImpl::I32>(unchecked_mul<i32>(x,y)))));
};/*case end*/
default: {
{
TRY((((*this).error(TRY((__jakt_format(Jakt::DeprecatedString("Invalid operands '{}' and '{}' to binary operation"sv),((lhs_value).type_name()),((rhs_value).type_name())))),span))));
return Error::from_errno((infallible_integer_cast<i32>((interpreter::InterpretError::InvalidType))));
}
};/*case end*/
}/*switch end*/
}()
)));
};/*case end*/
case 9: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::I64>();
i64 const& x = __jakt_match_value.value;
return JaktInternal::ExplicitValue(JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<NonnullRefPtr<typename types::ValueImpl>, ErrorOr<interpreter::StatementResult>>{
auto&& __jakt_match_variant = *((rhs_value).impl);
switch(__jakt_match_variant.index()) {
case 9: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::I64>();
i64 const& y = __jakt_match_value.value;
return JaktInternal::ExplicitValue(TRY((types::ValueImpl::template create<typename types::ValueImpl::I64>(unchecked_mul<i64>(x,y)))));
};/*case end*/
default: {
{
TRY((((*this).error(TRY((__jakt_format(Jakt::DeprecatedString("Invalid operands '{}' and '{}' to binary operation"sv),((lhs_value).type_name()),((rhs_value).type_name())))),span))));
return Error::from_errno((infallible_integer_cast<i32>((interpreter::InterpretError::InvalidType))));
}
};/*case end*/
}/*switch end*/
}()
)));
};/*case end*/
case 10: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::F32>();
f32 const& x = __jakt_match_value.value;
return JaktInternal::ExplicitValue(JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<NonnullRefPtr<typename types::ValueImpl>, ErrorOr<interpreter::StatementResult>>{
auto&& __jakt_match_variant = *((rhs_value).impl);
switch(__jakt_match_variant.index()) {
case 10: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::F32>();
f32 const& y = __jakt_match_value.value;
return JaktInternal::ExplicitValue(TRY((types::ValueImpl::template create<typename types::ValueImpl::F32>(unchecked_mul<f32>(x,y)))));
};/*case end*/
default: {
{
TRY((((*this).error(TRY((__jakt_format(Jakt::DeprecatedString("Invalid operands '{}' and '{}' to binary operation"sv),((lhs_value).type_name()),((rhs_value).type_name())))),span))));
return Error::from_errno((infallible_integer_cast<i32>((interpreter::InterpretError::InvalidType))));
}
};/*case end*/
}/*switch end*/
}()
)));
};/*case end*/
case 11: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::F64>();
f64 const& x = __jakt_match_value.value;
return JaktInternal::ExplicitValue(JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<NonnullRefPtr<typename types::ValueImpl>, ErrorOr<interpreter::StatementResult>>{
auto&& __jakt_match_variant = *((rhs_value).impl);
switch(__jakt_match_variant.index()) {
case 11: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::F64>();
f64 const& y = __jakt_match_value.value;
return JaktInternal::ExplicitValue(TRY((types::ValueImpl::template create<typename types::ValueImpl::F64>(unchecked_mul<f64>(x,y)))));
};/*case end*/
default: {
{
TRY((((*this).error(TRY((__jakt_format(Jakt::DeprecatedString("Invalid operands '{}' and '{}' to binary operation"sv),((lhs_value).type_name()),((rhs_value).type_name())))),span))));
return Error::from_errno((infallible_integer_cast<i32>((interpreter::InterpretError::InvalidType))));
}
};/*case end*/
}/*switch end*/
}()
)));
};/*case end*/
case 12: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::USize>();
size_t const& x = __jakt_match_value.value;
return JaktInternal::ExplicitValue(JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<NonnullRefPtr<typename types::ValueImpl>, ErrorOr<interpreter::StatementResult>>{
auto&& __jakt_match_variant = *((rhs_value).impl);
switch(__jakt_match_variant.index()) {
case 12: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::USize>();
size_t const& y = __jakt_match_value.value;
return JaktInternal::ExplicitValue(TRY((types::ValueImpl::template create<typename types::ValueImpl::USize>(unchecked_mul<size_t>(x,y)))));
};/*case end*/
default: {
{
TRY((((*this).error(TRY((__jakt_format(Jakt::DeprecatedString("Invalid operands '{}' and '{}' to binary operation"sv),((lhs_value).type_name()),((rhs_value).type_name())))),span))));
return Error::from_errno((infallible_integer_cast<i32>((interpreter::InterpretError::InvalidType))));
}
};/*case end*/
}/*switch end*/
}()
)));
};/*case end*/
default: {
{
TRY((((*this).error(TRY((__jakt_format(Jakt::DeprecatedString("Invalid operands '{}' and '{}' to binary operation"sv),((lhs_value).type_name()),((rhs_value).type_name())))),span))));
return Error::from_errno((infallible_integer_cast<i32>((interpreter::InterpretError::InvalidType))));
}
};/*case end*/
}/*switch end*/
}()
)),span)) } ; goto __jakt_label_152;

}
__jakt_label_152:; __jakt_var_155.release_value(); }));
}
else if (__jakt_enum_value == Jakt::DeprecatedString("unchecked_add"sv)) {
return JaktInternal::ExplicitValue(({ Optional<interpreter::StatementResult> __jakt_var_156; {
types::Value const lhs_value = ((arguments)[static_cast<i64>(0LL)]);
types::Value const rhs_value = ((arguments)[static_cast<i64>(1LL)]);
utility::Span const span = call_span;
__jakt_var_156 =  interpreter::StatementResult { typename interpreter::StatementResult::JustValue(types::Value(JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<NonnullRefPtr<typename types::ValueImpl>, ErrorOr<interpreter::StatementResult>>{
auto&& __jakt_match_variant = *((lhs_value).impl);
switch(__jakt_match_variant.index()) {
case 2: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::U8>();
u8 const& x = __jakt_match_value.value;
return JaktInternal::ExplicitValue(JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<NonnullRefPtr<typename types::ValueImpl>, ErrorOr<interpreter::StatementResult>>{
auto&& __jakt_match_variant = *((rhs_value).impl);
switch(__jakt_match_variant.index()) {
case 2: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::U8>();
u8 const& y = __jakt_match_value.value;
return JaktInternal::ExplicitValue(TRY((types::ValueImpl::template create<typename types::ValueImpl::U8>(unchecked_add<u8>(x,y)))));
};/*case end*/
default: {
{
TRY((((*this).error(TRY((__jakt_format(Jakt::DeprecatedString("Invalid operands '{}' and '{}' to binary operation"sv),((lhs_value).type_name()),((rhs_value).type_name())))),span))));
return Error::from_errno((infallible_integer_cast<i32>((interpreter::InterpretError::InvalidType))));
}
};/*case end*/
}/*switch end*/
}()
)));
};/*case end*/
case 3: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::U16>();
u16 const& x = __jakt_match_value.value;
return JaktInternal::ExplicitValue(JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<NonnullRefPtr<typename types::ValueImpl>, ErrorOr<interpreter::StatementResult>>{
auto&& __jakt_match_variant = *((rhs_value).impl);
switch(__jakt_match_variant.index()) {
case 3: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::U16>();
u16 const& y = __jakt_match_value.value;
return JaktInternal::ExplicitValue(TRY((types::ValueImpl::template create<typename types::ValueImpl::U16>(unchecked_add<u16>(x,y)))));
};/*case end*/
default: {
{
TRY((((*this).error(TRY((__jakt_format(Jakt::DeprecatedString("Invalid operands '{}' and '{}' to binary operation"sv),((lhs_value).type_name()),((rhs_value).type_name())))),span))));
return Error::from_errno((infallible_integer_cast<i32>((interpreter::InterpretError::InvalidType))));
}
};/*case end*/
}/*switch end*/
}()
)));
};/*case end*/
case 4: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::U32>();
u32 const& x = __jakt_match_value.value;
return JaktInternal::ExplicitValue(JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<NonnullRefPtr<typename types::ValueImpl>, ErrorOr<interpreter::StatementResult>>{
auto&& __jakt_match_variant = *((rhs_value).impl);
switch(__jakt_match_variant.index()) {
case 4: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::U32>();
u32 const& y = __jakt_match_value.value;
return JaktInternal::ExplicitValue(TRY((types::ValueImpl::template create<typename types::ValueImpl::U32>(unchecked_add<u32>(x,y)))));
};/*case end*/
default: {
{
TRY((((*this).error(TRY((__jakt_format(Jakt::DeprecatedString("Invalid operands '{}' and '{}' to binary operation"sv),((lhs_value).type_name()),((rhs_value).type_name())))),span))));
return Error::from_errno((infallible_integer_cast<i32>((interpreter::InterpretError::InvalidType))));
}
};/*case end*/
}/*switch end*/
}()
)));
};/*case end*/
case 5: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::U64>();
u64 const& x = __jakt_match_value.value;
return JaktInternal::ExplicitValue(JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<NonnullRefPtr<typename types::ValueImpl>, ErrorOr<interpreter::StatementResult>>{
auto&& __jakt_match_variant = *((rhs_value).impl);
switch(__jakt_match_variant.index()) {
case 5: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::U64>();
u64 const& y = __jakt_match_value.value;
return JaktInternal::ExplicitValue(TRY((types::ValueImpl::template create<typename types::ValueImpl::U64>(unchecked_add<u64>(x,y)))));
};/*case end*/
default: {
{
TRY((((*this).error(TRY((__jakt_format(Jakt::DeprecatedString("Invalid operands '{}' and '{}' to binary operation"sv),((lhs_value).type_name()),((rhs_value).type_name())))),span))));
return Error::from_errno((infallible_integer_cast<i32>((interpreter::InterpretError::InvalidType))));
}
};/*case end*/
}/*switch end*/
}()
)));
};/*case end*/
case 6: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::I8>();
i8 const& x = __jakt_match_value.value;
return JaktInternal::ExplicitValue(JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<NonnullRefPtr<typename types::ValueImpl>, ErrorOr<interpreter::StatementResult>>{
auto&& __jakt_match_variant = *((rhs_value).impl);
switch(__jakt_match_variant.index()) {
case 6: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::I8>();
i8 const& y = __jakt_match_value.value;
return JaktInternal::ExplicitValue(TRY((types::ValueImpl::template create<typename types::ValueImpl::I8>(unchecked_add<i8>(x,y)))));
};/*case end*/
default: {
{
TRY((((*this).error(TRY((__jakt_format(Jakt::DeprecatedString("Invalid operands '{}' and '{}' to binary operation"sv),((lhs_value).type_name()),((rhs_value).type_name())))),span))));
return Error::from_errno((infallible_integer_cast<i32>((interpreter::InterpretError::InvalidType))));
}
};/*case end*/
}/*switch end*/
}()
)));
};/*case end*/
case 7: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::I16>();
i16 const& x = __jakt_match_value.value;
return JaktInternal::ExplicitValue(JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<NonnullRefPtr<typename types::ValueImpl>, ErrorOr<interpreter::StatementResult>>{
auto&& __jakt_match_variant = *((rhs_value).impl);
switch(__jakt_match_variant.index()) {
case 7: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::I16>();
i16 const& y = __jakt_match_value.value;
return JaktInternal::ExplicitValue(TRY((types::ValueImpl::template create<typename types::ValueImpl::I16>(unchecked_add<i16>(x,y)))));
};/*case end*/
default: {
{
TRY((((*this).error(TRY((__jakt_format(Jakt::DeprecatedString("Invalid operands '{}' and '{}' to binary operation"sv),((lhs_value).type_name()),((rhs_value).type_name())))),span))));
return Error::from_errno((infallible_integer_cast<i32>((interpreter::InterpretError::InvalidType))));
}
};/*case end*/
}/*switch end*/
}()
)));
};/*case end*/
case 8: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::I32>();
i32 const& x = __jakt_match_value.value;
return JaktInternal::ExplicitValue(JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<NonnullRefPtr<typename types::ValueImpl>, ErrorOr<interpreter::StatementResult>>{
auto&& __jakt_match_variant = *((rhs_value).impl);
switch(__jakt_match_variant.index()) {
case 8: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::I32>();
i32 const& y = __jakt_match_value.value;
return JaktInternal::ExplicitValue(TRY((types::ValueImpl::template create<typename types::ValueImpl::I32>(unchecked_add<i32>(x,y)))));
};/*case end*/
default: {
{
TRY((((*this).error(TRY((__jakt_format(Jakt::DeprecatedString("Invalid operands '{}' and '{}' to binary operation"sv),((lhs_value).type_name()),((rhs_value).type_name())))),span))));
return Error::from_errno((infallible_integer_cast<i32>((interpreter::InterpretError::InvalidType))));
}
};/*case end*/
}/*switch end*/
}()
)));
};/*case end*/
case 9: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::I64>();
i64 const& x = __jakt_match_value.value;
return JaktInternal::ExplicitValue(JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<NonnullRefPtr<typename types::ValueImpl>, ErrorOr<interpreter::StatementResult>>{
auto&& __jakt_match_variant = *((rhs_value).impl);
switch(__jakt_match_variant.index()) {
case 9: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::I64>();
i64 const& y = __jakt_match_value.value;
return JaktInternal::ExplicitValue(TRY((types::ValueImpl::template create<typename types::ValueImpl::I64>(unchecked_add<i64>(x,y)))));
};/*case end*/
default: {
{
TRY((((*this).error(TRY((__jakt_format(Jakt::DeprecatedString("Invalid operands '{}' and '{}' to binary operation"sv),((lhs_value).type_name()),((rhs_value).type_name())))),span))));
return Error::from_errno((infallible_integer_cast<i32>((interpreter::InterpretError::InvalidType))));
}
};/*case end*/
}/*switch end*/
}()
)));
};/*case end*/
case 10: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::F32>();
f32 const& x = __jakt_match_value.value;
return JaktInternal::ExplicitValue(JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<NonnullRefPtr<typename types::ValueImpl>, ErrorOr<interpreter::StatementResult>>{
auto&& __jakt_match_variant = *((rhs_value).impl);
switch(__jakt_match_variant.index()) {
case 10: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::F32>();
f32 const& y = __jakt_match_value.value;
return JaktInternal::ExplicitValue(TRY((types::ValueImpl::template create<typename types::ValueImpl::F32>(unchecked_add<f32>(x,y)))));
};/*case end*/
default: {
{
TRY((((*this).error(TRY((__jakt_format(Jakt::DeprecatedString("Invalid operands '{}' and '{}' to binary operation"sv),((lhs_value).type_name()),((rhs_value).type_name())))),span))));
return Error::from_errno((infallible_integer_cast<i32>((interpreter::InterpretError::InvalidType))));
}
};/*case end*/
}/*switch end*/
}()
)));
};/*case end*/
case 11: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::F64>();
f64 const& x = __jakt_match_value.value;
return JaktInternal::ExplicitValue(JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<NonnullRefPtr<typename types::ValueImpl>, ErrorOr<interpreter::StatementResult>>{
auto&& __jakt_match_variant = *((rhs_value).impl);
switch(__jakt_match_variant.index()) {
case 11: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::F64>();
f64 const& y = __jakt_match_value.value;
return JaktInternal::ExplicitValue(TRY((types::ValueImpl::template create<typename types::ValueImpl::F64>(unchecked_add<f64>(x,y)))));
};/*case end*/
default: {
{
TRY((((*this).error(TRY((__jakt_format(Jakt::DeprecatedString("Invalid operands '{}' and '{}' to binary operation"sv),((lhs_value).type_name()),((rhs_value).type_name())))),span))));
return Error::from_errno((infallible_integer_cast<i32>((interpreter::InterpretError::InvalidType))));
}
};/*case end*/
}/*switch end*/
}()
)));
};/*case end*/
case 12: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::USize>();
size_t const& x = __jakt_match_value.value;
return JaktInternal::ExplicitValue(JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<NonnullRefPtr<typename types::ValueImpl>, ErrorOr<interpreter::StatementResult>>{
auto&& __jakt_match_variant = *((rhs_value).impl);
switch(__jakt_match_variant.index()) {
case 12: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::USize>();
size_t const& y = __jakt_match_value.value;
return JaktInternal::ExplicitValue(TRY((types::ValueImpl::template create<typename types::ValueImpl::USize>(unchecked_add<size_t>(x,y)))));
};/*case end*/
default: {
{
TRY((((*this).error(TRY((__jakt_format(Jakt::DeprecatedString("Invalid operands '{}' and '{}' to binary operation"sv),((lhs_value).type_name()),((rhs_value).type_name())))),span))));
return Error::from_errno((infallible_integer_cast<i32>((interpreter::InterpretError::InvalidType))));
}
};/*case end*/
}/*switch end*/
}()
)));
};/*case end*/
default: {
{
TRY((((*this).error(TRY((__jakt_format(Jakt::DeprecatedString("Invalid operands '{}' and '{}' to binary operation"sv),((lhs_value).type_name()),((rhs_value).type_name())))),span))));
return Error::from_errno((infallible_integer_cast<i32>((interpreter::InterpretError::InvalidType))));
}
};/*case end*/
}/*switch end*/
}()
)),span)) } ; goto __jakt_label_153;

}
__jakt_label_153:; __jakt_var_156.release_value(); }));
}
else if (__jakt_enum_value == Jakt::DeprecatedString("___jakt_get_target_triple_string"sv)) {
return JaktInternal::ExplicitValue( interpreter::StatementResult { typename interpreter::StatementResult::JustValue(types::Value(TRY((types::ValueImpl::template create<typename types::ValueImpl::JaktString>(TRY((((((*this).compiler))->target_triple).try_value_or_lazy_evaluated([&]() -> ErrorOr<DeprecatedString> { return TRY((___jakt_get_target_triple_string())); })))))),call_span)) } );
}
else if (__jakt_enum_value == Jakt::DeprecatedString("abort"sv)) {
{
abort();
}
}
else if (__jakt_enum_value == Jakt::DeprecatedString("Set"sv)) {
return JaktInternal::ExplicitValue(({ Optional<interpreter::StatementResult> __jakt_var_157; {
if ((((type_bindings).size()) != static_cast<size_t>(1ULL))){
TRY((((*this).error(Jakt::DeprecatedString("Set constructor expects one generic argument"sv),call_span))));
return Error::from_errno((infallible_integer_cast<i32>((interpreter::InterpretError::InvalidType))));
}
types::StructId const set_struct_id = TRY((((((*this).program))->find_struct_in_prelude(Jakt::DeprecatedString("Set"sv)))));
types::TypeId const type_id = TRY((((*this).find_or_add_type_id(TRY((types::Type::template create<typename types::Type::GenericInstance>(set_struct_id,(TRY((DynamicArray<types::TypeId>::create_with({(((type_bindings).get(((TRY((((type_bindings).keys()))))[static_cast<i64>(0LL)]))).value())})))))))))));
__jakt_var_157 =  interpreter::StatementResult { typename interpreter::StatementResult::JustValue(types::Value(TRY((types::ValueImpl::template create<typename types::ValueImpl::JaktSet>((TRY((DynamicArray<types::Value>::create_with({})))),type_id))),call_span)) } ; goto __jakt_label_154;

}
__jakt_label_154:; __jakt_var_157.release_value(); }));
}
else if (__jakt_enum_value == Jakt::DeprecatedString("Dictionary"sv)) {
return JaktInternal::ExplicitValue(({ Optional<interpreter::StatementResult> __jakt_var_158; {
if ((((type_bindings).size()) != static_cast<size_t>(2ULL))){
TRY((((*this).error(Jakt::DeprecatedString("Dictionary constructor expects two generic argumenst"sv),call_span))));
return Error::from_errno((infallible_integer_cast<i32>((interpreter::InterpretError::InvalidType))));
}
types::StructId const dictionary_struct_id = TRY((((((*this).program))->find_struct_in_prelude(Jakt::DeprecatedString("Dictionary"sv)))));
types::TypeId const type_id = TRY((((*this).find_or_add_type_id(TRY((types::Type::template create<typename types::Type::GenericInstance>(dictionary_struct_id,(TRY((DynamicArray<types::TypeId>::create_with({(((type_bindings).get(((TRY((((type_bindings).keys()))))[static_cast<i64>(0LL)]))).value()), (((type_bindings).get(((TRY((((type_bindings).keys()))))[static_cast<i64>(1LL)]))).value())})))))))))));
__jakt_var_158 =  interpreter::StatementResult { typename interpreter::StatementResult::JustValue(types::Value(TRY((types::ValueImpl::template create<typename types::ValueImpl::JaktDictionary>((TRY((DynamicArray<types::Value>::create_with({})))),(TRY((DynamicArray<types::Value>::create_with({})))),type_id))),call_span)) } ; goto __jakt_label_155;

}
__jakt_label_155:; __jakt_var_158.release_value(); }));
}
else {
{
TRY((((*this).error(TRY((__jakt_format(Jakt::DeprecatedString("Prelude function {}::{} is not implemented yet"sv),namespace_,prelude_function))),call_span))));
return Error::from_errno((infallible_integer_cast<i32>((interpreter::InterpretError::Unimplemented))));
}
}
}()))
);
}
return (JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<interpreter::StatementResult,ErrorOr<interpreter::StatementResult>>{
auto __jakt_enum_value = (((((namespace_)[static_cast<i64>(0LL)])).name));
if (__jakt_enum_value == Jakt::DeprecatedString("Error"sv)) {
return JaktInternal::ExplicitValue(JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<interpreter::StatementResult,ErrorOr<interpreter::StatementResult>>{
auto __jakt_enum_value = (prelude_function);
if (__jakt_enum_value == Jakt::DeprecatedString("from_errno"sv)) {
return JaktInternal::ExplicitValue(({ Optional<interpreter::StatementResult> __jakt_var_159; {
types::Value const err = ((arguments)[static_cast<i64>(0LL)]);
types::StructId const error_struct_id = TRY((((((*this).program))->find_struct_in_prelude(Jakt::DeprecatedString("Error"sv)))));
types::CheckedStruct const error_struct = ((((*this).program))->get_struct(error_struct_id));
NonnullRefPtr<types::Scope> const scope = TRY((((((*this).program))->get_scope(((error_struct).scope_id)))));
JaktInternal::Optional<JaktInternal::DynamicArray<types::FunctionId>> const constructors = ((((scope)->functions)).get(Jakt::DeprecatedString("from_errno"sv)));
__jakt_var_159 =  interpreter::StatementResult { typename interpreter::StatementResult::JustValue(types::Value(TRY((types::ValueImpl::template create<typename types::ValueImpl::Struct>((TRY((DynamicArray<types::Value>::create_with({err})))),error_struct_id,(((constructors.value()))[static_cast<i64>(0LL)])))),call_span)) } ; goto __jakt_label_156;

}
__jakt_label_156:; __jakt_var_159.release_value(); }));
}
else if (__jakt_enum_value == Jakt::DeprecatedString("code"sv)) {
return JaktInternal::ExplicitValue(JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<interpreter::StatementResult, ErrorOr<interpreter::StatementResult>>{
auto&& __jakt_match_variant = *(((this_argument.value())).impl);
switch(__jakt_match_variant.index()) {
case 17: {
auto&& __jakt_match_value = __jakt_match_variant.template get<types::ValueImpl::Struct>();JaktInternal::DynamicArray<types::Value> const& fields = __jakt_match_value.fields;
return JaktInternal::ExplicitValue(JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<interpreter::StatementResult, ErrorOr<interpreter::StatementResult>>{
auto&& __jakt_match_variant = *((((fields)[static_cast<i64>(0LL)])).impl);
switch(__jakt_match_variant.index()) {
case 8: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::I32>();
i32 const& code = __jakt_match_value.value;
return JaktInternal::ExplicitValue( interpreter::StatementResult { typename interpreter::StatementResult::JustValue(types::Value(TRY((types::ValueImpl::template create<typename types::ValueImpl::I32>(code))),call_span)) } );
};/*case end*/
default: {
{
TRY((((*this).error(TRY((__jakt_format(Jakt::DeprecatedString("Error should have `i32` as its code, but got {}"sv),((((fields)[static_cast<i64>(0LL)])).impl)))),call_span))));
return Error::from_errno((infallible_integer_cast<i32>((interpreter::InterpretError::InvalidType))));
}
};/*case end*/
}/*switch end*/
}()
)));
};/*case end*/
default: {
{
TRY((((*this).error(TRY((__jakt_format(Jakt::DeprecatedString("Prelude function `Error::code` expects an Error as its this argument, but got {}"sv),(((this_argument.value())).impl)))),call_span))));
return Error::from_errno((infallible_integer_cast<i32>((interpreter::InterpretError::InvalidType))));
}
};/*case end*/
}/*switch end*/
}()
)));
}
else {
{
TRY((((*this).error(TRY((__jakt_format(Jakt::DeprecatedString("Prelude function `Error::{}` is not implemented"sv),prelude_function))),call_span))));
return Error::from_errno((infallible_integer_cast<i32>((interpreter::InterpretError::Unimplemented))));
}
}
}()))
);
}
else if (__jakt_enum_value == Jakt::DeprecatedString("File"sv)) {
return JaktInternal::ExplicitValue(JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<interpreter::StatementResult,ErrorOr<interpreter::StatementResult>>{
auto __jakt_enum_value = (prelude_function);
if (__jakt_enum_value == Jakt::DeprecatedString("open_for_reading"sv)) {
return JaktInternal::ExplicitValue(({ Optional<interpreter::StatementResult> __jakt_var_160; {
DeprecatedString const requested_path = JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<DeprecatedString, ErrorOr<interpreter::StatementResult>>{
auto&& __jakt_match_variant = *((((arguments)[static_cast<i64>(0LL)])).impl);
switch(__jakt_match_variant.index()) {
case 13: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::JaktString>();
DeprecatedString const& x = __jakt_match_value.value;
return JaktInternal::ExplicitValue(x);
};/*case end*/
default: {
{
TRY((((*this).error(TRY((__jakt_format(Jakt::DeprecatedString("Prelude function `File::{}` expects a string as its first argument, but got {}"sv),prelude_function,((((arguments)[static_cast<i64>(0LL)])).impl)))),call_span))));
return Error::from_errno((infallible_integer_cast<i32>((interpreter::InterpretError::InvalidType))));
}
};/*case end*/
}/*switch end*/
}()
));
jakt__path::Path const path = TRY((((TRY(((((TRY((((((((*this).program))->compiler))->get_file_path(((call_span).file_id))))).value())).parent())))).join(requested_path))));
types::Value const path_value = types::Value(TRY((types::ValueImpl::template create<typename types::ValueImpl::JaktString>(((path).to_string())))),call_span);
if ((!(((path).exists())))){
TRY((((*this).error(TRY((__jakt_format(Jakt::DeprecatedString("Prelude function `File::{}` could not find file at path {}"sv),prelude_function,((path).to_string())))),call_span))));
return Error::from_errno((infallible_integer_cast<i32>((interpreter::InterpretError::InvalidType))));
}
types::StructId const file_struct_id = TRY((((((*this).program))->find_struct_in_prelude(Jakt::DeprecatedString("File"sv)))));
types::CheckedStruct const file_struct = ((((*this).program))->get_struct(file_struct_id));
NonnullRefPtr<types::Scope> const scope = TRY((((((*this).program))->get_scope(((file_struct).scope_id)))));
JaktInternal::Optional<JaktInternal::DynamicArray<types::FunctionId>> const constructors = ((((scope)->functions)).get(Jakt::DeprecatedString("open_for_reading"sv)));
__jakt_var_160 =  interpreter::StatementResult { typename interpreter::StatementResult::JustValue(types::Value(TRY((types::ValueImpl::template create<typename types::ValueImpl::Struct>((TRY((DynamicArray<types::Value>::create_with({path_value})))),file_struct_id,(((constructors.value()))[static_cast<i64>(0LL)])))),call_span)) } ; goto __jakt_label_157;

}
__jakt_label_157:; __jakt_var_160.release_value(); }));
}
else if (__jakt_enum_value == Jakt::DeprecatedString("open_for_writing"sv)) {
return JaktInternal::ExplicitValue(({ Optional<interpreter::StatementResult> __jakt_var_161; {
DeprecatedString const requested_path = JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<DeprecatedString, ErrorOr<interpreter::StatementResult>>{
auto&& __jakt_match_variant = *((((arguments)[static_cast<i64>(0LL)])).impl);
switch(__jakt_match_variant.index()) {
case 13: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::JaktString>();
DeprecatedString const& x = __jakt_match_value.value;
return JaktInternal::ExplicitValue(x);
};/*case end*/
default: {
{
TRY((((*this).error(TRY((__jakt_format(Jakt::DeprecatedString("Prelude function `File::{}` expects a string as its first argument, but got {}"sv),prelude_function,((((arguments)[static_cast<i64>(0LL)])).impl)))),call_span))));
return Error::from_errno((infallible_integer_cast<i32>((interpreter::InterpretError::InvalidType))));
}
};/*case end*/
}/*switch end*/
}()
));
jakt__path::Path const path = TRY((((TRY(((((TRY((((((((*this).program))->compiler))->get_file_path(((call_span).file_id))))).value())).parent())))).join(requested_path))));
types::Value const path_value = types::Value(TRY((types::ValueImpl::template create<typename types::ValueImpl::JaktString>(((path).to_string())))),call_span);
if ((!(((path).exists())))){
TRY((((*this).error(TRY((__jakt_format(Jakt::DeprecatedString("Prelude function `File::{}` could not find file at path {}"sv),prelude_function,((path).to_string())))),call_span))));
return Error::from_errno((infallible_integer_cast<i32>((interpreter::InterpretError::InvalidType))));
}
types::StructId const file_struct_id = TRY((((((*this).program))->find_struct_in_prelude(Jakt::DeprecatedString("File"sv)))));
types::CheckedStruct const file_struct = ((((*this).program))->get_struct(file_struct_id));
NonnullRefPtr<types::Scope> const scope = TRY((((((*this).program))->get_scope(((file_struct).scope_id)))));
JaktInternal::Optional<JaktInternal::DynamicArray<types::FunctionId>> const constructor = ((((scope)->functions)).get(Jakt::DeprecatedString("open_for_writing"sv)));
__jakt_var_161 =  interpreter::StatementResult { typename interpreter::StatementResult::JustValue(types::Value(TRY((types::ValueImpl::template create<typename types::ValueImpl::Struct>((TRY((DynamicArray<types::Value>::create_with({path_value})))),file_struct_id,(((constructor.value()))[static_cast<i64>(0LL)])))),call_span)) } ; goto __jakt_label_158;

}
__jakt_label_158:; __jakt_var_161.release_value(); }));
}
else if (__jakt_enum_value == Jakt::DeprecatedString("read_all"sv)) {
return JaktInternal::ExplicitValue(({ Optional<interpreter::StatementResult> __jakt_var_162; {
DeprecatedString const path = JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<DeprecatedString, ErrorOr<interpreter::StatementResult>>{
auto&& __jakt_match_variant = *(((this_argument.value())).impl);
switch(__jakt_match_variant.index()) {
case 17: {
auto&& __jakt_match_value = __jakt_match_variant.template get<types::ValueImpl::Struct>();JaktInternal::DynamicArray<types::Value> const& fields = __jakt_match_value.fields;
return JaktInternal::ExplicitValue(JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<DeprecatedString, ErrorOr<interpreter::StatementResult>>{
auto&& __jakt_match_variant = *((((fields)[static_cast<i64>(0LL)])).impl);
switch(__jakt_match_variant.index()) {
case 13: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::JaktString>();
DeprecatedString const& x = __jakt_match_value.value;
return JaktInternal::ExplicitValue(x);
};/*case end*/
default: {
{
utility::panic(Jakt::DeprecatedString("invalid type for File::read_all"sv));
}
};/*case end*/
}/*switch end*/
}()
)));
};/*case end*/
default: {
{
TRY((((*this).error(TRY((__jakt_format(Jakt::DeprecatedString("Prelude function `File::read_all` expects a `File` as its this argument, but got {}"sv),(((this_argument.value())).impl)))),call_span))));
return Error::from_errno((infallible_integer_cast<i32>((interpreter::InterpretError::InvalidType))));
}
};/*case end*/
}/*switch end*/
}()
));
types::StructId const file_struct_id = TRY((((((*this).program))->find_struct_in_prelude(Jakt::DeprecatedString("File"sv)))));
types::CheckedStruct const file_struct = ((((*this).program))->get_struct(file_struct_id));
NonnullRefPtr<types::Scope> const scope = TRY((((((*this).program))->get_scope(((file_struct).scope_id)))));
types::FunctionId const open_for_reading = (((((((scope)->functions)).get(Jakt::DeprecatedString("open_for_reading"sv))).value()))[static_cast<i64>(0LL)]);
JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<void, ErrorOr<interpreter::StatementResult>>{
auto&& __jakt_match_variant = *(((this_argument.value())).impl);
switch(__jakt_match_variant.index()) {
case 17: {
auto&& __jakt_match_value = __jakt_match_variant.template get<types::ValueImpl::Struct>();JaktInternal::Optional<types::FunctionId> const& constructor = __jakt_match_value.constructor;
{
if (((!(((constructor).has_value()))) || (!((((constructor.value())).equals(open_for_reading)))))){
TRY((((*this).error(Jakt::DeprecatedString("Cannot read from a file not opened for reading"sv),call_span))));
return Error::from_errno((infallible_integer_cast<i32>((interpreter::InterpretError::InvalidType))));
}
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
default: {
{
utility::panic(Jakt::DeprecatedString("expected struct as this argument"sv));
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
}/*switch end*/
}()
));
NonnullRefPtr<File> file = TRY((File::open_for_reading(path)));
JaktInternal::DynamicArray<types::Value> result_values = (TRY((DynamicArray<types::Value>::create_with({}))));
{
JaktInternal::ArrayIterator<u8> _magic = ((TRY((((file)->read_all())))).iterator());
for (;;){
JaktInternal::Optional<u8> _magic_value = ((_magic).next());
if ((!(((_magic_value).has_value())))){
break;
}
u8 byte = (_magic_value.value());
{
TRY((((result_values).push(types::Value(TRY((types::ValueImpl::template create<typename types::ValueImpl::U8>(byte))),call_span)))));
}

}
}

types::StructId const array_struct_id = TRY((((((*this).program))->find_struct_in_prelude(Jakt::DeprecatedString("Array"sv)))));
__jakt_var_162 =  interpreter::StatementResult { typename interpreter::StatementResult::JustValue(types::Value(TRY((types::ValueImpl::template create<typename types::ValueImpl::JaktArray>(result_values,TRY((((*this).find_or_add_type_id(TRY((types::Type::template create<typename types::Type::GenericInstance>(array_struct_id,(TRY((DynamicArray<types::TypeId>::create_with({types::builtin( types::BuiltinType { typename types::BuiltinType::U8() } )})))))))))))))),call_span)) } ; goto __jakt_label_159;

}
__jakt_label_159:; __jakt_var_162.release_value(); }));
}
else if (__jakt_enum_value == Jakt::DeprecatedString("read"sv)) {
return JaktInternal::ExplicitValue(({ Optional<interpreter::StatementResult> __jakt_var_163; {
DeprecatedString const path = JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<DeprecatedString, ErrorOr<interpreter::StatementResult>>{
auto&& __jakt_match_variant = *(((this_argument.value())).impl);
switch(__jakt_match_variant.index()) {
case 17: {
auto&& __jakt_match_value = __jakt_match_variant.template get<types::ValueImpl::Struct>();JaktInternal::DynamicArray<types::Value> const& fields = __jakt_match_value.fields;
return JaktInternal::ExplicitValue(JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<DeprecatedString, ErrorOr<interpreter::StatementResult>>{
auto&& __jakt_match_variant = *((((fields)[static_cast<i64>(0LL)])).impl);
switch(__jakt_match_variant.index()) {
case 13: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::JaktString>();
DeprecatedString const& x = __jakt_match_value.value;
return JaktInternal::ExplicitValue(x);
};/*case end*/
default: {
{
utility::panic(Jakt::DeprecatedString("invalid type for File::read"sv));
}
};/*case end*/
}/*switch end*/
}()
)));
};/*case end*/
default: {
{
TRY((((*this).error(TRY((__jakt_format(Jakt::DeprecatedString("Prelude function `File::read` expects a `File` as its this argument, but got {}"sv),(((this_argument.value())).impl)))),call_span))));
return Error::from_errno((infallible_integer_cast<i32>((interpreter::InterpretError::InvalidType))));
}
};/*case end*/
}/*switch end*/
}()
));
types::StructId const file_struct_id = TRY((((((*this).program))->find_struct_in_prelude(Jakt::DeprecatedString("File"sv)))));
types::CheckedStruct const file_struct = ((((*this).program))->get_struct(file_struct_id));
NonnullRefPtr<types::Scope> const scope = TRY((((((*this).program))->get_scope(((file_struct).scope_id)))));
types::FunctionId const open_for_reading = (((((((scope)->functions)).get(Jakt::DeprecatedString("open_for_reading"sv))).value()))[static_cast<i64>(0LL)]);
JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<void, ErrorOr<interpreter::StatementResult>>{
auto&& __jakt_match_variant = *(((this_argument.value())).impl);
switch(__jakt_match_variant.index()) {
case 17: {
auto&& __jakt_match_value = __jakt_match_variant.template get<types::ValueImpl::Struct>();JaktInternal::Optional<types::FunctionId> const& constructor = __jakt_match_value.constructor;
{
if (((!(((constructor).has_value()))) || (!((((constructor.value())).equals(open_for_reading)))))){
TRY((((*this).error(Jakt::DeprecatedString("Cannot read from a file not opened for reading"sv),call_span))));
return Error::from_errno((infallible_integer_cast<i32>((interpreter::InterpretError::InvalidType))));
}
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
default: {
{
utility::panic(Jakt::DeprecatedString("expected struct as this argument"sv));
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
}/*switch end*/
}()
));
NonnullRefPtr<File> file = TRY((File::open_for_reading(path)));
JaktInternal::DynamicArray<types::Value> values_buffer = JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<JaktInternal::DynamicArray<types::Value>, ErrorOr<interpreter::StatementResult>>{
auto&& __jakt_match_variant = *((((arguments)[static_cast<i64>(0LL)])).impl);
switch(__jakt_match_variant.index()) {
case 20: {
auto&& __jakt_match_value = __jakt_match_variant.template get<types::ValueImpl::JaktArray>();JaktInternal::DynamicArray<types::Value> const& values = __jakt_match_value.values;
return JaktInternal::ExplicitValue(values);
};/*case end*/
default: {
{
TRY((((*this).error(TRY((__jakt_format(Jakt::DeprecatedString("Prelude function `File::read` expects a `[u8]` as its argument, but got {}"sv),((((arguments)[static_cast<i64>(0LL)])).impl)))),call_span))));
return Error::from_errno((infallible_integer_cast<i32>((interpreter::InterpretError::InvalidType))));
}
};/*case end*/
}/*switch end*/
}()
));
JaktInternal::DynamicArray<u8> byte_buffer = (TRY((DynamicArray<u8>::filled(((values_buffer).size()), static_cast<u8>(0)))));
size_t const bytes_read = TRY((((file)->read(byte_buffer))));
{
JaktInternal::Range<size_t> _magic = (JaktInternal::Range<size_t>{static_cast<size_t>(static_cast<size_t>(0ULL)),static_cast<size_t>(((byte_buffer).size()))});
for (;;){
JaktInternal::Optional<size_t> _magic_value = ((_magic).next());
if ((!(((_magic_value).has_value())))){
break;
}
size_t i = (_magic_value.value());
{
(((values_buffer)[i]) = types::Value(TRY((types::ValueImpl::template create<typename types::ValueImpl::U8>(((byte_buffer)[i])))),call_span));
}

}
}

__jakt_var_163 =  interpreter::StatementResult { typename interpreter::StatementResult::JustValue(types::Value(TRY((types::ValueImpl::template create<typename types::ValueImpl::USize>(bytes_read))),call_span)) } ; goto __jakt_label_160;

}
__jakt_label_160:; __jakt_var_163.release_value(); }));
}
else if (__jakt_enum_value == Jakt::DeprecatedString("exists"sv)) {
return JaktInternal::ExplicitValue(({ Optional<interpreter::StatementResult> __jakt_var_164; {
DeprecatedString const requested_path = JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<DeprecatedString, ErrorOr<interpreter::StatementResult>>{
auto&& __jakt_match_variant = *((((arguments)[static_cast<i64>(0LL)])).impl);
switch(__jakt_match_variant.index()) {
case 13: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::JaktString>();
DeprecatedString const& x = __jakt_match_value.value;
return JaktInternal::ExplicitValue(x);
};/*case end*/
default: {
{
TRY((((*this).error(TRY((__jakt_format(Jakt::DeprecatedString("Prelude function `File::{}` expects a string as its first argument, but got {}"sv),prelude_function,((((arguments)[static_cast<i64>(0LL)])).impl)))),call_span))));
return Error::from_errno((infallible_integer_cast<i32>((interpreter::InterpretError::InvalidType))));
}
};/*case end*/
}/*switch end*/
}()
));
jakt__path::Path const path = TRY((((TRY(((((TRY((((((((*this).program))->compiler))->get_file_path(((call_span).file_id))))).value())).parent())))).join(requested_path))));
__jakt_var_164 =  interpreter::StatementResult { typename interpreter::StatementResult::JustValue(types::Value(TRY((types::ValueImpl::template create<typename types::ValueImpl::Bool>(((path).exists())))),call_span)) } ; goto __jakt_label_161;

}
__jakt_label_161:; __jakt_var_164.release_value(); }));
}
else if (__jakt_enum_value == Jakt::DeprecatedString("write"sv)) {
return JaktInternal::ExplicitValue(({ Optional<interpreter::StatementResult> __jakt_var_165; {
DeprecatedString const path = JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<DeprecatedString, ErrorOr<interpreter::StatementResult>>{
auto&& __jakt_match_variant = *(((this_argument.value())).impl);
switch(__jakt_match_variant.index()) {
case 17: {
auto&& __jakt_match_value = __jakt_match_variant.template get<types::ValueImpl::Struct>();JaktInternal::DynamicArray<types::Value> const& fields = __jakt_match_value.fields;
return JaktInternal::ExplicitValue(JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<DeprecatedString, ErrorOr<interpreter::StatementResult>>{
auto&& __jakt_match_variant = *((((fields)[static_cast<i64>(0LL)])).impl);
switch(__jakt_match_variant.index()) {
case 13: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::JaktString>();
DeprecatedString const& x = __jakt_match_value.value;
return JaktInternal::ExplicitValue(x);
};/*case end*/
default: {
{
utility::panic(Jakt::DeprecatedString("invalid type for File::write"sv));
}
};/*case end*/
}/*switch end*/
}()
)));
};/*case end*/
default: {
{
TRY((((*this).error(TRY((__jakt_format(Jakt::DeprecatedString("Prelude function `File::write` expects a `File` as its this argument, but got {}"sv),(((this_argument.value())).impl)))),call_span))));
return Error::from_errno((infallible_integer_cast<i32>((interpreter::InterpretError::InvalidType))));
}
};/*case end*/
}/*switch end*/
}()
));
types::StructId const file_struct_id = TRY((((((*this).program))->find_struct_in_prelude(Jakt::DeprecatedString("File"sv)))));
types::CheckedStruct const file_struct = ((((*this).program))->get_struct(file_struct_id));
NonnullRefPtr<types::Scope> const scope = TRY((((((*this).program))->get_scope(((file_struct).scope_id)))));
types::FunctionId const open_for_writing = (((((((scope)->functions)).get(Jakt::DeprecatedString("open_for_writing"sv))).value()))[static_cast<i64>(0LL)]);
JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<void, ErrorOr<interpreter::StatementResult>>{
auto&& __jakt_match_variant = *(((this_argument.value())).impl);
switch(__jakt_match_variant.index()) {
case 17: {
auto&& __jakt_match_value = __jakt_match_variant.template get<types::ValueImpl::Struct>();JaktInternal::Optional<types::FunctionId> const& constructor = __jakt_match_value.constructor;
{
if (((!(((constructor).has_value()))) || (!((((constructor.value())).equals(open_for_writing)))))){
TRY((((*this).error(Jakt::DeprecatedString("Cannot write to a file not opened for writing"sv),call_span))));
return Error::from_errno((infallible_integer_cast<i32>((interpreter::InterpretError::InvalidType))));
}
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
default: {
{
utility::panic(Jakt::DeprecatedString("expected struct as this argument"sv));
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
}/*switch end*/
}()
));
NonnullRefPtr<File> file = TRY((File::open_for_writing(path)));
JaktInternal::DynamicArray<types::Value> data_values = JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<JaktInternal::DynamicArray<types::Value>, ErrorOr<interpreter::StatementResult>>{
auto&& __jakt_match_variant = *((((arguments)[static_cast<i64>(0LL)])).impl);
switch(__jakt_match_variant.index()) {
case 20: {
auto&& __jakt_match_value = __jakt_match_variant.template get<types::ValueImpl::JaktArray>();JaktInternal::DynamicArray<types::Value> const& values = __jakt_match_value.values;
return JaktInternal::ExplicitValue(values);
};/*case end*/
default: {
{
TRY((((*this).error(TRY((__jakt_format(Jakt::DeprecatedString("Prelude function `File::write` expects a `[u8]` as its argument, but got {}"sv),((((arguments)[static_cast<i64>(0LL)])).impl)))),call_span))));
return Error::from_errno((infallible_integer_cast<i32>((interpreter::InterpretError::InvalidType))));
}
};/*case end*/
}/*switch end*/
}()
));
JaktInternal::DynamicArray<u8> data = (TRY((DynamicArray<u8>::create_with({}))));
{
JaktInternal::ArrayIterator<types::Value> _magic = ((data_values).iterator());
for (;;){
JaktInternal::Optional<types::Value> _magic_value = ((_magic).next());
if ((!(((_magic_value).has_value())))){
break;
}
types::Value val = (_magic_value.value());
{
TRY((((data).push(JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_AT_LOOP(([&]() -> JaktInternal::ExplicitValueOrControlFlow<u8, ErrorOr<interpreter::StatementResult>>{
auto&& __jakt_match_variant = *((val).impl);
switch(__jakt_match_variant.index()) {
case 2: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::U8>();
u8 const& x = __jakt_match_value.value;
return JaktInternal::ExplicitValue(x);
};/*case end*/
default: {
{
utility::panic(Jakt::DeprecatedString("expected byte"sv));
}
};/*case end*/
}/*switch end*/
}()
))))));
}

}
}

size_t const bytes_written = TRY((((file)->write(data))));
__jakt_var_165 =  interpreter::StatementResult { typename interpreter::StatementResult::JustValue(types::Value(TRY((types::ValueImpl::template create<typename types::ValueImpl::USize>(bytes_written))),call_span)) } ; goto __jakt_label_162;

}
__jakt_label_162:; __jakt_var_165.release_value(); }));
}
else {
{
TRY((((*this).error(TRY((__jakt_format(Jakt::DeprecatedString("Prelude function `File::{}` is not implemented"sv),prelude_function))),call_span))));
return Error::from_errno((infallible_integer_cast<i32>((interpreter::InterpretError::Unimplemented))));
}
}
}()))
);
}
else if (__jakt_enum_value == Jakt::DeprecatedString("StringBuilder"sv)) {
return JaktInternal::ExplicitValue(JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<interpreter::StatementResult,ErrorOr<interpreter::StatementResult>>{
auto __jakt_enum_value = (prelude_function);
if (__jakt_enum_value == Jakt::DeprecatedString("create"sv)) {
return JaktInternal::ExplicitValue(({ Optional<interpreter::StatementResult> __jakt_var_166; {
types::StructId const string_builder_struct_id = TRY((((((*this).program))->find_struct_in_prelude(Jakt::DeprecatedString("StringBuilder"sv)))));
__jakt_var_166 =  interpreter::StatementResult { typename interpreter::StatementResult::JustValue(types::Value(TRY((types::ValueImpl::template create<typename types::ValueImpl::Struct>((TRY((DynamicArray<types::Value>::create_with({types::Value(TRY((types::ValueImpl::template create<typename types::ValueImpl::JaktString>(Jakt::DeprecatedString(""sv)))),call_span)})))),string_builder_struct_id,JaktInternal::OptionalNone()))),call_span)) } ; goto __jakt_label_163;

}
__jakt_label_163:; __jakt_var_166.release_value(); }));
}
else if (__jakt_enum_value == Jakt::DeprecatedString("append"sv)) {
return JaktInternal::ExplicitValue(({ Optional<interpreter::StatementResult> __jakt_var_167; {
JaktInternal::Tuple<JaktInternal::DynamicArray<types::Value>,DeprecatedString> fields_current_string_ = JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<JaktInternal::Tuple<JaktInternal::DynamicArray<types::Value>,DeprecatedString>, ErrorOr<interpreter::StatementResult>>{
auto&& __jakt_match_variant = *(((this_argument.value())).impl);
switch(__jakt_match_variant.index()) {
case 17: {
auto&& __jakt_match_value = __jakt_match_variant.template get<types::ValueImpl::Struct>();JaktInternal::DynamicArray<types::Value> const& fields = __jakt_match_value.fields;
return JaktInternal::ExplicitValue(JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<JaktInternal::Tuple<JaktInternal::DynamicArray<types::Value>,DeprecatedString>, ErrorOr<interpreter::StatementResult>>{
auto&& __jakt_match_variant = *((((fields)[static_cast<i64>(0LL)])).impl);
switch(__jakt_match_variant.index()) {
case 13: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::JaktString>();
DeprecatedString const& value = __jakt_match_value.value;
return JaktInternal::ExplicitValue((Tuple{fields, value}));
};/*case end*/
default: {
{
utility::panic(Jakt::DeprecatedString("Invalid use of prelude StringBuilder"sv));
}
};/*case end*/
}/*switch end*/
}()
)));
};/*case end*/
default: {
{
TRY((((*this).error(TRY((__jakt_format(Jakt::DeprecatedString("Prelude function `StringBuilder::{}` expects a StringBuilder as its this argument"sv),prelude_function))),call_span))));
return Error::from_errno((infallible_integer_cast<i32>((interpreter::InterpretError::Unimplemented))));
}
};/*case end*/
}/*switch end*/
}()
));
JaktInternal::DynamicArray<types::Value> fields = ((fields_current_string_).template get<0>());
DeprecatedString current_string = ((fields_current_string_).template get<1>());

DeprecatedStringBuilder builder = TRY((DeprecatedStringBuilder::create()));
TRY((((builder).append_string(current_string))));
JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<void,ErrorOr<interpreter::StatementResult>>{
auto __jakt_enum_value = (prelude_function);
if (__jakt_enum_value == Jakt::DeprecatedString("append"sv)) {
return (TRY((((builder).append(JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<u8, ErrorOr<interpreter::StatementResult>>{
auto&& __jakt_match_variant = *((((arguments)[static_cast<i64>(0LL)])).impl);
switch(__jakt_match_variant.index()) {
case 2: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::U8>();
u8 const& value = __jakt_match_value.value;
return JaktInternal::ExplicitValue(value);
};/*case end*/
default: {
{
TRY((((*this).error(TRY((__jakt_format(Jakt::DeprecatedString("Invalid use of StringBuilder::append({})"sv),((((arguments)[static_cast<i64>(0LL)])).impl)))),call_span))));
return Error::from_errno((infallible_integer_cast<i32>((interpreter::InterpretError::InvalidType))));
}
};/*case end*/
}/*switch end*/
}()
))))))), JaktInternal::ExplicitValue<void>();
}
else if (__jakt_enum_value == Jakt::DeprecatedString("append_string"sv)) {
return (TRY((((builder).append_string(JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<DeprecatedString, ErrorOr<interpreter::StatementResult>>{
auto&& __jakt_match_variant = *((((arguments)[static_cast<i64>(0LL)])).impl);
switch(__jakt_match_variant.index()) {
case 13: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::JaktString>();
DeprecatedString const& value = __jakt_match_value.value;
return JaktInternal::ExplicitValue(value);
};/*case end*/
default: {
{
TRY((((*this).error(Jakt::DeprecatedString("Invalid use of StringBuilder::append_string()"sv),call_span))));
return Error::from_errno((infallible_integer_cast<i32>((interpreter::InterpretError::InvalidType))));
}
};/*case end*/
}/*switch end*/
}()
))))))), JaktInternal::ExplicitValue<void>();
}
else if (__jakt_enum_value == Jakt::DeprecatedString("append_escaped_for_json"sv)) {
return (TRY((((builder).append_escaped_for_json(JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<DeprecatedString, ErrorOr<interpreter::StatementResult>>{
auto&& __jakt_match_variant = *((((arguments)[static_cast<i64>(0LL)])).impl);
switch(__jakt_match_variant.index()) {
case 13: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::JaktString>();
DeprecatedString const& value = __jakt_match_value.value;
return JaktInternal::ExplicitValue(value);
};/*case end*/
default: {
{
TRY((((*this).error(Jakt::DeprecatedString("Invalid use of StringBuilder::append_escaped_for_json()"sv),call_span))));
return Error::from_errno((infallible_integer_cast<i32>((interpreter::InterpretError::InvalidType))));
}
};/*case end*/
}/*switch end*/
}()
))))))), JaktInternal::ExplicitValue<void>();
}
else if (__jakt_enum_value == Jakt::DeprecatedString("append_code_point"sv)) {
return (TRY((((builder).append_code_point(JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<u32, ErrorOr<interpreter::StatementResult>>{
auto&& __jakt_match_variant = *((((arguments)[static_cast<i64>(0LL)])).impl);
switch(__jakt_match_variant.index()) {
case 4: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::U32>();
u32 const& value = __jakt_match_value.value;
return JaktInternal::ExplicitValue(value);
};/*case end*/
default: {
{
TRY((((*this).error(Jakt::DeprecatedString("Invalid use of StringBuilder::append_code_point()"sv),call_span))));
return Error::from_errno((infallible_integer_cast<i32>((interpreter::InterpretError::InvalidType))));
}
};/*case end*/
}/*switch end*/
}()
))))))), JaktInternal::ExplicitValue<void>();
}
else {
{
abort();
}
return JaktInternal::ExplicitValue<void>();
}
return JaktInternal::ExplicitValue<void>();
}()))
;
(((fields)[static_cast<i64>(0LL)]) = types::Value(TRY((types::ValueImpl::template create<typename types::ValueImpl::JaktString>(TRY((((builder).to_string())))))),call_span));
__jakt_var_167 =  interpreter::StatementResult { typename interpreter::StatementResult::JustValue(types::Value(TRY((types::ValueImpl::template create<typename types::ValueImpl::Void>())),call_span)) } ; goto __jakt_label_164;

}
__jakt_label_164:; __jakt_var_167.release_value(); }));
}
else if (__jakt_enum_value == Jakt::DeprecatedString("append_string"sv)) {
return JaktInternal::ExplicitValue(({ Optional<interpreter::StatementResult> __jakt_var_168; {
JaktInternal::Tuple<JaktInternal::DynamicArray<types::Value>,DeprecatedString> fields_current_string_ = JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<JaktInternal::Tuple<JaktInternal::DynamicArray<types::Value>,DeprecatedString>, ErrorOr<interpreter::StatementResult>>{
auto&& __jakt_match_variant = *(((this_argument.value())).impl);
switch(__jakt_match_variant.index()) {
case 17: {
auto&& __jakt_match_value = __jakt_match_variant.template get<types::ValueImpl::Struct>();JaktInternal::DynamicArray<types::Value> const& fields = __jakt_match_value.fields;
return JaktInternal::ExplicitValue(JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<JaktInternal::Tuple<JaktInternal::DynamicArray<types::Value>,DeprecatedString>, ErrorOr<interpreter::StatementResult>>{
auto&& __jakt_match_variant = *((((fields)[static_cast<i64>(0LL)])).impl);
switch(__jakt_match_variant.index()) {
case 13: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::JaktString>();
DeprecatedString const& value = __jakt_match_value.value;
return JaktInternal::ExplicitValue((Tuple{fields, value}));
};/*case end*/
default: {
{
utility::panic(Jakt::DeprecatedString("Invalid use of prelude StringBuilder"sv));
}
};/*case end*/
}/*switch end*/
}()
)));
};/*case end*/
default: {
{
TRY((((*this).error(TRY((__jakt_format(Jakt::DeprecatedString("Prelude function `StringBuilder::{}` expects a StringBuilder as its this argument"sv),prelude_function))),call_span))));
return Error::from_errno((infallible_integer_cast<i32>((interpreter::InterpretError::Unimplemented))));
}
};/*case end*/
}/*switch end*/
}()
));
JaktInternal::DynamicArray<types::Value> fields = ((fields_current_string_).template get<0>());
DeprecatedString current_string = ((fields_current_string_).template get<1>());

DeprecatedStringBuilder builder = TRY((DeprecatedStringBuilder::create()));
TRY((((builder).append_string(current_string))));
JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<void,ErrorOr<interpreter::StatementResult>>{
auto __jakt_enum_value = (prelude_function);
if (__jakt_enum_value == Jakt::DeprecatedString("append"sv)) {
return (TRY((((builder).append(JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<u8, ErrorOr<interpreter::StatementResult>>{
auto&& __jakt_match_variant = *((((arguments)[static_cast<i64>(0LL)])).impl);
switch(__jakt_match_variant.index()) {
case 2: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::U8>();
u8 const& value = __jakt_match_value.value;
return JaktInternal::ExplicitValue(value);
};/*case end*/
default: {
{
TRY((((*this).error(TRY((__jakt_format(Jakt::DeprecatedString("Invalid use of StringBuilder::append({})"sv),((((arguments)[static_cast<i64>(0LL)])).impl)))),call_span))));
return Error::from_errno((infallible_integer_cast<i32>((interpreter::InterpretError::InvalidType))));
}
};/*case end*/
}/*switch end*/
}()
))))))), JaktInternal::ExplicitValue<void>();
}
else if (__jakt_enum_value == Jakt::DeprecatedString("append_string"sv)) {
return (TRY((((builder).append_string(JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<DeprecatedString, ErrorOr<interpreter::StatementResult>>{
auto&& __jakt_match_variant = *((((arguments)[static_cast<i64>(0LL)])).impl);
switch(__jakt_match_variant.index()) {
case 13: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::JaktString>();
DeprecatedString const& value = __jakt_match_value.value;
return JaktInternal::ExplicitValue(value);
};/*case end*/
default: {
{
TRY((((*this).error(Jakt::DeprecatedString("Invalid use of StringBuilder::append_string()"sv),call_span))));
return Error::from_errno((infallible_integer_cast<i32>((interpreter::InterpretError::InvalidType))));
}
};/*case end*/
}/*switch end*/
}()
))))))), JaktInternal::ExplicitValue<void>();
}
else if (__jakt_enum_value == Jakt::DeprecatedString("append_escaped_for_json"sv)) {
return (TRY((((builder).append_escaped_for_json(JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<DeprecatedString, ErrorOr<interpreter::StatementResult>>{
auto&& __jakt_match_variant = *((((arguments)[static_cast<i64>(0LL)])).impl);
switch(__jakt_match_variant.index()) {
case 13: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::JaktString>();
DeprecatedString const& value = __jakt_match_value.value;
return JaktInternal::ExplicitValue(value);
};/*case end*/
default: {
{
TRY((((*this).error(Jakt::DeprecatedString("Invalid use of StringBuilder::append_escaped_for_json()"sv),call_span))));
return Error::from_errno((infallible_integer_cast<i32>((interpreter::InterpretError::InvalidType))));
}
};/*case end*/
}/*switch end*/
}()
))))))), JaktInternal::ExplicitValue<void>();
}
else if (__jakt_enum_value == Jakt::DeprecatedString("append_code_point"sv)) {
return (TRY((((builder).append_code_point(JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<u32, ErrorOr<interpreter::StatementResult>>{
auto&& __jakt_match_variant = *((((arguments)[static_cast<i64>(0LL)])).impl);
switch(__jakt_match_variant.index()) {
case 4: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::U32>();
u32 const& value = __jakt_match_value.value;
return JaktInternal::ExplicitValue(value);
};/*case end*/
default: {
{
TRY((((*this).error(Jakt::DeprecatedString("Invalid use of StringBuilder::append_code_point()"sv),call_span))));
return Error::from_errno((infallible_integer_cast<i32>((interpreter::InterpretError::InvalidType))));
}
};/*case end*/
}/*switch end*/
}()
))))))), JaktInternal::ExplicitValue<void>();
}
else {
{
abort();
}
return JaktInternal::ExplicitValue<void>();
}
return JaktInternal::ExplicitValue<void>();
}()))
;
(((fields)[static_cast<i64>(0LL)]) = types::Value(TRY((types::ValueImpl::template create<typename types::ValueImpl::JaktString>(TRY((((builder).to_string())))))),call_span));
__jakt_var_168 =  interpreter::StatementResult { typename interpreter::StatementResult::JustValue(types::Value(TRY((types::ValueImpl::template create<typename types::ValueImpl::Void>())),call_span)) } ; goto __jakt_label_165;

}
__jakt_label_165:; __jakt_var_168.release_value(); }));
}
else if (__jakt_enum_value == Jakt::DeprecatedString("append_code_point"sv)) {
return JaktInternal::ExplicitValue(({ Optional<interpreter::StatementResult> __jakt_var_169; {
JaktInternal::Tuple<JaktInternal::DynamicArray<types::Value>,DeprecatedString> fields_current_string_ = JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<JaktInternal::Tuple<JaktInternal::DynamicArray<types::Value>,DeprecatedString>, ErrorOr<interpreter::StatementResult>>{
auto&& __jakt_match_variant = *(((this_argument.value())).impl);
switch(__jakt_match_variant.index()) {
case 17: {
auto&& __jakt_match_value = __jakt_match_variant.template get<types::ValueImpl::Struct>();JaktInternal::DynamicArray<types::Value> const& fields = __jakt_match_value.fields;
return JaktInternal::ExplicitValue(JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<JaktInternal::Tuple<JaktInternal::DynamicArray<types::Value>,DeprecatedString>, ErrorOr<interpreter::StatementResult>>{
auto&& __jakt_match_variant = *((((fields)[static_cast<i64>(0LL)])).impl);
switch(__jakt_match_variant.index()) {
case 13: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::JaktString>();
DeprecatedString const& value = __jakt_match_value.value;
return JaktInternal::ExplicitValue((Tuple{fields, value}));
};/*case end*/
default: {
{
utility::panic(Jakt::DeprecatedString("Invalid use of prelude StringBuilder"sv));
}
};/*case end*/
}/*switch end*/
}()
)));
};/*case end*/
default: {
{
TRY((((*this).error(TRY((__jakt_format(Jakt::DeprecatedString("Prelude function `StringBuilder::{}` expects a StringBuilder as its this argument"sv),prelude_function))),call_span))));
return Error::from_errno((infallible_integer_cast<i32>((interpreter::InterpretError::Unimplemented))));
}
};/*case end*/
}/*switch end*/
}()
));
JaktInternal::DynamicArray<types::Value> fields = ((fields_current_string_).template get<0>());
DeprecatedString current_string = ((fields_current_string_).template get<1>());

DeprecatedStringBuilder builder = TRY((DeprecatedStringBuilder::create()));
TRY((((builder).append_string(current_string))));
JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<void,ErrorOr<interpreter::StatementResult>>{
auto __jakt_enum_value = (prelude_function);
if (__jakt_enum_value == Jakt::DeprecatedString("append"sv)) {
return (TRY((((builder).append(JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<u8, ErrorOr<interpreter::StatementResult>>{
auto&& __jakt_match_variant = *((((arguments)[static_cast<i64>(0LL)])).impl);
switch(__jakt_match_variant.index()) {
case 2: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::U8>();
u8 const& value = __jakt_match_value.value;
return JaktInternal::ExplicitValue(value);
};/*case end*/
default: {
{
TRY((((*this).error(TRY((__jakt_format(Jakt::DeprecatedString("Invalid use of StringBuilder::append({})"sv),((((arguments)[static_cast<i64>(0LL)])).impl)))),call_span))));
return Error::from_errno((infallible_integer_cast<i32>((interpreter::InterpretError::InvalidType))));
}
};/*case end*/
}/*switch end*/
}()
))))))), JaktInternal::ExplicitValue<void>();
}
else if (__jakt_enum_value == Jakt::DeprecatedString("append_string"sv)) {
return (TRY((((builder).append_string(JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<DeprecatedString, ErrorOr<interpreter::StatementResult>>{
auto&& __jakt_match_variant = *((((arguments)[static_cast<i64>(0LL)])).impl);
switch(__jakt_match_variant.index()) {
case 13: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::JaktString>();
DeprecatedString const& value = __jakt_match_value.value;
return JaktInternal::ExplicitValue(value);
};/*case end*/
default: {
{
TRY((((*this).error(Jakt::DeprecatedString("Invalid use of StringBuilder::append_string()"sv),call_span))));
return Error::from_errno((infallible_integer_cast<i32>((interpreter::InterpretError::InvalidType))));
}
};/*case end*/
}/*switch end*/
}()
))))))), JaktInternal::ExplicitValue<void>();
}
else if (__jakt_enum_value == Jakt::DeprecatedString("append_escaped_for_json"sv)) {
return (TRY((((builder).append_escaped_for_json(JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<DeprecatedString, ErrorOr<interpreter::StatementResult>>{
auto&& __jakt_match_variant = *((((arguments)[static_cast<i64>(0LL)])).impl);
switch(__jakt_match_variant.index()) {
case 13: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::JaktString>();
DeprecatedString const& value = __jakt_match_value.value;
return JaktInternal::ExplicitValue(value);
};/*case end*/
default: {
{
TRY((((*this).error(Jakt::DeprecatedString("Invalid use of StringBuilder::append_escaped_for_json()"sv),call_span))));
return Error::from_errno((infallible_integer_cast<i32>((interpreter::InterpretError::InvalidType))));
}
};/*case end*/
}/*switch end*/
}()
))))))), JaktInternal::ExplicitValue<void>();
}
else if (__jakt_enum_value == Jakt::DeprecatedString("append_code_point"sv)) {
return (TRY((((builder).append_code_point(JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<u32, ErrorOr<interpreter::StatementResult>>{
auto&& __jakt_match_variant = *((((arguments)[static_cast<i64>(0LL)])).impl);
switch(__jakt_match_variant.index()) {
case 4: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::U32>();
u32 const& value = __jakt_match_value.value;
return JaktInternal::ExplicitValue(value);
};/*case end*/
default: {
{
TRY((((*this).error(Jakt::DeprecatedString("Invalid use of StringBuilder::append_code_point()"sv),call_span))));
return Error::from_errno((infallible_integer_cast<i32>((interpreter::InterpretError::InvalidType))));
}
};/*case end*/
}/*switch end*/
}()
))))))), JaktInternal::ExplicitValue<void>();
}
else {
{
abort();
}
return JaktInternal::ExplicitValue<void>();
}
return JaktInternal::ExplicitValue<void>();
}()))
;
(((fields)[static_cast<i64>(0LL)]) = types::Value(TRY((types::ValueImpl::template create<typename types::ValueImpl::JaktString>(TRY((((builder).to_string())))))),call_span));
__jakt_var_169 =  interpreter::StatementResult { typename interpreter::StatementResult::JustValue(types::Value(TRY((types::ValueImpl::template create<typename types::ValueImpl::Void>())),call_span)) } ; goto __jakt_label_166;

}
__jakt_label_166:; __jakt_var_169.release_value(); }));
}
else if (__jakt_enum_value == Jakt::DeprecatedString("append_escaped_for_json"sv)) {
return JaktInternal::ExplicitValue(({ Optional<interpreter::StatementResult> __jakt_var_170; {
JaktInternal::Tuple<JaktInternal::DynamicArray<types::Value>,DeprecatedString> fields_current_string_ = JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<JaktInternal::Tuple<JaktInternal::DynamicArray<types::Value>,DeprecatedString>, ErrorOr<interpreter::StatementResult>>{
auto&& __jakt_match_variant = *(((this_argument.value())).impl);
switch(__jakt_match_variant.index()) {
case 17: {
auto&& __jakt_match_value = __jakt_match_variant.template get<types::ValueImpl::Struct>();JaktInternal::DynamicArray<types::Value> const& fields = __jakt_match_value.fields;
return JaktInternal::ExplicitValue(JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<JaktInternal::Tuple<JaktInternal::DynamicArray<types::Value>,DeprecatedString>, ErrorOr<interpreter::StatementResult>>{
auto&& __jakt_match_variant = *((((fields)[static_cast<i64>(0LL)])).impl);
switch(__jakt_match_variant.index()) {
case 13: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::JaktString>();
DeprecatedString const& value = __jakt_match_value.value;
return JaktInternal::ExplicitValue((Tuple{fields, value}));
};/*case end*/
default: {
{
utility::panic(Jakt::DeprecatedString("Invalid use of prelude StringBuilder"sv));
}
};/*case end*/
}/*switch end*/
}()
)));
};/*case end*/
default: {
{
TRY((((*this).error(TRY((__jakt_format(Jakt::DeprecatedString("Prelude function `StringBuilder::{}` expects a StringBuilder as its this argument"sv),prelude_function))),call_span))));
return Error::from_errno((infallible_integer_cast<i32>((interpreter::InterpretError::Unimplemented))));
}
};/*case end*/
}/*switch end*/
}()
));
JaktInternal::DynamicArray<types::Value> fields = ((fields_current_string_).template get<0>());
DeprecatedString current_string = ((fields_current_string_).template get<1>());

DeprecatedStringBuilder builder = TRY((DeprecatedStringBuilder::create()));
TRY((((builder).append_string(current_string))));
JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<void,ErrorOr<interpreter::StatementResult>>{
auto __jakt_enum_value = (prelude_function);
if (__jakt_enum_value == Jakt::DeprecatedString("append"sv)) {
return (TRY((((builder).append(JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<u8, ErrorOr<interpreter::StatementResult>>{
auto&& __jakt_match_variant = *((((arguments)[static_cast<i64>(0LL)])).impl);
switch(__jakt_match_variant.index()) {
case 2: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::U8>();
u8 const& value = __jakt_match_value.value;
return JaktInternal::ExplicitValue(value);
};/*case end*/
default: {
{
TRY((((*this).error(TRY((__jakt_format(Jakt::DeprecatedString("Invalid use of StringBuilder::append({})"sv),((((arguments)[static_cast<i64>(0LL)])).impl)))),call_span))));
return Error::from_errno((infallible_integer_cast<i32>((interpreter::InterpretError::InvalidType))));
}
};/*case end*/
}/*switch end*/
}()
))))))), JaktInternal::ExplicitValue<void>();
}
else if (__jakt_enum_value == Jakt::DeprecatedString("append_string"sv)) {
return (TRY((((builder).append_string(JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<DeprecatedString, ErrorOr<interpreter::StatementResult>>{
auto&& __jakt_match_variant = *((((arguments)[static_cast<i64>(0LL)])).impl);
switch(__jakt_match_variant.index()) {
case 13: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::JaktString>();
DeprecatedString const& value = __jakt_match_value.value;
return JaktInternal::ExplicitValue(value);
};/*case end*/
default: {
{
TRY((((*this).error(Jakt::DeprecatedString("Invalid use of StringBuilder::append_string()"sv),call_span))));
return Error::from_errno((infallible_integer_cast<i32>((interpreter::InterpretError::InvalidType))));
}
};/*case end*/
}/*switch end*/
}()
))))))), JaktInternal::ExplicitValue<void>();
}
else if (__jakt_enum_value == Jakt::DeprecatedString("append_escaped_for_json"sv)) {
return (TRY((((builder).append_escaped_for_json(JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<DeprecatedString, ErrorOr<interpreter::StatementResult>>{
auto&& __jakt_match_variant = *((((arguments)[static_cast<i64>(0LL)])).impl);
switch(__jakt_match_variant.index()) {
case 13: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::JaktString>();
DeprecatedString const& value = __jakt_match_value.value;
return JaktInternal::ExplicitValue(value);
};/*case end*/
default: {
{
TRY((((*this).error(Jakt::DeprecatedString("Invalid use of StringBuilder::append_escaped_for_json()"sv),call_span))));
return Error::from_errno((infallible_integer_cast<i32>((interpreter::InterpretError::InvalidType))));
}
};/*case end*/
}/*switch end*/
}()
))))))), JaktInternal::ExplicitValue<void>();
}
else if (__jakt_enum_value == Jakt::DeprecatedString("append_code_point"sv)) {
return (TRY((((builder).append_code_point(JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<u32, ErrorOr<interpreter::StatementResult>>{
auto&& __jakt_match_variant = *((((arguments)[static_cast<i64>(0LL)])).impl);
switch(__jakt_match_variant.index()) {
case 4: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::U32>();
u32 const& value = __jakt_match_value.value;
return JaktInternal::ExplicitValue(value);
};/*case end*/
default: {
{
TRY((((*this).error(Jakt::DeprecatedString("Invalid use of StringBuilder::append_code_point()"sv),call_span))));
return Error::from_errno((infallible_integer_cast<i32>((interpreter::InterpretError::InvalidType))));
}
};/*case end*/
}/*switch end*/
}()
))))))), JaktInternal::ExplicitValue<void>();
}
else {
{
abort();
}
return JaktInternal::ExplicitValue<void>();
}
return JaktInternal::ExplicitValue<void>();
}()))
;
(((fields)[static_cast<i64>(0LL)]) = types::Value(TRY((types::ValueImpl::template create<typename types::ValueImpl::JaktString>(TRY((((builder).to_string())))))),call_span));
__jakt_var_170 =  interpreter::StatementResult { typename interpreter::StatementResult::JustValue(types::Value(TRY((types::ValueImpl::template create<typename types::ValueImpl::Void>())),call_span)) } ; goto __jakt_label_167;

}
__jakt_label_167:; __jakt_var_170.release_value(); }));
}
else if (__jakt_enum_value == Jakt::DeprecatedString("to_string"sv)) {
return JaktInternal::ExplicitValue(JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<interpreter::StatementResult, ErrorOr<interpreter::StatementResult>>{
auto&& __jakt_match_variant = *(((this_argument.value())).impl);
switch(__jakt_match_variant.index()) {
case 17: {
auto&& __jakt_match_value = __jakt_match_variant.template get<types::ValueImpl::Struct>();JaktInternal::DynamicArray<types::Value> const& fields = __jakt_match_value.fields;
return JaktInternal::ExplicitValue( interpreter::StatementResult { typename interpreter::StatementResult::JustValue(((fields)[static_cast<i64>(0LL)])) } );
};/*case end*/
default: {
{
TRY((((*this).error(TRY((__jakt_format(Jakt::DeprecatedString("Prelude function `StringBuilder::{}` expects a StringBuilder as its this argument"sv),prelude_function))),call_span))));
return Error::from_errno((infallible_integer_cast<i32>((interpreter::InterpretError::Unimplemented))));
}
};/*case end*/
}/*switch end*/
}()
)));
}
else if (__jakt_enum_value == Jakt::DeprecatedString("is_empty"sv)) {
return JaktInternal::ExplicitValue(JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<interpreter::StatementResult, ErrorOr<interpreter::StatementResult>>{
auto&& __jakt_match_variant = *(((this_argument.value())).impl);
switch(__jakt_match_variant.index()) {
case 17: {
auto&& __jakt_match_value = __jakt_match_variant.template get<types::ValueImpl::Struct>();JaktInternal::DynamicArray<types::Value> const& fields = __jakt_match_value.fields;
return JaktInternal::ExplicitValue(JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<interpreter::StatementResult, ErrorOr<interpreter::StatementResult>>{
auto&& __jakt_match_variant = *((((fields)[static_cast<i64>(0LL)])).impl);
switch(__jakt_match_variant.index()) {
case 13: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::JaktString>();
DeprecatedString const& value = __jakt_match_value.value;
return JaktInternal::ExplicitValue( interpreter::StatementResult { typename interpreter::StatementResult::JustValue(types::Value(TRY((types::ValueImpl::template create<typename types::ValueImpl::Bool>(((value).is_empty())))),call_span)) } );
};/*case end*/
default: {
{
utility::panic(Jakt::DeprecatedString("Invalid use of prelude StringBuilder"sv));
}
};/*case end*/
}/*switch end*/
}()
)));
};/*case end*/
default: {
{
TRY((((*this).error(TRY((__jakt_format(Jakt::DeprecatedString("Prelude function `StringBuilder::{}` expects a StringBuilder as its this argument"sv),prelude_function))),call_span))));
return Error::from_errno((infallible_integer_cast<i32>((interpreter::InterpretError::Unimplemented))));
}
};/*case end*/
}/*switch end*/
}()
)));
}
else if (__jakt_enum_value == Jakt::DeprecatedString("length"sv)) {
return JaktInternal::ExplicitValue(JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<interpreter::StatementResult, ErrorOr<interpreter::StatementResult>>{
auto&& __jakt_match_variant = *(((this_argument.value())).impl);
switch(__jakt_match_variant.index()) {
case 17: {
auto&& __jakt_match_value = __jakt_match_variant.template get<types::ValueImpl::Struct>();JaktInternal::DynamicArray<types::Value> const& fields = __jakt_match_value.fields;
return JaktInternal::ExplicitValue(JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<interpreter::StatementResult, ErrorOr<interpreter::StatementResult>>{
auto&& __jakt_match_variant = *((((fields)[static_cast<i64>(0LL)])).impl);
switch(__jakt_match_variant.index()) {
case 13: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::JaktString>();
DeprecatedString const& value = __jakt_match_value.value;
return JaktInternal::ExplicitValue( interpreter::StatementResult { typename interpreter::StatementResult::JustValue(types::Value(TRY((types::ValueImpl::template create<typename types::ValueImpl::USize>(((value).length())))),call_span)) } );
};/*case end*/
default: {
{
utility::panic(Jakt::DeprecatedString("Invalid use of prelude StringBuilder"sv));
}
};/*case end*/
}/*switch end*/
}()
)));
};/*case end*/
default: {
{
TRY((((*this).error(TRY((__jakt_format(Jakt::DeprecatedString("Prelude function `StringBuilder::{}` expects a StringBuilder as its this argument"sv),prelude_function))),call_span))));
return Error::from_errno((infallible_integer_cast<i32>((interpreter::InterpretError::Unimplemented))));
}
};/*case end*/
}/*switch end*/
}()
)));
}
else if (__jakt_enum_value == Jakt::DeprecatedString("clear"sv)) {
return JaktInternal::ExplicitValue(JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<interpreter::StatementResult, ErrorOr<interpreter::StatementResult>>{
auto&& __jakt_match_variant = *(((this_argument.value())).impl);
switch(__jakt_match_variant.index()) {
case 17: {
auto&& __jakt_match_value = __jakt_match_variant.template get<types::ValueImpl::Struct>();JaktInternal::DynamicArray<types::Value> const& fields = __jakt_match_value.fields;
return JaktInternal::ExplicitValue(({ Optional<interpreter::StatementResult> __jakt_var_171; {
JaktInternal::DynamicArray<types::Value> mutable_fields = fields;
(((((mutable_fields)[static_cast<i64>(0LL)])).impl) = TRY((types::ValueImpl::template create<typename types::ValueImpl::JaktString>(Jakt::DeprecatedString(""sv)))));
__jakt_var_171 =  interpreter::StatementResult { typename interpreter::StatementResult::JustValue(types::Value(TRY((types::ValueImpl::template create<typename types::ValueImpl::Void>())),call_span)) } ; goto __jakt_label_168;

}
__jakt_label_168:; __jakt_var_171.release_value(); }));
};/*case end*/
default: {
{
TRY((((*this).error(TRY((__jakt_format(Jakt::DeprecatedString("Prelude function `StringBuilder::{}` expects a StringBuilder as its this argument"sv),prelude_function))),call_span))));
return Error::from_errno((infallible_integer_cast<i32>((interpreter::InterpretError::Unimplemented))));
}
};/*case end*/
}/*switch end*/
}()
)));
}
else {
{
TRY((((*this).error(TRY((__jakt_format(Jakt::DeprecatedString("Prelude function `StringBuilder::{}` is not implemented"sv),prelude_function))),call_span))));
return Error::from_errno((infallible_integer_cast<i32>((interpreter::InterpretError::Unimplemented))));
}
}
}()))
);
}
else if (__jakt_enum_value == Jakt::DeprecatedString("Dictionary"sv)) {
return JaktInternal::ExplicitValue(JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<interpreter::StatementResult,ErrorOr<interpreter::StatementResult>>{
auto __jakt_enum_value = (prelude_function);
if (__jakt_enum_value == Jakt::DeprecatedString("Dictionary"sv)) {
return JaktInternal::ExplicitValue(({ Optional<interpreter::StatementResult> __jakt_var_172; {
if ((((type_bindings).size()) != static_cast<size_t>(2ULL))){
TRY((((*this).error(Jakt::DeprecatedString("Dictionary constructor expects two generic argumenst"sv),call_span))));
return Error::from_errno((infallible_integer_cast<i32>((interpreter::InterpretError::InvalidType))));
}
types::StructId const dictionary_struct_id = TRY((((((*this).program))->find_struct_in_prelude(Jakt::DeprecatedString("Dictionary"sv)))));
types::TypeId const type_id = TRY((((*this).find_or_add_type_id(TRY((types::Type::template create<typename types::Type::GenericInstance>(dictionary_struct_id,(TRY((DynamicArray<types::TypeId>::create_with({(((type_bindings).get(((TRY((((type_bindings).keys()))))[static_cast<i64>(0LL)]))).value()), (((type_bindings).get(((TRY((((type_bindings).keys()))))[static_cast<i64>(1LL)]))).value())})))))))))));
__jakt_var_172 =  interpreter::StatementResult { typename interpreter::StatementResult::JustValue(types::Value(TRY((types::ValueImpl::template create<typename types::ValueImpl::JaktDictionary>((TRY((DynamicArray<types::Value>::create_with({})))),(TRY((DynamicArray<types::Value>::create_with({})))),type_id))),call_span)) } ; goto __jakt_label_169;

}
__jakt_label_169:; __jakt_var_172.release_value(); }));
}
else if (__jakt_enum_value == Jakt::DeprecatedString("get"sv)) {
return JaktInternal::ExplicitValue(JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<interpreter::StatementResult, ErrorOr<interpreter::StatementResult>>{
auto&& __jakt_match_variant = *(((this_argument.value())).impl);
switch(__jakt_match_variant.index()) {
case 21: {
auto&& __jakt_match_value = __jakt_match_variant.template get<types::ValueImpl::JaktDictionary>();JaktInternal::DynamicArray<types::Value> const& keys = __jakt_match_value.keys;
JaktInternal::DynamicArray<types::Value> const& values = __jakt_match_value.values;
return JaktInternal::ExplicitValue(({ Optional<interpreter::StatementResult> __jakt_var_173; {
JaktInternal::Optional<size_t> found_index = JaktInternal::OptionalNone();
{
JaktInternal::Range<size_t> _magic = (JaktInternal::Range<size_t>{static_cast<size_t>(static_cast<size_t>(0ULL)),static_cast<size_t>(((keys).size()))});
for (;;){
JaktInternal::Optional<size_t> _magic_value = ((_magic).next());
if ((!(((_magic_value).has_value())))){
break;
}
size_t i = (_magic_value.value());
{
if (((((((keys)[i])).impl))->equals(((((arguments)[static_cast<i64>(0LL)])).impl)))){
(found_index = i);
break;
}
}

}
}

__jakt_var_173 =  interpreter::StatementResult { typename interpreter::StatementResult::JustValue(JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<types::Value,ErrorOr<interpreter::StatementResult>>{
auto __jakt_enum_value = (((found_index).has_value()));
if (__jakt_enum_value == true) {
return JaktInternal::ExplicitValue(types::Value(TRY((types::ValueImpl::template create<typename types::ValueImpl::OptionalSome>(((values)[(found_index.value())])))),call_span));
}
else {
return JaktInternal::ExplicitValue(types::Value(TRY((types::ValueImpl::template create<typename types::ValueImpl::OptionalNone>())),call_span));
}
}()))
) } ; goto __jakt_label_170;

}
__jakt_label_170:; __jakt_var_173.release_value(); }));
};/*case end*/
default: {
{
utility::panic(Jakt::DeprecatedString("Invalid use of Dictionary::get()"sv));
}
};/*case end*/
}/*switch end*/
}()
)));
}
else if (__jakt_enum_value == Jakt::DeprecatedString("set"sv)) {
return JaktInternal::ExplicitValue(JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<interpreter::StatementResult, ErrorOr<interpreter::StatementResult>>{
auto&& __jakt_match_variant = *(((this_argument.value())).impl);
switch(__jakt_match_variant.index()) {
case 21: {
auto&& __jakt_match_value = __jakt_match_variant.template get<types::ValueImpl::JaktDictionary>();JaktInternal::DynamicArray<types::Value> const& keys = __jakt_match_value.keys;
JaktInternal::DynamicArray<types::Value> const& values = __jakt_match_value.values;
return JaktInternal::ExplicitValue(({ Optional<interpreter::StatementResult> __jakt_var_174; {
JaktInternal::Optional<size_t> found_index = JaktInternal::OptionalNone();
{
JaktInternal::Range<size_t> _magic = (JaktInternal::Range<size_t>{static_cast<size_t>(static_cast<size_t>(0ULL)),static_cast<size_t>(((keys).size()))});
for (;;){
JaktInternal::Optional<size_t> _magic_value = ((_magic).next());
if ((!(((_magic_value).has_value())))){
break;
}
size_t i = (_magic_value.value());
{
if (((((((keys)[i])).impl))->equals(((((arguments)[static_cast<i64>(0LL)])).impl)))){
(found_index = i);
break;
}
}

}
}

JaktInternal::DynamicArray<types::Value> mutable_keys = keys;
JaktInternal::DynamicArray<types::Value> mutable_values = values;
if (((found_index).has_value())){
(((mutable_values)[(found_index.value())]) = ((arguments)[static_cast<i64>(1LL)]));
}
else {
TRY((((mutable_keys).push(((arguments)[static_cast<i64>(0LL)])))));
TRY((((mutable_values).push(((arguments)[static_cast<i64>(1LL)])))));
}

__jakt_var_174 =  interpreter::StatementResult { typename interpreter::StatementResult::JustValue(types::Value(TRY((types::ValueImpl::template create<typename types::ValueImpl::Void>())),call_span)) } ; goto __jakt_label_171;

}
__jakt_label_171:; __jakt_var_174.release_value(); }));
};/*case end*/
default: {
{
utility::panic(Jakt::DeprecatedString("Invalid use of Dictionary::set()"sv));
}
};/*case end*/
}/*switch end*/
}()
)));
}
else if (__jakt_enum_value == Jakt::DeprecatedString("is_empty"sv)) {
return JaktInternal::ExplicitValue(JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<interpreter::StatementResult, ErrorOr<interpreter::StatementResult>>{
auto&& __jakt_match_variant = *(((this_argument.value())).impl);
switch(__jakt_match_variant.index()) {
case 21: {
auto&& __jakt_match_value = __jakt_match_variant.template get<types::ValueImpl::JaktDictionary>();JaktInternal::DynamicArray<types::Value> const& keys = __jakt_match_value.keys;
JaktInternal::DynamicArray<types::Value> const& values = __jakt_match_value.values;
return JaktInternal::ExplicitValue( interpreter::StatementResult { typename interpreter::StatementResult::JustValue(types::Value(TRY((types::ValueImpl::template create<typename types::ValueImpl::Bool>((((keys).is_empty()) && ((values).is_empty()))))),call_span)) } );
};/*case end*/
default: {
{
utility::panic(Jakt::DeprecatedString("Invalid use of Dictionary::is_empty()"sv));
}
};/*case end*/
}/*switch end*/
}()
)));
}
else if (__jakt_enum_value == Jakt::DeprecatedString("contains"sv)) {
return JaktInternal::ExplicitValue(JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<interpreter::StatementResult, ErrorOr<interpreter::StatementResult>>{
auto&& __jakt_match_variant = *(((this_argument.value())).impl);
switch(__jakt_match_variant.index()) {
case 21: {
auto&& __jakt_match_value = __jakt_match_variant.template get<types::ValueImpl::JaktDictionary>();JaktInternal::DynamicArray<types::Value> const& keys = __jakt_match_value.keys;
return JaktInternal::ExplicitValue(({ Optional<interpreter::StatementResult> __jakt_var_175; {
bool found = false;
{
JaktInternal::Range<size_t> _magic = (JaktInternal::Range<size_t>{static_cast<size_t>(static_cast<size_t>(0ULL)),static_cast<size_t>(((keys).size()))});
for (;;){
JaktInternal::Optional<size_t> _magic_value = ((_magic).next());
if ((!(((_magic_value).has_value())))){
break;
}
size_t i = (_magic_value.value());
{
if (((((((keys)[i])).impl))->equals(((((arguments)[static_cast<i64>(0LL)])).impl)))){
(found = true);
break;
}
}

}
}

__jakt_var_175 =  interpreter::StatementResult { typename interpreter::StatementResult::JustValue(types::Value(TRY((types::ValueImpl::template create<typename types::ValueImpl::Bool>(found))),call_span)) } ; goto __jakt_label_172;

}
__jakt_label_172:; __jakt_var_175.release_value(); }));
};/*case end*/
default: {
{
utility::panic(Jakt::DeprecatedString("Invalid use of Dictionary::contains()"sv));
}
};/*case end*/
}/*switch end*/
}()
)));
}
else if (__jakt_enum_value == Jakt::DeprecatedString("remove"sv)) {
return JaktInternal::ExplicitValue(JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<interpreter::StatementResult, ErrorOr<interpreter::StatementResult>>{
auto&& __jakt_match_variant = *(((this_argument.value())).impl);
switch(__jakt_match_variant.index()) {
case 21: {
auto&& __jakt_match_value = __jakt_match_variant.template get<types::ValueImpl::JaktDictionary>();JaktInternal::DynamicArray<types::Value> const& keys = __jakt_match_value.keys;
JaktInternal::DynamicArray<types::Value> const& values = __jakt_match_value.values;
return JaktInternal::ExplicitValue(({ Optional<interpreter::StatementResult> __jakt_var_176; {
JaktInternal::Optional<size_t> found_index = JaktInternal::OptionalNone();
{
JaktInternal::Range<size_t> _magic = (JaktInternal::Range<size_t>{static_cast<size_t>(static_cast<size_t>(0ULL)),static_cast<size_t>(((keys).size()))});
for (;;){
JaktInternal::Optional<size_t> _magic_value = ((_magic).next());
if ((!(((_magic_value).has_value())))){
break;
}
size_t i = (_magic_value.value());
{
if (((((((keys)[i])).impl))->equals(((((arguments)[static_cast<i64>(0LL)])).impl)))){
(found_index = i);
break;
}
}

}
}

if (((found_index).has_value())){
JaktInternal::DynamicArray<types::Value> keys_without = (TRY((DynamicArray<types::Value>::create_with({}))));
JaktInternal::DynamicArray<types::Value> values_without = (TRY((DynamicArray<types::Value>::create_with({}))));
{
JaktInternal::Range<size_t> _magic = (JaktInternal::Range<size_t>{static_cast<size_t>(static_cast<size_t>(0ULL)),static_cast<size_t>(((keys).size()))});
for (;;){
JaktInternal::Optional<size_t> _magic_value = ((_magic).next());
if ((!(((_magic_value).has_value())))){
break;
}
size_t i = (_magic_value.value());
{
if ((i == (found_index.value()))){
continue;
}
TRY((((keys_without).push(((keys)[i])))));
TRY((((values_without).push(((values)[i])))));
}

}
}

JaktInternal::DynamicArray<types::Value> mutable_keys = keys;
JaktInternal::DynamicArray<types::Value> mutable_values = values;
((mutable_keys).shrink(static_cast<size_t>(0ULL)));
((mutable_values).shrink(static_cast<size_t>(0ULL)));
{
JaktInternal::Range<size_t> _magic = (JaktInternal::Range<size_t>{static_cast<size_t>(static_cast<size_t>(0ULL)),static_cast<size_t>(((keys_without).size()))});
for (;;){
JaktInternal::Optional<size_t> _magic_value = ((_magic).next());
if ((!(((_magic_value).has_value())))){
break;
}
size_t i = (_magic_value.value());
{
TRY((((mutable_keys).push(((keys_without)[i])))));
TRY((((mutable_values).push(((values_without)[i])))));
}

}
}

}
__jakt_var_176 =  interpreter::StatementResult { typename interpreter::StatementResult::JustValue(types::Value(TRY((types::ValueImpl::template create<typename types::ValueImpl::Bool>(((found_index).has_value())))),call_span)) } ; goto __jakt_label_173;

}
__jakt_label_173:; __jakt_var_176.release_value(); }));
};/*case end*/
default: {
{
utility::panic(Jakt::DeprecatedString("Invalid use of Dictionary::remove()"sv));
}
};/*case end*/
}/*switch end*/
}()
)));
}
else if (__jakt_enum_value == Jakt::DeprecatedString("ensure_capacity"sv)) {
return JaktInternal::ExplicitValue(JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<interpreter::StatementResult, ErrorOr<interpreter::StatementResult>>{
auto&& __jakt_match_variant = *(((this_argument.value())).impl);
switch(__jakt_match_variant.index()) {
case 21: {
auto&& __jakt_match_value = __jakt_match_variant.template get<types::ValueImpl::JaktDictionary>();JaktInternal::DynamicArray<types::Value> const& keys = __jakt_match_value.keys;
JaktInternal::DynamicArray<types::Value> const& values = __jakt_match_value.values;
return JaktInternal::ExplicitValue(JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<interpreter::StatementResult, ErrorOr<interpreter::StatementResult>>{
auto&& __jakt_match_variant = *((((arguments)[static_cast<i64>(0LL)])).impl);
switch(__jakt_match_variant.index()) {
case 12: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::USize>();
size_t const& capacity = __jakt_match_value.value;
return JaktInternal::ExplicitValue(({ Optional<interpreter::StatementResult> __jakt_var_177; {
JaktInternal::DynamicArray<types::Value> mutable_keys = keys;
JaktInternal::DynamicArray<types::Value> mutable_values = values;
TRY((((mutable_keys).ensure_capacity(capacity))));
TRY((((mutable_values).ensure_capacity(capacity))));
__jakt_var_177 =  interpreter::StatementResult { typename interpreter::StatementResult::JustValue(types::Value(TRY((types::ValueImpl::template create<typename types::ValueImpl::Void>())),call_span)) } ; goto __jakt_label_174;

}
__jakt_label_174:; __jakt_var_177.release_value(); }));
};/*case end*/
default: {
{
TRY((((*this).error(Jakt::DeprecatedString("Dictionary::ensure_capacity must be called with a usize"sv),((((arguments)[static_cast<i64>(0LL)])).span)))));
return Error::from_errno((infallible_integer_cast<i32>((interpreter::InterpretError::InvalidType))));
}
};/*case end*/
}/*switch end*/
}()
)));
};/*case end*/
default: {
{
utility::panic(Jakt::DeprecatedString("Invalid use of Dictionary::ensure_capacity()"sv));
}
};/*case end*/
}/*switch end*/
}()
)));
}
else if (__jakt_enum_value == Jakt::DeprecatedString("capacity"sv)) {
return JaktInternal::ExplicitValue(JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<interpreter::StatementResult, ErrorOr<interpreter::StatementResult>>{
auto&& __jakt_match_variant = *(((this_argument.value())).impl);
switch(__jakt_match_variant.index()) {
case 21: {
auto&& __jakt_match_value = __jakt_match_variant.template get<types::ValueImpl::JaktDictionary>();JaktInternal::DynamicArray<types::Value> const& keys = __jakt_match_value.keys;
return JaktInternal::ExplicitValue( interpreter::StatementResult { typename interpreter::StatementResult::JustValue(types::Value(TRY((types::ValueImpl::template create<typename types::ValueImpl::USize>(((keys).capacity())))),call_span)) } );
};/*case end*/
default: {
{
utility::panic(Jakt::DeprecatedString("Invalid use of Dictionary::capacity()"sv));
}
};/*case end*/
}/*switch end*/
}()
)));
}
else if (__jakt_enum_value == Jakt::DeprecatedString("clear"sv)) {
return JaktInternal::ExplicitValue(JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<interpreter::StatementResult, ErrorOr<interpreter::StatementResult>>{
auto&& __jakt_match_variant = *(((this_argument.value())).impl);
switch(__jakt_match_variant.index()) {
case 21: {
auto&& __jakt_match_value = __jakt_match_variant.template get<types::ValueImpl::JaktDictionary>();JaktInternal::DynamicArray<types::Value> const& keys = __jakt_match_value.keys;
JaktInternal::DynamicArray<types::Value> const& values = __jakt_match_value.values;
return JaktInternal::ExplicitValue(({ Optional<interpreter::StatementResult> __jakt_var_178; {
JaktInternal::DynamicArray<types::Value> mutable_keys = keys;
JaktInternal::DynamicArray<types::Value> mutable_values = values;
((mutable_keys).shrink(static_cast<size_t>(0ULL)));
((mutable_values).shrink(static_cast<size_t>(0ULL)));
__jakt_var_178 =  interpreter::StatementResult { typename interpreter::StatementResult::JustValue(types::Value(TRY((types::ValueImpl::template create<typename types::ValueImpl::Void>())),call_span)) } ; goto __jakt_label_175;

}
__jakt_label_175:; __jakt_var_178.release_value(); }));
};/*case end*/
default: {
{
utility::panic(Jakt::DeprecatedString("Invalid use of Dictionary::clear()"sv));
}
};/*case end*/
}/*switch end*/
}()
)));
}
else if (__jakt_enum_value == Jakt::DeprecatedString("size"sv)) {
return JaktInternal::ExplicitValue(JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<interpreter::StatementResult, ErrorOr<interpreter::StatementResult>>{
auto&& __jakt_match_variant = *(((this_argument.value())).impl);
switch(__jakt_match_variant.index()) {
case 21: {
auto&& __jakt_match_value = __jakt_match_variant.template get<types::ValueImpl::JaktDictionary>();JaktInternal::DynamicArray<types::Value> const& keys = __jakt_match_value.keys;
return JaktInternal::ExplicitValue( interpreter::StatementResult { typename interpreter::StatementResult::JustValue(types::Value(TRY((types::ValueImpl::template create<typename types::ValueImpl::USize>(((keys).size())))),call_span)) } );
};/*case end*/
default: {
{
utility::panic(Jakt::DeprecatedString("Invalid use of Dictionary::size()"sv));
}
};/*case end*/
}/*switch end*/
}()
)));
}
else if (__jakt_enum_value == Jakt::DeprecatedString("keys"sv)) {
return JaktInternal::ExplicitValue(JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<interpreter::StatementResult, ErrorOr<interpreter::StatementResult>>{
auto&& __jakt_match_variant = *(((this_argument.value())).impl);
switch(__jakt_match_variant.index()) {
case 21: {
auto&& __jakt_match_value = __jakt_match_variant.template get<types::ValueImpl::JaktDictionary>();JaktInternal::DynamicArray<types::Value> const& keys = __jakt_match_value.keys;
types::TypeId const& type_id = __jakt_match_value.type_id;
return JaktInternal::ExplicitValue(({ Optional<interpreter::StatementResult> __jakt_var_179; {
JaktInternal::DynamicArray<types::TypeId> const generics = JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<JaktInternal::DynamicArray<types::TypeId>, ErrorOr<interpreter::StatementResult>>{
auto&& __jakt_match_variant = *((((*this).program))->get_type(type_id));
switch(__jakt_match_variant.index()) {
case 19: {
auto&& __jakt_match_value = __jakt_match_variant.template get<types::Type::GenericInstance>();JaktInternal::DynamicArray<types::TypeId> const& args = __jakt_match_value.args;
return JaktInternal::ExplicitValue(args);
};/*case end*/
default: {
{
utility::panic(Jakt::DeprecatedString("expected generic instance"sv));
}
};/*case end*/
}/*switch end*/
}()
));
__jakt_var_179 = JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<interpreter::StatementResult,ErrorOr<interpreter::StatementResult>>{
auto __jakt_enum_value = ((((generics).size()) == static_cast<size_t>(2ULL)));
if (__jakt_enum_value == true) {
return JaktInternal::ExplicitValue(({ Optional<interpreter::StatementResult> __jakt_var_180; {
types::StructId const array_struct_id = TRY((((((*this).program))->find_struct_in_prelude(Jakt::DeprecatedString("Array"sv)))));
types::TypeId const type_id = TRY((((*this).find_or_add_type_id(TRY((types::Type::template create<typename types::Type::GenericInstance>(array_struct_id,(TRY((DynamicArray<types::TypeId>::create_with({((generics)[static_cast<i64>(0LL)])})))))))))));
__jakt_var_180 =  interpreter::StatementResult { typename interpreter::StatementResult::JustValue(types::Value(TRY((types::ValueImpl::template create<typename types::ValueImpl::JaktArray>(keys,type_id))),call_span)) } ; goto __jakt_label_177;

}
__jakt_label_177:; __jakt_var_180.release_value(); }));
}
else {
{
utility::panic(Jakt::DeprecatedString("dictionary should have 2 generic args. one for keys, one for values"sv));
}
}
}()))
; goto __jakt_label_176;

}
__jakt_label_176:; __jakt_var_179.release_value(); }));
};/*case end*/
default: {
{
utility::panic(Jakt::DeprecatedString("Invalid use of Dictionary::keys()"sv));
}
};/*case end*/
}/*switch end*/
}()
)));
}
else if (__jakt_enum_value == Jakt::DeprecatedString("iterator"sv)) {
return JaktInternal::ExplicitValue(JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<interpreter::StatementResult, ErrorOr<interpreter::StatementResult>>{
auto&& __jakt_match_variant = *(((this_argument.value())).impl);
switch(__jakt_match_variant.index()) {
case 21: {
auto&& __jakt_match_value = __jakt_match_variant.template get<types::ValueImpl::JaktDictionary>();return JaktInternal::ExplicitValue(({ Optional<interpreter::StatementResult> __jakt_var_181; {
types::StructId const struct_id = TRY((((((*this).program))->find_struct_in_prelude(Jakt::DeprecatedString("DictionaryIterator"sv)))));
__jakt_var_181 =  interpreter::StatementResult { typename interpreter::StatementResult::JustValue(types::Value(TRY((types::ValueImpl::template create<typename types::ValueImpl::Struct>((TRY((DynamicArray<types::Value>::create_with({(this_argument.value()), types::Value(TRY((types::ValueImpl::template create<typename types::ValueImpl::USize>(static_cast<size_t>(0ULL)))),call_span)})))),struct_id,JaktInternal::OptionalNone()))),call_span)) } ; goto __jakt_label_178;

}
__jakt_label_178:; __jakt_var_181.release_value(); }));
};/*case end*/
default: {
{
utility::panic(Jakt::DeprecatedString("Invalid use of Dictionary::iterator()"sv));
}
};/*case end*/
}/*switch end*/
}()
)));
}
else {
{
TRY((((*this).error(TRY((__jakt_format(Jakt::DeprecatedString("Prelude function `Dictionary::{}` is not implemented"sv),prelude_function))),call_span))));
return Error::from_errno((infallible_integer_cast<i32>((interpreter::InterpretError::Unimplemented))));
}
}
}()))
);
}
else if (__jakt_enum_value == Jakt::DeprecatedString("Array"sv)) {
return JaktInternal::ExplicitValue(JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<interpreter::StatementResult,ErrorOr<interpreter::StatementResult>>{
auto __jakt_enum_value = (prelude_function);
if (__jakt_enum_value == Jakt::DeprecatedString("iterator"sv)) {
return JaktInternal::ExplicitValue(JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<interpreter::StatementResult, ErrorOr<interpreter::StatementResult>>{
auto&& __jakt_match_variant = *(((this_argument.value())).impl);
switch(__jakt_match_variant.index()) {
case 20: {
auto&& __jakt_match_value = __jakt_match_variant.template get<types::ValueImpl::JaktArray>();return JaktInternal::ExplicitValue(({ Optional<interpreter::StatementResult> __jakt_var_182; {
types::StructId const struct_id = TRY((((((*this).program))->find_struct_in_prelude(Jakt::DeprecatedString("ArrayIterator"sv)))));
__jakt_var_182 =  interpreter::StatementResult { typename interpreter::StatementResult::JustValue(types::Value(TRY((types::ValueImpl::template create<typename types::ValueImpl::Struct>((TRY((DynamicArray<types::Value>::create_with({(this_argument.value()), types::Value(TRY((types::ValueImpl::template create<typename types::ValueImpl::USize>(static_cast<size_t>(0ULL)))),call_span)})))),struct_id,JaktInternal::OptionalNone()))),call_span)) } ; goto __jakt_label_179;

}
__jakt_label_179:; __jakt_var_182.release_value(); }));
};/*case end*/
default: {
{
utility::panic(Jakt::DeprecatedString("Invalid use of Array::iterator()"sv));
}
};/*case end*/
}/*switch end*/
}()
)));
}
else if (__jakt_enum_value == Jakt::DeprecatedString("size"sv)) {
return JaktInternal::ExplicitValue(JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<interpreter::StatementResult, ErrorOr<interpreter::StatementResult>>{
auto&& __jakt_match_variant = *(((this_argument.value())).impl);
switch(__jakt_match_variant.index()) {
case 20: {
auto&& __jakt_match_value = __jakt_match_variant.template get<types::ValueImpl::JaktArray>();JaktInternal::DynamicArray<types::Value> const& values = __jakt_match_value.values;
return JaktInternal::ExplicitValue(({ Optional<interpreter::StatementResult> __jakt_var_183; {
__jakt_var_183 =  interpreter::StatementResult { typename interpreter::StatementResult::JustValue(types::Value(TRY((types::ValueImpl::template create<typename types::ValueImpl::USize>(((values).size())))),call_span)) } ; goto __jakt_label_180;

}
__jakt_label_180:; __jakt_var_183.release_value(); }));
};/*case end*/
default: {
{
utility::panic(Jakt::DeprecatedString("Invalid use of Array::size()"sv));
}
};/*case end*/
}/*switch end*/
}()
)));
}
else if (__jakt_enum_value == Jakt::DeprecatedString("push"sv)) {
return JaktInternal::ExplicitValue(JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<interpreter::StatementResult, ErrorOr<interpreter::StatementResult>>{
auto&& __jakt_match_variant = *(((this_argument.value())).impl);
switch(__jakt_match_variant.index()) {
case 20: {
auto&& __jakt_match_value = __jakt_match_variant.template get<types::ValueImpl::JaktArray>();JaktInternal::DynamicArray<types::Value> const& values = __jakt_match_value.values;
return JaktInternal::ExplicitValue(({ Optional<interpreter::StatementResult> __jakt_var_184; {
JaktInternal::DynamicArray<types::Value> mutable_values = values;
TRY((((mutable_values).push(((arguments)[static_cast<i64>(0LL)])))));
__jakt_var_184 =  interpreter::StatementResult { typename interpreter::StatementResult::JustValue(types::Value(TRY((types::ValueImpl::template create<typename types::ValueImpl::Void>())),call_span)) } ; goto __jakt_label_181;

}
__jakt_label_181:; __jakt_var_184.release_value(); }));
};/*case end*/
default: {
{
utility::panic(Jakt::DeprecatedString("Invalid use of Array::push()"sv));
}
};/*case end*/
}/*switch end*/
}()
)));
}
else if (__jakt_enum_value == Jakt::DeprecatedString("push_values"sv)) {
return JaktInternal::ExplicitValue(JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<interpreter::StatementResult, ErrorOr<interpreter::StatementResult>>{
auto&& __jakt_match_variant = *(((this_argument.value())).impl);
switch(__jakt_match_variant.index()) {
case 20: {
auto&& __jakt_match_value = __jakt_match_variant.template get<types::ValueImpl::JaktArray>();JaktInternal::DynamicArray<types::Value> const& values = __jakt_match_value.values;
return JaktInternal::ExplicitValue(({ Optional<interpreter::StatementResult> __jakt_var_185; {
JaktInternal::DynamicArray<types::Value> mutable_values = values;
JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<void, ErrorOr<interpreter::StatementResult>>{
auto&& __jakt_match_variant = *((((arguments)[static_cast<i64>(0LL)])).impl);
switch(__jakt_match_variant.index()) {
case 20: {
auto&& __jakt_match_value = __jakt_match_variant.template get<types::ValueImpl::JaktArray>();JaktInternal::DynamicArray<types::Value> const& values = __jakt_match_value.values;
{
{
JaktInternal::ArrayIterator<types::Value> _magic = ((values).iterator());
for (;;){
JaktInternal::Optional<types::Value> _magic_value = ((_magic).next());
if ((!(((_magic_value).has_value())))){
break;
}
types::Value value = (_magic_value.value());
{
TRY((((mutable_values).push(value))));
}

}
}

}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
default: {
return (TRY((((*this).error(Jakt::DeprecatedString("Only argument to push_values needs to be another Array"sv),call_span))))), JaktInternal::ExplicitValue<void>();
};/*case end*/
}/*switch end*/
}()
));
__jakt_var_185 =  interpreter::StatementResult { typename interpreter::StatementResult::JustValue(types::Value(TRY((types::ValueImpl::template create<typename types::ValueImpl::Void>())),call_span)) } ; goto __jakt_label_182;

}
__jakt_label_182:; __jakt_var_185.release_value(); }));
};/*case end*/
default: {
{
utility::panic(Jakt::DeprecatedString("Invalid use of Array::push_values()"sv));
}
};/*case end*/
}/*switch end*/
}()
)));
}
else if (__jakt_enum_value == Jakt::DeprecatedString("pop"sv)) {
return JaktInternal::ExplicitValue(JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<interpreter::StatementResult, ErrorOr<interpreter::StatementResult>>{
auto&& __jakt_match_variant = *(((this_argument.value())).impl);
switch(__jakt_match_variant.index()) {
case 20: {
auto&& __jakt_match_value = __jakt_match_variant.template get<types::ValueImpl::JaktArray>();JaktInternal::DynamicArray<types::Value> const& values = __jakt_match_value.values;
return JaktInternal::ExplicitValue(({ Optional<interpreter::StatementResult> __jakt_var_186; {
JaktInternal::DynamicArray<types::Value> mutable_values = values;
JaktInternal::Optional<types::Value> const value = ((mutable_values).pop());
__jakt_var_186 = JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<interpreter::StatementResult,ErrorOr<interpreter::StatementResult>>{
auto __jakt_enum_value = (((value).has_value()));
if (__jakt_enum_value == true) {
return JaktInternal::ExplicitValue( interpreter::StatementResult { typename interpreter::StatementResult::JustValue((value.value())) } );
}
else {
return JaktInternal::ExplicitValue( interpreter::StatementResult { typename interpreter::StatementResult::JustValue(types::Value(TRY((types::ValueImpl::template create<typename types::ValueImpl::OptionalNone>())),call_span)) } );
}
}()))
; goto __jakt_label_183;

}
__jakt_label_183:; __jakt_var_186.release_value(); }));
};/*case end*/
default: {
{
utility::panic(Jakt::DeprecatedString("Invalid use of Array::push()"sv));
}
};/*case end*/
}/*switch end*/
}()
)));
}
else if (__jakt_enum_value == Jakt::DeprecatedString("first"sv)) {
return JaktInternal::ExplicitValue(JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<interpreter::StatementResult, ErrorOr<interpreter::StatementResult>>{
auto&& __jakt_match_variant = *(((this_argument.value())).impl);
switch(__jakt_match_variant.index()) {
case 20: {
auto&& __jakt_match_value = __jakt_match_variant.template get<types::ValueImpl::JaktArray>();JaktInternal::DynamicArray<types::Value> const& values = __jakt_match_value.values;
return JaktInternal::ExplicitValue(({ Optional<interpreter::StatementResult> __jakt_var_187; {
JaktInternal::DynamicArray<types::Value> mutable_values = values;
JaktInternal::Optional<types::Value> const value = ((mutable_values).first());
__jakt_var_187 = JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<interpreter::StatementResult,ErrorOr<interpreter::StatementResult>>{
auto __jakt_enum_value = (((value).has_value()));
if (__jakt_enum_value == true) {
return JaktInternal::ExplicitValue( interpreter::StatementResult { typename interpreter::StatementResult::JustValue((value.value())) } );
}
else {
return JaktInternal::ExplicitValue( interpreter::StatementResult { typename interpreter::StatementResult::JustValue(types::Value(TRY((types::ValueImpl::template create<typename types::ValueImpl::OptionalNone>())),call_span)) } );
}
}()))
; goto __jakt_label_184;

}
__jakt_label_184:; __jakt_var_187.release_value(); }));
};/*case end*/
default: {
{
utility::panic(Jakt::DeprecatedString("Invalid use of Array::push()"sv));
}
};/*case end*/
}/*switch end*/
}()
)));
}
else if (__jakt_enum_value == Jakt::DeprecatedString("last"sv)) {
return JaktInternal::ExplicitValue(JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<interpreter::StatementResult, ErrorOr<interpreter::StatementResult>>{
auto&& __jakt_match_variant = *(((this_argument.value())).impl);
switch(__jakt_match_variant.index()) {
case 20: {
auto&& __jakt_match_value = __jakt_match_variant.template get<types::ValueImpl::JaktArray>();JaktInternal::DynamicArray<types::Value> const& values = __jakt_match_value.values;
return JaktInternal::ExplicitValue(({ Optional<interpreter::StatementResult> __jakt_var_188; {
JaktInternal::DynamicArray<types::Value> mutable_values = values;
JaktInternal::Optional<types::Value> const value = ((mutable_values).last());
__jakt_var_188 = JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<interpreter::StatementResult,ErrorOr<interpreter::StatementResult>>{
auto __jakt_enum_value = (((value).has_value()));
if (__jakt_enum_value == true) {
return JaktInternal::ExplicitValue( interpreter::StatementResult { typename interpreter::StatementResult::JustValue((value.value())) } );
}
else {
return JaktInternal::ExplicitValue( interpreter::StatementResult { typename interpreter::StatementResult::JustValue(types::Value(TRY((types::ValueImpl::template create<typename types::ValueImpl::OptionalNone>())),call_span)) } );
}
}()))
; goto __jakt_label_185;

}
__jakt_label_185:; __jakt_var_188.release_value(); }));
};/*case end*/
default: {
{
utility::panic(Jakt::DeprecatedString("Invalid use of Array::push()"sv));
}
};/*case end*/
}/*switch end*/
}()
)));
}
else if (__jakt_enum_value == Jakt::DeprecatedString("contains"sv)) {
return JaktInternal::ExplicitValue(JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<interpreter::StatementResult, ErrorOr<interpreter::StatementResult>>{
auto&& __jakt_match_variant = *(((this_argument.value())).impl);
switch(__jakt_match_variant.index()) {
case 20: {
auto&& __jakt_match_value = __jakt_match_variant.template get<types::ValueImpl::JaktArray>();JaktInternal::DynamicArray<types::Value> const& values = __jakt_match_value.values;
return JaktInternal::ExplicitValue(({ Optional<interpreter::StatementResult> __jakt_var_189; {
bool found = false;
{
JaktInternal::ArrayIterator<types::Value> _magic = ((values).iterator());
for (;;){
JaktInternal::Optional<types::Value> _magic_value = ((_magic).next());
if ((!(((_magic_value).has_value())))){
break;
}
types::Value value = (_magic_value.value());
{
if (((((value).impl))->equals(((((arguments)[static_cast<i64>(0LL)])).impl)))){
(found = true);
break;
}
}

}
}

__jakt_var_189 =  interpreter::StatementResult { typename interpreter::StatementResult::JustValue(types::Value(TRY((types::ValueImpl::template create<typename types::ValueImpl::Bool>(found))),call_span)) } ; goto __jakt_label_186;

}
__jakt_label_186:; __jakt_var_189.release_value(); }));
};/*case end*/
default: {
{
utility::panic(Jakt::DeprecatedString("Invalid use of Array::contains()"sv));
}
};/*case end*/
}/*switch end*/
}()
)));
}
else if (__jakt_enum_value == Jakt::DeprecatedString("is_empty"sv)) {
return JaktInternal::ExplicitValue(JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<interpreter::StatementResult, ErrorOr<interpreter::StatementResult>>{
auto&& __jakt_match_variant = *(((this_argument.value())).impl);
switch(__jakt_match_variant.index()) {
case 20: {
auto&& __jakt_match_value = __jakt_match_variant.template get<types::ValueImpl::JaktArray>();JaktInternal::DynamicArray<types::Value> const& values = __jakt_match_value.values;
return JaktInternal::ExplicitValue( interpreter::StatementResult { typename interpreter::StatementResult::JustValue(types::Value(TRY((types::ValueImpl::template create<typename types::ValueImpl::Bool>(((values).is_empty())))),call_span)) } );
};/*case end*/
default: {
{
utility::panic(Jakt::DeprecatedString("Invalid use of Array::is_empty()"sv));
}
};/*case end*/
}/*switch end*/
}()
)));
}
else if (__jakt_enum_value == Jakt::DeprecatedString("capacity"sv)) {
return JaktInternal::ExplicitValue(JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<interpreter::StatementResult, ErrorOr<interpreter::StatementResult>>{
auto&& __jakt_match_variant = *(((this_argument.value())).impl);
switch(__jakt_match_variant.index()) {
case 20: {
auto&& __jakt_match_value = __jakt_match_variant.template get<types::ValueImpl::JaktArray>();JaktInternal::DynamicArray<types::Value> const& values = __jakt_match_value.values;
return JaktInternal::ExplicitValue(({ Optional<interpreter::StatementResult> __jakt_var_190; {
__jakt_var_190 =  interpreter::StatementResult { typename interpreter::StatementResult::JustValue(types::Value(TRY((types::ValueImpl::template create<typename types::ValueImpl::USize>(((values).capacity())))),call_span)) } ; goto __jakt_label_187;

}
__jakt_label_187:; __jakt_var_190.release_value(); }));
};/*case end*/
default: {
{
utility::panic(Jakt::DeprecatedString("Invalid use of Array::capacity()"sv));
}
};/*case end*/
}/*switch end*/
}()
)));
}
else if (__jakt_enum_value == Jakt::DeprecatedString("ensure_capacity"sv)) {
return JaktInternal::ExplicitValue(JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<interpreter::StatementResult, ErrorOr<interpreter::StatementResult>>{
auto&& __jakt_match_variant = *(((this_argument.value())).impl);
switch(__jakt_match_variant.index()) {
case 20: {
auto&& __jakt_match_value = __jakt_match_variant.template get<types::ValueImpl::JaktArray>();JaktInternal::DynamicArray<types::Value> const& values = __jakt_match_value.values;
return JaktInternal::ExplicitValue(JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<interpreter::StatementResult, ErrorOr<interpreter::StatementResult>>{
auto&& __jakt_match_variant = *((((arguments)[static_cast<i64>(0LL)])).impl);
switch(__jakt_match_variant.index()) {
case 12: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::USize>();
size_t const& capacity = __jakt_match_value.value;
return JaktInternal::ExplicitValue(({ Optional<interpreter::StatementResult> __jakt_var_191; {
JaktInternal::DynamicArray<types::Value> mutable_values = values;
TRY((((mutable_values).ensure_capacity(capacity))));
__jakt_var_191 =  interpreter::StatementResult { typename interpreter::StatementResult::JustValue(types::Value(TRY((types::ValueImpl::template create<typename types::ValueImpl::Void>())),call_span)) } ; goto __jakt_label_188;

}
__jakt_label_188:; __jakt_var_191.release_value(); }));
};/*case end*/
default: {
{
TRY((((*this).error(Jakt::DeprecatedString("Array::ensure_capacity must be called with a usize"sv),((((arguments)[static_cast<i64>(0LL)])).span)))));
return Error::from_errno((infallible_integer_cast<i32>((interpreter::InterpretError::InvalidType))));
}
};/*case end*/
}/*switch end*/
}()
)));
};/*case end*/
default: {
{
utility::panic(Jakt::DeprecatedString("Invalid use of Array::ensure_capacity()"sv));
}
};/*case end*/
}/*switch end*/
}()
)));
}
else if (__jakt_enum_value == Jakt::DeprecatedString("add_capacity"sv)) {
return JaktInternal::ExplicitValue(JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<interpreter::StatementResult, ErrorOr<interpreter::StatementResult>>{
auto&& __jakt_match_variant = *(((this_argument.value())).impl);
switch(__jakt_match_variant.index()) {
case 20: {
auto&& __jakt_match_value = __jakt_match_variant.template get<types::ValueImpl::JaktArray>();JaktInternal::DynamicArray<types::Value> const& values = __jakt_match_value.values;
return JaktInternal::ExplicitValue(JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<interpreter::StatementResult, ErrorOr<interpreter::StatementResult>>{
auto&& __jakt_match_variant = *((((arguments)[static_cast<i64>(0LL)])).impl);
switch(__jakt_match_variant.index()) {
case 12: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::USize>();
size_t const& capacity = __jakt_match_value.value;
return JaktInternal::ExplicitValue(({ Optional<interpreter::StatementResult> __jakt_var_192; {
JaktInternal::DynamicArray<types::Value> mutable_values = values;
TRY((((mutable_values).add_capacity(capacity))));
__jakt_var_192 =  interpreter::StatementResult { typename interpreter::StatementResult::JustValue(types::Value(TRY((types::ValueImpl::template create<typename types::ValueImpl::Void>())),call_span)) } ; goto __jakt_label_189;

}
__jakt_label_189:; __jakt_var_192.release_value(); }));
};/*case end*/
default: {
{
TRY((((*this).error(Jakt::DeprecatedString("Array::add_capacity must be called with a usize"sv),((((arguments)[static_cast<i64>(0LL)])).span)))));
return Error::from_errno((infallible_integer_cast<i32>((interpreter::InterpretError::InvalidType))));
}
};/*case end*/
}/*switch end*/
}()
)));
};/*case end*/
default: {
{
utility::panic(Jakt::DeprecatedString("Invalid use of Array::add_capacity()"sv));
}
};/*case end*/
}/*switch end*/
}()
)));
}
else if (__jakt_enum_value == Jakt::DeprecatedString("shrink"sv)) {
return JaktInternal::ExplicitValue(JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<interpreter::StatementResult, ErrorOr<interpreter::StatementResult>>{
auto&& __jakt_match_variant = *(((this_argument.value())).impl);
switch(__jakt_match_variant.index()) {
case 20: {
auto&& __jakt_match_value = __jakt_match_variant.template get<types::ValueImpl::JaktArray>();JaktInternal::DynamicArray<types::Value> const& values = __jakt_match_value.values;
return JaktInternal::ExplicitValue(JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<interpreter::StatementResult, ErrorOr<interpreter::StatementResult>>{
auto&& __jakt_match_variant = *((((arguments)[static_cast<i64>(0LL)])).impl);
switch(__jakt_match_variant.index()) {
case 12: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::USize>();
size_t const& size = __jakt_match_value.value;
return JaktInternal::ExplicitValue(({ Optional<interpreter::StatementResult> __jakt_var_193; {
JaktInternal::DynamicArray<types::Value> mutable_values = values;
((mutable_values).shrink(size));
__jakt_var_193 =  interpreter::StatementResult { typename interpreter::StatementResult::JustValue(types::Value(TRY((types::ValueImpl::template create<typename types::ValueImpl::Void>())),call_span)) } ; goto __jakt_label_190;

}
__jakt_label_190:; __jakt_var_193.release_value(); }));
};/*case end*/
default: {
{
TRY((((*this).error(Jakt::DeprecatedString("Array::shrink must be called with a usize"sv),((((arguments)[static_cast<i64>(0LL)])).span)))));
return Error::from_errno((infallible_integer_cast<i32>((interpreter::InterpretError::InvalidType))));
}
};/*case end*/
}/*switch end*/
}()
)));
};/*case end*/
default: {
{
utility::panic(Jakt::DeprecatedString("Invalid use of Array::shrink()"sv));
}
};/*case end*/
}/*switch end*/
}()
)));
}
else {
{
TRY((((*this).error(TRY((__jakt_format(Jakt::DeprecatedString("Prelude function `Array::{}` is not implemented"sv),prelude_function))),call_span))));
return Error::from_errno((infallible_integer_cast<i32>((interpreter::InterpretError::Unimplemented))));
}
}
}()))
);
}
else if (__jakt_enum_value == Jakt::DeprecatedString("ArrayIterator"sv)) {
return JaktInternal::ExplicitValue(JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<interpreter::StatementResult,ErrorOr<interpreter::StatementResult>>{
auto __jakt_enum_value = (prelude_function);
if (__jakt_enum_value == Jakt::DeprecatedString("next"sv)) {
return JaktInternal::ExplicitValue(JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<interpreter::StatementResult, ErrorOr<interpreter::StatementResult>>{
auto&& __jakt_match_variant = *(((this_argument.value())).impl);
switch(__jakt_match_variant.index()) {
case 17: {
auto&& __jakt_match_value = __jakt_match_variant.template get<types::ValueImpl::Struct>();JaktInternal::DynamicArray<types::Value> const& fields = __jakt_match_value.fields;
return JaktInternal::ExplicitValue(({ Optional<interpreter::StatementResult> __jakt_var_194; {
size_t const index = JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<size_t, ErrorOr<interpreter::StatementResult>>{
auto&& __jakt_match_variant = *((((fields)[static_cast<i64>(1LL)])).impl);
switch(__jakt_match_variant.index()) {
case 12: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::USize>();
size_t const& value = __jakt_match_value.value;
return JaktInternal::ExplicitValue(value);
};/*case end*/
default: {
{
utility::panic(Jakt::DeprecatedString("Invalid ArrayIterator index configuration"sv));
}
};/*case end*/
}/*switch end*/
}()
));
JaktInternal::DynamicArray<types::Value> mutable_fields = fields;
__jakt_var_194 =  interpreter::StatementResult { typename interpreter::StatementResult::JustValue(JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<types::Value, ErrorOr<interpreter::StatementResult>>{
auto&& __jakt_match_variant = *((((fields)[static_cast<i64>(0LL)])).impl);
switch(__jakt_match_variant.index()) {
case 20: {
auto&& __jakt_match_value = __jakt_match_variant.template get<types::ValueImpl::JaktArray>();JaktInternal::DynamicArray<types::Value> const& values = __jakt_match_value.values;
return JaktInternal::ExplicitValue(JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<types::Value,ErrorOr<interpreter::StatementResult>>{
auto __jakt_enum_value = ((((values).size()) > index));
if (__jakt_enum_value == true) {
return JaktInternal::ExplicitValue(({ Optional<types::Value> __jakt_var_195; {
(((mutable_fields)[static_cast<i64>(1LL)]) = types::Value(TRY((types::ValueImpl::template create<typename types::ValueImpl::USize>((JaktInternal::checked_add<size_t>(index,static_cast<size_t>(1ULL)))))),call_span));
__jakt_var_195 = types::Value(TRY((types::ValueImpl::template create<typename types::ValueImpl::OptionalSome>(((values)[index])))),call_span); goto __jakt_label_192;

}
__jakt_label_192:; __jakt_var_195.release_value(); }));
}
else {
return JaktInternal::ExplicitValue(types::Value(TRY((types::ValueImpl::template create<typename types::ValueImpl::OptionalNone>())),call_span));
}
}()))
);
};/*case end*/
default: {
{
utility::panic(Jakt::DeprecatedString("Invalid ArrayIterator configuration"sv));
}
};/*case end*/
}/*switch end*/
}()
))) } ; goto __jakt_label_191;

}
__jakt_label_191:; __jakt_var_194.release_value(); }));
};/*case end*/
default: {
{
utility::panic(Jakt::DeprecatedString("Invalid ArrayIterator configuration"sv));
}
};/*case end*/
}/*switch end*/
}()
)));
}
else {
{
TRY((((*this).error(TRY((__jakt_format(Jakt::DeprecatedString("Prelude function `ArrayIterator::{}` is not implemented"sv),prelude_function))),call_span))));
return Error::from_errno((infallible_integer_cast<i32>((interpreter::InterpretError::Unimplemented))));
}
}
}()))
);
}
else if (__jakt_enum_value == Jakt::DeprecatedString("Range"sv)) {
return JaktInternal::ExplicitValue(JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<interpreter::StatementResult,ErrorOr<interpreter::StatementResult>>{
auto __jakt_enum_value = (prelude_function);
if (__jakt_enum_value == Jakt::DeprecatedString("next"sv)) {
return JaktInternal::ExplicitValue(({ Optional<interpreter::StatementResult> __jakt_var_196; {
JaktInternal::DynamicArray<types::Value> fields = JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<JaktInternal::DynamicArray<types::Value>, ErrorOr<interpreter::StatementResult>>{
auto&& __jakt_match_variant = *(((this_argument.value())).impl);
switch(__jakt_match_variant.index()) {
case 17: {
auto&& __jakt_match_value = __jakt_match_variant.template get<types::ValueImpl::Struct>();JaktInternal::DynamicArray<types::Value> const& fields = __jakt_match_value.fields;
return JaktInternal::ExplicitValue(fields);
};/*case end*/
default: {
{
utility::panic(Jakt::DeprecatedString("Invalid use of Range::next()"sv));
}
};/*case end*/
}/*switch end*/
}()
));
u64 const start = JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<u64, ErrorOr<interpreter::StatementResult>>{
auto&& __jakt_match_variant = *((((fields)[static_cast<i64>(0LL)])).impl);
switch(__jakt_match_variant.index()) {
case 6: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::I8>();
i8 const& x = __jakt_match_value.value;
return JaktInternal::ExplicitValue((infallible_integer_cast<u64>((x))));
};/*case end*/
case 7: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::I16>();
i16 const& x = __jakt_match_value.value;
return JaktInternal::ExplicitValue((infallible_integer_cast<u64>((x))));
};/*case end*/
case 8: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::I32>();
i32 const& x = __jakt_match_value.value;
return JaktInternal::ExplicitValue((infallible_integer_cast<u64>((x))));
};/*case end*/
case 9: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::I64>();
i64 const& x = __jakt_match_value.value;
return JaktInternal::ExplicitValue((infallible_integer_cast<u64>((x))));
};/*case end*/
case 2: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::U8>();
u8 const& x = __jakt_match_value.value;
return JaktInternal::ExplicitValue((infallible_integer_cast<u64>((x))));
};/*case end*/
case 3: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::U16>();
u16 const& x = __jakt_match_value.value;
return JaktInternal::ExplicitValue((infallible_integer_cast<u64>((x))));
};/*case end*/
case 4: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::U32>();
u32 const& x = __jakt_match_value.value;
return JaktInternal::ExplicitValue((infallible_integer_cast<u64>((x))));
};/*case end*/
case 5: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::U64>();
u64 const& x = __jakt_match_value.value;
return JaktInternal::ExplicitValue((infallible_integer_cast<u64>((x))));
};/*case end*/
case 12: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::USize>();
size_t const& x = __jakt_match_value.value;
return JaktInternal::ExplicitValue((infallible_integer_cast<u64>((x))));
};/*case end*/
default: {
{
utility::panic(Jakt::DeprecatedString("Invalid type for comptime range"sv));
}
};/*case end*/
}/*switch end*/
}()
));
u64 const end = JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<u64, ErrorOr<interpreter::StatementResult>>{
auto&& __jakt_match_variant = *((((fields)[static_cast<i64>(1LL)])).impl);
switch(__jakt_match_variant.index()) {
case 6: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::I8>();
i8 const& x = __jakt_match_value.value;
return JaktInternal::ExplicitValue((infallible_integer_cast<u64>((x))));
};/*case end*/
case 7: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::I16>();
i16 const& x = __jakt_match_value.value;
return JaktInternal::ExplicitValue((infallible_integer_cast<u64>((x))));
};/*case end*/
case 8: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::I32>();
i32 const& x = __jakt_match_value.value;
return JaktInternal::ExplicitValue((infallible_integer_cast<u64>((x))));
};/*case end*/
case 9: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::I64>();
i64 const& x = __jakt_match_value.value;
return JaktInternal::ExplicitValue((infallible_integer_cast<u64>((x))));
};/*case end*/
case 2: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::U8>();
u8 const& x = __jakt_match_value.value;
return JaktInternal::ExplicitValue((infallible_integer_cast<u64>((x))));
};/*case end*/
case 3: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::U16>();
u16 const& x = __jakt_match_value.value;
return JaktInternal::ExplicitValue((infallible_integer_cast<u64>((x))));
};/*case end*/
case 4: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::U32>();
u32 const& x = __jakt_match_value.value;
return JaktInternal::ExplicitValue((infallible_integer_cast<u64>((x))));
};/*case end*/
case 5: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::U64>();
u64 const& x = __jakt_match_value.value;
return JaktInternal::ExplicitValue((infallible_integer_cast<u64>((x))));
};/*case end*/
case 12: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::USize>();
size_t const& x = __jakt_match_value.value;
return JaktInternal::ExplicitValue((infallible_integer_cast<u64>((x))));
};/*case end*/
default: {
{
utility::panic(Jakt::DeprecatedString("Invalid type for comptime range"sv));
}
};/*case end*/
}/*switch end*/
}()
));
if ((start == end)){
return ( interpreter::StatementResult { typename interpreter::StatementResult::JustValue(types::Value(TRY((types::ValueImpl::template create<typename types::ValueImpl::OptionalNone>())),call_span)) } );
}
if ((start > end)){
(((fields)[static_cast<i64>(0LL)]) = types::Value(TRY((types::ValueImpl::template create<typename types::ValueImpl::U64>((JaktInternal::checked_sub<u64>(start,static_cast<u64>(1ULL)))))),call_span));
}
else {
(((fields)[static_cast<i64>(0LL)]) = types::Value(TRY((types::ValueImpl::template create<typename types::ValueImpl::U64>((JaktInternal::checked_add<u64>(start,static_cast<u64>(1ULL)))))),call_span));
}

__jakt_var_196 =  interpreter::StatementResult { typename interpreter::StatementResult::JustValue(types::Value(TRY((types::ValueImpl::template create<typename types::ValueImpl::OptionalSome>(types::Value(TRY((types::ValueImpl::template create<typename types::ValueImpl::U64>(start))),call_span)))),call_span)) } ; goto __jakt_label_193;

}
__jakt_label_193:; __jakt_var_196.release_value(); }));
}
else if (__jakt_enum_value == Jakt::DeprecatedString("inclusive"sv)) {
return JaktInternal::ExplicitValue(JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<interpreter::StatementResult, ErrorOr<interpreter::StatementResult>>{
auto&& __jakt_match_variant = *(((this_argument.value())).impl);
switch(__jakt_match_variant.index()) {
case 17: {
auto&& __jakt_match_value = __jakt_match_variant.template get<types::ValueImpl::Struct>();JaktInternal::DynamicArray<types::Value> const& fields = __jakt_match_value.fields;
types::StructId const& struct_id = __jakt_match_value.struct_id;
JaktInternal::Optional<types::FunctionId> const& constructor = __jakt_match_value.constructor;
return JaktInternal::ExplicitValue(({ Optional<interpreter::StatementResult> __jakt_var_197; {
JaktInternal::DynamicArray<types::Value> mutable_fields = fields;
u64 const end = JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<u64, ErrorOr<interpreter::StatementResult>>{
auto&& __jakt_match_variant = *((((fields)[static_cast<i64>(1LL)])).impl);
switch(__jakt_match_variant.index()) {
case 6: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::I8>();
i8 const& x = __jakt_match_value.value;
return JaktInternal::ExplicitValue((infallible_integer_cast<u64>((x))));
};/*case end*/
case 7: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::I16>();
i16 const& x = __jakt_match_value.value;
return JaktInternal::ExplicitValue((infallible_integer_cast<u64>((x))));
};/*case end*/
case 8: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::I32>();
i32 const& x = __jakt_match_value.value;
return JaktInternal::ExplicitValue((infallible_integer_cast<u64>((x))));
};/*case end*/
case 9: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::I64>();
i64 const& x = __jakt_match_value.value;
return JaktInternal::ExplicitValue((infallible_integer_cast<u64>((x))));
};/*case end*/
case 2: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::U8>();
u8 const& x = __jakt_match_value.value;
return JaktInternal::ExplicitValue((infallible_integer_cast<u64>((x))));
};/*case end*/
case 3: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::U16>();
u16 const& x = __jakt_match_value.value;
return JaktInternal::ExplicitValue((infallible_integer_cast<u64>((x))));
};/*case end*/
case 4: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::U32>();
u32 const& x = __jakt_match_value.value;
return JaktInternal::ExplicitValue((infallible_integer_cast<u64>((x))));
};/*case end*/
case 5: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::U64>();
u64 const& x = __jakt_match_value.value;
return JaktInternal::ExplicitValue((infallible_integer_cast<u64>((x))));
};/*case end*/
case 12: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::USize>();
size_t const& x = __jakt_match_value.value;
return JaktInternal::ExplicitValue((infallible_integer_cast<u64>((x))));
};/*case end*/
default: {
{
utility::panic(Jakt::DeprecatedString("Invalid type for comptime range"sv));
}
};/*case end*/
}/*switch end*/
}()
));
(((((mutable_fields)[static_cast<i64>(1LL)])).impl) = TRY((types::ValueImpl::template create<typename types::ValueImpl::U64>((JaktInternal::checked_add<u64>(end,static_cast<u64>(1ULL)))))));
__jakt_var_197 =  interpreter::StatementResult { typename interpreter::StatementResult::JustValue(types::Value(TRY((types::ValueImpl::template create<typename types::ValueImpl::Struct>(fields,struct_id,constructor))),(((this_argument.value())).span))) } ; goto __jakt_label_194;

}
__jakt_label_194:; __jakt_var_197.release_value(); }));
};/*case end*/
default: {
{
utility::panic(Jakt::DeprecatedString("Invalid use of Range::inclusive()"sv));
}
};/*case end*/
}/*switch end*/
}()
)));
}
else if (__jakt_enum_value == Jakt::DeprecatedString("exclusive"sv)) {
return JaktInternal::ExplicitValue(JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<interpreter::StatementResult, ErrorOr<interpreter::StatementResult>>{
auto&& __jakt_match_variant = *(((this_argument.value())).impl);
switch(__jakt_match_variant.index()) {
case 17: {
auto&& __jakt_match_value = __jakt_match_variant.template get<types::ValueImpl::Struct>();return JaktInternal::ExplicitValue( interpreter::StatementResult { typename interpreter::StatementResult::JustValue((this_argument.value())) } );
};/*case end*/
default: {
{
utility::panic(Jakt::DeprecatedString("Invalid use of Range::exclusive()"sv));
}
};/*case end*/
}/*switch end*/
}()
)));
}
else {
{
TRY((((*this).error(TRY((__jakt_format(Jakt::DeprecatedString("Prelude function `Range::{}` is not implemented"sv),prelude_function))),call_span))));
return Error::from_errno((infallible_integer_cast<i32>((interpreter::InterpretError::Unimplemented))));
}
}
}()))
);
}
else if (__jakt_enum_value == Jakt::DeprecatedString("String"sv)) {
return JaktInternal::ExplicitValue(JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<interpreter::StatementResult,ErrorOr<interpreter::StatementResult>>{
auto __jakt_enum_value = (prelude_function);
if (__jakt_enum_value == Jakt::DeprecatedString("is_empty"sv)) {
return JaktInternal::ExplicitValue(JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<interpreter::StatementResult, ErrorOr<interpreter::StatementResult>>{
auto&& __jakt_match_variant = *(((this_argument.value())).impl);
switch(__jakt_match_variant.index()) {
case 13: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::JaktString>();
DeprecatedString const& value = __jakt_match_value.value;
return JaktInternal::ExplicitValue( interpreter::StatementResult { typename interpreter::StatementResult::JustValue(types::Value(TRY((types::ValueImpl::template create<typename types::ValueImpl::Bool>(((value).is_empty())))),call_span)) } );
};/*case end*/
default: {
{
utility::panic(Jakt::DeprecatedString("Invalid String"sv));
}
};/*case end*/
}/*switch end*/
}()
)));
}
else if (__jakt_enum_value == Jakt::DeprecatedString("length"sv)) {
return JaktInternal::ExplicitValue(JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<interpreter::StatementResult, ErrorOr<interpreter::StatementResult>>{
auto&& __jakt_match_variant = *(((this_argument.value())).impl);
switch(__jakt_match_variant.index()) {
case 13: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::JaktString>();
DeprecatedString const& value = __jakt_match_value.value;
return JaktInternal::ExplicitValue( interpreter::StatementResult { typename interpreter::StatementResult::JustValue(types::Value(TRY((types::ValueImpl::template create<typename types::ValueImpl::USize>(((value).length())))),call_span)) } );
};/*case end*/
default: {
{
utility::panic(Jakt::DeprecatedString("Invalid String"sv));
}
};/*case end*/
}/*switch end*/
}()
)));
}
else if (__jakt_enum_value == Jakt::DeprecatedString("hash"sv)) {
return JaktInternal::ExplicitValue(JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<interpreter::StatementResult, ErrorOr<interpreter::StatementResult>>{
auto&& __jakt_match_variant = *(((this_argument.value())).impl);
switch(__jakt_match_variant.index()) {
case 13: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::JaktString>();
DeprecatedString const& value = __jakt_match_value.value;
return JaktInternal::ExplicitValue( interpreter::StatementResult { typename interpreter::StatementResult::JustValue(types::Value(TRY((types::ValueImpl::template create<typename types::ValueImpl::U32>(((value).hash())))),call_span)) } );
};/*case end*/
default: {
{
utility::panic(Jakt::DeprecatedString("Invalid String"sv));
}
};/*case end*/
}/*switch end*/
}()
)));
}
else if (__jakt_enum_value == Jakt::DeprecatedString("substring"sv)) {
return JaktInternal::ExplicitValue(JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<interpreter::StatementResult, ErrorOr<interpreter::StatementResult>>{
auto&& __jakt_match_variant = *(((this_argument.value())).impl);
switch(__jakt_match_variant.index()) {
case 13: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::JaktString>();
DeprecatedString const& value = __jakt_match_value.value;
return JaktInternal::ExplicitValue(JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<interpreter::StatementResult, ErrorOr<interpreter::StatementResult>>{
auto&& __jakt_match_variant = *((((arguments)[static_cast<i64>(0LL)])).impl);
switch(__jakt_match_variant.index()) {
case 12: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::USize>();
size_t const& start = __jakt_match_value.value;
return JaktInternal::ExplicitValue(JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<interpreter::StatementResult, ErrorOr<interpreter::StatementResult>>{
auto&& __jakt_match_variant = *((((arguments)[static_cast<i64>(1LL)])).impl);
switch(__jakt_match_variant.index()) {
case 12: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::USize>();
size_t const& length = __jakt_match_value.value;
return JaktInternal::ExplicitValue(({ Optional<interpreter::StatementResult> __jakt_var_198; {
DeprecatedString const result = ((value).substring((infallible_integer_cast<size_t>((start))),(infallible_integer_cast<size_t>((length)))));
__jakt_var_198 =  interpreter::StatementResult { typename interpreter::StatementResult::JustValue(types::Value(TRY((types::ValueImpl::template create<typename types::ValueImpl::JaktString>(result))),call_span)) } ; goto __jakt_label_195;

}
__jakt_label_195:; __jakt_var_198.release_value(); }));
};/*case end*/
case 5: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::U64>();
u64 const& length = __jakt_match_value.value;
return JaktInternal::ExplicitValue(({ Optional<interpreter::StatementResult> __jakt_var_199; {
DeprecatedString const result = ((value).substring((infallible_integer_cast<size_t>((start))),(infallible_integer_cast<size_t>((length)))));
__jakt_var_199 =  interpreter::StatementResult { typename interpreter::StatementResult::JustValue(types::Value(TRY((types::ValueImpl::template create<typename types::ValueImpl::JaktString>(result))),call_span)) } ; goto __jakt_label_196;

}
__jakt_label_196:; __jakt_var_199.release_value(); }));
};/*case end*/
case 4: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::U32>();
u32 const& length = __jakt_match_value.value;
return JaktInternal::ExplicitValue(({ Optional<interpreter::StatementResult> __jakt_var_200; {
DeprecatedString const result = ((value).substring((infallible_integer_cast<size_t>((start))),(infallible_integer_cast<size_t>((length)))));
__jakt_var_200 =  interpreter::StatementResult { typename interpreter::StatementResult::JustValue(types::Value(TRY((types::ValueImpl::template create<typename types::ValueImpl::JaktString>(result))),call_span)) } ; goto __jakt_label_197;

}
__jakt_label_197:; __jakt_var_200.release_value(); }));
};/*case end*/
case 3: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::U16>();
u16 const& length = __jakt_match_value.value;
return JaktInternal::ExplicitValue(({ Optional<interpreter::StatementResult> __jakt_var_201; {
DeprecatedString const result = ((value).substring((infallible_integer_cast<size_t>((start))),(infallible_integer_cast<size_t>((length)))));
__jakt_var_201 =  interpreter::StatementResult { typename interpreter::StatementResult::JustValue(types::Value(TRY((types::ValueImpl::template create<typename types::ValueImpl::JaktString>(result))),call_span)) } ; goto __jakt_label_198;

}
__jakt_label_198:; __jakt_var_201.release_value(); }));
};/*case end*/
case 2: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::U8>();
u8 const& length = __jakt_match_value.value;
return JaktInternal::ExplicitValue(({ Optional<interpreter::StatementResult> __jakt_var_202; {
DeprecatedString const result = ((value).substring((infallible_integer_cast<size_t>((start))),(infallible_integer_cast<size_t>((length)))));
__jakt_var_202 =  interpreter::StatementResult { typename interpreter::StatementResult::JustValue(types::Value(TRY((types::ValueImpl::template create<typename types::ValueImpl::JaktString>(result))),call_span)) } ; goto __jakt_label_199;

}
__jakt_label_199:; __jakt_var_202.release_value(); }));
};/*case end*/
default: {
{
TRY((((*this).error(Jakt::DeprecatedString("String::substring must be called with unsigned arguments"sv),((((arguments)[static_cast<i64>(1LL)])).span)))));
return Error::from_errno((infallible_integer_cast<i32>((interpreter::InterpretError::InvalidType))));
}
};/*case end*/
}/*switch end*/
}()
)));
};/*case end*/
case 5: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::U64>();
u64 const& start = __jakt_match_value.value;
return JaktInternal::ExplicitValue(JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<interpreter::StatementResult, ErrorOr<interpreter::StatementResult>>{
auto&& __jakt_match_variant = *((((arguments)[static_cast<i64>(1LL)])).impl);
switch(__jakt_match_variant.index()) {
case 12: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::USize>();
size_t const& length = __jakt_match_value.value;
return JaktInternal::ExplicitValue(({ Optional<interpreter::StatementResult> __jakt_var_203; {
DeprecatedString const result = ((value).substring((infallible_integer_cast<size_t>((start))),(infallible_integer_cast<size_t>((length)))));
__jakt_var_203 =  interpreter::StatementResult { typename interpreter::StatementResult::JustValue(types::Value(TRY((types::ValueImpl::template create<typename types::ValueImpl::JaktString>(result))),call_span)) } ; goto __jakt_label_200;

}
__jakt_label_200:; __jakt_var_203.release_value(); }));
};/*case end*/
case 5: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::U64>();
u64 const& length = __jakt_match_value.value;
return JaktInternal::ExplicitValue(({ Optional<interpreter::StatementResult> __jakt_var_204; {
DeprecatedString const result = ((value).substring((infallible_integer_cast<size_t>((start))),(infallible_integer_cast<size_t>((length)))));
__jakt_var_204 =  interpreter::StatementResult { typename interpreter::StatementResult::JustValue(types::Value(TRY((types::ValueImpl::template create<typename types::ValueImpl::JaktString>(result))),call_span)) } ; goto __jakt_label_201;

}
__jakt_label_201:; __jakt_var_204.release_value(); }));
};/*case end*/
case 4: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::U32>();
u32 const& length = __jakt_match_value.value;
return JaktInternal::ExplicitValue(({ Optional<interpreter::StatementResult> __jakt_var_205; {
DeprecatedString const result = ((value).substring((infallible_integer_cast<size_t>((start))),(infallible_integer_cast<size_t>((length)))));
__jakt_var_205 =  interpreter::StatementResult { typename interpreter::StatementResult::JustValue(types::Value(TRY((types::ValueImpl::template create<typename types::ValueImpl::JaktString>(result))),call_span)) } ; goto __jakt_label_202;

}
__jakt_label_202:; __jakt_var_205.release_value(); }));
};/*case end*/
case 3: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::U16>();
u16 const& length = __jakt_match_value.value;
return JaktInternal::ExplicitValue(({ Optional<interpreter::StatementResult> __jakt_var_206; {
DeprecatedString const result = ((value).substring((infallible_integer_cast<size_t>((start))),(infallible_integer_cast<size_t>((length)))));
__jakt_var_206 =  interpreter::StatementResult { typename interpreter::StatementResult::JustValue(types::Value(TRY((types::ValueImpl::template create<typename types::ValueImpl::JaktString>(result))),call_span)) } ; goto __jakt_label_203;

}
__jakt_label_203:; __jakt_var_206.release_value(); }));
};/*case end*/
case 2: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::U8>();
u8 const& length = __jakt_match_value.value;
return JaktInternal::ExplicitValue(({ Optional<interpreter::StatementResult> __jakt_var_207; {
DeprecatedString const result = ((value).substring((infallible_integer_cast<size_t>((start))),(infallible_integer_cast<size_t>((length)))));
__jakt_var_207 =  interpreter::StatementResult { typename interpreter::StatementResult::JustValue(types::Value(TRY((types::ValueImpl::template create<typename types::ValueImpl::JaktString>(result))),call_span)) } ; goto __jakt_label_204;

}
__jakt_label_204:; __jakt_var_207.release_value(); }));
};/*case end*/
default: {
{
TRY((((*this).error(Jakt::DeprecatedString("String::substring must be called with unsigned arguments"sv),((((arguments)[static_cast<i64>(1LL)])).span)))));
return Error::from_errno((infallible_integer_cast<i32>((interpreter::InterpretError::InvalidType))));
}
};/*case end*/
}/*switch end*/
}()
)));
};/*case end*/
case 4: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::U32>();
u32 const& start = __jakt_match_value.value;
return JaktInternal::ExplicitValue(JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<interpreter::StatementResult, ErrorOr<interpreter::StatementResult>>{
auto&& __jakt_match_variant = *((((arguments)[static_cast<i64>(1LL)])).impl);
switch(__jakt_match_variant.index()) {
case 12: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::USize>();
size_t const& length = __jakt_match_value.value;
return JaktInternal::ExplicitValue(({ Optional<interpreter::StatementResult> __jakt_var_208; {
DeprecatedString const result = ((value).substring((infallible_integer_cast<size_t>((start))),(infallible_integer_cast<size_t>((length)))));
__jakt_var_208 =  interpreter::StatementResult { typename interpreter::StatementResult::JustValue(types::Value(TRY((types::ValueImpl::template create<typename types::ValueImpl::JaktString>(result))),call_span)) } ; goto __jakt_label_205;

}
__jakt_label_205:; __jakt_var_208.release_value(); }));
};/*case end*/
case 5: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::U64>();
u64 const& length = __jakt_match_value.value;
return JaktInternal::ExplicitValue(({ Optional<interpreter::StatementResult> __jakt_var_209; {
DeprecatedString const result = ((value).substring((infallible_integer_cast<size_t>((start))),(infallible_integer_cast<size_t>((length)))));
__jakt_var_209 =  interpreter::StatementResult { typename interpreter::StatementResult::JustValue(types::Value(TRY((types::ValueImpl::template create<typename types::ValueImpl::JaktString>(result))),call_span)) } ; goto __jakt_label_206;

}
__jakt_label_206:; __jakt_var_209.release_value(); }));
};/*case end*/
case 4: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::U32>();
u32 const& length = __jakt_match_value.value;
return JaktInternal::ExplicitValue(({ Optional<interpreter::StatementResult> __jakt_var_210; {
DeprecatedString const result = ((value).substring((infallible_integer_cast<size_t>((start))),(infallible_integer_cast<size_t>((length)))));
__jakt_var_210 =  interpreter::StatementResult { typename interpreter::StatementResult::JustValue(types::Value(TRY((types::ValueImpl::template create<typename types::ValueImpl::JaktString>(result))),call_span)) } ; goto __jakt_label_207;

}
__jakt_label_207:; __jakt_var_210.release_value(); }));
};/*case end*/
case 3: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::U16>();
u16 const& length = __jakt_match_value.value;
return JaktInternal::ExplicitValue(({ Optional<interpreter::StatementResult> __jakt_var_211; {
DeprecatedString const result = ((value).substring((infallible_integer_cast<size_t>((start))),(infallible_integer_cast<size_t>((length)))));
__jakt_var_211 =  interpreter::StatementResult { typename interpreter::StatementResult::JustValue(types::Value(TRY((types::ValueImpl::template create<typename types::ValueImpl::JaktString>(result))),call_span)) } ; goto __jakt_label_208;

}
__jakt_label_208:; __jakt_var_211.release_value(); }));
};/*case end*/
case 2: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::U8>();
u8 const& length = __jakt_match_value.value;
return JaktInternal::ExplicitValue(({ Optional<interpreter::StatementResult> __jakt_var_212; {
DeprecatedString const result = ((value).substring((infallible_integer_cast<size_t>((start))),(infallible_integer_cast<size_t>((length)))));
__jakt_var_212 =  interpreter::StatementResult { typename interpreter::StatementResult::JustValue(types::Value(TRY((types::ValueImpl::template create<typename types::ValueImpl::JaktString>(result))),call_span)) } ; goto __jakt_label_209;

}
__jakt_label_209:; __jakt_var_212.release_value(); }));
};/*case end*/
default: {
{
TRY((((*this).error(Jakt::DeprecatedString("String::substring must be called with unsigned arguments"sv),((((arguments)[static_cast<i64>(1LL)])).span)))));
return Error::from_errno((infallible_integer_cast<i32>((interpreter::InterpretError::InvalidType))));
}
};/*case end*/
}/*switch end*/
}()
)));
};/*case end*/
case 3: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::U16>();
u16 const& start = __jakt_match_value.value;
return JaktInternal::ExplicitValue(JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<interpreter::StatementResult, ErrorOr<interpreter::StatementResult>>{
auto&& __jakt_match_variant = *((((arguments)[static_cast<i64>(1LL)])).impl);
switch(__jakt_match_variant.index()) {
case 12: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::USize>();
size_t const& length = __jakt_match_value.value;
return JaktInternal::ExplicitValue(({ Optional<interpreter::StatementResult> __jakt_var_213; {
DeprecatedString const result = ((value).substring((infallible_integer_cast<size_t>((start))),(infallible_integer_cast<size_t>((length)))));
__jakt_var_213 =  interpreter::StatementResult { typename interpreter::StatementResult::JustValue(types::Value(TRY((types::ValueImpl::template create<typename types::ValueImpl::JaktString>(result))),call_span)) } ; goto __jakt_label_210;

}
__jakt_label_210:; __jakt_var_213.release_value(); }));
};/*case end*/
case 5: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::U64>();
u64 const& length = __jakt_match_value.value;
return JaktInternal::ExplicitValue(({ Optional<interpreter::StatementResult> __jakt_var_214; {
DeprecatedString const result = ((value).substring((infallible_integer_cast<size_t>((start))),(infallible_integer_cast<size_t>((length)))));
__jakt_var_214 =  interpreter::StatementResult { typename interpreter::StatementResult::JustValue(types::Value(TRY((types::ValueImpl::template create<typename types::ValueImpl::JaktString>(result))),call_span)) } ; goto __jakt_label_211;

}
__jakt_label_211:; __jakt_var_214.release_value(); }));
};/*case end*/
case 4: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::U32>();
u32 const& length = __jakt_match_value.value;
return JaktInternal::ExplicitValue(({ Optional<interpreter::StatementResult> __jakt_var_215; {
DeprecatedString const result = ((value).substring((infallible_integer_cast<size_t>((start))),(infallible_integer_cast<size_t>((length)))));
__jakt_var_215 =  interpreter::StatementResult { typename interpreter::StatementResult::JustValue(types::Value(TRY((types::ValueImpl::template create<typename types::ValueImpl::JaktString>(result))),call_span)) } ; goto __jakt_label_212;

}
__jakt_label_212:; __jakt_var_215.release_value(); }));
};/*case end*/
case 3: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::U16>();
u16 const& length = __jakt_match_value.value;
return JaktInternal::ExplicitValue(({ Optional<interpreter::StatementResult> __jakt_var_216; {
DeprecatedString const result = ((value).substring((infallible_integer_cast<size_t>((start))),(infallible_integer_cast<size_t>((length)))));
__jakt_var_216 =  interpreter::StatementResult { typename interpreter::StatementResult::JustValue(types::Value(TRY((types::ValueImpl::template create<typename types::ValueImpl::JaktString>(result))),call_span)) } ; goto __jakt_label_213;

}
__jakt_label_213:; __jakt_var_216.release_value(); }));
};/*case end*/
case 2: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::U8>();
u8 const& length = __jakt_match_value.value;
return JaktInternal::ExplicitValue(({ Optional<interpreter::StatementResult> __jakt_var_217; {
DeprecatedString const result = ((value).substring((infallible_integer_cast<size_t>((start))),(infallible_integer_cast<size_t>((length)))));
__jakt_var_217 =  interpreter::StatementResult { typename interpreter::StatementResult::JustValue(types::Value(TRY((types::ValueImpl::template create<typename types::ValueImpl::JaktString>(result))),call_span)) } ; goto __jakt_label_214;

}
__jakt_label_214:; __jakt_var_217.release_value(); }));
};/*case end*/
default: {
{
TRY((((*this).error(Jakt::DeprecatedString("String::substring must be called with unsigned arguments"sv),((((arguments)[static_cast<i64>(1LL)])).span)))));
return Error::from_errno((infallible_integer_cast<i32>((interpreter::InterpretError::InvalidType))));
}
};/*case end*/
}/*switch end*/
}()
)));
};/*case end*/
case 2: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::U8>();
u8 const& start = __jakt_match_value.value;
return JaktInternal::ExplicitValue(JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<interpreter::StatementResult, ErrorOr<interpreter::StatementResult>>{
auto&& __jakt_match_variant = *((((arguments)[static_cast<i64>(1LL)])).impl);
switch(__jakt_match_variant.index()) {
case 12: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::USize>();
size_t const& length = __jakt_match_value.value;
return JaktInternal::ExplicitValue(({ Optional<interpreter::StatementResult> __jakt_var_218; {
DeprecatedString const result = ((value).substring((infallible_integer_cast<size_t>((start))),(infallible_integer_cast<size_t>((length)))));
__jakt_var_218 =  interpreter::StatementResult { typename interpreter::StatementResult::JustValue(types::Value(TRY((types::ValueImpl::template create<typename types::ValueImpl::JaktString>(result))),call_span)) } ; goto __jakt_label_215;

}
__jakt_label_215:; __jakt_var_218.release_value(); }));
};/*case end*/
case 5: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::U64>();
u64 const& length = __jakt_match_value.value;
return JaktInternal::ExplicitValue(({ Optional<interpreter::StatementResult> __jakt_var_219; {
DeprecatedString const result = ((value).substring((infallible_integer_cast<size_t>((start))),(infallible_integer_cast<size_t>((length)))));
__jakt_var_219 =  interpreter::StatementResult { typename interpreter::StatementResult::JustValue(types::Value(TRY((types::ValueImpl::template create<typename types::ValueImpl::JaktString>(result))),call_span)) } ; goto __jakt_label_216;

}
__jakt_label_216:; __jakt_var_219.release_value(); }));
};/*case end*/
case 4: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::U32>();
u32 const& length = __jakt_match_value.value;
return JaktInternal::ExplicitValue(({ Optional<interpreter::StatementResult> __jakt_var_220; {
DeprecatedString const result = ((value).substring((infallible_integer_cast<size_t>((start))),(infallible_integer_cast<size_t>((length)))));
__jakt_var_220 =  interpreter::StatementResult { typename interpreter::StatementResult::JustValue(types::Value(TRY((types::ValueImpl::template create<typename types::ValueImpl::JaktString>(result))),call_span)) } ; goto __jakt_label_217;

}
__jakt_label_217:; __jakt_var_220.release_value(); }));
};/*case end*/
case 3: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::U16>();
u16 const& length = __jakt_match_value.value;
return JaktInternal::ExplicitValue(({ Optional<interpreter::StatementResult> __jakt_var_221; {
DeprecatedString const result = ((value).substring((infallible_integer_cast<size_t>((start))),(infallible_integer_cast<size_t>((length)))));
__jakt_var_221 =  interpreter::StatementResult { typename interpreter::StatementResult::JustValue(types::Value(TRY((types::ValueImpl::template create<typename types::ValueImpl::JaktString>(result))),call_span)) } ; goto __jakt_label_218;

}
__jakt_label_218:; __jakt_var_221.release_value(); }));
};/*case end*/
case 2: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::U8>();
u8 const& length = __jakt_match_value.value;
return JaktInternal::ExplicitValue(({ Optional<interpreter::StatementResult> __jakt_var_222; {
DeprecatedString const result = ((value).substring((infallible_integer_cast<size_t>((start))),(infallible_integer_cast<size_t>((length)))));
__jakt_var_222 =  interpreter::StatementResult { typename interpreter::StatementResult::JustValue(types::Value(TRY((types::ValueImpl::template create<typename types::ValueImpl::JaktString>(result))),call_span)) } ; goto __jakt_label_219;

}
__jakt_label_219:; __jakt_var_222.release_value(); }));
};/*case end*/
default: {
{
TRY((((*this).error(Jakt::DeprecatedString("String::substring must be called with unsigned arguments"sv),((((arguments)[static_cast<i64>(1LL)])).span)))));
return Error::from_errno((infallible_integer_cast<i32>((interpreter::InterpretError::InvalidType))));
}
};/*case end*/
}/*switch end*/
}()
)));
};/*case end*/
default: {
{
TRY((((*this).error(Jakt::DeprecatedString("String::substring must be called with unsigned arguments"sv),((((arguments)[static_cast<i64>(0LL)])).span)))));
return Error::from_errno((infallible_integer_cast<i32>((interpreter::InterpretError::InvalidType))));
}
};/*case end*/
}/*switch end*/
}()
)));
};/*case end*/
default: {
{
utility::panic(Jakt::DeprecatedString("Invalid String"sv));
}
};/*case end*/
}/*switch end*/
}()
)));
}
else if (__jakt_enum_value == Jakt::DeprecatedString("number"sv)) {
return JaktInternal::ExplicitValue(JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<interpreter::StatementResult, ErrorOr<interpreter::StatementResult>>{
auto&& __jakt_match_variant = *((((arguments)[static_cast<i64>(0LL)])).impl);
switch(__jakt_match_variant.index()) {
case 9: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::I64>();
i64 const& number = __jakt_match_value.value;
return JaktInternal::ExplicitValue( interpreter::StatementResult { typename interpreter::StatementResult::JustValue(types::Value(TRY((types::ValueImpl::template create<typename types::ValueImpl::JaktString>(DeprecatedString::number((infallible_integer_cast<i64>((number))))))),call_span)) } );
};/*case end*/
case 4: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::U32>();
u32 const& number = __jakt_match_value.value;
return JaktInternal::ExplicitValue( interpreter::StatementResult { typename interpreter::StatementResult::JustValue(types::Value(TRY((types::ValueImpl::template create<typename types::ValueImpl::JaktString>(DeprecatedString::number((infallible_integer_cast<i64>((number))))))),call_span)) } );
};/*case end*/
case 8: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::I32>();
i32 const& number = __jakt_match_value.value;
return JaktInternal::ExplicitValue( interpreter::StatementResult { typename interpreter::StatementResult::JustValue(types::Value(TRY((types::ValueImpl::template create<typename types::ValueImpl::JaktString>(DeprecatedString::number((infallible_integer_cast<i64>((number))))))),call_span)) } );
};/*case end*/
case 3: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::U16>();
u16 const& number = __jakt_match_value.value;
return JaktInternal::ExplicitValue( interpreter::StatementResult { typename interpreter::StatementResult::JustValue(types::Value(TRY((types::ValueImpl::template create<typename types::ValueImpl::JaktString>(DeprecatedString::number((infallible_integer_cast<i64>((number))))))),call_span)) } );
};/*case end*/
case 7: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::I16>();
i16 const& number = __jakt_match_value.value;
return JaktInternal::ExplicitValue( interpreter::StatementResult { typename interpreter::StatementResult::JustValue(types::Value(TRY((types::ValueImpl::template create<typename types::ValueImpl::JaktString>(DeprecatedString::number((infallible_integer_cast<i64>((number))))))),call_span)) } );
};/*case end*/
case 2: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::U8>();
u8 const& number = __jakt_match_value.value;
return JaktInternal::ExplicitValue( interpreter::StatementResult { typename interpreter::StatementResult::JustValue(types::Value(TRY((types::ValueImpl::template create<typename types::ValueImpl::JaktString>(DeprecatedString::number((infallible_integer_cast<i64>((number))))))),call_span)) } );
};/*case end*/
case 6: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::I8>();
i8 const& number = __jakt_match_value.value;
return JaktInternal::ExplicitValue( interpreter::StatementResult { typename interpreter::StatementResult::JustValue(types::Value(TRY((types::ValueImpl::template create<typename types::ValueImpl::JaktString>(DeprecatedString::number((infallible_integer_cast<i64>((number))))))),call_span)) } );
};/*case end*/
case 12: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::USize>();
{
TRY((((*this).error(Jakt::DeprecatedString("String::number must not be called with a usize or u64"sv),((((arguments)[static_cast<i64>(0LL)])).span)))));
return Error::from_errno((infallible_integer_cast<i32>((interpreter::InterpretError::InvalidType))));
}
};/*case end*/
case 5: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::U64>();
{
TRY((((*this).error(Jakt::DeprecatedString("String::number must not be called with a usize or u64"sv),((((arguments)[static_cast<i64>(0LL)])).span)))));
return Error::from_errno((infallible_integer_cast<i32>((interpreter::InterpretError::InvalidType))));
}
};/*case end*/
default: {
{
TRY((((*this).error(Jakt::DeprecatedString("String::number must be called with an integer"sv),((((arguments)[static_cast<i64>(0LL)])).span)))));
return Error::from_errno((infallible_integer_cast<i32>((interpreter::InterpretError::InvalidType))));
}
};/*case end*/
}/*switch end*/
}()
)));
}
else if (__jakt_enum_value == Jakt::DeprecatedString("to_uint"sv)) {
return JaktInternal::ExplicitValue(JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<interpreter::StatementResult, ErrorOr<interpreter::StatementResult>>{
auto&& __jakt_match_variant = *(((this_argument.value())).impl);
switch(__jakt_match_variant.index()) {
case 13: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::JaktString>();
DeprecatedString const& value = __jakt_match_value.value;
return JaktInternal::ExplicitValue(({ Optional<interpreter::StatementResult> __jakt_var_223; {
JaktInternal::Optional<u32> const result = ((value).to_uint());
__jakt_var_223 =  interpreter::StatementResult { typename interpreter::StatementResult::JustValue(types::Value(JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<NonnullRefPtr<typename types::ValueImpl>,ErrorOr<interpreter::StatementResult>>{
auto __jakt_enum_value = (((result).has_value()));
if (__jakt_enum_value == true) {
return JaktInternal::ExplicitValue(TRY((types::ValueImpl::template create<typename types::ValueImpl::OptionalSome>(types::Value(TRY((types::ValueImpl::template create<typename types::ValueImpl::U32>((result.value())))),call_span)))));
}
else {
return JaktInternal::ExplicitValue(TRY((types::ValueImpl::template create<typename types::ValueImpl::OptionalNone>())));
}
}()))
,call_span)) } ; goto __jakt_label_220;

}
__jakt_label_220:; __jakt_var_223.release_value(); }));
};/*case end*/
default: {
{
utility::panic(Jakt::DeprecatedString("Invalid String"sv));
}
};/*case end*/
}/*switch end*/
}()
)));
}
else if (__jakt_enum_value == Jakt::DeprecatedString("to_int"sv)) {
return JaktInternal::ExplicitValue(JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<interpreter::StatementResult, ErrorOr<interpreter::StatementResult>>{
auto&& __jakt_match_variant = *(((this_argument.value())).impl);
switch(__jakt_match_variant.index()) {
case 13: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::JaktString>();
DeprecatedString const& value = __jakt_match_value.value;
return JaktInternal::ExplicitValue(({ Optional<interpreter::StatementResult> __jakt_var_224; {
JaktInternal::Optional<i32> const result = ((value).to_int());
__jakt_var_224 =  interpreter::StatementResult { typename interpreter::StatementResult::JustValue(types::Value(JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<NonnullRefPtr<typename types::ValueImpl>,ErrorOr<interpreter::StatementResult>>{
auto __jakt_enum_value = (((result).has_value()));
if (__jakt_enum_value == true) {
return JaktInternal::ExplicitValue(TRY((types::ValueImpl::template create<typename types::ValueImpl::OptionalSome>(types::Value(TRY((types::ValueImpl::template create<typename types::ValueImpl::I32>((result.value())))),call_span)))));
}
else {
return JaktInternal::ExplicitValue(TRY((types::ValueImpl::template create<typename types::ValueImpl::OptionalNone>())));
}
}()))
,call_span)) } ; goto __jakt_label_221;

}
__jakt_label_221:; __jakt_var_224.release_value(); }));
};/*case end*/
default: {
{
utility::panic(Jakt::DeprecatedString("Invalid String"sv));
}
};/*case end*/
}/*switch end*/
}()
)));
}
else if (__jakt_enum_value == Jakt::DeprecatedString("is_whitespace"sv)) {
return JaktInternal::ExplicitValue(JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<interpreter::StatementResult, ErrorOr<interpreter::StatementResult>>{
auto&& __jakt_match_variant = *(((this_argument.value())).impl);
switch(__jakt_match_variant.index()) {
case 13: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::JaktString>();
DeprecatedString const& value = __jakt_match_value.value;
return JaktInternal::ExplicitValue( interpreter::StatementResult { typename interpreter::StatementResult::JustValue(types::Value(TRY((types::ValueImpl::template create<typename types::ValueImpl::Bool>(((value).is_whitespace())))),call_span)) } );
};/*case end*/
default: {
{
utility::panic(Jakt::DeprecatedString("Invalid String"sv));
}
};/*case end*/
}/*switch end*/
}()
)));
}
else if (__jakt_enum_value == Jakt::DeprecatedString("contains"sv)) {
return JaktInternal::ExplicitValue(JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<interpreter::StatementResult, ErrorOr<interpreter::StatementResult>>{
auto&& __jakt_match_variant = *(((this_argument.value())).impl);
switch(__jakt_match_variant.index()) {
case 13: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::JaktString>();
DeprecatedString const& value = __jakt_match_value.value;
return JaktInternal::ExplicitValue(JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<interpreter::StatementResult, ErrorOr<interpreter::StatementResult>>{
auto&& __jakt_match_variant = *((((arguments)[static_cast<i64>(0LL)])).impl);
switch(__jakt_match_variant.index()) {
case 13: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::JaktString>();
DeprecatedString const& arg = __jakt_match_value.value;
return JaktInternal::ExplicitValue( interpreter::StatementResult { typename interpreter::StatementResult::JustValue(types::Value(TRY((types::ValueImpl::template create<typename types::ValueImpl::Bool>(((value).contains(arg))))),call_span)) } );
};/*case end*/
default: {
{
TRY((((*this).error(Jakt::DeprecatedString("String::contains must be called with a string"sv),((((arguments)[static_cast<i64>(0LL)])).span)))));
return Error::from_errno((infallible_integer_cast<i32>((interpreter::InterpretError::InvalidType))));
}
};/*case end*/
}/*switch end*/
}()
)));
};/*case end*/
default: {
{
utility::panic(Jakt::DeprecatedString("Invalid String"sv));
}
};/*case end*/
}/*switch end*/
}()
)));
}
else if (__jakt_enum_value == Jakt::DeprecatedString("replace"sv)) {
return JaktInternal::ExplicitValue(JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<interpreter::StatementResult, ErrorOr<interpreter::StatementResult>>{
auto&& __jakt_match_variant = *(((this_argument.value())).impl);
switch(__jakt_match_variant.index()) {
case 13: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::JaktString>();
DeprecatedString const& value = __jakt_match_value.value;
return JaktInternal::ExplicitValue(JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<interpreter::StatementResult, ErrorOr<interpreter::StatementResult>>{
auto&& __jakt_match_variant = *((((arguments)[static_cast<i64>(0LL)])).impl);
switch(__jakt_match_variant.index()) {
case 13: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::JaktString>();
DeprecatedString const& replace = __jakt_match_value.value;
return JaktInternal::ExplicitValue(JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<interpreter::StatementResult, ErrorOr<interpreter::StatementResult>>{
auto&& __jakt_match_variant = *((((arguments)[static_cast<i64>(1LL)])).impl);
switch(__jakt_match_variant.index()) {
case 13: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::JaktString>();
DeprecatedString const& with = __jakt_match_value.value;
return JaktInternal::ExplicitValue( interpreter::StatementResult { typename interpreter::StatementResult::JustValue(types::Value(TRY((types::ValueImpl::template create<typename types::ValueImpl::JaktString>(((value).replace(replace,with))))),call_span)) } );
};/*case end*/
default: {
{
TRY((((*this).error(Jakt::DeprecatedString("String::replace must be called with strings"sv),((((arguments)[static_cast<i64>(1LL)])).span)))));
return Error::from_errno((infallible_integer_cast<i32>((interpreter::InterpretError::InvalidType))));
}
};/*case end*/
}/*switch end*/
}()
)));
};/*case end*/
default: {
{
TRY((((*this).error(Jakt::DeprecatedString("String::replace must be called with strings"sv),((((arguments)[static_cast<i64>(0LL)])).span)))));
return Error::from_errno((infallible_integer_cast<i32>((interpreter::InterpretError::InvalidType))));
}
};/*case end*/
}/*switch end*/
}()
)));
};/*case end*/
default: {
{
utility::panic(Jakt::DeprecatedString("Invalid String"sv));
}
};/*case end*/
}/*switch end*/
}()
)));
}
else if (__jakt_enum_value == Jakt::DeprecatedString("byte_at"sv)) {
return JaktInternal::ExplicitValue(JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<interpreter::StatementResult, ErrorOr<interpreter::StatementResult>>{
auto&& __jakt_match_variant = *(((this_argument.value())).impl);
switch(__jakt_match_variant.index()) {
case 13: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::JaktString>();
DeprecatedString const& value = __jakt_match_value.value;
return JaktInternal::ExplicitValue(JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<interpreter::StatementResult, ErrorOr<interpreter::StatementResult>>{
auto&& __jakt_match_variant = *((((arguments)[static_cast<i64>(0LL)])).impl);
switch(__jakt_match_variant.index()) {
case 12: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::USize>();
size_t const& index = __jakt_match_value.value;
return JaktInternal::ExplicitValue( interpreter::StatementResult { typename interpreter::StatementResult::JustValue(types::Value(TRY((types::ValueImpl::template create<typename types::ValueImpl::U8>(((value).byte_at((infallible_integer_cast<size_t>((index)))))))),call_span)) } );
};/*case end*/
case 5: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::U64>();
u64 const& index = __jakt_match_value.value;
return JaktInternal::ExplicitValue( interpreter::StatementResult { typename interpreter::StatementResult::JustValue(types::Value(TRY((types::ValueImpl::template create<typename types::ValueImpl::U8>(((value).byte_at((infallible_integer_cast<size_t>((index)))))))),call_span)) } );
};/*case end*/
case 4: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::U32>();
u32 const& index = __jakt_match_value.value;
return JaktInternal::ExplicitValue( interpreter::StatementResult { typename interpreter::StatementResult::JustValue(types::Value(TRY((types::ValueImpl::template create<typename types::ValueImpl::U8>(((value).byte_at((infallible_integer_cast<size_t>((index)))))))),call_span)) } );
};/*case end*/
case 3: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::U16>();
u16 const& index = __jakt_match_value.value;
return JaktInternal::ExplicitValue( interpreter::StatementResult { typename interpreter::StatementResult::JustValue(types::Value(TRY((types::ValueImpl::template create<typename types::ValueImpl::U8>(((value).byte_at((infallible_integer_cast<size_t>((index)))))))),call_span)) } );
};/*case end*/
case 2: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::U8>();
u8 const& index = __jakt_match_value.value;
return JaktInternal::ExplicitValue( interpreter::StatementResult { typename interpreter::StatementResult::JustValue(types::Value(TRY((types::ValueImpl::template create<typename types::ValueImpl::U8>(((value).byte_at((infallible_integer_cast<size_t>((index)))))))),call_span)) } );
};/*case end*/
default: {
{
TRY((((*this).error(Jakt::DeprecatedString("String::byte_at must be called with an unsigned integer"sv),((((arguments)[static_cast<i64>(0LL)])).span)))));
return Error::from_errno((infallible_integer_cast<i32>((interpreter::InterpretError::InvalidType))));
}
};/*case end*/
}/*switch end*/
}()
)));
};/*case end*/
default: {
{
utility::panic(Jakt::DeprecatedString("Invalid String"sv));
}
};/*case end*/
}/*switch end*/
}()
)));
}
else if (__jakt_enum_value == Jakt::DeprecatedString("split"sv)) {
return JaktInternal::ExplicitValue(JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<interpreter::StatementResult, ErrorOr<interpreter::StatementResult>>{
auto&& __jakt_match_variant = *(((this_argument.value())).impl);
switch(__jakt_match_variant.index()) {
case 13: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::JaktString>();
DeprecatedString const& value = __jakt_match_value.value;
return JaktInternal::ExplicitValue(JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<interpreter::StatementResult, ErrorOr<interpreter::StatementResult>>{
auto&& __jakt_match_variant = *((((arguments)[static_cast<i64>(0LL)])).impl);
switch(__jakt_match_variant.index()) {
case 15: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::CChar>();
char const& c = __jakt_match_value.value;
return JaktInternal::ExplicitValue(({ Optional<interpreter::StatementResult> __jakt_var_225; {
JaktInternal::DynamicArray<DeprecatedString> const values = ((value).split(c));
JaktInternal::DynamicArray<types::Value> result = (TRY((DynamicArray<types::Value>::create_with({}))));
{
JaktInternal::ArrayIterator<DeprecatedString> _magic = ((values).iterator());
for (;;){
JaktInternal::Optional<DeprecatedString> _magic_value = ((_magic).next());
if ((!(((_magic_value).has_value())))){
break;
}
DeprecatedString value = (_magic_value.value());
{
TRY((((result).push(types::Value(TRY((types::ValueImpl::template create<typename types::ValueImpl::JaktString>(value))),call_span)))));
}

}
}

types::StructId const array_struct_id = TRY((((((*this).program))->find_struct_in_prelude(Jakt::DeprecatedString("Array"sv)))));
__jakt_var_225 =  interpreter::StatementResult { typename interpreter::StatementResult::JustValue(types::Value(TRY((types::ValueImpl::template create<typename types::ValueImpl::JaktArray>(result,TRY((((*this).find_or_add_type_id(TRY((types::Type::template create<typename types::Type::GenericInstance>(array_struct_id,(TRY((DynamicArray<types::TypeId>::create_with({types::builtin( types::BuiltinType { typename types::BuiltinType::JaktString() } )})))))))))))))),call_span)) } ; goto __jakt_label_222;

}
__jakt_label_222:; __jakt_var_225.release_value(); }));
};/*case end*/
default: {
{
TRY((((*this).error(Jakt::DeprecatedString("String::split must be called with a c_char"sv),((((arguments)[static_cast<i64>(0LL)])).span)))));
return Error::from_errno((infallible_integer_cast<i32>((interpreter::InterpretError::InvalidType))));
}
};/*case end*/
}/*switch end*/
}()
)));
};/*case end*/
default: {
{
utility::panic(Jakt::DeprecatedString("Invalid String"sv));
}
};/*case end*/
}/*switch end*/
}()
)));
}
else if (__jakt_enum_value == Jakt::DeprecatedString("starts_with"sv)) {
return JaktInternal::ExplicitValue(JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<interpreter::StatementResult, ErrorOr<interpreter::StatementResult>>{
auto&& __jakt_match_variant = *(((this_argument.value())).impl);
switch(__jakt_match_variant.index()) {
case 13: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::JaktString>();
DeprecatedString const& value = __jakt_match_value.value;
return JaktInternal::ExplicitValue(JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<interpreter::StatementResult, ErrorOr<interpreter::StatementResult>>{
auto&& __jakt_match_variant = *((((arguments)[static_cast<i64>(0LL)])).impl);
switch(__jakt_match_variant.index()) {
case 13: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::JaktString>();
DeprecatedString const& arg = __jakt_match_value.value;
return JaktInternal::ExplicitValue( interpreter::StatementResult { typename interpreter::StatementResult::JustValue(types::Value(TRY((types::ValueImpl::template create<typename types::ValueImpl::Bool>(((value).starts_with(arg))))),call_span)) } );
};/*case end*/
default: {
{
TRY((((*this).error(Jakt::DeprecatedString("String::starts_with must be called with a string"sv),((((arguments)[static_cast<i64>(0LL)])).span)))));
return Error::from_errno((infallible_integer_cast<i32>((interpreter::InterpretError::InvalidType))));
}
};/*case end*/
}/*switch end*/
}()
)));
};/*case end*/
default: {
{
utility::panic(Jakt::DeprecatedString("Invalid String"sv));
}
};/*case end*/
}/*switch end*/
}()
)));
}
else if (__jakt_enum_value == Jakt::DeprecatedString("ends_with"sv)) {
return JaktInternal::ExplicitValue(JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<interpreter::StatementResult, ErrorOr<interpreter::StatementResult>>{
auto&& __jakt_match_variant = *(((this_argument.value())).impl);
switch(__jakt_match_variant.index()) {
case 13: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::JaktString>();
DeprecatedString const& value = __jakt_match_value.value;
return JaktInternal::ExplicitValue(JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<interpreter::StatementResult, ErrorOr<interpreter::StatementResult>>{
auto&& __jakt_match_variant = *((((arguments)[static_cast<i64>(0LL)])).impl);
switch(__jakt_match_variant.index()) {
case 13: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::JaktString>();
DeprecatedString const& arg = __jakt_match_value.value;
return JaktInternal::ExplicitValue( interpreter::StatementResult { typename interpreter::StatementResult::JustValue(types::Value(TRY((types::ValueImpl::template create<typename types::ValueImpl::Bool>(((value).ends_with(arg))))),call_span)) } );
};/*case end*/
default: {
{
TRY((((*this).error(Jakt::DeprecatedString("String::ends_with must be called with a string"sv),((((arguments)[static_cast<i64>(0LL)])).span)))));
return Error::from_errno((infallible_integer_cast<i32>((interpreter::InterpretError::InvalidType))));
}
};/*case end*/
}/*switch end*/
}()
)));
};/*case end*/
default: {
{
utility::panic(Jakt::DeprecatedString("Invalid String"sv));
}
};/*case end*/
}/*switch end*/
}()
)));
}
else if (__jakt_enum_value == Jakt::DeprecatedString("repeated"sv)) {
return JaktInternal::ExplicitValue(({ Optional<interpreter::StatementResult> __jakt_var_226; {
if ((((arguments).size()) != static_cast<size_t>(2ULL))){
TRY((((*this).error(Jakt::DeprecatedString("String::repeated must be called with a c_char and a usize"sv),call_span))));
return Error::from_errno((infallible_integer_cast<i32>((interpreter::InterpretError::InvalidType))));
}
JaktInternal::Tuple<char,size_t> const character_count_ = JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<JaktInternal::Tuple<char,size_t>, ErrorOr<interpreter::StatementResult>>{
auto&& __jakt_match_variant = *((((arguments)[static_cast<i64>(0LL)])).impl);
switch(__jakt_match_variant.index()) {
case 15: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::CChar>();
char const& arg = __jakt_match_value.value;
return JaktInternal::ExplicitValue(JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<JaktInternal::Tuple<char,size_t>, ErrorOr<interpreter::StatementResult>>{
auto&& __jakt_match_variant = *((((arguments)[static_cast<i64>(1LL)])).impl);
switch(__jakt_match_variant.index()) {
case 12: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::USize>();
size_t const& c = __jakt_match_value.value;
return JaktInternal::ExplicitValue((Tuple{arg, c}));
};/*case end*/
default: {
{
TRY((((*this).error(Jakt::DeprecatedString("String::repeated must be called with a usize"sv),((((arguments)[static_cast<i64>(1LL)])).span)))));
return Error::from_errno((infallible_integer_cast<i32>((interpreter::InterpretError::InvalidType))));
}
};/*case end*/
}/*switch end*/
}()
)));
};/*case end*/
default: {
{
TRY((((*this).error(Jakt::DeprecatedString("String::repeated must be called with a c_char"sv),((((arguments)[static_cast<i64>(0LL)])).span)))));
return Error::from_errno((infallible_integer_cast<i32>((interpreter::InterpretError::InvalidType))));
}
};/*case end*/
}/*switch end*/
}()
));
char const character = ((character_count_).template get<0>());
size_t const count = ((character_count_).template get<1>());

__jakt_var_226 =  interpreter::StatementResult { typename interpreter::StatementResult::JustValue(types::Value(TRY((types::ValueImpl::template create<typename types::ValueImpl::JaktString>(DeprecatedString::repeated(character,count)))),call_span)) } ; goto __jakt_label_223;

}
__jakt_label_223:; __jakt_var_226.release_value(); }));
}
else {
{
TRY((((*this).error(TRY((__jakt_format(Jakt::DeprecatedString("Prelude function `String::{}` is not implemented"sv),prelude_function))),call_span))));
return Error::from_errno((infallible_integer_cast<i32>((interpreter::InterpretError::Unimplemented))));
}
}
}()))
);
}
else if (__jakt_enum_value == Jakt::DeprecatedString("Set"sv)) {
return JaktInternal::ExplicitValue(JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<interpreter::StatementResult,ErrorOr<interpreter::StatementResult>>{
auto __jakt_enum_value = (prelude_function);
if (__jakt_enum_value == Jakt::DeprecatedString("Set"sv)) {
return JaktInternal::ExplicitValue(({ Optional<interpreter::StatementResult> __jakt_var_227; {
if ((((type_bindings).size()) != static_cast<size_t>(1ULL))){
TRY((((*this).error(Jakt::DeprecatedString("Set constructor expects one generic argument"sv),call_span))));
return Error::from_errno((infallible_integer_cast<i32>((interpreter::InterpretError::InvalidType))));
}
types::StructId const set_struct_id = TRY((((((*this).program))->find_struct_in_prelude(Jakt::DeprecatedString("Set"sv)))));
types::TypeId const type_id = TRY((((*this).find_or_add_type_id(TRY((types::Type::template create<typename types::Type::GenericInstance>(set_struct_id,(TRY((DynamicArray<types::TypeId>::create_with({(((type_bindings).get(((TRY((((type_bindings).keys()))))[static_cast<i64>(0LL)]))).value())})))))))))));
__jakt_var_227 =  interpreter::StatementResult { typename interpreter::StatementResult::JustValue(types::Value(TRY((types::ValueImpl::template create<typename types::ValueImpl::JaktSet>((TRY((DynamicArray<types::Value>::create_with({})))),type_id))),call_span)) } ; goto __jakt_label_224;

}
__jakt_label_224:; __jakt_var_227.release_value(); }));
}
else if (__jakt_enum_value == Jakt::DeprecatedString("is_empty"sv)) {
return JaktInternal::ExplicitValue(JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<interpreter::StatementResult, ErrorOr<interpreter::StatementResult>>{
auto&& __jakt_match_variant = *(((this_argument.value())).impl);
switch(__jakt_match_variant.index()) {
case 22: {
auto&& __jakt_match_value = __jakt_match_variant.template get<types::ValueImpl::JaktSet>();JaktInternal::DynamicArray<types::Value> const& values = __jakt_match_value.values;
return JaktInternal::ExplicitValue( interpreter::StatementResult { typename interpreter::StatementResult::JustValue(types::Value(TRY((types::ValueImpl::template create<typename types::ValueImpl::Bool>(((values).is_empty())))),call_span)) } );
};/*case end*/
default: {
{
utility::panic(Jakt::DeprecatedString("Invalid Set"sv));
}
};/*case end*/
}/*switch end*/
}()
)));
}
else if (__jakt_enum_value == Jakt::DeprecatedString("contains"sv)) {
return JaktInternal::ExplicitValue(JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<interpreter::StatementResult, ErrorOr<interpreter::StatementResult>>{
auto&& __jakt_match_variant = *(((this_argument.value())).impl);
switch(__jakt_match_variant.index()) {
case 22: {
auto&& __jakt_match_value = __jakt_match_variant.template get<types::ValueImpl::JaktSet>();JaktInternal::DynamicArray<types::Value> const& values = __jakt_match_value.values;
return JaktInternal::ExplicitValue(({ Optional<interpreter::StatementResult> __jakt_var_228; {
bool found = false;
{
JaktInternal::Range<size_t> _magic = (JaktInternal::Range<size_t>{static_cast<size_t>(static_cast<size_t>(0ULL)),static_cast<size_t>(((values).size()))});
for (;;){
JaktInternal::Optional<size_t> _magic_value = ((_magic).next());
if ((!(((_magic_value).has_value())))){
break;
}
size_t i = (_magic_value.value());
{
if (((((((values)[i])).impl))->equals(((((arguments)[static_cast<i64>(0LL)])).impl)))){
(found = true);
break;
}
}

}
}

__jakt_var_228 =  interpreter::StatementResult { typename interpreter::StatementResult::JustValue(types::Value(TRY((types::ValueImpl::template create<typename types::ValueImpl::Bool>(found))),call_span)) } ; goto __jakt_label_225;

}
__jakt_label_225:; __jakt_var_228.release_value(); }));
};/*case end*/
default: {
{
utility::panic(Jakt::DeprecatedString("Invalid Set"sv));
}
};/*case end*/
}/*switch end*/
}()
)));
}
else if (__jakt_enum_value == Jakt::DeprecatedString("add"sv)) {
return JaktInternal::ExplicitValue(JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<interpreter::StatementResult, ErrorOr<interpreter::StatementResult>>{
auto&& __jakt_match_variant = *(((this_argument.value())).impl);
switch(__jakt_match_variant.index()) {
case 22: {
auto&& __jakt_match_value = __jakt_match_variant.template get<types::ValueImpl::JaktSet>();JaktInternal::DynamicArray<types::Value> const& values = __jakt_match_value.values;
return JaktInternal::ExplicitValue(({ Optional<interpreter::StatementResult> __jakt_var_229; {
JaktInternal::DynamicArray<types::Value> mutable_values = values;
TRY((((mutable_values).push(((arguments)[static_cast<i64>(0LL)])))));
__jakt_var_229 =  interpreter::StatementResult { typename interpreter::StatementResult::JustValue(types::Value(TRY((types::ValueImpl::template create<typename types::ValueImpl::Void>())),call_span)) } ; goto __jakt_label_226;

}
__jakt_label_226:; __jakt_var_229.release_value(); }));
};/*case end*/
default: {
{
utility::panic(Jakt::DeprecatedString("Invalid Set"sv));
}
};/*case end*/
}/*switch end*/
}()
)));
}
else if (__jakt_enum_value == Jakt::DeprecatedString("remove"sv)) {
return JaktInternal::ExplicitValue(JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<interpreter::StatementResult, ErrorOr<interpreter::StatementResult>>{
auto&& __jakt_match_variant = *(((this_argument.value())).impl);
switch(__jakt_match_variant.index()) {
case 22: {
auto&& __jakt_match_value = __jakt_match_variant.template get<types::ValueImpl::JaktSet>();JaktInternal::DynamicArray<types::Value> const& values = __jakt_match_value.values;
return JaktInternal::ExplicitValue(({ Optional<interpreter::StatementResult> __jakt_var_230; {
bool found = false;
JaktInternal::DynamicArray<types::Value> values_without = (TRY((DynamicArray<types::Value>::create_with({}))));
{
JaktInternal::Range<size_t> _magic = (JaktInternal::Range<size_t>{static_cast<size_t>(static_cast<size_t>(0ULL)),static_cast<size_t>(((values).size()))});
for (;;){
JaktInternal::Optional<size_t> _magic_value = ((_magic).next());
if ((!(((_magic_value).has_value())))){
break;
}
size_t i = (_magic_value.value());
{
if (((((((values)[i])).impl))->equals(((((arguments)[static_cast<i64>(0LL)])).impl)))){
(found = true);
continue;
}
TRY((((values_without).push(((values)[i])))));
}

}
}

JaktInternal::DynamicArray<types::Value> mutable_values = values;
((mutable_values).shrink(static_cast<size_t>(0ULL)));
{
JaktInternal::Range<size_t> _magic = (JaktInternal::Range<size_t>{static_cast<size_t>(static_cast<size_t>(0ULL)),static_cast<size_t>(((values_without).size()))});
for (;;){
JaktInternal::Optional<size_t> _magic_value = ((_magic).next());
if ((!(((_magic_value).has_value())))){
break;
}
size_t i = (_magic_value.value());
{
TRY((((mutable_values).push(((values_without)[i])))));
}

}
}

__jakt_var_230 =  interpreter::StatementResult { typename interpreter::StatementResult::JustValue(types::Value(TRY((types::ValueImpl::template create<typename types::ValueImpl::Bool>(found))),call_span)) } ; goto __jakt_label_227;

}
__jakt_label_227:; __jakt_var_230.release_value(); }));
};/*case end*/
default: {
{
utility::panic(Jakt::DeprecatedString("Invalid Set"sv));
}
};/*case end*/
}/*switch end*/
}()
)));
}
else if (__jakt_enum_value == Jakt::DeprecatedString("clear"sv)) {
return JaktInternal::ExplicitValue(JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<interpreter::StatementResult, ErrorOr<interpreter::StatementResult>>{
auto&& __jakt_match_variant = *(((this_argument.value())).impl);
switch(__jakt_match_variant.index()) {
case 22: {
auto&& __jakt_match_value = __jakt_match_variant.template get<types::ValueImpl::JaktSet>();JaktInternal::DynamicArray<types::Value> const& values = __jakt_match_value.values;
return JaktInternal::ExplicitValue(({ Optional<interpreter::StatementResult> __jakt_var_231; {
JaktInternal::DynamicArray<types::Value> mutable_values = values;
((mutable_values).shrink(static_cast<size_t>(0ULL)));
__jakt_var_231 =  interpreter::StatementResult { typename interpreter::StatementResult::JustValue(types::Value(TRY((types::ValueImpl::template create<typename types::ValueImpl::Void>())),call_span)) } ; goto __jakt_label_228;

}
__jakt_label_228:; __jakt_var_231.release_value(); }));
};/*case end*/
default: {
{
utility::panic(Jakt::DeprecatedString("Invalid Set"sv));
}
};/*case end*/
}/*switch end*/
}()
)));
}
else if (__jakt_enum_value == Jakt::DeprecatedString("size"sv)) {
return JaktInternal::ExplicitValue(JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<interpreter::StatementResult, ErrorOr<interpreter::StatementResult>>{
auto&& __jakt_match_variant = *(((this_argument.value())).impl);
switch(__jakt_match_variant.index()) {
case 22: {
auto&& __jakt_match_value = __jakt_match_variant.template get<types::ValueImpl::JaktSet>();JaktInternal::DynamicArray<types::Value> const& values = __jakt_match_value.values;
return JaktInternal::ExplicitValue( interpreter::StatementResult { typename interpreter::StatementResult::JustValue(types::Value(TRY((types::ValueImpl::template create<typename types::ValueImpl::USize>(((values).size())))),call_span)) } );
};/*case end*/
default: {
{
utility::panic(Jakt::DeprecatedString("Invalid Set"sv));
}
};/*case end*/
}/*switch end*/
}()
)));
}
else if (__jakt_enum_value == Jakt::DeprecatedString("capacity"sv)) {
return JaktInternal::ExplicitValue(JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<interpreter::StatementResult, ErrorOr<interpreter::StatementResult>>{
auto&& __jakt_match_variant = *(((this_argument.value())).impl);
switch(__jakt_match_variant.index()) {
case 22: {
auto&& __jakt_match_value = __jakt_match_variant.template get<types::ValueImpl::JaktSet>();JaktInternal::DynamicArray<types::Value> const& values = __jakt_match_value.values;
return JaktInternal::ExplicitValue( interpreter::StatementResult { typename interpreter::StatementResult::JustValue(types::Value(TRY((types::ValueImpl::template create<typename types::ValueImpl::USize>(((values).capacity())))),call_span)) } );
};/*case end*/
default: {
{
utility::panic(Jakt::DeprecatedString("Invalid Set"sv));
}
};/*case end*/
}/*switch end*/
}()
)));
}
else if (__jakt_enum_value == Jakt::DeprecatedString("ensure_capacity"sv)) {
return JaktInternal::ExplicitValue(JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<interpreter::StatementResult, ErrorOr<interpreter::StatementResult>>{
auto&& __jakt_match_variant = *(((this_argument.value())).impl);
switch(__jakt_match_variant.index()) {
case 22: {
auto&& __jakt_match_value = __jakt_match_variant.template get<types::ValueImpl::JaktSet>();JaktInternal::DynamicArray<types::Value> const& values = __jakt_match_value.values;
return JaktInternal::ExplicitValue(JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<interpreter::StatementResult, ErrorOr<interpreter::StatementResult>>{
auto&& __jakt_match_variant = *((((arguments)[static_cast<i64>(0LL)])).impl);
switch(__jakt_match_variant.index()) {
case 12: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::USize>();
size_t const& capacity = __jakt_match_value.value;
return JaktInternal::ExplicitValue(({ Optional<interpreter::StatementResult> __jakt_var_232; {
JaktInternal::DynamicArray<types::Value> mutable_values = values;
TRY((((mutable_values).ensure_capacity(capacity))));
__jakt_var_232 =  interpreter::StatementResult { typename interpreter::StatementResult::JustValue(types::Value(TRY((types::ValueImpl::template create<typename types::ValueImpl::Void>())),call_span)) } ; goto __jakt_label_229;

}
__jakt_label_229:; __jakt_var_232.release_value(); }));
};/*case end*/
default: {
{
TRY((((*this).error(Jakt::DeprecatedString("Set::ensure_capacity must be called with a usize"sv),((((arguments)[static_cast<i64>(0LL)])).span)))));
return Error::from_errno((infallible_integer_cast<i32>((interpreter::InterpretError::InvalidType))));
}
};/*case end*/
}/*switch end*/
}()
)));
};/*case end*/
default: {
{
utility::panic(Jakt::DeprecatedString("Invalid Set"sv));
}
};/*case end*/
}/*switch end*/
}()
)));
}
else if (__jakt_enum_value == Jakt::DeprecatedString("iterator"sv)) {
return JaktInternal::ExplicitValue(JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<interpreter::StatementResult, ErrorOr<interpreter::StatementResult>>{
auto&& __jakt_match_variant = *(((this_argument.value())).impl);
switch(__jakt_match_variant.index()) {
case 22: {
auto&& __jakt_match_value = __jakt_match_variant.template get<types::ValueImpl::JaktSet>();return JaktInternal::ExplicitValue(({ Optional<interpreter::StatementResult> __jakt_var_233; {
types::StructId const struct_id = TRY((((((*this).program))->find_struct_in_prelude(Jakt::DeprecatedString("SetIterator"sv)))));
__jakt_var_233 =  interpreter::StatementResult { typename interpreter::StatementResult::JustValue(types::Value(TRY((types::ValueImpl::template create<typename types::ValueImpl::Struct>((TRY((DynamicArray<types::Value>::create_with({(this_argument.value()), types::Value(TRY((types::ValueImpl::template create<typename types::ValueImpl::USize>(static_cast<size_t>(0ULL)))),call_span)})))),struct_id,JaktInternal::OptionalNone()))),call_span)) } ; goto __jakt_label_230;

}
__jakt_label_230:; __jakt_var_233.release_value(); }));
};/*case end*/
default: {
{
utility::panic(Jakt::DeprecatedString("Invalid use of Set::iterator()"sv));
}
};/*case end*/
}/*switch end*/
}()
)));
}
else {
{
TRY((((*this).error(TRY((__jakt_format(Jakt::DeprecatedString("Prelude function `Set::{}` is not implemented"sv),prelude_function))),call_span))));
return Error::from_errno((infallible_integer_cast<i32>((interpreter::InterpretError::Unimplemented))));
}
}
}()))
);
}
else if (__jakt_enum_value == Jakt::DeprecatedString("SetIterator"sv)) {
return JaktInternal::ExplicitValue(JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<interpreter::StatementResult,ErrorOr<interpreter::StatementResult>>{
auto __jakt_enum_value = (prelude_function);
if (__jakt_enum_value == Jakt::DeprecatedString("next"sv)) {
return JaktInternal::ExplicitValue(JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<interpreter::StatementResult, ErrorOr<interpreter::StatementResult>>{
auto&& __jakt_match_variant = *(((this_argument.value())).impl);
switch(__jakt_match_variant.index()) {
case 17: {
auto&& __jakt_match_value = __jakt_match_variant.template get<types::ValueImpl::Struct>();JaktInternal::DynamicArray<types::Value> const& fields = __jakt_match_value.fields;
return JaktInternal::ExplicitValue(({ Optional<interpreter::StatementResult> __jakt_var_234; {
size_t const index = JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<size_t, ErrorOr<interpreter::StatementResult>>{
auto&& __jakt_match_variant = *((((fields)[static_cast<i64>(1LL)])).impl);
switch(__jakt_match_variant.index()) {
case 12: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::USize>();
size_t const& value = __jakt_match_value.value;
return JaktInternal::ExplicitValue(value);
};/*case end*/
default: {
{
utility::panic(Jakt::DeprecatedString("Invalid SetIterator index configuration"sv));
}
};/*case end*/
}/*switch end*/
}()
));
JaktInternal::DynamicArray<types::Value> mutable_fields = fields;
__jakt_var_234 =  interpreter::StatementResult { typename interpreter::StatementResult::JustValue(JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<types::Value, ErrorOr<interpreter::StatementResult>>{
auto&& __jakt_match_variant = *((((fields)[static_cast<i64>(0LL)])).impl);
switch(__jakt_match_variant.index()) {
case 22: {
auto&& __jakt_match_value = __jakt_match_variant.template get<types::ValueImpl::JaktSet>();JaktInternal::DynamicArray<types::Value> const& values = __jakt_match_value.values;
return JaktInternal::ExplicitValue(JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<types::Value,ErrorOr<interpreter::StatementResult>>{
auto __jakt_enum_value = ((((values).size()) > index));
if (__jakt_enum_value == true) {
return JaktInternal::ExplicitValue(({ Optional<types::Value> __jakt_var_235; {
(((mutable_fields)[static_cast<i64>(1LL)]) = types::Value(TRY((types::ValueImpl::template create<typename types::ValueImpl::USize>((JaktInternal::checked_add<size_t>(index,static_cast<size_t>(1ULL)))))),call_span));
__jakt_var_235 = types::Value(TRY((types::ValueImpl::template create<typename types::ValueImpl::OptionalSome>(((values)[index])))),call_span); goto __jakt_label_232;

}
__jakt_label_232:; __jakt_var_235.release_value(); }));
}
else {
return JaktInternal::ExplicitValue(types::Value(TRY((types::ValueImpl::template create<typename types::ValueImpl::OptionalNone>())),call_span));
}
}()))
);
};/*case end*/
default: {
{
utility::panic(Jakt::DeprecatedString("Invalid SetIterator configuration"sv));
}
};/*case end*/
}/*switch end*/
}()
))) } ; goto __jakt_label_231;

}
__jakt_label_231:; __jakt_var_234.release_value(); }));
};/*case end*/
default: {
{
utility::panic(Jakt::DeprecatedString("Invalid SetIterator configuration"sv));
}
};/*case end*/
}/*switch end*/
}()
)));
}
else {
{
TRY((((*this).error(TRY((__jakt_format(Jakt::DeprecatedString("Prelude function `ArrayIterator::{}` is not implemented"sv),prelude_function))),call_span))));
return Error::from_errno((infallible_integer_cast<i32>((interpreter::InterpretError::Unimplemented))));
}
}
}()))
);
}
else if (__jakt_enum_value == Jakt::DeprecatedString("DictionaryIterator"sv)) {
return JaktInternal::ExplicitValue(JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<interpreter::StatementResult,ErrorOr<interpreter::StatementResult>>{
auto __jakt_enum_value = (prelude_function);
if (__jakt_enum_value == Jakt::DeprecatedString("next"sv)) {
return JaktInternal::ExplicitValue(JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<interpreter::StatementResult, ErrorOr<interpreter::StatementResult>>{
auto&& __jakt_match_variant = *(((this_argument.value())).impl);
switch(__jakt_match_variant.index()) {
case 17: {
auto&& __jakt_match_value = __jakt_match_variant.template get<types::ValueImpl::Struct>();JaktInternal::DynamicArray<types::Value> const& fields = __jakt_match_value.fields;
return JaktInternal::ExplicitValue(({ Optional<interpreter::StatementResult> __jakt_var_236; {
size_t const index = JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<size_t, ErrorOr<interpreter::StatementResult>>{
auto&& __jakt_match_variant = *((((fields)[static_cast<i64>(1LL)])).impl);
switch(__jakt_match_variant.index()) {
case 12: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::USize>();
size_t const& value = __jakt_match_value.value;
return JaktInternal::ExplicitValue(value);
};/*case end*/
default: {
{
utility::panic(Jakt::DeprecatedString("Invalid DictionaryIterator index configuration"sv));
}
};/*case end*/
}/*switch end*/
}()
));
JaktInternal::DynamicArray<types::Value> mutable_fields = fields;
__jakt_var_236 =  interpreter::StatementResult { typename interpreter::StatementResult::JustValue(JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<types::Value, ErrorOr<interpreter::StatementResult>>{
auto&& __jakt_match_variant = *((((fields)[static_cast<i64>(0LL)])).impl);
switch(__jakt_match_variant.index()) {
case 21: {
auto&& __jakt_match_value = __jakt_match_variant.template get<types::ValueImpl::JaktDictionary>();JaktInternal::DynamicArray<types::Value> const& keys = __jakt_match_value.keys;
JaktInternal::DynamicArray<types::Value> const& values = __jakt_match_value.values;
types::TypeId const& type_id = __jakt_match_value.type_id;
return JaktInternal::ExplicitValue(JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<types::Value,ErrorOr<interpreter::StatementResult>>{
auto __jakt_enum_value = (((((keys).size()) > index) && (((values).size()) > index)));
if (__jakt_enum_value == true) {
return JaktInternal::ExplicitValue(({ Optional<types::Value> __jakt_var_237; {
(((mutable_fields)[static_cast<i64>(1LL)]) = types::Value(TRY((types::ValueImpl::template create<typename types::ValueImpl::USize>((JaktInternal::checked_add<size_t>(index,static_cast<size_t>(1ULL)))))),call_span));
JaktInternal::DynamicArray<types::TypeId> const generics = JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<JaktInternal::DynamicArray<types::TypeId>, ErrorOr<interpreter::StatementResult>>{
auto&& __jakt_match_variant = *((((*this).program))->get_type(type_id));
switch(__jakt_match_variant.index()) {
case 19: {
auto&& __jakt_match_value = __jakt_match_variant.template get<types::Type::GenericInstance>();JaktInternal::DynamicArray<types::TypeId> const& args = __jakt_match_value.args;
return JaktInternal::ExplicitValue(args);
};/*case end*/
default: {
{
utility::panic(Jakt::DeprecatedString("expected generic instance"sv));
}
};/*case end*/
}/*switch end*/
}()
));
types::StructId const tuple_struct_id = TRY((((((*this).program))->find_struct_in_prelude(Jakt::DeprecatedString("Tuple"sv)))));
types::TypeId const tuple_type_id = TRY((((*this).find_or_add_type_id(TRY((types::Type::template create<typename types::Type::GenericInstance>(tuple_struct_id,generics)))))));
__jakt_var_237 = types::Value(TRY((types::ValueImpl::template create<typename types::ValueImpl::OptionalSome>(types::Value(TRY((types::ValueImpl::template create<typename types::ValueImpl::JaktTuple>((TRY((DynamicArray<types::Value>::create_with({((keys)[index]), ((values)[index])})))),tuple_type_id))),call_span)))),call_span); goto __jakt_label_234;

}
__jakt_label_234:; __jakt_var_237.release_value(); }));
}
else {
return JaktInternal::ExplicitValue(types::Value(TRY((types::ValueImpl::template create<typename types::ValueImpl::OptionalNone>())),call_span));
}
}()))
);
};/*case end*/
default: {
{
utility::panic(Jakt::DeprecatedString("Invalid DictionaryIterator configuration"sv));
}
};/*case end*/
}/*switch end*/
}()
))) } ; goto __jakt_label_233;

}
__jakt_label_233:; __jakt_var_236.release_value(); }));
};/*case end*/
default: {
{
utility::panic(Jakt::DeprecatedString("Invalid DictionaryIterator configuration"sv));
}
};/*case end*/
}/*switch end*/
}()
)));
}
else {
{
TRY((((*this).error(TRY((__jakt_format(Jakt::DeprecatedString("Prelude function `DictionaryIterator::{}` is not implemented"sv),prelude_function))),call_span))));
return Error::from_errno((infallible_integer_cast<i32>((interpreter::InterpretError::Unimplemented))));
}
}
}()))
);
}
else if (__jakt_enum_value == Jakt::DeprecatedString("Optional"sv)) {
return JaktInternal::ExplicitValue(JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<interpreter::StatementResult,ErrorOr<interpreter::StatementResult>>{
auto __jakt_enum_value = (prelude_function);
if (__jakt_enum_value == Jakt::DeprecatedString("has_value"sv)) {
return JaktInternal::ExplicitValue(JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<interpreter::StatementResult, ErrorOr<interpreter::StatementResult>>{
auto&& __jakt_match_variant = *(((this_argument.value())).impl);
switch(__jakt_match_variant.index()) {
case 24: {
auto&& __jakt_match_value = __jakt_match_variant.template get<types::ValueImpl::OptionalSome>();return JaktInternal::ExplicitValue( interpreter::StatementResult { typename interpreter::StatementResult::JustValue(types::Value(TRY((types::ValueImpl::template create<typename types::ValueImpl::Bool>(true))),call_span)) } );
};/*case end*/
case 25: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::OptionalNone>();
return JaktInternal::ExplicitValue( interpreter::StatementResult { typename interpreter::StatementResult::JustValue(types::Value(TRY((types::ValueImpl::template create<typename types::ValueImpl::Bool>(false))),call_span)) } );
};/*case end*/
default: {
{
utility::panic(Jakt::DeprecatedString("Invalid Optional configuration"sv));
}
};/*case end*/
}/*switch end*/
}()
)));
}
else if (__jakt_enum_value == Jakt::DeprecatedString("value"sv)) {
return JaktInternal::ExplicitValue(JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<interpreter::StatementResult, ErrorOr<interpreter::StatementResult>>{
auto&& __jakt_match_variant = *(((this_argument.value())).impl);
switch(__jakt_match_variant.index()) {
case 24: {
auto&& __jakt_match_value = __jakt_match_variant.template get<types::ValueImpl::OptionalSome>();types::Value const& value = __jakt_match_value.value;
return JaktInternal::ExplicitValue( interpreter::StatementResult { typename interpreter::StatementResult::JustValue(value) } );
};/*case end*/
case 25: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::OptionalNone>();
{
TRY((((*this).error(TRY((__jakt_format(Jakt::DeprecatedString("Cannot unwrap optional none"sv),prelude_function))),call_span))));
return Error::from_errno((infallible_integer_cast<i32>((interpreter::InterpretError::UnwrapOptionalNone))));
}
};/*case end*/
default: {
{
utility::panic(Jakt::DeprecatedString("Invalid Optional configuration"sv));
}
};/*case end*/
}/*switch end*/
}()
)));
}
else if (__jakt_enum_value == Jakt::DeprecatedString("value_or"sv)) {
return JaktInternal::ExplicitValue(JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<interpreter::StatementResult, ErrorOr<interpreter::StatementResult>>{
auto&& __jakt_match_variant = *(((this_argument.value())).impl);
switch(__jakt_match_variant.index()) {
case 24: {
auto&& __jakt_match_value = __jakt_match_variant.template get<types::ValueImpl::OptionalSome>();types::Value const& value = __jakt_match_value.value;
return JaktInternal::ExplicitValue( interpreter::StatementResult { typename interpreter::StatementResult::JustValue(value) } );
};/*case end*/
case 25: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::OptionalNone>();
return JaktInternal::ExplicitValue( interpreter::StatementResult { typename interpreter::StatementResult::JustValue(((arguments)[static_cast<i64>(0LL)])) } );
};/*case end*/
default: {
{
utility::panic(Jakt::DeprecatedString("Invalid Optional configuration"sv));
}
};/*case end*/
}/*switch end*/
}()
)));
}
else {
{
TRY((((*this).error(TRY((__jakt_format(Jakt::DeprecatedString("Prelude function `Optional::{}` is not implemented"sv),prelude_function))),call_span))));
return Error::from_errno((infallible_integer_cast<i32>((interpreter::InterpretError::Unimplemented))));
}
}
}()))
);
}
else {
{
TRY((((*this).error(TRY((__jakt_format(Jakt::DeprecatedString("Prelude function `{}::{}` is not implemented"sv),((((namespace_)[static_cast<i64>(0LL)])).name),prelude_function))),call_span))));
return Error::from_errno((infallible_integer_cast<i32>((interpreter::InterpretError::Unimplemented))));
}
}
}()))
);
}
}

ErrorOr<void> interpreter::Interpreter::update_binding(NonnullRefPtr<typename types::CheckedExpression> const binding,NonnullRefPtr<interpreter::InterpreterScope> scope,types::Value const value,utility::Span const span) {
{
JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<void, ErrorOr<void>>{
auto&& __jakt_match_variant = *binding;
switch(__jakt_match_variant.index()) {
case 22: {
auto&& __jakt_match_value = __jakt_match_variant.template get<types::CheckedExpression::Var>();NonnullRefPtr<types::CheckedVariable> const& var = __jakt_match_value.var;
{
TRY((((scope)->set(((var)->name),value))));
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 15: {
auto&& __jakt_match_value = __jakt_match_variant.template get<types::CheckedExpression::IndexedStruct>();NonnullRefPtr<typename types::CheckedExpression> const& expr = __jakt_match_value.expr;
DeprecatedString const& index = __jakt_match_value.index;
{
JaktInternal::Tuple<JaktInternal::DynamicArray<types::Value>,types::StructId> fields_struct_id_ = JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<JaktInternal::Tuple<JaktInternal::DynamicArray<types::Value>,types::StructId>, ErrorOr<void>>{
auto&& __jakt_match_variant = TRY((((*this).execute_expression(expr,scope))));
switch(__jakt_match_variant.index()) {
case 5: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename interpreter::StatementResult::JustValue>();
types::Value const& value = __jakt_match_value.value;
return JaktInternal::ExplicitValue(JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<JaktInternal::Tuple<JaktInternal::DynamicArray<types::Value>,types::StructId>, ErrorOr<void>>{
auto&& __jakt_match_variant = *((value).impl);
switch(__jakt_match_variant.index()) {
case 18: {
auto&& __jakt_match_value = __jakt_match_variant.template get<types::ValueImpl::Class>();JaktInternal::DynamicArray<types::Value> const& fields = __jakt_match_value.fields;
types::StructId const& struct_id = __jakt_match_value.struct_id;
return JaktInternal::ExplicitValue((Tuple{fields, struct_id}));
};/*case end*/
case 17: {
auto&& __jakt_match_value = __jakt_match_variant.template get<types::ValueImpl::Struct>();JaktInternal::DynamicArray<types::Value> const& fields = __jakt_match_value.fields;
types::StructId const& struct_id = __jakt_match_value.struct_id;
return JaktInternal::ExplicitValue((Tuple{fields, struct_id}));
};/*case end*/
default: {
{
utility::panic(Jakt::DeprecatedString("Invalid left-hand side in assignment"sv));
}
};/*case end*/
}/*switch end*/
}()
)));
};/*case end*/
default: {
{
utility::panic(Jakt::DeprecatedString("Should not be happening here"sv));
}
};/*case end*/
}/*switch end*/
}()
));
JaktInternal::DynamicArray<types::Value> fields = ((fields_struct_id_).template get<0>());
types::StructId struct_id = ((fields_struct_id_).template get<1>());

JaktInternal::DynamicArray<types::CheckedField> const field_decls = ((((((*this).program))->get_struct(struct_id))).fields);
size_t field_index = static_cast<size_t>(0ULL);
{
JaktInternal::Range<size_t> _magic = (JaktInternal::Range<size_t>{static_cast<size_t>(static_cast<size_t>(0ULL)),static_cast<size_t>(((field_decls).size()))});
for (;;){
JaktInternal::Optional<size_t> _magic_value = ((_magic).next());
if ((!(((_magic_value).has_value())))){
break;
}
size_t i = (_magic_value.value());
{
if ((((((((*this).program))->get_variable(((((field_decls)[i])).variable_id))))->name) == index)){
(field_index = i);
break;
}
}

}
}

(((fields)[field_index]) = value);
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 16: {
auto&& __jakt_match_value = __jakt_match_variant.template get<types::CheckedExpression::IndexedCommonEnumMember>();NonnullRefPtr<typename types::CheckedExpression> const& expr = __jakt_match_value.expr;
DeprecatedString const& index = __jakt_match_value.index;
{
JaktInternal::Tuple<JaktInternal::DynamicArray<types::Value>,types::EnumId> fields_enum_id_ = JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<JaktInternal::Tuple<JaktInternal::DynamicArray<types::Value>,types::EnumId>, ErrorOr<void>>{
auto&& __jakt_match_variant = TRY((((*this).execute_expression(expr,scope))));
switch(__jakt_match_variant.index()) {
case 5: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename interpreter::StatementResult::JustValue>();
types::Value const& value = __jakt_match_value.value;
return JaktInternal::ExplicitValue(JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<JaktInternal::Tuple<JaktInternal::DynamicArray<types::Value>,types::EnumId>, ErrorOr<void>>{
auto&& __jakt_match_variant = *((value).impl);
switch(__jakt_match_variant.index()) {
case 19: {
auto&& __jakt_match_value = __jakt_match_variant.template get<types::ValueImpl::Enum>();JaktInternal::DynamicArray<types::Value> const& fields = __jakt_match_value.fields;
types::EnumId const& enum_id = __jakt_match_value.enum_id;
return JaktInternal::ExplicitValue((Tuple{fields, enum_id}));
};/*case end*/
default: {
{
utility::panic(Jakt::DeprecatedString("Invalid left-hand side in assignment"sv));
}
};/*case end*/
}/*switch end*/
}()
)));
};/*case end*/
default: {
{
utility::panic(Jakt::DeprecatedString("Should not be happening here"sv));
}
};/*case end*/
}/*switch end*/
}()
));
JaktInternal::DynamicArray<types::Value> fields = ((fields_enum_id_).template get<0>());
types::EnumId enum_id = ((fields_enum_id_).template get<1>());

JaktInternal::DynamicArray<types::CheckedField> const field_decls = ((((((*this).program))->get_enum(enum_id))).fields);
size_t field_index = static_cast<size_t>(0ULL);
{
JaktInternal::Range<size_t> _magic = (JaktInternal::Range<size_t>{static_cast<size_t>(static_cast<size_t>(0ULL)),static_cast<size_t>(((field_decls).size()))});
for (;;){
JaktInternal::Optional<size_t> _magic_value = ((_magic).next());
if ((!(((_magic_value).has_value())))){
break;
}
size_t i = (_magic_value.value());
{
if ((((((((*this).program))->get_variable(((((field_decls)[i])).variable_id))))->name) == index)){
(field_index = i);
break;
}
}

}
}

(((fields)[field_index]) = value);
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
default: {
{
TRY((((*this).error(TRY((__jakt_format(Jakt::DeprecatedString("Invalid left-hand side of assignment {}"sv),binding))),span))));
return Error::from_errno((infallible_integer_cast<i32>((interpreter::InterpretError::InvalidType))));
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
}/*switch end*/
}()
));
}
return {};
}

ErrorOr<interpreter::StatementResult> interpreter::Interpreter::execute_binary_operator(types::Value const lhs_value,types::Value const rhs_value,parser::BinaryOperator const op,utility::Span const span,NonnullRefPtr<interpreter::InterpreterScope> const scope) {
{
return (JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<interpreter::StatementResult, ErrorOr<interpreter::StatementResult>>{
auto&& __jakt_match_variant = op;
switch(__jakt_match_variant.index()) {
case 0: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename parser::BinaryOperator::Add>();
return JaktInternal::ExplicitValue( interpreter::StatementResult { typename interpreter::StatementResult::JustValue(types::Value(JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<NonnullRefPtr<typename types::ValueImpl>, ErrorOr<interpreter::StatementResult>>{
auto&& __jakt_match_variant = *((lhs_value).impl);
switch(__jakt_match_variant.index()) {
case 2: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::U8>();
u8 const& x = __jakt_match_value.value;
return JaktInternal::ExplicitValue(JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<NonnullRefPtr<typename types::ValueImpl>, ErrorOr<interpreter::StatementResult>>{
auto&& __jakt_match_variant = *((rhs_value).impl);
switch(__jakt_match_variant.index()) {
case 2: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::U8>();
u8 const& y = __jakt_match_value.value;
return JaktInternal::ExplicitValue(TRY((types::ValueImpl::template create<typename types::ValueImpl::U8>((JaktInternal::checked_add<u8>(x,y))))));
};/*case end*/
default: {
{
TRY((((*this).error(TRY((__jakt_format(Jakt::DeprecatedString("Invalid operands '{}' and '{}' to binary operation"sv),((lhs_value).type_name()),((rhs_value).type_name())))),span))));
return Error::from_errno((infallible_integer_cast<i32>((interpreter::InterpretError::InvalidType))));
}
};/*case end*/
}/*switch end*/
}()
)));
};/*case end*/
case 3: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::U16>();
u16 const& x = __jakt_match_value.value;
return JaktInternal::ExplicitValue(JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<NonnullRefPtr<typename types::ValueImpl>, ErrorOr<interpreter::StatementResult>>{
auto&& __jakt_match_variant = *((rhs_value).impl);
switch(__jakt_match_variant.index()) {
case 3: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::U16>();
u16 const& y = __jakt_match_value.value;
return JaktInternal::ExplicitValue(TRY((types::ValueImpl::template create<typename types::ValueImpl::U16>((JaktInternal::checked_add<u16>(x,y))))));
};/*case end*/
default: {
{
TRY((((*this).error(TRY((__jakt_format(Jakt::DeprecatedString("Invalid operands '{}' and '{}' to binary operation"sv),((lhs_value).type_name()),((rhs_value).type_name())))),span))));
return Error::from_errno((infallible_integer_cast<i32>((interpreter::InterpretError::InvalidType))));
}
};/*case end*/
}/*switch end*/
}()
)));
};/*case end*/
case 4: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::U32>();
u32 const& x = __jakt_match_value.value;
return JaktInternal::ExplicitValue(JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<NonnullRefPtr<typename types::ValueImpl>, ErrorOr<interpreter::StatementResult>>{
auto&& __jakt_match_variant = *((rhs_value).impl);
switch(__jakt_match_variant.index()) {
case 4: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::U32>();
u32 const& y = __jakt_match_value.value;
return JaktInternal::ExplicitValue(TRY((types::ValueImpl::template create<typename types::ValueImpl::U32>((JaktInternal::checked_add<u32>(x,y))))));
};/*case end*/
default: {
{
TRY((((*this).error(TRY((__jakt_format(Jakt::DeprecatedString("Invalid operands '{}' and '{}' to binary operation"sv),((lhs_value).type_name()),((rhs_value).type_name())))),span))));
return Error::from_errno((infallible_integer_cast<i32>((interpreter::InterpretError::InvalidType))));
}
};/*case end*/
}/*switch end*/
}()
)));
};/*case end*/
case 5: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::U64>();
u64 const& x = __jakt_match_value.value;
return JaktInternal::ExplicitValue(JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<NonnullRefPtr<typename types::ValueImpl>, ErrorOr<interpreter::StatementResult>>{
auto&& __jakt_match_variant = *((rhs_value).impl);
switch(__jakt_match_variant.index()) {
case 5: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::U64>();
u64 const& y = __jakt_match_value.value;
return JaktInternal::ExplicitValue(TRY((types::ValueImpl::template create<typename types::ValueImpl::U64>((JaktInternal::checked_add<u64>(x,y))))));
};/*case end*/
default: {
{
TRY((((*this).error(TRY((__jakt_format(Jakt::DeprecatedString("Invalid operands '{}' and '{}' to binary operation"sv),((lhs_value).type_name()),((rhs_value).type_name())))),span))));
return Error::from_errno((infallible_integer_cast<i32>((interpreter::InterpretError::InvalidType))));
}
};/*case end*/
}/*switch end*/
}()
)));
};/*case end*/
case 6: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::I8>();
i8 const& x = __jakt_match_value.value;
return JaktInternal::ExplicitValue(JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<NonnullRefPtr<typename types::ValueImpl>, ErrorOr<interpreter::StatementResult>>{
auto&& __jakt_match_variant = *((rhs_value).impl);
switch(__jakt_match_variant.index()) {
case 6: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::I8>();
i8 const& y = __jakt_match_value.value;
return JaktInternal::ExplicitValue(TRY((types::ValueImpl::template create<typename types::ValueImpl::I8>((JaktInternal::checked_add<i8>(x,y))))));
};/*case end*/
default: {
{
TRY((((*this).error(TRY((__jakt_format(Jakt::DeprecatedString("Invalid operands '{}' and '{}' to binary operation"sv),((lhs_value).type_name()),((rhs_value).type_name())))),span))));
return Error::from_errno((infallible_integer_cast<i32>((interpreter::InterpretError::InvalidType))));
}
};/*case end*/
}/*switch end*/
}()
)));
};/*case end*/
case 7: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::I16>();
i16 const& x = __jakt_match_value.value;
return JaktInternal::ExplicitValue(JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<NonnullRefPtr<typename types::ValueImpl>, ErrorOr<interpreter::StatementResult>>{
auto&& __jakt_match_variant = *((rhs_value).impl);
switch(__jakt_match_variant.index()) {
case 7: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::I16>();
i16 const& y = __jakt_match_value.value;
return JaktInternal::ExplicitValue(TRY((types::ValueImpl::template create<typename types::ValueImpl::I16>((JaktInternal::checked_add<i16>(x,y))))));
};/*case end*/
default: {
{
TRY((((*this).error(TRY((__jakt_format(Jakt::DeprecatedString("Invalid operands '{}' and '{}' to binary operation"sv),((lhs_value).type_name()),((rhs_value).type_name())))),span))));
return Error::from_errno((infallible_integer_cast<i32>((interpreter::InterpretError::InvalidType))));
}
};/*case end*/
}/*switch end*/
}()
)));
};/*case end*/
case 8: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::I32>();
i32 const& x = __jakt_match_value.value;
return JaktInternal::ExplicitValue(JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<NonnullRefPtr<typename types::ValueImpl>, ErrorOr<interpreter::StatementResult>>{
auto&& __jakt_match_variant = *((rhs_value).impl);
switch(__jakt_match_variant.index()) {
case 8: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::I32>();
i32 const& y = __jakt_match_value.value;
return JaktInternal::ExplicitValue(TRY((types::ValueImpl::template create<typename types::ValueImpl::I32>((JaktInternal::checked_add<i32>(x,y))))));
};/*case end*/
default: {
{
TRY((((*this).error(TRY((__jakt_format(Jakt::DeprecatedString("Invalid operands '{}' and '{}' to binary operation"sv),((lhs_value).type_name()),((rhs_value).type_name())))),span))));
return Error::from_errno((infallible_integer_cast<i32>((interpreter::InterpretError::InvalidType))));
}
};/*case end*/
}/*switch end*/
}()
)));
};/*case end*/
case 9: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::I64>();
i64 const& x = __jakt_match_value.value;
return JaktInternal::ExplicitValue(JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<NonnullRefPtr<typename types::ValueImpl>, ErrorOr<interpreter::StatementResult>>{
auto&& __jakt_match_variant = *((rhs_value).impl);
switch(__jakt_match_variant.index()) {
case 9: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::I64>();
i64 const& y = __jakt_match_value.value;
return JaktInternal::ExplicitValue(TRY((types::ValueImpl::template create<typename types::ValueImpl::I64>((JaktInternal::checked_add<i64>(x,y))))));
};/*case end*/
default: {
{
TRY((((*this).error(TRY((__jakt_format(Jakt::DeprecatedString("Invalid operands '{}' and '{}' to binary operation"sv),((lhs_value).type_name()),((rhs_value).type_name())))),span))));
return Error::from_errno((infallible_integer_cast<i32>((interpreter::InterpretError::InvalidType))));
}
};/*case end*/
}/*switch end*/
}()
)));
};/*case end*/
case 10: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::F32>();
f32 const& x = __jakt_match_value.value;
return JaktInternal::ExplicitValue(JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<NonnullRefPtr<typename types::ValueImpl>, ErrorOr<interpreter::StatementResult>>{
auto&& __jakt_match_variant = *((rhs_value).impl);
switch(__jakt_match_variant.index()) {
case 10: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::F32>();
f32 const& y = __jakt_match_value.value;
return JaktInternal::ExplicitValue(TRY((types::ValueImpl::template create<typename types::ValueImpl::F32>((x + y)))));
};/*case end*/
default: {
{
TRY((((*this).error(TRY((__jakt_format(Jakt::DeprecatedString("Invalid operands '{}' and '{}' to binary operation"sv),((lhs_value).type_name()),((rhs_value).type_name())))),span))));
return Error::from_errno((infallible_integer_cast<i32>((interpreter::InterpretError::InvalidType))));
}
};/*case end*/
}/*switch end*/
}()
)));
};/*case end*/
case 11: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::F64>();
f64 const& x = __jakt_match_value.value;
return JaktInternal::ExplicitValue(JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<NonnullRefPtr<typename types::ValueImpl>, ErrorOr<interpreter::StatementResult>>{
auto&& __jakt_match_variant = *((rhs_value).impl);
switch(__jakt_match_variant.index()) {
case 11: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::F64>();
f64 const& y = __jakt_match_value.value;
return JaktInternal::ExplicitValue(TRY((types::ValueImpl::template create<typename types::ValueImpl::F64>((x + y)))));
};/*case end*/
default: {
{
TRY((((*this).error(TRY((__jakt_format(Jakt::DeprecatedString("Invalid operands '{}' and '{}' to binary operation"sv),((lhs_value).type_name()),((rhs_value).type_name())))),span))));
return Error::from_errno((infallible_integer_cast<i32>((interpreter::InterpretError::InvalidType))));
}
};/*case end*/
}/*switch end*/
}()
)));
};/*case end*/
case 12: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::USize>();
size_t const& x = __jakt_match_value.value;
return JaktInternal::ExplicitValue(JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<NonnullRefPtr<typename types::ValueImpl>, ErrorOr<interpreter::StatementResult>>{
auto&& __jakt_match_variant = *((rhs_value).impl);
switch(__jakt_match_variant.index()) {
case 12: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::USize>();
size_t const& y = __jakt_match_value.value;
return JaktInternal::ExplicitValue(TRY((types::ValueImpl::template create<typename types::ValueImpl::USize>((JaktInternal::checked_add<size_t>(x,y))))));
};/*case end*/
default: {
{
TRY((((*this).error(TRY((__jakt_format(Jakt::DeprecatedString("Invalid operands '{}' and '{}' to binary operation"sv),((lhs_value).type_name()),((rhs_value).type_name())))),span))));
return Error::from_errno((infallible_integer_cast<i32>((interpreter::InterpretError::InvalidType))));
}
};/*case end*/
}/*switch end*/
}()
)));
};/*case end*/
case 13: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::JaktString>();
DeprecatedString const& x = __jakt_match_value.value;
return JaktInternal::ExplicitValue(JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<NonnullRefPtr<typename types::ValueImpl>, ErrorOr<interpreter::StatementResult>>{
auto&& __jakt_match_variant = *((rhs_value).impl);
switch(__jakt_match_variant.index()) {
case 13: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::JaktString>();
DeprecatedString const& y = __jakt_match_value.value;
return JaktInternal::ExplicitValue(TRY((types::ValueImpl::template create<typename types::ValueImpl::JaktString>((x + y)))));
};/*case end*/
default: {
{
TRY((((*this).error(TRY((__jakt_format(Jakt::DeprecatedString("Invalid operands '{}' and '{}' to binary operation"sv),((lhs_value).type_name()),((rhs_value).type_name())))),span))));
return Error::from_errno((infallible_integer_cast<i32>((interpreter::InterpretError::InvalidType))));
}
};/*case end*/
}/*switch end*/
}()
)));
};/*case end*/
default: {
{
TRY((((*this).error(TRY((__jakt_format(Jakt::DeprecatedString("Invalid operands '{}' and '{}' to binary operation"sv),((lhs_value).type_name()),((rhs_value).type_name())))),span))));
return Error::from_errno((infallible_integer_cast<i32>((interpreter::InterpretError::InvalidType))));
}
};/*case end*/
}/*switch end*/
}()
)),span)) } );
};/*case end*/
case 1: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename parser::BinaryOperator::Subtract>();
return JaktInternal::ExplicitValue( interpreter::StatementResult { typename interpreter::StatementResult::JustValue(types::Value(JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<NonnullRefPtr<typename types::ValueImpl>, ErrorOr<interpreter::StatementResult>>{
auto&& __jakt_match_variant = *((lhs_value).impl);
switch(__jakt_match_variant.index()) {
case 2: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::U8>();
u8 const& x = __jakt_match_value.value;
return JaktInternal::ExplicitValue(JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<NonnullRefPtr<typename types::ValueImpl>, ErrorOr<interpreter::StatementResult>>{
auto&& __jakt_match_variant = *((rhs_value).impl);
switch(__jakt_match_variant.index()) {
case 2: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::U8>();
u8 const& y = __jakt_match_value.value;
return JaktInternal::ExplicitValue(TRY((types::ValueImpl::template create<typename types::ValueImpl::U8>((JaktInternal::checked_sub<u8>(x,y))))));
};/*case end*/
default: {
{
TRY((((*this).error(TRY((__jakt_format(Jakt::DeprecatedString("Invalid operands '{}' and '{}' to binary operation"sv),((lhs_value).type_name()),((rhs_value).type_name())))),span))));
return Error::from_errno((infallible_integer_cast<i32>((interpreter::InterpretError::InvalidType))));
}
};/*case end*/
}/*switch end*/
}()
)));
};/*case end*/
case 3: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::U16>();
u16 const& x = __jakt_match_value.value;
return JaktInternal::ExplicitValue(JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<NonnullRefPtr<typename types::ValueImpl>, ErrorOr<interpreter::StatementResult>>{
auto&& __jakt_match_variant = *((rhs_value).impl);
switch(__jakt_match_variant.index()) {
case 3: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::U16>();
u16 const& y = __jakt_match_value.value;
return JaktInternal::ExplicitValue(TRY((types::ValueImpl::template create<typename types::ValueImpl::U16>((JaktInternal::checked_sub<u16>(x,y))))));
};/*case end*/
default: {
{
TRY((((*this).error(TRY((__jakt_format(Jakt::DeprecatedString("Invalid operands '{}' and '{}' to binary operation"sv),((lhs_value).type_name()),((rhs_value).type_name())))),span))));
return Error::from_errno((infallible_integer_cast<i32>((interpreter::InterpretError::InvalidType))));
}
};/*case end*/
}/*switch end*/
}()
)));
};/*case end*/
case 4: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::U32>();
u32 const& x = __jakt_match_value.value;
return JaktInternal::ExplicitValue(JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<NonnullRefPtr<typename types::ValueImpl>, ErrorOr<interpreter::StatementResult>>{
auto&& __jakt_match_variant = *((rhs_value).impl);
switch(__jakt_match_variant.index()) {
case 4: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::U32>();
u32 const& y = __jakt_match_value.value;
return JaktInternal::ExplicitValue(TRY((types::ValueImpl::template create<typename types::ValueImpl::U32>((JaktInternal::checked_sub<u32>(x,y))))));
};/*case end*/
default: {
{
TRY((((*this).error(TRY((__jakt_format(Jakt::DeprecatedString("Invalid operands '{}' and '{}' to binary operation"sv),((lhs_value).type_name()),((rhs_value).type_name())))),span))));
return Error::from_errno((infallible_integer_cast<i32>((interpreter::InterpretError::InvalidType))));
}
};/*case end*/
}/*switch end*/
}()
)));
};/*case end*/
case 5: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::U64>();
u64 const& x = __jakt_match_value.value;
return JaktInternal::ExplicitValue(JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<NonnullRefPtr<typename types::ValueImpl>, ErrorOr<interpreter::StatementResult>>{
auto&& __jakt_match_variant = *((rhs_value).impl);
switch(__jakt_match_variant.index()) {
case 5: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::U64>();
u64 const& y = __jakt_match_value.value;
return JaktInternal::ExplicitValue(TRY((types::ValueImpl::template create<typename types::ValueImpl::U64>((JaktInternal::checked_sub<u64>(x,y))))));
};/*case end*/
default: {
{
TRY((((*this).error(TRY((__jakt_format(Jakt::DeprecatedString("Invalid operands '{}' and '{}' to binary operation"sv),((lhs_value).type_name()),((rhs_value).type_name())))),span))));
return Error::from_errno((infallible_integer_cast<i32>((interpreter::InterpretError::InvalidType))));
}
};/*case end*/
}/*switch end*/
}()
)));
};/*case end*/
case 6: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::I8>();
i8 const& x = __jakt_match_value.value;
return JaktInternal::ExplicitValue(JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<NonnullRefPtr<typename types::ValueImpl>, ErrorOr<interpreter::StatementResult>>{
auto&& __jakt_match_variant = *((rhs_value).impl);
switch(__jakt_match_variant.index()) {
case 6: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::I8>();
i8 const& y = __jakt_match_value.value;
return JaktInternal::ExplicitValue(TRY((types::ValueImpl::template create<typename types::ValueImpl::I8>((JaktInternal::checked_sub<i8>(x,y))))));
};/*case end*/
default: {
{
TRY((((*this).error(TRY((__jakt_format(Jakt::DeprecatedString("Invalid operands '{}' and '{}' to binary operation"sv),((lhs_value).type_name()),((rhs_value).type_name())))),span))));
return Error::from_errno((infallible_integer_cast<i32>((interpreter::InterpretError::InvalidType))));
}
};/*case end*/
}/*switch end*/
}()
)));
};/*case end*/
case 7: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::I16>();
i16 const& x = __jakt_match_value.value;
return JaktInternal::ExplicitValue(JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<NonnullRefPtr<typename types::ValueImpl>, ErrorOr<interpreter::StatementResult>>{
auto&& __jakt_match_variant = *((rhs_value).impl);
switch(__jakt_match_variant.index()) {
case 7: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::I16>();
i16 const& y = __jakt_match_value.value;
return JaktInternal::ExplicitValue(TRY((types::ValueImpl::template create<typename types::ValueImpl::I16>((JaktInternal::checked_sub<i16>(x,y))))));
};/*case end*/
default: {
{
TRY((((*this).error(TRY((__jakt_format(Jakt::DeprecatedString("Invalid operands '{}' and '{}' to binary operation"sv),((lhs_value).type_name()),((rhs_value).type_name())))),span))));
return Error::from_errno((infallible_integer_cast<i32>((interpreter::InterpretError::InvalidType))));
}
};/*case end*/
}/*switch end*/
}()
)));
};/*case end*/
case 8: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::I32>();
i32 const& x = __jakt_match_value.value;
return JaktInternal::ExplicitValue(JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<NonnullRefPtr<typename types::ValueImpl>, ErrorOr<interpreter::StatementResult>>{
auto&& __jakt_match_variant = *((rhs_value).impl);
switch(__jakt_match_variant.index()) {
case 8: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::I32>();
i32 const& y = __jakt_match_value.value;
return JaktInternal::ExplicitValue(TRY((types::ValueImpl::template create<typename types::ValueImpl::I32>((JaktInternal::checked_sub<i32>(x,y))))));
};/*case end*/
default: {
{
TRY((((*this).error(TRY((__jakt_format(Jakt::DeprecatedString("Invalid operands '{}' and '{}' to binary operation"sv),((lhs_value).type_name()),((rhs_value).type_name())))),span))));
return Error::from_errno((infallible_integer_cast<i32>((interpreter::InterpretError::InvalidType))));
}
};/*case end*/
}/*switch end*/
}()
)));
};/*case end*/
case 9: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::I64>();
i64 const& x = __jakt_match_value.value;
return JaktInternal::ExplicitValue(JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<NonnullRefPtr<typename types::ValueImpl>, ErrorOr<interpreter::StatementResult>>{
auto&& __jakt_match_variant = *((rhs_value).impl);
switch(__jakt_match_variant.index()) {
case 9: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::I64>();
i64 const& y = __jakt_match_value.value;
return JaktInternal::ExplicitValue(TRY((types::ValueImpl::template create<typename types::ValueImpl::I64>((JaktInternal::checked_sub<i64>(x,y))))));
};/*case end*/
default: {
{
TRY((((*this).error(TRY((__jakt_format(Jakt::DeprecatedString("Invalid operands '{}' and '{}' to binary operation"sv),((lhs_value).type_name()),((rhs_value).type_name())))),span))));
return Error::from_errno((infallible_integer_cast<i32>((interpreter::InterpretError::InvalidType))));
}
};/*case end*/
}/*switch end*/
}()
)));
};/*case end*/
case 10: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::F32>();
f32 const& x = __jakt_match_value.value;
return JaktInternal::ExplicitValue(JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<NonnullRefPtr<typename types::ValueImpl>, ErrorOr<interpreter::StatementResult>>{
auto&& __jakt_match_variant = *((rhs_value).impl);
switch(__jakt_match_variant.index()) {
case 10: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::F32>();
f32 const& y = __jakt_match_value.value;
return JaktInternal::ExplicitValue(TRY((types::ValueImpl::template create<typename types::ValueImpl::F32>((x - y)))));
};/*case end*/
default: {
{
TRY((((*this).error(TRY((__jakt_format(Jakt::DeprecatedString("Invalid operands '{}' and '{}' to binary operation"sv),((lhs_value).type_name()),((rhs_value).type_name())))),span))));
return Error::from_errno((infallible_integer_cast<i32>((interpreter::InterpretError::InvalidType))));
}
};/*case end*/
}/*switch end*/
}()
)));
};/*case end*/
case 11: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::F64>();
f64 const& x = __jakt_match_value.value;
return JaktInternal::ExplicitValue(JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<NonnullRefPtr<typename types::ValueImpl>, ErrorOr<interpreter::StatementResult>>{
auto&& __jakt_match_variant = *((rhs_value).impl);
switch(__jakt_match_variant.index()) {
case 11: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::F64>();
f64 const& y = __jakt_match_value.value;
return JaktInternal::ExplicitValue(TRY((types::ValueImpl::template create<typename types::ValueImpl::F64>((x - y)))));
};/*case end*/
default: {
{
TRY((((*this).error(TRY((__jakt_format(Jakt::DeprecatedString("Invalid operands '{}' and '{}' to binary operation"sv),((lhs_value).type_name()),((rhs_value).type_name())))),span))));
return Error::from_errno((infallible_integer_cast<i32>((interpreter::InterpretError::InvalidType))));
}
};/*case end*/
}/*switch end*/
}()
)));
};/*case end*/
case 12: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::USize>();
size_t const& x = __jakt_match_value.value;
return JaktInternal::ExplicitValue(JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<NonnullRefPtr<typename types::ValueImpl>, ErrorOr<interpreter::StatementResult>>{
auto&& __jakt_match_variant = *((rhs_value).impl);
switch(__jakt_match_variant.index()) {
case 12: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::USize>();
size_t const& y = __jakt_match_value.value;
return JaktInternal::ExplicitValue(TRY((types::ValueImpl::template create<typename types::ValueImpl::USize>((JaktInternal::checked_sub<size_t>(x,y))))));
};/*case end*/
default: {
{
TRY((((*this).error(TRY((__jakt_format(Jakt::DeprecatedString("Invalid operands '{}' and '{}' to binary operation"sv),((lhs_value).type_name()),((rhs_value).type_name())))),span))));
return Error::from_errno((infallible_integer_cast<i32>((interpreter::InterpretError::InvalidType))));
}
};/*case end*/
}/*switch end*/
}()
)));
};/*case end*/
default: {
{
TRY((((*this).error(TRY((__jakt_format(Jakt::DeprecatedString("Invalid operands '{}' and '{}' to binary operation"sv),((lhs_value).type_name()),((rhs_value).type_name())))),span))));
return Error::from_errno((infallible_integer_cast<i32>((interpreter::InterpretError::InvalidType))));
}
};/*case end*/
}/*switch end*/
}()
)),span)) } );
};/*case end*/
case 2: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename parser::BinaryOperator::Multiply>();
return JaktInternal::ExplicitValue( interpreter::StatementResult { typename interpreter::StatementResult::JustValue(types::Value(JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<NonnullRefPtr<typename types::ValueImpl>, ErrorOr<interpreter::StatementResult>>{
auto&& __jakt_match_variant = *((lhs_value).impl);
switch(__jakt_match_variant.index()) {
case 2: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::U8>();
u8 const& x = __jakt_match_value.value;
return JaktInternal::ExplicitValue(JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<NonnullRefPtr<typename types::ValueImpl>, ErrorOr<interpreter::StatementResult>>{
auto&& __jakt_match_variant = *((rhs_value).impl);
switch(__jakt_match_variant.index()) {
case 2: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::U8>();
u8 const& y = __jakt_match_value.value;
return JaktInternal::ExplicitValue(TRY((types::ValueImpl::template create<typename types::ValueImpl::U8>((JaktInternal::checked_mul<u8>(x,y))))));
};/*case end*/
default: {
{
TRY((((*this).error(TRY((__jakt_format(Jakt::DeprecatedString("Invalid operands '{}' and '{}' to binary operation"sv),((lhs_value).type_name()),((rhs_value).type_name())))),span))));
return Error::from_errno((infallible_integer_cast<i32>((interpreter::InterpretError::InvalidType))));
}
};/*case end*/
}/*switch end*/
}()
)));
};/*case end*/
case 3: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::U16>();
u16 const& x = __jakt_match_value.value;
return JaktInternal::ExplicitValue(JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<NonnullRefPtr<typename types::ValueImpl>, ErrorOr<interpreter::StatementResult>>{
auto&& __jakt_match_variant = *((rhs_value).impl);
switch(__jakt_match_variant.index()) {
case 3: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::U16>();
u16 const& y = __jakt_match_value.value;
return JaktInternal::ExplicitValue(TRY((types::ValueImpl::template create<typename types::ValueImpl::U16>((JaktInternal::checked_mul<u16>(x,y))))));
};/*case end*/
default: {
{
TRY((((*this).error(TRY((__jakt_format(Jakt::DeprecatedString("Invalid operands '{}' and '{}' to binary operation"sv),((lhs_value).type_name()),((rhs_value).type_name())))),span))));
return Error::from_errno((infallible_integer_cast<i32>((interpreter::InterpretError::InvalidType))));
}
};/*case end*/
}/*switch end*/
}()
)));
};/*case end*/
case 4: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::U32>();
u32 const& x = __jakt_match_value.value;
return JaktInternal::ExplicitValue(JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<NonnullRefPtr<typename types::ValueImpl>, ErrorOr<interpreter::StatementResult>>{
auto&& __jakt_match_variant = *((rhs_value).impl);
switch(__jakt_match_variant.index()) {
case 4: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::U32>();
u32 const& y = __jakt_match_value.value;
return JaktInternal::ExplicitValue(TRY((types::ValueImpl::template create<typename types::ValueImpl::U32>((JaktInternal::checked_mul<u32>(x,y))))));
};/*case end*/
default: {
{
TRY((((*this).error(TRY((__jakt_format(Jakt::DeprecatedString("Invalid operands '{}' and '{}' to binary operation"sv),((lhs_value).type_name()),((rhs_value).type_name())))),span))));
return Error::from_errno((infallible_integer_cast<i32>((interpreter::InterpretError::InvalidType))));
}
};/*case end*/
}/*switch end*/
}()
)));
};/*case end*/
case 5: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::U64>();
u64 const& x = __jakt_match_value.value;
return JaktInternal::ExplicitValue(JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<NonnullRefPtr<typename types::ValueImpl>, ErrorOr<interpreter::StatementResult>>{
auto&& __jakt_match_variant = *((rhs_value).impl);
switch(__jakt_match_variant.index()) {
case 5: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::U64>();
u64 const& y = __jakt_match_value.value;
return JaktInternal::ExplicitValue(TRY((types::ValueImpl::template create<typename types::ValueImpl::U64>((JaktInternal::checked_mul<u64>(x,y))))));
};/*case end*/
default: {
{
TRY((((*this).error(TRY((__jakt_format(Jakt::DeprecatedString("Invalid operands '{}' and '{}' to binary operation"sv),((lhs_value).type_name()),((rhs_value).type_name())))),span))));
return Error::from_errno((infallible_integer_cast<i32>((interpreter::InterpretError::InvalidType))));
}
};/*case end*/
}/*switch end*/
}()
)));
};/*case end*/
case 6: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::I8>();
i8 const& x = __jakt_match_value.value;
return JaktInternal::ExplicitValue(JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<NonnullRefPtr<typename types::ValueImpl>, ErrorOr<interpreter::StatementResult>>{
auto&& __jakt_match_variant = *((rhs_value).impl);
switch(__jakt_match_variant.index()) {
case 6: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::I8>();
i8 const& y = __jakt_match_value.value;
return JaktInternal::ExplicitValue(TRY((types::ValueImpl::template create<typename types::ValueImpl::I8>((JaktInternal::checked_mul<i8>(x,y))))));
};/*case end*/
default: {
{
TRY((((*this).error(TRY((__jakt_format(Jakt::DeprecatedString("Invalid operands '{}' and '{}' to binary operation"sv),((lhs_value).type_name()),((rhs_value).type_name())))),span))));
return Error::from_errno((infallible_integer_cast<i32>((interpreter::InterpretError::InvalidType))));
}
};/*case end*/
}/*switch end*/
}()
)));
};/*case end*/
case 7: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::I16>();
i16 const& x = __jakt_match_value.value;
return JaktInternal::ExplicitValue(JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<NonnullRefPtr<typename types::ValueImpl>, ErrorOr<interpreter::StatementResult>>{
auto&& __jakt_match_variant = *((rhs_value).impl);
switch(__jakt_match_variant.index()) {
case 7: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::I16>();
i16 const& y = __jakt_match_value.value;
return JaktInternal::ExplicitValue(TRY((types::ValueImpl::template create<typename types::ValueImpl::I16>((JaktInternal::checked_mul<i16>(x,y))))));
};/*case end*/
default: {
{
TRY((((*this).error(TRY((__jakt_format(Jakt::DeprecatedString("Invalid operands '{}' and '{}' to binary operation"sv),((lhs_value).type_name()),((rhs_value).type_name())))),span))));
return Error::from_errno((infallible_integer_cast<i32>((interpreter::InterpretError::InvalidType))));
}
};/*case end*/
}/*switch end*/
}()
)));
};/*case end*/
case 8: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::I32>();
i32 const& x = __jakt_match_value.value;
return JaktInternal::ExplicitValue(JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<NonnullRefPtr<typename types::ValueImpl>, ErrorOr<interpreter::StatementResult>>{
auto&& __jakt_match_variant = *((rhs_value).impl);
switch(__jakt_match_variant.index()) {
case 8: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::I32>();
i32 const& y = __jakt_match_value.value;
return JaktInternal::ExplicitValue(TRY((types::ValueImpl::template create<typename types::ValueImpl::I32>((JaktInternal::checked_mul<i32>(x,y))))));
};/*case end*/
default: {
{
TRY((((*this).error(TRY((__jakt_format(Jakt::DeprecatedString("Invalid operands '{}' and '{}' to binary operation"sv),((lhs_value).type_name()),((rhs_value).type_name())))),span))));
return Error::from_errno((infallible_integer_cast<i32>((interpreter::InterpretError::InvalidType))));
}
};/*case end*/
}/*switch end*/
}()
)));
};/*case end*/
case 9: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::I64>();
i64 const& x = __jakt_match_value.value;
return JaktInternal::ExplicitValue(JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<NonnullRefPtr<typename types::ValueImpl>, ErrorOr<interpreter::StatementResult>>{
auto&& __jakt_match_variant = *((rhs_value).impl);
switch(__jakt_match_variant.index()) {
case 9: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::I64>();
i64 const& y = __jakt_match_value.value;
return JaktInternal::ExplicitValue(TRY((types::ValueImpl::template create<typename types::ValueImpl::I64>((JaktInternal::checked_mul<i64>(x,y))))));
};/*case end*/
default: {
{
TRY((((*this).error(TRY((__jakt_format(Jakt::DeprecatedString("Invalid operands '{}' and '{}' to binary operation"sv),((lhs_value).type_name()),((rhs_value).type_name())))),span))));
return Error::from_errno((infallible_integer_cast<i32>((interpreter::InterpretError::InvalidType))));
}
};/*case end*/
}/*switch end*/
}()
)));
};/*case end*/
case 10: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::F32>();
f32 const& x = __jakt_match_value.value;
return JaktInternal::ExplicitValue(JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<NonnullRefPtr<typename types::ValueImpl>, ErrorOr<interpreter::StatementResult>>{
auto&& __jakt_match_variant = *((rhs_value).impl);
switch(__jakt_match_variant.index()) {
case 10: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::F32>();
f32 const& y = __jakt_match_value.value;
return JaktInternal::ExplicitValue(TRY((types::ValueImpl::template create<typename types::ValueImpl::F32>((x * y)))));
};/*case end*/
default: {
{
TRY((((*this).error(TRY((__jakt_format(Jakt::DeprecatedString("Invalid operands '{}' and '{}' to binary operation"sv),((lhs_value).type_name()),((rhs_value).type_name())))),span))));
return Error::from_errno((infallible_integer_cast<i32>((interpreter::InterpretError::InvalidType))));
}
};/*case end*/
}/*switch end*/
}()
)));
};/*case end*/
case 11: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::F64>();
f64 const& x = __jakt_match_value.value;
return JaktInternal::ExplicitValue(JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<NonnullRefPtr<typename types::ValueImpl>, ErrorOr<interpreter::StatementResult>>{
auto&& __jakt_match_variant = *((rhs_value).impl);
switch(__jakt_match_variant.index()) {
case 11: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::F64>();
f64 const& y = __jakt_match_value.value;
return JaktInternal::ExplicitValue(TRY((types::ValueImpl::template create<typename types::ValueImpl::F64>((x * y)))));
};/*case end*/
default: {
{
TRY((((*this).error(TRY((__jakt_format(Jakt::DeprecatedString("Invalid operands '{}' and '{}' to binary operation"sv),((lhs_value).type_name()),((rhs_value).type_name())))),span))));
return Error::from_errno((infallible_integer_cast<i32>((interpreter::InterpretError::InvalidType))));
}
};/*case end*/
}/*switch end*/
}()
)));
};/*case end*/
case 12: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::USize>();
size_t const& x = __jakt_match_value.value;
return JaktInternal::ExplicitValue(JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<NonnullRefPtr<typename types::ValueImpl>, ErrorOr<interpreter::StatementResult>>{
auto&& __jakt_match_variant = *((rhs_value).impl);
switch(__jakt_match_variant.index()) {
case 12: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::USize>();
size_t const& y = __jakt_match_value.value;
return JaktInternal::ExplicitValue(TRY((types::ValueImpl::template create<typename types::ValueImpl::USize>((JaktInternal::checked_mul<size_t>(x,y))))));
};/*case end*/
default: {
{
TRY((((*this).error(TRY((__jakt_format(Jakt::DeprecatedString("Invalid operands '{}' and '{}' to binary operation"sv),((lhs_value).type_name()),((rhs_value).type_name())))),span))));
return Error::from_errno((infallible_integer_cast<i32>((interpreter::InterpretError::InvalidType))));
}
};/*case end*/
}/*switch end*/
}()
)));
};/*case end*/
default: {
{
TRY((((*this).error(TRY((__jakt_format(Jakt::DeprecatedString("Invalid operands '{}' and '{}' to binary operation"sv),((lhs_value).type_name()),((rhs_value).type_name())))),span))));
return Error::from_errno((infallible_integer_cast<i32>((interpreter::InterpretError::InvalidType))));
}
};/*case end*/
}/*switch end*/
}()
)),span)) } );
};/*case end*/
case 3: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename parser::BinaryOperator::Divide>();
return JaktInternal::ExplicitValue( interpreter::StatementResult { typename interpreter::StatementResult::JustValue(types::Value(JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<NonnullRefPtr<typename types::ValueImpl>, ErrorOr<interpreter::StatementResult>>{
auto&& __jakt_match_variant = *((lhs_value).impl);
switch(__jakt_match_variant.index()) {
case 2: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::U8>();
u8 const& x = __jakt_match_value.value;
return JaktInternal::ExplicitValue(JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<NonnullRefPtr<typename types::ValueImpl>, ErrorOr<interpreter::StatementResult>>{
auto&& __jakt_match_variant = *((rhs_value).impl);
switch(__jakt_match_variant.index()) {
case 2: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::U8>();
u8 const& y = __jakt_match_value.value;
return JaktInternal::ExplicitValue(TRY((types::ValueImpl::template create<typename types::ValueImpl::U8>((JaktInternal::checked_div<u8>(x,y))))));
};/*case end*/
default: {
{
TRY((((*this).error(TRY((__jakt_format(Jakt::DeprecatedString("Invalid operands '{}' and '{}' to binary operation"sv),((lhs_value).type_name()),((rhs_value).type_name())))),span))));
return Error::from_errno((infallible_integer_cast<i32>((interpreter::InterpretError::InvalidType))));
}
};/*case end*/
}/*switch end*/
}()
)));
};/*case end*/
case 3: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::U16>();
u16 const& x = __jakt_match_value.value;
return JaktInternal::ExplicitValue(JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<NonnullRefPtr<typename types::ValueImpl>, ErrorOr<interpreter::StatementResult>>{
auto&& __jakt_match_variant = *((rhs_value).impl);
switch(__jakt_match_variant.index()) {
case 3: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::U16>();
u16 const& y = __jakt_match_value.value;
return JaktInternal::ExplicitValue(TRY((types::ValueImpl::template create<typename types::ValueImpl::U16>((JaktInternal::checked_div<u16>(x,y))))));
};/*case end*/
default: {
{
TRY((((*this).error(TRY((__jakt_format(Jakt::DeprecatedString("Invalid operands '{}' and '{}' to binary operation"sv),((lhs_value).type_name()),((rhs_value).type_name())))),span))));
return Error::from_errno((infallible_integer_cast<i32>((interpreter::InterpretError::InvalidType))));
}
};/*case end*/
}/*switch end*/
}()
)));
};/*case end*/
case 4: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::U32>();
u32 const& x = __jakt_match_value.value;
return JaktInternal::ExplicitValue(JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<NonnullRefPtr<typename types::ValueImpl>, ErrorOr<interpreter::StatementResult>>{
auto&& __jakt_match_variant = *((rhs_value).impl);
switch(__jakt_match_variant.index()) {
case 4: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::U32>();
u32 const& y = __jakt_match_value.value;
return JaktInternal::ExplicitValue(TRY((types::ValueImpl::template create<typename types::ValueImpl::U32>((JaktInternal::checked_div<u32>(x,y))))));
};/*case end*/
default: {
{
TRY((((*this).error(TRY((__jakt_format(Jakt::DeprecatedString("Invalid operands '{}' and '{}' to binary operation"sv),((lhs_value).type_name()),((rhs_value).type_name())))),span))));
return Error::from_errno((infallible_integer_cast<i32>((interpreter::InterpretError::InvalidType))));
}
};/*case end*/
}/*switch end*/
}()
)));
};/*case end*/
case 5: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::U64>();
u64 const& x = __jakt_match_value.value;
return JaktInternal::ExplicitValue(JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<NonnullRefPtr<typename types::ValueImpl>, ErrorOr<interpreter::StatementResult>>{
auto&& __jakt_match_variant = *((rhs_value).impl);
switch(__jakt_match_variant.index()) {
case 5: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::U64>();
u64 const& y = __jakt_match_value.value;
return JaktInternal::ExplicitValue(TRY((types::ValueImpl::template create<typename types::ValueImpl::U64>((JaktInternal::checked_div<u64>(x,y))))));
};/*case end*/
default: {
{
TRY((((*this).error(TRY((__jakt_format(Jakt::DeprecatedString("Invalid operands '{}' and '{}' to binary operation"sv),((lhs_value).type_name()),((rhs_value).type_name())))),span))));
return Error::from_errno((infallible_integer_cast<i32>((interpreter::InterpretError::InvalidType))));
}
};/*case end*/
}/*switch end*/
}()
)));
};/*case end*/
case 6: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::I8>();
i8 const& x = __jakt_match_value.value;
return JaktInternal::ExplicitValue(JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<NonnullRefPtr<typename types::ValueImpl>, ErrorOr<interpreter::StatementResult>>{
auto&& __jakt_match_variant = *((rhs_value).impl);
switch(__jakt_match_variant.index()) {
case 6: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::I8>();
i8 const& y = __jakt_match_value.value;
return JaktInternal::ExplicitValue(TRY((types::ValueImpl::template create<typename types::ValueImpl::I8>((JaktInternal::checked_div<i8>(x,y))))));
};/*case end*/
default: {
{
TRY((((*this).error(TRY((__jakt_format(Jakt::DeprecatedString("Invalid operands '{}' and '{}' to binary operation"sv),((lhs_value).type_name()),((rhs_value).type_name())))),span))));
return Error::from_errno((infallible_integer_cast<i32>((interpreter::InterpretError::InvalidType))));
}
};/*case end*/
}/*switch end*/
}()
)));
};/*case end*/
case 7: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::I16>();
i16 const& x = __jakt_match_value.value;
return JaktInternal::ExplicitValue(JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<NonnullRefPtr<typename types::ValueImpl>, ErrorOr<interpreter::StatementResult>>{
auto&& __jakt_match_variant = *((rhs_value).impl);
switch(__jakt_match_variant.index()) {
case 7: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::I16>();
i16 const& y = __jakt_match_value.value;
return JaktInternal::ExplicitValue(TRY((types::ValueImpl::template create<typename types::ValueImpl::I16>((JaktInternal::checked_div<i16>(x,y))))));
};/*case end*/
default: {
{
TRY((((*this).error(TRY((__jakt_format(Jakt::DeprecatedString("Invalid operands '{}' and '{}' to binary operation"sv),((lhs_value).type_name()),((rhs_value).type_name())))),span))));
return Error::from_errno((infallible_integer_cast<i32>((interpreter::InterpretError::InvalidType))));
}
};/*case end*/
}/*switch end*/
}()
)));
};/*case end*/
case 8: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::I32>();
i32 const& x = __jakt_match_value.value;
return JaktInternal::ExplicitValue(JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<NonnullRefPtr<typename types::ValueImpl>, ErrorOr<interpreter::StatementResult>>{
auto&& __jakt_match_variant = *((rhs_value).impl);
switch(__jakt_match_variant.index()) {
case 8: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::I32>();
i32 const& y = __jakt_match_value.value;
return JaktInternal::ExplicitValue(TRY((types::ValueImpl::template create<typename types::ValueImpl::I32>((JaktInternal::checked_div<i32>(x,y))))));
};/*case end*/
default: {
{
TRY((((*this).error(TRY((__jakt_format(Jakt::DeprecatedString("Invalid operands '{}' and '{}' to binary operation"sv),((lhs_value).type_name()),((rhs_value).type_name())))),span))));
return Error::from_errno((infallible_integer_cast<i32>((interpreter::InterpretError::InvalidType))));
}
};/*case end*/
}/*switch end*/
}()
)));
};/*case end*/
case 9: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::I64>();
i64 const& x = __jakt_match_value.value;
return JaktInternal::ExplicitValue(JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<NonnullRefPtr<typename types::ValueImpl>, ErrorOr<interpreter::StatementResult>>{
auto&& __jakt_match_variant = *((rhs_value).impl);
switch(__jakt_match_variant.index()) {
case 9: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::I64>();
i64 const& y = __jakt_match_value.value;
return JaktInternal::ExplicitValue(TRY((types::ValueImpl::template create<typename types::ValueImpl::I64>((JaktInternal::checked_div<i64>(x,y))))));
};/*case end*/
default: {
{
TRY((((*this).error(TRY((__jakt_format(Jakt::DeprecatedString("Invalid operands '{}' and '{}' to binary operation"sv),((lhs_value).type_name()),((rhs_value).type_name())))),span))));
return Error::from_errno((infallible_integer_cast<i32>((interpreter::InterpretError::InvalidType))));
}
};/*case end*/
}/*switch end*/
}()
)));
};/*case end*/
case 10: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::F32>();
f32 const& x = __jakt_match_value.value;
return JaktInternal::ExplicitValue(JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<NonnullRefPtr<typename types::ValueImpl>, ErrorOr<interpreter::StatementResult>>{
auto&& __jakt_match_variant = *((rhs_value).impl);
switch(__jakt_match_variant.index()) {
case 10: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::F32>();
f32 const& y = __jakt_match_value.value;
return JaktInternal::ExplicitValue(TRY((types::ValueImpl::template create<typename types::ValueImpl::F32>((x / y)))));
};/*case end*/
default: {
{
TRY((((*this).error(TRY((__jakt_format(Jakt::DeprecatedString("Invalid operands '{}' and '{}' to binary operation"sv),((lhs_value).type_name()),((rhs_value).type_name())))),span))));
return Error::from_errno((infallible_integer_cast<i32>((interpreter::InterpretError::InvalidType))));
}
};/*case end*/
}/*switch end*/
}()
)));
};/*case end*/
case 11: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::F64>();
f64 const& x = __jakt_match_value.value;
return JaktInternal::ExplicitValue(JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<NonnullRefPtr<typename types::ValueImpl>, ErrorOr<interpreter::StatementResult>>{
auto&& __jakt_match_variant = *((rhs_value).impl);
switch(__jakt_match_variant.index()) {
case 11: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::F64>();
f64 const& y = __jakt_match_value.value;
return JaktInternal::ExplicitValue(TRY((types::ValueImpl::template create<typename types::ValueImpl::F64>((x / y)))));
};/*case end*/
default: {
{
TRY((((*this).error(TRY((__jakt_format(Jakt::DeprecatedString("Invalid operands '{}' and '{}' to binary operation"sv),((lhs_value).type_name()),((rhs_value).type_name())))),span))));
return Error::from_errno((infallible_integer_cast<i32>((interpreter::InterpretError::InvalidType))));
}
};/*case end*/
}/*switch end*/
}()
)));
};/*case end*/
case 12: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::USize>();
size_t const& x = __jakt_match_value.value;
return JaktInternal::ExplicitValue(JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<NonnullRefPtr<typename types::ValueImpl>, ErrorOr<interpreter::StatementResult>>{
auto&& __jakt_match_variant = *((rhs_value).impl);
switch(__jakt_match_variant.index()) {
case 12: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::USize>();
size_t const& y = __jakt_match_value.value;
return JaktInternal::ExplicitValue(TRY((types::ValueImpl::template create<typename types::ValueImpl::USize>((JaktInternal::checked_div<size_t>(x,y))))));
};/*case end*/
default: {
{
TRY((((*this).error(TRY((__jakt_format(Jakt::DeprecatedString("Invalid operands '{}' and '{}' to binary operation"sv),((lhs_value).type_name()),((rhs_value).type_name())))),span))));
return Error::from_errno((infallible_integer_cast<i32>((interpreter::InterpretError::InvalidType))));
}
};/*case end*/
}/*switch end*/
}()
)));
};/*case end*/
default: {
{
TRY((((*this).error(TRY((__jakt_format(Jakt::DeprecatedString("Invalid operands '{}' and '{}' to binary operation"sv),((lhs_value).type_name()),((rhs_value).type_name())))),span))));
return Error::from_errno((infallible_integer_cast<i32>((interpreter::InterpretError::InvalidType))));
}
};/*case end*/
}/*switch end*/
}()
)),span)) } );
};/*case end*/
case 9: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename parser::BinaryOperator::Equal>();
return JaktInternal::ExplicitValue( interpreter::StatementResult { typename interpreter::StatementResult::JustValue(types::Value(JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<NonnullRefPtr<typename types::ValueImpl>, ErrorOr<interpreter::StatementResult>>{
auto&& __jakt_match_variant = *((lhs_value).impl);
switch(__jakt_match_variant.index()) {
case 2: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::U8>();
u8 const& x = __jakt_match_value.value;
return JaktInternal::ExplicitValue(JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<NonnullRefPtr<typename types::ValueImpl>, ErrorOr<interpreter::StatementResult>>{
auto&& __jakt_match_variant = *((rhs_value).impl);
switch(__jakt_match_variant.index()) {
case 2: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::U8>();
u8 const& y = __jakt_match_value.value;
return JaktInternal::ExplicitValue(TRY((types::ValueImpl::template create<typename types::ValueImpl::Bool>((x == y)))));
};/*case end*/
default: {
{
TRY((((*this).error(TRY((__jakt_format(Jakt::DeprecatedString("Invalid operands '{}' and '{}' to binary operation"sv),((lhs_value).type_name()),((rhs_value).type_name())))),span))));
return Error::from_errno((infallible_integer_cast<i32>((interpreter::InterpretError::InvalidType))));
}
};/*case end*/
}/*switch end*/
}()
)));
};/*case end*/
case 3: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::U16>();
u16 const& x = __jakt_match_value.value;
return JaktInternal::ExplicitValue(JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<NonnullRefPtr<typename types::ValueImpl>, ErrorOr<interpreter::StatementResult>>{
auto&& __jakt_match_variant = *((rhs_value).impl);
switch(__jakt_match_variant.index()) {
case 3: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::U16>();
u16 const& y = __jakt_match_value.value;
return JaktInternal::ExplicitValue(TRY((types::ValueImpl::template create<typename types::ValueImpl::Bool>((x == y)))));
};/*case end*/
default: {
{
TRY((((*this).error(TRY((__jakt_format(Jakt::DeprecatedString("Invalid operands '{}' and '{}' to binary operation"sv),((lhs_value).type_name()),((rhs_value).type_name())))),span))));
return Error::from_errno((infallible_integer_cast<i32>((interpreter::InterpretError::InvalidType))));
}
};/*case end*/
}/*switch end*/
}()
)));
};/*case end*/
case 4: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::U32>();
u32 const& x = __jakt_match_value.value;
return JaktInternal::ExplicitValue(JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<NonnullRefPtr<typename types::ValueImpl>, ErrorOr<interpreter::StatementResult>>{
auto&& __jakt_match_variant = *((rhs_value).impl);
switch(__jakt_match_variant.index()) {
case 4: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::U32>();
u32 const& y = __jakt_match_value.value;
return JaktInternal::ExplicitValue(TRY((types::ValueImpl::template create<typename types::ValueImpl::Bool>((x == y)))));
};/*case end*/
default: {
{
TRY((((*this).error(TRY((__jakt_format(Jakt::DeprecatedString("Invalid operands '{}' and '{}' to binary operation"sv),((lhs_value).type_name()),((rhs_value).type_name())))),span))));
return Error::from_errno((infallible_integer_cast<i32>((interpreter::InterpretError::InvalidType))));
}
};/*case end*/
}/*switch end*/
}()
)));
};/*case end*/
case 5: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::U64>();
u64 const& x = __jakt_match_value.value;
return JaktInternal::ExplicitValue(JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<NonnullRefPtr<typename types::ValueImpl>, ErrorOr<interpreter::StatementResult>>{
auto&& __jakt_match_variant = *((rhs_value).impl);
switch(__jakt_match_variant.index()) {
case 5: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::U64>();
u64 const& y = __jakt_match_value.value;
return JaktInternal::ExplicitValue(TRY((types::ValueImpl::template create<typename types::ValueImpl::Bool>((x == y)))));
};/*case end*/
default: {
{
TRY((((*this).error(TRY((__jakt_format(Jakt::DeprecatedString("Invalid operands '{}' and '{}' to binary operation"sv),((lhs_value).type_name()),((rhs_value).type_name())))),span))));
return Error::from_errno((infallible_integer_cast<i32>((interpreter::InterpretError::InvalidType))));
}
};/*case end*/
}/*switch end*/
}()
)));
};/*case end*/
case 6: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::I8>();
i8 const& x = __jakt_match_value.value;
return JaktInternal::ExplicitValue(JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<NonnullRefPtr<typename types::ValueImpl>, ErrorOr<interpreter::StatementResult>>{
auto&& __jakt_match_variant = *((rhs_value).impl);
switch(__jakt_match_variant.index()) {
case 6: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::I8>();
i8 const& y = __jakt_match_value.value;
return JaktInternal::ExplicitValue(TRY((types::ValueImpl::template create<typename types::ValueImpl::Bool>((x == y)))));
};/*case end*/
default: {
{
TRY((((*this).error(TRY((__jakt_format(Jakt::DeprecatedString("Invalid operands '{}' and '{}' to binary operation"sv),((lhs_value).type_name()),((rhs_value).type_name())))),span))));
return Error::from_errno((infallible_integer_cast<i32>((interpreter::InterpretError::InvalidType))));
}
};/*case end*/
}/*switch end*/
}()
)));
};/*case end*/
case 7: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::I16>();
i16 const& x = __jakt_match_value.value;
return JaktInternal::ExplicitValue(JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<NonnullRefPtr<typename types::ValueImpl>, ErrorOr<interpreter::StatementResult>>{
auto&& __jakt_match_variant = *((rhs_value).impl);
switch(__jakt_match_variant.index()) {
case 7: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::I16>();
i16 const& y = __jakt_match_value.value;
return JaktInternal::ExplicitValue(TRY((types::ValueImpl::template create<typename types::ValueImpl::Bool>((x == y)))));
};/*case end*/
default: {
{
TRY((((*this).error(TRY((__jakt_format(Jakt::DeprecatedString("Invalid operands '{}' and '{}' to binary operation"sv),((lhs_value).type_name()),((rhs_value).type_name())))),span))));
return Error::from_errno((infallible_integer_cast<i32>((interpreter::InterpretError::InvalidType))));
}
};/*case end*/
}/*switch end*/
}()
)));
};/*case end*/
case 8: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::I32>();
i32 const& x = __jakt_match_value.value;
return JaktInternal::ExplicitValue(JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<NonnullRefPtr<typename types::ValueImpl>, ErrorOr<interpreter::StatementResult>>{
auto&& __jakt_match_variant = *((rhs_value).impl);
switch(__jakt_match_variant.index()) {
case 8: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::I32>();
i32 const& y = __jakt_match_value.value;
return JaktInternal::ExplicitValue(TRY((types::ValueImpl::template create<typename types::ValueImpl::Bool>((x == y)))));
};/*case end*/
default: {
{
TRY((((*this).error(TRY((__jakt_format(Jakt::DeprecatedString("Invalid operands '{}' and '{}' to binary operation"sv),((lhs_value).type_name()),((rhs_value).type_name())))),span))));
return Error::from_errno((infallible_integer_cast<i32>((interpreter::InterpretError::InvalidType))));
}
};/*case end*/
}/*switch end*/
}()
)));
};/*case end*/
case 9: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::I64>();
i64 const& x = __jakt_match_value.value;
return JaktInternal::ExplicitValue(JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<NonnullRefPtr<typename types::ValueImpl>, ErrorOr<interpreter::StatementResult>>{
auto&& __jakt_match_variant = *((rhs_value).impl);
switch(__jakt_match_variant.index()) {
case 9: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::I64>();
i64 const& y = __jakt_match_value.value;
return JaktInternal::ExplicitValue(TRY((types::ValueImpl::template create<typename types::ValueImpl::Bool>((x == y)))));
};/*case end*/
default: {
{
TRY((((*this).error(TRY((__jakt_format(Jakt::DeprecatedString("Invalid operands '{}' and '{}' to binary operation"sv),((lhs_value).type_name()),((rhs_value).type_name())))),span))));
return Error::from_errno((infallible_integer_cast<i32>((interpreter::InterpretError::InvalidType))));
}
};/*case end*/
}/*switch end*/
}()
)));
};/*case end*/
case 10: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::F32>();
f32 const& x = __jakt_match_value.value;
return JaktInternal::ExplicitValue(JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<NonnullRefPtr<typename types::ValueImpl>, ErrorOr<interpreter::StatementResult>>{
auto&& __jakt_match_variant = *((rhs_value).impl);
switch(__jakt_match_variant.index()) {
case 10: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::F32>();
f32 const& y = __jakt_match_value.value;
return JaktInternal::ExplicitValue(TRY((types::ValueImpl::template create<typename types::ValueImpl::Bool>((x == y)))));
};/*case end*/
default: {
{
TRY((((*this).error(TRY((__jakt_format(Jakt::DeprecatedString("Invalid operands '{}' and '{}' to binary operation"sv),((lhs_value).type_name()),((rhs_value).type_name())))),span))));
return Error::from_errno((infallible_integer_cast<i32>((interpreter::InterpretError::InvalidType))));
}
};/*case end*/
}/*switch end*/
}()
)));
};/*case end*/
case 11: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::F64>();
f64 const& x = __jakt_match_value.value;
return JaktInternal::ExplicitValue(JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<NonnullRefPtr<typename types::ValueImpl>, ErrorOr<interpreter::StatementResult>>{
auto&& __jakt_match_variant = *((rhs_value).impl);
switch(__jakt_match_variant.index()) {
case 11: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::F64>();
f64 const& y = __jakt_match_value.value;
return JaktInternal::ExplicitValue(TRY((types::ValueImpl::template create<typename types::ValueImpl::Bool>((x == y)))));
};/*case end*/
default: {
{
TRY((((*this).error(TRY((__jakt_format(Jakt::DeprecatedString("Invalid operands '{}' and '{}' to binary operation"sv),((lhs_value).type_name()),((rhs_value).type_name())))),span))));
return Error::from_errno((infallible_integer_cast<i32>((interpreter::InterpretError::InvalidType))));
}
};/*case end*/
}/*switch end*/
}()
)));
};/*case end*/
case 12: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::USize>();
size_t const& x = __jakt_match_value.value;
return JaktInternal::ExplicitValue(JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<NonnullRefPtr<typename types::ValueImpl>, ErrorOr<interpreter::StatementResult>>{
auto&& __jakt_match_variant = *((rhs_value).impl);
switch(__jakt_match_variant.index()) {
case 12: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::USize>();
size_t const& y = __jakt_match_value.value;
return JaktInternal::ExplicitValue(TRY((types::ValueImpl::template create<typename types::ValueImpl::Bool>((x == y)))));
};/*case end*/
default: {
{
TRY((((*this).error(TRY((__jakt_format(Jakt::DeprecatedString("Invalid operands '{}' and '{}' to binary operation"sv),((lhs_value).type_name()),((rhs_value).type_name())))),span))));
return Error::from_errno((infallible_integer_cast<i32>((interpreter::InterpretError::InvalidType))));
}
};/*case end*/
}/*switch end*/
}()
)));
};/*case end*/
case 16: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::CInt>();
int const& x = __jakt_match_value.value;
return JaktInternal::ExplicitValue(JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<NonnullRefPtr<typename types::ValueImpl>, ErrorOr<interpreter::StatementResult>>{
auto&& __jakt_match_variant = *((rhs_value).impl);
switch(__jakt_match_variant.index()) {
case 16: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::CInt>();
int const& y = __jakt_match_value.value;
return JaktInternal::ExplicitValue(TRY((types::ValueImpl::template create<typename types::ValueImpl::Bool>((x == y)))));
};/*case end*/
default: {
{
TRY((((*this).error(TRY((__jakt_format(Jakt::DeprecatedString("Invalid operands '{}' and '{}' to binary operation"sv),((lhs_value).type_name()),((rhs_value).type_name())))),span))));
return Error::from_errno((infallible_integer_cast<i32>((interpreter::InterpretError::InvalidType))));
}
};/*case end*/
}/*switch end*/
}()
)));
};/*case end*/
case 15: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::CChar>();
char const& x = __jakt_match_value.value;
return JaktInternal::ExplicitValue(JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<NonnullRefPtr<typename types::ValueImpl>, ErrorOr<interpreter::StatementResult>>{
auto&& __jakt_match_variant = *((rhs_value).impl);
switch(__jakt_match_variant.index()) {
case 15: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::CChar>();
char const& y = __jakt_match_value.value;
return JaktInternal::ExplicitValue(TRY((types::ValueImpl::template create<typename types::ValueImpl::Bool>((x == y)))));
};/*case end*/
default: {
{
TRY((((*this).error(TRY((__jakt_format(Jakt::DeprecatedString("Invalid operands '{}' and '{}' to binary operation"sv),((lhs_value).type_name()),((rhs_value).type_name())))),span))));
return Error::from_errno((infallible_integer_cast<i32>((interpreter::InterpretError::InvalidType))));
}
};/*case end*/
}/*switch end*/
}()
)));
};/*case end*/
case 13: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::JaktString>();
DeprecatedString const& x = __jakt_match_value.value;
return JaktInternal::ExplicitValue(JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<NonnullRefPtr<typename types::ValueImpl>, ErrorOr<interpreter::StatementResult>>{
auto&& __jakt_match_variant = *((rhs_value).impl);
switch(__jakt_match_variant.index()) {
case 13: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::JaktString>();
DeprecatedString const& y = __jakt_match_value.value;
return JaktInternal::ExplicitValue(TRY((types::ValueImpl::template create<typename types::ValueImpl::Bool>((x == y)))));
};/*case end*/
default: {
{
TRY((((*this).error(TRY((__jakt_format(Jakt::DeprecatedString("Invalid operands '{}' and '{}' to binary operation"sv),((lhs_value).type_name()),((rhs_value).type_name())))),span))));
return Error::from_errno((infallible_integer_cast<i32>((interpreter::InterpretError::InvalidType))));
}
};/*case end*/
}/*switch end*/
}()
)));
};/*case end*/
default: {
{
TRY((((*this).error(TRY((__jakt_format(Jakt::DeprecatedString("Invalid operands '{}' and '{}' to binary operation"sv),((lhs_value).type_name()),((rhs_value).type_name())))),span))));
return Error::from_errno((infallible_integer_cast<i32>((interpreter::InterpretError::InvalidType))));
}
};/*case end*/
}/*switch end*/
}()
)),span)) } );
};/*case end*/
case 10: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename parser::BinaryOperator::NotEqual>();
return JaktInternal::ExplicitValue( interpreter::StatementResult { typename interpreter::StatementResult::JustValue(types::Value(JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<NonnullRefPtr<typename types::ValueImpl>, ErrorOr<interpreter::StatementResult>>{
auto&& __jakt_match_variant = *((lhs_value).impl);
switch(__jakt_match_variant.index()) {
case 2: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::U8>();
u8 const& x = __jakt_match_value.value;
return JaktInternal::ExplicitValue(JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<NonnullRefPtr<typename types::ValueImpl>, ErrorOr<interpreter::StatementResult>>{
auto&& __jakt_match_variant = *((rhs_value).impl);
switch(__jakt_match_variant.index()) {
case 2: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::U8>();
u8 const& y = __jakt_match_value.value;
return JaktInternal::ExplicitValue(TRY((types::ValueImpl::template create<typename types::ValueImpl::Bool>((x != y)))));
};/*case end*/
default: {
{
TRY((((*this).error(TRY((__jakt_format(Jakt::DeprecatedString("Invalid operands '{}' and '{}' to binary operation"sv),((lhs_value).type_name()),((rhs_value).type_name())))),span))));
return Error::from_errno((infallible_integer_cast<i32>((interpreter::InterpretError::InvalidType))));
}
};/*case end*/
}/*switch end*/
}()
)));
};/*case end*/
case 3: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::U16>();
u16 const& x = __jakt_match_value.value;
return JaktInternal::ExplicitValue(JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<NonnullRefPtr<typename types::ValueImpl>, ErrorOr<interpreter::StatementResult>>{
auto&& __jakt_match_variant = *((rhs_value).impl);
switch(__jakt_match_variant.index()) {
case 3: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::U16>();
u16 const& y = __jakt_match_value.value;
return JaktInternal::ExplicitValue(TRY((types::ValueImpl::template create<typename types::ValueImpl::Bool>((x != y)))));
};/*case end*/
default: {
{
TRY((((*this).error(TRY((__jakt_format(Jakt::DeprecatedString("Invalid operands '{}' and '{}' to binary operation"sv),((lhs_value).type_name()),((rhs_value).type_name())))),span))));
return Error::from_errno((infallible_integer_cast<i32>((interpreter::InterpretError::InvalidType))));
}
};/*case end*/
}/*switch end*/
}()
)));
};/*case end*/
case 4: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::U32>();
u32 const& x = __jakt_match_value.value;
return JaktInternal::ExplicitValue(JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<NonnullRefPtr<typename types::ValueImpl>, ErrorOr<interpreter::StatementResult>>{
auto&& __jakt_match_variant = *((rhs_value).impl);
switch(__jakt_match_variant.index()) {
case 4: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::U32>();
u32 const& y = __jakt_match_value.value;
return JaktInternal::ExplicitValue(TRY((types::ValueImpl::template create<typename types::ValueImpl::Bool>((x != y)))));
};/*case end*/
default: {
{
TRY((((*this).error(TRY((__jakt_format(Jakt::DeprecatedString("Invalid operands '{}' and '{}' to binary operation"sv),((lhs_value).type_name()),((rhs_value).type_name())))),span))));
return Error::from_errno((infallible_integer_cast<i32>((interpreter::InterpretError::InvalidType))));
}
};/*case end*/
}/*switch end*/
}()
)));
};/*case end*/
case 5: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::U64>();
u64 const& x = __jakt_match_value.value;
return JaktInternal::ExplicitValue(JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<NonnullRefPtr<typename types::ValueImpl>, ErrorOr<interpreter::StatementResult>>{
auto&& __jakt_match_variant = *((rhs_value).impl);
switch(__jakt_match_variant.index()) {
case 5: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::U64>();
u64 const& y = __jakt_match_value.value;
return JaktInternal::ExplicitValue(TRY((types::ValueImpl::template create<typename types::ValueImpl::Bool>((x != y)))));
};/*case end*/
default: {
{
TRY((((*this).error(TRY((__jakt_format(Jakt::DeprecatedString("Invalid operands '{}' and '{}' to binary operation"sv),((lhs_value).type_name()),((rhs_value).type_name())))),span))));
return Error::from_errno((infallible_integer_cast<i32>((interpreter::InterpretError::InvalidType))));
}
};/*case end*/
}/*switch end*/
}()
)));
};/*case end*/
case 6: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::I8>();
i8 const& x = __jakt_match_value.value;
return JaktInternal::ExplicitValue(JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<NonnullRefPtr<typename types::ValueImpl>, ErrorOr<interpreter::StatementResult>>{
auto&& __jakt_match_variant = *((rhs_value).impl);
switch(__jakt_match_variant.index()) {
case 6: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::I8>();
i8 const& y = __jakt_match_value.value;
return JaktInternal::ExplicitValue(TRY((types::ValueImpl::template create<typename types::ValueImpl::Bool>((x != y)))));
};/*case end*/
default: {
{
TRY((((*this).error(TRY((__jakt_format(Jakt::DeprecatedString("Invalid operands '{}' and '{}' to binary operation"sv),((lhs_value).type_name()),((rhs_value).type_name())))),span))));
return Error::from_errno((infallible_integer_cast<i32>((interpreter::InterpretError::InvalidType))));
}
};/*case end*/
}/*switch end*/
}()
)));
};/*case end*/
case 7: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::I16>();
i16 const& x = __jakt_match_value.value;
return JaktInternal::ExplicitValue(JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<NonnullRefPtr<typename types::ValueImpl>, ErrorOr<interpreter::StatementResult>>{
auto&& __jakt_match_variant = *((rhs_value).impl);
switch(__jakt_match_variant.index()) {
case 7: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::I16>();
i16 const& y = __jakt_match_value.value;
return JaktInternal::ExplicitValue(TRY((types::ValueImpl::template create<typename types::ValueImpl::Bool>((x != y)))));
};/*case end*/
default: {
{
TRY((((*this).error(TRY((__jakt_format(Jakt::DeprecatedString("Invalid operands '{}' and '{}' to binary operation"sv),((lhs_value).type_name()),((rhs_value).type_name())))),span))));
return Error::from_errno((infallible_integer_cast<i32>((interpreter::InterpretError::InvalidType))));
}
};/*case end*/
}/*switch end*/
}()
)));
};/*case end*/
case 8: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::I32>();
i32 const& x = __jakt_match_value.value;
return JaktInternal::ExplicitValue(JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<NonnullRefPtr<typename types::ValueImpl>, ErrorOr<interpreter::StatementResult>>{
auto&& __jakt_match_variant = *((rhs_value).impl);
switch(__jakt_match_variant.index()) {
case 8: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::I32>();
i32 const& y = __jakt_match_value.value;
return JaktInternal::ExplicitValue(TRY((types::ValueImpl::template create<typename types::ValueImpl::Bool>((x != y)))));
};/*case end*/
default: {
{
TRY((((*this).error(TRY((__jakt_format(Jakt::DeprecatedString("Invalid operands '{}' and '{}' to binary operation"sv),((lhs_value).type_name()),((rhs_value).type_name())))),span))));
return Error::from_errno((infallible_integer_cast<i32>((interpreter::InterpretError::InvalidType))));
}
};/*case end*/
}/*switch end*/
}()
)));
};/*case end*/
case 9: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::I64>();
i64 const& x = __jakt_match_value.value;
return JaktInternal::ExplicitValue(JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<NonnullRefPtr<typename types::ValueImpl>, ErrorOr<interpreter::StatementResult>>{
auto&& __jakt_match_variant = *((rhs_value).impl);
switch(__jakt_match_variant.index()) {
case 9: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::I64>();
i64 const& y = __jakt_match_value.value;
return JaktInternal::ExplicitValue(TRY((types::ValueImpl::template create<typename types::ValueImpl::Bool>((x != y)))));
};/*case end*/
default: {
{
TRY((((*this).error(TRY((__jakt_format(Jakt::DeprecatedString("Invalid operands '{}' and '{}' to binary operation"sv),((lhs_value).type_name()),((rhs_value).type_name())))),span))));
return Error::from_errno((infallible_integer_cast<i32>((interpreter::InterpretError::InvalidType))));
}
};/*case end*/
}/*switch end*/
}()
)));
};/*case end*/
case 10: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::F32>();
f32 const& x = __jakt_match_value.value;
return JaktInternal::ExplicitValue(JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<NonnullRefPtr<typename types::ValueImpl>, ErrorOr<interpreter::StatementResult>>{
auto&& __jakt_match_variant = *((rhs_value).impl);
switch(__jakt_match_variant.index()) {
case 10: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::F32>();
f32 const& y = __jakt_match_value.value;
return JaktInternal::ExplicitValue(TRY((types::ValueImpl::template create<typename types::ValueImpl::Bool>((x != y)))));
};/*case end*/
default: {
{
TRY((((*this).error(TRY((__jakt_format(Jakt::DeprecatedString("Invalid operands '{}' and '{}' to binary operation"sv),((lhs_value).type_name()),((rhs_value).type_name())))),span))));
return Error::from_errno((infallible_integer_cast<i32>((interpreter::InterpretError::InvalidType))));
}
};/*case end*/
}/*switch end*/
}()
)));
};/*case end*/
case 11: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::F64>();
f64 const& x = __jakt_match_value.value;
return JaktInternal::ExplicitValue(JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<NonnullRefPtr<typename types::ValueImpl>, ErrorOr<interpreter::StatementResult>>{
auto&& __jakt_match_variant = *((rhs_value).impl);
switch(__jakt_match_variant.index()) {
case 11: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::F64>();
f64 const& y = __jakt_match_value.value;
return JaktInternal::ExplicitValue(TRY((types::ValueImpl::template create<typename types::ValueImpl::Bool>((x != y)))));
};/*case end*/
default: {
{
TRY((((*this).error(TRY((__jakt_format(Jakt::DeprecatedString("Invalid operands '{}' and '{}' to binary operation"sv),((lhs_value).type_name()),((rhs_value).type_name())))),span))));
return Error::from_errno((infallible_integer_cast<i32>((interpreter::InterpretError::InvalidType))));
}
};/*case end*/
}/*switch end*/
}()
)));
};/*case end*/
case 12: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::USize>();
size_t const& x = __jakt_match_value.value;
return JaktInternal::ExplicitValue(JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<NonnullRefPtr<typename types::ValueImpl>, ErrorOr<interpreter::StatementResult>>{
auto&& __jakt_match_variant = *((rhs_value).impl);
switch(__jakt_match_variant.index()) {
case 12: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::USize>();
size_t const& y = __jakt_match_value.value;
return JaktInternal::ExplicitValue(TRY((types::ValueImpl::template create<typename types::ValueImpl::Bool>((x != y)))));
};/*case end*/
default: {
{
TRY((((*this).error(TRY((__jakt_format(Jakt::DeprecatedString("Invalid operands '{}' and '{}' to binary operation"sv),((lhs_value).type_name()),((rhs_value).type_name())))),span))));
return Error::from_errno((infallible_integer_cast<i32>((interpreter::InterpretError::InvalidType))));
}
};/*case end*/
}/*switch end*/
}()
)));
};/*case end*/
case 16: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::CInt>();
int const& x = __jakt_match_value.value;
return JaktInternal::ExplicitValue(JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<NonnullRefPtr<typename types::ValueImpl>, ErrorOr<interpreter::StatementResult>>{
auto&& __jakt_match_variant = *((rhs_value).impl);
switch(__jakt_match_variant.index()) {
case 16: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::CInt>();
int const& y = __jakt_match_value.value;
return JaktInternal::ExplicitValue(TRY((types::ValueImpl::template create<typename types::ValueImpl::Bool>((x != y)))));
};/*case end*/
default: {
{
TRY((((*this).error(TRY((__jakt_format(Jakt::DeprecatedString("Invalid operands '{}' and '{}' to binary operation"sv),((lhs_value).type_name()),((rhs_value).type_name())))),span))));
return Error::from_errno((infallible_integer_cast<i32>((interpreter::InterpretError::InvalidType))));
}
};/*case end*/
}/*switch end*/
}()
)));
};/*case end*/
case 15: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::CChar>();
char const& x = __jakt_match_value.value;
return JaktInternal::ExplicitValue(JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<NonnullRefPtr<typename types::ValueImpl>, ErrorOr<interpreter::StatementResult>>{
auto&& __jakt_match_variant = *((rhs_value).impl);
switch(__jakt_match_variant.index()) {
case 15: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::CChar>();
char const& y = __jakt_match_value.value;
return JaktInternal::ExplicitValue(TRY((types::ValueImpl::template create<typename types::ValueImpl::Bool>((x != y)))));
};/*case end*/
default: {
{
TRY((((*this).error(TRY((__jakt_format(Jakt::DeprecatedString("Invalid operands '{}' and '{}' to binary operation"sv),((lhs_value).type_name()),((rhs_value).type_name())))),span))));
return Error::from_errno((infallible_integer_cast<i32>((interpreter::InterpretError::InvalidType))));
}
};/*case end*/
}/*switch end*/
}()
)));
};/*case end*/
case 13: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::JaktString>();
DeprecatedString const& x = __jakt_match_value.value;
return JaktInternal::ExplicitValue(JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<NonnullRefPtr<typename types::ValueImpl>, ErrorOr<interpreter::StatementResult>>{
auto&& __jakt_match_variant = *((rhs_value).impl);
switch(__jakt_match_variant.index()) {
case 13: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::JaktString>();
DeprecatedString const& y = __jakt_match_value.value;
return JaktInternal::ExplicitValue(TRY((types::ValueImpl::template create<typename types::ValueImpl::Bool>((x != y)))));
};/*case end*/
default: {
{
TRY((((*this).error(TRY((__jakt_format(Jakt::DeprecatedString("Invalid operands '{}' and '{}' to binary operation"sv),((lhs_value).type_name()),((rhs_value).type_name())))),span))));
return Error::from_errno((infallible_integer_cast<i32>((interpreter::InterpretError::InvalidType))));
}
};/*case end*/
}/*switch end*/
}()
)));
};/*case end*/
default: {
{
TRY((((*this).error(TRY((__jakt_format(Jakt::DeprecatedString("Invalid operands '{}' and '{}' to binary operation"sv),((lhs_value).type_name()),((rhs_value).type_name())))),span))));
return Error::from_errno((infallible_integer_cast<i32>((interpreter::InterpretError::InvalidType))));
}
};/*case end*/
}/*switch end*/
}()
)),span)) } );
};/*case end*/
case 5: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename parser::BinaryOperator::LessThan>();
return JaktInternal::ExplicitValue( interpreter::StatementResult { typename interpreter::StatementResult::JustValue(types::Value(JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<NonnullRefPtr<typename types::ValueImpl>, ErrorOr<interpreter::StatementResult>>{
auto&& __jakt_match_variant = *((lhs_value).impl);
switch(__jakt_match_variant.index()) {
case 2: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::U8>();
u8 const& x = __jakt_match_value.value;
return JaktInternal::ExplicitValue(JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<NonnullRefPtr<typename types::ValueImpl>, ErrorOr<interpreter::StatementResult>>{
auto&& __jakt_match_variant = *((rhs_value).impl);
switch(__jakt_match_variant.index()) {
case 2: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::U8>();
u8 const& y = __jakt_match_value.value;
return JaktInternal::ExplicitValue(TRY((types::ValueImpl::template create<typename types::ValueImpl::Bool>((x < y)))));
};/*case end*/
default: {
{
TRY((((*this).error(TRY((__jakt_format(Jakt::DeprecatedString("Invalid operands '{}' and '{}' to binary operation"sv),((lhs_value).type_name()),((rhs_value).type_name())))),span))));
return Error::from_errno((infallible_integer_cast<i32>((interpreter::InterpretError::InvalidType))));
}
};/*case end*/
}/*switch end*/
}()
)));
};/*case end*/
case 3: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::U16>();
u16 const& x = __jakt_match_value.value;
return JaktInternal::ExplicitValue(JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<NonnullRefPtr<typename types::ValueImpl>, ErrorOr<interpreter::StatementResult>>{
auto&& __jakt_match_variant = *((rhs_value).impl);
switch(__jakt_match_variant.index()) {
case 3: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::U16>();
u16 const& y = __jakt_match_value.value;
return JaktInternal::ExplicitValue(TRY((types::ValueImpl::template create<typename types::ValueImpl::Bool>((x < y)))));
};/*case end*/
default: {
{
TRY((((*this).error(TRY((__jakt_format(Jakt::DeprecatedString("Invalid operands '{}' and '{}' to binary operation"sv),((lhs_value).type_name()),((rhs_value).type_name())))),span))));
return Error::from_errno((infallible_integer_cast<i32>((interpreter::InterpretError::InvalidType))));
}
};/*case end*/
}/*switch end*/
}()
)));
};/*case end*/
case 4: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::U32>();
u32 const& x = __jakt_match_value.value;
return JaktInternal::ExplicitValue(JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<NonnullRefPtr<typename types::ValueImpl>, ErrorOr<interpreter::StatementResult>>{
auto&& __jakt_match_variant = *((rhs_value).impl);
switch(__jakt_match_variant.index()) {
case 4: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::U32>();
u32 const& y = __jakt_match_value.value;
return JaktInternal::ExplicitValue(TRY((types::ValueImpl::template create<typename types::ValueImpl::Bool>((x < y)))));
};/*case end*/
default: {
{
TRY((((*this).error(TRY((__jakt_format(Jakt::DeprecatedString("Invalid operands '{}' and '{}' to binary operation"sv),((lhs_value).type_name()),((rhs_value).type_name())))),span))));
return Error::from_errno((infallible_integer_cast<i32>((interpreter::InterpretError::InvalidType))));
}
};/*case end*/
}/*switch end*/
}()
)));
};/*case end*/
case 5: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::U64>();
u64 const& x = __jakt_match_value.value;
return JaktInternal::ExplicitValue(JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<NonnullRefPtr<typename types::ValueImpl>, ErrorOr<interpreter::StatementResult>>{
auto&& __jakt_match_variant = *((rhs_value).impl);
switch(__jakt_match_variant.index()) {
case 5: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::U64>();
u64 const& y = __jakt_match_value.value;
return JaktInternal::ExplicitValue(TRY((types::ValueImpl::template create<typename types::ValueImpl::Bool>((x < y)))));
};/*case end*/
default: {
{
TRY((((*this).error(TRY((__jakt_format(Jakt::DeprecatedString("Invalid operands '{}' and '{}' to binary operation"sv),((lhs_value).type_name()),((rhs_value).type_name())))),span))));
return Error::from_errno((infallible_integer_cast<i32>((interpreter::InterpretError::InvalidType))));
}
};/*case end*/
}/*switch end*/
}()
)));
};/*case end*/
case 6: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::I8>();
i8 const& x = __jakt_match_value.value;
return JaktInternal::ExplicitValue(JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<NonnullRefPtr<typename types::ValueImpl>, ErrorOr<interpreter::StatementResult>>{
auto&& __jakt_match_variant = *((rhs_value).impl);
switch(__jakt_match_variant.index()) {
case 6: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::I8>();
i8 const& y = __jakt_match_value.value;
return JaktInternal::ExplicitValue(TRY((types::ValueImpl::template create<typename types::ValueImpl::Bool>((x < y)))));
};/*case end*/
default: {
{
TRY((((*this).error(TRY((__jakt_format(Jakt::DeprecatedString("Invalid operands '{}' and '{}' to binary operation"sv),((lhs_value).type_name()),((rhs_value).type_name())))),span))));
return Error::from_errno((infallible_integer_cast<i32>((interpreter::InterpretError::InvalidType))));
}
};/*case end*/
}/*switch end*/
}()
)));
};/*case end*/
case 7: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::I16>();
i16 const& x = __jakt_match_value.value;
return JaktInternal::ExplicitValue(JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<NonnullRefPtr<typename types::ValueImpl>, ErrorOr<interpreter::StatementResult>>{
auto&& __jakt_match_variant = *((rhs_value).impl);
switch(__jakt_match_variant.index()) {
case 7: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::I16>();
i16 const& y = __jakt_match_value.value;
return JaktInternal::ExplicitValue(TRY((types::ValueImpl::template create<typename types::ValueImpl::Bool>((x < y)))));
};/*case end*/
default: {
{
TRY((((*this).error(TRY((__jakt_format(Jakt::DeprecatedString("Invalid operands '{}' and '{}' to binary operation"sv),((lhs_value).type_name()),((rhs_value).type_name())))),span))));
return Error::from_errno((infallible_integer_cast<i32>((interpreter::InterpretError::InvalidType))));
}
};/*case end*/
}/*switch end*/
}()
)));
};/*case end*/
case 8: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::I32>();
i32 const& x = __jakt_match_value.value;
return JaktInternal::ExplicitValue(JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<NonnullRefPtr<typename types::ValueImpl>, ErrorOr<interpreter::StatementResult>>{
auto&& __jakt_match_variant = *((rhs_value).impl);
switch(__jakt_match_variant.index()) {
case 8: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::I32>();
i32 const& y = __jakt_match_value.value;
return JaktInternal::ExplicitValue(TRY((types::ValueImpl::template create<typename types::ValueImpl::Bool>((x < y)))));
};/*case end*/
default: {
{
TRY((((*this).error(TRY((__jakt_format(Jakt::DeprecatedString("Invalid operands '{}' and '{}' to binary operation"sv),((lhs_value).type_name()),((rhs_value).type_name())))),span))));
return Error::from_errno((infallible_integer_cast<i32>((interpreter::InterpretError::InvalidType))));
}
};/*case end*/
}/*switch end*/
}()
)));
};/*case end*/
case 9: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::I64>();
i64 const& x = __jakt_match_value.value;
return JaktInternal::ExplicitValue(JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<NonnullRefPtr<typename types::ValueImpl>, ErrorOr<interpreter::StatementResult>>{
auto&& __jakt_match_variant = *((rhs_value).impl);
switch(__jakt_match_variant.index()) {
case 9: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::I64>();
i64 const& y = __jakt_match_value.value;
return JaktInternal::ExplicitValue(TRY((types::ValueImpl::template create<typename types::ValueImpl::Bool>((x < y)))));
};/*case end*/
default: {
{
TRY((((*this).error(TRY((__jakt_format(Jakt::DeprecatedString("Invalid operands '{}' and '{}' to binary operation"sv),((lhs_value).type_name()),((rhs_value).type_name())))),span))));
return Error::from_errno((infallible_integer_cast<i32>((interpreter::InterpretError::InvalidType))));
}
};/*case end*/
}/*switch end*/
}()
)));
};/*case end*/
case 10: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::F32>();
f32 const& x = __jakt_match_value.value;
return JaktInternal::ExplicitValue(JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<NonnullRefPtr<typename types::ValueImpl>, ErrorOr<interpreter::StatementResult>>{
auto&& __jakt_match_variant = *((rhs_value).impl);
switch(__jakt_match_variant.index()) {
case 10: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::F32>();
f32 const& y = __jakt_match_value.value;
return JaktInternal::ExplicitValue(TRY((types::ValueImpl::template create<typename types::ValueImpl::Bool>((x < y)))));
};/*case end*/
default: {
{
TRY((((*this).error(TRY((__jakt_format(Jakt::DeprecatedString("Invalid operands '{}' and '{}' to binary operation"sv),((lhs_value).type_name()),((rhs_value).type_name())))),span))));
return Error::from_errno((infallible_integer_cast<i32>((interpreter::InterpretError::InvalidType))));
}
};/*case end*/
}/*switch end*/
}()
)));
};/*case end*/
case 11: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::F64>();
f64 const& x = __jakt_match_value.value;
return JaktInternal::ExplicitValue(JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<NonnullRefPtr<typename types::ValueImpl>, ErrorOr<interpreter::StatementResult>>{
auto&& __jakt_match_variant = *((rhs_value).impl);
switch(__jakt_match_variant.index()) {
case 11: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::F64>();
f64 const& y = __jakt_match_value.value;
return JaktInternal::ExplicitValue(TRY((types::ValueImpl::template create<typename types::ValueImpl::Bool>((x < y)))));
};/*case end*/
default: {
{
TRY((((*this).error(TRY((__jakt_format(Jakt::DeprecatedString("Invalid operands '{}' and '{}' to binary operation"sv),((lhs_value).type_name()),((rhs_value).type_name())))),span))));
return Error::from_errno((infallible_integer_cast<i32>((interpreter::InterpretError::InvalidType))));
}
};/*case end*/
}/*switch end*/
}()
)));
};/*case end*/
case 12: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::USize>();
size_t const& x = __jakt_match_value.value;
return JaktInternal::ExplicitValue(JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<NonnullRefPtr<typename types::ValueImpl>, ErrorOr<interpreter::StatementResult>>{
auto&& __jakt_match_variant = *((rhs_value).impl);
switch(__jakt_match_variant.index()) {
case 12: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::USize>();
size_t const& y = __jakt_match_value.value;
return JaktInternal::ExplicitValue(TRY((types::ValueImpl::template create<typename types::ValueImpl::Bool>((x < y)))));
};/*case end*/
default: {
{
TRY((((*this).error(TRY((__jakt_format(Jakt::DeprecatedString("Invalid operands '{}' and '{}' to binary operation"sv),((lhs_value).type_name()),((rhs_value).type_name())))),span))));
return Error::from_errno((infallible_integer_cast<i32>((interpreter::InterpretError::InvalidType))));
}
};/*case end*/
}/*switch end*/
}()
)));
};/*case end*/
case 13: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::JaktString>();
DeprecatedString const& x = __jakt_match_value.value;
return JaktInternal::ExplicitValue(JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<NonnullRefPtr<typename types::ValueImpl>, ErrorOr<interpreter::StatementResult>>{
auto&& __jakt_match_variant = *((rhs_value).impl);
switch(__jakt_match_variant.index()) {
case 13: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::JaktString>();
DeprecatedString const& y = __jakt_match_value.value;
return JaktInternal::ExplicitValue(TRY((types::ValueImpl::template create<typename types::ValueImpl::Bool>((x < y)))));
};/*case end*/
default: {
{
TRY((((*this).error(TRY((__jakt_format(Jakt::DeprecatedString("Invalid operands '{}' and '{}' to binary operation"sv),((lhs_value).type_name()),((rhs_value).type_name())))),span))));
return Error::from_errno((infallible_integer_cast<i32>((interpreter::InterpretError::InvalidType))));
}
};/*case end*/
}/*switch end*/
}()
)));
};/*case end*/
default: {
{
TRY((((*this).error(TRY((__jakt_format(Jakt::DeprecatedString("Invalid operands '{}' and '{}' to binary operation"sv),((lhs_value).type_name()),((rhs_value).type_name())))),span))));
return Error::from_errno((infallible_integer_cast<i32>((interpreter::InterpretError::InvalidType))));
}
};/*case end*/
}/*switch end*/
}()
)),span)) } );
};/*case end*/
case 6: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename parser::BinaryOperator::LessThanOrEqual>();
return JaktInternal::ExplicitValue( interpreter::StatementResult { typename interpreter::StatementResult::JustValue(types::Value(JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<NonnullRefPtr<typename types::ValueImpl>, ErrorOr<interpreter::StatementResult>>{
auto&& __jakt_match_variant = *((lhs_value).impl);
switch(__jakt_match_variant.index()) {
case 2: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::U8>();
u8 const& x = __jakt_match_value.value;
return JaktInternal::ExplicitValue(JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<NonnullRefPtr<typename types::ValueImpl>, ErrorOr<interpreter::StatementResult>>{
auto&& __jakt_match_variant = *((rhs_value).impl);
switch(__jakt_match_variant.index()) {
case 2: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::U8>();
u8 const& y = __jakt_match_value.value;
return JaktInternal::ExplicitValue(TRY((types::ValueImpl::template create<typename types::ValueImpl::Bool>((x <= y)))));
};/*case end*/
default: {
{
TRY((((*this).error(TRY((__jakt_format(Jakt::DeprecatedString("Invalid operands '{}' and '{}' to binary operation"sv),((lhs_value).type_name()),((rhs_value).type_name())))),span))));
return Error::from_errno((infallible_integer_cast<i32>((interpreter::InterpretError::InvalidType))));
}
};/*case end*/
}/*switch end*/
}()
)));
};/*case end*/
case 3: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::U16>();
u16 const& x = __jakt_match_value.value;
return JaktInternal::ExplicitValue(JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<NonnullRefPtr<typename types::ValueImpl>, ErrorOr<interpreter::StatementResult>>{
auto&& __jakt_match_variant = *((rhs_value).impl);
switch(__jakt_match_variant.index()) {
case 3: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::U16>();
u16 const& y = __jakt_match_value.value;
return JaktInternal::ExplicitValue(TRY((types::ValueImpl::template create<typename types::ValueImpl::Bool>((x <= y)))));
};/*case end*/
default: {
{
TRY((((*this).error(TRY((__jakt_format(Jakt::DeprecatedString("Invalid operands '{}' and '{}' to binary operation"sv),((lhs_value).type_name()),((rhs_value).type_name())))),span))));
return Error::from_errno((infallible_integer_cast<i32>((interpreter::InterpretError::InvalidType))));
}
};/*case end*/
}/*switch end*/
}()
)));
};/*case end*/
case 4: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::U32>();
u32 const& x = __jakt_match_value.value;
return JaktInternal::ExplicitValue(JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<NonnullRefPtr<typename types::ValueImpl>, ErrorOr<interpreter::StatementResult>>{
auto&& __jakt_match_variant = *((rhs_value).impl);
switch(__jakt_match_variant.index()) {
case 4: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::U32>();
u32 const& y = __jakt_match_value.value;
return JaktInternal::ExplicitValue(TRY((types::ValueImpl::template create<typename types::ValueImpl::Bool>((x <= y)))));
};/*case end*/
default: {
{
TRY((((*this).error(TRY((__jakt_format(Jakt::DeprecatedString("Invalid operands '{}' and '{}' to binary operation"sv),((lhs_value).type_name()),((rhs_value).type_name())))),span))));
return Error::from_errno((infallible_integer_cast<i32>((interpreter::InterpretError::InvalidType))));
}
};/*case end*/
}/*switch end*/
}()
)));
};/*case end*/
case 5: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::U64>();
u64 const& x = __jakt_match_value.value;
return JaktInternal::ExplicitValue(JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<NonnullRefPtr<typename types::ValueImpl>, ErrorOr<interpreter::StatementResult>>{
auto&& __jakt_match_variant = *((rhs_value).impl);
switch(__jakt_match_variant.index()) {
case 5: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::U64>();
u64 const& y = __jakt_match_value.value;
return JaktInternal::ExplicitValue(TRY((types::ValueImpl::template create<typename types::ValueImpl::Bool>((x <= y)))));
};/*case end*/
default: {
{
TRY((((*this).error(TRY((__jakt_format(Jakt::DeprecatedString("Invalid operands '{}' and '{}' to binary operation"sv),((lhs_value).type_name()),((rhs_value).type_name())))),span))));
return Error::from_errno((infallible_integer_cast<i32>((interpreter::InterpretError::InvalidType))));
}
};/*case end*/
}/*switch end*/
}()
)));
};/*case end*/
case 6: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::I8>();
i8 const& x = __jakt_match_value.value;
return JaktInternal::ExplicitValue(JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<NonnullRefPtr<typename types::ValueImpl>, ErrorOr<interpreter::StatementResult>>{
auto&& __jakt_match_variant = *((rhs_value).impl);
switch(__jakt_match_variant.index()) {
case 6: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::I8>();
i8 const& y = __jakt_match_value.value;
return JaktInternal::ExplicitValue(TRY((types::ValueImpl::template create<typename types::ValueImpl::Bool>((x <= y)))));
};/*case end*/
default: {
{
TRY((((*this).error(TRY((__jakt_format(Jakt::DeprecatedString("Invalid operands '{}' and '{}' to binary operation"sv),((lhs_value).type_name()),((rhs_value).type_name())))),span))));
return Error::from_errno((infallible_integer_cast<i32>((interpreter::InterpretError::InvalidType))));
}
};/*case end*/
}/*switch end*/
}()
)));
};/*case end*/
case 7: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::I16>();
i16 const& x = __jakt_match_value.value;
return JaktInternal::ExplicitValue(JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<NonnullRefPtr<typename types::ValueImpl>, ErrorOr<interpreter::StatementResult>>{
auto&& __jakt_match_variant = *((rhs_value).impl);
switch(__jakt_match_variant.index()) {
case 7: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::I16>();
i16 const& y = __jakt_match_value.value;
return JaktInternal::ExplicitValue(TRY((types::ValueImpl::template create<typename types::ValueImpl::Bool>((x <= y)))));
};/*case end*/
default: {
{
TRY((((*this).error(TRY((__jakt_format(Jakt::DeprecatedString("Invalid operands '{}' and '{}' to binary operation"sv),((lhs_value).type_name()),((rhs_value).type_name())))),span))));
return Error::from_errno((infallible_integer_cast<i32>((interpreter::InterpretError::InvalidType))));
}
};/*case end*/
}/*switch end*/
}()
)));
};/*case end*/
case 8: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::I32>();
i32 const& x = __jakt_match_value.value;
return JaktInternal::ExplicitValue(JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<NonnullRefPtr<typename types::ValueImpl>, ErrorOr<interpreter::StatementResult>>{
auto&& __jakt_match_variant = *((rhs_value).impl);
switch(__jakt_match_variant.index()) {
case 8: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::I32>();
i32 const& y = __jakt_match_value.value;
return JaktInternal::ExplicitValue(TRY((types::ValueImpl::template create<typename types::ValueImpl::Bool>((x <= y)))));
};/*case end*/
default: {
{
TRY((((*this).error(TRY((__jakt_format(Jakt::DeprecatedString("Invalid operands '{}' and '{}' to binary operation"sv),((lhs_value).type_name()),((rhs_value).type_name())))),span))));
return Error::from_errno((infallible_integer_cast<i32>((interpreter::InterpretError::InvalidType))));
}
};/*case end*/
}/*switch end*/
}()
)));
};/*case end*/
case 9: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::I64>();
i64 const& x = __jakt_match_value.value;
return JaktInternal::ExplicitValue(JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<NonnullRefPtr<typename types::ValueImpl>, ErrorOr<interpreter::StatementResult>>{
auto&& __jakt_match_variant = *((rhs_value).impl);
switch(__jakt_match_variant.index()) {
case 9: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::I64>();
i64 const& y = __jakt_match_value.value;
return JaktInternal::ExplicitValue(TRY((types::ValueImpl::template create<typename types::ValueImpl::Bool>((x <= y)))));
};/*case end*/
default: {
{
TRY((((*this).error(TRY((__jakt_format(Jakt::DeprecatedString("Invalid operands '{}' and '{}' to binary operation"sv),((lhs_value).type_name()),((rhs_value).type_name())))),span))));
return Error::from_errno((infallible_integer_cast<i32>((interpreter::InterpretError::InvalidType))));
}
};/*case end*/
}/*switch end*/
}()
)));
};/*case end*/
case 10: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::F32>();
f32 const& x = __jakt_match_value.value;
return JaktInternal::ExplicitValue(JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<NonnullRefPtr<typename types::ValueImpl>, ErrorOr<interpreter::StatementResult>>{
auto&& __jakt_match_variant = *((rhs_value).impl);
switch(__jakt_match_variant.index()) {
case 10: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::F32>();
f32 const& y = __jakt_match_value.value;
return JaktInternal::ExplicitValue(TRY((types::ValueImpl::template create<typename types::ValueImpl::Bool>((x <= y)))));
};/*case end*/
default: {
{
TRY((((*this).error(TRY((__jakt_format(Jakt::DeprecatedString("Invalid operands '{}' and '{}' to binary operation"sv),((lhs_value).type_name()),((rhs_value).type_name())))),span))));
return Error::from_errno((infallible_integer_cast<i32>((interpreter::InterpretError::InvalidType))));
}
};/*case end*/
}/*switch end*/
}()
)));
};/*case end*/
case 11: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::F64>();
f64 const& x = __jakt_match_value.value;
return JaktInternal::ExplicitValue(JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<NonnullRefPtr<typename types::ValueImpl>, ErrorOr<interpreter::StatementResult>>{
auto&& __jakt_match_variant = *((rhs_value).impl);
switch(__jakt_match_variant.index()) {
case 11: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::F64>();
f64 const& y = __jakt_match_value.value;
return JaktInternal::ExplicitValue(TRY((types::ValueImpl::template create<typename types::ValueImpl::Bool>((x <= y)))));
};/*case end*/
default: {
{
TRY((((*this).error(TRY((__jakt_format(Jakt::DeprecatedString("Invalid operands '{}' and '{}' to binary operation"sv),((lhs_value).type_name()),((rhs_value).type_name())))),span))));
return Error::from_errno((infallible_integer_cast<i32>((interpreter::InterpretError::InvalidType))));
}
};/*case end*/
}/*switch end*/
}()
)));
};/*case end*/
case 12: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::USize>();
size_t const& x = __jakt_match_value.value;
return JaktInternal::ExplicitValue(JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<NonnullRefPtr<typename types::ValueImpl>, ErrorOr<interpreter::StatementResult>>{
auto&& __jakt_match_variant = *((rhs_value).impl);
switch(__jakt_match_variant.index()) {
case 12: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::USize>();
size_t const& y = __jakt_match_value.value;
return JaktInternal::ExplicitValue(TRY((types::ValueImpl::template create<typename types::ValueImpl::Bool>((x <= y)))));
};/*case end*/
default: {
{
TRY((((*this).error(TRY((__jakt_format(Jakt::DeprecatedString("Invalid operands '{}' and '{}' to binary operation"sv),((lhs_value).type_name()),((rhs_value).type_name())))),span))));
return Error::from_errno((infallible_integer_cast<i32>((interpreter::InterpretError::InvalidType))));
}
};/*case end*/
}/*switch end*/
}()
)));
};/*case end*/
case 13: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::JaktString>();
DeprecatedString const& x = __jakt_match_value.value;
return JaktInternal::ExplicitValue(JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<NonnullRefPtr<typename types::ValueImpl>, ErrorOr<interpreter::StatementResult>>{
auto&& __jakt_match_variant = *((rhs_value).impl);
switch(__jakt_match_variant.index()) {
case 13: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::JaktString>();
DeprecatedString const& y = __jakt_match_value.value;
return JaktInternal::ExplicitValue(TRY((types::ValueImpl::template create<typename types::ValueImpl::Bool>((x <= y)))));
};/*case end*/
default: {
{
TRY((((*this).error(TRY((__jakt_format(Jakt::DeprecatedString("Invalid operands '{}' and '{}' to binary operation"sv),((lhs_value).type_name()),((rhs_value).type_name())))),span))));
return Error::from_errno((infallible_integer_cast<i32>((interpreter::InterpretError::InvalidType))));
}
};/*case end*/
}/*switch end*/
}()
)));
};/*case end*/
default: {
{
TRY((((*this).error(TRY((__jakt_format(Jakt::DeprecatedString("Invalid operands '{}' and '{}' to binary operation"sv),((lhs_value).type_name()),((rhs_value).type_name())))),span))));
return Error::from_errno((infallible_integer_cast<i32>((interpreter::InterpretError::InvalidType))));
}
};/*case end*/
}/*switch end*/
}()
)),span)) } );
};/*case end*/
case 7: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename parser::BinaryOperator::GreaterThan>();
return JaktInternal::ExplicitValue( interpreter::StatementResult { typename interpreter::StatementResult::JustValue(types::Value(JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<NonnullRefPtr<typename types::ValueImpl>, ErrorOr<interpreter::StatementResult>>{
auto&& __jakt_match_variant = *((lhs_value).impl);
switch(__jakt_match_variant.index()) {
case 2: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::U8>();
u8 const& x = __jakt_match_value.value;
return JaktInternal::ExplicitValue(JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<NonnullRefPtr<typename types::ValueImpl>, ErrorOr<interpreter::StatementResult>>{
auto&& __jakt_match_variant = *((rhs_value).impl);
switch(__jakt_match_variant.index()) {
case 2: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::U8>();
u8 const& y = __jakt_match_value.value;
return JaktInternal::ExplicitValue(TRY((types::ValueImpl::template create<typename types::ValueImpl::Bool>((x > y)))));
};/*case end*/
default: {
{
TRY((((*this).error(TRY((__jakt_format(Jakt::DeprecatedString("Invalid operands '{}' and '{}' to binary operation"sv),((lhs_value).type_name()),((rhs_value).type_name())))),span))));
return Error::from_errno((infallible_integer_cast<i32>((interpreter::InterpretError::InvalidType))));
}
};/*case end*/
}/*switch end*/
}()
)));
};/*case end*/
case 3: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::U16>();
u16 const& x = __jakt_match_value.value;
return JaktInternal::ExplicitValue(JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<NonnullRefPtr<typename types::ValueImpl>, ErrorOr<interpreter::StatementResult>>{
auto&& __jakt_match_variant = *((rhs_value).impl);
switch(__jakt_match_variant.index()) {
case 3: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::U16>();
u16 const& y = __jakt_match_value.value;
return JaktInternal::ExplicitValue(TRY((types::ValueImpl::template create<typename types::ValueImpl::Bool>((x > y)))));
};/*case end*/
default: {
{
TRY((((*this).error(TRY((__jakt_format(Jakt::DeprecatedString("Invalid operands '{}' and '{}' to binary operation"sv),((lhs_value).type_name()),((rhs_value).type_name())))),span))));
return Error::from_errno((infallible_integer_cast<i32>((interpreter::InterpretError::InvalidType))));
}
};/*case end*/
}/*switch end*/
}()
)));
};/*case end*/
case 4: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::U32>();
u32 const& x = __jakt_match_value.value;
return JaktInternal::ExplicitValue(JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<NonnullRefPtr<typename types::ValueImpl>, ErrorOr<interpreter::StatementResult>>{
auto&& __jakt_match_variant = *((rhs_value).impl);
switch(__jakt_match_variant.index()) {
case 4: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::U32>();
u32 const& y = __jakt_match_value.value;
return JaktInternal::ExplicitValue(TRY((types::ValueImpl::template create<typename types::ValueImpl::Bool>((x > y)))));
};/*case end*/
default: {
{
TRY((((*this).error(TRY((__jakt_format(Jakt::DeprecatedString("Invalid operands '{}' and '{}' to binary operation"sv),((lhs_value).type_name()),((rhs_value).type_name())))),span))));
return Error::from_errno((infallible_integer_cast<i32>((interpreter::InterpretError::InvalidType))));
}
};/*case end*/
}/*switch end*/
}()
)));
};/*case end*/
case 5: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::U64>();
u64 const& x = __jakt_match_value.value;
return JaktInternal::ExplicitValue(JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<NonnullRefPtr<typename types::ValueImpl>, ErrorOr<interpreter::StatementResult>>{
auto&& __jakt_match_variant = *((rhs_value).impl);
switch(__jakt_match_variant.index()) {
case 5: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::U64>();
u64 const& y = __jakt_match_value.value;
return JaktInternal::ExplicitValue(TRY((types::ValueImpl::template create<typename types::ValueImpl::Bool>((x > y)))));
};/*case end*/
default: {
{
TRY((((*this).error(TRY((__jakt_format(Jakt::DeprecatedString("Invalid operands '{}' and '{}' to binary operation"sv),((lhs_value).type_name()),((rhs_value).type_name())))),span))));
return Error::from_errno((infallible_integer_cast<i32>((interpreter::InterpretError::InvalidType))));
}
};/*case end*/
}/*switch end*/
}()
)));
};/*case end*/
case 6: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::I8>();
i8 const& x = __jakt_match_value.value;
return JaktInternal::ExplicitValue(JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<NonnullRefPtr<typename types::ValueImpl>, ErrorOr<interpreter::StatementResult>>{
auto&& __jakt_match_variant = *((rhs_value).impl);
switch(__jakt_match_variant.index()) {
case 6: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::I8>();
i8 const& y = __jakt_match_value.value;
return JaktInternal::ExplicitValue(TRY((types::ValueImpl::template create<typename types::ValueImpl::Bool>((x > y)))));
};/*case end*/
default: {
{
TRY((((*this).error(TRY((__jakt_format(Jakt::DeprecatedString("Invalid operands '{}' and '{}' to binary operation"sv),((lhs_value).type_name()),((rhs_value).type_name())))),span))));
return Error::from_errno((infallible_integer_cast<i32>((interpreter::InterpretError::InvalidType))));
}
};/*case end*/
}/*switch end*/
}()
)));
};/*case end*/
case 7: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::I16>();
i16 const& x = __jakt_match_value.value;
return JaktInternal::ExplicitValue(JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<NonnullRefPtr<typename types::ValueImpl>, ErrorOr<interpreter::StatementResult>>{
auto&& __jakt_match_variant = *((rhs_value).impl);
switch(__jakt_match_variant.index()) {
case 7: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::I16>();
i16 const& y = __jakt_match_value.value;
return JaktInternal::ExplicitValue(TRY((types::ValueImpl::template create<typename types::ValueImpl::Bool>((x > y)))));
};/*case end*/
default: {
{
TRY((((*this).error(TRY((__jakt_format(Jakt::DeprecatedString("Invalid operands '{}' and '{}' to binary operation"sv),((lhs_value).type_name()),((rhs_value).type_name())))),span))));
return Error::from_errno((infallible_integer_cast<i32>((interpreter::InterpretError::InvalidType))));
}
};/*case end*/
}/*switch end*/
}()
)));
};/*case end*/
case 8: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::I32>();
i32 const& x = __jakt_match_value.value;
return JaktInternal::ExplicitValue(JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<NonnullRefPtr<typename types::ValueImpl>, ErrorOr<interpreter::StatementResult>>{
auto&& __jakt_match_variant = *((rhs_value).impl);
switch(__jakt_match_variant.index()) {
case 8: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::I32>();
i32 const& y = __jakt_match_value.value;
return JaktInternal::ExplicitValue(TRY((types::ValueImpl::template create<typename types::ValueImpl::Bool>((x > y)))));
};/*case end*/
default: {
{
TRY((((*this).error(TRY((__jakt_format(Jakt::DeprecatedString("Invalid operands '{}' and '{}' to binary operation"sv),((lhs_value).type_name()),((rhs_value).type_name())))),span))));
return Error::from_errno((infallible_integer_cast<i32>((interpreter::InterpretError::InvalidType))));
}
};/*case end*/
}/*switch end*/
}()
)));
};/*case end*/
case 9: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::I64>();
i64 const& x = __jakt_match_value.value;
return JaktInternal::ExplicitValue(JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<NonnullRefPtr<typename types::ValueImpl>, ErrorOr<interpreter::StatementResult>>{
auto&& __jakt_match_variant = *((rhs_value).impl);
switch(__jakt_match_variant.index()) {
case 9: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::I64>();
i64 const& y = __jakt_match_value.value;
return JaktInternal::ExplicitValue(TRY((types::ValueImpl::template create<typename types::ValueImpl::Bool>((x > y)))));
};/*case end*/
default: {
{
TRY((((*this).error(TRY((__jakt_format(Jakt::DeprecatedString("Invalid operands '{}' and '{}' to binary operation"sv),((lhs_value).type_name()),((rhs_value).type_name())))),span))));
return Error::from_errno((infallible_integer_cast<i32>((interpreter::InterpretError::InvalidType))));
}
};/*case end*/
}/*switch end*/
}()
)));
};/*case end*/
case 10: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::F32>();
f32 const& x = __jakt_match_value.value;
return JaktInternal::ExplicitValue(JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<NonnullRefPtr<typename types::ValueImpl>, ErrorOr<interpreter::StatementResult>>{
auto&& __jakt_match_variant = *((rhs_value).impl);
switch(__jakt_match_variant.index()) {
case 10: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::F32>();
f32 const& y = __jakt_match_value.value;
return JaktInternal::ExplicitValue(TRY((types::ValueImpl::template create<typename types::ValueImpl::Bool>((x > y)))));
};/*case end*/
default: {
{
TRY((((*this).error(TRY((__jakt_format(Jakt::DeprecatedString("Invalid operands '{}' and '{}' to binary operation"sv),((lhs_value).type_name()),((rhs_value).type_name())))),span))));
return Error::from_errno((infallible_integer_cast<i32>((interpreter::InterpretError::InvalidType))));
}
};/*case end*/
}/*switch end*/
}()
)));
};/*case end*/
case 11: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::F64>();
f64 const& x = __jakt_match_value.value;
return JaktInternal::ExplicitValue(JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<NonnullRefPtr<typename types::ValueImpl>, ErrorOr<interpreter::StatementResult>>{
auto&& __jakt_match_variant = *((rhs_value).impl);
switch(__jakt_match_variant.index()) {
case 11: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::F64>();
f64 const& y = __jakt_match_value.value;
return JaktInternal::ExplicitValue(TRY((types::ValueImpl::template create<typename types::ValueImpl::Bool>((x > y)))));
};/*case end*/
default: {
{
TRY((((*this).error(TRY((__jakt_format(Jakt::DeprecatedString("Invalid operands '{}' and '{}' to binary operation"sv),((lhs_value).type_name()),((rhs_value).type_name())))),span))));
return Error::from_errno((infallible_integer_cast<i32>((interpreter::InterpretError::InvalidType))));
}
};/*case end*/
}/*switch end*/
}()
)));
};/*case end*/
case 12: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::USize>();
size_t const& x = __jakt_match_value.value;
return JaktInternal::ExplicitValue(JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<NonnullRefPtr<typename types::ValueImpl>, ErrorOr<interpreter::StatementResult>>{
auto&& __jakt_match_variant = *((rhs_value).impl);
switch(__jakt_match_variant.index()) {
case 12: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::USize>();
size_t const& y = __jakt_match_value.value;
return JaktInternal::ExplicitValue(TRY((types::ValueImpl::template create<typename types::ValueImpl::Bool>((x > y)))));
};/*case end*/
default: {
{
TRY((((*this).error(TRY((__jakt_format(Jakt::DeprecatedString("Invalid operands '{}' and '{}' to binary operation"sv),((lhs_value).type_name()),((rhs_value).type_name())))),span))));
return Error::from_errno((infallible_integer_cast<i32>((interpreter::InterpretError::InvalidType))));
}
};/*case end*/
}/*switch end*/
}()
)));
};/*case end*/
case 13: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::JaktString>();
DeprecatedString const& x = __jakt_match_value.value;
return JaktInternal::ExplicitValue(JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<NonnullRefPtr<typename types::ValueImpl>, ErrorOr<interpreter::StatementResult>>{
auto&& __jakt_match_variant = *((rhs_value).impl);
switch(__jakt_match_variant.index()) {
case 13: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::JaktString>();
DeprecatedString const& y = __jakt_match_value.value;
return JaktInternal::ExplicitValue(TRY((types::ValueImpl::template create<typename types::ValueImpl::Bool>((x > y)))));
};/*case end*/
default: {
{
TRY((((*this).error(TRY((__jakt_format(Jakt::DeprecatedString("Invalid operands '{}' and '{}' to binary operation"sv),((lhs_value).type_name()),((rhs_value).type_name())))),span))));
return Error::from_errno((infallible_integer_cast<i32>((interpreter::InterpretError::InvalidType))));
}
};/*case end*/
}/*switch end*/
}()
)));
};/*case end*/
default: {
{
TRY((((*this).error(TRY((__jakt_format(Jakt::DeprecatedString("Invalid operands '{}' and '{}' to binary operation"sv),((lhs_value).type_name()),((rhs_value).type_name())))),span))));
return Error::from_errno((infallible_integer_cast<i32>((interpreter::InterpretError::InvalidType))));
}
};/*case end*/
}/*switch end*/
}()
)),span)) } );
};/*case end*/
case 8: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename parser::BinaryOperator::GreaterThanOrEqual>();
return JaktInternal::ExplicitValue( interpreter::StatementResult { typename interpreter::StatementResult::JustValue(types::Value(JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<NonnullRefPtr<typename types::ValueImpl>, ErrorOr<interpreter::StatementResult>>{
auto&& __jakt_match_variant = *((lhs_value).impl);
switch(__jakt_match_variant.index()) {
case 2: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::U8>();
u8 const& x = __jakt_match_value.value;
return JaktInternal::ExplicitValue(JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<NonnullRefPtr<typename types::ValueImpl>, ErrorOr<interpreter::StatementResult>>{
auto&& __jakt_match_variant = *((rhs_value).impl);
switch(__jakt_match_variant.index()) {
case 2: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::U8>();
u8 const& y = __jakt_match_value.value;
return JaktInternal::ExplicitValue(TRY((types::ValueImpl::template create<typename types::ValueImpl::Bool>((x >= y)))));
};/*case end*/
default: {
{
TRY((((*this).error(TRY((__jakt_format(Jakt::DeprecatedString("Invalid operands '{}' and '{}' to binary operation"sv),((lhs_value).type_name()),((rhs_value).type_name())))),span))));
return Error::from_errno((infallible_integer_cast<i32>((interpreter::InterpretError::InvalidType))));
}
};/*case end*/
}/*switch end*/
}()
)));
};/*case end*/
case 3: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::U16>();
u16 const& x = __jakt_match_value.value;
return JaktInternal::ExplicitValue(JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<NonnullRefPtr<typename types::ValueImpl>, ErrorOr<interpreter::StatementResult>>{
auto&& __jakt_match_variant = *((rhs_value).impl);
switch(__jakt_match_variant.index()) {
case 3: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::U16>();
u16 const& y = __jakt_match_value.value;
return JaktInternal::ExplicitValue(TRY((types::ValueImpl::template create<typename types::ValueImpl::Bool>((x >= y)))));
};/*case end*/
default: {
{
TRY((((*this).error(TRY((__jakt_format(Jakt::DeprecatedString("Invalid operands '{}' and '{}' to binary operation"sv),((lhs_value).type_name()),((rhs_value).type_name())))),span))));
return Error::from_errno((infallible_integer_cast<i32>((interpreter::InterpretError::InvalidType))));
}
};/*case end*/
}/*switch end*/
}()
)));
};/*case end*/
case 4: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::U32>();
u32 const& x = __jakt_match_value.value;
return JaktInternal::ExplicitValue(JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<NonnullRefPtr<typename types::ValueImpl>, ErrorOr<interpreter::StatementResult>>{
auto&& __jakt_match_variant = *((rhs_value).impl);
switch(__jakt_match_variant.index()) {
case 4: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::U32>();
u32 const& y = __jakt_match_value.value;
return JaktInternal::ExplicitValue(TRY((types::ValueImpl::template create<typename types::ValueImpl::Bool>((x >= y)))));
};/*case end*/
default: {
{
TRY((((*this).error(TRY((__jakt_format(Jakt::DeprecatedString("Invalid operands '{}' and '{}' to binary operation"sv),((lhs_value).type_name()),((rhs_value).type_name())))),span))));
return Error::from_errno((infallible_integer_cast<i32>((interpreter::InterpretError::InvalidType))));
}
};/*case end*/
}/*switch end*/
}()
)));
};/*case end*/
case 5: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::U64>();
u64 const& x = __jakt_match_value.value;
return JaktInternal::ExplicitValue(JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<NonnullRefPtr<typename types::ValueImpl>, ErrorOr<interpreter::StatementResult>>{
auto&& __jakt_match_variant = *((rhs_value).impl);
switch(__jakt_match_variant.index()) {
case 5: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::U64>();
u64 const& y = __jakt_match_value.value;
return JaktInternal::ExplicitValue(TRY((types::ValueImpl::template create<typename types::ValueImpl::Bool>((x >= y)))));
};/*case end*/
default: {
{
TRY((((*this).error(TRY((__jakt_format(Jakt::DeprecatedString("Invalid operands '{}' and '{}' to binary operation"sv),((lhs_value).type_name()),((rhs_value).type_name())))),span))));
return Error::from_errno((infallible_integer_cast<i32>((interpreter::InterpretError::InvalidType))));
}
};/*case end*/
}/*switch end*/
}()
)));
};/*case end*/
case 6: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::I8>();
i8 const& x = __jakt_match_value.value;
return JaktInternal::ExplicitValue(JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<NonnullRefPtr<typename types::ValueImpl>, ErrorOr<interpreter::StatementResult>>{
auto&& __jakt_match_variant = *((rhs_value).impl);
switch(__jakt_match_variant.index()) {
case 6: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::I8>();
i8 const& y = __jakt_match_value.value;
return JaktInternal::ExplicitValue(TRY((types::ValueImpl::template create<typename types::ValueImpl::Bool>((x >= y)))));
};/*case end*/
default: {
{
TRY((((*this).error(TRY((__jakt_format(Jakt::DeprecatedString("Invalid operands '{}' and '{}' to binary operation"sv),((lhs_value).type_name()),((rhs_value).type_name())))),span))));
return Error::from_errno((infallible_integer_cast<i32>((interpreter::InterpretError::InvalidType))));
}
};/*case end*/
}/*switch end*/
}()
)));
};/*case end*/
case 7: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::I16>();
i16 const& x = __jakt_match_value.value;
return JaktInternal::ExplicitValue(JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<NonnullRefPtr<typename types::ValueImpl>, ErrorOr<interpreter::StatementResult>>{
auto&& __jakt_match_variant = *((rhs_value).impl);
switch(__jakt_match_variant.index()) {
case 7: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::I16>();
i16 const& y = __jakt_match_value.value;
return JaktInternal::ExplicitValue(TRY((types::ValueImpl::template create<typename types::ValueImpl::Bool>((x >= y)))));
};/*case end*/
default: {
{
TRY((((*this).error(TRY((__jakt_format(Jakt::DeprecatedString("Invalid operands '{}' and '{}' to binary operation"sv),((lhs_value).type_name()),((rhs_value).type_name())))),span))));
return Error::from_errno((infallible_integer_cast<i32>((interpreter::InterpretError::InvalidType))));
}
};/*case end*/
}/*switch end*/
}()
)));
};/*case end*/
case 8: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::I32>();
i32 const& x = __jakt_match_value.value;
return JaktInternal::ExplicitValue(JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<NonnullRefPtr<typename types::ValueImpl>, ErrorOr<interpreter::StatementResult>>{
auto&& __jakt_match_variant = *((rhs_value).impl);
switch(__jakt_match_variant.index()) {
case 8: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::I32>();
i32 const& y = __jakt_match_value.value;
return JaktInternal::ExplicitValue(TRY((types::ValueImpl::template create<typename types::ValueImpl::Bool>((x >= y)))));
};/*case end*/
default: {
{
TRY((((*this).error(TRY((__jakt_format(Jakt::DeprecatedString("Invalid operands '{}' and '{}' to binary operation"sv),((lhs_value).type_name()),((rhs_value).type_name())))),span))));
return Error::from_errno((infallible_integer_cast<i32>((interpreter::InterpretError::InvalidType))));
}
};/*case end*/
}/*switch end*/
}()
)));
};/*case end*/
case 9: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::I64>();
i64 const& x = __jakt_match_value.value;
return JaktInternal::ExplicitValue(JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<NonnullRefPtr<typename types::ValueImpl>, ErrorOr<interpreter::StatementResult>>{
auto&& __jakt_match_variant = *((rhs_value).impl);
switch(__jakt_match_variant.index()) {
case 9: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::I64>();
i64 const& y = __jakt_match_value.value;
return JaktInternal::ExplicitValue(TRY((types::ValueImpl::template create<typename types::ValueImpl::Bool>((x >= y)))));
};/*case end*/
default: {
{
TRY((((*this).error(TRY((__jakt_format(Jakt::DeprecatedString("Invalid operands '{}' and '{}' to binary operation"sv),((lhs_value).type_name()),((rhs_value).type_name())))),span))));
return Error::from_errno((infallible_integer_cast<i32>((interpreter::InterpretError::InvalidType))));
}
};/*case end*/
}/*switch end*/
}()
)));
};/*case end*/
case 10: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::F32>();
f32 const& x = __jakt_match_value.value;
return JaktInternal::ExplicitValue(JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<NonnullRefPtr<typename types::ValueImpl>, ErrorOr<interpreter::StatementResult>>{
auto&& __jakt_match_variant = *((rhs_value).impl);
switch(__jakt_match_variant.index()) {
case 10: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::F32>();
f32 const& y = __jakt_match_value.value;
return JaktInternal::ExplicitValue(TRY((types::ValueImpl::template create<typename types::ValueImpl::Bool>((x >= y)))));
};/*case end*/
default: {
{
TRY((((*this).error(TRY((__jakt_format(Jakt::DeprecatedString("Invalid operands '{}' and '{}' to binary operation"sv),((lhs_value).type_name()),((rhs_value).type_name())))),span))));
return Error::from_errno((infallible_integer_cast<i32>((interpreter::InterpretError::InvalidType))));
}
};/*case end*/
}/*switch end*/
}()
)));
};/*case end*/
case 11: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::F64>();
f64 const& x = __jakt_match_value.value;
return JaktInternal::ExplicitValue(JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<NonnullRefPtr<typename types::ValueImpl>, ErrorOr<interpreter::StatementResult>>{
auto&& __jakt_match_variant = *((rhs_value).impl);
switch(__jakt_match_variant.index()) {
case 11: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::F64>();
f64 const& y = __jakt_match_value.value;
return JaktInternal::ExplicitValue(TRY((types::ValueImpl::template create<typename types::ValueImpl::Bool>((x >= y)))));
};/*case end*/
default: {
{
TRY((((*this).error(TRY((__jakt_format(Jakt::DeprecatedString("Invalid operands '{}' and '{}' to binary operation"sv),((lhs_value).type_name()),((rhs_value).type_name())))),span))));
return Error::from_errno((infallible_integer_cast<i32>((interpreter::InterpretError::InvalidType))));
}
};/*case end*/
}/*switch end*/
}()
)));
};/*case end*/
case 12: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::USize>();
size_t const& x = __jakt_match_value.value;
return JaktInternal::ExplicitValue(JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<NonnullRefPtr<typename types::ValueImpl>, ErrorOr<interpreter::StatementResult>>{
auto&& __jakt_match_variant = *((rhs_value).impl);
switch(__jakt_match_variant.index()) {
case 12: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::USize>();
size_t const& y = __jakt_match_value.value;
return JaktInternal::ExplicitValue(TRY((types::ValueImpl::template create<typename types::ValueImpl::Bool>((x >= y)))));
};/*case end*/
default: {
{
TRY((((*this).error(TRY((__jakt_format(Jakt::DeprecatedString("Invalid operands '{}' and '{}' to binary operation"sv),((lhs_value).type_name()),((rhs_value).type_name())))),span))));
return Error::from_errno((infallible_integer_cast<i32>((interpreter::InterpretError::InvalidType))));
}
};/*case end*/
}/*switch end*/
}()
)));
};/*case end*/
case 13: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::JaktString>();
DeprecatedString const& x = __jakt_match_value.value;
return JaktInternal::ExplicitValue(JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<NonnullRefPtr<typename types::ValueImpl>, ErrorOr<interpreter::StatementResult>>{
auto&& __jakt_match_variant = *((rhs_value).impl);
switch(__jakt_match_variant.index()) {
case 13: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::JaktString>();
DeprecatedString const& y = __jakt_match_value.value;
return JaktInternal::ExplicitValue(TRY((types::ValueImpl::template create<typename types::ValueImpl::Bool>((x >= y)))));
};/*case end*/
default: {
{
TRY((((*this).error(TRY((__jakt_format(Jakt::DeprecatedString("Invalid operands '{}' and '{}' to binary operation"sv),((lhs_value).type_name()),((rhs_value).type_name())))),span))));
return Error::from_errno((infallible_integer_cast<i32>((interpreter::InterpretError::InvalidType))));
}
};/*case end*/
}/*switch end*/
}()
)));
};/*case end*/
default: {
{
TRY((((*this).error(TRY((__jakt_format(Jakt::DeprecatedString("Invalid operands '{}' and '{}' to binary operation"sv),((lhs_value).type_name()),((rhs_value).type_name())))),span))));
return Error::from_errno((infallible_integer_cast<i32>((interpreter::InterpretError::InvalidType))));
}
};/*case end*/
}/*switch end*/
}()
)),span)) } );
};/*case end*/
case 11: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename parser::BinaryOperator::BitwiseAnd>();
return JaktInternal::ExplicitValue( interpreter::StatementResult { typename interpreter::StatementResult::JustValue(types::Value(JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<NonnullRefPtr<typename types::ValueImpl>, ErrorOr<interpreter::StatementResult>>{
auto&& __jakt_match_variant = *((lhs_value).impl);
switch(__jakt_match_variant.index()) {
case 2: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::U8>();
u8 const& x = __jakt_match_value.value;
return JaktInternal::ExplicitValue(JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<NonnullRefPtr<typename types::ValueImpl>, ErrorOr<interpreter::StatementResult>>{
auto&& __jakt_match_variant = *((rhs_value).impl);
switch(__jakt_match_variant.index()) {
case 2: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::U8>();
u8 const& y = __jakt_match_value.value;
return JaktInternal::ExplicitValue(TRY((types::ValueImpl::template create<typename types::ValueImpl::U8>((infallible_integer_cast<u8>(((x & y))))))));
};/*case end*/
default: {
{
TRY((((*this).error(TRY((__jakt_format(Jakt::DeprecatedString("Invalid operands '{}' and '{}' to binary operation"sv),((lhs_value).type_name()),((rhs_value).type_name())))),span))));
return Error::from_errno((infallible_integer_cast<i32>((interpreter::InterpretError::InvalidType))));
}
};/*case end*/
}/*switch end*/
}()
)));
};/*case end*/
case 3: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::U16>();
u16 const& x = __jakt_match_value.value;
return JaktInternal::ExplicitValue(JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<NonnullRefPtr<typename types::ValueImpl>, ErrorOr<interpreter::StatementResult>>{
auto&& __jakt_match_variant = *((rhs_value).impl);
switch(__jakt_match_variant.index()) {
case 3: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::U16>();
u16 const& y = __jakt_match_value.value;
return JaktInternal::ExplicitValue(TRY((types::ValueImpl::template create<typename types::ValueImpl::U16>((infallible_integer_cast<u16>(((x & y))))))));
};/*case end*/
default: {
{
TRY((((*this).error(TRY((__jakt_format(Jakt::DeprecatedString("Invalid operands '{}' and '{}' to binary operation"sv),((lhs_value).type_name()),((rhs_value).type_name())))),span))));
return Error::from_errno((infallible_integer_cast<i32>((interpreter::InterpretError::InvalidType))));
}
};/*case end*/
}/*switch end*/
}()
)));
};/*case end*/
case 4: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::U32>();
u32 const& x = __jakt_match_value.value;
return JaktInternal::ExplicitValue(JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<NonnullRefPtr<typename types::ValueImpl>, ErrorOr<interpreter::StatementResult>>{
auto&& __jakt_match_variant = *((rhs_value).impl);
switch(__jakt_match_variant.index()) {
case 4: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::U32>();
u32 const& y = __jakt_match_value.value;
return JaktInternal::ExplicitValue(TRY((types::ValueImpl::template create<typename types::ValueImpl::U32>((x & y)))));
};/*case end*/
default: {
{
TRY((((*this).error(TRY((__jakt_format(Jakt::DeprecatedString("Invalid operands '{}' and '{}' to binary operation"sv),((lhs_value).type_name()),((rhs_value).type_name())))),span))));
return Error::from_errno((infallible_integer_cast<i32>((interpreter::InterpretError::InvalidType))));
}
};/*case end*/
}/*switch end*/
}()
)));
};/*case end*/
case 5: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::U64>();
u64 const& x = __jakt_match_value.value;
return JaktInternal::ExplicitValue(JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<NonnullRefPtr<typename types::ValueImpl>, ErrorOr<interpreter::StatementResult>>{
auto&& __jakt_match_variant = *((rhs_value).impl);
switch(__jakt_match_variant.index()) {
case 5: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::U64>();
u64 const& y = __jakt_match_value.value;
return JaktInternal::ExplicitValue(TRY((types::ValueImpl::template create<typename types::ValueImpl::U64>((x & y)))));
};/*case end*/
default: {
{
TRY((((*this).error(TRY((__jakt_format(Jakt::DeprecatedString("Invalid operands '{}' and '{}' to binary operation"sv),((lhs_value).type_name()),((rhs_value).type_name())))),span))));
return Error::from_errno((infallible_integer_cast<i32>((interpreter::InterpretError::InvalidType))));
}
};/*case end*/
}/*switch end*/
}()
)));
};/*case end*/
case 6: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::I8>();
i8 const& x = __jakt_match_value.value;
return JaktInternal::ExplicitValue(JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<NonnullRefPtr<typename types::ValueImpl>, ErrorOr<interpreter::StatementResult>>{
auto&& __jakt_match_variant = *((rhs_value).impl);
switch(__jakt_match_variant.index()) {
case 6: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::I8>();
i8 const& y = __jakt_match_value.value;
return JaktInternal::ExplicitValue(TRY((types::ValueImpl::template create<typename types::ValueImpl::I8>((infallible_integer_cast<i8>(((x & y))))))));
};/*case end*/
default: {
{
TRY((((*this).error(TRY((__jakt_format(Jakt::DeprecatedString("Invalid operands '{}' and '{}' to binary operation"sv),((lhs_value).type_name()),((rhs_value).type_name())))),span))));
return Error::from_errno((infallible_integer_cast<i32>((interpreter::InterpretError::InvalidType))));
}
};/*case end*/
}/*switch end*/
}()
)));
};/*case end*/
case 7: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::I16>();
i16 const& x = __jakt_match_value.value;
return JaktInternal::ExplicitValue(JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<NonnullRefPtr<typename types::ValueImpl>, ErrorOr<interpreter::StatementResult>>{
auto&& __jakt_match_variant = *((rhs_value).impl);
switch(__jakt_match_variant.index()) {
case 7: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::I16>();
i16 const& y = __jakt_match_value.value;
return JaktInternal::ExplicitValue(TRY((types::ValueImpl::template create<typename types::ValueImpl::I16>((infallible_integer_cast<i16>(((x & y))))))));
};/*case end*/
default: {
{
TRY((((*this).error(TRY((__jakt_format(Jakt::DeprecatedString("Invalid operands '{}' and '{}' to binary operation"sv),((lhs_value).type_name()),((rhs_value).type_name())))),span))));
return Error::from_errno((infallible_integer_cast<i32>((interpreter::InterpretError::InvalidType))));
}
};/*case end*/
}/*switch end*/
}()
)));
};/*case end*/
case 8: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::I32>();
i32 const& x = __jakt_match_value.value;
return JaktInternal::ExplicitValue(JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<NonnullRefPtr<typename types::ValueImpl>, ErrorOr<interpreter::StatementResult>>{
auto&& __jakt_match_variant = *((rhs_value).impl);
switch(__jakt_match_variant.index()) {
case 8: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::I32>();
i32 const& y = __jakt_match_value.value;
return JaktInternal::ExplicitValue(TRY((types::ValueImpl::template create<typename types::ValueImpl::I32>((x & y)))));
};/*case end*/
default: {
{
TRY((((*this).error(TRY((__jakt_format(Jakt::DeprecatedString("Invalid operands '{}' and '{}' to binary operation"sv),((lhs_value).type_name()),((rhs_value).type_name())))),span))));
return Error::from_errno((infallible_integer_cast<i32>((interpreter::InterpretError::InvalidType))));
}
};/*case end*/
}/*switch end*/
}()
)));
};/*case end*/
case 9: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::I64>();
i64 const& x = __jakt_match_value.value;
return JaktInternal::ExplicitValue(JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<NonnullRefPtr<typename types::ValueImpl>, ErrorOr<interpreter::StatementResult>>{
auto&& __jakt_match_variant = *((rhs_value).impl);
switch(__jakt_match_variant.index()) {
case 9: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::I64>();
i64 const& y = __jakt_match_value.value;
return JaktInternal::ExplicitValue(TRY((types::ValueImpl::template create<typename types::ValueImpl::I64>((x & y)))));
};/*case end*/
default: {
{
TRY((((*this).error(TRY((__jakt_format(Jakt::DeprecatedString("Invalid operands '{}' and '{}' to binary operation"sv),((lhs_value).type_name()),((rhs_value).type_name())))),span))));
return Error::from_errno((infallible_integer_cast<i32>((interpreter::InterpretError::InvalidType))));
}
};/*case end*/
}/*switch end*/
}()
)));
};/*case end*/
case 12: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::USize>();
size_t const& x = __jakt_match_value.value;
return JaktInternal::ExplicitValue(JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<NonnullRefPtr<typename types::ValueImpl>, ErrorOr<interpreter::StatementResult>>{
auto&& __jakt_match_variant = *((rhs_value).impl);
switch(__jakt_match_variant.index()) {
case 12: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::USize>();
size_t const& y = __jakt_match_value.value;
return JaktInternal::ExplicitValue(TRY((types::ValueImpl::template create<typename types::ValueImpl::USize>((x & y)))));
};/*case end*/
default: {
{
TRY((((*this).error(TRY((__jakt_format(Jakt::DeprecatedString("Invalid operands '{}' and '{}' to binary operation"sv),((lhs_value).type_name()),((rhs_value).type_name())))),span))));
return Error::from_errno((infallible_integer_cast<i32>((interpreter::InterpretError::InvalidType))));
}
};/*case end*/
}/*switch end*/
}()
)));
};/*case end*/
default: {
{
TRY((((*this).error(TRY((__jakt_format(Jakt::DeprecatedString("Invalid operands '{}' and '{}' to binary operation"sv),((lhs_value).type_name()),((rhs_value).type_name())))),span))));
return Error::from_errno((infallible_integer_cast<i32>((interpreter::InterpretError::InvalidType))));
}
};/*case end*/
}/*switch end*/
}()
)),span)) } );
};/*case end*/
case 13: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename parser::BinaryOperator::BitwiseOr>();
return JaktInternal::ExplicitValue( interpreter::StatementResult { typename interpreter::StatementResult::JustValue(types::Value(JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<NonnullRefPtr<typename types::ValueImpl>, ErrorOr<interpreter::StatementResult>>{
auto&& __jakt_match_variant = *((lhs_value).impl);
switch(__jakt_match_variant.index()) {
case 2: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::U8>();
u8 const& x = __jakt_match_value.value;
return JaktInternal::ExplicitValue(JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<NonnullRefPtr<typename types::ValueImpl>, ErrorOr<interpreter::StatementResult>>{
auto&& __jakt_match_variant = *((rhs_value).impl);
switch(__jakt_match_variant.index()) {
case 2: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::U8>();
u8 const& y = __jakt_match_value.value;
return JaktInternal::ExplicitValue(TRY((types::ValueImpl::template create<typename types::ValueImpl::U8>((infallible_integer_cast<u8>(((x | y))))))));
};/*case end*/
default: {
{
TRY((((*this).error(TRY((__jakt_format(Jakt::DeprecatedString("Invalid operands '{}' and '{}' to binary operation"sv),((lhs_value).type_name()),((rhs_value).type_name())))),span))));
return Error::from_errno((infallible_integer_cast<i32>((interpreter::InterpretError::InvalidType))));
}
};/*case end*/
}/*switch end*/
}()
)));
};/*case end*/
case 3: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::U16>();
u16 const& x = __jakt_match_value.value;
return JaktInternal::ExplicitValue(JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<NonnullRefPtr<typename types::ValueImpl>, ErrorOr<interpreter::StatementResult>>{
auto&& __jakt_match_variant = *((rhs_value).impl);
switch(__jakt_match_variant.index()) {
case 3: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::U16>();
u16 const& y = __jakt_match_value.value;
return JaktInternal::ExplicitValue(TRY((types::ValueImpl::template create<typename types::ValueImpl::U16>((infallible_integer_cast<u16>(((x | y))))))));
};/*case end*/
default: {
{
TRY((((*this).error(TRY((__jakt_format(Jakt::DeprecatedString("Invalid operands '{}' and '{}' to binary operation"sv),((lhs_value).type_name()),((rhs_value).type_name())))),span))));
return Error::from_errno((infallible_integer_cast<i32>((interpreter::InterpretError::InvalidType))));
}
};/*case end*/
}/*switch end*/
}()
)));
};/*case end*/
case 4: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::U32>();
u32 const& x = __jakt_match_value.value;
return JaktInternal::ExplicitValue(JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<NonnullRefPtr<typename types::ValueImpl>, ErrorOr<interpreter::StatementResult>>{
auto&& __jakt_match_variant = *((rhs_value).impl);
switch(__jakt_match_variant.index()) {
case 4: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::U32>();
u32 const& y = __jakt_match_value.value;
return JaktInternal::ExplicitValue(TRY((types::ValueImpl::template create<typename types::ValueImpl::U32>((x | y)))));
};/*case end*/
default: {
{
TRY((((*this).error(TRY((__jakt_format(Jakt::DeprecatedString("Invalid operands '{}' and '{}' to binary operation"sv),((lhs_value).type_name()),((rhs_value).type_name())))),span))));
return Error::from_errno((infallible_integer_cast<i32>((interpreter::InterpretError::InvalidType))));
}
};/*case end*/
}/*switch end*/
}()
)));
};/*case end*/
case 5: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::U64>();
u64 const& x = __jakt_match_value.value;
return JaktInternal::ExplicitValue(JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<NonnullRefPtr<typename types::ValueImpl>, ErrorOr<interpreter::StatementResult>>{
auto&& __jakt_match_variant = *((rhs_value).impl);
switch(__jakt_match_variant.index()) {
case 5: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::U64>();
u64 const& y = __jakt_match_value.value;
return JaktInternal::ExplicitValue(TRY((types::ValueImpl::template create<typename types::ValueImpl::U64>((x | y)))));
};/*case end*/
default: {
{
TRY((((*this).error(TRY((__jakt_format(Jakt::DeprecatedString("Invalid operands '{}' and '{}' to binary operation"sv),((lhs_value).type_name()),((rhs_value).type_name())))),span))));
return Error::from_errno((infallible_integer_cast<i32>((interpreter::InterpretError::InvalidType))));
}
};/*case end*/
}/*switch end*/
}()
)));
};/*case end*/
case 6: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::I8>();
i8 const& x = __jakt_match_value.value;
return JaktInternal::ExplicitValue(JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<NonnullRefPtr<typename types::ValueImpl>, ErrorOr<interpreter::StatementResult>>{
auto&& __jakt_match_variant = *((rhs_value).impl);
switch(__jakt_match_variant.index()) {
case 6: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::I8>();
i8 const& y = __jakt_match_value.value;
return JaktInternal::ExplicitValue(TRY((types::ValueImpl::template create<typename types::ValueImpl::I8>((infallible_integer_cast<i8>(((x | y))))))));
};/*case end*/
default: {
{
TRY((((*this).error(TRY((__jakt_format(Jakt::DeprecatedString("Invalid operands '{}' and '{}' to binary operation"sv),((lhs_value).type_name()),((rhs_value).type_name())))),span))));
return Error::from_errno((infallible_integer_cast<i32>((interpreter::InterpretError::InvalidType))));
}
};/*case end*/
}/*switch end*/
}()
)));
};/*case end*/
case 7: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::I16>();
i16 const& x = __jakt_match_value.value;
return JaktInternal::ExplicitValue(JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<NonnullRefPtr<typename types::ValueImpl>, ErrorOr<interpreter::StatementResult>>{
auto&& __jakt_match_variant = *((rhs_value).impl);
switch(__jakt_match_variant.index()) {
case 7: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::I16>();
i16 const& y = __jakt_match_value.value;
return JaktInternal::ExplicitValue(TRY((types::ValueImpl::template create<typename types::ValueImpl::I16>((infallible_integer_cast<i16>(((x | y))))))));
};/*case end*/
default: {
{
TRY((((*this).error(TRY((__jakt_format(Jakt::DeprecatedString("Invalid operands '{}' and '{}' to binary operation"sv),((lhs_value).type_name()),((rhs_value).type_name())))),span))));
return Error::from_errno((infallible_integer_cast<i32>((interpreter::InterpretError::InvalidType))));
}
};/*case end*/
}/*switch end*/
}()
)));
};/*case end*/
case 8: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::I32>();
i32 const& x = __jakt_match_value.value;
return JaktInternal::ExplicitValue(JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<NonnullRefPtr<typename types::ValueImpl>, ErrorOr<interpreter::StatementResult>>{
auto&& __jakt_match_variant = *((rhs_value).impl);
switch(__jakt_match_variant.index()) {
case 8: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::I32>();
i32 const& y = __jakt_match_value.value;
return JaktInternal::ExplicitValue(TRY((types::ValueImpl::template create<typename types::ValueImpl::I32>((x | y)))));
};/*case end*/
default: {
{
TRY((((*this).error(TRY((__jakt_format(Jakt::DeprecatedString("Invalid operands '{}' and '{}' to binary operation"sv),((lhs_value).type_name()),((rhs_value).type_name())))),span))));
return Error::from_errno((infallible_integer_cast<i32>((interpreter::InterpretError::InvalidType))));
}
};/*case end*/
}/*switch end*/
}()
)));
};/*case end*/
case 9: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::I64>();
i64 const& x = __jakt_match_value.value;
return JaktInternal::ExplicitValue(JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<NonnullRefPtr<typename types::ValueImpl>, ErrorOr<interpreter::StatementResult>>{
auto&& __jakt_match_variant = *((rhs_value).impl);
switch(__jakt_match_variant.index()) {
case 9: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::I64>();
i64 const& y = __jakt_match_value.value;
return JaktInternal::ExplicitValue(TRY((types::ValueImpl::template create<typename types::ValueImpl::I64>((x | y)))));
};/*case end*/
default: {
{
TRY((((*this).error(TRY((__jakt_format(Jakt::DeprecatedString("Invalid operands '{}' and '{}' to binary operation"sv),((lhs_value).type_name()),((rhs_value).type_name())))),span))));
return Error::from_errno((infallible_integer_cast<i32>((interpreter::InterpretError::InvalidType))));
}
};/*case end*/
}/*switch end*/
}()
)));
};/*case end*/
case 12: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::USize>();
size_t const& x = __jakt_match_value.value;
return JaktInternal::ExplicitValue(JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<NonnullRefPtr<typename types::ValueImpl>, ErrorOr<interpreter::StatementResult>>{
auto&& __jakt_match_variant = *((rhs_value).impl);
switch(__jakt_match_variant.index()) {
case 12: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::USize>();
size_t const& y = __jakt_match_value.value;
return JaktInternal::ExplicitValue(TRY((types::ValueImpl::template create<typename types::ValueImpl::USize>((x | y)))));
};/*case end*/
default: {
{
TRY((((*this).error(TRY((__jakt_format(Jakt::DeprecatedString("Invalid operands '{}' and '{}' to binary operation"sv),((lhs_value).type_name()),((rhs_value).type_name())))),span))));
return Error::from_errno((infallible_integer_cast<i32>((interpreter::InterpretError::InvalidType))));
}
};/*case end*/
}/*switch end*/
}()
)));
};/*case end*/
default: {
{
TRY((((*this).error(TRY((__jakt_format(Jakt::DeprecatedString("Invalid operands '{}' and '{}' to binary operation"sv),((lhs_value).type_name()),((rhs_value).type_name())))),span))));
return Error::from_errno((infallible_integer_cast<i32>((interpreter::InterpretError::InvalidType))));
}
};/*case end*/
}/*switch end*/
}()
)),span)) } );
};/*case end*/
case 12: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename parser::BinaryOperator::BitwiseXor>();
return JaktInternal::ExplicitValue( interpreter::StatementResult { typename interpreter::StatementResult::JustValue(types::Value(JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<NonnullRefPtr<typename types::ValueImpl>, ErrorOr<interpreter::StatementResult>>{
auto&& __jakt_match_variant = *((lhs_value).impl);
switch(__jakt_match_variant.index()) {
case 2: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::U8>();
u8 const& x = __jakt_match_value.value;
return JaktInternal::ExplicitValue(JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<NonnullRefPtr<typename types::ValueImpl>, ErrorOr<interpreter::StatementResult>>{
auto&& __jakt_match_variant = *((rhs_value).impl);
switch(__jakt_match_variant.index()) {
case 2: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::U8>();
u8 const& y = __jakt_match_value.value;
return JaktInternal::ExplicitValue(TRY((types::ValueImpl::template create<typename types::ValueImpl::U8>((infallible_integer_cast<u8>(((x ^ y))))))));
};/*case end*/
default: {
{
TRY((((*this).error(TRY((__jakt_format(Jakt::DeprecatedString("Invalid operands '{}' and '{}' to binary operation"sv),((lhs_value).type_name()),((rhs_value).type_name())))),span))));
return Error::from_errno((infallible_integer_cast<i32>((interpreter::InterpretError::InvalidType))));
}
};/*case end*/
}/*switch end*/
}()
)));
};/*case end*/
case 3: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::U16>();
u16 const& x = __jakt_match_value.value;
return JaktInternal::ExplicitValue(JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<NonnullRefPtr<typename types::ValueImpl>, ErrorOr<interpreter::StatementResult>>{
auto&& __jakt_match_variant = *((rhs_value).impl);
switch(__jakt_match_variant.index()) {
case 3: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::U16>();
u16 const& y = __jakt_match_value.value;
return JaktInternal::ExplicitValue(TRY((types::ValueImpl::template create<typename types::ValueImpl::U16>((infallible_integer_cast<u16>(((x ^ y))))))));
};/*case end*/
default: {
{
TRY((((*this).error(TRY((__jakt_format(Jakt::DeprecatedString("Invalid operands '{}' and '{}' to binary operation"sv),((lhs_value).type_name()),((rhs_value).type_name())))),span))));
return Error::from_errno((infallible_integer_cast<i32>((interpreter::InterpretError::InvalidType))));
}
};/*case end*/
}/*switch end*/
}()
)));
};/*case end*/
case 4: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::U32>();
u32 const& x = __jakt_match_value.value;
return JaktInternal::ExplicitValue(JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<NonnullRefPtr<typename types::ValueImpl>, ErrorOr<interpreter::StatementResult>>{
auto&& __jakt_match_variant = *((rhs_value).impl);
switch(__jakt_match_variant.index()) {
case 4: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::U32>();
u32 const& y = __jakt_match_value.value;
return JaktInternal::ExplicitValue(TRY((types::ValueImpl::template create<typename types::ValueImpl::U32>((x ^ y)))));
};/*case end*/
default: {
{
TRY((((*this).error(TRY((__jakt_format(Jakt::DeprecatedString("Invalid operands '{}' and '{}' to binary operation"sv),((lhs_value).type_name()),((rhs_value).type_name())))),span))));
return Error::from_errno((infallible_integer_cast<i32>((interpreter::InterpretError::InvalidType))));
}
};/*case end*/
}/*switch end*/
}()
)));
};/*case end*/
case 5: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::U64>();
u64 const& x = __jakt_match_value.value;
return JaktInternal::ExplicitValue(JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<NonnullRefPtr<typename types::ValueImpl>, ErrorOr<interpreter::StatementResult>>{
auto&& __jakt_match_variant = *((rhs_value).impl);
switch(__jakt_match_variant.index()) {
case 5: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::U64>();
u64 const& y = __jakt_match_value.value;
return JaktInternal::ExplicitValue(TRY((types::ValueImpl::template create<typename types::ValueImpl::U64>((x ^ y)))));
};/*case end*/
default: {
{
TRY((((*this).error(TRY((__jakt_format(Jakt::DeprecatedString("Invalid operands '{}' and '{}' to binary operation"sv),((lhs_value).type_name()),((rhs_value).type_name())))),span))));
return Error::from_errno((infallible_integer_cast<i32>((interpreter::InterpretError::InvalidType))));
}
};/*case end*/
}/*switch end*/
}()
)));
};/*case end*/
case 6: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::I8>();
i8 const& x = __jakt_match_value.value;
return JaktInternal::ExplicitValue(JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<NonnullRefPtr<typename types::ValueImpl>, ErrorOr<interpreter::StatementResult>>{
auto&& __jakt_match_variant = *((rhs_value).impl);
switch(__jakt_match_variant.index()) {
case 6: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::I8>();
i8 const& y = __jakt_match_value.value;
return JaktInternal::ExplicitValue(TRY((types::ValueImpl::template create<typename types::ValueImpl::I8>((infallible_integer_cast<i8>(((x ^ y))))))));
};/*case end*/
default: {
{
TRY((((*this).error(TRY((__jakt_format(Jakt::DeprecatedString("Invalid operands '{}' and '{}' to binary operation"sv),((lhs_value).type_name()),((rhs_value).type_name())))),span))));
return Error::from_errno((infallible_integer_cast<i32>((interpreter::InterpretError::InvalidType))));
}
};/*case end*/
}/*switch end*/
}()
)));
};/*case end*/
case 7: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::I16>();
i16 const& x = __jakt_match_value.value;
return JaktInternal::ExplicitValue(JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<NonnullRefPtr<typename types::ValueImpl>, ErrorOr<interpreter::StatementResult>>{
auto&& __jakt_match_variant = *((rhs_value).impl);
switch(__jakt_match_variant.index()) {
case 7: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::I16>();
i16 const& y = __jakt_match_value.value;
return JaktInternal::ExplicitValue(TRY((types::ValueImpl::template create<typename types::ValueImpl::I16>((infallible_integer_cast<i16>(((x ^ y))))))));
};/*case end*/
default: {
{
TRY((((*this).error(TRY((__jakt_format(Jakt::DeprecatedString("Invalid operands '{}' and '{}' to binary operation"sv),((lhs_value).type_name()),((rhs_value).type_name())))),span))));
return Error::from_errno((infallible_integer_cast<i32>((interpreter::InterpretError::InvalidType))));
}
};/*case end*/
}/*switch end*/
}()
)));
};/*case end*/
case 8: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::I32>();
i32 const& x = __jakt_match_value.value;
return JaktInternal::ExplicitValue(JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<NonnullRefPtr<typename types::ValueImpl>, ErrorOr<interpreter::StatementResult>>{
auto&& __jakt_match_variant = *((rhs_value).impl);
switch(__jakt_match_variant.index()) {
case 8: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::I32>();
i32 const& y = __jakt_match_value.value;
return JaktInternal::ExplicitValue(TRY((types::ValueImpl::template create<typename types::ValueImpl::I32>((x ^ y)))));
};/*case end*/
default: {
{
TRY((((*this).error(TRY((__jakt_format(Jakt::DeprecatedString("Invalid operands '{}' and '{}' to binary operation"sv),((lhs_value).type_name()),((rhs_value).type_name())))),span))));
return Error::from_errno((infallible_integer_cast<i32>((interpreter::InterpretError::InvalidType))));
}
};/*case end*/
}/*switch end*/
}()
)));
};/*case end*/
case 9: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::I64>();
i64 const& x = __jakt_match_value.value;
return JaktInternal::ExplicitValue(JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<NonnullRefPtr<typename types::ValueImpl>, ErrorOr<interpreter::StatementResult>>{
auto&& __jakt_match_variant = *((rhs_value).impl);
switch(__jakt_match_variant.index()) {
case 9: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::I64>();
i64 const& y = __jakt_match_value.value;
return JaktInternal::ExplicitValue(TRY((types::ValueImpl::template create<typename types::ValueImpl::I64>((x ^ y)))));
};/*case end*/
default: {
{
TRY((((*this).error(TRY((__jakt_format(Jakt::DeprecatedString("Invalid operands '{}' and '{}' to binary operation"sv),((lhs_value).type_name()),((rhs_value).type_name())))),span))));
return Error::from_errno((infallible_integer_cast<i32>((interpreter::InterpretError::InvalidType))));
}
};/*case end*/
}/*switch end*/
}()
)));
};/*case end*/
case 12: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::USize>();
size_t const& x = __jakt_match_value.value;
return JaktInternal::ExplicitValue(JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<NonnullRefPtr<typename types::ValueImpl>, ErrorOr<interpreter::StatementResult>>{
auto&& __jakt_match_variant = *((rhs_value).impl);
switch(__jakt_match_variant.index()) {
case 12: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::USize>();
size_t const& y = __jakt_match_value.value;
return JaktInternal::ExplicitValue(TRY((types::ValueImpl::template create<typename types::ValueImpl::USize>((x ^ y)))));
};/*case end*/
default: {
{
TRY((((*this).error(TRY((__jakt_format(Jakt::DeprecatedString("Invalid operands '{}' and '{}' to binary operation"sv),((lhs_value).type_name()),((rhs_value).type_name())))),span))));
return Error::from_errno((infallible_integer_cast<i32>((interpreter::InterpretError::InvalidType))));
}
};/*case end*/
}/*switch end*/
}()
)));
};/*case end*/
default: {
{
TRY((((*this).error(TRY((__jakt_format(Jakt::DeprecatedString("Invalid operands '{}' and '{}' to binary operation"sv),((lhs_value).type_name()),((rhs_value).type_name())))),span))));
return Error::from_errno((infallible_integer_cast<i32>((interpreter::InterpretError::InvalidType))));
}
};/*case end*/
}/*switch end*/
}()
)),span)) } );
};/*case end*/
case 14: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename parser::BinaryOperator::BitwiseLeftShift>();
return JaktInternal::ExplicitValue( interpreter::StatementResult { typename interpreter::StatementResult::JustValue(types::Value(JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<NonnullRefPtr<typename types::ValueImpl>, ErrorOr<interpreter::StatementResult>>{
auto&& __jakt_match_variant = *((lhs_value).impl);
switch(__jakt_match_variant.index()) {
case 2: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::U8>();
u8 const& x = __jakt_match_value.value;
return JaktInternal::ExplicitValue(JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<NonnullRefPtr<typename types::ValueImpl>, ErrorOr<interpreter::StatementResult>>{
auto&& __jakt_match_variant = *((rhs_value).impl);
switch(__jakt_match_variant.index()) {
case 2: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::U8>();
u8 const& y = __jakt_match_value.value;
return JaktInternal::ExplicitValue(TRY((types::ValueImpl::template create<typename types::ValueImpl::U8>((infallible_integer_cast<u8>(((x << y))))))));
};/*case end*/
default: {
{
TRY((((*this).error(TRY((__jakt_format(Jakt::DeprecatedString("Invalid operands '{}' and '{}' to binary operation"sv),((lhs_value).type_name()),((rhs_value).type_name())))),span))));
return Error::from_errno((infallible_integer_cast<i32>((interpreter::InterpretError::InvalidType))));
}
};/*case end*/
}/*switch end*/
}()
)));
};/*case end*/
case 3: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::U16>();
u16 const& x = __jakt_match_value.value;
return JaktInternal::ExplicitValue(JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<NonnullRefPtr<typename types::ValueImpl>, ErrorOr<interpreter::StatementResult>>{
auto&& __jakt_match_variant = *((rhs_value).impl);
switch(__jakt_match_variant.index()) {
case 3: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::U16>();
u16 const& y = __jakt_match_value.value;
return JaktInternal::ExplicitValue(TRY((types::ValueImpl::template create<typename types::ValueImpl::U16>((infallible_integer_cast<u16>(((x << y))))))));
};/*case end*/
default: {
{
TRY((((*this).error(TRY((__jakt_format(Jakt::DeprecatedString("Invalid operands '{}' and '{}' to binary operation"sv),((lhs_value).type_name()),((rhs_value).type_name())))),span))));
return Error::from_errno((infallible_integer_cast<i32>((interpreter::InterpretError::InvalidType))));
}
};/*case end*/
}/*switch end*/
}()
)));
};/*case end*/
case 4: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::U32>();
u32 const& x = __jakt_match_value.value;
return JaktInternal::ExplicitValue(JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<NonnullRefPtr<typename types::ValueImpl>, ErrorOr<interpreter::StatementResult>>{
auto&& __jakt_match_variant = *((rhs_value).impl);
switch(__jakt_match_variant.index()) {
case 4: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::U32>();
u32 const& y = __jakt_match_value.value;
return JaktInternal::ExplicitValue(TRY((types::ValueImpl::template create<typename types::ValueImpl::U32>((x << y)))));
};/*case end*/
default: {
{
TRY((((*this).error(TRY((__jakt_format(Jakt::DeprecatedString("Invalid operands '{}' and '{}' to binary operation"sv),((lhs_value).type_name()),((rhs_value).type_name())))),span))));
return Error::from_errno((infallible_integer_cast<i32>((interpreter::InterpretError::InvalidType))));
}
};/*case end*/
}/*switch end*/
}()
)));
};/*case end*/
case 5: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::U64>();
u64 const& x = __jakt_match_value.value;
return JaktInternal::ExplicitValue(JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<NonnullRefPtr<typename types::ValueImpl>, ErrorOr<interpreter::StatementResult>>{
auto&& __jakt_match_variant = *((rhs_value).impl);
switch(__jakt_match_variant.index()) {
case 5: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::U64>();
u64 const& y = __jakt_match_value.value;
return JaktInternal::ExplicitValue(TRY((types::ValueImpl::template create<typename types::ValueImpl::U64>((x << y)))));
};/*case end*/
default: {
{
TRY((((*this).error(TRY((__jakt_format(Jakt::DeprecatedString("Invalid operands '{}' and '{}' to binary operation"sv),((lhs_value).type_name()),((rhs_value).type_name())))),span))));
return Error::from_errno((infallible_integer_cast<i32>((interpreter::InterpretError::InvalidType))));
}
};/*case end*/
}/*switch end*/
}()
)));
};/*case end*/
case 6: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::I8>();
i8 const& x = __jakt_match_value.value;
return JaktInternal::ExplicitValue(JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<NonnullRefPtr<typename types::ValueImpl>, ErrorOr<interpreter::StatementResult>>{
auto&& __jakt_match_variant = *((rhs_value).impl);
switch(__jakt_match_variant.index()) {
case 6: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::I8>();
i8 const& y = __jakt_match_value.value;
return JaktInternal::ExplicitValue(TRY((types::ValueImpl::template create<typename types::ValueImpl::I8>((infallible_integer_cast<i8>(((x << y))))))));
};/*case end*/
default: {
{
TRY((((*this).error(TRY((__jakt_format(Jakt::DeprecatedString("Invalid operands '{}' and '{}' to binary operation"sv),((lhs_value).type_name()),((rhs_value).type_name())))),span))));
return Error::from_errno((infallible_integer_cast<i32>((interpreter::InterpretError::InvalidType))));
}
};/*case end*/
}/*switch end*/
}()
)));
};/*case end*/
case 7: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::I16>();
i16 const& x = __jakt_match_value.value;
return JaktInternal::ExplicitValue(JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<NonnullRefPtr<typename types::ValueImpl>, ErrorOr<interpreter::StatementResult>>{
auto&& __jakt_match_variant = *((rhs_value).impl);
switch(__jakt_match_variant.index()) {
case 7: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::I16>();
i16 const& y = __jakt_match_value.value;
return JaktInternal::ExplicitValue(TRY((types::ValueImpl::template create<typename types::ValueImpl::I16>((infallible_integer_cast<i16>(((x << y))))))));
};/*case end*/
default: {
{
TRY((((*this).error(TRY((__jakt_format(Jakt::DeprecatedString("Invalid operands '{}' and '{}' to binary operation"sv),((lhs_value).type_name()),((rhs_value).type_name())))),span))));
return Error::from_errno((infallible_integer_cast<i32>((interpreter::InterpretError::InvalidType))));
}
};/*case end*/
}/*switch end*/
}()
)));
};/*case end*/
case 8: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::I32>();
i32 const& x = __jakt_match_value.value;
return JaktInternal::ExplicitValue(JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<NonnullRefPtr<typename types::ValueImpl>, ErrorOr<interpreter::StatementResult>>{
auto&& __jakt_match_variant = *((rhs_value).impl);
switch(__jakt_match_variant.index()) {
case 8: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::I32>();
i32 const& y = __jakt_match_value.value;
return JaktInternal::ExplicitValue(TRY((types::ValueImpl::template create<typename types::ValueImpl::I32>((x << y)))));
};/*case end*/
default: {
{
TRY((((*this).error(TRY((__jakt_format(Jakt::DeprecatedString("Invalid operands '{}' and '{}' to binary operation"sv),((lhs_value).type_name()),((rhs_value).type_name())))),span))));
return Error::from_errno((infallible_integer_cast<i32>((interpreter::InterpretError::InvalidType))));
}
};/*case end*/
}/*switch end*/
}()
)));
};/*case end*/
case 9: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::I64>();
i64 const& x = __jakt_match_value.value;
return JaktInternal::ExplicitValue(JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<NonnullRefPtr<typename types::ValueImpl>, ErrorOr<interpreter::StatementResult>>{
auto&& __jakt_match_variant = *((rhs_value).impl);
switch(__jakt_match_variant.index()) {
case 9: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::I64>();
i64 const& y = __jakt_match_value.value;
return JaktInternal::ExplicitValue(TRY((types::ValueImpl::template create<typename types::ValueImpl::I64>((x << y)))));
};/*case end*/
default: {
{
TRY((((*this).error(TRY((__jakt_format(Jakt::DeprecatedString("Invalid operands '{}' and '{}' to binary operation"sv),((lhs_value).type_name()),((rhs_value).type_name())))),span))));
return Error::from_errno((infallible_integer_cast<i32>((interpreter::InterpretError::InvalidType))));
}
};/*case end*/
}/*switch end*/
}()
)));
};/*case end*/
case 12: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::USize>();
size_t const& x = __jakt_match_value.value;
return JaktInternal::ExplicitValue(JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<NonnullRefPtr<typename types::ValueImpl>, ErrorOr<interpreter::StatementResult>>{
auto&& __jakt_match_variant = *((rhs_value).impl);
switch(__jakt_match_variant.index()) {
case 12: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::USize>();
size_t const& y = __jakt_match_value.value;
return JaktInternal::ExplicitValue(TRY((types::ValueImpl::template create<typename types::ValueImpl::USize>((x << y)))));
};/*case end*/
default: {
{
TRY((((*this).error(TRY((__jakt_format(Jakt::DeprecatedString("Invalid operands '{}' and '{}' to binary operation"sv),((lhs_value).type_name()),((rhs_value).type_name())))),span))));
return Error::from_errno((infallible_integer_cast<i32>((interpreter::InterpretError::InvalidType))));
}
};/*case end*/
}/*switch end*/
}()
)));
};/*case end*/
default: {
{
TRY((((*this).error(TRY((__jakt_format(Jakt::DeprecatedString("Invalid operands '{}' and '{}' to binary operation"sv),((lhs_value).type_name()),((rhs_value).type_name())))),span))));
return Error::from_errno((infallible_integer_cast<i32>((interpreter::InterpretError::InvalidType))));
}
};/*case end*/
}/*switch end*/
}()
)),span)) } );
};/*case end*/
case 15: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename parser::BinaryOperator::BitwiseRightShift>();
return JaktInternal::ExplicitValue( interpreter::StatementResult { typename interpreter::StatementResult::JustValue(types::Value(JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<NonnullRefPtr<typename types::ValueImpl>, ErrorOr<interpreter::StatementResult>>{
auto&& __jakt_match_variant = *((lhs_value).impl);
switch(__jakt_match_variant.index()) {
case 2: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::U8>();
u8 const& x = __jakt_match_value.value;
return JaktInternal::ExplicitValue(JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<NonnullRefPtr<typename types::ValueImpl>, ErrorOr<interpreter::StatementResult>>{
auto&& __jakt_match_variant = *((rhs_value).impl);
switch(__jakt_match_variant.index()) {
case 2: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::U8>();
u8 const& y = __jakt_match_value.value;
return JaktInternal::ExplicitValue(TRY((types::ValueImpl::template create<typename types::ValueImpl::U8>((infallible_integer_cast<u8>(((x >> y))))))));
};/*case end*/
default: {
{
TRY((((*this).error(TRY((__jakt_format(Jakt::DeprecatedString("Invalid operands '{}' and '{}' to binary operation"sv),((lhs_value).type_name()),((rhs_value).type_name())))),span))));
return Error::from_errno((infallible_integer_cast<i32>((interpreter::InterpretError::InvalidType))));
}
};/*case end*/
}/*switch end*/
}()
)));
};/*case end*/
case 3: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::U16>();
u16 const& x = __jakt_match_value.value;
return JaktInternal::ExplicitValue(JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<NonnullRefPtr<typename types::ValueImpl>, ErrorOr<interpreter::StatementResult>>{
auto&& __jakt_match_variant = *((rhs_value).impl);
switch(__jakt_match_variant.index()) {
case 3: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::U16>();
u16 const& y = __jakt_match_value.value;
return JaktInternal::ExplicitValue(TRY((types::ValueImpl::template create<typename types::ValueImpl::U16>((infallible_integer_cast<u16>(((x >> y))))))));
};/*case end*/
default: {
{
TRY((((*this).error(TRY((__jakt_format(Jakt::DeprecatedString("Invalid operands '{}' and '{}' to binary operation"sv),((lhs_value).type_name()),((rhs_value).type_name())))),span))));
return Error::from_errno((infallible_integer_cast<i32>((interpreter::InterpretError::InvalidType))));
}
};/*case end*/
}/*switch end*/
}()
)));
};/*case end*/
case 4: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::U32>();
u32 const& x = __jakt_match_value.value;
return JaktInternal::ExplicitValue(JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<NonnullRefPtr<typename types::ValueImpl>, ErrorOr<interpreter::StatementResult>>{
auto&& __jakt_match_variant = *((rhs_value).impl);
switch(__jakt_match_variant.index()) {
case 4: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::U32>();
u32 const& y = __jakt_match_value.value;
return JaktInternal::ExplicitValue(TRY((types::ValueImpl::template create<typename types::ValueImpl::U32>((x >> y)))));
};/*case end*/
default: {
{
TRY((((*this).error(TRY((__jakt_format(Jakt::DeprecatedString("Invalid operands '{}' and '{}' to binary operation"sv),((lhs_value).type_name()),((rhs_value).type_name())))),span))));
return Error::from_errno((infallible_integer_cast<i32>((interpreter::InterpretError::InvalidType))));
}
};/*case end*/
}/*switch end*/
}()
)));
};/*case end*/
case 5: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::U64>();
u64 const& x = __jakt_match_value.value;
return JaktInternal::ExplicitValue(JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<NonnullRefPtr<typename types::ValueImpl>, ErrorOr<interpreter::StatementResult>>{
auto&& __jakt_match_variant = *((rhs_value).impl);
switch(__jakt_match_variant.index()) {
case 5: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::U64>();
u64 const& y = __jakt_match_value.value;
return JaktInternal::ExplicitValue(TRY((types::ValueImpl::template create<typename types::ValueImpl::U64>((x >> y)))));
};/*case end*/
default: {
{
TRY((((*this).error(TRY((__jakt_format(Jakt::DeprecatedString("Invalid operands '{}' and '{}' to binary operation"sv),((lhs_value).type_name()),((rhs_value).type_name())))),span))));
return Error::from_errno((infallible_integer_cast<i32>((interpreter::InterpretError::InvalidType))));
}
};/*case end*/
}/*switch end*/
}()
)));
};/*case end*/
case 6: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::I8>();
i8 const& x = __jakt_match_value.value;
return JaktInternal::ExplicitValue(JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<NonnullRefPtr<typename types::ValueImpl>, ErrorOr<interpreter::StatementResult>>{
auto&& __jakt_match_variant = *((rhs_value).impl);
switch(__jakt_match_variant.index()) {
case 6: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::I8>();
i8 const& y = __jakt_match_value.value;
return JaktInternal::ExplicitValue(TRY((types::ValueImpl::template create<typename types::ValueImpl::I8>((infallible_integer_cast<i8>(((x >> y))))))));
};/*case end*/
default: {
{
TRY((((*this).error(TRY((__jakt_format(Jakt::DeprecatedString("Invalid operands '{}' and '{}' to binary operation"sv),((lhs_value).type_name()),((rhs_value).type_name())))),span))));
return Error::from_errno((infallible_integer_cast<i32>((interpreter::InterpretError::InvalidType))));
}
};/*case end*/
}/*switch end*/
}()
)));
};/*case end*/
case 7: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::I16>();
i16 const& x = __jakt_match_value.value;
return JaktInternal::ExplicitValue(JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<NonnullRefPtr<typename types::ValueImpl>, ErrorOr<interpreter::StatementResult>>{
auto&& __jakt_match_variant = *((rhs_value).impl);
switch(__jakt_match_variant.index()) {
case 7: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::I16>();
i16 const& y = __jakt_match_value.value;
return JaktInternal::ExplicitValue(TRY((types::ValueImpl::template create<typename types::ValueImpl::I16>((infallible_integer_cast<i16>(((x >> y))))))));
};/*case end*/
default: {
{
TRY((((*this).error(TRY((__jakt_format(Jakt::DeprecatedString("Invalid operands '{}' and '{}' to binary operation"sv),((lhs_value).type_name()),((rhs_value).type_name())))),span))));
return Error::from_errno((infallible_integer_cast<i32>((interpreter::InterpretError::InvalidType))));
}
};/*case end*/
}/*switch end*/
}()
)));
};/*case end*/
case 8: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::I32>();
i32 const& x = __jakt_match_value.value;
return JaktInternal::ExplicitValue(JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<NonnullRefPtr<typename types::ValueImpl>, ErrorOr<interpreter::StatementResult>>{
auto&& __jakt_match_variant = *((rhs_value).impl);
switch(__jakt_match_variant.index()) {
case 8: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::I32>();
i32 const& y = __jakt_match_value.value;
return JaktInternal::ExplicitValue(TRY((types::ValueImpl::template create<typename types::ValueImpl::I32>((x >> y)))));
};/*case end*/
default: {
{
TRY((((*this).error(TRY((__jakt_format(Jakt::DeprecatedString("Invalid operands '{}' and '{}' to binary operation"sv),((lhs_value).type_name()),((rhs_value).type_name())))),span))));
return Error::from_errno((infallible_integer_cast<i32>((interpreter::InterpretError::InvalidType))));
}
};/*case end*/
}/*switch end*/
}()
)));
};/*case end*/
case 9: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::I64>();
i64 const& x = __jakt_match_value.value;
return JaktInternal::ExplicitValue(JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<NonnullRefPtr<typename types::ValueImpl>, ErrorOr<interpreter::StatementResult>>{
auto&& __jakt_match_variant = *((rhs_value).impl);
switch(__jakt_match_variant.index()) {
case 9: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::I64>();
i64 const& y = __jakt_match_value.value;
return JaktInternal::ExplicitValue(TRY((types::ValueImpl::template create<typename types::ValueImpl::I64>((x >> y)))));
};/*case end*/
default: {
{
TRY((((*this).error(TRY((__jakt_format(Jakt::DeprecatedString("Invalid operands '{}' and '{}' to binary operation"sv),((lhs_value).type_name()),((rhs_value).type_name())))),span))));
return Error::from_errno((infallible_integer_cast<i32>((interpreter::InterpretError::InvalidType))));
}
};/*case end*/
}/*switch end*/
}()
)));
};/*case end*/
case 12: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::USize>();
size_t const& x = __jakt_match_value.value;
return JaktInternal::ExplicitValue(JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<NonnullRefPtr<typename types::ValueImpl>, ErrorOr<interpreter::StatementResult>>{
auto&& __jakt_match_variant = *((rhs_value).impl);
switch(__jakt_match_variant.index()) {
case 12: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::USize>();
size_t const& y = __jakt_match_value.value;
return JaktInternal::ExplicitValue(TRY((types::ValueImpl::template create<typename types::ValueImpl::USize>((x >> y)))));
};/*case end*/
default: {
{
TRY((((*this).error(TRY((__jakt_format(Jakt::DeprecatedString("Invalid operands '{}' and '{}' to binary operation"sv),((lhs_value).type_name()),((rhs_value).type_name())))),span))));
return Error::from_errno((infallible_integer_cast<i32>((interpreter::InterpretError::InvalidType))));
}
};/*case end*/
}/*switch end*/
}()
)));
};/*case end*/
default: {
{
TRY((((*this).error(TRY((__jakt_format(Jakt::DeprecatedString("Invalid operands '{}' and '{}' to binary operation"sv),((lhs_value).type_name()),((rhs_value).type_name())))),span))));
return Error::from_errno((infallible_integer_cast<i32>((interpreter::InterpretError::InvalidType))));
}
};/*case end*/
}/*switch end*/
}()
)),span)) } );
};/*case end*/
case 16: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename parser::BinaryOperator::ArithmeticLeftShift>();
return JaktInternal::ExplicitValue( interpreter::StatementResult { typename interpreter::StatementResult::JustValue(types::Value(JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<NonnullRefPtr<typename types::ValueImpl>, ErrorOr<interpreter::StatementResult>>{
auto&& __jakt_match_variant = *((lhs_value).impl);
switch(__jakt_match_variant.index()) {
case 2: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::U8>();
u8 const& x = __jakt_match_value.value;
return JaktInternal::ExplicitValue(JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<NonnullRefPtr<typename types::ValueImpl>, ErrorOr<interpreter::StatementResult>>{
auto&& __jakt_match_variant = *((rhs_value).impl);
switch(__jakt_match_variant.index()) {
case 2: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::U8>();
u8 const& y = __jakt_match_value.value;
return JaktInternal::ExplicitValue(TRY((types::ValueImpl::template create<typename types::ValueImpl::U8>((infallible_integer_cast<u8>(((x << y))))))));
};/*case end*/
default: {
{
TRY((((*this).error(TRY((__jakt_format(Jakt::DeprecatedString("Invalid operands '{}' and '{}' to binary operation"sv),((lhs_value).type_name()),((rhs_value).type_name())))),span))));
return Error::from_errno((infallible_integer_cast<i32>((interpreter::InterpretError::InvalidType))));
}
};/*case end*/
}/*switch end*/
}()
)));
};/*case end*/
case 3: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::U16>();
u16 const& x = __jakt_match_value.value;
return JaktInternal::ExplicitValue(JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<NonnullRefPtr<typename types::ValueImpl>, ErrorOr<interpreter::StatementResult>>{
auto&& __jakt_match_variant = *((rhs_value).impl);
switch(__jakt_match_variant.index()) {
case 3: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::U16>();
u16 const& y = __jakt_match_value.value;
return JaktInternal::ExplicitValue(TRY((types::ValueImpl::template create<typename types::ValueImpl::U16>((infallible_integer_cast<u16>(((x << y))))))));
};/*case end*/
default: {
{
TRY((((*this).error(TRY((__jakt_format(Jakt::DeprecatedString("Invalid operands '{}' and '{}' to binary operation"sv),((lhs_value).type_name()),((rhs_value).type_name())))),span))));
return Error::from_errno((infallible_integer_cast<i32>((interpreter::InterpretError::InvalidType))));
}
};/*case end*/
}/*switch end*/
}()
)));
};/*case end*/
case 4: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::U32>();
u32 const& x = __jakt_match_value.value;
return JaktInternal::ExplicitValue(JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<NonnullRefPtr<typename types::ValueImpl>, ErrorOr<interpreter::StatementResult>>{
auto&& __jakt_match_variant = *((rhs_value).impl);
switch(__jakt_match_variant.index()) {
case 4: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::U32>();
u32 const& y = __jakt_match_value.value;
return JaktInternal::ExplicitValue(TRY((types::ValueImpl::template create<typename types::ValueImpl::U32>((x << y)))));
};/*case end*/
default: {
{
TRY((((*this).error(TRY((__jakt_format(Jakt::DeprecatedString("Invalid operands '{}' and '{}' to binary operation"sv),((lhs_value).type_name()),((rhs_value).type_name())))),span))));
return Error::from_errno((infallible_integer_cast<i32>((interpreter::InterpretError::InvalidType))));
}
};/*case end*/
}/*switch end*/
}()
)));
};/*case end*/
case 5: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::U64>();
u64 const& x = __jakt_match_value.value;
return JaktInternal::ExplicitValue(JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<NonnullRefPtr<typename types::ValueImpl>, ErrorOr<interpreter::StatementResult>>{
auto&& __jakt_match_variant = *((rhs_value).impl);
switch(__jakt_match_variant.index()) {
case 5: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::U64>();
u64 const& y = __jakt_match_value.value;
return JaktInternal::ExplicitValue(TRY((types::ValueImpl::template create<typename types::ValueImpl::U64>((x << y)))));
};/*case end*/
default: {
{
TRY((((*this).error(TRY((__jakt_format(Jakt::DeprecatedString("Invalid operands '{}' and '{}' to binary operation"sv),((lhs_value).type_name()),((rhs_value).type_name())))),span))));
return Error::from_errno((infallible_integer_cast<i32>((interpreter::InterpretError::InvalidType))));
}
};/*case end*/
}/*switch end*/
}()
)));
};/*case end*/
case 6: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::I8>();
i8 const& x = __jakt_match_value.value;
return JaktInternal::ExplicitValue(JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<NonnullRefPtr<typename types::ValueImpl>, ErrorOr<interpreter::StatementResult>>{
auto&& __jakt_match_variant = *((rhs_value).impl);
switch(__jakt_match_variant.index()) {
case 6: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::I8>();
i8 const& y = __jakt_match_value.value;
return JaktInternal::ExplicitValue(TRY((types::ValueImpl::template create<typename types::ValueImpl::I8>((infallible_integer_cast<i8>(((x << y))))))));
};/*case end*/
default: {
{
TRY((((*this).error(TRY((__jakt_format(Jakt::DeprecatedString("Invalid operands '{}' and '{}' to binary operation"sv),((lhs_value).type_name()),((rhs_value).type_name())))),span))));
return Error::from_errno((infallible_integer_cast<i32>((interpreter::InterpretError::InvalidType))));
}
};/*case end*/
}/*switch end*/
}()
)));
};/*case end*/
case 7: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::I16>();
i16 const& x = __jakt_match_value.value;
return JaktInternal::ExplicitValue(JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<NonnullRefPtr<typename types::ValueImpl>, ErrorOr<interpreter::StatementResult>>{
auto&& __jakt_match_variant = *((rhs_value).impl);
switch(__jakt_match_variant.index()) {
case 7: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::I16>();
i16 const& y = __jakt_match_value.value;
return JaktInternal::ExplicitValue(TRY((types::ValueImpl::template create<typename types::ValueImpl::I16>((infallible_integer_cast<i16>(((x << y))))))));
};/*case end*/
default: {
{
TRY((((*this).error(TRY((__jakt_format(Jakt::DeprecatedString("Invalid operands '{}' and '{}' to binary operation"sv),((lhs_value).type_name()),((rhs_value).type_name())))),span))));
return Error::from_errno((infallible_integer_cast<i32>((interpreter::InterpretError::InvalidType))));
}
};/*case end*/
}/*switch end*/
}()
)));
};/*case end*/
case 8: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::I32>();
i32 const& x = __jakt_match_value.value;
return JaktInternal::ExplicitValue(JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<NonnullRefPtr<typename types::ValueImpl>, ErrorOr<interpreter::StatementResult>>{
auto&& __jakt_match_variant = *((rhs_value).impl);
switch(__jakt_match_variant.index()) {
case 8: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::I32>();
i32 const& y = __jakt_match_value.value;
return JaktInternal::ExplicitValue(TRY((types::ValueImpl::template create<typename types::ValueImpl::I32>((x << y)))));
};/*case end*/
default: {
{
TRY((((*this).error(TRY((__jakt_format(Jakt::DeprecatedString("Invalid operands '{}' and '{}' to binary operation"sv),((lhs_value).type_name()),((rhs_value).type_name())))),span))));
return Error::from_errno((infallible_integer_cast<i32>((interpreter::InterpretError::InvalidType))));
}
};/*case end*/
}/*switch end*/
}()
)));
};/*case end*/
case 9: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::I64>();
i64 const& x = __jakt_match_value.value;
return JaktInternal::ExplicitValue(JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<NonnullRefPtr<typename types::ValueImpl>, ErrorOr<interpreter::StatementResult>>{
auto&& __jakt_match_variant = *((rhs_value).impl);
switch(__jakt_match_variant.index()) {
case 9: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::I64>();
i64 const& y = __jakt_match_value.value;
return JaktInternal::ExplicitValue(TRY((types::ValueImpl::template create<typename types::ValueImpl::I64>((x << y)))));
};/*case end*/
default: {
{
TRY((((*this).error(TRY((__jakt_format(Jakt::DeprecatedString("Invalid operands '{}' and '{}' to binary operation"sv),((lhs_value).type_name()),((rhs_value).type_name())))),span))));
return Error::from_errno((infallible_integer_cast<i32>((interpreter::InterpretError::InvalidType))));
}
};/*case end*/
}/*switch end*/
}()
)));
};/*case end*/
case 12: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::USize>();
size_t const& x = __jakt_match_value.value;
return JaktInternal::ExplicitValue(JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<NonnullRefPtr<typename types::ValueImpl>, ErrorOr<interpreter::StatementResult>>{
auto&& __jakt_match_variant = *((rhs_value).impl);
switch(__jakt_match_variant.index()) {
case 12: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::USize>();
size_t const& y = __jakt_match_value.value;
return JaktInternal::ExplicitValue(TRY((types::ValueImpl::template create<typename types::ValueImpl::USize>((x << y)))));
};/*case end*/
default: {
{
TRY((((*this).error(TRY((__jakt_format(Jakt::DeprecatedString("Invalid operands '{}' and '{}' to binary operation"sv),((lhs_value).type_name()),((rhs_value).type_name())))),span))));
return Error::from_errno((infallible_integer_cast<i32>((interpreter::InterpretError::InvalidType))));
}
};/*case end*/
}/*switch end*/
}()
)));
};/*case end*/
default: {
{
TRY((((*this).error(TRY((__jakt_format(Jakt::DeprecatedString("Invalid operands '{}' and '{}' to binary operation"sv),((lhs_value).type_name()),((rhs_value).type_name())))),span))));
return Error::from_errno((infallible_integer_cast<i32>((interpreter::InterpretError::InvalidType))));
}
};/*case end*/
}/*switch end*/
}()
)),span)) } );
};/*case end*/
case 17: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename parser::BinaryOperator::ArithmeticRightShift>();
return JaktInternal::ExplicitValue( interpreter::StatementResult { typename interpreter::StatementResult::JustValue(types::Value(JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<NonnullRefPtr<typename types::ValueImpl>, ErrorOr<interpreter::StatementResult>>{
auto&& __jakt_match_variant = *((lhs_value).impl);
switch(__jakt_match_variant.index()) {
case 2: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::U8>();
u8 const& x = __jakt_match_value.value;
return JaktInternal::ExplicitValue(JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<NonnullRefPtr<typename types::ValueImpl>, ErrorOr<interpreter::StatementResult>>{
auto&& __jakt_match_variant = *((rhs_value).impl);
switch(__jakt_match_variant.index()) {
case 2: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::U8>();
u8 const& y = __jakt_match_value.value;
return JaktInternal::ExplicitValue(TRY((types::ValueImpl::template create<typename types::ValueImpl::U8>(JaktInternal::arithmetic_shift_right(x,y)))));
};/*case end*/
default: {
{
TRY((((*this).error(TRY((__jakt_format(Jakt::DeprecatedString("Invalid operands '{}' and '{}' to binary operation"sv),((lhs_value).type_name()),((rhs_value).type_name())))),span))));
return Error::from_errno((infallible_integer_cast<i32>((interpreter::InterpretError::InvalidType))));
}
};/*case end*/
}/*switch end*/
}()
)));
};/*case end*/
case 3: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::U16>();
u16 const& x = __jakt_match_value.value;
return JaktInternal::ExplicitValue(JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<NonnullRefPtr<typename types::ValueImpl>, ErrorOr<interpreter::StatementResult>>{
auto&& __jakt_match_variant = *((rhs_value).impl);
switch(__jakt_match_variant.index()) {
case 3: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::U16>();
u16 const& y = __jakt_match_value.value;
return JaktInternal::ExplicitValue(TRY((types::ValueImpl::template create<typename types::ValueImpl::U16>(JaktInternal::arithmetic_shift_right(x,y)))));
};/*case end*/
default: {
{
TRY((((*this).error(TRY((__jakt_format(Jakt::DeprecatedString("Invalid operands '{}' and '{}' to binary operation"sv),((lhs_value).type_name()),((rhs_value).type_name())))),span))));
return Error::from_errno((infallible_integer_cast<i32>((interpreter::InterpretError::InvalidType))));
}
};/*case end*/
}/*switch end*/
}()
)));
};/*case end*/
case 4: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::U32>();
u32 const& x = __jakt_match_value.value;
return JaktInternal::ExplicitValue(JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<NonnullRefPtr<typename types::ValueImpl>, ErrorOr<interpreter::StatementResult>>{
auto&& __jakt_match_variant = *((rhs_value).impl);
switch(__jakt_match_variant.index()) {
case 4: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::U32>();
u32 const& y = __jakt_match_value.value;
return JaktInternal::ExplicitValue(TRY((types::ValueImpl::template create<typename types::ValueImpl::U32>(JaktInternal::arithmetic_shift_right(x,y)))));
};/*case end*/
default: {
{
TRY((((*this).error(TRY((__jakt_format(Jakt::DeprecatedString("Invalid operands '{}' and '{}' to binary operation"sv),((lhs_value).type_name()),((rhs_value).type_name())))),span))));
return Error::from_errno((infallible_integer_cast<i32>((interpreter::InterpretError::InvalidType))));
}
};/*case end*/
}/*switch end*/
}()
)));
};/*case end*/
case 5: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::U64>();
u64 const& x = __jakt_match_value.value;
return JaktInternal::ExplicitValue(JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<NonnullRefPtr<typename types::ValueImpl>, ErrorOr<interpreter::StatementResult>>{
auto&& __jakt_match_variant = *((rhs_value).impl);
switch(__jakt_match_variant.index()) {
case 5: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::U64>();
u64 const& y = __jakt_match_value.value;
return JaktInternal::ExplicitValue(TRY((types::ValueImpl::template create<typename types::ValueImpl::U64>(JaktInternal::arithmetic_shift_right(x,y)))));
};/*case end*/
default: {
{
TRY((((*this).error(TRY((__jakt_format(Jakt::DeprecatedString("Invalid operands '{}' and '{}' to binary operation"sv),((lhs_value).type_name()),((rhs_value).type_name())))),span))));
return Error::from_errno((infallible_integer_cast<i32>((interpreter::InterpretError::InvalidType))));
}
};/*case end*/
}/*switch end*/
}()
)));
};/*case end*/
case 6: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::I8>();
i8 const& x = __jakt_match_value.value;
return JaktInternal::ExplicitValue(JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<NonnullRefPtr<typename types::ValueImpl>, ErrorOr<interpreter::StatementResult>>{
auto&& __jakt_match_variant = *((rhs_value).impl);
switch(__jakt_match_variant.index()) {
case 6: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::I8>();
i8 const& y = __jakt_match_value.value;
return JaktInternal::ExplicitValue(TRY((types::ValueImpl::template create<typename types::ValueImpl::I8>(JaktInternal::arithmetic_shift_right(x,y)))));
};/*case end*/
default: {
{
TRY((((*this).error(TRY((__jakt_format(Jakt::DeprecatedString("Invalid operands '{}' and '{}' to binary operation"sv),((lhs_value).type_name()),((rhs_value).type_name())))),span))));
return Error::from_errno((infallible_integer_cast<i32>((interpreter::InterpretError::InvalidType))));
}
};/*case end*/
}/*switch end*/
}()
)));
};/*case end*/
case 7: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::I16>();
i16 const& x = __jakt_match_value.value;
return JaktInternal::ExplicitValue(JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<NonnullRefPtr<typename types::ValueImpl>, ErrorOr<interpreter::StatementResult>>{
auto&& __jakt_match_variant = *((rhs_value).impl);
switch(__jakt_match_variant.index()) {
case 7: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::I16>();
i16 const& y = __jakt_match_value.value;
return JaktInternal::ExplicitValue(TRY((types::ValueImpl::template create<typename types::ValueImpl::I16>(JaktInternal::arithmetic_shift_right(x,y)))));
};/*case end*/
default: {
{
TRY((((*this).error(TRY((__jakt_format(Jakt::DeprecatedString("Invalid operands '{}' and '{}' to binary operation"sv),((lhs_value).type_name()),((rhs_value).type_name())))),span))));
return Error::from_errno((infallible_integer_cast<i32>((interpreter::InterpretError::InvalidType))));
}
};/*case end*/
}/*switch end*/
}()
)));
};/*case end*/
case 8: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::I32>();
i32 const& x = __jakt_match_value.value;
return JaktInternal::ExplicitValue(JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<NonnullRefPtr<typename types::ValueImpl>, ErrorOr<interpreter::StatementResult>>{
auto&& __jakt_match_variant = *((rhs_value).impl);
switch(__jakt_match_variant.index()) {
case 8: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::I32>();
i32 const& y = __jakt_match_value.value;
return JaktInternal::ExplicitValue(TRY((types::ValueImpl::template create<typename types::ValueImpl::I32>(JaktInternal::arithmetic_shift_right(x,y)))));
};/*case end*/
default: {
{
TRY((((*this).error(TRY((__jakt_format(Jakt::DeprecatedString("Invalid operands '{}' and '{}' to binary operation"sv),((lhs_value).type_name()),((rhs_value).type_name())))),span))));
return Error::from_errno((infallible_integer_cast<i32>((interpreter::InterpretError::InvalidType))));
}
};/*case end*/
}/*switch end*/
}()
)));
};/*case end*/
case 9: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::I64>();
i64 const& x = __jakt_match_value.value;
return JaktInternal::ExplicitValue(JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<NonnullRefPtr<typename types::ValueImpl>, ErrorOr<interpreter::StatementResult>>{
auto&& __jakt_match_variant = *((rhs_value).impl);
switch(__jakt_match_variant.index()) {
case 9: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::I64>();
i64 const& y = __jakt_match_value.value;
return JaktInternal::ExplicitValue(TRY((types::ValueImpl::template create<typename types::ValueImpl::I64>(JaktInternal::arithmetic_shift_right(x,y)))));
};/*case end*/
default: {
{
TRY((((*this).error(TRY((__jakt_format(Jakt::DeprecatedString("Invalid operands '{}' and '{}' to binary operation"sv),((lhs_value).type_name()),((rhs_value).type_name())))),span))));
return Error::from_errno((infallible_integer_cast<i32>((interpreter::InterpretError::InvalidType))));
}
};/*case end*/
}/*switch end*/
}()
)));
};/*case end*/
case 12: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::USize>();
size_t const& x = __jakt_match_value.value;
return JaktInternal::ExplicitValue(JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<NonnullRefPtr<typename types::ValueImpl>, ErrorOr<interpreter::StatementResult>>{
auto&& __jakt_match_variant = *((rhs_value).impl);
switch(__jakt_match_variant.index()) {
case 12: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::USize>();
size_t const& y = __jakt_match_value.value;
return JaktInternal::ExplicitValue(TRY((types::ValueImpl::template create<typename types::ValueImpl::USize>(JaktInternal::arithmetic_shift_right(x,y)))));
};/*case end*/
default: {
{
TRY((((*this).error(TRY((__jakt_format(Jakt::DeprecatedString("Invalid operands '{}' and '{}' to binary operation"sv),((lhs_value).type_name()),((rhs_value).type_name())))),span))));
return Error::from_errno((infallible_integer_cast<i32>((interpreter::InterpretError::InvalidType))));
}
};/*case end*/
}/*switch end*/
}()
)));
};/*case end*/
default: {
{
TRY((((*this).error(TRY((__jakt_format(Jakt::DeprecatedString("Invalid operands '{}' and '{}' to binary operation"sv),((lhs_value).type_name()),((rhs_value).type_name())))),span))));
return Error::from_errno((infallible_integer_cast<i32>((interpreter::InterpretError::InvalidType))));
}
};/*case end*/
}/*switch end*/
}()
)),span)) } );
};/*case end*/
case 19: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename parser::BinaryOperator::LogicalOr>();
return JaktInternal::ExplicitValue( interpreter::StatementResult { typename interpreter::StatementResult::JustValue(types::Value(JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<NonnullRefPtr<typename types::ValueImpl>, ErrorOr<interpreter::StatementResult>>{
auto&& __jakt_match_variant = *((lhs_value).impl);
switch(__jakt_match_variant.index()) {
case 1: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::Bool>();
bool const& x = __jakt_match_value.value;
return JaktInternal::ExplicitValue(JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<NonnullRefPtr<typename types::ValueImpl>, ErrorOr<interpreter::StatementResult>>{
auto&& __jakt_match_variant = *((rhs_value).impl);
switch(__jakt_match_variant.index()) {
case 1: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::Bool>();
bool const& y = __jakt_match_value.value;
return JaktInternal::ExplicitValue(TRY((types::ValueImpl::template create<typename types::ValueImpl::Bool>((x || y)))));
};/*case end*/
default: {
{
TRY((((*this).error(TRY((__jakt_format(Jakt::DeprecatedString("Invalid operands '{}' and '{}' to binary operation"sv),((lhs_value).type_name()),((rhs_value).type_name())))),span))));
return Error::from_errno((infallible_integer_cast<i32>((interpreter::InterpretError::InvalidType))));
}
};/*case end*/
}/*switch end*/
}()
)));
};/*case end*/
default: {
{
TRY((((*this).error(TRY((__jakt_format(Jakt::DeprecatedString("Invalid operands '{}' and '{}' to binary operation"sv),((lhs_value).type_name()),((rhs_value).type_name())))),span))));
return Error::from_errno((infallible_integer_cast<i32>((interpreter::InterpretError::InvalidType))));
}
};/*case end*/
}/*switch end*/
}()
)),span)) } );
};/*case end*/
case 18: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename parser::BinaryOperator::LogicalAnd>();
return JaktInternal::ExplicitValue( interpreter::StatementResult { typename interpreter::StatementResult::JustValue(types::Value(JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<NonnullRefPtr<typename types::ValueImpl>, ErrorOr<interpreter::StatementResult>>{
auto&& __jakt_match_variant = *((lhs_value).impl);
switch(__jakt_match_variant.index()) {
case 1: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::Bool>();
bool const& x = __jakt_match_value.value;
return JaktInternal::ExplicitValue(JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<NonnullRefPtr<typename types::ValueImpl>, ErrorOr<interpreter::StatementResult>>{
auto&& __jakt_match_variant = *((rhs_value).impl);
switch(__jakt_match_variant.index()) {
case 1: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::Bool>();
bool const& y = __jakt_match_value.value;
return JaktInternal::ExplicitValue(TRY((types::ValueImpl::template create<typename types::ValueImpl::Bool>((x && y)))));
};/*case end*/
default: {
{
TRY((((*this).error(TRY((__jakt_format(Jakt::DeprecatedString("Invalid operands '{}' and '{}' to binary operation"sv),((lhs_value).type_name()),((rhs_value).type_name())))),span))));
return Error::from_errno((infallible_integer_cast<i32>((interpreter::InterpretError::InvalidType))));
}
};/*case end*/
}/*switch end*/
}()
)));
};/*case end*/
default: {
{
TRY((((*this).error(TRY((__jakt_format(Jakt::DeprecatedString("Invalid operands '{}' and '{}' to binary operation"sv),((lhs_value).type_name()),((rhs_value).type_name())))),span))));
return Error::from_errno((infallible_integer_cast<i32>((interpreter::InterpretError::InvalidType))));
}
};/*case end*/
}/*switch end*/
}()
)),span)) } );
};/*case end*/
case 21: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename parser::BinaryOperator::Assign>();
return JaktInternal::ExplicitValue( interpreter::StatementResult { typename interpreter::StatementResult::JustValue(rhs_value) } );
};/*case end*/
case 22: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename parser::BinaryOperator::BitwiseAndAssign>();
return JaktInternal::ExplicitValue(TRY((((*this).execute_binary_operator(lhs_value,rhs_value, parser::BinaryOperator { typename parser::BinaryOperator::BitwiseAnd() } ,span,scope)))));
};/*case end*/
case 23: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename parser::BinaryOperator::BitwiseOrAssign>();
return JaktInternal::ExplicitValue(TRY((((*this).execute_binary_operator(lhs_value,rhs_value, parser::BinaryOperator { typename parser::BinaryOperator::BitwiseOr() } ,span,scope)))));
};/*case end*/
case 24: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename parser::BinaryOperator::BitwiseXorAssign>();
return JaktInternal::ExplicitValue(TRY((((*this).execute_binary_operator(lhs_value,rhs_value, parser::BinaryOperator { typename parser::BinaryOperator::BitwiseXor() } ,span,scope)))));
};/*case end*/
case 25: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename parser::BinaryOperator::BitwiseLeftShiftAssign>();
return JaktInternal::ExplicitValue(TRY((((*this).execute_binary_operator(lhs_value,rhs_value, parser::BinaryOperator { typename parser::BinaryOperator::BitwiseLeftShift() } ,span,scope)))));
};/*case end*/
case 26: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename parser::BinaryOperator::BitwiseRightShiftAssign>();
return JaktInternal::ExplicitValue(TRY((((*this).execute_binary_operator(lhs_value,rhs_value, parser::BinaryOperator { typename parser::BinaryOperator::BitwiseRightShift() } ,span,scope)))));
};/*case end*/
case 27: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename parser::BinaryOperator::AddAssign>();
return JaktInternal::ExplicitValue(TRY((((*this).execute_binary_operator(lhs_value,rhs_value, parser::BinaryOperator { typename parser::BinaryOperator::Add() } ,span,scope)))));
};/*case end*/
case 28: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename parser::BinaryOperator::SubtractAssign>();
return JaktInternal::ExplicitValue(TRY((((*this).execute_binary_operator(lhs_value,rhs_value, parser::BinaryOperator { typename parser::BinaryOperator::Subtract() } ,span,scope)))));
};/*case end*/
case 29: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename parser::BinaryOperator::MultiplyAssign>();
return JaktInternal::ExplicitValue(TRY((((*this).execute_binary_operator(lhs_value,rhs_value, parser::BinaryOperator { typename parser::BinaryOperator::Multiply() } ,span,scope)))));
};/*case end*/
case 30: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename parser::BinaryOperator::ModuloAssign>();
return JaktInternal::ExplicitValue(TRY((((*this).execute_binary_operator(lhs_value,rhs_value, parser::BinaryOperator { typename parser::BinaryOperator::Modulo() } ,span,scope)))));
};/*case end*/
case 31: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename parser::BinaryOperator::DivideAssign>();
return JaktInternal::ExplicitValue(TRY((((*this).execute_binary_operator(lhs_value,rhs_value, parser::BinaryOperator { typename parser::BinaryOperator::Divide() } ,span,scope)))));
};/*case end*/
default: {
{
TRY((((*this).error(TRY((__jakt_format(Jakt::DeprecatedString("Unimplemented binary operator '{}'"sv),op))),span))));
return Error::from_errno((infallible_integer_cast<i32>((interpreter::InterpretError::Unimplemented))));
}
};/*case end*/
}/*switch end*/
}()
)));
}
}

interpreter::Interpreter::Interpreter(NonnullRefPtr<compiler::Compiler>&& a_compiler, NonnullRefPtr<types::CheckedProgram>&& a_program, JaktInternal::DynamicArray<utility::Span>&& a_spans, JaktInternal::Optional<types::FunctionId>&& a_current_function_id): compiler(move(a_compiler)), program(move(a_program)), spans(move(a_spans)), current_function_id(move(a_current_function_id)){}
ErrorOr<NonnullRefPtr<Interpreter>> interpreter::Interpreter::create(NonnullRefPtr<compiler::Compiler> compiler, NonnullRefPtr<types::CheckedProgram> program, JaktInternal::DynamicArray<utility::Span> spans, JaktInternal::Optional<types::FunctionId> current_function_id) { auto o = TRY(adopt_nonnull_ref_or_enomem(new (nothrow) Interpreter (move(compiler), move(program), move(spans), move(current_function_id)))); return o; }
void interpreter::Interpreter::leave_span() {
{
JaktInternal::Optional<utility::Span> const dummy = ((((*this).spans)).pop());
}
}

ErrorOr<void> interpreter::Interpreter::error(DeprecatedString const message,utility::Span const span) {
{
TRY((((((((*this).compiler))->errors)).push( error::JaktError { typename error::JaktError::Message(message,span) } ))));
TRY((((((*this).compiler))->print_errors())));
}
return {};
}

ErrorOr<interpreter::StatementResult> interpreter::Interpreter::execute_expression(NonnullRefPtr<typename types::CheckedExpression> const expr,NonnullRefPtr<interpreter::InterpreterScope> scope) {
{
return (JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<interpreter::StatementResult,ErrorOr<interpreter::StatementResult>>{
auto __jakt_enum_value = (((((*this).current_function_id)).has_value()));
if (__jakt_enum_value == false) {
return JaktInternal::ExplicitValue(TRY((((*this).execute_expression_without_cast(expr,scope)))));
}
else {
return JaktInternal::ExplicitValue(JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<interpreter::StatementResult, ErrorOr<interpreter::StatementResult>>{
auto&& __jakt_match_variant = TRY((((*this).execute_expression_without_cast(expr,scope))));
switch(__jakt_match_variant.index()) {
case 0: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename interpreter::StatementResult::Return>();
types::Value const& value = __jakt_match_value.value;
return JaktInternal::ExplicitValue( interpreter::StatementResult { typename interpreter::StatementResult::Return(TRY((interpreter::cast_value_to_type(value,((((((*this).program))->get_function((((*this).current_function_id).value()))))->return_type_id),*this,false)))) } );
};/*case end*/
case 5: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename interpreter::StatementResult::JustValue>();
types::Value const& value = __jakt_match_value.value;
return JaktInternal::ExplicitValue( interpreter::StatementResult { typename interpreter::StatementResult::JustValue(TRY((interpreter::cast_value_to_type(value,((expr)->type()),*this,false)))) } );
};/*case end*/
case 1: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename interpreter::StatementResult::Throw>();
types::Value const& value = __jakt_match_value.value;
return JaktInternal::ExplicitValue( interpreter::StatementResult { typename interpreter::StatementResult::Throw(value) } );
};/*case end*/
case 2: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename interpreter::StatementResult::Yield>();
types::Value const& value = __jakt_match_value.value;
return JaktInternal::ExplicitValue( interpreter::StatementResult { typename interpreter::StatementResult::Yield(value) } );
};/*case end*/
case 4: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename interpreter::StatementResult::Break>();
return JaktInternal::ExplicitValue( interpreter::StatementResult { typename interpreter::StatementResult::Break() } );
};/*case end*/
case 3: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename interpreter::StatementResult::Continue>();
return JaktInternal::ExplicitValue( interpreter::StatementResult { typename interpreter::StatementResult::Continue() } );
};/*case end*/
default: VERIFY_NOT_REACHED();}/*switch end*/
}()
)));
}
}()))
);
}
}

ErrorOr<NonnullRefPtr<interpreter::Interpreter>> interpreter::Interpreter::create(NonnullRefPtr<compiler::Compiler> const compiler,NonnullRefPtr<types::CheckedProgram> const program,JaktInternal::DynamicArray<utility::Span> const spans) {
{
return (TRY((interpreter::Interpreter::create(compiler,program,spans,JaktInternal::OptionalNone()))));
}
}

ErrorOr<interpreter::StatementResult> interpreter::Interpreter::execute_expression_without_cast(NonnullRefPtr<typename types::CheckedExpression> const expr,NonnullRefPtr<interpreter::InterpreterScope> scope) {
{
return (JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<interpreter::StatementResult, ErrorOr<interpreter::StatementResult>>{
auto&& __jakt_match_variant = *expr;
switch(__jakt_match_variant.index()) {
case 6: {
auto&& __jakt_match_value = __jakt_match_variant.template get<types::CheckedExpression::BinaryOp>();NonnullRefPtr<typename types::CheckedExpression> const& lhs = __jakt_match_value.lhs;
parser::BinaryOperator const& op = __jakt_match_value.op;
NonnullRefPtr<typename types::CheckedExpression> const& rhs = __jakt_match_value.rhs;
utility::Span const& span = __jakt_match_value.span;
return JaktInternal::ExplicitValue(({ Optional<interpreter::StatementResult> __jakt_var_238; {
types::Value const lhs_value = JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<types::Value, ErrorOr<interpreter::StatementResult>>{
auto&& __jakt_match_variant = TRY((((*this).execute_expression(lhs,scope))));
switch(__jakt_match_variant.index()) {
case 0: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename interpreter::StatementResult::Return>();
types::Value const& value = __jakt_match_value.value;
{
return ( interpreter::StatementResult { typename interpreter::StatementResult::Return(value) } );
}
};/*case end*/
case 1: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename interpreter::StatementResult::Throw>();
types::Value const& value = __jakt_match_value.value;
{
return ( interpreter::StatementResult { typename interpreter::StatementResult::Throw(value) } );
}
};/*case end*/
case 5: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename interpreter::StatementResult::JustValue>();
types::Value const& value = __jakt_match_value.value;
return JaktInternal::ExplicitValue(value);
};/*case end*/
case 3: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename interpreter::StatementResult::Continue>();
{
return ( interpreter::StatementResult { typename interpreter::StatementResult::Continue() } );
}
};/*case end*/
case 4: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename interpreter::StatementResult::Break>();
{
return ( interpreter::StatementResult { typename interpreter::StatementResult::Break() } );
}
};/*case end*/
case 2: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename interpreter::StatementResult::Yield>();
types::Value const& expr = __jakt_match_value.value;
{
utility::panic(Jakt::DeprecatedString("Invalid control flow"sv));
}
};/*case end*/
default: VERIFY_NOT_REACHED();}/*switch end*/
}()
));
interpreter::StatementResult const value = JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<interpreter::StatementResult, ErrorOr<interpreter::StatementResult>>{
auto&& __jakt_match_variant = op;
switch(__jakt_match_variant.index()) {
case 20: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename parser::BinaryOperator::NoneCoalescing>();
return JaktInternal::ExplicitValue( interpreter::StatementResult { typename interpreter::StatementResult::JustValue(JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<types::Value, ErrorOr<interpreter::StatementResult>>{
auto&& __jakt_match_variant = *((lhs_value).impl);
switch(__jakt_match_variant.index()) {
case 25: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::OptionalNone>();
return JaktInternal::ExplicitValue(JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<types::Value, ErrorOr<interpreter::StatementResult>>{
auto&& __jakt_match_variant = TRY((((*this).execute_expression(rhs,scope))));
switch(__jakt_match_variant.index()) {
case 0: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename interpreter::StatementResult::Return>();
types::Value const& value = __jakt_match_value.value;
{
return ( interpreter::StatementResult { typename interpreter::StatementResult::Return(value) } );
}
};/*case end*/
case 1: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename interpreter::StatementResult::Throw>();
types::Value const& value = __jakt_match_value.value;
{
return ( interpreter::StatementResult { typename interpreter::StatementResult::Throw(value) } );
}
};/*case end*/
case 5: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename interpreter::StatementResult::JustValue>();
types::Value const& value = __jakt_match_value.value;
return JaktInternal::ExplicitValue(value);
};/*case end*/
case 3: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename interpreter::StatementResult::Continue>();
{
return ( interpreter::StatementResult { typename interpreter::StatementResult::Continue() } );
}
};/*case end*/
case 4: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename interpreter::StatementResult::Break>();
{
return ( interpreter::StatementResult { typename interpreter::StatementResult::Break() } );
}
};/*case end*/
case 2: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename interpreter::StatementResult::Yield>();
types::Value const& expr = __jakt_match_value.value;
{
utility::panic(Jakt::DeprecatedString("Invalid control flow"sv));
}
};/*case end*/
default: VERIFY_NOT_REACHED();}/*switch end*/
}()
)));
};/*case end*/
case 24: {
auto&& __jakt_match_value = __jakt_match_variant.template get<types::ValueImpl::OptionalSome>();types::Value const& value = __jakt_match_value.value;
return JaktInternal::ExplicitValue(value);
};/*case end*/
default: {
{
utility::panic(Jakt::DeprecatedString("Invalid left-hand side of NoneCoalescing"sv));
}
};/*case end*/
}/*switch end*/
}()
))) } );
};/*case end*/
case 32: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename parser::BinaryOperator::NoneCoalescingAssign>();
return JaktInternal::ExplicitValue( interpreter::StatementResult { typename interpreter::StatementResult::JustValue(JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<types::Value, ErrorOr<interpreter::StatementResult>>{
auto&& __jakt_match_variant = *((lhs_value).impl);
switch(__jakt_match_variant.index()) {
case 25: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::OptionalNone>();
return JaktInternal::ExplicitValue(JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<types::Value, ErrorOr<interpreter::StatementResult>>{
auto&& __jakt_match_variant = TRY((((*this).execute_expression(rhs,scope))));
switch(__jakt_match_variant.index()) {
case 0: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename interpreter::StatementResult::Return>();
types::Value const& value = __jakt_match_value.value;
{
return ( interpreter::StatementResult { typename interpreter::StatementResult::Return(value) } );
}
};/*case end*/
case 1: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename interpreter::StatementResult::Throw>();
types::Value const& value = __jakt_match_value.value;
{
return ( interpreter::StatementResult { typename interpreter::StatementResult::Throw(value) } );
}
};/*case end*/
case 5: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename interpreter::StatementResult::JustValue>();
types::Value const& value = __jakt_match_value.value;
return JaktInternal::ExplicitValue(value);
};/*case end*/
case 3: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename interpreter::StatementResult::Continue>();
{
return ( interpreter::StatementResult { typename interpreter::StatementResult::Continue() } );
}
};/*case end*/
case 4: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename interpreter::StatementResult::Break>();
{
return ( interpreter::StatementResult { typename interpreter::StatementResult::Break() } );
}
};/*case end*/
case 2: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename interpreter::StatementResult::Yield>();
types::Value const& expr = __jakt_match_value.value;
{
utility::panic(Jakt::DeprecatedString("Invalid control flow"sv));
}
};/*case end*/
default: VERIFY_NOT_REACHED();}/*switch end*/
}()
)));
};/*case end*/
case 24: {
auto&& __jakt_match_value = __jakt_match_variant.template get<types::ValueImpl::OptionalSome>();types::Value const& value = __jakt_match_value.value;
return JaktInternal::ExplicitValue(value);
};/*case end*/
default: {
{
utility::panic(Jakt::DeprecatedString("Invalid left-hand side of NoneCoalescing"sv));
}
};/*case end*/
}/*switch end*/
}()
))) } );
};/*case end*/
case 18: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename parser::BinaryOperator::LogicalAnd>();
return JaktInternal::ExplicitValue( interpreter::StatementResult { typename interpreter::StatementResult::JustValue(JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<types::Value, ErrorOr<interpreter::StatementResult>>{
auto&& __jakt_match_variant = *((lhs_value).impl);
switch(__jakt_match_variant.index()) {
case 1: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::Bool>();
bool const& x = __jakt_match_value.value;
return JaktInternal::ExplicitValue(JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<types::Value,ErrorOr<interpreter::StatementResult>>{
auto __jakt_enum_value = (x);
if (__jakt_enum_value == ((op).index() == 18 /* LogicalAnd */)) {
return JaktInternal::ExplicitValue(TRY((((JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<types::Value, ErrorOr<interpreter::StatementResult>>{
auto&& __jakt_match_variant = TRY((((*this).execute_expression(rhs,scope))));
switch(__jakt_match_variant.index()) {
case 0: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename interpreter::StatementResult::Return>();
types::Value const& value = __jakt_match_value.value;
{
return ( interpreter::StatementResult { typename interpreter::StatementResult::Return(value) } );
}
};/*case end*/
case 1: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename interpreter::StatementResult::Throw>();
types::Value const& value = __jakt_match_value.value;
{
return ( interpreter::StatementResult { typename interpreter::StatementResult::Throw(value) } );
}
};/*case end*/
case 5: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename interpreter::StatementResult::JustValue>();
types::Value const& value = __jakt_match_value.value;
return JaktInternal::ExplicitValue(value);
};/*case end*/
case 3: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename interpreter::StatementResult::Continue>();
{
return ( interpreter::StatementResult { typename interpreter::StatementResult::Continue() } );
}
};/*case end*/
case 4: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename interpreter::StatementResult::Break>();
{
return ( interpreter::StatementResult { typename interpreter::StatementResult::Break() } );
}
};/*case end*/
case 2: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename interpreter::StatementResult::Yield>();
types::Value const& expr = __jakt_match_value.value;
{
utility::panic(Jakt::DeprecatedString("Invalid control flow"sv));
}
};/*case end*/
default: VERIFY_NOT_REACHED();}/*switch end*/
}()
))).cast(lhs_value,span)))));
}
else {
return JaktInternal::ExplicitValue(lhs_value);
}
}()))
);
};/*case end*/
default: {
{
TRY((((*this).error(TRY((__jakt_format(Jakt::DeprecatedString("Invalid operand '{}' to binary operation"sv),((lhs_value).type_name())))),span))));
return Error::from_errno((infallible_integer_cast<i32>((interpreter::InterpretError::InvalidType))));
}
};/*case end*/
}/*switch end*/
}()
))) } );
};/*case end*/
case 19: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename parser::BinaryOperator::LogicalOr>();
return JaktInternal::ExplicitValue( interpreter::StatementResult { typename interpreter::StatementResult::JustValue(JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<types::Value, ErrorOr<interpreter::StatementResult>>{
auto&& __jakt_match_variant = *((lhs_value).impl);
switch(__jakt_match_variant.index()) {
case 1: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::Bool>();
bool const& x = __jakt_match_value.value;
return JaktInternal::ExplicitValue(JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<types::Value,ErrorOr<interpreter::StatementResult>>{
auto __jakt_enum_value = (x);
if (__jakt_enum_value == ((op).index() == 18 /* LogicalAnd */)) {
return JaktInternal::ExplicitValue(TRY((((JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<types::Value, ErrorOr<interpreter::StatementResult>>{
auto&& __jakt_match_variant = TRY((((*this).execute_expression(rhs,scope))));
switch(__jakt_match_variant.index()) {
case 0: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename interpreter::StatementResult::Return>();
types::Value const& value = __jakt_match_value.value;
{
return ( interpreter::StatementResult { typename interpreter::StatementResult::Return(value) } );
}
};/*case end*/
case 1: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename interpreter::StatementResult::Throw>();
types::Value const& value = __jakt_match_value.value;
{
return ( interpreter::StatementResult { typename interpreter::StatementResult::Throw(value) } );
}
};/*case end*/
case 5: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename interpreter::StatementResult::JustValue>();
types::Value const& value = __jakt_match_value.value;
return JaktInternal::ExplicitValue(value);
};/*case end*/
case 3: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename interpreter::StatementResult::Continue>();
{
return ( interpreter::StatementResult { typename interpreter::StatementResult::Continue() } );
}
};/*case end*/
case 4: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename interpreter::StatementResult::Break>();
{
return ( interpreter::StatementResult { typename interpreter::StatementResult::Break() } );
}
};/*case end*/
case 2: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename interpreter::StatementResult::Yield>();
types::Value const& expr = __jakt_match_value.value;
{
utility::panic(Jakt::DeprecatedString("Invalid control flow"sv));
}
};/*case end*/
default: VERIFY_NOT_REACHED();}/*switch end*/
}()
))).cast(lhs_value,span)))));
}
else {
return JaktInternal::ExplicitValue(lhs_value);
}
}()))
);
};/*case end*/
default: {
{
TRY((((*this).error(TRY((__jakt_format(Jakt::DeprecatedString("Invalid operand '{}' to binary operation"sv),((lhs_value).type_name())))),span))));
return Error::from_errno((infallible_integer_cast<i32>((interpreter::InterpretError::InvalidType))));
}
};/*case end*/
}/*switch end*/
}()
))) } );
};/*case end*/
default: {
return JaktInternal::ExplicitValue(({ Optional<interpreter::StatementResult> __jakt_var_239; {
types::Value const rhs_value = TRY((((JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<types::Value, ErrorOr<interpreter::StatementResult>>{
auto&& __jakt_match_variant = TRY((((*this).execute_expression(rhs,scope))));
switch(__jakt_match_variant.index()) {
case 0: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename interpreter::StatementResult::Return>();
types::Value const& value = __jakt_match_value.value;
{
return ( interpreter::StatementResult { typename interpreter::StatementResult::Return(value) } );
}
};/*case end*/
case 1: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename interpreter::StatementResult::Throw>();
types::Value const& value = __jakt_match_value.value;
{
return ( interpreter::StatementResult { typename interpreter::StatementResult::Throw(value) } );
}
};/*case end*/
case 5: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename interpreter::StatementResult::JustValue>();
types::Value const& value = __jakt_match_value.value;
return JaktInternal::ExplicitValue(value);
};/*case end*/
case 3: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename interpreter::StatementResult::Continue>();
{
return ( interpreter::StatementResult { typename interpreter::StatementResult::Continue() } );
}
};/*case end*/
case 4: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename interpreter::StatementResult::Break>();
{
return ( interpreter::StatementResult { typename interpreter::StatementResult::Break() } );
}
};/*case end*/
case 2: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename interpreter::StatementResult::Yield>();
types::Value const& expr = __jakt_match_value.value;
{
utility::panic(Jakt::DeprecatedString("Invalid control flow"sv));
}
};/*case end*/
default: VERIFY_NOT_REACHED();}/*switch end*/
}()
))).cast(lhs_value,span))));
__jakt_var_239 = TRY((((*this).execute_binary_operator(lhs_value,rhs_value,op,span,scope)))); goto __jakt_label_236;

}
__jakt_label_236:; __jakt_var_239.release_value(); }));
};/*case end*/
}/*switch end*/
}()
));
JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<void, ErrorOr<interpreter::StatementResult>>{
auto&& __jakt_match_variant = value;
switch(__jakt_match_variant.index()) {
case 5: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename interpreter::StatementResult::JustValue>();
types::Value const& value = __jakt_match_value.value;
return (JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<void, ErrorOr<interpreter::StatementResult>>{
auto&& __jakt_match_variant = op;
switch(__jakt_match_variant.index()) {
case 21: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename parser::BinaryOperator::Assign>();
{
TRY((((*this).update_binding(lhs,scope,value,span))));
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 22: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename parser::BinaryOperator::BitwiseAndAssign>();
{
TRY((((*this).update_binding(lhs,scope,value,span))));
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 23: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename parser::BinaryOperator::BitwiseOrAssign>();
{
TRY((((*this).update_binding(lhs,scope,value,span))));
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 24: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename parser::BinaryOperator::BitwiseXorAssign>();
{
TRY((((*this).update_binding(lhs,scope,value,span))));
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 25: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename parser::BinaryOperator::BitwiseLeftShiftAssign>();
{
TRY((((*this).update_binding(lhs,scope,value,span))));
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 26: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename parser::BinaryOperator::BitwiseRightShiftAssign>();
{
TRY((((*this).update_binding(lhs,scope,value,span))));
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 27: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename parser::BinaryOperator::AddAssign>();
{
TRY((((*this).update_binding(lhs,scope,value,span))));
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 28: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename parser::BinaryOperator::SubtractAssign>();
{
TRY((((*this).update_binding(lhs,scope,value,span))));
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 29: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename parser::BinaryOperator::MultiplyAssign>();
{
TRY((((*this).update_binding(lhs,scope,value,span))));
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 30: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename parser::BinaryOperator::ModuloAssign>();
{
TRY((((*this).update_binding(lhs,scope,value,span))));
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 31: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename parser::BinaryOperator::DivideAssign>();
{
TRY((((*this).update_binding(lhs,scope,value,span))));
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 32: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename parser::BinaryOperator::NoneCoalescingAssign>();
{
TRY((((*this).update_binding(lhs,scope,value,span))));
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
default: {
{
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
}/*switch end*/
}()
))), JaktInternal::ExplicitValue<void>();
};/*case end*/
default: {
{
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
}/*switch end*/
}()
));
__jakt_var_238 = value; goto __jakt_label_235;

}
__jakt_label_235:; __jakt_var_238.release_value(); }));
};/*case end*/
case 5: {
auto&& __jakt_match_value = __jakt_match_variant.template get<types::CheckedExpression::UnaryOp>();NonnullRefPtr<typename types::CheckedExpression> const& expr = __jakt_match_value.expr;
types::CheckedUnaryOperator const& op = __jakt_match_value.op;
utility::Span const& span = __jakt_match_value.span;
return JaktInternal::ExplicitValue(({ Optional<interpreter::StatementResult> __jakt_var_240; {
types::Value const value = JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<types::Value, ErrorOr<interpreter::StatementResult>>{
auto&& __jakt_match_variant = TRY((((*this).execute_expression(expr,scope))));
switch(__jakt_match_variant.index()) {
case 0: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename interpreter::StatementResult::Return>();
types::Value const& value = __jakt_match_value.value;
{
return ( interpreter::StatementResult { typename interpreter::StatementResult::Return(value) } );
}
};/*case end*/
case 1: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename interpreter::StatementResult::Throw>();
types::Value const& value = __jakt_match_value.value;
{
return ( interpreter::StatementResult { typename interpreter::StatementResult::Throw(value) } );
}
};/*case end*/
case 5: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename interpreter::StatementResult::JustValue>();
types::Value const& value = __jakt_match_value.value;
return JaktInternal::ExplicitValue(value);
};/*case end*/
case 3: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename interpreter::StatementResult::Continue>();
{
return ( interpreter::StatementResult { typename interpreter::StatementResult::Continue() } );
}
};/*case end*/
case 4: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename interpreter::StatementResult::Break>();
{
return ( interpreter::StatementResult { typename interpreter::StatementResult::Break() } );
}
};/*case end*/
case 2: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename interpreter::StatementResult::Yield>();
types::Value const& expr = __jakt_match_value.value;
{
utility::panic(Jakt::DeprecatedString("Invalid control flow"sv));
}
};/*case end*/
default: VERIFY_NOT_REACHED();}/*switch end*/
}()
));
__jakt_var_240 = JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<interpreter::StatementResult, ErrorOr<interpreter::StatementResult>>{
auto&& __jakt_match_variant = op;
switch(__jakt_match_variant.index()) {
case 9: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::CheckedUnaryOperator::LogicalNot>();
return JaktInternal::ExplicitValue(JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<interpreter::StatementResult, ErrorOr<interpreter::StatementResult>>{
auto&& __jakt_match_variant = *((value).impl);
switch(__jakt_match_variant.index()) {
case 1: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::Bool>();
bool const& value = __jakt_match_value.value;
return JaktInternal::ExplicitValue( interpreter::StatementResult { typename interpreter::StatementResult::JustValue(types::Value(TRY((types::ValueImpl::template create<typename types::ValueImpl::Bool>((!(value))))),span)) } );
};/*case end*/
default: {
{
TRY((((*this).error(TRY((__jakt_format(Jakt::DeprecatedString("Invalid type for unary operator"sv)))),span))));
return Error::from_errno((infallible_integer_cast<i32>((interpreter::InterpretError::InvalidType))));
}
};/*case end*/
}/*switch end*/
}()
)));
};/*case end*/
case 1: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::CheckedUnaryOperator::PostIncrement>();
return JaktInternal::ExplicitValue( interpreter::StatementResult { typename interpreter::StatementResult::JustValue(JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<types::Value, ErrorOr<interpreter::StatementResult>>{
auto&& __jakt_match_variant = *((value).impl);
switch(__jakt_match_variant.index()) {
case 2: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::U8>();
u8 const& x = __jakt_match_value.value;
return JaktInternal::ExplicitValue(({ Optional<types::Value> __jakt_var_241; {
TRY((((*this).update_binding(expr,scope,types::Value(TRY((types::ValueImpl::template create<typename types::ValueImpl::U8>((JaktInternal::checked_add<u8>(x,static_cast<u8>(1)))))),span),span))));
__jakt_var_241 = value; goto __jakt_label_238;

}
__jakt_label_238:; __jakt_var_241.release_value(); }));
};/*case end*/
case 6: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::I8>();
i8 const& x = __jakt_match_value.value;
return JaktInternal::ExplicitValue(({ Optional<types::Value> __jakt_var_242; {
TRY((((*this).update_binding(expr,scope,types::Value(TRY((types::ValueImpl::template create<typename types::ValueImpl::I8>((JaktInternal::checked_add<i8>(x,static_cast<i8>(1)))))),span),span))));
__jakt_var_242 = value; goto __jakt_label_239;

}
__jakt_label_239:; __jakt_var_242.release_value(); }));
};/*case end*/
case 3: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::U16>();
u16 const& x = __jakt_match_value.value;
return JaktInternal::ExplicitValue(({ Optional<types::Value> __jakt_var_243; {
TRY((((*this).update_binding(expr,scope,types::Value(TRY((types::ValueImpl::template create<typename types::ValueImpl::U16>((JaktInternal::checked_add<u16>(x,static_cast<u16>(1)))))),span),span))));
__jakt_var_243 = value; goto __jakt_label_240;

}
__jakt_label_240:; __jakt_var_243.release_value(); }));
};/*case end*/
case 7: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::I16>();
i16 const& x = __jakt_match_value.value;
return JaktInternal::ExplicitValue(({ Optional<types::Value> __jakt_var_244; {
TRY((((*this).update_binding(expr,scope,types::Value(TRY((types::ValueImpl::template create<typename types::ValueImpl::I16>((JaktInternal::checked_add<i16>(x,static_cast<i16>(1)))))),span),span))));
__jakt_var_244 = value; goto __jakt_label_241;

}
__jakt_label_241:; __jakt_var_244.release_value(); }));
};/*case end*/
case 4: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::U32>();
u32 const& x = __jakt_match_value.value;
return JaktInternal::ExplicitValue(({ Optional<types::Value> __jakt_var_245; {
TRY((((*this).update_binding(expr,scope,types::Value(TRY((types::ValueImpl::template create<typename types::ValueImpl::U32>((JaktInternal::checked_add<u32>(x,static_cast<u32>(1)))))),span),span))));
__jakt_var_245 = value; goto __jakt_label_242;

}
__jakt_label_242:; __jakt_var_245.release_value(); }));
};/*case end*/
case 8: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::I32>();
i32 const& x = __jakt_match_value.value;
return JaktInternal::ExplicitValue(({ Optional<types::Value> __jakt_var_246; {
TRY((((*this).update_binding(expr,scope,types::Value(TRY((types::ValueImpl::template create<typename types::ValueImpl::I32>((JaktInternal::checked_add<i32>(x,static_cast<i32>(1)))))),span),span))));
__jakt_var_246 = value; goto __jakt_label_243;

}
__jakt_label_243:; __jakt_var_246.release_value(); }));
};/*case end*/
case 5: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::U64>();
u64 const& x = __jakt_match_value.value;
return JaktInternal::ExplicitValue(({ Optional<types::Value> __jakt_var_247; {
TRY((((*this).update_binding(expr,scope,types::Value(TRY((types::ValueImpl::template create<typename types::ValueImpl::U64>((JaktInternal::checked_add<u64>(x,static_cast<u64>(1ULL)))))),span),span))));
__jakt_var_247 = value; goto __jakt_label_244;

}
__jakt_label_244:; __jakt_var_247.release_value(); }));
};/*case end*/
case 9: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::I64>();
i64 const& x = __jakt_match_value.value;
return JaktInternal::ExplicitValue(({ Optional<types::Value> __jakt_var_248; {
TRY((((*this).update_binding(expr,scope,types::Value(TRY((types::ValueImpl::template create<typename types::ValueImpl::I64>((JaktInternal::checked_add<i64>(x,static_cast<i64>(1LL)))))),span),span))));
__jakt_var_248 = value; goto __jakt_label_245;

}
__jakt_label_245:; __jakt_var_248.release_value(); }));
};/*case end*/
case 15: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::CChar>();
char const& x = __jakt_match_value.value;
return JaktInternal::ExplicitValue(({ Optional<types::Value> __jakt_var_249; {
TRY((((*this).update_binding(expr,scope,types::Value(TRY((types::ValueImpl::template create<typename types::ValueImpl::CChar>((JaktInternal::checked_add<char>(x,static_cast<char>(1)))))),span),span))));
__jakt_var_249 = value; goto __jakt_label_246;

}
__jakt_label_246:; __jakt_var_249.release_value(); }));
};/*case end*/
case 16: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::CInt>();
int const& x = __jakt_match_value.value;
return JaktInternal::ExplicitValue(({ Optional<types::Value> __jakt_var_250; {
TRY((((*this).update_binding(expr,scope,types::Value(TRY((types::ValueImpl::template create<typename types::ValueImpl::CInt>((JaktInternal::checked_add<int>(x,static_cast<size_t>(1ULL)))))),span),span))));
__jakt_var_250 = value; goto __jakt_label_247;

}
__jakt_label_247:; __jakt_var_250.release_value(); }));
};/*case end*/
case 12: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::USize>();
size_t const& x = __jakt_match_value.value;
return JaktInternal::ExplicitValue(({ Optional<types::Value> __jakt_var_251; {
TRY((((*this).update_binding(expr,scope,types::Value(TRY((types::ValueImpl::template create<typename types::ValueImpl::USize>((JaktInternal::checked_add<size_t>(x,static_cast<size_t>(1ULL)))))),span),span))));
__jakt_var_251 = value; goto __jakt_label_248;

}
__jakt_label_248:; __jakt_var_251.release_value(); }));
};/*case end*/
default: {
{
TRY((((*this).error(TRY((__jakt_format(Jakt::DeprecatedString("Invalid type for unary operator"sv)))),span))));
return Error::from_errno((infallible_integer_cast<i32>((interpreter::InterpretError::InvalidType))));
}
};/*case end*/
}/*switch end*/
}()
))) } );
};/*case end*/
case 0: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::CheckedUnaryOperator::PreIncrement>();
return JaktInternal::ExplicitValue( interpreter::StatementResult { typename interpreter::StatementResult::JustValue(JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<types::Value, ErrorOr<interpreter::StatementResult>>{
auto&& __jakt_match_variant = *((value).impl);
switch(__jakt_match_variant.index()) {
case 2: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::U8>();
u8 const& x = __jakt_match_value.value;
return JaktInternal::ExplicitValue(({ Optional<types::Value> __jakt_var_252; {
types::Value const value = types::Value(TRY((types::ValueImpl::template create<typename types::ValueImpl::U8>((JaktInternal::checked_add<u8>(x,static_cast<u8>(1)))))),span);
TRY((((*this).update_binding(expr,scope,value,span))));
__jakt_var_252 = value; goto __jakt_label_249;

}
__jakt_label_249:; __jakt_var_252.release_value(); }));
};/*case end*/
case 6: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::I8>();
i8 const& x = __jakt_match_value.value;
return JaktInternal::ExplicitValue(({ Optional<types::Value> __jakt_var_253; {
types::Value const value = types::Value(TRY((types::ValueImpl::template create<typename types::ValueImpl::I8>((JaktInternal::checked_add<i8>(x,static_cast<i8>(1)))))),span);
TRY((((*this).update_binding(expr,scope,value,span))));
__jakt_var_253 = value; goto __jakt_label_250;

}
__jakt_label_250:; __jakt_var_253.release_value(); }));
};/*case end*/
case 3: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::U16>();
u16 const& x = __jakt_match_value.value;
return JaktInternal::ExplicitValue(({ Optional<types::Value> __jakt_var_254; {
types::Value const value = types::Value(TRY((types::ValueImpl::template create<typename types::ValueImpl::U16>((JaktInternal::checked_add<u16>(x,static_cast<u16>(1)))))),span);
TRY((((*this).update_binding(expr,scope,value,span))));
__jakt_var_254 = value; goto __jakt_label_251;

}
__jakt_label_251:; __jakt_var_254.release_value(); }));
};/*case end*/
case 7: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::I16>();
i16 const& x = __jakt_match_value.value;
return JaktInternal::ExplicitValue(({ Optional<types::Value> __jakt_var_255; {
types::Value const value = types::Value(TRY((types::ValueImpl::template create<typename types::ValueImpl::I16>((JaktInternal::checked_add<i16>(x,static_cast<i16>(1)))))),span);
TRY((((*this).update_binding(expr,scope,value,span))));
__jakt_var_255 = value; goto __jakt_label_252;

}
__jakt_label_252:; __jakt_var_255.release_value(); }));
};/*case end*/
case 4: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::U32>();
u32 const& x = __jakt_match_value.value;
return JaktInternal::ExplicitValue(({ Optional<types::Value> __jakt_var_256; {
types::Value const value = types::Value(TRY((types::ValueImpl::template create<typename types::ValueImpl::U32>((JaktInternal::checked_add<u32>(x,static_cast<u32>(1)))))),span);
TRY((((*this).update_binding(expr,scope,value,span))));
__jakt_var_256 = value; goto __jakt_label_253;

}
__jakt_label_253:; __jakt_var_256.release_value(); }));
};/*case end*/
case 8: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::I32>();
i32 const& x = __jakt_match_value.value;
return JaktInternal::ExplicitValue(({ Optional<types::Value> __jakt_var_257; {
types::Value const value = types::Value(TRY((types::ValueImpl::template create<typename types::ValueImpl::I32>((JaktInternal::checked_add<i32>(x,static_cast<i32>(1)))))),span);
TRY((((*this).update_binding(expr,scope,value,span))));
__jakt_var_257 = value; goto __jakt_label_254;

}
__jakt_label_254:; __jakt_var_257.release_value(); }));
};/*case end*/
case 5: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::U64>();
u64 const& x = __jakt_match_value.value;
return JaktInternal::ExplicitValue(({ Optional<types::Value> __jakt_var_258; {
types::Value const value = types::Value(TRY((types::ValueImpl::template create<typename types::ValueImpl::U64>((JaktInternal::checked_add<u64>(x,static_cast<u64>(1ULL)))))),span);
TRY((((*this).update_binding(expr,scope,value,span))));
__jakt_var_258 = value; goto __jakt_label_255;

}
__jakt_label_255:; __jakt_var_258.release_value(); }));
};/*case end*/
case 9: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::I64>();
i64 const& x = __jakt_match_value.value;
return JaktInternal::ExplicitValue(({ Optional<types::Value> __jakt_var_259; {
types::Value const value = types::Value(TRY((types::ValueImpl::template create<typename types::ValueImpl::I64>((JaktInternal::checked_add<i64>(x,static_cast<i64>(1LL)))))),span);
TRY((((*this).update_binding(expr,scope,value,span))));
__jakt_var_259 = value; goto __jakt_label_256;

}
__jakt_label_256:; __jakt_var_259.release_value(); }));
};/*case end*/
case 15: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::CChar>();
char const& x = __jakt_match_value.value;
return JaktInternal::ExplicitValue(({ Optional<types::Value> __jakt_var_260; {
types::Value const value = types::Value(TRY((types::ValueImpl::template create<typename types::ValueImpl::CChar>((JaktInternal::checked_add<char>(x,static_cast<char>(1)))))),span);
TRY((((*this).update_binding(expr,scope,value,span))));
__jakt_var_260 = value; goto __jakt_label_257;

}
__jakt_label_257:; __jakt_var_260.release_value(); }));
};/*case end*/
case 16: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::CInt>();
int const& x = __jakt_match_value.value;
return JaktInternal::ExplicitValue(({ Optional<types::Value> __jakt_var_261; {
types::Value const value = types::Value(TRY((types::ValueImpl::template create<typename types::ValueImpl::CInt>((JaktInternal::checked_add<int>(x,static_cast<size_t>(1ULL)))))),span);
TRY((((*this).update_binding(expr,scope,value,span))));
__jakt_var_261 = value; goto __jakt_label_258;

}
__jakt_label_258:; __jakt_var_261.release_value(); }));
};/*case end*/
case 12: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::USize>();
size_t const& x = __jakt_match_value.value;
return JaktInternal::ExplicitValue(({ Optional<types::Value> __jakt_var_262; {
types::Value const value = types::Value(TRY((types::ValueImpl::template create<typename types::ValueImpl::USize>((JaktInternal::checked_add<size_t>(x,static_cast<size_t>(1ULL)))))),span);
TRY((((*this).update_binding(expr,scope,value,span))));
__jakt_var_262 = value; goto __jakt_label_259;

}
__jakt_label_259:; __jakt_var_262.release_value(); }));
};/*case end*/
default: {
{
TRY((((*this).error(TRY((__jakt_format(Jakt::DeprecatedString("Invalid type for unary operator"sv)))),span))));
return Error::from_errno((infallible_integer_cast<i32>((interpreter::InterpretError::InvalidType))));
}
};/*case end*/
}/*switch end*/
}()
))) } );
};/*case end*/
case 3: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::CheckedUnaryOperator::PostDecrement>();
return JaktInternal::ExplicitValue( interpreter::StatementResult { typename interpreter::StatementResult::JustValue(JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<types::Value, ErrorOr<interpreter::StatementResult>>{
auto&& __jakt_match_variant = *((value).impl);
switch(__jakt_match_variant.index()) {
case 2: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::U8>();
u8 const& x = __jakt_match_value.value;
return JaktInternal::ExplicitValue(({ Optional<types::Value> __jakt_var_263; {
TRY((((*this).update_binding(expr,scope,types::Value(TRY((types::ValueImpl::template create<typename types::ValueImpl::U8>((JaktInternal::checked_sub<u8>(x,static_cast<u8>(1)))))),span),span))));
__jakt_var_263 = value; goto __jakt_label_260;

}
__jakt_label_260:; __jakt_var_263.release_value(); }));
};/*case end*/
case 6: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::I8>();
i8 const& x = __jakt_match_value.value;
return JaktInternal::ExplicitValue(({ Optional<types::Value> __jakt_var_264; {
TRY((((*this).update_binding(expr,scope,types::Value(TRY((types::ValueImpl::template create<typename types::ValueImpl::I8>((JaktInternal::checked_sub<i8>(x,static_cast<i8>(1)))))),span),span))));
__jakt_var_264 = value; goto __jakt_label_261;

}
__jakt_label_261:; __jakt_var_264.release_value(); }));
};/*case end*/
case 3: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::U16>();
u16 const& x = __jakt_match_value.value;
return JaktInternal::ExplicitValue(({ Optional<types::Value> __jakt_var_265; {
TRY((((*this).update_binding(expr,scope,types::Value(TRY((types::ValueImpl::template create<typename types::ValueImpl::U16>((JaktInternal::checked_sub<u16>(x,static_cast<u16>(1)))))),span),span))));
__jakt_var_265 = value; goto __jakt_label_262;

}
__jakt_label_262:; __jakt_var_265.release_value(); }));
};/*case end*/
case 7: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::I16>();
i16 const& x = __jakt_match_value.value;
return JaktInternal::ExplicitValue(({ Optional<types::Value> __jakt_var_266; {
TRY((((*this).update_binding(expr,scope,types::Value(TRY((types::ValueImpl::template create<typename types::ValueImpl::I16>((JaktInternal::checked_sub<i16>(x,static_cast<i16>(1)))))),span),span))));
__jakt_var_266 = value; goto __jakt_label_263;

}
__jakt_label_263:; __jakt_var_266.release_value(); }));
};/*case end*/
case 4: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::U32>();
u32 const& x = __jakt_match_value.value;
return JaktInternal::ExplicitValue(({ Optional<types::Value> __jakt_var_267; {
TRY((((*this).update_binding(expr,scope,types::Value(TRY((types::ValueImpl::template create<typename types::ValueImpl::U32>((JaktInternal::checked_sub<u32>(x,static_cast<u32>(1)))))),span),span))));
__jakt_var_267 = value; goto __jakt_label_264;

}
__jakt_label_264:; __jakt_var_267.release_value(); }));
};/*case end*/
case 8: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::I32>();
i32 const& x = __jakt_match_value.value;
return JaktInternal::ExplicitValue(({ Optional<types::Value> __jakt_var_268; {
TRY((((*this).update_binding(expr,scope,types::Value(TRY((types::ValueImpl::template create<typename types::ValueImpl::I32>((JaktInternal::checked_sub<i32>(x,static_cast<i32>(1)))))),span),span))));
__jakt_var_268 = value; goto __jakt_label_265;

}
__jakt_label_265:; __jakt_var_268.release_value(); }));
};/*case end*/
case 5: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::U64>();
u64 const& x = __jakt_match_value.value;
return JaktInternal::ExplicitValue(({ Optional<types::Value> __jakt_var_269; {
TRY((((*this).update_binding(expr,scope,types::Value(TRY((types::ValueImpl::template create<typename types::ValueImpl::U64>((JaktInternal::checked_sub<u64>(x,static_cast<u64>(1ULL)))))),span),span))));
__jakt_var_269 = value; goto __jakt_label_266;

}
__jakt_label_266:; __jakt_var_269.release_value(); }));
};/*case end*/
case 9: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::I64>();
i64 const& x = __jakt_match_value.value;
return JaktInternal::ExplicitValue(({ Optional<types::Value> __jakt_var_270; {
TRY((((*this).update_binding(expr,scope,types::Value(TRY((types::ValueImpl::template create<typename types::ValueImpl::I64>((JaktInternal::checked_sub<i64>(x,static_cast<i64>(1LL)))))),span),span))));
__jakt_var_270 = value; goto __jakt_label_267;

}
__jakt_label_267:; __jakt_var_270.release_value(); }));
};/*case end*/
case 15: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::CChar>();
char const& x = __jakt_match_value.value;
return JaktInternal::ExplicitValue(({ Optional<types::Value> __jakt_var_271; {
TRY((((*this).update_binding(expr,scope,types::Value(TRY((types::ValueImpl::template create<typename types::ValueImpl::CChar>((JaktInternal::checked_sub<char>(x,static_cast<char>(1)))))),span),span))));
__jakt_var_271 = value; goto __jakt_label_268;

}
__jakt_label_268:; __jakt_var_271.release_value(); }));
};/*case end*/
case 16: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::CInt>();
int const& x = __jakt_match_value.value;
return JaktInternal::ExplicitValue(({ Optional<types::Value> __jakt_var_272; {
TRY((((*this).update_binding(expr,scope,types::Value(TRY((types::ValueImpl::template create<typename types::ValueImpl::CInt>((JaktInternal::checked_sub<int>(x,static_cast<size_t>(1ULL)))))),span),span))));
__jakt_var_272 = value; goto __jakt_label_269;

}
__jakt_label_269:; __jakt_var_272.release_value(); }));
};/*case end*/
case 12: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::USize>();
size_t const& x = __jakt_match_value.value;
return JaktInternal::ExplicitValue(({ Optional<types::Value> __jakt_var_273; {
TRY((((*this).update_binding(expr,scope,types::Value(TRY((types::ValueImpl::template create<typename types::ValueImpl::USize>((JaktInternal::checked_sub<size_t>(x,static_cast<size_t>(1ULL)))))),span),span))));
__jakt_var_273 = value; goto __jakt_label_270;

}
__jakt_label_270:; __jakt_var_273.release_value(); }));
};/*case end*/
default: {
{
TRY((((*this).error(TRY((__jakt_format(Jakt::DeprecatedString("Invalid type for unary operator"sv)))),span))));
return Error::from_errno((infallible_integer_cast<i32>((interpreter::InterpretError::InvalidType))));
}
};/*case end*/
}/*switch end*/
}()
))) } );
};/*case end*/
case 2: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::CheckedUnaryOperator::PreDecrement>();
return JaktInternal::ExplicitValue( interpreter::StatementResult { typename interpreter::StatementResult::JustValue(JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<types::Value, ErrorOr<interpreter::StatementResult>>{
auto&& __jakt_match_variant = *((value).impl);
switch(__jakt_match_variant.index()) {
case 2: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::U8>();
u8 const& x = __jakt_match_value.value;
return JaktInternal::ExplicitValue(({ Optional<types::Value> __jakt_var_274; {
types::Value const value = types::Value(TRY((types::ValueImpl::template create<typename types::ValueImpl::U8>((JaktInternal::checked_sub<u8>(x,static_cast<u8>(1)))))),span);
TRY((((*this).update_binding(expr,scope,value,span))));
__jakt_var_274 = value; goto __jakt_label_271;

}
__jakt_label_271:; __jakt_var_274.release_value(); }));
};/*case end*/
case 6: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::I8>();
i8 const& x = __jakt_match_value.value;
return JaktInternal::ExplicitValue(({ Optional<types::Value> __jakt_var_275; {
types::Value const value = types::Value(TRY((types::ValueImpl::template create<typename types::ValueImpl::I8>((JaktInternal::checked_sub<i8>(x,static_cast<i8>(1)))))),span);
TRY((((*this).update_binding(expr,scope,value,span))));
__jakt_var_275 = value; goto __jakt_label_272;

}
__jakt_label_272:; __jakt_var_275.release_value(); }));
};/*case end*/
case 3: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::U16>();
u16 const& x = __jakt_match_value.value;
return JaktInternal::ExplicitValue(({ Optional<types::Value> __jakt_var_276; {
types::Value const value = types::Value(TRY((types::ValueImpl::template create<typename types::ValueImpl::U16>((JaktInternal::checked_sub<u16>(x,static_cast<u16>(1)))))),span);
TRY((((*this).update_binding(expr,scope,value,span))));
__jakt_var_276 = value; goto __jakt_label_273;

}
__jakt_label_273:; __jakt_var_276.release_value(); }));
};/*case end*/
case 7: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::I16>();
i16 const& x = __jakt_match_value.value;
return JaktInternal::ExplicitValue(({ Optional<types::Value> __jakt_var_277; {
types::Value const value = types::Value(TRY((types::ValueImpl::template create<typename types::ValueImpl::I16>((JaktInternal::checked_sub<i16>(x,static_cast<i16>(1)))))),span);
TRY((((*this).update_binding(expr,scope,value,span))));
__jakt_var_277 = value; goto __jakt_label_274;

}
__jakt_label_274:; __jakt_var_277.release_value(); }));
};/*case end*/
case 4: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::U32>();
u32 const& x = __jakt_match_value.value;
return JaktInternal::ExplicitValue(({ Optional<types::Value> __jakt_var_278; {
types::Value const value = types::Value(TRY((types::ValueImpl::template create<typename types::ValueImpl::U32>((JaktInternal::checked_sub<u32>(x,static_cast<u32>(1)))))),span);
TRY((((*this).update_binding(expr,scope,value,span))));
__jakt_var_278 = value; goto __jakt_label_275;

}
__jakt_label_275:; __jakt_var_278.release_value(); }));
};/*case end*/
case 8: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::I32>();
i32 const& x = __jakt_match_value.value;
return JaktInternal::ExplicitValue(({ Optional<types::Value> __jakt_var_279; {
types::Value const value = types::Value(TRY((types::ValueImpl::template create<typename types::ValueImpl::I32>((JaktInternal::checked_sub<i32>(x,static_cast<i32>(1)))))),span);
TRY((((*this).update_binding(expr,scope,value,span))));
__jakt_var_279 = value; goto __jakt_label_276;

}
__jakt_label_276:; __jakt_var_279.release_value(); }));
};/*case end*/
case 5: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::U64>();
u64 const& x = __jakt_match_value.value;
return JaktInternal::ExplicitValue(({ Optional<types::Value> __jakt_var_280; {
types::Value const value = types::Value(TRY((types::ValueImpl::template create<typename types::ValueImpl::U64>((JaktInternal::checked_sub<u64>(x,static_cast<u64>(1ULL)))))),span);
TRY((((*this).update_binding(expr,scope,value,span))));
__jakt_var_280 = value; goto __jakt_label_277;

}
__jakt_label_277:; __jakt_var_280.release_value(); }));
};/*case end*/
case 9: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::I64>();
i64 const& x = __jakt_match_value.value;
return JaktInternal::ExplicitValue(({ Optional<types::Value> __jakt_var_281; {
types::Value const value = types::Value(TRY((types::ValueImpl::template create<typename types::ValueImpl::I64>((JaktInternal::checked_sub<i64>(x,static_cast<i64>(1LL)))))),span);
TRY((((*this).update_binding(expr,scope,value,span))));
__jakt_var_281 = value; goto __jakt_label_278;

}
__jakt_label_278:; __jakt_var_281.release_value(); }));
};/*case end*/
case 15: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::CChar>();
char const& x = __jakt_match_value.value;
return JaktInternal::ExplicitValue(({ Optional<types::Value> __jakt_var_282; {
types::Value const value = types::Value(TRY((types::ValueImpl::template create<typename types::ValueImpl::CChar>((JaktInternal::checked_sub<char>(x,static_cast<char>(1)))))),span);
TRY((((*this).update_binding(expr,scope,value,span))));
__jakt_var_282 = value; goto __jakt_label_279;

}
__jakt_label_279:; __jakt_var_282.release_value(); }));
};/*case end*/
case 16: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::CInt>();
int const& x = __jakt_match_value.value;
return JaktInternal::ExplicitValue(({ Optional<types::Value> __jakt_var_283; {
types::Value const value = types::Value(TRY((types::ValueImpl::template create<typename types::ValueImpl::CInt>((JaktInternal::checked_sub<int>(x,static_cast<size_t>(1ULL)))))),span);
TRY((((*this).update_binding(expr,scope,value,span))));
__jakt_var_283 = value; goto __jakt_label_280;

}
__jakt_label_280:; __jakt_var_283.release_value(); }));
};/*case end*/
case 12: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::USize>();
size_t const& x = __jakt_match_value.value;
return JaktInternal::ExplicitValue(({ Optional<types::Value> __jakt_var_284; {
types::Value const value = types::Value(TRY((types::ValueImpl::template create<typename types::ValueImpl::USize>((JaktInternal::checked_sub<size_t>(x,static_cast<size_t>(1ULL)))))),span);
TRY((((*this).update_binding(expr,scope,value,span))));
__jakt_var_284 = value; goto __jakt_label_281;

}
__jakt_label_281:; __jakt_var_284.release_value(); }));
};/*case end*/
default: {
{
TRY((((*this).error(TRY((__jakt_format(Jakt::DeprecatedString("Invalid type for unary operator"sv)))),span))));
return Error::from_errno((infallible_integer_cast<i32>((interpreter::InterpretError::InvalidType))));
}
};/*case end*/
}/*switch end*/
}()
))) } );
};/*case end*/
case 11: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::CheckedUnaryOperator::TypeCast>();
types::CheckedTypeCast const& cast = __jakt_match_value.value;
return JaktInternal::ExplicitValue(JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<interpreter::StatementResult, ErrorOr<interpreter::StatementResult>>{
auto&& __jakt_match_variant = cast;
switch(__jakt_match_variant.index()) {
case 1: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::CheckedTypeCast::Infallible>();
types::TypeId const& type_id = __jakt_match_value.value;
return JaktInternal::ExplicitValue( interpreter::StatementResult { typename interpreter::StatementResult::JustValue(TRY((interpreter::cast_value_to_type(value,type_id,*this,false)))) } );
};/*case end*/
case 0: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::CheckedTypeCast::Fallible>();
types::TypeId const& type_id = __jakt_match_value.value;
return JaktInternal::ExplicitValue(({ Optional<interpreter::StatementResult> __jakt_var_285; {
__jakt_var_285 =  interpreter::StatementResult { typename interpreter::StatementResult::JustValue(types::Value(TRY((types::ValueImpl::template create<typename types::ValueImpl::OptionalSome>(TRY((interpreter::cast_value_to_type(value,type_id,*this,false)))))),span)) } ; goto __jakt_label_282;

}
__jakt_label_282:; __jakt_var_285.release_value(); }));
};/*case end*/
default: VERIFY_NOT_REACHED();}/*switch end*/
}()
)));
};/*case end*/
case 13: {
auto&& __jakt_match_value = __jakt_match_variant.template get<types::CheckedUnaryOperator::IsEnumVariant>();types::CheckedEnumVariant const& enum_variant = __jakt_match_value.enum_variant;
JaktInternal::DynamicArray<types::CheckedEnumVariantBinding> const& bindings = __jakt_match_value.bindings;
return JaktInternal::ExplicitValue(JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<interpreter::StatementResult, ErrorOr<interpreter::StatementResult>>{
auto&& __jakt_match_variant = *((value).impl);
switch(__jakt_match_variant.index()) {
case 19: {
auto&& __jakt_match_value = __jakt_match_variant.template get<types::ValueImpl::Enum>();JaktInternal::DynamicArray<types::Value> const& fields = __jakt_match_value.fields;
types::FunctionId const& constructor = __jakt_match_value.constructor;
return JaktInternal::ExplicitValue(({ Optional<interpreter::StatementResult> __jakt_var_286; {
DeprecatedString const constructor_name = ((((((*this).program))->get_function(constructor)))->name);
if ((((enum_variant).name()) != constructor_name)){
return ( interpreter::StatementResult { typename interpreter::StatementResult::JustValue(types::Value(TRY((types::ValueImpl::template create<typename types::ValueImpl::Bool>(false))),span)) } );
}
__jakt_var_286 =  interpreter::StatementResult { typename interpreter::StatementResult::JustValue(types::Value(TRY((types::ValueImpl::template create<typename types::ValueImpl::Bool>(true))),span)) } ; goto __jakt_label_283;

}
__jakt_label_283:; __jakt_var_286.release_value(); }));
};/*case end*/
default: {
{
TRY((((*this).error(TRY((__jakt_format(Jakt::DeprecatedString("Invalid value for unary operator '{}'"sv),op))),span))));
return Error::from_errno((infallible_integer_cast<i32>((interpreter::InterpretError::InvalidType))));
}
};/*case end*/
}/*switch end*/
}()
)));
};/*case end*/
default: {
{
TRY((((*this).error(TRY((__jakt_format(Jakt::DeprecatedString("Unimplemented unary operator '{}'"sv),op))),span))));
return Error::from_errno((infallible_integer_cast<i32>((interpreter::InterpretError::Unimplemented))));
}
};/*case end*/
}/*switch end*/
}()
)); goto __jakt_label_237;

}
__jakt_label_237:; __jakt_var_240.release_value(); }));
};/*case end*/
case 8: {
auto&& __jakt_match_value = __jakt_match_variant.template get<types::CheckedExpression::Range>();JaktInternal::Optional<NonnullRefPtr<typename types::CheckedExpression>> const& from = __jakt_match_value.from;
JaktInternal::Optional<NonnullRefPtr<typename types::CheckedExpression>> const& to = __jakt_match_value.to;
utility::Span const& span = __jakt_match_value.span;
return JaktInternal::ExplicitValue(({ Optional<interpreter::StatementResult> __jakt_var_287; {
types::Value const start = JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<types::Value,ErrorOr<interpreter::StatementResult>>{
auto __jakt_enum_value = (((from).has_value()));
if (__jakt_enum_value == true) {
return JaktInternal::ExplicitValue(JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<types::Value, ErrorOr<interpreter::StatementResult>>{
auto&& __jakt_match_variant = TRY((((*this).execute_expression((from.value()),scope))));
switch(__jakt_match_variant.index()) {
case 0: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename interpreter::StatementResult::Return>();
types::Value const& value = __jakt_match_value.value;
{
return ( interpreter::StatementResult { typename interpreter::StatementResult::Return(value) } );
}
};/*case end*/
case 1: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename interpreter::StatementResult::Throw>();
types::Value const& value = __jakt_match_value.value;
{
return ( interpreter::StatementResult { typename interpreter::StatementResult::Throw(value) } );
}
};/*case end*/
case 5: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename interpreter::StatementResult::JustValue>();
types::Value const& value = __jakt_match_value.value;
return JaktInternal::ExplicitValue(value);
};/*case end*/
case 3: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename interpreter::StatementResult::Continue>();
{
return ( interpreter::StatementResult { typename interpreter::StatementResult::Continue() } );
}
};/*case end*/
case 4: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename interpreter::StatementResult::Break>();
{
return ( interpreter::StatementResult { typename interpreter::StatementResult::Break() } );
}
};/*case end*/
case 2: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename interpreter::StatementResult::Yield>();
types::Value const& expr = __jakt_match_value.value;
{
utility::panic(Jakt::DeprecatedString("Invalid control flow"sv));
}
};/*case end*/
default: VERIFY_NOT_REACHED();}/*switch end*/
}()
)));
}
else {
{
TRY((((*this).error(Jakt::DeprecatedString("Partial ranges are not implemented"sv),span))));
return Error::from_errno((infallible_integer_cast<i32>((interpreter::InterpretError::Unimplemented))));
}
}
}()))
;
types::Value const end = JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<types::Value,ErrorOr<interpreter::StatementResult>>{
auto __jakt_enum_value = (((to).has_value()));
if (__jakt_enum_value == true) {
return JaktInternal::ExplicitValue(JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<types::Value, ErrorOr<interpreter::StatementResult>>{
auto&& __jakt_match_variant = TRY((((*this).execute_expression((to.value()),scope))));
switch(__jakt_match_variant.index()) {
case 0: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename interpreter::StatementResult::Return>();
types::Value const& value = __jakt_match_value.value;
{
return ( interpreter::StatementResult { typename interpreter::StatementResult::Return(value) } );
}
};/*case end*/
case 1: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename interpreter::StatementResult::Throw>();
types::Value const& value = __jakt_match_value.value;
{
return ( interpreter::StatementResult { typename interpreter::StatementResult::Throw(value) } );
}
};/*case end*/
case 5: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename interpreter::StatementResult::JustValue>();
types::Value const& value = __jakt_match_value.value;
return JaktInternal::ExplicitValue(value);
};/*case end*/
case 3: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename interpreter::StatementResult::Continue>();
{
return ( interpreter::StatementResult { typename interpreter::StatementResult::Continue() } );
}
};/*case end*/
case 4: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename interpreter::StatementResult::Break>();
{
return ( interpreter::StatementResult { typename interpreter::StatementResult::Break() } );
}
};/*case end*/
case 2: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename interpreter::StatementResult::Yield>();
types::Value const& expr = __jakt_match_value.value;
{
utility::panic(Jakt::DeprecatedString("Invalid control flow"sv));
}
};/*case end*/
default: VERIFY_NOT_REACHED();}/*switch end*/
}()
)));
}
else {
{
TRY((((*this).error(Jakt::DeprecatedString("Partial ranges are not implemented"sv),span))));
return Error::from_errno((infallible_integer_cast<i32>((interpreter::InterpretError::Unimplemented))));
}
}
}()))
;
types::StructId const range_struct_id = TRY((((((*this).program))->find_struct_in_prelude(Jakt::DeprecatedString("Range"sv)))));
JaktInternal::DynamicArray<types::FunctionId> const range_constructors = (TRY((((((*this).program))->find_functions_with_name_in_scope(((((((*this).program))->get_struct(range_struct_id))).scope_id),Jakt::DeprecatedString("Range"sv))))).value());
__jakt_var_287 =  interpreter::StatementResult { typename interpreter::StatementResult::JustValue(types::Value(TRY((types::ValueImpl::template create<typename types::ValueImpl::Struct>((TRY((DynamicArray<types::Value>::create_with({start, end})))),range_struct_id,((range_constructors)[static_cast<i64>(0LL)])))),span)) } ; goto __jakt_label_284;

}
__jakt_label_284:; __jakt_var_287.release_value(); }));
};/*case end*/
case 19: {
auto&& __jakt_match_value = __jakt_match_variant.template get<types::CheckedExpression::Call>();types::CheckedCall const& call = __jakt_match_value.call;
utility::Span const& span = __jakt_match_value.span;
return JaktInternal::ExplicitValue(({ Optional<interpreter::StatementResult> __jakt_var_288; {
if ((!(((((call).function_id)).has_value())))){
JaktInternal::DynamicArray<types::Value> arguments = (TRY((DynamicArray<types::Value>::create_with({}))));
{
JaktInternal::ArrayIterator<JaktInternal::Tuple<DeprecatedString,NonnullRefPtr<typename types::CheckedExpression>>> _magic = ((((call).args)).iterator());
for (;;){
JaktInternal::Optional<JaktInternal::Tuple<DeprecatedString,NonnullRefPtr<typename types::CheckedExpression>>> _magic_value = ((_magic).next());
if ((!(((_magic_value).has_value())))){
break;
}
JaktInternal::Tuple<DeprecatedString,NonnullRefPtr<typename types::CheckedExpression>> arg = (_magic_value.value());
{
TRY((((arguments).push(JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_AT_LOOP(([&]() -> JaktInternal::ExplicitValueOrControlFlow<types::Value, ErrorOr<interpreter::StatementResult>>{
auto&& __jakt_match_variant = TRY((((*this).execute_expression(((arg).template get<1>()),scope))));
switch(__jakt_match_variant.index()) {
case 0: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename interpreter::StatementResult::Return>();
types::Value const& value = __jakt_match_value.value;
{
return ( interpreter::StatementResult { typename interpreter::StatementResult::Return(value) } );
}
};/*case end*/
case 1: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename interpreter::StatementResult::Throw>();
types::Value const& value = __jakt_match_value.value;
{
return ( interpreter::StatementResult { typename interpreter::StatementResult::Throw(value) } );
}
};/*case end*/
case 5: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename interpreter::StatementResult::JustValue>();
types::Value const& value = __jakt_match_value.value;
return JaktInternal::ExplicitValue(value);
};/*case end*/
case 3: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename interpreter::StatementResult::Continue>();
{
return ( interpreter::StatementResult { typename interpreter::StatementResult::Continue() } );
}
};/*case end*/
case 4: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename interpreter::StatementResult::Break>();
{
return ( interpreter::StatementResult { typename interpreter::StatementResult::Break() } );
}
};/*case end*/
case 2: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename interpreter::StatementResult::Yield>();
types::Value const& expr = __jakt_match_value.value;
{
utility::panic(Jakt::DeprecatedString("Invalid control flow"sv));
}
};/*case end*/
default: VERIFY_NOT_REACHED();}/*switch end*/
}()
))))));
}

}
}

return (TRY((((*this).call_prelude_function(((call).name),(TRY((DynamicArray<types::ResolvedNamespace>::create_with({})))),JaktInternal::OptionalNone(),arguments,span,(TRY((Dictionary<DeprecatedString, types::TypeId>::create_with_entries({})))))))));
}
NonnullRefPtr<types::CheckedFunction> const function_to_run = ((((*this).program))->get_function((((call).function_id).value())));
if (((((function_to_run)->type)).index() == 5 /* Closure */)){
TRY((((*this).error(TRY((__jakt_format(Jakt::DeprecatedString("Cannot call a closure (nyi)"sv)))),span))));
return Error::from_errno((infallible_integer_cast<i32>((interpreter::InterpretError::Unimplemented))));
}
JaktInternal::Optional<types::Value> this_argument = JaktInternal::OptionalNone();
JaktInternal::DynamicArray<types::Value> arguments = (TRY((DynamicArray<types::Value>::create_with({}))));
{
JaktInternal::ArrayIterator<JaktInternal::Tuple<DeprecatedString,NonnullRefPtr<typename types::CheckedExpression>>> _magic = ((((call).args)).iterator());
for (;;){
JaktInternal::Optional<JaktInternal::Tuple<DeprecatedString,NonnullRefPtr<typename types::CheckedExpression>>> _magic_value = ((_magic).next());
if ((!(((_magic_value).has_value())))){
break;
}
JaktInternal::Tuple<DeprecatedString,NonnullRefPtr<typename types::CheckedExpression>> arg = (_magic_value.value());
{
TRY((((arguments).push(JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_AT_LOOP(([&]() -> JaktInternal::ExplicitValueOrControlFlow<types::Value, ErrorOr<interpreter::StatementResult>>{
auto&& __jakt_match_variant = TRY((((*this).execute_expression(((arg).template get<1>()),scope))));
switch(__jakt_match_variant.index()) {
case 0: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename interpreter::StatementResult::Return>();
types::Value const& value = __jakt_match_value.value;
{
return ( interpreter::StatementResult { typename interpreter::StatementResult::Return(value) } );
}
};/*case end*/
case 1: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename interpreter::StatementResult::Throw>();
types::Value const& value = __jakt_match_value.value;
{
return ( interpreter::StatementResult { typename interpreter::StatementResult::Throw(value) } );
}
};/*case end*/
case 5: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename interpreter::StatementResult::JustValue>();
types::Value const& value = __jakt_match_value.value;
return JaktInternal::ExplicitValue(value);
};/*case end*/
case 3: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename interpreter::StatementResult::Continue>();
{
return ( interpreter::StatementResult { typename interpreter::StatementResult::Continue() } );
}
};/*case end*/
case 4: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename interpreter::StatementResult::Break>();
{
return ( interpreter::StatementResult { typename interpreter::StatementResult::Break() } );
}
};/*case end*/
case 2: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename interpreter::StatementResult::Yield>();
types::Value const& expr = __jakt_match_value.value;
{
utility::panic(Jakt::DeprecatedString("Invalid control flow"sv));
}
};/*case end*/
default: VERIFY_NOT_REACHED();}/*switch end*/
}()
))))));
}

}
}

JaktInternal::Dictionary<DeprecatedString,types::TypeId> type_bindings = (TRY((Dictionary<DeprecatedString, types::TypeId>::create_with_entries({}))));
{
JaktInternal::Range<size_t> _magic = (JaktInternal::Range<size_t>{static_cast<size_t>(static_cast<size_t>(0ULL)),static_cast<size_t>(((((((function_to_run)->generics))->params)).size()))});
for (;;){
JaktInternal::Optional<size_t> _magic_value = ((_magic).next());
if ((!(((_magic_value).has_value())))){
break;
}
size_t i = (_magic_value.value());
{
types::FunctionGenericParameter const param = ((((((function_to_run)->generics))->params))[i]);
TRY((((type_bindings).set(TRY((((((param).type_id())).to_string()))),((((call).type_args))[i])))));
}

}
}

JaktInternal::Dictionary<DeprecatedString,types::Value> const empty_bindings = (TRY((Dictionary<DeprecatedString, types::Value>::create_with_entries({}))));
__jakt_var_288 = JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<interpreter::StatementResult, ErrorOr<interpreter::StatementResult>>{
auto&& __jakt_match_variant = TRY((((*this).execute((((call).function_id).value()),static_cast<JaktInternal::Optional<JaktInternal::DynamicArray<types::ResolvedNamespace>>>(((call).namespace_)),this_argument,arguments,span,TRY((interpreter::InterpreterScope::create((TRY((Dictionary<DeprecatedString, types::Value>::create_with_entries({})))),JaktInternal::OptionalNone(),type_bindings)))))));
switch(__jakt_match_variant.index()) {
case 0: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename interpreter::ExecutionResult::Return>();
types::Value const& value = __jakt_match_value.value;
return JaktInternal::ExplicitValue( interpreter::StatementResult { typename interpreter::StatementResult::JustValue(value) } );
};/*case end*/
case 1: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename interpreter::ExecutionResult::Throw>();
types::Value const& value = __jakt_match_value.value;
return JaktInternal::ExplicitValue( interpreter::StatementResult { typename interpreter::StatementResult::Throw(value) } );
};/*case end*/
default: VERIFY_NOT_REACHED();}/*switch end*/
}()
)); goto __jakt_label_285;

}
__jakt_label_285:; __jakt_var_288.release_value(); }));
};/*case end*/
case 20: {
auto&& __jakt_match_value = __jakt_match_variant.template get<types::CheckedExpression::MethodCall>();NonnullRefPtr<typename types::CheckedExpression> const& expr = __jakt_match_value.expr;
types::CheckedCall const& call = __jakt_match_value.call;
utility::Span const& span = __jakt_match_value.span;
return JaktInternal::ExplicitValue(({ Optional<interpreter::StatementResult> __jakt_var_289; {
types::Value const this_argument = JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<types::Value, ErrorOr<interpreter::StatementResult>>{
auto&& __jakt_match_variant = TRY((((*this).execute_expression(expr,scope))));
switch(__jakt_match_variant.index()) {
case 0: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename interpreter::StatementResult::Return>();
types::Value const& value = __jakt_match_value.value;
{
return ( interpreter::StatementResult { typename interpreter::StatementResult::Return(value) } );
}
};/*case end*/
case 1: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename interpreter::StatementResult::Throw>();
types::Value const& value = __jakt_match_value.value;
{
return ( interpreter::StatementResult { typename interpreter::StatementResult::Throw(value) } );
}
};/*case end*/
case 5: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename interpreter::StatementResult::JustValue>();
types::Value const& value = __jakt_match_value.value;
return JaktInternal::ExplicitValue(value);
};/*case end*/
case 3: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename interpreter::StatementResult::Continue>();
{
return ( interpreter::StatementResult { typename interpreter::StatementResult::Continue() } );
}
};/*case end*/
case 4: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename interpreter::StatementResult::Break>();
{
return ( interpreter::StatementResult { typename interpreter::StatementResult::Break() } );
}
};/*case end*/
case 2: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename interpreter::StatementResult::Yield>();
types::Value const& expr = __jakt_match_value.value;
{
utility::panic(Jakt::DeprecatedString("Invalid control flow"sv));
}
};/*case end*/
default: VERIFY_NOT_REACHED();}/*switch end*/
}()
));
JaktInternal::DynamicArray<types::ResolvedNamespace> effective_namespace = (TRY((DynamicArray<types::ResolvedNamespace>::create_with({}))));
JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<void, ErrorOr<interpreter::StatementResult>>{
auto&& __jakt_match_variant = *((this_argument).impl);
switch(__jakt_match_variant.index()) {
case 13: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::JaktString>();
{
JaktInternal::DynamicArray<types::TypeId> const generic_parameters = (TRY((DynamicArray<types::TypeId>::create_with({}))));
TRY((((effective_namespace).push(types::ResolvedNamespace(Jakt::DeprecatedString("String"sv),JaktInternal::OptionalNone(),generic_parameters)))));
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 20: {
auto&& __jakt_match_value = __jakt_match_variant.template get<types::ValueImpl::JaktArray>();types::TypeId const& type_id = __jakt_match_value.type_id;
{
JaktInternal::DynamicArray<types::TypeId> const generic_parameters = JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<JaktInternal::DynamicArray<types::TypeId>, ErrorOr<interpreter::StatementResult>>{
auto&& __jakt_match_variant = *((((*this).program))->get_type(type_id));
switch(__jakt_match_variant.index()) {
case 19: {
auto&& __jakt_match_value = __jakt_match_variant.template get<types::Type::GenericInstance>();JaktInternal::DynamicArray<types::TypeId> const& args = __jakt_match_value.args;
return JaktInternal::ExplicitValue(args);
};/*case end*/
default: {
{
TRY((((*this).error(Jakt::DeprecatedString("Attempted to call a prelude function on a non-generic array"sv),((this_argument).span)))));
return Error::from_errno((infallible_integer_cast<i32>((interpreter::InterpretError::InvalidType))));
}
};/*case end*/
}/*switch end*/
}()
));
TRY((((effective_namespace).push(types::ResolvedNamespace(Jakt::DeprecatedString("Array"sv),JaktInternal::OptionalNone(),generic_parameters)))));
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 21: {
auto&& __jakt_match_value = __jakt_match_variant.template get<types::ValueImpl::JaktDictionary>();types::TypeId const& type_id = __jakt_match_value.type_id;
{
JaktInternal::DynamicArray<types::TypeId> const generic_parameters = JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<JaktInternal::DynamicArray<types::TypeId>, ErrorOr<interpreter::StatementResult>>{
auto&& __jakt_match_variant = *((((*this).program))->get_type(type_id));
switch(__jakt_match_variant.index()) {
case 19: {
auto&& __jakt_match_value = __jakt_match_variant.template get<types::Type::GenericInstance>();JaktInternal::DynamicArray<types::TypeId> const& args = __jakt_match_value.args;
return JaktInternal::ExplicitValue(args);
};/*case end*/
default: {
{
TRY((((*this).error(Jakt::DeprecatedString("Attempted to call a prelude function on a non-generic dictionary"sv),((this_argument).span)))));
return Error::from_errno((infallible_integer_cast<i32>((interpreter::InterpretError::InvalidType))));
}
};/*case end*/
}/*switch end*/
}()
));
TRY((((effective_namespace).push(types::ResolvedNamespace(Jakt::DeprecatedString("Dictionary"sv),JaktInternal::OptionalNone(),generic_parameters)))));
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 22: {
auto&& __jakt_match_value = __jakt_match_variant.template get<types::ValueImpl::JaktSet>();types::TypeId const& type_id = __jakt_match_value.type_id;
{
if (((((((*this).program))->get_type(type_id)))->index() == 19 /* GenericInstance */)){
JaktInternal::DynamicArray<types::TypeId> const generic_parameters = ((((((*this).program))->get_type(type_id)))->get<types::Type::GenericInstance>()).args;
TRY((((effective_namespace).push(types::ResolvedNamespace(Jakt::DeprecatedString("Set"sv),JaktInternal::OptionalNone(),generic_parameters)))));
}
else {
TRY((((*this).error(Jakt::DeprecatedString("Attempted to call a prelude function on a non-generic set"sv),((this_argument).span)))));
return Error::from_errno((infallible_integer_cast<i32>((interpreter::InterpretError::InvalidType))));
}

}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 17: {
auto&& __jakt_match_value = __jakt_match_variant.template get<types::ValueImpl::Struct>();types::StructId const& struct_id = __jakt_match_value.struct_id;
{
JaktInternal::DynamicArray<types::TypeId> const generic_parameters = (TRY((DynamicArray<types::TypeId>::create_with({}))));
TRY((((effective_namespace).push(types::ResolvedNamespace(((((((*this).program))->get_struct(struct_id))).name),JaktInternal::OptionalNone(),generic_parameters)))));
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 18: {
auto&& __jakt_match_value = __jakt_match_variant.template get<types::ValueImpl::Class>();types::StructId const& struct_id = __jakt_match_value.struct_id;
{
JaktInternal::DynamicArray<types::TypeId> const generic_parameters = (TRY((DynamicArray<types::TypeId>::create_with({}))));
TRY((((effective_namespace).push(types::ResolvedNamespace(((((((*this).program))->get_struct(struct_id))).name),JaktInternal::OptionalNone(),generic_parameters)))));
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 19: {
auto&& __jakt_match_value = __jakt_match_variant.template get<types::ValueImpl::Enum>();types::EnumId const& enum_id = __jakt_match_value.enum_id;
{
JaktInternal::DynamicArray<types::TypeId> const generic_parameters = (TRY((DynamicArray<types::TypeId>::create_with({}))));
TRY((((effective_namespace).push(types::ResolvedNamespace(((((((*this).program))->get_enum(enum_id))).name),JaktInternal::OptionalNone(),generic_parameters)))));
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 25: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::OptionalNone>();
{
JaktInternal::DynamicArray<types::TypeId> const generic_parameters = (TRY((DynamicArray<types::TypeId>::create_with({}))));
TRY((((effective_namespace).push(types::ResolvedNamespace(Jakt::DeprecatedString("Optional"sv),JaktInternal::OptionalNone(),generic_parameters)))));
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 24: {
auto&& __jakt_match_value = __jakt_match_variant.template get<types::ValueImpl::OptionalSome>();{
JaktInternal::DynamicArray<types::TypeId> const generic_parameters = (TRY((DynamicArray<types::TypeId>::create_with({}))));
TRY((((effective_namespace).push(types::ResolvedNamespace(Jakt::DeprecatedString("Optional"sv),JaktInternal::OptionalNone(),generic_parameters)))));
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
default: {
{
TRY((((*this).error(Jakt::DeprecatedString("Attempted to call an instance method on a non-struct/enum type"sv),((this_argument).span)))));
return Error::from_errno((infallible_integer_cast<i32>((interpreter::InterpretError::InvalidType))));
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
}/*switch end*/
}()
));
if ((!(((((call).function_id)).has_value())))){
JaktInternal::DynamicArray<types::Value> arguments = (TRY((DynamicArray<types::Value>::create_with({}))));
{
JaktInternal::ArrayIterator<JaktInternal::Tuple<DeprecatedString,NonnullRefPtr<typename types::CheckedExpression>>> _magic = ((((call).args)).iterator());
for (;;){
JaktInternal::Optional<JaktInternal::Tuple<DeprecatedString,NonnullRefPtr<typename types::CheckedExpression>>> _magic_value = ((_magic).next());
if ((!(((_magic_value).has_value())))){
break;
}
JaktInternal::Tuple<DeprecatedString,NonnullRefPtr<typename types::CheckedExpression>> arg = (_magic_value.value());
{
TRY((((arguments).push(JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_AT_LOOP(([&]() -> JaktInternal::ExplicitValueOrControlFlow<types::Value, ErrorOr<interpreter::StatementResult>>{
auto&& __jakt_match_variant = TRY((((*this).execute_expression(((arg).template get<1>()),scope))));
switch(__jakt_match_variant.index()) {
case 0: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename interpreter::StatementResult::Return>();
types::Value const& value = __jakt_match_value.value;
{
return ( interpreter::StatementResult { typename interpreter::StatementResult::Return(value) } );
}
};/*case end*/
case 1: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename interpreter::StatementResult::Throw>();
types::Value const& value = __jakt_match_value.value;
{
return ( interpreter::StatementResult { typename interpreter::StatementResult::Throw(value) } );
}
};/*case end*/
case 5: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename interpreter::StatementResult::JustValue>();
types::Value const& value = __jakt_match_value.value;
return JaktInternal::ExplicitValue(value);
};/*case end*/
case 3: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename interpreter::StatementResult::Continue>();
{
return ( interpreter::StatementResult { typename interpreter::StatementResult::Continue() } );
}
};/*case end*/
case 4: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename interpreter::StatementResult::Break>();
{
return ( interpreter::StatementResult { typename interpreter::StatementResult::Break() } );
}
};/*case end*/
case 2: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename interpreter::StatementResult::Yield>();
types::Value const& expr = __jakt_match_value.value;
{
utility::panic(Jakt::DeprecatedString("Invalid control flow"sv));
}
};/*case end*/
default: VERIFY_NOT_REACHED();}/*switch end*/
}()
))))));
}

}
}

return (TRY((((*this).call_prelude_function(((call).name),effective_namespace,this_argument,arguments,span,(TRY((Dictionary<DeprecatedString, types::TypeId>::create_with_entries({})))))))));
}
NonnullRefPtr<types::CheckedFunction> const function_to_run = ((((*this).program))->get_function((((call).function_id).value())));
JaktInternal::DynamicArray<types::Value> arguments = (TRY((DynamicArray<types::Value>::create_with({}))));
{
JaktInternal::ArrayIterator<JaktInternal::Tuple<DeprecatedString,NonnullRefPtr<typename types::CheckedExpression>>> _magic = ((((call).args)).iterator());
for (;;){
JaktInternal::Optional<JaktInternal::Tuple<DeprecatedString,NonnullRefPtr<typename types::CheckedExpression>>> _magic_value = ((_magic).next());
if ((!(((_magic_value).has_value())))){
break;
}
JaktInternal::Tuple<DeprecatedString,NonnullRefPtr<typename types::CheckedExpression>> arg = (_magic_value.value());
{
TRY((((arguments).push(JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_AT_LOOP(([&]() -> JaktInternal::ExplicitValueOrControlFlow<types::Value, ErrorOr<interpreter::StatementResult>>{
auto&& __jakt_match_variant = TRY((((*this).execute_expression(((arg).template get<1>()),scope))));
switch(__jakt_match_variant.index()) {
case 0: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename interpreter::StatementResult::Return>();
types::Value const& value = __jakt_match_value.value;
{
return ( interpreter::StatementResult { typename interpreter::StatementResult::Return(value) } );
}
};/*case end*/
case 1: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename interpreter::StatementResult::Throw>();
types::Value const& value = __jakt_match_value.value;
{
return ( interpreter::StatementResult { typename interpreter::StatementResult::Throw(value) } );
}
};/*case end*/
case 5: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename interpreter::StatementResult::JustValue>();
types::Value const& value = __jakt_match_value.value;
return JaktInternal::ExplicitValue(value);
};/*case end*/
case 3: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename interpreter::StatementResult::Continue>();
{
return ( interpreter::StatementResult { typename interpreter::StatementResult::Continue() } );
}
};/*case end*/
case 4: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename interpreter::StatementResult::Break>();
{
return ( interpreter::StatementResult { typename interpreter::StatementResult::Break() } );
}
};/*case end*/
case 2: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename interpreter::StatementResult::Yield>();
types::Value const& expr = __jakt_match_value.value;
{
utility::panic(Jakt::DeprecatedString("Invalid control flow"sv));
}
};/*case end*/
default: VERIFY_NOT_REACHED();}/*switch end*/
}()
))))));
}

}
}

__jakt_var_289 = JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<interpreter::StatementResult, ErrorOr<interpreter::StatementResult>>{
auto&& __jakt_match_variant = TRY((((*this).execute((((call).function_id).value()),static_cast<JaktInternal::Optional<JaktInternal::DynamicArray<types::ResolvedNamespace>>>(((call).namespace_)),this_argument,arguments,span,JaktInternal::OptionalNone()))));
switch(__jakt_match_variant.index()) {
case 0: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename interpreter::ExecutionResult::Return>();
types::Value const& value = __jakt_match_value.value;
return JaktInternal::ExplicitValue( interpreter::StatementResult { typename interpreter::StatementResult::JustValue(value) } );
};/*case end*/
case 1: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename interpreter::ExecutionResult::Throw>();
types::Value const& value = __jakt_match_value.value;
return JaktInternal::ExplicitValue( interpreter::StatementResult { typename interpreter::StatementResult::Throw(value) } );
};/*case end*/
default: VERIFY_NOT_REACHED();}/*switch end*/
}()
)); goto __jakt_label_286;

}
__jakt_label_286:; __jakt_var_289.release_value(); }));
};/*case end*/
case 23: {
auto&& __jakt_match_value = __jakt_match_variant.template get<types::CheckedExpression::OptionalNone>();utility::Span const& span = __jakt_match_value.span;
return JaktInternal::ExplicitValue( interpreter::StatementResult { typename interpreter::StatementResult::JustValue(types::Value(TRY((types::ValueImpl::template create<typename types::ValueImpl::OptionalNone>())),span)) } );
};/*case end*/
case 24: {
auto&& __jakt_match_value = __jakt_match_variant.template get<types::CheckedExpression::OptionalSome>();NonnullRefPtr<typename types::CheckedExpression> const& expr = __jakt_match_value.expr;
utility::Span const& span = __jakt_match_value.span;
{
interpreter::StatementResult const result = TRY((((*this).execute_expression(expr,scope))));
if (((result).index() == 5 /* JustValue */)){
types::Value const value = ((result).get<interpreter::StatementResult::JustValue>()).value;
return ( interpreter::StatementResult { typename interpreter::StatementResult::JustValue(types::Value(TRY((types::ValueImpl::template create<typename types::ValueImpl::OptionalSome>(value))),span)) } );
}
return (result);
}
};/*case end*/
case 25: {
auto&& __jakt_match_value = __jakt_match_variant.template get<types::CheckedExpression::ForcedUnwrap>();NonnullRefPtr<typename types::CheckedExpression> const& expr = __jakt_match_value.expr;
return JaktInternal::ExplicitValue(({ Optional<interpreter::StatementResult> __jakt_var_290; {
types::Value const value = JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<types::Value, ErrorOr<interpreter::StatementResult>>{
auto&& __jakt_match_variant = TRY((((*this).execute_expression(expr,scope))));
switch(__jakt_match_variant.index()) {
case 0: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename interpreter::StatementResult::Return>();
types::Value const& value = __jakt_match_value.value;
{
return ( interpreter::StatementResult { typename interpreter::StatementResult::Return(value) } );
}
};/*case end*/
case 1: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename interpreter::StatementResult::Throw>();
types::Value const& value = __jakt_match_value.value;
{
return ( interpreter::StatementResult { typename interpreter::StatementResult::Throw(value) } );
}
};/*case end*/
case 5: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename interpreter::StatementResult::JustValue>();
types::Value const& value = __jakt_match_value.value;
return JaktInternal::ExplicitValue(value);
};/*case end*/
case 3: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename interpreter::StatementResult::Continue>();
{
return ( interpreter::StatementResult { typename interpreter::StatementResult::Continue() } );
}
};/*case end*/
case 4: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename interpreter::StatementResult::Break>();
{
return ( interpreter::StatementResult { typename interpreter::StatementResult::Break() } );
}
};/*case end*/
case 2: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename interpreter::StatementResult::Yield>();
types::Value const& expr = __jakt_match_value.value;
{
utility::panic(Jakt::DeprecatedString("Invalid control flow"sv));
}
};/*case end*/
default: VERIFY_NOT_REACHED();}/*switch end*/
}()
));
if (((((value).impl))->index() == 25 /* OptionalNone */)){
TRY((((*this).error(Jakt::DeprecatedString("Attempted to unwrap an optional value that was None"sv),((value).span)))));
return Error::from_errno((infallible_integer_cast<i32>((interpreter::InterpretError::InvalidType))));
}
__jakt_var_290 = JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<interpreter::StatementResult, ErrorOr<interpreter::StatementResult>>{
auto&& __jakt_match_variant = *((value).impl);
switch(__jakt_match_variant.index()) {
case 24: {
auto&& __jakt_match_value = __jakt_match_variant.template get<types::ValueImpl::OptionalSome>();types::Value const& value = __jakt_match_value.value;
return JaktInternal::ExplicitValue( interpreter::StatementResult { typename interpreter::StatementResult::JustValue(value) } );
};/*case end*/
default: {
{
TRY((((*this).error(Jakt::DeprecatedString("Invalid type for unwrap"sv),((value).span)))));
return Error::from_errno((infallible_integer_cast<i32>((interpreter::InterpretError::InvalidType))));
}
};/*case end*/
}/*switch end*/
}()
)); goto __jakt_label_287;

}
__jakt_label_287:; __jakt_var_290.release_value(); }));
};/*case end*/
case 26: {
auto&& __jakt_match_value = __jakt_match_variant.template get<types::CheckedExpression::Block>();types::CheckedBlock const& block = __jakt_match_value.block;
utility::Span const& span = __jakt_match_value.span;
return JaktInternal::ExplicitValue(TRY((((*this).execute_block(block,scope,span)))));
};/*case end*/
case 3: {
auto&& __jakt_match_value = __jakt_match_variant.template get<types::CheckedExpression::ByteConstant>();DeprecatedString const& val = __jakt_match_value.val;
utility::Span const& span = __jakt_match_value.span;
return JaktInternal::ExplicitValue( interpreter::StatementResult { typename interpreter::StatementResult::JustValue(types::Value(TRY((types::ValueImpl::template create<typename types::ValueImpl::U8>(((val).byte_at(static_cast<size_t>(0ULL)))))),span)) } );
};/*case end*/
case 22: {
auto&& __jakt_match_value = __jakt_match_variant.template get<types::CheckedExpression::Var>();NonnullRefPtr<types::CheckedVariable> const& var = __jakt_match_value.var;
return JaktInternal::ExplicitValue( interpreter::StatementResult { typename interpreter::StatementResult::JustValue(TRY((((scope)->must_get(((var)->name)))))) } );
};/*case end*/
case 12: {
auto&& __jakt_match_value = __jakt_match_variant.template get<types::CheckedExpression::IndexedExpression>();NonnullRefPtr<typename types::CheckedExpression> const& expr = __jakt_match_value.expr;
NonnullRefPtr<typename types::CheckedExpression> const& index_expr = __jakt_match_value.index;
utility::Span const& span = __jakt_match_value.span;
return JaktInternal::ExplicitValue(({ Optional<interpreter::StatementResult> __jakt_var_291; {
types::Value const value = JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<types::Value, ErrorOr<interpreter::StatementResult>>{
auto&& __jakt_match_variant = TRY((((*this).execute_expression(expr,scope))));
switch(__jakt_match_variant.index()) {
case 0: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename interpreter::StatementResult::Return>();
types::Value const& value = __jakt_match_value.value;
{
return ( interpreter::StatementResult { typename interpreter::StatementResult::Return(value) } );
}
};/*case end*/
case 1: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename interpreter::StatementResult::Throw>();
types::Value const& value = __jakt_match_value.value;
{
return ( interpreter::StatementResult { typename interpreter::StatementResult::Throw(value) } );
}
};/*case end*/
case 5: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename interpreter::StatementResult::JustValue>();
types::Value const& value = __jakt_match_value.value;
return JaktInternal::ExplicitValue(value);
};/*case end*/
case 3: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename interpreter::StatementResult::Continue>();
{
return ( interpreter::StatementResult { typename interpreter::StatementResult::Continue() } );
}
};/*case end*/
case 4: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename interpreter::StatementResult::Break>();
{
return ( interpreter::StatementResult { typename interpreter::StatementResult::Break() } );
}
};/*case end*/
case 2: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename interpreter::StatementResult::Yield>();
types::Value const& expr = __jakt_match_value.value;
{
utility::panic(Jakt::DeprecatedString("Invalid control flow"sv));
}
};/*case end*/
default: VERIFY_NOT_REACHED();}/*switch end*/
}()
));
types::Value const index = JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<types::Value, ErrorOr<interpreter::StatementResult>>{
auto&& __jakt_match_variant = TRY((((*this).execute_expression(index_expr,scope))));
switch(__jakt_match_variant.index()) {
case 0: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename interpreter::StatementResult::Return>();
types::Value const& value = __jakt_match_value.value;
{
return ( interpreter::StatementResult { typename interpreter::StatementResult::Return(value) } );
}
};/*case end*/
case 1: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename interpreter::StatementResult::Throw>();
types::Value const& value = __jakt_match_value.value;
{
return ( interpreter::StatementResult { typename interpreter::StatementResult::Throw(value) } );
}
};/*case end*/
case 5: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename interpreter::StatementResult::JustValue>();
types::Value const& value = __jakt_match_value.value;
return JaktInternal::ExplicitValue(value);
};/*case end*/
case 3: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename interpreter::StatementResult::Continue>();
{
return ( interpreter::StatementResult { typename interpreter::StatementResult::Continue() } );
}
};/*case end*/
case 4: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename interpreter::StatementResult::Break>();
{
return ( interpreter::StatementResult { typename interpreter::StatementResult::Break() } );
}
};/*case end*/
case 2: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename interpreter::StatementResult::Yield>();
types::Value const& expr = __jakt_match_value.value;
{
utility::panic(Jakt::DeprecatedString("Invalid control flow"sv));
}
};/*case end*/
default: VERIFY_NOT_REACHED();}/*switch end*/
}()
));
__jakt_var_291 = JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<interpreter::StatementResult, ErrorOr<interpreter::StatementResult>>{
auto&& __jakt_match_variant = *((value).impl);
switch(__jakt_match_variant.index()) {
case 20: {
auto&& __jakt_match_value = __jakt_match_variant.template get<types::ValueImpl::JaktArray>();JaktInternal::DynamicArray<types::Value> const& values = __jakt_match_value.values;
return JaktInternal::ExplicitValue(({ Optional<interpreter::StatementResult> __jakt_var_292; {
u64 const numeric_index = JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<u64, ErrorOr<interpreter::StatementResult>>{
auto&& __jakt_match_variant = *((index).impl);
switch(__jakt_match_variant.index()) {
case 6: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::I8>();
i8 const& x = __jakt_match_value.value;
return JaktInternal::ExplicitValue((infallible_integer_cast<u64>((x))));
};/*case end*/
case 7: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::I16>();
i16 const& x = __jakt_match_value.value;
return JaktInternal::ExplicitValue((infallible_integer_cast<u64>((x))));
};/*case end*/
case 8: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::I32>();
i32 const& x = __jakt_match_value.value;
return JaktInternal::ExplicitValue((infallible_integer_cast<u64>((x))));
};/*case end*/
case 9: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::I64>();
i64 const& x = __jakt_match_value.value;
return JaktInternal::ExplicitValue((infallible_integer_cast<u64>((x))));
};/*case end*/
case 2: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::U8>();
u8 const& x = __jakt_match_value.value;
return JaktInternal::ExplicitValue((infallible_integer_cast<u64>((x))));
};/*case end*/
case 3: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::U16>();
u16 const& x = __jakt_match_value.value;
return JaktInternal::ExplicitValue((infallible_integer_cast<u64>((x))));
};/*case end*/
case 4: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::U32>();
u32 const& x = __jakt_match_value.value;
return JaktInternal::ExplicitValue((infallible_integer_cast<u64>((x))));
};/*case end*/
case 5: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::U64>();
u64 const& x = __jakt_match_value.value;
return JaktInternal::ExplicitValue((infallible_integer_cast<u64>((x))));
};/*case end*/
case 12: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::USize>();
size_t const& x = __jakt_match_value.value;
return JaktInternal::ExplicitValue((infallible_integer_cast<u64>((x))));
};/*case end*/
default: {
{
utility::panic(Jakt::DeprecatedString("Invalid type for repeat"sv));
}
};/*case end*/
}/*switch end*/
}()
));
if ((numeric_index >= (infallible_integer_cast<u64>((((values).size())))))){
TRY((((*this).error(TRY((__jakt_format(Jakt::DeprecatedString("Index {} out of bounds (max={})"sv),numeric_index,((values).size())))),span))));
return Error::from_errno((infallible_integer_cast<i32>((interpreter::InterpretError::InvalidType))));
}
__jakt_var_292 =  interpreter::StatementResult { typename interpreter::StatementResult::JustValue(((values)[numeric_index])) } ; goto __jakt_label_289;

}
__jakt_label_289:; __jakt_var_292.release_value(); }));
};/*case end*/
default: {
{
TRY((((*this).error(Jakt::DeprecatedString("Invalid or unsupported indexed expression"sv),span))));
return Error::from_errno((infallible_integer_cast<i32>((interpreter::InterpretError::InvalidType))));
}
};/*case end*/
}/*switch end*/
}()
)); goto __jakt_label_288;

}
__jakt_label_288:; __jakt_var_291.release_value(); }));
};/*case end*/
case 0: {
auto&& __jakt_match_value = __jakt_match_variant.template get<types::CheckedExpression::Boolean>();bool const& val = __jakt_match_value.val;
utility::Span const& span = __jakt_match_value.span;
return JaktInternal::ExplicitValue( interpreter::StatementResult { typename interpreter::StatementResult::JustValue(types::Value(TRY((types::ValueImpl::template create<typename types::ValueImpl::Bool>(val))),span)) } );
};/*case end*/
case 15: {
auto&& __jakt_match_value = __jakt_match_variant.template get<types::CheckedExpression::IndexedStruct>();NonnullRefPtr<typename types::CheckedExpression> const& expr = __jakt_match_value.expr;
DeprecatedString const& index = __jakt_match_value.index;
return JaktInternal::ExplicitValue(({ Optional<interpreter::StatementResult> __jakt_var_293; {
types::Value const value = JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<types::Value, ErrorOr<interpreter::StatementResult>>{
auto&& __jakt_match_variant = TRY((((*this).execute_expression(expr,scope))));
switch(__jakt_match_variant.index()) {
case 0: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename interpreter::StatementResult::Return>();
types::Value const& value = __jakt_match_value.value;
{
return ( interpreter::StatementResult { typename interpreter::StatementResult::Return(value) } );
}
};/*case end*/
case 1: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename interpreter::StatementResult::Throw>();
types::Value const& value = __jakt_match_value.value;
{
return ( interpreter::StatementResult { typename interpreter::StatementResult::Throw(value) } );
}
};/*case end*/
case 5: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename interpreter::StatementResult::JustValue>();
types::Value const& value = __jakt_match_value.value;
return JaktInternal::ExplicitValue(value);
};/*case end*/
case 3: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename interpreter::StatementResult::Continue>();
{
return ( interpreter::StatementResult { typename interpreter::StatementResult::Continue() } );
}
};/*case end*/
case 4: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename interpreter::StatementResult::Break>();
{
return ( interpreter::StatementResult { typename interpreter::StatementResult::Break() } );
}
};/*case end*/
case 2: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename interpreter::StatementResult::Yield>();
types::Value const& expr = __jakt_match_value.value;
{
utility::panic(Jakt::DeprecatedString("Invalid control flow"sv));
}
};/*case end*/
default: VERIFY_NOT_REACHED();}/*switch end*/
}()
));
__jakt_var_293 = JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<interpreter::StatementResult, ErrorOr<interpreter::StatementResult>>{
auto&& __jakt_match_variant = *((value).impl);
switch(__jakt_match_variant.index()) {
case 17: {
auto&& __jakt_match_value = __jakt_match_variant.template get<types::ValueImpl::Struct>();JaktInternal::DynamicArray<types::Value> const& fields = __jakt_match_value.fields;
types::StructId const& struct_id = __jakt_match_value.struct_id;
return JaktInternal::ExplicitValue(({ Optional<interpreter::StatementResult> __jakt_var_294; {
types::CheckedStruct const struct_ = ((((*this).program))->get_struct(struct_id));
i64 idx = static_cast<i64>(0LL);
JaktInternal::Optional<i64> found_index = JaktInternal::OptionalNone();
{
JaktInternal::ArrayIterator<types::CheckedField> _magic = ((((struct_).fields)).iterator());
for (;;){
JaktInternal::Optional<types::CheckedField> _magic_value = ((_magic).next());
if ((!(((_magic_value).has_value())))){
break;
}
types::CheckedField field = (_magic_value.value());
{
if ((((((((*this).program))->get_variable(((field).variable_id))))->name) == index)){
(found_index = idx);
break;
}
({auto& _jakt_ref = idx;_jakt_ref = JaktInternal::checked_add<i64>(_jakt_ref, static_cast<i64>(1LL));});
}

}
}

if ((!(((found_index).has_value())))){
TRY((((*this).error(Jakt::DeprecatedString("Attempted to access a field that does not exist"sv),((value).span)))));
return Error::from_errno((infallible_integer_cast<i32>((interpreter::InterpretError::InvalidType))));
}
__jakt_var_294 =  interpreter::StatementResult { typename interpreter::StatementResult::JustValue(((fields)[(found_index.value())])) } ; goto __jakt_label_291;

}
__jakt_label_291:; __jakt_var_294.release_value(); }));
};/*case end*/
case 18: {
auto&& __jakt_match_value = __jakt_match_variant.template get<types::ValueImpl::Class>();JaktInternal::DynamicArray<types::Value> const& fields = __jakt_match_value.fields;
types::StructId const& struct_id = __jakt_match_value.struct_id;
return JaktInternal::ExplicitValue(({ Optional<interpreter::StatementResult> __jakt_var_295; {
types::CheckedStruct const struct_ = ((((*this).program))->get_struct(struct_id));
i64 idx = static_cast<i64>(0LL);
JaktInternal::Optional<i64> found_index = JaktInternal::OptionalNone();
{
JaktInternal::ArrayIterator<types::CheckedField> _magic = ((((struct_).fields)).iterator());
for (;;){
JaktInternal::Optional<types::CheckedField> _magic_value = ((_magic).next());
if ((!(((_magic_value).has_value())))){
break;
}
types::CheckedField field = (_magic_value.value());
{
if ((((((((*this).program))->get_variable(((field).variable_id))))->name) == index)){
(found_index = idx);
break;
}
({auto& _jakt_ref = idx;_jakt_ref = JaktInternal::checked_add<i64>(_jakt_ref, static_cast<i64>(1LL));});
}

}
}

if ((!(((found_index).has_value())))){
TRY((((*this).error(Jakt::DeprecatedString("Attempted to access a field that does not exist"sv),((value).span)))));
return Error::from_errno((infallible_integer_cast<i32>((interpreter::InterpretError::InvalidType))));
}
__jakt_var_295 =  interpreter::StatementResult { typename interpreter::StatementResult::JustValue(((fields)[(found_index.value())])) } ; goto __jakt_label_292;

}
__jakt_label_292:; __jakt_var_295.release_value(); }));
};/*case end*/
default: {
{
TRY((((*this).error(Jakt::DeprecatedString("Attempted to access a field on a non-struct/enum type"sv),((value).span)))));
return Error::from_errno((infallible_integer_cast<i32>((interpreter::InterpretError::InvalidType))));
}
};/*case end*/
}/*switch end*/
}()
)); goto __jakt_label_290;

}
__jakt_label_290:; __jakt_var_293.release_value(); }));
};/*case end*/
case 16: {
auto&& __jakt_match_value = __jakt_match_variant.template get<types::CheckedExpression::IndexedCommonEnumMember>();NonnullRefPtr<typename types::CheckedExpression> const& expr = __jakt_match_value.expr;
DeprecatedString const& index = __jakt_match_value.index;
return JaktInternal::ExplicitValue(({ Optional<interpreter::StatementResult> __jakt_var_296; {
types::Value const value = JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<types::Value, ErrorOr<interpreter::StatementResult>>{
auto&& __jakt_match_variant = TRY((((*this).execute_expression(expr,scope))));
switch(__jakt_match_variant.index()) {
case 0: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename interpreter::StatementResult::Return>();
types::Value const& value = __jakt_match_value.value;
{
return ( interpreter::StatementResult { typename interpreter::StatementResult::Return(value) } );
}
};/*case end*/
case 1: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename interpreter::StatementResult::Throw>();
types::Value const& value = __jakt_match_value.value;
{
return ( interpreter::StatementResult { typename interpreter::StatementResult::Throw(value) } );
}
};/*case end*/
case 5: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename interpreter::StatementResult::JustValue>();
types::Value const& value = __jakt_match_value.value;
return JaktInternal::ExplicitValue(value);
};/*case end*/
case 3: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename interpreter::StatementResult::Continue>();
{
return ( interpreter::StatementResult { typename interpreter::StatementResult::Continue() } );
}
};/*case end*/
case 4: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename interpreter::StatementResult::Break>();
{
return ( interpreter::StatementResult { typename interpreter::StatementResult::Break() } );
}
};/*case end*/
case 2: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename interpreter::StatementResult::Yield>();
types::Value const& expr = __jakt_match_value.value;
{
utility::panic(Jakt::DeprecatedString("Invalid control flow"sv));
}
};/*case end*/
default: VERIFY_NOT_REACHED();}/*switch end*/
}()
));
__jakt_var_296 = JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<interpreter::StatementResult, ErrorOr<interpreter::StatementResult>>{
auto&& __jakt_match_variant = *((value).impl);
switch(__jakt_match_variant.index()) {
case 19: {
auto&& __jakt_match_value = __jakt_match_variant.template get<types::ValueImpl::Enum>();JaktInternal::DynamicArray<types::Value> const& fields = __jakt_match_value.fields;
types::EnumId const& enum_id = __jakt_match_value.enum_id;
return JaktInternal::ExplicitValue(({ Optional<interpreter::StatementResult> __jakt_var_297; {
types::CheckedEnum const enum_ = ((((*this).program))->get_enum(enum_id));
i64 idx = static_cast<i64>(0LL);
JaktInternal::Optional<i64> found_index = JaktInternal::OptionalNone();
{
JaktInternal::ArrayIterator<types::CheckedField> _magic = ((((enum_).fields)).iterator());
for (;;){
JaktInternal::Optional<types::CheckedField> _magic_value = ((_magic).next());
if ((!(((_magic_value).has_value())))){
break;
}
types::CheckedField field = (_magic_value.value());
{
if ((((((((*this).program))->get_variable(((field).variable_id))))->name) == index)){
(found_index = idx);
break;
}
({auto& _jakt_ref = idx;_jakt_ref = JaktInternal::checked_add<i64>(_jakt_ref, static_cast<i64>(1LL));});
}

}
}

if ((!(((found_index).has_value())))){
TRY((((*this).error(Jakt::DeprecatedString("Attempted to access a field that does not exist"sv),((value).span)))));
return Error::from_errno((infallible_integer_cast<i32>((interpreter::InterpretError::InvalidType))));
}
__jakt_var_297 =  interpreter::StatementResult { typename interpreter::StatementResult::JustValue(((fields)[(found_index.value())])) } ; goto __jakt_label_294;

}
__jakt_label_294:; __jakt_var_297.release_value(); }));
};/*case end*/
default: {
{
TRY((((*this).error(Jakt::DeprecatedString("Attempted to access a field on a non-struct/enum type"sv),((value).span)))));
return Error::from_errno((infallible_integer_cast<i32>((interpreter::InterpretError::InvalidType))));
}
};/*case end*/
}/*switch end*/
}()
)); goto __jakt_label_293;

}
__jakt_label_293:; __jakt_var_296.release_value(); }));
};/*case end*/
case 11: {
auto&& __jakt_match_value = __jakt_match_variant.template get<types::CheckedExpression::JaktDictionary>();JaktInternal::DynamicArray<JaktInternal::Tuple<NonnullRefPtr<typename types::CheckedExpression>,NonnullRefPtr<typename types::CheckedExpression>>> const& vals = __jakt_match_value.vals;
utility::Span const& span = __jakt_match_value.span;
types::TypeId const& type_id = __jakt_match_value.type_id;
return JaktInternal::ExplicitValue(({ Optional<interpreter::StatementResult> __jakt_var_298; {
JaktInternal::DynamicArray<types::Value> keys = (TRY((DynamicArray<types::Value>::create_with({}))));
JaktInternal::DynamicArray<types::Value> values = (TRY((DynamicArray<types::Value>::create_with({}))));
{
JaktInternal::ArrayIterator<JaktInternal::Tuple<NonnullRefPtr<typename types::CheckedExpression>,NonnullRefPtr<typename types::CheckedExpression>>> _magic = ((vals).iterator());
for (;;){
JaktInternal::Optional<JaktInternal::Tuple<NonnullRefPtr<typename types::CheckedExpression>,NonnullRefPtr<typename types::CheckedExpression>>> _magic_value = ((_magic).next());
if ((!(((_magic_value).has_value())))){
break;
}
JaktInternal::Tuple<NonnullRefPtr<typename types::CheckedExpression>,NonnullRefPtr<typename types::CheckedExpression>> k__v__ = (_magic_value.value());
{
JaktInternal::Tuple<NonnullRefPtr<typename types::CheckedExpression>,NonnullRefPtr<typename types::CheckedExpression>> const jakt__k__v__ = k__v__;
NonnullRefPtr<typename types::CheckedExpression> const k = ((jakt__k__v__).template get<0>());
NonnullRefPtr<typename types::CheckedExpression> const v = ((jakt__k__v__).template get<1>());

types::Value const key = JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_AT_LOOP(([&]() -> JaktInternal::ExplicitValueOrControlFlow<types::Value, ErrorOr<interpreter::StatementResult>>{
auto&& __jakt_match_variant = TRY((((*this).execute_expression(k,scope))));
switch(__jakt_match_variant.index()) {
case 0: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename interpreter::StatementResult::Return>();
types::Value const& value = __jakt_match_value.value;
{
return ( interpreter::StatementResult { typename interpreter::StatementResult::Return(value) } );
}
};/*case end*/
case 1: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename interpreter::StatementResult::Throw>();
types::Value const& value = __jakt_match_value.value;
{
return ( interpreter::StatementResult { typename interpreter::StatementResult::Throw(value) } );
}
};/*case end*/
case 5: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename interpreter::StatementResult::JustValue>();
types::Value const& value = __jakt_match_value.value;
return JaktInternal::ExplicitValue(value);
};/*case end*/
case 3: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename interpreter::StatementResult::Continue>();
{
return ( interpreter::StatementResult { typename interpreter::StatementResult::Continue() } );
}
};/*case end*/
case 4: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename interpreter::StatementResult::Break>();
{
return ( interpreter::StatementResult { typename interpreter::StatementResult::Break() } );
}
};/*case end*/
case 2: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename interpreter::StatementResult::Yield>();
types::Value const& expr = __jakt_match_value.value;
{
utility::panic(Jakt::DeprecatedString("Invalid control flow"sv));
}
};/*case end*/
default: VERIFY_NOT_REACHED();}/*switch end*/
}()
));
types::Value const val = JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_AT_LOOP(([&]() -> JaktInternal::ExplicitValueOrControlFlow<types::Value, ErrorOr<interpreter::StatementResult>>{
auto&& __jakt_match_variant = TRY((((*this).execute_expression(v,scope))));
switch(__jakt_match_variant.index()) {
case 0: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename interpreter::StatementResult::Return>();
types::Value const& value = __jakt_match_value.value;
{
return ( interpreter::StatementResult { typename interpreter::StatementResult::Return(value) } );
}
};/*case end*/
case 1: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename interpreter::StatementResult::Throw>();
types::Value const& value = __jakt_match_value.value;
{
return ( interpreter::StatementResult { typename interpreter::StatementResult::Throw(value) } );
}
};/*case end*/
case 5: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename interpreter::StatementResult::JustValue>();
types::Value const& value = __jakt_match_value.value;
return JaktInternal::ExplicitValue(value);
};/*case end*/
case 3: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename interpreter::StatementResult::Continue>();
{
return ( interpreter::StatementResult { typename interpreter::StatementResult::Continue() } );
}
};/*case end*/
case 4: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename interpreter::StatementResult::Break>();
{
return ( interpreter::StatementResult { typename interpreter::StatementResult::Break() } );
}
};/*case end*/
case 2: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename interpreter::StatementResult::Yield>();
types::Value const& expr = __jakt_match_value.value;
{
utility::panic(Jakt::DeprecatedString("Invalid control flow"sv));
}
};/*case end*/
default: VERIFY_NOT_REACHED();}/*switch end*/
}()
));
TRY((((keys).push(key))));
TRY((((values).push(val))));
}

}
}

__jakt_var_298 =  interpreter::StatementResult { typename interpreter::StatementResult::JustValue(types::Value(TRY((types::ValueImpl::template create<typename types::ValueImpl::JaktDictionary>(keys,values,type_id))),span)) } ; goto __jakt_label_295;

}
__jakt_label_295:; __jakt_var_298.release_value(); }));
};/*case end*/
case 1: {
auto&& __jakt_match_value = __jakt_match_variant.template get<types::CheckedExpression::NumericConstant>();types::CheckedNumericConstant const& val = __jakt_match_value.val;
utility::Span const& span = __jakt_match_value.span;
return JaktInternal::ExplicitValue( interpreter::StatementResult { typename interpreter::StatementResult::JustValue(JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<types::Value, ErrorOr<interpreter::StatementResult>>{
auto&& __jakt_match_variant = val;
switch(__jakt_match_variant.index()) {
case 0: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::CheckedNumericConstant::I8>();
i8 const& x = __jakt_match_value.value;
return JaktInternal::ExplicitValue(types::Value(TRY((types::ValueImpl::template create<typename types::ValueImpl::I8>(x))),span));
};/*case end*/
case 1: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::CheckedNumericConstant::I16>();
i16 const& x = __jakt_match_value.value;
return JaktInternal::ExplicitValue(types::Value(TRY((types::ValueImpl::template create<typename types::ValueImpl::I16>(x))),span));
};/*case end*/
case 2: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::CheckedNumericConstant::I32>();
i32 const& x = __jakt_match_value.value;
return JaktInternal::ExplicitValue(types::Value(TRY((types::ValueImpl::template create<typename types::ValueImpl::I32>(x))),span));
};/*case end*/
case 3: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::CheckedNumericConstant::I64>();
i64 const& x = __jakt_match_value.value;
return JaktInternal::ExplicitValue(types::Value(TRY((types::ValueImpl::template create<typename types::ValueImpl::I64>(x))),span));
};/*case end*/
case 4: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::CheckedNumericConstant::U8>();
u8 const& x = __jakt_match_value.value;
return JaktInternal::ExplicitValue(types::Value(TRY((types::ValueImpl::template create<typename types::ValueImpl::U8>(x))),span));
};/*case end*/
case 5: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::CheckedNumericConstant::U16>();
u16 const& x = __jakt_match_value.value;
return JaktInternal::ExplicitValue(types::Value(TRY((types::ValueImpl::template create<typename types::ValueImpl::U16>(x))),span));
};/*case end*/
case 6: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::CheckedNumericConstant::U32>();
u32 const& x = __jakt_match_value.value;
return JaktInternal::ExplicitValue(types::Value(TRY((types::ValueImpl::template create<typename types::ValueImpl::U32>(x))),span));
};/*case end*/
case 7: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::CheckedNumericConstant::U64>();
u64 const& x = __jakt_match_value.value;
return JaktInternal::ExplicitValue(types::Value(TRY((types::ValueImpl::template create<typename types::ValueImpl::U64>(x))),span));
};/*case end*/
case 8: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::CheckedNumericConstant::USize>();
u64 const& x = __jakt_match_value.value;
return JaktInternal::ExplicitValue(types::Value(TRY((types::ValueImpl::template create<typename types::ValueImpl::USize>((infallible_integer_cast<size_t>((x)))))),span));
};/*case end*/
case 9: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::CheckedNumericConstant::F32>();
f32 const& x = __jakt_match_value.value;
return JaktInternal::ExplicitValue(types::Value(TRY((types::ValueImpl::template create<typename types::ValueImpl::F32>(x))),span));
};/*case end*/
case 10: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::CheckedNumericConstant::F64>();
f64 const& x = __jakt_match_value.value;
return JaktInternal::ExplicitValue(types::Value(TRY((types::ValueImpl::template create<typename types::ValueImpl::F64>(x))),span));
};/*case end*/
default: VERIFY_NOT_REACHED();}/*switch end*/
}()
))) } );
};/*case end*/
case 2: {
auto&& __jakt_match_value = __jakt_match_variant.template get<types::CheckedExpression::QuotedString>();types::CheckedStringLiteral const& val = __jakt_match_value.val;
utility::Span const& span = __jakt_match_value.span;
return JaktInternal::ExplicitValue(JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<interpreter::StatementResult,ErrorOr<interpreter::StatementResult>>{
auto __jakt_enum_value = (((((val).type_id)).equals(types::builtin( types::BuiltinType { typename types::BuiltinType::JaktString() } ))));
if (__jakt_enum_value == true) {
return JaktInternal::ExplicitValue( interpreter::StatementResult { typename interpreter::StatementResult::JustValue(types::Value(TRY((types::ValueImpl::template create<typename types::ValueImpl::JaktString>(TRY((utility::interpret_escapes(((val).to_string()))))))),span)) } );
}
else {
return JaktInternal::ExplicitValue(({ Optional<interpreter::StatementResult> __jakt_var_299; {
types::FunctionId const function_id = JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<types::FunctionId, ErrorOr<interpreter::StatementResult>>{
auto&& __jakt_match_variant = *((((*this).program))->get_type(((val).type_id)));
switch(__jakt_match_variant.index()) {
case 23: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::Type::Struct>();
types::StructId const& struct_id = __jakt_match_value.value;
return JaktInternal::ExplicitValue(({ Optional<types::FunctionId> __jakt_var_300; {
NonnullRefPtr<types::Scope> const scope = TRY((((((*this).program))->get_scope(((((((*this).program))->get_struct(struct_id))).scope_id)))));
JaktInternal::Optional<JaktInternal::DynamicArray<types::FunctionId>> const overloads = ((((scope)->functions)).get(Jakt::DeprecatedString("from_string_literal"sv)));
if ((!(((overloads).has_value())))){
utility::panic(TRY((__jakt_format(Jakt::DeprecatedString("Failed to find a from_string_literal overload in {}"sv),TRY((((((*this).program))->type_name(((val).type_id),false))))))));
}
__jakt_var_300 = ((((overloads.value())).first()).value()); goto __jakt_label_297;

}
__jakt_label_297:; __jakt_var_300.release_value(); }));
};/*case end*/
case 19: {
auto&& __jakt_match_value = __jakt_match_variant.template get<types::Type::GenericInstance>();types::StructId const& struct_id = __jakt_match_value.id;
return JaktInternal::ExplicitValue(({ Optional<types::FunctionId> __jakt_var_301; {
NonnullRefPtr<types::Scope> const scope = TRY((((((*this).program))->get_scope(((((((*this).program))->get_struct(struct_id))).scope_id)))));
JaktInternal::Optional<JaktInternal::DynamicArray<types::FunctionId>> const overloads = ((((scope)->functions)).get(Jakt::DeprecatedString("from_string_literal"sv)));
if ((!(((overloads).has_value())))){
utility::panic(TRY((__jakt_format(Jakt::DeprecatedString("Failed to find a from_string_literal overload in {}"sv),TRY((((((*this).program))->type_name(((val).type_id),false))))))));
}
__jakt_var_301 = ((((overloads.value())).first()).value()); goto __jakt_label_298;

}
__jakt_label_298:; __jakt_var_301.release_value(); }));
};/*case end*/
case 24: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::Type::Enum>();
types::EnumId const& enum_id = __jakt_match_value.value;
return JaktInternal::ExplicitValue(({ Optional<types::FunctionId> __jakt_var_302; {
NonnullRefPtr<types::Scope> const scope = TRY((((((*this).program))->get_scope(((((((*this).program))->get_enum(enum_id))).scope_id)))));
JaktInternal::Optional<JaktInternal::DynamicArray<types::FunctionId>> const overloads = ((((scope)->functions)).get(Jakt::DeprecatedString("from_string_literal"sv)));
if ((!(((overloads).has_value())))){
utility::panic(Jakt::DeprecatedString("Failed to find a from_string_literal overload"sv));
}
__jakt_var_302 = ((((overloads.value())).first()).value()); goto __jakt_label_299;

}
__jakt_label_299:; __jakt_var_302.release_value(); }));
};/*case end*/
case 20: {
auto&& __jakt_match_value = __jakt_match_variant.template get<types::Type::GenericEnumInstance>();types::EnumId const& enum_id = __jakt_match_value.id;
return JaktInternal::ExplicitValue(({ Optional<types::FunctionId> __jakt_var_303; {
NonnullRefPtr<types::Scope> const scope = TRY((((((*this).program))->get_scope(((((((*this).program))->get_enum(enum_id))).scope_id)))));
JaktInternal::Optional<JaktInternal::DynamicArray<types::FunctionId>> const overloads = ((((scope)->functions)).get(Jakt::DeprecatedString("from_string_literal"sv)));
if ((!(((overloads).has_value())))){
utility::panic(Jakt::DeprecatedString("Failed to find a from_string_literal overload"sv));
}
__jakt_var_303 = ((((overloads.value())).first()).value()); goto __jakt_label_300;

}
__jakt_label_300:; __jakt_var_303.release_value(); }));
};/*case end*/
default: {
{
TRY((((*this).error(TRY((__jakt_format(Jakt::DeprecatedString("Invalid type {} for string literal"sv),((((*this).program))->get_type(((val).type_id)))))),span))));
return Error::from_errno((infallible_integer_cast<i32>((interpreter::InterpretError::InvalidType))));
}
};/*case end*/
}/*switch end*/
}()
));
JaktInternal::DynamicArray<types::ResolvedNamespace> const ns = (TRY((DynamicArray<types::ResolvedNamespace>::create_with({}))));
__jakt_var_299 = JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<interpreter::StatementResult, ErrorOr<interpreter::StatementResult>>{
auto&& __jakt_match_variant = TRY((((*this).execute(function_id,static_cast<JaktInternal::Optional<JaktInternal::DynamicArray<types::ResolvedNamespace>>>(ns),JaktInternal::OptionalNone(),(TRY((DynamicArray<types::Value>::create_with({types::Value(TRY((types::ValueImpl::template create<typename types::ValueImpl::JaktString>(TRY((utility::interpret_escapes(((val).to_string()))))))),span)})))),span,scope))));
switch(__jakt_match_variant.index()) {
case 0: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename interpreter::ExecutionResult::Return>();
types::Value const& value = __jakt_match_value.value;
return JaktInternal::ExplicitValue( interpreter::StatementResult { typename interpreter::StatementResult::JustValue(value) } );
};/*case end*/
case 1: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename interpreter::ExecutionResult::Throw>();
types::Value const& value = __jakt_match_value.value;
return JaktInternal::ExplicitValue( interpreter::StatementResult { typename interpreter::StatementResult::Throw(value) } );
};/*case end*/
default: VERIFY_NOT_REACHED();}/*switch end*/
}()
)); goto __jakt_label_296;

}
__jakt_label_296:; __jakt_var_299.release_value(); }));
}
}()))
);
};/*case end*/
case 4: {
auto&& __jakt_match_value = __jakt_match_variant.template get<types::CheckedExpression::CharacterConstant>();DeprecatedString const& val = __jakt_match_value.val;
utility::Span const& span = __jakt_match_value.span;
return JaktInternal::ExplicitValue( interpreter::StatementResult { typename interpreter::StatementResult::JustValue(types::Value(TRY((types::ValueImpl::template create<typename types::ValueImpl::CChar>((infallible_integer_cast<char>((((val).byte_at(static_cast<size_t>(0ULL))))))))),span)) } );
};/*case end*/
case 9: {
auto&& __jakt_match_value = __jakt_match_variant.template get<types::CheckedExpression::JaktArray>();JaktInternal::DynamicArray<NonnullRefPtr<typename types::CheckedExpression>> const& vals = __jakt_match_value.vals;
JaktInternal::Optional<NonnullRefPtr<typename types::CheckedExpression>> const& repeat = __jakt_match_value.repeat;
utility::Span const& span = __jakt_match_value.span;
types::TypeId const& type_id = __jakt_match_value.type_id;
return JaktInternal::ExplicitValue(JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<interpreter::StatementResult,ErrorOr<interpreter::StatementResult>>{
auto __jakt_enum_value = (((repeat).has_value()));
if (__jakt_enum_value == true) {
return JaktInternal::ExplicitValue(({ Optional<interpreter::StatementResult> __jakt_var_304; {
size_t const count = JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<size_t, ErrorOr<interpreter::StatementResult>>{
auto&& __jakt_match_variant = TRY((((*this).execute_expression((repeat.value()),scope))));
switch(__jakt_match_variant.index()) {
case 0: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename interpreter::StatementResult::Return>();
types::Value const& value = __jakt_match_value.value;
{
return ( interpreter::StatementResult { typename interpreter::StatementResult::Return(value) } );
}
};/*case end*/
case 1: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename interpreter::StatementResult::Throw>();
types::Value const& value = __jakt_match_value.value;
{
return ( interpreter::StatementResult { typename interpreter::StatementResult::Throw(value) } );
}
};/*case end*/
case 5: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename interpreter::StatementResult::JustValue>();
types::Value const& value = __jakt_match_value.value;
return JaktInternal::ExplicitValue(JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<size_t, ErrorOr<interpreter::StatementResult>>{
auto&& __jakt_match_variant = *((value).impl);
switch(__jakt_match_variant.index()) {
case 6: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::I8>();
i8 const& x = __jakt_match_value.value;
return JaktInternal::ExplicitValue((infallible_integer_cast<size_t>((x))));
};/*case end*/
case 7: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::I16>();
i16 const& x = __jakt_match_value.value;
return JaktInternal::ExplicitValue((infallible_integer_cast<size_t>((x))));
};/*case end*/
case 8: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::I32>();
i32 const& x = __jakt_match_value.value;
return JaktInternal::ExplicitValue((infallible_integer_cast<size_t>((x))));
};/*case end*/
case 9: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::I64>();
i64 const& x = __jakt_match_value.value;
return JaktInternal::ExplicitValue((infallible_integer_cast<size_t>((x))));
};/*case end*/
case 2: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::U8>();
u8 const& x = __jakt_match_value.value;
return JaktInternal::ExplicitValue((infallible_integer_cast<size_t>((x))));
};/*case end*/
case 3: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::U16>();
u16 const& x = __jakt_match_value.value;
return JaktInternal::ExplicitValue((infallible_integer_cast<size_t>((x))));
};/*case end*/
case 4: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::U32>();
u32 const& x = __jakt_match_value.value;
return JaktInternal::ExplicitValue((infallible_integer_cast<size_t>((x))));
};/*case end*/
case 5: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::U64>();
u64 const& x = __jakt_match_value.value;
return JaktInternal::ExplicitValue((infallible_integer_cast<size_t>((x))));
};/*case end*/
case 12: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::USize>();
size_t const& x = __jakt_match_value.value;
return JaktInternal::ExplicitValue((infallible_integer_cast<size_t>((x))));
};/*case end*/
default: {
{
utility::panic(Jakt::DeprecatedString("Invalid type for repeat"sv));
}
};/*case end*/
}/*switch end*/
}()
)));
};/*case end*/
case 3: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename interpreter::StatementResult::Continue>();
{
return ( interpreter::StatementResult { typename interpreter::StatementResult::Continue() } );
}
};/*case end*/
case 4: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename interpreter::StatementResult::Break>();
{
return ( interpreter::StatementResult { typename interpreter::StatementResult::Break() } );
}
};/*case end*/
case 2: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename interpreter::StatementResult::Yield>();
types::Value const& expr = __jakt_match_value.value;
{
utility::panic(Jakt::DeprecatedString("Invalid control flow"sv));
}
};/*case end*/
default: VERIFY_NOT_REACHED();}/*switch end*/
}()
));
types::Value const value_to_repeat = JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<types::Value, ErrorOr<interpreter::StatementResult>>{
auto&& __jakt_match_variant = TRY((((*this).execute_expression(((vals)[static_cast<i64>(0LL)]),scope))));
switch(__jakt_match_variant.index()) {
case 0: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename interpreter::StatementResult::Return>();
types::Value const& value = __jakt_match_value.value;
{
return ( interpreter::StatementResult { typename interpreter::StatementResult::Return(value) } );
}
};/*case end*/
case 1: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename interpreter::StatementResult::Throw>();
types::Value const& value = __jakt_match_value.value;
{
return ( interpreter::StatementResult { typename interpreter::StatementResult::Throw(value) } );
}
};/*case end*/
case 5: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename interpreter::StatementResult::JustValue>();
types::Value const& value = __jakt_match_value.value;
return JaktInternal::ExplicitValue(value);
};/*case end*/
case 3: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename interpreter::StatementResult::Continue>();
{
return ( interpreter::StatementResult { typename interpreter::StatementResult::Continue() } );
}
};/*case end*/
case 4: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename interpreter::StatementResult::Break>();
{
return ( interpreter::StatementResult { typename interpreter::StatementResult::Break() } );
}
};/*case end*/
case 2: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename interpreter::StatementResult::Yield>();
types::Value const& expr = __jakt_match_value.value;
{
utility::panic(Jakt::DeprecatedString("Invalid control flow"sv));
}
};/*case end*/
default: VERIFY_NOT_REACHED();}/*switch end*/
}()
));
__jakt_var_304 =  interpreter::StatementResult { typename interpreter::StatementResult::JustValue(types::Value(TRY((types::ValueImpl::template create<typename types::ValueImpl::JaktArray>((TRY((DynamicArray<types::Value>::filled(count, value_to_repeat)))),TRY((((((*this).program))->substitute_typevars_in_type(type_id,TRY((((scope)->type_map_for_substitution()))),((type_id).module)))))))),span)) } ; goto __jakt_label_301;

}
__jakt_label_301:; __jakt_var_304.release_value(); }));
}
else {
return JaktInternal::ExplicitValue(({ Optional<interpreter::StatementResult> __jakt_var_305; {
JaktInternal::DynamicArray<types::Value> values = (TRY((DynamicArray<types::Value>::create_with({}))));
{
JaktInternal::ArrayIterator<NonnullRefPtr<typename types::CheckedExpression>> _magic = ((vals).iterator());
for (;;){
JaktInternal::Optional<NonnullRefPtr<typename types::CheckedExpression>> _magic_value = ((_magic).next());
if ((!(((_magic_value).has_value())))){
break;
}
NonnullRefPtr<typename types::CheckedExpression> value = (_magic_value.value());
{
types::Value const val = JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_AT_LOOP(([&]() -> JaktInternal::ExplicitValueOrControlFlow<types::Value, ErrorOr<interpreter::StatementResult>>{
auto&& __jakt_match_variant = TRY((((*this).execute_expression(value,scope))));
switch(__jakt_match_variant.index()) {
case 0: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename interpreter::StatementResult::Return>();
types::Value const& value = __jakt_match_value.value;
{
return ( interpreter::StatementResult { typename interpreter::StatementResult::Return(value) } );
}
};/*case end*/
case 1: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename interpreter::StatementResult::Throw>();
types::Value const& value = __jakt_match_value.value;
{
return ( interpreter::StatementResult { typename interpreter::StatementResult::Throw(value) } );
}
};/*case end*/
case 5: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename interpreter::StatementResult::JustValue>();
types::Value const& value = __jakt_match_value.value;
return JaktInternal::ExplicitValue(value);
};/*case end*/
case 3: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename interpreter::StatementResult::Continue>();
{
return ( interpreter::StatementResult { typename interpreter::StatementResult::Continue() } );
}
};/*case end*/
case 4: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename interpreter::StatementResult::Break>();
{
return ( interpreter::StatementResult { typename interpreter::StatementResult::Break() } );
}
};/*case end*/
case 2: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename interpreter::StatementResult::Yield>();
types::Value const& expr = __jakt_match_value.value;
{
utility::panic(Jakt::DeprecatedString("Invalid control flow"sv));
}
};/*case end*/
default: VERIFY_NOT_REACHED();}/*switch end*/
}()
));
TRY((((values).push(val))));
}

}
}

__jakt_var_305 =  interpreter::StatementResult { typename interpreter::StatementResult::JustValue(types::Value(TRY((types::ValueImpl::template create<typename types::ValueImpl::JaktArray>(values,TRY((((((*this).program))->substitute_typevars_in_type(type_id,TRY((((scope)->type_map_for_substitution()))),((type_id).module)))))))),span)) } ; goto __jakt_label_302;

}
__jakt_label_302:; __jakt_var_305.release_value(); }));
}
}()))
);
};/*case end*/
case 14: {
auto&& __jakt_match_value = __jakt_match_variant.template get<types::CheckedExpression::IndexedTuple>();NonnullRefPtr<typename types::CheckedExpression> const& expr = __jakt_match_value.expr;
size_t const& index = __jakt_match_value.index;
return JaktInternal::ExplicitValue(({ Optional<interpreter::StatementResult> __jakt_var_306; {
types::Value const value = JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<types::Value, ErrorOr<interpreter::StatementResult>>{
auto&& __jakt_match_variant = TRY((((*this).execute_expression(expr,scope))));
switch(__jakt_match_variant.index()) {
case 5: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename interpreter::StatementResult::JustValue>();
types::Value const& value = __jakt_match_value.value;
return JaktInternal::ExplicitValue(value);
};/*case end*/
case 0: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename interpreter::StatementResult::Return>();
types::Value const& value = __jakt_match_value.value;
{
return ( interpreter::StatementResult { typename interpreter::StatementResult::Return(value) } );
}
};/*case end*/
case 1: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename interpreter::StatementResult::Throw>();
types::Value const& value = __jakt_match_value.value;
{
return ( interpreter::StatementResult { typename interpreter::StatementResult::Throw(value) } );
}
};/*case end*/
case 3: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename interpreter::StatementResult::Continue>();
{
return ( interpreter::StatementResult { typename interpreter::StatementResult::Continue() } );
}
};/*case end*/
case 4: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename interpreter::StatementResult::Break>();
{
return ( interpreter::StatementResult { typename interpreter::StatementResult::Break() } );
}
};/*case end*/
case 2: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename interpreter::StatementResult::Yield>();
{
utility::panic(Jakt::DeprecatedString("Invalid control flow"sv));
}
};/*case end*/
default: VERIFY_NOT_REACHED();}/*switch end*/
}()
));
__jakt_var_306 = JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<interpreter::StatementResult,ErrorOr<interpreter::StatementResult>>{
auto __jakt_enum_value = (((((value).impl))->index() == 26 /* JaktTuple */));
if (__jakt_enum_value == true) {
return JaktInternal::ExplicitValue(({ Optional<interpreter::StatementResult> __jakt_var_307; {
JaktInternal::DynamicArray<types::Value> const fields = ((((value).impl))->get<types::ValueImpl::JaktTuple>()).fields;
__jakt_var_307 =  interpreter::StatementResult { typename interpreter::StatementResult::JustValue(((fields)[index])) } ; goto __jakt_label_304;

}
__jakt_label_304:; __jakt_var_307.release_value(); }));
}
else {
{
utility::panic(Jakt::DeprecatedString("expected tuple"sv));
}
}
}()))
; goto __jakt_label_303;

}
__jakt_label_303:; __jakt_var_306.release_value(); }));
};/*case end*/
case 17: {
auto&& __jakt_match_value = __jakt_match_variant.template get<types::CheckedExpression::Match>();NonnullRefPtr<typename types::CheckedExpression> const& expr = __jakt_match_value.expr;
JaktInternal::DynamicArray<types::CheckedMatchCase> const& match_cases = __jakt_match_value.match_cases;
bool const& all_variants_constant = __jakt_match_value.all_variants_constant;
utility::Span const& span = __jakt_match_value.span;
return JaktInternal::ExplicitValue(({ Optional<interpreter::StatementResult> __jakt_var_308; {
types::Value const value = JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<types::Value, ErrorOr<interpreter::StatementResult>>{
auto&& __jakt_match_variant = TRY((((*this).execute_expression(expr,scope))));
switch(__jakt_match_variant.index()) {
case 5: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename interpreter::StatementResult::JustValue>();
types::Value const& value = __jakt_match_value.value;
return JaktInternal::ExplicitValue(value);
};/*case end*/
case 0: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename interpreter::StatementResult::Return>();
types::Value const& value = __jakt_match_value.value;
{
return ( interpreter::StatementResult { typename interpreter::StatementResult::Return(value) } );
}
};/*case end*/
case 1: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename interpreter::StatementResult::Throw>();
types::Value const& value = __jakt_match_value.value;
{
return ( interpreter::StatementResult { typename interpreter::StatementResult::Throw(value) } );
}
};/*case end*/
case 3: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename interpreter::StatementResult::Continue>();
{
return ( interpreter::StatementResult { typename interpreter::StatementResult::Continue() } );
}
};/*case end*/
case 4: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename interpreter::StatementResult::Break>();
{
return ( interpreter::StatementResult { typename interpreter::StatementResult::Break() } );
}
};/*case end*/
case 2: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename interpreter::StatementResult::Yield>();
{
utility::panic(Jakt::DeprecatedString("Invalid control flow"sv));
}
};/*case end*/
default: VERIFY_NOT_REACHED();}/*switch end*/
}()
));
__jakt_var_308 = JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<interpreter::StatementResult, ErrorOr<interpreter::StatementResult>>{
auto&& __jakt_match_variant = *((value).impl);
switch(__jakt_match_variant.index()) {
case 19: {
auto&& __jakt_match_value = __jakt_match_variant.template get<types::ValueImpl::Enum>();JaktInternal::DynamicArray<types::Value> const& fields = __jakt_match_value.fields;
types::EnumId const& enum_id = __jakt_match_value.enum_id;
types::FunctionId const& constructor = __jakt_match_value.constructor;
return JaktInternal::ExplicitValue(({ Optional<interpreter::StatementResult> __jakt_var_309; {
DeprecatedString const constructor_name = ((((((*this).program))->get_function(constructor)))->name);
JaktInternal::Optional<types::CheckedMatchBody> catch_all_case = JaktInternal::OptionalNone();
JaktInternal::Optional<types::CheckedMatchBody> found_body = JaktInternal::OptionalNone();
JaktInternal::Optional<JaktInternal::DynamicArray<parser::EnumVariantPatternArgument>> found_args = JaktInternal::OptionalNone();
JaktInternal::Optional<size_t> found_variant_index = JaktInternal::OptionalNone();
JaktInternal::Optional<utility::Span> span = JaktInternal::OptionalNone();
{
JaktInternal::ArrayIterator<types::CheckedMatchCase> _magic = ((match_cases).iterator());
for (;;){
JaktInternal::Optional<types::CheckedMatchCase> _magic_value = ((_magic).next());
if ((!(((_magic_value).has_value())))){
break;
}
types::CheckedMatchCase match_case = (_magic_value.value());
{
JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_AT_LOOP(([&]() -> JaktInternal::ExplicitValueOrControlFlow<void, ErrorOr<interpreter::StatementResult>>{
auto&& __jakt_match_variant = match_case;
switch(__jakt_match_variant.index()) {
case 0: {
auto&& __jakt_match_value = __jakt_match_variant.template get<types::CheckedMatchCase::EnumVariant>();DeprecatedString const& name = __jakt_match_value.name;
JaktInternal::DynamicArray<parser::EnumVariantPatternArgument> const& args = __jakt_match_value.args;
size_t const& index = __jakt_match_value.index;
types::CheckedMatchBody const& body = __jakt_match_value.body;
utility::Span const& marker_span = __jakt_match_value.marker_span;
{
if ((name != constructor_name)){
return JaktInternal::LoopContinue{};
}
(found_body = body);
(found_args = args);
(found_variant_index = index);
(span = marker_span);
return JaktInternal::LoopBreak{};
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 1: {
auto&& __jakt_match_value = __jakt_match_variant.template get<types::CheckedMatchCase::Expression>();utility::Span const& marker_span = __jakt_match_value.marker_span;
{
TRY((((*this).error(Jakt::DeprecatedString("Value matches are not allowed on enums"sv),marker_span))));
return Error::from_errno((infallible_integer_cast<i32>((interpreter::InterpretError::InvalidType))));
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 2: {
auto&& __jakt_match_value = __jakt_match_variant.template get<types::CheckedMatchCase::CatchAll>();types::CheckedMatchBody const& body = __jakt_match_value.body;
utility::Span const& marker_span = __jakt_match_value.marker_span;
{
(catch_all_case = body);
(span = marker_span);
return JaktInternal::LoopContinue{};
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
default: VERIFY_NOT_REACHED();}/*switch end*/
}()
));
}

}
}

(found_body = found_body.value_or_lazy_evaluated([&] { return (catch_all_case.value()); }));
JaktInternal::DynamicArray<parser::EnumVariantPatternArgument> const empty_args = (TRY((DynamicArray<parser::EnumVariantPatternArgument>::create_with({}))));
(found_args = found_args.value_or_lazy_evaluated([&] { return empty_args; }));
NonnullRefPtr<interpreter::InterpreterScope> new_scope = TRY((interpreter::InterpreterScope::create((TRY((Dictionary<DeprecatedString, types::Value>::create_with_entries({})))),scope,(TRY((Dictionary<DeprecatedString, types::TypeId>::create_with_entries({})))))));
ScopeGuard __jakt_var_310([&] {
MUST((((new_scope)->perform_defers(*this,(span.value())))));
});
if ((((found_variant_index).has_value()) && (!((((found_args.value())).is_empty()))))){
types::CheckedEnumVariant const variant = ((((((((*this).program))->get_enum(enum_id))).variants))[(found_variant_index.value())]);
JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<void, ErrorOr<interpreter::StatementResult>>{
auto&& __jakt_match_variant = variant;
switch(__jakt_match_variant.index()) {
case 0: {
auto&& __jakt_match_value = __jakt_match_variant.template get<types::CheckedEnumVariant::Untyped>();{
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 2: {
auto&& __jakt_match_value = __jakt_match_variant.template get<types::CheckedEnumVariant::WithValue>();{
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 1: {
auto&& __jakt_match_value = __jakt_match_variant.template get<types::CheckedEnumVariant::Typed>();{
TRY((((((new_scope)->bindings)).set((((((found_args.value()))[static_cast<i64>(0LL)])).binding),((fields)[static_cast<i64>(0LL)])))));
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 3: {
auto&& __jakt_match_value = __jakt_match_variant.template get<types::CheckedEnumVariant::StructLike>();JaktInternal::DynamicArray<types::VarId> const& variant_fields = __jakt_match_value.fields;
{
i64 i = static_cast<i64>(0LL);
{
JaktInternal::ArrayIterator<types::VarId> _magic = ((variant_fields).iterator());
for (;;){
JaktInternal::Optional<types::VarId> _magic_value = ((_magic).next());
if ((!(((_magic_value).has_value())))){
break;
}
types::VarId var_id = (_magic_value.value());
{
NonnullRefPtr<types::CheckedVariable> const field = ((((*this).program))->get_variable(var_id));
{
JaktInternal::ArrayIterator<parser::EnumVariantPatternArgument> _magic = (((found_args.value())).iterator());
for (;;){
JaktInternal::Optional<parser::EnumVariantPatternArgument> _magic_value = ((_magic).next());
if ((!(((_magic_value).has_value())))){
break;
}
parser::EnumVariantPatternArgument arg = (_magic_value.value());
{
DeprecatedString const matched_name = ((arg).name).value_or_lazy_evaluated([&] { return ((arg).binding); });
if ((matched_name == ((field)->name))){
TRY((((((new_scope)->bindings)).set(((arg).binding),((fields)[i])))));
break;
}
}

}
}

({auto& _jakt_ref = i;_jakt_ref = JaktInternal::checked_add<i64>(_jakt_ref, static_cast<i64>(1LL));});
}

}
}

}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
default: VERIFY_NOT_REACHED();}/*switch end*/
}()
));
}
__jakt_var_309 = JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<interpreter::StatementResult, ErrorOr<interpreter::StatementResult>>{
auto&& __jakt_match_variant = (found_body.value());
switch(__jakt_match_variant.index()) {
case 0: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::CheckedMatchBody::Expression>();
NonnullRefPtr<typename types::CheckedExpression> const& expr = __jakt_match_value.value;
return JaktInternal::ExplicitValue(({ Optional<interpreter::StatementResult> __jakt_var_311; {
interpreter::StatementResult const result = TRY((((*this).execute_expression(expr,new_scope))));
__jakt_var_311 = JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<interpreter::StatementResult, ErrorOr<interpreter::StatementResult>>{
auto&& __jakt_match_variant = result;
switch(__jakt_match_variant.index()) {
case 2: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename interpreter::StatementResult::Yield>();
types::Value const& value = __jakt_match_value.value;
return JaktInternal::ExplicitValue( interpreter::StatementResult { typename interpreter::StatementResult::JustValue(value) } );
};/*case end*/
case 3: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename interpreter::StatementResult::Continue>();
return JaktInternal::ExplicitValue(result);
};/*case end*/
case 4: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename interpreter::StatementResult::Break>();
return JaktInternal::ExplicitValue(result);
};/*case end*/
case 5: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename interpreter::StatementResult::JustValue>();
return JaktInternal::ExplicitValue(result);
};/*case end*/
case 0: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename interpreter::StatementResult::Return>();
return JaktInternal::ExplicitValue(result);
};/*case end*/
case 1: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename interpreter::StatementResult::Throw>();
return JaktInternal::ExplicitValue(result);
};/*case end*/
default: VERIFY_NOT_REACHED();}/*switch end*/
}()
)); goto __jakt_label_307;

}
__jakt_label_307:; __jakt_var_311.release_value(); }));
};/*case end*/
case 1: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::CheckedMatchBody::Block>();
types::CheckedBlock const& block = __jakt_match_value.value;
return JaktInternal::ExplicitValue(({ Optional<interpreter::StatementResult> __jakt_var_312; {
interpreter::StatementResult const result = TRY((((*this).execute_block(block,new_scope,(span.value())))));
__jakt_var_312 = JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<interpreter::StatementResult, ErrorOr<interpreter::StatementResult>>{
auto&& __jakt_match_variant = result;
switch(__jakt_match_variant.index()) {
case 2: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename interpreter::StatementResult::Yield>();
types::Value const& value = __jakt_match_value.value;
return JaktInternal::ExplicitValue( interpreter::StatementResult { typename interpreter::StatementResult::JustValue(value) } );
};/*case end*/
case 3: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename interpreter::StatementResult::Continue>();
return JaktInternal::ExplicitValue(result);
};/*case end*/
case 4: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename interpreter::StatementResult::Break>();
return JaktInternal::ExplicitValue(result);
};/*case end*/
case 5: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename interpreter::StatementResult::JustValue>();
return JaktInternal::ExplicitValue(result);
};/*case end*/
case 0: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename interpreter::StatementResult::Return>();
return JaktInternal::ExplicitValue(result);
};/*case end*/
case 1: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename interpreter::StatementResult::Throw>();
return JaktInternal::ExplicitValue(result);
};/*case end*/
default: VERIFY_NOT_REACHED();}/*switch end*/
}()
)); goto __jakt_label_308;

}
__jakt_label_308:; __jakt_var_312.release_value(); }));
};/*case end*/
default: VERIFY_NOT_REACHED();}/*switch end*/
}()
)); goto __jakt_label_306;

}
__jakt_label_306:; __jakt_var_309.release_value(); }));
};/*case end*/
default: {
return JaktInternal::ExplicitValue(({ Optional<interpreter::StatementResult> __jakt_var_313; {
JaktInternal::Optional<types::CheckedMatchBody> catch_all_case = JaktInternal::OptionalNone();
JaktInternal::Optional<types::CheckedMatchBody> found_body = JaktInternal::OptionalNone();
JaktInternal::Optional<utility::Span> span = JaktInternal::OptionalNone();
{
JaktInternal::ArrayIterator<types::CheckedMatchCase> _magic = ((match_cases).iterator());
for (;;){
JaktInternal::Optional<types::CheckedMatchCase> _magic_value = ((_magic).next());
if ((!(((_magic_value).has_value())))){
break;
}
types::CheckedMatchCase match_case = (_magic_value.value());
{
JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_AT_LOOP(([&]() -> JaktInternal::ExplicitValueOrControlFlow<void, ErrorOr<interpreter::StatementResult>>{
auto&& __jakt_match_variant = match_case;
switch(__jakt_match_variant.index()) {
case 1: {
auto&& __jakt_match_value = __jakt_match_variant.template get<types::CheckedMatchCase::Expression>();types::CheckedMatchBody const& body = __jakt_match_value.body;
NonnullRefPtr<typename types::CheckedExpression> const& expression = __jakt_match_value.expression;
utility::Span const& marker_span = __jakt_match_value.marker_span;
{
types::Value const value_to_match_against = JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_AT_LOOP_NESTED_MATCH(([&]() -> JaktInternal::ExplicitValueOrControlFlow<types::Value, ErrorOr<interpreter::StatementResult>>{
auto&& __jakt_match_variant = TRY((((*this).execute_expression(expression,scope))));
switch(__jakt_match_variant.index()) {
case 0: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename interpreter::StatementResult::Return>();
types::Value const& value = __jakt_match_value.value;
{
return ( interpreter::StatementResult { typename interpreter::StatementResult::Return(value) } );
}
};/*case end*/
case 1: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename interpreter::StatementResult::Throw>();
types::Value const& value = __jakt_match_value.value;
{
return ( interpreter::StatementResult { typename interpreter::StatementResult::Throw(value) } );
}
};/*case end*/
case 5: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename interpreter::StatementResult::JustValue>();
types::Value const& value = __jakt_match_value.value;
return JaktInternal::ExplicitValue(value);
};/*case end*/
case 3: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename interpreter::StatementResult::Continue>();
{
return ( interpreter::StatementResult { typename interpreter::StatementResult::Continue() } );
}
};/*case end*/
case 4: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename interpreter::StatementResult::Break>();
{
return ( interpreter::StatementResult { typename interpreter::StatementResult::Break() } );
}
};/*case end*/
case 2: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename interpreter::StatementResult::Yield>();
{
utility::panic(Jakt::DeprecatedString("Invalid control flow"sv));
}
};/*case end*/
default: VERIFY_NOT_REACHED();}/*switch end*/
}()
));
if (((((value_to_match_against).impl))->equals(((value).impl)))){
(found_body = static_cast<JaktInternal::Optional<types::CheckedMatchBody>>(body));
(span = static_cast<JaktInternal::Optional<utility::Span>>(marker_span));
return JaktInternal::LoopBreak{};
}
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 2: {
auto&& __jakt_match_value = __jakt_match_variant.template get<types::CheckedMatchCase::CatchAll>();types::CheckedMatchBody const& body = __jakt_match_value.body;
utility::Span const& marker_span = __jakt_match_value.marker_span;
{
(catch_all_case = body);
(span = marker_span);
return JaktInternal::LoopContinue{};
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 0: {
auto&& __jakt_match_value = __jakt_match_variant.template get<types::CheckedMatchCase::EnumVariant>();utility::Span const& marker_span = __jakt_match_value.marker_span;
{
TRY((((*this).error(TRY((__jakt_format(Jakt::DeprecatedString("Value matches cannot have enum variant arms (matching on {})"sv),((value).type_name())))),marker_span))));
return Error::from_errno((infallible_integer_cast<i32>((interpreter::InterpretError::InvalidType))));
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
default: VERIFY_NOT_REACHED();}/*switch end*/
}()
));
}

}
}

(found_body = found_body.value_or_lazy_evaluated([&] { return (catch_all_case.value()); }));
NonnullRefPtr<interpreter::InterpreterScope> new_scope = TRY((interpreter::InterpreterScope::create((TRY((Dictionary<DeprecatedString, types::Value>::create_with_entries({})))),scope,(TRY((Dictionary<DeprecatedString, types::TypeId>::create_with_entries({})))))));
ScopeGuard __jakt_var_314([&] {
MUST((((new_scope)->perform_defers(*this,(span.value())))));
});
__jakt_var_313 = JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<interpreter::StatementResult, ErrorOr<interpreter::StatementResult>>{
auto&& __jakt_match_variant = (found_body.value());
switch(__jakt_match_variant.index()) {
case 0: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::CheckedMatchBody::Expression>();
NonnullRefPtr<typename types::CheckedExpression> const& expr = __jakt_match_value.value;
return JaktInternal::ExplicitValue(({ Optional<interpreter::StatementResult> __jakt_var_315; {
interpreter::StatementResult const result = TRY((((*this).execute_expression(expr,new_scope))));
__jakt_var_315 = JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<interpreter::StatementResult, ErrorOr<interpreter::StatementResult>>{
auto&& __jakt_match_variant = result;
switch(__jakt_match_variant.index()) {
case 2: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename interpreter::StatementResult::Yield>();
types::Value const& value = __jakt_match_value.value;
return JaktInternal::ExplicitValue( interpreter::StatementResult { typename interpreter::StatementResult::JustValue(value) } );
};/*case end*/
case 3: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename interpreter::StatementResult::Continue>();
return JaktInternal::ExplicitValue(result);
};/*case end*/
case 4: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename interpreter::StatementResult::Break>();
return JaktInternal::ExplicitValue(result);
};/*case end*/
case 5: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename interpreter::StatementResult::JustValue>();
return JaktInternal::ExplicitValue(result);
};/*case end*/
case 0: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename interpreter::StatementResult::Return>();
return JaktInternal::ExplicitValue(result);
};/*case end*/
case 1: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename interpreter::StatementResult::Throw>();
return JaktInternal::ExplicitValue(result);
};/*case end*/
default: VERIFY_NOT_REACHED();}/*switch end*/
}()
)); goto __jakt_label_310;

}
__jakt_label_310:; __jakt_var_315.release_value(); }));
};/*case end*/
case 1: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::CheckedMatchBody::Block>();
types::CheckedBlock const& block = __jakt_match_value.value;
return JaktInternal::ExplicitValue(({ Optional<interpreter::StatementResult> __jakt_var_316; {
interpreter::StatementResult const result = TRY((((*this).execute_block(block,new_scope,(span.value())))));
__jakt_var_316 = JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<interpreter::StatementResult, ErrorOr<interpreter::StatementResult>>{
auto&& __jakt_match_variant = result;
switch(__jakt_match_variant.index()) {
case 2: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename interpreter::StatementResult::Yield>();
types::Value const& value = __jakt_match_value.value;
return JaktInternal::ExplicitValue( interpreter::StatementResult { typename interpreter::StatementResult::JustValue(value) } );
};/*case end*/
case 3: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename interpreter::StatementResult::Continue>();
return JaktInternal::ExplicitValue(result);
};/*case end*/
case 4: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename interpreter::StatementResult::Break>();
return JaktInternal::ExplicitValue(result);
};/*case end*/
case 5: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename interpreter::StatementResult::JustValue>();
return JaktInternal::ExplicitValue(result);
};/*case end*/
case 0: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename interpreter::StatementResult::Return>();
return JaktInternal::ExplicitValue(result);
};/*case end*/
case 1: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename interpreter::StatementResult::Throw>();
return JaktInternal::ExplicitValue(result);
};/*case end*/
default: VERIFY_NOT_REACHED();}/*switch end*/
}()
)); goto __jakt_label_311;

}
__jakt_label_311:; __jakt_var_316.release_value(); }));
};/*case end*/
default: VERIFY_NOT_REACHED();}/*switch end*/
}()
)); goto __jakt_label_309;

}
__jakt_label_309:; __jakt_var_313.release_value(); }));
};/*case end*/
}/*switch end*/
}()
)); goto __jakt_label_305;

}
__jakt_label_305:; __jakt_var_308.release_value(); }));
};/*case end*/
case 18: {
auto&& __jakt_match_value = __jakt_match_variant.template get<types::CheckedExpression::EnumVariantArg>();NonnullRefPtr<typename types::CheckedExpression> const& expr = __jakt_match_value.expr;
types::CheckedEnumVariantBinding const& arg = __jakt_match_value.arg;
types::CheckedEnumVariant const& enum_variant = __jakt_match_value.enum_variant;
utility::Span const& span = __jakt_match_value.span;
return JaktInternal::ExplicitValue(({ Optional<interpreter::StatementResult> __jakt_var_317; {
types::Value const value = JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<types::Value, ErrorOr<interpreter::StatementResult>>{
auto&& __jakt_match_variant = TRY((((*this).execute_expression(expr,scope))));
switch(__jakt_match_variant.index()) {
case 5: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename interpreter::StatementResult::JustValue>();
types::Value const& value = __jakt_match_value.value;
return JaktInternal::ExplicitValue(value);
};/*case end*/
case 0: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename interpreter::StatementResult::Return>();
types::Value const& value = __jakt_match_value.value;
{
return ( interpreter::StatementResult { typename interpreter::StatementResult::Return(value) } );
}
};/*case end*/
case 1: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename interpreter::StatementResult::Throw>();
types::Value const& value = __jakt_match_value.value;
{
return ( interpreter::StatementResult { typename interpreter::StatementResult::Throw(value) } );
}
};/*case end*/
case 3: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename interpreter::StatementResult::Continue>();
{
return ( interpreter::StatementResult { typename interpreter::StatementResult::Continue() } );
}
};/*case end*/
case 4: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename interpreter::StatementResult::Break>();
{
return ( interpreter::StatementResult { typename interpreter::StatementResult::Break() } );
}
};/*case end*/
case 2: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename interpreter::StatementResult::Yield>();
{
utility::panic(Jakt::DeprecatedString("Invalid control flow"sv));
}
};/*case end*/
default: VERIFY_NOT_REACHED();}/*switch end*/
}()
));
__jakt_var_317 = JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<interpreter::StatementResult, ErrorOr<interpreter::StatementResult>>{
auto&& __jakt_match_variant = *((value).impl);
switch(__jakt_match_variant.index()) {
case 19: {
auto&& __jakt_match_value = __jakt_match_variant.template get<types::ValueImpl::Enum>();JaktInternal::DynamicArray<types::Value> const& fields = __jakt_match_value.fields;
types::EnumId const& enum_id = __jakt_match_value.enum_id;
types::FunctionId const& constructor = __jakt_match_value.constructor;
return JaktInternal::ExplicitValue(({ Optional<interpreter::StatementResult> __jakt_var_318; {
JaktInternal::Optional<types::CheckedEnumVariant> found_variant = JaktInternal::OptionalNone();
{
JaktInternal::ArrayIterator<types::CheckedEnumVariant> _magic = ((((((((*this).program))->get_enum(enum_id))).variants)).iterator());
for (;;){
JaktInternal::Optional<types::CheckedEnumVariant> _magic_value = ((_magic).next());
if ((!(((_magic_value).has_value())))){
break;
}
types::CheckedEnumVariant variant = (_magic_value.value());
{
if ((((variant).name()) == ((enum_variant).name()))){
(found_variant = variant);
break;
}
}

}
}

__jakt_var_318 = JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<interpreter::StatementResult, ErrorOr<interpreter::StatementResult>>{
auto&& __jakt_match_variant = (found_variant.value());
switch(__jakt_match_variant.index()) {
case 1: {
auto&& __jakt_match_value = __jakt_match_variant.template get<types::CheckedEnumVariant::Typed>();return JaktInternal::ExplicitValue( interpreter::StatementResult { typename interpreter::StatementResult::JustValue(((fields)[static_cast<i64>(0LL)])) } );
};/*case end*/
case 3: {
auto&& __jakt_match_value = __jakt_match_variant.template get<types::CheckedEnumVariant::StructLike>();JaktInternal::DynamicArray<types::VarId> const& variant_fields = __jakt_match_value.fields;
return JaktInternal::ExplicitValue(({ Optional<interpreter::StatementResult> __jakt_var_319; {
i64 i = static_cast<i64>(0LL);
{
JaktInternal::ArrayIterator<types::VarId> _magic = ((variant_fields).iterator());
for (;;){
JaktInternal::Optional<types::VarId> _magic_value = ((_magic).next());
if ((!(((_magic_value).has_value())))){
break;
}
types::VarId var_id = (_magic_value.value());
{
NonnullRefPtr<types::CheckedVariable> const field = ((((*this).program))->get_variable(var_id));
DeprecatedString const matched_name = ((arg).name).value_or_lazy_evaluated([&] { return ((arg).binding); });
if ((matched_name == ((field)->name))){
break;
}
({auto& _jakt_ref = i;_jakt_ref = JaktInternal::checked_add<i64>(_jakt_ref, static_cast<i64>(1LL));});
}

}
}

__jakt_var_319 =  interpreter::StatementResult { typename interpreter::StatementResult::JustValue(((fields)[i])) } ; goto __jakt_label_314;

}
__jakt_label_314:; __jakt_var_319.release_value(); }));
};/*case end*/
default: {
return JaktInternal::ExplicitValue( interpreter::StatementResult { typename interpreter::StatementResult::JustValue(types::Value(TRY((types::ValueImpl::template create<typename types::ValueImpl::Void>())),span)) } );
};/*case end*/
}/*switch end*/
}()
)); goto __jakt_label_313;

}
__jakt_label_313:; __jakt_var_318.release_value(); }));
};/*case end*/
default: {
{
TRY((((*this).error(TRY((__jakt_format(Jakt::DeprecatedString("Value matches cannot have enum variant arms (matching on {})"sv),((value).type_name())))),span))));
return Error::from_errno((infallible_integer_cast<i32>((interpreter::InterpretError::InvalidType))));
}
};/*case end*/
}/*switch end*/
}()
)); goto __jakt_label_312;

}
__jakt_label_312:; __jakt_var_317.release_value(); }));
};/*case end*/
case 7: {
auto&& __jakt_match_value = __jakt_match_variant.template get<types::CheckedExpression::JaktTuple>();JaktInternal::DynamicArray<NonnullRefPtr<typename types::CheckedExpression>> const& vals = __jakt_match_value.vals;
utility::Span const& span = __jakt_match_value.span;
types::TypeId const& type_id = __jakt_match_value.type_id;
return JaktInternal::ExplicitValue(({ Optional<interpreter::StatementResult> __jakt_var_320; {
JaktInternal::DynamicArray<types::Value> fields = (TRY((DynamicArray<types::Value>::create_with({}))));
{
JaktInternal::ArrayIterator<NonnullRefPtr<typename types::CheckedExpression>> _magic = ((vals).iterator());
for (;;){
JaktInternal::Optional<NonnullRefPtr<typename types::CheckedExpression>> _magic_value = ((_magic).next());
if ((!(((_magic_value).has_value())))){
break;
}
NonnullRefPtr<typename types::CheckedExpression> val = (_magic_value.value());
{
types::Value const value = JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_AT_LOOP(([&]() -> JaktInternal::ExplicitValueOrControlFlow<types::Value, ErrorOr<interpreter::StatementResult>>{
auto&& __jakt_match_variant = TRY((((*this).execute_expression(val,scope))));
switch(__jakt_match_variant.index()) {
case 5: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename interpreter::StatementResult::JustValue>();
types::Value const& value = __jakt_match_value.value;
return JaktInternal::ExplicitValue(value);
};/*case end*/
case 0: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename interpreter::StatementResult::Return>();
types::Value const& value = __jakt_match_value.value;
{
return ( interpreter::StatementResult { typename interpreter::StatementResult::Return(value) } );
}
};/*case end*/
case 1: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename interpreter::StatementResult::Throw>();
types::Value const& value = __jakt_match_value.value;
{
return ( interpreter::StatementResult { typename interpreter::StatementResult::Throw(value) } );
}
};/*case end*/
case 3: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename interpreter::StatementResult::Continue>();
{
return ( interpreter::StatementResult { typename interpreter::StatementResult::Continue() } );
}
};/*case end*/
case 4: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename interpreter::StatementResult::Break>();
{
return ( interpreter::StatementResult { typename interpreter::StatementResult::Break() } );
}
};/*case end*/
case 2: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename interpreter::StatementResult::Yield>();
{
utility::panic(Jakt::DeprecatedString("Invalid control flow"sv));
}
};/*case end*/
default: VERIFY_NOT_REACHED();}/*switch end*/
}()
));
TRY((((fields).push(value))));
}

}
}

__jakt_var_320 =  interpreter::StatementResult { typename interpreter::StatementResult::JustValue(types::Value(TRY((types::ValueImpl::template create<typename types::ValueImpl::JaktTuple>(fields,type_id))),span)) } ; goto __jakt_label_315;

}
__jakt_label_315:; __jakt_var_320.release_value(); }));
};/*case end*/
case 10: {
auto&& __jakt_match_value = __jakt_match_variant.template get<types::CheckedExpression::JaktSet>();JaktInternal::DynamicArray<NonnullRefPtr<typename types::CheckedExpression>> const& vals = __jakt_match_value.vals;
utility::Span const& span = __jakt_match_value.span;
types::TypeId const& type_id = __jakt_match_value.type_id;
return JaktInternal::ExplicitValue(({ Optional<interpreter::StatementResult> __jakt_var_321; {
JaktInternal::DynamicArray<types::Value> values = (TRY((DynamicArray<types::Value>::create_with({}))));
{
JaktInternal::ArrayIterator<NonnullRefPtr<typename types::CheckedExpression>> _magic = ((vals).iterator());
for (;;){
JaktInternal::Optional<NonnullRefPtr<typename types::CheckedExpression>> _magic_value = ((_magic).next());
if ((!(((_magic_value).has_value())))){
break;
}
NonnullRefPtr<typename types::CheckedExpression> v = (_magic_value.value());
{
types::Value const val = JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_AT_LOOP(([&]() -> JaktInternal::ExplicitValueOrControlFlow<types::Value, ErrorOr<interpreter::StatementResult>>{
auto&& __jakt_match_variant = TRY((((*this).execute_expression(v,scope))));
switch(__jakt_match_variant.index()) {
case 0: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename interpreter::StatementResult::Return>();
types::Value const& value = __jakt_match_value.value;
{
return ( interpreter::StatementResult { typename interpreter::StatementResult::Return(value) } );
}
};/*case end*/
case 1: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename interpreter::StatementResult::Throw>();
types::Value const& value = __jakt_match_value.value;
{
return ( interpreter::StatementResult { typename interpreter::StatementResult::Throw(value) } );
}
};/*case end*/
case 5: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename interpreter::StatementResult::JustValue>();
types::Value const& value = __jakt_match_value.value;
return JaktInternal::ExplicitValue(value);
};/*case end*/
case 3: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename interpreter::StatementResult::Continue>();
{
return ( interpreter::StatementResult { typename interpreter::StatementResult::Continue() } );
}
};/*case end*/
case 4: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename interpreter::StatementResult::Break>();
{
return ( interpreter::StatementResult { typename interpreter::StatementResult::Break() } );
}
};/*case end*/
case 2: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename interpreter::StatementResult::Yield>();
types::Value const& expr = __jakt_match_value.value;
{
utility::panic(Jakt::DeprecatedString("Invalid control flow"sv));
}
};/*case end*/
default: VERIFY_NOT_REACHED();}/*switch end*/
}()
));
TRY((((values).push(val))));
}

}
}

__jakt_var_321 =  interpreter::StatementResult { typename interpreter::StatementResult::JustValue(types::Value(TRY((types::ValueImpl::template create<typename types::ValueImpl::JaktSet>(values,type_id))),span)) } ; goto __jakt_label_316;

}
__jakt_label_316:; __jakt_var_321.release_value(); }));
};/*case end*/
case 27: {
auto&& __jakt_match_value = __jakt_match_variant.template get<types::CheckedExpression::Function>();JaktInternal::DynamicArray<types::CheckedCapture> const& captures = __jakt_match_value.captures;
JaktInternal::DynamicArray<types::CheckedParameter> const& params = __jakt_match_value.params;
types::TypeId const& return_type_id = __jakt_match_value.return_type_id;
types::TypeId const& type_id = __jakt_match_value.type_id;
types::CheckedBlock const& block = __jakt_match_value.block;
utility::Span const& span = __jakt_match_value.span;
bool const& can_throw = __jakt_match_value.can_throw;
return JaktInternal::ExplicitValue(({ Optional<interpreter::StatementResult> __jakt_var_322; {
JaktInternal::Dictionary<DeprecatedString,types::Value> resolved_captures = (TRY((Dictionary<DeprecatedString, types::Value>::create_with_entries({}))));
{
JaktInternal::ArrayIterator<types::CheckedCapture> _magic = ((captures).iterator());
for (;;){
JaktInternal::Optional<types::CheckedCapture> _magic_value = ((_magic).next());
if ((!(((_magic_value).has_value())))){
break;
}
types::CheckedCapture capture = (_magic_value.value());
{
DeprecatedString const name = ((capture).name());
if (((capture).index() == 0 /* ByValue */)){
TRY((((resolved_captures).set(name,TRY((((scope)->must_get(name))))))));
}
else {
TRY((((*this).error(TRY((__jakt_format(Jakt::DeprecatedString("Cannot capture by reference in a comptime function (nyi)"sv)))),span))));
return Error::from_errno((infallible_integer_cast<i32>((interpreter::InterpretError::Unimplemented))));
}

}

}
}

types::GenericInferences const type_map = TRY((((scope)->type_map_for_substitution())));
JaktInternal::Dictionary<DeprecatedString,JaktInternal::Tuple<types::TypeId,JaktInternal::Optional<NonnullRefPtr<typename types::CheckedExpression>>>> resolved_params = (TRY((Dictionary<DeprecatedString, JaktInternal::Tuple<types::TypeId,JaktInternal::Optional<NonnullRefPtr<typename types::CheckedExpression>>>>::create_with_entries({}))));
JaktInternal::DynamicArray<types::CheckedParameter> checked_params = (TRY((DynamicArray<types::CheckedParameter>::create_with({}))));
{
JaktInternal::ArrayIterator<types::CheckedParameter> _magic = ((params).iterator());
for (;;){
JaktInternal::Optional<types::CheckedParameter> _magic_value = ((_magic).next());
if ((!(((_magic_value).has_value())))){
break;
}
types::CheckedParameter param = (_magic_value.value());
{
types::TypeId const param_type_id = TRY((((((*this).program))->substitute_typevars_in_type(((((param).variable))->type_id),type_map,((((((param).variable))->type_id)).module)))));
TRY((((resolved_params).set(((((param).variable))->name),(Tuple{param_type_id, ((param).default_value)})))));
TRY((((checked_params).push(types::CheckedParameter(((param).requires_label),TRY((types::CheckedVariable::create(((((param).variable))->name),param_type_id,((((param).variable))->is_mutable),((((param).variable))->definition_span),((((param).variable))->type_span),((((param).variable))->visibility),JaktInternal::OptionalNone()))),((param).default_value))))));
}

}
}

__jakt_var_322 =  interpreter::StatementResult { typename interpreter::StatementResult::JustValue(types::Value(TRY((types::ValueImpl::template create<typename types::ValueImpl::Function>(resolved_captures,resolved_params,TRY((((((*this).program))->substitute_typevars_in_type(return_type_id,type_map,((return_type_id).module))))),TRY((((((*this).program))->substitute_typevars_in_type(type_id,type_map,((type_id).module))))),block,can_throw,checked_params))),span)) } ; goto __jakt_label_317;

}
__jakt_label_317:; __jakt_var_322.release_value(); }));
};/*case end*/
case 29: {
auto&& __jakt_match_value = __jakt_match_variant.template get<types::CheckedExpression::TryBlock>();NonnullRefPtr<typename types::CheckedStatement> const& stmt = __jakt_match_value.stmt;
types::CheckedBlock const& catch_block = __jakt_match_value.catch_block;
DeprecatedString const& error_name = __jakt_match_value.error_name;
utility::Span const& span = __jakt_match_value.span;
return JaktInternal::ExplicitValue(({ Optional<interpreter::StatementResult> __jakt_var_323; {
JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<void, ErrorOr<interpreter::StatementResult>>{
auto&& __jakt_match_variant = TRY((((*this).execute_statement(stmt,scope,span))));
switch(__jakt_match_variant.index()) {
case 5: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename interpreter::StatementResult::JustValue>();
{
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 1: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename interpreter::StatementResult::Throw>();
types::Value const& value = __jakt_match_value.value;
{
NonnullRefPtr<interpreter::InterpreterScope> catch_scope = TRY((interpreter::InterpreterScope::create((TRY((Dictionary<DeprecatedString, types::Value>::create_with_entries({})))),scope,(TRY((Dictionary<DeprecatedString, types::TypeId>::create_with_entries({})))))));
ScopeGuard __jakt_var_324([&] {
MUST((((catch_scope)->perform_defers(*this,span))));
});
TRY((((((catch_scope)->bindings)).set(error_name,value))));
interpreter::StatementResult const result = TRY((((*this).execute_block(catch_block,catch_scope,span))));
JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<void, ErrorOr<interpreter::StatementResult>>{
auto&& __jakt_match_variant = result;
switch(__jakt_match_variant.index()) {
case 3: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename interpreter::StatementResult::Continue>();
{
return (result);
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 4: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename interpreter::StatementResult::Break>();
{
return (result);
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 0: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename interpreter::StatementResult::Return>();
{
return (result);
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 1: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename interpreter::StatementResult::Throw>();
{
return (result);
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
default: {
{
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
}/*switch end*/
}()
));
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 0: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename interpreter::StatementResult::Return>();
types::Value const& value = __jakt_match_value.value;
{
return ( interpreter::StatementResult { typename interpreter::StatementResult::Return(value) } );
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 4: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename interpreter::StatementResult::Break>();
{
return ( interpreter::StatementResult { typename interpreter::StatementResult::Break() } );
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 3: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename interpreter::StatementResult::Continue>();
{
return ( interpreter::StatementResult { typename interpreter::StatementResult::Continue() } );
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 2: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename interpreter::StatementResult::Yield>();
{
utility::panic(Jakt::DeprecatedString("Invalid control flow"sv));
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
default: VERIFY_NOT_REACHED();}/*switch end*/
}()
));
__jakt_var_323 =  interpreter::StatementResult { typename interpreter::StatementResult::JustValue(types::Value(TRY((types::ValueImpl::template create<typename types::ValueImpl::Void>())),span)) } ; goto __jakt_label_318;

}
__jakt_label_318:; __jakt_var_323.release_value(); }));
};/*case end*/
default: {
{
TRY((((*this).error(TRY((__jakt_format(Jakt::DeprecatedString("expression not implemented: {}"sv),expr))),((expr)->span())))));
return Error::from_errno((infallible_integer_cast<i32>((interpreter::InterpretError::Unimplemented))));
}
};/*case end*/
}/*switch end*/
}()
)));
}
}

ErrorOr<interpreter::StatementResult> interpreter::Interpreter::execute_statement(NonnullRefPtr<typename types::CheckedStatement> const statement,NonnullRefPtr<interpreter::InterpreterScope> scope,utility::Span const call_span) {
{
JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<void, ErrorOr<interpreter::StatementResult>>{
auto&& __jakt_match_variant = *statement;
switch(__jakt_match_variant.index()) {
case 0: {
auto&& __jakt_match_value = __jakt_match_variant.template get<types::CheckedStatement::Expression>();NonnullRefPtr<typename types::CheckedExpression> const& expr = __jakt_match_value.expr;
{
return (TRY((((*this).execute_expression(expr,scope)))));
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 1: {
auto&& __jakt_match_value = __jakt_match_variant.template get<types::CheckedStatement::Defer>();NonnullRefPtr<typename types::CheckedStatement> const& statement = __jakt_match_value.statement;
{
TRY((((scope)->defer_statement(statement))));
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 2: {
auto&& __jakt_match_value = __jakt_match_variant.template get<types::CheckedStatement::DestructuringAssignment>();JaktInternal::DynamicArray<NonnullRefPtr<typename types::CheckedStatement>> const& vars = __jakt_match_value.vars;
NonnullRefPtr<typename types::CheckedStatement> const& var_decl = __jakt_match_value.var_decl;
{
if (((var_decl)->index() == 3 /* VarDecl */)){
types::VarId const var_id = ((var_decl)->get<types::CheckedStatement::VarDecl>()).var_id;
NonnullRefPtr<typename types::CheckedExpression> const init = ((var_decl)->get<types::CheckedStatement::VarDecl>()).init;
JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<void, ErrorOr<interpreter::StatementResult>>{
auto&& __jakt_match_variant = TRY((((*this).execute_expression(init,scope))));
switch(__jakt_match_variant.index()) {
case 0: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename interpreter::StatementResult::Return>();
types::Value const& value = __jakt_match_value.value;
{
return ( interpreter::StatementResult { typename interpreter::StatementResult::Return(value) } );
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 1: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename interpreter::StatementResult::Throw>();
types::Value const& value = __jakt_match_value.value;
{
return ( interpreter::StatementResult { typename interpreter::StatementResult::Throw(value) } );
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 5: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename interpreter::StatementResult::JustValue>();
types::Value const& var_value = __jakt_match_value.value;
{
TRY(((scope)->bindings).set(((((((*this).program))->get_variable(var_id)))->name), var_value));
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 3: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename interpreter::StatementResult::Continue>();
{
return ( interpreter::StatementResult { typename interpreter::StatementResult::Continue() } );
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 4: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename interpreter::StatementResult::Break>();
{
return ( interpreter::StatementResult { typename interpreter::StatementResult::Break() } );
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 2: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename interpreter::StatementResult::Yield>();
{
utility::panic(Jakt::DeprecatedString("Invalid control flow"sv));
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
default: VERIFY_NOT_REACHED();}/*switch end*/
}()
));
{
JaktInternal::ArrayIterator<NonnullRefPtr<typename types::CheckedStatement>> _magic = ((vars).iterator());
for (;;){
JaktInternal::Optional<NonnullRefPtr<typename types::CheckedStatement>> _magic_value = ((_magic).next());
if ((!(((_magic_value).has_value())))){
break;
}
NonnullRefPtr<typename types::CheckedStatement> var = (_magic_value.value());
{
if (((var)->index() == 3 /* VarDecl */)){
types::VarId const var_id = ((var)->get<types::CheckedStatement::VarDecl>()).var_id;
NonnullRefPtr<typename types::CheckedExpression> const init = ((var)->get<types::CheckedStatement::VarDecl>()).init;
JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_AT_LOOP(([&]() -> JaktInternal::ExplicitValueOrControlFlow<void, ErrorOr<interpreter::StatementResult>>{
auto&& __jakt_match_variant = TRY((((*this).execute_expression(init,scope))));
switch(__jakt_match_variant.index()) {
case 0: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename interpreter::StatementResult::Return>();
types::Value const& value = __jakt_match_value.value;
{
return ( interpreter::StatementResult { typename interpreter::StatementResult::Return(value) } );
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 1: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename interpreter::StatementResult::Throw>();
types::Value const& value = __jakt_match_value.value;
{
return ( interpreter::StatementResult { typename interpreter::StatementResult::Throw(value) } );
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 5: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename interpreter::StatementResult::JustValue>();
types::Value const& var_value = __jakt_match_value.value;
{
TRY(((scope)->bindings).set(((((((*this).program))->get_variable(var_id)))->name), var_value));
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 3: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename interpreter::StatementResult::Continue>();
{
return ( interpreter::StatementResult { typename interpreter::StatementResult::Continue() } );
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 4: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename interpreter::StatementResult::Break>();
{
return ( interpreter::StatementResult { typename interpreter::StatementResult::Break() } );
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 2: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename interpreter::StatementResult::Yield>();
{
utility::panic(Jakt::DeprecatedString("Invalid control flow"sv));
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
default: VERIFY_NOT_REACHED();}/*switch end*/
}()
));
}
else {
utility::panic(Jakt::DeprecatedString("expected vardecl"sv));
}

}

}
}

}
else {
utility::panic(Jakt::DeprecatedString("expected vardecl"sv));
}

}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 3: {
auto&& __jakt_match_value = __jakt_match_variant.template get<types::CheckedStatement::VarDecl>();types::VarId const& var_id = __jakt_match_value.var_id;
NonnullRefPtr<typename types::CheckedExpression> const& init = __jakt_match_value.init;
utility::Span const& span = __jakt_match_value.span;
{
JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<void, ErrorOr<interpreter::StatementResult>>{
auto&& __jakt_match_variant = TRY((((*this).execute_expression(init,scope))));
switch(__jakt_match_variant.index()) {
case 0: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename interpreter::StatementResult::Return>();
types::Value const& value = __jakt_match_value.value;
{
return ( interpreter::StatementResult { typename interpreter::StatementResult::Return(value) } );
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 1: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename interpreter::StatementResult::Throw>();
types::Value const& value = __jakt_match_value.value;
{
return ( interpreter::StatementResult { typename interpreter::StatementResult::Throw(value) } );
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 5: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename interpreter::StatementResult::JustValue>();
types::Value const& var_value = __jakt_match_value.value;
{
TRY(((scope)->bindings).set(((((((*this).program))->get_variable(var_id)))->name), var_value));
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 3: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename interpreter::StatementResult::Continue>();
{
return ( interpreter::StatementResult { typename interpreter::StatementResult::Continue() } );
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 4: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename interpreter::StatementResult::Break>();
{
return ( interpreter::StatementResult { typename interpreter::StatementResult::Break() } );
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 2: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename interpreter::StatementResult::Yield>();
{
utility::panic(Jakt::DeprecatedString("Invalid control flow"sv));
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
default: VERIFY_NOT_REACHED();}/*switch end*/
}()
));
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 4: {
auto&& __jakt_match_value = __jakt_match_variant.template get<types::CheckedStatement::If>();NonnullRefPtr<typename types::CheckedExpression> const& condition = __jakt_match_value.condition;
types::CheckedBlock const& then_block = __jakt_match_value.then_block;
JaktInternal::Optional<NonnullRefPtr<typename types::CheckedStatement>> const& else_statement = __jakt_match_value.else_statement;
utility::Span const& span = __jakt_match_value.span;
{
bool const cond = JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<bool, ErrorOr<interpreter::StatementResult>>{
auto&& __jakt_match_variant = TRY((((*this).execute_expression(condition,scope))));
switch(__jakt_match_variant.index()) {
case 5: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename interpreter::StatementResult::JustValue>();
types::Value const& value = __jakt_match_value.value;
return JaktInternal::ExplicitValue(JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<bool, ErrorOr<interpreter::StatementResult>>{
auto&& __jakt_match_variant = *((value).impl);
switch(__jakt_match_variant.index()) {
case 1: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::Bool>();
bool const& x = __jakt_match_value.value;
return JaktInternal::ExplicitValue(x);
};/*case end*/
default: {
{
TRY((((*this).error(TRY((__jakt_format(Jakt::DeprecatedString("if condition must be a boolean, but got {}"sv),((value).impl)))),span))));
return Error::from_errno((infallible_integer_cast<i32>((interpreter::InterpretError::InvalidType))));
}
};/*case end*/
}/*switch end*/
}()
)));
};/*case end*/
case 0: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename interpreter::StatementResult::Return>();
types::Value const& value = __jakt_match_value.value;
{
return ( interpreter::StatementResult { typename interpreter::StatementResult::Return(value) } );
}
};/*case end*/
case 1: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename interpreter::StatementResult::Throw>();
types::Value const& value = __jakt_match_value.value;
{
return ( interpreter::StatementResult { typename interpreter::StatementResult::Throw(value) } );
}
};/*case end*/
case 3: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename interpreter::StatementResult::Continue>();
{
return ( interpreter::StatementResult { typename interpreter::StatementResult::Continue() } );
}
};/*case end*/
case 4: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename interpreter::StatementResult::Break>();
{
return ( interpreter::StatementResult { typename interpreter::StatementResult::Break() } );
}
};/*case end*/
case 2: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename interpreter::StatementResult::Yield>();
{
utility::panic(Jakt::DeprecatedString("Invalid control flow"sv));
}
};/*case end*/
default: VERIFY_NOT_REACHED();}/*switch end*/
}()
));
JaktInternal::Optional<types::CheckedBlock> const block = JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<JaktInternal::Optional<types::CheckedBlock>,ErrorOr<interpreter::StatementResult>>{
auto __jakt_enum_value = (cond);
if (__jakt_enum_value == true) {
return JaktInternal::ExplicitValue(static_cast<JaktInternal::Optional<types::CheckedBlock>>(then_block));
}
else {
return JaktInternal::ExplicitValue(JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<JaktInternal::Optional<types::CheckedBlock>,ErrorOr<interpreter::StatementResult>>{
auto __jakt_enum_value = (((else_statement).has_value()));
if (__jakt_enum_value == true) {
return JaktInternal::ExplicitValue(static_cast<JaktInternal::Optional<types::CheckedBlock>>(types::CheckedBlock((TRY((DynamicArray<NonnullRefPtr<typename types::CheckedStatement>>::create_with({(else_statement.value())})))),((then_block).scope_id), types::BlockControlFlow { typename types::BlockControlFlow::MayReturn() } ,JaktInternal::OptionalNone(),false)));
}
else {
return JaktInternal::ExplicitValue(JaktInternal::OptionalNone());
}
}()))
);
}
}()))
;
if (((block).has_value())){
return (JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<interpreter::StatementResult, ErrorOr<interpreter::StatementResult>>{
auto&& __jakt_match_variant = TRY((((*this).execute_block((block.value()),scope,span))));
switch(__jakt_match_variant.index()) {
case 0: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename interpreter::StatementResult::Return>();
types::Value const& value = __jakt_match_value.value;
return JaktInternal::ExplicitValue( interpreter::StatementResult { typename interpreter::StatementResult::Return(value) } );
};/*case end*/
case 1: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename interpreter::StatementResult::Throw>();
types::Value const& value = __jakt_match_value.value;
return JaktInternal::ExplicitValue( interpreter::StatementResult { typename interpreter::StatementResult::Throw(value) } );
};/*case end*/
case 5: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename interpreter::StatementResult::JustValue>();
return JaktInternal::ExplicitValue( interpreter::StatementResult { typename interpreter::StatementResult::JustValue(types::Value(TRY((types::ValueImpl::template create<typename types::ValueImpl::Void>())),span)) } );
};/*case end*/
case 3: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename interpreter::StatementResult::Continue>();
return JaktInternal::ExplicitValue( interpreter::StatementResult { typename interpreter::StatementResult::Continue() } );
};/*case end*/
case 4: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename interpreter::StatementResult::Break>();
return JaktInternal::ExplicitValue( interpreter::StatementResult { typename interpreter::StatementResult::Break() } );
};/*case end*/
case 2: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename interpreter::StatementResult::Yield>();
{
utility::panic(Jakt::DeprecatedString("Invalid control flow"sv));
}
};/*case end*/
default: VERIFY_NOT_REACHED();}/*switch end*/
}()
)));
}
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 5: {
auto&& __jakt_match_value = __jakt_match_variant.template get<types::CheckedStatement::Block>();types::CheckedBlock const& block = __jakt_match_value.block;
utility::Span const& span = __jakt_match_value.span;
{
NonnullRefPtr<interpreter::InterpreterScope> new_scope = TRY((interpreter::InterpreterScope::create((TRY((Dictionary<DeprecatedString, types::Value>::create_with_entries({})))),scope,(TRY((Dictionary<DeprecatedString, types::TypeId>::create_with_entries({})))))));
ScopeGuard __jakt_var_325([&] {
MUST((((new_scope)->perform_defers(*this,span))));
});
return (TRY((((*this).execute_block(block,new_scope,span)))));
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 6: {
auto&& __jakt_match_value = __jakt_match_variant.template get<types::CheckedStatement::Loop>();types::CheckedBlock const& block = __jakt_match_value.block;
utility::Span const& span = __jakt_match_value.span;
{
for (;;){
JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_AT_LOOP(([&]() -> JaktInternal::ExplicitValueOrControlFlow<void, ErrorOr<interpreter::StatementResult>>{
auto&& __jakt_match_variant = TRY((((*this).execute_block(block,scope,span))));
switch(__jakt_match_variant.index()) {
case 0: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename interpreter::StatementResult::Return>();
types::Value const& value = __jakt_match_value.value;
{
return ( interpreter::StatementResult { typename interpreter::StatementResult::Return(value) } );
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 1: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename interpreter::StatementResult::Throw>();
types::Value const& value = __jakt_match_value.value;
{
return ( interpreter::StatementResult { typename interpreter::StatementResult::Throw(value) } );
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 3: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename interpreter::StatementResult::Continue>();
{
return JaktInternal::LoopContinue{};
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 4: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename interpreter::StatementResult::Break>();
{
return JaktInternal::LoopBreak{};
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 5: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename interpreter::StatementResult::JustValue>();
{
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 2: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename interpreter::StatementResult::Yield>();
{
utility::panic(Jakt::DeprecatedString("Invalid control flow"sv));
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
default: VERIFY_NOT_REACHED();}/*switch end*/
}()
));
}
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 7: {
auto&& __jakt_match_value = __jakt_match_variant.template get<types::CheckedStatement::While>();NonnullRefPtr<typename types::CheckedExpression> const& condition = __jakt_match_value.condition;
types::CheckedBlock const& block = __jakt_match_value.block;
utility::Span const& span = __jakt_match_value.span;
{
for (;;){
JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_AT_LOOP(([&]() -> JaktInternal::ExplicitValueOrControlFlow<void, ErrorOr<interpreter::StatementResult>>{
auto&& __jakt_match_variant = TRY((((*this).execute_expression(condition,scope))));
switch(__jakt_match_variant.index()) {
case 0: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename interpreter::StatementResult::Return>();
types::Value const& value = __jakt_match_value.value;
{
return ( interpreter::StatementResult { typename interpreter::StatementResult::Return(value) } );
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 1: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename interpreter::StatementResult::Throw>();
types::Value const& value = __jakt_match_value.value;
{
return ( interpreter::StatementResult { typename interpreter::StatementResult::Throw(value) } );
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 3: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename interpreter::StatementResult::Continue>();
{
return ( interpreter::StatementResult { typename interpreter::StatementResult::Continue() } );
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 4: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename interpreter::StatementResult::Break>();
{
return ( interpreter::StatementResult { typename interpreter::StatementResult::Break() } );
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 5: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename interpreter::StatementResult::JustValue>();
types::Value const& x = __jakt_match_value.value;
{
if (((((x).impl))->index() == 1 /* Bool */)){
bool const cond = ((((x).impl))->get<types::ValueImpl::Bool>()).value;
if ((!(cond))){
return JaktInternal::LoopBreak{};
}
}
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 2: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename interpreter::StatementResult::Yield>();
{
utility::panic(Jakt::DeprecatedString("Invalid control flow"sv));
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
default: VERIFY_NOT_REACHED();}/*switch end*/
}()
));
JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_AT_LOOP(([&]() -> JaktInternal::ExplicitValueOrControlFlow<void, ErrorOr<interpreter::StatementResult>>{
auto&& __jakt_match_variant = TRY((((*this).execute_block(block,scope,span))));
switch(__jakt_match_variant.index()) {
case 0: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename interpreter::StatementResult::Return>();
types::Value const& value = __jakt_match_value.value;
{
return ( interpreter::StatementResult { typename interpreter::StatementResult::Return(value) } );
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 1: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename interpreter::StatementResult::Throw>();
types::Value const& value = __jakt_match_value.value;
{
return ( interpreter::StatementResult { typename interpreter::StatementResult::Throw(value) } );
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 3: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename interpreter::StatementResult::Continue>();
{
return JaktInternal::LoopContinue{};
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 4: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename interpreter::StatementResult::Break>();
{
return JaktInternal::LoopBreak{};
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 5: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename interpreter::StatementResult::JustValue>();
{
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 2: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename interpreter::StatementResult::Yield>();
{
utility::panic(Jakt::DeprecatedString("Invalid control flow"sv));
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
default: VERIFY_NOT_REACHED();}/*switch end*/
}()
));
}
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 8: {
auto&& __jakt_match_value = __jakt_match_variant.template get<types::CheckedStatement::Return>();JaktInternal::Optional<NonnullRefPtr<typename types::CheckedExpression>> const& val = __jakt_match_value.val;
{
if (((val).has_value())){
return (JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<interpreter::StatementResult, ErrorOr<interpreter::StatementResult>>{
auto&& __jakt_match_variant = TRY((((*this).execute_expression((val.value()),scope))));
switch(__jakt_match_variant.index()) {
case 0: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename interpreter::StatementResult::Return>();
types::Value const& value = __jakt_match_value.value;
return JaktInternal::ExplicitValue( interpreter::StatementResult { typename interpreter::StatementResult::Return(value) } );
};/*case end*/
case 1: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename interpreter::StatementResult::Throw>();
types::Value const& value = __jakt_match_value.value;
return JaktInternal::ExplicitValue( interpreter::StatementResult { typename interpreter::StatementResult::Throw(value) } );
};/*case end*/
case 5: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename interpreter::StatementResult::JustValue>();
types::Value const& value = __jakt_match_value.value;
return JaktInternal::ExplicitValue( interpreter::StatementResult { typename interpreter::StatementResult::Return(value) } );
};/*case end*/
case 3: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename interpreter::StatementResult::Continue>();
return JaktInternal::ExplicitValue( interpreter::StatementResult { typename interpreter::StatementResult::Continue() } );
};/*case end*/
case 4: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename interpreter::StatementResult::Break>();
return JaktInternal::ExplicitValue( interpreter::StatementResult { typename interpreter::StatementResult::Break() } );
};/*case end*/
case 2: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename interpreter::StatementResult::Yield>();
{
utility::panic(Jakt::DeprecatedString("Invalid control flow"sv));
}
};/*case end*/
default: VERIFY_NOT_REACHED();}/*switch end*/
}()
)));
}
return ( interpreter::StatementResult { typename interpreter::StatementResult::Return(types::Value(TRY((types::ValueImpl::template create<typename types::ValueImpl::Void>())),call_span)) } );
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 9: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::CheckedStatement::Break>();
{
return ( interpreter::StatementResult { typename interpreter::StatementResult::Break() } );
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 10: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::CheckedStatement::Continue>();
{
return ( interpreter::StatementResult { typename interpreter::StatementResult::Continue() } );
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 12: {
auto&& __jakt_match_value = __jakt_match_variant.template get<types::CheckedStatement::Yield>();NonnullRefPtr<typename types::CheckedExpression> const& expr = __jakt_match_value.expr;
return (JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<void, ErrorOr<interpreter::StatementResult>>{
auto&& __jakt_match_variant = TRY((((*this).execute_expression(expr,scope))));
switch(__jakt_match_variant.index()) {
case 5: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename interpreter::StatementResult::JustValue>();
types::Value const& value = __jakt_match_value.value;
{
return ( interpreter::StatementResult { typename interpreter::StatementResult::Yield(value) } );
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 1: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename interpreter::StatementResult::Throw>();
types::Value const& value = __jakt_match_value.value;
{
return ( interpreter::StatementResult { typename interpreter::StatementResult::Throw(value) } );
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 0: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename interpreter::StatementResult::Return>();
types::Value const& value = __jakt_match_value.value;
{
return ( interpreter::StatementResult { typename interpreter::StatementResult::Return(value) } );
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 3: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename interpreter::StatementResult::Continue>();
{
return ( interpreter::StatementResult { typename interpreter::StatementResult::Continue() } );
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 4: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename interpreter::StatementResult::Break>();
{
return ( interpreter::StatementResult { typename interpreter::StatementResult::Break() } );
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 2: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename interpreter::StatementResult::Yield>();
{
utility::panic(Jakt::DeprecatedString("Invalid control flow"sv));
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
default: VERIFY_NOT_REACHED();}/*switch end*/
}()
))), JaktInternal::ExplicitValue<void>();
};/*case end*/
case 11: {
auto&& __jakt_match_value = __jakt_match_variant.template get<types::CheckedStatement::Throw>();NonnullRefPtr<typename types::CheckedExpression> const& expr = __jakt_match_value.expr;
return (JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<void, ErrorOr<interpreter::StatementResult>>{
auto&& __jakt_match_variant = TRY((((*this).execute_expression(expr,scope))));
switch(__jakt_match_variant.index()) {
case 0: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename interpreter::StatementResult::Return>();
types::Value const& value = __jakt_match_value.value;
{
return ( interpreter::StatementResult { typename interpreter::StatementResult::Throw(value) } );
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 5: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename interpreter::StatementResult::JustValue>();
types::Value const& value = __jakt_match_value.value;
{
return ( interpreter::StatementResult { typename interpreter::StatementResult::Throw(value) } );
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 1: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename interpreter::StatementResult::Throw>();
types::Value const& value = __jakt_match_value.value;
{
return ( interpreter::StatementResult { typename interpreter::StatementResult::Throw(value) } );
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 3: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename interpreter::StatementResult::Continue>();
{
return ( interpreter::StatementResult { typename interpreter::StatementResult::Continue() } );
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 4: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename interpreter::StatementResult::Break>();
{
return ( interpreter::StatementResult { typename interpreter::StatementResult::Break() } );
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 2: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename interpreter::StatementResult::Yield>();
{
utility::panic(Jakt::DeprecatedString("Invalid control flow"sv));
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
default: VERIFY_NOT_REACHED();}/*switch end*/
}()
))), JaktInternal::ExplicitValue<void>();
};/*case end*/
case 13: {
auto&& __jakt_match_value = __jakt_match_variant.template get<types::CheckedStatement::InlineCpp>();utility::Span const& span = __jakt_match_value.span;
return (TRY((((*this).error(Jakt::DeprecatedString("Cannot run inline cpp at compile time"sv),span))))), JaktInternal::ExplicitValue<void>();
};/*case end*/
case 14: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::CheckedStatement::Garbage>();
utility::Span const& span = __jakt_match_value.value;
return (TRY((((*this).error(Jakt::DeprecatedString("Cannot run invalid statements at compile time"sv),span))))), JaktInternal::ExplicitValue<void>();
};/*case end*/
default: VERIFY_NOT_REACHED();}/*switch end*/
}()
));
return ( interpreter::StatementResult { typename interpreter::StatementResult::JustValue(types::Value(TRY((types::ValueImpl::template create<typename types::ValueImpl::Void>())),call_span)) } );
}
}

ErrorOr<void> interpreter::Interpreter::error_with_hint(DeprecatedString const message,utility::Span const span,DeprecatedString const hint_message,utility::Span const hint_span) {
{
TRY((((((((*this).compiler))->errors)).push( error::JaktError { typename error::JaktError::MessageWithHint(message,span,hint_message,hint_span) } ))));
TRY((((((*this).compiler))->print_errors())));
}
return {};
}

ErrorOr<interpreter::ExecutionResult> interpreter::Interpreter::execute(types::FunctionId const function_to_run_id,JaktInternal::Optional<JaktInternal::DynamicArray<types::ResolvedNamespace>> namespace_,JaktInternal::Optional<types::Value> const this_argument,JaktInternal::DynamicArray<types::Value> const arguments,utility::Span const call_span,JaktInternal::Optional<NonnullRefPtr<interpreter::InterpreterScope>> const invocation_scope) {
{
NonnullRefPtr<types::CheckedFunction> const function_to_run = ((((*this).program))->get_function(function_to_run_id));
TRY((((*this).enter_span(call_span))));
JaktInternal::Optional<types::FunctionId> const old_function_id = ((*this).current_function_id);
(((*this).current_function_id) = function_to_run_id);
ScopeGuard __jakt_var_326([&] {
{
(((*this).current_function_id) = old_function_id);
((*this).leave_span());
}

});
bool is_prelude_function = false;
if (((((function_to_run)->linkage)).index() == 1 /* External */)){
NonnullRefPtr<types::Scope> const function_scope = TRY((((((*this).program))->get_scope(((function_to_run)->function_scope_id)))));
if ((!(TRY((((*this).get_prelude_function(((function_to_run)->function_scope_id)))))))){
TRY((((*this).error(TRY((__jakt_format(Jakt::DeprecatedString("Cannot call external function '{}'"sv),((function_to_run)->name)))),call_span))));
return Error::from_errno((infallible_integer_cast<i32>((interpreter::InterpretError::CallToExternalFunction))));
}
(is_prelude_function = true);
}
if ((((function_to_run)->is_static()) == ((this_argument).has_value()))){
DeprecatedString expected = Jakt::DeprecatedString("did not expect"sv);
if ((!(((function_to_run)->is_static())))){
(expected = Jakt::DeprecatedString("expected"sv));
}
DeprecatedString not_provided = Jakt::DeprecatedString(" not"sv);
if (((this_argument).has_value())){
(not_provided = Jakt::DeprecatedString(""sv));
}
TRY((((((((*this).compiler))->errors)).push( error::JaktError { typename error::JaktError::Message(TRY((__jakt_format(Jakt::DeprecatedString("function call {} a this argument, yet one was{} provided"sv),expected,not_provided))),((function_to_run)->name_span)) } ))));
return Error::from_errno((infallible_integer_cast<i32>((interpreter::InterpretError::InvalidThisArgument))));
}
size_t this_offset = static_cast<size_t>(0ULL);
if (((this_argument).has_value())){
(this_offset = static_cast<size_t>(1ULL));
}
if (((JaktInternal::checked_sub<size_t>(((((function_to_run)->params)).size()),this_offset)) != ((arguments).size()))){
TRY((((*this).error(TRY((__jakt_format(Jakt::DeprecatedString("Function called with wrong number of arguments, expected {} but got {}"sv),((((function_to_run)->params)).size()),((arguments).size())))),call_span))));
return Error::from_errno((infallible_integer_cast<i32>((interpreter::InterpretError::MismatchingArguments))));
}
if (is_prelude_function){
if ((((this_argument).has_value()) && ((!(((namespace_).has_value()))) || (((namespace_.value())).is_empty())))){
JaktInternal::DynamicArray<types::ResolvedNamespace> effective_namespace = (TRY((DynamicArray<types::ResolvedNamespace>::create_with({}))));
JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<void, ErrorOr<interpreter::ExecutionResult>>{
auto&& __jakt_match_variant = *(((this_argument.value())).impl);
switch(__jakt_match_variant.index()) {
case 13: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::JaktString>();
{
JaktInternal::DynamicArray<types::TypeId> const generic_parameters = (TRY((DynamicArray<types::TypeId>::create_with({}))));
TRY((((effective_namespace).push(types::ResolvedNamespace(Jakt::DeprecatedString("String"sv),JaktInternal::OptionalNone(),generic_parameters)))));
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 20: {
auto&& __jakt_match_value = __jakt_match_variant.template get<types::ValueImpl::JaktArray>();types::TypeId const& type_id = __jakt_match_value.type_id;
{
JaktInternal::DynamicArray<types::TypeId> const generic_parameters = JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<JaktInternal::DynamicArray<types::TypeId>, ErrorOr<interpreter::ExecutionResult>>{
auto&& __jakt_match_variant = *((((*this).program))->get_type(type_id));
switch(__jakt_match_variant.index()) {
case 19: {
auto&& __jakt_match_value = __jakt_match_variant.template get<types::Type::GenericInstance>();JaktInternal::DynamicArray<types::TypeId> const& args = __jakt_match_value.args;
return JaktInternal::ExplicitValue(args);
};/*case end*/
default: {
{
TRY((((*this).error(Jakt::DeprecatedString("Attempted to call a prelude function on a non-generic array"sv),call_span))));
return Error::from_errno((infallible_integer_cast<i32>((interpreter::InterpretError::InvalidType))));
}
};/*case end*/
}/*switch end*/
}()
));
TRY((((effective_namespace).push(types::ResolvedNamespace(Jakt::DeprecatedString("Array"sv),JaktInternal::OptionalNone(),generic_parameters)))));
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 21: {
auto&& __jakt_match_value = __jakt_match_variant.template get<types::ValueImpl::JaktDictionary>();types::TypeId const& type_id = __jakt_match_value.type_id;
{
JaktInternal::DynamicArray<types::TypeId> const generic_parameters = JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<JaktInternal::DynamicArray<types::TypeId>, ErrorOr<interpreter::ExecutionResult>>{
auto&& __jakt_match_variant = *((((*this).program))->get_type(type_id));
switch(__jakt_match_variant.index()) {
case 19: {
auto&& __jakt_match_value = __jakt_match_variant.template get<types::Type::GenericInstance>();JaktInternal::DynamicArray<types::TypeId> const& args = __jakt_match_value.args;
return JaktInternal::ExplicitValue(args);
};/*case end*/
default: {
{
TRY((((*this).error(Jakt::DeprecatedString("Attempted to call a prelude function on a non-generic dictionary"sv),call_span))));
return Error::from_errno((infallible_integer_cast<i32>((interpreter::InterpretError::InvalidType))));
}
};/*case end*/
}/*switch end*/
}()
));
TRY((((effective_namespace).push(types::ResolvedNamespace(Jakt::DeprecatedString("Dictionary"sv),JaktInternal::OptionalNone(),generic_parameters)))));
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 22: {
auto&& __jakt_match_value = __jakt_match_variant.template get<types::ValueImpl::JaktSet>();types::TypeId const& type_id = __jakt_match_value.type_id;
{
if (((((((*this).program))->get_type(type_id)))->index() == 19 /* GenericInstance */)){
JaktInternal::DynamicArray<types::TypeId> const generic_parameters = ((((((*this).program))->get_type(type_id)))->get<types::Type::GenericInstance>()).args;
TRY((((effective_namespace).push(types::ResolvedNamespace(Jakt::DeprecatedString("Set"sv),JaktInternal::OptionalNone(),generic_parameters)))));
}
else {
TRY((((*this).error(Jakt::DeprecatedString("Attempted to call a prelude function on a non-generic set"sv),call_span))));
return Error::from_errno((infallible_integer_cast<i32>((interpreter::InterpretError::InvalidType))));
}

}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 17: {
auto&& __jakt_match_value = __jakt_match_variant.template get<types::ValueImpl::Struct>();types::StructId const& struct_id = __jakt_match_value.struct_id;
{
JaktInternal::DynamicArray<types::TypeId> const generic_parameters = (TRY((DynamicArray<types::TypeId>::create_with({}))));
TRY((((effective_namespace).push(types::ResolvedNamespace(((((((*this).program))->get_struct(struct_id))).name),JaktInternal::OptionalNone(),generic_parameters)))));
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 18: {
auto&& __jakt_match_value = __jakt_match_variant.template get<types::ValueImpl::Class>();types::StructId const& struct_id = __jakt_match_value.struct_id;
{
JaktInternal::DynamicArray<types::TypeId> const generic_parameters = (TRY((DynamicArray<types::TypeId>::create_with({}))));
TRY((((effective_namespace).push(types::ResolvedNamespace(((((((*this).program))->get_struct(struct_id))).name),JaktInternal::OptionalNone(),generic_parameters)))));
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 19: {
auto&& __jakt_match_value = __jakt_match_variant.template get<types::ValueImpl::Enum>();types::EnumId const& enum_id = __jakt_match_value.enum_id;
{
JaktInternal::DynamicArray<types::TypeId> const generic_parameters = (TRY((DynamicArray<types::TypeId>::create_with({}))));
TRY((((effective_namespace).push(types::ResolvedNamespace(((((((*this).program))->get_enum(enum_id))).name),JaktInternal::OptionalNone(),generic_parameters)))));
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 25: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::OptionalNone>();
{
JaktInternal::DynamicArray<types::TypeId> const generic_parameters = (TRY((DynamicArray<types::TypeId>::create_with({}))));
TRY((((effective_namespace).push(types::ResolvedNamespace(Jakt::DeprecatedString("Optional"sv),JaktInternal::OptionalNone(),generic_parameters)))));
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 24: {
auto&& __jakt_match_value = __jakt_match_variant.template get<types::ValueImpl::OptionalSome>();{
JaktInternal::DynamicArray<types::TypeId> const generic_parameters = (TRY((DynamicArray<types::TypeId>::create_with({}))));
TRY((((effective_namespace).push(types::ResolvedNamespace(Jakt::DeprecatedString("Optional"sv),JaktInternal::OptionalNone(),generic_parameters)))));
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
default: {
{
TRY((((*this).error(Jakt::DeprecatedString("Attempted to call an instance method on a non-struct/enum type"sv),call_span))));
return Error::from_errno((infallible_integer_cast<i32>((interpreter::InterpretError::InvalidType))));
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
}/*switch end*/
}()
));
(namespace_ = effective_namespace);
}
JaktInternal::Dictionary<DeprecatedString,types::TypeId> type_bindings = (TRY((Dictionary<DeprecatedString, types::TypeId>::create_with_entries({}))));
if (((invocation_scope).has_value())){
(type_bindings = (((invocation_scope.value()))->type_bindings));
}
return (JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<interpreter::ExecutionResult, ErrorOr<interpreter::ExecutionResult>>{
auto&& __jakt_match_variant = TRY((((*this).call_prelude_function(((function_to_run)->name),(namespace_.value()),this_argument,arguments,call_span,type_bindings))));
switch(__jakt_match_variant.index()) {
case 5: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename interpreter::StatementResult::JustValue>();
types::Value const& value = __jakt_match_value.value;
return JaktInternal::ExplicitValue( interpreter::ExecutionResult { typename interpreter::ExecutionResult::Return(value) } );
};/*case end*/
case 0: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename interpreter::StatementResult::Return>();
types::Value const& value = __jakt_match_value.value;
return JaktInternal::ExplicitValue( interpreter::ExecutionResult { typename interpreter::ExecutionResult::Return(value) } );
};/*case end*/
case 1: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename interpreter::StatementResult::Throw>();
types::Value const& value = __jakt_match_value.value;
return JaktInternal::ExplicitValue( interpreter::ExecutionResult { typename interpreter::ExecutionResult::Throw(value) } );
};/*case end*/
case 3: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename interpreter::StatementResult::Continue>();
{
utility::panic(Jakt::DeprecatedString("Invalid control flow"sv));
}
};/*case end*/
case 4: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename interpreter::StatementResult::Break>();
{
utility::panic(Jakt::DeprecatedString("Invalid control flow"sv));
}
};/*case end*/
case 2: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename interpreter::StatementResult::Yield>();
{
utility::panic(Jakt::DeprecatedString("Invalid control flow"sv));
}
};/*case end*/
default: VERIFY_NOT_REACHED();}/*switch end*/
}()
)));
}
JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<void, ErrorOr<interpreter::ExecutionResult>>{
auto&& __jakt_match_variant = ((function_to_run)->type);
switch(__jakt_match_variant.index()) {
case 0: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename parser::FunctionType::Normal>();
{
NonnullRefPtr<interpreter::InterpreterScope> scope = TRY((interpreter::InterpreterScope::create((TRY((Dictionary<DeprecatedString, types::Value>::create_with_entries({})))),invocation_scope,(TRY((Dictionary<DeprecatedString, types::TypeId>::create_with_entries({})))))));
ScopeGuard __jakt_var_327([&] {
{
MUST((((scope)->perform_defers(*this,call_span))));
}

});
{
JaktInternal::Range<size_t> _magic = (JaktInternal::Range<size_t>{static_cast<size_t>(static_cast<size_t>(0ULL)),static_cast<size_t>(((((function_to_run)->params)).size()))});
for (;;){
JaktInternal::Optional<size_t> _magic_value = ((_magic).next());
if ((!(((_magic_value).has_value())))){
break;
}
size_t i = (_magic_value.value());
{
if (((this_offset != static_cast<size_t>(0ULL)) && (i == static_cast<size_t>(0ULL)))){
continue;
}
DeprecatedString const param_name = ((((((((function_to_run)->params))[i])).variable))->name);
types::Value const param_value = ((arguments)[(JaktInternal::checked_sub<size_t>(i,this_offset))]);
TRY(((scope)->bindings).set(param_name, param_value));
}

}
}

if (((this_argument).has_value())){
TRY((((((scope)->bindings)).set(Jakt::DeprecatedString("this"sv),(this_argument.value())))));
}
return (JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<interpreter::ExecutionResult, ErrorOr<interpreter::ExecutionResult>>{
auto&& __jakt_match_variant = TRY((((*this).execute_block(((function_to_run)->block),scope,call_span))));
switch(__jakt_match_variant.index()) {
case 0: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename interpreter::StatementResult::Return>();
types::Value const& value = __jakt_match_value.value;
return JaktInternal::ExplicitValue( interpreter::ExecutionResult { typename interpreter::ExecutionResult::Return(TRY((interpreter::cast_value_to_type(value,((function_to_run)->return_type_id),*this,false)))) } );
};/*case end*/
case 5: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename interpreter::StatementResult::JustValue>();
types::Value const& value = __jakt_match_value.value;
return JaktInternal::ExplicitValue( interpreter::ExecutionResult { typename interpreter::ExecutionResult::Return(TRY((interpreter::cast_value_to_type(value,((function_to_run)->return_type_id),*this,false)))) } );
};/*case end*/
case 1: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename interpreter::StatementResult::Throw>();
types::Value const& value = __jakt_match_value.value;
return JaktInternal::ExplicitValue( interpreter::ExecutionResult { typename interpreter::ExecutionResult::Throw(value) } );
};/*case end*/
case 3: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename interpreter::StatementResult::Continue>();
{
utility::panic(Jakt::DeprecatedString("Invalid control flow"sv));
}
};/*case end*/
case 4: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename interpreter::StatementResult::Break>();
{
utility::panic(Jakt::DeprecatedString("Invalid control flow"sv));
}
};/*case end*/
case 2: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename interpreter::StatementResult::Yield>();
{
utility::panic(Jakt::DeprecatedString("Invalid control flow"sv));
}
};/*case end*/
default: VERIFY_NOT_REACHED();}/*switch end*/
}()
)));
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 1: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename parser::FunctionType::ImplicitConstructor>();
{
NonnullRefPtr<typename types::Type> const result_type = ((((*this).program))->get_type(((function_to_run)->return_type_id)));
JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<void, ErrorOr<interpreter::ExecutionResult>>{
auto&& __jakt_match_variant = *result_type;
switch(__jakt_match_variant.index()) {
case 23: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::Type::Struct>();
types::StructId const& struct_id = __jakt_match_value.value;
{
types::CheckedStruct const struct_ = ((((*this).program))->get_struct(struct_id));
types::FunctionId const constructor = function_to_run_id;
NonnullRefPtr<typename types::ValueImpl> const impl = JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<NonnullRefPtr<typename types::ValueImpl>, ErrorOr<interpreter::ExecutionResult>>{
auto&& __jakt_match_variant = ((struct_).record_type);
switch(__jakt_match_variant.index()) {
case 0: {
auto&& __jakt_match_value = __jakt_match_variant.template get<parser::RecordType::Struct>();return JaktInternal::ExplicitValue(TRY((types::ValueImpl::template create<typename types::ValueImpl::Struct>(arguments,struct_id,constructor))));
};/*case end*/
case 1: {
auto&& __jakt_match_value = __jakt_match_variant.template get<parser::RecordType::Class>();return JaktInternal::ExplicitValue(TRY((types::ValueImpl::template create<typename types::ValueImpl::Class>(arguments,struct_id,constructor))));
};/*case end*/
default: {
{
TRY((((*this).error(TRY((__jakt_format(Jakt::DeprecatedString("Cannot create instance of non-struct type {}"sv),((struct_).name)))),call_span))));
return Error::from_errno((infallible_integer_cast<i32>((interpreter::InterpretError::InvalidType))));
}
};/*case end*/
}/*switch end*/
}()
));
return ( interpreter::ExecutionResult { typename interpreter::ExecutionResult::Return(types::Value(impl,call_span)) } );
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 19: {
auto&& __jakt_match_value = __jakt_match_variant.template get<types::Type::GenericInstance>();types::StructId const& struct_id = __jakt_match_value.id;
{
types::CheckedStruct const struct_ = ((((*this).program))->get_struct(struct_id));
types::FunctionId const constructor = function_to_run_id;
NonnullRefPtr<typename types::ValueImpl> const impl = JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<NonnullRefPtr<typename types::ValueImpl>, ErrorOr<interpreter::ExecutionResult>>{
auto&& __jakt_match_variant = ((struct_).record_type);
switch(__jakt_match_variant.index()) {
case 0: {
auto&& __jakt_match_value = __jakt_match_variant.template get<parser::RecordType::Struct>();return JaktInternal::ExplicitValue(TRY((types::ValueImpl::template create<typename types::ValueImpl::Struct>(arguments,struct_id,constructor))));
};/*case end*/
case 1: {
auto&& __jakt_match_value = __jakt_match_variant.template get<parser::RecordType::Class>();return JaktInternal::ExplicitValue(TRY((types::ValueImpl::template create<typename types::ValueImpl::Class>(arguments,struct_id,constructor))));
};/*case end*/
default: {
{
TRY((((*this).error(TRY((__jakt_format(Jakt::DeprecatedString("Cannot create instance of non-struct type {}"sv),((struct_).name)))),call_span))));
return Error::from_errno((infallible_integer_cast<i32>((interpreter::InterpretError::InvalidType))));
}
};/*case end*/
}/*switch end*/
}()
));
return ( interpreter::ExecutionResult { typename interpreter::ExecutionResult::Return(types::Value(impl,call_span)) } );
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
default: {
{
TRY((((*this).error(TRY((__jakt_format(Jakt::DeprecatedString("Implicit constructor can only return a struct or a generic instance"sv)))),call_span))));
return Error::from_errno((infallible_integer_cast<i32>((interpreter::InterpretError::InvalidType))));
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
}/*switch end*/
}()
));
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 2: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename parser::FunctionType::ImplicitEnumConstructor>();
{
NonnullRefPtr<typename types::Type> const result_type = ((((*this).program))->get_type(((function_to_run)->return_type_id)));
JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<void, ErrorOr<interpreter::ExecutionResult>>{
auto&& __jakt_match_variant = *result_type;
switch(__jakt_match_variant.index()) {
case 24: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::Type::Enum>();
types::EnumId const& enum_id = __jakt_match_value.value;
{
types::CheckedEnum const enum_ = ((((*this).program))->get_enum(enum_id));
types::FunctionId const constructor = function_to_run_id;
NonnullRefPtr<typename types::ValueImpl> const impl = TRY((types::ValueImpl::template create<typename types::ValueImpl::Enum>(arguments,enum_id,constructor)));
return ( interpreter::ExecutionResult { typename interpreter::ExecutionResult::Return(types::Value(impl,call_span)) } );
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 20: {
auto&& __jakt_match_value = __jakt_match_variant.template get<types::Type::GenericEnumInstance>();types::EnumId const& enum_id = __jakt_match_value.id;
{
types::CheckedEnum const enum_ = ((((*this).program))->get_enum(enum_id));
types::FunctionId const constructor = function_to_run_id;
NonnullRefPtr<typename types::ValueImpl> const impl = TRY((types::ValueImpl::template create<typename types::ValueImpl::Enum>(arguments,enum_id,constructor)));
return ( interpreter::ExecutionResult { typename interpreter::ExecutionResult::Return(types::Value(impl,call_span)) } );
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
default: {
{
TRY((((*this).error(TRY((__jakt_format(Jakt::DeprecatedString("Implicit enum constructor can only return an enum or a generic instance of one"sv)))),call_span))));
return Error::from_errno((infallible_integer_cast<i32>((interpreter::InterpretError::InvalidType))));
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
}/*switch end*/
}()
));
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
default: {
{
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
}/*switch end*/
}()
));
TRY((((*this).error(TRY((__jakt_format(Jakt::DeprecatedString("Function type {} is not implemented"sv),((function_to_run)->type)))),call_span))));
return Error::from_errno((infallible_integer_cast<i32>((interpreter::InterpretError::Unimplemented))));
}
}

ErrorOr<void> interpreter::Interpreter::enter_span(utility::Span const span) {
{
TRY((((((*this).spans)).push(span))));
}
return {};
}

ErrorOr<interpreter::StatementResult> interpreter::Interpreter::execute_block(types::CheckedBlock const block,NonnullRefPtr<interpreter::InterpreterScope> scope,utility::Span const call_span) {
{
{
JaktInternal::ArrayIterator<NonnullRefPtr<typename types::CheckedStatement>> _magic = ((((block).statements)).iterator());
for (;;){
JaktInternal::Optional<NonnullRefPtr<typename types::CheckedStatement>> _magic_value = ((_magic).next());
if ((!(((_magic_value).has_value())))){
break;
}
NonnullRefPtr<typename types::CheckedStatement> statement = (_magic_value.value());
{
TRY((((*this).enter_span(((statement)->span()).value_or_lazy_evaluated([&] { return call_span; })))));
ScopeGuard __jakt_var_328([&] {
((*this).leave_span());
});
JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_AT_LOOP(([&]() -> JaktInternal::ExplicitValueOrControlFlow<void, ErrorOr<interpreter::StatementResult>>{
auto&& __jakt_match_variant = TRY((((*this).execute_statement(statement,scope,call_span))));
switch(__jakt_match_variant.index()) {
case 0: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename interpreter::StatementResult::Return>();
types::Value const& value = __jakt_match_value.value;
{
return ( interpreter::StatementResult { typename interpreter::StatementResult::Return(value) } );
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 1: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename interpreter::StatementResult::Throw>();
types::Value const& value = __jakt_match_value.value;
{
return ( interpreter::StatementResult { typename interpreter::StatementResult::Throw(value) } );
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 3: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename interpreter::StatementResult::Continue>();
{
return ( interpreter::StatementResult { typename interpreter::StatementResult::Continue() } );
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 4: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename interpreter::StatementResult::Break>();
{
return ( interpreter::StatementResult { typename interpreter::StatementResult::Break() } );
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 5: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename interpreter::StatementResult::JustValue>();
{
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 2: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename interpreter::StatementResult::Yield>();
types::Value const& value = __jakt_match_value.value;
{
return ( interpreter::StatementResult { typename interpreter::StatementResult::Yield(value) } );
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
default: VERIFY_NOT_REACHED();}/*switch end*/
}()
));
}

}
}

return ( interpreter::StatementResult { typename interpreter::StatementResult::JustValue(types::Value(TRY((types::ValueImpl::template create<typename types::ValueImpl::Void>())),call_span)) } );
}
}

ErrorOr<types::TypeId> interpreter::Interpreter::find_or_add_type_id(NonnullRefPtr<typename types::Type> const type) {
{
{
JaktInternal::ArrayIterator<NonnullRefPtr<types::Module>> _magic = ((((((*this).program))->modules)).iterator());
for (;;){
JaktInternal::Optional<NonnullRefPtr<types::Module>> _magic_value = ((_magic).next());
if ((!(((_magic_value).has_value())))){
break;
}
NonnullRefPtr<types::Module> module = (_magic_value.value());
{
{
JaktInternal::Range<size_t> _magic = (JaktInternal::Range<size_t>{static_cast<size_t>(static_cast<size_t>(0ULL)),static_cast<size_t>(((((module)->types)).size()))});
for (;;){
JaktInternal::Optional<size_t> _magic_value = ((_magic).next());
if ((!(((_magic_value).has_value())))){
break;
}
size_t id = (_magic_value.value());
{
if (((((((module)->types))[id]))->equals(type))){
return (types::TypeId(((module)->id),id));
}
}

}
}

}

}
}

TRY((((((((((((*this).program))->modules))[static_cast<i64>(0LL)]))->types)).push(type))));
return (types::TypeId(types::ModuleId(static_cast<size_t>(0ULL)),(JaktInternal::checked_sub<size_t>(((((((((((*this).program))->modules))[static_cast<i64>(0LL)]))->types)).size()),static_cast<size_t>(1ULL)))));
}
}

ErrorOr<DeprecatedString> interpreter::InterpreterScope::debug_description() const { auto builder = MUST(DeprecatedStringBuilder::create());TRY(builder.append("InterpreterScope("sv));{
JaktInternal::PrettyPrint::ScopedLevelIncrease increase_indent {};
TRY(JaktInternal::PrettyPrint::output_indentation(builder));TRY(builder.append("bindings: "sv));TRY(builder.appendff("{}, ", bindings));
TRY(JaktInternal::PrettyPrint::output_indentation(builder));TRY(builder.append("parent: "sv));TRY(builder.appendff("{}, ", parent));
TRY(JaktInternal::PrettyPrint::output_indentation(builder));TRY(builder.append("type_bindings: "sv));TRY(builder.appendff("{}, ", type_bindings));
TRY(JaktInternal::PrettyPrint::output_indentation(builder));TRY(builder.append("defers: "sv));TRY(builder.appendff("{}", defers));
}
TRY(builder.append(")"sv));return builder.to_string(); }
ErrorOr<void> interpreter::InterpreterScope::defer_statement(NonnullRefPtr<typename types::CheckedStatement> const statement) {
{
TRY((((((*this).defers)).push( interpreter::Deferred { typename interpreter::Deferred::Statement(statement) } ))));
}
return {};
}

ErrorOr<void> interpreter::InterpreterScope::perform_defers(NonnullRefPtr<interpreter::Interpreter> interpreter,utility::Span const span) {
{
while ((!(((((*this).defers)).is_empty())))){
JaktInternal::Optional<interpreter::Deferred> const deferred = ((((*this).defers)).pop());
JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_AT_LOOP(([&]() -> JaktInternal::ExplicitValueOrControlFlow<interpreter::StatementResult, ErrorOr<void>>{
auto&& __jakt_match_variant = (deferred.value());
switch(__jakt_match_variant.index()) {
case 0: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename interpreter::Deferred::Expression>();
NonnullRefPtr<typename types::CheckedExpression> const& expr = __jakt_match_value.value;
return JaktInternal::ExplicitValue(TRY((((interpreter)->execute_expression(expr,*this)))));
};/*case end*/
case 1: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename interpreter::Deferred::Statement>();
NonnullRefPtr<typename types::CheckedStatement> const& statement = __jakt_match_value.value;
return JaktInternal::ExplicitValue(TRY((((interpreter)->execute_statement(statement,*this,span)))));
};/*case end*/
default: VERIFY_NOT_REACHED();}/*switch end*/
}()
));
}
}
return {};
}

ErrorOr<NonnullRefPtr<interpreter::InterpreterScope>> interpreter::InterpreterScope::from_runtime_scope(types::ScopeId const scope_id,NonnullRefPtr<types::CheckedProgram> const program,JaktInternal::Optional<NonnullRefPtr<interpreter::InterpreterScope>> const parent) {
{
JaktInternal::Dictionary<DeprecatedString,types::Value> bindings = (TRY((Dictionary<DeprecatedString, types::Value>::create_with_entries({}))));
JaktInternal::Optional<types::ScopeId> current_id = scope_id;
while (((current_id).has_value())){
NonnullRefPtr<types::Scope> const scope = TRY((((program)->get_scope((current_id.value())))));
{
JaktInternal::DictionaryIterator<DeprecatedString,types::Value> _magic = ((((scope)->comptime_bindings)).iterator());
for (;;){
JaktInternal::Optional<JaktInternal::Tuple<DeprecatedString,types::Value>> _magic_value = ((_magic).next());
if ((!(((_magic_value).has_value())))){
break;
}
JaktInternal::Tuple<DeprecatedString,types::Value> pair = (_magic_value.value());
{
if (((bindings).contains(((pair).template get<0>())))){
continue;
}
TRY((((bindings).set(((pair).template get<0>()),((pair).template get<1>())))));
}

}
}

(current_id = ((scope)->parent));
}
return (TRY((interpreter::InterpreterScope::create(bindings,parent,(TRY((Dictionary<DeprecatedString, types::TypeId>::create_with_entries({})))),(TRY((DynamicArray<interpreter::Deferred>::create_with({}))))))));
}
}

ErrorOr<types::GenericInferences> interpreter::InterpreterScope::type_map_for_substitution() const {
{
JaktInternal::Dictionary<DeprecatedString,DeprecatedString> map = (TRY((Dictionary<DeprecatedString, DeprecatedString>::create_with_entries({}))));
TRY((((*this).type_map_for_substitution_helper(((map))))));
return (types::GenericInferences(map));
}
}

interpreter::InterpreterScope::InterpreterScope(JaktInternal::Dictionary<DeprecatedString,types::Value>&& a_bindings, JaktInternal::Optional<NonnullRefPtr<interpreter::InterpreterScope>>&& a_parent, JaktInternal::Dictionary<DeprecatedString,types::TypeId>&& a_type_bindings, JaktInternal::DynamicArray<interpreter::Deferred>&& a_defers): bindings(move(a_bindings)), parent(move(a_parent)), type_bindings(move(a_type_bindings)), defers(move(a_defers)){}
ErrorOr<NonnullRefPtr<InterpreterScope>> interpreter::InterpreterScope::create(JaktInternal::Dictionary<DeprecatedString,types::Value> bindings, JaktInternal::Optional<NonnullRefPtr<interpreter::InterpreterScope>> parent, JaktInternal::Dictionary<DeprecatedString,types::TypeId> type_bindings, JaktInternal::DynamicArray<interpreter::Deferred> defers) { auto o = TRY(adopt_nonnull_ref_or_enomem(new (nothrow) InterpreterScope (move(bindings), move(parent), move(type_bindings), move(defers)))); return o; }
ErrorOr<types::TypeId> interpreter::InterpreterScope::map_type(types::TypeId const id) const {
{
DeprecatedString const name = TRY((((id).to_string())));
if (((((*this).type_bindings)).contains(name))){
return (((((*this).type_bindings))[name]));
}
JaktInternal::Optional<NonnullRefPtr<interpreter::InterpreterScope>> scope = ((*this).parent);
while (((scope).has_value())){
if ((((((scope.value()))->type_bindings)).contains(name))){
return ((((((scope.value()))->type_bindings))[name]));
}
(scope = (((scope.value()))->parent));
}
return (id);
}
}

ErrorOr<void> interpreter::InterpreterScope::set(DeprecatedString const name,types::Value const value) {
{
if (((((*this).bindings)).contains(name))){
TRY(((*this).bindings).set(name, value));
return {};
}
JaktInternal::Optional<NonnullRefPtr<interpreter::InterpreterScope>> scope = ((*this).parent);
while (((scope).has_value())){
if ((((((scope.value()))->bindings)).contains(name))){
TRY((((scope.value()))->bindings).set(name, value));
return {};
}
(scope = (((scope.value()))->parent));
}
utility::panic(TRY((__jakt_format(Jakt::DeprecatedString("Could not find binding for {}"sv),name))));
}
return {};
}

ErrorOr<NonnullRefPtr<interpreter::InterpreterScope>> interpreter::InterpreterScope::create(JaktInternal::Dictionary<DeprecatedString,types::Value> const bindings,JaktInternal::Optional<NonnullRefPtr<interpreter::InterpreterScope>> const parent,JaktInternal::Dictionary<DeprecatedString,types::TypeId> const type_bindings) {
{
return (TRY((interpreter::InterpreterScope::create(bindings,parent,type_bindings,(TRY((DynamicArray<interpreter::Deferred>::create_with({}))))))));
}
}

ErrorOr<void> interpreter::InterpreterScope::type_map_for_substitution_helper(JaktInternal::Dictionary<DeprecatedString,DeprecatedString>& map) const {
{
if (((((*this).parent)).has_value())){
TRY(((((((*this).parent).value()))->type_map_for_substitution_helper(map))));
}
{
JaktInternal::DictionaryIterator<DeprecatedString,types::TypeId> _magic = ((((*this).type_bindings)).iterator());
for (;;){
JaktInternal::Optional<JaktInternal::Tuple<DeprecatedString,types::TypeId>> _magic_value = ((_magic).next());
if ((!(((_magic_value).has_value())))){
break;
}
JaktInternal::Tuple<DeprecatedString,types::TypeId> pair = (_magic_value.value());
{
TRY((((((map))).set(((pair).template get<0>()),TRY((((((pair).template get<1>())).to_string())))))));
}

}
}

}
return {};
}

ErrorOr<types::Value> interpreter::InterpreterScope::must_get(DeprecatedString const name) const {
{
if (((((*this).bindings)).contains(name))){
return (((((*this).bindings))[name]));
}
JaktInternal::Optional<NonnullRefPtr<interpreter::InterpreterScope>> scope = ((*this).parent);
while (((scope).has_value())){
if ((((((scope.value()))->bindings)).contains(name))){
return ((((((scope.value()))->bindings))[name]));
}
(scope = (((scope.value()))->parent));
}
utility::panic(TRY((__jakt_format(Jakt::DeprecatedString("Could not find binding for {}"sv),name))));
}
}

ErrorOr<void> interpreter::InterpreterScope::defer_expression(NonnullRefPtr<typename types::CheckedExpression> const expr) {
{
TRY((((((*this).defers)).push( interpreter::Deferred { typename interpreter::Deferred::Expression(expr) } ))));
}
return {};
}

ErrorOr<DeprecatedString> interpreter::StatementResult::debug_description() const {
auto builder = TRY(DeprecatedStringBuilder::create());
switch (this->index()) {case 0 /* Return */: {
[[maybe_unused]] auto const& that = this->template get<StatementResult::Return>();
TRY(builder.append("StatementResult::Return"sv));
TRY(builder.appendff("({})", that.value));
break;}
case 1 /* Throw */: {
[[maybe_unused]] auto const& that = this->template get<StatementResult::Throw>();
TRY(builder.append("StatementResult::Throw"sv));
TRY(builder.appendff("({})", that.value));
break;}
case 2 /* Yield */: {
[[maybe_unused]] auto const& that = this->template get<StatementResult::Yield>();
TRY(builder.append("StatementResult::Yield"sv));
TRY(builder.appendff("({})", that.value));
break;}
case 3 /* Continue */: {
[[maybe_unused]] auto const& that = this->template get<StatementResult::Continue>();
TRY(builder.append("StatementResult::Continue"sv));
break;}
case 4 /* Break */: {
[[maybe_unused]] auto const& that = this->template get<StatementResult::Break>();
TRY(builder.append("StatementResult::Break"sv));
break;}
case 5 /* JustValue */: {
[[maybe_unused]] auto const& that = this->template get<StatementResult::JustValue>();
TRY(builder.append("StatementResult::JustValue"sv));
TRY(builder.appendff("({})", that.value));
break;}
}
return builder.to_string();
}
ErrorOr<DeprecatedString> interpreter::ExecutionResult::debug_description() const {
auto builder = TRY(DeprecatedStringBuilder::create());
switch (this->index()) {case 0 /* Return */: {
[[maybe_unused]] auto const& that = this->template get<ExecutionResult::Return>();
TRY(builder.append("ExecutionResult::Return"sv));
TRY(builder.appendff("({})", that.value));
break;}
case 1 /* Throw */: {
[[maybe_unused]] auto const& that = this->template get<ExecutionResult::Throw>();
TRY(builder.append("ExecutionResult::Throw"sv));
TRY(builder.appendff("({})", that.value));
break;}
}
return builder.to_string();
}
ErrorOr<DeprecatedString> interpreter::Deferred::debug_description() const {
auto builder = TRY(DeprecatedStringBuilder::create());
switch (this->index()) {case 0 /* Expression */: {
[[maybe_unused]] auto const& that = this->template get<Deferred::Expression>();
TRY(builder.append("Deferred::Expression"sv));
TRY(builder.appendff("({})", that.value));
break;}
case 1 /* Statement */: {
[[maybe_unused]] auto const& that = this->template get<Deferred::Statement>();
TRY(builder.append("Deferred::Statement"sv));
TRY(builder.appendff("({})", that.value));
break;}
}
return builder.to_string();
}
}
} // namespace Jakt
