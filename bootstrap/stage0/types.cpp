#include "types.h"
namespace Jakt {
namespace types {
types::TypeId builtin(types::BuiltinType const builtin) {
{
return (types::TypeId(types::ModuleId(static_cast<size_t>(0ULL)),((builtin).id())));
}
}

types::TypeId void_type_id() {
{
return (types::builtin( types::BuiltinType { typename types::BuiltinType::Void() } ));
}
}

types::TypeId unknown_type_id() {
{
return (types::builtin( types::BuiltinType { typename types::BuiltinType::Unknown() } ));
}
}

types::TypeId never_type_id() {
{
return (types::builtin( types::BuiltinType { typename types::BuiltinType::Never() } ));
}
}

ErrorOr<DeprecatedString> types::FunctionGenerics::debug_description() const { auto builder = MUST(DeprecatedStringBuilder::create());TRY(builder.append("FunctionGenerics("sv));{
JaktInternal::PrettyPrint::ScopedLevelIncrease increase_indent {};
TRY(JaktInternal::PrettyPrint::output_indentation(builder));TRY(builder.append("base_scope_id: "sv));TRY(builder.appendff("{}, ", base_scope_id));
TRY(JaktInternal::PrettyPrint::output_indentation(builder));TRY(builder.append("base_params: "sv));TRY(builder.appendff("{}, ", base_params));
TRY(JaktInternal::PrettyPrint::output_indentation(builder));TRY(builder.append("params: "sv));TRY(builder.appendff("{}, ", params));
TRY(JaktInternal::PrettyPrint::output_indentation(builder));TRY(builder.append("specializations: "sv));TRY(builder.appendff("{}", specializations));
}
TRY(builder.append(")"sv));return builder.to_string(); }
types::FunctionGenerics::FunctionGenerics(types::ScopeId&& a_base_scope_id, JaktInternal::DynamicArray<types::CheckedParameter>&& a_base_params, JaktInternal::DynamicArray<types::FunctionGenericParameter>&& a_params, JaktInternal::DynamicArray<JaktInternal::DynamicArray<types::TypeId>>&& a_specializations): base_scope_id(move(a_base_scope_id)), base_params(move(a_base_params)), params(move(a_params)), specializations(move(a_specializations)){}
ErrorOr<NonnullRefPtr<FunctionGenerics>> types::FunctionGenerics::create(types::ScopeId base_scope_id, JaktInternal::DynamicArray<types::CheckedParameter> base_params, JaktInternal::DynamicArray<types::FunctionGenericParameter> params, JaktInternal::DynamicArray<JaktInternal::DynamicArray<types::TypeId>> specializations) { auto o = TRY(adopt_nonnull_ref_or_enomem(new (nothrow) FunctionGenerics (move(base_scope_id), move(base_params), move(params), move(specializations)))); return o; }
bool types::FunctionGenerics::is_specialized_for_types(JaktInternal::DynamicArray<types::TypeId> const types) const {
{
if ((((types).size()) == static_cast<size_t>(0ULL))){
return (true);
}
{
JaktInternal::ArrayIterator<JaktInternal::DynamicArray<types::TypeId>> _magic = ((((*this).specializations)).iterator());
for (;;){
JaktInternal::Optional<JaktInternal::DynamicArray<types::TypeId>> _magic_value = ((_magic).next());
if ((!(((_magic_value).has_value())))){
break;
}
JaktInternal::DynamicArray<types::TypeId> specialization = (_magic_value.value());
{
bool matched = true;
if ((((types).size()) == ((specialization).size()))){
{
JaktInternal::Range<size_t> _magic = (JaktInternal::Range<size_t>{static_cast<size_t>(0LL),static_cast<size_t>(((types).size()))});
for (;;){
JaktInternal::Optional<size_t> _magic_value = ((_magic).next());
if ((!(((_magic_value).has_value())))){
break;
}
size_t i = (_magic_value.value());
{
if ((!(((((types)[i])).equals(((specialization)[i])))))){
(matched = false);
break;
}
}

}
}

}
if (matched){
return (true);
}
}

}
}

return (false);
}
}

ErrorOr<DeprecatedString> types::CheckedStringLiteral::debug_description() const { auto builder = MUST(DeprecatedStringBuilder::create());TRY(builder.append("CheckedStringLiteral("sv));{
JaktInternal::PrettyPrint::ScopedLevelIncrease increase_indent {};
TRY(JaktInternal::PrettyPrint::output_indentation(builder));TRY(builder.append("value: "sv));TRY(builder.appendff("{}, ", value));
TRY(JaktInternal::PrettyPrint::output_indentation(builder));TRY(builder.append("type_id: "sv));TRY(builder.appendff("{}, ", type_id));
TRY(JaktInternal::PrettyPrint::output_indentation(builder));TRY(builder.append("may_throw: "sv));TRY(builder.appendff("{}", may_throw));
}
TRY(builder.append(")"sv));return builder.to_string(); }
DeprecatedString types::CheckedStringLiteral::to_string() const {
{
return (((((*this).value)).to_string()));
}
}

types::CheckedStringLiteral::CheckedStringLiteral(types::StringLiteral a_value, types::TypeId a_type_id, bool a_may_throw) :value(a_value), type_id(a_type_id), may_throw(a_may_throw){}

ErrorOr<DeprecatedString> types::GenericInferences::debug_description() const { auto builder = MUST(DeprecatedStringBuilder::create());TRY(builder.append("GenericInferences("sv));{
JaktInternal::PrettyPrint::ScopedLevelIncrease increase_indent {};
TRY(JaktInternal::PrettyPrint::output_indentation(builder));TRY(builder.append("values: "sv));TRY(builder.appendff("{}", values));
}
TRY(builder.append(")"sv));return builder.to_string(); }
DeprecatedString types::GenericInferences::map_name(DeprecatedString const type) const {
{
JaktInternal::Optional<DeprecatedString> mapped = ((((*this).values)).get(type));
JaktInternal::Optional<DeprecatedString> final_mapped_result = mapped;
while (((mapped).has_value())){
(final_mapped_result = mapped);
(mapped = ((((*this).values)).get((mapped.value()))));
}
return (final_mapped_result.value_or_lazy_evaluated([&] { return type; }));
}
}

types::GenericInferences::GenericInferences(JaktInternal::Dictionary<DeprecatedString,DeprecatedString> a_values) :values(a_values){}

void types::GenericInferences::restore(JaktInternal::Dictionary<DeprecatedString,DeprecatedString> const checkpoint) {
{
(((*this).values) = checkpoint);
}
}

ErrorOr<types::TypeId> types::GenericInferences::map(types::TypeId const type_id) const {
{
return (TRY((types::TypeId::from_string(((*this).map_name(TRY((((type_id).to_string())))))))));
}
}

JaktInternal::Dictionary<DeprecatedString,DeprecatedString> types::GenericInferences::iterator() const {
{
return (((*this).values));
}
}

ErrorOr<void> types::GenericInferences::set(DeprecatedString const key,DeprecatedString const value) {
{
if ((key == value)){
outln(Jakt::DeprecatedString("Warning: Generic parameter {} is being bound to itself"sv),key);
abort();
}
DeprecatedString const mapped_value = ((*this).map_name(value));
if ((key == mapped_value)){
return {};
}
TRY(((*this).values).set(key, mapped_value));
}
return {};
}

ErrorOr<void> types::GenericInferences::set_all(JaktInternal::DynamicArray<types::CheckedGenericParameter> const keys,JaktInternal::DynamicArray<types::TypeId> const values) {
{
{
JaktInternal::Range<size_t> _magic = (JaktInternal::Range<size_t>{static_cast<size_t>(static_cast<size_t>(0ULL)),static_cast<size_t>(((keys).size()))});
for (;;){
JaktInternal::Optional<size_t> _magic_value = ((_magic).next());
if ((!(((_magic_value).has_value())))){
break;
}
size_t i = (_magic_value.value());
{
DeprecatedString const key = TRY((((((((keys)[i])).type_id)).to_string())));
DeprecatedString const value = TRY((((((values)[i])).to_string())));
TRY((((*this).set(key,value))));
}

}
}

}
return {};
}

ErrorOr<void> types::GenericInferences::set_from(JaktInternal::Dictionary<DeprecatedString,DeprecatedString> const checkpoint) {
{
{
JaktInternal::DictionaryIterator<DeprecatedString,DeprecatedString> _magic = ((checkpoint).iterator());
for (;;){
JaktInternal::Optional<JaktInternal::Tuple<DeprecatedString,DeprecatedString>> _magic_value = ((_magic).next());
if ((!(((_magic_value).has_value())))){
break;
}
JaktInternal::Tuple<DeprecatedString,DeprecatedString> key__value__ = (_magic_value.value());
{
JaktInternal::Tuple<DeprecatedString,DeprecatedString> const jakt__key__value__ = key__value__;
DeprecatedString const key = ((jakt__key__value__).template get<0>());
DeprecatedString const value = ((jakt__key__value__).template get<1>());

TRY(((*this).values).set(key, value));
}

}
}

}
return {};
}

JaktInternal::Optional<DeprecatedString> types::GenericInferences::get(DeprecatedString const key) const {
{
return (((((*this).values)).get(key)));
}
}

ErrorOr<JaktInternal::Dictionary<DeprecatedString,DeprecatedString>> types::GenericInferences::perform_checkpoint(bool const reset) {
{
JaktInternal::Dictionary<DeprecatedString,DeprecatedString> const result = ((*this).values);
(((*this).values) = (TRY((Dictionary<DeprecatedString, DeprecatedString>::create_with_entries({})))));
if ((!(reset))){
{
JaktInternal::DictionaryIterator<DeprecatedString,DeprecatedString> _magic = ((result).iterator());
for (;;){
JaktInternal::Optional<JaktInternal::Tuple<DeprecatedString,DeprecatedString>> _magic_value = ((_magic).next());
if ((!(((_magic_value).has_value())))){
break;
}
JaktInternal::Tuple<DeprecatedString,DeprecatedString> key__value__ = (_magic_value.value());
{
JaktInternal::Tuple<DeprecatedString,DeprecatedString> const jakt__key__value__ = key__value__;
DeprecatedString const key = ((jakt__key__value__).template get<0>());
DeprecatedString const value = ((jakt__key__value__).template get<1>());

TRY(((*this).values).set(key, value));
}

}
}

}
return (result);
}
}

ErrorOr<DeprecatedString> types::CheckedStruct::debug_description() const { auto builder = MUST(DeprecatedStringBuilder::create());TRY(builder.append("CheckedStruct("sv));{
JaktInternal::PrettyPrint::ScopedLevelIncrease increase_indent {};
TRY(JaktInternal::PrettyPrint::output_indentation(builder));TRY(builder.append("name: "sv));TRY(builder.appendff("\"{}\", ", name));
TRY(JaktInternal::PrettyPrint::output_indentation(builder));TRY(builder.append("name_span: "sv));TRY(builder.appendff("{}, ", name_span));
TRY(JaktInternal::PrettyPrint::output_indentation(builder));TRY(builder.append("generic_parameters: "sv));TRY(builder.appendff("{}, ", generic_parameters));
TRY(JaktInternal::PrettyPrint::output_indentation(builder));TRY(builder.append("fields: "sv));TRY(builder.appendff("{}, ", fields));
TRY(JaktInternal::PrettyPrint::output_indentation(builder));TRY(builder.append("scope_id: "sv));TRY(builder.appendff("{}, ", scope_id));
TRY(JaktInternal::PrettyPrint::output_indentation(builder));TRY(builder.append("definition_linkage: "sv));TRY(builder.appendff("{}, ", definition_linkage));
TRY(JaktInternal::PrettyPrint::output_indentation(builder));TRY(builder.append("trait_implementations: "sv));TRY(builder.appendff("{}, ", trait_implementations));
TRY(JaktInternal::PrettyPrint::output_indentation(builder));TRY(builder.append("record_type: "sv));TRY(builder.appendff("{}, ", record_type));
TRY(JaktInternal::PrettyPrint::output_indentation(builder));TRY(builder.append("type_id: "sv));TRY(builder.appendff("{}, ", type_id));
TRY(JaktInternal::PrettyPrint::output_indentation(builder));TRY(builder.append("super_struct_id: "sv));TRY(builder.appendff("{}, ", super_struct_id));
TRY(JaktInternal::PrettyPrint::output_indentation(builder));TRY(builder.append("external_name: "sv));TRY(builder.appendff("{}", external_name));
}
TRY(builder.append(")"sv));return builder.to_string(); }
types::CheckedStruct::CheckedStruct(DeprecatedString a_name, utility::Span a_name_span, JaktInternal::DynamicArray<types::CheckedGenericParameter> a_generic_parameters, JaktInternal::DynamicArray<types::CheckedField> a_fields, types::ScopeId a_scope_id, parser::DefinitionLinkage a_definition_linkage, JaktInternal::Dictionary<DeprecatedString,JaktInternal::Tuple<types::TraitId,JaktInternal::DynamicArray<types::TypeId>>> a_trait_implementations, parser::RecordType a_record_type, types::TypeId a_type_id, JaktInternal::Optional<types::StructId> a_super_struct_id, JaktInternal::Optional<DeprecatedString> a_external_name) :name(a_name), name_span(a_name_span), generic_parameters(a_generic_parameters), fields(a_fields), scope_id(a_scope_id), definition_linkage(a_definition_linkage), trait_implementations(a_trait_implementations), record_type(a_record_type), type_id(a_type_id), super_struct_id(a_super_struct_id), external_name(a_external_name){}

DeprecatedString types::CheckedStruct::name_for_codegen() const {
{
return (((*this).external_name).value_or_lazy_evaluated([&] { return ((*this).name); }));
}
}

ErrorOr<DeprecatedString> types::CheckedVariable::debug_description() const { auto builder = MUST(DeprecatedStringBuilder::create());TRY(builder.append("CheckedVariable("sv));{
JaktInternal::PrettyPrint::ScopedLevelIncrease increase_indent {};
TRY(JaktInternal::PrettyPrint::output_indentation(builder));TRY(builder.append("name: "sv));TRY(builder.appendff("\"{}\", ", name));
TRY(JaktInternal::PrettyPrint::output_indentation(builder));TRY(builder.append("type_id: "sv));TRY(builder.appendff("{}, ", type_id));
TRY(JaktInternal::PrettyPrint::output_indentation(builder));TRY(builder.append("is_mutable: "sv));TRY(builder.appendff("{}, ", is_mutable));
TRY(JaktInternal::PrettyPrint::output_indentation(builder));TRY(builder.append("definition_span: "sv));TRY(builder.appendff("{}, ", definition_span));
TRY(JaktInternal::PrettyPrint::output_indentation(builder));TRY(builder.append("type_span: "sv));TRY(builder.appendff("{}, ", type_span));
TRY(JaktInternal::PrettyPrint::output_indentation(builder));TRY(builder.append("visibility: "sv));TRY(builder.appendff("{}, ", visibility));
TRY(JaktInternal::PrettyPrint::output_indentation(builder));TRY(builder.append("owner_scope: "sv));TRY(builder.appendff("{}", owner_scope));
}
TRY(builder.append(")"sv));return builder.to_string(); }
ErrorOr<NonnullRefPtr<types::CheckedVariable>> types::CheckedVariable::map_types(Function<ErrorOr<types::TypeId>(types::TypeId)> const& map) const {
{
return (TRY((types::CheckedVariable::create(((*this).name),TRY((map(((*this).type_id)))),((*this).is_mutable),((*this).definition_span),((*this).type_span),((*this).visibility),((*this).owner_scope)))));
}
}

types::CheckedVariable::CheckedVariable(DeprecatedString&& a_name, types::TypeId&& a_type_id, bool&& a_is_mutable, utility::Span&& a_definition_span, JaktInternal::Optional<utility::Span>&& a_type_span, types::CheckedVisibility&& a_visibility, JaktInternal::Optional<types::ScopeId>&& a_owner_scope): name(move(a_name)), type_id(move(a_type_id)), is_mutable(move(a_is_mutable)), definition_span(move(a_definition_span)), type_span(move(a_type_span)), visibility(move(a_visibility)), owner_scope(move(a_owner_scope)){}
ErrorOr<NonnullRefPtr<CheckedVariable>> types::CheckedVariable::create(DeprecatedString name, types::TypeId type_id, bool is_mutable, utility::Span definition_span, JaktInternal::Optional<utility::Span> type_span, types::CheckedVisibility visibility, JaktInternal::Optional<types::ScopeId> owner_scope) { auto o = TRY(adopt_nonnull_ref_or_enomem(new (nothrow) CheckedVariable (move(name), move(type_id), move(is_mutable), move(definition_span), move(type_span), move(visibility), move(owner_scope)))); return o; }
ErrorOr<DeprecatedString> types::CheckedProgram::debug_description() const { auto builder = MUST(DeprecatedStringBuilder::create());TRY(builder.append("CheckedProgram("sv));{
JaktInternal::PrettyPrint::ScopedLevelIncrease increase_indent {};
TRY(JaktInternal::PrettyPrint::output_indentation(builder));TRY(builder.append("compiler: "sv));TRY(builder.appendff("{}, ", *compiler));
TRY(JaktInternal::PrettyPrint::output_indentation(builder));TRY(builder.append("modules: "sv));TRY(builder.appendff("{}, ", modules));
TRY(JaktInternal::PrettyPrint::output_indentation(builder));TRY(builder.append("loaded_modules: "sv));TRY(builder.appendff("{}", loaded_modules));
}
TRY(builder.append(")"sv));return builder.to_string(); }
bool types::CheckedProgram::is_floating(types::TypeId const type_id) const {
{
NonnullRefPtr<typename types::Type> const type = ((*this).get_type(type_id));
return (JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<bool, bool>{
auto&& __jakt_match_variant = *type;
switch(__jakt_match_variant.index()) {
case 10: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::Type::F32>();
return JaktInternal::ExplicitValue(true);
};/*case end*/
case 11: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::Type::F64>();
return JaktInternal::ExplicitValue(true);
};/*case end*/
default: {
return JaktInternal::ExplicitValue(false);
};/*case end*/
}/*switch end*/
}()
)));
}
}

ErrorOr<JaktInternal::Optional<JaktInternal::Tuple<JaktInternal::DynamicArray<types::FunctionId>,types::ScopeId>>> types::CheckedProgram::find_scoped_functions_with_name_in_scope(types::ScopeId const parent_scope_id,DeprecatedString const function_name) const {
{
return (TRY((((*this).template for_each_scope_accessible_unqualified_from_scope<JaktInternal::Tuple<JaktInternal::DynamicArray<types::FunctionId>,types::ScopeId>>(parent_scope_id,(([function_name, this](types::ScopeId scope_id, JaktInternal::Optional<DeprecatedString> name_override, bool is_alias) -> ErrorOr<typename utility::IterationDecision<JaktInternal::Tuple<JaktInternal::DynamicArray<types::FunctionId>,types::ScopeId>>> {
{
NonnullRefPtr<types::Scope> const scope = TRY((((*this).get_scope(scope_id))));
JaktInternal::Optional<JaktInternal::DynamicArray<types::FunctionId>> const maybe_functions = ((((scope)->functions)).get(function_name));
if (((maybe_functions).has_value())){
return ( typename utility::IterationDecision<JaktInternal::Tuple<JaktInternal::DynamicArray<types::FunctionId>,types::ScopeId>> { typename utility::IterationDecision<JaktInternal::Tuple<JaktInternal::DynamicArray<types::FunctionId>,types::ScopeId>>::Break((Tuple{(maybe_functions.value()), scope_id})) } );
}
return ( typename utility::IterationDecision<JaktInternal::Tuple<JaktInternal::DynamicArray<types::FunctionId>,types::ScopeId>> { typename utility::IterationDecision<JaktInternal::Tuple<JaktInternal::DynamicArray<types::FunctionId>,types::ScopeId>>::Continue() } );
}
}
)))))));
}
}

bool types::CheckedProgram::is_signed(types::TypeId const type_id) const {
{
return (((((*this).get_type(type_id)))->is_signed()));
}
}

ErrorOr<JaktInternal::Optional<types::StructId>> types::CheckedProgram::find_struct_in_scope(types::ScopeId const scope_id,DeprecatedString const name) const {
{
return (TRY((((*this).template for_each_scope_accessible_unqualified_from_scope<types::StructId>(scope_id,(([name, this](types::ScopeId scope_id, JaktInternal::Optional<DeprecatedString> name_override, bool is_alias) -> ErrorOr<typename utility::IterationDecision<types::StructId>> {
{
NonnullRefPtr<types::Scope> const scope = TRY((((*this).get_scope(scope_id))));
JaktInternal::Optional<types::StructId> const maybe_struct = ((((scope)->structs)).get(name));
if (((maybe_struct).has_value())){
return ( typename utility::IterationDecision<types::StructId> { typename utility::IterationDecision<types::StructId>::Break((maybe_struct.value())) } );
}
return ( typename utility::IterationDecision<types::StructId> { typename utility::IterationDecision<types::StructId>::Continue() } );
}
}
)))))));
}
}

ErrorOr<void> types::CheckedProgram::set_loaded_module(DeprecatedString const module_name,types::LoadedModule const loaded_module) {
{
TRY((((((*this).loaded_modules)).set(module_name,loaded_module))));
}
return {};
}

bool types::CheckedProgram::is_integer(types::TypeId const type_id) const {
{
NonnullRefPtr<typename types::Type> const type = ((*this).get_type(type_id));
return (JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<bool, bool>{
auto&& __jakt_match_variant = *type;
switch(__jakt_match_variant.index()) {
case 6: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::Type::I8>();
return JaktInternal::ExplicitValue(true);
};/*case end*/
case 7: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::Type::I16>();
return JaktInternal::ExplicitValue(true);
};/*case end*/
case 8: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::Type::I32>();
return JaktInternal::ExplicitValue(true);
};/*case end*/
case 9: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::Type::I64>();
return JaktInternal::ExplicitValue(true);
};/*case end*/
case 2: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::Type::U8>();
return JaktInternal::ExplicitValue(true);
};/*case end*/
case 3: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::Type::U16>();
return JaktInternal::ExplicitValue(true);
};/*case end*/
case 4: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::Type::U32>();
return JaktInternal::ExplicitValue(true);
};/*case end*/
case 5: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::Type::U64>();
return JaktInternal::ExplicitValue(true);
};/*case end*/
case 12: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::Type::Usize>();
return JaktInternal::ExplicitValue(true);
};/*case end*/
case 15: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::Type::CInt>();
return JaktInternal::ExplicitValue(true);
};/*case end*/
case 14: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::Type::CChar>();
return JaktInternal::ExplicitValue(true);
};/*case end*/
default: {
return JaktInternal::ExplicitValue(false);
};/*case end*/
}/*switch end*/
}()
)));
}
}

ErrorOr<types::ScopeId> types::CheckedProgram::create_scope(JaktInternal::Optional<types::ScopeId> const parent_scope_id,bool const can_throw,DeprecatedString const debug_name,types::ModuleId const module_id) {
{
if (((parent_scope_id).has_value())){
if (((((((parent_scope_id.value())).module_id)).id) >= ((((*this).modules)).size()))){
TRY((((((*this).compiler))->panic(TRY((__jakt_format(Jakt::DeprecatedString("create_scope: parent_scope_id.module is invalid! No module with id {}."sv),(((((parent_scope_id.value())).module_id)).id))))))));
}
if (((((parent_scope_id.value())).id) >= ((((((((*this).modules))[(((((parent_scope_id.value())).module_id)).id)]))->scopes)).size()))){
TRY((((((*this).compiler))->panic(TRY((__jakt_format(Jakt::DeprecatedString("create_scope: parent_scope_id.id is invalid! Module {} does not have a scope with id {}."sv),(((((parent_scope_id.value())).module_id)).id),(((parent_scope_id.value())).id))))))));
}
}
JaktInternal::Optional<DeprecatedString> const none_string = JaktInternal::OptionalNone();
NonnullRefPtr<types::Scope> const scope = TRY((types::Scope::create(none_string,none_string,(TRY((Dictionary<DeprecatedString, types::VarId>::create_with_entries({})))),(TRY((Dictionary<DeprecatedString, types::Value>::create_with_entries({})))),(TRY((Dictionary<DeprecatedString, types::StructId>::create_with_entries({})))),(TRY((Dictionary<DeprecatedString, JaktInternal::DynamicArray<types::FunctionId>>::create_with_entries({})))),(TRY((Dictionary<DeprecatedString, types::EnumId>::create_with_entries({})))),(TRY((Dictionary<DeprecatedString, types::TypeId>::create_with_entries({})))),(TRY((Dictionary<DeprecatedString, types::TraitId>::create_with_entries({})))),(TRY((Dictionary<DeprecatedString, types::ModuleId>::create_with_entries({})))),(TRY((Dictionary<DeprecatedString, types::ScopeId>::create_with_entries({})))),parent_scope_id,JaktInternal::OptionalNone(),(TRY((DynamicArray<types::ScopeId>::create_with({})))),can_throw,JaktInternal::OptionalNone(),JaktInternal::OptionalNone(),(TRY((DynamicArray<parser::IncludeAction>::create_with({})))),(TRY((DynamicArray<parser::IncludeAction>::create_with({})))),debug_name,(TRY((DynamicArray<types::ScopeId>::create_with({})))))));
TRY((((((((((*this).modules))[((module_id).id)]))->scopes)).push(scope))));
return (types::ScopeId(module_id,(JaktInternal::checked_sub<size_t>(((((((((*this).modules))[((module_id).id)]))->scopes)).size()),static_cast<size_t>(1ULL)))));
}
}

NonnullRefPtr<types::Module> types::CheckedProgram::get_module(types::ModuleId const id) const {
{
return (((((*this).modules))[((id).id)]));
}
}

ErrorOr<JaktInternal::Optional<bool>> types::CheckedProgram::for_each_scope_accessible_unqualified_from_scope_impl(types::ScopeId const scope_id,Function<ErrorOr<typename utility::IterationDecision<bool>>(types::ScopeId, JaktInternal::Optional<DeprecatedString>, bool)> const& callback) const {
{
JaktInternal::DynamicArray<types::ScopeId> scopes_to_check = (TRY((DynamicArray<types::ScopeId>::create_with({scope_id}))));
JaktInternal::Set<DeprecatedString> seen = (TRY((Set<DeprecatedString>::create_with_values({}))));
{
JaktInternal::ArrayIterator<types::ScopeId> _magic = ((((TRY((((*this).get_scope(scope_id)))))->children)).iterator());
for (;;){
JaktInternal::Optional<types::ScopeId> _magic_value = ((_magic).next());
if ((!(((_magic_value).has_value())))){
break;
}
types::ScopeId child = (_magic_value.value());
{
TRY((((scopes_to_check).insert(static_cast<size_t>(0ULL),child))));
}

}
}

while ((!(((scopes_to_check).is_empty())))){
types::ScopeId const scope_id = (((scopes_to_check).pop()).value());
TRY((((seen).add(TRY((((scope_id).to_string())))))));
typename utility::IterationDecision<bool> const res = TRY((callback(scope_id,JaktInternal::OptionalNone(),false)));
JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_AT_LOOP(([&]() -> JaktInternal::ExplicitValueOrControlFlow<void,ErrorOr<JaktInternal::Optional<bool>>>{
auto&& __jakt_enum_value = JaktInternal::deref_if_ref_pointer(res);
if (__jakt_enum_value.index() == 0 /* Break */) {
auto& __jakt_match_value = __jakt_enum_value.template get<typename JaktInternal::RemoveRefPtr<utility::IterationDecision<bool>>::Break>();
auto& value = __jakt_match_value.value;
{
return (static_cast<JaktInternal::Optional<bool>>(value));
}
return JaktInternal::ExplicitValue<void>();
}
else {
{
}
return JaktInternal::ExplicitValue<void>();
}
return JaktInternal::ExplicitValue<void>();
}()))
;
NonnullRefPtr<types::Scope> const scope = TRY((((*this).get_scope(scope_id))));
{
JaktInternal::DictionaryIterator<DeprecatedString,types::ScopeId> _magic = ((((scope)->aliases)).iterator());
for (;;){
JaktInternal::Optional<JaktInternal::Tuple<DeprecatedString,types::ScopeId>> _magic_value = ((_magic).next());
if ((!(((_magic_value).has_value())))){
break;
}
JaktInternal::Tuple<DeprecatedString,types::ScopeId> name__alias__ = (_magic_value.value());
{
JaktInternal::Tuple<DeprecatedString,types::ScopeId> const jakt__name__alias__ = name__alias__;
DeprecatedString const name = ((jakt__name__alias__).template get<0>());
types::ScopeId const alias = ((jakt__name__alias__).template get<1>());

typename utility::IterationDecision<bool> const res = TRY((callback(alias,name,true)));
JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_AT_LOOP(([&]() -> JaktInternal::ExplicitValueOrControlFlow<void,ErrorOr<JaktInternal::Optional<bool>>>{
auto&& __jakt_enum_value = JaktInternal::deref_if_ref_pointer(res);
if (__jakt_enum_value.index() == 0 /* Break */) {
auto& __jakt_match_value = __jakt_enum_value.template get<typename JaktInternal::RemoveRefPtr<utility::IterationDecision<bool>>::Break>();
auto& value = __jakt_match_value.value;
{
return (static_cast<JaktInternal::Optional<bool>>(value));
}
return JaktInternal::ExplicitValue<void>();
}
else {
{
}
return JaktInternal::ExplicitValue<void>();
}
return JaktInternal::ExplicitValue<void>();
}()))
;
}

}
}

{
JaktInternal::ArrayIterator<types::ScopeId> _magic = ((((scope)->resolution_mixins)).iterator());
for (;;){
JaktInternal::Optional<types::ScopeId> _magic_value = ((_magic).next());
if ((!(((_magic_value).has_value())))){
break;
}
types::ScopeId entry = (_magic_value.value());
{
TRY((((scopes_to_check).insert(static_cast<size_t>(0ULL),entry))));
{
JaktInternal::ArrayIterator<types::ScopeId> _magic = ((((TRY((((*this).get_scope(entry)))))->children)).iterator());
for (;;){
JaktInternal::Optional<types::ScopeId> _magic_value = ((_magic).next());
if ((!(((_magic_value).has_value())))){
break;
}
types::ScopeId child = (_magic_value.value());
{
if ((!(((seen).contains(TRY((((child).to_string())))))))){
TRY((((scopes_to_check).insert(static_cast<size_t>(0ULL),child))));
}
}

}
}

}

}
}

if (((((scope)->parent)).has_value())){
TRY((((scopes_to_check).insert(static_cast<size_t>(0ULL),(((scope)->parent).value())))));
{
JaktInternal::ArrayIterator<types::ScopeId> _magic = ((((TRY((((*this).get_scope((((scope)->parent).value()))))))->children)).iterator());
for (;;){
JaktInternal::Optional<types::ScopeId> _magic_value = ((_magic).next());
if ((!(((_magic_value).has_value())))){
break;
}
types::ScopeId child = (_magic_value.value());
{
if ((!(((seen).contains(TRY((((child).to_string())))))))){
TRY((((scopes_to_check).insert(static_cast<size_t>(0ULL),child))));
}
}

}
}

}
if (((((scope)->namespace_name)).has_value())){
continue;
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
if ((!(((seen).contains(TRY((((child).to_string())))))))){
TRY((((scopes_to_check).insert(static_cast<size_t>(0ULL),child))));
}
}

}
}

}
types::ModuleId const module_id = ((scope_id).module_id);
types::ScopeId const search_scope_id = types::ScopeId(module_id,static_cast<size_t>(0ULL));
NonnullRefPtr<types::Scope> const search_scope = TRY((((*this).get_scope(search_scope_id))));
{
JaktInternal::DictionaryIterator<DeprecatedString,types::ModuleId> _magic = ((((search_scope)->imports)).iterator());
for (;;){
JaktInternal::Optional<JaktInternal::Tuple<DeprecatedString,types::ModuleId>> _magic_value = ((_magic).next());
if ((!(((_magic_value).has_value())))){
break;
}
JaktInternal::Tuple<DeprecatedString,types::ModuleId> name__module__ = (_magic_value.value());
{
JaktInternal::Tuple<DeprecatedString,types::ModuleId> const jakt__name__module__ = name__module__;
DeprecatedString const name = ((jakt__name__module__).template get<0>());
types::ModuleId const module = ((jakt__name__module__).template get<1>());

types::ScopeId const import_scope_id = types::ScopeId(module,static_cast<size_t>(0ULL));
typename utility::IterationDecision<bool> const res = TRY((callback(import_scope_id,name,false)));
JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_AT_LOOP(([&]() -> JaktInternal::ExplicitValueOrControlFlow<void,ErrorOr<JaktInternal::Optional<bool>>>{
auto&& __jakt_enum_value = JaktInternal::deref_if_ref_pointer(res);
if (__jakt_enum_value.index() == 0 /* Break */) {
auto& __jakt_match_value = __jakt_enum_value.template get<typename JaktInternal::RemoveRefPtr<utility::IterationDecision<bool>>::Break>();
auto& value = __jakt_match_value.value;
{
return (static_cast<JaktInternal::Optional<bool>>(value));
}
return JaktInternal::ExplicitValue<void>();
}
else {
{
}
return JaktInternal::ExplicitValue<void>();
}
return JaktInternal::ExplicitValue<void>();
}()))
;
}

}
}

return (JaktInternal::OptionalNone());
}
}

ErrorOr<bool> types::CheckedProgram::is_scope_directly_accessible_from(types::ScopeId const check_scope_id,types::ScopeId const scope_id) const {
{
return (TRY((((*this).template for_each_scope_accessible_unqualified_from_scope<bool>(scope_id,(([check_scope_id](types::ScopeId scope_id, JaktInternal::Optional<DeprecatedString> name_override, bool is_alias) -> ErrorOr<typename utility::IterationDecision<bool>> {
{
if (((check_scope_id).equals(scope_id))){
return ( typename utility::IterationDecision<bool> { typename utility::IterationDecision<bool>::Break(true) } );
}
return ( typename utility::IterationDecision<bool> { typename utility::IterationDecision<bool>::Continue() } );
}
}
)))))).value_or_lazy_evaluated([&] { return false; }));
}
}

ErrorOr<types::TypeId> types::CheckedProgram::substitute_typevars_in_type_helper(types::TypeId const type_id,types::GenericInferences const generic_inferences,types::ModuleId const module_id) {
{
NonnullRefPtr<typename types::Type> const type_ = ((*this).get_type(type_id));
JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<void, ErrorOr<types::TypeId>>{
auto&& __jakt_match_variant = *type_;
switch(__jakt_match_variant.index()) {
case 18: {
auto&& __jakt_match_value = __jakt_match_variant.template get<types::Type::TypeVariable>();{
JaktInternal::Optional<DeprecatedString> const replacment_type_id_string = ((generic_inferences).get(TRY((((type_id).to_string())))));
if (((replacment_type_id_string).has_value())){
return (TRY((types::TypeId::from_string(((replacment_type_id_string).value())))));
}
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 21: {
auto&& __jakt_match_value = __jakt_match_variant.template get<types::Type::GenericTraitInstance>();types::TraitId const& id = __jakt_match_value.id;
JaktInternal::DynamicArray<types::TypeId> const& args = __jakt_match_value.args;
{
JaktInternal::DynamicArray<types::TypeId> new_args = (TRY((DynamicArray<types::TypeId>::create_with({}))));
TRY((((new_args).ensure_capacity(((args).size())))));
{
JaktInternal::ArrayIterator<types::TypeId> _magic = ((args).iterator());
for (;;){
JaktInternal::Optional<types::TypeId> _magic_value = ((_magic).next());
if ((!(((_magic_value).has_value())))){
break;
}
types::TypeId arg = (_magic_value.value());
{
TRY((((new_args).push(TRY((((*this).substitute_typevars_in_type(arg,generic_inferences,module_id))))))));
}

}
}

return (TRY((((*this).find_or_add_type_id(TRY((types::Type::template create<typename types::Type::GenericTraitInstance>(id,new_args))),module_id)))));
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 19: {
auto&& __jakt_match_value = __jakt_match_variant.template get<types::Type::GenericInstance>();types::StructId const& id = __jakt_match_value.id;
JaktInternal::DynamicArray<types::TypeId> const& args = __jakt_match_value.args;
{
JaktInternal::DynamicArray<types::TypeId> new_args = (TRY((DynamicArray<types::TypeId>::create_with({}))));
TRY((((new_args).ensure_capacity(((args).size())))));
{
JaktInternal::ArrayIterator<types::TypeId> _magic = ((args).iterator());
for (;;){
JaktInternal::Optional<types::TypeId> _magic_value = ((_magic).next());
if ((!(((_magic_value).has_value())))){
break;
}
types::TypeId arg = (_magic_value.value());
{
TRY((((new_args).push(TRY((((*this).substitute_typevars_in_type(arg,generic_inferences,module_id))))))));
}

}
}

return (TRY((((*this).find_or_add_type_id(TRY((types::Type::template create<typename types::Type::GenericInstance>(id,new_args))),module_id)))));
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 20: {
auto&& __jakt_match_value = __jakt_match_variant.template get<types::Type::GenericEnumInstance>();types::EnumId const& id = __jakt_match_value.id;
JaktInternal::DynamicArray<types::TypeId> const& args = __jakt_match_value.args;
{
JaktInternal::DynamicArray<types::TypeId> new_args = (TRY((DynamicArray<types::TypeId>::create_with({}))));
TRY((((new_args).ensure_capacity(((args).size())))));
{
JaktInternal::ArrayIterator<types::TypeId> _magic = ((args).iterator());
for (;;){
JaktInternal::Optional<types::TypeId> _magic_value = ((_magic).next());
if ((!(((_magic_value).has_value())))){
break;
}
types::TypeId arg = (_magic_value.value());
{
TRY((((new_args).push(TRY((((*this).substitute_typevars_in_type(arg,generic_inferences,module_id))))))));
}

}
}

return (TRY((((*this).find_or_add_type_id(TRY((types::Type::template create<typename types::Type::GenericEnumInstance>(id,new_args))),module_id)))));
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 23: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::Type::Struct>();
types::StructId const& struct_id = __jakt_match_value.value;
{
types::CheckedStruct const struct_ = ((*this).get_struct(struct_id));
if ((!(((((struct_).generic_parameters)).is_empty())))){
JaktInternal::DynamicArray<types::TypeId> new_args = (TRY((DynamicArray<types::TypeId>::create_with({}))));
TRY((((new_args).ensure_capacity(((((struct_).generic_parameters)).size())))));
{
JaktInternal::ArrayIterator<types::CheckedGenericParameter> _magic = ((((struct_).generic_parameters)).iterator());
for (;;){
JaktInternal::Optional<types::CheckedGenericParameter> _magic_value = ((_magic).next());
if ((!(((_magic_value).has_value())))){
break;
}
types::CheckedGenericParameter arg = (_magic_value.value());
{
TRY((((new_args).push(TRY((((*this).substitute_typevars_in_type(((arg).type_id),generic_inferences,module_id))))))));
}

}
}

return (TRY((((*this).find_or_add_type_id(TRY((types::Type::template create<typename types::Type::GenericInstance>(struct_id,new_args))),module_id)))));
}
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 24: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::Type::Enum>();
types::EnumId const& enum_id = __jakt_match_value.value;
{
types::CheckedEnum const enum_ = ((*this).get_enum(enum_id));
if ((!(((((enum_).generic_parameters)).is_empty())))){
JaktInternal::DynamicArray<types::TypeId> new_args = (TRY((DynamicArray<types::TypeId>::create_with({}))));
TRY((((new_args).ensure_capacity(((((enum_).generic_parameters)).size())))));
{
JaktInternal::ArrayIterator<types::CheckedGenericParameter> _magic = ((((enum_).generic_parameters)).iterator());
for (;;){
JaktInternal::Optional<types::CheckedGenericParameter> _magic_value = ((_magic).next());
if ((!(((_magic_value).has_value())))){
break;
}
types::CheckedGenericParameter arg = (_magic_value.value());
{
TRY((((new_args).push(TRY((((*this).substitute_typevars_in_type(((arg).type_id),generic_inferences,module_id))))))));
}

}
}

return (TRY((((*this).find_or_add_type_id(TRY((types::Type::template create<typename types::Type::GenericEnumInstance>(enum_id,new_args))),module_id)))));
}
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 25: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::Type::RawPtr>();
types::TypeId const& rawptr_type_id = __jakt_match_value.value;
{
NonnullRefPtr<typename types::Type> const rawptr_type = TRY((types::Type::template create<typename types::Type::RawPtr>(TRY((((*this).substitute_typevars_in_type(rawptr_type_id,generic_inferences,module_id)))))));
return (TRY((((*this).find_or_add_type_id(rawptr_type,module_id)))));
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 27: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::Type::Reference>();
types::TypeId const& ref_type_id = __jakt_match_value.value;
{
NonnullRefPtr<typename types::Type> const ref_type = TRY((types::Type::template create<typename types::Type::Reference>(TRY((((*this).substitute_typevars_in_type(ref_type_id,generic_inferences,module_id)))))));
return (TRY((((*this).find_or_add_type_id(ref_type,module_id)))));
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 28: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::Type::MutableReference>();
types::TypeId const& ref_type_id = __jakt_match_value.value;
{
NonnullRefPtr<typename types::Type> const ref_type = TRY((types::Type::template create<typename types::Type::MutableReference>(TRY((((*this).substitute_typevars_in_type(ref_type_id,generic_inferences,module_id)))))));
return (TRY((((*this).find_or_add_type_id(ref_type,module_id)))));
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 29: {
auto&& __jakt_match_value = __jakt_match_variant.template get<types::Type::Function>();JaktInternal::DynamicArray<types::TypeId> const& params = __jakt_match_value.params;
bool const& can_throw = __jakt_match_value.can_throw;
types::TypeId const& return_type_id = __jakt_match_value.return_type_id;
types::FunctionId const& pseudo_function_id = __jakt_match_value.pseudo_function_id;
{
JaktInternal::DynamicArray<types::TypeId> new_params = (TRY((DynamicArray<types::TypeId>::create_with({}))));
TRY((((new_params).ensure_capacity(((params).size())))));
bool is_different = false;
{
JaktInternal::ArrayIterator<types::TypeId> _magic = ((params).iterator());
for (;;){
JaktInternal::Optional<types::TypeId> _magic_value = ((_magic).next());
if ((!(((_magic_value).has_value())))){
break;
}
types::TypeId param = (_magic_value.value());
{
types::TypeId const new_param = TRY((((*this).substitute_typevars_in_type(param,generic_inferences,module_id))));
(is_different = (is_different || (!(((new_param).equals(param))))));
TRY((((new_params).push(new_param))));
}

}
}

types::TypeId const return_type_substitute = TRY((((*this).substitute_typevars_in_type(return_type_id,generic_inferences,module_id))));
(is_different = (is_different || (!(((return_type_substitute).equals(return_type_id))))));
if ((!(is_different))){
return (type_id);
}
NonnullRefPtr<types::CheckedFunction> const previous_function = ((*this).get_function(pseudo_function_id));
JaktInternal::DynamicArray<types::CheckedParameter> replacement_params = (TRY((DynamicArray<types::CheckedParameter>::create_with({}))));
{
JaktInternal::Range<size_t> _magic = (JaktInternal::Range<size_t>{static_cast<size_t>(static_cast<size_t>(0ULL)),static_cast<size_t>(((((previous_function)->params)).size()))});
for (;;){
JaktInternal::Optional<size_t> _magic_value = ((_magic).next());
if ((!(((_magic_value).has_value())))){
break;
}
size_t i = (_magic_value.value());
{
types::CheckedParameter const param = ((((previous_function)->params))[i]);
types::CheckedParameter const new_param = types::CheckedParameter(((param).requires_label),TRY((types::CheckedVariable::create(((((param).variable))->name),((new_params)[i]),((((param).variable))->is_mutable),((((param).variable))->definition_span),((((param).variable))->type_span),((((param).variable))->visibility),JaktInternal::OptionalNone()))),((param).default_value));
TRY((((replacement_params).push(new_param))));
}

}
}

NonnullRefPtr<types::CheckedFunction> const new_function = TRY((types::CheckedFunction::create(((previous_function)->name),((previous_function)->name_span),((previous_function)->visibility),return_type_substitute,((previous_function)->return_type_span),replacement_params,((previous_function)->generics),((previous_function)->block),can_throw,((previous_function)->type),((previous_function)->linkage),((previous_function)->function_scope_id),((previous_function)->struct_id),((previous_function)->is_instantiated),((previous_function)->parsed_function),((previous_function)->is_comptime),((previous_function)->is_virtual),((previous_function)->is_override),JaktInternal::OptionalNone(),JaktInternal::OptionalNone(),JaktInternal::OptionalNone())));
types::FunctionId const new_function_id = TRY((((((((*this).modules))[((module_id).id)]))->add_function(new_function))));
return (TRY((((*this).find_or_add_type_id(TRY((types::Type::template create<typename types::Type::Function>(new_params,can_throw,return_type_substitute,new_function_id))),module_id)))));
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
default: {
{
return (type_id);
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
}/*switch end*/
}()
));
return (type_id);
}
}

bool types::CheckedProgram::is_string(types::TypeId const type_id) const {
{
return (((((*this).get_type(type_id)))->index() == 13 /* JaktString */));
}
}

types::ScopeId types::CheckedProgram::prelude_scope_id() const {
{
return (types::ScopeId(types::ModuleId(static_cast<size_t>(0ULL)),static_cast<size_t>(0ULL)));
}
}

types::CheckedProgram::CheckedProgram(NonnullRefPtr<compiler::Compiler>&& a_compiler, JaktInternal::DynamicArray<NonnullRefPtr<types::Module>>&& a_modules, JaktInternal::Dictionary<DeprecatedString,types::LoadedModule>&& a_loaded_modules): compiler(move(a_compiler)), modules(move(a_modules)), loaded_modules(move(a_loaded_modules)){}
ErrorOr<NonnullRefPtr<CheckedProgram>> types::CheckedProgram::create(NonnullRefPtr<compiler::Compiler> compiler, JaktInternal::DynamicArray<NonnullRefPtr<types::Module>> modules, JaktInternal::Dictionary<DeprecatedString,types::LoadedModule> loaded_modules) { auto o = TRY(adopt_nonnull_ref_or_enomem(new (nothrow) CheckedProgram (move(compiler), move(modules), move(loaded_modules)))); return o; }
NonnullRefPtr<types::CheckedFunction> types::CheckedProgram::get_function(types::FunctionId const id) const {
{
return (((((((((*this).modules))[((((id).module)).id)]))->functions))[((id).id)]));
}
}

ErrorOr<JaktInternal::Optional<types::Value>> types::CheckedProgram::find_comptime_binding_in_scope(types::ScopeId const scope_id,DeprecatedString const name) const {
{
return (TRY((((*this).template for_each_scope_accessible_unqualified_from_scope<types::Value>(scope_id,(([name, this](types::ScopeId scope_id, JaktInternal::Optional<DeprecatedString> name_override, bool is_alias) -> ErrorOr<typename utility::IterationDecision<types::Value>> {
{
NonnullRefPtr<types::Scope> const scope = TRY((((*this).get_scope(scope_id))));
JaktInternal::Optional<types::Value> const maybe_binding = ((((scope)->comptime_bindings)).get(name));
if (((maybe_binding).has_value())){
return ( typename utility::IterationDecision<types::Value> { typename utility::IterationDecision<types::Value>::Break((maybe_binding.value())) } );
}
return ( typename utility::IterationDecision<types::Value> { typename utility::IterationDecision<types::Value>::Continue() } );
}
}
)))))));
}
}

i64 types::CheckedProgram::get_bits(types::TypeId const type_id) const {
{
return (((((*this).get_type(type_id)))->get_bits()));
}
}

NonnullRefPtr<typename types::Type> types::CheckedProgram::get_type(types::TypeId const id) const {
{
return (((((((((*this).modules))[((((id).module)).id)]))->types))[((id).id)]));
}
}

ErrorOr<types::TypeId> types::CheckedProgram::find_or_add_type_id(NonnullRefPtr<typename types::Type> const type,types::ModuleId const module_id) {
{
{
JaktInternal::ArrayIterator<NonnullRefPtr<types::Module>> _magic = ((((*this).modules)).iterator());
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

TRY((((((((((*this).modules))[((module_id).id)]))->types)).push(type))));
return (types::TypeId(module_id,(JaktInternal::checked_sub<size_t>(((((((((*this).modules))[((module_id).id)]))->types)).size()),static_cast<size_t>(1ULL)))));
}
}

ErrorOr<types::StructId> types::CheckedProgram::find_struct_in_prelude(DeprecatedString const name) const {
{
types::ScopeId const scope_id = ((*this).prelude_scope_id());
JaktInternal::Optional<types::StructId> const struct_id = TRY((((*this).find_struct_in_scope(scope_id,name))));
if (((struct_id).has_value())){
return (((struct_id).value()));
}
TRY((((((*this).compiler))->panic(TRY((__jakt_format(Jakt::DeprecatedString("internal error: {} builtin definition not found"sv),name)))))));
}
}

ErrorOr<JaktInternal::Optional<JaktInternal::Tuple<types::ScopeId,bool>>> types::CheckedProgram::find_namespace_in_scope(types::ScopeId const scope_id,DeprecatedString const name,bool const treat_aliases_as_imports) const {
{
return (TRY((((*this).template for_each_scope_accessible_unqualified_from_scope<JaktInternal::Tuple<types::ScopeId,bool>>(scope_id,(([name, treat_aliases_as_imports, this](types::ScopeId scope_id, JaktInternal::Optional<DeprecatedString> name_override, bool is_alias) -> ErrorOr<typename utility::IterationDecision<JaktInternal::Tuple<types::ScopeId,bool>>> {
{
NonnullRefPtr<types::Scope> const scope = TRY((((*this).get_scope(scope_id))));
JaktInternal::Optional<DeprecatedString> const effective_name = name_override.value_or_lazy_evaluated_optional([&] { return ((scope)->namespace_name); });
bool const is_import = (((name_override).has_value()) && (!(is_alias)));
if ((((effective_name).has_value()) && ((effective_name.value()) == name))){
return ( typename utility::IterationDecision<JaktInternal::Tuple<types::ScopeId,bool>> { typename utility::IterationDecision<JaktInternal::Tuple<types::ScopeId,bool>>::Break((Tuple{scope_id, (is_import || (is_alias && treat_aliases_as_imports))})) } );
}
return ( typename utility::IterationDecision<JaktInternal::Tuple<types::ScopeId,bool>> { typename utility::IterationDecision<JaktInternal::Tuple<types::ScopeId,bool>>::Continue() } );
}
}
)))))));
}
}

types::CheckedEnum types::CheckedProgram::get_enum(types::EnumId const id) const {
{
return (((((((((*this).modules))[((((id).module)).id)]))->enums))[((id).id)]));
}
}

ErrorOr<JaktInternal::Optional<types::TraitId>> types::CheckedProgram::find_trait_in_scope(types::ScopeId const scope_id,DeprecatedString const name) const {
{
return (TRY((((*this).template for_each_scope_accessible_unqualified_from_scope<types::TraitId>(scope_id,(([name, this](types::ScopeId scope_id, JaktInternal::Optional<DeprecatedString> name_override, bool is_alias) -> ErrorOr<typename utility::IterationDecision<types::TraitId>> {
{
NonnullRefPtr<types::Scope> const scope = TRY((((*this).get_scope(scope_id))));
JaktInternal::Optional<types::TraitId> const maybe_trait = ((((scope)->traits)).get(name));
if (((maybe_trait).has_value())){
return ( typename utility::IterationDecision<types::TraitId> { typename utility::IterationDecision<types::TraitId>::Break((maybe_trait.value())) } );
}
return ( typename utility::IterationDecision<types::TraitId> { typename utility::IterationDecision<types::TraitId>::Continue() } );
}
}
)))))));
}
}

NonnullRefPtr<types::CheckedTrait> types::CheckedProgram::get_trait(types::TraitId const id) const {
{
return (((((((((*this).modules))[((((id).module)).id)]))->traits))[((id).id)]));
}
}

ErrorOr<DeprecatedString> types::CheckedProgram::type_name(types::TypeId const type_id,bool const debug_mode) const {
{
NonnullRefPtr<typename types::Type> const type = ((*this).get_type(type_id));
return ((JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<DeprecatedString,ErrorOr<DeprecatedString>>{
auto __jakt_enum_value = (debug_mode);
if (__jakt_enum_value == true) {
return JaktInternal::ExplicitValue(TRY((__jakt_format(Jakt::DeprecatedString("({}@{}) "sv),((type_id).id),((((type_id).module)).id)))));
}
else {
return JaktInternal::ExplicitValue(Jakt::DeprecatedString(""sv));
}
}()))
 + JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<DeprecatedString, ErrorOr<DeprecatedString>>{
auto&& __jakt_match_variant = *type;
switch(__jakt_match_variant.index()) {
case 17: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::Type::Never>();
return JaktInternal::ExplicitValue(Jakt::DeprecatedString("never"sv));
};/*case end*/
case 10: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::Type::F32>();
return JaktInternal::ExplicitValue(Jakt::DeprecatedString("f32"sv));
};/*case end*/
case 11: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::Type::F64>();
return JaktInternal::ExplicitValue(Jakt::DeprecatedString("f64"sv));
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
case 12: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::Type::Usize>();
return JaktInternal::ExplicitValue(Jakt::DeprecatedString("usize"sv));
};/*case end*/
case 14: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::Type::CChar>();
return JaktInternal::ExplicitValue(Jakt::DeprecatedString("c_char"sv));
};/*case end*/
case 15: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::Type::CInt>();
return JaktInternal::ExplicitValue(Jakt::DeprecatedString("c_int"sv));
};/*case end*/
case 1: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::Type::Bool>();
return JaktInternal::ExplicitValue(Jakt::DeprecatedString("bool"sv));
};/*case end*/
case 0: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::Type::Void>();
return JaktInternal::ExplicitValue(Jakt::DeprecatedString("void"sv));
};/*case end*/
case 16: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::Type::Unknown>();
return JaktInternal::ExplicitValue(Jakt::DeprecatedString("unknown"sv));
};/*case end*/
case 13: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::Type::JaktString>();
return JaktInternal::ExplicitValue(Jakt::DeprecatedString("String"sv));
};/*case end*/
case 26: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::Type::Trait>();
types::TraitId const& id = __jakt_match_value.value;
return JaktInternal::ExplicitValue(((((*this).get_trait(id)))->name));
};/*case end*/
case 30: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::Type::Self>();
return JaktInternal::ExplicitValue(Jakt::DeprecatedString("Self"sv));
};/*case end*/
case 29: {
auto&& __jakt_match_value = __jakt_match_variant.template get<types::Type::Function>();JaktInternal::DynamicArray<types::TypeId> const& params = __jakt_match_value.params;
types::TypeId const& return_type_id = __jakt_match_value.return_type_id;
return JaktInternal::ExplicitValue(({ Optional<DeprecatedString> __jakt_var_120; {
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
TRY((((param_names).push(TRY((((*this).type_name(x,debug_mode))))))));
}

}
}

DeprecatedString const return_type = TRY((((*this).type_name(return_type_id,debug_mode))));
__jakt_var_120 = TRY((__jakt_format(Jakt::DeprecatedString("function({}) -> {}"sv),utility::join(param_names,Jakt::DeprecatedString(", "sv)),return_type))); goto __jakt_label_117;

}
__jakt_label_117:; __jakt_var_120.release_value(); }));
};/*case end*/
case 24: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::Type::Enum>();
types::EnumId const& id = __jakt_match_value.value;
return JaktInternal::ExplicitValue(((((*this).get_enum(id))).name));
};/*case end*/
case 23: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::Type::Struct>();
types::StructId const& id = __jakt_match_value.value;
return JaktInternal::ExplicitValue(((((*this).get_struct(id))).name));
};/*case end*/
case 20: {
auto&& __jakt_match_value = __jakt_match_variant.template get<types::Type::GenericEnumInstance>();types::EnumId const& id = __jakt_match_value.id;
JaktInternal::DynamicArray<types::TypeId> const& args = __jakt_match_value.args;
return JaktInternal::ExplicitValue(({ Optional<DeprecatedString> __jakt_var_121; {
DeprecatedString output = TRY((__jakt_format(Jakt::DeprecatedString("enum {}"sv),((((*this).get_enum(id))).name))));
(output += Jakt::DeprecatedString("<"sv));
bool first = true;
{
JaktInternal::ArrayIterator<types::TypeId> _magic = ((args).iterator());
for (;;){
JaktInternal::Optional<types::TypeId> _magic_value = ((_magic).next());
if ((!(((_magic_value).has_value())))){
break;
}
types::TypeId arg = (_magic_value.value());
{
if ((!(first))){
(output += Jakt::DeprecatedString(", "sv));
}
else {
(first = false);
}

(output += TRY((((*this).type_name(arg,debug_mode)))));
}

}
}

(output += Jakt::DeprecatedString(">"sv));
__jakt_var_121 = output; goto __jakt_label_118;

}
__jakt_label_118:; __jakt_var_121.release_value(); }));
};/*case end*/
case 21: {
auto&& __jakt_match_value = __jakt_match_variant.template get<types::Type::GenericTraitInstance>();types::TraitId const& id = __jakt_match_value.id;
JaktInternal::DynamicArray<types::TypeId> const& args = __jakt_match_value.args;
return JaktInternal::ExplicitValue(({ Optional<DeprecatedString> __jakt_var_122; {
DeprecatedString output = TRY((__jakt_format(Jakt::DeprecatedString("trait {}"sv),((((*this).get_trait(id)))->name))));
(output += Jakt::DeprecatedString("<"sv));
bool first = true;
{
JaktInternal::ArrayIterator<types::TypeId> _magic = ((args).iterator());
for (;;){
JaktInternal::Optional<types::TypeId> _magic_value = ((_magic).next());
if ((!(((_magic_value).has_value())))){
break;
}
types::TypeId arg = (_magic_value.value());
{
if ((!(first))){
(output += Jakt::DeprecatedString(", "sv));
}
else {
(first = false);
}

(output += TRY((((*this).type_name(arg,debug_mode)))));
}

}
}

(output += Jakt::DeprecatedString(">"sv));
__jakt_var_122 = output; goto __jakt_label_119;

}
__jakt_label_119:; __jakt_var_122.release_value(); }));
};/*case end*/
case 19: {
auto&& __jakt_match_value = __jakt_match_variant.template get<types::Type::GenericInstance>();types::StructId const& id = __jakt_match_value.id;
JaktInternal::DynamicArray<types::TypeId> const& args = __jakt_match_value.args;
return JaktInternal::ExplicitValue(({ Optional<DeprecatedString> __jakt_var_123; {
types::StructId const array_struct_id = TRY((((*this).find_struct_in_prelude(Jakt::DeprecatedString("Array"sv)))));
types::StructId const dictionary_struct_id = TRY((((*this).find_struct_in_prelude(Jakt::DeprecatedString("Dictionary"sv)))));
types::StructId const optional_struct_id = TRY((((*this).find_struct_in_prelude(Jakt::DeprecatedString("Optional"sv)))));
types::StructId const range_struct_id = TRY((((*this).find_struct_in_prelude(Jakt::DeprecatedString("Range"sv)))));
types::StructId const set_struct_id = TRY((((*this).find_struct_in_prelude(Jakt::DeprecatedString("Set"sv)))));
types::StructId const tuple_struct_id = TRY((((*this).find_struct_in_prelude(Jakt::DeprecatedString("Tuple"sv)))));
types::StructId const weak_ptr_struct_id = TRY((((*this).find_struct_in_prelude(Jakt::DeprecatedString("WeakPtr"sv)))));
DeprecatedString output = Jakt::DeprecatedString(""sv);
if (((id).equals(array_struct_id))){
(output = TRY((__jakt_format(Jakt::DeprecatedString("[{}]"sv),TRY((((*this).type_name(((args)[static_cast<i64>(0LL)]),debug_mode))))))));
}
else if (((id).equals(dictionary_struct_id))){
(output = TRY((__jakt_format(Jakt::DeprecatedString("[{}:{}]"sv),TRY((((*this).type_name(((args)[static_cast<i64>(0LL)]),debug_mode)))),TRY((((*this).type_name(((args)[static_cast<i64>(1LL)]),debug_mode))))))));
}
else if (((id).equals(optional_struct_id))){
(output = TRY((__jakt_format(Jakt::DeprecatedString("{}?"sv),TRY((((*this).type_name(((args)[static_cast<i64>(0LL)]),debug_mode))))))));
}
else if (((id).equals(range_struct_id))){
(output = TRY((__jakt_format(Jakt::DeprecatedString("{}..{}"sv),TRY((((*this).type_name(((args)[static_cast<i64>(0LL)]),debug_mode)))),TRY((((*this).type_name(((args)[static_cast<i64>(0LL)]),debug_mode))))))));
}
else if (((id).equals(set_struct_id))){
(output = TRY((__jakt_format(Jakt::DeprecatedString("{{{}}}"sv),TRY((((*this).type_name(((args)[static_cast<i64>(0LL)]),debug_mode))))))));
}
else if (((id).equals(tuple_struct_id))){
(output = Jakt::DeprecatedString("("sv));
bool first = true;
{
JaktInternal::ArrayIterator<types::TypeId> _magic = ((args).iterator());
for (;;){
JaktInternal::Optional<types::TypeId> _magic_value = ((_magic).next());
if ((!(((_magic_value).has_value())))){
break;
}
types::TypeId arg = (_magic_value.value());
{
if ((!(first))){
(output += Jakt::DeprecatedString(", "sv));
}
else {
(first = false);
}

(output += TRY((((*this).type_name(arg,debug_mode)))));
}

}
}

(output += Jakt::DeprecatedString(")"sv));
}
else if (((id).equals(weak_ptr_struct_id))){
(output = TRY((__jakt_format(Jakt::DeprecatedString("weak {}?"sv),TRY((((*this).type_name(((args)[static_cast<i64>(0LL)]),debug_mode))))))));
}
else {
types::CheckedStruct const structure = ((*this).get_struct(id));
(output = ((structure).name));
(output += Jakt::DeprecatedString("<"sv));
bool first = true;
{
JaktInternal::ArrayIterator<types::TypeId> _magic = ((args).iterator());
for (;;){
JaktInternal::Optional<types::TypeId> _magic_value = ((_magic).next());
if ((!(((_magic_value).has_value())))){
break;
}
types::TypeId arg = (_magic_value.value());
{
if ((!(first))){
(output += Jakt::DeprecatedString(", "sv));
}
else {
(first = false);
}

(output += TRY((((*this).type_name(arg,debug_mode)))));
}

}
}

(output += Jakt::DeprecatedString(">"sv));
}

__jakt_var_123 = output; goto __jakt_label_120;

}
__jakt_label_120:; __jakt_var_123.release_value(); }));
};/*case end*/
case 22: {
auto&& __jakt_match_value = __jakt_match_variant.template get<types::Type::GenericResolvedType>();types::StructId const& id = __jakt_match_value.id;
JaktInternal::DynamicArray<types::TypeId> const& args = __jakt_match_value.args;
return JaktInternal::ExplicitValue(({ Optional<DeprecatedString> __jakt_var_124; {
DeprecatedString output = ((((*this).get_struct(id))).name);
bool first = true;
(output += Jakt::DeprecatedString("<"sv));
{
JaktInternal::ArrayIterator<types::TypeId> _magic = ((args).iterator());
for (;;){
JaktInternal::Optional<types::TypeId> _magic_value = ((_magic).next());
if ((!(((_magic_value).has_value())))){
break;
}
types::TypeId arg = (_magic_value.value());
{
if ((!(first))){
(output += Jakt::DeprecatedString(", "sv));
}
else {
(first = false);
}

(output += TRY((((*this).type_name(type_id,debug_mode)))));
}

}
}

(output += Jakt::DeprecatedString(">"sv));
__jakt_var_124 = output; goto __jakt_label_121;

}
__jakt_label_121:; __jakt_var_124.release_value(); }));
};/*case end*/
case 18: {
auto&& __jakt_match_value = __jakt_match_variant.template get<types::Type::TypeVariable>();DeprecatedString const& name = __jakt_match_value.name;
return JaktInternal::ExplicitValue(name);
};/*case end*/
case 25: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::Type::RawPtr>();
types::TypeId const& type_id = __jakt_match_value.value;
return JaktInternal::ExplicitValue(TRY((__jakt_format(Jakt::DeprecatedString("raw {}"sv),TRY((((*this).type_name(type_id,debug_mode))))))));
};/*case end*/
case 27: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::Type::Reference>();
types::TypeId const& type_id = __jakt_match_value.value;
return JaktInternal::ExplicitValue(TRY((__jakt_format(Jakt::DeprecatedString("&{}"sv),TRY((((*this).type_name(type_id,debug_mode))))))));
};/*case end*/
case 28: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::Type::MutableReference>();
types::TypeId const& type_id = __jakt_match_value.value;
return JaktInternal::ExplicitValue(TRY((__jakt_format(Jakt::DeprecatedString("&mut {}"sv),TRY((((*this).type_name(type_id,debug_mode))))))));
};/*case end*/
default: VERIFY_NOT_REACHED();}/*switch end*/
}()
))));
}
}

ErrorOr<JaktInternal::Optional<JaktInternal::DynamicArray<types::FunctionId>>> types::CheckedProgram::find_functions_with_name_in_scope(types::ScopeId const parent_scope_id,DeprecatedString const function_name) const {
{
return (((TRY((((*this).find_scoped_functions_with_name_in_scope(parent_scope_id,function_name))))).map([](auto& _value) { return _value.template get<0>(); })));
}
}

ErrorOr<JaktInternal::Optional<NonnullRefPtr<types::CheckedVariable>>> types::CheckedProgram::find_var_in_scope(types::ScopeId const scope_id,DeprecatedString const var) const {
{
return (TRY((((*this).template for_each_scope_accessible_unqualified_from_scope<NonnullRefPtr<types::CheckedVariable>>(scope_id,(([var, this](types::ScopeId scope_id, JaktInternal::Optional<DeprecatedString> name_override, bool is_alias) -> ErrorOr<typename utility::IterationDecision<NonnullRefPtr<types::CheckedVariable>>> {
{
NonnullRefPtr<types::Scope> const scope = TRY((((*this).get_scope(scope_id))));
JaktInternal::Optional<types::VarId> const maybe_var = ((((scope)->vars)).get(var));
if (((maybe_var).has_value())){
return ( typename utility::IterationDecision<NonnullRefPtr<types::CheckedVariable>> { typename utility::IterationDecision<NonnullRefPtr<types::CheckedVariable>>::Break(((*this).get_variable((maybe_var.value())))) } );
}
return ( typename utility::IterationDecision<NonnullRefPtr<types::CheckedVariable>> { typename utility::IterationDecision<NonnullRefPtr<types::CheckedVariable>>::Continue() } );
}
}
)))))));
}
}

types::CheckedStruct types::CheckedProgram::get_struct(types::StructId const id) const {
{
return (((((((((*this).modules))[((((id).module)).id)]))->structures))[((id).id)]));
}
}

ErrorOr<JaktInternal::Optional<types::StructId>> types::CheckedProgram::check_and_extract_weak_ptr(types::StructId const struct_id,JaktInternal::DynamicArray<types::TypeId> const args) const {
{
types::StructId const weak_ptr_struct_id = TRY((((*this).find_struct_in_prelude(Jakt::DeprecatedString("WeakPtr"sv)))));
if (((struct_id).equals(weak_ptr_struct_id))){
if ((((args).size()) != static_cast<size_t>(1ULL))){
TRY((((((*this).compiler))->panic(TRY((__jakt_format(Jakt::DeprecatedString("Internal error: Generic type is WeakPtr but there are not exactly 1 type parameter. There are {} parameters."sv),((args).size()))))))));
}
types::TypeId const inner_type_id = ((args)[static_cast<i64>(0LL)]);
NonnullRefPtr<typename types::Type> const inner_type = ((*this).get_type(inner_type_id));
if (((inner_type)->index() == 23 /* Struct */)){
types::StructId const inner_struct_id = ((inner_type)->get<types::Type::Struct>()).value;
return (inner_struct_id);
}
utility::panic(TRY((__jakt_format(Jakt::DeprecatedString("Internal error: Inner type of WeakPtr is not a struct. It is {}."sv),inner_type))));
}
else {
return (JaktInternal::OptionalNone());
}

}
}

ErrorOr<JaktInternal::Optional<types::EnumId>> types::CheckedProgram::find_enum_in_scope(types::ScopeId const scope_id,DeprecatedString const name) const {
{
return (TRY((((*this).template for_each_scope_accessible_unqualified_from_scope<types::EnumId>(scope_id,(([name, this](types::ScopeId scope_id, JaktInternal::Optional<DeprecatedString> name_override, bool is_alias) -> ErrorOr<typename utility::IterationDecision<types::EnumId>> {
{
NonnullRefPtr<types::Scope> const scope = TRY((((*this).get_scope(scope_id))));
JaktInternal::Optional<types::EnumId> const maybe_enum = ((((scope)->enums)).get(name));
if (((maybe_enum).has_value())){
return ( typename utility::IterationDecision<types::EnumId> { typename utility::IterationDecision<types::EnumId>::Break((maybe_enum.value())) } );
}
return ( typename utility::IterationDecision<types::EnumId> { typename utility::IterationDecision<types::EnumId>::Continue() } );
}
}
)))))));
}
}

JaktInternal::Optional<types::LoadedModule> types::CheckedProgram::get_loaded_module(DeprecatedString const module_name) const {
{
return (((((*this).loaded_modules)).get(module_name)));
}
}

bool types::CheckedProgram::is_numeric(types::TypeId const type_id) const {
{
return ((((*this).is_integer(type_id)) || ((*this).is_floating(type_id))));
}
}

NonnullRefPtr<types::CheckedVariable> types::CheckedProgram::get_variable(types::VarId const id) const {
{
return (((((((((*this).modules))[((((id).module)).id)]))->variables))[((id).id)]));
}
}

ErrorOr<types::TypeId> types::CheckedProgram::substitute_typevars_in_type(types::TypeId const type_id,types::GenericInferences const generic_inferences,types::ModuleId const module_id) {
{
types::TypeId result = TRY((((*this).substitute_typevars_in_type_helper(type_id,generic_inferences,module_id))));
for (;;){
types::TypeId const fixed_point = TRY((((*this).substitute_typevars_in_type_helper(type_id,generic_inferences,module_id))));
if (((fixed_point).equals(result))){
break;
}
else {
(result = fixed_point);
}

}
return (result);
}
}

ErrorOr<NonnullRefPtr<types::Scope>> types::CheckedProgram::get_scope(types::ScopeId const id) const {
{
size_t const max_scope = (JaktInternal::checked_sub<size_t>(((((((((*this).modules))[((((id).module_id)).id)]))->scopes)).size()),static_cast<size_t>(1ULL)));
if ((((id).id) > max_scope)){
TRY((((((*this).compiler))->panic(TRY((__jakt_format(Jakt::DeprecatedString("scope_id {} does not exist in module"sv),id)))))));
}
return (((((((((*this).modules))[((((id).module_id)).id)]))->scopes))[((id).id)]));
}
}

ErrorOr<DeprecatedString> types::Value::debug_description() const { auto builder = MUST(DeprecatedStringBuilder::create());TRY(builder.append("Value("sv));{
JaktInternal::PrettyPrint::ScopedLevelIncrease increase_indent {};
TRY(JaktInternal::PrettyPrint::output_indentation(builder));TRY(builder.append("impl: "sv));TRY(builder.appendff("{}, ", impl));
TRY(JaktInternal::PrettyPrint::output_indentation(builder));TRY(builder.append("span: "sv));TRY(builder.appendff("{}", span));
}
TRY(builder.append(")"sv));return builder.to_string(); }
ErrorOr<types::Value> types::Value::copy() const {
{
return (types::Value(TRY((((((*this).impl))->copy()))),((*this).span)));
}
}

types::Value::Value(NonnullRefPtr<typename types::ValueImpl> a_impl, utility::Span a_span) :impl(a_impl), span(a_span){}

ErrorOr<types::Value> types::Value::cast(types::Value const expected,utility::Span const span) const {
{
return (JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<types::Value, ErrorOr<types::Value>>{
auto&& __jakt_match_variant = *((*this).impl);
switch(__jakt_match_variant.index()) {
case 2: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::U8>();
u8 const& value = __jakt_match_value.value;
return JaktInternal::ExplicitValue(JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<types::Value, ErrorOr<types::Value>>{
auto&& __jakt_match_variant = *((expected).impl);
switch(__jakt_match_variant.index()) {
case 3: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::U16>();
return JaktInternal::ExplicitValue(types::Value(TRY((types::ValueImpl::template create<typename types::ValueImpl::U16>((infallible_integer_cast<u16>((value)))))),span));
};/*case end*/
case 4: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::U32>();
return JaktInternal::ExplicitValue(types::Value(TRY((types::ValueImpl::template create<typename types::ValueImpl::U32>((infallible_integer_cast<u32>((value)))))),span));
};/*case end*/
case 5: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::U64>();
return JaktInternal::ExplicitValue(types::Value(TRY((types::ValueImpl::template create<typename types::ValueImpl::U64>((infallible_integer_cast<u64>((value)))))),span));
};/*case end*/
case 12: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::USize>();
return JaktInternal::ExplicitValue(types::Value(TRY((types::ValueImpl::template create<typename types::ValueImpl::USize>((infallible_integer_cast<size_t>((value)))))),span));
};/*case end*/
default: {
return JaktInternal::ExplicitValue(*this);
};/*case end*/
}/*switch end*/
}()
)));
};/*case end*/
case 3: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::U16>();
u16 const& value = __jakt_match_value.value;
return JaktInternal::ExplicitValue(JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<types::Value, ErrorOr<types::Value>>{
auto&& __jakt_match_variant = *((expected).impl);
switch(__jakt_match_variant.index()) {
case 4: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::U32>();
return JaktInternal::ExplicitValue(types::Value(TRY((types::ValueImpl::template create<typename types::ValueImpl::U32>((infallible_integer_cast<u32>((value)))))),span));
};/*case end*/
case 5: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::U64>();
return JaktInternal::ExplicitValue(types::Value(TRY((types::ValueImpl::template create<typename types::ValueImpl::U64>((infallible_integer_cast<u64>((value)))))),span));
};/*case end*/
case 12: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::USize>();
return JaktInternal::ExplicitValue(types::Value(TRY((types::ValueImpl::template create<typename types::ValueImpl::USize>((infallible_integer_cast<size_t>((value)))))),span));
};/*case end*/
default: {
return JaktInternal::ExplicitValue(*this);
};/*case end*/
}/*switch end*/
}()
)));
};/*case end*/
case 4: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::U32>();
u32 const& value = __jakt_match_value.value;
return JaktInternal::ExplicitValue(JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<types::Value, ErrorOr<types::Value>>{
auto&& __jakt_match_variant = *((expected).impl);
switch(__jakt_match_variant.index()) {
case 5: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::U64>();
return JaktInternal::ExplicitValue(types::Value(TRY((types::ValueImpl::template create<typename types::ValueImpl::U64>((infallible_integer_cast<u64>((value)))))),span));
};/*case end*/
case 12: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::USize>();
return JaktInternal::ExplicitValue(types::Value(TRY((types::ValueImpl::template create<typename types::ValueImpl::USize>((infallible_integer_cast<size_t>((value)))))),span));
};/*case end*/
default: {
return JaktInternal::ExplicitValue(*this);
};/*case end*/
}/*switch end*/
}()
)));
};/*case end*/
case 5: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::U64>();
u64 const& value = __jakt_match_value.value;
return JaktInternal::ExplicitValue(JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<types::Value, ErrorOr<types::Value>>{
auto&& __jakt_match_variant = *((expected).impl);
switch(__jakt_match_variant.index()) {
case 12: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::USize>();
return JaktInternal::ExplicitValue(types::Value(TRY((types::ValueImpl::template create<typename types::ValueImpl::USize>((infallible_integer_cast<size_t>((value)))))),span));
};/*case end*/
default: {
return JaktInternal::ExplicitValue(*this);
};/*case end*/
}/*switch end*/
}()
)));
};/*case end*/
case 6: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::I8>();
i8 const& value = __jakt_match_value.value;
return JaktInternal::ExplicitValue(JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<types::Value, ErrorOr<types::Value>>{
auto&& __jakt_match_variant = *((expected).impl);
switch(__jakt_match_variant.index()) {
case 7: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::I16>();
return JaktInternal::ExplicitValue(types::Value(TRY((types::ValueImpl::template create<typename types::ValueImpl::I16>((infallible_integer_cast<i16>((value)))))),span));
};/*case end*/
case 8: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::I32>();
return JaktInternal::ExplicitValue(types::Value(TRY((types::ValueImpl::template create<typename types::ValueImpl::I32>((infallible_integer_cast<i32>((value)))))),span));
};/*case end*/
case 9: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::I64>();
return JaktInternal::ExplicitValue(types::Value(TRY((types::ValueImpl::template create<typename types::ValueImpl::I64>((infallible_integer_cast<i64>((value)))))),span));
};/*case end*/
default: {
return JaktInternal::ExplicitValue(*this);
};/*case end*/
}/*switch end*/
}()
)));
};/*case end*/
case 7: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::I16>();
i16 const& value = __jakt_match_value.value;
return JaktInternal::ExplicitValue(JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<types::Value, ErrorOr<types::Value>>{
auto&& __jakt_match_variant = *((expected).impl);
switch(__jakt_match_variant.index()) {
case 8: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::I32>();
return JaktInternal::ExplicitValue(types::Value(TRY((types::ValueImpl::template create<typename types::ValueImpl::I32>((infallible_integer_cast<i32>((value)))))),span));
};/*case end*/
case 9: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::I64>();
return JaktInternal::ExplicitValue(types::Value(TRY((types::ValueImpl::template create<typename types::ValueImpl::I64>((infallible_integer_cast<i64>((value)))))),span));
};/*case end*/
default: {
return JaktInternal::ExplicitValue(*this);
};/*case end*/
}/*switch end*/
}()
)));
};/*case end*/
case 8: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::I32>();
i32 const& value = __jakt_match_value.value;
return JaktInternal::ExplicitValue(JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<types::Value, ErrorOr<types::Value>>{
auto&& __jakt_match_variant = *((expected).impl);
switch(__jakt_match_variant.index()) {
case 9: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::I64>();
return JaktInternal::ExplicitValue(types::Value(TRY((types::ValueImpl::template create<typename types::ValueImpl::I64>((infallible_integer_cast<i64>((value)))))),span));
};/*case end*/
default: {
return JaktInternal::ExplicitValue(*this);
};/*case end*/
}/*switch end*/
}()
)));
};/*case end*/
case 9: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::I64>();
i64 const& value = __jakt_match_value.value;
return JaktInternal::ExplicitValue(JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<types::Value, ErrorOr<types::Value>>{
auto&& __jakt_match_variant = *((expected).impl);
switch(__jakt_match_variant.index()) {
case 12: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::USize>();
return JaktInternal::ExplicitValue(types::Value(TRY((types::ValueImpl::template create<typename types::ValueImpl::USize>((infallible_integer_cast<size_t>((value)))))),span));
};/*case end*/
default: {
return JaktInternal::ExplicitValue(*this);
};/*case end*/
}/*switch end*/
}()
)));
};/*case end*/
case 12: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::USize>();
size_t const& value = __jakt_match_value.value;
return JaktInternal::ExplicitValue(JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<types::Value, ErrorOr<types::Value>>{
auto&& __jakt_match_variant = *((expected).impl);
switch(__jakt_match_variant.index()) {
case 5: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::U64>();
return JaktInternal::ExplicitValue(types::Value(TRY((types::ValueImpl::template create<typename types::ValueImpl::U64>((infallible_integer_cast<u64>((value)))))),span));
};/*case end*/
case 16: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::CInt>();
return JaktInternal::ExplicitValue(types::Value(TRY((types::ValueImpl::template create<typename types::ValueImpl::CInt>((infallible_integer_cast<int>((value)))))),span));
};/*case end*/
default: {
return JaktInternal::ExplicitValue(*this);
};/*case end*/
}/*switch end*/
}()
)));
};/*case end*/
case 24: {
auto&& __jakt_match_value = __jakt_match_variant.template get<types::ValueImpl::OptionalSome>();return JaktInternal::ExplicitValue(*this);
};/*case end*/
default: {
return JaktInternal::ExplicitValue(JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<types::Value, ErrorOr<types::Value>>{
auto&& __jakt_match_variant = *((expected).impl);
switch(__jakt_match_variant.index()) {
case 24: {
auto&& __jakt_match_value = __jakt_match_variant.template get<types::ValueImpl::OptionalSome>();return JaktInternal::ExplicitValue(types::Value(TRY((types::ValueImpl::template create<typename types::ValueImpl::OptionalSome>(*this))),span));
};/*case end*/
case 25: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::OptionalNone>();
return JaktInternal::ExplicitValue(types::Value(TRY((types::ValueImpl::template create<typename types::ValueImpl::OptionalSome>(*this))),span));
};/*case end*/
default: {
return JaktInternal::ExplicitValue(*this);
};/*case end*/
}/*switch end*/
}()
)));
};/*case end*/
}/*switch end*/
}()
)));
}
}

DeprecatedString types::Value::type_name() const {
{
return (JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<DeprecatedString, DeprecatedString>{
auto&& __jakt_match_variant = *((*this).impl);
switch(__jakt_match_variant.index()) {
case 0: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::Void>();
return JaktInternal::ExplicitValue(Jakt::DeprecatedString("void"sv));
};/*case end*/
case 1: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::Bool>();
return JaktInternal::ExplicitValue(Jakt::DeprecatedString("bool"sv));
};/*case end*/
case 2: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::U8>();
return JaktInternal::ExplicitValue(Jakt::DeprecatedString("u8"sv));
};/*case end*/
case 3: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::U16>();
return JaktInternal::ExplicitValue(Jakt::DeprecatedString("u16"sv));
};/*case end*/
case 4: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::U32>();
return JaktInternal::ExplicitValue(Jakt::DeprecatedString("u32"sv));
};/*case end*/
case 5: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::U64>();
return JaktInternal::ExplicitValue(Jakt::DeprecatedString("u64"sv));
};/*case end*/
case 6: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::I8>();
return JaktInternal::ExplicitValue(Jakt::DeprecatedString("i18"sv));
};/*case end*/
case 7: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::I16>();
return JaktInternal::ExplicitValue(Jakt::DeprecatedString("i16"sv));
};/*case end*/
case 8: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::I32>();
return JaktInternal::ExplicitValue(Jakt::DeprecatedString("i32"sv));
};/*case end*/
case 9: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::I64>();
return JaktInternal::ExplicitValue(Jakt::DeprecatedString("i64"sv));
};/*case end*/
case 10: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::F32>();
return JaktInternal::ExplicitValue(Jakt::DeprecatedString("f32"sv));
};/*case end*/
case 11: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::F64>();
return JaktInternal::ExplicitValue(Jakt::DeprecatedString("f64"sv));
};/*case end*/
case 12: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::USize>();
return JaktInternal::ExplicitValue(Jakt::DeprecatedString("usize"sv));
};/*case end*/
case 13: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::JaktString>();
return JaktInternal::ExplicitValue(Jakt::DeprecatedString("String"sv));
};/*case end*/
case 14: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::StringView>();
return JaktInternal::ExplicitValue(Jakt::DeprecatedString("StringView"sv));
};/*case end*/
case 15: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::CChar>();
return JaktInternal::ExplicitValue(Jakt::DeprecatedString("c_char"sv));
};/*case end*/
case 16: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::CInt>();
return JaktInternal::ExplicitValue(Jakt::DeprecatedString("c_int"sv));
};/*case end*/
case 17: {
auto&& __jakt_match_value = __jakt_match_variant.template get<types::ValueImpl::Struct>();return JaktInternal::ExplicitValue(Jakt::DeprecatedString("struct <T>"sv));
};/*case end*/
case 18: {
auto&& __jakt_match_value = __jakt_match_variant.template get<types::ValueImpl::Class>();return JaktInternal::ExplicitValue(Jakt::DeprecatedString("class <T>"sv));
};/*case end*/
case 19: {
auto&& __jakt_match_value = __jakt_match_variant.template get<types::ValueImpl::Enum>();return JaktInternal::ExplicitValue(Jakt::DeprecatedString("enum <T>"sv));
};/*case end*/
case 20: {
auto&& __jakt_match_value = __jakt_match_variant.template get<types::ValueImpl::JaktArray>();return JaktInternal::ExplicitValue(Jakt::DeprecatedString("Array"sv));
};/*case end*/
case 21: {
auto&& __jakt_match_value = __jakt_match_variant.template get<types::ValueImpl::JaktDictionary>();return JaktInternal::ExplicitValue(Jakt::DeprecatedString("Dictionary"sv));
};/*case end*/
case 22: {
auto&& __jakt_match_value = __jakt_match_variant.template get<types::ValueImpl::JaktSet>();return JaktInternal::ExplicitValue(Jakt::DeprecatedString("Set"sv));
};/*case end*/
case 23: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::RawPtr>();
return JaktInternal::ExplicitValue(Jakt::DeprecatedString("raw <T>"sv));
};/*case end*/
case 24: {
auto&& __jakt_match_value = __jakt_match_variant.template get<types::ValueImpl::OptionalSome>();return JaktInternal::ExplicitValue(Jakt::DeprecatedString("Some"sv));
};/*case end*/
case 25: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::OptionalNone>();
return JaktInternal::ExplicitValue(Jakt::DeprecatedString("None"sv));
};/*case end*/
case 26: {
auto&& __jakt_match_value = __jakt_match_variant.template get<types::ValueImpl::JaktTuple>();return JaktInternal::ExplicitValue(Jakt::DeprecatedString("Tuple"sv));
};/*case end*/
case 27: {
auto&& __jakt_match_value = __jakt_match_variant.template get<types::ValueImpl::Function>();return JaktInternal::ExplicitValue(Jakt::DeprecatedString("Function"sv));
};/*case end*/
default: VERIFY_NOT_REACHED();}/*switch end*/
}()
)));
}
}

ErrorOr<DeprecatedString> types::VarId::debug_description() const { auto builder = MUST(DeprecatedStringBuilder::create());TRY(builder.append("VarId("sv));{
JaktInternal::PrettyPrint::ScopedLevelIncrease increase_indent {};
TRY(JaktInternal::PrettyPrint::output_indentation(builder));TRY(builder.append("module: "sv));TRY(builder.appendff("{}, ", module));
TRY(JaktInternal::PrettyPrint::output_indentation(builder));TRY(builder.append("id: "sv));TRY(builder.appendff("{}", id));
}
TRY(builder.append(")"sv));return builder.to_string(); }
types::VarId::VarId(types::ModuleId a_module, size_t a_id) :module(a_module), id(a_id){}

ErrorOr<DeprecatedString> types::CheckedParameter::debug_description() const { auto builder = MUST(DeprecatedStringBuilder::create());TRY(builder.append("CheckedParameter("sv));{
JaktInternal::PrettyPrint::ScopedLevelIncrease increase_indent {};
TRY(JaktInternal::PrettyPrint::output_indentation(builder));TRY(builder.append("requires_label: "sv));TRY(builder.appendff("{}, ", requires_label));
TRY(JaktInternal::PrettyPrint::output_indentation(builder));TRY(builder.append("variable: "sv));TRY(builder.appendff("{}, ", *variable));
TRY(JaktInternal::PrettyPrint::output_indentation(builder));TRY(builder.append("default_value: "sv));TRY(builder.appendff("{}", default_value));
}
TRY(builder.append(")"sv));return builder.to_string(); }
ErrorOr<types::CheckedParameter> types::CheckedParameter::map_types(Function<ErrorOr<types::TypeId>(types::TypeId)> const& map) const {
{
return (types::CheckedParameter(((*this).requires_label),TRY((((((*this).variable))->map_types(map)))),((*this).default_value)));
}
}

types::CheckedParameter::CheckedParameter(bool a_requires_label, NonnullRefPtr<types::CheckedVariable> a_variable, JaktInternal::Optional<NonnullRefPtr<typename types::CheckedExpression>> a_default_value) :requires_label(a_requires_label), variable(a_variable), default_value(a_default_value){}

ErrorOr<DeprecatedString> types::CheckedCall::debug_description() const { auto builder = MUST(DeprecatedStringBuilder::create());TRY(builder.append("CheckedCall("sv));{
JaktInternal::PrettyPrint::ScopedLevelIncrease increase_indent {};
TRY(JaktInternal::PrettyPrint::output_indentation(builder));TRY(builder.append("namespace_: "sv));TRY(builder.appendff("{}, ", namespace_));
TRY(JaktInternal::PrettyPrint::output_indentation(builder));TRY(builder.append("name: "sv));TRY(builder.appendff("\"{}\", ", name));
TRY(JaktInternal::PrettyPrint::output_indentation(builder));TRY(builder.append("args: "sv));TRY(builder.appendff("{}, ", args));
TRY(JaktInternal::PrettyPrint::output_indentation(builder));TRY(builder.append("type_args: "sv));TRY(builder.appendff("{}, ", type_args));
TRY(JaktInternal::PrettyPrint::output_indentation(builder));TRY(builder.append("function_id: "sv));TRY(builder.appendff("{}, ", function_id));
TRY(JaktInternal::PrettyPrint::output_indentation(builder));TRY(builder.append("return_type: "sv));TRY(builder.appendff("{}, ", return_type));
TRY(JaktInternal::PrettyPrint::output_indentation(builder));TRY(builder.append("callee_throws: "sv));TRY(builder.appendff("{}, ", callee_throws));
TRY(JaktInternal::PrettyPrint::output_indentation(builder));TRY(builder.append("external_name: "sv));TRY(builder.appendff("{}", external_name));
}
TRY(builder.append(")"sv));return builder.to_string(); }
types::CheckedCall::CheckedCall(JaktInternal::DynamicArray<types::ResolvedNamespace> a_namespace_, DeprecatedString a_name, JaktInternal::DynamicArray<JaktInternal::Tuple<DeprecatedString,NonnullRefPtr<typename types::CheckedExpression>>> a_args, JaktInternal::DynamicArray<types::TypeId> a_type_args, JaktInternal::Optional<types::FunctionId> a_function_id, types::TypeId a_return_type, bool a_callee_throws, JaktInternal::Optional<DeprecatedString> a_external_name) :namespace_(a_namespace_), name(a_name), args(a_args), type_args(a_type_args), function_id(a_function_id), return_type(a_return_type), callee_throws(a_callee_throws), external_name(a_external_name){}

DeprecatedString types::CheckedCall::name_for_codegen() const {
{
return (((*this).external_name).value_or_lazy_evaluated([&] { return ((*this).name); }));
}
}

ErrorOr<DeprecatedString> types::CheckedVarDecl::debug_description() const { auto builder = MUST(DeprecatedStringBuilder::create());TRY(builder.append("CheckedVarDecl("sv));{
JaktInternal::PrettyPrint::ScopedLevelIncrease increase_indent {};
TRY(JaktInternal::PrettyPrint::output_indentation(builder));TRY(builder.append("name: "sv));TRY(builder.appendff("\"{}\", ", name));
TRY(JaktInternal::PrettyPrint::output_indentation(builder));TRY(builder.append("is_mutable: "sv));TRY(builder.appendff("{}, ", is_mutable));
TRY(JaktInternal::PrettyPrint::output_indentation(builder));TRY(builder.append("span: "sv));TRY(builder.appendff("{}, ", span));
TRY(JaktInternal::PrettyPrint::output_indentation(builder));TRY(builder.append("type_id: "sv));TRY(builder.appendff("{}", type_id));
}
TRY(builder.append(")"sv));return builder.to_string(); }
types::CheckedVarDecl::CheckedVarDecl(DeprecatedString a_name, bool a_is_mutable, utility::Span a_span, types::TypeId a_type_id) :name(a_name), is_mutable(a_is_mutable), span(a_span), type_id(a_type_id){}

ErrorOr<DeprecatedString> types::CheckedNamespace::debug_description() const { auto builder = MUST(DeprecatedStringBuilder::create());TRY(builder.append("CheckedNamespace("sv));{
JaktInternal::PrettyPrint::ScopedLevelIncrease increase_indent {};
TRY(JaktInternal::PrettyPrint::output_indentation(builder));TRY(builder.append("name: "sv));TRY(builder.appendff("\"{}\", ", name));
TRY(JaktInternal::PrettyPrint::output_indentation(builder));TRY(builder.append("scope: "sv));TRY(builder.appendff("{}", scope));
}
TRY(builder.append(")"sv));return builder.to_string(); }
types::CheckedNamespace::CheckedNamespace(DeprecatedString a_name, types::ScopeId a_scope) :name(a_name), scope(a_scope){}

ErrorOr<DeprecatedString> types::CheckedGenericParameter::debug_description() const { auto builder = MUST(DeprecatedStringBuilder::create());TRY(builder.append("CheckedGenericParameter("sv));{
JaktInternal::PrettyPrint::ScopedLevelIncrease increase_indent {};
TRY(JaktInternal::PrettyPrint::output_indentation(builder));TRY(builder.append("type_id: "sv));TRY(builder.appendff("{}, ", type_id));
TRY(JaktInternal::PrettyPrint::output_indentation(builder));TRY(builder.append("constraints: "sv));TRY(builder.appendff("{}, ", constraints));
TRY(JaktInternal::PrettyPrint::output_indentation(builder));TRY(builder.append("span: "sv));TRY(builder.appendff("{}", span));
}
TRY(builder.append(")"sv));return builder.to_string(); }
types::CheckedGenericParameter::CheckedGenericParameter(types::TypeId a_type_id, JaktInternal::DynamicArray<types::TraitId> a_constraints, utility::Span a_span) :type_id(a_type_id), constraints(a_constraints), span(a_span){}

ErrorOr<types::CheckedGenericParameter> types::CheckedGenericParameter::make(types::TypeId const type_id,utility::Span const span) {
{
return (types::CheckedGenericParameter(type_id,(TRY((DynamicArray<types::TraitId>::create_with({})))),span));
}
}

ErrorOr<DeprecatedString> types::CheckedBlock::debug_description() const { auto builder = MUST(DeprecatedStringBuilder::create());TRY(builder.append("CheckedBlock("sv));{
JaktInternal::PrettyPrint::ScopedLevelIncrease increase_indent {};
TRY(JaktInternal::PrettyPrint::output_indentation(builder));TRY(builder.append("statements: "sv));TRY(builder.appendff("{}, ", statements));
TRY(JaktInternal::PrettyPrint::output_indentation(builder));TRY(builder.append("scope_id: "sv));TRY(builder.appendff("{}, ", scope_id));
TRY(JaktInternal::PrettyPrint::output_indentation(builder));TRY(builder.append("control_flow: "sv));TRY(builder.appendff("{}, ", control_flow));
TRY(JaktInternal::PrettyPrint::output_indentation(builder));TRY(builder.append("yielded_type: "sv));TRY(builder.appendff("{}, ", yielded_type));
TRY(JaktInternal::PrettyPrint::output_indentation(builder));TRY(builder.append("yielded_none: "sv));TRY(builder.appendff("{}", yielded_none));
}
TRY(builder.append(")"sv));return builder.to_string(); }
types::CheckedBlock::CheckedBlock(JaktInternal::DynamicArray<NonnullRefPtr<typename types::CheckedStatement>> a_statements, types::ScopeId a_scope_id, types::BlockControlFlow a_control_flow, JaktInternal::Optional<types::TypeId> a_yielded_type, bool a_yielded_none) :statements(a_statements), scope_id(a_scope_id), control_flow(a_control_flow), yielded_type(a_yielded_type), yielded_none(a_yielded_none){}

ErrorOr<DeprecatedString> types::TraitId::debug_description() const { auto builder = MUST(DeprecatedStringBuilder::create());TRY(builder.append("TraitId("sv));{
JaktInternal::PrettyPrint::ScopedLevelIncrease increase_indent {};
TRY(JaktInternal::PrettyPrint::output_indentation(builder));TRY(builder.append("module: "sv));TRY(builder.appendff("{}, ", module));
TRY(JaktInternal::PrettyPrint::output_indentation(builder));TRY(builder.append("id: "sv));TRY(builder.appendff("{}", id));
}
TRY(builder.append(")"sv));return builder.to_string(); }
bool types::TraitId::equals(types::TraitId const other) const {
{
return (((((((*this).module)).id) == ((((other).module)).id)) && (((*this).id) == ((other).id))));
}
}

types::TraitId::TraitId(types::ModuleId a_module, size_t a_id) :module(a_module), id(a_id){}

ErrorOr<DeprecatedString> types::FunctionId::debug_description() const { auto builder = MUST(DeprecatedStringBuilder::create());TRY(builder.append("FunctionId("sv));{
JaktInternal::PrettyPrint::ScopedLevelIncrease increase_indent {};
TRY(JaktInternal::PrettyPrint::output_indentation(builder));TRY(builder.append("module: "sv));TRY(builder.appendff("{}, ", module));
TRY(JaktInternal::PrettyPrint::output_indentation(builder));TRY(builder.append("id: "sv));TRY(builder.appendff("{}", id));
}
TRY(builder.append(")"sv));return builder.to_string(); }
bool types::FunctionId::equals(types::FunctionId const rhs) const {
{
return (((((((*this).module)).id) == ((((rhs).module)).id)) && (((*this).id) == ((rhs).id))));
}
}

types::FunctionId::FunctionId(types::ModuleId a_module, size_t a_id) :module(a_module), id(a_id){}

ErrorOr<DeprecatedString> types::Module::debug_description() const { auto builder = MUST(DeprecatedStringBuilder::create());TRY(builder.append("Module("sv));{
JaktInternal::PrettyPrint::ScopedLevelIncrease increase_indent {};
TRY(JaktInternal::PrettyPrint::output_indentation(builder));TRY(builder.append("id: "sv));TRY(builder.appendff("{}, ", id));
TRY(JaktInternal::PrettyPrint::output_indentation(builder));TRY(builder.append("name: "sv));TRY(builder.appendff("\"{}\", ", name));
TRY(JaktInternal::PrettyPrint::output_indentation(builder));TRY(builder.append("functions: "sv));TRY(builder.appendff("{}, ", functions));
TRY(JaktInternal::PrettyPrint::output_indentation(builder));TRY(builder.append("structures: "sv));TRY(builder.appendff("{}, ", structures));
TRY(JaktInternal::PrettyPrint::output_indentation(builder));TRY(builder.append("enums: "sv));TRY(builder.appendff("{}, ", enums));
TRY(JaktInternal::PrettyPrint::output_indentation(builder));TRY(builder.append("scopes: "sv));TRY(builder.appendff("{}, ", scopes));
TRY(JaktInternal::PrettyPrint::output_indentation(builder));TRY(builder.append("types: "sv));TRY(builder.appendff("{}, ", types));
TRY(JaktInternal::PrettyPrint::output_indentation(builder));TRY(builder.append("traits: "sv));TRY(builder.appendff("{}, ", traits));
TRY(JaktInternal::PrettyPrint::output_indentation(builder));TRY(builder.append("variables: "sv));TRY(builder.appendff("{}, ", variables));
TRY(JaktInternal::PrettyPrint::output_indentation(builder));TRY(builder.append("imports: "sv));TRY(builder.appendff("{}, ", imports));
TRY(JaktInternal::PrettyPrint::output_indentation(builder));TRY(builder.append("resolved_import_path: "sv));TRY(builder.appendff("\"{}\", ", resolved_import_path));
TRY(JaktInternal::PrettyPrint::output_indentation(builder));TRY(builder.append("is_root: "sv));TRY(builder.appendff("{}", is_root));
}
TRY(builder.append(")"sv));return builder.to_string(); }
types::Module::Module(types::ModuleId&& a_id, DeprecatedString&& a_name, JaktInternal::DynamicArray<NonnullRefPtr<types::CheckedFunction>>&& a_functions, JaktInternal::DynamicArray<types::CheckedStruct>&& a_structures, JaktInternal::DynamicArray<types::CheckedEnum>&& a_enums, JaktInternal::DynamicArray<NonnullRefPtr<types::Scope>>&& a_scopes, JaktInternal::DynamicArray<NonnullRefPtr<typename types::Type>>&& a_types, JaktInternal::DynamicArray<NonnullRefPtr<types::CheckedTrait>>&& a_traits, JaktInternal::DynamicArray<NonnullRefPtr<types::CheckedVariable>>&& a_variables, JaktInternal::DynamicArray<types::ModuleId>&& a_imports, DeprecatedString&& a_resolved_import_path, bool&& a_is_root): id(move(a_id)), name(move(a_name)), functions(move(a_functions)), structures(move(a_structures)), enums(move(a_enums)), scopes(move(a_scopes)), types(move(a_types)), traits(move(a_traits)), variables(move(a_variables)), imports(move(a_imports)), resolved_import_path(move(a_resolved_import_path)), is_root(move(a_is_root)){}
ErrorOr<NonnullRefPtr<Module>> types::Module::create(types::ModuleId id, DeprecatedString name, JaktInternal::DynamicArray<NonnullRefPtr<types::CheckedFunction>> functions, JaktInternal::DynamicArray<types::CheckedStruct> structures, JaktInternal::DynamicArray<types::CheckedEnum> enums, JaktInternal::DynamicArray<NonnullRefPtr<types::Scope>> scopes, JaktInternal::DynamicArray<NonnullRefPtr<typename types::Type>> types, JaktInternal::DynamicArray<NonnullRefPtr<types::CheckedTrait>> traits, JaktInternal::DynamicArray<NonnullRefPtr<types::CheckedVariable>> variables, JaktInternal::DynamicArray<types::ModuleId> imports, DeprecatedString resolved_import_path, bool is_root) { auto o = TRY(adopt_nonnull_ref_or_enomem(new (nothrow) Module (move(id), move(name), move(functions), move(structures), move(enums), move(scopes), move(types), move(traits), move(variables), move(imports), move(resolved_import_path), move(is_root)))); return o; }
ErrorOr<types::TypeId> types::Module::new_type_variable(JaktInternal::Optional<JaktInternal::DynamicArray<types::TypeId>> const implemented_traits) {
{
size_t const new_id = ((((*this).types)).size());
JaktInternal::DynamicArray<types::TypeId> const empty_implementation = (TRY((DynamicArray<types::TypeId>::create_with({}))));
JaktInternal::DynamicArray<types::TypeId> const trait_implementations = implemented_traits.value_or_lazy_evaluated([&] { return empty_implementation; });
TRY((((((*this).types)).push(TRY((types::Type::template create<typename types::Type::TypeVariable>(TRY((__jakt_format(Jakt::DeprecatedString("T{}"sv),new_id))),trait_implementations)))))));
return (types::TypeId(((*this).id),new_id));
}
}

ErrorOr<types::FunctionId> types::Module::add_function(NonnullRefPtr<types::CheckedFunction> const checked_function) {
{
types::FunctionId const new_id = ((*this).next_function_id());
TRY((((((*this).functions)).push(checked_function))));
return (new_id);
}
}

bool types::Module::is_prelude() const {
{
return ((((((*this).id)).id) == static_cast<size_t>(0ULL)));
}
}

ErrorOr<types::VarId> types::Module::add_variable(NonnullRefPtr<types::CheckedVariable> const checked_variable) {
{
size_t const new_id = ((((*this).variables)).size());
TRY((((((*this).variables)).push(checked_variable))));
return (types::VarId(((*this).id),new_id));
}
}

types::FunctionId types::Module::next_function_id() const {
{
return (types::FunctionId(((*this).id),((((*this).functions)).size())));
}
}

ErrorOr<DeprecatedString> types::CheckedTrait::debug_description() const { auto builder = MUST(DeprecatedStringBuilder::create());TRY(builder.append("CheckedTrait("sv));{
JaktInternal::PrettyPrint::ScopedLevelIncrease increase_indent {};
TRY(JaktInternal::PrettyPrint::output_indentation(builder));TRY(builder.append("name: "sv));TRY(builder.appendff("\"{}\", ", name));
TRY(JaktInternal::PrettyPrint::output_indentation(builder));TRY(builder.append("name_span: "sv));TRY(builder.appendff("{}, ", name_span));
TRY(JaktInternal::PrettyPrint::output_indentation(builder));TRY(builder.append("methods: "sv));TRY(builder.appendff("{}, ", methods));
TRY(JaktInternal::PrettyPrint::output_indentation(builder));TRY(builder.append("generic_parameters: "sv));TRY(builder.appendff("{}, ", generic_parameters));
TRY(JaktInternal::PrettyPrint::output_indentation(builder));TRY(builder.append("scope_id: "sv));TRY(builder.appendff("{}", scope_id));
}
TRY(builder.append(")"sv));return builder.to_string(); }
types::CheckedTrait::CheckedTrait(DeprecatedString&& a_name, utility::Span&& a_name_span, JaktInternal::Dictionary<DeprecatedString,types::FunctionId>&& a_methods, JaktInternal::DynamicArray<types::CheckedGenericParameter>&& a_generic_parameters, types::ScopeId&& a_scope_id): name(move(a_name)), name_span(move(a_name_span)), methods(move(a_methods)), generic_parameters(move(a_generic_parameters)), scope_id(move(a_scope_id)){}
ErrorOr<NonnullRefPtr<CheckedTrait>> types::CheckedTrait::create(DeprecatedString name, utility::Span name_span, JaktInternal::Dictionary<DeprecatedString,types::FunctionId> methods, JaktInternal::DynamicArray<types::CheckedGenericParameter> generic_parameters, types::ScopeId scope_id) { auto o = TRY(adopt_nonnull_ref_or_enomem(new (nothrow) CheckedTrait (move(name), move(name_span), move(methods), move(generic_parameters), move(scope_id)))); return o; }
ErrorOr<DeprecatedString> types::CheckedFunction::debug_description() const { auto builder = MUST(DeprecatedStringBuilder::create());TRY(builder.append("CheckedFunction("sv));{
JaktInternal::PrettyPrint::ScopedLevelIncrease increase_indent {};
TRY(JaktInternal::PrettyPrint::output_indentation(builder));TRY(builder.append("name: "sv));TRY(builder.appendff("\"{}\", ", name));
TRY(JaktInternal::PrettyPrint::output_indentation(builder));TRY(builder.append("name_span: "sv));TRY(builder.appendff("{}, ", name_span));
TRY(JaktInternal::PrettyPrint::output_indentation(builder));TRY(builder.append("visibility: "sv));TRY(builder.appendff("{}, ", visibility));
TRY(JaktInternal::PrettyPrint::output_indentation(builder));TRY(builder.append("return_type_id: "sv));TRY(builder.appendff("{}, ", return_type_id));
TRY(JaktInternal::PrettyPrint::output_indentation(builder));TRY(builder.append("return_type_span: "sv));TRY(builder.appendff("{}, ", return_type_span));
TRY(JaktInternal::PrettyPrint::output_indentation(builder));TRY(builder.append("params: "sv));TRY(builder.appendff("{}, ", params));
TRY(JaktInternal::PrettyPrint::output_indentation(builder));TRY(builder.append("generics: "sv));TRY(builder.appendff("{}, ", *generics));
TRY(JaktInternal::PrettyPrint::output_indentation(builder));TRY(builder.append("block: "sv));TRY(builder.appendff("{}, ", block));
TRY(JaktInternal::PrettyPrint::output_indentation(builder));TRY(builder.append("can_throw: "sv));TRY(builder.appendff("{}, ", can_throw));
TRY(JaktInternal::PrettyPrint::output_indentation(builder));TRY(builder.append("type: "sv));TRY(builder.appendff("{}, ", type));
TRY(JaktInternal::PrettyPrint::output_indentation(builder));TRY(builder.append("linkage: "sv));TRY(builder.appendff("{}, ", linkage));
TRY(JaktInternal::PrettyPrint::output_indentation(builder));TRY(builder.append("function_scope_id: "sv));TRY(builder.appendff("{}, ", function_scope_id));
TRY(JaktInternal::PrettyPrint::output_indentation(builder));TRY(builder.append("struct_id: "sv));TRY(builder.appendff("{}, ", struct_id));
TRY(JaktInternal::PrettyPrint::output_indentation(builder));TRY(builder.append("is_instantiated: "sv));TRY(builder.appendff("{}, ", is_instantiated));
TRY(JaktInternal::PrettyPrint::output_indentation(builder));TRY(builder.append("parsed_function: "sv));TRY(builder.appendff("{}, ", parsed_function));
TRY(JaktInternal::PrettyPrint::output_indentation(builder));TRY(builder.append("is_comptime: "sv));TRY(builder.appendff("{}, ", is_comptime));
TRY(JaktInternal::PrettyPrint::output_indentation(builder));TRY(builder.append("is_virtual: "sv));TRY(builder.appendff("{}, ", is_virtual));
TRY(JaktInternal::PrettyPrint::output_indentation(builder));TRY(builder.append("is_override: "sv));TRY(builder.appendff("{}, ", is_override));
TRY(JaktInternal::PrettyPrint::output_indentation(builder));TRY(builder.append("owner_scope: "sv));TRY(builder.appendff("{}, ", owner_scope));
TRY(JaktInternal::PrettyPrint::output_indentation(builder));TRY(builder.append("external_name: "sv));TRY(builder.appendff("{}, ", external_name));
TRY(JaktInternal::PrettyPrint::output_indentation(builder));TRY(builder.append("deprecated_message: "sv));TRY(builder.appendff("{}", deprecated_message));
}
TRY(builder.append(")"sv));return builder.to_string(); }
ErrorOr<bool> types::CheckedFunction::signature_matches(NonnullRefPtr<types::CheckedFunction> const other) const {
{
if ((((((*this).name) != ((other)->name)) || (((*this).can_throw) != ((other)->can_throw))) || (((*this).is_comptime) != ((other)->is_comptime)))){
return (false);
}
if ((((((*this).params)).size()) != ((((other)->params)).size()))){
return (false);
}
if ((((((((*this).generics))->params)).size()) != ((((((other)->generics))->params)).size()))){
return (false);
}
JaktInternal::Set<DeprecatedString> lhs_generic_type_ids = (TRY((Set<DeprecatedString>::create_with_values({}))));
JaktInternal::Set<DeprecatedString> rhs_generic_type_ids = (TRY((Set<DeprecatedString>::create_with_values({}))));
{
JaktInternal::ArrayIterator<types::FunctionGenericParameter> _magic = ((((((*this).generics))->params)).iterator());
for (;;){
JaktInternal::Optional<types::FunctionGenericParameter> _magic_value = ((_magic).next());
if ((!(((_magic_value).has_value())))){
break;
}
types::FunctionGenericParameter param = (_magic_value.value());
{
types::TypeId const type_id = ((param).type_id());
TRY((((lhs_generic_type_ids).add(TRY((((type_id).to_string())))))));
}

}
}

{
JaktInternal::ArrayIterator<types::FunctionGenericParameter> _magic = ((((((other)->generics))->params)).iterator());
for (;;){
JaktInternal::Optional<types::FunctionGenericParameter> _magic_value = ((_magic).next());
if ((!(((_magic_value).has_value())))){
break;
}
types::FunctionGenericParameter param = (_magic_value.value());
{
types::TypeId const type_id = ((param).type_id());
TRY((((rhs_generic_type_ids).add(TRY((((type_id).to_string())))))));
}

}
}

{
JaktInternal::Range<size_t> _magic = (JaktInternal::Range<size_t>{static_cast<size_t>(static_cast<size_t>(0ULL)),static_cast<size_t>(((((*this).params)).size()))});
for (;;){
JaktInternal::Optional<size_t> _magic_value = ((_magic).next());
if ((!(((_magic_value).has_value())))){
break;
}
size_t param_index = (_magic_value.value());
{
types::CheckedParameter const lhs_param = ((((*this).params))[param_index]);
types::CheckedParameter const rhs_param = ((((other)->params))[param_index]);
DeprecatedString const lhs_param_id = TRY((((((((lhs_param).variable))->type_id)).to_string())));
DeprecatedString const rhs_param_id = TRY((((((((rhs_param).variable))->type_id)).to_string())));
if (((!(((((((lhs_param).variable))->type_id)).equals(((((rhs_param).variable))->type_id))))) && (!((((lhs_generic_type_ids).contains(lhs_param_id)) && ((rhs_generic_type_ids).contains(rhs_param_id))))))){
return (false);
}
}

}
}

return (true);
}
}

bool types::CheckedFunction::is_static() const {
{
if ((((((*this).params)).size()) < static_cast<size_t>(1ULL))){
return (true);
}
return ((((((((((*this).params))[static_cast<i64>(0LL)])).variable))->name) != Jakt::DeprecatedString("this"sv)));
}
}

types::CheckedFunction::CheckedFunction(DeprecatedString&& a_name, utility::Span&& a_name_span, types::CheckedVisibility&& a_visibility, types::TypeId&& a_return_type_id, JaktInternal::Optional<utility::Span>&& a_return_type_span, JaktInternal::DynamicArray<types::CheckedParameter>&& a_params, NonnullRefPtr<types::FunctionGenerics>&& a_generics, types::CheckedBlock&& a_block, bool&& a_can_throw, parser::FunctionType&& a_type, parser::FunctionLinkage&& a_linkage, types::ScopeId&& a_function_scope_id, JaktInternal::Optional<types::StructId>&& a_struct_id, bool&& a_is_instantiated, JaktInternal::Optional<parser::ParsedFunction>&& a_parsed_function, bool&& a_is_comptime, bool&& a_is_virtual, bool&& a_is_override, JaktInternal::Optional<types::ScopeId>&& a_owner_scope, JaktInternal::Optional<DeprecatedString>&& a_external_name, JaktInternal::Optional<DeprecatedString>&& a_deprecated_message): name(move(a_name)), name_span(move(a_name_span)), visibility(move(a_visibility)), return_type_id(move(a_return_type_id)), return_type_span(move(a_return_type_span)), params(move(a_params)), generics(move(a_generics)), block(move(a_block)), can_throw(move(a_can_throw)), type(move(a_type)), linkage(move(a_linkage)), function_scope_id(move(a_function_scope_id)), struct_id(move(a_struct_id)), is_instantiated(move(a_is_instantiated)), parsed_function(move(a_parsed_function)), is_comptime(move(a_is_comptime)), is_virtual(move(a_is_virtual)), is_override(move(a_is_override)), owner_scope(move(a_owner_scope)), external_name(move(a_external_name)), deprecated_message(move(a_deprecated_message)){}
ErrorOr<NonnullRefPtr<CheckedFunction>> types::CheckedFunction::create(DeprecatedString name, utility::Span name_span, types::CheckedVisibility visibility, types::TypeId return_type_id, JaktInternal::Optional<utility::Span> return_type_span, JaktInternal::DynamicArray<types::CheckedParameter> params, NonnullRefPtr<types::FunctionGenerics> generics, types::CheckedBlock block, bool can_throw, parser::FunctionType type, parser::FunctionLinkage linkage, types::ScopeId function_scope_id, JaktInternal::Optional<types::StructId> struct_id, bool is_instantiated, JaktInternal::Optional<parser::ParsedFunction> parsed_function, bool is_comptime, bool is_virtual, bool is_override, JaktInternal::Optional<types::ScopeId> owner_scope, JaktInternal::Optional<DeprecatedString> external_name, JaktInternal::Optional<DeprecatedString> deprecated_message) { auto o = TRY(adopt_nonnull_ref_or_enomem(new (nothrow) CheckedFunction (move(name), move(name_span), move(visibility), move(return_type_id), move(return_type_span), move(params), move(generics), move(block), move(can_throw), move(type), move(linkage), move(function_scope_id), move(struct_id), move(is_instantiated), move(parsed_function), move(is_comptime), move(is_virtual), move(is_override), move(owner_scope), move(external_name), move(deprecated_message)))); return o; }
parser::ParsedFunction types::CheckedFunction::to_parsed_function() const {
{
if ((!(((((*this).parsed_function)).has_value())))){
utility::panic(Jakt::DeprecatedString("to_parsed_function() called on a synthetic function"sv));
}
return ((((*this).parsed_function).value()));
}
}

bool types::CheckedFunction::is_specialized_for_types(JaktInternal::DynamicArray<types::TypeId> const types) const {
{
return (((((*this).generics))->is_specialized_for_types(types)));
}
}

ErrorOr<NonnullRefPtr<types::CheckedFunction>> types::CheckedFunction::copy() const {
{
return (TRY((types::CheckedFunction::create(((*this).name),((*this).name_span),((*this).visibility),((*this).return_type_id),((*this).return_type_span),((*this).params),((*this).generics),((*this).block),((*this).can_throw),((*this).type),((*this).linkage),((*this).function_scope_id),((*this).struct_id),((*this).is_instantiated),((*this).parsed_function),((*this).is_comptime),((*this).is_virtual),((*this).is_override),JaktInternal::OptionalNone(),JaktInternal::OptionalNone(),JaktInternal::OptionalNone()))));
}
}

ErrorOr<void> types::CheckedFunction::add_param(types::CheckedParameter const checked_param) {
{
TRY((((((*this).params)).push(checked_param))));
TRY((((((((*this).generics))->base_params)).push(checked_param))));
}
return {};
}

ErrorOr<void> types::CheckedFunction::map_types(Function<ErrorOr<types::TypeId>(types::TypeId)> const& map) {
{
(((*this).return_type_id) = TRY((map(((*this).return_type_id)))));
JaktInternal::DynamicArray<types::CheckedParameter> changed_params = (TRY((DynamicArray<types::CheckedParameter>::create_with({}))));
{
JaktInternal::ArrayIterator<types::CheckedParameter> _magic = ((((*this).params)).iterator());
for (;;){
JaktInternal::Optional<types::CheckedParameter> _magic_value = ((_magic).next());
if ((!(((_magic_value).has_value())))){
break;
}
types::CheckedParameter param = (_magic_value.value());
{
TRY((((changed_params).push(TRY((((param).map_types(map))))))));
}

}
}

(((*this).params) = changed_params);
}
return {};
}

bool types::CheckedFunction::is_mutating() const {
{
if ((((((*this).params)).size()) < static_cast<size_t>(1ULL))){
return (false);
}
NonnullRefPtr<types::CheckedVariable> const first_param_variable = ((((((*this).params))[static_cast<i64>(0LL)])).variable);
return (((((first_param_variable)->name) == Jakt::DeprecatedString("this"sv)) && ((first_param_variable)->is_mutable)));
}
}

DeprecatedString types::CheckedFunction::name_for_codegen() const {
{
return (((*this).external_name).value_or_lazy_evaluated([&] { return ((*this).name); }));
}
}

ErrorOr<void> types::CheckedFunction::set_params(JaktInternal::DynamicArray<types::CheckedParameter> const checked_params) {
{
(((*this).params) = checked_params);
(((((*this).generics))->base_params) = checked_params);
}
return {};
}

ErrorOr<DeprecatedString> types::EnumId::debug_description() const { auto builder = MUST(DeprecatedStringBuilder::create());TRY(builder.append("EnumId("sv));{
JaktInternal::PrettyPrint::ScopedLevelIncrease increase_indent {};
TRY(JaktInternal::PrettyPrint::output_indentation(builder));TRY(builder.append("module: "sv));TRY(builder.appendff("{}, ", module));
TRY(JaktInternal::PrettyPrint::output_indentation(builder));TRY(builder.append("id: "sv));TRY(builder.appendff("{}", id));
}
TRY(builder.append(")"sv));return builder.to_string(); }
bool types::EnumId::equals(types::EnumId const rhs) const {
{
return (((((((*this).module)).id) == ((((rhs).module)).id)) && (((*this).id) == ((rhs).id))));
}
}

types::EnumId::EnumId(types::ModuleId a_module, size_t a_id) :module(a_module), id(a_id){}

ErrorOr<DeprecatedString> types::StructId::debug_description() const { auto builder = MUST(DeprecatedStringBuilder::create());TRY(builder.append("StructId("sv));{
JaktInternal::PrettyPrint::ScopedLevelIncrease increase_indent {};
TRY(JaktInternal::PrettyPrint::output_indentation(builder));TRY(builder.append("module: "sv));TRY(builder.appendff("{}, ", module));
TRY(JaktInternal::PrettyPrint::output_indentation(builder));TRY(builder.append("id: "sv));TRY(builder.appendff("{}", id));
}
TRY(builder.append(")"sv));return builder.to_string(); }
bool types::StructId::equals(types::StructId const rhs) const {
{
return (((((((*this).module)).id) == ((((rhs).module)).id)) && (((*this).id) == ((rhs).id))));
}
}

types::StructId::StructId(types::ModuleId a_module, size_t a_id) :module(a_module), id(a_id){}

ErrorOr<DeprecatedString> types::ScopeId::debug_description() const { auto builder = MUST(DeprecatedStringBuilder::create());TRY(builder.append("ScopeId("sv));{
JaktInternal::PrettyPrint::ScopedLevelIncrease increase_indent {};
TRY(JaktInternal::PrettyPrint::output_indentation(builder));TRY(builder.append("module_id: "sv));TRY(builder.appendff("{}, ", module_id));
TRY(JaktInternal::PrettyPrint::output_indentation(builder));TRY(builder.append("id: "sv));TRY(builder.appendff("{}", id));
}
TRY(builder.append(")"sv));return builder.to_string(); }
ErrorOr<DeprecatedString> types::ScopeId::to_string() const {
{
return (TRY((__jakt_format(Jakt::DeprecatedString("{}:{}"sv),((((*this).module_id)).id),((*this).id)))));
}
}

bool types::ScopeId::equals(types::ScopeId const other) const {
{
return (((((((*this).module_id)).id) == ((((other).module_id)).id)) && (((*this).id) == ((other).id))));
}
}

types::ScopeId::ScopeId(types::ModuleId a_module_id, size_t a_id) :module_id(a_module_id), id(a_id){}

ErrorOr<DeprecatedString> types::LoadedModule::debug_description() const { auto builder = MUST(DeprecatedStringBuilder::create());TRY(builder.append("LoadedModule("sv));{
JaktInternal::PrettyPrint::ScopedLevelIncrease increase_indent {};
TRY(JaktInternal::PrettyPrint::output_indentation(builder));TRY(builder.append("module_id: "sv));TRY(builder.appendff("{}, ", module_id));
TRY(JaktInternal::PrettyPrint::output_indentation(builder));TRY(builder.append("file_id: "sv));TRY(builder.appendff("{}", file_id));
}
TRY(builder.append(")"sv));return builder.to_string(); }
types::LoadedModule::LoadedModule(types::ModuleId a_module_id, utility::FileId a_file_id) :module_id(a_module_id), file_id(a_file_id){}

ErrorOr<DeprecatedString> types::CheckedEnum::debug_description() const { auto builder = MUST(DeprecatedStringBuilder::create());TRY(builder.append("CheckedEnum("sv));{
JaktInternal::PrettyPrint::ScopedLevelIncrease increase_indent {};
TRY(JaktInternal::PrettyPrint::output_indentation(builder));TRY(builder.append("name: "sv));TRY(builder.appendff("\"{}\", ", name));
TRY(JaktInternal::PrettyPrint::output_indentation(builder));TRY(builder.append("name_span: "sv));TRY(builder.appendff("{}, ", name_span));
TRY(JaktInternal::PrettyPrint::output_indentation(builder));TRY(builder.append("generic_parameters: "sv));TRY(builder.appendff("{}, ", generic_parameters));
TRY(JaktInternal::PrettyPrint::output_indentation(builder));TRY(builder.append("variants: "sv));TRY(builder.appendff("{}, ", variants));
TRY(JaktInternal::PrettyPrint::output_indentation(builder));TRY(builder.append("fields: "sv));TRY(builder.appendff("{}, ", fields));
TRY(JaktInternal::PrettyPrint::output_indentation(builder));TRY(builder.append("scope_id: "sv));TRY(builder.appendff("{}, ", scope_id));
TRY(JaktInternal::PrettyPrint::output_indentation(builder));TRY(builder.append("definition_linkage: "sv));TRY(builder.appendff("{}, ", definition_linkage));
TRY(JaktInternal::PrettyPrint::output_indentation(builder));TRY(builder.append("trait_implementations: "sv));TRY(builder.appendff("{}, ", trait_implementations));
TRY(JaktInternal::PrettyPrint::output_indentation(builder));TRY(builder.append("record_type: "sv));TRY(builder.appendff("{}, ", record_type));
TRY(JaktInternal::PrettyPrint::output_indentation(builder));TRY(builder.append("underlying_type_id: "sv));TRY(builder.appendff("{}, ", underlying_type_id));
TRY(JaktInternal::PrettyPrint::output_indentation(builder));TRY(builder.append("type_id: "sv));TRY(builder.appendff("{}, ", type_id));
TRY(JaktInternal::PrettyPrint::output_indentation(builder));TRY(builder.append("is_boxed: "sv));TRY(builder.appendff("{}", is_boxed));
}
TRY(builder.append(")"sv));return builder.to_string(); }
types::CheckedEnum::CheckedEnum(DeprecatedString a_name, utility::Span a_name_span, JaktInternal::DynamicArray<types::CheckedGenericParameter> a_generic_parameters, JaktInternal::DynamicArray<types::CheckedEnumVariant> a_variants, JaktInternal::DynamicArray<types::CheckedField> a_fields, types::ScopeId a_scope_id, parser::DefinitionLinkage a_definition_linkage, JaktInternal::Dictionary<DeprecatedString,JaktInternal::Tuple<types::TraitId,JaktInternal::DynamicArray<types::TypeId>>> a_trait_implementations, parser::RecordType a_record_type, types::TypeId a_underlying_type_id, types::TypeId a_type_id, bool a_is_boxed) :name(a_name), name_span(a_name_span), generic_parameters(a_generic_parameters), variants(a_variants), fields(a_fields), scope_id(a_scope_id), definition_linkage(a_definition_linkage), trait_implementations(a_trait_implementations), record_type(a_record_type), underlying_type_id(a_underlying_type_id), type_id(a_type_id), is_boxed(a_is_boxed){}

ErrorOr<DeprecatedString> types::FunctionGenericParameter::debug_description() const { auto builder = MUST(DeprecatedStringBuilder::create());TRY(builder.append("FunctionGenericParameter("sv));{
JaktInternal::PrettyPrint::ScopedLevelIncrease increase_indent {};
TRY(JaktInternal::PrettyPrint::output_indentation(builder));TRY(builder.append("kind: "sv));TRY(builder.appendff("{}, ", kind));
TRY(JaktInternal::PrettyPrint::output_indentation(builder));TRY(builder.append("checked_parameter: "sv));TRY(builder.appendff("{}", checked_parameter));
}
TRY(builder.append(")"sv));return builder.to_string(); }
ErrorOr<types::FunctionGenericParameter> types::FunctionGenericParameter::parameter(types::TypeId const type_id,utility::Span const span) {
{
return (types::FunctionGenericParameter( types::FunctionGenericParameterKind { typename types::FunctionGenericParameterKind::Parameter() } ,TRY((types::CheckedGenericParameter::make(type_id,span)))));
}
}

types::TypeId types::FunctionGenericParameter::type_id() const {
{
return (((((*this).checked_parameter)).type_id));
}
}

types::FunctionGenericParameter::FunctionGenericParameter(types::FunctionGenericParameterKind a_kind, types::CheckedGenericParameter a_checked_parameter) :kind(a_kind), checked_parameter(a_checked_parameter){}

ErrorOr<DeprecatedString> types::ResolvedNamespace::debug_description() const { auto builder = MUST(DeprecatedStringBuilder::create());TRY(builder.append("ResolvedNamespace("sv));{
JaktInternal::PrettyPrint::ScopedLevelIncrease increase_indent {};
TRY(JaktInternal::PrettyPrint::output_indentation(builder));TRY(builder.append("name: "sv));TRY(builder.appendff("\"{}\", ", name));
TRY(JaktInternal::PrettyPrint::output_indentation(builder));TRY(builder.append("external_name: "sv));TRY(builder.appendff("{}, ", external_name));
TRY(JaktInternal::PrettyPrint::output_indentation(builder));TRY(builder.append("generic_parameters: "sv));TRY(builder.appendff("{}", generic_parameters));
}
TRY(builder.append(")"sv));return builder.to_string(); }
types::ResolvedNamespace::ResolvedNamespace(DeprecatedString a_name, JaktInternal::Optional<DeprecatedString> a_external_name, JaktInternal::Optional<JaktInternal::DynamicArray<types::TypeId>> a_generic_parameters) :name(a_name), external_name(a_external_name), generic_parameters(a_generic_parameters){}

ErrorOr<DeprecatedString> types::Scope::debug_description() const { auto builder = MUST(DeprecatedStringBuilder::create());TRY(builder.append("Scope("sv));{
JaktInternal::PrettyPrint::ScopedLevelIncrease increase_indent {};
TRY(JaktInternal::PrettyPrint::output_indentation(builder));TRY(builder.append("namespace_name: "sv));TRY(builder.appendff("{}, ", namespace_name));
TRY(JaktInternal::PrettyPrint::output_indentation(builder));TRY(builder.append("external_name: "sv));TRY(builder.appendff("{}, ", external_name));
TRY(JaktInternal::PrettyPrint::output_indentation(builder));TRY(builder.append("vars: "sv));TRY(builder.appendff("{}, ", vars));
TRY(JaktInternal::PrettyPrint::output_indentation(builder));TRY(builder.append("comptime_bindings: "sv));TRY(builder.appendff("{}, ", comptime_bindings));
TRY(JaktInternal::PrettyPrint::output_indentation(builder));TRY(builder.append("structs: "sv));TRY(builder.appendff("{}, ", structs));
TRY(JaktInternal::PrettyPrint::output_indentation(builder));TRY(builder.append("functions: "sv));TRY(builder.appendff("{}, ", functions));
TRY(JaktInternal::PrettyPrint::output_indentation(builder));TRY(builder.append("enums: "sv));TRY(builder.appendff("{}, ", enums));
TRY(JaktInternal::PrettyPrint::output_indentation(builder));TRY(builder.append("types: "sv));TRY(builder.appendff("{}, ", types));
TRY(JaktInternal::PrettyPrint::output_indentation(builder));TRY(builder.append("traits: "sv));TRY(builder.appendff("{}, ", traits));
TRY(JaktInternal::PrettyPrint::output_indentation(builder));TRY(builder.append("imports: "sv));TRY(builder.appendff("{}, ", imports));
TRY(JaktInternal::PrettyPrint::output_indentation(builder));TRY(builder.append("aliases: "sv));TRY(builder.appendff("{}, ", aliases));
TRY(JaktInternal::PrettyPrint::output_indentation(builder));TRY(builder.append("parent: "sv));TRY(builder.appendff("{}, ", parent));
TRY(JaktInternal::PrettyPrint::output_indentation(builder));TRY(builder.append("alias_scope: "sv));TRY(builder.appendff("{}, ", alias_scope));
TRY(JaktInternal::PrettyPrint::output_indentation(builder));TRY(builder.append("children: "sv));TRY(builder.appendff("{}, ", children));
TRY(JaktInternal::PrettyPrint::output_indentation(builder));TRY(builder.append("can_throw: "sv));TRY(builder.appendff("{}, ", can_throw));
TRY(JaktInternal::PrettyPrint::output_indentation(builder));TRY(builder.append("import_path_if_extern: "sv));TRY(builder.appendff("{}, ", import_path_if_extern));
TRY(JaktInternal::PrettyPrint::output_indentation(builder));TRY(builder.append("alias_path: "sv));TRY(builder.appendff("{}, ", alias_path));
TRY(JaktInternal::PrettyPrint::output_indentation(builder));TRY(builder.append("after_extern_include: "sv));TRY(builder.appendff("{}, ", after_extern_include));
TRY(JaktInternal::PrettyPrint::output_indentation(builder));TRY(builder.append("before_extern_include: "sv));TRY(builder.appendff("{}, ", before_extern_include));
TRY(JaktInternal::PrettyPrint::output_indentation(builder));TRY(builder.append("debug_name: "sv));TRY(builder.appendff("\"{}\", ", debug_name));
TRY(JaktInternal::PrettyPrint::output_indentation(builder));TRY(builder.append("resolution_mixins: "sv));TRY(builder.appendff("{}", resolution_mixins));
}
TRY(builder.append(")"sv));return builder.to_string(); }
types::Scope::Scope(JaktInternal::Optional<DeprecatedString>&& a_namespace_name, JaktInternal::Optional<DeprecatedString>&& a_external_name, JaktInternal::Dictionary<DeprecatedString,types::VarId>&& a_vars, JaktInternal::Dictionary<DeprecatedString,types::Value>&& a_comptime_bindings, JaktInternal::Dictionary<DeprecatedString,types::StructId>&& a_structs, JaktInternal::Dictionary<DeprecatedString,JaktInternal::DynamicArray<types::FunctionId>>&& a_functions, JaktInternal::Dictionary<DeprecatedString,types::EnumId>&& a_enums, JaktInternal::Dictionary<DeprecatedString,types::TypeId>&& a_types, JaktInternal::Dictionary<DeprecatedString,types::TraitId>&& a_traits, JaktInternal::Dictionary<DeprecatedString,types::ModuleId>&& a_imports, JaktInternal::Dictionary<DeprecatedString,types::ScopeId>&& a_aliases, JaktInternal::Optional<types::ScopeId>&& a_parent, JaktInternal::Optional<types::ScopeId>&& a_alias_scope, JaktInternal::DynamicArray<types::ScopeId>&& a_children, bool&& a_can_throw, JaktInternal::Optional<DeprecatedString>&& a_import_path_if_extern, JaktInternal::Optional<JaktInternal::DynamicArray<types::ResolvedNamespace>>&& a_alias_path, JaktInternal::DynamicArray<parser::IncludeAction>&& a_after_extern_include, JaktInternal::DynamicArray<parser::IncludeAction>&& a_before_extern_include, DeprecatedString&& a_debug_name, JaktInternal::DynamicArray<types::ScopeId>&& a_resolution_mixins): namespace_name(move(a_namespace_name)), external_name(move(a_external_name)), vars(move(a_vars)), comptime_bindings(move(a_comptime_bindings)), structs(move(a_structs)), functions(move(a_functions)), enums(move(a_enums)), types(move(a_types)), traits(move(a_traits)), imports(move(a_imports)), aliases(move(a_aliases)), parent(move(a_parent)), alias_scope(move(a_alias_scope)), children(move(a_children)), can_throw(move(a_can_throw)), import_path_if_extern(move(a_import_path_if_extern)), alias_path(move(a_alias_path)), after_extern_include(move(a_after_extern_include)), before_extern_include(move(a_before_extern_include)), debug_name(move(a_debug_name)), resolution_mixins(move(a_resolution_mixins)){}
ErrorOr<NonnullRefPtr<Scope>> types::Scope::create(JaktInternal::Optional<DeprecatedString> namespace_name, JaktInternal::Optional<DeprecatedString> external_name, JaktInternal::Dictionary<DeprecatedString,types::VarId> vars, JaktInternal::Dictionary<DeprecatedString,types::Value> comptime_bindings, JaktInternal::Dictionary<DeprecatedString,types::StructId> structs, JaktInternal::Dictionary<DeprecatedString,JaktInternal::DynamicArray<types::FunctionId>> functions, JaktInternal::Dictionary<DeprecatedString,types::EnumId> enums, JaktInternal::Dictionary<DeprecatedString,types::TypeId> types, JaktInternal::Dictionary<DeprecatedString,types::TraitId> traits, JaktInternal::Dictionary<DeprecatedString,types::ModuleId> imports, JaktInternal::Dictionary<DeprecatedString,types::ScopeId> aliases, JaktInternal::Optional<types::ScopeId> parent, JaktInternal::Optional<types::ScopeId> alias_scope, JaktInternal::DynamicArray<types::ScopeId> children, bool can_throw, JaktInternal::Optional<DeprecatedString> import_path_if_extern, JaktInternal::Optional<JaktInternal::DynamicArray<types::ResolvedNamespace>> alias_path, JaktInternal::DynamicArray<parser::IncludeAction> after_extern_include, JaktInternal::DynamicArray<parser::IncludeAction> before_extern_include, DeprecatedString debug_name, JaktInternal::DynamicArray<types::ScopeId> resolution_mixins) { auto o = TRY(adopt_nonnull_ref_or_enomem(new (nothrow) Scope (move(namespace_name), move(external_name), move(vars), move(comptime_bindings), move(structs), move(functions), move(enums), move(types), move(traits), move(imports), move(aliases), move(parent), move(alias_scope), move(children), move(can_throw), move(import_path_if_extern), move(alias_path), move(after_extern_include), move(before_extern_include), move(debug_name), move(resolution_mixins)))); return o; }
ErrorOr<DeprecatedString> types::TypeId::debug_description() const { auto builder = MUST(DeprecatedStringBuilder::create());TRY(builder.append("TypeId("sv));{
JaktInternal::PrettyPrint::ScopedLevelIncrease increase_indent {};
TRY(JaktInternal::PrettyPrint::output_indentation(builder));TRY(builder.append("module: "sv));TRY(builder.appendff("{}, ", module));
TRY(JaktInternal::PrettyPrint::output_indentation(builder));TRY(builder.append("id: "sv));TRY(builder.appendff("{}", id));
}
TRY(builder.append(")"sv));return builder.to_string(); }
ErrorOr<DeprecatedString> types::TypeId::to_string() const {
{
return (TRY((__jakt_format(Jakt::DeprecatedString("{}_{}"sv),((((*this).module)).id),((*this).id)))));
}
}

JaktInternal::Optional<types::TypeId> types::TypeId::none() {
{
return (JaktInternal::OptionalNone());
}
}

bool types::TypeId::equals(types::TypeId const rhs) const {
{
return (((((((*this).module)).id) == ((((rhs).module)).id)) && (((*this).id) == ((rhs).id))));
}
}

types::TypeId::TypeId(types::ModuleId a_module, size_t a_id) :module(a_module), id(a_id){}

ErrorOr<types::TypeId> types::TypeId::from_string(DeprecatedString const type_id_string) {
{
JaktInternal::DynamicArray<DeprecatedString> const parts = ((type_id_string).split('_'));
if ((!((((parts).size()) == static_cast<size_t>(2ULL))))){
utility::panic(TRY((__jakt_format(Jakt::DeprecatedString("Failed to convert string ‘{}’ to a TypeId: Wrong number of parts. (Wanted 2, got {})"sv),type_id_string,((parts).size())))));
}
JaktInternal::Optional<u32> const module_id = ((((parts)[static_cast<i64>(0LL)])).to_uint());
JaktInternal::Optional<u32> const type_id = ((((parts)[static_cast<i64>(1LL)])).to_uint());
if (((!(((module_id).has_value()))) || (!(((type_id).has_value()))))){
utility::panic(TRY((__jakt_format(Jakt::DeprecatedString("Failed to convert string ‘{}’ to a TypeId. (module_id = {} ({}), type_id = {} ({}))"sv),type_id_string,module_id,((parts)[static_cast<i64>(0LL)]),type_id,((parts)[static_cast<i64>(1LL)])))));
}
return (types::TypeId(types::ModuleId((infallible_integer_cast<size_t>((((module_id).value()))))),(infallible_integer_cast<size_t>((((type_id).value()))))));
}
}

ErrorOr<DeprecatedString> types::FieldRecord::debug_description() const { auto builder = MUST(DeprecatedStringBuilder::create());TRY(builder.append("FieldRecord("sv));{
JaktInternal::PrettyPrint::ScopedLevelIncrease increase_indent {};
TRY(JaktInternal::PrettyPrint::output_indentation(builder));TRY(builder.append("struct_id: "sv));TRY(builder.appendff("{}, ", struct_id));
TRY(JaktInternal::PrettyPrint::output_indentation(builder));TRY(builder.append("field_id: "sv));TRY(builder.appendff("{}", field_id));
}
TRY(builder.append(")"sv));return builder.to_string(); }
types::FieldRecord::FieldRecord(types::StructId a_struct_id, types::VarId a_field_id) :struct_id(a_struct_id), field_id(a_field_id){}

ErrorOr<DeprecatedString> types::ModuleId::debug_description() const { auto builder = MUST(DeprecatedStringBuilder::create());TRY(builder.append("ModuleId("sv));{
JaktInternal::PrettyPrint::ScopedLevelIncrease increase_indent {};
TRY(JaktInternal::PrettyPrint::output_indentation(builder));TRY(builder.append("id: "sv));TRY(builder.appendff("{}", id));
}
TRY(builder.append(")"sv));return builder.to_string(); }
types::ModuleId::ModuleId(size_t a_id) :id(a_id){}

bool types::ModuleId::equals(types::ModuleId const rhs) const {
{
return ((((*this).id) == ((rhs).id)));
}
}

ErrorOr<DeprecatedString> types::CheckedEnumVariantBinding::debug_description() const { auto builder = MUST(DeprecatedStringBuilder::create());TRY(builder.append("CheckedEnumVariantBinding("sv));{
JaktInternal::PrettyPrint::ScopedLevelIncrease increase_indent {};
TRY(JaktInternal::PrettyPrint::output_indentation(builder));TRY(builder.append("name: "sv));TRY(builder.appendff("{}, ", name));
TRY(JaktInternal::PrettyPrint::output_indentation(builder));TRY(builder.append("binding: "sv));TRY(builder.appendff("\"{}\", ", binding));
TRY(JaktInternal::PrettyPrint::output_indentation(builder));TRY(builder.append("type_id: "sv));TRY(builder.appendff("{}, ", type_id));
TRY(JaktInternal::PrettyPrint::output_indentation(builder));TRY(builder.append("span: "sv));TRY(builder.appendff("{}", span));
}
TRY(builder.append(")"sv));return builder.to_string(); }
types::CheckedEnumVariantBinding::CheckedEnumVariantBinding(JaktInternal::Optional<DeprecatedString> a_name, DeprecatedString a_binding, types::TypeId a_type_id, utility::Span a_span) :name(a_name), binding(a_binding), type_id(a_type_id), span(a_span){}

ErrorOr<DeprecatedString> types::CheckedField::debug_description() const { auto builder = MUST(DeprecatedStringBuilder::create());TRY(builder.append("CheckedField("sv));{
JaktInternal::PrettyPrint::ScopedLevelIncrease increase_indent {};
TRY(JaktInternal::PrettyPrint::output_indentation(builder));TRY(builder.append("variable_id: "sv));TRY(builder.appendff("{}, ", variable_id));
TRY(JaktInternal::PrettyPrint::output_indentation(builder));TRY(builder.append("default_value: "sv));TRY(builder.appendff("{}, ", default_value));
TRY(JaktInternal::PrettyPrint::output_indentation(builder));TRY(builder.append("default_value_expression: "sv));TRY(builder.appendff("{}", default_value_expression));
}
TRY(builder.append(")"sv));return builder.to_string(); }
types::CheckedField::CheckedField(types::VarId a_variable_id, JaktInternal::Optional<NonnullRefPtr<typename types::CheckedExpression>> a_default_value, JaktInternal::Optional<NonnullRefPtr<typename parser::ParsedExpression>> a_default_value_expression) :variable_id(a_variable_id), default_value(a_default_value), default_value_expression(a_default_value_expression){}

ErrorOr<DeprecatedString> types::FunctionGenericParameterKind::debug_description() const {
auto builder = TRY(DeprecatedStringBuilder::create());
switch (this->index()) {case 0 /* InferenceGuide */: {
[[maybe_unused]] auto const& that = this->template get<FunctionGenericParameterKind::InferenceGuide>();
TRY(builder.append("FunctionGenericParameterKind::InferenceGuide"sv));
break;}
case 1 /* Parameter */: {
[[maybe_unused]] auto const& that = this->template get<FunctionGenericParameterKind::Parameter>();
TRY(builder.append("FunctionGenericParameterKind::Parameter"sv));
break;}
}
return builder.to_string();
}
ErrorOr<DeprecatedString> types::Type::debug_description() const {
auto builder = TRY(DeprecatedStringBuilder::create());
switch (this->index()) {case 0 /* Void */: {
[[maybe_unused]] auto const& that = this->template get<Type::Void>();
TRY(builder.append("Type::Void"sv));
break;}
case 1 /* Bool */: {
[[maybe_unused]] auto const& that = this->template get<Type::Bool>();
TRY(builder.append("Type::Bool"sv));
break;}
case 2 /* U8 */: {
[[maybe_unused]] auto const& that = this->template get<Type::U8>();
TRY(builder.append("Type::U8"sv));
break;}
case 3 /* U16 */: {
[[maybe_unused]] auto const& that = this->template get<Type::U16>();
TRY(builder.append("Type::U16"sv));
break;}
case 4 /* U32 */: {
[[maybe_unused]] auto const& that = this->template get<Type::U32>();
TRY(builder.append("Type::U32"sv));
break;}
case 5 /* U64 */: {
[[maybe_unused]] auto const& that = this->template get<Type::U64>();
TRY(builder.append("Type::U64"sv));
break;}
case 6 /* I8 */: {
[[maybe_unused]] auto const& that = this->template get<Type::I8>();
TRY(builder.append("Type::I8"sv));
break;}
case 7 /* I16 */: {
[[maybe_unused]] auto const& that = this->template get<Type::I16>();
TRY(builder.append("Type::I16"sv));
break;}
case 8 /* I32 */: {
[[maybe_unused]] auto const& that = this->template get<Type::I32>();
TRY(builder.append("Type::I32"sv));
break;}
case 9 /* I64 */: {
[[maybe_unused]] auto const& that = this->template get<Type::I64>();
TRY(builder.append("Type::I64"sv));
break;}
case 10 /* F32 */: {
[[maybe_unused]] auto const& that = this->template get<Type::F32>();
TRY(builder.append("Type::F32"sv));
break;}
case 11 /* F64 */: {
[[maybe_unused]] auto const& that = this->template get<Type::F64>();
TRY(builder.append("Type::F64"sv));
break;}
case 12 /* Usize */: {
[[maybe_unused]] auto const& that = this->template get<Type::Usize>();
TRY(builder.append("Type::Usize"sv));
break;}
case 13 /* JaktString */: {
[[maybe_unused]] auto const& that = this->template get<Type::JaktString>();
TRY(builder.append("Type::JaktString"sv));
break;}
case 14 /* CChar */: {
[[maybe_unused]] auto const& that = this->template get<Type::CChar>();
TRY(builder.append("Type::CChar"sv));
break;}
case 15 /* CInt */: {
[[maybe_unused]] auto const& that = this->template get<Type::CInt>();
TRY(builder.append("Type::CInt"sv));
break;}
case 16 /* Unknown */: {
[[maybe_unused]] auto const& that = this->template get<Type::Unknown>();
TRY(builder.append("Type::Unknown"sv));
break;}
case 17 /* Never */: {
[[maybe_unused]] auto const& that = this->template get<Type::Never>();
TRY(builder.append("Type::Never"sv));
break;}
case 18 /* TypeVariable */: {
[[maybe_unused]] auto const& that = this->template get<Type::TypeVariable>();
TRY(builder.append("Type::TypeVariable"sv));
TRY(builder.append("("sv));
{
JaktInternal::PrettyPrint::ScopedLevelIncrease increase_indent {};
TRY(JaktInternal::PrettyPrint::output_indentation(builder));
TRY(builder.appendff("name: \"{}\"", that.name));
TRY(builder.append(", "sv));
TRY(JaktInternal::PrettyPrint::output_indentation(builder));
TRY(builder.appendff("trait_implementations: {}", that.trait_implementations));
}
TRY(builder.append(")"sv));
break;}
case 19 /* GenericInstance */: {
[[maybe_unused]] auto const& that = this->template get<Type::GenericInstance>();
TRY(builder.append("Type::GenericInstance"sv));
TRY(builder.append("("sv));
{
JaktInternal::PrettyPrint::ScopedLevelIncrease increase_indent {};
TRY(JaktInternal::PrettyPrint::output_indentation(builder));
TRY(builder.appendff("id: {}", that.id));
TRY(builder.append(", "sv));
TRY(JaktInternal::PrettyPrint::output_indentation(builder));
TRY(builder.appendff("args: {}", that.args));
}
TRY(builder.append(")"sv));
break;}
case 20 /* GenericEnumInstance */: {
[[maybe_unused]] auto const& that = this->template get<Type::GenericEnumInstance>();
TRY(builder.append("Type::GenericEnumInstance"sv));
TRY(builder.append("("sv));
{
JaktInternal::PrettyPrint::ScopedLevelIncrease increase_indent {};
TRY(JaktInternal::PrettyPrint::output_indentation(builder));
TRY(builder.appendff("id: {}", that.id));
TRY(builder.append(", "sv));
TRY(JaktInternal::PrettyPrint::output_indentation(builder));
TRY(builder.appendff("args: {}", that.args));
}
TRY(builder.append(")"sv));
break;}
case 21 /* GenericTraitInstance */: {
[[maybe_unused]] auto const& that = this->template get<Type::GenericTraitInstance>();
TRY(builder.append("Type::GenericTraitInstance"sv));
TRY(builder.append("("sv));
{
JaktInternal::PrettyPrint::ScopedLevelIncrease increase_indent {};
TRY(JaktInternal::PrettyPrint::output_indentation(builder));
TRY(builder.appendff("id: {}", that.id));
TRY(builder.append(", "sv));
TRY(JaktInternal::PrettyPrint::output_indentation(builder));
TRY(builder.appendff("args: {}", that.args));
}
TRY(builder.append(")"sv));
break;}
case 22 /* GenericResolvedType */: {
[[maybe_unused]] auto const& that = this->template get<Type::GenericResolvedType>();
TRY(builder.append("Type::GenericResolvedType"sv));
TRY(builder.append("("sv));
{
JaktInternal::PrettyPrint::ScopedLevelIncrease increase_indent {};
TRY(JaktInternal::PrettyPrint::output_indentation(builder));
TRY(builder.appendff("id: {}", that.id));
TRY(builder.append(", "sv));
TRY(JaktInternal::PrettyPrint::output_indentation(builder));
TRY(builder.appendff("args: {}", that.args));
}
TRY(builder.append(")"sv));
break;}
case 23 /* Struct */: {
[[maybe_unused]] auto const& that = this->template get<Type::Struct>();
TRY(builder.append("Type::Struct"sv));
TRY(builder.appendff("({})", that.value));
break;}
case 24 /* Enum */: {
[[maybe_unused]] auto const& that = this->template get<Type::Enum>();
TRY(builder.append("Type::Enum"sv));
TRY(builder.appendff("({})", that.value));
break;}
case 25 /* RawPtr */: {
[[maybe_unused]] auto const& that = this->template get<Type::RawPtr>();
TRY(builder.append("Type::RawPtr"sv));
TRY(builder.appendff("({})", that.value));
break;}
case 26 /* Trait */: {
[[maybe_unused]] auto const& that = this->template get<Type::Trait>();
TRY(builder.append("Type::Trait"sv));
TRY(builder.appendff("({})", that.value));
break;}
case 27 /* Reference */: {
[[maybe_unused]] auto const& that = this->template get<Type::Reference>();
TRY(builder.append("Type::Reference"sv));
TRY(builder.appendff("({})", that.value));
break;}
case 28 /* MutableReference */: {
[[maybe_unused]] auto const& that = this->template get<Type::MutableReference>();
TRY(builder.append("Type::MutableReference"sv));
TRY(builder.appendff("({})", that.value));
break;}
case 29 /* Function */: {
[[maybe_unused]] auto const& that = this->template get<Type::Function>();
TRY(builder.append("Type::Function"sv));
TRY(builder.append("("sv));
{
JaktInternal::PrettyPrint::ScopedLevelIncrease increase_indent {};
TRY(JaktInternal::PrettyPrint::output_indentation(builder));
TRY(builder.appendff("params: {}", that.params));
TRY(builder.append(", "sv));
TRY(JaktInternal::PrettyPrint::output_indentation(builder));
TRY(builder.appendff("can_throw: {}", that.can_throw));
TRY(builder.append(", "sv));
TRY(JaktInternal::PrettyPrint::output_indentation(builder));
TRY(builder.appendff("return_type_id: {}", that.return_type_id));
TRY(builder.append(", "sv));
TRY(JaktInternal::PrettyPrint::output_indentation(builder));
TRY(builder.appendff("pseudo_function_id: {}", that.pseudo_function_id));
}
TRY(builder.append(")"sv));
break;}
case 30 /* Self */: {
[[maybe_unused]] auto const& that = this->template get<Type::Self>();
TRY(builder.append("Type::Self"sv));
break;}
}
return builder.to_string();
}
bool types::Type::equals(NonnullRefPtr<typename types::Type> const rhs) const {
{
if ((((*this).index() == 0 /* Void */) && ((rhs)->index() == 0 /* Void */))){
return (true);
}
else if ((((*this).index() == 1 /* Bool */) && ((rhs)->index() == 1 /* Bool */))){
return (true);
}
else if ((((*this).index() == 2 /* U8 */) && ((rhs)->index() == 2 /* U8 */))){
return (true);
}
else if ((((*this).index() == 3 /* U16 */) && ((rhs)->index() == 3 /* U16 */))){
return (true);
}
else if ((((*this).index() == 4 /* U32 */) && ((rhs)->index() == 4 /* U32 */))){
return (true);
}
else if ((((*this).index() == 5 /* U64 */) && ((rhs)->index() == 5 /* U64 */))){
return (true);
}
else if ((((*this).index() == 6 /* I8 */) && ((rhs)->index() == 6 /* I8 */))){
return (true);
}
else if ((((*this).index() == 7 /* I16 */) && ((rhs)->index() == 7 /* I16 */))){
return (true);
}
else if ((((*this).index() == 8 /* I32 */) && ((rhs)->index() == 8 /* I32 */))){
return (true);
}
else if ((((*this).index() == 9 /* I64 */) && ((rhs)->index() == 9 /* I64 */))){
return (true);
}
else if ((((*this).index() == 10 /* F32 */) && ((rhs)->index() == 10 /* F32 */))){
return (true);
}
else if ((((*this).index() == 11 /* F64 */) && ((rhs)->index() == 11 /* F64 */))){
return (true);
}
else if ((((*this).index() == 12 /* Usize */) && ((rhs)->index() == 12 /* Usize */))){
return (true);
}
else if ((((*this).index() == 13 /* JaktString */) && ((rhs)->index() == 13 /* JaktString */))){
return (true);
}
else if ((((*this).index() == 14 /* CChar */) && ((rhs)->index() == 14 /* CChar */))){
return (true);
}
else if ((((*this).index() == 15 /* CInt */) && ((rhs)->index() == 15 /* CInt */))){
return (true);
}
else if ((((*this).index() == 30 /* Self */) && ((rhs)->index() == 30 /* Self */))){
return (true);
}
JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<void, bool>{
auto&& __jakt_match_variant = *this;
switch(__jakt_match_variant.index()) {
case 18: {
auto&& __jakt_match_value = __jakt_match_variant.template get<types::Type::TypeVariable>();DeprecatedString const& lhs_name = __jakt_match_value.name;
{
if (((rhs)->index() == 18 /* TypeVariable */)){
DeprecatedString const rhs_name = ((rhs)->get<types::Type::TypeVariable>()).name;
return ((lhs_name == rhs_name));
}
else {
return (false);
}

}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 19: {
auto&& __jakt_match_value = __jakt_match_variant.template get<types::Type::GenericInstance>();types::StructId const& lhs_id = __jakt_match_value.id;
JaktInternal::DynamicArray<types::TypeId> const& lhs_args = __jakt_match_value.args;
{
if (((rhs)->index() == 19 /* GenericInstance */)){
types::StructId const rhs_id = ((rhs)->get<types::Type::GenericInstance>()).id;
JaktInternal::DynamicArray<types::TypeId> const rhs_args = ((rhs)->get<types::Type::GenericInstance>()).args;
if ((((lhs_id).equals(rhs_id)) && (((lhs_args).size()) == ((rhs_args).size())))){
size_t idx = static_cast<size_t>(0ULL);
while ((idx < ((lhs_args).size()))){
if ((!(((((lhs_args)[idx])).equals(((rhs_args)[idx])))))){
return (false);
}
((idx++));
}
return (true);
}
else {
return (false);
}

}
else {
return (false);
}

}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 21: {
auto&& __jakt_match_value = __jakt_match_variant.template get<types::Type::GenericTraitInstance>();types::TraitId const& lhs_id = __jakt_match_value.id;
JaktInternal::DynamicArray<types::TypeId> const& lhs_args = __jakt_match_value.args;
{
if (((rhs)->index() == 21 /* GenericTraitInstance */)){
types::TraitId const rhs_id = ((rhs)->get<types::Type::GenericTraitInstance>()).id;
JaktInternal::DynamicArray<types::TypeId> const rhs_args = ((rhs)->get<types::Type::GenericTraitInstance>()).args;
if ((((lhs_id).equals(rhs_id)) && (((lhs_args).size()) == ((rhs_args).size())))){
size_t idx = static_cast<size_t>(0ULL);
while ((idx < ((lhs_args).size()))){
if ((!(((((lhs_args)[idx])).equals(((rhs_args)[idx])))))){
return (false);
}
((idx++));
}
return (true);
}
else {
return (false);
}

}
else {
return (false);
}

}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 20: {
auto&& __jakt_match_value = __jakt_match_variant.template get<types::Type::GenericEnumInstance>();types::EnumId const& lhs_id = __jakt_match_value.id;
JaktInternal::DynamicArray<types::TypeId> const& lhs_args = __jakt_match_value.args;
{
if (((rhs)->index() == 20 /* GenericEnumInstance */)){
types::EnumId const rhs_id = ((rhs)->get<types::Type::GenericEnumInstance>()).id;
JaktInternal::DynamicArray<types::TypeId> const rhs_args = ((rhs)->get<types::Type::GenericEnumInstance>()).args;
if ((((lhs_id).equals(rhs_id)) && (((lhs_args).size()) == ((rhs_args).size())))){
size_t idx = static_cast<size_t>(0ULL);
while ((idx < ((lhs_args).size()))){
if ((!(((((lhs_args)[idx])).equals(((rhs_args)[idx])))))){
return (false);
}
((idx++));
}
return (true);
}
else {
return (false);
}

}
else {
return (false);
}

}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 23: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::Type::Struct>();
types::StructId const& lhs_id = __jakt_match_value.value;
{
if (((rhs)->index() == 23 /* Struct */)){
types::StructId const rhs_id = ((rhs)->get<types::Type::Struct>()).value;
return (((lhs_id).equals(rhs_id)));
}
return (false);
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 24: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::Type::Enum>();
types::EnumId const& lhs_id = __jakt_match_value.value;
{
if (((rhs)->index() == 24 /* Enum */)){
types::EnumId const rhs_id = ((rhs)->get<types::Type::Enum>()).value;
return (((lhs_id).equals(rhs_id)));
}
else {
return (false);
}

}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 25: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::Type::RawPtr>();
types::TypeId const& lhs_id = __jakt_match_value.value;
{
if (((rhs)->index() == 25 /* RawPtr */)){
types::TypeId const rhs_id = ((rhs)->get<types::Type::RawPtr>()).value;
return (((lhs_id).equals(rhs_id)));
}
else {
return (false);
}

}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 27: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::Type::Reference>();
types::TypeId const& lhs_id = __jakt_match_value.value;
{
if (((rhs)->index() == 27 /* Reference */)){
types::TypeId const rhs_id = ((rhs)->get<types::Type::Reference>()).value;
return (((lhs_id).equals(rhs_id)));
}
else {
return (false);
}

}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 28: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::Type::MutableReference>();
types::TypeId const& lhs_id = __jakt_match_value.value;
{
if (((rhs)->index() == 28 /* MutableReference */)){
types::TypeId const rhs_id = ((rhs)->get<types::Type::MutableReference>()).value;
return (((lhs_id).equals(rhs_id)));
}
else {
return (false);
}

}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 26: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::Type::Trait>();
types::TraitId const& lhs_id = __jakt_match_value.value;
{
if (((rhs)->index() == 26 /* Trait */)){
types::TraitId const rhs_id = ((rhs)->get<types::Type::Trait>()).value;
return (((lhs_id).equals(rhs_id)));
}
else {
return (false);
}

}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 29: {
auto&& __jakt_match_value = __jakt_match_variant.template get<types::Type::Function>();JaktInternal::DynamicArray<types::TypeId> const& params = __jakt_match_value.params;
bool const& can_throw = __jakt_match_value.can_throw;
types::TypeId const& return_type_id = __jakt_match_value.return_type_id;
{
if (((rhs)->index() == 29 /* Function */)){
JaktInternal::DynamicArray<types::TypeId> const rhs_params = ((rhs)->get<types::Type::Function>()).params;
bool const rhs_can_throw = ((rhs)->get<types::Type::Function>()).can_throw;
types::TypeId const rhs_return_type_id = ((rhs)->get<types::Type::Function>()).return_type_id;
if (((((params).size()) == ((rhs_params).size())) && (((return_type_id).equals(rhs_return_type_id)) && (can_throw == rhs_can_throw)))){
{
JaktInternal::Range<size_t> _magic = (JaktInternal::Range<size_t>{static_cast<size_t>(static_cast<size_t>(0ULL)),static_cast<size_t>(((params).size()))});
for (;;){
JaktInternal::Optional<size_t> _magic_value = ((_magic).next());
if ((!(((_magic_value).has_value())))){
break;
}
size_t i = (_magic_value.value());
{
if ((!(((((params)[i])).equals(((rhs_params)[i])))))){
return (false);
}
}

}
}

return (true);
}
else {
return (false);
}

}
else {
return (false);
}

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
return (false);
}
}

i64 types::Type::get_bits() const {
{
return (JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<i64, i64>{
auto&& __jakt_match_variant = *this;
switch(__jakt_match_variant.index()) {
case 2: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::Type::U8>();
return JaktInternal::ExplicitValue(static_cast<i64>(8LL));
};/*case end*/
case 6: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::Type::I8>();
return JaktInternal::ExplicitValue(static_cast<i64>(8LL));
};/*case end*/
case 14: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::Type::CChar>();
return JaktInternal::ExplicitValue(static_cast<i64>(8LL));
};/*case end*/
case 3: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::Type::U16>();
return JaktInternal::ExplicitValue(static_cast<i64>(16LL));
};/*case end*/
case 7: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::Type::I16>();
return JaktInternal::ExplicitValue(static_cast<i64>(16LL));
};/*case end*/
case 4: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::Type::U32>();
return JaktInternal::ExplicitValue(static_cast<i64>(32LL));
};/*case end*/
case 8: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::Type::I32>();
return JaktInternal::ExplicitValue(static_cast<i64>(32LL));
};/*case end*/
case 15: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::Type::CInt>();
return JaktInternal::ExplicitValue(static_cast<i64>(32LL));
};/*case end*/
case 5: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::Type::U64>();
return JaktInternal::ExplicitValue(static_cast<i64>(64LL));
};/*case end*/
case 9: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::Type::I64>();
return JaktInternal::ExplicitValue(static_cast<i64>(64LL));
};/*case end*/
case 12: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::Type::Usize>();
return JaktInternal::ExplicitValue(static_cast<i64>(64LL));
};/*case end*/
case 10: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::Type::F32>();
return JaktInternal::ExplicitValue(static_cast<i64>(32LL));
};/*case end*/
case 11: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::Type::F64>();
return JaktInternal::ExplicitValue(static_cast<i64>(64LL));
};/*case end*/
default: {
return JaktInternal::ExplicitValue(static_cast<i64>(0LL));
};/*case end*/
}/*switch end*/
}()
)));
}
}

i64 types::Type::specificity(NonnullRefPtr<types::CheckedProgram> const program,i64 const base_specificity) const {
{
return (JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<i64, i64>{
auto&& __jakt_match_variant = *this;
switch(__jakt_match_variant.index()) {
case 18: {
auto&& __jakt_match_value = __jakt_match_variant.template get<types::Type::TypeVariable>();return JaktInternal::ExplicitValue(static_cast<i64>(0LL));
};/*case end*/
case 19: {
auto&& __jakt_match_value = __jakt_match_variant.template get<types::Type::GenericInstance>();JaktInternal::DynamicArray<types::TypeId> const& args = __jakt_match_value.args;
return JaktInternal::ExplicitValue(({ Optional<i64> __jakt_var_125; {
i64 specificity = (JaktInternal::checked_div<i64>(base_specificity,static_cast<i64>(2LL)));
{
JaktInternal::ArrayIterator<types::TypeId> _magic = ((args).iterator());
for (;;){
JaktInternal::Optional<types::TypeId> _magic_value = ((_magic).next());
if ((!(((_magic_value).has_value())))){
break;
}
types::TypeId subtype_id = (_magic_value.value());
{
NonnullRefPtr<typename types::Type> const subtype = ((program)->get_type(subtype_id));
({auto& _jakt_ref = specificity;_jakt_ref = JaktInternal::checked_add<i64>(_jakt_ref, ((subtype)->specificity(program,(JaktInternal::checked_div<i64>(base_specificity,static_cast<i64>(4LL))))));});
}

}
}

__jakt_var_125 = specificity; goto __jakt_label_122;

}
__jakt_label_122:; __jakt_var_125.release_value(); }));
};/*case end*/
case 20: {
auto&& __jakt_match_value = __jakt_match_variant.template get<types::Type::GenericEnumInstance>();JaktInternal::DynamicArray<types::TypeId> const& args = __jakt_match_value.args;
return JaktInternal::ExplicitValue(({ Optional<i64> __jakt_var_126; {
i64 specificity = (JaktInternal::checked_div<i64>(base_specificity,static_cast<i64>(2LL)));
{
JaktInternal::ArrayIterator<types::TypeId> _magic = ((args).iterator());
for (;;){
JaktInternal::Optional<types::TypeId> _magic_value = ((_magic).next());
if ((!(((_magic_value).has_value())))){
break;
}
types::TypeId subtype_id = (_magic_value.value());
{
NonnullRefPtr<typename types::Type> const subtype = ((program)->get_type(subtype_id));
({auto& _jakt_ref = specificity;_jakt_ref = JaktInternal::checked_add<i64>(_jakt_ref, ((subtype)->specificity(program,(JaktInternal::checked_div<i64>(base_specificity,static_cast<i64>(4LL))))));});
}

}
}

__jakt_var_126 = specificity; goto __jakt_label_123;

}
__jakt_label_123:; __jakt_var_126.release_value(); }));
};/*case end*/
case 22: {
auto&& __jakt_match_value = __jakt_match_variant.template get<types::Type::GenericResolvedType>();JaktInternal::DynamicArray<types::TypeId> const& args = __jakt_match_value.args;
return JaktInternal::ExplicitValue(({ Optional<i64> __jakt_var_127; {
i64 specificity = (JaktInternal::checked_div<i64>(base_specificity,static_cast<i64>(2LL)));
{
JaktInternal::ArrayIterator<types::TypeId> _magic = ((args).iterator());
for (;;){
JaktInternal::Optional<types::TypeId> _magic_value = ((_magic).next());
if ((!(((_magic_value).has_value())))){
break;
}
types::TypeId subtype_id = (_magic_value.value());
{
NonnullRefPtr<typename types::Type> const subtype = ((program)->get_type(subtype_id));
({auto& _jakt_ref = specificity;_jakt_ref = JaktInternal::checked_add<i64>(_jakt_ref, ((subtype)->specificity(program,(JaktInternal::checked_div<i64>(base_specificity,static_cast<i64>(4LL))))));});
}

}
}

__jakt_var_127 = specificity; goto __jakt_label_124;

}
__jakt_label_124:; __jakt_var_127.release_value(); }));
};/*case end*/
case 29: {
auto&& __jakt_match_value = __jakt_match_variant.template get<types::Type::Function>();JaktInternal::DynamicArray<types::TypeId> const& params = __jakt_match_value.params;
return JaktInternal::ExplicitValue(({ Optional<i64> __jakt_var_128; {
i64 specificity = (JaktInternal::checked_div<i64>(base_specificity,static_cast<i64>(2LL)));
{
JaktInternal::ArrayIterator<types::TypeId> _magic = ((params).iterator());
for (;;){
JaktInternal::Optional<types::TypeId> _magic_value = ((_magic).next());
if ((!(((_magic_value).has_value())))){
break;
}
types::TypeId subtype_id = (_magic_value.value());
{
NonnullRefPtr<typename types::Type> const subtype = ((program)->get_type(subtype_id));
({auto& _jakt_ref = specificity;_jakt_ref = JaktInternal::checked_add<i64>(_jakt_ref, ((subtype)->specificity(program,(JaktInternal::checked_div<i64>(base_specificity,static_cast<i64>(4LL))))));});
}

}
}

__jakt_var_128 = specificity; goto __jakt_label_125;

}
__jakt_label_125:; __jakt_var_128.release_value(); }));
};/*case end*/
default: {
return JaktInternal::ExplicitValue(base_specificity);
};/*case end*/
}/*switch end*/
}()
)));
}
}

bool types::Type::is_concrete() const {
{
return (JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<bool, bool>{
auto&& __jakt_match_variant = *this;
switch(__jakt_match_variant.index()) {
case 18: {
auto&& __jakt_match_value = __jakt_match_variant.template get<types::Type::TypeVariable>();return JaktInternal::ExplicitValue(false);
};/*case end*/
case 30: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::Type::Self>();
return JaktInternal::ExplicitValue(false);
};/*case end*/
case 16: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::Type::Unknown>();
return JaktInternal::ExplicitValue(false);
};/*case end*/
default: {
return JaktInternal::ExplicitValue(true);
};/*case end*/
}/*switch end*/
}()
)));
}
}

bool types::Type::is_builtin() const {
{
return (JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<bool, bool>{
auto&& __jakt_match_variant = *this;
switch(__jakt_match_variant.index()) {
case 0: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::Type::Void>();
return JaktInternal::ExplicitValue(true);
};/*case end*/
case 1: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::Type::Bool>();
return JaktInternal::ExplicitValue(true);
};/*case end*/
case 2: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::Type::U8>();
return JaktInternal::ExplicitValue(true);
};/*case end*/
case 3: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::Type::U16>();
return JaktInternal::ExplicitValue(true);
};/*case end*/
case 4: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::Type::U32>();
return JaktInternal::ExplicitValue(true);
};/*case end*/
case 5: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::Type::U64>();
return JaktInternal::ExplicitValue(true);
};/*case end*/
case 6: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::Type::I8>();
return JaktInternal::ExplicitValue(true);
};/*case end*/
case 7: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::Type::I16>();
return JaktInternal::ExplicitValue(true);
};/*case end*/
case 8: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::Type::I32>();
return JaktInternal::ExplicitValue(true);
};/*case end*/
case 9: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::Type::I64>();
return JaktInternal::ExplicitValue(true);
};/*case end*/
case 10: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::Type::F32>();
return JaktInternal::ExplicitValue(true);
};/*case end*/
case 11: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::Type::F64>();
return JaktInternal::ExplicitValue(true);
};/*case end*/
case 12: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::Type::Usize>();
return JaktInternal::ExplicitValue(true);
};/*case end*/
case 13: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::Type::JaktString>();
return JaktInternal::ExplicitValue(true);
};/*case end*/
case 14: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::Type::CChar>();
return JaktInternal::ExplicitValue(true);
};/*case end*/
case 15: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::Type::CInt>();
return JaktInternal::ExplicitValue(true);
};/*case end*/
default: {
return JaktInternal::ExplicitValue(false);
};/*case end*/
}/*switch end*/
}()
)));
}
}

ErrorOr<types::TypeId> types::Type::flip_signedness() const {
{
return (JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<types::TypeId, ErrorOr<types::TypeId>>{
auto&& __jakt_match_variant = *this;
switch(__jakt_match_variant.index()) {
case 6: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::Type::I8>();
return JaktInternal::ExplicitValue(types::builtin( types::BuiltinType { typename types::BuiltinType::U8() } ));
};/*case end*/
case 7: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::Type::I16>();
return JaktInternal::ExplicitValue(types::builtin( types::BuiltinType { typename types::BuiltinType::U16() } ));
};/*case end*/
case 8: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::Type::I32>();
return JaktInternal::ExplicitValue(types::builtin( types::BuiltinType { typename types::BuiltinType::U32() } ));
};/*case end*/
case 9: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::Type::I64>();
return JaktInternal::ExplicitValue(types::builtin( types::BuiltinType { typename types::BuiltinType::U64() } ));
};/*case end*/
case 2: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::Type::U8>();
return JaktInternal::ExplicitValue(types::builtin( types::BuiltinType { typename types::BuiltinType::I8() } ));
};/*case end*/
case 3: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::Type::U16>();
return JaktInternal::ExplicitValue(types::builtin( types::BuiltinType { typename types::BuiltinType::I16() } ));
};/*case end*/
case 4: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::Type::U32>();
return JaktInternal::ExplicitValue(types::builtin( types::BuiltinType { typename types::BuiltinType::I32() } ));
};/*case end*/
case 5: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::Type::U64>();
return JaktInternal::ExplicitValue(types::builtin( types::BuiltinType { typename types::BuiltinType::I64() } ));
};/*case end*/
default: {
return JaktInternal::ExplicitValue(types::builtin( types::BuiltinType { typename types::BuiltinType::Unknown() } ));
};/*case end*/
}/*switch end*/
}()
)));
}
}

u64 types::Type::max() const {
{
return (JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<u64, u64>{
auto&& __jakt_match_variant = *this;
switch(__jakt_match_variant.index()) {
case 14: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::Type::CChar>();
return JaktInternal::ExplicitValue(static_cast<u64>(127ULL));
};/*case end*/
case 15: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::Type::CInt>();
return JaktInternal::ExplicitValue(static_cast<u64>(2147483647ULL));
};/*case end*/
case 6: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::Type::I8>();
return JaktInternal::ExplicitValue(static_cast<u64>(127ULL));
};/*case end*/
case 7: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::Type::I16>();
return JaktInternal::ExplicitValue(static_cast<u64>(32767ULL));
};/*case end*/
case 8: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::Type::I32>();
return JaktInternal::ExplicitValue(static_cast<u64>(2147483647ULL));
};/*case end*/
case 9: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::Type::I64>();
return JaktInternal::ExplicitValue(static_cast<u64>(9223372036854775807ULL));
};/*case end*/
case 2: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::Type::U8>();
return JaktInternal::ExplicitValue(static_cast<u64>(255ULL));
};/*case end*/
case 3: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::Type::U16>();
return JaktInternal::ExplicitValue(static_cast<u64>(65535ULL));
};/*case end*/
case 4: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::Type::U32>();
return JaktInternal::ExplicitValue(static_cast<u64>(4294967295ULL));
};/*case end*/
case 5: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::Type::U64>();
return JaktInternal::ExplicitValue(static_cast<u64>(18446744073709551615ULL));
};/*case end*/
case 12: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::Type::Usize>();
return JaktInternal::ExplicitValue(static_cast<u64>(18446744073709551615ULL));
};/*case end*/
default: {
return JaktInternal::ExplicitValue(static_cast<u64>(0ULL));
};/*case end*/
}/*switch end*/
}()
)));
}
}

DeprecatedString types::Type::constructor_name() const {
{
return (JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<DeprecatedString, DeprecatedString>{
auto&& __jakt_match_variant = *this;
switch(__jakt_match_variant.index()) {
case 0: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::Type::Void>();
return JaktInternal::ExplicitValue(Jakt::DeprecatedString("Void"sv));
};/*case end*/
case 1: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::Type::Bool>();
return JaktInternal::ExplicitValue(Jakt::DeprecatedString("Bool"sv));
};/*case end*/
case 2: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::Type::U8>();
return JaktInternal::ExplicitValue(Jakt::DeprecatedString("U8"sv));
};/*case end*/
case 3: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::Type::U16>();
return JaktInternal::ExplicitValue(Jakt::DeprecatedString("U16"sv));
};/*case end*/
case 4: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::Type::U32>();
return JaktInternal::ExplicitValue(Jakt::DeprecatedString("U32"sv));
};/*case end*/
case 5: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::Type::U64>();
return JaktInternal::ExplicitValue(Jakt::DeprecatedString("U64"sv));
};/*case end*/
case 6: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::Type::I8>();
return JaktInternal::ExplicitValue(Jakt::DeprecatedString("I8"sv));
};/*case end*/
case 7: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::Type::I16>();
return JaktInternal::ExplicitValue(Jakt::DeprecatedString("I16"sv));
};/*case end*/
case 8: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::Type::I32>();
return JaktInternal::ExplicitValue(Jakt::DeprecatedString("I32"sv));
};/*case end*/
case 9: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::Type::I64>();
return JaktInternal::ExplicitValue(Jakt::DeprecatedString("I64"sv));
};/*case end*/
case 10: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::Type::F32>();
return JaktInternal::ExplicitValue(Jakt::DeprecatedString("F32"sv));
};/*case end*/
case 11: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::Type::F64>();
return JaktInternal::ExplicitValue(Jakt::DeprecatedString("F64"sv));
};/*case end*/
case 12: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::Type::Usize>();
return JaktInternal::ExplicitValue(Jakt::DeprecatedString("Usize"sv));
};/*case end*/
case 13: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::Type::JaktString>();
return JaktInternal::ExplicitValue(Jakt::DeprecatedString("JaktString"sv));
};/*case end*/
case 14: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::Type::CChar>();
return JaktInternal::ExplicitValue(Jakt::DeprecatedString("CChar"sv));
};/*case end*/
case 15: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::Type::CInt>();
return JaktInternal::ExplicitValue(Jakt::DeprecatedString("CInt"sv));
};/*case end*/
case 16: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::Type::Unknown>();
return JaktInternal::ExplicitValue(Jakt::DeprecatedString("Unknown"sv));
};/*case end*/
case 17: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::Type::Never>();
return JaktInternal::ExplicitValue(Jakt::DeprecatedString("Never"sv));
};/*case end*/
case 18: {
auto&& __jakt_match_value = __jakt_match_variant.template get<types::Type::TypeVariable>();return JaktInternal::ExplicitValue(Jakt::DeprecatedString("TypeVariable"sv));
};/*case end*/
case 19: {
auto&& __jakt_match_value = __jakt_match_variant.template get<types::Type::GenericInstance>();return JaktInternal::ExplicitValue(Jakt::DeprecatedString("GenericInstance"sv));
};/*case end*/
case 20: {
auto&& __jakt_match_value = __jakt_match_variant.template get<types::Type::GenericEnumInstance>();return JaktInternal::ExplicitValue(Jakt::DeprecatedString("GenericEnumInstance"sv));
};/*case end*/
case 21: {
auto&& __jakt_match_value = __jakt_match_variant.template get<types::Type::GenericTraitInstance>();return JaktInternal::ExplicitValue(Jakt::DeprecatedString("GenericTraitInstance"sv));
};/*case end*/
case 22: {
auto&& __jakt_match_value = __jakt_match_variant.template get<types::Type::GenericResolvedType>();return JaktInternal::ExplicitValue(Jakt::DeprecatedString("GenericResolvedType"sv));
};/*case end*/
case 23: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::Type::Struct>();
return JaktInternal::ExplicitValue(Jakt::DeprecatedString("Struct"sv));
};/*case end*/
case 24: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::Type::Enum>();
return JaktInternal::ExplicitValue(Jakt::DeprecatedString("Enum"sv));
};/*case end*/
case 25: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::Type::RawPtr>();
return JaktInternal::ExplicitValue(Jakt::DeprecatedString("RawPtr"sv));
};/*case end*/
case 26: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::Type::Trait>();
return JaktInternal::ExplicitValue(Jakt::DeprecatedString("Trait"sv));
};/*case end*/
case 27: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::Type::Reference>();
return JaktInternal::ExplicitValue(Jakt::DeprecatedString("Reference"sv));
};/*case end*/
case 28: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::Type::MutableReference>();
return JaktInternal::ExplicitValue(Jakt::DeprecatedString("MutableReference"sv));
};/*case end*/
case 29: {
auto&& __jakt_match_value = __jakt_match_variant.template get<types::Type::Function>();return JaktInternal::ExplicitValue(Jakt::DeprecatedString("Function"sv));
};/*case end*/
case 30: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::Type::Self>();
return JaktInternal::ExplicitValue(Jakt::DeprecatedString("Self"sv));
};/*case end*/
default: VERIFY_NOT_REACHED();}/*switch end*/
}()
)));
}
}

i64 types::Type::min() const {
{
return (JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<i64, i64>{
auto&& __jakt_match_variant = *this;
switch(__jakt_match_variant.index()) {
case 14: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::Type::CChar>();
return JaktInternal::ExplicitValue((-(static_cast<i64>(128LL))));
};/*case end*/
case 15: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::Type::CInt>();
return JaktInternal::ExplicitValue((-(static_cast<i64>(2147483648LL))));
};/*case end*/
case 6: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::Type::I8>();
return JaktInternal::ExplicitValue((-(static_cast<i64>(128LL))));
};/*case end*/
case 7: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::Type::I16>();
return JaktInternal::ExplicitValue((-(static_cast<i64>(32768LL))));
};/*case end*/
case 8: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::Type::I32>();
return JaktInternal::ExplicitValue((-(static_cast<i64>(2147483648LL))));
};/*case end*/
case 9: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::Type::I64>();
return JaktInternal::ExplicitValue((JaktInternal::checked_sub<i64>((-(static_cast<i64>(9223372036854775807LL))),static_cast<i64>(1LL))));
};/*case end*/
case 2: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::Type::U8>();
return JaktInternal::ExplicitValue(static_cast<i64>(0LL));
};/*case end*/
case 3: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::Type::U16>();
return JaktInternal::ExplicitValue(static_cast<i64>(0LL));
};/*case end*/
case 4: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::Type::U32>();
return JaktInternal::ExplicitValue(static_cast<i64>(0LL));
};/*case end*/
case 5: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::Type::U64>();
return JaktInternal::ExplicitValue(static_cast<i64>(0LL));
};/*case end*/
case 12: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::Type::Usize>();
return JaktInternal::ExplicitValue(static_cast<i64>(0LL));
};/*case end*/
default: {
return JaktInternal::ExplicitValue(static_cast<i64>(0LL));
};/*case end*/
}/*switch end*/
}()
)));
}
}

bool types::Type::is_signed() const {
{
return (JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<bool, bool>{
auto&& __jakt_match_variant = *this;
switch(__jakt_match_variant.index()) {
case 6: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::Type::I8>();
return JaktInternal::ExplicitValue(true);
};/*case end*/
case 7: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::Type::I16>();
return JaktInternal::ExplicitValue(true);
};/*case end*/
case 8: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::Type::I32>();
return JaktInternal::ExplicitValue(true);
};/*case end*/
case 9: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::Type::I64>();
return JaktInternal::ExplicitValue(true);
};/*case end*/
case 14: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::Type::CChar>();
return JaktInternal::ExplicitValue(true);
};/*case end*/
case 15: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::Type::CInt>();
return JaktInternal::ExplicitValue(true);
};/*case end*/
case 2: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::Type::U8>();
return JaktInternal::ExplicitValue(false);
};/*case end*/
case 3: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::Type::U16>();
return JaktInternal::ExplicitValue(false);
};/*case end*/
case 4: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::Type::U32>();
return JaktInternal::ExplicitValue(false);
};/*case end*/
case 5: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::Type::U64>();
return JaktInternal::ExplicitValue(false);
};/*case end*/
case 12: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::Type::Usize>();
return JaktInternal::ExplicitValue(false);
};/*case end*/
case 10: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::Type::F32>();
return JaktInternal::ExplicitValue(true);
};/*case end*/
case 11: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::Type::F64>();
return JaktInternal::ExplicitValue(true);
};/*case end*/
default: {
return JaktInternal::ExplicitValue(false);
};/*case end*/
}/*switch end*/
}()
)));
}
}

ErrorOr<DeprecatedString> types::CheckedMatchBody::debug_description() const {
auto builder = TRY(DeprecatedStringBuilder::create());
switch (this->index()) {case 0 /* Expression */: {
[[maybe_unused]] auto const& that = this->template get<CheckedMatchBody::Expression>();
TRY(builder.append("CheckedMatchBody::Expression"sv));
TRY(builder.appendff("({})", that.value));
break;}
case 1 /* Block */: {
[[maybe_unused]] auto const& that = this->template get<CheckedMatchBody::Block>();
TRY(builder.append("CheckedMatchBody::Block"sv));
TRY(builder.appendff("({})", that.value));
break;}
}
return builder.to_string();
}
ErrorOr<DeprecatedString> types::CheckedStatement::debug_description() const {
auto builder = TRY(DeprecatedStringBuilder::create());
switch (this->index()) {case 0 /* Expression */: {
[[maybe_unused]] auto const& that = this->template get<CheckedStatement::Expression>();
TRY(builder.append("CheckedStatement::Expression"sv));
TRY(builder.append("("sv));
{
JaktInternal::PrettyPrint::ScopedLevelIncrease increase_indent {};
TRY(JaktInternal::PrettyPrint::output_indentation(builder));
TRY(builder.appendff("expr: {}", that.expr));
TRY(builder.append(", "sv));
TRY(JaktInternal::PrettyPrint::output_indentation(builder));
TRY(builder.appendff("span: {}", that.span));
}
TRY(builder.append(")"sv));
break;}
case 1 /* Defer */: {
[[maybe_unused]] auto const& that = this->template get<CheckedStatement::Defer>();
TRY(builder.append("CheckedStatement::Defer"sv));
TRY(builder.append("("sv));
{
JaktInternal::PrettyPrint::ScopedLevelIncrease increase_indent {};
TRY(JaktInternal::PrettyPrint::output_indentation(builder));
TRY(builder.appendff("statement: {}", that.statement));
TRY(builder.append(", "sv));
TRY(JaktInternal::PrettyPrint::output_indentation(builder));
TRY(builder.appendff("span: {}", that.span));
}
TRY(builder.append(")"sv));
break;}
case 2 /* DestructuringAssignment */: {
[[maybe_unused]] auto const& that = this->template get<CheckedStatement::DestructuringAssignment>();
TRY(builder.append("CheckedStatement::DestructuringAssignment"sv));
TRY(builder.append("("sv));
{
JaktInternal::PrettyPrint::ScopedLevelIncrease increase_indent {};
TRY(JaktInternal::PrettyPrint::output_indentation(builder));
TRY(builder.appendff("vars: {}", that.vars));
TRY(builder.append(", "sv));
TRY(JaktInternal::PrettyPrint::output_indentation(builder));
TRY(builder.appendff("var_decl: {}", that.var_decl));
TRY(builder.append(", "sv));
TRY(JaktInternal::PrettyPrint::output_indentation(builder));
TRY(builder.appendff("span: {}", that.span));
}
TRY(builder.append(")"sv));
break;}
case 3 /* VarDecl */: {
[[maybe_unused]] auto const& that = this->template get<CheckedStatement::VarDecl>();
TRY(builder.append("CheckedStatement::VarDecl"sv));
TRY(builder.append("("sv));
{
JaktInternal::PrettyPrint::ScopedLevelIncrease increase_indent {};
TRY(JaktInternal::PrettyPrint::output_indentation(builder));
TRY(builder.appendff("var_id: {}", that.var_id));
TRY(builder.append(", "sv));
TRY(JaktInternal::PrettyPrint::output_indentation(builder));
TRY(builder.appendff("init: {}", that.init));
TRY(builder.append(", "sv));
TRY(JaktInternal::PrettyPrint::output_indentation(builder));
TRY(builder.appendff("span: {}", that.span));
}
TRY(builder.append(")"sv));
break;}
case 4 /* If */: {
[[maybe_unused]] auto const& that = this->template get<CheckedStatement::If>();
TRY(builder.append("CheckedStatement::If"sv));
TRY(builder.append("("sv));
{
JaktInternal::PrettyPrint::ScopedLevelIncrease increase_indent {};
TRY(JaktInternal::PrettyPrint::output_indentation(builder));
TRY(builder.appendff("condition: {}", that.condition));
TRY(builder.append(", "sv));
TRY(JaktInternal::PrettyPrint::output_indentation(builder));
TRY(builder.appendff("then_block: {}", that.then_block));
TRY(builder.append(", "sv));
TRY(JaktInternal::PrettyPrint::output_indentation(builder));
TRY(builder.appendff("else_statement: {}", that.else_statement));
TRY(builder.append(", "sv));
TRY(JaktInternal::PrettyPrint::output_indentation(builder));
TRY(builder.appendff("span: {}", that.span));
}
TRY(builder.append(")"sv));
break;}
case 5 /* Block */: {
[[maybe_unused]] auto const& that = this->template get<CheckedStatement::Block>();
TRY(builder.append("CheckedStatement::Block"sv));
TRY(builder.append("("sv));
{
JaktInternal::PrettyPrint::ScopedLevelIncrease increase_indent {};
TRY(JaktInternal::PrettyPrint::output_indentation(builder));
TRY(builder.appendff("block: {}", that.block));
TRY(builder.append(", "sv));
TRY(JaktInternal::PrettyPrint::output_indentation(builder));
TRY(builder.appendff("span: {}", that.span));
}
TRY(builder.append(")"sv));
break;}
case 6 /* Loop */: {
[[maybe_unused]] auto const& that = this->template get<CheckedStatement::Loop>();
TRY(builder.append("CheckedStatement::Loop"sv));
TRY(builder.append("("sv));
{
JaktInternal::PrettyPrint::ScopedLevelIncrease increase_indent {};
TRY(JaktInternal::PrettyPrint::output_indentation(builder));
TRY(builder.appendff("block: {}", that.block));
TRY(builder.append(", "sv));
TRY(JaktInternal::PrettyPrint::output_indentation(builder));
TRY(builder.appendff("span: {}", that.span));
}
TRY(builder.append(")"sv));
break;}
case 7 /* While */: {
[[maybe_unused]] auto const& that = this->template get<CheckedStatement::While>();
TRY(builder.append("CheckedStatement::While"sv));
TRY(builder.append("("sv));
{
JaktInternal::PrettyPrint::ScopedLevelIncrease increase_indent {};
TRY(JaktInternal::PrettyPrint::output_indentation(builder));
TRY(builder.appendff("condition: {}", that.condition));
TRY(builder.append(", "sv));
TRY(JaktInternal::PrettyPrint::output_indentation(builder));
TRY(builder.appendff("block: {}", that.block));
TRY(builder.append(", "sv));
TRY(JaktInternal::PrettyPrint::output_indentation(builder));
TRY(builder.appendff("span: {}", that.span));
}
TRY(builder.append(")"sv));
break;}
case 8 /* Return */: {
[[maybe_unused]] auto const& that = this->template get<CheckedStatement::Return>();
TRY(builder.append("CheckedStatement::Return"sv));
TRY(builder.append("("sv));
{
JaktInternal::PrettyPrint::ScopedLevelIncrease increase_indent {};
TRY(JaktInternal::PrettyPrint::output_indentation(builder));
TRY(builder.appendff("val: {}", that.val));
TRY(builder.append(", "sv));
TRY(JaktInternal::PrettyPrint::output_indentation(builder));
TRY(builder.appendff("span: {}", that.span));
}
TRY(builder.append(")"sv));
break;}
case 9 /* Break */: {
[[maybe_unused]] auto const& that = this->template get<CheckedStatement::Break>();
TRY(builder.append("CheckedStatement::Break"sv));
TRY(builder.appendff("({})", that.value));
break;}
case 10 /* Continue */: {
[[maybe_unused]] auto const& that = this->template get<CheckedStatement::Continue>();
TRY(builder.append("CheckedStatement::Continue"sv));
TRY(builder.appendff("({})", that.value));
break;}
case 11 /* Throw */: {
[[maybe_unused]] auto const& that = this->template get<CheckedStatement::Throw>();
TRY(builder.append("CheckedStatement::Throw"sv));
TRY(builder.append("("sv));
{
JaktInternal::PrettyPrint::ScopedLevelIncrease increase_indent {};
TRY(JaktInternal::PrettyPrint::output_indentation(builder));
TRY(builder.appendff("expr: {}", that.expr));
TRY(builder.append(", "sv));
TRY(JaktInternal::PrettyPrint::output_indentation(builder));
TRY(builder.appendff("span: {}", that.span));
}
TRY(builder.append(")"sv));
break;}
case 12 /* Yield */: {
[[maybe_unused]] auto const& that = this->template get<CheckedStatement::Yield>();
TRY(builder.append("CheckedStatement::Yield"sv));
TRY(builder.append("("sv));
{
JaktInternal::PrettyPrint::ScopedLevelIncrease increase_indent {};
TRY(JaktInternal::PrettyPrint::output_indentation(builder));
TRY(builder.appendff("expr: {}", that.expr));
TRY(builder.append(", "sv));
TRY(JaktInternal::PrettyPrint::output_indentation(builder));
TRY(builder.appendff("span: {}", that.span));
}
TRY(builder.append(")"sv));
break;}
case 13 /* InlineCpp */: {
[[maybe_unused]] auto const& that = this->template get<CheckedStatement::InlineCpp>();
TRY(builder.append("CheckedStatement::InlineCpp"sv));
TRY(builder.append("("sv));
{
JaktInternal::PrettyPrint::ScopedLevelIncrease increase_indent {};
TRY(JaktInternal::PrettyPrint::output_indentation(builder));
TRY(builder.appendff("lines: {}", that.lines));
TRY(builder.append(", "sv));
TRY(JaktInternal::PrettyPrint::output_indentation(builder));
TRY(builder.appendff("span: {}", that.span));
}
TRY(builder.append(")"sv));
break;}
case 14 /* Garbage */: {
[[maybe_unused]] auto const& that = this->template get<CheckedStatement::Garbage>();
TRY(builder.append("CheckedStatement::Garbage"sv));
TRY(builder.appendff("({})", that.value));
break;}
}
return builder.to_string();
}
JaktInternal::Optional<NonnullRefPtr<typename types::CheckedStatement>> types::CheckedStatement::none() {
{
return (JaktInternal::OptionalNone());
}
}

JaktInternal::Optional<utility::Span> types::CheckedStatement::span() const {
{
return (JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<JaktInternal::Optional<utility::Span>, JaktInternal::Optional<utility::Span>>{
auto&& __jakt_match_variant = *this;
switch(__jakt_match_variant.index()) {
case 0: {
auto&& __jakt_match_value = __jakt_match_variant.template get<types::CheckedStatement::Expression>();utility::Span const& span = __jakt_match_value.span;
return JaktInternal::ExplicitValue(static_cast<JaktInternal::Optional<utility::Span>>(span));
};/*case end*/
case 1: {
auto&& __jakt_match_value = __jakt_match_variant.template get<types::CheckedStatement::Defer>();utility::Span const& span = __jakt_match_value.span;
return JaktInternal::ExplicitValue(span);
};/*case end*/
case 2: {
auto&& __jakt_match_value = __jakt_match_variant.template get<types::CheckedStatement::DestructuringAssignment>();utility::Span const& span = __jakt_match_value.span;
return JaktInternal::ExplicitValue(span);
};/*case end*/
case 3: {
auto&& __jakt_match_value = __jakt_match_variant.template get<types::CheckedStatement::VarDecl>();utility::Span const& span = __jakt_match_value.span;
return JaktInternal::ExplicitValue(span);
};/*case end*/
case 4: {
auto&& __jakt_match_value = __jakt_match_variant.template get<types::CheckedStatement::If>();utility::Span const& span = __jakt_match_value.span;
return JaktInternal::ExplicitValue(span);
};/*case end*/
case 5: {
auto&& __jakt_match_value = __jakt_match_variant.template get<types::CheckedStatement::Block>();utility::Span const& span = __jakt_match_value.span;
return JaktInternal::ExplicitValue(span);
};/*case end*/
case 6: {
auto&& __jakt_match_value = __jakt_match_variant.template get<types::CheckedStatement::Loop>();utility::Span const& span = __jakt_match_value.span;
return JaktInternal::ExplicitValue(span);
};/*case end*/
case 7: {
auto&& __jakt_match_value = __jakt_match_variant.template get<types::CheckedStatement::While>();utility::Span const& span = __jakt_match_value.span;
return JaktInternal::ExplicitValue(span);
};/*case end*/
case 8: {
auto&& __jakt_match_value = __jakt_match_variant.template get<types::CheckedStatement::Return>();JaktInternal::Optional<utility::Span> const& span = __jakt_match_value.span;
return JaktInternal::ExplicitValue(span);
};/*case end*/
case 9: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::CheckedStatement::Break>();
utility::Span const& span = __jakt_match_value.value;
return JaktInternal::ExplicitValue(span);
};/*case end*/
case 10: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::CheckedStatement::Continue>();
utility::Span const& span = __jakt_match_value.value;
return JaktInternal::ExplicitValue(span);
};/*case end*/
case 11: {
auto&& __jakt_match_value = __jakt_match_variant.template get<types::CheckedStatement::Throw>();utility::Span const& span = __jakt_match_value.span;
return JaktInternal::ExplicitValue(span);
};/*case end*/
case 12: {
auto&& __jakt_match_value = __jakt_match_variant.template get<types::CheckedStatement::Yield>();utility::Span const& span = __jakt_match_value.span;
return JaktInternal::ExplicitValue(span);
};/*case end*/
case 13: {
auto&& __jakt_match_value = __jakt_match_variant.template get<types::CheckedStatement::InlineCpp>();utility::Span const& span = __jakt_match_value.span;
return JaktInternal::ExplicitValue(span);
};/*case end*/
case 14: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::CheckedStatement::Garbage>();
utility::Span const& span = __jakt_match_value.value;
return JaktInternal::ExplicitValue(span);
};/*case end*/
default: VERIFY_NOT_REACHED();}/*switch end*/
}()
)));
}
}

ErrorOr<DeprecatedString> types::ValueImpl::debug_description() const {
auto builder = TRY(DeprecatedStringBuilder::create());
switch (this->index()) {case 0 /* Void */: {
[[maybe_unused]] auto const& that = this->template get<ValueImpl::Void>();
TRY(builder.append("ValueImpl::Void"sv));
break;}
case 1 /* Bool */: {
[[maybe_unused]] auto const& that = this->template get<ValueImpl::Bool>();
TRY(builder.append("ValueImpl::Bool"sv));
TRY(builder.appendff("({})", that.value));
break;}
case 2 /* U8 */: {
[[maybe_unused]] auto const& that = this->template get<ValueImpl::U8>();
TRY(builder.append("ValueImpl::U8"sv));
TRY(builder.appendff("({})", that.value));
break;}
case 3 /* U16 */: {
[[maybe_unused]] auto const& that = this->template get<ValueImpl::U16>();
TRY(builder.append("ValueImpl::U16"sv));
TRY(builder.appendff("({})", that.value));
break;}
case 4 /* U32 */: {
[[maybe_unused]] auto const& that = this->template get<ValueImpl::U32>();
TRY(builder.append("ValueImpl::U32"sv));
TRY(builder.appendff("({})", that.value));
break;}
case 5 /* U64 */: {
[[maybe_unused]] auto const& that = this->template get<ValueImpl::U64>();
TRY(builder.append("ValueImpl::U64"sv));
TRY(builder.appendff("({})", that.value));
break;}
case 6 /* I8 */: {
[[maybe_unused]] auto const& that = this->template get<ValueImpl::I8>();
TRY(builder.append("ValueImpl::I8"sv));
TRY(builder.appendff("({})", that.value));
break;}
case 7 /* I16 */: {
[[maybe_unused]] auto const& that = this->template get<ValueImpl::I16>();
TRY(builder.append("ValueImpl::I16"sv));
TRY(builder.appendff("({})", that.value));
break;}
case 8 /* I32 */: {
[[maybe_unused]] auto const& that = this->template get<ValueImpl::I32>();
TRY(builder.append("ValueImpl::I32"sv));
TRY(builder.appendff("({})", that.value));
break;}
case 9 /* I64 */: {
[[maybe_unused]] auto const& that = this->template get<ValueImpl::I64>();
TRY(builder.append("ValueImpl::I64"sv));
TRY(builder.appendff("({})", that.value));
break;}
case 10 /* F32 */: {
[[maybe_unused]] auto const& that = this->template get<ValueImpl::F32>();
TRY(builder.append("ValueImpl::F32"sv));
TRY(builder.appendff("({})", that.value));
break;}
case 11 /* F64 */: {
[[maybe_unused]] auto const& that = this->template get<ValueImpl::F64>();
TRY(builder.append("ValueImpl::F64"sv));
TRY(builder.appendff("({})", that.value));
break;}
case 12 /* USize */: {
[[maybe_unused]] auto const& that = this->template get<ValueImpl::USize>();
TRY(builder.append("ValueImpl::USize"sv));
TRY(builder.appendff("({})", that.value));
break;}
case 13 /* JaktString */: {
[[maybe_unused]] auto const& that = this->template get<ValueImpl::JaktString>();
TRY(builder.append("ValueImpl::JaktString"sv));
TRY(builder.appendff("(\"{}\")", that.value));
break;}
case 14 /* StringView */: {
[[maybe_unused]] auto const& that = this->template get<ValueImpl::StringView>();
TRY(builder.append("ValueImpl::StringView"sv));
TRY(builder.appendff("(\"{}\")", that.value));
break;}
case 15 /* CChar */: {
[[maybe_unused]] auto const& that = this->template get<ValueImpl::CChar>();
TRY(builder.append("ValueImpl::CChar"sv));
TRY(builder.appendff("({})", that.value));
break;}
case 16 /* CInt */: {
[[maybe_unused]] auto const& that = this->template get<ValueImpl::CInt>();
TRY(builder.append("ValueImpl::CInt"sv));
TRY(builder.appendff("({})", that.value));
break;}
case 17 /* Struct */: {
[[maybe_unused]] auto const& that = this->template get<ValueImpl::Struct>();
TRY(builder.append("ValueImpl::Struct"sv));
TRY(builder.append("("sv));
{
JaktInternal::PrettyPrint::ScopedLevelIncrease increase_indent {};
TRY(JaktInternal::PrettyPrint::output_indentation(builder));
TRY(builder.appendff("fields: {}", that.fields));
TRY(builder.append(", "sv));
TRY(JaktInternal::PrettyPrint::output_indentation(builder));
TRY(builder.appendff("struct_id: {}", that.struct_id));
TRY(builder.append(", "sv));
TRY(JaktInternal::PrettyPrint::output_indentation(builder));
TRY(builder.appendff("constructor: {}", that.constructor));
}
TRY(builder.append(")"sv));
break;}
case 18 /* Class */: {
[[maybe_unused]] auto const& that = this->template get<ValueImpl::Class>();
TRY(builder.append("ValueImpl::Class"sv));
TRY(builder.append("("sv));
{
JaktInternal::PrettyPrint::ScopedLevelIncrease increase_indent {};
TRY(JaktInternal::PrettyPrint::output_indentation(builder));
TRY(builder.appendff("fields: {}", that.fields));
TRY(builder.append(", "sv));
TRY(JaktInternal::PrettyPrint::output_indentation(builder));
TRY(builder.appendff("struct_id: {}", that.struct_id));
TRY(builder.append(", "sv));
TRY(JaktInternal::PrettyPrint::output_indentation(builder));
TRY(builder.appendff("constructor: {}", that.constructor));
}
TRY(builder.append(")"sv));
break;}
case 19 /* Enum */: {
[[maybe_unused]] auto const& that = this->template get<ValueImpl::Enum>();
TRY(builder.append("ValueImpl::Enum"sv));
TRY(builder.append("("sv));
{
JaktInternal::PrettyPrint::ScopedLevelIncrease increase_indent {};
TRY(JaktInternal::PrettyPrint::output_indentation(builder));
TRY(builder.appendff("fields: {}", that.fields));
TRY(builder.append(", "sv));
TRY(JaktInternal::PrettyPrint::output_indentation(builder));
TRY(builder.appendff("enum_id: {}", that.enum_id));
TRY(builder.append(", "sv));
TRY(JaktInternal::PrettyPrint::output_indentation(builder));
TRY(builder.appendff("constructor: {}", that.constructor));
}
TRY(builder.append(")"sv));
break;}
case 20 /* JaktArray */: {
[[maybe_unused]] auto const& that = this->template get<ValueImpl::JaktArray>();
TRY(builder.append("ValueImpl::JaktArray"sv));
TRY(builder.append("("sv));
{
JaktInternal::PrettyPrint::ScopedLevelIncrease increase_indent {};
TRY(JaktInternal::PrettyPrint::output_indentation(builder));
TRY(builder.appendff("values: {}", that.values));
TRY(builder.append(", "sv));
TRY(JaktInternal::PrettyPrint::output_indentation(builder));
TRY(builder.appendff("type_id: {}", that.type_id));
}
TRY(builder.append(")"sv));
break;}
case 21 /* JaktDictionary */: {
[[maybe_unused]] auto const& that = this->template get<ValueImpl::JaktDictionary>();
TRY(builder.append("ValueImpl::JaktDictionary"sv));
TRY(builder.append("("sv));
{
JaktInternal::PrettyPrint::ScopedLevelIncrease increase_indent {};
TRY(JaktInternal::PrettyPrint::output_indentation(builder));
TRY(builder.appendff("keys: {}", that.keys));
TRY(builder.append(", "sv));
TRY(JaktInternal::PrettyPrint::output_indentation(builder));
TRY(builder.appendff("values: {}", that.values));
TRY(builder.append(", "sv));
TRY(JaktInternal::PrettyPrint::output_indentation(builder));
TRY(builder.appendff("type_id: {}", that.type_id));
}
TRY(builder.append(")"sv));
break;}
case 22 /* JaktSet */: {
[[maybe_unused]] auto const& that = this->template get<ValueImpl::JaktSet>();
TRY(builder.append("ValueImpl::JaktSet"sv));
TRY(builder.append("("sv));
{
JaktInternal::PrettyPrint::ScopedLevelIncrease increase_indent {};
TRY(JaktInternal::PrettyPrint::output_indentation(builder));
TRY(builder.appendff("values: {}", that.values));
TRY(builder.append(", "sv));
TRY(JaktInternal::PrettyPrint::output_indentation(builder));
TRY(builder.appendff("type_id: {}", that.type_id));
}
TRY(builder.append(")"sv));
break;}
case 23 /* RawPtr */: {
[[maybe_unused]] auto const& that = this->template get<ValueImpl::RawPtr>();
TRY(builder.append("ValueImpl::RawPtr"sv));
TRY(builder.appendff("({})", that.value));
break;}
case 24 /* OptionalSome */: {
[[maybe_unused]] auto const& that = this->template get<ValueImpl::OptionalSome>();
TRY(builder.append("ValueImpl::OptionalSome"sv));
TRY(builder.append("("sv));
{
JaktInternal::PrettyPrint::ScopedLevelIncrease increase_indent {};
TRY(JaktInternal::PrettyPrint::output_indentation(builder));
TRY(builder.appendff("value: {}", that.value));
}
TRY(builder.append(")"sv));
break;}
case 25 /* OptionalNone */: {
[[maybe_unused]] auto const& that = this->template get<ValueImpl::OptionalNone>();
TRY(builder.append("ValueImpl::OptionalNone"sv));
break;}
case 26 /* JaktTuple */: {
[[maybe_unused]] auto const& that = this->template get<ValueImpl::JaktTuple>();
TRY(builder.append("ValueImpl::JaktTuple"sv));
TRY(builder.append("("sv));
{
JaktInternal::PrettyPrint::ScopedLevelIncrease increase_indent {};
TRY(JaktInternal::PrettyPrint::output_indentation(builder));
TRY(builder.appendff("fields: {}", that.fields));
TRY(builder.append(", "sv));
TRY(JaktInternal::PrettyPrint::output_indentation(builder));
TRY(builder.appendff("type_id: {}", that.type_id));
}
TRY(builder.append(")"sv));
break;}
case 27 /* Function */: {
[[maybe_unused]] auto const& that = this->template get<ValueImpl::Function>();
TRY(builder.append("ValueImpl::Function"sv));
TRY(builder.append("("sv));
{
JaktInternal::PrettyPrint::ScopedLevelIncrease increase_indent {};
TRY(JaktInternal::PrettyPrint::output_indentation(builder));
TRY(builder.appendff("captures: {}", that.captures));
TRY(builder.append(", "sv));
TRY(JaktInternal::PrettyPrint::output_indentation(builder));
TRY(builder.appendff("params: {}", that.params));
TRY(builder.append(", "sv));
TRY(JaktInternal::PrettyPrint::output_indentation(builder));
TRY(builder.appendff("return_type_id: {}", that.return_type_id));
TRY(builder.append(", "sv));
TRY(JaktInternal::PrettyPrint::output_indentation(builder));
TRY(builder.appendff("type_id: {}", that.type_id));
TRY(builder.append(", "sv));
TRY(JaktInternal::PrettyPrint::output_indentation(builder));
TRY(builder.appendff("block: {}", that.block));
TRY(builder.append(", "sv));
TRY(JaktInternal::PrettyPrint::output_indentation(builder));
TRY(builder.appendff("can_throw: {}", that.can_throw));
TRY(builder.append(", "sv));
TRY(JaktInternal::PrettyPrint::output_indentation(builder));
TRY(builder.appendff("checked_params: {}", that.checked_params));
}
TRY(builder.append(")"sv));
break;}
}
return builder.to_string();
}
bool types::ValueImpl::equals(NonnullRefPtr<typename types::ValueImpl> const other) const {
{
return (JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<bool, bool>{
auto&& __jakt_match_variant = *this;
switch(__jakt_match_variant.index()) {
case 0: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::Void>();
return JaktInternal::ExplicitValue(((other)->index() == 0 /* Void */));
};/*case end*/
case 1: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::Bool>();
bool const& x = __jakt_match_value.value;
return JaktInternal::ExplicitValue(JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<bool, bool>{
auto&& __jakt_match_variant = *other;
switch(__jakt_match_variant.index()) {
case 1: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::Bool>();
bool const& y = __jakt_match_value.value;
return JaktInternal::ExplicitValue((x == y));
};/*case end*/
default: {
return JaktInternal::ExplicitValue(false);
};/*case end*/
}/*switch end*/
}()
)));
};/*case end*/
case 2: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::U8>();
u8 const& x = __jakt_match_value.value;
return JaktInternal::ExplicitValue(JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<bool, bool>{
auto&& __jakt_match_variant = *other;
switch(__jakt_match_variant.index()) {
case 2: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::U8>();
u8 const& y = __jakt_match_value.value;
return JaktInternal::ExplicitValue((x == y));
};/*case end*/
default: {
return JaktInternal::ExplicitValue(false);
};/*case end*/
}/*switch end*/
}()
)));
};/*case end*/
case 3: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::U16>();
u16 const& x = __jakt_match_value.value;
return JaktInternal::ExplicitValue(JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<bool, bool>{
auto&& __jakt_match_variant = *other;
switch(__jakt_match_variant.index()) {
case 3: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::U16>();
u16 const& y = __jakt_match_value.value;
return JaktInternal::ExplicitValue((y == x));
};/*case end*/
default: {
return JaktInternal::ExplicitValue(false);
};/*case end*/
}/*switch end*/
}()
)));
};/*case end*/
case 4: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::U32>();
u32 const& x = __jakt_match_value.value;
return JaktInternal::ExplicitValue(JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<bool, bool>{
auto&& __jakt_match_variant = *other;
switch(__jakt_match_variant.index()) {
case 4: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::U32>();
u32 const& y = __jakt_match_value.value;
return JaktInternal::ExplicitValue((y == x));
};/*case end*/
default: {
return JaktInternal::ExplicitValue(false);
};/*case end*/
}/*switch end*/
}()
)));
};/*case end*/
case 5: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::U64>();
u64 const& x = __jakt_match_value.value;
return JaktInternal::ExplicitValue(JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<bool, bool>{
auto&& __jakt_match_variant = *other;
switch(__jakt_match_variant.index()) {
case 5: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::U64>();
u64 const& y = __jakt_match_value.value;
return JaktInternal::ExplicitValue((y == x));
};/*case end*/
default: {
return JaktInternal::ExplicitValue(false);
};/*case end*/
}/*switch end*/
}()
)));
};/*case end*/
case 6: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::I8>();
i8 const& x = __jakt_match_value.value;
return JaktInternal::ExplicitValue(JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<bool, bool>{
auto&& __jakt_match_variant = *other;
switch(__jakt_match_variant.index()) {
case 6: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::I8>();
i8 const& y = __jakt_match_value.value;
return JaktInternal::ExplicitValue((y == x));
};/*case end*/
default: {
return JaktInternal::ExplicitValue(false);
};/*case end*/
}/*switch end*/
}()
)));
};/*case end*/
case 7: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::I16>();
i16 const& x = __jakt_match_value.value;
return JaktInternal::ExplicitValue(JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<bool, bool>{
auto&& __jakt_match_variant = *other;
switch(__jakt_match_variant.index()) {
case 7: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::I16>();
i16 const& y = __jakt_match_value.value;
return JaktInternal::ExplicitValue((y == x));
};/*case end*/
default: {
return JaktInternal::ExplicitValue(false);
};/*case end*/
}/*switch end*/
}()
)));
};/*case end*/
case 8: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::I32>();
i32 const& x = __jakt_match_value.value;
return JaktInternal::ExplicitValue(JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<bool, bool>{
auto&& __jakt_match_variant = *other;
switch(__jakt_match_variant.index()) {
case 8: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::I32>();
i32 const& y = __jakt_match_value.value;
return JaktInternal::ExplicitValue((y == x));
};/*case end*/
default: {
return JaktInternal::ExplicitValue(false);
};/*case end*/
}/*switch end*/
}()
)));
};/*case end*/
case 9: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::I64>();
i64 const& x = __jakt_match_value.value;
return JaktInternal::ExplicitValue(JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<bool, bool>{
auto&& __jakt_match_variant = *other;
switch(__jakt_match_variant.index()) {
case 9: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::I64>();
i64 const& y = __jakt_match_value.value;
return JaktInternal::ExplicitValue((y == x));
};/*case end*/
default: {
return JaktInternal::ExplicitValue(false);
};/*case end*/
}/*switch end*/
}()
)));
};/*case end*/
case 10: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::F32>();
f32 const& x = __jakt_match_value.value;
return JaktInternal::ExplicitValue(JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<bool, bool>{
auto&& __jakt_match_variant = *other;
switch(__jakt_match_variant.index()) {
case 10: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::F32>();
f32 const& y = __jakt_match_value.value;
return JaktInternal::ExplicitValue((y == x));
};/*case end*/
default: {
return JaktInternal::ExplicitValue(false);
};/*case end*/
}/*switch end*/
}()
)));
};/*case end*/
case 11: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::F64>();
f64 const& x = __jakt_match_value.value;
return JaktInternal::ExplicitValue(JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<bool, bool>{
auto&& __jakt_match_variant = *other;
switch(__jakt_match_variant.index()) {
case 11: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::F64>();
f64 const& y = __jakt_match_value.value;
return JaktInternal::ExplicitValue((y == x));
};/*case end*/
default: {
return JaktInternal::ExplicitValue(false);
};/*case end*/
}/*switch end*/
}()
)));
};/*case end*/
case 12: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::USize>();
size_t const& x = __jakt_match_value.value;
return JaktInternal::ExplicitValue(JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<bool, bool>{
auto&& __jakt_match_variant = *other;
switch(__jakt_match_variant.index()) {
case 12: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::USize>();
size_t const& y = __jakt_match_value.value;
return JaktInternal::ExplicitValue((y == x));
};/*case end*/
default: {
return JaktInternal::ExplicitValue(false);
};/*case end*/
}/*switch end*/
}()
)));
};/*case end*/
case 13: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::JaktString>();
DeprecatedString const& x = __jakt_match_value.value;
return JaktInternal::ExplicitValue(JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<bool, bool>{
auto&& __jakt_match_variant = *other;
switch(__jakt_match_variant.index()) {
case 13: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::JaktString>();
DeprecatedString const& y = __jakt_match_value.value;
return JaktInternal::ExplicitValue((y == x));
};/*case end*/
default: {
return JaktInternal::ExplicitValue(false);
};/*case end*/
}/*switch end*/
}()
)));
};/*case end*/
case 14: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::StringView>();
DeprecatedString const& x = __jakt_match_value.value;
return JaktInternal::ExplicitValue(JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<bool, bool>{
auto&& __jakt_match_variant = *other;
switch(__jakt_match_variant.index()) {
case 14: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::StringView>();
DeprecatedString const& y = __jakt_match_value.value;
return JaktInternal::ExplicitValue((y == x));
};/*case end*/
default: {
return JaktInternal::ExplicitValue(false);
};/*case end*/
}/*switch end*/
}()
)));
};/*case end*/
case 15: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::CChar>();
char const& x = __jakt_match_value.value;
return JaktInternal::ExplicitValue(JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<bool, bool>{
auto&& __jakt_match_variant = *other;
switch(__jakt_match_variant.index()) {
case 15: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::CChar>();
char const& y = __jakt_match_value.value;
return JaktInternal::ExplicitValue((y == x));
};/*case end*/
default: {
return JaktInternal::ExplicitValue(false);
};/*case end*/
}/*switch end*/
}()
)));
};/*case end*/
case 16: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::CInt>();
int const& x = __jakt_match_value.value;
return JaktInternal::ExplicitValue(JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<bool, bool>{
auto&& __jakt_match_variant = *other;
switch(__jakt_match_variant.index()) {
case 16: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::CInt>();
int const& y = __jakt_match_value.value;
return JaktInternal::ExplicitValue((y == x));
};/*case end*/
default: {
return JaktInternal::ExplicitValue(false);
};/*case end*/
}/*switch end*/
}()
)));
};/*case end*/
default: {
return JaktInternal::ExplicitValue(false);
};/*case end*/
}/*switch end*/
}()
)));
}
}

ErrorOr<NonnullRefPtr<typename types::ValueImpl>> types::ValueImpl::copy() const {
{
return (JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<NonnullRefPtr<typename types::ValueImpl>, ErrorOr<NonnullRefPtr<typename types::ValueImpl>>>{
auto&& __jakt_match_variant = *this;
switch(__jakt_match_variant.index()) {
case 0: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::Void>();
return JaktInternal::ExplicitValue(TRY((types::ValueImpl::template create<typename types::ValueImpl::Void>())));
};/*case end*/
case 1: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::Bool>();
bool const& x = __jakt_match_value.value;
return JaktInternal::ExplicitValue(TRY((types::ValueImpl::template create<typename types::ValueImpl::Bool>(x))));
};/*case end*/
case 2: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::U8>();
u8 const& x = __jakt_match_value.value;
return JaktInternal::ExplicitValue(TRY((types::ValueImpl::template create<typename types::ValueImpl::U8>(x))));
};/*case end*/
case 3: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::U16>();
u16 const& x = __jakt_match_value.value;
return JaktInternal::ExplicitValue(TRY((types::ValueImpl::template create<typename types::ValueImpl::U16>(x))));
};/*case end*/
case 4: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::U32>();
u32 const& x = __jakt_match_value.value;
return JaktInternal::ExplicitValue(TRY((types::ValueImpl::template create<typename types::ValueImpl::U32>(x))));
};/*case end*/
case 5: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::U64>();
u64 const& x = __jakt_match_value.value;
return JaktInternal::ExplicitValue(TRY((types::ValueImpl::template create<typename types::ValueImpl::U64>(x))));
};/*case end*/
case 6: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::I8>();
i8 const& x = __jakt_match_value.value;
return JaktInternal::ExplicitValue(TRY((types::ValueImpl::template create<typename types::ValueImpl::I8>(x))));
};/*case end*/
case 7: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::I16>();
i16 const& x = __jakt_match_value.value;
return JaktInternal::ExplicitValue(TRY((types::ValueImpl::template create<typename types::ValueImpl::I16>(x))));
};/*case end*/
case 8: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::I32>();
i32 const& x = __jakt_match_value.value;
return JaktInternal::ExplicitValue(TRY((types::ValueImpl::template create<typename types::ValueImpl::I32>(x))));
};/*case end*/
case 9: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::I64>();
i64 const& x = __jakt_match_value.value;
return JaktInternal::ExplicitValue(TRY((types::ValueImpl::template create<typename types::ValueImpl::I64>(x))));
};/*case end*/
case 10: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::F32>();
f32 const& x = __jakt_match_value.value;
return JaktInternal::ExplicitValue(TRY((types::ValueImpl::template create<typename types::ValueImpl::F32>(x))));
};/*case end*/
case 11: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::F64>();
f64 const& x = __jakt_match_value.value;
return JaktInternal::ExplicitValue(TRY((types::ValueImpl::template create<typename types::ValueImpl::F64>(x))));
};/*case end*/
case 12: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::USize>();
size_t const& x = __jakt_match_value.value;
return JaktInternal::ExplicitValue(TRY((types::ValueImpl::template create<typename types::ValueImpl::USize>(x))));
};/*case end*/
case 13: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::JaktString>();
DeprecatedString const& x = __jakt_match_value.value;
return JaktInternal::ExplicitValue(TRY((types::ValueImpl::template create<typename types::ValueImpl::JaktString>(x))));
};/*case end*/
case 14: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::StringView>();
DeprecatedString const& x = __jakt_match_value.value;
return JaktInternal::ExplicitValue(TRY((types::ValueImpl::template create<typename types::ValueImpl::StringView>(x))));
};/*case end*/
case 15: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::CChar>();
char const& x = __jakt_match_value.value;
return JaktInternal::ExplicitValue(TRY((types::ValueImpl::template create<typename types::ValueImpl::CChar>(x))));
};/*case end*/
case 16: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::CInt>();
int const& x = __jakt_match_value.value;
return JaktInternal::ExplicitValue(TRY((types::ValueImpl::template create<typename types::ValueImpl::CInt>(x))));
};/*case end*/
case 17: {
auto&& __jakt_match_value = __jakt_match_variant.template get<types::ValueImpl::Struct>();JaktInternal::DynamicArray<types::Value> const& fields = __jakt_match_value.fields;
types::StructId const& struct_id = __jakt_match_value.struct_id;
JaktInternal::Optional<types::FunctionId> const& constructor = __jakt_match_value.constructor;
return JaktInternal::ExplicitValue(({ Optional<NonnullRefPtr<typename types::ValueImpl>> __jakt_var_129; {
JaktInternal::DynamicArray<types::Value> fields_copy = (TRY((DynamicArray<types::Value>::create_with({}))));
{
JaktInternal::ArrayIterator<types::Value> _magic = ((fields).iterator());
for (;;){
JaktInternal::Optional<types::Value> _magic_value = ((_magic).next());
if ((!(((_magic_value).has_value())))){
break;
}
types::Value field = (_magic_value.value());
{
TRY((((fields_copy).push(TRY((((field).copy())))))));
}

}
}

__jakt_var_129 = TRY((types::ValueImpl::template create<typename types::ValueImpl::Struct>(fields_copy,struct_id,constructor))); goto __jakt_label_126;

}
__jakt_label_126:; __jakt_var_129.release_value(); }));
};/*case end*/
case 18: {
auto&& __jakt_match_value = __jakt_match_variant.template get<types::ValueImpl::Class>();JaktInternal::DynamicArray<types::Value> const& fields = __jakt_match_value.fields;
types::StructId const& struct_id = __jakt_match_value.struct_id;
JaktInternal::Optional<types::FunctionId> const& constructor = __jakt_match_value.constructor;
return JaktInternal::ExplicitValue(TRY((types::ValueImpl::template create<typename types::ValueImpl::Class>(fields,struct_id,constructor))));
};/*case end*/
case 19: {
auto&& __jakt_match_value = __jakt_match_variant.template get<types::ValueImpl::Enum>();JaktInternal::DynamicArray<types::Value> const& fields = __jakt_match_value.fields;
types::EnumId const& enum_id = __jakt_match_value.enum_id;
types::FunctionId const& constructor = __jakt_match_value.constructor;
return JaktInternal::ExplicitValue(({ Optional<NonnullRefPtr<typename types::ValueImpl>> __jakt_var_130; {
JaktInternal::DynamicArray<types::Value> fields_copy = (TRY((DynamicArray<types::Value>::create_with({}))));
{
JaktInternal::ArrayIterator<types::Value> _magic = ((fields).iterator());
for (;;){
JaktInternal::Optional<types::Value> _magic_value = ((_magic).next());
if ((!(((_magic_value).has_value())))){
break;
}
types::Value field = (_magic_value.value());
{
TRY((((fields_copy).push(TRY((((field).copy())))))));
}

}
}

__jakt_var_130 = TRY((types::ValueImpl::template create<typename types::ValueImpl::Enum>(fields_copy,enum_id,constructor))); goto __jakt_label_127;

}
__jakt_label_127:; __jakt_var_130.release_value(); }));
};/*case end*/
case 20: {
auto&& __jakt_match_value = __jakt_match_variant.template get<types::ValueImpl::JaktArray>();JaktInternal::DynamicArray<types::Value> const& values = __jakt_match_value.values;
types::TypeId const& type_id = __jakt_match_value.type_id;
return JaktInternal::ExplicitValue(({ Optional<NonnullRefPtr<typename types::ValueImpl>> __jakt_var_131; {
JaktInternal::DynamicArray<types::Value> values_copy = (TRY((DynamicArray<types::Value>::create_with({}))));
{
JaktInternal::ArrayIterator<types::Value> _magic = ((values).iterator());
for (;;){
JaktInternal::Optional<types::Value> _magic_value = ((_magic).next());
if ((!(((_magic_value).has_value())))){
break;
}
types::Value value = (_magic_value.value());
{
TRY((((values_copy).push(TRY((((value).copy())))))));
}

}
}

__jakt_var_131 = TRY((types::ValueImpl::template create<typename types::ValueImpl::JaktArray>(values_copy,type_id))); goto __jakt_label_128;

}
__jakt_label_128:; __jakt_var_131.release_value(); }));
};/*case end*/
case 21: {
auto&& __jakt_match_value = __jakt_match_variant.template get<types::ValueImpl::JaktDictionary>();JaktInternal::DynamicArray<types::Value> const& keys = __jakt_match_value.keys;
JaktInternal::DynamicArray<types::Value> const& values = __jakt_match_value.values;
types::TypeId const& type_id = __jakt_match_value.type_id;
return JaktInternal::ExplicitValue(({ Optional<NonnullRefPtr<typename types::ValueImpl>> __jakt_var_132; {
JaktInternal::DynamicArray<types::Value> values_copy = (TRY((DynamicArray<types::Value>::create_with({}))));
{
JaktInternal::ArrayIterator<types::Value> _magic = ((values).iterator());
for (;;){
JaktInternal::Optional<types::Value> _magic_value = ((_magic).next());
if ((!(((_magic_value).has_value())))){
break;
}
types::Value value = (_magic_value.value());
{
TRY((((values_copy).push(TRY((((value).copy())))))));
}

}
}

JaktInternal::DynamicArray<types::Value> keys_copy = (TRY((DynamicArray<types::Value>::create_with({}))));
{
JaktInternal::ArrayIterator<types::Value> _magic = ((keys).iterator());
for (;;){
JaktInternal::Optional<types::Value> _magic_value = ((_magic).next());
if ((!(((_magic_value).has_value())))){
break;
}
types::Value key = (_magic_value.value());
{
TRY((((keys_copy).push(TRY((((key).copy())))))));
}

}
}

__jakt_var_132 = TRY((types::ValueImpl::template create<typename types::ValueImpl::JaktDictionary>(keys_copy,values_copy,type_id))); goto __jakt_label_129;

}
__jakt_label_129:; __jakt_var_132.release_value(); }));
};/*case end*/
case 22: {
auto&& __jakt_match_value = __jakt_match_variant.template get<types::ValueImpl::JaktSet>();JaktInternal::DynamicArray<types::Value> const& values = __jakt_match_value.values;
types::TypeId const& type_id = __jakt_match_value.type_id;
return JaktInternal::ExplicitValue(({ Optional<NonnullRefPtr<typename types::ValueImpl>> __jakt_var_133; {
JaktInternal::DynamicArray<types::Value> values_copy = (TRY((DynamicArray<types::Value>::create_with({}))));
{
JaktInternal::ArrayIterator<types::Value> _magic = ((values).iterator());
for (;;){
JaktInternal::Optional<types::Value> _magic_value = ((_magic).next());
if ((!(((_magic_value).has_value())))){
break;
}
types::Value value = (_magic_value.value());
{
TRY((((values_copy).push(TRY((((value).copy())))))));
}

}
}

__jakt_var_133 = TRY((types::ValueImpl::template create<typename types::ValueImpl::JaktSet>(values_copy,type_id))); goto __jakt_label_130;

}
__jakt_label_130:; __jakt_var_133.release_value(); }));
};/*case end*/
case 23: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::RawPtr>();
NonnullRefPtr<typename types::ValueImpl> const& value = __jakt_match_value.value;
return JaktInternal::ExplicitValue(TRY((types::ValueImpl::template create<typename types::ValueImpl::RawPtr>(value))));
};/*case end*/
case 24: {
auto&& __jakt_match_value = __jakt_match_variant.template get<types::ValueImpl::OptionalSome>();types::Value const& value = __jakt_match_value.value;
return JaktInternal::ExplicitValue(TRY((types::ValueImpl::template create<typename types::ValueImpl::OptionalSome>(TRY((((value).copy())))))));
};/*case end*/
case 25: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::ValueImpl::OptionalNone>();
return JaktInternal::ExplicitValue(TRY((types::ValueImpl::template create<typename types::ValueImpl::OptionalNone>())));
};/*case end*/
case 26: {
auto&& __jakt_match_value = __jakt_match_variant.template get<types::ValueImpl::JaktTuple>();JaktInternal::DynamicArray<types::Value> const& fields = __jakt_match_value.fields;
types::TypeId const& type_id = __jakt_match_value.type_id;
return JaktInternal::ExplicitValue(({ Optional<NonnullRefPtr<typename types::ValueImpl>> __jakt_var_134; {
JaktInternal::DynamicArray<types::Value> values_copy = (TRY((DynamicArray<types::Value>::create_with({}))));
{
JaktInternal::ArrayIterator<types::Value> _magic = ((fields).iterator());
for (;;){
JaktInternal::Optional<types::Value> _magic_value = ((_magic).next());
if ((!(((_magic_value).has_value())))){
break;
}
types::Value value = (_magic_value.value());
{
TRY((((values_copy).push(TRY((((value).copy())))))));
}

}
}

__jakt_var_134 = TRY((types::ValueImpl::template create<typename types::ValueImpl::JaktTuple>(values_copy,type_id))); goto __jakt_label_131;

}
__jakt_label_131:; __jakt_var_134.release_value(); }));
};/*case end*/
case 27: {
auto&& __jakt_match_value = __jakt_match_variant.template get<types::ValueImpl::Function>();JaktInternal::Dictionary<DeprecatedString,types::Value> const& captures = __jakt_match_value.captures;
JaktInternal::Dictionary<DeprecatedString,JaktInternal::Tuple<types::TypeId,JaktInternal::Optional<NonnullRefPtr<typename types::CheckedExpression>>>> const& params = __jakt_match_value.params;
bool const& can_throw = __jakt_match_value.can_throw;
types::TypeId const& return_type_id = __jakt_match_value.return_type_id;
types::TypeId const& type_id = __jakt_match_value.type_id;
types::CheckedBlock const& block = __jakt_match_value.block;
JaktInternal::DynamicArray<types::CheckedParameter> const& checked_params = __jakt_match_value.checked_params;
return JaktInternal::ExplicitValue(TRY((types::ValueImpl::template create<typename types::ValueImpl::Function>(captures,params,return_type_id,type_id,block,can_throw,checked_params))));
};/*case end*/
default: VERIFY_NOT_REACHED();}/*switch end*/
}()
)));
}
}

ErrorOr<DeprecatedString> types::CheckedEnumVariant::debug_description() const {
auto builder = TRY(DeprecatedStringBuilder::create());
switch (this->index()) {case 0 /* Untyped */: {
[[maybe_unused]] auto const& that = this->template get<CheckedEnumVariant::Untyped>();
TRY(builder.append("CheckedEnumVariant::Untyped"sv));
TRY(builder.append("("sv));
{
JaktInternal::PrettyPrint::ScopedLevelIncrease increase_indent {};
TRY(JaktInternal::PrettyPrint::output_indentation(builder));
TRY(builder.appendff("enum_id: {}", that.enum_id));
TRY(builder.append(", "sv));
TRY(JaktInternal::PrettyPrint::output_indentation(builder));
TRY(builder.appendff("name: \"{}\"", that.name));
TRY(builder.append(", "sv));
TRY(JaktInternal::PrettyPrint::output_indentation(builder));
TRY(builder.appendff("span: {}", that.span));
}
TRY(builder.append(")"sv));
break;}
case 1 /* Typed */: {
[[maybe_unused]] auto const& that = this->template get<CheckedEnumVariant::Typed>();
TRY(builder.append("CheckedEnumVariant::Typed"sv));
TRY(builder.append("("sv));
{
JaktInternal::PrettyPrint::ScopedLevelIncrease increase_indent {};
TRY(JaktInternal::PrettyPrint::output_indentation(builder));
TRY(builder.appendff("enum_id: {}", that.enum_id));
TRY(builder.append(", "sv));
TRY(JaktInternal::PrettyPrint::output_indentation(builder));
TRY(builder.appendff("name: \"{}\"", that.name));
TRY(builder.append(", "sv));
TRY(JaktInternal::PrettyPrint::output_indentation(builder));
TRY(builder.appendff("type_id: {}", that.type_id));
TRY(builder.append(", "sv));
TRY(JaktInternal::PrettyPrint::output_indentation(builder));
TRY(builder.appendff("span: {}", that.span));
}
TRY(builder.append(")"sv));
break;}
case 2 /* WithValue */: {
[[maybe_unused]] auto const& that = this->template get<CheckedEnumVariant::WithValue>();
TRY(builder.append("CheckedEnumVariant::WithValue"sv));
TRY(builder.append("("sv));
{
JaktInternal::PrettyPrint::ScopedLevelIncrease increase_indent {};
TRY(JaktInternal::PrettyPrint::output_indentation(builder));
TRY(builder.appendff("enum_id: {}", that.enum_id));
TRY(builder.append(", "sv));
TRY(JaktInternal::PrettyPrint::output_indentation(builder));
TRY(builder.appendff("name: \"{}\"", that.name));
TRY(builder.append(", "sv));
TRY(JaktInternal::PrettyPrint::output_indentation(builder));
TRY(builder.appendff("expr: {}", that.expr));
TRY(builder.append(", "sv));
TRY(JaktInternal::PrettyPrint::output_indentation(builder));
TRY(builder.appendff("span: {}", that.span));
}
TRY(builder.append(")"sv));
break;}
case 3 /* StructLike */: {
[[maybe_unused]] auto const& that = this->template get<CheckedEnumVariant::StructLike>();
TRY(builder.append("CheckedEnumVariant::StructLike"sv));
TRY(builder.append("("sv));
{
JaktInternal::PrettyPrint::ScopedLevelIncrease increase_indent {};
TRY(JaktInternal::PrettyPrint::output_indentation(builder));
TRY(builder.appendff("enum_id: {}", that.enum_id));
TRY(builder.append(", "sv));
TRY(JaktInternal::PrettyPrint::output_indentation(builder));
TRY(builder.appendff("name: \"{}\"", that.name));
TRY(builder.append(", "sv));
TRY(JaktInternal::PrettyPrint::output_indentation(builder));
TRY(builder.appendff("fields: {}", that.fields));
TRY(builder.append(", "sv));
TRY(JaktInternal::PrettyPrint::output_indentation(builder));
TRY(builder.appendff("span: {}", that.span));
}
TRY(builder.append(")"sv));
break;}
}
return builder.to_string();
}
types::EnumId types::CheckedEnumVariant::enum_id() const {
{
return (JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<types::EnumId, types::EnumId>{
auto&& __jakt_match_variant = *this;
switch(__jakt_match_variant.index()) {
case 0: {
auto&& __jakt_match_value = __jakt_match_variant.template get<types::CheckedEnumVariant::Untyped>();types::EnumId const& enum_id = __jakt_match_value.enum_id;
return JaktInternal::ExplicitValue(enum_id);
};/*case end*/
case 1: {
auto&& __jakt_match_value = __jakt_match_variant.template get<types::CheckedEnumVariant::Typed>();types::EnumId const& enum_id = __jakt_match_value.enum_id;
return JaktInternal::ExplicitValue(enum_id);
};/*case end*/
case 2: {
auto&& __jakt_match_value = __jakt_match_variant.template get<types::CheckedEnumVariant::WithValue>();types::EnumId const& enum_id = __jakt_match_value.enum_id;
return JaktInternal::ExplicitValue(enum_id);
};/*case end*/
case 3: {
auto&& __jakt_match_value = __jakt_match_variant.template get<types::CheckedEnumVariant::StructLike>();types::EnumId const& enum_id = __jakt_match_value.enum_id;
return JaktInternal::ExplicitValue(enum_id);
};/*case end*/
default: VERIFY_NOT_REACHED();}/*switch end*/
}()
)));
}
}

DeprecatedString types::CheckedEnumVariant::name() const {
{
return (JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<DeprecatedString, DeprecatedString>{
auto&& __jakt_match_variant = *this;
switch(__jakt_match_variant.index()) {
case 0: {
auto&& __jakt_match_value = __jakt_match_variant.template get<types::CheckedEnumVariant::Untyped>();DeprecatedString const& name = __jakt_match_value.name;
return JaktInternal::ExplicitValue(name);
};/*case end*/
case 1: {
auto&& __jakt_match_value = __jakt_match_variant.template get<types::CheckedEnumVariant::Typed>();DeprecatedString const& name = __jakt_match_value.name;
return JaktInternal::ExplicitValue(name);
};/*case end*/
case 2: {
auto&& __jakt_match_value = __jakt_match_variant.template get<types::CheckedEnumVariant::WithValue>();DeprecatedString const& name = __jakt_match_value.name;
return JaktInternal::ExplicitValue(name);
};/*case end*/
case 3: {
auto&& __jakt_match_value = __jakt_match_variant.template get<types::CheckedEnumVariant::StructLike>();DeprecatedString const& name = __jakt_match_value.name;
return JaktInternal::ExplicitValue(name);
};/*case end*/
default: VERIFY_NOT_REACHED();}/*switch end*/
}()
)));
}
}

bool types::CheckedEnumVariant::equals(types::CheckedEnumVariant const other) const {
{
return (JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<bool, bool>{
auto&& __jakt_match_variant = *this;
switch(__jakt_match_variant.index()) {
case 0: {
auto&& __jakt_match_value = __jakt_match_variant.template get<types::CheckedEnumVariant::Untyped>();DeprecatedString const& this_name = __jakt_match_value.name;
return JaktInternal::ExplicitValue(JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<bool, bool>{
auto&& __jakt_match_variant = other;
switch(__jakt_match_variant.index()) {
case 0: {
auto&& __jakt_match_value = __jakt_match_variant.template get<types::CheckedEnumVariant::Untyped>();DeprecatedString const& other_name = __jakt_match_value.name;
return JaktInternal::ExplicitValue((this_name == other_name));
};/*case end*/
default: {
return JaktInternal::ExplicitValue(false);
};/*case end*/
}/*switch end*/
}()
)));
};/*case end*/
default: {
return JaktInternal::ExplicitValue(false);
};/*case end*/
}/*switch end*/
}()
)));
}
}

utility::Span types::CheckedEnumVariant::span() const {
{
return (JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<utility::Span, utility::Span>{
auto&& __jakt_match_variant = *this;
switch(__jakt_match_variant.index()) {
case 0: {
auto&& __jakt_match_value = __jakt_match_variant.template get<types::CheckedEnumVariant::Untyped>();utility::Span const& span = __jakt_match_value.span;
return JaktInternal::ExplicitValue(span);
};/*case end*/
case 1: {
auto&& __jakt_match_value = __jakt_match_variant.template get<types::CheckedEnumVariant::Typed>();utility::Span const& span = __jakt_match_value.span;
return JaktInternal::ExplicitValue(span);
};/*case end*/
case 2: {
auto&& __jakt_match_value = __jakt_match_variant.template get<types::CheckedEnumVariant::WithValue>();utility::Span const& span = __jakt_match_value.span;
return JaktInternal::ExplicitValue(span);
};/*case end*/
case 3: {
auto&& __jakt_match_value = __jakt_match_variant.template get<types::CheckedEnumVariant::StructLike>();utility::Span const& span = __jakt_match_value.span;
return JaktInternal::ExplicitValue(span);
};/*case end*/
default: VERIFY_NOT_REACHED();}/*switch end*/
}()
)));
}
}

ErrorOr<DeprecatedString> types::CheckedMatchCase::debug_description() const {
auto builder = TRY(DeprecatedStringBuilder::create());
switch (this->index()) {case 0 /* EnumVariant */: {
[[maybe_unused]] auto const& that = this->template get<CheckedMatchCase::EnumVariant>();
TRY(builder.append("CheckedMatchCase::EnumVariant"sv));
TRY(builder.append("("sv));
{
JaktInternal::PrettyPrint::ScopedLevelIncrease increase_indent {};
TRY(JaktInternal::PrettyPrint::output_indentation(builder));
TRY(builder.appendff("defaults: {}", that.defaults));
TRY(builder.append(", "sv));
TRY(JaktInternal::PrettyPrint::output_indentation(builder));
TRY(builder.appendff("name: \"{}\"", that.name));
TRY(builder.append(", "sv));
TRY(JaktInternal::PrettyPrint::output_indentation(builder));
TRY(builder.appendff("args: {}", that.args));
TRY(builder.append(", "sv));
TRY(JaktInternal::PrettyPrint::output_indentation(builder));
TRY(builder.appendff("subject_type_id: {}", that.subject_type_id));
TRY(builder.append(", "sv));
TRY(JaktInternal::PrettyPrint::output_indentation(builder));
TRY(builder.appendff("index: {}", that.index));
TRY(builder.append(", "sv));
TRY(JaktInternal::PrettyPrint::output_indentation(builder));
TRY(builder.appendff("scope_id: {}", that.scope_id));
TRY(builder.append(", "sv));
TRY(JaktInternal::PrettyPrint::output_indentation(builder));
TRY(builder.appendff("body: {}", that.body));
TRY(builder.append(", "sv));
TRY(JaktInternal::PrettyPrint::output_indentation(builder));
TRY(builder.appendff("marker_span: {}", that.marker_span));
}
TRY(builder.append(")"sv));
break;}
case 1 /* Expression */: {
[[maybe_unused]] auto const& that = this->template get<CheckedMatchCase::Expression>();
TRY(builder.append("CheckedMatchCase::Expression"sv));
TRY(builder.append("("sv));
{
JaktInternal::PrettyPrint::ScopedLevelIncrease increase_indent {};
TRY(JaktInternal::PrettyPrint::output_indentation(builder));
TRY(builder.appendff("defaults: {}", that.defaults));
TRY(builder.append(", "sv));
TRY(JaktInternal::PrettyPrint::output_indentation(builder));
TRY(builder.appendff("expression: {}", that.expression));
TRY(builder.append(", "sv));
TRY(JaktInternal::PrettyPrint::output_indentation(builder));
TRY(builder.appendff("body: {}", that.body));
TRY(builder.append(", "sv));
TRY(JaktInternal::PrettyPrint::output_indentation(builder));
TRY(builder.appendff("marker_span: {}", that.marker_span));
}
TRY(builder.append(")"sv));
break;}
case 2 /* CatchAll */: {
[[maybe_unused]] auto const& that = this->template get<CheckedMatchCase::CatchAll>();
TRY(builder.append("CheckedMatchCase::CatchAll"sv));
TRY(builder.append("("sv));
{
JaktInternal::PrettyPrint::ScopedLevelIncrease increase_indent {};
TRY(JaktInternal::PrettyPrint::output_indentation(builder));
TRY(builder.appendff("defaults: {}", that.defaults));
TRY(builder.append(", "sv));
TRY(JaktInternal::PrettyPrint::output_indentation(builder));
TRY(builder.appendff("has_arguments: {}", that.has_arguments));
TRY(builder.append(", "sv));
TRY(JaktInternal::PrettyPrint::output_indentation(builder));
TRY(builder.appendff("body: {}", that.body));
TRY(builder.append(", "sv));
TRY(JaktInternal::PrettyPrint::output_indentation(builder));
TRY(builder.appendff("marker_span: {}", that.marker_span));
}
TRY(builder.append(")"sv));
break;}
}
return builder.to_string();
}
ErrorOr<DeprecatedString> types::CheckedTypeCast::debug_description() const {
auto builder = TRY(DeprecatedStringBuilder::create());
switch (this->index()) {case 0 /* Fallible */: {
[[maybe_unused]] auto const& that = this->template get<CheckedTypeCast::Fallible>();
TRY(builder.append("CheckedTypeCast::Fallible"sv));
TRY(builder.appendff("({})", that.value));
break;}
case 1 /* Infallible */: {
[[maybe_unused]] auto const& that = this->template get<CheckedTypeCast::Infallible>();
TRY(builder.append("CheckedTypeCast::Infallible"sv));
TRY(builder.appendff("({})", that.value));
break;}
}
return builder.to_string();
}
types::TypeId types::CheckedTypeCast::type_id() const {
{
return (JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<types::TypeId, types::TypeId>{
auto&& __jakt_match_variant = *this;
switch(__jakt_match_variant.index()) {
case 0: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::CheckedTypeCast::Fallible>();
types::TypeId const& type_id = __jakt_match_value.value;
return JaktInternal::ExplicitValue(type_id);
};/*case end*/
case 1: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::CheckedTypeCast::Infallible>();
types::TypeId const& type_id = __jakt_match_value.value;
return JaktInternal::ExplicitValue(type_id);
};/*case end*/
default: VERIFY_NOT_REACHED();}/*switch end*/
}()
)));
}
}

ErrorOr<DeprecatedString> types::NumberConstant::debug_description() const {
auto builder = TRY(DeprecatedStringBuilder::create());
switch (this->index()) {case 0 /* Signed */: {
[[maybe_unused]] auto const& that = this->template get<NumberConstant::Signed>();
TRY(builder.append("NumberConstant::Signed"sv));
TRY(builder.appendff("({})", that.value));
break;}
case 1 /* Unsigned */: {
[[maybe_unused]] auto const& that = this->template get<NumberConstant::Unsigned>();
TRY(builder.append("NumberConstant::Unsigned"sv));
TRY(builder.appendff("({})", that.value));
break;}
case 2 /* Floating */: {
[[maybe_unused]] auto const& that = this->template get<NumberConstant::Floating>();
TRY(builder.append("NumberConstant::Floating"sv));
TRY(builder.appendff("({})", that.value));
break;}
}
return builder.to_string();
}
size_t types::NumberConstant::to_usize() const {
{
return (JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<size_t, size_t>{
auto&& __jakt_match_variant = *this;
switch(__jakt_match_variant.index()) {
case 0: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::NumberConstant::Signed>();
i64 const& value = __jakt_match_value.value;
return JaktInternal::ExplicitValue((infallible_integer_cast<size_t>((value))));
};/*case end*/
case 1: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::NumberConstant::Unsigned>();
u64 const& value = __jakt_match_value.value;
return JaktInternal::ExplicitValue((infallible_integer_cast<size_t>((value))));
};/*case end*/
case 2: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::NumberConstant::Floating>();
f64 const& value = __jakt_match_value.value;
{
utility::panic(Jakt::DeprecatedString("to_usize on a floating point constant"sv));
}
};/*case end*/
default: VERIFY_NOT_REACHED();}/*switch end*/
}()
)));
}
}

bool types::NumberConstant::can_fit_number(types::TypeId const type_id,NonnullRefPtr<types::CheckedProgram> const program) const {
{
NonnullRefPtr<typename types::Type> const type_ = ((program)->get_type(type_id));
return (JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<bool, bool>{
auto&& __jakt_match_variant = *this;
switch(__jakt_match_variant.index()) {
case 0: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::NumberConstant::Signed>();
i64 const& value = __jakt_match_value.value;
return JaktInternal::ExplicitValue(JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<bool, bool>{
auto&& __jakt_match_variant = *type_;
switch(__jakt_match_variant.index()) {
case 9: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::Type::I64>();
return JaktInternal::ExplicitValue(true);
};/*case end*/
case 5: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::Type::U64>();
return JaktInternal::ExplicitValue((value >= static_cast<i64>(0LL)));
};/*case end*/
case 12: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::Type::Usize>();
return JaktInternal::ExplicitValue((value >= static_cast<i64>(0LL)));
};/*case end*/
default: {
return JaktInternal::ExplicitValue(((((program)->is_integer(type_id)) && (value >= ((type_)->min()))) && (value <= (infallible_integer_cast<i64>((((type_)->max())))))));
};/*case end*/
}/*switch end*/
}()
)));
};/*case end*/
case 1: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::NumberConstant::Unsigned>();
u64 const& value = __jakt_match_value.value;
return JaktInternal::ExplicitValue(JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<bool, bool>{
auto&& __jakt_match_variant = *type_;
switch(__jakt_match_variant.index()) {
case 5: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::Type::U64>();
return JaktInternal::ExplicitValue(true);
};/*case end*/
case 12: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::Type::Usize>();
return JaktInternal::ExplicitValue(true);
};/*case end*/
default: {
return JaktInternal::ExplicitValue((((program)->is_integer(type_id)) && (value <= ((type_)->max()))));
};/*case end*/
}/*switch end*/
}()
)));
};/*case end*/
case 2: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::NumberConstant::Floating>();
f64 const& value = __jakt_match_value.value;
return JaktInternal::ExplicitValue(JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<bool, bool>{
auto&& __jakt_match_variant = *type_;
switch(__jakt_match_variant.index()) {
case 10: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::Type::F32>();
return JaktInternal::ExplicitValue(({ Optional<bool> __jakt_var_135; {
utility::todo(Jakt::DeprecatedString("Implement casting f32 to f64"sv));
__jakt_var_135 = false; goto __jakt_label_132;

}
__jakt_label_132:; __jakt_var_135.release_value(); }));
};/*case end*/
case 11: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::Type::F64>();
return JaktInternal::ExplicitValue(true);
};/*case end*/
default: {
return JaktInternal::ExplicitValue(false);
};/*case end*/
}/*switch end*/
}()
)));
};/*case end*/
default: VERIFY_NOT_REACHED();}/*switch end*/
}()
)));
}
}

ErrorOr<DeprecatedString> types::CheckedUnaryOperator::debug_description() const {
auto builder = TRY(DeprecatedStringBuilder::create());
switch (this->index()) {case 0 /* PreIncrement */: {
[[maybe_unused]] auto const& that = this->template get<CheckedUnaryOperator::PreIncrement>();
TRY(builder.append("CheckedUnaryOperator::PreIncrement"sv));
break;}
case 1 /* PostIncrement */: {
[[maybe_unused]] auto const& that = this->template get<CheckedUnaryOperator::PostIncrement>();
TRY(builder.append("CheckedUnaryOperator::PostIncrement"sv));
break;}
case 2 /* PreDecrement */: {
[[maybe_unused]] auto const& that = this->template get<CheckedUnaryOperator::PreDecrement>();
TRY(builder.append("CheckedUnaryOperator::PreDecrement"sv));
break;}
case 3 /* PostDecrement */: {
[[maybe_unused]] auto const& that = this->template get<CheckedUnaryOperator::PostDecrement>();
TRY(builder.append("CheckedUnaryOperator::PostDecrement"sv));
break;}
case 4 /* Negate */: {
[[maybe_unused]] auto const& that = this->template get<CheckedUnaryOperator::Negate>();
TRY(builder.append("CheckedUnaryOperator::Negate"sv));
break;}
case 5 /* Dereference */: {
[[maybe_unused]] auto const& that = this->template get<CheckedUnaryOperator::Dereference>();
TRY(builder.append("CheckedUnaryOperator::Dereference"sv));
break;}
case 6 /* RawAddress */: {
[[maybe_unused]] auto const& that = this->template get<CheckedUnaryOperator::RawAddress>();
TRY(builder.append("CheckedUnaryOperator::RawAddress"sv));
break;}
case 7 /* Reference */: {
[[maybe_unused]] auto const& that = this->template get<CheckedUnaryOperator::Reference>();
TRY(builder.append("CheckedUnaryOperator::Reference"sv));
break;}
case 8 /* MutableReference */: {
[[maybe_unused]] auto const& that = this->template get<CheckedUnaryOperator::MutableReference>();
TRY(builder.append("CheckedUnaryOperator::MutableReference"sv));
break;}
case 9 /* LogicalNot */: {
[[maybe_unused]] auto const& that = this->template get<CheckedUnaryOperator::LogicalNot>();
TRY(builder.append("CheckedUnaryOperator::LogicalNot"sv));
break;}
case 10 /* BitwiseNot */: {
[[maybe_unused]] auto const& that = this->template get<CheckedUnaryOperator::BitwiseNot>();
TRY(builder.append("CheckedUnaryOperator::BitwiseNot"sv));
break;}
case 11 /* TypeCast */: {
[[maybe_unused]] auto const& that = this->template get<CheckedUnaryOperator::TypeCast>();
TRY(builder.append("CheckedUnaryOperator::TypeCast"sv));
TRY(builder.appendff("({})", that.value));
break;}
case 12 /* Is */: {
[[maybe_unused]] auto const& that = this->template get<CheckedUnaryOperator::Is>();
TRY(builder.append("CheckedUnaryOperator::Is"sv));
TRY(builder.appendff("({})", that.value));
break;}
case 13 /* IsEnumVariant */: {
[[maybe_unused]] auto const& that = this->template get<CheckedUnaryOperator::IsEnumVariant>();
TRY(builder.append("CheckedUnaryOperator::IsEnumVariant"sv));
TRY(builder.append("("sv));
{
JaktInternal::PrettyPrint::ScopedLevelIncrease increase_indent {};
TRY(JaktInternal::PrettyPrint::output_indentation(builder));
TRY(builder.appendff("enum_variant: {}", that.enum_variant));
TRY(builder.append(", "sv));
TRY(JaktInternal::PrettyPrint::output_indentation(builder));
TRY(builder.appendff("bindings: {}", that.bindings));
TRY(builder.append(", "sv));
TRY(JaktInternal::PrettyPrint::output_indentation(builder));
TRY(builder.appendff("type_id: {}", that.type_id));
}
TRY(builder.append(")"sv));
break;}
}
return builder.to_string();
}
ErrorOr<DeprecatedString> types::BlockControlFlow::debug_description() const {
auto builder = TRY(DeprecatedStringBuilder::create());
switch (this->index()) {case 0 /* AlwaysReturns */: {
[[maybe_unused]] auto const& that = this->template get<BlockControlFlow::AlwaysReturns>();
TRY(builder.append("BlockControlFlow::AlwaysReturns"sv));
break;}
case 1 /* AlwaysTransfersControl */: {
[[maybe_unused]] auto const& that = this->template get<BlockControlFlow::AlwaysTransfersControl>();
TRY(builder.append("BlockControlFlow::AlwaysTransfersControl"sv));
TRY(builder.append("("sv));
{
JaktInternal::PrettyPrint::ScopedLevelIncrease increase_indent {};
TRY(JaktInternal::PrettyPrint::output_indentation(builder));
TRY(builder.appendff("might_break: {}", that.might_break));
}
TRY(builder.append(")"sv));
break;}
case 2 /* NeverReturns */: {
[[maybe_unused]] auto const& that = this->template get<BlockControlFlow::NeverReturns>();
TRY(builder.append("BlockControlFlow::NeverReturns"sv));
break;}
case 3 /* MayReturn */: {
[[maybe_unused]] auto const& that = this->template get<BlockControlFlow::MayReturn>();
TRY(builder.append("BlockControlFlow::MayReturn"sv));
break;}
case 4 /* PartialAlwaysReturns */: {
[[maybe_unused]] auto const& that = this->template get<BlockControlFlow::PartialAlwaysReturns>();
TRY(builder.append("BlockControlFlow::PartialAlwaysReturns"sv));
TRY(builder.append("("sv));
{
JaktInternal::PrettyPrint::ScopedLevelIncrease increase_indent {};
TRY(JaktInternal::PrettyPrint::output_indentation(builder));
TRY(builder.appendff("might_break: {}", that.might_break));
}
TRY(builder.append(")"sv));
break;}
case 5 /* PartialAlwaysTransfersControl */: {
[[maybe_unused]] auto const& that = this->template get<BlockControlFlow::PartialAlwaysTransfersControl>();
TRY(builder.append("BlockControlFlow::PartialAlwaysTransfersControl"sv));
TRY(builder.append("("sv));
{
JaktInternal::PrettyPrint::ScopedLevelIncrease increase_indent {};
TRY(JaktInternal::PrettyPrint::output_indentation(builder));
TRY(builder.appendff("might_break: {}", that.might_break));
}
TRY(builder.append(")"sv));
break;}
case 6 /* PartialNeverReturns */: {
[[maybe_unused]] auto const& that = this->template get<BlockControlFlow::PartialNeverReturns>();
TRY(builder.append("BlockControlFlow::PartialNeverReturns"sv));
TRY(builder.append("("sv));
{
JaktInternal::PrettyPrint::ScopedLevelIncrease increase_indent {};
TRY(JaktInternal::PrettyPrint::output_indentation(builder));
TRY(builder.appendff("might_break: {}", that.might_break));
}
TRY(builder.append(")"sv));
break;}
}
return builder.to_string();
}
bool types::BlockControlFlow::always_transfers_control() const {
{
return (JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<bool, bool>{
auto&& __jakt_match_variant = *this;
switch(__jakt_match_variant.index()) {
case 0: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::BlockControlFlow::AlwaysReturns>();
return JaktInternal::ExplicitValue(true);
};/*case end*/
case 1: {
auto&& __jakt_match_value = __jakt_match_variant.template get<types::BlockControlFlow::AlwaysTransfersControl>();return JaktInternal::ExplicitValue(true);
};/*case end*/
default: {
return JaktInternal::ExplicitValue(false);
};/*case end*/
}/*switch end*/
}()
)));
}
}

types::BlockControlFlow types::BlockControlFlow::partial() const {
{
return (JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<types::BlockControlFlow, types::BlockControlFlow>{
auto&& __jakt_match_variant = *this;
switch(__jakt_match_variant.index()) {
case 2: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::BlockControlFlow::NeverReturns>();
return JaktInternal::ExplicitValue( types::BlockControlFlow { typename types::BlockControlFlow::PartialNeverReturns(false) } );
};/*case end*/
case 0: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::BlockControlFlow::AlwaysReturns>();
return JaktInternal::ExplicitValue( types::BlockControlFlow { typename types::BlockControlFlow::PartialAlwaysReturns(false) } );
};/*case end*/
case 3: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::BlockControlFlow::MayReturn>();
return JaktInternal::ExplicitValue( types::BlockControlFlow { typename types::BlockControlFlow::MayReturn() } );
};/*case end*/
case 1: {
auto&& __jakt_match_value = __jakt_match_variant.template get<types::BlockControlFlow::AlwaysTransfersControl>();bool const& might_break = __jakt_match_value.might_break;
return JaktInternal::ExplicitValue( types::BlockControlFlow { typename types::BlockControlFlow::PartialAlwaysTransfersControl(might_break) } );
};/*case end*/
case 5: {
auto&& __jakt_match_value = __jakt_match_variant.template get<types::BlockControlFlow::PartialAlwaysTransfersControl>();bool const& might_break = __jakt_match_value.might_break;
return JaktInternal::ExplicitValue( types::BlockControlFlow { typename types::BlockControlFlow::PartialAlwaysTransfersControl(might_break) } );
};/*case end*/
case 4: {
auto&& __jakt_match_value = __jakt_match_variant.template get<types::BlockControlFlow::PartialAlwaysReturns>();bool const& might_break = __jakt_match_value.might_break;
return JaktInternal::ExplicitValue( types::BlockControlFlow { typename types::BlockControlFlow::PartialAlwaysReturns(might_break) } );
};/*case end*/
case 6: {
auto&& __jakt_match_value = __jakt_match_variant.template get<types::BlockControlFlow::PartialNeverReturns>();bool const& might_break = __jakt_match_value.might_break;
return JaktInternal::ExplicitValue( types::BlockControlFlow { typename types::BlockControlFlow::PartialNeverReturns(might_break) } );
};/*case end*/
default: VERIFY_NOT_REACHED();}/*switch end*/
}()
)));
}
}

bool types::BlockControlFlow::always_returns() const {
{
return (JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<bool, bool>{
auto&& __jakt_match_variant = *this;
switch(__jakt_match_variant.index()) {
case 0: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::BlockControlFlow::AlwaysReturns>();
return JaktInternal::ExplicitValue(true);
};/*case end*/
default: {
return JaktInternal::ExplicitValue(false);
};/*case end*/
}/*switch end*/
}()
)));
}
}

types::BlockControlFlow types::BlockControlFlow::updated(types::BlockControlFlow const second) const {
{
return (JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<types::BlockControlFlow, types::BlockControlFlow>{
auto&& __jakt_match_variant = *this;
switch(__jakt_match_variant.index()) {
case 2: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::BlockControlFlow::NeverReturns>();
return JaktInternal::ExplicitValue( types::BlockControlFlow { typename types::BlockControlFlow::NeverReturns() } );
};/*case end*/
case 0: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::BlockControlFlow::AlwaysReturns>();
return JaktInternal::ExplicitValue( types::BlockControlFlow { typename types::BlockControlFlow::AlwaysReturns() } );
};/*case end*/
case 1: {
auto&& __jakt_match_value = __jakt_match_variant.template get<types::BlockControlFlow::AlwaysTransfersControl>();bool const& might_break = __jakt_match_value.might_break;
return JaktInternal::ExplicitValue( types::BlockControlFlow { typename types::BlockControlFlow::AlwaysTransfersControl(might_break) } );
};/*case end*/
case 3: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::BlockControlFlow::MayReturn>();
return JaktInternal::ExplicitValue(second);
};/*case end*/
case 5: {
auto&& __jakt_match_value = __jakt_match_variant.template get<types::BlockControlFlow::PartialAlwaysTransfersControl>();return JaktInternal::ExplicitValue(((*this).unify_with(second)));
};/*case end*/
case 4: {
auto&& __jakt_match_value = __jakt_match_variant.template get<types::BlockControlFlow::PartialAlwaysReturns>();return JaktInternal::ExplicitValue(((*this).unify_with(second)));
};/*case end*/
case 6: {
auto&& __jakt_match_value = __jakt_match_variant.template get<types::BlockControlFlow::PartialNeverReturns>();return JaktInternal::ExplicitValue(((*this).unify_with(second)));
};/*case end*/
default: VERIFY_NOT_REACHED();}/*switch end*/
}()
)));
}
}

bool types::BlockControlFlow::may_break() const {
{
return (JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<bool, bool>{
auto&& __jakt_match_variant = *this;
switch(__jakt_match_variant.index()) {
case 4: {
auto&& __jakt_match_value = __jakt_match_variant.template get<types::BlockControlFlow::PartialAlwaysReturns>();bool const& might_break = __jakt_match_value.might_break;
return JaktInternal::ExplicitValue(might_break);
};/*case end*/
case 5: {
auto&& __jakt_match_value = __jakt_match_variant.template get<types::BlockControlFlow::PartialAlwaysTransfersControl>();bool const& might_break = __jakt_match_value.might_break;
return JaktInternal::ExplicitValue(might_break);
};/*case end*/
case 6: {
auto&& __jakt_match_value = __jakt_match_variant.template get<types::BlockControlFlow::PartialNeverReturns>();bool const& might_break = __jakt_match_value.might_break;
return JaktInternal::ExplicitValue(might_break);
};/*case end*/
case 1: {
auto&& __jakt_match_value = __jakt_match_variant.template get<types::BlockControlFlow::AlwaysTransfersControl>();bool const& might_break = __jakt_match_value.might_break;
return JaktInternal::ExplicitValue(might_break);
};/*case end*/
default: {
return JaktInternal::ExplicitValue(false);
};/*case end*/
}/*switch end*/
}()
)));
}
}

bool types::BlockControlFlow::is_reachable() const {
{
return (JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<bool, bool>{
auto&& __jakt_match_variant = *this;
switch(__jakt_match_variant.index()) {
case 2: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::BlockControlFlow::NeverReturns>();
return JaktInternal::ExplicitValue(false);
};/*case end*/
case 0: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::BlockControlFlow::AlwaysReturns>();
return JaktInternal::ExplicitValue(false);
};/*case end*/
case 1: {
auto&& __jakt_match_value = __jakt_match_variant.template get<types::BlockControlFlow::AlwaysTransfersControl>();return JaktInternal::ExplicitValue(false);
};/*case end*/
default: {
return JaktInternal::ExplicitValue(true);
};/*case end*/
}/*switch end*/
}()
)));
}
}

bool types::BlockControlFlow::never_returns() const {
{
return (JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<bool, bool>{
auto&& __jakt_match_variant = *this;
switch(__jakt_match_variant.index()) {
case 2: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::BlockControlFlow::NeverReturns>();
return JaktInternal::ExplicitValue(true);
};/*case end*/
default: {
return JaktInternal::ExplicitValue(false);
};/*case end*/
}/*switch end*/
}()
)));
}
}

types::BlockControlFlow types::BlockControlFlow::definitive() const {
{
return (JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<types::BlockControlFlow, types::BlockControlFlow>{
auto&& __jakt_match_variant = *this;
switch(__jakt_match_variant.index()) {
case 2: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::BlockControlFlow::NeverReturns>();
return JaktInternal::ExplicitValue( types::BlockControlFlow { typename types::BlockControlFlow::NeverReturns() } );
};/*case end*/
case 0: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::BlockControlFlow::AlwaysReturns>();
return JaktInternal::ExplicitValue( types::BlockControlFlow { typename types::BlockControlFlow::AlwaysReturns() } );
};/*case end*/
case 1: {
auto&& __jakt_match_value = __jakt_match_variant.template get<types::BlockControlFlow::AlwaysTransfersControl>();bool const& might_break = __jakt_match_value.might_break;
return JaktInternal::ExplicitValue( types::BlockControlFlow { typename types::BlockControlFlow::AlwaysTransfersControl(might_break) } );
};/*case end*/
case 3: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::BlockControlFlow::MayReturn>();
return JaktInternal::ExplicitValue( types::BlockControlFlow { typename types::BlockControlFlow::MayReturn() } );
};/*case end*/
default: {
return JaktInternal::ExplicitValue( types::BlockControlFlow { typename types::BlockControlFlow::MayReturn() } );
};/*case end*/
}/*switch end*/
}()
)));
}
}

bool types::BlockControlFlow::may_return() const {
{
return (JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<bool, bool>{
auto&& __jakt_match_variant = *this;
switch(__jakt_match_variant.index()) {
case 3: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::BlockControlFlow::MayReturn>();
return JaktInternal::ExplicitValue(true);
};/*case end*/
case 4: {
auto&& __jakt_match_value = __jakt_match_variant.template get<types::BlockControlFlow::PartialAlwaysReturns>();return JaktInternal::ExplicitValue(true);
};/*case end*/
case 5: {
auto&& __jakt_match_value = __jakt_match_variant.template get<types::BlockControlFlow::PartialAlwaysTransfersControl>();return JaktInternal::ExplicitValue(true);
};/*case end*/
case 6: {
auto&& __jakt_match_value = __jakt_match_variant.template get<types::BlockControlFlow::PartialNeverReturns>();return JaktInternal::ExplicitValue(true);
};/*case end*/
default: {
return JaktInternal::ExplicitValue(false);
};/*case end*/
}/*switch end*/
}()
)));
}
}

types::BlockControlFlow types::BlockControlFlow::branch_unify_with(types::BlockControlFlow const second) const {
{
return (JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<types::BlockControlFlow, types::BlockControlFlow>{
auto&& __jakt_match_variant = *this;
switch(__jakt_match_variant.index()) {
case 2: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::BlockControlFlow::NeverReturns>();
return JaktInternal::ExplicitValue(second);
};/*case end*/
case 0: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::BlockControlFlow::AlwaysReturns>();
return JaktInternal::ExplicitValue(JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<types::BlockControlFlow, types::BlockControlFlow>{
auto&& __jakt_match_variant = second;
switch(__jakt_match_variant.index()) {
case 2: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::BlockControlFlow::NeverReturns>();
return JaktInternal::ExplicitValue( types::BlockControlFlow { typename types::BlockControlFlow::AlwaysReturns() } );
};/*case end*/
case 0: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::BlockControlFlow::AlwaysReturns>();
return JaktInternal::ExplicitValue( types::BlockControlFlow { typename types::BlockControlFlow::AlwaysReturns() } );
};/*case end*/
case 3: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::BlockControlFlow::MayReturn>();
return JaktInternal::ExplicitValue( types::BlockControlFlow { typename types::BlockControlFlow::MayReturn() } );
};/*case end*/
case 1: {
auto&& __jakt_match_value = __jakt_match_variant.template get<types::BlockControlFlow::AlwaysTransfersControl>();bool const& might_break = __jakt_match_value.might_break;
return JaktInternal::ExplicitValue( types::BlockControlFlow { typename types::BlockControlFlow::AlwaysTransfersControl(might_break) } );
};/*case end*/
case 6: {
auto&& __jakt_match_value = __jakt_match_variant.template get<types::BlockControlFlow::PartialNeverReturns>();bool const& might_break = __jakt_match_value.might_break;
return JaktInternal::ExplicitValue( types::BlockControlFlow { typename types::BlockControlFlow::PartialNeverReturns(might_break) } );
};/*case end*/
case 4: {
auto&& __jakt_match_value = __jakt_match_variant.template get<types::BlockControlFlow::PartialAlwaysReturns>();bool const& might_break = __jakt_match_value.might_break;
return JaktInternal::ExplicitValue( types::BlockControlFlow { typename types::BlockControlFlow::PartialAlwaysReturns(might_break) } );
};/*case end*/
case 5: {
auto&& __jakt_match_value = __jakt_match_variant.template get<types::BlockControlFlow::PartialAlwaysTransfersControl>();bool const& might_break = __jakt_match_value.might_break;
return JaktInternal::ExplicitValue( types::BlockControlFlow { typename types::BlockControlFlow::PartialAlwaysTransfersControl(might_break) } );
};/*case end*/
default: VERIFY_NOT_REACHED();}/*switch end*/
}()
)));
};/*case end*/
case 3: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::BlockControlFlow::MayReturn>();
return JaktInternal::ExplicitValue(JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<types::BlockControlFlow, types::BlockControlFlow>{
auto&& __jakt_match_variant = second;
switch(__jakt_match_variant.index()) {
case 2: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::BlockControlFlow::NeverReturns>();
return JaktInternal::ExplicitValue( types::BlockControlFlow { typename types::BlockControlFlow::MayReturn() } );
};/*case end*/
case 0: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::BlockControlFlow::AlwaysReturns>();
return JaktInternal::ExplicitValue( types::BlockControlFlow { typename types::BlockControlFlow::MayReturn() } );
};/*case end*/
case 3: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::BlockControlFlow::MayReturn>();
return JaktInternal::ExplicitValue( types::BlockControlFlow { typename types::BlockControlFlow::MayReturn() } );
};/*case end*/
case 1: {
auto&& __jakt_match_value = __jakt_match_variant.template get<types::BlockControlFlow::AlwaysTransfersControl>();bool const& might_break = __jakt_match_value.might_break;
return JaktInternal::ExplicitValue( types::BlockControlFlow { typename types::BlockControlFlow::PartialAlwaysTransfersControl(might_break) } );
};/*case end*/
case 6: {
auto&& __jakt_match_value = __jakt_match_variant.template get<types::BlockControlFlow::PartialNeverReturns>();bool const& might_break = __jakt_match_value.might_break;
return JaktInternal::ExplicitValue( types::BlockControlFlow { typename types::BlockControlFlow::PartialNeverReturns(might_break) } );
};/*case end*/
case 4: {
auto&& __jakt_match_value = __jakt_match_variant.template get<types::BlockControlFlow::PartialAlwaysReturns>();bool const& might_break = __jakt_match_value.might_break;
return JaktInternal::ExplicitValue( types::BlockControlFlow { typename types::BlockControlFlow::PartialAlwaysReturns(might_break) } );
};/*case end*/
case 5: {
auto&& __jakt_match_value = __jakt_match_variant.template get<types::BlockControlFlow::PartialAlwaysTransfersControl>();bool const& might_break = __jakt_match_value.might_break;
return JaktInternal::ExplicitValue( types::BlockControlFlow { typename types::BlockControlFlow::PartialAlwaysTransfersControl(might_break) } );
};/*case end*/
default: VERIFY_NOT_REACHED();}/*switch end*/
}()
)));
};/*case end*/
case 6: {
auto&& __jakt_match_value = __jakt_match_variant.template get<types::BlockControlFlow::PartialNeverReturns>();bool const& this_might_break = __jakt_match_value.might_break;
return JaktInternal::ExplicitValue(JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<types::BlockControlFlow, types::BlockControlFlow>{
auto&& __jakt_match_variant = second;
switch(__jakt_match_variant.index()) {
case 2: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::BlockControlFlow::NeverReturns>();
return JaktInternal::ExplicitValue( types::BlockControlFlow { typename types::BlockControlFlow::PartialNeverReturns(this_might_break) } );
};/*case end*/
case 0: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::BlockControlFlow::AlwaysReturns>();
return JaktInternal::ExplicitValue( types::BlockControlFlow { typename types::BlockControlFlow::PartialNeverReturns(this_might_break) } );
};/*case end*/
case 3: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::BlockControlFlow::MayReturn>();
return JaktInternal::ExplicitValue( types::BlockControlFlow { typename types::BlockControlFlow::PartialNeverReturns(this_might_break) } );
};/*case end*/
case 1: {
auto&& __jakt_match_value = __jakt_match_variant.template get<types::BlockControlFlow::AlwaysTransfersControl>();bool const& might_break = __jakt_match_value.might_break;
return JaktInternal::ExplicitValue( types::BlockControlFlow { typename types::BlockControlFlow::PartialAlwaysTransfersControl((might_break || this_might_break)) } );
};/*case end*/
case 6: {
auto&& __jakt_match_value = __jakt_match_variant.template get<types::BlockControlFlow::PartialNeverReturns>();bool const& might_break = __jakt_match_value.might_break;
return JaktInternal::ExplicitValue( types::BlockControlFlow { typename types::BlockControlFlow::PartialNeverReturns((might_break || this_might_break)) } );
};/*case end*/
case 4: {
auto&& __jakt_match_value = __jakt_match_variant.template get<types::BlockControlFlow::PartialAlwaysReturns>();bool const& might_break = __jakt_match_value.might_break;
return JaktInternal::ExplicitValue( types::BlockControlFlow { typename types::BlockControlFlow::PartialAlwaysReturns((might_break || this_might_break)) } );
};/*case end*/
case 5: {
auto&& __jakt_match_value = __jakt_match_variant.template get<types::BlockControlFlow::PartialAlwaysTransfersControl>();bool const& might_break = __jakt_match_value.might_break;
return JaktInternal::ExplicitValue( types::BlockControlFlow { typename types::BlockControlFlow::PartialAlwaysTransfersControl((might_break || this_might_break)) } );
};/*case end*/
default: VERIFY_NOT_REACHED();}/*switch end*/
}()
)));
};/*case end*/
case 4: {
auto&& __jakt_match_value = __jakt_match_variant.template get<types::BlockControlFlow::PartialAlwaysReturns>();bool const& this_might_break = __jakt_match_value.might_break;
return JaktInternal::ExplicitValue(JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<types::BlockControlFlow, types::BlockControlFlow>{
auto&& __jakt_match_variant = second;
switch(__jakt_match_variant.index()) {
case 2: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::BlockControlFlow::NeverReturns>();
return JaktInternal::ExplicitValue( types::BlockControlFlow { typename types::BlockControlFlow::PartialAlwaysReturns(this_might_break) } );
};/*case end*/
case 0: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::BlockControlFlow::AlwaysReturns>();
return JaktInternal::ExplicitValue( types::BlockControlFlow { typename types::BlockControlFlow::PartialAlwaysReturns(this_might_break) } );
};/*case end*/
case 3: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::BlockControlFlow::MayReturn>();
return JaktInternal::ExplicitValue( types::BlockControlFlow { typename types::BlockControlFlow::PartialAlwaysReturns(this_might_break) } );
};/*case end*/
case 1: {
auto&& __jakt_match_value = __jakt_match_variant.template get<types::BlockControlFlow::AlwaysTransfersControl>();bool const& might_break = __jakt_match_value.might_break;
return JaktInternal::ExplicitValue( types::BlockControlFlow { typename types::BlockControlFlow::PartialAlwaysTransfersControl((might_break || this_might_break)) } );
};/*case end*/
case 6: {
auto&& __jakt_match_value = __jakt_match_variant.template get<types::BlockControlFlow::PartialNeverReturns>();bool const& might_break = __jakt_match_value.might_break;
return JaktInternal::ExplicitValue( types::BlockControlFlow { typename types::BlockControlFlow::PartialAlwaysReturns((might_break || this_might_break)) } );
};/*case end*/
case 4: {
auto&& __jakt_match_value = __jakt_match_variant.template get<types::BlockControlFlow::PartialAlwaysReturns>();bool const& might_break = __jakt_match_value.might_break;
return JaktInternal::ExplicitValue( types::BlockControlFlow { typename types::BlockControlFlow::PartialAlwaysReturns((might_break || this_might_break)) } );
};/*case end*/
case 5: {
auto&& __jakt_match_value = __jakt_match_variant.template get<types::BlockControlFlow::PartialAlwaysTransfersControl>();bool const& might_break = __jakt_match_value.might_break;
return JaktInternal::ExplicitValue( types::BlockControlFlow { typename types::BlockControlFlow::PartialAlwaysTransfersControl((might_break || this_might_break)) } );
};/*case end*/
default: VERIFY_NOT_REACHED();}/*switch end*/
}()
)));
};/*case end*/
case 5: {
auto&& __jakt_match_value = __jakt_match_variant.template get<types::BlockControlFlow::PartialAlwaysTransfersControl>();bool const& this_might_break = __jakt_match_value.might_break;
return JaktInternal::ExplicitValue(JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<types::BlockControlFlow, types::BlockControlFlow>{
auto&& __jakt_match_variant = second;
switch(__jakt_match_variant.index()) {
case 2: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::BlockControlFlow::NeverReturns>();
return JaktInternal::ExplicitValue( types::BlockControlFlow { typename types::BlockControlFlow::PartialAlwaysTransfersControl(this_might_break) } );
};/*case end*/
case 0: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::BlockControlFlow::AlwaysReturns>();
return JaktInternal::ExplicitValue( types::BlockControlFlow { typename types::BlockControlFlow::PartialAlwaysTransfersControl(this_might_break) } );
};/*case end*/
case 3: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::BlockControlFlow::MayReturn>();
return JaktInternal::ExplicitValue( types::BlockControlFlow { typename types::BlockControlFlow::PartialAlwaysTransfersControl(this_might_break) } );
};/*case end*/
case 1: {
auto&& __jakt_match_value = __jakt_match_variant.template get<types::BlockControlFlow::AlwaysTransfersControl>();bool const& might_break = __jakt_match_value.might_break;
return JaktInternal::ExplicitValue( types::BlockControlFlow { typename types::BlockControlFlow::PartialAlwaysTransfersControl((might_break || this_might_break)) } );
};/*case end*/
case 6: {
auto&& __jakt_match_value = __jakt_match_variant.template get<types::BlockControlFlow::PartialNeverReturns>();bool const& might_break = __jakt_match_value.might_break;
return JaktInternal::ExplicitValue( types::BlockControlFlow { typename types::BlockControlFlow::PartialAlwaysTransfersControl((might_break || this_might_break)) } );
};/*case end*/
case 4: {
auto&& __jakt_match_value = __jakt_match_variant.template get<types::BlockControlFlow::PartialAlwaysReturns>();bool const& might_break = __jakt_match_value.might_break;
return JaktInternal::ExplicitValue( types::BlockControlFlow { typename types::BlockControlFlow::PartialAlwaysTransfersControl((might_break || this_might_break)) } );
};/*case end*/
case 5: {
auto&& __jakt_match_value = __jakt_match_variant.template get<types::BlockControlFlow::PartialAlwaysTransfersControl>();bool const& might_break = __jakt_match_value.might_break;
return JaktInternal::ExplicitValue( types::BlockControlFlow { typename types::BlockControlFlow::PartialAlwaysTransfersControl((might_break || this_might_break)) } );
};/*case end*/
default: VERIFY_NOT_REACHED();}/*switch end*/
}()
)));
};/*case end*/
case 1: {
auto&& __jakt_match_value = __jakt_match_variant.template get<types::BlockControlFlow::AlwaysTransfersControl>();bool const& this_might_break = __jakt_match_value.might_break;
return JaktInternal::ExplicitValue(JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<types::BlockControlFlow, types::BlockControlFlow>{
auto&& __jakt_match_variant = second;
switch(__jakt_match_variant.index()) {
case 2: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::BlockControlFlow::NeverReturns>();
return JaktInternal::ExplicitValue( types::BlockControlFlow { typename types::BlockControlFlow::AlwaysTransfersControl(this_might_break) } );
};/*case end*/
case 0: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::BlockControlFlow::AlwaysReturns>();
return JaktInternal::ExplicitValue( types::BlockControlFlow { typename types::BlockControlFlow::AlwaysTransfersControl(this_might_break) } );
};/*case end*/
case 3: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::BlockControlFlow::MayReturn>();
return JaktInternal::ExplicitValue( types::BlockControlFlow { typename types::BlockControlFlow::PartialAlwaysTransfersControl(this_might_break) } );
};/*case end*/
case 1: {
auto&& __jakt_match_value = __jakt_match_variant.template get<types::BlockControlFlow::AlwaysTransfersControl>();bool const& might_break = __jakt_match_value.might_break;
return JaktInternal::ExplicitValue( types::BlockControlFlow { typename types::BlockControlFlow::AlwaysTransfersControl((might_break || this_might_break)) } );
};/*case end*/
case 6: {
auto&& __jakt_match_value = __jakt_match_variant.template get<types::BlockControlFlow::PartialNeverReturns>();bool const& might_break = __jakt_match_value.might_break;
return JaktInternal::ExplicitValue( types::BlockControlFlow { typename types::BlockControlFlow::PartialNeverReturns((might_break || this_might_break)) } );
};/*case end*/
case 4: {
auto&& __jakt_match_value = __jakt_match_variant.template get<types::BlockControlFlow::PartialAlwaysReturns>();bool const& might_break = __jakt_match_value.might_break;
return JaktInternal::ExplicitValue( types::BlockControlFlow { typename types::BlockControlFlow::PartialAlwaysReturns((might_break || this_might_break)) } );
};/*case end*/
case 5: {
auto&& __jakt_match_value = __jakt_match_variant.template get<types::BlockControlFlow::PartialAlwaysTransfersControl>();bool const& might_break = __jakt_match_value.might_break;
return JaktInternal::ExplicitValue( types::BlockControlFlow { typename types::BlockControlFlow::PartialAlwaysTransfersControl((might_break || this_might_break)) } );
};/*case end*/
default: VERIFY_NOT_REACHED();}/*switch end*/
}()
)));
};/*case end*/
default: VERIFY_NOT_REACHED();}/*switch end*/
}()
)));
}
}

types::BlockControlFlow types::BlockControlFlow::unify_with(types::BlockControlFlow const second) const {
{
return (JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<types::BlockControlFlow, types::BlockControlFlow>{
auto&& __jakt_match_variant = *this;
switch(__jakt_match_variant.index()) {
case 2: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::BlockControlFlow::NeverReturns>();
return JaktInternal::ExplicitValue(second);
};/*case end*/
case 0: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::BlockControlFlow::AlwaysReturns>();
return JaktInternal::ExplicitValue(JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<types::BlockControlFlow, types::BlockControlFlow>{
auto&& __jakt_match_variant = second;
switch(__jakt_match_variant.index()) {
case 2: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::BlockControlFlow::NeverReturns>();
return JaktInternal::ExplicitValue( types::BlockControlFlow { typename types::BlockControlFlow::AlwaysReturns() } );
};/*case end*/
case 0: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::BlockControlFlow::AlwaysReturns>();
return JaktInternal::ExplicitValue( types::BlockControlFlow { typename types::BlockControlFlow::AlwaysReturns() } );
};/*case end*/
case 1: {
auto&& __jakt_match_value = __jakt_match_variant.template get<types::BlockControlFlow::AlwaysTransfersControl>();bool const& might_break = __jakt_match_value.might_break;
return JaktInternal::ExplicitValue( types::BlockControlFlow { typename types::BlockControlFlow::AlwaysTransfersControl(might_break) } );
};/*case end*/
case 3: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::BlockControlFlow::MayReturn>();
return JaktInternal::ExplicitValue( types::BlockControlFlow { typename types::BlockControlFlow::MayReturn() } );
};/*case end*/
case 4: {
auto&& __jakt_match_value = __jakt_match_variant.template get<types::BlockControlFlow::PartialAlwaysReturns>();return JaktInternal::ExplicitValue( types::BlockControlFlow { typename types::BlockControlFlow::AlwaysReturns() } );
};/*case end*/
case 5: {
auto&& __jakt_match_value = __jakt_match_variant.template get<types::BlockControlFlow::PartialAlwaysTransfersControl>();bool const& might_break = __jakt_match_value.might_break;
return JaktInternal::ExplicitValue( types::BlockControlFlow { typename types::BlockControlFlow::AlwaysTransfersControl(might_break) } );
};/*case end*/
case 6: {
auto&& __jakt_match_value = __jakt_match_variant.template get<types::BlockControlFlow::PartialNeverReturns>();bool const& might_break = __jakt_match_value.might_break;
return JaktInternal::ExplicitValue( types::BlockControlFlow { typename types::BlockControlFlow::AlwaysTransfersControl(might_break) } );
};/*case end*/
default: VERIFY_NOT_REACHED();}/*switch end*/
}()
)));
};/*case end*/
case 1: {
auto&& __jakt_match_value = __jakt_match_variant.template get<types::BlockControlFlow::AlwaysTransfersControl>();bool const& lhs = __jakt_match_value.might_break;
return JaktInternal::ExplicitValue(JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<types::BlockControlFlow, types::BlockControlFlow>{
auto&& __jakt_match_variant = second;
switch(__jakt_match_variant.index()) {
case 2: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::BlockControlFlow::NeverReturns>();
return JaktInternal::ExplicitValue( types::BlockControlFlow { typename types::BlockControlFlow::AlwaysTransfersControl(lhs) } );
};/*case end*/
case 0: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::BlockControlFlow::AlwaysReturns>();
return JaktInternal::ExplicitValue( types::BlockControlFlow { typename types::BlockControlFlow::AlwaysTransfersControl(lhs) } );
};/*case end*/
case 1: {
auto&& __jakt_match_value = __jakt_match_variant.template get<types::BlockControlFlow::AlwaysTransfersControl>();bool const& might_break = __jakt_match_value.might_break;
return JaktInternal::ExplicitValue( types::BlockControlFlow { typename types::BlockControlFlow::AlwaysTransfersControl((lhs || might_break)) } );
};/*case end*/
case 3: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::BlockControlFlow::MayReturn>();
return JaktInternal::ExplicitValue( types::BlockControlFlow { typename types::BlockControlFlow::AlwaysTransfersControl(lhs) } );
};/*case end*/
default: {
return JaktInternal::ExplicitValue( types::BlockControlFlow { typename types::BlockControlFlow::AlwaysTransfersControl(lhs) } );
};/*case end*/
}/*switch end*/
}()
)));
};/*case end*/
case 3: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::BlockControlFlow::MayReturn>();
return JaktInternal::ExplicitValue(JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<types::BlockControlFlow, types::BlockControlFlow>{
auto&& __jakt_match_variant = second;
switch(__jakt_match_variant.index()) {
case 1: {
auto&& __jakt_match_value = __jakt_match_variant.template get<types::BlockControlFlow::AlwaysTransfersControl>();bool const& might_break = __jakt_match_value.might_break;
return JaktInternal::ExplicitValue( types::BlockControlFlow { typename types::BlockControlFlow::AlwaysTransfersControl(might_break) } );
};/*case end*/
case 4: {
auto&& __jakt_match_value = __jakt_match_variant.template get<types::BlockControlFlow::PartialAlwaysReturns>();bool const& might_break = __jakt_match_value.might_break;
return JaktInternal::ExplicitValue( types::BlockControlFlow { typename types::BlockControlFlow::PartialAlwaysReturns(might_break) } );
};/*case end*/
case 5: {
auto&& __jakt_match_value = __jakt_match_variant.template get<types::BlockControlFlow::PartialAlwaysTransfersControl>();bool const& might_break = __jakt_match_value.might_break;
return JaktInternal::ExplicitValue( types::BlockControlFlow { typename types::BlockControlFlow::PartialAlwaysTransfersControl(might_break) } );
};/*case end*/
case 6: {
auto&& __jakt_match_value = __jakt_match_variant.template get<types::BlockControlFlow::PartialNeverReturns>();bool const& might_break = __jakt_match_value.might_break;
return JaktInternal::ExplicitValue( types::BlockControlFlow { typename types::BlockControlFlow::PartialNeverReturns(might_break) } );
};/*case end*/
default: {
return JaktInternal::ExplicitValue( types::BlockControlFlow { typename types::BlockControlFlow::MayReturn() } );
};/*case end*/
}/*switch end*/
}()
)));
};/*case end*/
case 4: {
auto&& __jakt_match_value = __jakt_match_variant.template get<types::BlockControlFlow::PartialAlwaysReturns>();bool const& lhs = __jakt_match_value.might_break;
return JaktInternal::ExplicitValue(JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<types::BlockControlFlow, types::BlockControlFlow>{
auto&& __jakt_match_variant = second;
switch(__jakt_match_variant.index()) {
case 4: {
auto&& __jakt_match_value = __jakt_match_variant.template get<types::BlockControlFlow::PartialAlwaysReturns>();bool const& might_break = __jakt_match_value.might_break;
return JaktInternal::ExplicitValue( types::BlockControlFlow { typename types::BlockControlFlow::PartialAlwaysReturns((lhs || might_break)) } );
};/*case end*/
case 5: {
auto&& __jakt_match_value = __jakt_match_variant.template get<types::BlockControlFlow::PartialAlwaysTransfersControl>();bool const& might_break = __jakt_match_value.might_break;
return JaktInternal::ExplicitValue( types::BlockControlFlow { typename types::BlockControlFlow::PartialAlwaysTransfersControl((lhs || might_break)) } );
};/*case end*/
case 6: {
auto&& __jakt_match_value = __jakt_match_variant.template get<types::BlockControlFlow::PartialNeverReturns>();bool const& might_break = __jakt_match_value.might_break;
return JaktInternal::ExplicitValue( types::BlockControlFlow { typename types::BlockControlFlow::PartialAlwaysTransfersControl((lhs || might_break)) } );
};/*case end*/
case 0: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::BlockControlFlow::AlwaysReturns>();
return JaktInternal::ExplicitValue( types::BlockControlFlow { typename types::BlockControlFlow::AlwaysReturns() } );
};/*case end*/
case 2: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::BlockControlFlow::NeverReturns>();
return JaktInternal::ExplicitValue( types::BlockControlFlow { typename types::BlockControlFlow::AlwaysTransfersControl(lhs) } );
};/*case end*/
case 1: {
auto&& __jakt_match_value = __jakt_match_variant.template get<types::BlockControlFlow::AlwaysTransfersControl>();bool const& might_break = __jakt_match_value.might_break;
return JaktInternal::ExplicitValue( types::BlockControlFlow { typename types::BlockControlFlow::AlwaysTransfersControl((lhs || might_break)) } );
};/*case end*/
case 3: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::BlockControlFlow::MayReturn>();
return JaktInternal::ExplicitValue( types::BlockControlFlow { typename types::BlockControlFlow::MayReturn() } );
};/*case end*/
default: VERIFY_NOT_REACHED();}/*switch end*/
}()
)));
};/*case end*/
case 5: {
auto&& __jakt_match_value = __jakt_match_variant.template get<types::BlockControlFlow::PartialAlwaysTransfersControl>();bool const& lhs = __jakt_match_value.might_break;
return JaktInternal::ExplicitValue(JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<types::BlockControlFlow, types::BlockControlFlow>{
auto&& __jakt_match_variant = second;
switch(__jakt_match_variant.index()) {
case 5: {
auto&& __jakt_match_value = __jakt_match_variant.template get<types::BlockControlFlow::PartialAlwaysTransfersControl>();bool const& might_break = __jakt_match_value.might_break;
return JaktInternal::ExplicitValue( types::BlockControlFlow { typename types::BlockControlFlow::PartialAlwaysTransfersControl((lhs || might_break)) } );
};/*case end*/
case 4: {
auto&& __jakt_match_value = __jakt_match_variant.template get<types::BlockControlFlow::PartialAlwaysReturns>();bool const& might_break = __jakt_match_value.might_break;
return JaktInternal::ExplicitValue( types::BlockControlFlow { typename types::BlockControlFlow::PartialAlwaysTransfersControl((lhs || might_break)) } );
};/*case end*/
case 6: {
auto&& __jakt_match_value = __jakt_match_variant.template get<types::BlockControlFlow::PartialNeverReturns>();bool const& might_break = __jakt_match_value.might_break;
return JaktInternal::ExplicitValue( types::BlockControlFlow { typename types::BlockControlFlow::PartialAlwaysTransfersControl((lhs || might_break)) } );
};/*case end*/
case 0: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::BlockControlFlow::AlwaysReturns>();
return JaktInternal::ExplicitValue( types::BlockControlFlow { typename types::BlockControlFlow::AlwaysTransfersControl(lhs) } );
};/*case end*/
case 2: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::BlockControlFlow::NeverReturns>();
return JaktInternal::ExplicitValue( types::BlockControlFlow { typename types::BlockControlFlow::AlwaysTransfersControl(lhs) } );
};/*case end*/
case 1: {
auto&& __jakt_match_value = __jakt_match_variant.template get<types::BlockControlFlow::AlwaysTransfersControl>();bool const& might_break = __jakt_match_value.might_break;
return JaktInternal::ExplicitValue( types::BlockControlFlow { typename types::BlockControlFlow::AlwaysTransfersControl((lhs || might_break)) } );
};/*case end*/
case 3: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::BlockControlFlow::MayReturn>();
return JaktInternal::ExplicitValue( types::BlockControlFlow { typename types::BlockControlFlow::PartialAlwaysTransfersControl(lhs) } );
};/*case end*/
default: VERIFY_NOT_REACHED();}/*switch end*/
}()
)));
};/*case end*/
case 6: {
auto&& __jakt_match_value = __jakt_match_variant.template get<types::BlockControlFlow::PartialNeverReturns>();bool const& lhs = __jakt_match_value.might_break;
return JaktInternal::ExplicitValue(JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<types::BlockControlFlow, types::BlockControlFlow>{
auto&& __jakt_match_variant = second;
switch(__jakt_match_variant.index()) {
case 6: {
auto&& __jakt_match_value = __jakt_match_variant.template get<types::BlockControlFlow::PartialNeverReturns>();bool const& might_break = __jakt_match_value.might_break;
return JaktInternal::ExplicitValue( types::BlockControlFlow { typename types::BlockControlFlow::PartialNeverReturns((lhs || might_break)) } );
};/*case end*/
case 5: {
auto&& __jakt_match_value = __jakt_match_variant.template get<types::BlockControlFlow::PartialAlwaysTransfersControl>();bool const& might_break = __jakt_match_value.might_break;
return JaktInternal::ExplicitValue( types::BlockControlFlow { typename types::BlockControlFlow::PartialAlwaysTransfersControl((lhs || might_break)) } );
};/*case end*/
case 4: {
auto&& __jakt_match_value = __jakt_match_variant.template get<types::BlockControlFlow::PartialAlwaysReturns>();bool const& might_break = __jakt_match_value.might_break;
return JaktInternal::ExplicitValue( types::BlockControlFlow { typename types::BlockControlFlow::PartialAlwaysTransfersControl((lhs || might_break)) } );
};/*case end*/
case 0: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::BlockControlFlow::AlwaysReturns>();
return JaktInternal::ExplicitValue( types::BlockControlFlow { typename types::BlockControlFlow::AlwaysTransfersControl(lhs) } );
};/*case end*/
case 1: {
auto&& __jakt_match_value = __jakt_match_variant.template get<types::BlockControlFlow::AlwaysTransfersControl>();bool const& might_break = __jakt_match_value.might_break;
return JaktInternal::ExplicitValue( types::BlockControlFlow { typename types::BlockControlFlow::AlwaysTransfersControl((lhs || might_break)) } );
};/*case end*/
case 3: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::BlockControlFlow::MayReturn>();
return JaktInternal::ExplicitValue( types::BlockControlFlow { typename types::BlockControlFlow::PartialNeverReturns(lhs) } );
};/*case end*/
case 2: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::BlockControlFlow::NeverReturns>();
return JaktInternal::ExplicitValue( types::BlockControlFlow { typename types::BlockControlFlow::NeverReturns() } );
};/*case end*/
default: VERIFY_NOT_REACHED();}/*switch end*/
}()
)));
};/*case end*/
default: VERIFY_NOT_REACHED();}/*switch end*/
}()
)));
}
}

ErrorOr<DeprecatedString> types::CheckedCapture::debug_description() const {
auto builder = TRY(DeprecatedStringBuilder::create());
switch (this->index()) {case 0 /* ByValue */: {
[[maybe_unused]] auto const& that = this->template get<CheckedCapture::ByValue>();
TRY(builder.append("CheckedCapture::ByValue"sv));
TRY(builder.append("("sv));
{
JaktInternal::PrettyPrint::ScopedLevelIncrease increase_indent {};
TRY(JaktInternal::PrettyPrint::output_indentation(builder));
TRY(builder.appendff("name: \"{}\"", that.name));
TRY(builder.append(", "sv));
TRY(JaktInternal::PrettyPrint::output_indentation(builder));
TRY(builder.appendff("span: {}", that.span));
}
TRY(builder.append(")"sv));
break;}
case 1 /* ByReference */: {
[[maybe_unused]] auto const& that = this->template get<CheckedCapture::ByReference>();
TRY(builder.append("CheckedCapture::ByReference"sv));
TRY(builder.append("("sv));
{
JaktInternal::PrettyPrint::ScopedLevelIncrease increase_indent {};
TRY(JaktInternal::PrettyPrint::output_indentation(builder));
TRY(builder.appendff("name: \"{}\"", that.name));
TRY(builder.append(", "sv));
TRY(JaktInternal::PrettyPrint::output_indentation(builder));
TRY(builder.appendff("span: {}", that.span));
}
TRY(builder.append(")"sv));
break;}
case 2 /* ByMutableReference */: {
[[maybe_unused]] auto const& that = this->template get<CheckedCapture::ByMutableReference>();
TRY(builder.append("CheckedCapture::ByMutableReference"sv));
TRY(builder.append("("sv));
{
JaktInternal::PrettyPrint::ScopedLevelIncrease increase_indent {};
TRY(JaktInternal::PrettyPrint::output_indentation(builder));
TRY(builder.appendff("name: \"{}\"", that.name));
TRY(builder.append(", "sv));
TRY(JaktInternal::PrettyPrint::output_indentation(builder));
TRY(builder.appendff("span: {}", that.span));
}
TRY(builder.append(")"sv));
break;}
case 3 /* AllByReference */: {
[[maybe_unused]] auto const& that = this->template get<CheckedCapture::AllByReference>();
TRY(builder.append("CheckedCapture::AllByReference"sv));
TRY(builder.append("("sv));
{
JaktInternal::PrettyPrint::ScopedLevelIncrease increase_indent {};
TRY(JaktInternal::PrettyPrint::output_indentation(builder));
TRY(builder.appendff("span: {}", that.span));
}
TRY(builder.append(")"sv));
break;}
}
return builder.to_string();
}
DeprecatedString types::CheckedCapture::name() const {
{
return (JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<DeprecatedString, DeprecatedString>{
auto&& __jakt_match_variant = *this;
switch(__jakt_match_variant.index()) {
case 0: {
auto&& __jakt_match_value = __jakt_match_variant.template get<types::CheckedCapture::ByValue>();DeprecatedString const& name = __jakt_match_value.name;
return JaktInternal::ExplicitValue(name);
};/*case end*/
case 1: {
auto&& __jakt_match_value = __jakt_match_variant.template get<types::CheckedCapture::ByReference>();DeprecatedString const& name = __jakt_match_value.name;
return JaktInternal::ExplicitValue(name);
};/*case end*/
case 2: {
auto&& __jakt_match_value = __jakt_match_variant.template get<types::CheckedCapture::ByMutableReference>();DeprecatedString const& name = __jakt_match_value.name;
return JaktInternal::ExplicitValue(name);
};/*case end*/
case 3: {
auto&& __jakt_match_value = __jakt_match_variant.template get<types::CheckedCapture::AllByReference>();return JaktInternal::ExplicitValue(Jakt::DeprecatedString(""sv));
};/*case end*/
default: VERIFY_NOT_REACHED();}/*switch end*/
}()
)));
}
}

utility::Span types::CheckedCapture::span() const {
{
return (JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<utility::Span, utility::Span>{
auto&& __jakt_match_variant = *this;
switch(__jakt_match_variant.index()) {
case 0: {
auto&& __jakt_match_value = __jakt_match_variant.template get<types::CheckedCapture::ByValue>();utility::Span const& span = __jakt_match_value.span;
return JaktInternal::ExplicitValue(span);
};/*case end*/
case 1: {
auto&& __jakt_match_value = __jakt_match_variant.template get<types::CheckedCapture::ByReference>();utility::Span const& span = __jakt_match_value.span;
return JaktInternal::ExplicitValue(span);
};/*case end*/
case 2: {
auto&& __jakt_match_value = __jakt_match_variant.template get<types::CheckedCapture::ByMutableReference>();utility::Span const& span = __jakt_match_value.span;
return JaktInternal::ExplicitValue(span);
};/*case end*/
case 3: {
auto&& __jakt_match_value = __jakt_match_variant.template get<types::CheckedCapture::AllByReference>();utility::Span const& span = __jakt_match_value.span;
return JaktInternal::ExplicitValue(span);
};/*case end*/
default: VERIFY_NOT_REACHED();}/*switch end*/
}()
)));
}
}

ErrorOr<DeprecatedString> types::SafetyMode::debug_description() const {
auto builder = TRY(DeprecatedStringBuilder::create());
switch (this->index()) {case 0 /* Safe */: {
[[maybe_unused]] auto const& that = this->template get<SafetyMode::Safe>();
TRY(builder.append("SafetyMode::Safe"sv));
break;}
case 1 /* Unsafe */: {
[[maybe_unused]] auto const& that = this->template get<SafetyMode::Unsafe>();
TRY(builder.append("SafetyMode::Unsafe"sv));
break;}
}
return builder.to_string();
}
ErrorOr<DeprecatedString> types::MaybeResolvedScope::debug_description() const {
auto builder = TRY(DeprecatedStringBuilder::create());
switch (this->index()) {case 0 /* Resolved */: {
[[maybe_unused]] auto const& that = this->template get<MaybeResolvedScope::Resolved>();
TRY(builder.append("MaybeResolvedScope::Resolved"sv));
TRY(builder.appendff("({})", that.value));
break;}
case 1 /* Unresolved */: {
[[maybe_unused]] auto const& that = this->template get<MaybeResolvedScope::Unresolved>();
TRY(builder.append("MaybeResolvedScope::Unresolved"sv));
TRY(builder.append("("sv));
{
JaktInternal::PrettyPrint::ScopedLevelIncrease increase_indent {};
TRY(JaktInternal::PrettyPrint::output_indentation(builder));
TRY(builder.appendff("parent_scope: {}", that.parent_scope));
TRY(builder.append(", "sv));
TRY(JaktInternal::PrettyPrint::output_indentation(builder));
TRY(builder.appendff("relative_name: \"{}\"", that.relative_name));
}
TRY(builder.append(")"sv));
break;}
}
return builder.to_string();
}
ErrorOr<NonnullRefPtr<typename types::MaybeResolvedScope>> types::MaybeResolvedScope::try_resolve(NonnullRefPtr<types::CheckedProgram> const program) const {
{
return (JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<NonnullRefPtr<typename types::MaybeResolvedScope>, ErrorOr<NonnullRefPtr<typename types::MaybeResolvedScope>>>{
auto&& __jakt_match_variant = *this;
switch(__jakt_match_variant.index()) {
case 0: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::MaybeResolvedScope::Resolved>();
types::ScopeId const& id = __jakt_match_value.value;
return JaktInternal::ExplicitValue(TRY((types::MaybeResolvedScope::template create<typename types::MaybeResolvedScope::Resolved>(id))));
};/*case end*/
case 1: {
auto&& __jakt_match_value = __jakt_match_variant.template get<types::MaybeResolvedScope::Unresolved>();NonnullRefPtr<typename types::MaybeResolvedScope> const& parent_scope = __jakt_match_value.parent_scope;
DeprecatedString const& relative_name = __jakt_match_value.relative_name;
return JaktInternal::ExplicitValue(({ Optional<NonnullRefPtr<typename types::MaybeResolvedScope>> __jakt_var_136; {
NonnullRefPtr<typename types::MaybeResolvedScope> parent = TRY((((parent_scope)->try_resolve(program))));
if (((parent)->index() == 0 /* Resolved */)){
types::ScopeId const parent_scope_id = ((parent)->get<types::MaybeResolvedScope::Resolved>()).value;
types::ScopeId const scope = parent_scope_id;
JaktInternal::Optional<types::ScopeId> scope_id = JaktInternal::OptionalNone();
if ((!(((scope_id).has_value())))){
JaktInternal::Optional<types::StructId> const struct_ = TRY((((program)->find_struct_in_scope(scope,relative_name))));
if (((struct_).has_value())){
(scope_id = ((((program)->get_struct((struct_.value())))).scope_id));
}
}
if ((!(((scope_id).has_value())))){
JaktInternal::Optional<types::EnumId> const enum_ = TRY((((program)->find_enum_in_scope(scope,relative_name))));
if (((enum_).has_value())){
(scope_id = ((((program)->get_enum((enum_.value())))).scope_id));
}
}
if ((!(((scope_id).has_value())))){
JaktInternal::Optional<JaktInternal::Tuple<types::ScopeId,bool>> const ns = TRY((((program)->find_namespace_in_scope(scope,relative_name,false))));
if (((ns).has_value())){
(scope_id = (((ns.value())).template get<0>()));
}
}
if ((!(((scope_id).has_value())))){
JaktInternal::Optional<JaktInternal::DynamicArray<types::FunctionId>> const ids = TRY((((program)->find_functions_with_name_in_scope(scope,relative_name))));
if (((ids).has_value())){
(scope_id = ((((program)->get_function((((ids.value()))[static_cast<i64>(0LL)]))))->function_scope_id));
}
}
if (((scope_id).has_value())){
return (TRY((types::MaybeResolvedScope::template create<typename types::MaybeResolvedScope::Resolved>((scope_id.value())))));
}
}
__jakt_var_136 = TRY((types::MaybeResolvedScope::template create<typename types::MaybeResolvedScope::Unresolved>(parent,relative_name))); goto __jakt_label_133;

}
__jakt_label_133:; __jakt_var_136.release_value(); }));
};/*case end*/
default: VERIFY_NOT_REACHED();}/*switch end*/
}()
)));
}
}

ErrorOr<DeprecatedString> types::CheckedExpression::debug_description() const {
auto builder = TRY(DeprecatedStringBuilder::create());
switch (this->index()) {case 0 /* Boolean */: {
[[maybe_unused]] auto const& that = this->template get<CheckedExpression::Boolean>();
TRY(builder.append("CheckedExpression::Boolean"sv));
TRY(builder.append("("sv));
{
JaktInternal::PrettyPrint::ScopedLevelIncrease increase_indent {};
TRY(JaktInternal::PrettyPrint::output_indentation(builder));
TRY(builder.appendff("val: {}", that.val));
TRY(builder.append(", "sv));
TRY(JaktInternal::PrettyPrint::output_indentation(builder));
TRY(builder.appendff("span: {}", that.span));
}
TRY(builder.append(")"sv));
break;}
case 1 /* NumericConstant */: {
[[maybe_unused]] auto const& that = this->template get<CheckedExpression::NumericConstant>();
TRY(builder.append("CheckedExpression::NumericConstant"sv));
TRY(builder.append("("sv));
{
JaktInternal::PrettyPrint::ScopedLevelIncrease increase_indent {};
TRY(JaktInternal::PrettyPrint::output_indentation(builder));
TRY(builder.appendff("val: {}", that.val));
TRY(builder.append(", "sv));
TRY(JaktInternal::PrettyPrint::output_indentation(builder));
TRY(builder.appendff("span: {}", that.span));
TRY(builder.append(", "sv));
TRY(JaktInternal::PrettyPrint::output_indentation(builder));
TRY(builder.appendff("type_id: {}", that.type_id));
}
TRY(builder.append(")"sv));
break;}
case 2 /* QuotedString */: {
[[maybe_unused]] auto const& that = this->template get<CheckedExpression::QuotedString>();
TRY(builder.append("CheckedExpression::QuotedString"sv));
TRY(builder.append("("sv));
{
JaktInternal::PrettyPrint::ScopedLevelIncrease increase_indent {};
TRY(JaktInternal::PrettyPrint::output_indentation(builder));
TRY(builder.appendff("val: {}", that.val));
TRY(builder.append(", "sv));
TRY(JaktInternal::PrettyPrint::output_indentation(builder));
TRY(builder.appendff("span: {}", that.span));
}
TRY(builder.append(")"sv));
break;}
case 3 /* ByteConstant */: {
[[maybe_unused]] auto const& that = this->template get<CheckedExpression::ByteConstant>();
TRY(builder.append("CheckedExpression::ByteConstant"sv));
TRY(builder.append("("sv));
{
JaktInternal::PrettyPrint::ScopedLevelIncrease increase_indent {};
TRY(JaktInternal::PrettyPrint::output_indentation(builder));
TRY(builder.appendff("val: \"{}\"", that.val));
TRY(builder.append(", "sv));
TRY(JaktInternal::PrettyPrint::output_indentation(builder));
TRY(builder.appendff("span: {}", that.span));
}
TRY(builder.append(")"sv));
break;}
case 4 /* CharacterConstant */: {
[[maybe_unused]] auto const& that = this->template get<CheckedExpression::CharacterConstant>();
TRY(builder.append("CheckedExpression::CharacterConstant"sv));
TRY(builder.append("("sv));
{
JaktInternal::PrettyPrint::ScopedLevelIncrease increase_indent {};
TRY(JaktInternal::PrettyPrint::output_indentation(builder));
TRY(builder.appendff("val: \"{}\"", that.val));
TRY(builder.append(", "sv));
TRY(JaktInternal::PrettyPrint::output_indentation(builder));
TRY(builder.appendff("span: {}", that.span));
}
TRY(builder.append(")"sv));
break;}
case 5 /* UnaryOp */: {
[[maybe_unused]] auto const& that = this->template get<CheckedExpression::UnaryOp>();
TRY(builder.append("CheckedExpression::UnaryOp"sv));
TRY(builder.append("("sv));
{
JaktInternal::PrettyPrint::ScopedLevelIncrease increase_indent {};
TRY(JaktInternal::PrettyPrint::output_indentation(builder));
TRY(builder.appendff("expr: {}", that.expr));
TRY(builder.append(", "sv));
TRY(JaktInternal::PrettyPrint::output_indentation(builder));
TRY(builder.appendff("op: {}", that.op));
TRY(builder.append(", "sv));
TRY(JaktInternal::PrettyPrint::output_indentation(builder));
TRY(builder.appendff("span: {}", that.span));
TRY(builder.append(", "sv));
TRY(JaktInternal::PrettyPrint::output_indentation(builder));
TRY(builder.appendff("type_id: {}", that.type_id));
}
TRY(builder.append(")"sv));
break;}
case 6 /* BinaryOp */: {
[[maybe_unused]] auto const& that = this->template get<CheckedExpression::BinaryOp>();
TRY(builder.append("CheckedExpression::BinaryOp"sv));
TRY(builder.append("("sv));
{
JaktInternal::PrettyPrint::ScopedLevelIncrease increase_indent {};
TRY(JaktInternal::PrettyPrint::output_indentation(builder));
TRY(builder.appendff("lhs: {}", that.lhs));
TRY(builder.append(", "sv));
TRY(JaktInternal::PrettyPrint::output_indentation(builder));
TRY(builder.appendff("op: {}", that.op));
TRY(builder.append(", "sv));
TRY(JaktInternal::PrettyPrint::output_indentation(builder));
TRY(builder.appendff("rhs: {}", that.rhs));
TRY(builder.append(", "sv));
TRY(JaktInternal::PrettyPrint::output_indentation(builder));
TRY(builder.appendff("span: {}", that.span));
TRY(builder.append(", "sv));
TRY(JaktInternal::PrettyPrint::output_indentation(builder));
TRY(builder.appendff("type_id: {}", that.type_id));
}
TRY(builder.append(")"sv));
break;}
case 7 /* JaktTuple */: {
[[maybe_unused]] auto const& that = this->template get<CheckedExpression::JaktTuple>();
TRY(builder.append("CheckedExpression::JaktTuple"sv));
TRY(builder.append("("sv));
{
JaktInternal::PrettyPrint::ScopedLevelIncrease increase_indent {};
TRY(JaktInternal::PrettyPrint::output_indentation(builder));
TRY(builder.appendff("vals: {}", that.vals));
TRY(builder.append(", "sv));
TRY(JaktInternal::PrettyPrint::output_indentation(builder));
TRY(builder.appendff("span: {}", that.span));
TRY(builder.append(", "sv));
TRY(JaktInternal::PrettyPrint::output_indentation(builder));
TRY(builder.appendff("type_id: {}", that.type_id));
}
TRY(builder.append(")"sv));
break;}
case 8 /* Range */: {
[[maybe_unused]] auto const& that = this->template get<CheckedExpression::Range>();
TRY(builder.append("CheckedExpression::Range"sv));
TRY(builder.append("("sv));
{
JaktInternal::PrettyPrint::ScopedLevelIncrease increase_indent {};
TRY(JaktInternal::PrettyPrint::output_indentation(builder));
TRY(builder.appendff("from: {}", that.from));
TRY(builder.append(", "sv));
TRY(JaktInternal::PrettyPrint::output_indentation(builder));
TRY(builder.appendff("to: {}", that.to));
TRY(builder.append(", "sv));
TRY(JaktInternal::PrettyPrint::output_indentation(builder));
TRY(builder.appendff("span: {}", that.span));
TRY(builder.append(", "sv));
TRY(JaktInternal::PrettyPrint::output_indentation(builder));
TRY(builder.appendff("type_id: {}", that.type_id));
}
TRY(builder.append(")"sv));
break;}
case 9 /* JaktArray */: {
[[maybe_unused]] auto const& that = this->template get<CheckedExpression::JaktArray>();
TRY(builder.append("CheckedExpression::JaktArray"sv));
TRY(builder.append("("sv));
{
JaktInternal::PrettyPrint::ScopedLevelIncrease increase_indent {};
TRY(JaktInternal::PrettyPrint::output_indentation(builder));
TRY(builder.appendff("vals: {}", that.vals));
TRY(builder.append(", "sv));
TRY(JaktInternal::PrettyPrint::output_indentation(builder));
TRY(builder.appendff("repeat: {}", that.repeat));
TRY(builder.append(", "sv));
TRY(JaktInternal::PrettyPrint::output_indentation(builder));
TRY(builder.appendff("span: {}", that.span));
TRY(builder.append(", "sv));
TRY(JaktInternal::PrettyPrint::output_indentation(builder));
TRY(builder.appendff("type_id: {}", that.type_id));
TRY(builder.append(", "sv));
TRY(JaktInternal::PrettyPrint::output_indentation(builder));
TRY(builder.appendff("inner_type_id: {}", that.inner_type_id));
}
TRY(builder.append(")"sv));
break;}
case 10 /* JaktSet */: {
[[maybe_unused]] auto const& that = this->template get<CheckedExpression::JaktSet>();
TRY(builder.append("CheckedExpression::JaktSet"sv));
TRY(builder.append("("sv));
{
JaktInternal::PrettyPrint::ScopedLevelIncrease increase_indent {};
TRY(JaktInternal::PrettyPrint::output_indentation(builder));
TRY(builder.appendff("vals: {}", that.vals));
TRY(builder.append(", "sv));
TRY(JaktInternal::PrettyPrint::output_indentation(builder));
TRY(builder.appendff("span: {}", that.span));
TRY(builder.append(", "sv));
TRY(JaktInternal::PrettyPrint::output_indentation(builder));
TRY(builder.appendff("type_id: {}", that.type_id));
TRY(builder.append(", "sv));
TRY(JaktInternal::PrettyPrint::output_indentation(builder));
TRY(builder.appendff("inner_type_id: {}", that.inner_type_id));
}
TRY(builder.append(")"sv));
break;}
case 11 /* JaktDictionary */: {
[[maybe_unused]] auto const& that = this->template get<CheckedExpression::JaktDictionary>();
TRY(builder.append("CheckedExpression::JaktDictionary"sv));
TRY(builder.append("("sv));
{
JaktInternal::PrettyPrint::ScopedLevelIncrease increase_indent {};
TRY(JaktInternal::PrettyPrint::output_indentation(builder));
TRY(builder.appendff("vals: {}", that.vals));
TRY(builder.append(", "sv));
TRY(JaktInternal::PrettyPrint::output_indentation(builder));
TRY(builder.appendff("span: {}", that.span));
TRY(builder.append(", "sv));
TRY(JaktInternal::PrettyPrint::output_indentation(builder));
TRY(builder.appendff("type_id: {}", that.type_id));
TRY(builder.append(", "sv));
TRY(JaktInternal::PrettyPrint::output_indentation(builder));
TRY(builder.appendff("key_type_id: {}", that.key_type_id));
TRY(builder.append(", "sv));
TRY(JaktInternal::PrettyPrint::output_indentation(builder));
TRY(builder.appendff("value_type_id: {}", that.value_type_id));
}
TRY(builder.append(")"sv));
break;}
case 12 /* IndexedExpression */: {
[[maybe_unused]] auto const& that = this->template get<CheckedExpression::IndexedExpression>();
TRY(builder.append("CheckedExpression::IndexedExpression"sv));
TRY(builder.append("("sv));
{
JaktInternal::PrettyPrint::ScopedLevelIncrease increase_indent {};
TRY(JaktInternal::PrettyPrint::output_indentation(builder));
TRY(builder.appendff("expr: {}", that.expr));
TRY(builder.append(", "sv));
TRY(JaktInternal::PrettyPrint::output_indentation(builder));
TRY(builder.appendff("index: {}", that.index));
TRY(builder.append(", "sv));
TRY(JaktInternal::PrettyPrint::output_indentation(builder));
TRY(builder.appendff("span: {}", that.span));
TRY(builder.append(", "sv));
TRY(JaktInternal::PrettyPrint::output_indentation(builder));
TRY(builder.appendff("type_id: {}", that.type_id));
}
TRY(builder.append(")"sv));
break;}
case 13 /* IndexedDictionary */: {
[[maybe_unused]] auto const& that = this->template get<CheckedExpression::IndexedDictionary>();
TRY(builder.append("CheckedExpression::IndexedDictionary"sv));
TRY(builder.append("("sv));
{
JaktInternal::PrettyPrint::ScopedLevelIncrease increase_indent {};
TRY(JaktInternal::PrettyPrint::output_indentation(builder));
TRY(builder.appendff("expr: {}", that.expr));
TRY(builder.append(", "sv));
TRY(JaktInternal::PrettyPrint::output_indentation(builder));
TRY(builder.appendff("index: {}", that.index));
TRY(builder.append(", "sv));
TRY(JaktInternal::PrettyPrint::output_indentation(builder));
TRY(builder.appendff("span: {}", that.span));
TRY(builder.append(", "sv));
TRY(JaktInternal::PrettyPrint::output_indentation(builder));
TRY(builder.appendff("type_id: {}", that.type_id));
}
TRY(builder.append(")"sv));
break;}
case 14 /* IndexedTuple */: {
[[maybe_unused]] auto const& that = this->template get<CheckedExpression::IndexedTuple>();
TRY(builder.append("CheckedExpression::IndexedTuple"sv));
TRY(builder.append("("sv));
{
JaktInternal::PrettyPrint::ScopedLevelIncrease increase_indent {};
TRY(JaktInternal::PrettyPrint::output_indentation(builder));
TRY(builder.appendff("expr: {}", that.expr));
TRY(builder.append(", "sv));
TRY(JaktInternal::PrettyPrint::output_indentation(builder));
TRY(builder.appendff("index: {}", that.index));
TRY(builder.append(", "sv));
TRY(JaktInternal::PrettyPrint::output_indentation(builder));
TRY(builder.appendff("span: {}", that.span));
TRY(builder.append(", "sv));
TRY(JaktInternal::PrettyPrint::output_indentation(builder));
TRY(builder.appendff("is_optional: {}", that.is_optional));
TRY(builder.append(", "sv));
TRY(JaktInternal::PrettyPrint::output_indentation(builder));
TRY(builder.appendff("type_id: {}", that.type_id));
}
TRY(builder.append(")"sv));
break;}
case 15 /* IndexedStruct */: {
[[maybe_unused]] auto const& that = this->template get<CheckedExpression::IndexedStruct>();
TRY(builder.append("CheckedExpression::IndexedStruct"sv));
TRY(builder.append("("sv));
{
JaktInternal::PrettyPrint::ScopedLevelIncrease increase_indent {};
TRY(JaktInternal::PrettyPrint::output_indentation(builder));
TRY(builder.appendff("expr: {}", that.expr));
TRY(builder.append(", "sv));
TRY(JaktInternal::PrettyPrint::output_indentation(builder));
TRY(builder.appendff("index: \"{}\"", that.index));
TRY(builder.append(", "sv));
TRY(JaktInternal::PrettyPrint::output_indentation(builder));
TRY(builder.appendff("span: {}", that.span));
TRY(builder.append(", "sv));
TRY(JaktInternal::PrettyPrint::output_indentation(builder));
TRY(builder.appendff("is_optional: {}", that.is_optional));
TRY(builder.append(", "sv));
TRY(JaktInternal::PrettyPrint::output_indentation(builder));
TRY(builder.appendff("type_id: {}", that.type_id));
}
TRY(builder.append(")"sv));
break;}
case 16 /* IndexedCommonEnumMember */: {
[[maybe_unused]] auto const& that = this->template get<CheckedExpression::IndexedCommonEnumMember>();
TRY(builder.append("CheckedExpression::IndexedCommonEnumMember"sv));
TRY(builder.append("("sv));
{
JaktInternal::PrettyPrint::ScopedLevelIncrease increase_indent {};
TRY(JaktInternal::PrettyPrint::output_indentation(builder));
TRY(builder.appendff("expr: {}", that.expr));
TRY(builder.append(", "sv));
TRY(JaktInternal::PrettyPrint::output_indentation(builder));
TRY(builder.appendff("index: \"{}\"", that.index));
TRY(builder.append(", "sv));
TRY(JaktInternal::PrettyPrint::output_indentation(builder));
TRY(builder.appendff("span: {}", that.span));
TRY(builder.append(", "sv));
TRY(JaktInternal::PrettyPrint::output_indentation(builder));
TRY(builder.appendff("is_optional: {}", that.is_optional));
TRY(builder.append(", "sv));
TRY(JaktInternal::PrettyPrint::output_indentation(builder));
TRY(builder.appendff("type_id: {}", that.type_id));
}
TRY(builder.append(")"sv));
break;}
case 17 /* Match */: {
[[maybe_unused]] auto const& that = this->template get<CheckedExpression::Match>();
TRY(builder.append("CheckedExpression::Match"sv));
TRY(builder.append("("sv));
{
JaktInternal::PrettyPrint::ScopedLevelIncrease increase_indent {};
TRY(JaktInternal::PrettyPrint::output_indentation(builder));
TRY(builder.appendff("expr: {}", that.expr));
TRY(builder.append(", "sv));
TRY(JaktInternal::PrettyPrint::output_indentation(builder));
TRY(builder.appendff("match_cases: {}", that.match_cases));
TRY(builder.append(", "sv));
TRY(JaktInternal::PrettyPrint::output_indentation(builder));
TRY(builder.appendff("span: {}", that.span));
TRY(builder.append(", "sv));
TRY(JaktInternal::PrettyPrint::output_indentation(builder));
TRY(builder.appendff("type_id: {}", that.type_id));
TRY(builder.append(", "sv));
TRY(JaktInternal::PrettyPrint::output_indentation(builder));
TRY(builder.appendff("all_variants_constant: {}", that.all_variants_constant));
}
TRY(builder.append(")"sv));
break;}
case 18 /* EnumVariantArg */: {
[[maybe_unused]] auto const& that = this->template get<CheckedExpression::EnumVariantArg>();
TRY(builder.append("CheckedExpression::EnumVariantArg"sv));
TRY(builder.append("("sv));
{
JaktInternal::PrettyPrint::ScopedLevelIncrease increase_indent {};
TRY(JaktInternal::PrettyPrint::output_indentation(builder));
TRY(builder.appendff("expr: {}", that.expr));
TRY(builder.append(", "sv));
TRY(JaktInternal::PrettyPrint::output_indentation(builder));
TRY(builder.appendff("arg: {}", that.arg));
TRY(builder.append(", "sv));
TRY(JaktInternal::PrettyPrint::output_indentation(builder));
TRY(builder.appendff("enum_variant: {}", that.enum_variant));
TRY(builder.append(", "sv));
TRY(JaktInternal::PrettyPrint::output_indentation(builder));
TRY(builder.appendff("span: {}", that.span));
}
TRY(builder.append(")"sv));
break;}
case 19 /* Call */: {
[[maybe_unused]] auto const& that = this->template get<CheckedExpression::Call>();
TRY(builder.append("CheckedExpression::Call"sv));
TRY(builder.append("("sv));
{
JaktInternal::PrettyPrint::ScopedLevelIncrease increase_indent {};
TRY(JaktInternal::PrettyPrint::output_indentation(builder));
TRY(builder.appendff("call: {}", that.call));
TRY(builder.append(", "sv));
TRY(JaktInternal::PrettyPrint::output_indentation(builder));
TRY(builder.appendff("span: {}", that.span));
TRY(builder.append(", "sv));
TRY(JaktInternal::PrettyPrint::output_indentation(builder));
TRY(builder.appendff("type_id: {}", that.type_id));
}
TRY(builder.append(")"sv));
break;}
case 20 /* MethodCall */: {
[[maybe_unused]] auto const& that = this->template get<CheckedExpression::MethodCall>();
TRY(builder.append("CheckedExpression::MethodCall"sv));
TRY(builder.append("("sv));
{
JaktInternal::PrettyPrint::ScopedLevelIncrease increase_indent {};
TRY(JaktInternal::PrettyPrint::output_indentation(builder));
TRY(builder.appendff("expr: {}", that.expr));
TRY(builder.append(", "sv));
TRY(JaktInternal::PrettyPrint::output_indentation(builder));
TRY(builder.appendff("call: {}", that.call));
TRY(builder.append(", "sv));
TRY(JaktInternal::PrettyPrint::output_indentation(builder));
TRY(builder.appendff("span: {}", that.span));
TRY(builder.append(", "sv));
TRY(JaktInternal::PrettyPrint::output_indentation(builder));
TRY(builder.appendff("is_optional: {}", that.is_optional));
TRY(builder.append(", "sv));
TRY(JaktInternal::PrettyPrint::output_indentation(builder));
TRY(builder.appendff("type_id: {}", that.type_id));
}
TRY(builder.append(")"sv));
break;}
case 21 /* NamespacedVar */: {
[[maybe_unused]] auto const& that = this->template get<CheckedExpression::NamespacedVar>();
TRY(builder.append("CheckedExpression::NamespacedVar"sv));
TRY(builder.append("("sv));
{
JaktInternal::PrettyPrint::ScopedLevelIncrease increase_indent {};
TRY(JaktInternal::PrettyPrint::output_indentation(builder));
TRY(builder.appendff("namespaces: {}", that.namespaces));
TRY(builder.append(", "sv));
TRY(JaktInternal::PrettyPrint::output_indentation(builder));
TRY(builder.appendff("var: {}", that.var));
TRY(builder.append(", "sv));
TRY(JaktInternal::PrettyPrint::output_indentation(builder));
TRY(builder.appendff("span: {}", that.span));
}
TRY(builder.append(")"sv));
break;}
case 22 /* Var */: {
[[maybe_unused]] auto const& that = this->template get<CheckedExpression::Var>();
TRY(builder.append("CheckedExpression::Var"sv));
TRY(builder.append("("sv));
{
JaktInternal::PrettyPrint::ScopedLevelIncrease increase_indent {};
TRY(JaktInternal::PrettyPrint::output_indentation(builder));
TRY(builder.appendff("var: {}", that.var));
TRY(builder.append(", "sv));
TRY(JaktInternal::PrettyPrint::output_indentation(builder));
TRY(builder.appendff("span: {}", that.span));
}
TRY(builder.append(")"sv));
break;}
case 23 /* OptionalNone */: {
[[maybe_unused]] auto const& that = this->template get<CheckedExpression::OptionalNone>();
TRY(builder.append("CheckedExpression::OptionalNone"sv));
TRY(builder.append("("sv));
{
JaktInternal::PrettyPrint::ScopedLevelIncrease increase_indent {};
TRY(JaktInternal::PrettyPrint::output_indentation(builder));
TRY(builder.appendff("span: {}", that.span));
TRY(builder.append(", "sv));
TRY(JaktInternal::PrettyPrint::output_indentation(builder));
TRY(builder.appendff("type_id: {}", that.type_id));
}
TRY(builder.append(")"sv));
break;}
case 24 /* OptionalSome */: {
[[maybe_unused]] auto const& that = this->template get<CheckedExpression::OptionalSome>();
TRY(builder.append("CheckedExpression::OptionalSome"sv));
TRY(builder.append("("sv));
{
JaktInternal::PrettyPrint::ScopedLevelIncrease increase_indent {};
TRY(JaktInternal::PrettyPrint::output_indentation(builder));
TRY(builder.appendff("expr: {}", that.expr));
TRY(builder.append(", "sv));
TRY(JaktInternal::PrettyPrint::output_indentation(builder));
TRY(builder.appendff("span: {}", that.span));
TRY(builder.append(", "sv));
TRY(JaktInternal::PrettyPrint::output_indentation(builder));
TRY(builder.appendff("type_id: {}", that.type_id));
}
TRY(builder.append(")"sv));
break;}
case 25 /* ForcedUnwrap */: {
[[maybe_unused]] auto const& that = this->template get<CheckedExpression::ForcedUnwrap>();
TRY(builder.append("CheckedExpression::ForcedUnwrap"sv));
TRY(builder.append("("sv));
{
JaktInternal::PrettyPrint::ScopedLevelIncrease increase_indent {};
TRY(JaktInternal::PrettyPrint::output_indentation(builder));
TRY(builder.appendff("expr: {}", that.expr));
TRY(builder.append(", "sv));
TRY(JaktInternal::PrettyPrint::output_indentation(builder));
TRY(builder.appendff("span: {}", that.span));
TRY(builder.append(", "sv));
TRY(JaktInternal::PrettyPrint::output_indentation(builder));
TRY(builder.appendff("type_id: {}", that.type_id));
}
TRY(builder.append(")"sv));
break;}
case 26 /* Block */: {
[[maybe_unused]] auto const& that = this->template get<CheckedExpression::Block>();
TRY(builder.append("CheckedExpression::Block"sv));
TRY(builder.append("("sv));
{
JaktInternal::PrettyPrint::ScopedLevelIncrease increase_indent {};
TRY(JaktInternal::PrettyPrint::output_indentation(builder));
TRY(builder.appendff("block: {}", that.block));
TRY(builder.append(", "sv));
TRY(JaktInternal::PrettyPrint::output_indentation(builder));
TRY(builder.appendff("span: {}", that.span));
TRY(builder.append(", "sv));
TRY(JaktInternal::PrettyPrint::output_indentation(builder));
TRY(builder.appendff("type_id: {}", that.type_id));
}
TRY(builder.append(")"sv));
break;}
case 27 /* Function */: {
[[maybe_unused]] auto const& that = this->template get<CheckedExpression::Function>();
TRY(builder.append("CheckedExpression::Function"sv));
TRY(builder.append("("sv));
{
JaktInternal::PrettyPrint::ScopedLevelIncrease increase_indent {};
TRY(JaktInternal::PrettyPrint::output_indentation(builder));
TRY(builder.appendff("captures: {}", that.captures));
TRY(builder.append(", "sv));
TRY(JaktInternal::PrettyPrint::output_indentation(builder));
TRY(builder.appendff("params: {}", that.params));
TRY(builder.append(", "sv));
TRY(JaktInternal::PrettyPrint::output_indentation(builder));
TRY(builder.appendff("can_throw: {}", that.can_throw));
TRY(builder.append(", "sv));
TRY(JaktInternal::PrettyPrint::output_indentation(builder));
TRY(builder.appendff("return_type_id: {}", that.return_type_id));
TRY(builder.append(", "sv));
TRY(JaktInternal::PrettyPrint::output_indentation(builder));
TRY(builder.appendff("block: {}", that.block));
TRY(builder.append(", "sv));
TRY(JaktInternal::PrettyPrint::output_indentation(builder));
TRY(builder.appendff("span: {}", that.span));
TRY(builder.append(", "sv));
TRY(JaktInternal::PrettyPrint::output_indentation(builder));
TRY(builder.appendff("type_id: {}", that.type_id));
TRY(builder.append(", "sv));
TRY(JaktInternal::PrettyPrint::output_indentation(builder));
TRY(builder.appendff("pseudo_function_id: {}", that.pseudo_function_id));
}
TRY(builder.append(")"sv));
break;}
case 28 /* Try */: {
[[maybe_unused]] auto const& that = this->template get<CheckedExpression::Try>();
TRY(builder.append("CheckedExpression::Try"sv));
TRY(builder.append("("sv));
{
JaktInternal::PrettyPrint::ScopedLevelIncrease increase_indent {};
TRY(JaktInternal::PrettyPrint::output_indentation(builder));
TRY(builder.appendff("expr: {}", that.expr));
TRY(builder.append(", "sv));
TRY(JaktInternal::PrettyPrint::output_indentation(builder));
TRY(builder.appendff("catch_block: {}", that.catch_block));
TRY(builder.append(", "sv));
TRY(JaktInternal::PrettyPrint::output_indentation(builder));
TRY(builder.appendff("catch_name: {}", that.catch_name));
TRY(builder.append(", "sv));
TRY(JaktInternal::PrettyPrint::output_indentation(builder));
TRY(builder.appendff("span: {}", that.span));
TRY(builder.append(", "sv));
TRY(JaktInternal::PrettyPrint::output_indentation(builder));
TRY(builder.appendff("type_id: {}", that.type_id));
TRY(builder.append(", "sv));
TRY(JaktInternal::PrettyPrint::output_indentation(builder));
TRY(builder.appendff("inner_type_id: {}", that.inner_type_id));
}
TRY(builder.append(")"sv));
break;}
case 29 /* TryBlock */: {
[[maybe_unused]] auto const& that = this->template get<CheckedExpression::TryBlock>();
TRY(builder.append("CheckedExpression::TryBlock"sv));
TRY(builder.append("("sv));
{
JaktInternal::PrettyPrint::ScopedLevelIncrease increase_indent {};
TRY(JaktInternal::PrettyPrint::output_indentation(builder));
TRY(builder.appendff("stmt: {}", that.stmt));
TRY(builder.append(", "sv));
TRY(JaktInternal::PrettyPrint::output_indentation(builder));
TRY(builder.appendff("catch_block: {}", that.catch_block));
TRY(builder.append(", "sv));
TRY(JaktInternal::PrettyPrint::output_indentation(builder));
TRY(builder.appendff("error_name: \"{}\"", that.error_name));
TRY(builder.append(", "sv));
TRY(JaktInternal::PrettyPrint::output_indentation(builder));
TRY(builder.appendff("error_span: {}", that.error_span));
TRY(builder.append(", "sv));
TRY(JaktInternal::PrettyPrint::output_indentation(builder));
TRY(builder.appendff("span: {}", that.span));
TRY(builder.append(", "sv));
TRY(JaktInternal::PrettyPrint::output_indentation(builder));
TRY(builder.appendff("type_id: {}", that.type_id));
}
TRY(builder.append(")"sv));
break;}
case 30 /* Garbage */: {
[[maybe_unused]] auto const& that = this->template get<CheckedExpression::Garbage>();
TRY(builder.append("CheckedExpression::Garbage"sv));
TRY(builder.appendff("({})", that.value));
break;}
}
return builder.to_string();
}
bool types::CheckedExpression::can_throw() const {
{
return (JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<bool, bool>{
auto&& __jakt_match_variant = *this;
switch(__jakt_match_variant.index()) {
case 19: {
auto&& __jakt_match_value = __jakt_match_variant.template get<types::CheckedExpression::Call>();types::CheckedCall const& call = __jakt_match_value.call;
return JaktInternal::ExplicitValue(((call).callee_throws));
};/*case end*/
case 20: {
auto&& __jakt_match_value = __jakt_match_variant.template get<types::CheckedExpression::MethodCall>();types::CheckedCall const& call = __jakt_match_value.call;
return JaktInternal::ExplicitValue(((call).callee_throws));
};/*case end*/
default: {
return JaktInternal::ExplicitValue(false);
};/*case end*/
}/*switch end*/
}()
)));
}
}

utility::Span types::CheckedExpression::span() const {
{
return (JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<utility::Span, utility::Span>{
auto&& __jakt_match_variant = *this;
switch(__jakt_match_variant.index()) {
case 0: {
auto&& __jakt_match_value = __jakt_match_variant.template get<types::CheckedExpression::Boolean>();utility::Span const& span = __jakt_match_value.span;
return JaktInternal::ExplicitValue(span);
};/*case end*/
case 1: {
auto&& __jakt_match_value = __jakt_match_variant.template get<types::CheckedExpression::NumericConstant>();utility::Span const& span = __jakt_match_value.span;
return JaktInternal::ExplicitValue(span);
};/*case end*/
case 2: {
auto&& __jakt_match_value = __jakt_match_variant.template get<types::CheckedExpression::QuotedString>();utility::Span const& span = __jakt_match_value.span;
return JaktInternal::ExplicitValue(span);
};/*case end*/
case 3: {
auto&& __jakt_match_value = __jakt_match_variant.template get<types::CheckedExpression::ByteConstant>();utility::Span const& span = __jakt_match_value.span;
return JaktInternal::ExplicitValue(span);
};/*case end*/
case 4: {
auto&& __jakt_match_value = __jakt_match_variant.template get<types::CheckedExpression::CharacterConstant>();utility::Span const& span = __jakt_match_value.span;
return JaktInternal::ExplicitValue(span);
};/*case end*/
case 5: {
auto&& __jakt_match_value = __jakt_match_variant.template get<types::CheckedExpression::UnaryOp>();utility::Span const& span = __jakt_match_value.span;
return JaktInternal::ExplicitValue(span);
};/*case end*/
case 6: {
auto&& __jakt_match_value = __jakt_match_variant.template get<types::CheckedExpression::BinaryOp>();utility::Span const& span = __jakt_match_value.span;
return JaktInternal::ExplicitValue(span);
};/*case end*/
case 7: {
auto&& __jakt_match_value = __jakt_match_variant.template get<types::CheckedExpression::JaktTuple>();utility::Span const& span = __jakt_match_value.span;
return JaktInternal::ExplicitValue(span);
};/*case end*/
case 8: {
auto&& __jakt_match_value = __jakt_match_variant.template get<types::CheckedExpression::Range>();utility::Span const& span = __jakt_match_value.span;
return JaktInternal::ExplicitValue(span);
};/*case end*/
case 9: {
auto&& __jakt_match_value = __jakt_match_variant.template get<types::CheckedExpression::JaktArray>();utility::Span const& span = __jakt_match_value.span;
return JaktInternal::ExplicitValue(span);
};/*case end*/
case 10: {
auto&& __jakt_match_value = __jakt_match_variant.template get<types::CheckedExpression::JaktSet>();utility::Span const& span = __jakt_match_value.span;
return JaktInternal::ExplicitValue(span);
};/*case end*/
case 11: {
auto&& __jakt_match_value = __jakt_match_variant.template get<types::CheckedExpression::JaktDictionary>();utility::Span const& span = __jakt_match_value.span;
return JaktInternal::ExplicitValue(span);
};/*case end*/
case 12: {
auto&& __jakt_match_value = __jakt_match_variant.template get<types::CheckedExpression::IndexedExpression>();utility::Span const& span = __jakt_match_value.span;
return JaktInternal::ExplicitValue(span);
};/*case end*/
case 13: {
auto&& __jakt_match_value = __jakt_match_variant.template get<types::CheckedExpression::IndexedDictionary>();utility::Span const& span = __jakt_match_value.span;
return JaktInternal::ExplicitValue(span);
};/*case end*/
case 14: {
auto&& __jakt_match_value = __jakt_match_variant.template get<types::CheckedExpression::IndexedTuple>();utility::Span const& span = __jakt_match_value.span;
return JaktInternal::ExplicitValue(span);
};/*case end*/
case 15: {
auto&& __jakt_match_value = __jakt_match_variant.template get<types::CheckedExpression::IndexedStruct>();utility::Span const& span = __jakt_match_value.span;
return JaktInternal::ExplicitValue(span);
};/*case end*/
case 16: {
auto&& __jakt_match_value = __jakt_match_variant.template get<types::CheckedExpression::IndexedCommonEnumMember>();utility::Span const& span = __jakt_match_value.span;
return JaktInternal::ExplicitValue(span);
};/*case end*/
case 17: {
auto&& __jakt_match_value = __jakt_match_variant.template get<types::CheckedExpression::Match>();utility::Span const& span = __jakt_match_value.span;
return JaktInternal::ExplicitValue(span);
};/*case end*/
case 18: {
auto&& __jakt_match_value = __jakt_match_variant.template get<types::CheckedExpression::EnumVariantArg>();utility::Span const& span = __jakt_match_value.span;
return JaktInternal::ExplicitValue(span);
};/*case end*/
case 19: {
auto&& __jakt_match_value = __jakt_match_variant.template get<types::CheckedExpression::Call>();utility::Span const& span = __jakt_match_value.span;
return JaktInternal::ExplicitValue(span);
};/*case end*/
case 20: {
auto&& __jakt_match_value = __jakt_match_variant.template get<types::CheckedExpression::MethodCall>();utility::Span const& span = __jakt_match_value.span;
return JaktInternal::ExplicitValue(span);
};/*case end*/
case 21: {
auto&& __jakt_match_value = __jakt_match_variant.template get<types::CheckedExpression::NamespacedVar>();utility::Span const& span = __jakt_match_value.span;
return JaktInternal::ExplicitValue(span);
};/*case end*/
case 22: {
auto&& __jakt_match_value = __jakt_match_variant.template get<types::CheckedExpression::Var>();utility::Span const& span = __jakt_match_value.span;
return JaktInternal::ExplicitValue(span);
};/*case end*/
case 23: {
auto&& __jakt_match_value = __jakt_match_variant.template get<types::CheckedExpression::OptionalNone>();utility::Span const& span = __jakt_match_value.span;
return JaktInternal::ExplicitValue(span);
};/*case end*/
case 24: {
auto&& __jakt_match_value = __jakt_match_variant.template get<types::CheckedExpression::OptionalSome>();utility::Span const& span = __jakt_match_value.span;
return JaktInternal::ExplicitValue(span);
};/*case end*/
case 25: {
auto&& __jakt_match_value = __jakt_match_variant.template get<types::CheckedExpression::ForcedUnwrap>();utility::Span const& span = __jakt_match_value.span;
return JaktInternal::ExplicitValue(span);
};/*case end*/
case 26: {
auto&& __jakt_match_value = __jakt_match_variant.template get<types::CheckedExpression::Block>();utility::Span const& span = __jakt_match_value.span;
return JaktInternal::ExplicitValue(span);
};/*case end*/
case 27: {
auto&& __jakt_match_value = __jakt_match_variant.template get<types::CheckedExpression::Function>();utility::Span const& span = __jakt_match_value.span;
return JaktInternal::ExplicitValue(span);
};/*case end*/
case 28: {
auto&& __jakt_match_value = __jakt_match_variant.template get<types::CheckedExpression::Try>();utility::Span const& span = __jakt_match_value.span;
return JaktInternal::ExplicitValue(span);
};/*case end*/
case 29: {
auto&& __jakt_match_value = __jakt_match_variant.template get<types::CheckedExpression::TryBlock>();utility::Span const& span = __jakt_match_value.span;
return JaktInternal::ExplicitValue(span);
};/*case end*/
case 30: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::CheckedExpression::Garbage>();
utility::Span const& span = __jakt_match_value.value;
return JaktInternal::ExplicitValue(span);
};/*case end*/
default: VERIFY_NOT_REACHED();}/*switch end*/
}()
)));
}
}

JaktInternal::Optional<types::NumberConstant> types::CheckedExpression::to_number_constant(NonnullRefPtr<types::CheckedProgram> const program) const {
{
return (JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<JaktInternal::Optional<types::NumberConstant>, JaktInternal::Optional<types::NumberConstant>>{
auto&& __jakt_match_variant = *this;
switch(__jakt_match_variant.index()) {
case 1: {
auto&& __jakt_match_value = __jakt_match_variant.template get<types::CheckedExpression::NumericConstant>();types::CheckedNumericConstant const& val = __jakt_match_value.val;
utility::Span const& span = __jakt_match_value.span;
types::TypeId const& type_id = __jakt_match_value.type_id;
return JaktInternal::ExplicitValue(((val).number_constant()));
};/*case end*/
case 5: {
auto&& __jakt_match_value = __jakt_match_variant.template get<types::CheckedExpression::UnaryOp>();NonnullRefPtr<typename types::CheckedExpression> const& expr = __jakt_match_value.expr;
types::CheckedUnaryOperator const& op = __jakt_match_value.op;
utility::Span const& span = __jakt_match_value.span;
types::TypeId const& type_id = __jakt_match_value.type_id;
return JaktInternal::ExplicitValue(({ Optional<JaktInternal::Optional<types::NumberConstant>> __jakt_var_137; {
JaktInternal::Optional<types::NumberConstant> result = JaktInternal::OptionalNone();
__jakt_var_137 = JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<JaktInternal::Optional<types::NumberConstant>,JaktInternal::Optional<types::NumberConstant>>{
auto __jakt_enum_value = (((op).index() == 11 /* TypeCast */));
if (__jakt_enum_value == true) {
return JaktInternal::ExplicitValue(({ Optional<JaktInternal::Optional<types::NumberConstant>> __jakt_var_138; {
types::CheckedTypeCast const cast = ((op).get<types::CheckedUnaryOperator::TypeCast>()).value;
if ((!(((cast).index() == 1 /* Infallible */)))){
(result = JaktInternal::OptionalNone());
}
if (((!(((program)->is_integer(type_id)))) && (!(((program)->is_floating(type_id)))))){
(result = JaktInternal::OptionalNone());
}
if (((expr)->index() == 1 /* NumericConstant */)){
types::CheckedNumericConstant const val = ((expr)->get<types::CheckedExpression::NumericConstant>()).val;
(result = ((val).number_constant()));
}
__jakt_var_138 = result; goto __jakt_label_135;

}
__jakt_label_135:; __jakt_var_138.release_value(); }));
}
else {
{
return (JaktInternal::OptionalNone());
}
}
}()))
; goto __jakt_label_134;

}
__jakt_label_134:; __jakt_var_137.release_value(); }));
};/*case end*/
default: {
return JaktInternal::ExplicitValue(JaktInternal::OptionalNone());
};/*case end*/
}/*switch end*/
}()
)));
}
}

types::TypeId types::CheckedExpression::type() const {
{
return (JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<types::TypeId, types::TypeId>{
auto&& __jakt_match_variant = *this;
switch(__jakt_match_variant.index()) {
case 0: {
auto&& __jakt_match_value = __jakt_match_variant.template get<types::CheckedExpression::Boolean>();return JaktInternal::ExplicitValue(types::builtin( types::BuiltinType { typename types::BuiltinType::Bool() } ));
};/*case end*/
case 2: {
auto&& __jakt_match_value = __jakt_match_variant.template get<types::CheckedExpression::QuotedString>();types::CheckedStringLiteral const& val = __jakt_match_value.val;
return JaktInternal::ExplicitValue(((val).type_id));
};/*case end*/
case 3: {
auto&& __jakt_match_value = __jakt_match_variant.template get<types::CheckedExpression::ByteConstant>();return JaktInternal::ExplicitValue(types::builtin( types::BuiltinType { typename types::BuiltinType::U8() } ));
};/*case end*/
case 4: {
auto&& __jakt_match_value = __jakt_match_variant.template get<types::CheckedExpression::CharacterConstant>();return JaktInternal::ExplicitValue(types::builtin( types::BuiltinType { typename types::BuiltinType::CChar() } ));
};/*case end*/
case 18: {
auto&& __jakt_match_value = __jakt_match_variant.template get<types::CheckedExpression::EnumVariantArg>();types::CheckedEnumVariantBinding const& arg = __jakt_match_value.arg;
return JaktInternal::ExplicitValue(((arg).type_id));
};/*case end*/
case 21: {
auto&& __jakt_match_value = __jakt_match_variant.template get<types::CheckedExpression::NamespacedVar>();NonnullRefPtr<types::CheckedVariable> const& var = __jakt_match_value.var;
return JaktInternal::ExplicitValue(((var)->type_id));
};/*case end*/
case 22: {
auto&& __jakt_match_value = __jakt_match_variant.template get<types::CheckedExpression::Var>();NonnullRefPtr<types::CheckedVariable> const& var = __jakt_match_value.var;
return JaktInternal::ExplicitValue(((var)->type_id));
};/*case end*/
case 30: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::CheckedExpression::Garbage>();
return JaktInternal::ExplicitValue(types::builtin( types::BuiltinType { typename types::BuiltinType::Void() } ));
};/*case end*/
case 1: {
auto&& __jakt_match_value = __jakt_match_variant.template get<types::CheckedExpression::NumericConstant>();types::TypeId const& type_id = __jakt_match_value.type_id;
return JaktInternal::ExplicitValue(type_id);
};/*case end*/
case 5: {
auto&& __jakt_match_value = __jakt_match_variant.template get<types::CheckedExpression::UnaryOp>();types::TypeId const& type_id = __jakt_match_value.type_id;
return JaktInternal::ExplicitValue(type_id);
};/*case end*/
case 6: {
auto&& __jakt_match_value = __jakt_match_variant.template get<types::CheckedExpression::BinaryOp>();types::TypeId const& type_id = __jakt_match_value.type_id;
return JaktInternal::ExplicitValue(type_id);
};/*case end*/
case 7: {
auto&& __jakt_match_value = __jakt_match_variant.template get<types::CheckedExpression::JaktTuple>();types::TypeId const& type_id = __jakt_match_value.type_id;
return JaktInternal::ExplicitValue(type_id);
};/*case end*/
case 8: {
auto&& __jakt_match_value = __jakt_match_variant.template get<types::CheckedExpression::Range>();types::TypeId const& type_id = __jakt_match_value.type_id;
return JaktInternal::ExplicitValue(type_id);
};/*case end*/
case 9: {
auto&& __jakt_match_value = __jakt_match_variant.template get<types::CheckedExpression::JaktArray>();types::TypeId const& type_id = __jakt_match_value.type_id;
return JaktInternal::ExplicitValue(type_id);
};/*case end*/
case 10: {
auto&& __jakt_match_value = __jakt_match_variant.template get<types::CheckedExpression::JaktSet>();types::TypeId const& type_id = __jakt_match_value.type_id;
return JaktInternal::ExplicitValue(type_id);
};/*case end*/
case 11: {
auto&& __jakt_match_value = __jakt_match_variant.template get<types::CheckedExpression::JaktDictionary>();types::TypeId const& type_id = __jakt_match_value.type_id;
return JaktInternal::ExplicitValue(type_id);
};/*case end*/
case 12: {
auto&& __jakt_match_value = __jakt_match_variant.template get<types::CheckedExpression::IndexedExpression>();types::TypeId const& type_id = __jakt_match_value.type_id;
return JaktInternal::ExplicitValue(type_id);
};/*case end*/
case 13: {
auto&& __jakt_match_value = __jakt_match_variant.template get<types::CheckedExpression::IndexedDictionary>();types::TypeId const& type_id = __jakt_match_value.type_id;
return JaktInternal::ExplicitValue(type_id);
};/*case end*/
case 14: {
auto&& __jakt_match_value = __jakt_match_variant.template get<types::CheckedExpression::IndexedTuple>();types::TypeId const& type_id = __jakt_match_value.type_id;
return JaktInternal::ExplicitValue(type_id);
};/*case end*/
case 15: {
auto&& __jakt_match_value = __jakt_match_variant.template get<types::CheckedExpression::IndexedStruct>();types::TypeId const& type_id = __jakt_match_value.type_id;
return JaktInternal::ExplicitValue(type_id);
};/*case end*/
case 16: {
auto&& __jakt_match_value = __jakt_match_variant.template get<types::CheckedExpression::IndexedCommonEnumMember>();types::TypeId const& type_id = __jakt_match_value.type_id;
return JaktInternal::ExplicitValue(type_id);
};/*case end*/
case 17: {
auto&& __jakt_match_value = __jakt_match_variant.template get<types::CheckedExpression::Match>();types::TypeId const& type_id = __jakt_match_value.type_id;
return JaktInternal::ExplicitValue(type_id);
};/*case end*/
case 19: {
auto&& __jakt_match_value = __jakt_match_variant.template get<types::CheckedExpression::Call>();types::TypeId const& type_id = __jakt_match_value.type_id;
return JaktInternal::ExplicitValue(type_id);
};/*case end*/
case 20: {
auto&& __jakt_match_value = __jakt_match_variant.template get<types::CheckedExpression::MethodCall>();types::TypeId const& type_id = __jakt_match_value.type_id;
return JaktInternal::ExplicitValue(type_id);
};/*case end*/
case 23: {
auto&& __jakt_match_value = __jakt_match_variant.template get<types::CheckedExpression::OptionalNone>();types::TypeId const& type_id = __jakt_match_value.type_id;
return JaktInternal::ExplicitValue(type_id);
};/*case end*/
case 24: {
auto&& __jakt_match_value = __jakt_match_variant.template get<types::CheckedExpression::OptionalSome>();types::TypeId const& type_id = __jakt_match_value.type_id;
return JaktInternal::ExplicitValue(type_id);
};/*case end*/
case 25: {
auto&& __jakt_match_value = __jakt_match_variant.template get<types::CheckedExpression::ForcedUnwrap>();types::TypeId const& type_id = __jakt_match_value.type_id;
return JaktInternal::ExplicitValue(type_id);
};/*case end*/
case 26: {
auto&& __jakt_match_value = __jakt_match_variant.template get<types::CheckedExpression::Block>();types::TypeId const& type_id = __jakt_match_value.type_id;
return JaktInternal::ExplicitValue(type_id);
};/*case end*/
case 27: {
auto&& __jakt_match_value = __jakt_match_variant.template get<types::CheckedExpression::Function>();types::TypeId const& type_id = __jakt_match_value.type_id;
return JaktInternal::ExplicitValue(type_id);
};/*case end*/
case 28: {
auto&& __jakt_match_value = __jakt_match_variant.template get<types::CheckedExpression::Try>();types::TypeId const& type_id = __jakt_match_value.type_id;
return JaktInternal::ExplicitValue(type_id);
};/*case end*/
case 29: {
auto&& __jakt_match_value = __jakt_match_variant.template get<types::CheckedExpression::TryBlock>();types::TypeId const& type_id = __jakt_match_value.type_id;
return JaktInternal::ExplicitValue(type_id);
};/*case end*/
default: VERIFY_NOT_REACHED();}/*switch end*/
}()
)));
}
}

types::BlockControlFlow types::CheckedExpression::control_flow() const {
{
return (JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<types::BlockControlFlow, types::BlockControlFlow>{
auto&& __jakt_match_variant = *this;
switch(__jakt_match_variant.index()) {
case 17: {
auto&& __jakt_match_value = __jakt_match_variant.template get<types::CheckedExpression::Match>();NonnullRefPtr<typename types::CheckedExpression> const& expr = __jakt_match_value.expr;
JaktInternal::DynamicArray<types::CheckedMatchCase> const& match_cases = __jakt_match_value.match_cases;
utility::Span const& span = __jakt_match_value.span;
types::TypeId const& type_id = __jakt_match_value.type_id;
bool const& all_variants_constant = __jakt_match_value.all_variants_constant;
return JaktInternal::ExplicitValue(({ Optional<types::BlockControlFlow> __jakt_var_139; {
JaktInternal::Optional<types::BlockControlFlow> control_flow = JaktInternal::OptionalNone();
{
JaktInternal::ArrayIterator<types::CheckedMatchCase> _magic = ((match_cases).iterator());
for (;;){
JaktInternal::Optional<types::CheckedMatchCase> _magic_value = ((_magic).next());
if ((!(((_magic_value).has_value())))){
break;
}
types::CheckedMatchCase case_ = (_magic_value.value());
{
types::BlockControlFlow const case_control_flow = JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_AT_LOOP(([&]() -> JaktInternal::ExplicitValueOrControlFlow<types::BlockControlFlow, types::BlockControlFlow>{
auto&& __jakt_match_variant = case_;
switch(__jakt_match_variant.index()) {
case 0: {
auto&& __jakt_match_value = __jakt_match_variant.template get<types::CheckedMatchCase::EnumVariant>();types::CheckedMatchBody const& body = __jakt_match_value.body;
return JaktInternal::ExplicitValue(JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_AT_LOOP_NESTED_MATCH(([&]() -> JaktInternal::ExplicitValueOrControlFlow<types::BlockControlFlow, types::BlockControlFlow>{
auto&& __jakt_match_variant = body;
switch(__jakt_match_variant.index()) {
case 1: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::CheckedMatchBody::Block>();
types::CheckedBlock const& block = __jakt_match_value.value;
return JaktInternal::ExplicitValue(((block).control_flow));
};/*case end*/
case 0: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::CheckedMatchBody::Expression>();
NonnullRefPtr<typename types::CheckedExpression> const& expr = __jakt_match_value.value;
return JaktInternal::ExplicitValue(((expr)->control_flow()));
};/*case end*/
default: VERIFY_NOT_REACHED();}/*switch end*/
}()
)));
};/*case end*/
case 1: {
auto&& __jakt_match_value = __jakt_match_variant.template get<types::CheckedMatchCase::Expression>();types::CheckedMatchBody const& body = __jakt_match_value.body;
return JaktInternal::ExplicitValue(JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_AT_LOOP_NESTED_MATCH(([&]() -> JaktInternal::ExplicitValueOrControlFlow<types::BlockControlFlow, types::BlockControlFlow>{
auto&& __jakt_match_variant = body;
switch(__jakt_match_variant.index()) {
case 1: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::CheckedMatchBody::Block>();
types::CheckedBlock const& block = __jakt_match_value.value;
return JaktInternal::ExplicitValue(((block).control_flow));
};/*case end*/
case 0: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::CheckedMatchBody::Expression>();
NonnullRefPtr<typename types::CheckedExpression> const& expr = __jakt_match_value.value;
return JaktInternal::ExplicitValue(((expr)->control_flow()));
};/*case end*/
default: VERIFY_NOT_REACHED();}/*switch end*/
}()
)));
};/*case end*/
case 2: {
auto&& __jakt_match_value = __jakt_match_variant.template get<types::CheckedMatchCase::CatchAll>();types::CheckedMatchBody const& body = __jakt_match_value.body;
return JaktInternal::ExplicitValue(JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_AT_LOOP_NESTED_MATCH(([&]() -> JaktInternal::ExplicitValueOrControlFlow<types::BlockControlFlow, types::BlockControlFlow>{
auto&& __jakt_match_variant = body;
switch(__jakt_match_variant.index()) {
case 1: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::CheckedMatchBody::Block>();
types::CheckedBlock const& block = __jakt_match_value.value;
return JaktInternal::ExplicitValue(((block).control_flow));
};/*case end*/
case 0: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::CheckedMatchBody::Expression>();
NonnullRefPtr<typename types::CheckedExpression> const& expr = __jakt_match_value.value;
return JaktInternal::ExplicitValue(((expr)->control_flow()));
};/*case end*/
default: VERIFY_NOT_REACHED();}/*switch end*/
}()
)));
};/*case end*/
default: VERIFY_NOT_REACHED();}/*switch end*/
}()
));
if (((control_flow).has_value())){
(control_flow = (((control_flow.value())).branch_unify_with(case_control_flow)));
}
else {
(control_flow = case_control_flow);
}

}

}
}

__jakt_var_139 = control_flow.value_or_lazy_evaluated([&] { return  types::BlockControlFlow { typename types::BlockControlFlow::MayReturn() } ; }); goto __jakt_label_136;

}
__jakt_label_136:; __jakt_var_139.release_value(); }));
};/*case end*/
case 20: {
auto&& __jakt_match_value = __jakt_match_variant.template get<types::CheckedExpression::MethodCall>();types::TypeId const& type_id = __jakt_match_value.type_id;
return JaktInternal::ExplicitValue(JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<types::BlockControlFlow,types::BlockControlFlow>{
auto __jakt_enum_value = (((type_id).equals(types::never_type_id())));
if (__jakt_enum_value == true) {
return JaktInternal::ExplicitValue( types::BlockControlFlow { typename types::BlockControlFlow::NeverReturns() } );
}
else {
return JaktInternal::ExplicitValue( types::BlockControlFlow { typename types::BlockControlFlow::MayReturn() } );
}
}()))
);
};/*case end*/
case 19: {
auto&& __jakt_match_value = __jakt_match_variant.template get<types::CheckedExpression::Call>();types::TypeId const& type_id = __jakt_match_value.type_id;
return JaktInternal::ExplicitValue(JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<types::BlockControlFlow,types::BlockControlFlow>{
auto __jakt_enum_value = (((type_id).equals(types::never_type_id())));
if (__jakt_enum_value == true) {
return JaktInternal::ExplicitValue( types::BlockControlFlow { typename types::BlockControlFlow::NeverReturns() } );
}
else {
return JaktInternal::ExplicitValue( types::BlockControlFlow { typename types::BlockControlFlow::MayReturn() } );
}
}()))
);
};/*case end*/
default: {
return JaktInternal::ExplicitValue( types::BlockControlFlow { typename types::BlockControlFlow::MayReturn() } );
};/*case end*/
}/*switch end*/
}()
)));
}
}

bool types::CheckedExpression::is_mutable(NonnullRefPtr<types::CheckedProgram> const program) const {
{
return (JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<bool, bool>{
auto&& __jakt_match_variant = *this;
switch(__jakt_match_variant.index()) {
case 22: {
auto&& __jakt_match_value = __jakt_match_variant.template get<types::CheckedExpression::Var>();NonnullRefPtr<types::CheckedVariable> const& var = __jakt_match_value.var;
return JaktInternal::ExplicitValue(((var)->is_mutable));
};/*case end*/
case 15: {
auto&& __jakt_match_value = __jakt_match_variant.template get<types::CheckedExpression::IndexedStruct>();NonnullRefPtr<typename types::CheckedExpression> const& expr = __jakt_match_value.expr;
return JaktInternal::ExplicitValue(((expr)->is_mutable(program)));
};/*case end*/
case 12: {
auto&& __jakt_match_value = __jakt_match_variant.template get<types::CheckedExpression::IndexedExpression>();NonnullRefPtr<typename types::CheckedExpression> const& expr = __jakt_match_value.expr;
return JaktInternal::ExplicitValue(((expr)->is_mutable(program)));
};/*case end*/
case 14: {
auto&& __jakt_match_value = __jakt_match_variant.template get<types::CheckedExpression::IndexedTuple>();NonnullRefPtr<typename types::CheckedExpression> const& expr = __jakt_match_value.expr;
return JaktInternal::ExplicitValue(((expr)->is_mutable(program)));
};/*case end*/
case 13: {
auto&& __jakt_match_value = __jakt_match_variant.template get<types::CheckedExpression::IndexedDictionary>();NonnullRefPtr<typename types::CheckedExpression> const& expr = __jakt_match_value.expr;
return JaktInternal::ExplicitValue(((expr)->is_mutable(program)));
};/*case end*/
case 25: {
auto&& __jakt_match_value = __jakt_match_variant.template get<types::CheckedExpression::ForcedUnwrap>();NonnullRefPtr<typename types::CheckedExpression> const& expr = __jakt_match_value.expr;
return JaktInternal::ExplicitValue(((expr)->is_mutable(program)));
};/*case end*/
case 5: {
auto&& __jakt_match_value = __jakt_match_variant.template get<types::CheckedExpression::UnaryOp>();NonnullRefPtr<typename types::CheckedExpression> const& expr = __jakt_match_value.expr;
types::CheckedUnaryOperator const& op = __jakt_match_value.op;
return JaktInternal::ExplicitValue(JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<bool, bool>{
auto&& __jakt_match_variant = op;
switch(__jakt_match_variant.index()) {
case 5: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::CheckedUnaryOperator::Dereference>();
return JaktInternal::ExplicitValue(JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<bool, bool>{
auto&& __jakt_match_variant = *((program)->get_type(((expr)->type())));
switch(__jakt_match_variant.index()) {
case 28: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::Type::MutableReference>();
return JaktInternal::ExplicitValue(true);
};/*case end*/
case 25: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::Type::RawPtr>();
return JaktInternal::ExplicitValue(((expr)->is_mutable(program)));
};/*case end*/
default: {
return JaktInternal::ExplicitValue(false);
};/*case end*/
}/*switch end*/
}()
)));
};/*case end*/
default: {
return JaktInternal::ExplicitValue(false);
};/*case end*/
}/*switch end*/
}()
)));
};/*case end*/
case 20: {
auto&& __jakt_match_value = __jakt_match_variant.template get<types::CheckedExpression::MethodCall>();NonnullRefPtr<typename types::CheckedExpression> const& expr = __jakt_match_value.expr;
return JaktInternal::ExplicitValue(((expr)->is_mutable(program)));
};/*case end*/
default: {
return JaktInternal::ExplicitValue(false);
};/*case end*/
}/*switch end*/
}()
)));
}
}

ErrorOr<DeprecatedString> types::StringLiteral::debug_description() const {
auto builder = TRY(DeprecatedStringBuilder::create());
switch (this->index()) {case 0 /* Static */: {
[[maybe_unused]] auto const& that = this->template get<StringLiteral::Static>();
TRY(builder.append("StringLiteral::Static"sv));
TRY(builder.appendff("(\"{}\")", that.value));
break;}
}
return builder.to_string();
}
DeprecatedString types::StringLiteral::to_string() const {
{
return (JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<DeprecatedString, DeprecatedString>{
auto&& __jakt_match_variant = *this;
switch(__jakt_match_variant.index()) {
case 0: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::StringLiteral::Static>();
DeprecatedString const& value = __jakt_match_value.value;
return JaktInternal::ExplicitValue(value);
};/*case end*/
default: VERIFY_NOT_REACHED();}/*switch end*/
}()
)));
}
}

ErrorOr<DeprecatedString> types::StructLikeId::debug_description() const {
auto builder = TRY(DeprecatedStringBuilder::create());
switch (this->index()) {case 0 /* Struct */: {
[[maybe_unused]] auto const& that = this->template get<StructLikeId::Struct>();
TRY(builder.append("StructLikeId::Struct"sv));
TRY(builder.appendff("({})", that.value));
break;}
case 1 /* Enum */: {
[[maybe_unused]] auto const& that = this->template get<StructLikeId::Enum>();
TRY(builder.append("StructLikeId::Enum"sv));
TRY(builder.appendff("({})", that.value));
break;}
case 2 /* Trait */: {
[[maybe_unused]] auto const& that = this->template get<StructLikeId::Trait>();
TRY(builder.append("StructLikeId::Trait"sv));
TRY(builder.appendff("({})", that.value));
break;}
}
return builder.to_string();
}
ErrorOr<JaktInternal::DynamicArray<types::TypeId>> types::StructLikeId::generic_parameters(NonnullRefPtr<types::CheckedProgram> const& program) const {
{
JaktInternal::DynamicArray<types::CheckedGenericParameter> const parameters = JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<JaktInternal::DynamicArray<types::CheckedGenericParameter>, ErrorOr<JaktInternal::DynamicArray<types::TypeId>>>{
auto&& __jakt_match_variant = *this;
switch(__jakt_match_variant.index()) {
case 0: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::StructLikeId::Struct>();
types::StructId const& id = __jakt_match_value.value;
return JaktInternal::ExplicitValue(((((((program)))->get_struct(id))).generic_parameters));
};/*case end*/
case 1: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::StructLikeId::Enum>();
types::EnumId const& id = __jakt_match_value.value;
return JaktInternal::ExplicitValue(((((((program)))->get_enum(id))).generic_parameters));
};/*case end*/
case 2: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::StructLikeId::Trait>();
types::TraitId const& id = __jakt_match_value.value;
return JaktInternal::ExplicitValue(((((((program)))->get_trait(id)))->generic_parameters));
};/*case end*/
default: VERIFY_NOT_REACHED();}/*switch end*/
}()
));
JaktInternal::DynamicArray<types::TypeId> result = (TRY((DynamicArray<types::TypeId>::create_with({}))));
{
JaktInternal::ArrayIterator<types::CheckedGenericParameter> _magic = ((parameters).iterator());
for (;;){
JaktInternal::Optional<types::CheckedGenericParameter> _magic_value = ((_magic).next());
if ((!(((_magic_value).has_value())))){
break;
}
types::CheckedGenericParameter parameter = (_magic_value.value());
{
TRY((((result).push(((parameter).type_id)))));
}

}
}

return (result);
}
}

ErrorOr<DeprecatedString> types::CheckedVisibility::debug_description() const {
auto builder = TRY(DeprecatedStringBuilder::create());
switch (this->index()) {case 0 /* Public */: {
[[maybe_unused]] auto const& that = this->template get<CheckedVisibility::Public>();
TRY(builder.append("CheckedVisibility::Public"sv));
break;}
case 1 /* Private */: {
[[maybe_unused]] auto const& that = this->template get<CheckedVisibility::Private>();
TRY(builder.append("CheckedVisibility::Private"sv));
break;}
case 2 /* Restricted */: {
[[maybe_unused]] auto const& that = this->template get<CheckedVisibility::Restricted>();
TRY(builder.append("CheckedVisibility::Restricted"sv));
TRY(builder.append("("sv));
{
JaktInternal::PrettyPrint::ScopedLevelIncrease increase_indent {};
TRY(JaktInternal::PrettyPrint::output_indentation(builder));
TRY(builder.appendff("scopes: {}", that.scopes));
TRY(builder.append(", "sv));
TRY(JaktInternal::PrettyPrint::output_indentation(builder));
TRY(builder.appendff("span: {}", that.span));
}
TRY(builder.append(")"sv));
break;}
}
return builder.to_string();
}
ErrorOr<DeprecatedString> types::CheckedNumericConstant::debug_description() const {
auto builder = TRY(DeprecatedStringBuilder::create());
switch (this->index()) {case 0 /* I8 */: {
[[maybe_unused]] auto const& that = this->template get<CheckedNumericConstant::I8>();
TRY(builder.append("CheckedNumericConstant::I8"sv));
TRY(builder.appendff("({})", that.value));
break;}
case 1 /* I16 */: {
[[maybe_unused]] auto const& that = this->template get<CheckedNumericConstant::I16>();
TRY(builder.append("CheckedNumericConstant::I16"sv));
TRY(builder.appendff("({})", that.value));
break;}
case 2 /* I32 */: {
[[maybe_unused]] auto const& that = this->template get<CheckedNumericConstant::I32>();
TRY(builder.append("CheckedNumericConstant::I32"sv));
TRY(builder.appendff("({})", that.value));
break;}
case 3 /* I64 */: {
[[maybe_unused]] auto const& that = this->template get<CheckedNumericConstant::I64>();
TRY(builder.append("CheckedNumericConstant::I64"sv));
TRY(builder.appendff("({})", that.value));
break;}
case 4 /* U8 */: {
[[maybe_unused]] auto const& that = this->template get<CheckedNumericConstant::U8>();
TRY(builder.append("CheckedNumericConstant::U8"sv));
TRY(builder.appendff("({})", that.value));
break;}
case 5 /* U16 */: {
[[maybe_unused]] auto const& that = this->template get<CheckedNumericConstant::U16>();
TRY(builder.append("CheckedNumericConstant::U16"sv));
TRY(builder.appendff("({})", that.value));
break;}
case 6 /* U32 */: {
[[maybe_unused]] auto const& that = this->template get<CheckedNumericConstant::U32>();
TRY(builder.append("CheckedNumericConstant::U32"sv));
TRY(builder.appendff("({})", that.value));
break;}
case 7 /* U64 */: {
[[maybe_unused]] auto const& that = this->template get<CheckedNumericConstant::U64>();
TRY(builder.append("CheckedNumericConstant::U64"sv));
TRY(builder.appendff("({})", that.value));
break;}
case 8 /* USize */: {
[[maybe_unused]] auto const& that = this->template get<CheckedNumericConstant::USize>();
TRY(builder.append("CheckedNumericConstant::USize"sv));
TRY(builder.appendff("({})", that.value));
break;}
case 9 /* F32 */: {
[[maybe_unused]] auto const& that = this->template get<CheckedNumericConstant::F32>();
TRY(builder.append("CheckedNumericConstant::F32"sv));
TRY(builder.appendff("({})", that.value));
break;}
case 10 /* F64 */: {
[[maybe_unused]] auto const& that = this->template get<CheckedNumericConstant::F64>();
TRY(builder.append("CheckedNumericConstant::F64"sv));
TRY(builder.appendff("({})", that.value));
break;}
}
return builder.to_string();
}
JaktInternal::Optional<types::NumberConstant> types::CheckedNumericConstant::number_constant() const {
{
return (JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<JaktInternal::Optional<types::NumberConstant>, JaktInternal::Optional<types::NumberConstant>>{
auto&& __jakt_match_variant = *this;
switch(__jakt_match_variant.index()) {
case 0: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::CheckedNumericConstant::I8>();
i8 const& value = __jakt_match_value.value;
return JaktInternal::ExplicitValue( types::NumberConstant { typename types::NumberConstant::Signed((infallible_integer_cast<i64>((value)))) } );
};/*case end*/
case 1: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::CheckedNumericConstant::I16>();
i16 const& value = __jakt_match_value.value;
return JaktInternal::ExplicitValue( types::NumberConstant { typename types::NumberConstant::Signed((infallible_integer_cast<i64>((value)))) } );
};/*case end*/
case 2: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::CheckedNumericConstant::I32>();
i32 const& value = __jakt_match_value.value;
return JaktInternal::ExplicitValue( types::NumberConstant { typename types::NumberConstant::Signed((infallible_integer_cast<i64>((value)))) } );
};/*case end*/
case 3: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::CheckedNumericConstant::I64>();
i64 const& value = __jakt_match_value.value;
return JaktInternal::ExplicitValue( types::NumberConstant { typename types::NumberConstant::Signed((infallible_integer_cast<i64>((value)))) } );
};/*case end*/
case 4: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::CheckedNumericConstant::U8>();
u8 const& value = __jakt_match_value.value;
return JaktInternal::ExplicitValue( types::NumberConstant { typename types::NumberConstant::Unsigned((infallible_integer_cast<u64>((value)))) } );
};/*case end*/
case 5: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::CheckedNumericConstant::U16>();
u16 const& value = __jakt_match_value.value;
return JaktInternal::ExplicitValue( types::NumberConstant { typename types::NumberConstant::Unsigned((infallible_integer_cast<u64>((value)))) } );
};/*case end*/
case 6: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::CheckedNumericConstant::U32>();
u32 const& value = __jakt_match_value.value;
return JaktInternal::ExplicitValue( types::NumberConstant { typename types::NumberConstant::Unsigned((infallible_integer_cast<u64>((value)))) } );
};/*case end*/
case 7: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::CheckedNumericConstant::U64>();
u64 const& value = __jakt_match_value.value;
return JaktInternal::ExplicitValue( types::NumberConstant { typename types::NumberConstant::Unsigned((infallible_integer_cast<u64>((value)))) } );
};/*case end*/
case 8: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::CheckedNumericConstant::USize>();
u64 const& value = __jakt_match_value.value;
return JaktInternal::ExplicitValue( types::NumberConstant { typename types::NumberConstant::Unsigned((infallible_integer_cast<u64>((value)))) } );
};/*case end*/
case 10: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::CheckedNumericConstant::F64>();
f64 const& value = __jakt_match_value.value;
return JaktInternal::ExplicitValue( types::NumberConstant { typename types::NumberConstant::Floating(value) } );
};/*case end*/
default: {
return JaktInternal::ExplicitValue(JaktInternal::OptionalNone());
};/*case end*/
}/*switch end*/
}()
)));
}
}

ErrorOr<DeprecatedString> types::BuiltinType::debug_description() const {
auto builder = TRY(DeprecatedStringBuilder::create());
switch (this->index()) {case 0 /* Void */: {
[[maybe_unused]] auto const& that = this->template get<BuiltinType::Void>();
TRY(builder.append("BuiltinType::Void"sv));
break;}
case 1 /* Bool */: {
[[maybe_unused]] auto const& that = this->template get<BuiltinType::Bool>();
TRY(builder.append("BuiltinType::Bool"sv));
break;}
case 2 /* U8 */: {
[[maybe_unused]] auto const& that = this->template get<BuiltinType::U8>();
TRY(builder.append("BuiltinType::U8"sv));
break;}
case 3 /* U16 */: {
[[maybe_unused]] auto const& that = this->template get<BuiltinType::U16>();
TRY(builder.append("BuiltinType::U16"sv));
break;}
case 4 /* U32 */: {
[[maybe_unused]] auto const& that = this->template get<BuiltinType::U32>();
TRY(builder.append("BuiltinType::U32"sv));
break;}
case 5 /* U64 */: {
[[maybe_unused]] auto const& that = this->template get<BuiltinType::U64>();
TRY(builder.append("BuiltinType::U64"sv));
break;}
case 6 /* I8 */: {
[[maybe_unused]] auto const& that = this->template get<BuiltinType::I8>();
TRY(builder.append("BuiltinType::I8"sv));
break;}
case 7 /* I16 */: {
[[maybe_unused]] auto const& that = this->template get<BuiltinType::I16>();
TRY(builder.append("BuiltinType::I16"sv));
break;}
case 8 /* I32 */: {
[[maybe_unused]] auto const& that = this->template get<BuiltinType::I32>();
TRY(builder.append("BuiltinType::I32"sv));
break;}
case 9 /* I64 */: {
[[maybe_unused]] auto const& that = this->template get<BuiltinType::I64>();
TRY(builder.append("BuiltinType::I64"sv));
break;}
case 10 /* F32 */: {
[[maybe_unused]] auto const& that = this->template get<BuiltinType::F32>();
TRY(builder.append("BuiltinType::F32"sv));
break;}
case 11 /* F64 */: {
[[maybe_unused]] auto const& that = this->template get<BuiltinType::F64>();
TRY(builder.append("BuiltinType::F64"sv));
break;}
case 12 /* Usize */: {
[[maybe_unused]] auto const& that = this->template get<BuiltinType::Usize>();
TRY(builder.append("BuiltinType::Usize"sv));
break;}
case 13 /* JaktString */: {
[[maybe_unused]] auto const& that = this->template get<BuiltinType::JaktString>();
TRY(builder.append("BuiltinType::JaktString"sv));
break;}
case 14 /* CChar */: {
[[maybe_unused]] auto const& that = this->template get<BuiltinType::CChar>();
TRY(builder.append("BuiltinType::CChar"sv));
break;}
case 15 /* CInt */: {
[[maybe_unused]] auto const& that = this->template get<BuiltinType::CInt>();
TRY(builder.append("BuiltinType::CInt"sv));
break;}
case 16 /* Unknown */: {
[[maybe_unused]] auto const& that = this->template get<BuiltinType::Unknown>();
TRY(builder.append("BuiltinType::Unknown"sv));
break;}
case 17 /* Never */: {
[[maybe_unused]] auto const& that = this->template get<BuiltinType::Never>();
TRY(builder.append("BuiltinType::Never"sv));
break;}
}
return builder.to_string();
}
size_t types::BuiltinType::id() const {
{
return (JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<size_t, size_t>{
auto&& __jakt_match_variant = *this;
switch(__jakt_match_variant.index()) {
case 0: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::BuiltinType::Void>();
return JaktInternal::ExplicitValue(static_cast<size_t>(0ULL));
};/*case end*/
case 1: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::BuiltinType::Bool>();
return JaktInternal::ExplicitValue(static_cast<size_t>(1ULL));
};/*case end*/
case 2: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::BuiltinType::U8>();
return JaktInternal::ExplicitValue(static_cast<size_t>(2ULL));
};/*case end*/
case 3: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::BuiltinType::U16>();
return JaktInternal::ExplicitValue(static_cast<size_t>(3ULL));
};/*case end*/
case 4: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::BuiltinType::U32>();
return JaktInternal::ExplicitValue(static_cast<size_t>(4ULL));
};/*case end*/
case 5: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::BuiltinType::U64>();
return JaktInternal::ExplicitValue(static_cast<size_t>(5ULL));
};/*case end*/
case 6: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::BuiltinType::I8>();
return JaktInternal::ExplicitValue(static_cast<size_t>(6ULL));
};/*case end*/
case 7: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::BuiltinType::I16>();
return JaktInternal::ExplicitValue(static_cast<size_t>(7ULL));
};/*case end*/
case 8: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::BuiltinType::I32>();
return JaktInternal::ExplicitValue(static_cast<size_t>(8ULL));
};/*case end*/
case 9: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::BuiltinType::I64>();
return JaktInternal::ExplicitValue(static_cast<size_t>(9ULL));
};/*case end*/
case 10: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::BuiltinType::F32>();
return JaktInternal::ExplicitValue(static_cast<size_t>(10ULL));
};/*case end*/
case 11: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::BuiltinType::F64>();
return JaktInternal::ExplicitValue(static_cast<size_t>(11ULL));
};/*case end*/
case 12: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::BuiltinType::Usize>();
return JaktInternal::ExplicitValue(static_cast<size_t>(12ULL));
};/*case end*/
case 13: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::BuiltinType::JaktString>();
return JaktInternal::ExplicitValue(static_cast<size_t>(13ULL));
};/*case end*/
case 14: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::BuiltinType::CChar>();
return JaktInternal::ExplicitValue(static_cast<size_t>(14ULL));
};/*case end*/
case 15: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::BuiltinType::CInt>();
return JaktInternal::ExplicitValue(static_cast<size_t>(15ULL));
};/*case end*/
case 16: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::BuiltinType::Unknown>();
return JaktInternal::ExplicitValue(static_cast<size_t>(16ULL));
};/*case end*/
case 17: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::BuiltinType::Never>();
return JaktInternal::ExplicitValue(static_cast<size_t>(17ULL));
};/*case end*/
default: VERIFY_NOT_REACHED();}/*switch end*/
}()
)));
}
}

}
} // namespace Jakt
