#include "ide.h"
namespace Jakt {
namespace ide {
ErrorOr<ide::JaktSymbol> record_to_symbol(parser::ParsedRecord const record) {
{
JaktInternal::DynamicArray<ide::JaktSymbol> children = (TRY((DynamicArray<ide::JaktSymbol>::create_with({}))));
utility::Span record_span = ((record).name_span);
DeprecatedString const record_kind = JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<DeprecatedString, ErrorOr<ide::JaktSymbol>>{
auto&& __jakt_match_variant = ((record).record_type);
switch(__jakt_match_variant.index()) {
case 0: {
auto&& __jakt_match_value = __jakt_match_variant.template get<parser::RecordType::Struct>();JaktInternal::DynamicArray<parser::ParsedField> const& fields = __jakt_match_value.fields;
return JaktInternal::ExplicitValue(({ Optional<DeprecatedString> __jakt_var_713; {
{
JaktInternal::ArrayIterator<parser::ParsedField> _magic = ((fields).iterator());
for (;;){
JaktInternal::Optional<parser::ParsedField> _magic_value = ((_magic).next());
if ((!(((_magic_value).has_value())))){
break;
}
parser::ParsedField field = (_magic_value.value());
{
TRY((((children).push(ide::JaktSymbol(((((field).var_decl)).name),JaktInternal::OptionalNone(),Jakt::DeprecatedString("field"sv),((((field).var_decl)).span),((((field).var_decl)).span),(TRY((DynamicArray<ide::JaktSymbol>::create_with({})))))))));
}

}
}

__jakt_var_713 = Jakt::DeprecatedString("struct"sv); goto __jakt_label_636;

}
__jakt_label_636:; __jakt_var_713.release_value(); }));
};/*case end*/
case 1: {
auto&& __jakt_match_value = __jakt_match_variant.template get<parser::RecordType::Class>();JaktInternal::DynamicArray<parser::ParsedField> const& fields = __jakt_match_value.fields;
return JaktInternal::ExplicitValue(({ Optional<DeprecatedString> __jakt_var_714; {
{
JaktInternal::ArrayIterator<parser::ParsedField> _magic = ((fields).iterator());
for (;;){
JaktInternal::Optional<parser::ParsedField> _magic_value = ((_magic).next());
if ((!(((_magic_value).has_value())))){
break;
}
parser::ParsedField field = (_magic_value.value());
{
TRY((((children).push(ide::JaktSymbol(((((field).var_decl)).name),JaktInternal::OptionalNone(),Jakt::DeprecatedString("field"sv),((((field).var_decl)).span),((((field).var_decl)).span),(TRY((DynamicArray<ide::JaktSymbol>::create_with({})))))))));
}

}
}

__jakt_var_714 = Jakt::DeprecatedString("class"sv); goto __jakt_label_637;

}
__jakt_label_637:; __jakt_var_714.release_value(); }));
};/*case end*/
case 2: {
auto&& __jakt_match_value = __jakt_match_variant.template get<parser::RecordType::ValueEnum>();JaktInternal::DynamicArray<parser::ValueEnumVariant> const& variants = __jakt_match_value.variants;
return JaktInternal::ExplicitValue(({ Optional<DeprecatedString> __jakt_var_715; {
{
JaktInternal::ArrayIterator<parser::ValueEnumVariant> _magic = ((variants).iterator());
for (;;){
JaktInternal::Optional<parser::ValueEnumVariant> _magic_value = ((_magic).next());
if ((!(((_magic_value).has_value())))){
break;
}
parser::ValueEnumVariant variant = (_magic_value.value());
{
TRY((((children).push(ide::JaktSymbol(((variant).name),JaktInternal::OptionalNone(),Jakt::DeprecatedString("enum-member"sv),((variant).span),((variant).span),(TRY((DynamicArray<ide::JaktSymbol>::create_with({})))))))));
}

}
}

__jakt_var_715 = Jakt::DeprecatedString("enum"sv); goto __jakt_label_638;

}
__jakt_label_638:; __jakt_var_715.release_value(); }));
};/*case end*/
case 3: {
auto&& __jakt_match_value = __jakt_match_variant.template get<parser::RecordType::SumEnum>();JaktInternal::DynamicArray<parser::SumEnumVariant> const& variants = __jakt_match_value.variants;
return JaktInternal::ExplicitValue(({ Optional<DeprecatedString> __jakt_var_716; {
{
JaktInternal::ArrayIterator<parser::SumEnumVariant> _magic = ((variants).iterator());
for (;;){
JaktInternal::Optional<parser::SumEnumVariant> _magic_value = ((_magic).next());
if ((!(((_magic_value).has_value())))){
break;
}
parser::SumEnumVariant variant = (_magic_value.value());
{
JaktInternal::DynamicArray<ide::JaktSymbol> variant_children = (TRY((DynamicArray<ide::JaktSymbol>::create_with({}))));
if (((((variant).params)).has_value())){
{
JaktInternal::ArrayIterator<parser::ParsedVarDecl> _magic = (((((variant).params).value())).iterator());
for (;;){
JaktInternal::Optional<parser::ParsedVarDecl> _magic_value = ((_magic).next());
if ((!(((_magic_value).has_value())))){
break;
}
parser::ParsedVarDecl param = (_magic_value.value());
{
if ((((param).name) != Jakt::DeprecatedString(""sv))){
TRY((((variant_children).push(ide::JaktSymbol(((param).name),JaktInternal::OptionalNone(),Jakt::DeprecatedString("field"sv),((param).span),((param).span),(TRY((DynamicArray<ide::JaktSymbol>::create_with({})))))))));
}
}

}
}

}
TRY((((children).push(ide::JaktSymbol(((variant).name),JaktInternal::OptionalNone(),Jakt::DeprecatedString("enum-member"sv),((variant).span),((variant).span),variant_children)))));
}

}
}

__jakt_var_716 = Jakt::DeprecatedString("enum"sv); goto __jakt_label_639;

}
__jakt_label_639:; __jakt_var_716.release_value(); }));
};/*case end*/
case 4: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename parser::RecordType::Garbage>();
return JaktInternal::ExplicitValue(Jakt::DeprecatedString("garbage"sv));
};/*case end*/
default: VERIFY_NOT_REACHED();}/*switch end*/
}()
));
{
JaktInternal::ArrayIterator<parser::ParsedMethod> _magic = ((((record).methods)).iterator());
for (;;){
JaktInternal::Optional<parser::ParsedMethod> _magic_value = ((_magic).next());
if ((!(((_magic_value).has_value())))){
break;
}
parser::ParsedMethod method = (_magic_value.value());
{
ide::JaktSymbol const function_symbol = TRY((ide::function_to_symbol(((method).parsed_function),Jakt::DeprecatedString("method"sv))));
TRY((((children).push(function_symbol))));
(record_span = TRY((parser::merge_spans(record_span,((function_symbol).range)))));
}

}
}

return (ide::JaktSymbol(((record).name),JaktInternal::OptionalNone(),record_kind,record_span,((record).name_span),children));
}
}

ErrorOr<JaktInternal::Optional<DeprecatedString>> find_typename_in_program(NonnullRefPtr<types::CheckedProgram> const program,utility::Span const span) {
{
JaktInternal::Optional<ide::Usage> const result = TRY((ide::find_span_in_program(program,span)));
if (((result).has_value())){
return (JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<JaktInternal::Optional<DeprecatedString>, ErrorOr<JaktInternal::Optional<DeprecatedString>>>{
auto&& __jakt_match_variant = (result.value());
switch(__jakt_match_variant.index()) {
case 0: {
auto&& __jakt_match_value = __jakt_match_variant.template get<ide::Usage::Variable>();DeprecatedString const& name = __jakt_match_value.name;
types::TypeId const& type_id = __jakt_match_value.type_id;
ide::Mutability const& mutability = __jakt_match_value.mutability;
ide::VarType const& var_type = __jakt_match_value.var_type;
ide::VarVisibility const& visibility = __jakt_match_value.visibility;
JaktInternal::Optional<types::TypeId> const& struct_type_id = __jakt_match_value.struct_type_id;
return JaktInternal::ExplicitValue(({ Optional<JaktInternal::Optional<DeprecatedString>> __jakt_var_717; {
DeprecatedString const result = TRY((ide::get_var_signature(program,name,type_id,mutability,var_type,visibility,struct_type_id)));
__jakt_var_717 = static_cast<JaktInternal::Optional<DeprecatedString>>(result); goto __jakt_label_640;

}
__jakt_label_640:; __jakt_var_717.release_value(); }));
};/*case end*/
case 1: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename ide::Usage::Call>();
types::FunctionId const& function_id = __jakt_match_value.value;
return JaktInternal::ExplicitValue(({ Optional<JaktInternal::Optional<DeprecatedString>> __jakt_var_718; {
DeprecatedString const result = TRY((ide::get_function_signature(program,function_id)));
__jakt_var_718 = static_cast<JaktInternal::Optional<DeprecatedString>>(result); goto __jakt_label_641;

}
__jakt_label_641:; __jakt_var_718.release_value(); }));
};/*case end*/
case 2: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename ide::Usage::Typename>();
types::TypeId const& type_id = __jakt_match_value.value;
return JaktInternal::ExplicitValue(({ Optional<JaktInternal::Optional<DeprecatedString>> __jakt_var_719; {
DeprecatedString const result = TRY((ide::get_type_signature(program,type_id)));
__jakt_var_719 = static_cast<JaktInternal::Optional<DeprecatedString>>(result); goto __jakt_label_642;

}
__jakt_label_642:; __jakt_var_719.release_value(); }));
};/*case end*/
case 3: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename ide::Usage::NameSet>();
JaktInternal::DynamicArray<DeprecatedString> const& names = __jakt_match_value.value;
return JaktInternal::ExplicitValue(({ Optional<JaktInternal::Optional<DeprecatedString>> __jakt_var_720; {
DeprecatedString output = Jakt::DeprecatedString(""sv);
bool first = true;
{
JaktInternal::ArrayIterator<DeprecatedString> _magic = ((names).iterator());
for (;;){
JaktInternal::Optional<DeprecatedString> _magic_value = ((_magic).next());
if ((!(((_magic_value).has_value())))){
break;
}
DeprecatedString name = (_magic_value.value());
{
if ((!(first))){
(output += Jakt::DeprecatedString(" | "sv));
}
else {
(first = false);
}

(output += name);
}

}
}

__jakt_var_720 = static_cast<JaktInternal::Optional<DeprecatedString>>(output); goto __jakt_label_643;

}
__jakt_label_643:; __jakt_var_720.release_value(); }));
};/*case end*/
case 4: {
auto&& __jakt_match_value = __jakt_match_variant.template get<ide::Usage::EnumVariant>();DeprecatedString const& name = __jakt_match_value.name;
types::TypeId const& type_id = __jakt_match_value.type_id;
JaktInternal::DynamicArray<JaktInternal::Tuple<JaktInternal::Optional<DeprecatedString>,types::TypeId>> const& variants = __jakt_match_value.variants;
JaktInternal::Optional<types::NumberConstant> const& number_constant = __jakt_match_value.number_constant;
return JaktInternal::ExplicitValue(({ Optional<JaktInternal::Optional<DeprecatedString>> __jakt_var_721; {
DeprecatedString const result = TRY((ide::get_enum_variant_signature(program,name,type_id,variants,number_constant)));
__jakt_var_721 = static_cast<JaktInternal::Optional<DeprecatedString>>(result); goto __jakt_label_644;

}
__jakt_label_644:; __jakt_var_721.release_value(); }));
};/*case end*/
default: VERIFY_NOT_REACHED();}/*switch end*/
}()
)));
}
else {
return (JaktInternal::OptionalNone());
}

}
}

ErrorOr<JaktInternal::DynamicArray<DeprecatedString>> completions_for_type_id(NonnullRefPtr<types::CheckedProgram> const program,types::TypeId const type_id) {
{
JaktInternal::DynamicArray<DeprecatedString> output = (TRY((DynamicArray<DeprecatedString>::create_with({}))));
NonnullRefPtr<typename types::Type> const ty = ((program)->get_type(type_id));
JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<void, ErrorOr<JaktInternal::DynamicArray<DeprecatedString>>>{
auto&& __jakt_match_variant = *ty;
switch(__jakt_match_variant.index()) {
case 24: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::Type::Enum>();
types::EnumId const& enum_id = __jakt_match_value.value;
{
types::CheckedEnum const enum_ = ((program)->get_enum(enum_id));
NonnullRefPtr<types::Scope> const scope = TRY((((program)->get_scope(((enum_).scope_id)))));
TRY((((output).push_values(((TRY((ide::find_function_completions_in_scope(scope,program)))))))));
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 23: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::Type::Struct>();
types::StructId const& struct_id = __jakt_match_value.value;
{
types::CheckedStruct const structure = ((program)->get_struct(struct_id));
{
JaktInternal::ArrayIterator<types::CheckedField> _magic = ((((structure).fields)).iterator());
for (;;){
JaktInternal::Optional<types::CheckedField> _magic_value = ((_magic).next());
if ((!(((_magic_value).has_value())))){
break;
}
types::CheckedField field = (_magic_value.value());
{
NonnullRefPtr<types::CheckedVariable> const field_var = ((program)->get_variable(((field).variable_id)));
TRY((((output).push(((field_var)->name)))));
}

}
}

NonnullRefPtr<types::Scope> const scope = TRY((((program)->get_scope(((structure).scope_id)))));
TRY((((output).push_values(((TRY((ide::find_function_completions_in_scope(scope,program)))))))));
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 19: {
auto&& __jakt_match_value = __jakt_match_variant.template get<types::Type::GenericInstance>();types::StructId const& struct_id = __jakt_match_value.id;
{
types::CheckedStruct const structure = ((program)->get_struct(struct_id));
{
JaktInternal::ArrayIterator<types::CheckedField> _magic = ((((structure).fields)).iterator());
for (;;){
JaktInternal::Optional<types::CheckedField> _magic_value = ((_magic).next());
if ((!(((_magic_value).has_value())))){
break;
}
types::CheckedField field = (_magic_value.value());
{
NonnullRefPtr<types::CheckedVariable> const field_var = ((program)->get_variable(((field).variable_id)));
TRY((((output).push(((field_var)->name)))));
}

}
}

NonnullRefPtr<types::Scope> const scope = TRY((((program)->get_scope(((structure).scope_id)))));
TRY((((output).push_values(((TRY((ide::find_function_completions_in_scope(scope,program)))))))));
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
return (output);
}
}

ErrorOr<ide::Usage> get_enum_variant_usage_from_type_id_and_name(NonnullRefPtr<types::CheckedProgram> const program,types::TypeId const type_id,DeprecatedString const name) {
{
{
JaktInternal::ArrayIterator<types::CheckedEnum> _magic = ((((((program)->get_module(((type_id).module))))->enums)).iterator());
for (;;){
JaktInternal::Optional<types::CheckedEnum> _magic_value = ((_magic).next());
if ((!(((_magic_value).has_value())))){
break;
}
types::CheckedEnum enum_ = (_magic_value.value());
{
if ((!(((((enum_).type_id)).equals(type_id))))){
continue;
}
{
JaktInternal::ArrayIterator<types::CheckedEnumVariant> _magic = ((((enum_).variants)).iterator());
for (;;){
JaktInternal::Optional<types::CheckedEnumVariant> _magic_value = ((_magic).next());
if ((!(((_magic_value).has_value())))){
break;
}
types::CheckedEnumVariant variant = (_magic_value.value());
{
if ((((variant).name()) == name)){
JaktInternal::DynamicArray<JaktInternal::Tuple<JaktInternal::Optional<DeprecatedString>,types::TypeId>> const variants = TRY((ide::enum_variant_fields(program,variant)));
JaktInternal::Optional<types::NumberConstant> const number_constant = JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_AT_LOOP(([&]() -> JaktInternal::ExplicitValueOrControlFlow<JaktInternal::Optional<types::NumberConstant>, ErrorOr<ide::Usage>>{
auto&& __jakt_match_variant = variant;
switch(__jakt_match_variant.index()) {
case 2: {
auto&& __jakt_match_value = __jakt_match_variant.template get<types::CheckedEnumVariant::WithValue>();DeprecatedString const& name = __jakt_match_value.name;
NonnullRefPtr<typename types::CheckedExpression> const& expr = __jakt_match_value.expr;
return JaktInternal::ExplicitValue(((expr)->to_number_constant(program)));
};/*case end*/
default: {
return JaktInternal::ExplicitValue(JaktInternal::OptionalNone());
};/*case end*/
}/*switch end*/
}()
));
utility::Span const span = ((variant).span());
return ( ide::Usage { typename ide::Usage::EnumVariant(span,name,type_id,variants,number_constant) } );
}
}

}
}

utility::panic(Jakt::DeprecatedString("unreachable: should have found variant"sv));
}

}
}

utility::panic(Jakt::DeprecatedString("unreachable: should have found variant"sv));
}
}

ErrorOr<DeprecatedString> get_enum_variant_signature_from_type_id_and_name(NonnullRefPtr<types::CheckedProgram> const program,types::TypeId const type_id,DeprecatedString const name) {
{
NonnullRefPtr<types::Module> const mod = ((((program)->modules))[((((type_id).module)).id)]);
{
JaktInternal::ArrayIterator<types::CheckedEnum> _magic = ((((mod)->enums)).iterator());
for (;;){
JaktInternal::Optional<types::CheckedEnum> _magic_value = ((_magic).next());
if ((!(((_magic_value).has_value())))){
break;
}
types::CheckedEnum enum_ = (_magic_value.value());
{
if (((((enum_).type_id)).equals(type_id))){
{
JaktInternal::ArrayIterator<types::CheckedEnumVariant> _magic = ((((enum_).variants)).iterator());
for (;;){
JaktInternal::Optional<types::CheckedEnumVariant> _magic_value = ((_magic).next());
if ((!(((_magic_value).has_value())))){
break;
}
types::CheckedEnumVariant variant = (_magic_value.value());
{
JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_AT_LOOP(([&]() -> JaktInternal::ExplicitValueOrControlFlow<void, ErrorOr<DeprecatedString>>{
auto&& __jakt_match_variant = variant;
switch(__jakt_match_variant.index()) {
case 0: {
auto&& __jakt_match_value = __jakt_match_variant.template get<types::CheckedEnumVariant::Untyped>();DeprecatedString const& v_name = __jakt_match_value.name;
{
if ((v_name == name)){
JaktInternal::DynamicArray<JaktInternal::Tuple<JaktInternal::Optional<DeprecatedString>,types::TypeId>> const params = TRY((ide::enum_variant_fields(program,variant)));
JaktInternal::Optional<types::NumberConstant> const none = JaktInternal::OptionalNone();
return (TRY((ide::get_enum_variant_signature(program,name,type_id,params,none))));
}
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 1: {
auto&& __jakt_match_value = __jakt_match_variant.template get<types::CheckedEnumVariant::Typed>();DeprecatedString const& v_name = __jakt_match_value.name;
{
if ((v_name == name)){
JaktInternal::DynamicArray<JaktInternal::Tuple<JaktInternal::Optional<DeprecatedString>,types::TypeId>> const params = TRY((ide::enum_variant_fields(program,variant)));
JaktInternal::Optional<types::NumberConstant> const none = JaktInternal::OptionalNone();
return (TRY((ide::get_enum_variant_signature(program,name,type_id,params,none))));
}
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 2: {
auto&& __jakt_match_value = __jakt_match_variant.template get<types::CheckedEnumVariant::WithValue>();DeprecatedString const& v_name = __jakt_match_value.name;
{
if ((v_name == name)){
JaktInternal::DynamicArray<JaktInternal::Tuple<JaktInternal::Optional<DeprecatedString>,types::TypeId>> const params = TRY((ide::enum_variant_fields(program,variant)));
JaktInternal::Optional<types::NumberConstant> const value = JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_AT_LOOP_NESTED_MATCH(([&]() -> JaktInternal::ExplicitValueOrControlFlow<JaktInternal::Optional<types::NumberConstant>, ErrorOr<DeprecatedString>>{
auto&& __jakt_match_variant = variant;
switch(__jakt_match_variant.index()) {
case 2: {
auto&& __jakt_match_value = __jakt_match_variant.template get<types::CheckedEnumVariant::WithValue>();NonnullRefPtr<typename types::CheckedExpression> const& expr = __jakt_match_value.expr;
return JaktInternal::ExplicitValue(({ Optional<JaktInternal::Optional<types::NumberConstant>> __jakt_var_722; {
__jakt_var_722 = ((expr)->to_number_constant(program)); goto __jakt_label_645;

}
__jakt_label_645:; __jakt_var_722.release_value(); }));
};/*case end*/
default: {
return JaktInternal::ExplicitValue(({ Optional<JaktInternal::Optional<types::NumberConstant>> __jakt_var_723; {
JaktInternal::Optional<types::NumberConstant> const none = JaktInternal::OptionalNone();
__jakt_var_723 = none; goto __jakt_label_646;

}
__jakt_label_646:; __jakt_var_723.release_value(); }));
};/*case end*/
}/*switch end*/
}()
));
return (TRY((ide::get_enum_variant_signature(program,name,type_id,params,value))));
}
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 3: {
auto&& __jakt_match_value = __jakt_match_variant.template get<types::CheckedEnumVariant::StructLike>();DeprecatedString const& v_name = __jakt_match_value.name;
{
if ((v_name == name)){
JaktInternal::DynamicArray<JaktInternal::Tuple<JaktInternal::Optional<DeprecatedString>,types::TypeId>> const params = TRY((ide::enum_variant_fields(program,variant)));
JaktInternal::Optional<types::NumberConstant> const none = JaktInternal::OptionalNone();
return (TRY((ide::get_enum_variant_signature(program,name,type_id,params,none))));
}
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
default: VERIFY_NOT_REACHED();}/*switch end*/
}()
));
}

}
}

}
}

}
}

return (Jakt::DeprecatedString(""sv));
}
}

ErrorOr<DeprecatedString> get_type_signature(NonnullRefPtr<types::CheckedProgram> const program,types::TypeId const type_id) {
{
types::StructId const array_struct_id = TRY((((program)->find_struct_in_prelude(Jakt::DeprecatedString("Array"sv)))));
types::StructId const dictionary_struct_id = TRY((((program)->find_struct_in_prelude(Jakt::DeprecatedString("Dictionary"sv)))));
types::StructId const optional_struct_id = TRY((((program)->find_struct_in_prelude(Jakt::DeprecatedString("Optional"sv)))));
types::StructId const range_struct_id = TRY((((program)->find_struct_in_prelude(Jakt::DeprecatedString("Range"sv)))));
types::StructId const set_struct_id = TRY((((program)->find_struct_in_prelude(Jakt::DeprecatedString("Set"sv)))));
types::StructId const tuple_struct_id = TRY((((program)->find_struct_in_prelude(Jakt::DeprecatedString("Tuple"sv)))));
types::StructId const weak_ptr_struct_id = TRY((((program)->find_struct_in_prelude(Jakt::DeprecatedString("WeakPtr"sv)))));
NonnullRefPtr<typename types::Type> const type = ((program)->get_type(type_id));
return (JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<DeprecatedString, ErrorOr<DeprecatedString>>{
auto&& __jakt_match_variant = *type;
switch(__jakt_match_variant.index()) {
case 17: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::Type::Never>();
return JaktInternal::ExplicitValue(Jakt::DeprecatedString("never"sv));
};/*case end*/
case 0: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::Type::Void>();
return JaktInternal::ExplicitValue(Jakt::DeprecatedString("void"sv));
};/*case end*/
case 1: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::Type::Bool>();
return JaktInternal::ExplicitValue(Jakt::DeprecatedString("bool"sv));
};/*case end*/
case 2: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::Type::U8>();
return JaktInternal::ExplicitValue(Jakt::DeprecatedString("u8"sv));
};/*case end*/
case 3: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::Type::U16>();
return JaktInternal::ExplicitValue(Jakt::DeprecatedString("u16"sv));
};/*case end*/
case 4: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::Type::U32>();
return JaktInternal::ExplicitValue(Jakt::DeprecatedString("u32"sv));
};/*case end*/
case 5: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::Type::U64>();
return JaktInternal::ExplicitValue(Jakt::DeprecatedString("u64"sv));
};/*case end*/
case 6: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::Type::I8>();
return JaktInternal::ExplicitValue(Jakt::DeprecatedString("i8"sv));
};/*case end*/
case 7: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::Type::I16>();
return JaktInternal::ExplicitValue(Jakt::DeprecatedString("i16"sv));
};/*case end*/
case 8: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::Type::I32>();
return JaktInternal::ExplicitValue(Jakt::DeprecatedString("i32"sv));
};/*case end*/
case 9: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::Type::I64>();
return JaktInternal::ExplicitValue(Jakt::DeprecatedString("i64"sv));
};/*case end*/
case 10: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::Type::F32>();
return JaktInternal::ExplicitValue(Jakt::DeprecatedString("f32"sv));
};/*case end*/
case 11: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::Type::F64>();
return JaktInternal::ExplicitValue(Jakt::DeprecatedString("f64"sv));
};/*case end*/
case 12: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::Type::Usize>();
return JaktInternal::ExplicitValue(Jakt::DeprecatedString("usize"sv));
};/*case end*/
case 13: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::Type::JaktString>();
return JaktInternal::ExplicitValue(Jakt::DeprecatedString("String"sv));
};/*case end*/
case 15: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::Type::CInt>();
return JaktInternal::ExplicitValue(Jakt::DeprecatedString("c_int"sv));
};/*case end*/
case 14: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::Type::CChar>();
return JaktInternal::ExplicitValue(Jakt::DeprecatedString("c_char"sv));
};/*case end*/
case 18: {
auto&& __jakt_match_value = __jakt_match_variant.template get<types::Type::TypeVariable>();DeprecatedString const& name = __jakt_match_value.name;
return JaktInternal::ExplicitValue(name);
};/*case end*/
case 16: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::Type::Unknown>();
return JaktInternal::ExplicitValue(Jakt::DeprecatedString(""sv));
};/*case end*/
case 30: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::Type::Self>();
return JaktInternal::ExplicitValue(Jakt::DeprecatedString("Self"sv));
};/*case end*/
case 26: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::Type::Trait>();
types::TraitId const& trait_id = __jakt_match_value.value;
return JaktInternal::ExplicitValue(((((program)->get_trait(trait_id)))->name));
};/*case end*/
case 29: {
auto&& __jakt_match_value = __jakt_match_variant.template get<types::Type::Function>();JaktInternal::DynamicArray<types::TypeId> const& params = __jakt_match_value.params;
types::TypeId const& return_type_id = __jakt_match_value.return_type_id;
return JaktInternal::ExplicitValue(({ Optional<DeprecatedString> __jakt_var_724; {
JaktInternal::DynamicArray<DeprecatedString> param_names = (TRY((DynamicArray<DeprecatedString>::create_with({}))));
{
JaktInternal::ArrayIterator<types::TypeId> _magic = ((params).iterator());
for (;;){
JaktInternal::Optional<types::TypeId> _magic_value = ((_magic).next());
if ((!(((_magic_value).has_value())))){
break;
}
types::TypeId x = (_magic_value.value());
{
TRY((((param_names).push(TRY((((program)->type_name(x,false))))))));
}

}
}

DeprecatedString const return_type = TRY((((program)->type_name(return_type_id,false))));
__jakt_var_724 = TRY((__jakt_format(Jakt::DeprecatedString("function({}) -> {}"sv),utility::join(param_names,Jakt::DeprecatedString(", "sv)),return_type))); goto __jakt_label_647;

}
__jakt_label_647:; __jakt_var_724.release_value(); }));
};/*case end*/
case 25: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::Type::RawPtr>();
types::TypeId const& type_id = __jakt_match_value.value;
return JaktInternal::ExplicitValue((Jakt::DeprecatedString("raw "sv) + TRY((ide::get_type_signature(program,type_id)))));
};/*case end*/
case 24: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::Type::Enum>();
types::EnumId const& id = __jakt_match_value.value;
return JaktInternal::ExplicitValue(({ Optional<DeprecatedString> __jakt_var_725; {
types::CheckedEnum const enum_ = ((program)->get_enum(id));
__jakt_var_725 = ((JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<DeprecatedString,ErrorOr<DeprecatedString>>{
auto __jakt_enum_value = (((enum_).is_boxed));
if (__jakt_enum_value == true) {
return JaktInternal::ExplicitValue(Jakt::DeprecatedString("boxed "sv));
}
else {
return JaktInternal::ExplicitValue(Jakt::DeprecatedString(""sv));
}
}()))
 + Jakt::DeprecatedString("enum "sv)) + ((enum_).name)); goto __jakt_label_648;

}
__jakt_label_648:; __jakt_var_725.release_value(); }));
};/*case end*/
case 23: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::Type::Struct>();
types::StructId const& id = __jakt_match_value.value;
return JaktInternal::ExplicitValue(({ Optional<DeprecatedString> __jakt_var_726; {
types::CheckedStruct const struct_ = ((program)->get_struct(id));
__jakt_var_726 = (JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<DeprecatedString, ErrorOr<DeprecatedString>>{
auto&& __jakt_match_variant = ((struct_).record_type);
switch(__jakt_match_variant.index()) {
case 1: {
auto&& __jakt_match_value = __jakt_match_variant.template get<parser::RecordType::Class>();return JaktInternal::ExplicitValue(Jakt::DeprecatedString("class "sv));
};/*case end*/
case 0: {
auto&& __jakt_match_value = __jakt_match_variant.template get<parser::RecordType::Struct>();return JaktInternal::ExplicitValue(Jakt::DeprecatedString("struct "sv));
};/*case end*/
default: {
{
utility::panic(Jakt::DeprecatedString("unreachable: should've been struct"sv));
}
};/*case end*/
}/*switch end*/
}()
)) + ((struct_).name)); goto __jakt_label_649;

}
__jakt_label_649:; __jakt_var_726.release_value(); }));
};/*case end*/
case 22: {
auto&& __jakt_match_value = __jakt_match_variant.template get<types::Type::GenericResolvedType>();types::StructId const& id = __jakt_match_value.id;
JaktInternal::DynamicArray<types::TypeId> const& args = __jakt_match_value.args;
return JaktInternal::ExplicitValue(({ Optional<DeprecatedString> __jakt_var_727; {
types::CheckedStruct const record = ((program)->get_struct(id));
DeprecatedString output = ((record).name);
(output += Jakt::DeprecatedString("<"sv));
if ((!(((args).is_empty())))){
(output += TRY((ide::get_type_signature(program,((args)[static_cast<i64>(0LL)])))));
{
JaktInternal::Range<size_t> _magic = (JaktInternal::Range<size_t>{static_cast<size_t>(static_cast<size_t>(1ULL)),static_cast<size_t>(((args).size()))});
for (;;){
JaktInternal::Optional<size_t> _magic_value = ((_magic).next());
if ((!(((_magic_value).has_value())))){
break;
}
size_t i = (_magic_value.value());
{
(output += Jakt::DeprecatedString(", "sv));
(output += TRY((ide::get_type_signature(program,((args)[i])))));
}

}
}

}
__jakt_var_727 = (output + Jakt::DeprecatedString(">"sv)); goto __jakt_label_650;

}
__jakt_label_650:; __jakt_var_727.release_value(); }));
};/*case end*/
case 20: {
auto&& __jakt_match_value = __jakt_match_variant.template get<types::Type::GenericEnumInstance>();types::EnumId const& id = __jakt_match_value.id;
JaktInternal::DynamicArray<types::TypeId> const& args = __jakt_match_value.args;
return JaktInternal::ExplicitValue(({ Optional<DeprecatedString> __jakt_var_728; {
types::CheckedEnum const enum_ = ((program)->get_enum(id));
DeprecatedString output = Jakt::DeprecatedString(""sv);
if (((enum_).is_boxed)){
(output += Jakt::DeprecatedString("boxed "sv));
}
(output += Jakt::DeprecatedString("enum "sv));
(output += ((enum_).name));
(output += Jakt::DeprecatedString("<"sv));
if ((!(((args).is_empty())))){
(output += TRY((ide::get_type_signature(program,((args)[static_cast<i64>(0LL)])))));
{
JaktInternal::Range<size_t> _magic = (JaktInternal::Range<size_t>{static_cast<size_t>(static_cast<size_t>(1ULL)),static_cast<size_t>(((args).size()))});
for (;;){
JaktInternal::Optional<size_t> _magic_value = ((_magic).next());
if ((!(((_magic_value).has_value())))){
break;
}
size_t i = (_magic_value.value());
{
(output += Jakt::DeprecatedString(", "sv));
(output += TRY((ide::get_type_signature(program,((args)[i])))));
}

}
}

}
__jakt_var_728 = (output + Jakt::DeprecatedString(">"sv)); goto __jakt_label_651;

}
__jakt_label_651:; __jakt_var_728.release_value(); }));
};/*case end*/
case 21: {
auto&& __jakt_match_value = __jakt_match_variant.template get<types::Type::GenericTraitInstance>();types::TraitId const& id = __jakt_match_value.id;
JaktInternal::DynamicArray<types::TypeId> const& args = __jakt_match_value.args;
return JaktInternal::ExplicitValue(({ Optional<DeprecatedString> __jakt_var_729; {
NonnullRefPtr<types::CheckedTrait> const trait_ = ((program)->get_trait(id));
DeprecatedString output = Jakt::DeprecatedString(""sv);
(output += Jakt::DeprecatedString("trait "sv));
(output += ((trait_)->name));
(output += Jakt::DeprecatedString("<"sv));
if ((!(((args).is_empty())))){
(output += TRY((ide::get_type_signature(program,((args)[static_cast<i64>(0LL)])))));
{
JaktInternal::Range<size_t> _magic = (JaktInternal::Range<size_t>{static_cast<size_t>(static_cast<size_t>(1ULL)),static_cast<size_t>(((args).size()))});
for (;;){
JaktInternal::Optional<size_t> _magic_value = ((_magic).next());
if ((!(((_magic_value).has_value())))){
break;
}
size_t i = (_magic_value.value());
{
(output += Jakt::DeprecatedString(", "sv));
(output += TRY((ide::get_type_signature(program,((args)[i])))));
}

}
}

}
__jakt_var_729 = (output + Jakt::DeprecatedString(">"sv)); goto __jakt_label_652;

}
__jakt_label_652:; __jakt_var_729.release_value(); }));
};/*case end*/
case 19: {
auto&& __jakt_match_value = __jakt_match_variant.template get<types::Type::GenericInstance>();types::StructId const& id = __jakt_match_value.id;
JaktInternal::DynamicArray<types::TypeId> const& args = __jakt_match_value.args;
return JaktInternal::ExplicitValue(({ Optional<DeprecatedString> __jakt_var_730; {
if (((id).equals(array_struct_id))){
if (((args).is_empty())){
return (Jakt::DeprecatedString("[]"sv));
}
return (TRY((__jakt_format(Jakt::DeprecatedString("[{}]"sv),TRY((ide::get_type_signature(program,((args)[static_cast<i64>(0LL)]))))))));
}
if (((id).equals(dictionary_struct_id))){
if ((((args).size()) < static_cast<size_t>(2ULL))){
return (Jakt::DeprecatedString("[:]"sv));
}
return (TRY((__jakt_format(Jakt::DeprecatedString("[{}: {}]"sv),TRY((ide::get_type_signature(program,((args)[static_cast<i64>(0LL)])))),TRY((ide::get_type_signature(program,((args)[static_cast<i64>(1LL)]))))))));
}
if (((id).equals(optional_struct_id))){
if (((args).is_empty())){
return (Jakt::DeprecatedString(""sv));
}
return (TRY((__jakt_format(Jakt::DeprecatedString("{}?"sv),TRY((ide::get_type_signature(program,((args)[static_cast<i64>(0LL)]))))))));
}
if (((id).equals(range_struct_id))){
if (((args).is_empty())){
return (Jakt::DeprecatedString(""sv));
}
return (TRY((__jakt_format(Jakt::DeprecatedString("{}..{}"sv),TRY((ide::get_type_signature(program,((args)[static_cast<i64>(0LL)])))),TRY((((program)->type_name(((args)[static_cast<i64>(0LL)]),false))))))));
}
if (((id).equals(set_struct_id))){
if (((args).is_empty())){
return (Jakt::DeprecatedString(""sv));
}
return (TRY((__jakt_format(Jakt::DeprecatedString("{{{}}}"sv),TRY((ide::get_type_signature(program,((args)[static_cast<i64>(0LL)]))))))));
}
if (((id).equals(tuple_struct_id))){
DeprecatedString output = Jakt::DeprecatedString("("sv);
if ((!(((args).is_empty())))){
(output += TRY((ide::get_type_signature(program,((args)[static_cast<i64>(0LL)])))));
{
JaktInternal::Range<size_t> _magic = (JaktInternal::Range<size_t>{static_cast<size_t>(static_cast<size_t>(1ULL)),static_cast<size_t>(((args).size()))});
for (;;){
JaktInternal::Optional<size_t> _magic_value = ((_magic).next());
if ((!(((_magic_value).has_value())))){
break;
}
size_t i = (_magic_value.value());
{
(output += Jakt::DeprecatedString(", "sv));
(output += TRY((ide::get_type_signature(program,((args)[i])))));
}

}
}

}
return ((output + Jakt::DeprecatedString(")"sv)));
}
if (((id).equals(weak_ptr_struct_id))){
if (((args).is_empty())){
return (Jakt::DeprecatedString(""sv));
}
return (TRY((__jakt_format(Jakt::DeprecatedString("weak {}?"sv),TRY((ide::get_type_signature(program,((args)[static_cast<i64>(0LL)]))))))));
}
types::CheckedStruct const record = ((program)->get_struct(id));
DeprecatedString output = JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<DeprecatedString, ErrorOr<DeprecatedString>>{
auto&& __jakt_match_variant = ((record).record_type);
switch(__jakt_match_variant.index()) {
case 1: {
auto&& __jakt_match_value = __jakt_match_variant.template get<parser::RecordType::Class>();return JaktInternal::ExplicitValue(Jakt::DeprecatedString("class "sv));
};/*case end*/
case 0: {
auto&& __jakt_match_value = __jakt_match_variant.template get<parser::RecordType::Struct>();return JaktInternal::ExplicitValue(Jakt::DeprecatedString("struct "sv));
};/*case end*/
case 2: {
auto&& __jakt_match_value = __jakt_match_variant.template get<parser::RecordType::ValueEnum>();{
utility::panic(Jakt::DeprecatedString("unreachable: can't be an enum"sv));
}
};/*case end*/
case 3: {
auto&& __jakt_match_value = __jakt_match_variant.template get<parser::RecordType::SumEnum>();{
utility::panic(Jakt::DeprecatedString("unreachable: can't be an enum"sv));
}
};/*case end*/
case 4: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename parser::RecordType::Garbage>();
return JaktInternal::ExplicitValue(Jakt::DeprecatedString(""sv));
};/*case end*/
default: VERIFY_NOT_REACHED();}/*switch end*/
}()
));
(output += ((record).name));
(output += Jakt::DeprecatedString("<"sv));
if ((!(((args).is_empty())))){
(output += TRY((ide::get_type_signature(program,((args)[static_cast<i64>(0LL)])))));
{
JaktInternal::Range<size_t> _magic = (JaktInternal::Range<size_t>{static_cast<size_t>(static_cast<size_t>(1ULL)),static_cast<size_t>(((args).size()))});
for (;;){
JaktInternal::Optional<size_t> _magic_value = ((_magic).next());
if ((!(((_magic_value).has_value())))){
break;
}
size_t i = (_magic_value.value());
{
(output += Jakt::DeprecatedString(", "sv));
(output += TRY((ide::get_type_signature(program,((args)[i])))));
}

}
}

}
__jakt_var_730 = (output + Jakt::DeprecatedString(">"sv)); goto __jakt_label_653;

}
__jakt_label_653:; __jakt_var_730.release_value(); }));
};/*case end*/
case 27: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::Type::Reference>();
types::TypeId const& type_id = __jakt_match_value.value;
return JaktInternal::ExplicitValue(TRY((__jakt_format(Jakt::DeprecatedString("&{}"sv),TRY((((program)->type_name(type_id,false))))))));
};/*case end*/
case 28: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::Type::MutableReference>();
types::TypeId const& type_id = __jakt_match_value.value;
return JaktInternal::ExplicitValue(TRY((__jakt_format(Jakt::DeprecatedString("&mut {}"sv),TRY((((program)->type_name(type_id,false))))))));
};/*case end*/
default: VERIFY_NOT_REACHED();}/*switch end*/
}()
)));
}
}

ErrorOr<JaktInternal::Optional<ide::Usage>> find_span_in_scope(NonnullRefPtr<types::CheckedProgram> const program,NonnullRefPtr<types::Scope> const scope,utility::Span const span) {
{
{
JaktInternal::DictionaryIterator<DeprecatedString,types::VarId> _magic = ((((scope)->vars)).iterator());
for (;;){
JaktInternal::Optional<JaktInternal::Tuple<DeprecatedString,types::VarId>> _magic_value = ((_magic).next());
if ((!(((_magic_value).has_value())))){
break;
}
JaktInternal::Tuple<DeprecatedString,types::VarId> scope_var = (_magic_value.value());
{
NonnullRefPtr<types::CheckedVariable> const var = ((program)->get_variable(((scope_var).template get<1>())));
if (((((var)->definition_span)).contains(span))){
return (static_cast<JaktInternal::Optional<ide::Usage>>( ide::Usage { typename ide::Usage::Typename(((var)->type_id)) } ));
}
}

}
}

{
JaktInternal::DictionaryIterator<DeprecatedString,JaktInternal::DynamicArray<types::FunctionId>> _magic = ((((scope)->functions)).iterator());
for (;;){
JaktInternal::Optional<JaktInternal::Tuple<DeprecatedString,JaktInternal::DynamicArray<types::FunctionId>>> _magic_value = ((_magic).next());
if ((!(((_magic_value).has_value())))){
break;
}
JaktInternal::Tuple<DeprecatedString,JaktInternal::DynamicArray<types::FunctionId>> ___overload_set__ = (_magic_value.value());
{
JaktInternal::Tuple<DeprecatedString,JaktInternal::DynamicArray<types::FunctionId>> const jakt_____overload_set__ = ___overload_set__;
DeprecatedString const _ = ((jakt_____overload_set__).template get<0>());
JaktInternal::DynamicArray<types::FunctionId> const overload_set = ((jakt_____overload_set__).template get<1>());

{
JaktInternal::ArrayIterator<types::FunctionId> _magic = ((overload_set).iterator());
for (;;){
JaktInternal::Optional<types::FunctionId> _magic_value = ((_magic).next());
if ((!(((_magic_value).has_value())))){
break;
}
types::FunctionId function_id = (_magic_value.value());
{
NonnullRefPtr<types::CheckedFunction> const checked_function = ((program)->get_function(function_id));
JaktInternal::Optional<ide::Usage> const usage = TRY((ide::find_span_in_function(program,checked_function,span)));
if (((usage).has_value())){
return ((usage.value()));
}
}

}
}

}

}
}

{
JaktInternal::DictionaryIterator<DeprecatedString,types::StructId> _magic = ((((scope)->structs)).iterator());
for (;;){
JaktInternal::Optional<JaktInternal::Tuple<DeprecatedString,types::StructId>> _magic_value = ((_magic).next());
if ((!(((_magic_value).has_value())))){
break;
}
JaktInternal::Tuple<DeprecatedString,types::StructId> struct_id = (_magic_value.value());
{
types::CheckedStruct const checked_struct = ((program)->get_struct(((struct_id).template get<1>())));
JaktInternal::Optional<ide::Usage> const usage = TRY((ide::find_span_in_struct(program,checked_struct,span)));
if (((usage).has_value())){
return ((usage.value()));
}
}

}
}

{
JaktInternal::DictionaryIterator<DeprecatedString,types::EnumId> _magic = ((((scope)->enums)).iterator());
for (;;){
JaktInternal::Optional<JaktInternal::Tuple<DeprecatedString,types::EnumId>> _magic_value = ((_magic).next());
if ((!(((_magic_value).has_value())))){
break;
}
JaktInternal::Tuple<DeprecatedString,types::EnumId> enum_id = (_magic_value.value());
{
types::CheckedEnum const checked_enum = ((program)->get_enum(((enum_id).template get<1>())));
JaktInternal::Optional<ide::Usage> const usage = TRY((ide::find_span_in_enum(program,checked_enum,span)));
if (((usage).has_value())){
return ((usage.value()));
}
}

}
}

{
JaktInternal::ArrayIterator<types::ScopeId> _magic = ((((scope)->children)).iterator());
for (;;){
JaktInternal::Optional<types::ScopeId> _magic_value = ((_magic).next());
if ((!(((_magic_value).has_value())))){
break;
}
types::ScopeId child = (_magic_value.value());
{
NonnullRefPtr<types::Scope> const scope = TRY((((program)->get_scope(child))));
JaktInternal::Optional<ide::Usage> const usage = TRY((ide::find_span_in_scope(program,scope,span)));
if (((usage).has_value())){
return ((usage.value()));
}
}

}
}

return (JaktInternal::OptionalNone());
}
}

ErrorOr<DeprecatedString> get_constructor_signature(NonnullRefPtr<types::CheckedProgram> const program,types::FunctionId const function_id) {
{
NonnullRefPtr<types::CheckedFunction> const checked_function = ((program)->get_function(function_id));
types::TypeId const type_id = ((checked_function)->return_type_id);
NonnullRefPtr<types::Module> const mod = ((((program)->modules))[((((type_id).module)).id)]);
{
JaktInternal::ArrayIterator<types::CheckedStruct> _magic = ((((mod)->structures)).iterator());
for (;;){
JaktInternal::Optional<types::CheckedStruct> _magic_value = ((_magic).next());
if ((!(((_magic_value).has_value())))){
break;
}
types::CheckedStruct struct_ = (_magic_value.value());
{
if (((((struct_).type_id)).equals(type_id))){
DeprecatedString output = TRY((ide::get_type_signature(program,type_id)));
(output += Jakt::DeprecatedString("("sv));
bool first = true;
{
JaktInternal::ArrayIterator<types::CheckedField> _magic = ((((struct_).fields)).iterator());
for (;;){
JaktInternal::Optional<types::CheckedField> _magic_value = ((_magic).next());
if ((!(((_magic_value).has_value())))){
break;
}
types::CheckedField field = (_magic_value.value());
{
if (first){
(first = false);
}
else {
(output += Jakt::DeprecatedString(", "sv));
}

NonnullRefPtr<types::CheckedVariable> const variable = ((program)->get_variable(((field).variable_id)));
if (((variable)->is_mutable)){
(output += Jakt::DeprecatedString("mut "sv));
}
(output += TRY((__jakt_format(Jakt::DeprecatedString("{}: {}"sv),((variable)->name),TRY((((program)->type_name(((variable)->type_id),false))))))));
}

}
}

(output += Jakt::DeprecatedString(")"sv));
return (output);
}
}

}
}

return (Jakt::DeprecatedString(""sv));
}
}

ErrorOr<JaktInternal::DynamicArray<DeprecatedString>> find_dot_completions(NonnullRefPtr<types::CheckedProgram> const program,utility::Span const span) {
{
JaktInternal::Optional<ide::Usage> const result = TRY((ide::find_span_in_program(program,span)));
if (((result).has_value())){
return (JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<JaktInternal::DynamicArray<DeprecatedString>, ErrorOr<JaktInternal::DynamicArray<DeprecatedString>>>{
auto&& __jakt_match_variant = (result.value());
switch(__jakt_match_variant.index()) {
case 0: {
auto&& __jakt_match_value = __jakt_match_variant.template get<ide::Usage::Variable>();types::TypeId const& type_id = __jakt_match_value.type_id;
return JaktInternal::ExplicitValue(({ Optional<JaktInternal::DynamicArray<DeprecatedString>> __jakt_var_731; {
__jakt_var_731 = TRY((ide::completions_for_type_id(program,type_id))); goto __jakt_label_654;

}
__jakt_label_654:; __jakt_var_731.release_value(); }));
};/*case end*/
case 1: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename ide::Usage::Call>();
types::FunctionId const& function_id = __jakt_match_value.value;
return JaktInternal::ExplicitValue(({ Optional<JaktInternal::DynamicArray<DeprecatedString>> __jakt_var_732; {
types::TypeId const result_type_id = ((((program)->get_function(function_id)))->return_type_id);
__jakt_var_732 = TRY((ide::completions_for_type_id(program,result_type_id))); goto __jakt_label_655;

}
__jakt_label_655:; __jakt_var_732.release_value(); }));
};/*case end*/
default: {
return JaktInternal::ExplicitValue((TRY((DynamicArray<DeprecatedString>::create_with({})))));
};/*case end*/
}/*switch end*/
}()
)));
}
else {
return ((TRY((DynamicArray<DeprecatedString>::create_with({})))));
}

}
}

ErrorOr<utility::Span> find_definition_in_program(NonnullRefPtr<types::CheckedProgram> const program,utility::Span const span) {
{
JaktInternal::Optional<ide::Usage> const result = TRY((ide::find_span_in_program(program,span)));
if (((result).has_value())){
return (JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<utility::Span, ErrorOr<utility::Span>>{
auto&& __jakt_match_variant = (result.value());
switch(__jakt_match_variant.index()) {
case 0: {
auto&& __jakt_match_value = __jakt_match_variant.template get<ide::Usage::Variable>();utility::Span const& span = __jakt_match_value.span;
return JaktInternal::ExplicitValue(span);
};/*case end*/
case 1: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename ide::Usage::Call>();
types::FunctionId const& function_id = __jakt_match_value.value;
return JaktInternal::ExplicitValue(((((program)->get_function(function_id)))->name_span));
};/*case end*/
case 2: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename ide::Usage::Typename>();
types::TypeId const& type_id = __jakt_match_value.value;
return JaktInternal::ExplicitValue(TRY((ide::find_type_definition_for_type_id(program,type_id,span))));
};/*case end*/
case 3: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename ide::Usage::NameSet>();
return JaktInternal::ExplicitValue(span);
};/*case end*/
case 4: {
auto&& __jakt_match_value = __jakt_match_variant.template get<ide::Usage::EnumVariant>();utility::Span const& span = __jakt_match_value.span;
return JaktInternal::ExplicitValue(span);
};/*case end*/
default: VERIFY_NOT_REACHED();}/*switch end*/
}()
)));
}
else {
return (span);
}

}
}

ErrorOr<DeprecatedString> get_var_signature(NonnullRefPtr<types::CheckedProgram> const program,DeprecatedString const name,types::TypeId const var_type_id,ide::Mutability const mutability,ide::VarType const var_type,ide::VarVisibility const visibility,JaktInternal::Optional<types::TypeId> const struct_type_id) {
{
return (JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<DeprecatedString, ErrorOr<DeprecatedString>>{
auto&& __jakt_match_variant = var_type;
switch(__jakt_match_variant.index()) {
case 0: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename ide::VarType::Variable>();
return JaktInternal::ExplicitValue(({ Optional<DeprecatedString> __jakt_var_733; {
DeprecatedString const mut_string = JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<DeprecatedString, ErrorOr<DeprecatedString>>{
auto&& __jakt_match_variant = mutability;
switch(__jakt_match_variant.index()) {
case 2: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename ide::Mutability::Mutable>();
return JaktInternal::ExplicitValue(Jakt::DeprecatedString("mut"sv));
};/*case end*/
case 1: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename ide::Mutability::Immutable>();
return JaktInternal::ExplicitValue(Jakt::DeprecatedString("let"sv));
};/*case end*/
default: {
return JaktInternal::ExplicitValue(Jakt::DeprecatedString(""sv));
};/*case end*/
}/*switch end*/
}()
));
DeprecatedString const type_name = TRY((ide::get_type_signature(program,var_type_id)));
__jakt_var_733 = TRY((__jakt_format(Jakt::DeprecatedString("{} {}: {}"sv),mut_string,name,type_name))); goto __jakt_label_656;

}
__jakt_label_656:; __jakt_var_733.release_value(); }));
};/*case end*/
case 1: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename ide::VarType::Field>();
{
DeprecatedString record_string = Jakt::DeprecatedString(""sv);
if (((struct_type_id).has_value())){
(record_string = TRY((ide::get_type_signature(program,(struct_type_id.value())))));
}
DeprecatedString const visibility_string = JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<DeprecatedString, ErrorOr<DeprecatedString>>{
auto&& __jakt_match_variant = visibility;
switch(__jakt_match_variant.index()) {
case 1: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename ide::VarVisibility::Public>();
return JaktInternal::ExplicitValue(Jakt::DeprecatedString("public "sv));
};/*case end*/
case 2: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename ide::VarVisibility::Private>();
return JaktInternal::ExplicitValue(Jakt::DeprecatedString("private "sv));
};/*case end*/
default: {
return JaktInternal::ExplicitValue(Jakt::DeprecatedString(""sv));
};/*case end*/
}/*switch end*/
}()
));
DeprecatedString const type_name = TRY((ide::get_type_signature(program,var_type_id)));
if ((record_string != Jakt::DeprecatedString(""sv))){
return (TRY((__jakt_format(Jakt::DeprecatedString("{}\\n\\t{}{}: {}"sv),record_string,visibility_string,name,type_name))));
}
else {
return (TRY((__jakt_format(Jakt::DeprecatedString("{}{}: {}"sv),visibility_string,name,type_name))));
}

}
};/*case end*/
default: VERIFY_NOT_REACHED();}/*switch end*/
}()
)));
}
}

ErrorOr<JaktInternal::DynamicArray<JaktInternal::Tuple<JaktInternal::Optional<DeprecatedString>,types::TypeId>>> enum_variant_fields(NonnullRefPtr<types::CheckedProgram> const program,types::CheckedEnumVariant const checked_enum_variant) {
{
return (JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<JaktInternal::DynamicArray<JaktInternal::Tuple<JaktInternal::Optional<DeprecatedString>,types::TypeId>>, ErrorOr<JaktInternal::DynamicArray<JaktInternal::Tuple<JaktInternal::Optional<DeprecatedString>,types::TypeId>>>>{
auto&& __jakt_match_variant = checked_enum_variant;
switch(__jakt_match_variant.index()) {
case 3: {
auto&& __jakt_match_value = __jakt_match_variant.template get<types::CheckedEnumVariant::StructLike>();JaktInternal::DynamicArray<types::VarId> const& fields = __jakt_match_value.fields;
return JaktInternal::ExplicitValue(({ Optional<JaktInternal::DynamicArray<JaktInternal::Tuple<JaktInternal::Optional<DeprecatedString>,types::TypeId>>> __jakt_var_734; {
JaktInternal::DynamicArray<JaktInternal::Tuple<JaktInternal::Optional<DeprecatedString>,types::TypeId>> output = (TRY((DynamicArray<JaktInternal::Tuple<JaktInternal::Optional<DeprecatedString>,types::TypeId>>::create_with({}))));
{
JaktInternal::ArrayIterator<types::VarId> _magic = ((fields).iterator());
for (;;){
JaktInternal::Optional<types::VarId> _magic_value = ((_magic).next());
if ((!(((_magic_value).has_value())))){
break;
}
types::VarId field = (_magic_value.value());
{
NonnullRefPtr<types::CheckedVariable> const variable = ((program)->get_variable(field));
JaktInternal::Optional<DeprecatedString> const var_name = static_cast<JaktInternal::Optional<DeprecatedString>>(((variable)->name));
JaktInternal::Tuple<JaktInternal::Optional<DeprecatedString>,types::TypeId> const o = (Tuple{var_name, ((variable)->type_id)});
TRY((((output).push(o))));
}

}
}

__jakt_var_734 = output; goto __jakt_label_657;

}
__jakt_label_657:; __jakt_var_734.release_value(); }));
};/*case end*/
case 1: {
auto&& __jakt_match_value = __jakt_match_variant.template get<types::CheckedEnumVariant::Typed>();types::TypeId const& type_id = __jakt_match_value.type_id;
return JaktInternal::ExplicitValue(({ Optional<JaktInternal::DynamicArray<JaktInternal::Tuple<JaktInternal::Optional<DeprecatedString>,types::TypeId>>> __jakt_var_735; {
JaktInternal::Optional<DeprecatedString> const string_none = JaktInternal::OptionalNone();
__jakt_var_735 = (TRY((DynamicArray<JaktInternal::Tuple<JaktInternal::Optional<DeprecatedString>,types::TypeId>>::create_with({(Tuple{string_none, type_id})})))); goto __jakt_label_658;

}
__jakt_label_658:; __jakt_var_735.release_value(); }));
};/*case end*/
default: {
return JaktInternal::ExplicitValue((TRY((DynamicArray<JaktInternal::Tuple<JaktInternal::Optional<DeprecatedString>,types::TypeId>>::create_with({})))));
};/*case end*/
}/*switch end*/
}()
)));
}
}

ErrorOr<utility::Span> find_type_definition_in_program(NonnullRefPtr<types::CheckedProgram> const program,utility::Span const span) {
{
JaktInternal::Optional<ide::Usage> const result = TRY((ide::find_span_in_program(program,span)));
if (((result).has_value())){
return (JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<utility::Span, ErrorOr<utility::Span>>{
auto&& __jakt_match_variant = (result.value());
switch(__jakt_match_variant.index()) {
case 0: {
auto&& __jakt_match_value = __jakt_match_variant.template get<ide::Usage::Variable>();utility::Span const& span = __jakt_match_value.span;
types::TypeId const& type_id = __jakt_match_value.type_id;
return JaktInternal::ExplicitValue(({ Optional<utility::Span> __jakt_var_736; {
__jakt_var_736 = TRY((ide::find_type_definition_for_type_id(program,type_id,span))); goto __jakt_label_659;

}
__jakt_label_659:; __jakt_var_736.release_value(); }));
};/*case end*/
case 1: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename ide::Usage::Call>();
types::FunctionId const& function_id = __jakt_match_value.value;
return JaktInternal::ExplicitValue(({ Optional<utility::Span> __jakt_var_737; {
__jakt_var_737 = ((((program)->get_function(function_id)))->name_span); goto __jakt_label_660;

}
__jakt_label_660:; __jakt_var_737.release_value(); }));
};/*case end*/
case 2: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename ide::Usage::Typename>();
types::TypeId const& type_id = __jakt_match_value.value;
return JaktInternal::ExplicitValue(({ Optional<utility::Span> __jakt_var_738; {
__jakt_var_738 = TRY((ide::find_type_definition_for_type_id(program,type_id,span))); goto __jakt_label_661;

}
__jakt_label_661:; __jakt_var_738.release_value(); }));
};/*case end*/
case 3: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename ide::Usage::NameSet>();
return JaktInternal::ExplicitValue(span);
};/*case end*/
case 4: {
auto&& __jakt_match_value = __jakt_match_variant.template get<ide::Usage::EnumVariant>();utility::Span const& span = __jakt_match_value.span;
return JaktInternal::ExplicitValue(span);
};/*case end*/
default: VERIFY_NOT_REACHED();}/*switch end*/
}()
)));
}
else {
return (span);
}

}
}

ErrorOr<JaktInternal::Optional<ide::Usage>> find_span_in_expression(NonnullRefPtr<types::CheckedProgram> const program,NonnullRefPtr<typename types::CheckedExpression> const expr,utility::Span const span) {
{
JaktInternal::Optional<ide::Usage> const none = JaktInternal::OptionalNone();
return (JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<JaktInternal::Optional<ide::Usage>, ErrorOr<JaktInternal::Optional<ide::Usage>>>{
auto&& __jakt_match_variant = *expr;
switch(__jakt_match_variant.index()) {
case 6: {
auto&& __jakt_match_value = __jakt_match_variant.template get<types::CheckedExpression::BinaryOp>();NonnullRefPtr<typename types::CheckedExpression> const& lhs = __jakt_match_value.lhs;
parser::BinaryOperator const& op = __jakt_match_value.op;
NonnullRefPtr<typename types::CheckedExpression> const& rhs = __jakt_match_value.rhs;
return JaktInternal::ExplicitValue(({ Optional<JaktInternal::Optional<ide::Usage>> __jakt_var_739; {
JaktInternal::Optional<ide::Usage> const found = TRY((ide::find_span_in_expression(program,lhs,span)));
if (((found).has_value())){
return (found);
}
__jakt_var_739 = TRY((ide::find_span_in_expression(program,rhs,span))); goto __jakt_label_662;

}
__jakt_label_662:; __jakt_var_739.release_value(); }));
};/*case end*/
case 9: {
auto&& __jakt_match_value = __jakt_match_variant.template get<types::CheckedExpression::JaktArray>();JaktInternal::DynamicArray<NonnullRefPtr<typename types::CheckedExpression>> const& vals = __jakt_match_value.vals;
JaktInternal::Optional<NonnullRefPtr<typename types::CheckedExpression>> const& repeat = __jakt_match_value.repeat;
return JaktInternal::ExplicitValue(({ Optional<JaktInternal::Optional<ide::Usage>> __jakt_var_740; {
{
JaktInternal::ArrayIterator<NonnullRefPtr<typename types::CheckedExpression>> _magic = ((vals).iterator());
for (;;){
JaktInternal::Optional<NonnullRefPtr<typename types::CheckedExpression>> _magic_value = ((_magic).next());
if ((!(((_magic_value).has_value())))){
break;
}
NonnullRefPtr<typename types::CheckedExpression> val = (_magic_value.value());
{
JaktInternal::Optional<ide::Usage> const found = TRY((ide::find_span_in_expression(program,val,span)));
if (((found).has_value())){
return (found);
}
}

}
}

if (((repeat).has_value())){
return (TRY((ide::find_span_in_expression(program,(repeat.value()),span))));
}
__jakt_var_740 = none; goto __jakt_label_663;

}
__jakt_label_663:; __jakt_var_740.release_value(); }));
};/*case end*/
case 26: {
auto&& __jakt_match_value = __jakt_match_variant.template get<types::CheckedExpression::Block>();types::CheckedBlock const& block = __jakt_match_value.block;
return JaktInternal::ExplicitValue(TRY((ide::find_span_in_block(program,block,span))));
};/*case end*/
case 19: {
auto&& __jakt_match_value = __jakt_match_variant.template get<types::CheckedExpression::Call>();types::CheckedCall const& call = __jakt_match_value.call;
utility::Span const& call_span = __jakt_match_value.span;
return JaktInternal::ExplicitValue(({ Optional<JaktInternal::Optional<ide::Usage>> __jakt_var_741; {
{
JaktInternal::ArrayIterator<JaktInternal::Tuple<DeprecatedString,NonnullRefPtr<typename types::CheckedExpression>>> _magic = ((((call).args)).iterator());
for (;;){
JaktInternal::Optional<JaktInternal::Tuple<DeprecatedString,NonnullRefPtr<typename types::CheckedExpression>>> _magic_value = ((_magic).next());
if ((!(((_magic_value).has_value())))){
break;
}
JaktInternal::Tuple<DeprecatedString,NonnullRefPtr<typename types::CheckedExpression>> ___expr__ = (_magic_value.value());
{
JaktInternal::Tuple<DeprecatedString,NonnullRefPtr<typename types::CheckedExpression>> const jakt_____expr__ = ___expr__;
DeprecatedString const _ = ((jakt_____expr__).template get<0>());
NonnullRefPtr<typename types::CheckedExpression> const expr = ((jakt_____expr__).template get<1>());

JaktInternal::Optional<ide::Usage> const found = TRY((ide::find_span_in_expression(program,expr,span)));
if (((found).has_value())){
return (found);
}
}

}
}

if ((((((call).function_id)).has_value()) && ((call_span).contains(span)))){
return (static_cast<JaktInternal::Optional<ide::Usage>>( ide::Usage { typename ide::Usage::Call((((call).function_id).value())) } ));
}
__jakt_var_741 = none; goto __jakt_label_664;

}
__jakt_label_664:; __jakt_var_741.release_value(); }));
};/*case end*/
case 11: {
auto&& __jakt_match_value = __jakt_match_variant.template get<types::CheckedExpression::JaktDictionary>();JaktInternal::DynamicArray<JaktInternal::Tuple<NonnullRefPtr<typename types::CheckedExpression>,NonnullRefPtr<typename types::CheckedExpression>>> const& vals = __jakt_match_value.vals;
return JaktInternal::ExplicitValue(({ Optional<JaktInternal::Optional<ide::Usage>> __jakt_var_742; {
{
JaktInternal::ArrayIterator<JaktInternal::Tuple<NonnullRefPtr<typename types::CheckedExpression>,NonnullRefPtr<typename types::CheckedExpression>>> _magic = ((vals).iterator());
for (;;){
JaktInternal::Optional<JaktInternal::Tuple<NonnullRefPtr<typename types::CheckedExpression>,NonnullRefPtr<typename types::CheckedExpression>>> _magic_value = ((_magic).next());
if ((!(((_magic_value).has_value())))){
break;
}
JaktInternal::Tuple<NonnullRefPtr<typename types::CheckedExpression>,NonnullRefPtr<typename types::CheckedExpression>> key__value__ = (_magic_value.value());
{
JaktInternal::Tuple<NonnullRefPtr<typename types::CheckedExpression>,NonnullRefPtr<typename types::CheckedExpression>> const jakt__key__value__ = key__value__;
NonnullRefPtr<typename types::CheckedExpression> const key = ((jakt__key__value__).template get<0>());
NonnullRefPtr<typename types::CheckedExpression> const value = ((jakt__key__value__).template get<1>());

JaktInternal::Optional<ide::Usage> found = TRY((ide::find_span_in_expression(program,key,span)));
if (((found).has_value())){
return (found);
}
(found = TRY((ide::find_span_in_expression(program,value,span))));
if (((found).has_value())){
return (found);
}
}

}
}

__jakt_var_742 = none; goto __jakt_label_665;

}
__jakt_label_665:; __jakt_var_742.release_value(); }));
};/*case end*/
case 12: {
auto&& __jakt_match_value = __jakt_match_variant.template get<types::CheckedExpression::IndexedExpression>();NonnullRefPtr<typename types::CheckedExpression> const& expr = __jakt_match_value.expr;
NonnullRefPtr<typename types::CheckedExpression> const& index = __jakt_match_value.index;
return JaktInternal::ExplicitValue(({ Optional<JaktInternal::Optional<ide::Usage>> __jakt_var_743; {
JaktInternal::Optional<ide::Usage> found = TRY((ide::find_span_in_expression(program,expr,span)));
if (((found).has_value())){
return (found);
}
(found = TRY((ide::find_span_in_expression(program,index,span))));
if (((found).has_value())){
return (found);
}
__jakt_var_743 = none; goto __jakt_label_666;

}
__jakt_label_666:; __jakt_var_743.release_value(); }));
};/*case end*/
case 15: {
auto&& __jakt_match_value = __jakt_match_variant.template get<types::CheckedExpression::IndexedStruct>();NonnullRefPtr<typename types::CheckedExpression> const& expr = __jakt_match_value.expr;
DeprecatedString const& index = __jakt_match_value.index;
utility::Span const& index_span = __jakt_match_value.span;
types::TypeId const& known_type_id = __jakt_match_value.type_id;
return JaktInternal::ExplicitValue(({ Optional<JaktInternal::Optional<ide::Usage>> __jakt_var_744; {
JaktInternal::Optional<ide::Usage> const found = TRY((ide::find_span_in_expression(program,expr,span)));
if (((found).has_value())){
return (found);
}
if (((index_span).contains(span))){
types::TypeId const type_id = ((expr)->type());
JaktInternal::Optional<types::TypeId> result_type = JaktInternal::OptionalNone();
if ((!(((known_type_id).equals(types::unknown_type_id()))))){
(result_type = static_cast<JaktInternal::Optional<types::TypeId>>(known_type_id));
}
if (((((program)->get_type(type_id)))->index() == 23 /* Struct */)){
types::StructId const struct_id = ((((program)->get_type(type_id)))->get<types::Type::Struct>()).value;
{
JaktInternal::ArrayIterator<types::CheckedField> _magic = ((((((program)->get_struct(struct_id))).fields)).iterator());
for (;;){
JaktInternal::Optional<types::CheckedField> _magic_value = ((_magic).next());
if ((!(((_magic_value).has_value())))){
break;
}
types::CheckedField field = (_magic_value.value());
{
NonnullRefPtr<types::CheckedVariable> const var = ((program)->get_variable(((field).variable_id)));
if ((index != ((var)->name))){
continue;
}
return ( ide::Usage { typename ide::Usage::Variable(((var)->definition_span),index,result_type.value_or_lazy_evaluated([&] { return ((var)->type_id); }), ide::Mutability { typename ide::Mutability::DoesNotApply() } , ide::VarType { typename ide::VarType::Field() } ,JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_AT_LOOP(([&]() -> JaktInternal::ExplicitValueOrControlFlow<ide::VarVisibility, ErrorOr<JaktInternal::Optional<ide::Usage>>>{
auto&& __jakt_match_variant = ((var)->visibility);
switch(__jakt_match_variant.index()) {
case 0: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::CheckedVisibility::Public>();
return JaktInternal::ExplicitValue( ide::VarVisibility { typename ide::VarVisibility::Public() } );
};/*case end*/
case 1: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::CheckedVisibility::Private>();
return JaktInternal::ExplicitValue( ide::VarVisibility { typename ide::VarVisibility::Private() } );
};/*case end*/
case 2: {
auto&& __jakt_match_value = __jakt_match_variant.template get<types::CheckedVisibility::Restricted>();return JaktInternal::ExplicitValue( ide::VarVisibility { typename ide::VarVisibility::Restricted() } );
};/*case end*/
default: VERIFY_NOT_REACHED();}/*switch end*/
}()
)),type_id) } );
}

}
}

}
}
__jakt_var_744 = none; goto __jakt_label_667;

}
__jakt_label_667:; __jakt_var_744.release_value(); }));
};/*case end*/
case 13: {
auto&& __jakt_match_value = __jakt_match_variant.template get<types::CheckedExpression::IndexedDictionary>();NonnullRefPtr<typename types::CheckedExpression> const& expr = __jakt_match_value.expr;
NonnullRefPtr<typename types::CheckedExpression> const& index = __jakt_match_value.index;
return JaktInternal::ExplicitValue(({ Optional<JaktInternal::Optional<ide::Usage>> __jakt_var_745; {
JaktInternal::Optional<ide::Usage> const found = TRY((ide::find_span_in_expression(program,expr,span)));
if (((found).has_value())){
return (found);
}
__jakt_var_745 = TRY((ide::find_span_in_expression(program,index,span))); goto __jakt_label_668;

}
__jakt_label_668:; __jakt_var_745.release_value(); }));
};/*case end*/
case 17: {
auto&& __jakt_match_value = __jakt_match_variant.template get<types::CheckedExpression::Match>();NonnullRefPtr<typename types::CheckedExpression> const& expr = __jakt_match_value.expr;
JaktInternal::DynamicArray<types::CheckedMatchCase> const& match_cases = __jakt_match_value.match_cases;
utility::Span const& match_span = __jakt_match_value.span;
types::TypeId const& type_id = __jakt_match_value.type_id;
return JaktInternal::ExplicitValue(({ Optional<JaktInternal::Optional<ide::Usage>> __jakt_var_746; {
{
JaktInternal::ArrayIterator<types::CheckedMatchCase> _magic = ((match_cases).iterator());
for (;;){
JaktInternal::Optional<types::CheckedMatchCase> _magic_value = ((_magic).next());
if ((!(((_magic_value).has_value())))){
break;
}
types::CheckedMatchCase match_case = (_magic_value.value());
{
JaktInternal::Optional<ide::Usage> const found = JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_AT_LOOP(([&]() -> JaktInternal::ExplicitValueOrControlFlow<JaktInternal::Optional<ide::Usage>, ErrorOr<JaktInternal::Optional<ide::Usage>>>{
auto&& __jakt_match_variant = match_case;
switch(__jakt_match_variant.index()) {
case 0: {
auto&& __jakt_match_value = __jakt_match_variant.template get<types::CheckedMatchCase::EnumVariant>();DeprecatedString const& name = __jakt_match_value.name;
JaktInternal::DynamicArray<parser::EnumVariantPatternArgument> const& args = __jakt_match_value.args;
types::TypeId const& subject_type_id = __jakt_match_value.subject_type_id;
size_t const& index = __jakt_match_value.index;
types::ScopeId const& scope_id = __jakt_match_value.scope_id;
types::CheckedMatchBody const& body = __jakt_match_value.body;
utility::Span const& marker_span = __jakt_match_value.marker_span;
return JaktInternal::ExplicitValue(({ Optional<JaktInternal::Optional<ide::Usage>> __jakt_var_747; {
if (((marker_span).contains(span))){
return (static_cast<JaktInternal::Optional<ide::Usage>>(TRY((ide::get_enum_variant_usage_from_type_id_and_name(program,subject_type_id,name)))));
}
__jakt_var_747 = JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_AT_LOOP_NESTED_MATCH(([&]() -> JaktInternal::ExplicitValueOrControlFlow<JaktInternal::Optional<ide::Usage>, ErrorOr<JaktInternal::Optional<ide::Usage>>>{
auto&& __jakt_match_variant = body;
switch(__jakt_match_variant.index()) {
case 1: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::CheckedMatchBody::Block>();
types::CheckedBlock const& block = __jakt_match_value.value;
return JaktInternal::ExplicitValue(TRY((ide::find_span_in_block(program,block,span))));
};/*case end*/
case 0: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::CheckedMatchBody::Expression>();
NonnullRefPtr<typename types::CheckedExpression> const& expr = __jakt_match_value.value;
return JaktInternal::ExplicitValue(TRY((ide::find_span_in_expression(program,expr,span))));
};/*case end*/
default: VERIFY_NOT_REACHED();}/*switch end*/
}()
)); goto __jakt_label_670;

}
__jakt_label_670:; __jakt_var_747.release_value(); }));
};/*case end*/
case 1: {
auto&& __jakt_match_value = __jakt_match_variant.template get<types::CheckedMatchCase::Expression>();NonnullRefPtr<typename types::CheckedExpression> const& expr = __jakt_match_value.expression;
types::CheckedMatchBody const& body = __jakt_match_value.body;
return JaktInternal::ExplicitValue(({ Optional<JaktInternal::Optional<ide::Usage>> __jakt_var_748; {
JaktInternal::Optional<ide::Usage> const found = TRY((ide::find_span_in_expression(program,expr,span)));
if (((found).has_value())){
return (found);
}
__jakt_var_748 = JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_AT_LOOP_NESTED_MATCH(([&]() -> JaktInternal::ExplicitValueOrControlFlow<JaktInternal::Optional<ide::Usage>, ErrorOr<JaktInternal::Optional<ide::Usage>>>{
auto&& __jakt_match_variant = body;
switch(__jakt_match_variant.index()) {
case 1: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::CheckedMatchBody::Block>();
types::CheckedBlock const& block = __jakt_match_value.value;
return JaktInternal::ExplicitValue(TRY((ide::find_span_in_block(program,block,span))));
};/*case end*/
case 0: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::CheckedMatchBody::Expression>();
NonnullRefPtr<typename types::CheckedExpression> const& expr = __jakt_match_value.value;
return JaktInternal::ExplicitValue(TRY((ide::find_span_in_expression(program,expr,span))));
};/*case end*/
default: VERIFY_NOT_REACHED();}/*switch end*/
}()
)); goto __jakt_label_671;

}
__jakt_label_671:; __jakt_var_748.release_value(); }));
};/*case end*/
case 2: {
auto&& __jakt_match_value = __jakt_match_variant.template get<types::CheckedMatchCase::CatchAll>();types::CheckedMatchBody const& body = __jakt_match_value.body;
utility::Span const& marker_span = __jakt_match_value.marker_span;
return JaktInternal::ExplicitValue(JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_AT_LOOP_NESTED_MATCH(([&]() -> JaktInternal::ExplicitValueOrControlFlow<JaktInternal::Optional<ide::Usage>,ErrorOr<JaktInternal::Optional<ide::Usage>>>{
auto __jakt_enum_value = (((marker_span).contains(span)));
if (__jakt_enum_value == true) {
return JaktInternal::ExplicitValue(({ Optional<JaktInternal::Optional<ide::Usage>> __jakt_var_749; {
JaktInternal::Set<DeprecatedString> const all_cases = JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_AT_LOOP_NESTED_MATCH(([&]() -> JaktInternal::ExplicitValueOrControlFlow<JaktInternal::Set<DeprecatedString>, ErrorOr<JaktInternal::Optional<ide::Usage>>>{
auto&& __jakt_match_variant = *((program)->get_type(type_id));
switch(__jakt_match_variant.index()) {
case 24: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::Type::Enum>();
types::EnumId const& enum_id = __jakt_match_value.value;
return JaktInternal::ExplicitValue(({ Optional<JaktInternal::Set<DeprecatedString>> __jakt_var_750; {
JaktInternal::Set<DeprecatedString> names = (TRY((Set<DeprecatedString>::create_with_values({}))));
types::CheckedEnum const enum_ = ((program)->get_enum(enum_id));
{
JaktInternal::ArrayIterator<types::CheckedEnumVariant> _magic = ((((enum_).variants)).iterator());
for (;;){
JaktInternal::Optional<types::CheckedEnumVariant> _magic_value = ((_magic).next());
if ((!(((_magic_value).has_value())))){
break;
}
types::CheckedEnumVariant variant = (_magic_value.value());
{
TRY((((names).add(((variant).name())))));
}

}
}

__jakt_var_750 = names; goto __jakt_label_673;

}
__jakt_label_673:; __jakt_var_750.release_value(); }));
};/*case end*/
case 20: {
auto&& __jakt_match_value = __jakt_match_variant.template get<types::Type::GenericEnumInstance>();types::EnumId const& enum_id = __jakt_match_value.id;
return JaktInternal::ExplicitValue(({ Optional<JaktInternal::Set<DeprecatedString>> __jakt_var_751; {
JaktInternal::Set<DeprecatedString> names = (TRY((Set<DeprecatedString>::create_with_values({}))));
types::CheckedEnum const enum_ = ((program)->get_enum(enum_id));
{
JaktInternal::ArrayIterator<types::CheckedEnumVariant> _magic = ((((enum_).variants)).iterator());
for (;;){
JaktInternal::Optional<types::CheckedEnumVariant> _magic_value = ((_magic).next());
if ((!(((_magic_value).has_value())))){
break;
}
types::CheckedEnumVariant variant = (_magic_value.value());
{
TRY((((names).add(((variant).name())))));
}

}
}

__jakt_var_751 = names; goto __jakt_label_674;

}
__jakt_label_674:; __jakt_var_751.release_value(); }));
};/*case end*/
default: {
return JaktInternal::ExplicitValue(({ Optional<JaktInternal::Set<DeprecatedString>> __jakt_var_752; {
__jakt_var_752 = (TRY((Set<DeprecatedString>::create_with_values({TRY((__jakt_format(Jakt::DeprecatedString("else ({})"sv),TRY((((program)->type_name(type_id,false)))))))})))); goto __jakt_label_675;

}
__jakt_label_675:; __jakt_var_752.release_value(); }));
};/*case end*/
}/*switch end*/
}()
));
JaktInternal::Set<DeprecatedString> remaining_cases = all_cases;
{
JaktInternal::ArrayIterator<types::CheckedMatchCase> _magic = ((match_cases).iterator());
for (;;){
JaktInternal::Optional<types::CheckedMatchCase> _magic_value = ((_magic).next());
if ((!(((_magic_value).has_value())))){
break;
}
types::CheckedMatchCase other_case = (_magic_value.value());
{
if (((other_case).index() == 0 /* EnumVariant */)){
DeprecatedString const name = ((other_case).get<types::CheckedMatchCase::EnumVariant>()).name;
((remaining_cases).remove(name));
}
}

}
}

__jakt_var_749 = JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_AT_LOOP_NESTED_MATCH(([&]() -> JaktInternal::ExplicitValueOrControlFlow<JaktInternal::Optional<ide::Usage>,ErrorOr<JaktInternal::Optional<ide::Usage>>>{
auto __jakt_enum_value = (((remaining_cases).is_empty()));
if (__jakt_enum_value == false) {
return JaktInternal::ExplicitValue(({ Optional<JaktInternal::Optional<ide::Usage>> __jakt_var_753; {
JaktInternal::DynamicArray<DeprecatedString> cases_array = (TRY((DynamicArray<DeprecatedString>::create_with({}))));
TRY((((cases_array).ensure_capacity(((remaining_cases).size())))));
{
JaktInternal::SetIterator<DeprecatedString> _magic = ((remaining_cases).iterator());
for (;;){
JaktInternal::Optional<DeprecatedString> _magic_value = ((_magic).next());
if ((!(((_magic_value).has_value())))){
break;
}
DeprecatedString name = (_magic_value.value());
{
TRY((((cases_array).push(name))));
}

}
}

__jakt_var_753 = static_cast<JaktInternal::Optional<ide::Usage>>( ide::Usage { typename ide::Usage::NameSet(cases_array) } ); goto __jakt_label_676;

}
__jakt_label_676:; __jakt_var_753.release_value(); }));
}
else {
return JaktInternal::ExplicitValue(JaktInternal::OptionalNone());
}
}()))
; goto __jakt_label_672;

}
__jakt_label_672:; __jakt_var_749.release_value(); }));
}
else {
return JaktInternal::ExplicitValue(JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_AT_LOOP_NESTED_MATCH(([&]() -> JaktInternal::ExplicitValueOrControlFlow<JaktInternal::Optional<ide::Usage>, ErrorOr<JaktInternal::Optional<ide::Usage>>>{
auto&& __jakt_match_variant = body;
switch(__jakt_match_variant.index()) {
case 1: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::CheckedMatchBody::Block>();
types::CheckedBlock const& block = __jakt_match_value.value;
return JaktInternal::ExplicitValue(TRY((ide::find_span_in_block(program,block,span))));
};/*case end*/
case 0: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::CheckedMatchBody::Expression>();
NonnullRefPtr<typename types::CheckedExpression> const& expr = __jakt_match_value.value;
return JaktInternal::ExplicitValue(TRY((ide::find_span_in_expression(program,expr,span))));
};/*case end*/
default: VERIFY_NOT_REACHED();}/*switch end*/
}()
)));
}
}()))
);
};/*case end*/
default: VERIFY_NOT_REACHED();}/*switch end*/
}()
));
if (((found).has_value())){
return (found);
}
}

}
}

__jakt_var_746 = TRY((ide::find_span_in_expression(program,expr,span))); goto __jakt_label_669;

}
__jakt_label_669:; __jakt_var_746.release_value(); }));
};/*case end*/
case 25: {
auto&& __jakt_match_value = __jakt_match_variant.template get<types::CheckedExpression::ForcedUnwrap>();NonnullRefPtr<typename types::CheckedExpression> const& expr = __jakt_match_value.expr;
return JaktInternal::ExplicitValue(TRY((ide::find_span_in_expression(program,expr,span))));
};/*case end*/
case 5: {
auto&& __jakt_match_value = __jakt_match_variant.template get<types::CheckedExpression::UnaryOp>();NonnullRefPtr<typename types::CheckedExpression> const& expr = __jakt_match_value.expr;
return JaktInternal::ExplicitValue(TRY((ide::find_span_in_expression(program,expr,span))));
};/*case end*/
case 20: {
auto&& __jakt_match_value = __jakt_match_variant.template get<types::CheckedExpression::MethodCall>();NonnullRefPtr<typename types::CheckedExpression> const& expr = __jakt_match_value.expr;
types::CheckedCall const& call = __jakt_match_value.call;
utility::Span const& method_span = __jakt_match_value.span;
types::TypeId const& type_id = __jakt_match_value.type_id;
{
JaktInternal::Optional<ide::Usage> found = TRY((ide::find_span_in_expression(program,expr,span)));
if (((found).has_value())){
return (found);
}
{
JaktInternal::ArrayIterator<JaktInternal::Tuple<DeprecatedString,NonnullRefPtr<typename types::CheckedExpression>>> _magic = ((((call).args)).iterator());
for (;;){
JaktInternal::Optional<JaktInternal::Tuple<DeprecatedString,NonnullRefPtr<typename types::CheckedExpression>>> _magic_value = ((_magic).next());
if ((!(((_magic_value).has_value())))){
break;
}
JaktInternal::Tuple<DeprecatedString,NonnullRefPtr<typename types::CheckedExpression>> ___expr__ = (_magic_value.value());
{
JaktInternal::Tuple<DeprecatedString,NonnullRefPtr<typename types::CheckedExpression>> const jakt_____expr__ = ___expr__;
DeprecatedString const _ = ((jakt_____expr__).template get<0>());
NonnullRefPtr<typename types::CheckedExpression> const expr = ((jakt_____expr__).template get<1>());

(found = TRY((ide::find_span_in_expression(program,expr,span))));
if (((found).has_value())){
return (found);
}
}

}
}

if ((((((call).function_id)).has_value()) && ((method_span).contains(span)))){
return (static_cast<JaktInternal::Optional<ide::Usage>>( ide::Usage { typename ide::Usage::Call((((call).function_id).value())) } ));
}
return (none);
}
};/*case end*/
case 22: {
auto&& __jakt_match_value = __jakt_match_variant.template get<types::CheckedExpression::Var>();NonnullRefPtr<types::CheckedVariable> const& var = __jakt_match_value.var;
utility::Span const& var_span = __jakt_match_value.span;
{
JaktInternal::Optional<types::TypeId> const none_type_id = JaktInternal::OptionalNone();
if (((var_span).contains(span))){
ide::Mutability const mutability = JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<ide::Mutability,ErrorOr<JaktInternal::Optional<ide::Usage>>>{
auto __jakt_enum_value = (((var)->is_mutable));
if (__jakt_enum_value == true) {
return JaktInternal::ExplicitValue( ide::Mutability { typename ide::Mutability::Mutable() } );
}
else {
return JaktInternal::ExplicitValue( ide::Mutability { typename ide::Mutability::Immutable() } );
}
}()))
;
return (static_cast<JaktInternal::Optional<ide::Usage>>( ide::Usage { typename ide::Usage::Variable(((var)->definition_span),((var)->name),((var)->type_id),mutability, ide::VarType { typename ide::VarType::Variable() } , ide::VarVisibility { typename ide::VarVisibility::DoesNotApply() } ,none_type_id) } ));
}
return (none);
}
};/*case end*/
case 21: {
auto&& __jakt_match_value = __jakt_match_variant.template get<types::CheckedExpression::NamespacedVar>();JaktInternal::DynamicArray<types::CheckedNamespace> const& namespaces = __jakt_match_value.namespaces;
NonnullRefPtr<types::CheckedVariable> const& var = __jakt_match_value.var;
utility::Span const& var_span = __jakt_match_value.span;
return JaktInternal::ExplicitValue(({ Optional<JaktInternal::Optional<ide::Usage>> __jakt_var_754; {
if ((((var_span).contains(span)) && (!(((namespaces).is_empty()))))){
types::CheckedNamespace const last_ns = (((namespaces).last()).value());
if (((((TRY((((program)->get_scope(((last_ns).scope))))))->namespace_name)).has_value())){
JaktInternal::Optional<types::EnumId> const enum_id = TRY((((program)->find_enum_in_scope(((last_ns).scope),((last_ns).name)))));
if (((enum_id).has_value())){
types::CheckedEnum const enum_ = ((program)->get_enum((enum_id.value())));
return (static_cast<JaktInternal::Optional<ide::Usage>>(TRY((ide::get_enum_variant_usage_from_type_id_and_name(program,((enum_).type_id),((var)->name))))));
}
}
}
__jakt_var_754 = none; goto __jakt_label_677;

}
__jakt_label_677:; __jakt_var_754.release_value(); }));
};/*case end*/
case 29: {
auto&& __jakt_match_value = __jakt_match_variant.template get<types::CheckedExpression::TryBlock>();NonnullRefPtr<typename types::CheckedStatement> const& stmt = __jakt_match_value.stmt;
DeprecatedString const& error_name = __jakt_match_value.error_name;
types::CheckedBlock const& catch_block = __jakt_match_value.catch_block;
return JaktInternal::ExplicitValue(({ Optional<JaktInternal::Optional<ide::Usage>> __jakt_var_755; {
JaktInternal::Optional<ide::Usage> const found = TRY((ide::find_span_in_statement(program,stmt,span)));
if (((found).has_value())){
return (found);
}
__jakt_var_755 = TRY((ide::find_span_in_block(program,catch_block,span))); goto __jakt_label_678;

}
__jakt_label_678:; __jakt_var_755.release_value(); }));
};/*case end*/
case 28: {
auto&& __jakt_match_value = __jakt_match_variant.template get<types::CheckedExpression::Try>();NonnullRefPtr<typename types::CheckedExpression> const& expr = __jakt_match_value.expr;
JaktInternal::Optional<types::CheckedBlock> const& catch_block = __jakt_match_value.catch_block;
return JaktInternal::ExplicitValue(({ Optional<JaktInternal::Optional<ide::Usage>> __jakt_var_756; {
JaktInternal::Optional<ide::Usage> const found = TRY((ide::find_span_in_expression(program,expr,span)));
if (((found).has_value())){
return (found);
}
__jakt_var_756 = JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<JaktInternal::Optional<ide::Usage>,ErrorOr<JaktInternal::Optional<ide::Usage>>>{
auto __jakt_enum_value = (((catch_block).has_value()));
if (__jakt_enum_value == true) {
return JaktInternal::ExplicitValue(TRY((ide::find_span_in_block(program,(catch_block.value()),span))));
}
else {
return JaktInternal::ExplicitValue(none);
}
}()))
; goto __jakt_label_679;

}
__jakt_label_679:; __jakt_var_756.release_value(); }));
};/*case end*/
case 8: {
auto&& __jakt_match_value = __jakt_match_variant.template get<types::CheckedExpression::Range>();JaktInternal::Optional<NonnullRefPtr<typename types::CheckedExpression>> const& from = __jakt_match_value.from;
JaktInternal::Optional<NonnullRefPtr<typename types::CheckedExpression>> const& to = __jakt_match_value.to;
return JaktInternal::ExplicitValue(({ Optional<JaktInternal::Optional<ide::Usage>> __jakt_var_757; {
if (((from).has_value())){
JaktInternal::Optional<ide::Usage> const found = TRY((ide::find_span_in_expression(program,(from.value()),span)));
if (((found).has_value())){
return (found);
}
}
if (((to).has_value())){
return (TRY((ide::find_span_in_expression(program,(to.value()),span))));
}
__jakt_var_757 = none; goto __jakt_label_680;

}
__jakt_label_680:; __jakt_var_757.release_value(); }));
};/*case end*/
default: {
return JaktInternal::ExplicitValue(none);
};/*case end*/
}/*switch end*/
}()
)));
}
}

ErrorOr<JaktInternal::Optional<ide::Usage>> find_span_in_block(NonnullRefPtr<types::CheckedProgram> const program,types::CheckedBlock const block,utility::Span const span) {
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
JaktInternal::Optional<ide::Usage> const found = TRY((ide::find_span_in_statement(program,statement,span)));
if (((found).has_value())){
return (found);
}
}

}
}

return (JaktInternal::OptionalNone());
}
}

ErrorOr<JaktInternal::Optional<ide::Usage>> find_span_in_program(NonnullRefPtr<types::CheckedProgram> const program,utility::Span const span) {
{
JaktInternal::ArrayIterator<NonnullRefPtr<types::Module>> iterator = ((((program)->modules)).iterator());
JaktInternal::Optional<NonnullRefPtr<types::Module>> const dummy = ((iterator).next());
{
JaktInternal::ArrayIterator<NonnullRefPtr<types::Module>> _magic = iterator;
for (;;){
JaktInternal::Optional<NonnullRefPtr<types::Module>> _magic_value = ((_magic).next());
if ((!(((_magic_value).has_value())))){
break;
}
NonnullRefPtr<types::Module> module = (_magic_value.value());
{
NonnullRefPtr<types::Scope> const scope = TRY((((program)->get_scope(types::ScopeId(((module)->id),static_cast<size_t>(0ULL))))));
return (TRY((ide::find_span_in_scope(program,scope,span))));
}

}
}

return (JaktInternal::OptionalNone());
}
}

ErrorOr<JaktInternal::DynamicArray<DeprecatedString>> find_function_completions_in_scope(NonnullRefPtr<types::Scope> const scope,NonnullRefPtr<types::CheckedProgram> const program) {
{
JaktInternal::DynamicArray<DeprecatedString> output = (TRY((DynamicArray<DeprecatedString>::create_with({}))));
{
JaktInternal::ArrayIterator<DeprecatedString> _magic = ((TRY((((((scope)->functions)).keys())))).iterator());
for (;;){
JaktInternal::Optional<DeprecatedString> _magic_value = ((_magic).next());
if ((!(((_magic_value).has_value())))){
break;
}
DeprecatedString function_name = (_magic_value.value());
{
JaktInternal::DynamicArray<types::FunctionId> const overload_set = (((((scope)->functions)).get(function_name)).value());
{
JaktInternal::ArrayIterator<types::FunctionId> _magic = ((overload_set).iterator());
for (;;){
JaktInternal::Optional<types::FunctionId> _magic_value = ((_magic).next());
if ((!(((_magic_value).has_value())))){
break;
}
types::FunctionId function_id = (_magic_value.value());
{
NonnullRefPtr<types::CheckedFunction> const checked_function = ((program)->get_function(function_id));
if (((((((checked_function)->params)).first())).has_value())){
types::CheckedParameter const param = (((((checked_function)->params)).first()).value());
if ((((((param).variable))->name) == Jakt::DeprecatedString("this"sv))){
DeprecatedString full_call = ((checked_function)->name);
bool first = true;
(full_call += Jakt::DeprecatedString("("sv));
JaktInternal::ArrayIterator<types::CheckedParameter> iter = ((((checked_function)->params)).iterator());
JaktInternal::Optional<types::CheckedParameter> const dummy = ((iter).next());
{
JaktInternal::ArrayIterator<types::CheckedParameter> _magic = iter;
for (;;){
JaktInternal::Optional<types::CheckedParameter> _magic_value = ((_magic).next());
if ((!(((_magic_value).has_value())))){
break;
}
types::CheckedParameter param = (_magic_value.value());
{
if ((!(first))){
(full_call += Jakt::DeprecatedString(", "sv));
}
else {
(first = false);
}

(full_call += ((((param).variable))->name));
}

}
}

(full_call += Jakt::DeprecatedString(")"sv));
TRY((((output).push(full_call))));
}
}
else {
TRY((((output).push(TRY((__jakt_format(Jakt::DeprecatedString("{}()"sv),((checked_function)->name))))))));
}

}

}
}

}

}
}

return (output);
}
}

ErrorOr<JaktInternal::DynamicArray<ide::JaktSymbol>> find_symbols_in_namespace(parser::ParsedNamespace const namespace_) {
{
JaktInternal::DynamicArray<ide::JaktSymbol> symbols = (TRY((DynamicArray<ide::JaktSymbol>::create_with({}))));
{
JaktInternal::ArrayIterator<parser::ParsedRecord> _magic = ((((namespace_).records)).iterator());
for (;;){
JaktInternal::Optional<parser::ParsedRecord> _magic_value = ((_magic).next());
if ((!(((_magic_value).has_value())))){
break;
}
parser::ParsedRecord record = (_magic_value.value());
{
TRY((((symbols).push(TRY((ide::record_to_symbol(record)))))));
}

}
}

{
JaktInternal::ArrayIterator<parser::ParsedFunction> _magic = ((((namespace_).functions)).iterator());
for (;;){
JaktInternal::Optional<parser::ParsedFunction> _magic_value = ((_magic).next());
if ((!(((_magic_value).has_value())))){
break;
}
parser::ParsedFunction function_ = (_magic_value.value());
{
TRY((((symbols).push(TRY((ide::function_to_symbol(function_,Jakt::DeprecatedString("function"sv))))))));
}

}
}

{
JaktInternal::ArrayIterator<parser::ParsedNamespace> _magic = ((((namespace_).namespaces)).iterator());
for (;;){
JaktInternal::Optional<parser::ParsedNamespace> _magic_value = ((_magic).next());
if ((!(((_magic_value).has_value())))){
break;
}
parser::ParsedNamespace sub_namespace = (_magic_value.value());
{
TRY((((symbols).push_values(((TRY((ide::find_symbols_in_namespace(sub_namespace)))))))));
}

}
}

if ((!(((((namespace_).name_span)).has_value())))){
return (symbols);
}
utility::Span namespace_span = (((namespace_).name_span).value());
{
JaktInternal::ArrayIterator<ide::JaktSymbol> _magic = ((symbols).iterator());
for (;;){
JaktInternal::Optional<ide::JaktSymbol> _magic_value = ((_magic).next());
if ((!(((_magic_value).has_value())))){
break;
}
ide::JaktSymbol child = (_magic_value.value());
{
(namespace_span = TRY((parser::merge_spans((((namespace_).name_span).value()),((child).range)))));
}

}
}

return ((TRY((DynamicArray<ide::JaktSymbol>::create_with({ide::JaktSymbol((((namespace_).name).value()),JaktInternal::OptionalNone(),Jakt::DeprecatedString("namespace"sv),namespace_span,(((namespace_).name_span).value()),symbols)})))));
}
}

ErrorOr<JaktInternal::Optional<ide::Usage>> find_span_in_function(NonnullRefPtr<types::CheckedProgram> const program,NonnullRefPtr<types::CheckedFunction> const checked_function,utility::Span const span) {
{
if (((((checked_function)->return_type_span)).has_value())){
if ((((((checked_function)->return_type_span).value())).contains(span))){
return (static_cast<JaktInternal::Optional<ide::Usage>>( ide::Usage { typename ide::Usage::Typename(((checked_function)->return_type_id)) } ));
}
}
{
JaktInternal::ArrayIterator<types::CheckedParameter> _magic = ((((checked_function)->params)).iterator());
for (;;){
JaktInternal::Optional<types::CheckedParameter> _magic_value = ((_magic).next());
if ((!(((_magic_value).has_value())))){
break;
}
types::CheckedParameter param = (_magic_value.value());
{
if (((((((param).variable))->definition_span)).contains(span))){
return (static_cast<JaktInternal::Optional<ide::Usage>>( ide::Usage { typename ide::Usage::Typename(((((param).variable))->type_id)) } ));
}
}

}
}

return (TRY((ide::find_span_in_block(program,((checked_function)->block),span))));
}
}

ErrorOr<utility::Span> find_type_definition_for_type_id(NonnullRefPtr<types::CheckedProgram> const program,types::TypeId const type_id,utility::Span const span) {
{
types::StructId const array_struct_id = TRY((((program)->find_struct_in_prelude(Jakt::DeprecatedString("Array"sv)))));
types::StructId const dictionary_struct_id = TRY((((program)->find_struct_in_prelude(Jakt::DeprecatedString("Dictionary"sv)))));
types::StructId const optional_struct_id = TRY((((program)->find_struct_in_prelude(Jakt::DeprecatedString("Optional"sv)))));
types::StructId const range_struct_id = TRY((((program)->find_struct_in_prelude(Jakt::DeprecatedString("Range"sv)))));
types::StructId const set_struct_id = TRY((((program)->find_struct_in_prelude(Jakt::DeprecatedString("Set"sv)))));
types::StructId const tuple_struct_id = TRY((((program)->find_struct_in_prelude(Jakt::DeprecatedString("Tuple"sv)))));
types::StructId const weak_ptr_struct_id = TRY((((program)->find_struct_in_prelude(Jakt::DeprecatedString("WeakPtr"sv)))));
return (JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<utility::Span, ErrorOr<utility::Span>>{
auto&& __jakt_match_variant = *((program)->get_type(type_id));
switch(__jakt_match_variant.index()) {
case 17: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::Type::Never>();
return JaktInternal::ExplicitValue(span);
};/*case end*/
case 10: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::Type::F32>();
return JaktInternal::ExplicitValue(span);
};/*case end*/
case 11: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::Type::F64>();
return JaktInternal::ExplicitValue(span);
};/*case end*/
case 6: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::Type::I8>();
return JaktInternal::ExplicitValue(span);
};/*case end*/
case 7: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::Type::I16>();
return JaktInternal::ExplicitValue(span);
};/*case end*/
case 8: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::Type::I32>();
return JaktInternal::ExplicitValue(span);
};/*case end*/
case 9: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::Type::I64>();
return JaktInternal::ExplicitValue(span);
};/*case end*/
case 2: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::Type::U8>();
return JaktInternal::ExplicitValue(span);
};/*case end*/
case 3: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::Type::U16>();
return JaktInternal::ExplicitValue(span);
};/*case end*/
case 4: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::Type::U32>();
return JaktInternal::ExplicitValue(span);
};/*case end*/
case 5: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::Type::U64>();
return JaktInternal::ExplicitValue(span);
};/*case end*/
case 12: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::Type::Usize>();
return JaktInternal::ExplicitValue(span);
};/*case end*/
case 14: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::Type::CChar>();
return JaktInternal::ExplicitValue(span);
};/*case end*/
case 15: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::Type::CInt>();
return JaktInternal::ExplicitValue(span);
};/*case end*/
case 1: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::Type::Bool>();
return JaktInternal::ExplicitValue(span);
};/*case end*/
case 0: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::Type::Void>();
return JaktInternal::ExplicitValue(span);
};/*case end*/
case 16: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::Type::Unknown>();
return JaktInternal::ExplicitValue(span);
};/*case end*/
case 13: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::Type::JaktString>();
return JaktInternal::ExplicitValue(span);
};/*case end*/
case 29: {
auto&& __jakt_match_value = __jakt_match_variant.template get<types::Type::Function>();return JaktInternal::ExplicitValue(span);
};/*case end*/
case 26: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::Type::Trait>();
types::TraitId const& id = __jakt_match_value.value;
return JaktInternal::ExplicitValue(((((program)->get_trait(id)))->name_span));
};/*case end*/
case 30: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::Type::Self>();
return JaktInternal::ExplicitValue(span);
};/*case end*/
case 19: {
auto&& __jakt_match_value = __jakt_match_variant.template get<types::Type::GenericInstance>();types::StructId const& struct_id = __jakt_match_value.id;
JaktInternal::DynamicArray<types::TypeId> const& args = __jakt_match_value.args;
return JaktInternal::ExplicitValue(({ Optional<utility::Span> __jakt_var_758; {
utility::Span output = span;
if ((((((((struct_id).equals(array_struct_id)) || ((struct_id).equals(optional_struct_id))) || ((struct_id).equals(range_struct_id))) || ((struct_id).equals(set_struct_id))) || ((struct_id).equals(tuple_struct_id))) || ((struct_id).equals(weak_ptr_struct_id)))){
(output = TRY((ide::find_type_definition_for_type_id(program,((args)[static_cast<i64>(0LL)]),span))));
}
else if (((struct_id).equals(dictionary_struct_id))){
(output = TRY((ide::find_type_definition_for_type_id(program,((args)[static_cast<i64>(1LL)]),span))));
}
else {
(output = ((((program)->get_struct(struct_id))).name_span));
}

__jakt_var_758 = output; goto __jakt_label_681;

}
__jakt_label_681:; __jakt_var_758.release_value(); }));
};/*case end*/
case 23: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::Type::Struct>();
types::StructId const& struct_id = __jakt_match_value.value;
return JaktInternal::ExplicitValue(((((program)->get_struct(struct_id))).name_span));
};/*case end*/
case 20: {
auto&& __jakt_match_value = __jakt_match_variant.template get<types::Type::GenericEnumInstance>();types::EnumId const& id = __jakt_match_value.id;
return JaktInternal::ExplicitValue(((((program)->get_enum(id))).name_span));
};/*case end*/
case 21: {
auto&& __jakt_match_value = __jakt_match_variant.template get<types::Type::GenericTraitInstance>();types::TraitId const& id = __jakt_match_value.id;
return JaktInternal::ExplicitValue(((((program)->get_trait(id)))->name_span));
};/*case end*/
case 24: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::Type::Enum>();
types::EnumId const& id = __jakt_match_value.value;
return JaktInternal::ExplicitValue(((((program)->get_enum(id))).name_span));
};/*case end*/
case 25: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::Type::RawPtr>();
types::TypeId const& type_id = __jakt_match_value.value;
return JaktInternal::ExplicitValue(TRY((ide::find_type_definition_for_type_id(program,type_id,span))));
};/*case end*/
case 18: {
auto&& __jakt_match_value = __jakt_match_variant.template get<types::Type::TypeVariable>();return JaktInternal::ExplicitValue(span);
};/*case end*/
case 22: {
auto&& __jakt_match_value = __jakt_match_variant.template get<types::Type::GenericResolvedType>();types::StructId const& id = __jakt_match_value.id;
return JaktInternal::ExplicitValue(((((program)->get_struct(id))).name_span));
};/*case end*/
case 27: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::Type::Reference>();
types::TypeId const& type_id = __jakt_match_value.value;
return JaktInternal::ExplicitValue(TRY((ide::find_type_definition_for_type_id(program,type_id,span))));
};/*case end*/
case 28: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::Type::MutableReference>();
types::TypeId const& type_id = __jakt_match_value.value;
return JaktInternal::ExplicitValue(TRY((ide::find_type_definition_for_type_id(program,type_id,span))));
};/*case end*/
default: VERIFY_NOT_REACHED();}/*switch end*/
}()
)));
}
}

ErrorOr<DeprecatedString> get_enum_variant_signature(NonnullRefPtr<types::CheckedProgram> const program,DeprecatedString const name,types::TypeId const type_id,JaktInternal::DynamicArray<JaktInternal::Tuple<JaktInternal::Optional<DeprecatedString>,types::TypeId>> const variants,JaktInternal::Optional<types::NumberConstant> const number_constant) {
{
DeprecatedString output = TRY((ide::get_type_signature(program,type_id)));
(output += Jakt::DeprecatedString("::"sv));
(output += name);
if ((!(((variants).is_empty())))){
(output += Jakt::DeprecatedString("("sv));
bool first = true;
{
JaktInternal::ArrayIterator<JaktInternal::Tuple<JaktInternal::Optional<DeprecatedString>,types::TypeId>> _magic = ((variants).iterator());
for (;;){
JaktInternal::Optional<JaktInternal::Tuple<JaktInternal::Optional<DeprecatedString>,types::TypeId>> _magic_value = ((_magic).next());
if ((!(((_magic_value).has_value())))){
break;
}
JaktInternal::Tuple<JaktInternal::Optional<DeprecatedString>,types::TypeId> variant_name__variant_type_id__ = (_magic_value.value());
{
JaktInternal::Tuple<JaktInternal::Optional<DeprecatedString>,types::TypeId> const jakt__variant_name__variant_type_id__ = variant_name__variant_type_id__;
JaktInternal::Optional<DeprecatedString> const variant_name = ((jakt__variant_name__variant_type_id__).template get<0>());
types::TypeId const variant_type_id = ((jakt__variant_name__variant_type_id__).template get<1>());

if (first){
(first = false);
}
else {
(output += Jakt::DeprecatedString(", "sv));
}

if (((variant_name).has_value())){
(output += (variant_name.value()));
(output += Jakt::DeprecatedString(": "sv));
}
(output += TRY((((program)->type_name(variant_type_id,false)))));
}

}
}

(output += Jakt::DeprecatedString(")"sv));
}
if (((number_constant).has_value())){
(output += Jakt::DeprecatedString(" = "sv));
JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<void, ErrorOr<DeprecatedString>>{
auto&& __jakt_match_variant = (number_constant.value());
switch(__jakt_match_variant.index()) {
case 0: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::NumberConstant::Signed>();
i64 const& value = __jakt_match_value.value;
{
(output += TRY((__jakt_format(Jakt::DeprecatedString("{}"sv),value))));
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 1: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::NumberConstant::Unsigned>();
u64 const& value = __jakt_match_value.value;
{
(output += TRY((__jakt_format(Jakt::DeprecatedString("{}"sv),value))));
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 2: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::NumberConstant::Floating>();
f64 const& value = __jakt_match_value.value;
{
(output += TRY((__jakt_format(Jakt::DeprecatedString("{}"sv),value))));
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
default: VERIFY_NOT_REACHED();}/*switch end*/
}()
));
}
return (output);
}
}

ErrorOr<JaktInternal::Optional<ide::Usage>> find_span_in_enum(NonnullRefPtr<types::CheckedProgram> const program,types::CheckedEnum const checked_enum,utility::Span const span) {
{
NonnullRefPtr<types::Scope> const scope = TRY((((program)->get_scope(((checked_enum).scope_id)))));
{
JaktInternal::ArrayIterator<types::CheckedEnumVariant> _magic = ((((checked_enum).variants)).iterator());
for (;;){
JaktInternal::Optional<types::CheckedEnumVariant> _magic_value = ((_magic).next());
if ((!(((_magic_value).has_value())))){
break;
}
types::CheckedEnumVariant variant = (_magic_value.value());
{
JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_AT_LOOP(([&]() -> JaktInternal::ExplicitValueOrControlFlow<void, ErrorOr<JaktInternal::Optional<ide::Usage>>>{
auto&& __jakt_match_variant = variant;
switch(__jakt_match_variant.index()) {
case 3: {
auto&& __jakt_match_value = __jakt_match_variant.template get<types::CheckedEnumVariant::StructLike>();DeprecatedString const& name = __jakt_match_value.name;
JaktInternal::DynamicArray<types::VarId> const& fields = __jakt_match_value.fields;
utility::Span const& variant_span = __jakt_match_value.span;
{
{
JaktInternal::ArrayIterator<types::VarId> _magic = ((fields).iterator());
for (;;){
JaktInternal::Optional<types::VarId> _magic_value = ((_magic).next());
if ((!(((_magic_value).has_value())))){
break;
}
types::VarId field = (_magic_value.value());
{
NonnullRefPtr<types::CheckedVariable> const var = ((program)->get_variable(field));
if (((((var)->definition_span)).contains(span))){
return (static_cast<JaktInternal::Optional<ide::Usage>>( ide::Usage { typename ide::Usage::Typename(((var)->type_id)) } ));
}
}

}
}

if (((variant_span).contains(span))){
return (static_cast<JaktInternal::Optional<ide::Usage>>( ide::Usage { typename ide::Usage::EnumVariant(span,name,((checked_enum).type_id),(TRY((DynamicArray<JaktInternal::Tuple<JaktInternal::Optional<DeprecatedString>,types::TypeId>>::create_with({})))),JaktInternal::OptionalNone()) } ));
}
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 1: {
auto&& __jakt_match_value = __jakt_match_variant.template get<types::CheckedEnumVariant::Typed>();DeprecatedString const& name = __jakt_match_value.name;
utility::Span const& variant_span = __jakt_match_value.span;
{
if (((variant_span).contains(span))){
return (static_cast<JaktInternal::Optional<ide::Usage>>( ide::Usage { typename ide::Usage::EnumVariant(variant_span,name,((checked_enum).type_id),TRY((ide::enum_variant_fields(program,variant))),JaktInternal::OptionalNone()) } ));
}
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 0: {
auto&& __jakt_match_value = __jakt_match_variant.template get<types::CheckedEnumVariant::Untyped>();DeprecatedString const& name = __jakt_match_value.name;
utility::Span const& variant_span = __jakt_match_value.span;
{
if (((variant_span).contains(span))){
return (static_cast<JaktInternal::Optional<ide::Usage>>( ide::Usage { typename ide::Usage::EnumVariant(variant_span,name,((checked_enum).type_id),(TRY((DynamicArray<JaktInternal::Tuple<JaktInternal::Optional<DeprecatedString>,types::TypeId>>::create_with({})))),JaktInternal::OptionalNone()) } ));
}
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 2: {
auto&& __jakt_match_value = __jakt_match_variant.template get<types::CheckedEnumVariant::WithValue>();DeprecatedString const& name = __jakt_match_value.name;
NonnullRefPtr<typename types::CheckedExpression> const& expr = __jakt_match_value.expr;
utility::Span const& variant_span = __jakt_match_value.span;
{
if (((variant_span).contains(span))){
return (static_cast<JaktInternal::Optional<ide::Usage>>( ide::Usage { typename ide::Usage::EnumVariant(variant_span,name,((checked_enum).type_id),TRY((ide::enum_variant_fields(program,variant))),((expr)->to_number_constant(program))) } ));
}
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
default: VERIFY_NOT_REACHED();}/*switch end*/
}()
));
}

}
}

JaktInternal::Optional<ide::Usage> const usage = TRY((ide::find_span_in_scope(program,scope,span)));
return (usage);
}
}

ErrorOr<ide::JaktSymbol> function_to_symbol(parser::ParsedFunction const function_,DeprecatedString const kind) {
{
utility::Span function_span = ((function_).name_span);
{
JaktInternal::ArrayIterator<NonnullRefPtr<typename parser::ParsedStatement>> _magic = ((((((function_).block)).stmts)).iterator());
for (;;){
JaktInternal::Optional<NonnullRefPtr<typename parser::ParsedStatement>> _magic_value = ((_magic).next());
if ((!(((_magic_value).has_value())))){
break;
}
NonnullRefPtr<typename parser::ParsedStatement> stmt = (_magic_value.value());
{
(function_span = TRY((parser::merge_spans(function_span,((stmt)->span())))));
}

}
}

return (ide::JaktSymbol(((function_).name),JaktInternal::OptionalNone(),kind,function_span,((function_).name_span),(TRY((DynamicArray<ide::JaktSymbol>::create_with({}))))));
}
}

ErrorOr<JaktInternal::Optional<ide::Usage>> find_span_in_statement(NonnullRefPtr<types::CheckedProgram> const program,NonnullRefPtr<typename types::CheckedStatement> const statement,utility::Span const span) {
{
JaktInternal::Optional<ide::Usage> const none = JaktInternal::OptionalNone();
return (JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<JaktInternal::Optional<ide::Usage>, ErrorOr<JaktInternal::Optional<ide::Usage>>>{
auto&& __jakt_match_variant = *statement;
switch(__jakt_match_variant.index()) {
case 5: {
auto&& __jakt_match_value = __jakt_match_variant.template get<types::CheckedStatement::Block>();types::CheckedBlock const& block = __jakt_match_value.block;
return JaktInternal::ExplicitValue(TRY((ide::find_span_in_block(program,block,span))));
};/*case end*/
case 1: {
auto&& __jakt_match_value = __jakt_match_variant.template get<types::CheckedStatement::Defer>();NonnullRefPtr<typename types::CheckedStatement> const& statement = __jakt_match_value.statement;
return JaktInternal::ExplicitValue(TRY((ide::find_span_in_statement(program,statement,span))));
};/*case end*/
case 0: {
auto&& __jakt_match_value = __jakt_match_variant.template get<types::CheckedStatement::Expression>();NonnullRefPtr<typename types::CheckedExpression> const& expr = __jakt_match_value.expr;
return JaktInternal::ExplicitValue(TRY((ide::find_span_in_expression(program,expr,span))));
};/*case end*/
case 4: {
auto&& __jakt_match_value = __jakt_match_variant.template get<types::CheckedStatement::If>();NonnullRefPtr<typename types::CheckedExpression> const& condition = __jakt_match_value.condition;
types::CheckedBlock const& then_block = __jakt_match_value.then_block;
JaktInternal::Optional<NonnullRefPtr<typename types::CheckedStatement>> const& else_statement = __jakt_match_value.else_statement;
return JaktInternal::ExplicitValue(({ Optional<JaktInternal::Optional<ide::Usage>> __jakt_var_759; {
JaktInternal::Optional<ide::Usage> found = TRY((ide::find_span_in_expression(program,condition,span)));
if (((found).has_value())){
return (found);
}
(found = TRY((ide::find_span_in_block(program,then_block,span))));
if (((found).has_value())){
return (found);
}
if (((else_statement).has_value())){
return (TRY((ide::find_span_in_statement(program,(else_statement.value()),span))));
}
__jakt_var_759 = none; goto __jakt_label_682;

}
__jakt_label_682:; __jakt_var_759.release_value(); }));
};/*case end*/
case 13: {
auto&& __jakt_match_value = __jakt_match_variant.template get<types::CheckedStatement::InlineCpp>();return JaktInternal::ExplicitValue(({ Optional<JaktInternal::Optional<ide::Usage>> __jakt_var_760; {
JaktInternal::Optional<ide::Usage> const output = JaktInternal::OptionalNone();
__jakt_var_760 = output; goto __jakt_label_683;

}
__jakt_label_683:; __jakt_var_760.release_value(); }));
};/*case end*/
case 6: {
auto&& __jakt_match_value = __jakt_match_variant.template get<types::CheckedStatement::Loop>();types::CheckedBlock const& block = __jakt_match_value.block;
return JaktInternal::ExplicitValue(TRY((ide::find_span_in_block(program,block,span))));
};/*case end*/
case 8: {
auto&& __jakt_match_value = __jakt_match_variant.template get<types::CheckedStatement::Return>();JaktInternal::Optional<NonnullRefPtr<typename types::CheckedExpression>> const& val = __jakt_match_value.val;
return JaktInternal::ExplicitValue(JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<JaktInternal::Optional<ide::Usage>,ErrorOr<JaktInternal::Optional<ide::Usage>>>{
auto __jakt_enum_value = (((val).has_value()));
if (__jakt_enum_value == true) {
return JaktInternal::ExplicitValue(TRY((ide::find_span_in_expression(program,(val.value()),span))));
}
else {
return JaktInternal::ExplicitValue(none);
}
}()))
);
};/*case end*/
case 11: {
auto&& __jakt_match_value = __jakt_match_variant.template get<types::CheckedStatement::Throw>();NonnullRefPtr<typename types::CheckedExpression> const& expr = __jakt_match_value.expr;
return JaktInternal::ExplicitValue(TRY((ide::find_span_in_expression(program,expr,span))));
};/*case end*/
case 3: {
auto&& __jakt_match_value = __jakt_match_variant.template get<types::CheckedStatement::VarDecl>();types::VarId const& var_id = __jakt_match_value.var_id;
NonnullRefPtr<typename types::CheckedExpression> const& init = __jakt_match_value.init;
return JaktInternal::ExplicitValue(({ Optional<JaktInternal::Optional<ide::Usage>> __jakt_var_761; {
NonnullRefPtr<types::CheckedVariable> const checked_var = ((program)->get_variable(var_id));
JaktInternal::Optional<ide::Usage> const found = TRY((ide::find_span_in_expression(program,init,span)));
if (((found).has_value())){
return (found);
}
if (((((checked_var)->type_span)).has_value())){
utility::Span const type_span = (((checked_var)->type_span).value());
if (((type_span).contains(span))){
return (static_cast<JaktInternal::Optional<ide::Usage>>( ide::Usage { typename ide::Usage::Typename(((checked_var)->type_id)) } ));
}
}
if (((((checked_var)->definition_span)).contains(span))){
ide::Mutability const mutability = JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<ide::Mutability,ErrorOr<JaktInternal::Optional<ide::Usage>>>{
auto __jakt_enum_value = (((checked_var)->is_mutable));
if (__jakt_enum_value == true) {
return JaktInternal::ExplicitValue( ide::Mutability { typename ide::Mutability::Mutable() } );
}
else {
return JaktInternal::ExplicitValue( ide::Mutability { typename ide::Mutability::Immutable() } );
}
}()))
;
return (static_cast<JaktInternal::Optional<ide::Usage>>( ide::Usage { typename ide::Usage::Variable(((checked_var)->definition_span),((checked_var)->name),((checked_var)->type_id),mutability, ide::VarType { typename ide::VarType::Variable() } , ide::VarVisibility { typename ide::VarVisibility::DoesNotApply() } ,JaktInternal::OptionalNone()) } ));
}
__jakt_var_761 = none; goto __jakt_label_684;

}
__jakt_label_684:; __jakt_var_761.release_value(); }));
};/*case end*/
case 7: {
auto&& __jakt_match_value = __jakt_match_variant.template get<types::CheckedStatement::While>();NonnullRefPtr<typename types::CheckedExpression> const& condition = __jakt_match_value.condition;
types::CheckedBlock const& block = __jakt_match_value.block;
return JaktInternal::ExplicitValue(({ Optional<JaktInternal::Optional<ide::Usage>> __jakt_var_762; {
JaktInternal::Optional<ide::Usage> const found = TRY((ide::find_span_in_expression(program,condition,span)));
if (((found).has_value())){
return (found);
}
__jakt_var_762 = TRY((ide::find_span_in_block(program,block,span))); goto __jakt_label_685;

}
__jakt_label_685:; __jakt_var_762.release_value(); }));
};/*case end*/
case 2: {
auto&& __jakt_match_value = __jakt_match_variant.template get<types::CheckedStatement::DestructuringAssignment>();JaktInternal::DynamicArray<NonnullRefPtr<typename types::CheckedStatement>> const& vars = __jakt_match_value.vars;
NonnullRefPtr<typename types::CheckedStatement> const& var_decl = __jakt_match_value.var_decl;
return JaktInternal::ExplicitValue(({ Optional<JaktInternal::Optional<ide::Usage>> __jakt_var_763; {
{
JaktInternal::ArrayIterator<NonnullRefPtr<typename types::CheckedStatement>> _magic = ((vars).iterator());
for (;;){
JaktInternal::Optional<NonnullRefPtr<typename types::CheckedStatement>> _magic_value = ((_magic).next());
if ((!(((_magic_value).has_value())))){
break;
}
NonnullRefPtr<typename types::CheckedStatement> var = (_magic_value.value());
{
JaktInternal::Optional<ide::Usage> const found = TRY((ide::find_span_in_statement(program,var,span)));
if (((found).has_value())){
return (found);
}
}

}
}

__jakt_var_763 = TRY((ide::find_span_in_statement(program,var_decl,span))); goto __jakt_label_686;

}
__jakt_label_686:; __jakt_var_763.release_value(); }));
};/*case end*/
case 12: {
auto&& __jakt_match_value = __jakt_match_variant.template get<types::CheckedStatement::Yield>();NonnullRefPtr<typename types::CheckedExpression> const& expr = __jakt_match_value.expr;
return JaktInternal::ExplicitValue(TRY((ide::find_span_in_expression(program,expr,span))));
};/*case end*/
case 9: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::CheckedStatement::Break>();
return JaktInternal::ExplicitValue(none);
};/*case end*/
case 10: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::CheckedStatement::Continue>();
return JaktInternal::ExplicitValue(none);
};/*case end*/
case 14: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::CheckedStatement::Garbage>();
return JaktInternal::ExplicitValue(none);
};/*case end*/
default: VERIFY_NOT_REACHED();}/*switch end*/
}()
)));
}
}

ErrorOr<JaktInternal::Optional<ide::Usage>> find_span_in_struct(NonnullRefPtr<types::CheckedProgram> const program,types::CheckedStruct const checked_struct,utility::Span const span) {
{
NonnullRefPtr<types::Scope> const scope = TRY((((program)->get_scope(((checked_struct).scope_id)))));
{
JaktInternal::ArrayIterator<types::CheckedField> _magic = ((((checked_struct).fields)).iterator());
for (;;){
JaktInternal::Optional<types::CheckedField> _magic_value = ((_magic).next());
if ((!(((_magic_value).has_value())))){
break;
}
types::CheckedField field = (_magic_value.value());
{
NonnullRefPtr<types::CheckedVariable> const variable = ((program)->get_variable(((field).variable_id)));
if (((((variable)->definition_span)).contains(span))){
return (static_cast<JaktInternal::Optional<ide::Usage>>( ide::Usage { typename ide::Usage::Typename(((variable)->type_id)) } ));
}
}

}
}

JaktInternal::Optional<ide::Usage> const usage = TRY((ide::find_span_in_scope(program,scope,span)));
return (usage);
}
}

ErrorOr<DeprecatedString> get_function_signature(NonnullRefPtr<types::CheckedProgram> const program,types::FunctionId const function_id) {
{
NonnullRefPtr<types::CheckedFunction> const checked_function = ((program)->get_function(function_id));
JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<void, ErrorOr<DeprecatedString>>{
auto&& __jakt_match_variant = ((checked_function)->type);
switch(__jakt_match_variant.index()) {
case 2: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename parser::FunctionType::ImplicitEnumConstructor>();
{
types::TypeId const type_id = ((checked_function)->return_type_id);
DeprecatedString const name = ((checked_function)->name);
return (TRY((ide::get_enum_variant_signature_from_type_id_and_name(program,type_id,name))));
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 1: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename parser::FunctionType::ImplicitConstructor>();
{
return (TRY((ide::get_constructor_signature(program,function_id))));
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
DeprecatedString generic_parameters = Jakt::DeprecatedString(""sv);
bool is_first_param = true;
if ((!(((((((checked_function)->generics))->params)).is_empty())))){
(generic_parameters += Jakt::DeprecatedString("<"sv));
{
JaktInternal::ArrayIterator<types::FunctionGenericParameter> _magic = ((((((checked_function)->generics))->params)).iterator());
for (;;){
JaktInternal::Optional<types::FunctionGenericParameter> _magic_value = ((_magic).next());
if ((!(((_magic_value).has_value())))){
break;
}
types::FunctionGenericParameter parameter = (_magic_value.value());
{
DeprecatedString const generic_type = TRY((((program)->type_name(((parameter).type_id()),false))));
DeprecatedString const separator = JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_AT_LOOP(([&]() -> JaktInternal::ExplicitValueOrControlFlow<DeprecatedString,ErrorOr<DeprecatedString>>{
auto __jakt_enum_value = (is_first_param);
if (__jakt_enum_value == true) {
return JaktInternal::ExplicitValue(Jakt::DeprecatedString(""sv));
}
else {
return JaktInternal::ExplicitValue(Jakt::DeprecatedString(", "sv));
}
}()))
;
(generic_parameters += TRY((__jakt_format(Jakt::DeprecatedString("{}{}"sv),separator,generic_type))));
(is_first_param = false);
}

}
}

(generic_parameters += Jakt::DeprecatedString(">"sv));
}
DeprecatedString parameters = Jakt::DeprecatedString(""sv);
(is_first_param = true);
{
JaktInternal::ArrayIterator<types::CheckedParameter> _magic = ((((checked_function)->params)).iterator());
for (;;){
JaktInternal::Optional<types::CheckedParameter> _magic_value = ((_magic).next());
if ((!(((_magic_value).has_value())))){
break;
}
types::CheckedParameter param = (_magic_value.value());
{
DeprecatedString const anon_value = JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_AT_LOOP(([&]() -> JaktInternal::ExplicitValueOrControlFlow<DeprecatedString,ErrorOr<DeprecatedString>>{
auto __jakt_enum_value = (((param).requires_label));
if (__jakt_enum_value == true) {
return JaktInternal::ExplicitValue(Jakt::DeprecatedString(""sv));
}
else {
return JaktInternal::ExplicitValue(Jakt::DeprecatedString("anon "sv));
}
}()))
;
DeprecatedString const is_mutable = JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_AT_LOOP(([&]() -> JaktInternal::ExplicitValueOrControlFlow<DeprecatedString,ErrorOr<DeprecatedString>>{
auto __jakt_enum_value = (((((param).variable))->is_mutable));
if (__jakt_enum_value == true) {
return JaktInternal::ExplicitValue(Jakt::DeprecatedString("mut "sv));
}
else {
return JaktInternal::ExplicitValue(Jakt::DeprecatedString(""sv));
}
}()))
;
DeprecatedString variable_type = TRY((((program)->type_name(((((param).variable))->type_id),false))));
if ((variable_type != Jakt::DeprecatedString("void"sv))){
(variable_type = (Jakt::DeprecatedString(": "sv) + variable_type));
}
else {
(variable_type = Jakt::DeprecatedString(""sv));
}

DeprecatedString const separator = JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_AT_LOOP(([&]() -> JaktInternal::ExplicitValueOrControlFlow<DeprecatedString,ErrorOr<DeprecatedString>>{
auto __jakt_enum_value = (is_first_param);
if (__jakt_enum_value == true) {
return JaktInternal::ExplicitValue(Jakt::DeprecatedString(""sv));
}
else {
return JaktInternal::ExplicitValue(Jakt::DeprecatedString(", "sv));
}
}()))
;
(parameters += TRY((__jakt_format(Jakt::DeprecatedString("{}{}{}{}{}"sv),separator,anon_value,is_mutable,((((param).variable))->name),variable_type))));
(is_first_param = false);
}

}
}

DeprecatedString const throws_str = JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<DeprecatedString,ErrorOr<DeprecatedString>>{
auto __jakt_enum_value = (((checked_function)->can_throw));
if (__jakt_enum_value == true) {
return JaktInternal::ExplicitValue(Jakt::DeprecatedString(" throws"sv));
}
else {
return JaktInternal::ExplicitValue(Jakt::DeprecatedString(""sv));
}
}()))
;
DeprecatedString returns = TRY((((program)->type_name(((checked_function)->return_type_id),false))));
if ((returns != Jakt::DeprecatedString("void"sv))){
(returns = (Jakt::DeprecatedString(" -> "sv) + returns));
}
else {
(returns = Jakt::DeprecatedString(""sv));
}

return (TRY((__jakt_format(Jakt::DeprecatedString("function {}{}({}){}{}"sv),((checked_function)->name),generic_parameters,parameters,throws_str,returns))));
}
}

ErrorOr<DeprecatedString> ide::JaktSymbol::debug_description() const { auto builder = MUST(DeprecatedStringBuilder::create());TRY(builder.append("JaktSymbol("sv));{
JaktInternal::PrettyPrint::ScopedLevelIncrease increase_indent {};
TRY(JaktInternal::PrettyPrint::output_indentation(builder));TRY(builder.append("name: "sv));TRY(builder.appendff("\"{}\", ", name));
TRY(JaktInternal::PrettyPrint::output_indentation(builder));TRY(builder.append("detail: "sv));TRY(builder.appendff("{}, ", detail));
TRY(JaktInternal::PrettyPrint::output_indentation(builder));TRY(builder.append("kind: "sv));TRY(builder.appendff("\"{}\", ", kind));
TRY(JaktInternal::PrettyPrint::output_indentation(builder));TRY(builder.append("range: "sv));TRY(builder.appendff("{}, ", range));
TRY(JaktInternal::PrettyPrint::output_indentation(builder));TRY(builder.append("selection_range: "sv));TRY(builder.appendff("{}, ", selection_range));
TRY(JaktInternal::PrettyPrint::output_indentation(builder));TRY(builder.append("children: "sv));TRY(builder.appendff("{}", children));
}
TRY(builder.append(")"sv));return builder.to_string(); }
ide::JaktSymbol::JaktSymbol(DeprecatedString a_name, JaktInternal::Optional<DeprecatedString> a_detail, DeprecatedString a_kind, utility::Span a_range, utility::Span a_selection_range, JaktInternal::DynamicArray<ide::JaktSymbol> a_children) :name(a_name), detail(a_detail), kind(a_kind), range(a_range), selection_range(a_selection_range), children(a_children){}

ErrorOr<DeprecatedString> ide::JaktSymbol::to_json() const {
{
DeprecatedStringBuilder json_builder = TRY((DeprecatedStringBuilder::create()));
TRY((((json_builder).append_string(Jakt::DeprecatedString("{"sv)))));
TRY((((json_builder).append_string(TRY((__jakt_format(Jakt::DeprecatedString("\"name\": \"{}\","sv),((*this).name))))))));
if (((((*this).detail)).has_value())){
TRY((((json_builder).append_string(TRY((__jakt_format(Jakt::DeprecatedString("\"detail\": \"{}\","sv),((*this).detail))))))));
}
TRY((((json_builder).append_string(TRY((__jakt_format(Jakt::DeprecatedString("\"kind\": \"{}\","sv),((*this).kind))))))));
TRY((((json_builder).append_string(TRY((__jakt_format(Jakt::DeprecatedString("\"range\": {{\"start\": {}, \"end\": {}}},"sv),((((*this).range)).start),((((*this).range)).end))))))));
TRY((((json_builder).append_string(TRY((__jakt_format(Jakt::DeprecatedString("\"selection_range\": {{\"start\": {}, \"end\": {}}},"sv),((((*this).selection_range)).start),((((*this).selection_range)).end))))))));
JaktInternal::DynamicArray<DeprecatedString> child_symbols = (TRY((DynamicArray<DeprecatedString>::create_with({}))));
TRY((((child_symbols).ensure_capacity(((((*this).children)).size())))));
{
JaktInternal::ArrayIterator<ide::JaktSymbol> _magic = ((((*this).children)).iterator());
for (;;){
JaktInternal::Optional<ide::JaktSymbol> _magic_value = ((_magic).next());
if ((!(((_magic_value).has_value())))){
break;
}
ide::JaktSymbol child = (_magic_value.value());
{
TRY((((child_symbols).push(TRY((((child).to_json())))))));
}

}
}

TRY((((json_builder).append_string(TRY((__jakt_format(Jakt::DeprecatedString("\"children\": [{}]"sv),utility::join(child_symbols,Jakt::DeprecatedString(","sv)))))))));
TRY((((json_builder).append_string(Jakt::DeprecatedString("}"sv)))));
return (TRY((((json_builder).to_string()))));
}
}

ErrorOr<DeprecatedString> ide::Mutability::debug_description() const {
auto builder = TRY(DeprecatedStringBuilder::create());
switch (this->index()) {case 0 /* DoesNotApply */: {
[[maybe_unused]] auto const& that = this->template get<Mutability::DoesNotApply>();
TRY(builder.append("Mutability::DoesNotApply"sv));
break;}
case 1 /* Immutable */: {
[[maybe_unused]] auto const& that = this->template get<Mutability::Immutable>();
TRY(builder.append("Mutability::Immutable"sv));
break;}
case 2 /* Mutable */: {
[[maybe_unused]] auto const& that = this->template get<Mutability::Mutable>();
TRY(builder.append("Mutability::Mutable"sv));
break;}
}
return builder.to_string();
}
ErrorOr<DeprecatedString> ide::Usage::debug_description() const {
auto builder = TRY(DeprecatedStringBuilder::create());
switch (this->index()) {case 0 /* Variable */: {
[[maybe_unused]] auto const& that = this->template get<Usage::Variable>();
TRY(builder.append("Usage::Variable"sv));
TRY(builder.append("("sv));
{
JaktInternal::PrettyPrint::ScopedLevelIncrease increase_indent {};
TRY(JaktInternal::PrettyPrint::output_indentation(builder));
TRY(builder.appendff("span: {}", that.span));
TRY(builder.append(", "sv));
TRY(JaktInternal::PrettyPrint::output_indentation(builder));
TRY(builder.appendff("name: \"{}\"", that.name));
TRY(builder.append(", "sv));
TRY(JaktInternal::PrettyPrint::output_indentation(builder));
TRY(builder.appendff("type_id: {}", that.type_id));
TRY(builder.append(", "sv));
TRY(JaktInternal::PrettyPrint::output_indentation(builder));
TRY(builder.appendff("mutability: {}", that.mutability));
TRY(builder.append(", "sv));
TRY(JaktInternal::PrettyPrint::output_indentation(builder));
TRY(builder.appendff("var_type: {}", that.var_type));
TRY(builder.append(", "sv));
TRY(JaktInternal::PrettyPrint::output_indentation(builder));
TRY(builder.appendff("visibility: {}", that.visibility));
TRY(builder.append(", "sv));
TRY(JaktInternal::PrettyPrint::output_indentation(builder));
TRY(builder.appendff("struct_type_id: {}", that.struct_type_id));
}
TRY(builder.append(")"sv));
break;}
case 1 /* Call */: {
[[maybe_unused]] auto const& that = this->template get<Usage::Call>();
TRY(builder.append("Usage::Call"sv));
TRY(builder.appendff("({})", that.value));
break;}
case 2 /* Typename */: {
[[maybe_unused]] auto const& that = this->template get<Usage::Typename>();
TRY(builder.append("Usage::Typename"sv));
TRY(builder.appendff("({})", that.value));
break;}
case 3 /* NameSet */: {
[[maybe_unused]] auto const& that = this->template get<Usage::NameSet>();
TRY(builder.append("Usage::NameSet"sv));
TRY(builder.appendff("({})", that.value));
break;}
case 4 /* EnumVariant */: {
[[maybe_unused]] auto const& that = this->template get<Usage::EnumVariant>();
TRY(builder.append("Usage::EnumVariant"sv));
TRY(builder.append("("sv));
{
JaktInternal::PrettyPrint::ScopedLevelIncrease increase_indent {};
TRY(JaktInternal::PrettyPrint::output_indentation(builder));
TRY(builder.appendff("span: {}", that.span));
TRY(builder.append(", "sv));
TRY(JaktInternal::PrettyPrint::output_indentation(builder));
TRY(builder.appendff("name: \"{}\"", that.name));
TRY(builder.append(", "sv));
TRY(JaktInternal::PrettyPrint::output_indentation(builder));
TRY(builder.appendff("type_id: {}", that.type_id));
TRY(builder.append(", "sv));
TRY(JaktInternal::PrettyPrint::output_indentation(builder));
TRY(builder.appendff("variants: {}", that.variants));
TRY(builder.append(", "sv));
TRY(JaktInternal::PrettyPrint::output_indentation(builder));
TRY(builder.appendff("number_constant: {}", that.number_constant));
}
TRY(builder.append(")"sv));
break;}
}
return builder.to_string();
}
ErrorOr<DeprecatedString> ide::VarType::debug_description() const {
auto builder = TRY(DeprecatedStringBuilder::create());
switch (this->index()) {case 0 /* Variable */: {
[[maybe_unused]] auto const& that = this->template get<VarType::Variable>();
TRY(builder.append("VarType::Variable"sv));
break;}
case 1 /* Field */: {
[[maybe_unused]] auto const& that = this->template get<VarType::Field>();
TRY(builder.append("VarType::Field"sv));
break;}
}
return builder.to_string();
}
ErrorOr<DeprecatedString> ide::VarVisibility::debug_description() const {
auto builder = TRY(DeprecatedStringBuilder::create());
switch (this->index()) {case 0 /* DoesNotApply */: {
[[maybe_unused]] auto const& that = this->template get<VarVisibility::DoesNotApply>();
TRY(builder.append("VarVisibility::DoesNotApply"sv));
break;}
case 1 /* Public */: {
[[maybe_unused]] auto const& that = this->template get<VarVisibility::Public>();
TRY(builder.append("VarVisibility::Public"sv));
break;}
case 2 /* Private */: {
[[maybe_unused]] auto const& that = this->template get<VarVisibility::Private>();
TRY(builder.append("VarVisibility::Private"sv));
break;}
case 3 /* Restricted */: {
[[maybe_unused]] auto const& that = this->template get<VarVisibility::Restricted>();
TRY(builder.append("VarVisibility::Restricted"sv));
break;}
}
return builder.to_string();
}
}
} // namespace Jakt
