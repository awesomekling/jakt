#include "parser.h"
namespace Jakt {
namespace parser {
ErrorOr<utility::Span> merge_spans(utility::Span const start,utility::Span const end) {
{
if (((((((end).file_id)).id) == static_cast<size_t>(0ULL)) && ((((end).start) == static_cast<size_t>(0ULL)) && (((end).end) == static_cast<size_t>(0ULL))))){
return (start);
}
if ((((((start).file_id)).id) != ((((end).file_id)).id))){
utility::panic(TRY((__jakt_format(Jakt::DeprecatedString("cannot merge spans from two different files ({} and {})"sv),start,end))));
}
return (utility::Span(((start).file_id),((start).start),((end).end)));
}
}

f32 f64_to_f32(f64 const number) {
{
f32 f32_value = static_cast<i64>(0LL);
{
f32_value = (f32)number;
}

return (f32_value);
}
}

ErrorOr<DeprecatedString> parser::ParsedGenericParameter::debug_description() const { auto builder = MUST(DeprecatedStringBuilder::create());TRY(builder.append("ParsedGenericParameter("sv));{
JaktInternal::PrettyPrint::ScopedLevelIncrease increase_indent {};
TRY(JaktInternal::PrettyPrint::output_indentation(builder));TRY(builder.append("name: "sv));TRY(builder.appendff("\"{}\", ", name));
TRY(JaktInternal::PrettyPrint::output_indentation(builder));TRY(builder.append("span: "sv));TRY(builder.appendff("{}, ", span));
TRY(JaktInternal::PrettyPrint::output_indentation(builder));TRY(builder.append("requires_list: "sv));TRY(builder.appendff("{}", requires_list));
}
TRY(builder.append(")"sv));return builder.to_string(); }
parser::ParsedGenericParameter::ParsedGenericParameter(DeprecatedString a_name, utility::Span a_span, JaktInternal::Optional<JaktInternal::DynamicArray<parser::ParsedNameWithGenericParameters>> a_requires_list) :name(a_name), span(a_span), requires_list(a_requires_list){}

ErrorOr<DeprecatedString> parser::ParsedField::debug_description() const { auto builder = MUST(DeprecatedStringBuilder::create());TRY(builder.append("ParsedField("sv));{
JaktInternal::PrettyPrint::ScopedLevelIncrease increase_indent {};
TRY(JaktInternal::PrettyPrint::output_indentation(builder));TRY(builder.append("var_decl: "sv));TRY(builder.appendff("{}, ", var_decl));
TRY(JaktInternal::PrettyPrint::output_indentation(builder));TRY(builder.append("visibility: "sv));TRY(builder.appendff("{}, ", visibility));
TRY(JaktInternal::PrettyPrint::output_indentation(builder));TRY(builder.append("default_value: "sv));TRY(builder.appendff("{}", default_value));
}
TRY(builder.append(")"sv));return builder.to_string(); }
parser::ParsedField::ParsedField(parser::ParsedVarDecl a_var_decl, parser::Visibility a_visibility, JaktInternal::Optional<NonnullRefPtr<typename parser::ParsedExpression>> a_default_value) :var_decl(a_var_decl), visibility(a_visibility), default_value(a_default_value){}

ErrorOr<DeprecatedString> parser::EnumVariantPatternArgument::debug_description() const { auto builder = MUST(DeprecatedStringBuilder::create());TRY(builder.append("EnumVariantPatternArgument("sv));{
JaktInternal::PrettyPrint::ScopedLevelIncrease increase_indent {};
TRY(JaktInternal::PrettyPrint::output_indentation(builder));TRY(builder.append("name: "sv));TRY(builder.appendff("{}, ", name));
TRY(JaktInternal::PrettyPrint::output_indentation(builder));TRY(builder.append("binding: "sv));TRY(builder.appendff("\"{}\", ", binding));
TRY(JaktInternal::PrettyPrint::output_indentation(builder));TRY(builder.append("span: "sv));TRY(builder.appendff("{}, ", span));
TRY(JaktInternal::PrettyPrint::output_indentation(builder));TRY(builder.append("is_reference: "sv));TRY(builder.appendff("{}, ", is_reference));
TRY(JaktInternal::PrettyPrint::output_indentation(builder));TRY(builder.append("is_mutable: "sv));TRY(builder.appendff("{}", is_mutable));
}
TRY(builder.append(")"sv));return builder.to_string(); }
parser::EnumVariantPatternArgument::EnumVariantPatternArgument(JaktInternal::Optional<DeprecatedString> a_name, DeprecatedString a_binding, utility::Span a_span, bool a_is_reference, bool a_is_mutable) :name(a_name), binding(a_binding), span(a_span), is_reference(a_is_reference), is_mutable(a_is_mutable){}

bool parser::EnumVariantPatternArgument::equals(parser::EnumVariantPatternArgument const rhs_variant_pattern_argument) const {
{
if ((((*this).binding) != ((rhs_variant_pattern_argument).binding))){
return (false);
}
if ((((((*this).name)).has_value()) && ((((rhs_variant_pattern_argument).name)).has_value()))){
return (((((*this).name).value()) == (((rhs_variant_pattern_argument).name).value())));
}
if ((((*this).is_reference) != ((rhs_variant_pattern_argument).is_reference))){
return (false);
}
if ((((*this).is_mutable) != ((rhs_variant_pattern_argument).is_mutable))){
return (false);
}
return (((!(((((*this).name)).has_value()))) && (!(((((rhs_variant_pattern_argument).name)).has_value())))));
}
}

ErrorOr<DeprecatedString> parser::ParsedPatternDefault::debug_description() const { auto builder = MUST(DeprecatedStringBuilder::create());TRY(builder.append("ParsedPatternDefault("sv));{
JaktInternal::PrettyPrint::ScopedLevelIncrease increase_indent {};
TRY(JaktInternal::PrettyPrint::output_indentation(builder));TRY(builder.append("variable: "sv));TRY(builder.appendff("{}, ", variable));
TRY(JaktInternal::PrettyPrint::output_indentation(builder));TRY(builder.append("value: "sv));TRY(builder.appendff("{}", value));
}
TRY(builder.append(")"sv));return builder.to_string(); }
parser::ParsedPatternDefault::ParsedPatternDefault(parser::ParsedVarDecl a_variable, NonnullRefPtr<typename parser::ParsedExpression> a_value) :variable(a_variable), value(a_value){}

ErrorOr<DeprecatedString> parser::ParsedRecord::debug_description() const { auto builder = MUST(DeprecatedStringBuilder::create());TRY(builder.append("ParsedRecord("sv));{
JaktInternal::PrettyPrint::ScopedLevelIncrease increase_indent {};
TRY(JaktInternal::PrettyPrint::output_indentation(builder));TRY(builder.append("name: "sv));TRY(builder.appendff("\"{}\", ", name));
TRY(JaktInternal::PrettyPrint::output_indentation(builder));TRY(builder.append("name_span: "sv));TRY(builder.appendff("{}, ", name_span));
TRY(JaktInternal::PrettyPrint::output_indentation(builder));TRY(builder.append("generic_parameters: "sv));TRY(builder.appendff("{}, ", generic_parameters));
TRY(JaktInternal::PrettyPrint::output_indentation(builder));TRY(builder.append("definition_linkage: "sv));TRY(builder.appendff("{}, ", definition_linkage));
TRY(JaktInternal::PrettyPrint::output_indentation(builder));TRY(builder.append("implements_list: "sv));TRY(builder.appendff("{}, ", implements_list));
TRY(JaktInternal::PrettyPrint::output_indentation(builder));TRY(builder.append("methods: "sv));TRY(builder.appendff("{}, ", methods));
TRY(JaktInternal::PrettyPrint::output_indentation(builder));TRY(builder.append("record_type: "sv));TRY(builder.appendff("{}, ", record_type));
TRY(JaktInternal::PrettyPrint::output_indentation(builder));TRY(builder.append("external_name: "sv));TRY(builder.appendff("{}", external_name));
}
TRY(builder.append(")"sv));return builder.to_string(); }
parser::ParsedRecord::ParsedRecord(DeprecatedString a_name, utility::Span a_name_span, JaktInternal::DynamicArray<parser::ParsedGenericParameter> a_generic_parameters, parser::DefinitionLinkage a_definition_linkage, JaktInternal::Optional<JaktInternal::DynamicArray<parser::ParsedNameWithGenericParameters>> a_implements_list, JaktInternal::DynamicArray<parser::ParsedMethod> a_methods, parser::RecordType a_record_type, JaktInternal::Optional<DeprecatedString> a_external_name) :name(a_name), name_span(a_name_span), generic_parameters(a_generic_parameters), definition_linkage(a_definition_linkage), implements_list(a_implements_list), methods(a_methods), record_type(a_record_type), external_name(a_external_name){}

ErrorOr<DeprecatedString> parser::ParsedExternalTraitImplementation::debug_description() const { auto builder = MUST(DeprecatedStringBuilder::create());TRY(builder.append("ParsedExternalTraitImplementation("sv));{
JaktInternal::PrettyPrint::ScopedLevelIncrease increase_indent {};
TRY(JaktInternal::PrettyPrint::output_indentation(builder));TRY(builder.append("for_type: "sv));TRY(builder.appendff("{}, ", for_type));
TRY(JaktInternal::PrettyPrint::output_indentation(builder));TRY(builder.append("traits: "sv));TRY(builder.appendff("{}, ", traits));
TRY(JaktInternal::PrettyPrint::output_indentation(builder));TRY(builder.append("methods: "sv));TRY(builder.appendff("{}", methods));
}
TRY(builder.append(")"sv));return builder.to_string(); }
parser::ParsedExternalTraitImplementation::ParsedExternalTraitImplementation(NonnullRefPtr<typename parser::ParsedType> a_for_type, JaktInternal::DynamicArray<parser::ParsedNameWithGenericParameters> a_traits, JaktInternal::DynamicArray<parser::ParsedMethod> a_methods) :for_type(a_for_type), traits(a_traits), methods(a_methods){}

ErrorOr<DeprecatedString> parser::ParsedFunction::debug_description() const { auto builder = MUST(DeprecatedStringBuilder::create());TRY(builder.append("ParsedFunction("sv));{
JaktInternal::PrettyPrint::ScopedLevelIncrease increase_indent {};
TRY(JaktInternal::PrettyPrint::output_indentation(builder));TRY(builder.append("name: "sv));TRY(builder.appendff("\"{}\", ", name));
TRY(JaktInternal::PrettyPrint::output_indentation(builder));TRY(builder.append("name_span: "sv));TRY(builder.appendff("{}, ", name_span));
TRY(JaktInternal::PrettyPrint::output_indentation(builder));TRY(builder.append("visibility: "sv));TRY(builder.appendff("{}, ", visibility));
TRY(JaktInternal::PrettyPrint::output_indentation(builder));TRY(builder.append("params: "sv));TRY(builder.appendff("{}, ", params));
TRY(JaktInternal::PrettyPrint::output_indentation(builder));TRY(builder.append("generic_parameters: "sv));TRY(builder.appendff("{}, ", generic_parameters));
TRY(JaktInternal::PrettyPrint::output_indentation(builder));TRY(builder.append("block: "sv));TRY(builder.appendff("{}, ", block));
TRY(JaktInternal::PrettyPrint::output_indentation(builder));TRY(builder.append("return_type: "sv));TRY(builder.appendff("{}, ", return_type));
TRY(JaktInternal::PrettyPrint::output_indentation(builder));TRY(builder.append("return_type_span: "sv));TRY(builder.appendff("{}, ", return_type_span));
TRY(JaktInternal::PrettyPrint::output_indentation(builder));TRY(builder.append("can_throw: "sv));TRY(builder.appendff("{}, ", can_throw));
TRY(JaktInternal::PrettyPrint::output_indentation(builder));TRY(builder.append("type: "sv));TRY(builder.appendff("{}, ", type));
TRY(JaktInternal::PrettyPrint::output_indentation(builder));TRY(builder.append("linkage: "sv));TRY(builder.appendff("{}, ", linkage));
TRY(JaktInternal::PrettyPrint::output_indentation(builder));TRY(builder.append("must_instantiate: "sv));TRY(builder.appendff("{}, ", must_instantiate));
TRY(JaktInternal::PrettyPrint::output_indentation(builder));TRY(builder.append("is_comptime: "sv));TRY(builder.appendff("{}, ", is_comptime));
TRY(JaktInternal::PrettyPrint::output_indentation(builder));TRY(builder.append("is_fat_arrow: "sv));TRY(builder.appendff("{}, ", is_fat_arrow));
TRY(JaktInternal::PrettyPrint::output_indentation(builder));TRY(builder.append("external_name: "sv));TRY(builder.appendff("{}, ", external_name));
TRY(JaktInternal::PrettyPrint::output_indentation(builder));TRY(builder.append("deprecated_message: "sv));TRY(builder.appendff("{}", deprecated_message));
}
TRY(builder.append(")"sv));return builder.to_string(); }
parser::ParsedFunction::ParsedFunction(DeprecatedString a_name, utility::Span a_name_span, parser::Visibility a_visibility, JaktInternal::DynamicArray<parser::ParsedParameter> a_params, JaktInternal::DynamicArray<parser::ParsedGenericParameter> a_generic_parameters, parser::ParsedBlock a_block, NonnullRefPtr<typename parser::ParsedType> a_return_type, utility::Span a_return_type_span, bool a_can_throw, parser::FunctionType a_type, parser::FunctionLinkage a_linkage, bool a_must_instantiate, bool a_is_comptime, bool a_is_fat_arrow, JaktInternal::Optional<DeprecatedString> a_external_name, JaktInternal::Optional<DeprecatedString> a_deprecated_message) :name(a_name), name_span(a_name_span), visibility(a_visibility), params(a_params), generic_parameters(a_generic_parameters), block(a_block), return_type(a_return_type), return_type_span(a_return_type_span), can_throw(a_can_throw), type(a_type), linkage(a_linkage), must_instantiate(a_must_instantiate), is_comptime(a_is_comptime), is_fat_arrow(a_is_fat_arrow), external_name(a_external_name), deprecated_message(a_deprecated_message){}

bool parser::ParsedFunction::equals(parser::ParsedFunction const other) const {
{
if (((((((*this).name) != ((other).name)) || (((*this).can_throw) != ((other).can_throw))) || (((*this).is_comptime) != ((other).is_comptime))) || (((*this).is_fat_arrow) != ((other).is_fat_arrow)))){
return (false);
}
if ((!(((((*this).block)).equals(((other).block)))))){
return (false);
}
if ((((((*this).params)).size()) != ((((other).params)).size()))){
return (false);
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
if ((!(((((((*this).params))[param_index])).equals(((((other).params))[param_index])))))){
return (false);
}
}

}
}

if ((((((*this).generic_parameters)).size()) != ((((other).generic_parameters)).size()))){
return (false);
}
return (true);
}
}

ErrorOr<DeprecatedString> parser::ParsedExternImport::debug_description() const { auto builder = MUST(DeprecatedStringBuilder::create());TRY(builder.append("ParsedExternImport("sv));{
JaktInternal::PrettyPrint::ScopedLevelIncrease increase_indent {};
TRY(JaktInternal::PrettyPrint::output_indentation(builder));TRY(builder.append("is_c: "sv));TRY(builder.appendff("{}, ", is_c));
TRY(JaktInternal::PrettyPrint::output_indentation(builder));TRY(builder.append("assigned_namespace: "sv));TRY(builder.appendff("{}, ", assigned_namespace));
TRY(JaktInternal::PrettyPrint::output_indentation(builder));TRY(builder.append("before_include: "sv));TRY(builder.appendff("{}, ", before_include));
TRY(JaktInternal::PrettyPrint::output_indentation(builder));TRY(builder.append("after_include: "sv));TRY(builder.appendff("{}", after_include));
}
TRY(builder.append(")"sv));return builder.to_string(); }
ErrorOr<bool> parser::ParsedExternImport::is_equivalent_to(parser::ParsedExternImport const other) const {
{
return ((((*this).is_c) && (((other).is_c) && ((((*this).get_path()) == ((other).get_path())) && (((*this).get_name()) == ((other).get_name()))))));
}
}

parser::ParsedExternImport::ParsedExternImport(bool a_is_c, parser::ParsedNamespace a_assigned_namespace, JaktInternal::DynamicArray<parser::IncludeAction> a_before_include, JaktInternal::DynamicArray<parser::IncludeAction> a_after_include) :is_c(a_is_c), assigned_namespace(a_assigned_namespace), before_include(a_before_include), after_include(a_after_include){}

DeprecatedString parser::ParsedExternImport::get_name() const {
{
return ((((((*this).assigned_namespace)).name).value()));
}
}

DeprecatedString parser::ParsedExternImport::get_path() const {
{
return ((((((*this).assigned_namespace)).import_path_if_extern).value()));
}
}

ErrorOr<DeprecatedString> parser::ParsedModuleImport::debug_description() const { auto builder = MUST(DeprecatedStringBuilder::create());TRY(builder.append("ParsedModuleImport("sv));{
JaktInternal::PrettyPrint::ScopedLevelIncrease increase_indent {};
TRY(JaktInternal::PrettyPrint::output_indentation(builder));TRY(builder.append("module_name: "sv));TRY(builder.appendff("{}, ", module_name));
TRY(JaktInternal::PrettyPrint::output_indentation(builder));TRY(builder.append("alias_name: "sv));TRY(builder.appendff("{}, ", alias_name));
TRY(JaktInternal::PrettyPrint::output_indentation(builder));TRY(builder.append("import_list: "sv));TRY(builder.appendff("{}", import_list));
}
TRY(builder.append(")"sv));return builder.to_string(); }
parser::ParsedModuleImport::ParsedModuleImport(parser::ImportName a_module_name, JaktInternal::Optional<parser::ImportName> a_alias_name, parser::ImportList a_import_list) :module_name(a_module_name), alias_name(a_alias_name), import_list(a_import_list){}

bool parser::ParsedModuleImport::is_equivalent_to(parser::ParsedModuleImport const other) const {
{
return ((((((*this).module_name)).equals(((other).module_name))) && (((*this).has_same_alias_than(other)) && ((*this).has_same_import_semantics(other)))));
}
}

bool parser::ParsedModuleImport::has_same_alias_than(parser::ParsedModuleImport const other) const {
{
if (((((*this).alias_name)).has_value())){
return ((((((other).alias_name)).has_value()) && (((((other).alias_name).value())).equals((((*this).alias_name).value())))));
}
else {
return ((!(((((other).alias_name)).has_value()))));
}

}
}

bool parser::ParsedModuleImport::has_same_import_semantics(parser::ParsedModuleImport const other) const {
{
return ((((((*this).import_list)).is_empty()) == ((((other).import_list)).is_empty())));
}
}

ErrorOr<void> parser::ParsedModuleImport::merge_import_list(parser::ImportList const list) {
{
JaktInternal::Set<DeprecatedString> name_set = (TRY((Set<DeprecatedString>::create_with_values({}))));
bool everything = false;
JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<void, ErrorOr<void>>{
auto&& __jakt_match_variant = ((*this).import_list);
switch(__jakt_match_variant.index()) {
case 0: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename parser::ImportList::List>();
JaktInternal::DynamicArray<parser::ImportName> const& names = __jakt_match_value.value;
{
{
JaktInternal::ArrayIterator<parser::ImportName> _magic = ((names).iterator());
for (;;){
JaktInternal::Optional<parser::ImportName> _magic_value = ((_magic).next());
if ((!(((_magic_value).has_value())))){
break;
}
parser::ImportName name = (_magic_value.value());
{
TRY((((name_set).add(((name).literal_name())))));
}

}
}

}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 1: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename parser::ImportList::All>();
{
(everything = true);
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
default: VERIFY_NOT_REACHED();}/*switch end*/
}()
));
if ((!(everything))){
JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<void, ErrorOr<void>>{
auto&& __jakt_match_variant = list;
switch(__jakt_match_variant.index()) {
case 0: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename parser::ImportList::List>();
JaktInternal::DynamicArray<parser::ImportName> const& names = __jakt_match_value.value;
{
{
JaktInternal::ArrayIterator<parser::ImportName> _magic = ((names).iterator());
for (;;){
JaktInternal::Optional<parser::ImportName> _magic_value = ((_magic).next());
if ((!(((_magic_value).has_value())))){
break;
}
parser::ImportName name = (_magic_value.value());
{
if ((!(((name_set).contains(((name).literal_name())))))){
TRY((((((*this).import_list)).add(name))));
}
}

}
}

}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 1: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename parser::ImportList::All>();
{
(everything = true);
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
default: VERIFY_NOT_REACHED();}/*switch end*/
}()
));
}
if (everything){
(((*this).import_list) =  parser::ImportList { typename parser::ImportList::All() } );
}
}
return {};
}

ErrorOr<DeprecatedString> parser::ParsedVariable::debug_description() const { auto builder = MUST(DeprecatedStringBuilder::create());TRY(builder.append("ParsedVariable("sv));{
JaktInternal::PrettyPrint::ScopedLevelIncrease increase_indent {};
TRY(JaktInternal::PrettyPrint::output_indentation(builder));TRY(builder.append("name: "sv));TRY(builder.appendff("\"{}\", ", name));
TRY(JaktInternal::PrettyPrint::output_indentation(builder));TRY(builder.append("parsed_type: "sv));TRY(builder.appendff("{}, ", parsed_type));
TRY(JaktInternal::PrettyPrint::output_indentation(builder));TRY(builder.append("is_mutable: "sv));TRY(builder.appendff("{}, ", is_mutable));
TRY(JaktInternal::PrettyPrint::output_indentation(builder));TRY(builder.append("span: "sv));TRY(builder.appendff("{}", span));
}
TRY(builder.append(")"sv));return builder.to_string(); }
bool parser::ParsedVariable::equals(parser::ParsedVariable const rhs_parsed_varible) const {
{
return (((((*this).name) == ((rhs_parsed_varible).name)) && (((((*this).parsed_type))->equals(((rhs_parsed_varible).parsed_type))) && (((*this).is_mutable) == ((rhs_parsed_varible).is_mutable)))));
}
}

parser::ParsedVariable::ParsedVariable(DeprecatedString a_name, NonnullRefPtr<typename parser::ParsedType> a_parsed_type, bool a_is_mutable, utility::Span a_span) :name(a_name), parsed_type(a_parsed_type), is_mutable(a_is_mutable), span(a_span){}

ErrorOr<DeprecatedString> parser::ParsedNameWithGenericParameters::debug_description() const { auto builder = MUST(DeprecatedStringBuilder::create());TRY(builder.append("ParsedNameWithGenericParameters("sv));{
JaktInternal::PrettyPrint::ScopedLevelIncrease increase_indent {};
TRY(JaktInternal::PrettyPrint::output_indentation(builder));TRY(builder.append("name: "sv));TRY(builder.appendff("\"{}\", ", name));
TRY(JaktInternal::PrettyPrint::output_indentation(builder));TRY(builder.append("name_span: "sv));TRY(builder.appendff("{}, ", name_span));
TRY(JaktInternal::PrettyPrint::output_indentation(builder));TRY(builder.append("generic_parameters: "sv));TRY(builder.appendff("{}", generic_parameters));
}
TRY(builder.append(")"sv));return builder.to_string(); }
parser::ParsedNameWithGenericParameters::ParsedNameWithGenericParameters(DeprecatedString a_name, utility::Span a_name_span, JaktInternal::DynamicArray<NonnullRefPtr<typename parser::ParsedType>> a_generic_parameters) :name(a_name), name_span(a_name_span), generic_parameters(a_generic_parameters){}

ErrorOr<DeprecatedString> parser::SumEnumVariant::debug_description() const { auto builder = MUST(DeprecatedStringBuilder::create());TRY(builder.append("SumEnumVariant("sv));{
JaktInternal::PrettyPrint::ScopedLevelIncrease increase_indent {};
TRY(JaktInternal::PrettyPrint::output_indentation(builder));TRY(builder.append("name: "sv));TRY(builder.appendff("\"{}\", ", name));
TRY(JaktInternal::PrettyPrint::output_indentation(builder));TRY(builder.append("span: "sv));TRY(builder.appendff("{}, ", span));
TRY(JaktInternal::PrettyPrint::output_indentation(builder));TRY(builder.append("params: "sv));TRY(builder.appendff("{}", params));
}
TRY(builder.append(")"sv));return builder.to_string(); }
parser::SumEnumVariant::SumEnumVariant(DeprecatedString a_name, utility::Span a_span, JaktInternal::Optional<JaktInternal::DynamicArray<parser::ParsedVarDecl>> a_params) :name(a_name), span(a_span), params(a_params){}

ErrorOr<DeprecatedString> parser::ParsedBlock::debug_description() const { auto builder = MUST(DeprecatedStringBuilder::create());TRY(builder.append("ParsedBlock("sv));{
JaktInternal::PrettyPrint::ScopedLevelIncrease increase_indent {};
TRY(JaktInternal::PrettyPrint::output_indentation(builder));TRY(builder.append("stmts: "sv));TRY(builder.appendff("{}", stmts));
}
TRY(builder.append(")"sv));return builder.to_string(); }
bool parser::ParsedBlock::equals(parser::ParsedBlock const rhs_block) const {
{
if ((((((*this).stmts)).size()) != ((((rhs_block).stmts)).size()))){
return (false);
}
{
JaktInternal::Range<size_t> _magic = (JaktInternal::Range<size_t>{static_cast<size_t>(static_cast<size_t>(0ULL)),static_cast<size_t>(((((*this).stmts)).size()))});
for (;;){
JaktInternal::Optional<size_t> _magic_value = ((_magic).next());
if ((!(((_magic_value).has_value())))){
break;
}
size_t x = (_magic_value.value());
{
if ((!(((((((*this).stmts))[x]))->equals(((((rhs_block).stmts))[x])))))){
return (false);
}
}

}
}

return (true);
}
}

parser::ParsedBlock::ParsedBlock(JaktInternal::DynamicArray<NonnullRefPtr<typename parser::ParsedStatement>> a_stmts) :stmts(a_stmts){}

JaktInternal::Optional<utility::Span> parser::ParsedBlock::find_yield_span() const {
{
{
JaktInternal::ArrayIterator<NonnullRefPtr<typename parser::ParsedStatement>> _magic = ((((*this).stmts)).iterator());
for (;;){
JaktInternal::Optional<NonnullRefPtr<typename parser::ParsedStatement>> _magic_value = ((_magic).next());
if ((!(((_magic_value).has_value())))){
break;
}
NonnullRefPtr<typename parser::ParsedStatement> stmt = (_magic_value.value());
{
if (((stmt)->index() == 14 /* Yield */)){
NonnullRefPtr<typename parser::ParsedExpression> const expr = ((stmt)->get<parser::ParsedStatement::Yield>()).expr;
return (((expr)->span()));
}
}

}
}

return (JaktInternal::OptionalNone());
}
}

ErrorOr<JaktInternal::Optional<utility::Span>> parser::ParsedBlock::span(parser::Parser const parser) const {
{
JaktInternal::Optional<size_t> start = JaktInternal::OptionalNone();
size_t end = static_cast<size_t>(0ULL);
{
JaktInternal::ArrayIterator<NonnullRefPtr<typename parser::ParsedStatement>> _magic = ((((*this).stmts)).iterator());
for (;;){
JaktInternal::Optional<NonnullRefPtr<typename parser::ParsedStatement>> _magic_value = ((_magic).next());
if ((!(((_magic_value).has_value())))){
break;
}
NonnullRefPtr<typename parser::ParsedStatement> stmt = (_magic_value.value());
{
utility::Span const stmt_span = ((stmt)->span());
if ((!(((start).has_value())))){
(start = ((stmt_span).start));
}
(end = ((stmt_span).end));
}

}
}

if (((start).has_value())){
return (((parser).span((start.value()),end)));
}
return (JaktInternal::OptionalNone());
}
}

JaktInternal::Optional<utility::Span> parser::ParsedBlock::find_yield_keyword_span() const {
{
{
JaktInternal::ArrayIterator<NonnullRefPtr<typename parser::ParsedStatement>> _magic = ((((*this).stmts)).iterator());
for (;;){
JaktInternal::Optional<NonnullRefPtr<typename parser::ParsedStatement>> _magic_value = ((_magic).next());
if ((!(((_magic_value).has_value())))){
break;
}
NonnullRefPtr<typename parser::ParsedStatement> stmt = (_magic_value.value());
{
if (((stmt)->index() == 14 /* Yield */)){
NonnullRefPtr<typename parser::ParsedExpression> const expr = ((stmt)->get<parser::ParsedStatement::Yield>()).expr;
return (((stmt)->span()));
}
}

}
}

return (JaktInternal::OptionalNone());
}
}

ErrorOr<DeprecatedString> parser::ParsedAttributeArgument::debug_description() const { auto builder = MUST(DeprecatedStringBuilder::create());TRY(builder.append("ParsedAttributeArgument("sv));{
JaktInternal::PrettyPrint::ScopedLevelIncrease increase_indent {};
TRY(JaktInternal::PrettyPrint::output_indentation(builder));TRY(builder.append("name: "sv));TRY(builder.appendff("\"{}\", ", name));
TRY(JaktInternal::PrettyPrint::output_indentation(builder));TRY(builder.append("span: "sv));TRY(builder.appendff("{}, ", span));
TRY(JaktInternal::PrettyPrint::output_indentation(builder));TRY(builder.append("assigned_value: "sv));TRY(builder.appendff("{}", assigned_value));
}
TRY(builder.append(")"sv));return builder.to_string(); }
parser::ParsedAttributeArgument::ParsedAttributeArgument(DeprecatedString a_name, utility::Span a_span, JaktInternal::Optional<DeprecatedString> a_assigned_value) :name(a_name), span(a_span), assigned_value(a_assigned_value){}

ErrorOr<DeprecatedString> parser::ParsedAttribute::debug_description() const { auto builder = MUST(DeprecatedStringBuilder::create());TRY(builder.append("ParsedAttribute("sv));{
JaktInternal::PrettyPrint::ScopedLevelIncrease increase_indent {};
TRY(JaktInternal::PrettyPrint::output_indentation(builder));TRY(builder.append("name: "sv));TRY(builder.appendff("\"{}\", ", name));
TRY(JaktInternal::PrettyPrint::output_indentation(builder));TRY(builder.append("span: "sv));TRY(builder.appendff("{}, ", span));
TRY(JaktInternal::PrettyPrint::output_indentation(builder));TRY(builder.append("assigned_value: "sv));TRY(builder.appendff("{}, ", assigned_value));
TRY(JaktInternal::PrettyPrint::output_indentation(builder));TRY(builder.append("arguments: "sv));TRY(builder.appendff("{}", arguments));
}
TRY(builder.append(")"sv));return builder.to_string(); }
parser::ParsedAttribute::ParsedAttribute(DeprecatedString a_name, utility::Span a_span, JaktInternal::Optional<DeprecatedString> a_assigned_value, JaktInternal::DynamicArray<parser::ParsedAttributeArgument> a_arguments) :name(a_name), span(a_span), assigned_value(a_assigned_value), arguments(a_arguments){}

ErrorOr<DeprecatedString> parser::ParsedTrait::debug_description() const { auto builder = MUST(DeprecatedStringBuilder::create());TRY(builder.append("ParsedTrait("sv));{
JaktInternal::PrettyPrint::ScopedLevelIncrease increase_indent {};
TRY(JaktInternal::PrettyPrint::output_indentation(builder));TRY(builder.append("name: "sv));TRY(builder.appendff("\"{}\", ", name));
TRY(JaktInternal::PrettyPrint::output_indentation(builder));TRY(builder.append("name_span: "sv));TRY(builder.appendff("{}, ", name_span));
TRY(JaktInternal::PrettyPrint::output_indentation(builder));TRY(builder.append("generic_parameters: "sv));TRY(builder.appendff("{}, ", generic_parameters));
TRY(JaktInternal::PrettyPrint::output_indentation(builder));TRY(builder.append("methods: "sv));TRY(builder.appendff("{}", methods));
}
TRY(builder.append(")"sv));return builder.to_string(); }
parser::ParsedTrait::ParsedTrait(DeprecatedString a_name, utility::Span a_name_span, JaktInternal::DynamicArray<parser::ParsedGenericParameter> a_generic_parameters, JaktInternal::DynamicArray<parser::ParsedFunction> a_methods) :name(a_name), name_span(a_name_span), generic_parameters(a_generic_parameters), methods(a_methods){}

ErrorOr<DeprecatedString> parser::Parser::debug_description() const { auto builder = MUST(DeprecatedStringBuilder::create());TRY(builder.append("Parser("sv));{
JaktInternal::PrettyPrint::ScopedLevelIncrease increase_indent {};
TRY(JaktInternal::PrettyPrint::output_indentation(builder));TRY(builder.append("index: "sv));TRY(builder.appendff("{}, ", index));
TRY(JaktInternal::PrettyPrint::output_indentation(builder));TRY(builder.append("tokens: "sv));TRY(builder.appendff("{}, ", tokens));
TRY(JaktInternal::PrettyPrint::output_indentation(builder));TRY(builder.append("compiler: "sv));TRY(builder.appendff("{}, ", *compiler));
TRY(JaktInternal::PrettyPrint::output_indentation(builder));TRY(builder.append("can_have_trailing_closure: "sv));TRY(builder.appendff("{}", can_have_trailing_closure));
}
TRY(builder.append(")"sv));return builder.to_string(); }
ErrorOr<JaktInternal::Tuple<JaktInternal::DynamicArray<parser::ValueEnumVariant>,JaktInternal::DynamicArray<parser::ParsedMethod>>> parser::Parser::parse_value_enum_body(parser::ParsedRecord const partial_enum,parser::DefinitionLinkage const definition_linkage) {
{
JaktInternal::DynamicArray<parser::ParsedMethod> methods = (TRY((DynamicArray<parser::ParsedMethod>::create_with({}))));
JaktInternal::DynamicArray<parser::ValueEnumVariant> variants = (TRY((DynamicArray<parser::ValueEnumVariant>::create_with({}))));
if (((((*this).current())).index() == 10 /* LCurly */)){
((((*this).index)++));
}
else {
TRY((((*this).error(Jakt::DeprecatedString("Expected `{` to start the enum body"sv),((((*this).current())).span())))));
}

((*this).skip_newlines());
if (((*this).eof())){
TRY((((*this).error(Jakt::DeprecatedString("Incomplete enum definition, expected variant name"sv),((((*this).previous())).span())))));
return ((Tuple{variants, methods}));
}
JaktInternal::Optional<parser::Visibility> last_visibility = JaktInternal::OptionalNone();
JaktInternal::Optional<utility::Span> last_visibility_span = JaktInternal::OptionalNone();
while ((!(((*this).eof())))){
JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_AT_LOOP(([&]() -> JaktInternal::ExplicitValueOrControlFlow<void, ErrorOr<JaktInternal::Tuple<JaktInternal::DynamicArray<parser::ValueEnumVariant>,JaktInternal::DynamicArray<parser::ParsedMethod>>>>{
auto&& __jakt_match_variant = ((*this).current());
switch(__jakt_match_variant.index()) {
case 4: {
auto&& __jakt_match_value = __jakt_match_variant.template get<lexer::Token::Identifier>();DeprecatedString const& name = __jakt_match_value.name;
utility::Span const& span = __jakt_match_value.span;
{
if (((((*this).peek(static_cast<size_t>(1ULL)))).index() == 17 /* Equal */)){
({auto& _jakt_ref = ((*this).index);_jakt_ref = JaktInternal::checked_add<size_t>(_jakt_ref, static_cast<size_t>(2ULL));});
NonnullRefPtr<typename parser::ParsedExpression> const expr = TRY((((*this).parse_expression(false,false))));
TRY((((variants).push(parser::ValueEnumVariant(name,span,expr)))));
}
else {
((((*this).index)++));
TRY((((variants).push(parser::ValueEnumVariant(name,span,JaktInternal::OptionalNone())))));
}

}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 11: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::RCurly>();
{
((((*this).index)++));
return JaktInternal::LoopBreak{};
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 53: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::Comma>();
{
((((*this).index)++));
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 56: {
auto&& __jakt_match_value = __jakt_match_variant.template get<lexer::Token::Eol>();{
((((*this).index)++));
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 89: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::Private>();
utility::Span const& span = __jakt_match_value.value;
{
if (((last_visibility).has_value())){
TRY((((*this).error_with_hint(Jakt::DeprecatedString("Multiple visibility modifiers on one field or method are not allowed"sv),span,Jakt::DeprecatedString("Previous modifier is here"sv),(last_visibility_span.value())))));
}
(last_visibility =  parser::Visibility { typename parser::Visibility::Private() } );
(last_visibility_span = span);
((((*this).index)++));
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 90: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::Public>();
utility::Span const& span = __jakt_match_value.value;
{
if (((last_visibility).has_value())){
TRY((((*this).error_with_hint(Jakt::DeprecatedString("Multiple visibility modifiers on one field or method are not allowed"sv),span,Jakt::DeprecatedString("Previous modifier is here"sv),(last_visibility_span.value())))));
}
(last_visibility =  parser::Visibility { typename parser::Visibility::Public() } );
(last_visibility_span = span);
((((*this).index)++));
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 75: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::Function>();
{
bool const is_comptime = ((((*this).current())).index() == 76 /* Comptime */);
parser::FunctionLinkage const function_linkage = JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_AT_LOOP_NESTED_MATCH(([&]() -> JaktInternal::ExplicitValueOrControlFlow<parser::FunctionLinkage, ErrorOr<JaktInternal::Tuple<JaktInternal::DynamicArray<parser::ValueEnumVariant>,JaktInternal::DynamicArray<parser::ParsedMethod>>>>{
auto&& __jakt_match_variant = definition_linkage;
switch(__jakt_match_variant.index()) {
case 0: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename parser::DefinitionLinkage::Internal>();
return JaktInternal::ExplicitValue( parser::FunctionLinkage { typename parser::FunctionLinkage::Internal() } );
};/*case end*/
case 1: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename parser::DefinitionLinkage::External>();
return JaktInternal::ExplicitValue( parser::FunctionLinkage { typename parser::FunctionLinkage::External() } );
};/*case end*/
default: VERIFY_NOT_REACHED();}/*switch end*/
}()
));
if ((((function_linkage).index() == 1 /* External */) && is_comptime)){
TRY((((*this).error(Jakt::DeprecatedString("External functions cannot be comptime"sv),((((*this).current())).span())))));
}
parser::Visibility const visibility = last_visibility.value_or_lazy_evaluated([&] { return  parser::Visibility { typename parser::Visibility::Public() } ; });
(last_visibility = JaktInternal::OptionalNone());
(last_visibility_span = JaktInternal::OptionalNone());
parser::ParsedMethod const parsed_method = TRY((((*this).parse_method(function_linkage,visibility,false,false,is_comptime))));
TRY((((methods).push(parsed_method))));
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 76: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::Comptime>();
{
bool const is_comptime = ((((*this).current())).index() == 76 /* Comptime */);
parser::FunctionLinkage const function_linkage = JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_AT_LOOP_NESTED_MATCH(([&]() -> JaktInternal::ExplicitValueOrControlFlow<parser::FunctionLinkage, ErrorOr<JaktInternal::Tuple<JaktInternal::DynamicArray<parser::ValueEnumVariant>,JaktInternal::DynamicArray<parser::ParsedMethod>>>>{
auto&& __jakt_match_variant = definition_linkage;
switch(__jakt_match_variant.index()) {
case 0: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename parser::DefinitionLinkage::Internal>();
return JaktInternal::ExplicitValue( parser::FunctionLinkage { typename parser::FunctionLinkage::Internal() } );
};/*case end*/
case 1: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename parser::DefinitionLinkage::External>();
return JaktInternal::ExplicitValue( parser::FunctionLinkage { typename parser::FunctionLinkage::External() } );
};/*case end*/
default: VERIFY_NOT_REACHED();}/*switch end*/
}()
));
if ((((function_linkage).index() == 1 /* External */) && is_comptime)){
TRY((((*this).error(Jakt::DeprecatedString("External functions cannot be comptime"sv),((((*this).current())).span())))));
}
parser::Visibility const visibility = last_visibility.value_or_lazy_evaluated([&] { return  parser::Visibility { typename parser::Visibility::Public() } ; });
(last_visibility = JaktInternal::OptionalNone());
(last_visibility_span = JaktInternal::OptionalNone());
parser::ParsedMethod const parsed_method = TRY((((*this).parse_method(function_linkage,visibility,false,false,is_comptime))));
TRY((((methods).push(parsed_method))));
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
default: {
{
TRY((((*this).error(Jakt::DeprecatedString("Expected identifier or the end of enum block"sv),((((*this).current())).span())))));
((((*this).index)++));
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
}/*switch end*/
}()
));
}
if (((*this).eof())){
TRY((((*this).error(Jakt::DeprecatedString("Invalid enum definition, expected `}`"sv),((((*this).current())).span())))));
return ((Tuple{variants, methods}));
}
if (((variants).is_empty())){
TRY((((*this).error(Jakt::DeprecatedString("Empty enums are not allowed"sv),((partial_enum).name_span)))));
}
return ((Tuple{variants, methods}));
}
}

ErrorOr<JaktInternal::DynamicArray<NonnullRefPtr<typename parser::ParsedType>>> parser::Parser::parse_type_parameter_list() {
{
JaktInternal::DynamicArray<NonnullRefPtr<typename parser::ParsedType>> params = (TRY((DynamicArray<NonnullRefPtr<typename parser::ParsedType>>::create_with({}))));
if (((((*this).current())).index() == 29 /* LessThan */)){
((((*this).index)++));
bool saw_ending_bracket = false;
while ((!(((*this).eof())))){
JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_AT_LOOP(([&]() -> JaktInternal::ExplicitValueOrControlFlow<void, ErrorOr<JaktInternal::DynamicArray<NonnullRefPtr<typename parser::ParsedType>>>>{
auto&& __jakt_match_variant = ((*this).current());
switch(__jakt_match_variant.index()) {
case 27: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::GreaterThan>();
{
((((*this).index)++));
(saw_ending_bracket = true);
return JaktInternal::LoopBreak{};
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 34: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::RightShift>();
{
TRY((((*this).inject_token( lexer::Token { typename lexer::Token::GreaterThan(((((*this).current())).span())) } ))));
((((*this).index)++));
(saw_ending_bracket = true);
return JaktInternal::LoopBreak{};
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
default: {
{
size_t index_before = ((*this).index);
TRY((((params).push(TRY((((*this).parse_typename())))))));
if ((((*this).index) == index_before)){
TRY((((*this).error(Jakt::DeprecatedString("Expected type parameter"sv),((((*this).current())).span())))));
return JaktInternal::LoopBreak{};
}
if (((((*this).current())).index() == 53 /* Comma */)){
((((*this).index)++));
}
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
}/*switch end*/
}()
));
}
if ((!(saw_ending_bracket))){
TRY((((*this).error(Jakt::DeprecatedString("Expected `>` after type parameters"sv),((((*this).current())).span())))));
}
}
return (params);
}
}

ErrorOr<NonnullRefPtr<typename parser::ParsedStatement>> parser::Parser::parse_statement(bool const inside_block) {
{
utility::Span const start = ((((*this).current())).span());
return (JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<NonnullRefPtr<typename parser::ParsedStatement>, ErrorOr<NonnullRefPtr<typename parser::ParsedStatement>>>{
auto&& __jakt_match_variant = ((*this).current());
switch(__jakt_match_variant.index()) {
case 68: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::Cpp>();
return JaktInternal::ExplicitValue(({ Optional<NonnullRefPtr<typename parser::ParsedStatement>> __jakt_var_5; {
((((*this).index)++));
__jakt_var_5 = TRY((parser::ParsedStatement::template create<typename parser::ParsedStatement::InlineCpp>(TRY((((*this).parse_block()))),TRY((parser::merge_spans(start,((((*this).previous())).span()))))))); goto __jakt_label_3;

}
__jakt_label_3:; __jakt_var_5.release_value(); }));
};/*case end*/
case 69: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::Defer>();
return JaktInternal::ExplicitValue(({ Optional<NonnullRefPtr<typename parser::ParsedStatement>> __jakt_var_6; {
((((*this).index)++));
NonnullRefPtr<typename parser::ParsedStatement> const statement = TRY((((*this).parse_statement(false))));
__jakt_var_6 = TRY((parser::ParsedStatement::template create<typename parser::ParsedStatement::Defer>(statement,TRY((parser::merge_spans(start,((((*this).previous())).span()))))))); goto __jakt_label_4;

}
__jakt_label_4:; __jakt_var_6.release_value(); }));
};/*case end*/
case 100: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::Unsafe>();
return JaktInternal::ExplicitValue(({ Optional<NonnullRefPtr<typename parser::ParsedStatement>> __jakt_var_7; {
((((*this).index)++));
parser::ParsedBlock const block = TRY((((*this).parse_block())));
__jakt_var_7 = TRY((parser::ParsedStatement::template create<typename parser::ParsedStatement::UnsafeBlock>(block,TRY((parser::merge_spans(start,((((*this).previous())).span()))))))); goto __jakt_label_5;

}
__jakt_label_5:; __jakt_var_7.release_value(); }));
};/*case end*/
case 64: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::Break>();
return JaktInternal::ExplicitValue(({ Optional<NonnullRefPtr<typename parser::ParsedStatement>> __jakt_var_8; {
((((*this).index)++));
__jakt_var_8 = TRY((parser::ParsedStatement::template create<typename parser::ParsedStatement::Break>(start))); goto __jakt_label_6;

}
__jakt_label_6:; __jakt_var_8.release_value(); }));
};/*case end*/
case 67: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::Continue>();
return JaktInternal::ExplicitValue(({ Optional<NonnullRefPtr<typename parser::ParsedStatement>> __jakt_var_9; {
((((*this).index)++));
__jakt_var_9 = TRY((parser::ParsedStatement::template create<typename parser::ParsedStatement::Continue>(start))); goto __jakt_label_7;

}
__jakt_label_7:; __jakt_var_9.release_value(); }));
};/*case end*/
case 82: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::Loop>();
return JaktInternal::ExplicitValue(({ Optional<NonnullRefPtr<typename parser::ParsedStatement>> __jakt_var_10; {
((((*this).index)++));
parser::ParsedBlock const block = TRY((((*this).parse_block())));
__jakt_var_10 = TRY((parser::ParsedStatement::template create<typename parser::ParsedStatement::Loop>(block,TRY((parser::merge_spans(start,((((*this).previous())).span()))))))); goto __jakt_label_8;

}
__jakt_label_8:; __jakt_var_10.release_value(); }));
};/*case end*/
case 96: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::Throw>();
return JaktInternal::ExplicitValue(({ Optional<NonnullRefPtr<typename parser::ParsedStatement>> __jakt_var_11; {
((((*this).index)++));
NonnullRefPtr<typename parser::ParsedExpression> const expr = TRY((((*this).parse_expression(false,false))));
__jakt_var_11 = TRY((parser::ParsedStatement::template create<typename parser::ParsedStatement::Throw>(expr,TRY((parser::merge_spans(start,((((*this).previous())).span()))))))); goto __jakt_label_9;

}
__jakt_label_9:; __jakt_var_11.release_value(); }));
};/*case end*/
case 103: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::While>();
return JaktInternal::ExplicitValue(({ Optional<NonnullRefPtr<typename parser::ParsedStatement>> __jakt_var_12; {
((((*this).index)++));
bool const previous_can_have_trailing_closure = ((*this).can_have_trailing_closure);
(((*this).can_have_trailing_closure) = false);
NonnullRefPtr<typename parser::ParsedExpression> const condition = TRY((((*this).parse_expression(false,true))));
(((*this).can_have_trailing_closure) = previous_can_have_trailing_closure);
parser::ParsedBlock const block = TRY((((*this).parse_block())));
__jakt_var_12 = TRY((parser::ParsedStatement::template create<typename parser::ParsedStatement::While>(condition,block,TRY((parser::merge_spans(start,((((*this).previous())).span()))))))); goto __jakt_label_10;

}
__jakt_label_10:; __jakt_var_12.release_value(); }));
};/*case end*/
case 104: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::Yield>();
return JaktInternal::ExplicitValue(({ Optional<NonnullRefPtr<typename parser::ParsedStatement>> __jakt_var_13; {
((((*this).index)++));
NonnullRefPtr<typename parser::ParsedExpression> const expr = TRY((((*this).parse_expression(false,false))));
if ((!(inside_block))){
TRY((((*this).error(Jakt::DeprecatedString("‘yield’ can only be used inside a block"sv),TRY((parser::merge_spans(start,((expr)->span()))))))));
}
__jakt_var_13 = TRY((parser::ParsedStatement::template create<typename parser::ParsedStatement::Yield>(expr,TRY((parser::merge_spans(start,((((*this).previous())).span()))))))); goto __jakt_label_11;

}
__jakt_label_11:; __jakt_var_13.release_value(); }));
};/*case end*/
case 92: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::Return>();
return JaktInternal::ExplicitValue(({ Optional<NonnullRefPtr<typename parser::ParsedStatement>> __jakt_var_14; {
((((*this).index)++));
__jakt_var_14 = JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<NonnullRefPtr<typename parser::ParsedStatement>, ErrorOr<NonnullRefPtr<typename parser::ParsedStatement>>>{
auto&& __jakt_match_variant = ((*this).current());
switch(__jakt_match_variant.index()) {
case 56: {
auto&& __jakt_match_value = __jakt_match_variant.template get<lexer::Token::Eol>();return JaktInternal::ExplicitValue(TRY((parser::ParsedStatement::template create<typename parser::ParsedStatement::Return>(JaktInternal::OptionalNone(),start))));
};/*case end*/
case 57: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::Eof>();
return JaktInternal::ExplicitValue(TRY((parser::ParsedStatement::template create<typename parser::ParsedStatement::Return>(JaktInternal::OptionalNone(),start))));
};/*case end*/
case 11: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::RCurly>();
return JaktInternal::ExplicitValue(TRY((parser::ParsedStatement::template create<typename parser::ParsedStatement::Return>(JaktInternal::OptionalNone(),start))));
};/*case end*/
default: {
return JaktInternal::ExplicitValue(TRY((parser::ParsedStatement::template create<typename parser::ParsedStatement::Return>(TRY((((*this).parse_expression(false,false)))),TRY((parser::merge_spans(start,((((*this).previous())).span()))))))));
};/*case end*/
}/*switch end*/
}()
)); goto __jakt_label_12;

}
__jakt_label_12:; __jakt_var_14.release_value(); }));
};/*case end*/
case 81: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::Let>();
return JaktInternal::ExplicitValue(({ Optional<NonnullRefPtr<typename parser::ParsedStatement>> __jakt_var_15; {
bool const is_mutable = ((((*this).current())).index() == 84 /* Mut */);
((((*this).index)++));
JaktInternal::DynamicArray<parser::ParsedVarDecl> vars = (TRY((DynamicArray<parser::ParsedVarDecl>::create_with({}))));
bool is_destructuring_assingment = false;
DeprecatedString tuple_var_name = Jakt::DeprecatedString(""sv);
parser::ParsedVarDecl tuple_var_decl = parser::ParsedVarDecl(Jakt::DeprecatedString(""sv),TRY((parser::ParsedType::template create<typename parser::ParsedType::Empty>())),is_mutable,JaktInternal::OptionalNone(),((((*this).current())).span()));
if (((((*this).current())).index() == 8 /* LParen */)){
(vars = TRY((((*this).parse_destructuring_assignment(is_mutable)))));
{
JaktInternal::ArrayIterator<parser::ParsedVarDecl> _magic = ((vars).iterator());
for (;;){
JaktInternal::Optional<parser::ParsedVarDecl> _magic_value = ((_magic).next());
if ((!(((_magic_value).has_value())))){
break;
}
parser::ParsedVarDecl var = (_magic_value.value());
{
(tuple_var_name += ((var).name));
(tuple_var_name += Jakt::DeprecatedString("_"sv));
}

}
}

(((tuple_var_decl).name) = tuple_var_name);
(is_destructuring_assingment = true);
}
else {
(tuple_var_decl = TRY((((*this).parse_variable_declaration(is_mutable)))));
}

NonnullRefPtr<typename parser::ParsedExpression> const init = JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<NonnullRefPtr<typename parser::ParsedExpression>, ErrorOr<NonnullRefPtr<typename parser::ParsedStatement>>>{
auto&& __jakt_match_variant = ((*this).current());
switch(__jakt_match_variant.index()) {
case 17: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::Equal>();
return JaktInternal::ExplicitValue(({ Optional<NonnullRefPtr<typename parser::ParsedExpression>> __jakt_var_16; {
((((*this).index)++));
__jakt_var_16 = TRY((((*this).parse_expression(false,false)))); goto __jakt_label_14;

}
__jakt_label_14:; __jakt_var_16.release_value(); }));
};/*case end*/
default: {
return JaktInternal::ExplicitValue(({ Optional<NonnullRefPtr<typename parser::ParsedExpression>> __jakt_var_17; {
TRY((((*this).error(Jakt::DeprecatedString("Expected initializer"sv),((((*this).current())).span())))));
__jakt_var_17 = TRY((parser::ParsedExpression::template create<typename parser::ParsedExpression::Garbage>(((((*this).current())).span())))); goto __jakt_label_15;

}
__jakt_label_15:; __jakt_var_17.release_value(); }));
};/*case end*/
}/*switch end*/
}()
));
NonnullRefPtr<typename parser::ParsedStatement> return_statement = TRY((parser::ParsedStatement::template create<typename parser::ParsedStatement::VarDecl>(tuple_var_decl,init,TRY((parser::merge_spans(start,((((*this).previous())).span())))))));
if (is_destructuring_assingment){
NonnullRefPtr<typename parser::ParsedStatement> const old_return_statement = return_statement;
(return_statement = TRY((parser::ParsedStatement::template create<typename parser::ParsedStatement::DestructuringAssignment>(vars,old_return_statement,TRY((parser::merge_spans(start,((((*this).previous())).span()))))))));
}
__jakt_var_15 = return_statement; goto __jakt_label_13;

}
__jakt_label_13:; __jakt_var_15.release_value(); }));
};/*case end*/
case 84: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::Mut>();
return JaktInternal::ExplicitValue(({ Optional<NonnullRefPtr<typename parser::ParsedStatement>> __jakt_var_18; {
bool const is_mutable = ((((*this).current())).index() == 84 /* Mut */);
((((*this).index)++));
JaktInternal::DynamicArray<parser::ParsedVarDecl> vars = (TRY((DynamicArray<parser::ParsedVarDecl>::create_with({}))));
bool is_destructuring_assingment = false;
DeprecatedString tuple_var_name = Jakt::DeprecatedString(""sv);
parser::ParsedVarDecl tuple_var_decl = parser::ParsedVarDecl(Jakt::DeprecatedString(""sv),TRY((parser::ParsedType::template create<typename parser::ParsedType::Empty>())),is_mutable,JaktInternal::OptionalNone(),((((*this).current())).span()));
if (((((*this).current())).index() == 8 /* LParen */)){
(vars = TRY((((*this).parse_destructuring_assignment(is_mutable)))));
{
JaktInternal::ArrayIterator<parser::ParsedVarDecl> _magic = ((vars).iterator());
for (;;){
JaktInternal::Optional<parser::ParsedVarDecl> _magic_value = ((_magic).next());
if ((!(((_magic_value).has_value())))){
break;
}
parser::ParsedVarDecl var = (_magic_value.value());
{
(tuple_var_name += ((var).name));
(tuple_var_name += Jakt::DeprecatedString("_"sv));
}

}
}

(((tuple_var_decl).name) = tuple_var_name);
(is_destructuring_assingment = true);
}
else {
(tuple_var_decl = TRY((((*this).parse_variable_declaration(is_mutable)))));
}

NonnullRefPtr<typename parser::ParsedExpression> const init = JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<NonnullRefPtr<typename parser::ParsedExpression>, ErrorOr<NonnullRefPtr<typename parser::ParsedStatement>>>{
auto&& __jakt_match_variant = ((*this).current());
switch(__jakt_match_variant.index()) {
case 17: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::Equal>();
return JaktInternal::ExplicitValue(({ Optional<NonnullRefPtr<typename parser::ParsedExpression>> __jakt_var_19; {
((((*this).index)++));
__jakt_var_19 = TRY((((*this).parse_expression(false,false)))); goto __jakt_label_17;

}
__jakt_label_17:; __jakt_var_19.release_value(); }));
};/*case end*/
default: {
return JaktInternal::ExplicitValue(({ Optional<NonnullRefPtr<typename parser::ParsedExpression>> __jakt_var_20; {
TRY((((*this).error(Jakt::DeprecatedString("Expected initializer"sv),((((*this).current())).span())))));
__jakt_var_20 = TRY((parser::ParsedExpression::template create<typename parser::ParsedExpression::Garbage>(((((*this).current())).span())))); goto __jakt_label_18;

}
__jakt_label_18:; __jakt_var_20.release_value(); }));
};/*case end*/
}/*switch end*/
}()
));
NonnullRefPtr<typename parser::ParsedStatement> return_statement = TRY((parser::ParsedStatement::template create<typename parser::ParsedStatement::VarDecl>(tuple_var_decl,init,TRY((parser::merge_spans(start,((((*this).previous())).span())))))));
if (is_destructuring_assingment){
NonnullRefPtr<typename parser::ParsedStatement> const old_return_statement = return_statement;
(return_statement = TRY((parser::ParsedStatement::template create<typename parser::ParsedStatement::DestructuringAssignment>(vars,old_return_statement,TRY((parser::merge_spans(start,((((*this).previous())).span()))))))));
}
__jakt_var_18 = return_statement; goto __jakt_label_16;

}
__jakt_label_16:; __jakt_var_18.release_value(); }));
};/*case end*/
case 77: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::If>();
return JaktInternal::ExplicitValue(TRY((((*this).parse_if_statement()))));
};/*case end*/
case 74: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::For>();
return JaktInternal::ExplicitValue(TRY((((*this).parse_for_statement()))));
};/*case end*/
case 10: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::LCurly>();
return JaktInternal::ExplicitValue(({ Optional<NonnullRefPtr<typename parser::ParsedStatement>> __jakt_var_21; {
parser::ParsedBlock const block = TRY((((*this).parse_block())));
__jakt_var_21 = TRY((parser::ParsedStatement::template create<typename parser::ParsedStatement::Block>(block,TRY((parser::merge_spans(start,((((*this).previous())).span()))))))); goto __jakt_label_19;

}
__jakt_label_19:; __jakt_var_21.release_value(); }));
};/*case end*/
case 105: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::Guard>();
return JaktInternal::ExplicitValue(TRY((((*this).parse_guard_statement()))));
};/*case end*/
default: {
return JaktInternal::ExplicitValue(({ Optional<NonnullRefPtr<typename parser::ParsedStatement>> __jakt_var_22; {
NonnullRefPtr<typename parser::ParsedExpression> const expr = TRY((((*this).parse_expression(true,false))));
__jakt_var_22 = TRY((parser::ParsedStatement::template create<typename parser::ParsedStatement::Expression>(expr,TRY((parser::merge_spans(start,((((*this).previous())).span()))))))); goto __jakt_label_20;

}
__jakt_label_20:; __jakt_var_22.release_value(); }));
};/*case end*/
}/*switch end*/
}()
)));
}
}

ErrorOr<NonnullRefPtr<typename parser::ParsedType>> parser::Parser::parse_type_shorthand_array_or_dictionary() {
{
utility::Span const start = ((((*this).current())).span());
((((*this).index)++));
NonnullRefPtr<typename parser::ParsedType> const inner = TRY((((*this).parse_typename())));
if (((((*this).current())).index() == 13 /* RSquare */)){
((((*this).index)++));
return (TRY((parser::ParsedType::template create<typename parser::ParsedType::JaktArray>(inner,TRY((parser::merge_spans(start,((((*this).previous())).span()))))))));
}
if (((((*this).current())).index() == 6 /* Colon */)){
((((*this).index)++));
NonnullRefPtr<typename parser::ParsedType> const value = TRY((((*this).parse_typename())));
if (((((*this).current())).index() == 13 /* RSquare */)){
((((*this).index)++));
}
else {
TRY((((*this).error(Jakt::DeprecatedString("Expected ']'"sv),((((*this).current())).span())))));
}

return (TRY((parser::ParsedType::template create<typename parser::ParsedType::Dictionary>(inner,value,TRY((parser::merge_spans(start,((((*this).current())).span()))))))));
}
TRY((((*this).error(Jakt::DeprecatedString("Expected shorthand type"sv),((((*this).current())).span())))));
return (TRY((parser::ParsedType::template create<typename parser::ParsedType::Empty>())));
}
}

ErrorOr<parser::ParsedBlock> parser::Parser::parse_fat_arrow() {
{
((((*this).index)++));
utility::Span const start = ((((*this).current())).span());
NonnullRefPtr<typename parser::ParsedExpression> const expr = TRY((((*this).parse_expression(false,false))));
NonnullRefPtr<typename parser::ParsedStatement> const return_statement = TRY((parser::ParsedStatement::template create<typename parser::ParsedStatement::Return>(expr,TRY((parser::merge_spans(start,((((*this).current())).span())))))));
return (parser::ParsedBlock((TRY((DynamicArray<NonnullRefPtr<typename parser::ParsedStatement>>::create_with({return_statement}))))));
}
}

ErrorOr<NonnullRefPtr<typename parser::ParsedType>> parser::Parser::parse_typename() {
{
utility::Span const start = ((((*this).current())).span());
bool is_reference = false;
bool is_mutable_reference = false;
if (((((*this).current())).index() == 38 /* Ampersand */)){
(is_reference = true);
((((*this).index)++));
if (((((*this).current())).index() == 84 /* Mut */)){
(is_mutable_reference = true);
((((*this).index)++));
}
}
NonnullRefPtr<typename parser::ParsedType> parsed_type = TRY((((*this).parse_type_shorthand())));
if (((parsed_type)->index() == 13 /* Empty */)){
(parsed_type = TRY((((*this).parse_type_longhand()))));
}
if (((((*this).current())).index() == 50 /* QuestionMark */)){
((((*this).index)++));
utility::Span const span = TRY((parser::merge_spans(start,((((*this).current())).span()))));
(parsed_type = TRY((parser::ParsedType::template create<typename parser::ParsedType::Optional>(parsed_type,span))));
}
if (is_reference){
utility::Span const span = TRY((parser::merge_spans(start,((((*this).current())).span()))));
if (is_mutable_reference){
(parsed_type = TRY((parser::ParsedType::template create<typename parser::ParsedType::MutableReference>(parsed_type,span))));
}
else {
(parsed_type = TRY((parser::ParsedType::template create<typename parser::ParsedType::Reference>(parsed_type,span))));
}

}
return (parsed_type);
}
}

ErrorOr<void> parser::Parser::error_with_hint(DeprecatedString const message,utility::Span const span,DeprecatedString const hint,utility::Span const hint_span) {
{
if ((!(((((*this).compiler))->ignore_parser_errors)))){
TRY((((((((*this).compiler))->errors)).push( error::JaktError { typename error::JaktError::MessageWithHint(message,span,hint,hint_span) } ))));
}
}
return {};
}

ErrorOr<parser::ParsedRecord> parser::Parser::parse_class(parser::DefinitionLinkage const definition_linkage) {
{
parser::ParsedRecord parsed_class = parser::ParsedRecord(Jakt::DeprecatedString(""sv),((*this).empty_span()),(TRY((DynamicArray<parser::ParsedGenericParameter>::create_with({})))),definition_linkage,JaktInternal::OptionalNone(),(TRY((DynamicArray<parser::ParsedMethod>::create_with({})))), parser::RecordType { typename parser::RecordType::Garbage() } ,JaktInternal::OptionalNone());
JaktInternal::Optional<NonnullRefPtr<typename parser::ParsedType>> super_type = JaktInternal::OptionalNone();
if (((((*this).current())).index() == 66 /* Class */)){
((((*this).index)++));
}
else {
TRY((((*this).error(Jakt::DeprecatedString("Expected `class` keyword"sv),((((*this).current())).span())))));
return (parsed_class);
}

if (((*this).eof())){
TRY((((*this).error(Jakt::DeprecatedString("Incomplete class definition, expected name"sv),((((*this).current())).span())))));
return (parsed_class);
}
if (((((*this).current())).index() == 4 /* Identifier */)){
DeprecatedString const name = ((((*this).current())).get<lexer::Token::Identifier>()).name;
utility::Span const span = ((((*this).current())).get<lexer::Token::Identifier>()).span;
((((*this).index)++));
(((parsed_class).name) = name);
(((parsed_class).name_span) = span);
}
else {
TRY((((*this).error(Jakt::DeprecatedString("Incomplete class definition, expected name"sv),((((*this).current())).span())))));
}

if (((*this).eof())){
TRY((((*this).error(Jakt::DeprecatedString("Incomplete class definition, expected generic parameters or super class or body"sv),((((*this).current())).span())))));
return (parsed_class);
}
(((parsed_class).generic_parameters) = TRY((((*this).parse_generic_parameters()))));
if (((((*this).current())).index() == 106 /* Implements */)){
((((*this).index)++));
(((parsed_class).implements_list) = TRY((((*this).parse_trait_list()))));
}
if (((*this).eof())){
TRY((((*this).error(Jakt::DeprecatedString("Incomplete class definition, expected super class or body"sv),((((*this).current())).span())))));
return (parsed_class);
}
if (((((*this).current())).index() == 6 /* Colon */)){
((((*this).index)++));
(super_type = TRY((((*this).parse_typename()))));
}
((*this).skip_newlines());
if (((*this).eof())){
TRY((((*this).error(Jakt::DeprecatedString("Incomplete class definition, expected body"sv),((((*this).current())).span())))));
return (parsed_class);
}
JaktInternal::Tuple<JaktInternal::DynamicArray<parser::ParsedField>,JaktInternal::DynamicArray<parser::ParsedMethod>> const fields_methods_ = TRY((((*this).parse_struct_class_body(definition_linkage, parser::Visibility { typename parser::Visibility::Private() } ,true))));
JaktInternal::DynamicArray<parser::ParsedField> const fields = ((fields_methods_).template get<0>());
JaktInternal::DynamicArray<parser::ParsedMethod> const methods = ((fields_methods_).template get<1>());

(((parsed_class).methods) = methods);
(((parsed_class).record_type) =  parser::RecordType { typename parser::RecordType::Class(fields,super_type) } );
return (parsed_class);
}
}

bool parser::Parser::eof() const {
{
return ((((*this).index) >= (JaktInternal::checked_sub<size_t>(((((*this).tokens)).size()),static_cast<size_t>(1ULL)))));
}
}

ErrorOr<JaktInternal::DynamicArray<parser::ParsedVarDecl>> parser::Parser::parse_destructuring_assignment(bool const is_mutable) {
{
((((*this).index)++));
JaktInternal::DynamicArray<parser::ParsedVarDecl> var_declarations = (TRY((DynamicArray<parser::ParsedVarDecl>::create_with({}))));
for (;;){
JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_AT_LOOP(([&]() -> JaktInternal::ExplicitValueOrControlFlow<void, ErrorOr<JaktInternal::DynamicArray<parser::ParsedVarDecl>>>{
auto&& __jakt_match_variant = ((*this).current());
switch(__jakt_match_variant.index()) {
case 4: {
auto&& __jakt_match_value = __jakt_match_variant.template get<lexer::Token::Identifier>();{
TRY((((var_declarations).push(TRY((((*this).parse_variable_declaration(is_mutable))))))));
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 53: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::Comma>();
{
((((*this).index)++));
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 9: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::RParen>();
{
((((*this).index)++));
return (var_declarations);
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
default: {
{
TRY((((*this).error(Jakt::DeprecatedString("Expected close of destructuring assignment block"sv),((((*this).current())).span())))));
return ((TRY((DynamicArray<parser::ParsedVarDecl>::create_with({})))));
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
}/*switch end*/
}()
));
}
return ((TRY((DynamicArray<parser::ParsedVarDecl>::create_with({})))));
}
}

ErrorOr<NonnullRefPtr<typename parser::ParsedExpression>> parser::Parser::parse_match_expression() {
{
utility::Span start = ((((*this).current())).span());
((((*this).index)++));
bool const previous_can_have_trailing_closure = ((*this).can_have_trailing_closure);
(((*this).can_have_trailing_closure) = false);
NonnullRefPtr<typename parser::ParsedExpression> const expr = TRY((((*this).parse_expression(false,true))));
(((*this).can_have_trailing_closure) = previous_can_have_trailing_closure);
JaktInternal::DynamicArray<parser::ParsedMatchCase> const cases = TRY((((*this).parse_match_cases())));
if ((((cases).size()) > static_cast<size_t>(1ULL))){
{
JaktInternal::Range<size_t> _magic = (JaktInternal::Range<size_t>{static_cast<size_t>(0LL),static_cast<size_t>((JaktInternal::checked_sub<size_t>(((cases).size()),static_cast<size_t>(1ULL))))});
for (;;){
JaktInternal::Optional<size_t> _magic_value = ((_magic).next());
if ((!(((_magic_value).has_value())))){
break;
}
size_t i = (_magic_value.value());
{
{
JaktInternal::Range<size_t> _magic = (JaktInternal::Range<size_t>{static_cast<size_t>((JaktInternal::checked_add<size_t>(i,static_cast<size_t>(1ULL)))),static_cast<size_t>(((cases).size()))});
for (;;){
JaktInternal::Optional<size_t> _magic_value = ((_magic).next());
if ((!(((_magic_value).has_value())))){
break;
}
size_t k = (_magic_value.value());
{
if (((((cases)[i])).has_equal_pattern(((cases)[k])))){
TRY((((*this).error_with_hint(Jakt::DeprecatedString("Duplicated match pattern"sv),((((cases)[k])).marker_span),Jakt::DeprecatedString("Original pattern here"sv),((((cases)[i])).marker_span)))));
}
}

}
}

}

}
}

}
return (TRY((parser::ParsedExpression::template create<typename parser::ParsedExpression::Match>(expr,cases,TRY((parser::merge_spans(start,((((*this).previous())).span())))),start))));
}
}

ErrorOr<NonnullRefPtr<typename parser::ParsedExpression>> parser::Parser::parse_lambda() {
{
utility::Span const start = ((((*this).current())).span());
((((*this).index)++));
JaktInternal::DynamicArray<parser::ParsedCapture> const captures = TRY((((*this).parse_captures())));
JaktInternal::DynamicArray<parser::ParsedParameter> const params = TRY((((*this).parse_function_parameters())));
bool const can_throw = ((((*this).current())).index() == 97 /* Throws */);
if (can_throw){
((((*this).index)++));
}
NonnullRefPtr<typename parser::ParsedType> return_type = JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<NonnullRefPtr<typename parser::ParsedType>, ErrorOr<NonnullRefPtr<typename parser::ParsedExpression>>>{
auto&& __jakt_match_variant = ((*this).current());
switch(__jakt_match_variant.index()) {
case 59: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::Arrow>();
return JaktInternal::ExplicitValue(({ Optional<NonnullRefPtr<typename parser::ParsedType>> __jakt_var_23; {
((((*this).index)++));
__jakt_var_23 = TRY((((*this).parse_typename()))); goto __jakt_label_21;

}
__jakt_label_21:; __jakt_var_23.release_value(); }));
};/*case end*/
default: {
return JaktInternal::ExplicitValue(TRY((parser::ParsedType::template create<typename parser::ParsedType::Empty>())));
};/*case end*/
}/*switch end*/
}()
));
bool is_fat_arrow = false;
parser::ParsedBlock const block = JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<parser::ParsedBlock, ErrorOr<NonnullRefPtr<typename parser::ParsedExpression>>>{
auto&& __jakt_match_variant = ((*this).current());
switch(__jakt_match_variant.index()) {
case 58: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::FatArrow>();
return JaktInternal::ExplicitValue(({ Optional<parser::ParsedBlock> __jakt_var_24; {
(is_fat_arrow = true);
((((*this).index)++));
NonnullRefPtr<typename parser::ParsedExpression> const expr = TRY((((*this).parse_expression(true,false))));
utility::Span const span = ((expr)->span());
__jakt_var_24 = parser::ParsedBlock((TRY((DynamicArray<NonnullRefPtr<typename parser::ParsedStatement>>::create_with({TRY((parser::ParsedStatement::template create<typename parser::ParsedStatement::Return>(expr,span)))}))))); goto __jakt_label_22;

}
__jakt_label_22:; __jakt_var_24.release_value(); }));
};/*case end*/
default: {
return JaktInternal::ExplicitValue(TRY((((*this).parse_block()))));
};/*case end*/
}/*switch end*/
}()
));
return (TRY((parser::ParsedExpression::template create<typename parser::ParsedExpression::Function>(captures,params,can_throw,is_fat_arrow,return_type,block,TRY((parser::merge_spans(start,((((*this).current())).span()))))))));
}
}

lexer::Token parser::Parser::previous() const {
{
if (((((*this).index) == static_cast<size_t>(0ULL)) || (((*this).index) > ((((*this).tokens)).size())))){
return ( lexer::Token { typename lexer::Token::Eof(((*this).span(static_cast<size_t>(0ULL),static_cast<size_t>(0ULL)))) } );
}
return (((((*this).tokens))[(JaktInternal::checked_sub<size_t>(((*this).index),static_cast<size_t>(1ULL)))]));
}
}

ErrorOr<parser::ParsedBlock> parser::Parser::parse_block() {
{
utility::Span const start = ((((*this).current())).span());
parser::ParsedBlock block = parser::ParsedBlock((TRY((DynamicArray<NonnullRefPtr<typename parser::ParsedStatement>>::create_with({})))));
if (((*this).eof())){
TRY((((*this).error(Jakt::DeprecatedString("Incomplete block"sv),start))));
return (block);
}
((*this).skip_newlines());
if (((((*this).current())).index() == 10 /* LCurly */)){
((((*this).index)++));
}
else {
TRY((((*this).error(Jakt::DeprecatedString("Expected '{'"sv),start))));
}

while ((!(((*this).eof())))){
JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_AT_LOOP(([&]() -> JaktInternal::ExplicitValueOrControlFlow<void, ErrorOr<parser::ParsedBlock>>{
auto&& __jakt_match_variant = ((*this).current());
switch(__jakt_match_variant.index()) {
case 11: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::RCurly>();
{
((((*this).index)++));
return (block);
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 5: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::Semicolon>();
{
((((*this).index)++));
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 56: {
auto&& __jakt_match_value = __jakt_match_variant.template get<lexer::Token::Eol>();{
((((*this).index)++));
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
default: {
{
TRY((((((block).stmts)).push(TRY((((*this).parse_statement(true))))))));
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
}/*switch end*/
}()
));
}
TRY((((*this).error(Jakt::DeprecatedString("Expected complete block"sv),((((*this).current())).span())))));
return (block);
}
}

ErrorOr<NonnullRefPtr<typename parser::ParsedType>> parser::Parser::parse_type_longhand() {
{
return (JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<NonnullRefPtr<typename parser::ParsedType>, ErrorOr<NonnullRefPtr<typename parser::ParsedType>>>{
auto&& __jakt_match_variant = ((*this).current());
switch(__jakt_match_variant.index()) {
case 91: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::Raw>();
return JaktInternal::ExplicitValue(({ Optional<NonnullRefPtr<typename parser::ParsedType>> __jakt_var_25; {
utility::Span const start = ((((*this).current())).span());
((((*this).index)++));
NonnullRefPtr<typename parser::ParsedType> const inner = TRY((((*this).parse_typename())));
utility::Span const span = TRY((parser::merge_spans(start,((((*this).current())).span()))));
__jakt_var_25 = JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<NonnullRefPtr<typename parser::ParsedType>, ErrorOr<NonnullRefPtr<typename parser::ParsedType>>>{
auto&& __jakt_match_variant = *inner;
switch(__jakt_match_variant.index()) {
case 7: {
auto&& __jakt_match_value = __jakt_match_variant.template get<parser::ParsedType::Optional>();NonnullRefPtr<typename parser::ParsedType> const& inner = __jakt_match_value.inner;
return JaktInternal::ExplicitValue(TRY((parser::ParsedType::template create<typename parser::ParsedType::Optional>(TRY((parser::ParsedType::template create<typename parser::ParsedType::RawPtr>(inner,span))),span))));
};/*case end*/
default: {
return JaktInternal::ExplicitValue(TRY((parser::ParsedType::template create<typename parser::ParsedType::RawPtr>(inner,span))));
};/*case end*/
}/*switch end*/
}()
)); goto __jakt_label_23;

}
__jakt_label_23:; __jakt_var_25.release_value(); }));
};/*case end*/
case 102: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::Weak>();
return JaktInternal::ExplicitValue(({ Optional<NonnullRefPtr<typename parser::ParsedType>> __jakt_var_26; {
utility::Span const start = ((((*this).current())).span());
((((*this).index)++));
NonnullRefPtr<typename parser::ParsedType> const inner = TRY((((*this).parse_typename())));
utility::Span const span = TRY((parser::merge_spans(start,((((*this).current())).span()))));
__jakt_var_26 = JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<NonnullRefPtr<typename parser::ParsedType>, ErrorOr<NonnullRefPtr<typename parser::ParsedType>>>{
auto&& __jakt_match_variant = *inner;
switch(__jakt_match_variant.index()) {
case 7: {
auto&& __jakt_match_value = __jakt_match_variant.template get<parser::ParsedType::Optional>();NonnullRefPtr<typename parser::ParsedType> const& inner = __jakt_match_value.inner;
return JaktInternal::ExplicitValue(TRY((parser::ParsedType::template create<typename parser::ParsedType::WeakPtr>(inner,span))));
};/*case end*/
default: {
return JaktInternal::ExplicitValue(({ Optional<NonnullRefPtr<typename parser::ParsedType>> __jakt_var_27; {
TRY((((*this).error(Jakt::DeprecatedString("missing `?` after weak pointer type name"sv),span))));
__jakt_var_27 = TRY((parser::ParsedType::template create<typename parser::ParsedType::WeakPtr>(inner,span))); goto __jakt_label_25;

}
__jakt_label_25:; __jakt_var_27.release_value(); }));
};/*case end*/
}/*switch end*/
}()
)); goto __jakt_label_24;

}
__jakt_label_24:; __jakt_var_26.release_value(); }));
};/*case end*/
case 4: {
auto&& __jakt_match_value = __jakt_match_variant.template get<lexer::Token::Identifier>();DeprecatedString const& name = __jakt_match_value.name;
return JaktInternal::ExplicitValue(({ Optional<NonnullRefPtr<typename parser::ParsedType>> __jakt_var_28; {
utility::Span const span = ((((*this).current())).span());
((((*this).index)++));
NonnullRefPtr<typename parser::ParsedType> parsed_type = TRY((parser::ParsedType::template create<typename parser::ParsedType::Name>(name,span)));
if (((((*this).current())).index() == 29 /* LessThan */)){
JaktInternal::DynamicArray<NonnullRefPtr<typename parser::ParsedType>> params = TRY((((*this).parse_type_parameter_list())));
(parsed_type = TRY((parser::ParsedType::template create<typename parser::ParsedType::GenericType>(name,params,span))));
}
if (((((*this).current())).index() == 7 /* ColonColon */)){
((((*this).index)++));
JaktInternal::DynamicArray<DeprecatedString> namespaces = (TRY((DynamicArray<DeprecatedString>::create_with({name}))));
while ((!(((*this).eof())))){
JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_AT_LOOP(([&]() -> JaktInternal::ExplicitValueOrControlFlow<void, ErrorOr<NonnullRefPtr<typename parser::ParsedType>>>{
auto&& __jakt_match_variant = ((*this).current());
switch(__jakt_match_variant.index()) {
case 4: {
auto&& __jakt_match_value = __jakt_match_variant.template get<lexer::Token::Identifier>();DeprecatedString const& namespace_name = __jakt_match_value.name;
{
if (((((*this).previous())).index() == 7 /* ColonColon */)){
TRY((((namespaces).push(namespace_name))));
((((*this).index)++));
}
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 7: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::ColonColon>();
{
if (((((*this).previous())).index() == 4 /* Identifier */)){
((((*this).index)++));
}
else {
TRY((((*this).error(Jakt::DeprecatedString("Expected name after"sv),span))));
}

}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
default: {
{
return JaktInternal::LoopBreak{};
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
}/*switch end*/
}()
));
}
DeprecatedString const type_name = (((namespaces).pop()).value());
JaktInternal::DynamicArray<NonnullRefPtr<typename parser::ParsedType>> params = TRY((((*this).parse_type_parameter_list())));
(parsed_type = TRY((parser::ParsedType::template create<typename parser::ParsedType::NamespacedName>(type_name,namespaces,params,((((*this).previous())).span())))));
}
__jakt_var_28 = parsed_type; goto __jakt_label_26;

}
__jakt_label_26:; __jakt_var_28.release_value(); }));
};/*case end*/
case 75: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::Function>();
return JaktInternal::ExplicitValue(({ Optional<NonnullRefPtr<typename parser::ParsedType>> __jakt_var_29; {
utility::Span const start = ((((*this).current())).span());
((((*this).index)++));
JaktInternal::DynamicArray<parser::ParsedParameter> const params = TRY((((*this).parse_function_parameters())));
bool const can_throw = ((((*this).current())).index() == 97 /* Throws */);
if (can_throw){
((((*this).index)++));
}
NonnullRefPtr<typename parser::ParsedType> return_type = TRY((parser::ParsedType::template create<typename parser::ParsedType::Empty>()));
if (((((*this).current())).index() == 59 /* Arrow */)){
((((*this).index)++));
(return_type = TRY((((*this).parse_typename()))));
}
else {
TRY((((*this).error(Jakt::DeprecatedString("Expected '->'"sv),((((*this).current())).span())))));
}

__jakt_var_29 = TRY((parser::ParsedType::template create<typename parser::ParsedType::Function>(params,can_throw,return_type,TRY((parser::merge_spans(start,((return_type)->span()))))))); goto __jakt_label_27;

}
__jakt_label_27:; __jakt_var_29.release_value(); }));
};/*case end*/
default: {
return JaktInternal::ExplicitValue(({ Optional<NonnullRefPtr<typename parser::ParsedType>> __jakt_var_30; {
TRY((((*this).error(Jakt::DeprecatedString("Expected type name"sv),((((*this).current())).span())))));
__jakt_var_30 = TRY((parser::ParsedType::template create<typename parser::ParsedType::Empty>())); goto __jakt_label_28;

}
__jakt_label_28:; __jakt_var_30.release_value(); }));
};/*case end*/
}/*switch end*/
}()
)));
}
}

ErrorOr<void> parser::Parser::parse_attribute_list(JaktInternal::DynamicArray<parser::ParsedAttribute>& active_attributes) {
{
while ((((!(((*this).eof()))) && (!(((((*this).current())).index() == 13 /* RSquare */)))) && (!(((((*this).peek(static_cast<size_t>(1ULL)))).index() == 13 /* RSquare */))))){
JaktInternal::Optional<parser::ParsedAttribute> const attribute = TRY((((*this).parse_attribute())));
if (((attribute).has_value())){
TRY((((((active_attributes))).push((attribute.value())))));
}
}
if ((((((*this).current())).index() == 13 /* RSquare */) && ((((*this).peek(static_cast<size_t>(1ULL)))).index() == 13 /* RSquare */))){
({auto& _jakt_ref = ((*this).index);_jakt_ref = JaktInternal::checked_add<size_t>(_jakt_ref, static_cast<size_t>(2ULL));});
}
else {
TRY((((*this).error(Jakt::DeprecatedString("Expected ‘]]’"sv),((((*this).current())).span())))));
}

}
return {};
}

ErrorOr<void> parser::Parser::error(DeprecatedString const message,utility::Span const span) {
{
if ((!(((((*this).compiler))->ignore_parser_errors)))){
TRY((((((((*this).compiler))->errors)).push( error::JaktError { typename error::JaktError::Message(message,span) } ))));
}
}
return {};
}

ErrorOr<parser::ParsedRecord> parser::Parser::parse_struct(parser::DefinitionLinkage const definition_linkage) {
{
parser::ParsedRecord parsed_struct = parser::ParsedRecord(Jakt::DeprecatedString(""sv),((*this).empty_span()),(TRY((DynamicArray<parser::ParsedGenericParameter>::create_with({})))),definition_linkage,JaktInternal::OptionalNone(),(TRY((DynamicArray<parser::ParsedMethod>::create_with({})))), parser::RecordType { typename parser::RecordType::Garbage() } ,JaktInternal::OptionalNone());
if (((((*this).current())).index() == 94 /* Struct */)){
((((*this).index)++));
}
else {
TRY((((*this).error(Jakt::DeprecatedString("Expected `struct` keyword"sv),((((*this).current())).span())))));
return (parsed_struct);
}

if (((*this).eof())){
TRY((((*this).error(Jakt::DeprecatedString("Incomplete struct definition, expected name"sv),((((*this).current())).span())))));
return (parsed_struct);
}
if (((((*this).current())).index() == 4 /* Identifier */)){
DeprecatedString const name = ((((*this).current())).get<lexer::Token::Identifier>()).name;
utility::Span const span = ((((*this).current())).get<lexer::Token::Identifier>()).span;
((((*this).index)++));
(((parsed_struct).name) = name);
(((parsed_struct).name_span) = span);
}
else {
TRY((((*this).error(Jakt::DeprecatedString("Incomplete struct definition, expected name"sv),((((*this).current())).span())))));
}

if (((*this).eof())){
TRY((((*this).error(Jakt::DeprecatedString("Incomplete struct definition, expected generic parameters or body"sv),((((*this).current())).span())))));
return (parsed_struct);
}
(((parsed_struct).generic_parameters) = TRY((((*this).parse_generic_parameters()))));
if (((((*this).current())).index() == 106 /* Implements */)){
((((*this).index)++));
(((parsed_struct).implements_list) = TRY((((*this).parse_trait_list()))));
}
((*this).skip_newlines());
if (((*this).eof())){
TRY((((*this).error(Jakt::DeprecatedString("Incomplete struct definition, expected body"sv),((((*this).current())).span())))));
return (parsed_struct);
}
JaktInternal::Tuple<JaktInternal::DynamicArray<parser::ParsedField>,JaktInternal::DynamicArray<parser::ParsedMethod>> const fields_methods_ = TRY((((*this).parse_struct_class_body(definition_linkage, parser::Visibility { typename parser::Visibility::Public() } ,false))));
JaktInternal::DynamicArray<parser::ParsedField> const fields = ((fields_methods_).template get<0>());
JaktInternal::DynamicArray<parser::ParsedMethod> const methods = ((fields_methods_).template get<1>());

(((parsed_struct).methods) = methods);
JaktInternal::Optional<NonnullRefPtr<typename parser::ParsedType>> const super_type = JaktInternal::OptionalNone();
(((parsed_struct).record_type) =  parser::RecordType { typename parser::RecordType::Struct(fields,super_type) } );
return (parsed_struct);
}
}

bool parser::Parser::eol() const {
{
return ((((*this).eof()) || ((((((*this).tokens))[((*this).index)])).index() == 56 /* Eol */)));
}
}

ErrorOr<JaktInternal::Optional<JaktInternal::DynamicArray<parser::ParsedNameWithGenericParameters>>> parser::Parser::parse_trait_list() {
{
if (((((*this).current())).index() == 8 /* LParen */)){
((((*this).index)++));
JaktInternal::DynamicArray<parser::ParsedNameWithGenericParameters> result = (TRY((DynamicArray<parser::ParsedNameWithGenericParameters>::create_with({}))));
while ((!(((*this).eof())))){
JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_AT_LOOP(([&]() -> JaktInternal::ExplicitValueOrControlFlow<void, ErrorOr<JaktInternal::Optional<JaktInternal::DynamicArray<parser::ParsedNameWithGenericParameters>>>>{
auto&& __jakt_match_variant = ((*this).current());
switch(__jakt_match_variant.index()) {
case 56: {
auto&& __jakt_match_value = __jakt_match_variant.template get<lexer::Token::Eol>();{
((((*this).index)++));
return JaktInternal::LoopContinue{};
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 53: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::Comma>();
{
((((*this).index)++));
return JaktInternal::LoopContinue{};
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 57: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::Eof>();
utility::Span const& span = __jakt_match_value.value;
{
TRY((((*this).error(Jakt::DeprecatedString("Expected ')' to close the trait list"sv),span))));
return JaktInternal::LoopBreak{};
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 9: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::RParen>();
{
((((*this).index)++));
return JaktInternal::LoopBreak{};
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 4: {
auto&& __jakt_match_value = __jakt_match_variant.template get<lexer::Token::Identifier>();DeprecatedString const& name = __jakt_match_value.name;
utility::Span const& span = __jakt_match_value.span;
{
parser::ParsedNameWithGenericParameters parsed_name = parser::ParsedNameWithGenericParameters(name,span,(TRY((DynamicArray<NonnullRefPtr<typename parser::ParsedType>>::create_with({})))));
((((*this).index)++));
(((parsed_name).generic_parameters) = TRY((((*this).parse_type_parameter_list()))));
TRY((((result).push(parsed_name))));
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 0: {
auto&& __jakt_match_value = __jakt_match_variant.template get<lexer::Token::SingleQuotedString>();utility::Span const& span = __jakt_match_value.span;
{
TRY((((*this).error(Jakt::DeprecatedString("Expected trait name"sv),span))));
return JaktInternal::LoopBreak{};
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 1: {
auto&& __jakt_match_value = __jakt_match_variant.template get<lexer::Token::SingleQuotedByteString>();utility::Span const& span = __jakt_match_value.span;
{
TRY((((*this).error(Jakt::DeprecatedString("Expected trait name"sv),span))));
return JaktInternal::LoopBreak{};
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 2: {
auto&& __jakt_match_value = __jakt_match_variant.template get<lexer::Token::QuotedString>();utility::Span const& span = __jakt_match_value.span;
{
TRY((((*this).error(Jakt::DeprecatedString("Expected trait name"sv),span))));
return JaktInternal::LoopBreak{};
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 3: {
auto&& __jakt_match_value = __jakt_match_variant.template get<lexer::Token::Number>();utility::Span const& span = __jakt_match_value.span;
{
TRY((((*this).error(Jakt::DeprecatedString("Expected trait name"sv),span))));
return JaktInternal::LoopBreak{};
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 5: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::Semicolon>();
utility::Span const& span = __jakt_match_value.value;
{
TRY((((*this).error(Jakt::DeprecatedString("Expected trait name"sv),span))));
return JaktInternal::LoopBreak{};
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 6: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::Colon>();
utility::Span const& span = __jakt_match_value.value;
{
TRY((((*this).error(Jakt::DeprecatedString("Expected trait name"sv),span))));
return JaktInternal::LoopBreak{};
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 7: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::ColonColon>();
utility::Span const& span = __jakt_match_value.value;
{
TRY((((*this).error(Jakt::DeprecatedString("Expected trait name"sv),span))));
return JaktInternal::LoopBreak{};
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 8: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::LParen>();
utility::Span const& span = __jakt_match_value.value;
{
TRY((((*this).error(Jakt::DeprecatedString("Expected trait name"sv),span))));
return JaktInternal::LoopBreak{};
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 10: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::LCurly>();
utility::Span const& span = __jakt_match_value.value;
{
TRY((((*this).error(Jakt::DeprecatedString("Expected trait name"sv),span))));
return JaktInternal::LoopBreak{};
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 11: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::RCurly>();
utility::Span const& span = __jakt_match_value.value;
{
TRY((((*this).error(Jakt::DeprecatedString("Expected trait name"sv),span))));
return JaktInternal::LoopBreak{};
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 12: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::LSquare>();
utility::Span const& span = __jakt_match_value.value;
{
TRY((((*this).error(Jakt::DeprecatedString("Expected trait name"sv),span))));
return JaktInternal::LoopBreak{};
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 13: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::RSquare>();
utility::Span const& span = __jakt_match_value.value;
{
TRY((((*this).error(Jakt::DeprecatedString("Expected trait name"sv),span))));
return JaktInternal::LoopBreak{};
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 14: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::PercentSign>();
utility::Span const& span = __jakt_match_value.value;
{
TRY((((*this).error(Jakt::DeprecatedString("Expected trait name"sv),span))));
return JaktInternal::LoopBreak{};
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 15: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::Plus>();
utility::Span const& span = __jakt_match_value.value;
{
TRY((((*this).error(Jakt::DeprecatedString("Expected trait name"sv),span))));
return JaktInternal::LoopBreak{};
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 16: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::Minus>();
utility::Span const& span = __jakt_match_value.value;
{
TRY((((*this).error(Jakt::DeprecatedString("Expected trait name"sv),span))));
return JaktInternal::LoopBreak{};
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 17: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::Equal>();
utility::Span const& span = __jakt_match_value.value;
{
TRY((((*this).error(Jakt::DeprecatedString("Expected trait name"sv),span))));
return JaktInternal::LoopBreak{};
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 18: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::PlusEqual>();
utility::Span const& span = __jakt_match_value.value;
{
TRY((((*this).error(Jakt::DeprecatedString("Expected trait name"sv),span))));
return JaktInternal::LoopBreak{};
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 19: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::PlusPlus>();
utility::Span const& span = __jakt_match_value.value;
{
TRY((((*this).error(Jakt::DeprecatedString("Expected trait name"sv),span))));
return JaktInternal::LoopBreak{};
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 20: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::MinusEqual>();
utility::Span const& span = __jakt_match_value.value;
{
TRY((((*this).error(Jakt::DeprecatedString("Expected trait name"sv),span))));
return JaktInternal::LoopBreak{};
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 21: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::MinusMinus>();
utility::Span const& span = __jakt_match_value.value;
{
TRY((((*this).error(Jakt::DeprecatedString("Expected trait name"sv),span))));
return JaktInternal::LoopBreak{};
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 22: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::AsteriskEqual>();
utility::Span const& span = __jakt_match_value.value;
{
TRY((((*this).error(Jakt::DeprecatedString("Expected trait name"sv),span))));
return JaktInternal::LoopBreak{};
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 23: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::ForwardSlashEqual>();
utility::Span const& span = __jakt_match_value.value;
{
TRY((((*this).error(Jakt::DeprecatedString("Expected trait name"sv),span))));
return JaktInternal::LoopBreak{};
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 24: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::PercentSignEqual>();
utility::Span const& span = __jakt_match_value.value;
{
TRY((((*this).error(Jakt::DeprecatedString("Expected trait name"sv),span))));
return JaktInternal::LoopBreak{};
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 25: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::NotEqual>();
utility::Span const& span = __jakt_match_value.value;
{
TRY((((*this).error(Jakt::DeprecatedString("Expected trait name"sv),span))));
return JaktInternal::LoopBreak{};
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 26: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::DoubleEqual>();
utility::Span const& span = __jakt_match_value.value;
{
TRY((((*this).error(Jakt::DeprecatedString("Expected trait name"sv),span))));
return JaktInternal::LoopBreak{};
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 27: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::GreaterThan>();
utility::Span const& span = __jakt_match_value.value;
{
TRY((((*this).error(Jakt::DeprecatedString("Expected trait name"sv),span))));
return JaktInternal::LoopBreak{};
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 28: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::GreaterThanOrEqual>();
utility::Span const& span = __jakt_match_value.value;
{
TRY((((*this).error(Jakt::DeprecatedString("Expected trait name"sv),span))));
return JaktInternal::LoopBreak{};
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 29: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::LessThan>();
utility::Span const& span = __jakt_match_value.value;
{
TRY((((*this).error(Jakt::DeprecatedString("Expected trait name"sv),span))));
return JaktInternal::LoopBreak{};
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 30: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::LessThanOrEqual>();
utility::Span const& span = __jakt_match_value.value;
{
TRY((((*this).error(Jakt::DeprecatedString("Expected trait name"sv),span))));
return JaktInternal::LoopBreak{};
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 31: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::LeftArithmeticShift>();
utility::Span const& span = __jakt_match_value.value;
{
TRY((((*this).error(Jakt::DeprecatedString("Expected trait name"sv),span))));
return JaktInternal::LoopBreak{};
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 32: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::LeftShift>();
utility::Span const& span = __jakt_match_value.value;
{
TRY((((*this).error(Jakt::DeprecatedString("Expected trait name"sv),span))));
return JaktInternal::LoopBreak{};
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 33: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::LeftShiftEqual>();
utility::Span const& span = __jakt_match_value.value;
{
TRY((((*this).error(Jakt::DeprecatedString("Expected trait name"sv),span))));
return JaktInternal::LoopBreak{};
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 34: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::RightShift>();
utility::Span const& span = __jakt_match_value.value;
{
TRY((((*this).error(Jakt::DeprecatedString("Expected trait name"sv),span))));
return JaktInternal::LoopBreak{};
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 35: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::RightArithmeticShift>();
utility::Span const& span = __jakt_match_value.value;
{
TRY((((*this).error(Jakt::DeprecatedString("Expected trait name"sv),span))));
return JaktInternal::LoopBreak{};
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 36: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::RightShiftEqual>();
utility::Span const& span = __jakt_match_value.value;
{
TRY((((*this).error(Jakt::DeprecatedString("Expected trait name"sv),span))));
return JaktInternal::LoopBreak{};
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 37: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::Asterisk>();
utility::Span const& span = __jakt_match_value.value;
{
TRY((((*this).error(Jakt::DeprecatedString("Expected trait name"sv),span))));
return JaktInternal::LoopBreak{};
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 38: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::Ampersand>();
utility::Span const& span = __jakt_match_value.value;
{
TRY((((*this).error(Jakt::DeprecatedString("Expected trait name"sv),span))));
return JaktInternal::LoopBreak{};
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 39: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::AmpersandEqual>();
utility::Span const& span = __jakt_match_value.value;
{
TRY((((*this).error(Jakt::DeprecatedString("Expected trait name"sv),span))));
return JaktInternal::LoopBreak{};
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 40: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::AmpersandAmpersand>();
utility::Span const& span = __jakt_match_value.value;
{
TRY((((*this).error(Jakt::DeprecatedString("Expected trait name"sv),span))));
return JaktInternal::LoopBreak{};
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 41: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::Pipe>();
utility::Span const& span = __jakt_match_value.value;
{
TRY((((*this).error(Jakt::DeprecatedString("Expected trait name"sv),span))));
return JaktInternal::LoopBreak{};
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 42: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::PipeEqual>();
utility::Span const& span = __jakt_match_value.value;
{
TRY((((*this).error(Jakt::DeprecatedString("Expected trait name"sv),span))));
return JaktInternal::LoopBreak{};
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 43: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::PipePipe>();
utility::Span const& span = __jakt_match_value.value;
{
TRY((((*this).error(Jakt::DeprecatedString("Expected trait name"sv),span))));
return JaktInternal::LoopBreak{};
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 44: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::Caret>();
utility::Span const& span = __jakt_match_value.value;
{
TRY((((*this).error(Jakt::DeprecatedString("Expected trait name"sv),span))));
return JaktInternal::LoopBreak{};
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 45: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::CaretEqual>();
utility::Span const& span = __jakt_match_value.value;
{
TRY((((*this).error(Jakt::DeprecatedString("Expected trait name"sv),span))));
return JaktInternal::LoopBreak{};
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 46: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::Dollar>();
utility::Span const& span = __jakt_match_value.value;
{
TRY((((*this).error(Jakt::DeprecatedString("Expected trait name"sv),span))));
return JaktInternal::LoopBreak{};
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 47: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::Tilde>();
utility::Span const& span = __jakt_match_value.value;
{
TRY((((*this).error(Jakt::DeprecatedString("Expected trait name"sv),span))));
return JaktInternal::LoopBreak{};
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 48: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::ForwardSlash>();
utility::Span const& span = __jakt_match_value.value;
{
TRY((((*this).error(Jakt::DeprecatedString("Expected trait name"sv),span))));
return JaktInternal::LoopBreak{};
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 49: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::ExclamationPoint>();
utility::Span const& span = __jakt_match_value.value;
{
TRY((((*this).error(Jakt::DeprecatedString("Expected trait name"sv),span))));
return JaktInternal::LoopBreak{};
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 50: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::QuestionMark>();
utility::Span const& span = __jakt_match_value.value;
{
TRY((((*this).error(Jakt::DeprecatedString("Expected trait name"sv),span))));
return JaktInternal::LoopBreak{};
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 51: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::QuestionMarkQuestionMark>();
utility::Span const& span = __jakt_match_value.value;
{
TRY((((*this).error(Jakt::DeprecatedString("Expected trait name"sv),span))));
return JaktInternal::LoopBreak{};
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 52: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::QuestionMarkQuestionMarkEqual>();
utility::Span const& span = __jakt_match_value.value;
{
TRY((((*this).error(Jakt::DeprecatedString("Expected trait name"sv),span))));
return JaktInternal::LoopBreak{};
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 54: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::Dot>();
utility::Span const& span = __jakt_match_value.value;
{
TRY((((*this).error(Jakt::DeprecatedString("Expected trait name"sv),span))));
return JaktInternal::LoopBreak{};
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 55: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::DotDot>();
utility::Span const& span = __jakt_match_value.value;
{
TRY((((*this).error(Jakt::DeprecatedString("Expected trait name"sv),span))));
return JaktInternal::LoopBreak{};
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 58: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::FatArrow>();
utility::Span const& span = __jakt_match_value.value;
{
TRY((((*this).error(Jakt::DeprecatedString("Expected trait name"sv),span))));
return JaktInternal::LoopBreak{};
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 59: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::Arrow>();
utility::Span const& span = __jakt_match_value.value;
{
TRY((((*this).error(Jakt::DeprecatedString("Expected trait name"sv),span))));
return JaktInternal::LoopBreak{};
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 60: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::And>();
utility::Span const& span = __jakt_match_value.value;
{
TRY((((*this).error(Jakt::DeprecatedString("Expected trait name"sv),span))));
return JaktInternal::LoopBreak{};
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 61: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::Anon>();
utility::Span const& span = __jakt_match_value.value;
{
TRY((((*this).error(Jakt::DeprecatedString("Expected trait name"sv),span))));
return JaktInternal::LoopBreak{};
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 62: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::As>();
utility::Span const& span = __jakt_match_value.value;
{
TRY((((*this).error(Jakt::DeprecatedString("Expected trait name"sv),span))));
return JaktInternal::LoopBreak{};
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 63: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::Boxed>();
utility::Span const& span = __jakt_match_value.value;
{
TRY((((*this).error(Jakt::DeprecatedString("Expected trait name"sv),span))));
return JaktInternal::LoopBreak{};
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 64: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::Break>();
utility::Span const& span = __jakt_match_value.value;
{
TRY((((*this).error(Jakt::DeprecatedString("Expected trait name"sv),span))));
return JaktInternal::LoopBreak{};
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 65: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::Catch>();
utility::Span const& span = __jakt_match_value.value;
{
TRY((((*this).error(Jakt::DeprecatedString("Expected trait name"sv),span))));
return JaktInternal::LoopBreak{};
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 66: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::Class>();
utility::Span const& span = __jakt_match_value.value;
{
TRY((((*this).error(Jakt::DeprecatedString("Expected trait name"sv),span))));
return JaktInternal::LoopBreak{};
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 67: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::Continue>();
utility::Span const& span = __jakt_match_value.value;
{
TRY((((*this).error(Jakt::DeprecatedString("Expected trait name"sv),span))));
return JaktInternal::LoopBreak{};
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 68: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::Cpp>();
utility::Span const& span = __jakt_match_value.value;
{
TRY((((*this).error(Jakt::DeprecatedString("Expected trait name"sv),span))));
return JaktInternal::LoopBreak{};
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 69: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::Defer>();
utility::Span const& span = __jakt_match_value.value;
{
TRY((((*this).error(Jakt::DeprecatedString("Expected trait name"sv),span))));
return JaktInternal::LoopBreak{};
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 70: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::Else>();
utility::Span const& span = __jakt_match_value.value;
{
TRY((((*this).error(Jakt::DeprecatedString("Expected trait name"sv),span))));
return JaktInternal::LoopBreak{};
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 71: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::Enum>();
utility::Span const& span = __jakt_match_value.value;
{
TRY((((*this).error(Jakt::DeprecatedString("Expected trait name"sv),span))));
return JaktInternal::LoopBreak{};
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 72: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::Extern>();
utility::Span const& span = __jakt_match_value.value;
{
TRY((((*this).error(Jakt::DeprecatedString("Expected trait name"sv),span))));
return JaktInternal::LoopBreak{};
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 73: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::False>();
utility::Span const& span = __jakt_match_value.value;
{
TRY((((*this).error(Jakt::DeprecatedString("Expected trait name"sv),span))));
return JaktInternal::LoopBreak{};
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 74: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::For>();
utility::Span const& span = __jakt_match_value.value;
{
TRY((((*this).error(Jakt::DeprecatedString("Expected trait name"sv),span))));
return JaktInternal::LoopBreak{};
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 75: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::Function>();
utility::Span const& span = __jakt_match_value.value;
{
TRY((((*this).error(Jakt::DeprecatedString("Expected trait name"sv),span))));
return JaktInternal::LoopBreak{};
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 76: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::Comptime>();
utility::Span const& span = __jakt_match_value.value;
{
TRY((((*this).error(Jakt::DeprecatedString("Expected trait name"sv),span))));
return JaktInternal::LoopBreak{};
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 77: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::If>();
utility::Span const& span = __jakt_match_value.value;
{
TRY((((*this).error(Jakt::DeprecatedString("Expected trait name"sv),span))));
return JaktInternal::LoopBreak{};
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 78: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::Import>();
utility::Span const& span = __jakt_match_value.value;
{
TRY((((*this).error(Jakt::DeprecatedString("Expected trait name"sv),span))));
return JaktInternal::LoopBreak{};
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 79: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::In>();
utility::Span const& span = __jakt_match_value.value;
{
TRY((((*this).error(Jakt::DeprecatedString("Expected trait name"sv),span))));
return JaktInternal::LoopBreak{};
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 80: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::Is>();
utility::Span const& span = __jakt_match_value.value;
{
TRY((((*this).error(Jakt::DeprecatedString("Expected trait name"sv),span))));
return JaktInternal::LoopBreak{};
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 81: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::Let>();
utility::Span const& span = __jakt_match_value.value;
{
TRY((((*this).error(Jakt::DeprecatedString("Expected trait name"sv),span))));
return JaktInternal::LoopBreak{};
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 82: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::Loop>();
utility::Span const& span = __jakt_match_value.value;
{
TRY((((*this).error(Jakt::DeprecatedString("Expected trait name"sv),span))));
return JaktInternal::LoopBreak{};
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 83: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::Match>();
utility::Span const& span = __jakt_match_value.value;
{
TRY((((*this).error(Jakt::DeprecatedString("Expected trait name"sv),span))));
return JaktInternal::LoopBreak{};
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 84: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::Mut>();
utility::Span const& span = __jakt_match_value.value;
{
TRY((((*this).error(Jakt::DeprecatedString("Expected trait name"sv),span))));
return JaktInternal::LoopBreak{};
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 85: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::Namespace>();
utility::Span const& span = __jakt_match_value.value;
{
TRY((((*this).error(Jakt::DeprecatedString("Expected trait name"sv),span))));
return JaktInternal::LoopBreak{};
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 86: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::Not>();
utility::Span const& span = __jakt_match_value.value;
{
TRY((((*this).error(Jakt::DeprecatedString("Expected trait name"sv),span))));
return JaktInternal::LoopBreak{};
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 87: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::Or>();
utility::Span const& span = __jakt_match_value.value;
{
TRY((((*this).error(Jakt::DeprecatedString("Expected trait name"sv),span))));
return JaktInternal::LoopBreak{};
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 88: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::Override>();
utility::Span const& span = __jakt_match_value.value;
{
TRY((((*this).error(Jakt::DeprecatedString("Expected trait name"sv),span))));
return JaktInternal::LoopBreak{};
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 89: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::Private>();
utility::Span const& span = __jakt_match_value.value;
{
TRY((((*this).error(Jakt::DeprecatedString("Expected trait name"sv),span))));
return JaktInternal::LoopBreak{};
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 90: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::Public>();
utility::Span const& span = __jakt_match_value.value;
{
TRY((((*this).error(Jakt::DeprecatedString("Expected trait name"sv),span))));
return JaktInternal::LoopBreak{};
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 91: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::Raw>();
utility::Span const& span = __jakt_match_value.value;
{
TRY((((*this).error(Jakt::DeprecatedString("Expected trait name"sv),span))));
return JaktInternal::LoopBreak{};
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 92: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::Return>();
utility::Span const& span = __jakt_match_value.value;
{
TRY((((*this).error(Jakt::DeprecatedString("Expected trait name"sv),span))));
return JaktInternal::LoopBreak{};
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 93: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::Restricted>();
utility::Span const& span = __jakt_match_value.value;
{
TRY((((*this).error(Jakt::DeprecatedString("Expected trait name"sv),span))));
return JaktInternal::LoopBreak{};
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 94: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::Struct>();
utility::Span const& span = __jakt_match_value.value;
{
TRY((((*this).error(Jakt::DeprecatedString("Expected trait name"sv),span))));
return JaktInternal::LoopBreak{};
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 95: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::This>();
utility::Span const& span = __jakt_match_value.value;
{
TRY((((*this).error(Jakt::DeprecatedString("Expected trait name"sv),span))));
return JaktInternal::LoopBreak{};
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 96: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::Throw>();
utility::Span const& span = __jakt_match_value.value;
{
TRY((((*this).error(Jakt::DeprecatedString("Expected trait name"sv),span))));
return JaktInternal::LoopBreak{};
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 97: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::Throws>();
utility::Span const& span = __jakt_match_value.value;
{
TRY((((*this).error(Jakt::DeprecatedString("Expected trait name"sv),span))));
return JaktInternal::LoopBreak{};
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 98: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::True>();
utility::Span const& span = __jakt_match_value.value;
{
TRY((((*this).error(Jakt::DeprecatedString("Expected trait name"sv),span))));
return JaktInternal::LoopBreak{};
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 99: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::Try>();
utility::Span const& span = __jakt_match_value.value;
{
TRY((((*this).error(Jakt::DeprecatedString("Expected trait name"sv),span))));
return JaktInternal::LoopBreak{};
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 100: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::Unsafe>();
utility::Span const& span = __jakt_match_value.value;
{
TRY((((*this).error(Jakt::DeprecatedString("Expected trait name"sv),span))));
return JaktInternal::LoopBreak{};
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 101: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::Virtual>();
utility::Span const& span = __jakt_match_value.value;
{
TRY((((*this).error(Jakt::DeprecatedString("Expected trait name"sv),span))));
return JaktInternal::LoopBreak{};
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 102: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::Weak>();
utility::Span const& span = __jakt_match_value.value;
{
TRY((((*this).error(Jakt::DeprecatedString("Expected trait name"sv),span))));
return JaktInternal::LoopBreak{};
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 103: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::While>();
utility::Span const& span = __jakt_match_value.value;
{
TRY((((*this).error(Jakt::DeprecatedString("Expected trait name"sv),span))));
return JaktInternal::LoopBreak{};
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 104: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::Yield>();
utility::Span const& span = __jakt_match_value.value;
{
TRY((((*this).error(Jakt::DeprecatedString("Expected trait name"sv),span))));
return JaktInternal::LoopBreak{};
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 105: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::Guard>();
utility::Span const& span = __jakt_match_value.value;
{
TRY((((*this).error(Jakt::DeprecatedString("Expected trait name"sv),span))));
return JaktInternal::LoopBreak{};
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 106: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::Implements>();
utility::Span const& span = __jakt_match_value.value;
{
TRY((((*this).error(Jakt::DeprecatedString("Expected trait name"sv),span))));
return JaktInternal::LoopBreak{};
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 107: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::Requires>();
utility::Span const& span = __jakt_match_value.value;
{
TRY((((*this).error(Jakt::DeprecatedString("Expected trait name"sv),span))));
return JaktInternal::LoopBreak{};
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 108: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::Trait>();
utility::Span const& span = __jakt_match_value.value;
{
TRY((((*this).error(Jakt::DeprecatedString("Expected trait name"sv),span))));
return JaktInternal::LoopBreak{};
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 109: {
auto&& __jakt_match_value = __jakt_match_variant.template get<lexer::Token::Garbage>();utility::Span const& span = __jakt_match_value.span;
{
TRY((((*this).error(Jakt::DeprecatedString("Expected trait name"sv),span))));
return JaktInternal::LoopBreak{};
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
default: VERIFY_NOT_REACHED();}/*switch end*/
}()
));
}
if (((result).is_empty())){
TRY((((*this).error(Jakt::DeprecatedString("Expected trait list to have at least one trait inside it"sv),((((*this).previous())).span())))));
return (JaktInternal::OptionalNone());
}
else {
return (static_cast<JaktInternal::Optional<JaktInternal::DynamicArray<parser::ParsedNameWithGenericParameters>>>(result));
}

}
else {
TRY((((*this).error(Jakt::DeprecatedString("Expected '(' to start the trait list"sv),((((*this).current())).span())))));
return (JaktInternal::OptionalNone());
}

}
}

ErrorOr<JaktInternal::Tuple<JaktInternal::DynamicArray<parser::ParsedField>,JaktInternal::DynamicArray<parser::ParsedMethod>>> parser::Parser::parse_struct_class_body(parser::DefinitionLinkage const definition_linkage,parser::Visibility const default_visibility,bool const is_class) {
{
if (((((*this).current())).index() == 10 /* LCurly */)){
((((*this).index)++));
}
else {
TRY((((*this).error(Jakt::DeprecatedString("Expected ‘{’"sv),((((*this).current())).span())))));
}

JaktInternal::DynamicArray<parser::ParsedField> fields = (TRY((DynamicArray<parser::ParsedField>::create_with({}))));
JaktInternal::DynamicArray<parser::ParsedMethod> methods = (TRY((DynamicArray<parser::ParsedMethod>::create_with({}))));
JaktInternal::Optional<parser::Visibility> last_visibility = JaktInternal::OptionalNone();
JaktInternal::Optional<utility::Span> last_visibility_span = JaktInternal::OptionalNone();
bool last_virtual = false;
bool last_override = false;
bool error = false;
JaktInternal::DynamicArray<parser::ParsedAttribute> active_attributes = (TRY((DynamicArray<parser::ParsedAttribute>::create_with({}))));
while ((!(((*this).eof())))){
lexer::Token const token = ((*this).current());
JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_AT_LOOP(([&]() -> JaktInternal::ExplicitValueOrControlFlow<void, ErrorOr<JaktInternal::Tuple<JaktInternal::DynamicArray<parser::ParsedField>,JaktInternal::DynamicArray<parser::ParsedMethod>>>>{
auto&& __jakt_match_variant = token;
switch(__jakt_match_variant.index()) {
case 11: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::RCurly>();
{
if (((last_visibility).has_value())){
TRY((((*this).error(Jakt::DeprecatedString("Expected function or parameter after visibility modifier"sv),((token).span())))));
}
if ((!(((active_attributes).is_empty())))){
TRY((((*this).error(Jakt::DeprecatedString("Expected function after attribute"sv),((token).span())))));
}
((((*this).index)++));
return ((Tuple{fields, methods}));
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 53: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::Comma>();
{
((((*this).index)++));
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 56: {
auto&& __jakt_match_value = __jakt_match_variant.template get<lexer::Token::Eol>();{
((((*this).index)++));
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 90: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::Public>();
utility::Span const& span = __jakt_match_value.value;
{
if (((last_visibility).has_value())){
TRY((((*this).error_with_hint(Jakt::DeprecatedString("Multiple visibility modifiers on one field or method are not allowed"sv),span,Jakt::DeprecatedString("Previous modifier is here"sv),(last_visibility_span.value())))));
}
(last_visibility =  parser::Visibility { typename parser::Visibility::Public() } );
(last_visibility_span = span);
((((*this).index)++));
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 89: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::Private>();
utility::Span const& span = __jakt_match_value.value;
{
if (((last_visibility).has_value())){
TRY((((*this).error_with_hint(Jakt::DeprecatedString("Multiple visibility modifiers on one field or method are not allowed"sv),span,Jakt::DeprecatedString("Previous modifier is here"sv),(last_visibility_span.value())))));
}
(last_visibility =  parser::Visibility { typename parser::Visibility::Private() } );
(last_visibility_span = span);
((((*this).index)++));
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 93: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::Restricted>();
utility::Span const& span = __jakt_match_value.value;
{
if (((last_visibility).has_value())){
TRY((((*this).error_with_hint(Jakt::DeprecatedString("Multiple visibility modifiers on one field or method are not allowed"sv),span,Jakt::DeprecatedString("Previous modifier is here"sv),(last_visibility_span.value())))));
}
(last_visibility = TRY((((*this).parse_restricted_visibility_modifier()))));
(last_visibility_span = span);
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 12: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::LSquare>();
{
if (((((*this).peek(static_cast<size_t>(1ULL)))).index() == 12 /* LSquare */)){
({auto& _jakt_ref = ((*this).index);_jakt_ref = JaktInternal::checked_add<size_t>(_jakt_ref, static_cast<size_t>(2ULL));});
TRY((((*this).parse_attribute_list(((active_attributes))))));
}
else {
TRY((((*this).error(Jakt::DeprecatedString("Unexpected token (expected ‘[[’)"sv),((((*this).current())).span())))));
({auto& _jakt_ref = ((*this).index);_jakt_ref = JaktInternal::checked_add<size_t>(_jakt_ref, static_cast<size_t>(1ULL));});
}

}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 4: {
auto&& __jakt_match_value = __jakt_match_variant.template get<lexer::Token::Identifier>();{
if ((!(((active_attributes).is_empty())))){
TRY((((*this).error(Jakt::DeprecatedString("Attributes cannot be applied to fields"sv),((((*this).current())).span())))));
(active_attributes = (TRY((DynamicArray<parser::ParsedAttribute>::create_with({})))));
}
parser::Visibility const visibility = last_visibility.value_or_lazy_evaluated([&] { return default_visibility; });
(last_visibility = JaktInternal::OptionalNone());
(last_visibility_span = JaktInternal::OptionalNone());
if ((last_virtual || last_override)){
TRY((((*this).error(Jakt::DeprecatedString("Fields cannot be ‘virtual’ or ‘override’"sv),((((*this).current())).span())))));
}
(last_virtual = false);
(last_override = false);
parser::ParsedField const field = TRY((((*this).parse_field(visibility))));
TRY((((fields).push(field))));
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 75: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::Function>();
{
bool const is_comptime = ((((*this).current())).index() == 76 /* Comptime */);
parser::FunctionLinkage const function_linkage = JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_AT_LOOP_NESTED_MATCH(([&]() -> JaktInternal::ExplicitValueOrControlFlow<parser::FunctionLinkage, ErrorOr<JaktInternal::Tuple<JaktInternal::DynamicArray<parser::ParsedField>,JaktInternal::DynamicArray<parser::ParsedMethod>>>>{
auto&& __jakt_match_variant = definition_linkage;
switch(__jakt_match_variant.index()) {
case 0: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename parser::DefinitionLinkage::Internal>();
return JaktInternal::ExplicitValue( parser::FunctionLinkage { typename parser::FunctionLinkage::Internal() } );
};/*case end*/
case 1: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename parser::DefinitionLinkage::External>();
return JaktInternal::ExplicitValue( parser::FunctionLinkage { typename parser::FunctionLinkage::External() } );
};/*case end*/
default: VERIFY_NOT_REACHED();}/*switch end*/
}()
));
if ((((function_linkage).index() == 1 /* External */) && is_comptime)){
TRY((((*this).error(Jakt::DeprecatedString("External functions cannot be comptime"sv),((((*this).current())).span())))));
}
parser::Visibility const visibility = last_visibility.value_or_lazy_evaluated([&] { return default_visibility; });
(last_visibility = JaktInternal::OptionalNone());
(last_visibility_span = JaktInternal::OptionalNone());
bool const is_virtual = last_virtual;
bool const is_override = last_override;
(last_virtual = false);
(last_override = false);
parser::ParsedMethod parsed_method = TRY((((*this).parse_method(function_linkage,visibility,is_virtual,is_override,((((*this).current())).index() == 76 /* Comptime */)))));
TRY((((*this).apply_attributes(((parsed_method)),((active_attributes))))));
(active_attributes = (TRY((DynamicArray<parser::ParsedAttribute>::create_with({})))));
TRY((((methods).push(parsed_method))));
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 76: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::Comptime>();
{
bool const is_comptime = ((((*this).current())).index() == 76 /* Comptime */);
parser::FunctionLinkage const function_linkage = JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_AT_LOOP_NESTED_MATCH(([&]() -> JaktInternal::ExplicitValueOrControlFlow<parser::FunctionLinkage, ErrorOr<JaktInternal::Tuple<JaktInternal::DynamicArray<parser::ParsedField>,JaktInternal::DynamicArray<parser::ParsedMethod>>>>{
auto&& __jakt_match_variant = definition_linkage;
switch(__jakt_match_variant.index()) {
case 0: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename parser::DefinitionLinkage::Internal>();
return JaktInternal::ExplicitValue( parser::FunctionLinkage { typename parser::FunctionLinkage::Internal() } );
};/*case end*/
case 1: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename parser::DefinitionLinkage::External>();
return JaktInternal::ExplicitValue( parser::FunctionLinkage { typename parser::FunctionLinkage::External() } );
};/*case end*/
default: VERIFY_NOT_REACHED();}/*switch end*/
}()
));
if ((((function_linkage).index() == 1 /* External */) && is_comptime)){
TRY((((*this).error(Jakt::DeprecatedString("External functions cannot be comptime"sv),((((*this).current())).span())))));
}
parser::Visibility const visibility = last_visibility.value_or_lazy_evaluated([&] { return default_visibility; });
(last_visibility = JaktInternal::OptionalNone());
(last_visibility_span = JaktInternal::OptionalNone());
bool const is_virtual = last_virtual;
bool const is_override = last_override;
(last_virtual = false);
(last_override = false);
parser::ParsedMethod parsed_method = TRY((((*this).parse_method(function_linkage,visibility,is_virtual,is_override,((((*this).current())).index() == 76 /* Comptime */)))));
TRY((((*this).apply_attributes(((parsed_method)),((active_attributes))))));
(active_attributes = (TRY((DynamicArray<parser::ParsedAttribute>::create_with({})))));
TRY((((methods).push(parsed_method))));
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 101: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::Virtual>();
{
(last_virtual = true);
((((*this).index)++));
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 88: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::Override>();
{
(last_override = true);
((((*this).index)++));
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
default: {
{
(active_attributes = (TRY((DynamicArray<parser::ParsedAttribute>::create_with({})))));
if ((!(error))){
TRY((((*this).error(TRY((__jakt_format(Jakt::DeprecatedString("Invalid member, did not expect a {} here"sv),token))),((token).span())))));
(error = true);
}
((((*this).index)++));
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
}/*switch end*/
}()
));
}
if (is_class){
TRY((((*this).error(Jakt::DeprecatedString("Incomplete class body, expected ‘}’"sv),((((*this).current())).span())))));
}
else {
TRY((((*this).error(Jakt::DeprecatedString("Incomplete struct body, expected ‘}’"sv),((((*this).current())).span())))));
}

return ((Tuple{fields, methods}));
}
}

ErrorOr<JaktInternal::DynamicArray<parser::EnumVariantPatternArgument>> parser::Parser::parse_variant_arguments() {
{
JaktInternal::DynamicArray<parser::EnumVariantPatternArgument> variant_arguments = (TRY((DynamicArray<parser::EnumVariantPatternArgument>::create_with({}))));
bool has_parens = false;
if (((((*this).current())).index() == 8 /* LParen */)){
(has_parens = true);
((((*this).index)++));
bool is_reference = false;
bool is_mutable = false;
while ((!(((*this).eof())))){
((*this).skip_newlines());
JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_AT_LOOP(([&]() -> JaktInternal::ExplicitValueOrControlFlow<void, ErrorOr<JaktInternal::DynamicArray<parser::EnumVariantPatternArgument>>>{
auto&& __jakt_match_variant = ((*this).current());
switch(__jakt_match_variant.index()) {
case 38: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::Ampersand>();
{
(is_reference = true);
((((*this).index)++));
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 84: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::Mut>();
{
(is_mutable = true);
((((*this).index)++));
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 4: {
auto&& __jakt_match_value = __jakt_match_variant.template get<lexer::Token::Identifier>();DeprecatedString const& arg_name = __jakt_match_value.name;
{
if (((((*this).peek(static_cast<size_t>(1ULL)))).index() == 6 /* Colon */)){
({auto& _jakt_ref = ((*this).index);_jakt_ref = JaktInternal::checked_add<size_t>(_jakt_ref, static_cast<size_t>(2ULL));});
if (((((*this).current())).index() == 4 /* Identifier */)){
DeprecatedString const arg_binding = ((((*this).current())).get<lexer::Token::Identifier>()).name;
utility::Span const span = ((((*this).current())).span());
((((*this).index)++));
TRY((((variant_arguments).push(parser::EnumVariantPatternArgument(static_cast<JaktInternal::Optional<DeprecatedString>>(arg_name),arg_binding,span,is_reference,is_mutable)))));
}
else {
TRY((((*this).error(Jakt::DeprecatedString("Expected binding after ‘:’"sv),((((*this).current())).span())))));
}

}
else {
TRY((((variant_arguments).push(parser::EnumVariantPatternArgument(JaktInternal::OptionalNone(),arg_name,((((*this).current())).span()),is_reference,is_mutable)))));
((((*this).index)++));
}

(is_reference = false);
(is_mutable = false);
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 53: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::Comma>();
{
((((*this).index)++));
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 9: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::RParen>();
{
((((*this).index)++));
return JaktInternal::LoopBreak{};
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
default: {
{
TRY((((*this).error(Jakt::DeprecatedString("Expected pattern argument name"sv),((((*this).current())).span())))));
return JaktInternal::LoopBreak{};
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
}/*switch end*/
}()
));
}
}
return (variant_arguments);
}
}

ErrorOr<NonnullRefPtr<typename parser::ParsedExpression>> parser::Parser::parse_set_literal() {
{
utility::Span const start = ((((*this).current())).span());
if ((!(((((*this).current())).index() == 10 /* LCurly */)))){
TRY((((*this).error(Jakt::DeprecatedString("Expected ‘{’"sv),((((*this).current())).span())))));
return (TRY((parser::ParsedExpression::template create<typename parser::ParsedExpression::Garbage>(((((*this).current())).span())))));
}
((((*this).index)++));
JaktInternal::DynamicArray<NonnullRefPtr<typename parser::ParsedExpression>> output = (TRY((DynamicArray<NonnullRefPtr<typename parser::ParsedExpression>>::create_with({}))));
while ((!(((*this).eof())))){
JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_AT_LOOP(([&]() -> JaktInternal::ExplicitValueOrControlFlow<void, ErrorOr<NonnullRefPtr<typename parser::ParsedExpression>>>{
auto&& __jakt_match_variant = ((*this).current());
switch(__jakt_match_variant.index()) {
case 11: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::RCurly>();
{
((((*this).index)++));
return JaktInternal::LoopBreak{};
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 53: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::Comma>();
{
((((*this).index)++));
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 56: {
auto&& __jakt_match_value = __jakt_match_variant.template get<lexer::Token::Eol>();{
((((*this).index)++));
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
default: {
{
NonnullRefPtr<typename parser::ParsedExpression> const expr = TRY((((*this).parse_expression(false,false))));
if (((expr)->index() == 28 /* Garbage */)){
return JaktInternal::LoopBreak{};
}
TRY((((output).push(expr))));
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
}/*switch end*/
}()
));
}
size_t const end = (JaktInternal::checked_sub<size_t>(((*this).index),static_cast<size_t>(1ULL)));
if (((end >= ((((*this).tokens)).size())) || (!(((((((*this).tokens))[end])).index() == 11 /* RCurly */))))){
TRY((((*this).error(Jakt::DeprecatedString("Expected ‘}’ to close the set"sv),((((((*this).tokens))[end])).span())))));
}
return (TRY((parser::ParsedExpression::template create<typename parser::ParsedExpression::Set>(output,TRY((parser::merge_spans(start,((((((*this).tokens))[end])).span()))))))));
}
}

ErrorOr<parser::ParsedField> parser::Parser::parse_field(parser::Visibility const visibility) {
{
parser::ParsedVarDecl const parsed_variable_declaration = TRY((((*this).parse_variable_declaration(true))));
if (((((parsed_variable_declaration).parsed_type))->index() == 13 /* Empty */)){
TRY((((*this).error(Jakt::DeprecatedString("Field missing type"sv),((parsed_variable_declaration).span)))));
}
JaktInternal::Optional<NonnullRefPtr<typename parser::ParsedExpression>> default_value = JaktInternal::OptionalNone();
if (((((*this).peek(static_cast<size_t>(0ULL)))).index() == 17 /* Equal */)){
((((*this).index)++));
(default_value = TRY((((*this).parse_expression(false,false)))));
}
return (parser::ParsedField(parsed_variable_declaration,visibility,default_value));
}
}

void parser::Parser::skip_newlines() {
{
while (((((*this).current())).index() == 56 /* Eol */)){
((((*this).index)++));
}
}
}

ErrorOr<NonnullRefPtr<typename parser::ParsedExpression>> parser::Parser::parse_asterisk() {
{
utility::Span const start = ((((*this).current())).span());
((((*this).index)++));
NonnullRefPtr<typename parser::ParsedExpression> const expr = TRY((((*this).parse_operand())));
return (TRY((parser::ParsedExpression::template create<typename parser::ParsedExpression::UnaryOp>(expr, parser::UnaryOperator { typename parser::UnaryOperator::Dereference() } ,TRY((parser::merge_spans(start,((((*this).current())).span()))))))));
}
}

ErrorOr<JaktInternal::Tuple<JaktInternal::DynamicArray<parser::SumEnumVariant>,JaktInternal::DynamicArray<parser::ParsedField>,JaktInternal::DynamicArray<parser::ParsedMethod>>> parser::Parser::parse_sum_enum_body(parser::ParsedRecord const partial_enum,parser::DefinitionLinkage const definition_linkage,bool const is_boxed) {
{
JaktInternal::DynamicArray<parser::ParsedMethod> methods = (TRY((DynamicArray<parser::ParsedMethod>::create_with({}))));
JaktInternal::DynamicArray<parser::SumEnumVariant> variants = (TRY((DynamicArray<parser::SumEnumVariant>::create_with({}))));
JaktInternal::DynamicArray<parser::ParsedField> fields = (TRY((DynamicArray<parser::ParsedField>::create_with({}))));
bool seen_a_variant = false;
if (((((*this).current())).index() == 10 /* LCurly */)){
((((*this).index)++));
}
else {
TRY((((*this).error(Jakt::DeprecatedString("Expected `{` to start the enum body"sv),((((*this).current())).span())))));
}

((*this).skip_newlines());
if (((*this).eof())){
TRY((((*this).error(Jakt::DeprecatedString("Incomplete enum definition, expected variant or field name"sv),((((*this).previous())).span())))));
return ((Tuple{variants, fields, methods}));
}
JaktInternal::Optional<parser::Visibility> last_visibility = JaktInternal::OptionalNone();
JaktInternal::Optional<utility::Span> last_visibility_span = JaktInternal::OptionalNone();
while ((!(((*this).eof())))){
JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_AT_LOOP(([&]() -> JaktInternal::ExplicitValueOrControlFlow<void, ErrorOr<JaktInternal::Tuple<JaktInternal::DynamicArray<parser::SumEnumVariant>,JaktInternal::DynamicArray<parser::ParsedField>,JaktInternal::DynamicArray<parser::ParsedMethod>>>>{
auto&& __jakt_match_variant = ((*this).current());
switch(__jakt_match_variant.index()) {
case 4: {
auto&& __jakt_match_value = __jakt_match_variant.template get<lexer::Token::Identifier>();DeprecatedString const& name = __jakt_match_value.name;
utility::Span const& span = __jakt_match_value.span;
{
if (((((*this).peek(static_cast<size_t>(1ULL)))).index() == 6 /* Colon */)){
parser::ParsedField const field = TRY((((*this).parse_field(last_visibility.value_or_lazy_evaluated([&] { return  parser::Visibility { typename parser::Visibility::Public() } ; })))));
if (seen_a_variant){
TRY((((*this).error_with_hint(Jakt::DeprecatedString("Common enum fields must be declared before variants"sv),span,Jakt::DeprecatedString("Previous variant is here"sv),(((((variants).last()).value())).span)))));
}
else {
TRY((((fields).push(field))));
}

return JaktInternal::LoopContinue{};
}
(seen_a_variant = true);
if ((!(((((*this).peek(static_cast<size_t>(1ULL)))).index() == 8 /* LParen */)))){
((((*this).index)++));
TRY((((variants).push(parser::SumEnumVariant(name,span,JaktInternal::OptionalNone())))));
return JaktInternal::LoopContinue{};
}
({auto& _jakt_ref = ((*this).index);_jakt_ref = JaktInternal::checked_add<size_t>(_jakt_ref, static_cast<size_t>(2ULL));});
JaktInternal::DynamicArray<parser::ParsedVarDecl> var_decls = (TRY((DynamicArray<parser::ParsedVarDecl>::create_with({}))));
while ((!(((*this).eof())))){
if (((((*this).peek(static_cast<size_t>(1ULL)))).index() == 6 /* Colon */)){
parser::ParsedVarDecl var_decl = TRY((((*this).parse_variable_declaration(false))));
if (((((var_decl).parsed_type))->index() == 0 /* Name */)){
DeprecatedString const name = ((((var_decl).parsed_type))->get<parser::ParsedType::Name>()).name;
utility::Span const span = ((((var_decl).parsed_type))->get<parser::ParsedType::Name>()).span;
(((var_decl).inlay_span) = span);
if (((name == ((partial_enum).name)) && (!(is_boxed)))){
TRY((((*this).error(Jakt::DeprecatedString("use 'boxed enum' to make the enum recursive"sv),((var_decl).span)))));
}
}
TRY((((var_decls).push(var_decl))));
continue;
}
JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_AT_LOOP(([&]() -> JaktInternal::ExplicitValueOrControlFlow<void, ErrorOr<JaktInternal::Tuple<JaktInternal::DynamicArray<parser::SumEnumVariant>,JaktInternal::DynamicArray<parser::ParsedField>,JaktInternal::DynamicArray<parser::ParsedMethod>>>>{
auto&& __jakt_match_variant = ((*this).current());
switch(__jakt_match_variant.index()) {
case 4: {
auto&& __jakt_match_value = __jakt_match_variant.template get<lexer::Token::Identifier>();{
TRY((((var_decls).push(parser::ParsedVarDecl(Jakt::DeprecatedString(""sv),TRY((((*this).parse_typename()))),false,JaktInternal::OptionalNone(),((((*this).current())).span()))))));
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 12: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::LSquare>();
{
TRY((((var_decls).push(parser::ParsedVarDecl(Jakt::DeprecatedString(""sv),TRY((((*this).parse_typename()))),false,JaktInternal::OptionalNone(),((((*this).current())).span()))))));
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 10: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::LCurly>();
{
TRY((((var_decls).push(parser::ParsedVarDecl(Jakt::DeprecatedString(""sv),TRY((((*this).parse_typename()))),false,JaktInternal::OptionalNone(),((((*this).current())).span()))))));
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
JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_AT_LOOP(([&]() -> JaktInternal::ExplicitValueOrControlFlow<void, ErrorOr<JaktInternal::Tuple<JaktInternal::DynamicArray<parser::SumEnumVariant>,JaktInternal::DynamicArray<parser::ParsedField>,JaktInternal::DynamicArray<parser::ParsedMethod>>>>{
auto&& __jakt_match_variant = ((*this).current());
switch(__jakt_match_variant.index()) {
case 9: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::RParen>();
{
((((*this).index)++));
return JaktInternal::LoopBreak{};
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 53: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::Comma>();
{
((((*this).index)++));
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 56: {
auto&& __jakt_match_value = __jakt_match_variant.template get<lexer::Token::Eol>();{
((((*this).index)++));
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
default: {
{
TRY((((*this).error(TRY((__jakt_format(Jakt::DeprecatedString("Incomplete enum variant defintion, expected `,` or `)`; got ‘{}’"sv),((*this).current())))),((((*this).current())).span())))));
return JaktInternal::LoopBreak{};
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
}/*switch end*/
}()
));
}
TRY((((variants).push(parser::SumEnumVariant(name,span,var_decls)))));
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 11: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::RCurly>();
{
return JaktInternal::LoopBreak{};
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 53: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::Comma>();
{
((((*this).index)++));
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 56: {
auto&& __jakt_match_value = __jakt_match_variant.template get<lexer::Token::Eol>();{
((((*this).index)++));
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 89: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::Private>();
utility::Span const& span = __jakt_match_value.value;
{
if (((last_visibility).has_value())){
TRY((((*this).error_with_hint(Jakt::DeprecatedString("Multiple visibility modifiers on one field or method are not allowed"sv),span,Jakt::DeprecatedString("Previous modifier is here"sv),(last_visibility_span.value())))));
}
(last_visibility =  parser::Visibility { typename parser::Visibility::Private() } );
(last_visibility_span = span);
((((*this).index)++));
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 90: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::Public>();
utility::Span const& span = __jakt_match_value.value;
{
if (((last_visibility).has_value())){
TRY((((*this).error_with_hint(Jakt::DeprecatedString("Multiple visibility modifiers on one field or method are not allowed"sv),span,Jakt::DeprecatedString("Previous modifier is here"sv),(last_visibility_span.value())))));
}
(last_visibility =  parser::Visibility { typename parser::Visibility::Public() } );
(last_visibility_span = span);
((((*this).index)++));
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 75: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::Function>();
{
bool const is_comptime = ((((*this).current())).index() == 76 /* Comptime */);
parser::FunctionLinkage const function_linkage = JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_AT_LOOP_NESTED_MATCH(([&]() -> JaktInternal::ExplicitValueOrControlFlow<parser::FunctionLinkage, ErrorOr<JaktInternal::Tuple<JaktInternal::DynamicArray<parser::SumEnumVariant>,JaktInternal::DynamicArray<parser::ParsedField>,JaktInternal::DynamicArray<parser::ParsedMethod>>>>{
auto&& __jakt_match_variant = definition_linkage;
switch(__jakt_match_variant.index()) {
case 0: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename parser::DefinitionLinkage::Internal>();
return JaktInternal::ExplicitValue( parser::FunctionLinkage { typename parser::FunctionLinkage::Internal() } );
};/*case end*/
case 1: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename parser::DefinitionLinkage::External>();
return JaktInternal::ExplicitValue( parser::FunctionLinkage { typename parser::FunctionLinkage::External() } );
};/*case end*/
default: VERIFY_NOT_REACHED();}/*switch end*/
}()
));
if ((((function_linkage).index() == 1 /* External */) && is_comptime)){
TRY((((*this).error(Jakt::DeprecatedString("External functions cannot be comptime"sv),((((*this).current())).span())))));
}
parser::Visibility const visibility = last_visibility.value_or_lazy_evaluated([&] { return  parser::Visibility { typename parser::Visibility::Public() } ; });
(last_visibility = JaktInternal::OptionalNone());
(last_visibility_span = JaktInternal::OptionalNone());
parser::ParsedMethod const parsed_method = TRY((((*this).parse_method(function_linkage,visibility,false,false,is_comptime))));
TRY((((methods).push(parsed_method))));
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 76: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::Comptime>();
{
bool const is_comptime = ((((*this).current())).index() == 76 /* Comptime */);
parser::FunctionLinkage const function_linkage = JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_AT_LOOP_NESTED_MATCH(([&]() -> JaktInternal::ExplicitValueOrControlFlow<parser::FunctionLinkage, ErrorOr<JaktInternal::Tuple<JaktInternal::DynamicArray<parser::SumEnumVariant>,JaktInternal::DynamicArray<parser::ParsedField>,JaktInternal::DynamicArray<parser::ParsedMethod>>>>{
auto&& __jakt_match_variant = definition_linkage;
switch(__jakt_match_variant.index()) {
case 0: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename parser::DefinitionLinkage::Internal>();
return JaktInternal::ExplicitValue( parser::FunctionLinkage { typename parser::FunctionLinkage::Internal() } );
};/*case end*/
case 1: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename parser::DefinitionLinkage::External>();
return JaktInternal::ExplicitValue( parser::FunctionLinkage { typename parser::FunctionLinkage::External() } );
};/*case end*/
default: VERIFY_NOT_REACHED();}/*switch end*/
}()
));
if ((((function_linkage).index() == 1 /* External */) && is_comptime)){
TRY((((*this).error(Jakt::DeprecatedString("External functions cannot be comptime"sv),((((*this).current())).span())))));
}
parser::Visibility const visibility = last_visibility.value_or_lazy_evaluated([&] { return  parser::Visibility { typename parser::Visibility::Public() } ; });
(last_visibility = JaktInternal::OptionalNone());
(last_visibility_span = JaktInternal::OptionalNone());
parser::ParsedMethod const parsed_method = TRY((((*this).parse_method(function_linkage,visibility,false,false,is_comptime))));
TRY((((methods).push(parsed_method))));
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
default: {
{
TRY((((*this).error(Jakt::DeprecatedString("Expected identifier or the end of enum block"sv),((((*this).current())).span())))));
((((*this).index)++));
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
}/*switch end*/
}()
));
}
if ((!(((((*this).current())).index() == 11 /* RCurly */)))){
TRY((((*this).error(Jakt::DeprecatedString("Invalid enum definition, expected `}`"sv),((((*this).current())).span())))));
return ((Tuple{variants, fields, methods}));
}
((((*this).index)++));
if (((variants).is_empty())){
TRY((((*this).error(Jakt::DeprecatedString("Empty enums are not allowed"sv),((partial_enum).name_span)))));
}
return ((Tuple{variants, fields, methods}));
}
}

ErrorOr<NonnullRefPtr<typename parser::ParsedType>> parser::Parser::parse_type_shorthand_tuple() {
{
utility::Span const start = ((((*this).current())).span());
((((*this).index)++));
JaktInternal::DynamicArray<NonnullRefPtr<typename parser::ParsedType>> types = (TRY((DynamicArray<NonnullRefPtr<typename parser::ParsedType>>::create_with({}))));
while ((!(((*this).eof())))){
if (((((*this).current())).index() == 9 /* RParen */)){
((((*this).index)++));
return (TRY((parser::ParsedType::template create<typename parser::ParsedType::JaktTuple>(types,TRY((parser::merge_spans(start,((((*this).previous())).span()))))))));
}
if (((((*this).current())).index() == 53 /* Comma */)){
((((*this).index)++));
}
size_t const index_before = ((*this).index);
NonnullRefPtr<typename parser::ParsedType> const type = TRY((((*this).parse_typename())));
size_t const index_after = ((*this).index);
if ((index_before == index_after)){
break;
}
TRY((((types).push(type))));
}
TRY((((*this).error(Jakt::DeprecatedString("Expected ‘)’"sv),((((*this).current())).span())))));
return (TRY((parser::ParsedType::template create<typename parser::ParsedType::Empty>())));
}
}

ErrorOr<parser::ParsedMatchPattern> parser::Parser::parse_match_pattern() {
{
return (JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<parser::ParsedMatchPattern, ErrorOr<parser::ParsedMatchPattern>>{
auto&& __jakt_match_variant = ((*this).current());
switch(__jakt_match_variant.index()) {
case 98: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::True>();
return JaktInternal::ExplicitValue( parser::ParsedMatchPattern { typename parser::ParsedMatchPattern::Expression((TRY((Dictionary<DeprecatedString, parser::ParsedPatternDefault>::create_with_entries({})))),TRY((((*this).parse_operand())))) } );
};/*case end*/
case 73: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::False>();
return JaktInternal::ExplicitValue( parser::ParsedMatchPattern { typename parser::ParsedMatchPattern::Expression((TRY((Dictionary<DeprecatedString, parser::ParsedPatternDefault>::create_with_entries({})))),TRY((((*this).parse_operand())))) } );
};/*case end*/
case 3: {
auto&& __jakt_match_value = __jakt_match_variant.template get<lexer::Token::Number>();return JaktInternal::ExplicitValue( parser::ParsedMatchPattern { typename parser::ParsedMatchPattern::Expression((TRY((Dictionary<DeprecatedString, parser::ParsedPatternDefault>::create_with_entries({})))),TRY((((*this).parse_operand())))) } );
};/*case end*/
case 2: {
auto&& __jakt_match_value = __jakt_match_variant.template get<lexer::Token::QuotedString>();return JaktInternal::ExplicitValue( parser::ParsedMatchPattern { typename parser::ParsedMatchPattern::Expression((TRY((Dictionary<DeprecatedString, parser::ParsedPatternDefault>::create_with_entries({})))),TRY((((*this).parse_operand())))) } );
};/*case end*/
case 0: {
auto&& __jakt_match_value = __jakt_match_variant.template get<lexer::Token::SingleQuotedString>();return JaktInternal::ExplicitValue( parser::ParsedMatchPattern { typename parser::ParsedMatchPattern::Expression((TRY((Dictionary<DeprecatedString, parser::ParsedPatternDefault>::create_with_entries({})))),TRY((((*this).parse_operand())))) } );
};/*case end*/
case 1: {
auto&& __jakt_match_value = __jakt_match_variant.template get<lexer::Token::SingleQuotedByteString>();return JaktInternal::ExplicitValue( parser::ParsedMatchPattern { typename parser::ParsedMatchPattern::Expression((TRY((Dictionary<DeprecatedString, parser::ParsedPatternDefault>::create_with_entries({})))),TRY((((*this).parse_operand())))) } );
};/*case end*/
case 8: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::LParen>();
return JaktInternal::ExplicitValue( parser::ParsedMatchPattern { typename parser::ParsedMatchPattern::Expression((TRY((Dictionary<DeprecatedString, parser::ParsedPatternDefault>::create_with_entries({})))),TRY((((*this).parse_operand())))) } );
};/*case end*/
case 70: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::Else>();
return JaktInternal::ExplicitValue(({ Optional<parser::ParsedMatchPattern> __jakt_var_31; {
((((*this).index)++));
JaktInternal::DynamicArray<parser::EnumVariantPatternArgument> variant_arguments = TRY((((*this).parse_variant_arguments())));
utility::Span const arguments_start = ((((*this).current())).span());
utility::Span const arguments_end = ((((*this).previous())).span());
utility::Span const arguments_span = TRY((parser::merge_spans(arguments_start,arguments_end)));
__jakt_var_31 =  parser::ParsedMatchPattern { typename parser::ParsedMatchPattern::CatchAll((TRY((Dictionary<DeprecatedString, parser::ParsedPatternDefault>::create_with_entries({})))),variant_arguments,arguments_span) } ; goto __jakt_label_29;

}
__jakt_label_29:; __jakt_var_31.release_value(); }));
};/*case end*/
case 4: {
auto&& __jakt_match_value = __jakt_match_variant.template get<lexer::Token::Identifier>();return JaktInternal::ExplicitValue(({ Optional<parser::ParsedMatchPattern> __jakt_var_32; {
JaktInternal::DynamicArray<JaktInternal::Tuple<DeprecatedString,utility::Span>> variant_names = (TRY((DynamicArray<JaktInternal::Tuple<DeprecatedString,utility::Span>>::create_with({}))));
bool just_saw_name = false;
while ((!(((*this).eof())))){
((*this).skip_newlines());
JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_AT_LOOP(([&]() -> JaktInternal::ExplicitValueOrControlFlow<void, ErrorOr<parser::ParsedMatchPattern>>{
auto&& __jakt_match_variant = ((*this).current());
switch(__jakt_match_variant.index()) {
case 4: {
auto&& __jakt_match_value = __jakt_match_variant.template get<lexer::Token::Identifier>();DeprecatedString const& name = __jakt_match_value.name;
{
if (just_saw_name){
return JaktInternal::LoopBreak{};
}
(just_saw_name = true);
((((*this).index)++));
TRY((((variant_names).push((Tuple{name, ((((*this).current())).span())})))));
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 7: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::ColonColon>();
{
((((*this).index)++));
(just_saw_name = false);
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
default: {
{
return JaktInternal::LoopBreak{};
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
}/*switch end*/
}()
));
}
JaktInternal::DynamicArray<parser::EnumVariantPatternArgument> variant_arguments = TRY((((*this).parse_variant_arguments())));
utility::Span const arguments_start = ((((*this).current())).span());
utility::Span const arguments_end = ((((*this).previous())).span());
utility::Span const arguments_span = TRY((parser::merge_spans(arguments_start,arguments_end)));
__jakt_var_32 =  parser::ParsedMatchPattern { typename parser::ParsedMatchPattern::EnumVariant((TRY((Dictionary<DeprecatedString, parser::ParsedPatternDefault>::create_with_entries({})))),variant_names,variant_arguments,arguments_span) } ; goto __jakt_label_30;

}
__jakt_label_30:; __jakt_var_32.release_value(); }));
};/*case end*/
default: {
return JaktInternal::ExplicitValue(({ Optional<parser::ParsedMatchPattern> __jakt_var_33; {
TRY((((*this).error(Jakt::DeprecatedString("Expected pattern or ‘else’"sv),((((*this).current())).span())))));
__jakt_var_33 =  parser::ParsedMatchPattern { typename parser::ParsedMatchPattern::Invalid((TRY((Dictionary<DeprecatedString, parser::ParsedPatternDefault>::create_with_entries({}))))) } ; goto __jakt_label_31;

}
__jakt_label_31:; __jakt_var_33.release_value(); }));
};/*case end*/
}/*switch end*/
}()
)));
}
}

ErrorOr<void> parser::Parser::parse_import(parser::ParsedNamespace& parent) {
{
if (((((*this).current())).index() == 72 /* Extern */)){
((((*this).index)++));
TRY((((((parent))).add_extern_import(TRY((((*this).parse_extern_import(parent))))))));
}
else {
TRY((((((parent))).add_module_import(TRY((((*this).parse_module_import())))))));
}

}
return {};
}

ErrorOr<JaktInternal::Optional<parser::NumericConstant>> parser::Parser::make_integer_numeric_constant(u64 const number,lexer::LiteralSuffix const suffix,utility::Span const span) {
{
JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<void, ErrorOr<JaktInternal::Optional<parser::NumericConstant>>>{
auto&& __jakt_match_variant = suffix;
switch(__jakt_match_variant.index()) {
case 0: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::LiteralSuffix::None>();
{
JaktInternal::Optional<i64> const n = (fallible_integer_cast<i64>((number)));
if (((n).has_value())){
return ( parser::NumericConstant { typename parser::NumericConstant::UnknownSigned((n.value())) } );
}
return ( parser::NumericConstant { typename parser::NumericConstant::UnknownUnsigned(number) } );
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 2: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::LiteralSuffix::U8>();
{
JaktInternal::Optional<u8> const n = (fallible_integer_cast<u8>((number)));
if ((!(((n).has_value())))){
TRY((((*this).error(TRY((__jakt_format(Jakt::DeprecatedString("Number {} cannot fit in integer type {}"sv),number,suffix))),span))));
return ( parser::NumericConstant { typename parser::NumericConstant::U64(number) } );
}
return ( parser::NumericConstant { typename parser::NumericConstant::U8((n.value())) } );
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 3: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::LiteralSuffix::U16>();
{
JaktInternal::Optional<u16> const n = (fallible_integer_cast<u16>((number)));
if ((!(((n).has_value())))){
TRY((((*this).error(TRY((__jakt_format(Jakt::DeprecatedString("Number {} cannot fit in integer type {}"sv),number,suffix))),span))));
return ( parser::NumericConstant { typename parser::NumericConstant::U64(number) } );
}
return ( parser::NumericConstant { typename parser::NumericConstant::U16((n.value())) } );
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 4: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::LiteralSuffix::U32>();
{
JaktInternal::Optional<u32> const n = (fallible_integer_cast<u32>((number)));
if ((!(((n).has_value())))){
TRY((((*this).error(TRY((__jakt_format(Jakt::DeprecatedString("Number {} cannot fit in integer type {}"sv),number,suffix))),span))));
return ( parser::NumericConstant { typename parser::NumericConstant::U64(number) } );
}
return ( parser::NumericConstant { typename parser::NumericConstant::U32((n.value())) } );
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 5: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::LiteralSuffix::U64>();
{
JaktInternal::Optional<u64> const n = (fallible_integer_cast<u64>((number)));
if ((!(((n).has_value())))){
TRY((((*this).error(TRY((__jakt_format(Jakt::DeprecatedString("Number {} cannot fit in integer type {}"sv),number,suffix))),span))));
return ( parser::NumericConstant { typename parser::NumericConstant::U64(number) } );
}
return ( parser::NumericConstant { typename parser::NumericConstant::U64((n.value())) } );
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 1: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::LiteralSuffix::UZ>();
{
JaktInternal::Optional<size_t> const n = (fallible_integer_cast<size_t>((number)));
if ((!(((n).has_value())))){
TRY((((*this).error(TRY((__jakt_format(Jakt::DeprecatedString("Number {} cannot fit in integer type {}"sv),number,suffix))),span))));
return ( parser::NumericConstant { typename parser::NumericConstant::U64(number) } );
}
return ( parser::NumericConstant { typename parser::NumericConstant::USize((infallible_integer_cast<u64>(((n.value()))))) } );
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 6: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::LiteralSuffix::I8>();
{
JaktInternal::Optional<i8> const n = (fallible_integer_cast<i8>((number)));
if ((!(((n).has_value())))){
TRY((((*this).error(TRY((__jakt_format(Jakt::DeprecatedString("Number {} cannot fit in integer type {}"sv),number,suffix))),span))));
return ( parser::NumericConstant { typename parser::NumericConstant::U64(number) } );
}
return ( parser::NumericConstant { typename parser::NumericConstant::I8((n.value())) } );
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 7: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::LiteralSuffix::I16>();
{
JaktInternal::Optional<i16> const n = (fallible_integer_cast<i16>((number)));
if ((!(((n).has_value())))){
TRY((((*this).error(TRY((__jakt_format(Jakt::DeprecatedString("Number {} cannot fit in integer type {}"sv),number,suffix))),span))));
return ( parser::NumericConstant { typename parser::NumericConstant::U64(number) } );
}
return ( parser::NumericConstant { typename parser::NumericConstant::I16((n.value())) } );
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 8: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::LiteralSuffix::I32>();
{
JaktInternal::Optional<i32> const n = (fallible_integer_cast<i32>((number)));
if ((!(((n).has_value())))){
TRY((((*this).error(TRY((__jakt_format(Jakt::DeprecatedString("Number {} cannot fit in integer type {}"sv),number,suffix))),span))));
return ( parser::NumericConstant { typename parser::NumericConstant::U64(number) } );
}
return ( parser::NumericConstant { typename parser::NumericConstant::I32((n.value())) } );
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 9: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::LiteralSuffix::I64>();
{
JaktInternal::Optional<i64> const n = (fallible_integer_cast<i64>((number)));
if ((!(((n).has_value())))){
TRY((((*this).error(TRY((__jakt_format(Jakt::DeprecatedString("Number {} cannot fit in integer type {}"sv),number,suffix))),span))));
return ( parser::NumericConstant { typename parser::NumericConstant::U64(number) } );
}
return ( parser::NumericConstant { typename parser::NumericConstant::I64((n.value())) } );
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
return (JaktInternal::OptionalNone());
}
}

ErrorOr<parser::ParsedRecord> parser::Parser::parse_enum(parser::DefinitionLinkage const definition_linkage,bool const is_boxed) {
{
parser::ParsedRecord parsed_enum = parser::ParsedRecord(Jakt::DeprecatedString(""sv),((*this).empty_span()),(TRY((DynamicArray<parser::ParsedGenericParameter>::create_with({})))),definition_linkage,JaktInternal::OptionalNone(),(TRY((DynamicArray<parser::ParsedMethod>::create_with({})))), parser::RecordType { typename parser::RecordType::Garbage() } ,JaktInternal::OptionalNone());
JaktInternal::Optional<NonnullRefPtr<typename parser::ParsedType>> underlying_type = JaktInternal::OptionalNone();
if (((((*this).current())).index() == 71 /* Enum */)){
((((*this).index)++));
}
else {
TRY((((*this).error(Jakt::DeprecatedString("Expected ‘enum’ keyword"sv),((((*this).current())).span())))));
return (parsed_enum);
}

if (((*this).eof())){
TRY((((*this).error(Jakt::DeprecatedString("Incomplete enum definition, expected name"sv),((((*this).current())).span())))));
return (parsed_enum);
}
if (((((*this).current())).index() == 4 /* Identifier */)){
DeprecatedString const name = ((((*this).current())).get<lexer::Token::Identifier>()).name;
utility::Span const span = ((((*this).current())).get<lexer::Token::Identifier>()).span;
(((parsed_enum).name) = name);
(((parsed_enum).name_span) = span);
((((*this).index)++));
}
else {
TRY((((*this).error(Jakt::DeprecatedString("Incomplete enum definition, expected name"sv),((((*this).current())).span())))));
}

if (((*this).eof())){
TRY((((*this).error(Jakt::DeprecatedString("Incomplete enum definition, expected generic parameters or underlying type or body"sv),((((*this).current())).span())))));
return (parsed_enum);
}
if (((((*this).current())).index() == 29 /* LessThan */)){
(((parsed_enum).generic_parameters) = TRY((((*this).parse_generic_parameters()))));
}
if (((((*this).current())).index() == 106 /* Implements */)){
((((*this).index)++));
(((parsed_enum).implements_list) = TRY((((*this).parse_trait_list()))));
}
if (((*this).eof())){
TRY((((*this).error(Jakt::DeprecatedString("Incomplete enum definition, expected underlying type or body"sv),((((*this).current())).span())))));
return (parsed_enum);
}
if (((((*this).current())).index() == 6 /* Colon */)){
if (is_boxed){
TRY((((*this).error(Jakt::DeprecatedString("Invalid enum definition: Value enums must not have an underlying type"sv),((((*this).current())).span())))));
}
((((*this).index)++));
(underlying_type = TRY((((*this).parse_typename()))));
}
((*this).skip_newlines());
if (((*this).eof())){
TRY((((*this).error(Jakt::DeprecatedString("Incomplete enum definition, expected body"sv),((((*this).current())).span())))));
return (parsed_enum);
}
if (((underlying_type).has_value())){
JaktInternal::Tuple<JaktInternal::DynamicArray<parser::ValueEnumVariant>,JaktInternal::DynamicArray<parser::ParsedMethod>> const variants_methods_ = TRY((((*this).parse_value_enum_body(parsed_enum,definition_linkage))));
JaktInternal::DynamicArray<parser::ValueEnumVariant> const variants = ((variants_methods_).template get<0>());
JaktInternal::DynamicArray<parser::ParsedMethod> const methods = ((variants_methods_).template get<1>());

(((parsed_enum).methods) = methods);
(((parsed_enum).record_type) =  parser::RecordType { typename parser::RecordType::ValueEnum((underlying_type.value()),variants) } );
}
else {
JaktInternal::Tuple<JaktInternal::DynamicArray<parser::SumEnumVariant>,JaktInternal::DynamicArray<parser::ParsedField>,JaktInternal::DynamicArray<parser::ParsedMethod>> const variants_fields_methods_ = TRY((((*this).parse_sum_enum_body(parsed_enum,definition_linkage,is_boxed))));
JaktInternal::DynamicArray<parser::SumEnumVariant> const variants = ((variants_fields_methods_).template get<0>());
JaktInternal::DynamicArray<parser::ParsedField> const fields = ((variants_fields_methods_).template get<1>());
JaktInternal::DynamicArray<parser::ParsedMethod> const methods = ((variants_fields_methods_).template get<2>());

(((parsed_enum).methods) = methods);
(((parsed_enum).record_type) =  parser::RecordType { typename parser::RecordType::SumEnum(is_boxed,fields,variants) } );
}

return (parsed_enum);
}
}

ErrorOr<parser::Visibility> parser::Parser::parse_restricted_visibility_modifier() {
{
utility::Span restricted_span = ((((*this).current())).span());
((((*this).index)++));
if (((((*this).current())).index() == 8 /* LParen */)){
((((*this).index)++));
}
else {
TRY((((*this).error(Jakt::DeprecatedString("Expected ‘(’"sv),((((*this).current())).span())))));
return ( parser::Visibility { typename parser::Visibility::Restricted((TRY((DynamicArray<parser::VisibilityRestriction>::create_with({})))),restricted_span) } );
}

JaktInternal::DynamicArray<parser::VisibilityRestriction> whitelist = (TRY((DynamicArray<parser::VisibilityRestriction>::create_with({}))));
bool expect_comma = false;
while ((((*this).index) < ((((*this).tokens)).size()))){
JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_AT_LOOP(([&]() -> JaktInternal::ExplicitValueOrControlFlow<void, ErrorOr<parser::Visibility>>{
auto&& __jakt_match_variant = ((*this).current());
switch(__jakt_match_variant.index()) {
case 9: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::RParen>();
{
return JaktInternal::LoopBreak{};
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 53: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::Comma>();
utility::Span const& span = __jakt_match_value.value;
{
if (expect_comma){
(expect_comma = false);
}
else {
TRY((((*this).error(Jakt::DeprecatedString("Unexpected comma"sv),span))));
}

((((*this).index)++));
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
default: {
{
if (expect_comma){
TRY((((*this).error(Jakt::DeprecatedString("Expected comma"sv),((((*this).current())).span())))));
}
((*this).skip_newlines());
JaktInternal::DynamicArray<DeprecatedString> names = (TRY((DynamicArray<DeprecatedString>::create_with({}))));
for (;;){
if (((((*this).current())).index() == 4 /* Identifier */)){
DeprecatedString const name = ((((*this).current())).get<lexer::Token::Identifier>()).name;
TRY((((names).push(name))));
((((*this).index)++));
if (((((*this).current())).index() == 7 /* ColonColon */)){
((((*this).index)++));
}
else {
break;
}

}
else {
break;
}

}
if (((names).is_empty())){
TRY((((*this).error(Jakt::DeprecatedString("Expected identifier"sv),((((*this).current())).span())))));
}
else {
DeprecatedString const name = (((names).pop()).value());
TRY((((whitelist).push(parser::VisibilityRestriction(names,name)))));
}

(expect_comma = true);
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
}/*switch end*/
}()
));
}
(((restricted_span).end) = ((((((*this).current())).span())).end));
if (((whitelist).is_empty())){
TRY((((*this).error_with_hint(Jakt::DeprecatedString("Restriction list cannot be empty"sv),restricted_span,Jakt::DeprecatedString("Did you mean to use ‘private’ instead of ‘restricted’?"sv),restricted_span))));
}
if (((((*this).current())).index() == 9 /* RParen */)){
((((*this).index)++));
}
else {
TRY((((*this).error(Jakt::DeprecatedString("Expected ‘)’"sv),((((*this).current())).span())))));
}

return ( parser::Visibility { typename parser::Visibility::Restricted(whitelist,restricted_span) } );
}
}

ErrorOr<parser::ParsedRecord> parser::Parser::parse_record(parser::DefinitionLinkage const definition_linkage) {
{
return (JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<parser::ParsedRecord, ErrorOr<parser::ParsedRecord>>{
auto&& __jakt_match_variant = ((*this).current());
switch(__jakt_match_variant.index()) {
case 94: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::Struct>();
return JaktInternal::ExplicitValue(TRY((((*this).parse_struct(definition_linkage)))));
};/*case end*/
case 66: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::Class>();
return JaktInternal::ExplicitValue(TRY((((*this).parse_class(definition_linkage)))));
};/*case end*/
case 71: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::Enum>();
return JaktInternal::ExplicitValue(TRY((((*this).parse_enum(definition_linkage,false)))));
};/*case end*/
case 63: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::Boxed>();
return JaktInternal::ExplicitValue(({ Optional<parser::ParsedRecord> __jakt_var_34; {
((((*this).index)++));
__jakt_var_34 = TRY((((*this).parse_enum(definition_linkage,true)))); goto __jakt_label_32;

}
__jakt_label_32:; __jakt_var_34.release_value(); }));
};/*case end*/
default: {
return JaktInternal::ExplicitValue(({ Optional<parser::ParsedRecord> __jakt_var_35; {
TRY((((*this).error(Jakt::DeprecatedString("Expected `struct`, `class`, `enum`, or `boxed`"sv),((((*this).current())).span())))));
__jakt_var_35 = parser::ParsedRecord(Jakt::DeprecatedString(""sv),((*this).empty_span()),(TRY((DynamicArray<parser::ParsedGenericParameter>::create_with({})))),definition_linkage,JaktInternal::OptionalNone(),(TRY((DynamicArray<parser::ParsedMethod>::create_with({})))), parser::RecordType { typename parser::RecordType::Garbage() } ,JaktInternal::OptionalNone()); goto __jakt_label_33;

}
__jakt_label_33:; __jakt_var_35.release_value(); }));
};/*case end*/
}/*switch end*/
}()
)));
}
}

ErrorOr<JaktInternal::DynamicArray<parser::ParsedCapture>> parser::Parser::parse_captures() {
{
JaktInternal::DynamicArray<parser::ParsedCapture> captures = (TRY((DynamicArray<parser::ParsedCapture>::create_with({}))));
if (((((*this).current())).index() == 12 /* LSquare */)){
((((*this).index)++));
while ((!(((*this).eof())))){
JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_AT_LOOP(([&]() -> JaktInternal::ExplicitValueOrControlFlow<void, ErrorOr<JaktInternal::DynamicArray<parser::ParsedCapture>>>{
auto&& __jakt_match_variant = ((*this).current());
switch(__jakt_match_variant.index()) {
case 13: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::RSquare>();
{
((((*this).index)++));
return JaktInternal::LoopBreak{};
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 38: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::Ampersand>();
{
((((*this).index)++));
JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_AT_LOOP_NESTED_MATCH(([&]() -> JaktInternal::ExplicitValueOrControlFlow<void, ErrorOr<JaktInternal::DynamicArray<parser::ParsedCapture>>>{
auto&& __jakt_match_variant = ((*this).current());
switch(__jakt_match_variant.index()) {
case 84: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::Mut>();
{
((((*this).index)++));
if (((((*this).current())).index() == 4 /* Identifier */)){
DeprecatedString const name = ((((*this).current())).get<lexer::Token::Identifier>()).name;
TRY((((captures).push( parser::ParsedCapture { typename parser::ParsedCapture::ByMutableReference(name,((((*this).current())).span())) } ))));
((((*this).index)++));
}
else {
TRY((((*this).error(TRY((__jakt_format(Jakt::DeprecatedString("Expected identifier, got '{}'"sv),((*this).current())))),((((*this).current())).span())))));
((((*this).index)++));
}

}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 4: {
auto&& __jakt_match_value = __jakt_match_variant.template get<lexer::Token::Identifier>();DeprecatedString const& name = __jakt_match_value.name;
{
TRY((((captures).push( parser::ParsedCapture { typename parser::ParsedCapture::ByReference(name,((((*this).current())).span())) } ))));
((((*this).index)++));
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
default: {
{
TRY((((*this).error(TRY((__jakt_format(Jakt::DeprecatedString("Expected identifier or mut, got '{}'"sv),((*this).current())))),((((*this).current())).span())))));
((((*this).index)++));
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
}/*switch end*/
}()
));
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 4: {
auto&& __jakt_match_value = __jakt_match_variant.template get<lexer::Token::Identifier>();DeprecatedString const& name = __jakt_match_value.name;
{
TRY((((captures).push( parser::ParsedCapture { typename parser::ParsedCapture::ByValue(name,((((*this).current())).span())) } ))));
((((*this).index)++));
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 95: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::This>();
{
TRY((((captures).push( parser::ParsedCapture { typename parser::ParsedCapture::ByValue(Jakt::DeprecatedString("this"sv),((((*this).current())).span())) } ))));
((((*this).index)++));
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 53: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::Comma>();
{
((((*this).index)++));
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 56: {
auto&& __jakt_match_value = __jakt_match_variant.template get<lexer::Token::Eol>();{
((((*this).index)++));
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
default: {
{
TRY((((*this).error(TRY((__jakt_format(Jakt::DeprecatedString("Unexpected token '{}' in captures list"sv),((*this).current())))),((((*this).current())).span())))));
((((*this).index)++));
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
}/*switch end*/
}()
));
}
return (captures);
}
else {
return ((TRY((DynamicArray<parser::ParsedCapture>::create_with({})))));
}

}
}

ErrorOr<NonnullRefPtr<typename parser::ParsedExpression>> parser::Parser::parse_try_block() {
{
utility::Span const start_span = ((((*this).current())).span());
NonnullRefPtr<typename parser::ParsedStatement> const stmt = TRY((((*this).parse_statement(false))));
DeprecatedString error_name = Jakt::DeprecatedString(""sv);
utility::Span error_span = ((((*this).current())).span());
if (((((*this).current())).index() == 65 /* Catch */)){
((((*this).index)++));
if (((((*this).current())).index() == 4 /* Identifier */)){
DeprecatedString const name = ((((*this).current())).get<lexer::Token::Identifier>()).name;
(error_span = ((((*this).current())).span()));
(error_name = name);
((((*this).index)++));
}
}
else {
TRY((((*this).error(Jakt::DeprecatedString("Expected ‘catch’"sv),((((*this).current())).span())))));
}

parser::ParsedBlock const catch_block = TRY((((*this).parse_block())));
return (TRY((parser::ParsedExpression::template create<typename parser::ParsedExpression::TryBlock>(stmt,error_name,error_span,catch_block,TRY((parser::merge_spans(start_span,((((*this).previous())).span()))))))));
}
}

ErrorOr<JaktInternal::DynamicArray<parser::ParsedMatchPattern>> parser::Parser::parse_match_patterns() {
{
JaktInternal::DynamicArray<parser::ParsedMatchPattern> patterns = (TRY((DynamicArray<parser::ParsedMatchPattern>::create_with({}))));
((*this).skip_newlines());
while ((!(((*this).eof())))){
parser::ParsedMatchPattern pattern = TRY((((*this).parse_match_pattern())));
ScopeGuard __jakt_var_36([&] {
MUST((((patterns).push(pattern))));
});
JaktInternal::Dictionary<DeprecatedString,parser::ParsedPatternDefault> defaults = ((pattern).defaults());
((*this).skip_newlines());
if (((((*this).current())).index() == 4 /* Identifier */)){
DeprecatedString const name = ((((*this).current())).get<lexer::Token::Identifier>()).name;
if ((name == Jakt::DeprecatedString("default"sv))){
JaktInternal::Dictionary<DeprecatedString,parser::ParsedPatternDefault> defaults = ((pattern).defaults());
({auto& _jakt_ref = ((*this).index);_jakt_ref = JaktInternal::checked_add<size_t>(_jakt_ref, static_cast<size_t>(1ULL));});
if ((!(((((*this).current())).index() == 8 /* LParen */)))){
TRY((((*this).error(Jakt::DeprecatedString("Expected '(' after 'default'"sv),((((*this).current())).span())))));
continue;
}
({auto& _jakt_ref = ((*this).index);_jakt_ref = JaktInternal::checked_add<size_t>(_jakt_ref, static_cast<size_t>(1ULL));});
while (((!(((((*this).current())).index() == 9 /* RParen */))) && (!(((*this).eof()))))){
bool const is_mutable = ((((*this).current())).index() == 84 /* Mut */);
if (is_mutable){
((((*this).index)++));
}
parser::ParsedVarDecl const declaration = TRY((((*this).parse_variable_declaration(is_mutable))));
NonnullRefPtr<typename parser::ParsedExpression> const value = JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_AT_LOOP(([&]() -> JaktInternal::ExplicitValueOrControlFlow<NonnullRefPtr<typename parser::ParsedExpression>, ErrorOr<JaktInternal::DynamicArray<parser::ParsedMatchPattern>>>{
auto&& __jakt_match_variant = ((*this).current());
switch(__jakt_match_variant.index()) {
case 17: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::Equal>();
return JaktInternal::ExplicitValue(({ Optional<NonnullRefPtr<typename parser::ParsedExpression>> __jakt_var_37; {
((((*this).index)++));
__jakt_var_37 = TRY((((*this).parse_expression(false,false)))); goto __jakt_label_34;

}
__jakt_label_34:; __jakt_var_37.release_value(); }));
};/*case end*/
default: {
return JaktInternal::ExplicitValue(({ Optional<NonnullRefPtr<typename parser::ParsedExpression>> __jakt_var_38; {
TRY((((*this).error(Jakt::DeprecatedString("Expected initializer"sv),((((*this).current())).span())))));
__jakt_var_38 = TRY((parser::ParsedExpression::template create<typename parser::ParsedExpression::Garbage>(((((*this).current())).span())))); goto __jakt_label_35;

}
__jakt_label_35:; __jakt_var_38.release_value(); }));
};/*case end*/
}/*switch end*/
}()
));
TRY((((defaults).set(((declaration).name),parser::ParsedPatternDefault(declaration,value)))));
}
if (((((*this).current())).index() == 9 /* RParen */)){
({auto& _jakt_ref = ((*this).index);_jakt_ref = JaktInternal::checked_add<size_t>(_jakt_ref, static_cast<size_t>(1ULL));});
}
else {
TRY((((*this).error(Jakt::DeprecatedString("Expected a ')' to end 'defaults' list"sv),((((*this).current())).span())))));
}

}
}
((*this).skip_newlines());
if (((((*this).current())).index() == 41 /* Pipe */)){
((((*this).index)++));
continue;
}
break;
}
return (patterns);
}
}

ErrorOr<NonnullRefPtr<typename parser::ParsedExpression>> parser::Parser::parse_operand_postfix_operator(utility::Span const start,NonnullRefPtr<typename parser::ParsedExpression> const expr) {
{
NonnullRefPtr<typename parser::ParsedExpression> result = expr;
for (;;){
(result = JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_AT_LOOP(([&]() -> JaktInternal::ExplicitValueOrControlFlow<NonnullRefPtr<typename parser::ParsedExpression>, ErrorOr<NonnullRefPtr<typename parser::ParsedExpression>>>{
auto&& __jakt_match_variant = ((*this).current());
switch(__jakt_match_variant.index()) {
case 55: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::DotDot>();
return JaktInternal::ExplicitValue(({ Optional<NonnullRefPtr<typename parser::ParsedExpression>> __jakt_var_39; {
((((*this).index)++));
JaktInternal::Optional<NonnullRefPtr<typename parser::ParsedExpression>> to = JaktInternal::OptionalNone();
utility::Span span_end = ((((*this).current())).span());
JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_AT_LOOP_NESTED_MATCH(([&]() -> JaktInternal::ExplicitValueOrControlFlow<void, ErrorOr<NonnullRefPtr<typename parser::ParsedExpression>>>{
auto&& __jakt_match_variant = ((*this).current());
switch(__jakt_match_variant.index()) {
case 13: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::RSquare>();
{
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 56: {
auto&& __jakt_match_value = __jakt_match_variant.template get<lexer::Token::Eol>();{
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 53: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::Comma>();
{
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 9: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::RParen>();
{
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
default: {
{
(to = TRY((((*this).parse_operand()))));
(span_end = (((to.value()))->span()));
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
}/*switch end*/
}()
));
__jakt_var_39 = TRY((parser::ParsedExpression::template create<typename parser::ParsedExpression::Range>(result,to,TRY((parser::merge_spans(start,span_end)))))); goto __jakt_label_36;

}
__jakt_label_36:; __jakt_var_39.release_value(); }));
};/*case end*/
case 49: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::ExclamationPoint>();
return JaktInternal::ExplicitValue(({ Optional<NonnullRefPtr<typename parser::ParsedExpression>> __jakt_var_40; {
((((*this).index)++));
__jakt_var_40 = TRY((parser::ParsedExpression::template create<typename parser::ParsedExpression::ForcedUnwrap>(result,TRY((parser::merge_spans(start,((((*this).previous())).span()))))))); goto __jakt_label_37;

}
__jakt_label_37:; __jakt_var_40.release_value(); }));
};/*case end*/
case 19: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::PlusPlus>();
return JaktInternal::ExplicitValue(({ Optional<NonnullRefPtr<typename parser::ParsedExpression>> __jakt_var_41; {
((((*this).index)++));
__jakt_var_41 = TRY((parser::ParsedExpression::template create<typename parser::ParsedExpression::UnaryOp>(result, parser::UnaryOperator { typename parser::UnaryOperator::PostIncrement() } ,TRY((parser::merge_spans(start,((((*this).previous())).span()))))))); goto __jakt_label_38;

}
__jakt_label_38:; __jakt_var_41.release_value(); }));
};/*case end*/
case 21: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::MinusMinus>();
return JaktInternal::ExplicitValue(({ Optional<NonnullRefPtr<typename parser::ParsedExpression>> __jakt_var_42; {
((((*this).index)++));
__jakt_var_42 = TRY((parser::ParsedExpression::template create<typename parser::ParsedExpression::UnaryOp>(result, parser::UnaryOperator { typename parser::UnaryOperator::PostDecrement() } ,TRY((parser::merge_spans(start,((((*this).previous())).span()))))))); goto __jakt_label_39;

}
__jakt_label_39:; __jakt_var_42.release_value(); }));
};/*case end*/
case 62: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::As>();
return JaktInternal::ExplicitValue(({ Optional<NonnullRefPtr<typename parser::ParsedExpression>> __jakt_var_43; {
((((*this).index)++));
utility::Span const cast_span = TRY((parser::merge_spans(((((*this).previous())).span()),((((*this).current())).span()))));
parser::TypeCast const cast = JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_AT_LOOP_NESTED_MATCH(([&]() -> JaktInternal::ExplicitValueOrControlFlow<parser::TypeCast, ErrorOr<NonnullRefPtr<typename parser::ParsedExpression>>>{
auto&& __jakt_match_variant = ((*this).current());
switch(__jakt_match_variant.index()) {
case 49: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::ExclamationPoint>();
return JaktInternal::ExplicitValue(({ Optional<parser::TypeCast> __jakt_var_44; {
((((*this).index)++));
__jakt_var_44 =  parser::TypeCast { typename parser::TypeCast::Infallible(TRY((((*this).parse_typename())))) } ; goto __jakt_label_41;

}
__jakt_label_41:; __jakt_var_44.release_value(); }));
};/*case end*/
case 50: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::QuestionMark>();
return JaktInternal::ExplicitValue(({ Optional<parser::TypeCast> __jakt_var_45; {
((((*this).index)++));
__jakt_var_45 =  parser::TypeCast { typename parser::TypeCast::Fallible(TRY((((*this).parse_typename())))) } ; goto __jakt_label_42;

}
__jakt_label_42:; __jakt_var_45.release_value(); }));
};/*case end*/
default: {
return JaktInternal::ExplicitValue(({ Optional<parser::TypeCast> __jakt_var_46; {
TRY((((*this).error_with_hint(Jakt::DeprecatedString("Invalid cast syntax"sv),cast_span,Jakt::DeprecatedString("Use `as!` for an infallible cast, or `as?` for a fallible cast"sv),((((*this).previous())).span())))));
__jakt_var_46 =  parser::TypeCast { typename parser::TypeCast::Fallible(TRY((((*this).parse_typename())))) } ; goto __jakt_label_43;

}
__jakt_label_43:; __jakt_var_46.release_value(); }));
};/*case end*/
}/*switch end*/
}()
));
utility::Span const span = TRY((parser::merge_spans(start,TRY((parser::merge_spans(cast_span,((((*this).current())).span())))))));
__jakt_var_43 = TRY((parser::ParsedExpression::template create<typename parser::ParsedExpression::UnaryOp>(result, parser::UnaryOperator { typename parser::UnaryOperator::TypeCast(cast) } ,span))); goto __jakt_label_40;

}
__jakt_label_40:; __jakt_var_43.release_value(); }));
};/*case end*/
case 80: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::Is>();
return JaktInternal::ExplicitValue(({ Optional<NonnullRefPtr<typename parser::ParsedExpression>> __jakt_var_47; {
((((*this).index)++));
NonnullRefPtr<typename parser::ParsedType> const parsed_type = TRY((((*this).parse_typename())));
utility::Span const span = TRY((parser::merge_spans(start,((((*this).current())).span()))));
JaktInternal::DynamicArray<parser::EnumVariantPatternArgument> bindings = (TRY((DynamicArray<parser::EnumVariantPatternArgument>::create_with({}))));
JaktInternal::Optional<NonnullRefPtr<typename parser::ParsedExpression>> unary_operator_is = JaktInternal::OptionalNone();
if ((((((*this).current())).index() == 8 /* LParen */) && (((parsed_type)->index() == 1 /* NamespacedName */) || ((parsed_type)->index() == 0 /* Name */)))){
(bindings = TRY((((*this).parse_variant_arguments()))));
(unary_operator_is = TRY((parser::ParsedExpression::template create<typename parser::ParsedExpression::UnaryOp>(result, parser::UnaryOperator { typename parser::UnaryOperator::IsEnumVariant(parsed_type,bindings) } ,span))));
}
else {
(unary_operator_is = TRY((parser::ParsedExpression::template create<typename parser::ParsedExpression::UnaryOp>(result, parser::UnaryOperator { typename parser::UnaryOperator::Is(parsed_type) } ,span))));
}

__jakt_var_47 = (unary_operator_is.value()); goto __jakt_label_44;

}
__jakt_label_44:; __jakt_var_47.release_value(); }));
};/*case end*/
case 7: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::ColonColon>();
return JaktInternal::ExplicitValue(TRY((((*this).parse_postfix_colon_colon(start,result)))));
};/*case end*/
case 50: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::QuestionMark>();
return JaktInternal::ExplicitValue(({ Optional<NonnullRefPtr<typename parser::ParsedExpression>> __jakt_var_48; {
bool const is_optional = ((((*this).current())).index() == 50 /* QuestionMark */);
if (is_optional){
((((*this).index)++));
if ((!(((((*this).current())).index() == 54 /* Dot */)))){
TRY((((*this).error(Jakt::DeprecatedString("Expected ‘.’ after ‘?’ for optional chaining access"sv),((((*this).current())).span())))));
}
}
((((*this).index)++));
__jakt_var_48 = JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_AT_LOOP_NESTED_MATCH(([&]() -> JaktInternal::ExplicitValueOrControlFlow<NonnullRefPtr<typename parser::ParsedExpression>, ErrorOr<NonnullRefPtr<typename parser::ParsedExpression>>>{
auto&& __jakt_match_variant = ((*this).current());
switch(__jakt_match_variant.index()) {
case 3: {
auto&& __jakt_match_value = __jakt_match_variant.template get<lexer::Token::Number>();lexer::LiteralPrefix const& prefix = __jakt_match_value.prefix;
DeprecatedString const& number = __jakt_match_value.number;
lexer::LiteralSuffix const& suffix = __jakt_match_value.suffix;
utility::Span const& span = __jakt_match_value.span;
return JaktInternal::ExplicitValue(({ Optional<NonnullRefPtr<typename parser::ParsedExpression>> __jakt_var_49; {
NonnullRefPtr<typename parser::ParsedExpression> const numeric_constant = TRY((((*this).parse_number(prefix,number,suffix,span))));
__jakt_var_49 = JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_AT_LOOP_NESTED_MATCH(([&]() -> JaktInternal::ExplicitValueOrControlFlow<NonnullRefPtr<typename parser::ParsedExpression>,ErrorOr<NonnullRefPtr<typename parser::ParsedExpression>>>{
auto __jakt_enum_value = (((numeric_constant)->index() == 1 /* NumericConstant */));
if (__jakt_enum_value == true) {
return JaktInternal::ExplicitValue(({ Optional<NonnullRefPtr<typename parser::ParsedExpression>> __jakt_var_50; {
parser::NumericConstant const val = ((numeric_constant)->get<parser::ParsedExpression::NumericConstant>()).val;
size_t const num = ((val).to_usize());
__jakt_var_50 = TRY((parser::ParsedExpression::template create<typename parser::ParsedExpression::IndexedTuple>(result,num,is_optional,TRY((parser::merge_spans(start,((((*this).previous())).span()))))))); goto __jakt_label_47;

}
__jakt_label_47:; __jakt_var_50.release_value(); }));
}
else {
{
TRY((((*this).error(Jakt::DeprecatedString("Invalid Numeric Constant"sv),span))));
return (expr);
}
}
}()))
; goto __jakt_label_46;

}
__jakt_label_46:; __jakt_var_49.release_value(); }));
};/*case end*/
case 4: {
auto&& __jakt_match_value = __jakt_match_variant.template get<lexer::Token::Identifier>();DeprecatedString const& name = __jakt_match_value.name;
return JaktInternal::ExplicitValue(({ Optional<NonnullRefPtr<typename parser::ParsedExpression>> __jakt_var_51; {
((((*this).index)++));
__jakt_var_51 = JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_AT_LOOP_NESTED_MATCH(([&]() -> JaktInternal::ExplicitValueOrControlFlow<NonnullRefPtr<typename parser::ParsedExpression>, ErrorOr<NonnullRefPtr<typename parser::ParsedExpression>>>{
auto&& __jakt_match_variant = ((*this).current());
switch(__jakt_match_variant.index()) {
case 29: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::LessThan>();
return JaktInternal::ExplicitValue(({ Optional<NonnullRefPtr<typename parser::ParsedExpression>> __jakt_var_52; {
size_t const original_index = ((*this).index);
JaktInternal::DynamicArray<error::JaktError> const existing_errors = TRY((((((((((*this).compiler))->errors))[(JaktInternal::Range<i64>{static_cast<i64>(0LL),static_cast<i64>(9223372036854775807LL)})])).to_array())));
((((*this).index)--));
JaktInternal::Optional<parser::ParsedCall> const call = TRY((((*this).parse_call())));
__jakt_var_52 = JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_AT_LOOP_NESTED_MATCH(([&]() -> JaktInternal::ExplicitValueOrControlFlow<NonnullRefPtr<typename parser::ParsedExpression>,ErrorOr<NonnullRefPtr<typename parser::ParsedExpression>>>{
auto __jakt_enum_value = (((call).has_value()));
if (__jakt_enum_value == true) {
return JaktInternal::ExplicitValue(TRY((parser::ParsedExpression::template create<typename parser::ParsedExpression::MethodCall>(result,(call.value()),is_optional,TRY((parser::merge_spans(start,((((*this).previous())).span()))))))));
}
else {
return JaktInternal::ExplicitValue(({ Optional<NonnullRefPtr<typename parser::ParsedExpression>> __jakt_var_53; {
(((*this).index) = original_index);
(((((*this).compiler))->errors) = existing_errors);
__jakt_var_53 = TRY((parser::ParsedExpression::template create<typename parser::ParsedExpression::IndexedStruct>(result,name,is_optional,TRY((parser::merge_spans(start,((((*this).current())).span()))))))); goto __jakt_label_50;

}
__jakt_label_50:; __jakt_var_53.release_value(); }));
}
}()))
; goto __jakt_label_49;

}
__jakt_label_49:; __jakt_var_52.release_value(); }));
};/*case end*/
case 8: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::LParen>();
return JaktInternal::ExplicitValue(({ Optional<NonnullRefPtr<typename parser::ParsedExpression>> __jakt_var_54; {
((((*this).index)--));
JaktInternal::Optional<parser::ParsedCall> const call = TRY((((*this).parse_call())));
__jakt_var_54 = TRY((parser::ParsedExpression::template create<typename parser::ParsedExpression::MethodCall>(result,(call.value()),is_optional,TRY((parser::merge_spans(start,((((*this).previous())).span()))))))); goto __jakt_label_51;

}
__jakt_label_51:; __jakt_var_54.release_value(); }));
};/*case end*/
default: {
return JaktInternal::ExplicitValue(TRY((parser::ParsedExpression::template create<typename parser::ParsedExpression::IndexedStruct>(result,name,is_optional,TRY((parser::merge_spans(start,((((*this).current())).span()))))))));
};/*case end*/
}/*switch end*/
}()
)); goto __jakt_label_48;

}
__jakt_label_48:; __jakt_var_51.release_value(); }));
};/*case end*/
default: {
return JaktInternal::ExplicitValue(({ Optional<NonnullRefPtr<typename parser::ParsedExpression>> __jakt_var_55; {
TRY((((*this).error(Jakt::DeprecatedString("Unsupported dot operation"sv),((((*this).current())).span())))));
((((*this).index)++));
__jakt_var_55 = result; goto __jakt_label_52;

}
__jakt_label_52:; __jakt_var_55.release_value(); }));
};/*case end*/
}/*switch end*/
}()
)); goto __jakt_label_45;

}
__jakt_label_45:; __jakt_var_48.release_value(); }));
};/*case end*/
case 54: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::Dot>();
return JaktInternal::ExplicitValue(({ Optional<NonnullRefPtr<typename parser::ParsedExpression>> __jakt_var_56; {
bool const is_optional = ((((*this).current())).index() == 50 /* QuestionMark */);
if (is_optional){
((((*this).index)++));
if ((!(((((*this).current())).index() == 54 /* Dot */)))){
TRY((((*this).error(Jakt::DeprecatedString("Expected ‘.’ after ‘?’ for optional chaining access"sv),((((*this).current())).span())))));
}
}
((((*this).index)++));
__jakt_var_56 = JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_AT_LOOP_NESTED_MATCH(([&]() -> JaktInternal::ExplicitValueOrControlFlow<NonnullRefPtr<typename parser::ParsedExpression>, ErrorOr<NonnullRefPtr<typename parser::ParsedExpression>>>{
auto&& __jakt_match_variant = ((*this).current());
switch(__jakt_match_variant.index()) {
case 3: {
auto&& __jakt_match_value = __jakt_match_variant.template get<lexer::Token::Number>();lexer::LiteralPrefix const& prefix = __jakt_match_value.prefix;
DeprecatedString const& number = __jakt_match_value.number;
lexer::LiteralSuffix const& suffix = __jakt_match_value.suffix;
utility::Span const& span = __jakt_match_value.span;
return JaktInternal::ExplicitValue(({ Optional<NonnullRefPtr<typename parser::ParsedExpression>> __jakt_var_57; {
NonnullRefPtr<typename parser::ParsedExpression> const numeric_constant = TRY((((*this).parse_number(prefix,number,suffix,span))));
__jakt_var_57 = JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_AT_LOOP_NESTED_MATCH(([&]() -> JaktInternal::ExplicitValueOrControlFlow<NonnullRefPtr<typename parser::ParsedExpression>,ErrorOr<NonnullRefPtr<typename parser::ParsedExpression>>>{
auto __jakt_enum_value = (((numeric_constant)->index() == 1 /* NumericConstant */));
if (__jakt_enum_value == true) {
return JaktInternal::ExplicitValue(({ Optional<NonnullRefPtr<typename parser::ParsedExpression>> __jakt_var_58; {
parser::NumericConstant const val = ((numeric_constant)->get<parser::ParsedExpression::NumericConstant>()).val;
size_t const num = ((val).to_usize());
__jakt_var_58 = TRY((parser::ParsedExpression::template create<typename parser::ParsedExpression::IndexedTuple>(result,num,is_optional,TRY((parser::merge_spans(start,((((*this).previous())).span()))))))); goto __jakt_label_55;

}
__jakt_label_55:; __jakt_var_58.release_value(); }));
}
else {
{
TRY((((*this).error(Jakt::DeprecatedString("Invalid Numeric Constant"sv),span))));
return (expr);
}
}
}()))
; goto __jakt_label_54;

}
__jakt_label_54:; __jakt_var_57.release_value(); }));
};/*case end*/
case 4: {
auto&& __jakt_match_value = __jakt_match_variant.template get<lexer::Token::Identifier>();DeprecatedString const& name = __jakt_match_value.name;
return JaktInternal::ExplicitValue(({ Optional<NonnullRefPtr<typename parser::ParsedExpression>> __jakt_var_59; {
((((*this).index)++));
__jakt_var_59 = JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_AT_LOOP_NESTED_MATCH(([&]() -> JaktInternal::ExplicitValueOrControlFlow<NonnullRefPtr<typename parser::ParsedExpression>, ErrorOr<NonnullRefPtr<typename parser::ParsedExpression>>>{
auto&& __jakt_match_variant = ((*this).current());
switch(__jakt_match_variant.index()) {
case 29: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::LessThan>();
return JaktInternal::ExplicitValue(({ Optional<NonnullRefPtr<typename parser::ParsedExpression>> __jakt_var_60; {
size_t const original_index = ((*this).index);
JaktInternal::DynamicArray<error::JaktError> const existing_errors = TRY((((((((((*this).compiler))->errors))[(JaktInternal::Range<i64>{static_cast<i64>(0LL),static_cast<i64>(9223372036854775807LL)})])).to_array())));
((((*this).index)--));
JaktInternal::Optional<parser::ParsedCall> const call = TRY((((*this).parse_call())));
__jakt_var_60 = JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_AT_LOOP_NESTED_MATCH(([&]() -> JaktInternal::ExplicitValueOrControlFlow<NonnullRefPtr<typename parser::ParsedExpression>,ErrorOr<NonnullRefPtr<typename parser::ParsedExpression>>>{
auto __jakt_enum_value = (((call).has_value()));
if (__jakt_enum_value == true) {
return JaktInternal::ExplicitValue(TRY((parser::ParsedExpression::template create<typename parser::ParsedExpression::MethodCall>(result,(call.value()),is_optional,TRY((parser::merge_spans(start,((((*this).previous())).span()))))))));
}
else {
return JaktInternal::ExplicitValue(({ Optional<NonnullRefPtr<typename parser::ParsedExpression>> __jakt_var_61; {
(((*this).index) = original_index);
(((((*this).compiler))->errors) = existing_errors);
__jakt_var_61 = TRY((parser::ParsedExpression::template create<typename parser::ParsedExpression::IndexedStruct>(result,name,is_optional,TRY((parser::merge_spans(start,((((*this).current())).span()))))))); goto __jakt_label_58;

}
__jakt_label_58:; __jakt_var_61.release_value(); }));
}
}()))
; goto __jakt_label_57;

}
__jakt_label_57:; __jakt_var_60.release_value(); }));
};/*case end*/
case 8: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::LParen>();
return JaktInternal::ExplicitValue(({ Optional<NonnullRefPtr<typename parser::ParsedExpression>> __jakt_var_62; {
((((*this).index)--));
JaktInternal::Optional<parser::ParsedCall> const call = TRY((((*this).parse_call())));
__jakt_var_62 = TRY((parser::ParsedExpression::template create<typename parser::ParsedExpression::MethodCall>(result,(call.value()),is_optional,TRY((parser::merge_spans(start,((((*this).previous())).span()))))))); goto __jakt_label_59;

}
__jakt_label_59:; __jakt_var_62.release_value(); }));
};/*case end*/
default: {
return JaktInternal::ExplicitValue(TRY((parser::ParsedExpression::template create<typename parser::ParsedExpression::IndexedStruct>(result,name,is_optional,TRY((parser::merge_spans(start,((((*this).current())).span()))))))));
};/*case end*/
}/*switch end*/
}()
)); goto __jakt_label_56;

}
__jakt_label_56:; __jakt_var_59.release_value(); }));
};/*case end*/
default: {
return JaktInternal::ExplicitValue(({ Optional<NonnullRefPtr<typename parser::ParsedExpression>> __jakt_var_63; {
TRY((((*this).error(Jakt::DeprecatedString("Unsupported dot operation"sv),((((*this).current())).span())))));
((((*this).index)++));
__jakt_var_63 = result; goto __jakt_label_60;

}
__jakt_label_60:; __jakt_var_63.release_value(); }));
};/*case end*/
}/*switch end*/
}()
)); goto __jakt_label_53;

}
__jakt_label_53:; __jakt_var_56.release_value(); }));
};/*case end*/
case 12: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::LSquare>();
return JaktInternal::ExplicitValue(({ Optional<NonnullRefPtr<typename parser::ParsedExpression>> __jakt_var_64; {
((((*this).index)++));
NonnullRefPtr<typename parser::ParsedExpression> const index_expr = TRY((((*this).parse_expression(false,false))));
if (((((*this).current())).index() == 13 /* RSquare */)){
((((*this).index)++));
}
else {
TRY((((*this).error(Jakt::DeprecatedString("Expected ']'"sv),((((*this).current())).span())))));
}

size_t const end = (JaktInternal::checked_sub<size_t>(((*this).index),static_cast<size_t>(1ULL)));
__jakt_var_64 = TRY((parser::ParsedExpression::template create<typename parser::ParsedExpression::IndexedExpression>(result,index_expr,TRY((parser::merge_spans(start,((((((*this).tokens))[end])).span()))))))); goto __jakt_label_61;

}
__jakt_label_61:; __jakt_var_64.release_value(); }));
};/*case end*/
default: {
{
return JaktInternal::LoopBreak{};
}
};/*case end*/
}/*switch end*/
}()
)));
}
return (result);
}
}

ErrorOr<JaktInternal::DynamicArray<parser::ParsedGenericParameter>> parser::Parser::parse_generic_parameters() {
{
if ((!(((((*this).current())).index() == 29 /* LessThan */)))){
return ((TRY((DynamicArray<parser::ParsedGenericParameter>::create_with({})))));
}
((((*this).index)++));
JaktInternal::DynamicArray<parser::ParsedGenericParameter> generic_parameters = (TRY((DynamicArray<parser::ParsedGenericParameter>::create_with({}))));
((*this).skip_newlines());
bool saw_ending_bracket = false;
while ((!(((*this).eof())))){
JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_AT_LOOP(([&]() -> JaktInternal::ExplicitValueOrControlFlow<void, ErrorOr<JaktInternal::DynamicArray<parser::ParsedGenericParameter>>>{
auto&& __jakt_match_variant = ((*this).current());
switch(__jakt_match_variant.index()) {
case 4: {
auto&& __jakt_match_value = __jakt_match_variant.template get<lexer::Token::Identifier>();DeprecatedString const& name = __jakt_match_value.name;
utility::Span const& span = __jakt_match_value.span;
{
JaktInternal::Optional<JaktInternal::DynamicArray<parser::ParsedNameWithGenericParameters>> requires_list = JaktInternal::OptionalNone();
((((*this).index)++));
if (((((*this).current())).index() == 107 /* Requires */)){
((((*this).index)++));
(requires_list = TRY((((*this).parse_trait_list()))));
}
TRY((((generic_parameters).push(parser::ParsedGenericParameter(name,span,requires_list)))));
if ((((((*this).current())).index() == 53 /* Comma */) || ((((*this).current())).index() == 56 /* Eol */))){
((((*this).index)++));
}
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 27: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::GreaterThan>();
{
((((*this).index)++));
(saw_ending_bracket = true);
return JaktInternal::LoopBreak{};
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 34: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::RightShift>();
{
TRY((((*this).inject_token( lexer::Token { typename lexer::Token::GreaterThan(((((*this).current())).span())) } ))));
({auto& _jakt_ref = ((*this).index);_jakt_ref = JaktInternal::checked_add<size_t>(_jakt_ref, static_cast<size_t>(1ULL));});
(saw_ending_bracket = true);
return JaktInternal::LoopBreak{};
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 109: {
auto&& __jakt_match_value = __jakt_match_variant.template get<lexer::Token::Garbage>();{
TRY((((*this).error(Jakt::DeprecatedString("Expected `>` to end the generic parameters"sv),((((*this).current())).span())))));
return (generic_parameters);
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
default: {
{
TRY((((*this).error(Jakt::DeprecatedString("Expected generic parameter name"sv),((((*this).current())).span())))));
return (generic_parameters);
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
}/*switch end*/
}()
));
}
if ((!(saw_ending_bracket))){
TRY((((*this).error(Jakt::DeprecatedString("Expected `>` to end the generic parameters"sv),((((*this).current())).span())))));
return (generic_parameters);
}
return (generic_parameters);
}
}

ErrorOr<parser::ParsedMethod> parser::Parser::parse_method(parser::FunctionLinkage const linkage,parser::Visibility const visibility,bool const is_virtual,bool const is_override,bool const is_comptime) {
{
parser::ParsedFunction parsed_function = TRY((((*this).parse_function(linkage,visibility,is_comptime,false))));
if (((linkage).index() == 1 /* External */)){
(((parsed_function).must_instantiate) = true);
}
return (parser::ParsedMethod(parsed_function,visibility,is_virtual,is_override));
}
}

ErrorOr<parser::ParsedExternalTraitImplementation> parser::Parser::parse_external_trait_implementation() {
{
NonnullRefPtr<typename parser::ParsedType> const type_name = TRY((((*this).parse_typename())));
((*this).skip_newlines());
if (((((*this).current())).index() == 106 /* Implements */)){
((((*this).index)++));
}
else {
TRY((((*this).error(Jakt::DeprecatedString("Expected ‘implements’"sv),((((*this).current())).span())))));
}

JaktInternal::Optional<JaktInternal::DynamicArray<parser::ParsedNameWithGenericParameters>> const trait_list = TRY((((*this).parse_trait_list())));
if ((!(((trait_list).has_value())))){
TRY((((*this).error(Jakt::DeprecatedString("Expected non-empty trait list"sv),((((*this).current())).span())))));
return (parser::ParsedExternalTraitImplementation(type_name,(TRY((DynamicArray<parser::ParsedNameWithGenericParameters>::create_with({})))),(TRY((DynamicArray<parser::ParsedMethod>::create_with({}))))));
}
((*this).skip_newlines());
if (((((*this).current())).index() == 10 /* LCurly */)){
JaktInternal::Tuple<JaktInternal::DynamicArray<parser::ParsedField>,JaktInternal::DynamicArray<parser::ParsedMethod>> const fields_methods_ = TRY((((*this).parse_struct_class_body( parser::DefinitionLinkage { typename parser::DefinitionLinkage::Internal() } , parser::Visibility { typename parser::Visibility::Public() } ,false))));
JaktInternal::DynamicArray<parser::ParsedField> const fields = ((fields_methods_).template get<0>());
JaktInternal::DynamicArray<parser::ParsedMethod> const methods = ((fields_methods_).template get<1>());

if ((!(((fields).is_empty())))){
TRY((((*this).error(Jakt::DeprecatedString("External trait implementations cannot have fields"sv),((((((fields)[static_cast<i64>(0LL)])).var_decl)).span)))));
}
return (parser::ParsedExternalTraitImplementation(type_name,(trait_list.value()),methods));
}
else {
TRY((((*this).error(Jakt::DeprecatedString("Expected ‘{’"sv),((((*this).current())).span())))));
return (parser::ParsedExternalTraitImplementation(type_name,(trait_list.value()),(TRY((DynamicArray<parser::ParsedMethod>::create_with({}))))));
}

}
}

ErrorOr<DeprecatedString> parser::Parser::parse_argument_label() {
{
if ((((((*this).peek(static_cast<size_t>(1ULL)))).index() == 6 /* Colon */) && ((((*this).current())).index() == 4 /* Identifier */))){
DeprecatedString const name = ((((*this).current())).get<lexer::Token::Identifier>()).name;
({auto& _jakt_ref = ((*this).index);_jakt_ref = JaktInternal::checked_add<size_t>(_jakt_ref, static_cast<size_t>(2ULL));});
return (name);
}
return (Jakt::DeprecatedString(""sv));
}
}

ErrorOr<parser::ParsedTrait> parser::Parser::parse_trait() {
{
parser::ParsedTrait parsed_trait = parser::ParsedTrait(Jakt::DeprecatedString(""sv),((*this).empty_span()),(TRY((DynamicArray<parser::ParsedGenericParameter>::create_with({})))),(TRY((DynamicArray<parser::ParsedFunction>::create_with({})))));
if (((((*this).current())).index() == 4 /* Identifier */)){
DeprecatedString const name = ((((*this).current())).get<lexer::Token::Identifier>()).name;
utility::Span const name_span = ((((*this).current())).get<lexer::Token::Identifier>()).span;
(((parsed_trait).name) = name);
(((parsed_trait).name_span) = name_span);
((((*this).index)++));
if (((((*this).current())).index() == 29 /* LessThan */)){
(((parsed_trait).generic_parameters) = TRY((((*this).parse_generic_parameters()))));
}
if (((((*this).current())).index() == 10 /* LCurly */)){
((((*this).index)++));
for (;;){
JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_AT_LOOP(([&]() -> JaktInternal::ExplicitValueOrControlFlow<void, ErrorOr<parser::ParsedTrait>>{
auto&& __jakt_match_variant = ((*this).current());
switch(__jakt_match_variant.index()) {
case 11: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::RCurly>();
{
((((*this).index)++));
return JaktInternal::LoopBreak{};
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 57: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::Eof>();
utility::Span const& span = __jakt_match_value.value;
{
TRY((((*this).error(Jakt::DeprecatedString("Expected '}' to close the trait body"sv),span))));
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 56: {
auto&& __jakt_match_value = __jakt_match_variant.template get<lexer::Token::Eol>();{
((((*this).index)++));
return JaktInternal::LoopContinue{};
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 75: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::Function>();
{
parser::ParsedFunction method = TRY((((*this).parse_function( parser::FunctionLinkage { typename parser::FunctionLinkage::Internal() } , parser::Visibility { typename parser::Visibility::Public() } ,false,true))));
if (((((((method).block)).stmts)).is_empty())){
(((method).linkage) =  parser::FunctionLinkage { typename parser::FunctionLinkage::External() } );
}
TRY((((((parsed_trait).methods)).push(method))));
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 0: {
auto&& __jakt_match_value = __jakt_match_variant.template get<lexer::Token::SingleQuotedString>();utility::Span const& span = __jakt_match_value.span;
{
TRY((((*this).error_with_hint(Jakt::DeprecatedString("Expected 'function' keyword inside trait definition"sv),span,TRY((__jakt_format(Jakt::DeprecatedString("Inside '{}' trait's definition only function declarations can appear"sv),((parsed_trait).name)))),((parsed_trait).name_span)))));
return (parsed_trait);
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 1: {
auto&& __jakt_match_value = __jakt_match_variant.template get<lexer::Token::SingleQuotedByteString>();utility::Span const& span = __jakt_match_value.span;
{
TRY((((*this).error_with_hint(Jakt::DeprecatedString("Expected 'function' keyword inside trait definition"sv),span,TRY((__jakt_format(Jakt::DeprecatedString("Inside '{}' trait's definition only function declarations can appear"sv),((parsed_trait).name)))),((parsed_trait).name_span)))));
return (parsed_trait);
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 2: {
auto&& __jakt_match_value = __jakt_match_variant.template get<lexer::Token::QuotedString>();utility::Span const& span = __jakt_match_value.span;
{
TRY((((*this).error_with_hint(Jakt::DeprecatedString("Expected 'function' keyword inside trait definition"sv),span,TRY((__jakt_format(Jakt::DeprecatedString("Inside '{}' trait's definition only function declarations can appear"sv),((parsed_trait).name)))),((parsed_trait).name_span)))));
return (parsed_trait);
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 3: {
auto&& __jakt_match_value = __jakt_match_variant.template get<lexer::Token::Number>();utility::Span const& span = __jakt_match_value.span;
{
TRY((((*this).error_with_hint(Jakt::DeprecatedString("Expected 'function' keyword inside trait definition"sv),span,TRY((__jakt_format(Jakt::DeprecatedString("Inside '{}' trait's definition only function declarations can appear"sv),((parsed_trait).name)))),((parsed_trait).name_span)))));
return (parsed_trait);
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 4: {
auto&& __jakt_match_value = __jakt_match_variant.template get<lexer::Token::Identifier>();utility::Span const& span = __jakt_match_value.span;
{
TRY((((*this).error_with_hint(Jakt::DeprecatedString("Expected 'function' keyword inside trait definition"sv),span,TRY((__jakt_format(Jakt::DeprecatedString("Inside '{}' trait's definition only function declarations can appear"sv),((parsed_trait).name)))),((parsed_trait).name_span)))));
return (parsed_trait);
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 5: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::Semicolon>();
utility::Span const& span = __jakt_match_value.value;
{
TRY((((*this).error_with_hint(Jakt::DeprecatedString("Expected 'function' keyword inside trait definition"sv),span,TRY((__jakt_format(Jakt::DeprecatedString("Inside '{}' trait's definition only function declarations can appear"sv),((parsed_trait).name)))),((parsed_trait).name_span)))));
return (parsed_trait);
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 6: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::Colon>();
utility::Span const& span = __jakt_match_value.value;
{
TRY((((*this).error_with_hint(Jakt::DeprecatedString("Expected 'function' keyword inside trait definition"sv),span,TRY((__jakt_format(Jakt::DeprecatedString("Inside '{}' trait's definition only function declarations can appear"sv),((parsed_trait).name)))),((parsed_trait).name_span)))));
return (parsed_trait);
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 7: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::ColonColon>();
utility::Span const& span = __jakt_match_value.value;
{
TRY((((*this).error_with_hint(Jakt::DeprecatedString("Expected 'function' keyword inside trait definition"sv),span,TRY((__jakt_format(Jakt::DeprecatedString("Inside '{}' trait's definition only function declarations can appear"sv),((parsed_trait).name)))),((parsed_trait).name_span)))));
return (parsed_trait);
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 8: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::LParen>();
utility::Span const& span = __jakt_match_value.value;
{
TRY((((*this).error_with_hint(Jakt::DeprecatedString("Expected 'function' keyword inside trait definition"sv),span,TRY((__jakt_format(Jakt::DeprecatedString("Inside '{}' trait's definition only function declarations can appear"sv),((parsed_trait).name)))),((parsed_trait).name_span)))));
return (parsed_trait);
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 9: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::RParen>();
utility::Span const& span = __jakt_match_value.value;
{
TRY((((*this).error_with_hint(Jakt::DeprecatedString("Expected 'function' keyword inside trait definition"sv),span,TRY((__jakt_format(Jakt::DeprecatedString("Inside '{}' trait's definition only function declarations can appear"sv),((parsed_trait).name)))),((parsed_trait).name_span)))));
return (parsed_trait);
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 10: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::LCurly>();
utility::Span const& span = __jakt_match_value.value;
{
TRY((((*this).error_with_hint(Jakt::DeprecatedString("Expected 'function' keyword inside trait definition"sv),span,TRY((__jakt_format(Jakt::DeprecatedString("Inside '{}' trait's definition only function declarations can appear"sv),((parsed_trait).name)))),((parsed_trait).name_span)))));
return (parsed_trait);
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 12: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::LSquare>();
utility::Span const& span = __jakt_match_value.value;
{
TRY((((*this).error_with_hint(Jakt::DeprecatedString("Expected 'function' keyword inside trait definition"sv),span,TRY((__jakt_format(Jakt::DeprecatedString("Inside '{}' trait's definition only function declarations can appear"sv),((parsed_trait).name)))),((parsed_trait).name_span)))));
return (parsed_trait);
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 13: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::RSquare>();
utility::Span const& span = __jakt_match_value.value;
{
TRY((((*this).error_with_hint(Jakt::DeprecatedString("Expected 'function' keyword inside trait definition"sv),span,TRY((__jakt_format(Jakt::DeprecatedString("Inside '{}' trait's definition only function declarations can appear"sv),((parsed_trait).name)))),((parsed_trait).name_span)))));
return (parsed_trait);
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 14: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::PercentSign>();
utility::Span const& span = __jakt_match_value.value;
{
TRY((((*this).error_with_hint(Jakt::DeprecatedString("Expected 'function' keyword inside trait definition"sv),span,TRY((__jakt_format(Jakt::DeprecatedString("Inside '{}' trait's definition only function declarations can appear"sv),((parsed_trait).name)))),((parsed_trait).name_span)))));
return (parsed_trait);
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 15: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::Plus>();
utility::Span const& span = __jakt_match_value.value;
{
TRY((((*this).error_with_hint(Jakt::DeprecatedString("Expected 'function' keyword inside trait definition"sv),span,TRY((__jakt_format(Jakt::DeprecatedString("Inside '{}' trait's definition only function declarations can appear"sv),((parsed_trait).name)))),((parsed_trait).name_span)))));
return (parsed_trait);
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 16: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::Minus>();
utility::Span const& span = __jakt_match_value.value;
{
TRY((((*this).error_with_hint(Jakt::DeprecatedString("Expected 'function' keyword inside trait definition"sv),span,TRY((__jakt_format(Jakt::DeprecatedString("Inside '{}' trait's definition only function declarations can appear"sv),((parsed_trait).name)))),((parsed_trait).name_span)))));
return (parsed_trait);
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 17: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::Equal>();
utility::Span const& span = __jakt_match_value.value;
{
TRY((((*this).error_with_hint(Jakt::DeprecatedString("Expected 'function' keyword inside trait definition"sv),span,TRY((__jakt_format(Jakt::DeprecatedString("Inside '{}' trait's definition only function declarations can appear"sv),((parsed_trait).name)))),((parsed_trait).name_span)))));
return (parsed_trait);
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 18: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::PlusEqual>();
utility::Span const& span = __jakt_match_value.value;
{
TRY((((*this).error_with_hint(Jakt::DeprecatedString("Expected 'function' keyword inside trait definition"sv),span,TRY((__jakt_format(Jakt::DeprecatedString("Inside '{}' trait's definition only function declarations can appear"sv),((parsed_trait).name)))),((parsed_trait).name_span)))));
return (parsed_trait);
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 19: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::PlusPlus>();
utility::Span const& span = __jakt_match_value.value;
{
TRY((((*this).error_with_hint(Jakt::DeprecatedString("Expected 'function' keyword inside trait definition"sv),span,TRY((__jakt_format(Jakt::DeprecatedString("Inside '{}' trait's definition only function declarations can appear"sv),((parsed_trait).name)))),((parsed_trait).name_span)))));
return (parsed_trait);
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 20: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::MinusEqual>();
utility::Span const& span = __jakt_match_value.value;
{
TRY((((*this).error_with_hint(Jakt::DeprecatedString("Expected 'function' keyword inside trait definition"sv),span,TRY((__jakt_format(Jakt::DeprecatedString("Inside '{}' trait's definition only function declarations can appear"sv),((parsed_trait).name)))),((parsed_trait).name_span)))));
return (parsed_trait);
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 21: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::MinusMinus>();
utility::Span const& span = __jakt_match_value.value;
{
TRY((((*this).error_with_hint(Jakt::DeprecatedString("Expected 'function' keyword inside trait definition"sv),span,TRY((__jakt_format(Jakt::DeprecatedString("Inside '{}' trait's definition only function declarations can appear"sv),((parsed_trait).name)))),((parsed_trait).name_span)))));
return (parsed_trait);
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 22: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::AsteriskEqual>();
utility::Span const& span = __jakt_match_value.value;
{
TRY((((*this).error_with_hint(Jakt::DeprecatedString("Expected 'function' keyword inside trait definition"sv),span,TRY((__jakt_format(Jakt::DeprecatedString("Inside '{}' trait's definition only function declarations can appear"sv),((parsed_trait).name)))),((parsed_trait).name_span)))));
return (parsed_trait);
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 23: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::ForwardSlashEqual>();
utility::Span const& span = __jakt_match_value.value;
{
TRY((((*this).error_with_hint(Jakt::DeprecatedString("Expected 'function' keyword inside trait definition"sv),span,TRY((__jakt_format(Jakt::DeprecatedString("Inside '{}' trait's definition only function declarations can appear"sv),((parsed_trait).name)))),((parsed_trait).name_span)))));
return (parsed_trait);
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 24: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::PercentSignEqual>();
utility::Span const& span = __jakt_match_value.value;
{
TRY((((*this).error_with_hint(Jakt::DeprecatedString("Expected 'function' keyword inside trait definition"sv),span,TRY((__jakt_format(Jakt::DeprecatedString("Inside '{}' trait's definition only function declarations can appear"sv),((parsed_trait).name)))),((parsed_trait).name_span)))));
return (parsed_trait);
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 25: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::NotEqual>();
utility::Span const& span = __jakt_match_value.value;
{
TRY((((*this).error_with_hint(Jakt::DeprecatedString("Expected 'function' keyword inside trait definition"sv),span,TRY((__jakt_format(Jakt::DeprecatedString("Inside '{}' trait's definition only function declarations can appear"sv),((parsed_trait).name)))),((parsed_trait).name_span)))));
return (parsed_trait);
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 26: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::DoubleEqual>();
utility::Span const& span = __jakt_match_value.value;
{
TRY((((*this).error_with_hint(Jakt::DeprecatedString("Expected 'function' keyword inside trait definition"sv),span,TRY((__jakt_format(Jakt::DeprecatedString("Inside '{}' trait's definition only function declarations can appear"sv),((parsed_trait).name)))),((parsed_trait).name_span)))));
return (parsed_trait);
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 27: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::GreaterThan>();
utility::Span const& span = __jakt_match_value.value;
{
TRY((((*this).error_with_hint(Jakt::DeprecatedString("Expected 'function' keyword inside trait definition"sv),span,TRY((__jakt_format(Jakt::DeprecatedString("Inside '{}' trait's definition only function declarations can appear"sv),((parsed_trait).name)))),((parsed_trait).name_span)))));
return (parsed_trait);
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 28: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::GreaterThanOrEqual>();
utility::Span const& span = __jakt_match_value.value;
{
TRY((((*this).error_with_hint(Jakt::DeprecatedString("Expected 'function' keyword inside trait definition"sv),span,TRY((__jakt_format(Jakt::DeprecatedString("Inside '{}' trait's definition only function declarations can appear"sv),((parsed_trait).name)))),((parsed_trait).name_span)))));
return (parsed_trait);
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 29: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::LessThan>();
utility::Span const& span = __jakt_match_value.value;
{
TRY((((*this).error_with_hint(Jakt::DeprecatedString("Expected 'function' keyword inside trait definition"sv),span,TRY((__jakt_format(Jakt::DeprecatedString("Inside '{}' trait's definition only function declarations can appear"sv),((parsed_trait).name)))),((parsed_trait).name_span)))));
return (parsed_trait);
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 30: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::LessThanOrEqual>();
utility::Span const& span = __jakt_match_value.value;
{
TRY((((*this).error_with_hint(Jakt::DeprecatedString("Expected 'function' keyword inside trait definition"sv),span,TRY((__jakt_format(Jakt::DeprecatedString("Inside '{}' trait's definition only function declarations can appear"sv),((parsed_trait).name)))),((parsed_trait).name_span)))));
return (parsed_trait);
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 31: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::LeftArithmeticShift>();
utility::Span const& span = __jakt_match_value.value;
{
TRY((((*this).error_with_hint(Jakt::DeprecatedString("Expected 'function' keyword inside trait definition"sv),span,TRY((__jakt_format(Jakt::DeprecatedString("Inside '{}' trait's definition only function declarations can appear"sv),((parsed_trait).name)))),((parsed_trait).name_span)))));
return (parsed_trait);
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 32: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::LeftShift>();
utility::Span const& span = __jakt_match_value.value;
{
TRY((((*this).error_with_hint(Jakt::DeprecatedString("Expected 'function' keyword inside trait definition"sv),span,TRY((__jakt_format(Jakt::DeprecatedString("Inside '{}' trait's definition only function declarations can appear"sv),((parsed_trait).name)))),((parsed_trait).name_span)))));
return (parsed_trait);
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 33: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::LeftShiftEqual>();
utility::Span const& span = __jakt_match_value.value;
{
TRY((((*this).error_with_hint(Jakt::DeprecatedString("Expected 'function' keyword inside trait definition"sv),span,TRY((__jakt_format(Jakt::DeprecatedString("Inside '{}' trait's definition only function declarations can appear"sv),((parsed_trait).name)))),((parsed_trait).name_span)))));
return (parsed_trait);
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 34: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::RightShift>();
utility::Span const& span = __jakt_match_value.value;
{
TRY((((*this).error_with_hint(Jakt::DeprecatedString("Expected 'function' keyword inside trait definition"sv),span,TRY((__jakt_format(Jakt::DeprecatedString("Inside '{}' trait's definition only function declarations can appear"sv),((parsed_trait).name)))),((parsed_trait).name_span)))));
return (parsed_trait);
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 35: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::RightArithmeticShift>();
utility::Span const& span = __jakt_match_value.value;
{
TRY((((*this).error_with_hint(Jakt::DeprecatedString("Expected 'function' keyword inside trait definition"sv),span,TRY((__jakt_format(Jakt::DeprecatedString("Inside '{}' trait's definition only function declarations can appear"sv),((parsed_trait).name)))),((parsed_trait).name_span)))));
return (parsed_trait);
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 36: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::RightShiftEqual>();
utility::Span const& span = __jakt_match_value.value;
{
TRY((((*this).error_with_hint(Jakt::DeprecatedString("Expected 'function' keyword inside trait definition"sv),span,TRY((__jakt_format(Jakt::DeprecatedString("Inside '{}' trait's definition only function declarations can appear"sv),((parsed_trait).name)))),((parsed_trait).name_span)))));
return (parsed_trait);
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 37: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::Asterisk>();
utility::Span const& span = __jakt_match_value.value;
{
TRY((((*this).error_with_hint(Jakt::DeprecatedString("Expected 'function' keyword inside trait definition"sv),span,TRY((__jakt_format(Jakt::DeprecatedString("Inside '{}' trait's definition only function declarations can appear"sv),((parsed_trait).name)))),((parsed_trait).name_span)))));
return (parsed_trait);
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 38: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::Ampersand>();
utility::Span const& span = __jakt_match_value.value;
{
TRY((((*this).error_with_hint(Jakt::DeprecatedString("Expected 'function' keyword inside trait definition"sv),span,TRY((__jakt_format(Jakt::DeprecatedString("Inside '{}' trait's definition only function declarations can appear"sv),((parsed_trait).name)))),((parsed_trait).name_span)))));
return (parsed_trait);
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 39: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::AmpersandEqual>();
utility::Span const& span = __jakt_match_value.value;
{
TRY((((*this).error_with_hint(Jakt::DeprecatedString("Expected 'function' keyword inside trait definition"sv),span,TRY((__jakt_format(Jakt::DeprecatedString("Inside '{}' trait's definition only function declarations can appear"sv),((parsed_trait).name)))),((parsed_trait).name_span)))));
return (parsed_trait);
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 40: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::AmpersandAmpersand>();
utility::Span const& span = __jakt_match_value.value;
{
TRY((((*this).error_with_hint(Jakt::DeprecatedString("Expected 'function' keyword inside trait definition"sv),span,TRY((__jakt_format(Jakt::DeprecatedString("Inside '{}' trait's definition only function declarations can appear"sv),((parsed_trait).name)))),((parsed_trait).name_span)))));
return (parsed_trait);
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 41: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::Pipe>();
utility::Span const& span = __jakt_match_value.value;
{
TRY((((*this).error_with_hint(Jakt::DeprecatedString("Expected 'function' keyword inside trait definition"sv),span,TRY((__jakt_format(Jakt::DeprecatedString("Inside '{}' trait's definition only function declarations can appear"sv),((parsed_trait).name)))),((parsed_trait).name_span)))));
return (parsed_trait);
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 42: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::PipeEqual>();
utility::Span const& span = __jakt_match_value.value;
{
TRY((((*this).error_with_hint(Jakt::DeprecatedString("Expected 'function' keyword inside trait definition"sv),span,TRY((__jakt_format(Jakt::DeprecatedString("Inside '{}' trait's definition only function declarations can appear"sv),((parsed_trait).name)))),((parsed_trait).name_span)))));
return (parsed_trait);
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 43: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::PipePipe>();
utility::Span const& span = __jakt_match_value.value;
{
TRY((((*this).error_with_hint(Jakt::DeprecatedString("Expected 'function' keyword inside trait definition"sv),span,TRY((__jakt_format(Jakt::DeprecatedString("Inside '{}' trait's definition only function declarations can appear"sv),((parsed_trait).name)))),((parsed_trait).name_span)))));
return (parsed_trait);
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 44: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::Caret>();
utility::Span const& span = __jakt_match_value.value;
{
TRY((((*this).error_with_hint(Jakt::DeprecatedString("Expected 'function' keyword inside trait definition"sv),span,TRY((__jakt_format(Jakt::DeprecatedString("Inside '{}' trait's definition only function declarations can appear"sv),((parsed_trait).name)))),((parsed_trait).name_span)))));
return (parsed_trait);
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 45: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::CaretEqual>();
utility::Span const& span = __jakt_match_value.value;
{
TRY((((*this).error_with_hint(Jakt::DeprecatedString("Expected 'function' keyword inside trait definition"sv),span,TRY((__jakt_format(Jakt::DeprecatedString("Inside '{}' trait's definition only function declarations can appear"sv),((parsed_trait).name)))),((parsed_trait).name_span)))));
return (parsed_trait);
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 46: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::Dollar>();
utility::Span const& span = __jakt_match_value.value;
{
TRY((((*this).error_with_hint(Jakt::DeprecatedString("Expected 'function' keyword inside trait definition"sv),span,TRY((__jakt_format(Jakt::DeprecatedString("Inside '{}' trait's definition only function declarations can appear"sv),((parsed_trait).name)))),((parsed_trait).name_span)))));
return (parsed_trait);
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 47: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::Tilde>();
utility::Span const& span = __jakt_match_value.value;
{
TRY((((*this).error_with_hint(Jakt::DeprecatedString("Expected 'function' keyword inside trait definition"sv),span,TRY((__jakt_format(Jakt::DeprecatedString("Inside '{}' trait's definition only function declarations can appear"sv),((parsed_trait).name)))),((parsed_trait).name_span)))));
return (parsed_trait);
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 48: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::ForwardSlash>();
utility::Span const& span = __jakt_match_value.value;
{
TRY((((*this).error_with_hint(Jakt::DeprecatedString("Expected 'function' keyword inside trait definition"sv),span,TRY((__jakt_format(Jakt::DeprecatedString("Inside '{}' trait's definition only function declarations can appear"sv),((parsed_trait).name)))),((parsed_trait).name_span)))));
return (parsed_trait);
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 49: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::ExclamationPoint>();
utility::Span const& span = __jakt_match_value.value;
{
TRY((((*this).error_with_hint(Jakt::DeprecatedString("Expected 'function' keyword inside trait definition"sv),span,TRY((__jakt_format(Jakt::DeprecatedString("Inside '{}' trait's definition only function declarations can appear"sv),((parsed_trait).name)))),((parsed_trait).name_span)))));
return (parsed_trait);
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 50: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::QuestionMark>();
utility::Span const& span = __jakt_match_value.value;
{
TRY((((*this).error_with_hint(Jakt::DeprecatedString("Expected 'function' keyword inside trait definition"sv),span,TRY((__jakt_format(Jakt::DeprecatedString("Inside '{}' trait's definition only function declarations can appear"sv),((parsed_trait).name)))),((parsed_trait).name_span)))));
return (parsed_trait);
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 51: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::QuestionMarkQuestionMark>();
utility::Span const& span = __jakt_match_value.value;
{
TRY((((*this).error_with_hint(Jakt::DeprecatedString("Expected 'function' keyword inside trait definition"sv),span,TRY((__jakt_format(Jakt::DeprecatedString("Inside '{}' trait's definition only function declarations can appear"sv),((parsed_trait).name)))),((parsed_trait).name_span)))));
return (parsed_trait);
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 52: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::QuestionMarkQuestionMarkEqual>();
utility::Span const& span = __jakt_match_value.value;
{
TRY((((*this).error_with_hint(Jakt::DeprecatedString("Expected 'function' keyword inside trait definition"sv),span,TRY((__jakt_format(Jakt::DeprecatedString("Inside '{}' trait's definition only function declarations can appear"sv),((parsed_trait).name)))),((parsed_trait).name_span)))));
return (parsed_trait);
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 53: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::Comma>();
utility::Span const& span = __jakt_match_value.value;
{
TRY((((*this).error_with_hint(Jakt::DeprecatedString("Expected 'function' keyword inside trait definition"sv),span,TRY((__jakt_format(Jakt::DeprecatedString("Inside '{}' trait's definition only function declarations can appear"sv),((parsed_trait).name)))),((parsed_trait).name_span)))));
return (parsed_trait);
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 54: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::Dot>();
utility::Span const& span = __jakt_match_value.value;
{
TRY((((*this).error_with_hint(Jakt::DeprecatedString("Expected 'function' keyword inside trait definition"sv),span,TRY((__jakt_format(Jakt::DeprecatedString("Inside '{}' trait's definition only function declarations can appear"sv),((parsed_trait).name)))),((parsed_trait).name_span)))));
return (parsed_trait);
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 55: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::DotDot>();
utility::Span const& span = __jakt_match_value.value;
{
TRY((((*this).error_with_hint(Jakt::DeprecatedString("Expected 'function' keyword inside trait definition"sv),span,TRY((__jakt_format(Jakt::DeprecatedString("Inside '{}' trait's definition only function declarations can appear"sv),((parsed_trait).name)))),((parsed_trait).name_span)))));
return (parsed_trait);
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 58: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::FatArrow>();
utility::Span const& span = __jakt_match_value.value;
{
TRY((((*this).error_with_hint(Jakt::DeprecatedString("Expected 'function' keyword inside trait definition"sv),span,TRY((__jakt_format(Jakt::DeprecatedString("Inside '{}' trait's definition only function declarations can appear"sv),((parsed_trait).name)))),((parsed_trait).name_span)))));
return (parsed_trait);
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 59: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::Arrow>();
utility::Span const& span = __jakt_match_value.value;
{
TRY((((*this).error_with_hint(Jakt::DeprecatedString("Expected 'function' keyword inside trait definition"sv),span,TRY((__jakt_format(Jakt::DeprecatedString("Inside '{}' trait's definition only function declarations can appear"sv),((parsed_trait).name)))),((parsed_trait).name_span)))));
return (parsed_trait);
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 60: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::And>();
utility::Span const& span = __jakt_match_value.value;
{
TRY((((*this).error_with_hint(Jakt::DeprecatedString("Expected 'function' keyword inside trait definition"sv),span,TRY((__jakt_format(Jakt::DeprecatedString("Inside '{}' trait's definition only function declarations can appear"sv),((parsed_trait).name)))),((parsed_trait).name_span)))));
return (parsed_trait);
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 61: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::Anon>();
utility::Span const& span = __jakt_match_value.value;
{
TRY((((*this).error_with_hint(Jakt::DeprecatedString("Expected 'function' keyword inside trait definition"sv),span,TRY((__jakt_format(Jakt::DeprecatedString("Inside '{}' trait's definition only function declarations can appear"sv),((parsed_trait).name)))),((parsed_trait).name_span)))));
return (parsed_trait);
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 62: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::As>();
utility::Span const& span = __jakt_match_value.value;
{
TRY((((*this).error_with_hint(Jakt::DeprecatedString("Expected 'function' keyword inside trait definition"sv),span,TRY((__jakt_format(Jakt::DeprecatedString("Inside '{}' trait's definition only function declarations can appear"sv),((parsed_trait).name)))),((parsed_trait).name_span)))));
return (parsed_trait);
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 63: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::Boxed>();
utility::Span const& span = __jakt_match_value.value;
{
TRY((((*this).error_with_hint(Jakt::DeprecatedString("Expected 'function' keyword inside trait definition"sv),span,TRY((__jakt_format(Jakt::DeprecatedString("Inside '{}' trait's definition only function declarations can appear"sv),((parsed_trait).name)))),((parsed_trait).name_span)))));
return (parsed_trait);
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 64: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::Break>();
utility::Span const& span = __jakt_match_value.value;
{
TRY((((*this).error_with_hint(Jakt::DeprecatedString("Expected 'function' keyword inside trait definition"sv),span,TRY((__jakt_format(Jakt::DeprecatedString("Inside '{}' trait's definition only function declarations can appear"sv),((parsed_trait).name)))),((parsed_trait).name_span)))));
return (parsed_trait);
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 65: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::Catch>();
utility::Span const& span = __jakt_match_value.value;
{
TRY((((*this).error_with_hint(Jakt::DeprecatedString("Expected 'function' keyword inside trait definition"sv),span,TRY((__jakt_format(Jakt::DeprecatedString("Inside '{}' trait's definition only function declarations can appear"sv),((parsed_trait).name)))),((parsed_trait).name_span)))));
return (parsed_trait);
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 66: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::Class>();
utility::Span const& span = __jakt_match_value.value;
{
TRY((((*this).error_with_hint(Jakt::DeprecatedString("Expected 'function' keyword inside trait definition"sv),span,TRY((__jakt_format(Jakt::DeprecatedString("Inside '{}' trait's definition only function declarations can appear"sv),((parsed_trait).name)))),((parsed_trait).name_span)))));
return (parsed_trait);
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 67: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::Continue>();
utility::Span const& span = __jakt_match_value.value;
{
TRY((((*this).error_with_hint(Jakt::DeprecatedString("Expected 'function' keyword inside trait definition"sv),span,TRY((__jakt_format(Jakt::DeprecatedString("Inside '{}' trait's definition only function declarations can appear"sv),((parsed_trait).name)))),((parsed_trait).name_span)))));
return (parsed_trait);
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 68: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::Cpp>();
utility::Span const& span = __jakt_match_value.value;
{
TRY((((*this).error_with_hint(Jakt::DeprecatedString("Expected 'function' keyword inside trait definition"sv),span,TRY((__jakt_format(Jakt::DeprecatedString("Inside '{}' trait's definition only function declarations can appear"sv),((parsed_trait).name)))),((parsed_trait).name_span)))));
return (parsed_trait);
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 69: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::Defer>();
utility::Span const& span = __jakt_match_value.value;
{
TRY((((*this).error_with_hint(Jakt::DeprecatedString("Expected 'function' keyword inside trait definition"sv),span,TRY((__jakt_format(Jakt::DeprecatedString("Inside '{}' trait's definition only function declarations can appear"sv),((parsed_trait).name)))),((parsed_trait).name_span)))));
return (parsed_trait);
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 70: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::Else>();
utility::Span const& span = __jakt_match_value.value;
{
TRY((((*this).error_with_hint(Jakt::DeprecatedString("Expected 'function' keyword inside trait definition"sv),span,TRY((__jakt_format(Jakt::DeprecatedString("Inside '{}' trait's definition only function declarations can appear"sv),((parsed_trait).name)))),((parsed_trait).name_span)))));
return (parsed_trait);
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 71: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::Enum>();
utility::Span const& span = __jakt_match_value.value;
{
TRY((((*this).error_with_hint(Jakt::DeprecatedString("Expected 'function' keyword inside trait definition"sv),span,TRY((__jakt_format(Jakt::DeprecatedString("Inside '{}' trait's definition only function declarations can appear"sv),((parsed_trait).name)))),((parsed_trait).name_span)))));
return (parsed_trait);
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 72: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::Extern>();
utility::Span const& span = __jakt_match_value.value;
{
TRY((((*this).error_with_hint(Jakt::DeprecatedString("Expected 'function' keyword inside trait definition"sv),span,TRY((__jakt_format(Jakt::DeprecatedString("Inside '{}' trait's definition only function declarations can appear"sv),((parsed_trait).name)))),((parsed_trait).name_span)))));
return (parsed_trait);
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 73: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::False>();
utility::Span const& span = __jakt_match_value.value;
{
TRY((((*this).error_with_hint(Jakt::DeprecatedString("Expected 'function' keyword inside trait definition"sv),span,TRY((__jakt_format(Jakt::DeprecatedString("Inside '{}' trait's definition only function declarations can appear"sv),((parsed_trait).name)))),((parsed_trait).name_span)))));
return (parsed_trait);
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 74: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::For>();
utility::Span const& span = __jakt_match_value.value;
{
TRY((((*this).error_with_hint(Jakt::DeprecatedString("Expected 'function' keyword inside trait definition"sv),span,TRY((__jakt_format(Jakt::DeprecatedString("Inside '{}' trait's definition only function declarations can appear"sv),((parsed_trait).name)))),((parsed_trait).name_span)))));
return (parsed_trait);
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 76: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::Comptime>();
utility::Span const& span = __jakt_match_value.value;
{
TRY((((*this).error_with_hint(Jakt::DeprecatedString("Expected 'function' keyword inside trait definition"sv),span,TRY((__jakt_format(Jakt::DeprecatedString("Inside '{}' trait's definition only function declarations can appear"sv),((parsed_trait).name)))),((parsed_trait).name_span)))));
return (parsed_trait);
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 77: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::If>();
utility::Span const& span = __jakt_match_value.value;
{
TRY((((*this).error_with_hint(Jakt::DeprecatedString("Expected 'function' keyword inside trait definition"sv),span,TRY((__jakt_format(Jakt::DeprecatedString("Inside '{}' trait's definition only function declarations can appear"sv),((parsed_trait).name)))),((parsed_trait).name_span)))));
return (parsed_trait);
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 78: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::Import>();
utility::Span const& span = __jakt_match_value.value;
{
TRY((((*this).error_with_hint(Jakt::DeprecatedString("Expected 'function' keyword inside trait definition"sv),span,TRY((__jakt_format(Jakt::DeprecatedString("Inside '{}' trait's definition only function declarations can appear"sv),((parsed_trait).name)))),((parsed_trait).name_span)))));
return (parsed_trait);
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 79: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::In>();
utility::Span const& span = __jakt_match_value.value;
{
TRY((((*this).error_with_hint(Jakt::DeprecatedString("Expected 'function' keyword inside trait definition"sv),span,TRY((__jakt_format(Jakt::DeprecatedString("Inside '{}' trait's definition only function declarations can appear"sv),((parsed_trait).name)))),((parsed_trait).name_span)))));
return (parsed_trait);
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 80: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::Is>();
utility::Span const& span = __jakt_match_value.value;
{
TRY((((*this).error_with_hint(Jakt::DeprecatedString("Expected 'function' keyword inside trait definition"sv),span,TRY((__jakt_format(Jakt::DeprecatedString("Inside '{}' trait's definition only function declarations can appear"sv),((parsed_trait).name)))),((parsed_trait).name_span)))));
return (parsed_trait);
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 81: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::Let>();
utility::Span const& span = __jakt_match_value.value;
{
TRY((((*this).error_with_hint(Jakt::DeprecatedString("Expected 'function' keyword inside trait definition"sv),span,TRY((__jakt_format(Jakt::DeprecatedString("Inside '{}' trait's definition only function declarations can appear"sv),((parsed_trait).name)))),((parsed_trait).name_span)))));
return (parsed_trait);
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 82: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::Loop>();
utility::Span const& span = __jakt_match_value.value;
{
TRY((((*this).error_with_hint(Jakt::DeprecatedString("Expected 'function' keyword inside trait definition"sv),span,TRY((__jakt_format(Jakt::DeprecatedString("Inside '{}' trait's definition only function declarations can appear"sv),((parsed_trait).name)))),((parsed_trait).name_span)))));
return (parsed_trait);
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 83: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::Match>();
utility::Span const& span = __jakt_match_value.value;
{
TRY((((*this).error_with_hint(Jakt::DeprecatedString("Expected 'function' keyword inside trait definition"sv),span,TRY((__jakt_format(Jakt::DeprecatedString("Inside '{}' trait's definition only function declarations can appear"sv),((parsed_trait).name)))),((parsed_trait).name_span)))));
return (parsed_trait);
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 84: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::Mut>();
utility::Span const& span = __jakt_match_value.value;
{
TRY((((*this).error_with_hint(Jakt::DeprecatedString("Expected 'function' keyword inside trait definition"sv),span,TRY((__jakt_format(Jakt::DeprecatedString("Inside '{}' trait's definition only function declarations can appear"sv),((parsed_trait).name)))),((parsed_trait).name_span)))));
return (parsed_trait);
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 85: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::Namespace>();
utility::Span const& span = __jakt_match_value.value;
{
TRY((((*this).error_with_hint(Jakt::DeprecatedString("Expected 'function' keyword inside trait definition"sv),span,TRY((__jakt_format(Jakt::DeprecatedString("Inside '{}' trait's definition only function declarations can appear"sv),((parsed_trait).name)))),((parsed_trait).name_span)))));
return (parsed_trait);
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 86: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::Not>();
utility::Span const& span = __jakt_match_value.value;
{
TRY((((*this).error_with_hint(Jakt::DeprecatedString("Expected 'function' keyword inside trait definition"sv),span,TRY((__jakt_format(Jakt::DeprecatedString("Inside '{}' trait's definition only function declarations can appear"sv),((parsed_trait).name)))),((parsed_trait).name_span)))));
return (parsed_trait);
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 87: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::Or>();
utility::Span const& span = __jakt_match_value.value;
{
TRY((((*this).error_with_hint(Jakt::DeprecatedString("Expected 'function' keyword inside trait definition"sv),span,TRY((__jakt_format(Jakt::DeprecatedString("Inside '{}' trait's definition only function declarations can appear"sv),((parsed_trait).name)))),((parsed_trait).name_span)))));
return (parsed_trait);
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 88: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::Override>();
utility::Span const& span = __jakt_match_value.value;
{
TRY((((*this).error_with_hint(Jakt::DeprecatedString("Expected 'function' keyword inside trait definition"sv),span,TRY((__jakt_format(Jakt::DeprecatedString("Inside '{}' trait's definition only function declarations can appear"sv),((parsed_trait).name)))),((parsed_trait).name_span)))));
return (parsed_trait);
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 89: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::Private>();
utility::Span const& span = __jakt_match_value.value;
{
TRY((((*this).error_with_hint(Jakt::DeprecatedString("Expected 'function' keyword inside trait definition"sv),span,TRY((__jakt_format(Jakt::DeprecatedString("Inside '{}' trait's definition only function declarations can appear"sv),((parsed_trait).name)))),((parsed_trait).name_span)))));
return (parsed_trait);
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 90: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::Public>();
utility::Span const& span = __jakt_match_value.value;
{
TRY((((*this).error_with_hint(Jakt::DeprecatedString("Expected 'function' keyword inside trait definition"sv),span,TRY((__jakt_format(Jakt::DeprecatedString("Inside '{}' trait's definition only function declarations can appear"sv),((parsed_trait).name)))),((parsed_trait).name_span)))));
return (parsed_trait);
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 91: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::Raw>();
utility::Span const& span = __jakt_match_value.value;
{
TRY((((*this).error_with_hint(Jakt::DeprecatedString("Expected 'function' keyword inside trait definition"sv),span,TRY((__jakt_format(Jakt::DeprecatedString("Inside '{}' trait's definition only function declarations can appear"sv),((parsed_trait).name)))),((parsed_trait).name_span)))));
return (parsed_trait);
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 92: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::Return>();
utility::Span const& span = __jakt_match_value.value;
{
TRY((((*this).error_with_hint(Jakt::DeprecatedString("Expected 'function' keyword inside trait definition"sv),span,TRY((__jakt_format(Jakt::DeprecatedString("Inside '{}' trait's definition only function declarations can appear"sv),((parsed_trait).name)))),((parsed_trait).name_span)))));
return (parsed_trait);
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 93: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::Restricted>();
utility::Span const& span = __jakt_match_value.value;
{
TRY((((*this).error_with_hint(Jakt::DeprecatedString("Expected 'function' keyword inside trait definition"sv),span,TRY((__jakt_format(Jakt::DeprecatedString("Inside '{}' trait's definition only function declarations can appear"sv),((parsed_trait).name)))),((parsed_trait).name_span)))));
return (parsed_trait);
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 94: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::Struct>();
utility::Span const& span = __jakt_match_value.value;
{
TRY((((*this).error_with_hint(Jakt::DeprecatedString("Expected 'function' keyword inside trait definition"sv),span,TRY((__jakt_format(Jakt::DeprecatedString("Inside '{}' trait's definition only function declarations can appear"sv),((parsed_trait).name)))),((parsed_trait).name_span)))));
return (parsed_trait);
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 95: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::This>();
utility::Span const& span = __jakt_match_value.value;
{
TRY((((*this).error_with_hint(Jakt::DeprecatedString("Expected 'function' keyword inside trait definition"sv),span,TRY((__jakt_format(Jakt::DeprecatedString("Inside '{}' trait's definition only function declarations can appear"sv),((parsed_trait).name)))),((parsed_trait).name_span)))));
return (parsed_trait);
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 96: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::Throw>();
utility::Span const& span = __jakt_match_value.value;
{
TRY((((*this).error_with_hint(Jakt::DeprecatedString("Expected 'function' keyword inside trait definition"sv),span,TRY((__jakt_format(Jakt::DeprecatedString("Inside '{}' trait's definition only function declarations can appear"sv),((parsed_trait).name)))),((parsed_trait).name_span)))));
return (parsed_trait);
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 97: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::Throws>();
utility::Span const& span = __jakt_match_value.value;
{
TRY((((*this).error_with_hint(Jakt::DeprecatedString("Expected 'function' keyword inside trait definition"sv),span,TRY((__jakt_format(Jakt::DeprecatedString("Inside '{}' trait's definition only function declarations can appear"sv),((parsed_trait).name)))),((parsed_trait).name_span)))));
return (parsed_trait);
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 98: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::True>();
utility::Span const& span = __jakt_match_value.value;
{
TRY((((*this).error_with_hint(Jakt::DeprecatedString("Expected 'function' keyword inside trait definition"sv),span,TRY((__jakt_format(Jakt::DeprecatedString("Inside '{}' trait's definition only function declarations can appear"sv),((parsed_trait).name)))),((parsed_trait).name_span)))));
return (parsed_trait);
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 99: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::Try>();
utility::Span const& span = __jakt_match_value.value;
{
TRY((((*this).error_with_hint(Jakt::DeprecatedString("Expected 'function' keyword inside trait definition"sv),span,TRY((__jakt_format(Jakt::DeprecatedString("Inside '{}' trait's definition only function declarations can appear"sv),((parsed_trait).name)))),((parsed_trait).name_span)))));
return (parsed_trait);
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 100: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::Unsafe>();
utility::Span const& span = __jakt_match_value.value;
{
TRY((((*this).error_with_hint(Jakt::DeprecatedString("Expected 'function' keyword inside trait definition"sv),span,TRY((__jakt_format(Jakt::DeprecatedString("Inside '{}' trait's definition only function declarations can appear"sv),((parsed_trait).name)))),((parsed_trait).name_span)))));
return (parsed_trait);
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 101: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::Virtual>();
utility::Span const& span = __jakt_match_value.value;
{
TRY((((*this).error_with_hint(Jakt::DeprecatedString("Expected 'function' keyword inside trait definition"sv),span,TRY((__jakt_format(Jakt::DeprecatedString("Inside '{}' trait's definition only function declarations can appear"sv),((parsed_trait).name)))),((parsed_trait).name_span)))));
return (parsed_trait);
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 102: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::Weak>();
utility::Span const& span = __jakt_match_value.value;
{
TRY((((*this).error_with_hint(Jakt::DeprecatedString("Expected 'function' keyword inside trait definition"sv),span,TRY((__jakt_format(Jakt::DeprecatedString("Inside '{}' trait's definition only function declarations can appear"sv),((parsed_trait).name)))),((parsed_trait).name_span)))));
return (parsed_trait);
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 103: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::While>();
utility::Span const& span = __jakt_match_value.value;
{
TRY((((*this).error_with_hint(Jakt::DeprecatedString("Expected 'function' keyword inside trait definition"sv),span,TRY((__jakt_format(Jakt::DeprecatedString("Inside '{}' trait's definition only function declarations can appear"sv),((parsed_trait).name)))),((parsed_trait).name_span)))));
return (parsed_trait);
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 104: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::Yield>();
utility::Span const& span = __jakt_match_value.value;
{
TRY((((*this).error_with_hint(Jakt::DeprecatedString("Expected 'function' keyword inside trait definition"sv),span,TRY((__jakt_format(Jakt::DeprecatedString("Inside '{}' trait's definition only function declarations can appear"sv),((parsed_trait).name)))),((parsed_trait).name_span)))));
return (parsed_trait);
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 105: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::Guard>();
utility::Span const& span = __jakt_match_value.value;
{
TRY((((*this).error_with_hint(Jakt::DeprecatedString("Expected 'function' keyword inside trait definition"sv),span,TRY((__jakt_format(Jakt::DeprecatedString("Inside '{}' trait's definition only function declarations can appear"sv),((parsed_trait).name)))),((parsed_trait).name_span)))));
return (parsed_trait);
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 106: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::Implements>();
utility::Span const& span = __jakt_match_value.value;
{
TRY((((*this).error_with_hint(Jakt::DeprecatedString("Expected 'function' keyword inside trait definition"sv),span,TRY((__jakt_format(Jakt::DeprecatedString("Inside '{}' trait's definition only function declarations can appear"sv),((parsed_trait).name)))),((parsed_trait).name_span)))));
return (parsed_trait);
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 107: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::Requires>();
utility::Span const& span = __jakt_match_value.value;
{
TRY((((*this).error_with_hint(Jakt::DeprecatedString("Expected 'function' keyword inside trait definition"sv),span,TRY((__jakt_format(Jakt::DeprecatedString("Inside '{}' trait's definition only function declarations can appear"sv),((parsed_trait).name)))),((parsed_trait).name_span)))));
return (parsed_trait);
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 108: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::Trait>();
utility::Span const& span = __jakt_match_value.value;
{
TRY((((*this).error_with_hint(Jakt::DeprecatedString("Expected 'function' keyword inside trait definition"sv),span,TRY((__jakt_format(Jakt::DeprecatedString("Inside '{}' trait's definition only function declarations can appear"sv),((parsed_trait).name)))),((parsed_trait).name_span)))));
return (parsed_trait);
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 109: {
auto&& __jakt_match_value = __jakt_match_variant.template get<lexer::Token::Garbage>();utility::Span const& span = __jakt_match_value.span;
{
TRY((((*this).error_with_hint(Jakt::DeprecatedString("Expected 'function' keyword inside trait definition"sv),span,TRY((__jakt_format(Jakt::DeprecatedString("Inside '{}' trait's definition only function declarations can appear"sv),((parsed_trait).name)))),((parsed_trait).name_span)))));
return (parsed_trait);
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
default: VERIFY_NOT_REACHED();}/*switch end*/
}()
));
}
return (parsed_trait);
}
else {
TRY((((*this).error(Jakt::DeprecatedString("Expected '{' to enter the body of the trait"sv),((((*this).current())).span())))));
return (parsed_trait);
}

}
else {
TRY((((*this).error(Jakt::DeprecatedString("Expected trait name"sv),((((*this).current())).span())))));
return (parsed_trait);
}

}
}

ErrorOr<NonnullRefPtr<typename parser::ParsedExpression>> parser::Parser::parse_number(lexer::LiteralPrefix const prefix,DeprecatedString const number,lexer::LiteralSuffix suffix,utility::Span const span) {
{
((((*this).index)++));
u64 total = static_cast<u64>(0ULL);
if ((!(((prefix).index() == 0 /* None */)))){
JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<void, ErrorOr<NonnullRefPtr<typename parser::ParsedExpression>>>{
auto&& __jakt_match_variant = prefix;
switch(__jakt_match_variant.index()) {
case 1: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::LiteralPrefix::Hexadecimal>();
{
if ((((number).length()) == static_cast<size_t>(0ULL))){
TRY((((*this).error(TRY((__jakt_format(Jakt::DeprecatedString("Could not parse hexadecimal number due to no digits"sv)))),span))));
return (TRY((parser::ParsedExpression::template create<typename parser::ParsedExpression::Garbage>(span))));
}
{
JaktInternal::Range<size_t> _magic = (JaktInternal::Range<size_t>{static_cast<size_t>(0LL),static_cast<size_t>(((number).length()))});
for (;;){
JaktInternal::Optional<size_t> _magic_value = ((_magic).next());
if ((!(((_magic_value).has_value())))){
break;
}
size_t i = (_magic_value.value());
{
u8 const byte = ((number).byte_at(i));
if ((byte != '_')){
u8 offset = static_cast<u8>(0);
if (((byte >= 'a') && (byte <= 'z'))){
(offset = static_cast<u8>(39));
}
else if (((byte >= 'A') && (byte <= 'Z'))){
(offset = static_cast<u8>(7));
}
u8 const value = (JaktInternal::checked_sub<u8>(byte,offset));
u64 const digit = as_saturated<u64, u8>((JaktInternal::checked_sub<u8>(value,'0')));
(total = (JaktInternal::checked_add<u64>((JaktInternal::checked_mul<u64>(total,static_cast<u64>(16ULL))),digit)));
}
}

}
}

}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 2: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::LiteralPrefix::Octal>();
{
if ((((number).length()) == static_cast<size_t>(0ULL))){
TRY((((*this).error(TRY((__jakt_format(Jakt::DeprecatedString("Could not parse octal number due to no digits"sv)))),span))));
return (TRY((parser::ParsedExpression::template create<typename parser::ParsedExpression::Garbage>(span))));
}
{
JaktInternal::Range<size_t> _magic = (JaktInternal::Range<size_t>{static_cast<size_t>(0LL),static_cast<size_t>(((number).length()))});
for (;;){
JaktInternal::Optional<size_t> _magic_value = ((_magic).next());
if ((!(((_magic_value).has_value())))){
break;
}
size_t i = (_magic_value.value());
{
u8 const byte = ((number).byte_at(i));
if ((byte != '_')){
u64 const digit = as_saturated<u64, u8>((JaktInternal::checked_sub<u8>(byte,'0')));
(total = (JaktInternal::checked_add<u64>((JaktInternal::checked_mul<u64>(total,static_cast<u64>(8ULL))),digit)));
}
}

}
}

}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 3: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::LiteralPrefix::Binary>();
{
if ((((number).length()) == static_cast<size_t>(0ULL))){
TRY((((*this).error(TRY((__jakt_format(Jakt::DeprecatedString("Could not parse binary number due to no digits"sv)))),span))));
return (TRY((parser::ParsedExpression::template create<typename parser::ParsedExpression::Garbage>(span))));
}
{
JaktInternal::Range<size_t> _magic = (JaktInternal::Range<size_t>{static_cast<size_t>(0LL),static_cast<size_t>(((number).length()))});
for (;;){
JaktInternal::Optional<size_t> _magic_value = ((_magic).next());
if ((!(((_magic_value).has_value())))){
break;
}
size_t i = (_magic_value.value());
{
u8 const byte = ((number).byte_at(i));
if ((byte != '_')){
u64 const digit = as_saturated<u64, u8>((JaktInternal::checked_sub<u8>(byte,'0')));
(total = (JaktInternal::checked_add<u64>((JaktInternal::checked_mul<u64>(total,static_cast<u64>(2ULL))),digit)));
}
}

}
}

}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 0: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::LiteralPrefix::None>();
{
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
default: VERIFY_NOT_REACHED();}/*switch end*/
}()
));
JaktInternal::Optional<parser::NumericConstant> const constant_value = TRY((((*this).make_integer_numeric_constant(total,suffix,span))));
if (((constant_value).has_value())){
return (TRY((parser::ParsedExpression::template create<typename parser::ParsedExpression::NumericConstant>((constant_value.value()),span))));
}
return (TRY((parser::ParsedExpression::template create<typename parser::ParsedExpression::Garbage>(span))));
}
bool number_too_large = false;
bool floating = false;
u64 fraction_nominator = static_cast<u64>(0ULL);
u64 fraction_denominator = static_cast<u64>(1ULL);
if ((((number).length()) == static_cast<size_t>(0ULL))){
TRY((((*this).error(TRY((__jakt_format(Jakt::DeprecatedString("Could not parse number due to no digits"sv)))),span))));
return (TRY((parser::ParsedExpression::template create<typename parser::ParsedExpression::Garbage>(span))));
}
{
JaktInternal::Range<size_t> _magic = (JaktInternal::Range<size_t>{static_cast<size_t>(0LL),static_cast<size_t>(((number).length()))});
for (;;){
JaktInternal::Optional<size_t> _magic_value = ((_magic).next());
if ((!(((_magic_value).has_value())))){
break;
}
size_t i = (_magic_value.value());
{
u8 const byte = ((number).byte_at(i));
if ((byte != '_')){
if ((byte == '.')){
(floating = true);
continue;
}
u64 const digit = as_saturated<u64, u8>((JaktInternal::checked_sub<u8>(byte,'0')));
if (floating){
(fraction_nominator = (JaktInternal::checked_add<u64>((JaktInternal::checked_mul<u64>(fraction_nominator,static_cast<u64>(10ULL))),digit)));
({auto& _jakt_ref = fraction_denominator;_jakt_ref = JaktInternal::checked_mul<u64>(_jakt_ref, static_cast<u64>(10ULL));});
}
else {
u64 const old_total = total;
(total = unchecked_add<u64>(unchecked_mul<u64>(total,static_cast<u64>(10ULL)),digit));
if ((total < old_total)){
(number_too_large = true);
}
}

}
}

}
}

if (number_too_large){
TRY((((*this).error(TRY((__jakt_format(Jakt::DeprecatedString("Integer literal too large"sv)))),span))));
return (TRY((parser::ParsedExpression::template create<typename parser::ParsedExpression::Garbage>(span))));
}
if ((floating && ((suffix).index() == 0 /* None */))){
(suffix =  lexer::LiteralSuffix { typename lexer::LiteralSuffix::F64() } );
}
bool const is_float_suffix = JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<bool, ErrorOr<NonnullRefPtr<typename parser::ParsedExpression>>>{
auto&& __jakt_match_variant = suffix;
switch(__jakt_match_variant.index()) {
case 10: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::LiteralSuffix::F32>();
return JaktInternal::ExplicitValue(true);
};/*case end*/
case 11: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::LiteralSuffix::F64>();
return JaktInternal::ExplicitValue(true);
};/*case end*/
default: {
return JaktInternal::ExplicitValue(false);
};/*case end*/
}/*switch end*/
}()
));
if ((floating && (!(is_float_suffix)))){
return (TRY((parser::ParsedExpression::template create<typename parser::ParsedExpression::Garbage>(span))));
}
JaktInternal::Optional<parser::NumericConstant> const constant_value = JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<JaktInternal::Optional<parser::NumericConstant>, ErrorOr<NonnullRefPtr<typename parser::ParsedExpression>>>{
auto&& __jakt_match_variant = suffix;
switch(__jakt_match_variant.index()) {
case 10: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::LiteralSuffix::F32>();
return JaktInternal::ExplicitValue(({ Optional<JaktInternal::Optional<parser::NumericConstant>> __jakt_var_65; {
f64 const number = (parser::u64_to_float<f64>(total) + (parser::u64_to_float<f64>(fraction_nominator) / parser::u64_to_float<f64>(fraction_denominator)));
__jakt_var_65 = TRY((((*this).make_float_numeric_constant(number,suffix,span)))); goto __jakt_label_62;

}
__jakt_label_62:; __jakt_var_65.release_value(); }));
};/*case end*/
case 11: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::LiteralSuffix::F64>();
return JaktInternal::ExplicitValue(({ Optional<JaktInternal::Optional<parser::NumericConstant>> __jakt_var_66; {
f64 const number = (parser::u64_to_float<f64>(total) + (parser::u64_to_float<f64>(fraction_nominator) / parser::u64_to_float<f64>(fraction_denominator)));
__jakt_var_66 = TRY((((*this).make_float_numeric_constant(number,suffix,span)))); goto __jakt_label_63;

}
__jakt_label_63:; __jakt_var_66.release_value(); }));
};/*case end*/
default: {
return JaktInternal::ExplicitValue(TRY((((*this).make_integer_numeric_constant(total,suffix,span)))));
};/*case end*/
}/*switch end*/
}()
));
if (((constant_value).has_value())){
return (TRY((parser::ParsedExpression::template create<typename parser::ParsedExpression::NumericConstant>((constant_value.value()),span))));
}
return (TRY((parser::ParsedExpression::template create<typename parser::ParsedExpression::Garbage>(span))));
}
}

ErrorOr<void> parser::Parser::apply_attributes(parser::ParsedFunction& parsed_function,JaktInternal::DynamicArray<parser::ParsedAttribute> const& active_attributes) {
{
{
JaktInternal::ArrayIterator<parser::ParsedAttribute> _magic = ((((active_attributes))).iterator());
for (;;){
JaktInternal::Optional<parser::ParsedAttribute> _magic_value = ((_magic).next());
if ((!(((_magic_value).has_value())))){
break;
}
parser::ParsedAttribute attribute = (_magic_value.value());
{
JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_AT_LOOP(([&]() -> JaktInternal::ExplicitValueOrControlFlow<void,ErrorOr<void>>{
auto __jakt_enum_value = (((attribute).name));
if (__jakt_enum_value == Jakt::DeprecatedString("name"sv)) {
{
if (((((attribute).assigned_value)).has_value())){
if (((((((parsed_function))).external_name)).has_value())){
TRY((((*this).error(TRY((__jakt_format(Jakt::DeprecatedString("The attribute '{}' cannot be applied more than once"sv),((attribute).name)))),((attribute).span)))));
return JaktInternal::LoopContinue{};
}
(((((parsed_function))).external_name) = ((attribute).assigned_value));
}
else {
TRY((((*this).error(TRY((__jakt_format(Jakt::DeprecatedString("The attribute '{}' requires a value"sv),((attribute).name)))),((attribute).span)))));
return JaktInternal::LoopContinue{};
}

}
return JaktInternal::ExplicitValue<void>();
}
else if (__jakt_enum_value == Jakt::DeprecatedString("deprecated"sv)) {
{
if (((((((parsed_function))).deprecated_message)).has_value())){
TRY((((*this).error(TRY((__jakt_format(Jakt::DeprecatedString("The attribute '{}' cannot be applied more than once"sv),((attribute).name)))),((attribute).span)))));
return JaktInternal::LoopContinue{};
}
DeprecatedString const message = TRY((((((((attribute).arguments)).first())).map([](auto& _value) { return _value.name; })).try_value_or_lazy_evaluated([&]() -> ErrorOr<DeprecatedString> { return TRY((__jakt_format(Jakt::DeprecatedString("The function '{}' is marked as deprecated"sv),((((parsed_function))).name)))); })));
(((((parsed_function))).deprecated_message) = message);
}
return JaktInternal::ExplicitValue<void>();
}
else {
{
TRY((((*this).error(TRY((__jakt_format(Jakt::DeprecatedString("The attribute '{}' does not apply to functions"sv),((attribute).name)))),((attribute).span)))));
}
return JaktInternal::ExplicitValue<void>();
}
return JaktInternal::ExplicitValue<void>();
}()))
;
}

}
}

}
return {};
}

ErrorOr<void> parser::Parser::apply_attributes(parser::ParsedMethod& parsed_method,JaktInternal::DynamicArray<parser::ParsedAttribute> const& active_attributes) {
{
TRY((((*this).apply_attributes(((((((parsed_method))).parsed_function))),active_attributes))));
}
return {};
}

ErrorOr<void> parser::Parser::apply_attributes(parser::ParsedRecord& parsed_record,JaktInternal::DynamicArray<parser::ParsedAttribute> const& active_attributes) {
{
{
JaktInternal::ArrayIterator<parser::ParsedAttribute> _magic = ((((active_attributes))).iterator());
for (;;){
JaktInternal::Optional<parser::ParsedAttribute> _magic_value = ((_magic).next());
if ((!(((_magic_value).has_value())))){
break;
}
parser::ParsedAttribute attribute = (_magic_value.value());
{
JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_AT_LOOP(([&]() -> JaktInternal::ExplicitValueOrControlFlow<void,ErrorOr<void>>{
auto __jakt_enum_value = (((attribute).name));
if (__jakt_enum_value == Jakt::DeprecatedString("name"sv)) {
{
if (((((attribute).assigned_value)).has_value())){
if (((((((parsed_record))).external_name)).has_value())){
TRY((((*this).error(TRY((__jakt_format(Jakt::DeprecatedString("The attribute '{}' cannot be applied more than once"sv),((attribute).name)))),((attribute).span)))));
return JaktInternal::LoopContinue{};
}
(((((parsed_record))).external_name) = ((attribute).assigned_value));
}
else {
TRY((((*this).error(TRY((__jakt_format(Jakt::DeprecatedString("The attribute '{}' requires a value"sv),((attribute).name)))),((attribute).span)))));
return JaktInternal::LoopContinue{};
}

}
return JaktInternal::ExplicitValue<void>();
}
else {
{
TRY((((*this).error(TRY((__jakt_format(Jakt::DeprecatedString("The attribute '{}' does not apply to records"sv),((attribute).name)))),((attribute).span)))));
}
return JaktInternal::ExplicitValue<void>();
}
return JaktInternal::ExplicitValue<void>();
}()))
;
}

}
}

}
return {};
}

utility::Span parser::Parser::span(size_t const start,size_t const end) const {
{
return (utility::Span((((((*this).compiler))->current_file).value()),start,end));
}
}

ErrorOr<parser::ParsedFunction> parser::Parser::parse_function(parser::FunctionLinkage const linkage,parser::Visibility const visibility,bool const is_comptime,bool const allow_missing_body) {
{
parser::ParsedFunction parsed_function = parser::ParsedFunction(Jakt::DeprecatedString(""sv),((*this).empty_span()),visibility,(TRY((DynamicArray<parser::ParsedParameter>::create_with({})))),(TRY((DynamicArray<parser::ParsedGenericParameter>::create_with({})))),parser::ParsedBlock((TRY((DynamicArray<NonnullRefPtr<typename parser::ParsedStatement>>::create_with({}))))),TRY((parser::ParsedType::template create<typename parser::ParsedType::Empty>())),((*this).span(static_cast<size_t>(0ULL),static_cast<size_t>(0ULL))),false, parser::FunctionType { typename parser::FunctionType::Normal() } ,linkage,false,is_comptime,false,JaktInternal::OptionalNone(),JaktInternal::OptionalNone());
((((*this).index)++));
if (((*this).eof())){
TRY((((*this).error(Jakt::DeprecatedString("Incomplete function definition"sv),((((*this).current())).span())))));
return (parsed_function);
}
if (((((*this).current())).index() == 4 /* Identifier */)){
DeprecatedString const name = ((((*this).current())).get<lexer::Token::Identifier>()).name;
(((parsed_function).name) = name);
(((parsed_function).name_span) = ((((*this).current())).span()));
((((*this).index)++));
(((parsed_function).generic_parameters) = TRY((((*this).parse_generic_parameters()))));
if (((*this).eof())){
TRY((((*this).error(Jakt::DeprecatedString("Incomplete function"sv),((((*this).current())).span())))));
}
(((parsed_function).params) = TRY((((*this).parse_function_parameters()))));
bool can_throw = (name == Jakt::DeprecatedString("main"sv));
if (((((*this).current())).index() == 97 /* Throws */)){
(can_throw = true);
((((*this).index)++));
}
(((parsed_function).can_throw) = can_throw);
if (((((*this).current())).index() == 59 /* Arrow */)){
((((*this).index)++));
utility::Span const start = ((((*this).current())).span());
(((parsed_function).return_type) = TRY((((*this).parse_typename()))));
(((parsed_function).return_type_span) = TRY((parser::merge_spans(start,((((*this).previous())).span())))));
}
if (((linkage).index() == 1 /* External */)){
return (parsed_function);
}
if (((((*this).current())).index() == 58 /* FatArrow */)){
(((parsed_function).block) = TRY((((*this).parse_fat_arrow()))));
(((parsed_function).is_fat_arrow) = true);
}
else {
if (allow_missing_body){
((*this).skip_newlines());
if (((((*this).current())).index() == 10 /* LCurly */)){
}
else {
return (parsed_function);
}

}
(((parsed_function).block) = TRY((((*this).parse_block()))));
}

return (parsed_function);
}
else {
TRY((((*this).error(Jakt::DeprecatedString("Incomplete function definition"sv),((((*this).current())).span())))));
return (parsed_function);
}

}
}

ErrorOr<JaktInternal::Optional<JaktInternal::DynamicArray<parser::IncludeAction>>> parser::Parser::parse_include_action() {
{
((*this).skip_newlines());
if (((((*this).current())).index() == 4 /* Identifier */)){
DeprecatedString const name = ((((*this).current())).get<lexer::Token::Identifier>()).name;
JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<void,ErrorOr<JaktInternal::Optional<JaktInternal::DynamicArray<parser::IncludeAction>>>>{
auto __jakt_enum_value = (name);
if (__jakt_enum_value == Jakt::DeprecatedString("define"sv)) {
{
((((*this).index)++));
((*this).skip_newlines());
if (((((*this).current())).index() == 10 /* LCurly */)){
((((*this).index)++));
((*this).skip_newlines());
}
else {
TRY((((*this).error(Jakt::DeprecatedString("Expected '{' to start define action"sv),((((*this).current())).span())))));
return (JaktInternal::OptionalNone());
}

JaktInternal::DynamicArray<parser::IncludeAction> defines = (TRY((DynamicArray<parser::IncludeAction>::create_with({}))));
for (;;){
if (((((*this).current())).index() == 4 /* Identifier */)){
DeprecatedString const name = ((((*this).current())).get<lexer::Token::Identifier>()).name;
utility::Span const span = ((((*this).current())).span());
((((*this).index)++));
((*this).skip_newlines());
if (((((*this).current())).index() == 17 /* Equal */)){
((((*this).index)++));
}
else {
TRY((((*this).error(Jakt::DeprecatedString("Expected '=' to assign value to defined symbols"sv),((((*this).current())).span())))));
continue;
}

DeprecatedString const value = JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_AT_LOOP(([&]() -> JaktInternal::ExplicitValueOrControlFlow<DeprecatedString, ErrorOr<JaktInternal::Optional<JaktInternal::DynamicArray<parser::IncludeAction>>>>{
auto&& __jakt_match_variant = ((*this).current());
switch(__jakt_match_variant.index()) {
case 2: {
auto&& __jakt_match_value = __jakt_match_variant.template get<lexer::Token::QuotedString>();DeprecatedString const& quote = __jakt_match_value.quote;
return JaktInternal::ExplicitValue(({ Optional<DeprecatedString> __jakt_var_67; {
((((*this).index)++));
__jakt_var_67 = quote; goto __jakt_label_64;

}
__jakt_label_64:; __jakt_var_67.release_value(); }));
};/*case end*/
default: {
return JaktInternal::ExplicitValue(({ Optional<DeprecatedString> __jakt_var_68; {
TRY((((*this).error(Jakt::DeprecatedString("Expected quoted string to assign value to defined symbols"sv),((((*this).current())).span())))));
__jakt_var_68 = Jakt::DeprecatedString(""sv); goto __jakt_label_65;

}
__jakt_label_65:; __jakt_var_68.release_value(); }));
};/*case end*/
}/*switch end*/
}()
));
TRY((((defines).push( parser::IncludeAction { typename parser::IncludeAction::Define(name,span,value) } ))));
((*this).skip_newlines());
if (((((*this).current())).index() == 53 /* Comma */)){
((((*this).index)++));
((*this).skip_newlines());
}
}
else {
break;
}

}
if (((((*this).current())).index() == 11 /* RCurly */)){
((((*this).index)++));
}
else {
TRY((((*this).error(Jakt::DeprecatedString("Expected '}' to end define action"sv),((((*this).current())).span())))));
}

return (static_cast<JaktInternal::Optional<JaktInternal::DynamicArray<parser::IncludeAction>>>(defines));
}
return JaktInternal::ExplicitValue<void>();
}
else if (__jakt_enum_value == Jakt::DeprecatedString("undefine"sv)) {
{
((((*this).index)++));
((*this).skip_newlines());
if (((((*this).current())).index() == 10 /* LCurly */)){
((((*this).index)++));
((*this).skip_newlines());
}
else {
TRY((((*this).error(Jakt::DeprecatedString("Expected '{' to start undefine include action"sv),((((*this).current())).span())))));
return (JaktInternal::OptionalNone());
}

JaktInternal::DynamicArray<parser::IncludeAction> defines = (TRY((DynamicArray<parser::IncludeAction>::create_with({}))));
for (;;){
if (((((*this).current())).index() == 4 /* Identifier */)){
DeprecatedString const name = ((((*this).current())).get<lexer::Token::Identifier>()).name;
utility::Span const span = ((((*this).current())).span());
((((*this).index)++));
TRY((((defines).push( parser::IncludeAction { typename parser::IncludeAction::Undefine(name,span) } ))));
((*this).skip_newlines());
if (((((*this).current())).index() == 53 /* Comma */)){
((((*this).index)++));
((*this).skip_newlines());
}
}
else {
break;
}

}
if (((((*this).current())).index() == 11 /* RCurly */)){
((((*this).index)++));
}
else {
TRY((((*this).error(Jakt::DeprecatedString("Expected '}' to end undefine action"sv),((((*this).current())).span())))));
}

return (static_cast<JaktInternal::Optional<JaktInternal::DynamicArray<parser::IncludeAction>>>(defines));
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
TRY((((*this).error(Jakt::DeprecatedString("Expected 'define' or 'undefine' in include action"sv),((((*this).current())).span())))));
return (JaktInternal::OptionalNone());
}
else {
TRY((((*this).error(Jakt::DeprecatedString("Expected 'define' or 'undefine' in include action"sv),((((*this).current())).span())))));
return (JaktInternal::OptionalNone());
}

}
}

ErrorOr<NonnullRefPtr<typename parser::ParsedExpression>> parser::Parser::parse_range() {
{
utility::Span const start = ((((*this).current())).span());
((((*this).index)++));
JaktInternal::Optional<NonnullRefPtr<typename parser::ParsedExpression>> to = JaktInternal::OptionalNone();
JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<void, ErrorOr<NonnullRefPtr<typename parser::ParsedExpression>>>{
auto&& __jakt_match_variant = ((*this).current());
switch(__jakt_match_variant.index()) {
case 13: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::RSquare>();
{
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 56: {
auto&& __jakt_match_value = __jakt_match_variant.template get<lexer::Token::Eol>();{
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 53: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::Comma>();
{
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 9: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::RParen>();
{
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
default: {
{
(to = TRY((((*this).parse_operand()))));
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
}/*switch end*/
}()
));
return (TRY((parser::ParsedExpression::template create<typename parser::ParsedExpression::Range>(JaktInternal::OptionalNone(),to,TRY((parser::merge_spans(start,((((*this).current())).span()))))))));
}
}

ErrorOr<NonnullRefPtr<typename parser::ParsedStatement>> parser::Parser::parse_guard_statement() {
{
utility::Span const span = ((((*this).current())).span());
((((*this).index)++));
bool const previous_can_have_trailing_closure = ((*this).can_have_trailing_closure);
(((*this).can_have_trailing_closure) = false);
NonnullRefPtr<typename parser::ParsedExpression> const expr = TRY((((*this).parse_expression(false,true))));
(((*this).can_have_trailing_closure) = previous_can_have_trailing_closure);
if (((((*this).current())).index() == 70 /* Else */)){
((((*this).index)++));
}
else {
TRY((((*this).error(Jakt::DeprecatedString("Expected `else` keyword"sv),((((*this).current())).span())))));
}

parser::ParsedBlock const else_block = TRY((((*this).parse_block())));
parser::ParsedBlock remaining_code = parser::ParsedBlock((TRY((DynamicArray<NonnullRefPtr<typename parser::ParsedStatement>>::create_with({})))));
while ((!(((*this).eof())))){
JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_AT_LOOP(([&]() -> JaktInternal::ExplicitValueOrControlFlow<void, ErrorOr<NonnullRefPtr<typename parser::ParsedStatement>>>{
auto&& __jakt_match_variant = ((*this).current());
switch(__jakt_match_variant.index()) {
case 11: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::RCurly>();
{
return (TRY((parser::ParsedStatement::template create<typename parser::ParsedStatement::Guard>(expr,else_block,remaining_code,span))));
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 5: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::Semicolon>();
{
((((*this).index)++));
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 56: {
auto&& __jakt_match_value = __jakt_match_variant.template get<lexer::Token::Eol>();{
((((*this).index)++));
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
default: {
{
TRY((((((remaining_code).stmts)).push(TRY((((*this).parse_statement(true))))))));
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
}/*switch end*/
}()
));
}
return (TRY((parser::ParsedStatement::template create<typename parser::ParsedStatement::Guard>(expr,else_block,remaining_code,span))));
}
}

ErrorOr<void> parser::Parser::inject_token(lexer::Token const token) {
{
TRY((((((*this).tokens)).insert((JaktInternal::checked_add<size_t>(((*this).index),static_cast<size_t>(1ULL))),token))));
}
return {};
}

ErrorOr<JaktInternal::Optional<parser::ParsedAttribute>> parser::Parser::parse_attribute() {
{
utility::Span const span = ((((*this).current())).span());
DeprecatedString const name = JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<DeprecatedString, ErrorOr<JaktInternal::Optional<parser::ParsedAttribute>>>{
auto&& __jakt_match_variant = ((*this).current());
switch(__jakt_match_variant.index()) {
case 4: {
auto&& __jakt_match_value = __jakt_match_variant.template get<lexer::Token::Identifier>();DeprecatedString const& name = __jakt_match_value.name;
return JaktInternal::ExplicitValue(({ Optional<DeprecatedString> __jakt_var_69; {
((((*this).index)++));
__jakt_var_69 = name; goto __jakt_label_66;

}
__jakt_label_66:; __jakt_var_69.release_value(); }));
};/*case end*/
default: {
{
TRY((((*this).error(Jakt::DeprecatedString("Expected identifier"sv),((((*this).current())).span())))));
return (JaktInternal::OptionalNone());
}
};/*case end*/
}/*switch end*/
}()
));
JaktInternal::DynamicArray<parser::ParsedAttributeArgument> arguments = (TRY((DynamicArray<parser::ParsedAttributeArgument>::create_with({}))));
if (((((*this).current())).index() == 8 /* LParen */)){
((((*this).index)++));
while (((!(((*this).eof()))) && (!(((((*this).current())).index() == 9 /* RParen */))))){
utility::Span const span = ((((*this).current())).span());
DeprecatedString const argument_name = JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_AT_LOOP(([&]() -> JaktInternal::ExplicitValueOrControlFlow<DeprecatedString, ErrorOr<JaktInternal::Optional<parser::ParsedAttribute>>>{
auto&& __jakt_match_variant = ((*this).current());
switch(__jakt_match_variant.index()) {
case 4: {
auto&& __jakt_match_value = __jakt_match_variant.template get<lexer::Token::Identifier>();DeprecatedString const& name = __jakt_match_value.name;
return JaktInternal::ExplicitValue(({ Optional<DeprecatedString> __jakt_var_70; {
((((*this).index)++));
__jakt_var_70 = name; goto __jakt_label_67;

}
__jakt_label_67:; __jakt_var_70.release_value(); }));
};/*case end*/
case 2: {
auto&& __jakt_match_value = __jakt_match_variant.template get<lexer::Token::QuotedString>();DeprecatedString const& quote = __jakt_match_value.quote;
return JaktInternal::ExplicitValue(({ Optional<DeprecatedString> __jakt_var_71; {
((((*this).index)++));
__jakt_var_71 = quote; goto __jakt_label_68;

}
__jakt_label_68:; __jakt_var_71.release_value(); }));
};/*case end*/
default: {
{
TRY((((*this).error(Jakt::DeprecatedString("Expected identifier or string literal"sv),((((*this).current())).span())))));
return (JaktInternal::OptionalNone());
}
};/*case end*/
}/*switch end*/
}()
));
JaktInternal::Optional<DeprecatedString> argument_value = JaktInternal::OptionalNone();
if (((((*this).current())).index() == 6 /* Colon */)){
((((*this).index)++));
(argument_value = JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_AT_LOOP(([&]() -> JaktInternal::ExplicitValueOrControlFlow<JaktInternal::Optional<DeprecatedString>, ErrorOr<JaktInternal::Optional<parser::ParsedAttribute>>>{
auto&& __jakt_match_variant = ((*this).current());
switch(__jakt_match_variant.index()) {
case 4: {
auto&& __jakt_match_value = __jakt_match_variant.template get<lexer::Token::Identifier>();DeprecatedString const& name = __jakt_match_value.name;
return JaktInternal::ExplicitValue(({ Optional<DeprecatedString> __jakt_var_72; {
((((*this).index)++));
__jakt_var_72 = name; goto __jakt_label_69;

}
__jakt_label_69:; __jakt_var_72.release_value(); }));
};/*case end*/
case 2: {
auto&& __jakt_match_value = __jakt_match_variant.template get<lexer::Token::QuotedString>();DeprecatedString const& quote = __jakt_match_value.quote;
return JaktInternal::ExplicitValue(({ Optional<DeprecatedString> __jakt_var_73; {
((((*this).index)++));
__jakt_var_73 = quote; goto __jakt_label_70;

}
__jakt_label_70:; __jakt_var_73.release_value(); }));
};/*case end*/
default: {
{
TRY((((*this).error(Jakt::DeprecatedString("Expected identifier or string literal"sv),((((*this).current())).span())))));
return (JaktInternal::OptionalNone());
}
};/*case end*/
}/*switch end*/
}()
)));
}
TRY((((arguments).push(parser::ParsedAttributeArgument(argument_name,span,argument_value)))));
if (((((*this).current())).index() == 53 /* Comma */)){
((((*this).index)++));
}
else if ((!(((((*this).current())).index() == 9 /* RParen */)))){
TRY((((*this).error(Jakt::DeprecatedString("Expected ‘,’ or ‘)’"sv),((((*this).current())).span())))));
break;
}
}
if (((((*this).current())).index() == 9 /* RParen */)){
((((*this).index)++));
}
else {
TRY((((*this).error(Jakt::DeprecatedString("Expected ‘)’"sv),((((*this).current())).span())))));
}

}
JaktInternal::Optional<DeprecatedString> assigned_value = JaktInternal::OptionalNone();
if (((((*this).current())).index() == 17 /* Equal */)){
((((*this).index)++));
(assigned_value = JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<JaktInternal::Optional<DeprecatedString>, ErrorOr<JaktInternal::Optional<parser::ParsedAttribute>>>{
auto&& __jakt_match_variant = ((*this).current());
switch(__jakt_match_variant.index()) {
case 4: {
auto&& __jakt_match_value = __jakt_match_variant.template get<lexer::Token::Identifier>();DeprecatedString const& name = __jakt_match_value.name;
return JaktInternal::ExplicitValue(({ Optional<JaktInternal::Optional<DeprecatedString>> __jakt_var_74; {
((((*this).index)++));
__jakt_var_74 = static_cast<JaktInternal::Optional<DeprecatedString>>(name); goto __jakt_label_71;

}
__jakt_label_71:; __jakt_var_74.release_value(); }));
};/*case end*/
case 2: {
auto&& __jakt_match_value = __jakt_match_variant.template get<lexer::Token::QuotedString>();DeprecatedString const& quote = __jakt_match_value.quote;
return JaktInternal::ExplicitValue(({ Optional<JaktInternal::Optional<DeprecatedString>> __jakt_var_75; {
((((*this).index)++));
__jakt_var_75 = static_cast<JaktInternal::Optional<DeprecatedString>>(quote); goto __jakt_label_72;

}
__jakt_label_72:; __jakt_var_75.release_value(); }));
};/*case end*/
default: {
return JaktInternal::ExplicitValue(({ Optional<DeprecatedString> __jakt_var_76; {
TRY((((*this).error(Jakt::DeprecatedString("Expected identifier or string literal"sv),((((*this).current())).span())))));
__jakt_var_76 = JaktInternal::OptionalNone(); goto __jakt_label_73;

}
__jakt_label_73:; __jakt_var_76; }));
};/*case end*/
}/*switch end*/
}()
)));
}
return (parser::ParsedAttribute(name,span,assigned_value,arguments));
}
}

ErrorOr<NonnullRefPtr<typename parser::ParsedExpression>> parser::Parser::parse_operator(bool const allow_assignments) {
{
utility::Span const span = ((((*this).current())).span());
parser::BinaryOperator const op = JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<parser::BinaryOperator, ErrorOr<NonnullRefPtr<typename parser::ParsedExpression>>>{
auto&& __jakt_match_variant = ((*this).current());
switch(__jakt_match_variant.index()) {
case 51: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::QuestionMarkQuestionMark>();
return JaktInternal::ExplicitValue( parser::BinaryOperator { typename parser::BinaryOperator::NoneCoalescing() } );
};/*case end*/
case 15: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::Plus>();
return JaktInternal::ExplicitValue( parser::BinaryOperator { typename parser::BinaryOperator::Add() } );
};/*case end*/
case 16: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::Minus>();
return JaktInternal::ExplicitValue( parser::BinaryOperator { typename parser::BinaryOperator::Subtract() } );
};/*case end*/
case 37: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::Asterisk>();
return JaktInternal::ExplicitValue( parser::BinaryOperator { typename parser::BinaryOperator::Multiply() } );
};/*case end*/
case 48: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::ForwardSlash>();
return JaktInternal::ExplicitValue( parser::BinaryOperator { typename parser::BinaryOperator::Divide() } );
};/*case end*/
case 14: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::PercentSign>();
return JaktInternal::ExplicitValue( parser::BinaryOperator { typename parser::BinaryOperator::Modulo() } );
};/*case end*/
case 60: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::And>();
return JaktInternal::ExplicitValue( parser::BinaryOperator { typename parser::BinaryOperator::LogicalAnd() } );
};/*case end*/
case 87: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::Or>();
return JaktInternal::ExplicitValue( parser::BinaryOperator { typename parser::BinaryOperator::LogicalOr() } );
};/*case end*/
case 26: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::DoubleEqual>();
return JaktInternal::ExplicitValue( parser::BinaryOperator { typename parser::BinaryOperator::Equal() } );
};/*case end*/
case 25: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::NotEqual>();
return JaktInternal::ExplicitValue( parser::BinaryOperator { typename parser::BinaryOperator::NotEqual() } );
};/*case end*/
case 29: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::LessThan>();
return JaktInternal::ExplicitValue( parser::BinaryOperator { typename parser::BinaryOperator::LessThan() } );
};/*case end*/
case 30: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::LessThanOrEqual>();
return JaktInternal::ExplicitValue( parser::BinaryOperator { typename parser::BinaryOperator::LessThanOrEqual() } );
};/*case end*/
case 27: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::GreaterThan>();
return JaktInternal::ExplicitValue( parser::BinaryOperator { typename parser::BinaryOperator::GreaterThan() } );
};/*case end*/
case 28: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::GreaterThanOrEqual>();
return JaktInternal::ExplicitValue( parser::BinaryOperator { typename parser::BinaryOperator::GreaterThanOrEqual() } );
};/*case end*/
case 38: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::Ampersand>();
return JaktInternal::ExplicitValue( parser::BinaryOperator { typename parser::BinaryOperator::BitwiseAnd() } );
};/*case end*/
case 40: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::AmpersandAmpersand>();
return JaktInternal::ExplicitValue(({ Optional<parser::BinaryOperator> __jakt_var_77; {
TRY((((*this).error(Jakt::DeprecatedString("‘&&’ is not allowed, use ‘and’ instead"sv),span))));
__jakt_var_77 =  parser::BinaryOperator { typename parser::BinaryOperator::LogicalAnd() } ; goto __jakt_label_74;

}
__jakt_label_74:; __jakt_var_77.release_value(); }));
};/*case end*/
case 41: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::Pipe>();
return JaktInternal::ExplicitValue( parser::BinaryOperator { typename parser::BinaryOperator::BitwiseOr() } );
};/*case end*/
case 43: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::PipePipe>();
return JaktInternal::ExplicitValue(({ Optional<parser::BinaryOperator> __jakt_var_78; {
TRY((((*this).error(Jakt::DeprecatedString("‘||’ is not allowed, use ‘or’ instead"sv),span))));
__jakt_var_78 =  parser::BinaryOperator { typename parser::BinaryOperator::LogicalOr() } ; goto __jakt_label_75;

}
__jakt_label_75:; __jakt_var_78.release_value(); }));
};/*case end*/
case 44: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::Caret>();
return JaktInternal::ExplicitValue( parser::BinaryOperator { typename parser::BinaryOperator::BitwiseXor() } );
};/*case end*/
case 32: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::LeftShift>();
return JaktInternal::ExplicitValue( parser::BinaryOperator { typename parser::BinaryOperator::BitwiseLeftShift() } );
};/*case end*/
case 34: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::RightShift>();
return JaktInternal::ExplicitValue( parser::BinaryOperator { typename parser::BinaryOperator::BitwiseRightShift() } );
};/*case end*/
case 31: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::LeftArithmeticShift>();
return JaktInternal::ExplicitValue( parser::BinaryOperator { typename parser::BinaryOperator::ArithmeticLeftShift() } );
};/*case end*/
case 35: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::RightArithmeticShift>();
return JaktInternal::ExplicitValue( parser::BinaryOperator { typename parser::BinaryOperator::ArithmeticRightShift() } );
};/*case end*/
case 17: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::Equal>();
return JaktInternal::ExplicitValue( parser::BinaryOperator { typename parser::BinaryOperator::Assign() } );
};/*case end*/
case 33: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::LeftShiftEqual>();
return JaktInternal::ExplicitValue( parser::BinaryOperator { typename parser::BinaryOperator::BitwiseLeftShiftAssign() } );
};/*case end*/
case 36: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::RightShiftEqual>();
return JaktInternal::ExplicitValue( parser::BinaryOperator { typename parser::BinaryOperator::BitwiseRightShiftAssign() } );
};/*case end*/
case 39: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::AmpersandEqual>();
return JaktInternal::ExplicitValue( parser::BinaryOperator { typename parser::BinaryOperator::BitwiseAndAssign() } );
};/*case end*/
case 42: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::PipeEqual>();
return JaktInternal::ExplicitValue( parser::BinaryOperator { typename parser::BinaryOperator::BitwiseOrAssign() } );
};/*case end*/
case 45: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::CaretEqual>();
return JaktInternal::ExplicitValue( parser::BinaryOperator { typename parser::BinaryOperator::BitwiseXorAssign() } );
};/*case end*/
case 18: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::PlusEqual>();
return JaktInternal::ExplicitValue( parser::BinaryOperator { typename parser::BinaryOperator::AddAssign() } );
};/*case end*/
case 20: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::MinusEqual>();
return JaktInternal::ExplicitValue( parser::BinaryOperator { typename parser::BinaryOperator::SubtractAssign() } );
};/*case end*/
case 22: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::AsteriskEqual>();
return JaktInternal::ExplicitValue( parser::BinaryOperator { typename parser::BinaryOperator::MultiplyAssign() } );
};/*case end*/
case 23: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::ForwardSlashEqual>();
return JaktInternal::ExplicitValue( parser::BinaryOperator { typename parser::BinaryOperator::DivideAssign() } );
};/*case end*/
case 24: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::PercentSignEqual>();
return JaktInternal::ExplicitValue( parser::BinaryOperator { typename parser::BinaryOperator::ModuloAssign() } );
};/*case end*/
case 52: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::QuestionMarkQuestionMarkEqual>();
return JaktInternal::ExplicitValue( parser::BinaryOperator { typename parser::BinaryOperator::NoneCoalescingAssign() } );
};/*case end*/
default: {
{
return (TRY((parser::ParsedExpression::template create<typename parser::ParsedExpression::Garbage>(span))));
}
};/*case end*/
}/*switch end*/
}()
));
((((*this).index)++));
if (((!(allow_assignments)) && ((op).is_assignment()))){
TRY((((*this).error(Jakt::DeprecatedString("Assignment is not allowed in this position"sv),span))));
return (TRY((parser::ParsedExpression::template create<typename parser::ParsedExpression::Operator>(op,span))));
}
return (TRY((parser::ParsedExpression::template create<typename parser::ParsedExpression::Operator>(op,span))));
}
}

ErrorOr<NonnullRefPtr<typename parser::ParsedStatement>> parser::Parser::parse_for_statement() {
{
utility::Span const start_span = ((((*this).current())).span());
((((*this).index)++));
DeprecatedString iterator_name = Jakt::DeprecatedString(""sv);
JaktInternal::DynamicArray<parser::ParsedVarDecl> destructured_var_decls = (TRY((DynamicArray<parser::ParsedVarDecl>::create_with({}))));
JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<void, ErrorOr<NonnullRefPtr<typename parser::ParsedStatement>>>{
auto&& __jakt_match_variant = ((*this).current());
switch(__jakt_match_variant.index()) {
case 4: {
auto&& __jakt_match_value = __jakt_match_variant.template get<lexer::Token::Identifier>();DeprecatedString const& name = __jakt_match_value.name;
{
(iterator_name = name);
((((*this).index)++));
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 8: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::LParen>();
{
(destructured_var_decls = TRY((((*this).parse_destructuring_assignment(false)))));
DeprecatedString tuple_var_name = Jakt::DeprecatedString(""sv);
{
JaktInternal::ArrayIterator<parser::ParsedVarDecl> _magic = ((destructured_var_decls).iterator());
for (;;){
JaktInternal::Optional<parser::ParsedVarDecl> _magic_value = ((_magic).next());
if ((!(((_magic_value).has_value())))){
break;
}
parser::ParsedVarDecl var = (_magic_value.value());
{
(tuple_var_name += ((var).name));
(tuple_var_name += Jakt::DeprecatedString("__"sv));
}

}
}

(iterator_name = tuple_var_name);
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
default: {
{
TRY((((*this).error(Jakt::DeprecatedString("Expected iterator name or destructuring pattern"sv),((((*this).current())).span())))));
return (TRY((parser::ParsedStatement::template create<typename parser::ParsedStatement::Garbage>(TRY((parser::merge_spans(start_span,((((*this).current())).span()))))))));
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
}/*switch end*/
}()
));
utility::Span const name_span = ((((*this).current())).span());
if (((((*this).current())).index() == 79 /* In */)){
((((*this).index)++));
}
else {
TRY((((*this).error(Jakt::DeprecatedString("Expected ‘in’"sv),((((*this).current())).span())))));
return (TRY((parser::ParsedStatement::template create<typename parser::ParsedStatement::Garbage>(TRY((parser::merge_spans(start_span,((((*this).current())).span()))))))));
}

bool const previous_can_have_trailing_closure = ((*this).can_have_trailing_closure);
(((*this).can_have_trailing_closure) = false);
NonnullRefPtr<typename parser::ParsedExpression> const range = TRY((((*this).parse_expression(false,false))));
(((*this).can_have_trailing_closure) = previous_can_have_trailing_closure);
parser::ParsedBlock block = TRY((((*this).parse_block())));
if ((((destructured_var_decls).size()) > static_cast<size_t>(0ULL))){
DeprecatedString tuple_var_name = Jakt::DeprecatedString("jakt__"sv);
(tuple_var_name += iterator_name);
parser::ParsedVarDecl tuple_var_decl = parser::ParsedVarDecl(tuple_var_name,TRY((parser::ParsedType::template create<typename parser::ParsedType::Empty>())),false,JaktInternal::OptionalNone(),((((*this).current())).span()));
NonnullRefPtr<typename parser::ParsedExpression> const init = TRY((parser::ParsedExpression::template create<typename parser::ParsedExpression::Var>(iterator_name,TRY((parser::merge_spans(start_span,((((*this).previous())).span())))))));
NonnullRefPtr<typename parser::ParsedStatement> const var_decl = TRY((parser::ParsedStatement::template create<typename parser::ParsedStatement::VarDecl>(tuple_var_decl,init,TRY((parser::merge_spans(start_span,((((*this).previous())).span())))))));
NonnullRefPtr<typename parser::ParsedStatement> const destructured_vars_stmt = TRY((parser::ParsedStatement::template create<typename parser::ParsedStatement::DestructuringAssignment>(destructured_var_decls,var_decl,TRY((parser::merge_spans(start_span,((((*this).previous())).span())))))));
JaktInternal::DynamicArray<NonnullRefPtr<typename parser::ParsedStatement>> block_stmts = (TRY((DynamicArray<NonnullRefPtr<typename parser::ParsedStatement>>::create_with({}))));
TRY((((block_stmts).push(destructured_vars_stmt))));
TRY((((block_stmts).push_values(((((block).stmts)))))));
(((block).stmts) = block_stmts);
}
return (TRY((parser::ParsedStatement::template create<typename parser::ParsedStatement::For>(iterator_name,name_span,range,block,TRY((parser::merge_spans(start_span,((((*this).previous())).span()))))))));
}
}

ErrorOr<JaktInternal::DynamicArray<parser::ParsedParameter>> parser::Parser::parse_function_parameters() {
{
if (((((*this).current())).index() == 8 /* LParen */)){
((((*this).index)++));
}
else {
TRY((((*this).error(Jakt::DeprecatedString("Expected '('"sv),((((*this).current())).span())))));
}

((*this).skip_newlines());
JaktInternal::DynamicArray<parser::ParsedParameter> params = (TRY((DynamicArray<parser::ParsedParameter>::create_with({}))));
bool current_param_requires_label = true;
bool current_param_is_mutable = false;
bool error = false;
bool parameter_complete = false;
while ((!(((*this).eof())))){
JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_AT_LOOP(([&]() -> JaktInternal::ExplicitValueOrControlFlow<void, ErrorOr<JaktInternal::DynamicArray<parser::ParsedParameter>>>{
auto&& __jakt_match_variant = ((*this).current());
switch(__jakt_match_variant.index()) {
case 9: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::RParen>();
{
((((*this).index)++));
return JaktInternal::LoopBreak{};
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 53: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::Comma>();
{
if (((!(parameter_complete)) && (!(error)))){
TRY((((*this).error(Jakt::DeprecatedString("Expected parameter"sv),((((*this).current())).span())))));
(error = true);
}
((((*this).index)++));
(current_param_requires_label = true);
(current_param_is_mutable = false);
(parameter_complete = false);
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 56: {
auto&& __jakt_match_value = __jakt_match_variant.template get<lexer::Token::Eol>();{
if (((!(parameter_complete)) && (!(error)))){
TRY((((*this).error(Jakt::DeprecatedString("Expected parameter"sv),((((*this).current())).span())))));
(error = true);
}
((((*this).index)++));
(current_param_requires_label = true);
(current_param_is_mutable = false);
(parameter_complete = false);
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 61: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::Anon>();
{
if ((parameter_complete && (!(error)))){
TRY((((*this).error(Jakt::DeprecatedString("‘anon’ must appear at start of parameter declaration, not the end"sv),((((*this).current())).span())))));
(error = true);
}
if ((current_param_is_mutable && (!(error)))){
TRY((((*this).error(Jakt::DeprecatedString("‘anon’ must appear before ‘mut’"sv),((((*this).current())).span())))));
(error = true);
}
if (((!(current_param_requires_label)) && (!(error)))){
TRY((((*this).error(Jakt::DeprecatedString("‘anon’ cannot appear multiple times in one parameter declaration"sv),((((*this).current())).span())))));
(error = true);
}
((((*this).index)++));
(current_param_requires_label = false);
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 84: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::Mut>();
{
if ((parameter_complete && (!(error)))){
TRY((((*this).error(Jakt::DeprecatedString("‘mut’ must appear at start of parameter declaration, not the end"sv),((((*this).current())).span())))));
(error = true);
}
if ((current_param_is_mutable && (!(error)))){
TRY((((*this).error(Jakt::DeprecatedString("‘mut’ cannot appear multiple times in one parameter declaration"sv),((((*this).current())).span())))));
(error = true);
}
((((*this).index)++));
(current_param_is_mutable = true);
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 95: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::This>();
{
TRY((((params).push(parser::ParsedParameter(false,parser::ParsedVariable(Jakt::DeprecatedString("this"sv),TRY((parser::ParsedType::template create<typename parser::ParsedType::Empty>())),current_param_is_mutable,((((*this).current())).span())),JaktInternal::OptionalNone(),((((*this).current())).span()))))));
((((*this).index)++));
(parameter_complete = true);
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 4: {
auto&& __jakt_match_value = __jakt_match_variant.template get<lexer::Token::Identifier>();DeprecatedString const& name = __jakt_match_value.name;
utility::Span const& span = __jakt_match_value.span;
{
parser::ParsedVarDecl const var_decl = TRY((((*this).parse_variable_declaration(current_param_is_mutable))));
JaktInternal::Optional<NonnullRefPtr<typename parser::ParsedExpression>> default_argument = JaktInternal::OptionalNone();
if (((((*this).current())).index() == 17 /* Equal */)){
((((*this).index)++));
(default_argument = TRY((((*this).parse_expression(false,true)))));
}
TRY((((params).push(parser::ParsedParameter(current_param_requires_label,parser::ParsedVariable(((var_decl).name),((var_decl).parsed_type),((var_decl).is_mutable),((((*this).previous())).span())),default_argument,((((*this).previous())).span()))))));
(parameter_complete = true);
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
default: {
{
if ((!(error))){
TRY((((*this).error(Jakt::DeprecatedString("Expected parameter"sv),((((*this).current())).span())))));
(error = true);
}
((((*this).index)++));
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
}/*switch end*/
}()
));
}
return (params);
}
}

ErrorOr<JaktInternal::Optional<parser::ParsedCall>> parser::Parser::parse_call() {
{
parser::ParsedCall call = parser::ParsedCall((TRY((DynamicArray<DeprecatedString>::create_with({})))),Jakt::DeprecatedString(""sv),(TRY((DynamicArray<JaktInternal::Tuple<DeprecatedString,utility::Span,NonnullRefPtr<typename parser::ParsedExpression>>>::create_with({})))),(TRY((DynamicArray<NonnullRefPtr<typename parser::ParsedType>>::create_with({})))));
if (((((*this).current())).index() == 4 /* Identifier */)){
DeprecatedString const name = ((((*this).current())).get<lexer::Token::Identifier>()).name;
(((call).name) = name);
((((*this).index)++));
size_t const index_reset = ((*this).index);
if (((((*this).current())).index() == 29 /* LessThan */)){
((((*this).index)++));
JaktInternal::DynamicArray<NonnullRefPtr<typename parser::ParsedType>> inner_types = (TRY((DynamicArray<NonnullRefPtr<typename parser::ParsedType>>::create_with({}))));
while ((!(((*this).eof())))){
JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_AT_LOOP(([&]() -> JaktInternal::ExplicitValueOrControlFlow<void, ErrorOr<JaktInternal::Optional<parser::ParsedCall>>>{
auto&& __jakt_match_variant = ((*this).current());
switch(__jakt_match_variant.index()) {
case 27: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::GreaterThan>();
{
((((*this).index)++));
return JaktInternal::LoopBreak{};
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 34: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::RightShift>();
{
TRY((((*this).inject_token( lexer::Token { typename lexer::Token::GreaterThan(((((*this).current())).span())) } ))));
((((*this).index)++));
return JaktInternal::LoopBreak{};
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 53: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::Comma>();
{
((((*this).index)++));
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 56: {
auto&& __jakt_match_value = __jakt_match_variant.template get<lexer::Token::Eol>();{
((((*this).index)++));
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
default: {
{
size_t const index_before = ((*this).index);
NonnullRefPtr<typename parser::ParsedType> const inner_type = TRY((((*this).parse_typename())));
if ((index_before == ((*this).index))){
(((*this).index) = index_reset);
return JaktInternal::LoopBreak{};
}
TRY((((inner_types).push(inner_type))));
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
}/*switch end*/
}()
));
}
(((call).type_args) = inner_types);
}
if (((((*this).current())).index() == 8 /* LParen */)){
((((*this).index)++));
}
else {
(((*this).index) = index_reset);
TRY((((*this).error(Jakt::DeprecatedString("Expected '('"sv),((((*this).current())).span())))));
return (JaktInternal::OptionalNone());
}

while ((!(((*this).eof())))){
JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_AT_LOOP(([&]() -> JaktInternal::ExplicitValueOrControlFlow<void, ErrorOr<JaktInternal::Optional<parser::ParsedCall>>>{
auto&& __jakt_match_variant = ((*this).current());
switch(__jakt_match_variant.index()) {
case 9: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::RParen>();
{
((((*this).index)++));
return JaktInternal::LoopBreak{};
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 56: {
auto&& __jakt_match_value = __jakt_match_variant.template get<lexer::Token::Eol>();{
((((*this).index)++));
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 53: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::Comma>();
{
((((*this).index)++));
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
default: {
{
utility::Span const label_span = ((((*this).current())).span());
DeprecatedString const label = TRY((((*this).parse_argument_label())));
NonnullRefPtr<typename parser::ParsedExpression> const expr = TRY((((*this).parse_expression(false,false))));
TRY((((((call).args)).push((Tuple{label, label_span, expr})))));
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
}/*switch end*/
}()
));
}
if ((((*this).can_have_trailing_closure) && ((((*this).current())).index() == 10 /* LCurly */))){
utility::Span const start = ((((*this).current())).span());
parser::ParsedBlock const block = TRY((((*this).parse_block())));
utility::Span const span = TRY((parser::merge_spans(start,((((*this).current())).span()))));
JaktInternal::DynamicArray<parser::ParsedCapture> const captures = (TRY((DynamicArray<parser::ParsedCapture>::create_with({ parser::ParsedCapture { typename parser::ParsedCapture::AllByReference(((*this).empty_span())) } }))));
NonnullRefPtr<typename parser::ParsedExpression> const trailing_closure = TRY((parser::ParsedExpression::template create<typename parser::ParsedExpression::Function>(captures,(TRY((DynamicArray<parser::ParsedParameter>::create_with({})))),false,false,TRY((parser::ParsedType::template create<typename parser::ParsedType::Empty>())),block,span)));
NonnullRefPtr<typename parser::ParsedExpression> const reference_to_closure = TRY((parser::ParsedExpression::template create<typename parser::ParsedExpression::UnaryOp>(trailing_closure, parser::UnaryOperator { typename parser::UnaryOperator::Reference() } ,span)));
TRY((((((call).args)).push((Tuple{Jakt::DeprecatedString(""sv), ((*this).empty_span()), reference_to_closure})))));
}
return (call);
}
else {
TRY((((*this).error(Jakt::DeprecatedString("Expected function call"sv),((((*this).current())).span())))));
return (call);
}

}
}

ErrorOr<NonnullRefPtr<typename parser::ParsedExpression>> parser::Parser::parse_array_or_dictionary_literal() {
{
bool is_dictionary = false;
utility::Span const start = ((((*this).current())).span());
if ((!(((((*this).current())).index() == 12 /* LSquare */)))){
TRY((((*this).error(Jakt::DeprecatedString("Expected ‘[’"sv),((((*this).current())).span())))));
return (TRY((parser::ParsedExpression::template create<typename parser::ParsedExpression::Garbage>(((((*this).current())).span())))));
}
((((*this).index)++));
JaktInternal::Optional<NonnullRefPtr<typename parser::ParsedExpression>> fill_size_expr = JaktInternal::OptionalNone();
JaktInternal::DynamicArray<NonnullRefPtr<typename parser::ParsedExpression>> output = (TRY((DynamicArray<NonnullRefPtr<typename parser::ParsedExpression>>::create_with({}))));
JaktInternal::DynamicArray<JaktInternal::Tuple<NonnullRefPtr<typename parser::ParsedExpression>,NonnullRefPtr<typename parser::ParsedExpression>>> dict_output = (TRY((DynamicArray<JaktInternal::Tuple<NonnullRefPtr<typename parser::ParsedExpression>,NonnullRefPtr<typename parser::ParsedExpression>>>::create_with({}))));
while ((!(((*this).eof())))){
JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_AT_LOOP(([&]() -> JaktInternal::ExplicitValueOrControlFlow<void, ErrorOr<NonnullRefPtr<typename parser::ParsedExpression>>>{
auto&& __jakt_match_variant = ((*this).current());
switch(__jakt_match_variant.index()) {
case 13: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::RSquare>();
{
((((*this).index)++));
return JaktInternal::LoopBreak{};
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 53: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::Comma>();
{
((((*this).index)++));
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 56: {
auto&& __jakt_match_value = __jakt_match_variant.template get<lexer::Token::Eol>();{
((((*this).index)++));
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 5: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::Semicolon>();
{
if ((((output).size()) == static_cast<size_t>(1ULL))){
((((*this).index)++));
(fill_size_expr = TRY((((*this).parse_expression(false,false)))));
}
else {
TRY((((*this).error(Jakt::DeprecatedString("Can't fill an Array with more than one expression"sv),((((*this).current())).span())))));
((((*this).index)++));
}

}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 6: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::Colon>();
{
((((*this).index)++));
if (((dict_output).is_empty())){
if (((((*this).current())).index() == 13 /* RSquare */)){
((((*this).index)++));
(is_dictionary = true);
return JaktInternal::LoopBreak{};
}
else {
TRY((((*this).error(Jakt::DeprecatedString("Expected ‘]’"sv),((((*this).current())).span())))));
}

}
else {
TRY((((*this).error(Jakt::DeprecatedString("Missing key in dictionary literal"sv),((((*this).current())).span())))));
}

}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
default: {
{
NonnullRefPtr<typename parser::ParsedExpression> const expr = TRY((((*this).parse_expression(false,false))));
if (((expr)->index() == 28 /* Garbage */)){
return JaktInternal::LoopBreak{};
}
if (((((*this).current())).index() == 6 /* Colon */)){
if ((!(((output).is_empty())))){
TRY((((*this).error(Jakt::DeprecatedString("Mixing dictionary and array values"sv),((((*this).current())).span())))));
}
(is_dictionary = true);
((((*this).index)++));
if (((*this).eof())){
TRY((((*this).error(Jakt::DeprecatedString("Key missing value in dictionary"sv),((((*this).current())).span())))));
return (TRY((parser::ParsedExpression::template create<typename parser::ParsedExpression::Garbage>(((((*this).current())).span())))));
}
NonnullRefPtr<typename parser::ParsedExpression> const value = TRY((((*this).parse_expression(false,false))));
TRY((((dict_output).push((Tuple{expr, value})))));
}
else if ((!(is_dictionary))){
TRY((((output).push(expr))));
}
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
}/*switch end*/
}()
));
}
size_t const end = (JaktInternal::checked_sub<size_t>(((*this).index),static_cast<size_t>(1ULL)));
if (((end >= ((((*this).tokens)).size())) || (!(((((((*this).tokens))[end])).index() == 13 /* RSquare */))))){
TRY((((*this).error(Jakt::DeprecatedString("Expected ‘]’ to close the array"sv),((((((*this).tokens))[end])).span())))));
}
if (is_dictionary){
return (TRY((parser::ParsedExpression::template create<typename parser::ParsedExpression::JaktDictionary>(dict_output,TRY((parser::merge_spans(start,((((((*this).tokens))[end])).span()))))))));
}
else {
return (TRY((parser::ParsedExpression::template create<typename parser::ParsedExpression::JaktArray>(output,fill_size_expr,TRY((parser::merge_spans(start,((((((*this).tokens))[end])).span()))))))));
}

}
}

ErrorOr<NonnullRefPtr<typename parser::ParsedExpression>> parser::Parser::parse_operand() {
{
((*this).skip_newlines());
utility::Span const start = ((((*this).current())).span());
((*this).skip_newlines());
NonnullRefPtr<typename parser::ParsedExpression> expr = TRY((((*this).parse_operand_base())));
return (TRY((((*this).parse_operand_postfix_operator(start,expr)))));
}
}

ErrorOr<parser::ParsedNamespace> parser::Parser::parse(NonnullRefPtr<compiler::Compiler> const compiler,JaktInternal::DynamicArray<lexer::Token> const tokens) {
{
parser::Parser parser = parser::Parser(static_cast<size_t>(0ULL),tokens,compiler,true);
return (TRY((((parser).parse_namespace()))));
}
}

ErrorOr<parser::ParsedExternImport> parser::Parser::parse_extern_import(parser::ParsedNamespace& parent) {
{
parser::ParsedExternImport parsed_import = parser::ParsedExternImport(false,parser::ParsedNamespace(JaktInternal::OptionalNone(),JaktInternal::OptionalNone(),(TRY((DynamicArray<parser::ParsedFunction>::create_with({})))),(TRY((DynamicArray<parser::ParsedRecord>::create_with({})))),(TRY((DynamicArray<parser::ParsedTrait>::create_with({})))),(TRY((DynamicArray<parser::ParsedExternalTraitImplementation>::create_with({})))),(TRY((DynamicArray<parser::ParsedNamespace>::create_with({})))),(TRY((DynamicArray<parser::ParsedAlias>::create_with({})))),(TRY((DynamicArray<parser::ParsedModuleImport>::create_with({})))),(TRY((DynamicArray<parser::ParsedExternImport>::create_with({})))),JaktInternal::OptionalNone(),(TRY((DynamicArray<parser::IncludeAction>::create_with({})))),(TRY((DynamicArray<parser::IncludeAction>::create_with({}))))),(TRY((DynamicArray<parser::IncludeAction>::create_with({})))),(TRY((DynamicArray<parser::IncludeAction>::create_with({})))));
if (((((*this).current())).index() == 4 /* Identifier */)){
DeprecatedString const name = ((((*this).current())).get<lexer::Token::Identifier>()).name;
utility::Span const span = ((((*this).current())).get<lexer::Token::Identifier>()).span;
((((*this).index)++));
if (((name == Jakt::DeprecatedString("c"sv)) || (name == Jakt::DeprecatedString("C"sv)))){
(((parsed_import).is_c) = true);
}
else {
TRY((((*this).error(Jakt::DeprecatedString("Expected 'c' or path after `import extern`"sv),((((*this).current())).span())))));
}

}
DeprecatedString const import_path = JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<DeprecatedString, ErrorOr<parser::ParsedExternImport>>{
auto&& __jakt_match_variant = ((*this).current());
switch(__jakt_match_variant.index()) {
case 2: {
auto&& __jakt_match_value = __jakt_match_variant.template get<lexer::Token::QuotedString>();DeprecatedString const& quote = __jakt_match_value.quote;
return JaktInternal::ExplicitValue(({ Optional<DeprecatedString> __jakt_var_79; {
((((*this).index)++));
__jakt_var_79 = quote; goto __jakt_label_76;

}
__jakt_label_76:; __jakt_var_79.release_value(); }));
};/*case end*/
default: {
return JaktInternal::ExplicitValue(({ Optional<DeprecatedString> __jakt_var_80; {
TRY((((*this).error(Jakt::DeprecatedString("Expected path after `import extern`"sv),((((*this).current())).span())))));
__jakt_var_80 = Jakt::DeprecatedString(""sv); goto __jakt_label_77;

}
__jakt_label_77:; __jakt_var_80.release_value(); }));
};/*case end*/
}/*switch end*/
}()
));
if (((((*this).current())).index() == 62 /* As */)){
((((*this).index)++));
if (((((*this).current())).index() == 4 /* Identifier */)){
DeprecatedString const name = ((((*this).current())).get<lexer::Token::Identifier>()).name;
utility::Span const span = ((((*this).current())).get<lexer::Token::Identifier>()).span;
((((*this).index)++));
(((((parsed_import).assigned_namespace)).name) = name);
(((((parsed_import).assigned_namespace)).name_span) = span);
}
else {
TRY((((*this).error(Jakt::DeprecatedString("Expected name after 'as' keyword to name the extern import"sv),((((*this).current())).span())))));
}

}
if ((!(((((*this).current())).index() == 10 /* LCurly */)))){
TRY((((*this).error(Jakt::DeprecatedString("Expected '{' to start namespace for the extern import"sv),((((*this).current())).span())))));
}
((((*this).index)++));
(((parsed_import).assigned_namespace) = TRY((((*this).parse_namespace()))));
(((((parsed_import).assigned_namespace)).import_path_if_extern) = static_cast<JaktInternal::Optional<DeprecatedString>>(import_path));
(((((parsed_import).assigned_namespace)).generating_import_extern_before_include) = ((parsed_import).before_include));
(((((parsed_import).assigned_namespace)).generating_import_extern_after_include) = ((parsed_import).after_include));
if (((((*this).current())).index() == 11 /* RCurly */)){
((((*this).index)++));
}
else {
TRY((((*this).error(Jakt::DeprecatedString("Expected '}' to end namespace for the extern import"sv),((((*this).current())).span())))));
}

for (;;){
if (((((*this).current())).index() == 4 /* Identifier */)){
DeprecatedString const name = ((((*this).current())).get<lexer::Token::Identifier>()).name;
JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_AT_LOOP(([&]() -> JaktInternal::ExplicitValueOrControlFlow<void,ErrorOr<parser::ParsedExternImport>>{
auto __jakt_enum_value = (name);
if (__jakt_enum_value == Jakt::DeprecatedString("before_include"sv)) {
{
((((*this).index)++));
JaktInternal::Optional<JaktInternal::DynamicArray<parser::IncludeAction>> const actions = TRY((((*this).parse_include_action())));
if (((actions).has_value())){
TRY((((((parsed_import).before_include)).push_values((((actions.value())))))));
}
}
return JaktInternal::ExplicitValue<void>();
}
else if (__jakt_enum_value == Jakt::DeprecatedString("after_include"sv)) {
{
((((*this).index)++));
JaktInternal::Optional<JaktInternal::DynamicArray<parser::IncludeAction>> const actions = TRY((((*this).parse_include_action())));
if (((actions).has_value())){
TRY((((((parsed_import).after_include)).push_values((((actions.value())))))));
}
}
return JaktInternal::ExplicitValue<void>();
}
else {
{
return JaktInternal::LoopBreak{};
}
return JaktInternal::ExplicitValue<void>();
}
return JaktInternal::ExplicitValue<void>();
}()))
;
}
else {
break;
}

}
TRY((((((parent))).add_child_namespace(((parsed_import).assigned_namespace)))));
return (parsed_import);
}
}

ErrorOr<parser::ParsedModuleImport> parser::Parser::parse_module_import() {
{
parser::ParsedModuleImport parsed_import = parser::ParsedModuleImport( parser::ImportName { typename parser::ImportName::Literal(Jakt::DeprecatedString(""sv),((*this).empty_span())) } ,JaktInternal::OptionalNone(), parser::ImportList { typename parser::ImportList::List((TRY((DynamicArray<parser::ImportName>::create_with({}))))) } );
(((parsed_import).module_name) = JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<parser::ImportName, ErrorOr<parser::ParsedModuleImport>>{
auto&& __jakt_match_variant = ((*this).current());
switch(__jakt_match_variant.index()) {
case 4: {
auto&& __jakt_match_value = __jakt_match_variant.template get<lexer::Token::Identifier>();DeprecatedString const& name = __jakt_match_value.name;
utility::Span const& span = __jakt_match_value.span;
return JaktInternal::ExplicitValue(JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<parser::ImportName, ErrorOr<parser::ParsedModuleImport>>{
auto&& __jakt_match_variant = ((*this).peek(static_cast<size_t>(1ULL)));
switch(__jakt_match_variant.index()) {
case 8: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::LParen>();
return JaktInternal::ExplicitValue(({ Optional<parser::ImportName> __jakt_var_81; {
bool const previous_can_have_trailing_closure = ((*this).can_have_trailing_closure);
(((*this).can_have_trailing_closure) = false);
NonnullRefPtr<typename parser::ParsedExpression> const expression = TRY((parser::ParsedExpression::template create<typename parser::ParsedExpression::Call>((TRY((((*this).parse_call()))).value()),span)));
(((*this).can_have_trailing_closure) = previous_can_have_trailing_closure);
((((*this).index)--));
__jakt_var_81 =  parser::ImportName { typename parser::ImportName::Comptime(expression) } ; goto __jakt_label_78;

}
__jakt_label_78:; __jakt_var_81.release_value(); }));
};/*case end*/
default: {
return JaktInternal::ExplicitValue( parser::ImportName { typename parser::ImportName::Literal(name,span) } );
};/*case end*/
}/*switch end*/
}()
)));
};/*case end*/
default: {
{
TRY((((*this).error(Jakt::DeprecatedString("Expected module name"sv),((((*this).current())).span())))));
return (parsed_import);
}
};/*case end*/
}/*switch end*/
}()
)));
((((*this).index)++));
if (((*this).eol())){
return (parsed_import);
}
if ((!(((((*this).current())).index() == 10 /* LCurly */)))){
DeprecatedString module_name = ((((parsed_import).module_name)).literal_name());
utility::Span module_span = ((((parsed_import).module_name)).span());
while (((((*this).current())).index() == 7 /* ColonColon */)){
((((*this).index)++));
(module_name += Jakt::DeprecatedString("::"sv));
JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_AT_LOOP(([&]() -> JaktInternal::ExplicitValueOrControlFlow<void, ErrorOr<parser::ParsedModuleImport>>{
auto&& __jakt_match_variant = ((*this).current());
switch(__jakt_match_variant.index()) {
case 4: {
auto&& __jakt_match_value = __jakt_match_variant.template get<lexer::Token::Identifier>();DeprecatedString const& name = __jakt_match_value.name;
utility::Span const& span = __jakt_match_value.span;
{
(module_name += name);
(module_span = TRY((parser::merge_spans(module_span,span))));
((((*this).index)++));
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 62: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::As>();
{
return JaktInternal::LoopBreak{};
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 10: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::LCurly>();
{
return JaktInternal::LoopBreak{};
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
default: {
{
TRY((((*this).error(Jakt::DeprecatedString("Expected module name fragment"sv),((((*this).current())).span())))));
return (parsed_import);
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
}/*switch end*/
}()
));
}
(((parsed_import).module_name) =  parser::ImportName { typename parser::ImportName::Literal(module_name,module_span) } );
}
if (((((*this).current())).index() == 62 /* As */)){
((((*this).index)++));
if (((((*this).current())).index() == 4 /* Identifier */)){
DeprecatedString const name = ((((*this).current())).get<lexer::Token::Identifier>()).name;
utility::Span const span = ((((*this).current())).get<lexer::Token::Identifier>()).span;
((((*this).index)++));
(((parsed_import).alias_name) =  parser::ImportName { typename parser::ImportName::Literal(name,span) } );
}
else {
TRY((((*this).error(Jakt::DeprecatedString("Expected name"sv),((((*this).current())).span())))));
((((*this).index)++));
}

}
if (((*this).eol())){
return (parsed_import);
}
if ((!(((((*this).current())).index() == 10 /* LCurly */)))){
TRY((((*this).error(Jakt::DeprecatedString("Expected '{'"sv),((((*this).current())).span())))));
}
((((*this).index)++));
while ((!(((*this).eof())))){
JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_AT_LOOP(([&]() -> JaktInternal::ExplicitValueOrControlFlow<void, ErrorOr<parser::ParsedModuleImport>>{
auto&& __jakt_match_variant = ((*this).current());
switch(__jakt_match_variant.index()) {
case 4: {
auto&& __jakt_match_value = __jakt_match_variant.template get<lexer::Token::Identifier>();DeprecatedString const& name = __jakt_match_value.name;
utility::Span const& span = __jakt_match_value.span;
{
if (((((parsed_import).import_list)).index() == 0 /* List */)){
JaktInternal::DynamicArray<parser::ImportName> const names = ((((parsed_import).import_list)).get<parser::ImportList::List>()).value;
JaktInternal::DynamicArray<parser::ImportName> mutable_names = names;
TRY((((mutable_names).push( parser::ImportName { typename parser::ImportName::Literal(name,span) } ))));
}
else {
TRY((((*this).error_with_hint(TRY((__jakt_format(Jakt::DeprecatedString("Already importing everything from '{}'"sv),((((parsed_import).module_name)).literal_name())))),((((*this).current())).span()),Jakt::DeprecatedString("Remove the '*' to import specific names"sv),((((*this).current())).span())))));
}

((((*this).index)++));
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 37: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::Asterisk>();
{
if (((((parsed_import).import_list)).index() == 0 /* List */)){
JaktInternal::DynamicArray<parser::ImportName> const names = ((((parsed_import).import_list)).get<parser::ImportList::List>()).value;
if (((names).is_empty())){
(((parsed_import).import_list) =  parser::ImportList { typename parser::ImportList::All() } );
}
else {
if (((((parsed_import).import_list)).index() == 1 /* All */)){
TRY((((*this).error(TRY((__jakt_format(Jakt::DeprecatedString("Cannot repeat '*' in import list for '{}'"sv),((((parsed_import).module_name)).literal_name())))),((((*this).current())).span())))));
}
else {
TRY((((*this).error(TRY((__jakt_format(Jakt::DeprecatedString("Cannot mix '*' and specific names in import list for '{}'"sv),((((parsed_import).module_name)).literal_name())))),((((*this).current())).span())))));
}

}

}
else {
if (((((parsed_import).import_list)).index() == 1 /* All */)){
TRY((((*this).error(TRY((__jakt_format(Jakt::DeprecatedString("Cannot repeat '*' in import list for '{}'"sv),((((parsed_import).module_name)).literal_name())))),((((*this).current())).span())))));
}
else {
TRY((((*this).error(TRY((__jakt_format(Jakt::DeprecatedString("Cannot mix '*' and specific names in import list for '{}'"sv),((((parsed_import).module_name)).literal_name())))),((((*this).current())).span())))));
}

}

((((*this).index)++));
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 53: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::Comma>();
{
((((*this).index)++));
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 56: {
auto&& __jakt_match_value = __jakt_match_variant.template get<lexer::Token::Eol>();{
((((*this).index)++));
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 11: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::RCurly>();
{
((((*this).index)++));
return JaktInternal::LoopBreak{};
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
default: {
{
TRY((((*this).error(Jakt::DeprecatedString("Expected import symbol"sv),((((*this).current())).span())))));
((((*this).index)++));
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
}/*switch end*/
}()
));
}
return (parsed_import);
}
}

ErrorOr<parser::ParsedNamespace> parser::Parser::parse_namespace() {
{
parser::ParsedNamespace parsed_namespace = parser::ParsedNamespace(JaktInternal::OptionalNone(),JaktInternal::OptionalNone(),(TRY((DynamicArray<parser::ParsedFunction>::create_with({})))),(TRY((DynamicArray<parser::ParsedRecord>::create_with({})))),(TRY((DynamicArray<parser::ParsedTrait>::create_with({})))),(TRY((DynamicArray<parser::ParsedExternalTraitImplementation>::create_with({})))),(TRY((DynamicArray<parser::ParsedNamespace>::create_with({})))),(TRY((DynamicArray<parser::ParsedAlias>::create_with({})))),(TRY((DynamicArray<parser::ParsedModuleImport>::create_with({})))),(TRY((DynamicArray<parser::ParsedExternImport>::create_with({})))),JaktInternal::OptionalNone(),(TRY((DynamicArray<parser::IncludeAction>::create_with({})))),(TRY((DynamicArray<parser::IncludeAction>::create_with({})))));
JaktInternal::DynamicArray<parser::ParsedAttribute> active_attributes = (TRY((DynamicArray<parser::ParsedAttribute>::create_with({}))));
while ((!(((*this).eof())))){
JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_AT_LOOP(([&]() -> JaktInternal::ExplicitValueOrControlFlow<void, ErrorOr<parser::ParsedNamespace>>{
auto&& __jakt_match_variant = ((*this).current());
switch(__jakt_match_variant.index()) {
case 108: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::Trait>();
{
if ((!(((active_attributes).is_empty())))){
TRY((((*this).error(Jakt::DeprecatedString("Cannot apply attributes to trait declarations"sv),((((active_attributes)[static_cast<i64>(0LL)])).span)))));
(active_attributes = (TRY((DynamicArray<parser::ParsedAttribute>::create_with({})))));
}
((((*this).index)++));
TRY((((((parsed_namespace).traits)).push(TRY((((*this).parse_trait())))))));
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 4: {
auto&& __jakt_match_value = __jakt_match_variant.template get<lexer::Token::Identifier>();DeprecatedString const& name = __jakt_match_value.name;
return (JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_AT_LOOP_NESTED_MATCH(([&]() -> JaktInternal::ExplicitValueOrControlFlow<void,ErrorOr<parser::ParsedNamespace>>{
auto __jakt_enum_value = (name);
if (__jakt_enum_value == Jakt::DeprecatedString("type"sv)) {
{
if ((!(((active_attributes).is_empty())))){
TRY((((*this).error(Jakt::DeprecatedString("Cannot apply attributes to external trait declarations"sv),((((active_attributes)[static_cast<i64>(0LL)])).span)))));
(active_attributes = (TRY((DynamicArray<parser::ParsedAttribute>::create_with({})))));
}
((((*this).index)++));
TRY((((((parsed_namespace).external_trait_implementations)).push(TRY((((*this).parse_external_trait_implementation())))))));
}
return JaktInternal::ExplicitValue<void>();
}
else if (__jakt_enum_value == Jakt::DeprecatedString("use"sv)) {
{
if ((!(((active_attributes).is_empty())))){
TRY((((*this).error(Jakt::DeprecatedString("Cannot apply attributes to use declarations"sv),((((active_attributes)[static_cast<i64>(0LL)])).span)))));
(active_attributes = (TRY((DynamicArray<parser::ParsedAttribute>::create_with({})))));
}
((((*this).index)++));
TRY((((((parsed_namespace).aliases)).push(TRY((((*this).parse_using())))))));
}
return JaktInternal::ExplicitValue<void>();
}
else {
{
(active_attributes = (TRY((DynamicArray<parser::ParsedAttribute>::create_with({})))));
TRY((((*this).error(Jakt::DeprecatedString("Unexpected token (expected keyword)"sv),((((*this).current())).span())))));
return JaktInternal::LoopBreak{};
}
return JaktInternal::ExplicitValue<void>();
}
return JaktInternal::ExplicitValue<void>();
}()))
), JaktInternal::ExplicitValue<void>();
};/*case end*/
case 78: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::Import>();
{
if ((!(((active_attributes).is_empty())))){
TRY((((*this).error(Jakt::DeprecatedString("Cannot apply attributes to imports"sv),((((active_attributes)[static_cast<i64>(0LL)])).span)))));
(active_attributes = (TRY((DynamicArray<parser::ParsedAttribute>::create_with({})))));
}
((((*this).index)++));
TRY((((*this).parse_import(((parsed_namespace))))));
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 12: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::LSquare>();
{
if (((((*this).peek(static_cast<size_t>(1ULL)))).index() == 12 /* LSquare */)){
({auto& _jakt_ref = ((*this).index);_jakt_ref = JaktInternal::checked_add<size_t>(_jakt_ref, static_cast<size_t>(2ULL));});
TRY((((*this).parse_attribute_list(((active_attributes))))));
}
else {
TRY((((*this).error(Jakt::DeprecatedString("Unexpected token (expected ‘[[’)"sv),((((*this).current())).span())))));
({auto& _jakt_ref = ((*this).index);_jakt_ref = JaktInternal::checked_add<size_t>(_jakt_ref, static_cast<size_t>(1ULL));});
}

}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 75: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::Function>();
{
parser::ParsedFunction parsed_function = TRY((((*this).parse_function( parser::FunctionLinkage { typename parser::FunctionLinkage::Internal() } , parser::Visibility { typename parser::Visibility::Public() } ,((((*this).current())).index() == 76 /* Comptime */),false))));
TRY((((*this).apply_attributes(((parsed_function)),((active_attributes))))));
(active_attributes = (TRY((DynamicArray<parser::ParsedAttribute>::create_with({})))));
TRY((((((parsed_namespace).functions)).push(parsed_function))));
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 76: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::Comptime>();
{
parser::ParsedFunction parsed_function = TRY((((*this).parse_function( parser::FunctionLinkage { typename parser::FunctionLinkage::Internal() } , parser::Visibility { typename parser::Visibility::Public() } ,((((*this).current())).index() == 76 /* Comptime */),false))));
TRY((((*this).apply_attributes(((parsed_function)),((active_attributes))))));
(active_attributes = (TRY((DynamicArray<parser::ParsedAttribute>::create_with({})))));
TRY((((((parsed_namespace).functions)).push(parsed_function))));
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 94: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::Struct>();
{
parser::ParsedRecord parsed_record = TRY((((*this).parse_record( parser::DefinitionLinkage { typename parser::DefinitionLinkage::Internal() } ))));
TRY((((*this).apply_attributes(((parsed_record)),((active_attributes))))));
(active_attributes = (TRY((DynamicArray<parser::ParsedAttribute>::create_with({})))));
TRY((((((parsed_namespace).records)).push(parsed_record))));
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 66: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::Class>();
{
parser::ParsedRecord parsed_record = TRY((((*this).parse_record( parser::DefinitionLinkage { typename parser::DefinitionLinkage::Internal() } ))));
TRY((((*this).apply_attributes(((parsed_record)),((active_attributes))))));
(active_attributes = (TRY((DynamicArray<parser::ParsedAttribute>::create_with({})))));
TRY((((((parsed_namespace).records)).push(parsed_record))));
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 71: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::Enum>();
{
parser::ParsedRecord parsed_record = TRY((((*this).parse_record( parser::DefinitionLinkage { typename parser::DefinitionLinkage::Internal() } ))));
TRY((((*this).apply_attributes(((parsed_record)),((active_attributes))))));
(active_attributes = (TRY((DynamicArray<parser::ParsedAttribute>::create_with({})))));
TRY((((((parsed_namespace).records)).push(parsed_record))));
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 63: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::Boxed>();
{
parser::ParsedRecord parsed_record = TRY((((*this).parse_record( parser::DefinitionLinkage { typename parser::DefinitionLinkage::Internal() } ))));
TRY((((*this).apply_attributes(((parsed_record)),((active_attributes))))));
(active_attributes = (TRY((DynamicArray<parser::ParsedAttribute>::create_with({})))));
TRY((((((parsed_namespace).records)).push(parsed_record))));
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 85: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::Namespace>();
{
if ((!(((active_attributes).is_empty())))){
TRY((((*this).error(Jakt::DeprecatedString("Cannot apply attributes to namespaces"sv),((((active_attributes)[static_cast<i64>(0LL)])).span)))));
(active_attributes = (TRY((DynamicArray<parser::ParsedAttribute>::create_with({})))));
}
((((*this).index)++));
JaktInternal::Optional<JaktInternal::Tuple<DeprecatedString,utility::Span>> const name = JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_AT_LOOP_NESTED_MATCH(([&]() -> JaktInternal::ExplicitValueOrControlFlow<JaktInternal::Optional<JaktInternal::Tuple<DeprecatedString,utility::Span>>, ErrorOr<parser::ParsedNamespace>>{
auto&& __jakt_match_variant = ((*this).current());
switch(__jakt_match_variant.index()) {
case 4: {
auto&& __jakt_match_value = __jakt_match_variant.template get<lexer::Token::Identifier>();DeprecatedString const& name = __jakt_match_value.name;
utility::Span const& span = __jakt_match_value.span;
return JaktInternal::ExplicitValue(({ Optional<JaktInternal::Optional<JaktInternal::Tuple<DeprecatedString,utility::Span>>> __jakt_var_82; {
((((*this).index)++));
__jakt_var_82 = static_cast<JaktInternal::Optional<JaktInternal::Tuple<DeprecatedString,utility::Span>>>((Tuple{name, span})); goto __jakt_label_79;

}
__jakt_label_79:; __jakt_var_82.release_value(); }));
};/*case end*/
default: {
return JaktInternal::ExplicitValue(JaktInternal::OptionalNone());
};/*case end*/
}/*switch end*/
}()
));
((*this).skip_newlines());
if (((((*this).current())).index() == 10 /* LCurly */)){
((((*this).index)++));
}
else {
TRY((((*this).error(Jakt::DeprecatedString("Expected ‘{’"sv),((((*this).current())).span())))));
}

parser::ParsedNamespace namespace_ = TRY((((*this).parse_namespace())));
if (((((*this).current())).index() == 11 /* RCurly */)){
((((*this).index)++));
}
else {
TRY((((*this).error(Jakt::DeprecatedString("Incomplete namespace"sv),((((*this).previous())).span())))));
}

if (((name).has_value())){
(((namespace_).name) = (((name.value())).template get<0>()));
(((namespace_).name_span) = (((name.value())).template get<1>()));
}
TRY((((parsed_namespace).add_child_namespace(namespace_))));
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 72: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::Extern>();
{
((((*this).index)++));
JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_AT_LOOP_NESTED_MATCH(([&]() -> JaktInternal::ExplicitValueOrControlFlow<void, ErrorOr<parser::ParsedNamespace>>{
auto&& __jakt_match_variant = ((*this).current());
switch(__jakt_match_variant.index()) {
case 75: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::Function>();
{
parser::ParsedFunction parsed_function = TRY((((*this).parse_function( parser::FunctionLinkage { typename parser::FunctionLinkage::External() } , parser::Visibility { typename parser::Visibility::Public() } ,false,false))));
TRY((((*this).apply_attributes(((parsed_function)),((active_attributes))))));
(active_attributes = (TRY((DynamicArray<parser::ParsedAttribute>::create_with({})))));
TRY((((((parsed_namespace).functions)).push(parsed_function))));
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 94: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::Struct>();
{
parser::ParsedRecord parsed_struct = TRY((((*this).parse_struct( parser::DefinitionLinkage { typename parser::DefinitionLinkage::External() } ))));
TRY((((*this).apply_attributes(((parsed_struct)),((active_attributes))))));
(active_attributes = (TRY((DynamicArray<parser::ParsedAttribute>::create_with({})))));
TRY((((((parsed_namespace).records)).push(parsed_struct))));
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 66: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::Class>();
{
parser::ParsedRecord parsed_class = TRY((((*this).parse_class( parser::DefinitionLinkage { typename parser::DefinitionLinkage::External() } ))));
TRY((((*this).apply_attributes(((parsed_class)),((active_attributes))))));
(active_attributes = (TRY((DynamicArray<parser::ParsedAttribute>::create_with({})))));
TRY((((((parsed_namespace).records)).push(parsed_class))));
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
default: {
{
(active_attributes = (TRY((DynamicArray<parser::ParsedAttribute>::create_with({})))));
TRY((((*this).error(Jakt::DeprecatedString("Unexpected keyword"sv),((((*this).current())).span())))));
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
}/*switch end*/
}()
));
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 56: {
auto&& __jakt_match_value = __jakt_match_variant.template get<lexer::Token::Eol>();{
((((*this).index)++));
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 11: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::RCurly>();
{
return JaktInternal::LoopBreak{};
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
default: {
{
TRY((((*this).error(Jakt::DeprecatedString("Unexpected token (expected keyword)"sv),((((*this).current())).span())))));
return JaktInternal::LoopBreak{};
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
}/*switch end*/
}()
));
}
return (parsed_namespace);
}
}

ErrorOr<NonnullRefPtr<typename parser::ParsedExpression>> parser::Parser::parse_ampersand() {
{
utility::Span const start = ((((*this).current())).span());
((((*this).index)++));
if (((((*this).current())).index() == 91 /* Raw */)){
((((*this).index)++));
NonnullRefPtr<typename parser::ParsedExpression> const expr = TRY((((*this).parse_operand())));
return (TRY((parser::ParsedExpression::template create<typename parser::ParsedExpression::UnaryOp>(expr, parser::UnaryOperator { typename parser::UnaryOperator::RawAddress() } ,TRY((parser::merge_spans(start,((expr)->span()))))))));
}
if (((((*this).current())).index() == 84 /* Mut */)){
((((*this).index)++));
NonnullRefPtr<typename parser::ParsedExpression> const expr = TRY((((*this).parse_operand())));
return (TRY((parser::ParsedExpression::template create<typename parser::ParsedExpression::UnaryOp>(expr, parser::UnaryOperator { typename parser::UnaryOperator::MutableReference() } ,TRY((parser::merge_spans(start,((expr)->span()))))))));
}
NonnullRefPtr<typename parser::ParsedExpression> const expr = TRY((((*this).parse_operand())));
return (TRY((parser::ParsedExpression::template create<typename parser::ParsedExpression::UnaryOp>(expr, parser::UnaryOperator { typename parser::UnaryOperator::Reference() } ,TRY((parser::merge_spans(start,((expr)->span()))))))));
}
}

ErrorOr<JaktInternal::DynamicArray<parser::ParsedMatchCase>> parser::Parser::parse_match_cases() {
{
JaktInternal::DynamicArray<parser::ParsedMatchCase> cases = (TRY((DynamicArray<parser::ParsedMatchCase>::create_with({}))));
((*this).skip_newlines());
if ((!(((((*this).current())).index() == 10 /* LCurly */)))){
TRY((((*this).error(Jakt::DeprecatedString("Expected ‘{’"sv),((((*this).current())).span())))));
return (cases);
}
((((*this).index)++));
((*this).skip_newlines());
while (((!(((*this).eof()))) && (!(((((*this).current())).index() == 11 /* RCurly */))))){
utility::Span const marker_span = ((((*this).current())).span());
size_t const pattern_start_index = ((*this).index);
JaktInternal::DynamicArray<parser::ParsedMatchPattern> const patterns = TRY((((*this).parse_match_patterns())));
((*this).skip_newlines());
if (((((*this).current())).index() == 58 /* FatArrow */)){
((((*this).index)++));
}
else {
TRY((((*this).error(Jakt::DeprecatedString("Expected ‘=>’"sv),((((*this).current())).span())))));
}

((*this).skip_newlines());
parser::ParsedMatchBody const body = JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_AT_LOOP(([&]() -> JaktInternal::ExplicitValueOrControlFlow<parser::ParsedMatchBody, ErrorOr<JaktInternal::DynamicArray<parser::ParsedMatchCase>>>{
auto&& __jakt_match_variant = ((*this).current());
switch(__jakt_match_variant.index()) {
case 10: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::LCurly>();
return JaktInternal::ExplicitValue( parser::ParsedMatchBody { typename parser::ParsedMatchBody::Block(TRY((((*this).parse_block())))) } );
};/*case end*/
default: {
return JaktInternal::ExplicitValue( parser::ParsedMatchBody { typename parser::ParsedMatchBody::Expression(TRY((((*this).parse_expression(false,true))))) } );
};/*case end*/
}/*switch end*/
}()
));
{
JaktInternal::ArrayIterator<parser::ParsedMatchPattern> _magic = ((patterns).iterator());
for (;;){
JaktInternal::Optional<parser::ParsedMatchPattern> _magic_value = ((_magic).next());
if ((!(((_magic_value).has_value())))){
break;
}
parser::ParsedMatchPattern pattern = (_magic_value.value());
{
TRY((((cases).push(parser::ParsedMatchCase((TRY((DynamicArray<parser::ParsedMatchPattern>::create_with({pattern})))),marker_span,body)))));
}

}
}

if ((((*this).index) == pattern_start_index)){
break;
}
if ((((((*this).current())).index() == 56 /* Eol */) || ((((*this).current())).index() == 53 /* Comma */))){
((((*this).index)++));
}
((*this).skip_newlines());
}
((*this).skip_newlines());
if ((!(((((*this).current())).index() == 11 /* RCurly */)))){
TRY((((*this).error(Jakt::DeprecatedString("Expected ‘}’"sv),((((*this).current())).span())))));
}
((((*this).index)++));
return (cases);
}
}

ErrorOr<JaktInternal::Optional<parser::NumericConstant>> parser::Parser::make_float_numeric_constant(f64 const number,lexer::LiteralSuffix const suffix,utility::Span const span) {
{
return (JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<JaktInternal::Optional<parser::NumericConstant>, ErrorOr<JaktInternal::Optional<parser::NumericConstant>>>{
auto&& __jakt_match_variant = suffix;
switch(__jakt_match_variant.index()) {
case 10: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::LiteralSuffix::F32>();
return JaktInternal::ExplicitValue( parser::NumericConstant { typename parser::NumericConstant::F32(parser::f64_to_f32(number)) } );
};/*case end*/
case 11: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::LiteralSuffix::F64>();
return JaktInternal::ExplicitValue( parser::NumericConstant { typename parser::NumericConstant::F64(number) } );
};/*case end*/
default: {
return JaktInternal::ExplicitValue(JaktInternal::OptionalNone());
};/*case end*/
}/*switch end*/
}()
)));
}
}

ErrorOr<NonnullRefPtr<typename parser::ParsedExpression>> parser::Parser::parse_postfix_colon_colon(utility::Span const start,NonnullRefPtr<typename parser::ParsedExpression> const expr) {
{
((((*this).index)++));
JaktInternal::DynamicArray<DeprecatedString> namespace_ = (TRY((DynamicArray<DeprecatedString>::create_with({}))));
if (((expr)->index() == 9 /* Var */)){
DeprecatedString const name = ((expr)->get<parser::ParsedExpression::Var>()).name;
TRY((((namespace_).push(name))));
}
else {
TRY((((*this).error(Jakt::DeprecatedString("Expected namespace"sv),((expr)->span())))));
}

while ((!(((*this).eof())))){
if (((((*this).current())).index() == 4 /* Identifier */)){
DeprecatedString const current_name = ((((*this).current())).get<lexer::Token::Identifier>()).name;
((((*this).index)++));
if (((((*this).current())).index() == 8 /* LParen */)){
((((*this).index)--));
JaktInternal::Optional<parser::ParsedCall> call = TRY((((*this).parse_call())));
((((call.value())).namespace_) = namespace_);
return (TRY((parser::ParsedExpression::template create<typename parser::ParsedExpression::Call>((call.value()),TRY((parser::merge_spans(((expr)->span()),((((*this).current())).span()))))))));
}
if (((((*this).current())).index() == 29 /* LessThan */)){
((((*this).index)--));
JaktInternal::Optional<parser::ParsedCall> const maybe_call = TRY((((*this).parse_call())));
if (((maybe_call).has_value())){
parser::ParsedCall call = (maybe_call.value());
(((call).namespace_) = namespace_);
return (TRY((parser::ParsedExpression::template create<typename parser::ParsedExpression::Call>(call,TRY((parser::merge_spans(((expr)->span()),((((*this).current())).span()))))))));
}
return (TRY((parser::ParsedExpression::template create<typename parser::ParsedExpression::Garbage>(((((*this).current())).span())))));
}
if (((((*this).current())).index() == 7 /* ColonColon */)){
if (((((*this).previous())).index() == 4 /* Identifier */)){
DeprecatedString const name = ((((*this).previous())).get<lexer::Token::Identifier>()).name;
TRY((((namespace_).push(name))));
}
else {
TRY((((*this).error(Jakt::DeprecatedString("Expected namespace"sv),((expr)->span())))));
}

((((*this).index)++));
}
else {
return (TRY((parser::ParsedExpression::template create<typename parser::ParsedExpression::NamespacedVar>(current_name,namespace_,TRY((parser::merge_spans(start,((((*this).current())).span()))))))));
}

}
else {
TRY((((*this).error(Jakt::DeprecatedString("Unsupported static method call"sv),((((*this).current())).span())))));
return (expr);
}

}
TRY((((*this).error(Jakt::DeprecatedString("Incomplete static method call"sv),((((*this).current())).span())))));
return (expr);
}
}

parser::Parser::Parser(size_t a_index, JaktInternal::DynamicArray<lexer::Token> a_tokens, NonnullRefPtr<compiler::Compiler> a_compiler, bool a_can_have_trailing_closure) :index(a_index), tokens(a_tokens), compiler(a_compiler), can_have_trailing_closure(a_can_have_trailing_closure){}

ErrorOr<NonnullRefPtr<typename parser::ParsedStatement>> parser::Parser::parse_if_statement() {
{
if ((!(((((*this).current())).index() == 77 /* If */)))){
TRY((((*this).error(Jakt::DeprecatedString("Expected ‘if’ statement"sv),((((*this).current())).span())))));
return (TRY((parser::ParsedStatement::template create<typename parser::ParsedStatement::Garbage>(((((*this).current())).span())))));
}
utility::Span const start_span = ((((*this).current())).span());
((((*this).index)++));
bool const previous_can_have_trailing_closure = ((*this).can_have_trailing_closure);
(((*this).can_have_trailing_closure) = false);
NonnullRefPtr<typename parser::ParsedExpression> const condition = TRY((((*this).parse_expression(false,true))));
(((*this).can_have_trailing_closure) = previous_can_have_trailing_closure);
parser::ParsedBlock const then_block = TRY((((*this).parse_block())));
JaktInternal::Optional<NonnullRefPtr<typename parser::ParsedStatement>> else_statement = JaktInternal::OptionalNone();
((*this).skip_newlines());
if (((((*this).current())).index() == 70 /* Else */)){
((((*this).index)++));
((*this).skip_newlines());
JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<void, ErrorOr<NonnullRefPtr<typename parser::ParsedStatement>>>{
auto&& __jakt_match_variant = ((*this).current());
switch(__jakt_match_variant.index()) {
case 77: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::If>();
{
(else_statement = TRY((((*this).parse_if_statement()))));
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 10: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::LCurly>();
{
parser::ParsedBlock const block = TRY((((*this).parse_block())));
if (((then_block).equals(block))){
TRY((((*this).error(Jakt::DeprecatedString("if and else have identical blocks"sv),((((*this).current())).span())))));
}
(else_statement = TRY((parser::ParsedStatement::template create<typename parser::ParsedStatement::Block>(block,TRY((parser::merge_spans(start_span,((((*this).previous())).span()))))))));
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
default: {
{
TRY((((*this).error(Jakt::DeprecatedString("‘else’ missing ‘if’ or block"sv),((((*this).previous())).span())))));
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
}/*switch end*/
}()
));
}
return (TRY((parser::ParsedStatement::template create<typename parser::ParsedStatement::If>(condition,then_block,else_statement,TRY((parser::merge_spans(start_span,((((*this).previous())).span()))))))));
}
}

ErrorOr<NonnullRefPtr<typename parser::ParsedType>> parser::Parser::parse_type_shorthand_set() {
{
utility::Span const start = ((((*this).current())).span());
if (((((*this).current())).index() == 10 /* LCurly */)){
((((*this).index)++));
}
NonnullRefPtr<typename parser::ParsedType> const inner = TRY((((*this).parse_typename())));
if (((((*this).current())).index() == 11 /* RCurly */)){
((((*this).index)++));
return (TRY((parser::ParsedType::template create<typename parser::ParsedType::Set>(inner,TRY((parser::merge_spans(start,((((*this).current())).span()))))))));
}
TRY((((*this).error(Jakt::DeprecatedString("Expected '}'"sv),((((*this).current())).span())))));
return (TRY((parser::ParsedType::template create<typename parser::ParsedType::Empty>())));
}
}

ErrorOr<NonnullRefPtr<typename parser::ParsedExpression>> parser::Parser::parse_operand_base() {
{
return (JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<NonnullRefPtr<typename parser::ParsedExpression>, ErrorOr<NonnullRefPtr<typename parser::ParsedExpression>>>{
auto&& __jakt_match_variant = ((*this).current());
switch(__jakt_match_variant.index()) {
case 54: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::Dot>();
utility::Span const& span = __jakt_match_value.value;
return JaktInternal::ExplicitValue(({ Optional<NonnullRefPtr<typename parser::ParsedExpression>> __jakt_var_83; {
__jakt_var_83 = TRY((parser::ParsedExpression::template create<typename parser::ParsedExpression::Var>(Jakt::DeprecatedString("this"sv),span))); goto __jakt_label_80;

}
__jakt_label_80:; __jakt_var_83.release_value(); }));
};/*case end*/
case 99: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::Try>();
utility::Span const& span = __jakt_match_value.value;
return JaktInternal::ExplicitValue(({ Optional<NonnullRefPtr<typename parser::ParsedExpression>> __jakt_var_84; {
((((*this).index)++));
__jakt_var_84 = JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<NonnullRefPtr<typename parser::ParsedExpression>, ErrorOr<NonnullRefPtr<typename parser::ParsedExpression>>>{
auto&& __jakt_match_variant = ((*this).current());
switch(__jakt_match_variant.index()) {
case 10: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::LCurly>();
return JaktInternal::ExplicitValue(TRY((((*this).parse_try_block()))));
};/*case end*/
default: {
return JaktInternal::ExplicitValue(({ Optional<NonnullRefPtr<typename parser::ParsedExpression>> __jakt_var_85; {
NonnullRefPtr<typename parser::ParsedExpression> const expression = TRY((((*this).parse_expression(true,true))));
JaktInternal::Optional<parser::ParsedBlock> catch_block = JaktInternal::OptionalNone();
JaktInternal::Optional<DeprecatedString> catch_name = JaktInternal::OptionalNone();
if (((((*this).current())).index() == 65 /* Catch */)){
((((*this).index)++));
if (((((*this).current())).index() == 4 /* Identifier */)){
DeprecatedString const name = ((((*this).current())).get<lexer::Token::Identifier>()).name;
(catch_name = name);
((((*this).index)++));
}
(catch_block = TRY((((*this).parse_block()))));
}
__jakt_var_85 = TRY((parser::ParsedExpression::template create<typename parser::ParsedExpression::Try>(expression,catch_block,catch_name,span))); goto __jakt_label_82;

}
__jakt_label_82:; __jakt_var_85.release_value(); }));
};/*case end*/
}/*switch end*/
}()
)); goto __jakt_label_81;

}
__jakt_label_81:; __jakt_var_84.release_value(); }));
};/*case end*/
case 2: {
auto&& __jakt_match_value = __jakt_match_variant.template get<lexer::Token::QuotedString>();DeprecatedString const& quote = __jakt_match_value.quote;
utility::Span const& span = __jakt_match_value.span;
return JaktInternal::ExplicitValue(({ Optional<NonnullRefPtr<typename parser::ParsedExpression>> __jakt_var_86; {
((((*this).index)++));
__jakt_var_86 = TRY((parser::ParsedExpression::template create<typename parser::ParsedExpression::QuotedString>(quote,span))); goto __jakt_label_83;

}
__jakt_label_83:; __jakt_var_86.release_value(); }));
};/*case end*/
case 0: {
auto&& __jakt_match_value = __jakt_match_variant.template get<lexer::Token::SingleQuotedString>();DeprecatedString const& quote = __jakt_match_value.quote;
utility::Span const& span = __jakt_match_value.span;
return JaktInternal::ExplicitValue(({ Optional<NonnullRefPtr<typename parser::ParsedExpression>> __jakt_var_87; {
((((*this).index)++));
__jakt_var_87 = TRY((parser::ParsedExpression::template create<typename parser::ParsedExpression::SingleQuotedString>(quote,span))); goto __jakt_label_84;

}
__jakt_label_84:; __jakt_var_87.release_value(); }));
};/*case end*/
case 1: {
auto&& __jakt_match_value = __jakt_match_variant.template get<lexer::Token::SingleQuotedByteString>();DeprecatedString const& quote = __jakt_match_value.quote;
utility::Span const& span = __jakt_match_value.span;
return JaktInternal::ExplicitValue(({ Optional<NonnullRefPtr<typename parser::ParsedExpression>> __jakt_var_88; {
((((*this).index)++));
__jakt_var_88 = TRY((parser::ParsedExpression::template create<typename parser::ParsedExpression::SingleQuotedByteString>(quote,span))); goto __jakt_label_85;

}
__jakt_label_85:; __jakt_var_88.release_value(); }));
};/*case end*/
case 3: {
auto&& __jakt_match_value = __jakt_match_variant.template get<lexer::Token::Number>();lexer::LiteralPrefix const& prefix = __jakt_match_value.prefix;
DeprecatedString const& number = __jakt_match_value.number;
lexer::LiteralSuffix const& suffix = __jakt_match_value.suffix;
utility::Span const& span = __jakt_match_value.span;
return JaktInternal::ExplicitValue(TRY((((*this).parse_number(prefix,number,suffix,span)))));
};/*case end*/
case 98: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::True>();
utility::Span const& span = __jakt_match_value.value;
return JaktInternal::ExplicitValue(({ Optional<NonnullRefPtr<typename parser::ParsedExpression>> __jakt_var_89; {
((((*this).index)++));
__jakt_var_89 = TRY((parser::ParsedExpression::template create<typename parser::ParsedExpression::Boolean>(true,span))); goto __jakt_label_86;

}
__jakt_label_86:; __jakt_var_89.release_value(); }));
};/*case end*/
case 73: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::False>();
utility::Span const& span = __jakt_match_value.value;
return JaktInternal::ExplicitValue(({ Optional<NonnullRefPtr<typename parser::ParsedExpression>> __jakt_var_90; {
((((*this).index)++));
__jakt_var_90 = TRY((parser::ParsedExpression::template create<typename parser::ParsedExpression::Boolean>(false,span))); goto __jakt_label_87;

}
__jakt_label_87:; __jakt_var_90.release_value(); }));
};/*case end*/
case 95: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::This>();
utility::Span const& span = __jakt_match_value.value;
return JaktInternal::ExplicitValue(({ Optional<NonnullRefPtr<typename parser::ParsedExpression>> __jakt_var_91; {
((((*this).index)++));
__jakt_var_91 = TRY((parser::ParsedExpression::template create<typename parser::ParsedExpression::Var>(Jakt::DeprecatedString("this"sv),span))); goto __jakt_label_88;

}
__jakt_label_88:; __jakt_var_91.release_value(); }));
};/*case end*/
case 86: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::Not>();
utility::Span const& span = __jakt_match_value.value;
return JaktInternal::ExplicitValue(({ Optional<NonnullRefPtr<typename parser::ParsedExpression>> __jakt_var_92; {
utility::Span const start = ((((*this).current())).span());
((((*this).index)++));
NonnullRefPtr<typename parser::ParsedExpression> const expr = TRY((((*this).parse_operand())));
utility::Span const span = TRY((parser::merge_spans(start,((expr)->span()))));
__jakt_var_92 = TRY((parser::ParsedExpression::template create<typename parser::ParsedExpression::UnaryOp>(expr, parser::UnaryOperator { typename parser::UnaryOperator::LogicalNot() } ,span))); goto __jakt_label_89;

}
__jakt_label_89:; __jakt_var_92.release_value(); }));
};/*case end*/
case 47: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::Tilde>();
utility::Span const& span = __jakt_match_value.value;
return JaktInternal::ExplicitValue(({ Optional<NonnullRefPtr<typename parser::ParsedExpression>> __jakt_var_93; {
utility::Span const start = ((((*this).current())).span());
((((*this).index)++));
NonnullRefPtr<typename parser::ParsedExpression> const expr = TRY((((*this).parse_operand())));
utility::Span const span = TRY((parser::merge_spans(start,((expr)->span()))));
__jakt_var_93 = TRY((parser::ParsedExpression::template create<typename parser::ParsedExpression::UnaryOp>(expr, parser::UnaryOperator { typename parser::UnaryOperator::BitwiseNot() } ,span))); goto __jakt_label_90;

}
__jakt_label_90:; __jakt_var_93.release_value(); }));
};/*case end*/
case 4: {
auto&& __jakt_match_value = __jakt_match_variant.template get<lexer::Token::Identifier>();DeprecatedString const& name = __jakt_match_value.name;
utility::Span const& span = __jakt_match_value.span;
return JaktInternal::ExplicitValue(({ Optional<NonnullRefPtr<typename parser::ParsedExpression>> __jakt_var_94; {
if (((((*this).peek(static_cast<size_t>(1ULL)))).index() == 8 /* LParen */)){
if ((name == Jakt::DeprecatedString("Some"sv))){
((((*this).index)++));
NonnullRefPtr<typename parser::ParsedExpression> const expr = TRY((((*this).parse_expression(false,false))));
return (TRY((parser::ParsedExpression::template create<typename parser::ParsedExpression::OptionalSome>(expr,span))));
}
JaktInternal::Optional<parser::ParsedCall> const call = TRY((((*this).parse_call())));
return (TRY((parser::ParsedExpression::template create<typename parser::ParsedExpression::Call>((call.value()),span))));
}
if (((((*this).peek(static_cast<size_t>(1ULL)))).index() == 29 /* LessThan */)){
(((((*this).compiler))->ignore_parser_errors) = true);
JaktInternal::Optional<parser::ParsedCall> const call = TRY((((*this).parse_call())));
(((((*this).compiler))->ignore_parser_errors) = false);
if ((!(((call).has_value())))){
return (JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<NonnullRefPtr<typename parser::ParsedExpression>,ErrorOr<NonnullRefPtr<typename parser::ParsedExpression>>>{
auto __jakt_enum_value = (name);
if (__jakt_enum_value == Jakt::DeprecatedString("None"sv)) {
return JaktInternal::ExplicitValue(TRY((parser::ParsedExpression::template create<typename parser::ParsedExpression::OptionalNone>(span))));
}
else {
return JaktInternal::ExplicitValue(TRY((parser::ParsedExpression::template create<typename parser::ParsedExpression::Var>(name,span))));
}
}()))
);
}
return (TRY((parser::ParsedExpression::template create<typename parser::ParsedExpression::Call>((call.value()),span))));
}
((((*this).index)++));
if ((name == Jakt::DeprecatedString("None"sv))){
return (TRY((parser::ParsedExpression::template create<typename parser::ParsedExpression::OptionalNone>(span))));
}
__jakt_var_94 = TRY((parser::ParsedExpression::template create<typename parser::ParsedExpression::Var>(name,span))); goto __jakt_label_91;

}
__jakt_label_91:; __jakt_var_94.release_value(); }));
};/*case end*/
case 8: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::LParen>();
utility::Span const& span = __jakt_match_value.value;
return JaktInternal::ExplicitValue(({ Optional<NonnullRefPtr<typename parser::ParsedExpression>> __jakt_var_95; {
utility::Span const start_span = ((((*this).current())).span());
((((*this).index)++));
NonnullRefPtr<typename parser::ParsedExpression> expr = TRY((((*this).parse_expression(false,false))));
((*this).skip_newlines());
JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<void, ErrorOr<NonnullRefPtr<typename parser::ParsedExpression>>>{
auto&& __jakt_match_variant = ((*this).current());
switch(__jakt_match_variant.index()) {
case 9: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::RParen>();
{
((((*this).index)++));
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 53: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::Comma>();
{
((((*this).index)++));
JaktInternal::DynamicArray<NonnullRefPtr<typename parser::ParsedExpression>> tuple_exprs = (TRY((DynamicArray<NonnullRefPtr<typename parser::ParsedExpression>>::create_with({expr}))));
utility::Span end_span = start_span;
while ((!(((*this).eof())))){
JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_AT_LOOP(([&]() -> JaktInternal::ExplicitValueOrControlFlow<void, ErrorOr<NonnullRefPtr<typename parser::ParsedExpression>>>{
auto&& __jakt_match_variant = ((*this).current());
switch(__jakt_match_variant.index()) {
case 56: {
auto&& __jakt_match_value = __jakt_match_variant.template get<lexer::Token::Eol>();{
((((*this).index)++));
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 53: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::Comma>();
{
((((*this).index)++));
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 9: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::RParen>();
{
((((*this).index)++));
return JaktInternal::LoopBreak{};
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
default: {
{
NonnullRefPtr<typename parser::ParsedExpression> const expr = TRY((((*this).parse_expression(false,false))));
(end_span = ((expr)->span()));
TRY((((tuple_exprs).push(expr))));
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
}/*switch end*/
}()
));
}
if (((*this).eof())){
TRY((((*this).error(Jakt::DeprecatedString("Expected ')'"sv),((((*this).current())).span())))));
}
(expr = TRY((parser::ParsedExpression::template create<typename parser::ParsedExpression::JaktTuple>(tuple_exprs,TRY((parser::merge_spans(start_span,end_span)))))));
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
default: {
{
TRY((((*this).error(Jakt::DeprecatedString("Expected ')'"sv),((((*this).current())).span())))));
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
}/*switch end*/
}()
));
__jakt_var_95 = expr; goto __jakt_label_92;

}
__jakt_label_92:; __jakt_var_95.release_value(); }));
};/*case end*/
case 19: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::PlusPlus>();
utility::Span const& span = __jakt_match_value.value;
return JaktInternal::ExplicitValue(({ Optional<NonnullRefPtr<typename parser::ParsedExpression>> __jakt_var_96; {
parser::UnaryOperator const op = JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<parser::UnaryOperator, ErrorOr<NonnullRefPtr<typename parser::ParsedExpression>>>{
auto&& __jakt_match_variant = ((*this).current());
switch(__jakt_match_variant.index()) {
case 19: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::PlusPlus>();
return JaktInternal::ExplicitValue( parser::UnaryOperator { typename parser::UnaryOperator::PreIncrement() } );
};/*case end*/
case 21: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::MinusMinus>();
return JaktInternal::ExplicitValue( parser::UnaryOperator { typename parser::UnaryOperator::PreDecrement() } );
};/*case end*/
case 16: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::Minus>();
return JaktInternal::ExplicitValue( parser::UnaryOperator { typename parser::UnaryOperator::Negate() } );
};/*case end*/
default: {
{
TRY((((((*this).compiler))->panic(Jakt::DeprecatedString("unreachable"sv)))));
}
};/*case end*/
}/*switch end*/
}()
));
utility::Span const start = ((((*this).current())).span());
((((*this).index)++));
NonnullRefPtr<typename parser::ParsedExpression> const expr = TRY((((*this).parse_operand())));
utility::Span const span = TRY((parser::merge_spans(start,((expr)->span()))));
__jakt_var_96 = TRY((parser::ParsedExpression::template create<typename parser::ParsedExpression::UnaryOp>(expr,op,span))); goto __jakt_label_93;

}
__jakt_label_93:; __jakt_var_96.release_value(); }));
};/*case end*/
case 21: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::MinusMinus>();
utility::Span const& span = __jakt_match_value.value;
return JaktInternal::ExplicitValue(({ Optional<NonnullRefPtr<typename parser::ParsedExpression>> __jakt_var_97; {
parser::UnaryOperator const op = JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<parser::UnaryOperator, ErrorOr<NonnullRefPtr<typename parser::ParsedExpression>>>{
auto&& __jakt_match_variant = ((*this).current());
switch(__jakt_match_variant.index()) {
case 19: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::PlusPlus>();
return JaktInternal::ExplicitValue( parser::UnaryOperator { typename parser::UnaryOperator::PreIncrement() } );
};/*case end*/
case 21: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::MinusMinus>();
return JaktInternal::ExplicitValue( parser::UnaryOperator { typename parser::UnaryOperator::PreDecrement() } );
};/*case end*/
case 16: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::Minus>();
return JaktInternal::ExplicitValue( parser::UnaryOperator { typename parser::UnaryOperator::Negate() } );
};/*case end*/
default: {
{
TRY((((((*this).compiler))->panic(Jakt::DeprecatedString("unreachable"sv)))));
}
};/*case end*/
}/*switch end*/
}()
));
utility::Span const start = ((((*this).current())).span());
((((*this).index)++));
NonnullRefPtr<typename parser::ParsedExpression> const expr = TRY((((*this).parse_operand())));
utility::Span const span = TRY((parser::merge_spans(start,((expr)->span()))));
__jakt_var_97 = TRY((parser::ParsedExpression::template create<typename parser::ParsedExpression::UnaryOp>(expr,op,span))); goto __jakt_label_94;

}
__jakt_label_94:; __jakt_var_97.release_value(); }));
};/*case end*/
case 16: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::Minus>();
utility::Span const& span = __jakt_match_value.value;
return JaktInternal::ExplicitValue(({ Optional<NonnullRefPtr<typename parser::ParsedExpression>> __jakt_var_98; {
parser::UnaryOperator const op = JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<parser::UnaryOperator, ErrorOr<NonnullRefPtr<typename parser::ParsedExpression>>>{
auto&& __jakt_match_variant = ((*this).current());
switch(__jakt_match_variant.index()) {
case 19: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::PlusPlus>();
return JaktInternal::ExplicitValue( parser::UnaryOperator { typename parser::UnaryOperator::PreIncrement() } );
};/*case end*/
case 21: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::MinusMinus>();
return JaktInternal::ExplicitValue( parser::UnaryOperator { typename parser::UnaryOperator::PreDecrement() } );
};/*case end*/
case 16: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::Minus>();
return JaktInternal::ExplicitValue( parser::UnaryOperator { typename parser::UnaryOperator::Negate() } );
};/*case end*/
default: {
{
TRY((((((*this).compiler))->panic(Jakt::DeprecatedString("unreachable"sv)))));
}
};/*case end*/
}/*switch end*/
}()
));
utility::Span const start = ((((*this).current())).span());
((((*this).index)++));
NonnullRefPtr<typename parser::ParsedExpression> const expr = TRY((((*this).parse_operand())));
utility::Span const span = TRY((parser::merge_spans(start,((expr)->span()))));
__jakt_var_98 = TRY((parser::ParsedExpression::template create<typename parser::ParsedExpression::UnaryOp>(expr,op,span))); goto __jakt_label_95;

}
__jakt_label_95:; __jakt_var_98.release_value(); }));
};/*case end*/
case 12: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::LSquare>();
return JaktInternal::ExplicitValue(({ Optional<NonnullRefPtr<typename parser::ParsedExpression>> __jakt_var_99; {
__jakt_var_99 = TRY((((*this).parse_array_or_dictionary_literal()))); goto __jakt_label_96;

}
__jakt_label_96:; __jakt_var_99.release_value(); }));
};/*case end*/
case 83: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::Match>();
return JaktInternal::ExplicitValue(({ Optional<NonnullRefPtr<typename parser::ParsedExpression>> __jakt_var_100; {
__jakt_var_100 = TRY((((*this).parse_match_expression()))); goto __jakt_label_97;

}
__jakt_label_97:; __jakt_var_100.release_value(); }));
};/*case end*/
case 10: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::LCurly>();
return JaktInternal::ExplicitValue(({ Optional<NonnullRefPtr<typename parser::ParsedExpression>> __jakt_var_101; {
__jakt_var_101 = TRY((((*this).parse_set_literal()))); goto __jakt_label_98;

}
__jakt_label_98:; __jakt_var_101.release_value(); }));
};/*case end*/
case 38: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::Ampersand>();
return JaktInternal::ExplicitValue(TRY((((*this).parse_ampersand()))));
};/*case end*/
case 37: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::Asterisk>();
return JaktInternal::ExplicitValue(TRY((((*this).parse_asterisk()))));
};/*case end*/
case 75: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::Function>();
return JaktInternal::ExplicitValue(TRY((((*this).parse_lambda()))));
};/*case end*/
case 55: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::DotDot>();
return JaktInternal::ExplicitValue(TRY((((*this).parse_range()))));
};/*case end*/
default: {
return JaktInternal::ExplicitValue(({ Optional<NonnullRefPtr<typename parser::ParsedExpression>> __jakt_var_102; {
utility::Span const span = ((((*this).current())).span());
((((*this).index)++));
TRY((((*this).error(Jakt::DeprecatedString("Unsupported expression"sv),span))));
__jakt_var_102 = TRY((parser::ParsedExpression::template create<typename parser::ParsedExpression::Garbage>(span))); goto __jakt_label_99;

}
__jakt_label_99:; __jakt_var_102.release_value(); }));
};/*case end*/
}/*switch end*/
}()
)));
}
}

ErrorOr<parser::ParsedAlias> parser::Parser::parse_using() {
{
parser::ParsedAlias alias = parser::ParsedAlias(JaktInternal::OptionalNone(),(TRY((DynamicArray<parser::ParsedNameWithGenericParameters>::create_with({})))));
for (;;){
JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_AT_LOOP(([&]() -> JaktInternal::ExplicitValueOrControlFlow<void, ErrorOr<parser::ParsedAlias>>{
auto&& __jakt_match_variant = ((*this).current());
switch(__jakt_match_variant.index()) {
case 56: {
auto&& __jakt_match_value = __jakt_match_variant.template get<lexer::Token::Eol>();{
return JaktInternal::LoopBreak{};
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 62: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::As>();
{
return JaktInternal::LoopBreak{};
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 57: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::Eof>();
{
return JaktInternal::LoopBreak{};
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 7: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::ColonColon>();
{
((((*this).index)++));
return JaktInternal::LoopContinue{};
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 4: {
auto&& __jakt_match_value = __jakt_match_variant.template get<lexer::Token::Identifier>();DeprecatedString const& name = __jakt_match_value.name;
utility::Span const& span = __jakt_match_value.span;
{
parser::ParsedNameWithGenericParameters parsed_name = parser::ParsedNameWithGenericParameters(name,span,(TRY((DynamicArray<NonnullRefPtr<typename parser::ParsedType>>::create_with({})))));
((((*this).index)++));
if (((((*this).current())).index() == 29 /* LessThan */)){
((((*this).index)++));
while ((!(((*this).eof())))){
JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_AT_LOOP(([&]() -> JaktInternal::ExplicitValueOrControlFlow<void, ErrorOr<parser::ParsedAlias>>{
auto&& __jakt_match_variant = ((*this).current());
switch(__jakt_match_variant.index()) {
case 27: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::GreaterThan>();
{
((((*this).index)++));
return JaktInternal::LoopBreak{};
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 53: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::Comma>();
{
((((*this).index)++));
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 56: {
auto&& __jakt_match_value = __jakt_match_variant.template get<lexer::Token::Eol>();{
((((*this).index)++));
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 34: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::RightShift>();
{
TRY((((*this).inject_token( lexer::Token { typename lexer::Token::GreaterThan(((((*this).current())).span())) } ))));
({auto& _jakt_ref = ((*this).index);_jakt_ref = JaktInternal::checked_add<size_t>(_jakt_ref, static_cast<size_t>(1ULL));});
return JaktInternal::LoopBreak{};
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
default: {
{
size_t const index_before = ((*this).index);
NonnullRefPtr<typename parser::ParsedType> const inner_type = TRY((((*this).parse_typename())));
if ((index_before == ((*this).index))){
TRY((((*this).error(Jakt::DeprecatedString("Expected type name"sv),((((*this).current())).span())))));
return JaktInternal::LoopBreak{};
}
TRY((((((parsed_name).generic_parameters)).push(inner_type))));
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
}/*switch end*/
}()
));
}
}
TRY((((((alias).target)).push(parsed_name))));
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 0: {
auto&& __jakt_match_value = __jakt_match_variant.template get<lexer::Token::SingleQuotedString>();utility::Span const& span = __jakt_match_value.span;
{
TRY((((*this).error(Jakt::DeprecatedString("Expected alias target name"sv),span))));
return JaktInternal::LoopBreak{};
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 1: {
auto&& __jakt_match_value = __jakt_match_variant.template get<lexer::Token::SingleQuotedByteString>();utility::Span const& span = __jakt_match_value.span;
{
TRY((((*this).error(Jakt::DeprecatedString("Expected alias target name"sv),span))));
return JaktInternal::LoopBreak{};
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 2: {
auto&& __jakt_match_value = __jakt_match_variant.template get<lexer::Token::QuotedString>();utility::Span const& span = __jakt_match_value.span;
{
TRY((((*this).error(Jakt::DeprecatedString("Expected alias target name"sv),span))));
return JaktInternal::LoopBreak{};
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 3: {
auto&& __jakt_match_value = __jakt_match_variant.template get<lexer::Token::Number>();utility::Span const& span = __jakt_match_value.span;
{
TRY((((*this).error(Jakt::DeprecatedString("Expected alias target name"sv),span))));
return JaktInternal::LoopBreak{};
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 5: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::Semicolon>();
utility::Span const& span = __jakt_match_value.value;
{
TRY((((*this).error(Jakt::DeprecatedString("Expected alias target name"sv),span))));
return JaktInternal::LoopBreak{};
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 6: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::Colon>();
utility::Span const& span = __jakt_match_value.value;
{
TRY((((*this).error(Jakt::DeprecatedString("Expected alias target name"sv),span))));
return JaktInternal::LoopBreak{};
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 8: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::LParen>();
utility::Span const& span = __jakt_match_value.value;
{
TRY((((*this).error(Jakt::DeprecatedString("Expected alias target name"sv),span))));
return JaktInternal::LoopBreak{};
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 9: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::RParen>();
utility::Span const& span = __jakt_match_value.value;
{
TRY((((*this).error(Jakt::DeprecatedString("Expected alias target name"sv),span))));
return JaktInternal::LoopBreak{};
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 10: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::LCurly>();
utility::Span const& span = __jakt_match_value.value;
{
TRY((((*this).error(Jakt::DeprecatedString("Expected alias target name"sv),span))));
return JaktInternal::LoopBreak{};
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 11: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::RCurly>();
utility::Span const& span = __jakt_match_value.value;
{
TRY((((*this).error(Jakt::DeprecatedString("Expected alias target name"sv),span))));
return JaktInternal::LoopBreak{};
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 12: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::LSquare>();
utility::Span const& span = __jakt_match_value.value;
{
TRY((((*this).error(Jakt::DeprecatedString("Expected alias target name"sv),span))));
return JaktInternal::LoopBreak{};
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 13: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::RSquare>();
utility::Span const& span = __jakt_match_value.value;
{
TRY((((*this).error(Jakt::DeprecatedString("Expected alias target name"sv),span))));
return JaktInternal::LoopBreak{};
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 14: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::PercentSign>();
utility::Span const& span = __jakt_match_value.value;
{
TRY((((*this).error(Jakt::DeprecatedString("Expected alias target name"sv),span))));
return JaktInternal::LoopBreak{};
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 15: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::Plus>();
utility::Span const& span = __jakt_match_value.value;
{
TRY((((*this).error(Jakt::DeprecatedString("Expected alias target name"sv),span))));
return JaktInternal::LoopBreak{};
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 16: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::Minus>();
utility::Span const& span = __jakt_match_value.value;
{
TRY((((*this).error(Jakt::DeprecatedString("Expected alias target name"sv),span))));
return JaktInternal::LoopBreak{};
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 17: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::Equal>();
utility::Span const& span = __jakt_match_value.value;
{
TRY((((*this).error(Jakt::DeprecatedString("Expected alias target name"sv),span))));
return JaktInternal::LoopBreak{};
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 18: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::PlusEqual>();
utility::Span const& span = __jakt_match_value.value;
{
TRY((((*this).error(Jakt::DeprecatedString("Expected alias target name"sv),span))));
return JaktInternal::LoopBreak{};
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 19: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::PlusPlus>();
utility::Span const& span = __jakt_match_value.value;
{
TRY((((*this).error(Jakt::DeprecatedString("Expected alias target name"sv),span))));
return JaktInternal::LoopBreak{};
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 20: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::MinusEqual>();
utility::Span const& span = __jakt_match_value.value;
{
TRY((((*this).error(Jakt::DeprecatedString("Expected alias target name"sv),span))));
return JaktInternal::LoopBreak{};
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 21: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::MinusMinus>();
utility::Span const& span = __jakt_match_value.value;
{
TRY((((*this).error(Jakt::DeprecatedString("Expected alias target name"sv),span))));
return JaktInternal::LoopBreak{};
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 22: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::AsteriskEqual>();
utility::Span const& span = __jakt_match_value.value;
{
TRY((((*this).error(Jakt::DeprecatedString("Expected alias target name"sv),span))));
return JaktInternal::LoopBreak{};
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 23: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::ForwardSlashEqual>();
utility::Span const& span = __jakt_match_value.value;
{
TRY((((*this).error(Jakt::DeprecatedString("Expected alias target name"sv),span))));
return JaktInternal::LoopBreak{};
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 24: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::PercentSignEqual>();
utility::Span const& span = __jakt_match_value.value;
{
TRY((((*this).error(Jakt::DeprecatedString("Expected alias target name"sv),span))));
return JaktInternal::LoopBreak{};
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 25: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::NotEqual>();
utility::Span const& span = __jakt_match_value.value;
{
TRY((((*this).error(Jakt::DeprecatedString("Expected alias target name"sv),span))));
return JaktInternal::LoopBreak{};
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 26: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::DoubleEqual>();
utility::Span const& span = __jakt_match_value.value;
{
TRY((((*this).error(Jakt::DeprecatedString("Expected alias target name"sv),span))));
return JaktInternal::LoopBreak{};
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 27: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::GreaterThan>();
utility::Span const& span = __jakt_match_value.value;
{
TRY((((*this).error(Jakt::DeprecatedString("Expected alias target name"sv),span))));
return JaktInternal::LoopBreak{};
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 28: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::GreaterThanOrEqual>();
utility::Span const& span = __jakt_match_value.value;
{
TRY((((*this).error(Jakt::DeprecatedString("Expected alias target name"sv),span))));
return JaktInternal::LoopBreak{};
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 29: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::LessThan>();
utility::Span const& span = __jakt_match_value.value;
{
TRY((((*this).error(Jakt::DeprecatedString("Expected alias target name"sv),span))));
return JaktInternal::LoopBreak{};
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 30: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::LessThanOrEqual>();
utility::Span const& span = __jakt_match_value.value;
{
TRY((((*this).error(Jakt::DeprecatedString("Expected alias target name"sv),span))));
return JaktInternal::LoopBreak{};
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 31: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::LeftArithmeticShift>();
utility::Span const& span = __jakt_match_value.value;
{
TRY((((*this).error(Jakt::DeprecatedString("Expected alias target name"sv),span))));
return JaktInternal::LoopBreak{};
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 32: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::LeftShift>();
utility::Span const& span = __jakt_match_value.value;
{
TRY((((*this).error(Jakt::DeprecatedString("Expected alias target name"sv),span))));
return JaktInternal::LoopBreak{};
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 33: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::LeftShiftEqual>();
utility::Span const& span = __jakt_match_value.value;
{
TRY((((*this).error(Jakt::DeprecatedString("Expected alias target name"sv),span))));
return JaktInternal::LoopBreak{};
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 34: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::RightShift>();
utility::Span const& span = __jakt_match_value.value;
{
TRY((((*this).error(Jakt::DeprecatedString("Expected alias target name"sv),span))));
return JaktInternal::LoopBreak{};
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 35: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::RightArithmeticShift>();
utility::Span const& span = __jakt_match_value.value;
{
TRY((((*this).error(Jakt::DeprecatedString("Expected alias target name"sv),span))));
return JaktInternal::LoopBreak{};
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 36: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::RightShiftEqual>();
utility::Span const& span = __jakt_match_value.value;
{
TRY((((*this).error(Jakt::DeprecatedString("Expected alias target name"sv),span))));
return JaktInternal::LoopBreak{};
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 37: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::Asterisk>();
utility::Span const& span = __jakt_match_value.value;
{
TRY((((*this).error(Jakt::DeprecatedString("Expected alias target name"sv),span))));
return JaktInternal::LoopBreak{};
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 38: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::Ampersand>();
utility::Span const& span = __jakt_match_value.value;
{
TRY((((*this).error(Jakt::DeprecatedString("Expected alias target name"sv),span))));
return JaktInternal::LoopBreak{};
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 39: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::AmpersandEqual>();
utility::Span const& span = __jakt_match_value.value;
{
TRY((((*this).error(Jakt::DeprecatedString("Expected alias target name"sv),span))));
return JaktInternal::LoopBreak{};
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 40: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::AmpersandAmpersand>();
utility::Span const& span = __jakt_match_value.value;
{
TRY((((*this).error(Jakt::DeprecatedString("Expected alias target name"sv),span))));
return JaktInternal::LoopBreak{};
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 41: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::Pipe>();
utility::Span const& span = __jakt_match_value.value;
{
TRY((((*this).error(Jakt::DeprecatedString("Expected alias target name"sv),span))));
return JaktInternal::LoopBreak{};
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 42: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::PipeEqual>();
utility::Span const& span = __jakt_match_value.value;
{
TRY((((*this).error(Jakt::DeprecatedString("Expected alias target name"sv),span))));
return JaktInternal::LoopBreak{};
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 43: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::PipePipe>();
utility::Span const& span = __jakt_match_value.value;
{
TRY((((*this).error(Jakt::DeprecatedString("Expected alias target name"sv),span))));
return JaktInternal::LoopBreak{};
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 44: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::Caret>();
utility::Span const& span = __jakt_match_value.value;
{
TRY((((*this).error(Jakt::DeprecatedString("Expected alias target name"sv),span))));
return JaktInternal::LoopBreak{};
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 45: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::CaretEqual>();
utility::Span const& span = __jakt_match_value.value;
{
TRY((((*this).error(Jakt::DeprecatedString("Expected alias target name"sv),span))));
return JaktInternal::LoopBreak{};
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 46: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::Dollar>();
utility::Span const& span = __jakt_match_value.value;
{
TRY((((*this).error(Jakt::DeprecatedString("Expected alias target name"sv),span))));
return JaktInternal::LoopBreak{};
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 47: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::Tilde>();
utility::Span const& span = __jakt_match_value.value;
{
TRY((((*this).error(Jakt::DeprecatedString("Expected alias target name"sv),span))));
return JaktInternal::LoopBreak{};
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 48: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::ForwardSlash>();
utility::Span const& span = __jakt_match_value.value;
{
TRY((((*this).error(Jakt::DeprecatedString("Expected alias target name"sv),span))));
return JaktInternal::LoopBreak{};
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 49: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::ExclamationPoint>();
utility::Span const& span = __jakt_match_value.value;
{
TRY((((*this).error(Jakt::DeprecatedString("Expected alias target name"sv),span))));
return JaktInternal::LoopBreak{};
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 50: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::QuestionMark>();
utility::Span const& span = __jakt_match_value.value;
{
TRY((((*this).error(Jakt::DeprecatedString("Expected alias target name"sv),span))));
return JaktInternal::LoopBreak{};
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 51: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::QuestionMarkQuestionMark>();
utility::Span const& span = __jakt_match_value.value;
{
TRY((((*this).error(Jakt::DeprecatedString("Expected alias target name"sv),span))));
return JaktInternal::LoopBreak{};
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 52: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::QuestionMarkQuestionMarkEqual>();
utility::Span const& span = __jakt_match_value.value;
{
TRY((((*this).error(Jakt::DeprecatedString("Expected alias target name"sv),span))));
return JaktInternal::LoopBreak{};
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 53: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::Comma>();
utility::Span const& span = __jakt_match_value.value;
{
TRY((((*this).error(Jakt::DeprecatedString("Expected alias target name"sv),span))));
return JaktInternal::LoopBreak{};
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 54: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::Dot>();
utility::Span const& span = __jakt_match_value.value;
{
TRY((((*this).error(Jakt::DeprecatedString("Expected alias target name"sv),span))));
return JaktInternal::LoopBreak{};
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 55: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::DotDot>();
utility::Span const& span = __jakt_match_value.value;
{
TRY((((*this).error(Jakt::DeprecatedString("Expected alias target name"sv),span))));
return JaktInternal::LoopBreak{};
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 58: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::FatArrow>();
utility::Span const& span = __jakt_match_value.value;
{
TRY((((*this).error(Jakt::DeprecatedString("Expected alias target name"sv),span))));
return JaktInternal::LoopBreak{};
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 59: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::Arrow>();
utility::Span const& span = __jakt_match_value.value;
{
TRY((((*this).error(Jakt::DeprecatedString("Expected alias target name"sv),span))));
return JaktInternal::LoopBreak{};
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 60: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::And>();
utility::Span const& span = __jakt_match_value.value;
{
TRY((((*this).error(Jakt::DeprecatedString("Expected alias target name"sv),span))));
return JaktInternal::LoopBreak{};
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 61: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::Anon>();
utility::Span const& span = __jakt_match_value.value;
{
TRY((((*this).error(Jakt::DeprecatedString("Expected alias target name"sv),span))));
return JaktInternal::LoopBreak{};
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 63: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::Boxed>();
utility::Span const& span = __jakt_match_value.value;
{
TRY((((*this).error(Jakt::DeprecatedString("Expected alias target name"sv),span))));
return JaktInternal::LoopBreak{};
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 64: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::Break>();
utility::Span const& span = __jakt_match_value.value;
{
TRY((((*this).error(Jakt::DeprecatedString("Expected alias target name"sv),span))));
return JaktInternal::LoopBreak{};
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 65: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::Catch>();
utility::Span const& span = __jakt_match_value.value;
{
TRY((((*this).error(Jakt::DeprecatedString("Expected alias target name"sv),span))));
return JaktInternal::LoopBreak{};
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 66: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::Class>();
utility::Span const& span = __jakt_match_value.value;
{
TRY((((*this).error(Jakt::DeprecatedString("Expected alias target name"sv),span))));
return JaktInternal::LoopBreak{};
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 67: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::Continue>();
utility::Span const& span = __jakt_match_value.value;
{
TRY((((*this).error(Jakt::DeprecatedString("Expected alias target name"sv),span))));
return JaktInternal::LoopBreak{};
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 68: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::Cpp>();
utility::Span const& span = __jakt_match_value.value;
{
TRY((((*this).error(Jakt::DeprecatedString("Expected alias target name"sv),span))));
return JaktInternal::LoopBreak{};
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 69: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::Defer>();
utility::Span const& span = __jakt_match_value.value;
{
TRY((((*this).error(Jakt::DeprecatedString("Expected alias target name"sv),span))));
return JaktInternal::LoopBreak{};
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 70: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::Else>();
utility::Span const& span = __jakt_match_value.value;
{
TRY((((*this).error(Jakt::DeprecatedString("Expected alias target name"sv),span))));
return JaktInternal::LoopBreak{};
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 71: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::Enum>();
utility::Span const& span = __jakt_match_value.value;
{
TRY((((*this).error(Jakt::DeprecatedString("Expected alias target name"sv),span))));
return JaktInternal::LoopBreak{};
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 72: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::Extern>();
utility::Span const& span = __jakt_match_value.value;
{
TRY((((*this).error(Jakt::DeprecatedString("Expected alias target name"sv),span))));
return JaktInternal::LoopBreak{};
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 73: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::False>();
utility::Span const& span = __jakt_match_value.value;
{
TRY((((*this).error(Jakt::DeprecatedString("Expected alias target name"sv),span))));
return JaktInternal::LoopBreak{};
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 74: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::For>();
utility::Span const& span = __jakt_match_value.value;
{
TRY((((*this).error(Jakt::DeprecatedString("Expected alias target name"sv),span))));
return JaktInternal::LoopBreak{};
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 75: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::Function>();
utility::Span const& span = __jakt_match_value.value;
{
TRY((((*this).error(Jakt::DeprecatedString("Expected alias target name"sv),span))));
return JaktInternal::LoopBreak{};
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 76: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::Comptime>();
utility::Span const& span = __jakt_match_value.value;
{
TRY((((*this).error(Jakt::DeprecatedString("Expected alias target name"sv),span))));
return JaktInternal::LoopBreak{};
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 77: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::If>();
utility::Span const& span = __jakt_match_value.value;
{
TRY((((*this).error(Jakt::DeprecatedString("Expected alias target name"sv),span))));
return JaktInternal::LoopBreak{};
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 78: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::Import>();
utility::Span const& span = __jakt_match_value.value;
{
TRY((((*this).error(Jakt::DeprecatedString("Expected alias target name"sv),span))));
return JaktInternal::LoopBreak{};
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 79: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::In>();
utility::Span const& span = __jakt_match_value.value;
{
TRY((((*this).error(Jakt::DeprecatedString("Expected alias target name"sv),span))));
return JaktInternal::LoopBreak{};
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 80: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::Is>();
utility::Span const& span = __jakt_match_value.value;
{
TRY((((*this).error(Jakt::DeprecatedString("Expected alias target name"sv),span))));
return JaktInternal::LoopBreak{};
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 81: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::Let>();
utility::Span const& span = __jakt_match_value.value;
{
TRY((((*this).error(Jakt::DeprecatedString("Expected alias target name"sv),span))));
return JaktInternal::LoopBreak{};
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 82: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::Loop>();
utility::Span const& span = __jakt_match_value.value;
{
TRY((((*this).error(Jakt::DeprecatedString("Expected alias target name"sv),span))));
return JaktInternal::LoopBreak{};
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 83: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::Match>();
utility::Span const& span = __jakt_match_value.value;
{
TRY((((*this).error(Jakt::DeprecatedString("Expected alias target name"sv),span))));
return JaktInternal::LoopBreak{};
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 84: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::Mut>();
utility::Span const& span = __jakt_match_value.value;
{
TRY((((*this).error(Jakt::DeprecatedString("Expected alias target name"sv),span))));
return JaktInternal::LoopBreak{};
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 85: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::Namespace>();
utility::Span const& span = __jakt_match_value.value;
{
TRY((((*this).error(Jakt::DeprecatedString("Expected alias target name"sv),span))));
return JaktInternal::LoopBreak{};
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 86: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::Not>();
utility::Span const& span = __jakt_match_value.value;
{
TRY((((*this).error(Jakt::DeprecatedString("Expected alias target name"sv),span))));
return JaktInternal::LoopBreak{};
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 87: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::Or>();
utility::Span const& span = __jakt_match_value.value;
{
TRY((((*this).error(Jakt::DeprecatedString("Expected alias target name"sv),span))));
return JaktInternal::LoopBreak{};
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 88: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::Override>();
utility::Span const& span = __jakt_match_value.value;
{
TRY((((*this).error(Jakt::DeprecatedString("Expected alias target name"sv),span))));
return JaktInternal::LoopBreak{};
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 89: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::Private>();
utility::Span const& span = __jakt_match_value.value;
{
TRY((((*this).error(Jakt::DeprecatedString("Expected alias target name"sv),span))));
return JaktInternal::LoopBreak{};
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 90: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::Public>();
utility::Span const& span = __jakt_match_value.value;
{
TRY((((*this).error(Jakt::DeprecatedString("Expected alias target name"sv),span))));
return JaktInternal::LoopBreak{};
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 91: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::Raw>();
utility::Span const& span = __jakt_match_value.value;
{
TRY((((*this).error(Jakt::DeprecatedString("Expected alias target name"sv),span))));
return JaktInternal::LoopBreak{};
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 92: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::Return>();
utility::Span const& span = __jakt_match_value.value;
{
TRY((((*this).error(Jakt::DeprecatedString("Expected alias target name"sv),span))));
return JaktInternal::LoopBreak{};
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 93: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::Restricted>();
utility::Span const& span = __jakt_match_value.value;
{
TRY((((*this).error(Jakt::DeprecatedString("Expected alias target name"sv),span))));
return JaktInternal::LoopBreak{};
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 94: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::Struct>();
utility::Span const& span = __jakt_match_value.value;
{
TRY((((*this).error(Jakt::DeprecatedString("Expected alias target name"sv),span))));
return JaktInternal::LoopBreak{};
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 95: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::This>();
utility::Span const& span = __jakt_match_value.value;
{
TRY((((*this).error(Jakt::DeprecatedString("Expected alias target name"sv),span))));
return JaktInternal::LoopBreak{};
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 96: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::Throw>();
utility::Span const& span = __jakt_match_value.value;
{
TRY((((*this).error(Jakt::DeprecatedString("Expected alias target name"sv),span))));
return JaktInternal::LoopBreak{};
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 97: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::Throws>();
utility::Span const& span = __jakt_match_value.value;
{
TRY((((*this).error(Jakt::DeprecatedString("Expected alias target name"sv),span))));
return JaktInternal::LoopBreak{};
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 98: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::True>();
utility::Span const& span = __jakt_match_value.value;
{
TRY((((*this).error(Jakt::DeprecatedString("Expected alias target name"sv),span))));
return JaktInternal::LoopBreak{};
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 99: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::Try>();
utility::Span const& span = __jakt_match_value.value;
{
TRY((((*this).error(Jakt::DeprecatedString("Expected alias target name"sv),span))));
return JaktInternal::LoopBreak{};
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 100: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::Unsafe>();
utility::Span const& span = __jakt_match_value.value;
{
TRY((((*this).error(Jakt::DeprecatedString("Expected alias target name"sv),span))));
return JaktInternal::LoopBreak{};
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 101: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::Virtual>();
utility::Span const& span = __jakt_match_value.value;
{
TRY((((*this).error(Jakt::DeprecatedString("Expected alias target name"sv),span))));
return JaktInternal::LoopBreak{};
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 102: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::Weak>();
utility::Span const& span = __jakt_match_value.value;
{
TRY((((*this).error(Jakt::DeprecatedString("Expected alias target name"sv),span))));
return JaktInternal::LoopBreak{};
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 103: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::While>();
utility::Span const& span = __jakt_match_value.value;
{
TRY((((*this).error(Jakt::DeprecatedString("Expected alias target name"sv),span))));
return JaktInternal::LoopBreak{};
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 104: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::Yield>();
utility::Span const& span = __jakt_match_value.value;
{
TRY((((*this).error(Jakt::DeprecatedString("Expected alias target name"sv),span))));
return JaktInternal::LoopBreak{};
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 105: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::Guard>();
utility::Span const& span = __jakt_match_value.value;
{
TRY((((*this).error(Jakt::DeprecatedString("Expected alias target name"sv),span))));
return JaktInternal::LoopBreak{};
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 106: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::Implements>();
utility::Span const& span = __jakt_match_value.value;
{
TRY((((*this).error(Jakt::DeprecatedString("Expected alias target name"sv),span))));
return JaktInternal::LoopBreak{};
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 107: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::Requires>();
utility::Span const& span = __jakt_match_value.value;
{
TRY((((*this).error(Jakt::DeprecatedString("Expected alias target name"sv),span))));
return JaktInternal::LoopBreak{};
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 108: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::Trait>();
utility::Span const& span = __jakt_match_value.value;
{
TRY((((*this).error(Jakt::DeprecatedString("Expected alias target name"sv),span))));
return JaktInternal::LoopBreak{};
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 109: {
auto&& __jakt_match_value = __jakt_match_variant.template get<lexer::Token::Garbage>();utility::Span const& span = __jakt_match_value.span;
{
TRY((((*this).error(Jakt::DeprecatedString("Expected alias target name"sv),span))));
return JaktInternal::LoopBreak{};
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
default: VERIFY_NOT_REACHED();}/*switch end*/
}()
));
}
if (((((*this).previous())).index() == 7 /* ColonColon */)){
utility::Span const span = ((((*this).previous())).get<lexer::Token::ColonColon>()).value;
TRY((((*this).error(Jakt::DeprecatedString("Expected alias target name"sv),span))));
}
if (((((*this).current())).index() == 62 /* As */)){
((((*this).index)++));
JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<void, ErrorOr<parser::ParsedAlias>>{
auto&& __jakt_match_variant = ((*this).current());
switch(__jakt_match_variant.index()) {
case 4: {
auto&& __jakt_match_value = __jakt_match_variant.template get<lexer::Token::Identifier>();DeprecatedString const& name = __jakt_match_value.name;
utility::Span const& span = __jakt_match_value.span;
{
(((alias).alias_name) = parser::ParsedName(name,span));
((((*this).index)++));
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 0: {
auto&& __jakt_match_value = __jakt_match_variant.template get<lexer::Token::SingleQuotedString>();utility::Span const& span = __jakt_match_value.span;
{
TRY((((*this).error(Jakt::DeprecatedString("Expected alias name"sv),span))));
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 1: {
auto&& __jakt_match_value = __jakt_match_variant.template get<lexer::Token::SingleQuotedByteString>();utility::Span const& span = __jakt_match_value.span;
{
TRY((((*this).error(Jakt::DeprecatedString("Expected alias name"sv),span))));
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 2: {
auto&& __jakt_match_value = __jakt_match_variant.template get<lexer::Token::QuotedString>();utility::Span const& span = __jakt_match_value.span;
{
TRY((((*this).error(Jakt::DeprecatedString("Expected alias name"sv),span))));
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 3: {
auto&& __jakt_match_value = __jakt_match_variant.template get<lexer::Token::Number>();utility::Span const& span = __jakt_match_value.span;
{
TRY((((*this).error(Jakt::DeprecatedString("Expected alias name"sv),span))));
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 5: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::Semicolon>();
utility::Span const& span = __jakt_match_value.value;
{
TRY((((*this).error(Jakt::DeprecatedString("Expected alias name"sv),span))));
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 6: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::Colon>();
utility::Span const& span = __jakt_match_value.value;
{
TRY((((*this).error(Jakt::DeprecatedString("Expected alias name"sv),span))));
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 7: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::ColonColon>();
utility::Span const& span = __jakt_match_value.value;
{
TRY((((*this).error(Jakt::DeprecatedString("Expected alias name"sv),span))));
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 8: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::LParen>();
utility::Span const& span = __jakt_match_value.value;
{
TRY((((*this).error(Jakt::DeprecatedString("Expected alias name"sv),span))));
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 9: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::RParen>();
utility::Span const& span = __jakt_match_value.value;
{
TRY((((*this).error(Jakt::DeprecatedString("Expected alias name"sv),span))));
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 10: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::LCurly>();
utility::Span const& span = __jakt_match_value.value;
{
TRY((((*this).error(Jakt::DeprecatedString("Expected alias name"sv),span))));
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 11: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::RCurly>();
utility::Span const& span = __jakt_match_value.value;
{
TRY((((*this).error(Jakt::DeprecatedString("Expected alias name"sv),span))));
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 12: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::LSquare>();
utility::Span const& span = __jakt_match_value.value;
{
TRY((((*this).error(Jakt::DeprecatedString("Expected alias name"sv),span))));
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 13: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::RSquare>();
utility::Span const& span = __jakt_match_value.value;
{
TRY((((*this).error(Jakt::DeprecatedString("Expected alias name"sv),span))));
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 14: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::PercentSign>();
utility::Span const& span = __jakt_match_value.value;
{
TRY((((*this).error(Jakt::DeprecatedString("Expected alias name"sv),span))));
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 15: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::Plus>();
utility::Span const& span = __jakt_match_value.value;
{
TRY((((*this).error(Jakt::DeprecatedString("Expected alias name"sv),span))));
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 16: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::Minus>();
utility::Span const& span = __jakt_match_value.value;
{
TRY((((*this).error(Jakt::DeprecatedString("Expected alias name"sv),span))));
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 17: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::Equal>();
utility::Span const& span = __jakt_match_value.value;
{
TRY((((*this).error(Jakt::DeprecatedString("Expected alias name"sv),span))));
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 18: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::PlusEqual>();
utility::Span const& span = __jakt_match_value.value;
{
TRY((((*this).error(Jakt::DeprecatedString("Expected alias name"sv),span))));
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 19: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::PlusPlus>();
utility::Span const& span = __jakt_match_value.value;
{
TRY((((*this).error(Jakt::DeprecatedString("Expected alias name"sv),span))));
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 20: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::MinusEqual>();
utility::Span const& span = __jakt_match_value.value;
{
TRY((((*this).error(Jakt::DeprecatedString("Expected alias name"sv),span))));
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 21: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::MinusMinus>();
utility::Span const& span = __jakt_match_value.value;
{
TRY((((*this).error(Jakt::DeprecatedString("Expected alias name"sv),span))));
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 22: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::AsteriskEqual>();
utility::Span const& span = __jakt_match_value.value;
{
TRY((((*this).error(Jakt::DeprecatedString("Expected alias name"sv),span))));
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 23: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::ForwardSlashEqual>();
utility::Span const& span = __jakt_match_value.value;
{
TRY((((*this).error(Jakt::DeprecatedString("Expected alias name"sv),span))));
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 24: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::PercentSignEqual>();
utility::Span const& span = __jakt_match_value.value;
{
TRY((((*this).error(Jakt::DeprecatedString("Expected alias name"sv),span))));
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 25: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::NotEqual>();
utility::Span const& span = __jakt_match_value.value;
{
TRY((((*this).error(Jakt::DeprecatedString("Expected alias name"sv),span))));
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 26: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::DoubleEqual>();
utility::Span const& span = __jakt_match_value.value;
{
TRY((((*this).error(Jakt::DeprecatedString("Expected alias name"sv),span))));
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 27: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::GreaterThan>();
utility::Span const& span = __jakt_match_value.value;
{
TRY((((*this).error(Jakt::DeprecatedString("Expected alias name"sv),span))));
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 28: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::GreaterThanOrEqual>();
utility::Span const& span = __jakt_match_value.value;
{
TRY((((*this).error(Jakt::DeprecatedString("Expected alias name"sv),span))));
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 29: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::LessThan>();
utility::Span const& span = __jakt_match_value.value;
{
TRY((((*this).error(Jakt::DeprecatedString("Expected alias name"sv),span))));
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 30: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::LessThanOrEqual>();
utility::Span const& span = __jakt_match_value.value;
{
TRY((((*this).error(Jakt::DeprecatedString("Expected alias name"sv),span))));
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 31: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::LeftArithmeticShift>();
utility::Span const& span = __jakt_match_value.value;
{
TRY((((*this).error(Jakt::DeprecatedString("Expected alias name"sv),span))));
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 32: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::LeftShift>();
utility::Span const& span = __jakt_match_value.value;
{
TRY((((*this).error(Jakt::DeprecatedString("Expected alias name"sv),span))));
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 33: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::LeftShiftEqual>();
utility::Span const& span = __jakt_match_value.value;
{
TRY((((*this).error(Jakt::DeprecatedString("Expected alias name"sv),span))));
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 34: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::RightShift>();
utility::Span const& span = __jakt_match_value.value;
{
TRY((((*this).error(Jakt::DeprecatedString("Expected alias name"sv),span))));
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 35: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::RightArithmeticShift>();
utility::Span const& span = __jakt_match_value.value;
{
TRY((((*this).error(Jakt::DeprecatedString("Expected alias name"sv),span))));
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 36: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::RightShiftEqual>();
utility::Span const& span = __jakt_match_value.value;
{
TRY((((*this).error(Jakt::DeprecatedString("Expected alias name"sv),span))));
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 37: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::Asterisk>();
utility::Span const& span = __jakt_match_value.value;
{
TRY((((*this).error(Jakt::DeprecatedString("Expected alias name"sv),span))));
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 38: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::Ampersand>();
utility::Span const& span = __jakt_match_value.value;
{
TRY((((*this).error(Jakt::DeprecatedString("Expected alias name"sv),span))));
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 39: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::AmpersandEqual>();
utility::Span const& span = __jakt_match_value.value;
{
TRY((((*this).error(Jakt::DeprecatedString("Expected alias name"sv),span))));
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 40: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::AmpersandAmpersand>();
utility::Span const& span = __jakt_match_value.value;
{
TRY((((*this).error(Jakt::DeprecatedString("Expected alias name"sv),span))));
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 41: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::Pipe>();
utility::Span const& span = __jakt_match_value.value;
{
TRY((((*this).error(Jakt::DeprecatedString("Expected alias name"sv),span))));
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 42: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::PipeEqual>();
utility::Span const& span = __jakt_match_value.value;
{
TRY((((*this).error(Jakt::DeprecatedString("Expected alias name"sv),span))));
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 43: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::PipePipe>();
utility::Span const& span = __jakt_match_value.value;
{
TRY((((*this).error(Jakt::DeprecatedString("Expected alias name"sv),span))));
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 44: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::Caret>();
utility::Span const& span = __jakt_match_value.value;
{
TRY((((*this).error(Jakt::DeprecatedString("Expected alias name"sv),span))));
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 45: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::CaretEqual>();
utility::Span const& span = __jakt_match_value.value;
{
TRY((((*this).error(Jakt::DeprecatedString("Expected alias name"sv),span))));
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 46: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::Dollar>();
utility::Span const& span = __jakt_match_value.value;
{
TRY((((*this).error(Jakt::DeprecatedString("Expected alias name"sv),span))));
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 47: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::Tilde>();
utility::Span const& span = __jakt_match_value.value;
{
TRY((((*this).error(Jakt::DeprecatedString("Expected alias name"sv),span))));
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 48: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::ForwardSlash>();
utility::Span const& span = __jakt_match_value.value;
{
TRY((((*this).error(Jakt::DeprecatedString("Expected alias name"sv),span))));
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 49: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::ExclamationPoint>();
utility::Span const& span = __jakt_match_value.value;
{
TRY((((*this).error(Jakt::DeprecatedString("Expected alias name"sv),span))));
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 50: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::QuestionMark>();
utility::Span const& span = __jakt_match_value.value;
{
TRY((((*this).error(Jakt::DeprecatedString("Expected alias name"sv),span))));
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 51: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::QuestionMarkQuestionMark>();
utility::Span const& span = __jakt_match_value.value;
{
TRY((((*this).error(Jakt::DeprecatedString("Expected alias name"sv),span))));
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 52: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::QuestionMarkQuestionMarkEqual>();
utility::Span const& span = __jakt_match_value.value;
{
TRY((((*this).error(Jakt::DeprecatedString("Expected alias name"sv),span))));
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 53: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::Comma>();
utility::Span const& span = __jakt_match_value.value;
{
TRY((((*this).error(Jakt::DeprecatedString("Expected alias name"sv),span))));
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 54: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::Dot>();
utility::Span const& span = __jakt_match_value.value;
{
TRY((((*this).error(Jakt::DeprecatedString("Expected alias name"sv),span))));
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 55: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::DotDot>();
utility::Span const& span = __jakt_match_value.value;
{
TRY((((*this).error(Jakt::DeprecatedString("Expected alias name"sv),span))));
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 56: {
auto&& __jakt_match_value = __jakt_match_variant.template get<lexer::Token::Eol>();utility::Span const& span = __jakt_match_value.span;
{
TRY((((*this).error(Jakt::DeprecatedString("Expected alias name"sv),span))));
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 57: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::Eof>();
utility::Span const& span = __jakt_match_value.value;
{
TRY((((*this).error(Jakt::DeprecatedString("Expected alias name"sv),span))));
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 58: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::FatArrow>();
utility::Span const& span = __jakt_match_value.value;
{
TRY((((*this).error(Jakt::DeprecatedString("Expected alias name"sv),span))));
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 59: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::Arrow>();
utility::Span const& span = __jakt_match_value.value;
{
TRY((((*this).error(Jakt::DeprecatedString("Expected alias name"sv),span))));
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 60: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::And>();
utility::Span const& span = __jakt_match_value.value;
{
TRY((((*this).error(Jakt::DeprecatedString("Expected alias name"sv),span))));
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 61: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::Anon>();
utility::Span const& span = __jakt_match_value.value;
{
TRY((((*this).error(Jakt::DeprecatedString("Expected alias name"sv),span))));
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 62: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::As>();
utility::Span const& span = __jakt_match_value.value;
{
TRY((((*this).error(Jakt::DeprecatedString("Expected alias name"sv),span))));
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 63: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::Boxed>();
utility::Span const& span = __jakt_match_value.value;
{
TRY((((*this).error(Jakt::DeprecatedString("Expected alias name"sv),span))));
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 64: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::Break>();
utility::Span const& span = __jakt_match_value.value;
{
TRY((((*this).error(Jakt::DeprecatedString("Expected alias name"sv),span))));
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 65: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::Catch>();
utility::Span const& span = __jakt_match_value.value;
{
TRY((((*this).error(Jakt::DeprecatedString("Expected alias name"sv),span))));
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 66: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::Class>();
utility::Span const& span = __jakt_match_value.value;
{
TRY((((*this).error(Jakt::DeprecatedString("Expected alias name"sv),span))));
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 67: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::Continue>();
utility::Span const& span = __jakt_match_value.value;
{
TRY((((*this).error(Jakt::DeprecatedString("Expected alias name"sv),span))));
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 68: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::Cpp>();
utility::Span const& span = __jakt_match_value.value;
{
TRY((((*this).error(Jakt::DeprecatedString("Expected alias name"sv),span))));
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 69: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::Defer>();
utility::Span const& span = __jakt_match_value.value;
{
TRY((((*this).error(Jakt::DeprecatedString("Expected alias name"sv),span))));
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 70: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::Else>();
utility::Span const& span = __jakt_match_value.value;
{
TRY((((*this).error(Jakt::DeprecatedString("Expected alias name"sv),span))));
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 71: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::Enum>();
utility::Span const& span = __jakt_match_value.value;
{
TRY((((*this).error(Jakt::DeprecatedString("Expected alias name"sv),span))));
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 72: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::Extern>();
utility::Span const& span = __jakt_match_value.value;
{
TRY((((*this).error(Jakt::DeprecatedString("Expected alias name"sv),span))));
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 73: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::False>();
utility::Span const& span = __jakt_match_value.value;
{
TRY((((*this).error(Jakt::DeprecatedString("Expected alias name"sv),span))));
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 74: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::For>();
utility::Span const& span = __jakt_match_value.value;
{
TRY((((*this).error(Jakt::DeprecatedString("Expected alias name"sv),span))));
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 75: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::Function>();
utility::Span const& span = __jakt_match_value.value;
{
TRY((((*this).error(Jakt::DeprecatedString("Expected alias name"sv),span))));
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 76: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::Comptime>();
utility::Span const& span = __jakt_match_value.value;
{
TRY((((*this).error(Jakt::DeprecatedString("Expected alias name"sv),span))));
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 77: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::If>();
utility::Span const& span = __jakt_match_value.value;
{
TRY((((*this).error(Jakt::DeprecatedString("Expected alias name"sv),span))));
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 78: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::Import>();
utility::Span const& span = __jakt_match_value.value;
{
TRY((((*this).error(Jakt::DeprecatedString("Expected alias name"sv),span))));
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 79: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::In>();
utility::Span const& span = __jakt_match_value.value;
{
TRY((((*this).error(Jakt::DeprecatedString("Expected alias name"sv),span))));
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 80: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::Is>();
utility::Span const& span = __jakt_match_value.value;
{
TRY((((*this).error(Jakt::DeprecatedString("Expected alias name"sv),span))));
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 81: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::Let>();
utility::Span const& span = __jakt_match_value.value;
{
TRY((((*this).error(Jakt::DeprecatedString("Expected alias name"sv),span))));
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 82: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::Loop>();
utility::Span const& span = __jakt_match_value.value;
{
TRY((((*this).error(Jakt::DeprecatedString("Expected alias name"sv),span))));
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 83: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::Match>();
utility::Span const& span = __jakt_match_value.value;
{
TRY((((*this).error(Jakt::DeprecatedString("Expected alias name"sv),span))));
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 84: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::Mut>();
utility::Span const& span = __jakt_match_value.value;
{
TRY((((*this).error(Jakt::DeprecatedString("Expected alias name"sv),span))));
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 85: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::Namespace>();
utility::Span const& span = __jakt_match_value.value;
{
TRY((((*this).error(Jakt::DeprecatedString("Expected alias name"sv),span))));
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 86: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::Not>();
utility::Span const& span = __jakt_match_value.value;
{
TRY((((*this).error(Jakt::DeprecatedString("Expected alias name"sv),span))));
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 87: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::Or>();
utility::Span const& span = __jakt_match_value.value;
{
TRY((((*this).error(Jakt::DeprecatedString("Expected alias name"sv),span))));
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 88: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::Override>();
utility::Span const& span = __jakt_match_value.value;
{
TRY((((*this).error(Jakt::DeprecatedString("Expected alias name"sv),span))));
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 89: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::Private>();
utility::Span const& span = __jakt_match_value.value;
{
TRY((((*this).error(Jakt::DeprecatedString("Expected alias name"sv),span))));
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 90: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::Public>();
utility::Span const& span = __jakt_match_value.value;
{
TRY((((*this).error(Jakt::DeprecatedString("Expected alias name"sv),span))));
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 91: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::Raw>();
utility::Span const& span = __jakt_match_value.value;
{
TRY((((*this).error(Jakt::DeprecatedString("Expected alias name"sv),span))));
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 92: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::Return>();
utility::Span const& span = __jakt_match_value.value;
{
TRY((((*this).error(Jakt::DeprecatedString("Expected alias name"sv),span))));
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 93: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::Restricted>();
utility::Span const& span = __jakt_match_value.value;
{
TRY((((*this).error(Jakt::DeprecatedString("Expected alias name"sv),span))));
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 94: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::Struct>();
utility::Span const& span = __jakt_match_value.value;
{
TRY((((*this).error(Jakt::DeprecatedString("Expected alias name"sv),span))));
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 95: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::This>();
utility::Span const& span = __jakt_match_value.value;
{
TRY((((*this).error(Jakt::DeprecatedString("Expected alias name"sv),span))));
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 96: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::Throw>();
utility::Span const& span = __jakt_match_value.value;
{
TRY((((*this).error(Jakt::DeprecatedString("Expected alias name"sv),span))));
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 97: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::Throws>();
utility::Span const& span = __jakt_match_value.value;
{
TRY((((*this).error(Jakt::DeprecatedString("Expected alias name"sv),span))));
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 98: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::True>();
utility::Span const& span = __jakt_match_value.value;
{
TRY((((*this).error(Jakt::DeprecatedString("Expected alias name"sv),span))));
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 99: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::Try>();
utility::Span const& span = __jakt_match_value.value;
{
TRY((((*this).error(Jakt::DeprecatedString("Expected alias name"sv),span))));
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 100: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::Unsafe>();
utility::Span const& span = __jakt_match_value.value;
{
TRY((((*this).error(Jakt::DeprecatedString("Expected alias name"sv),span))));
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 101: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::Virtual>();
utility::Span const& span = __jakt_match_value.value;
{
TRY((((*this).error(Jakt::DeprecatedString("Expected alias name"sv),span))));
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 102: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::Weak>();
utility::Span const& span = __jakt_match_value.value;
{
TRY((((*this).error(Jakt::DeprecatedString("Expected alias name"sv),span))));
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 103: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::While>();
utility::Span const& span = __jakt_match_value.value;
{
TRY((((*this).error(Jakt::DeprecatedString("Expected alias name"sv),span))));
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 104: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::Yield>();
utility::Span const& span = __jakt_match_value.value;
{
TRY((((*this).error(Jakt::DeprecatedString("Expected alias name"sv),span))));
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 105: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::Guard>();
utility::Span const& span = __jakt_match_value.value;
{
TRY((((*this).error(Jakt::DeprecatedString("Expected alias name"sv),span))));
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 106: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::Implements>();
utility::Span const& span = __jakt_match_value.value;
{
TRY((((*this).error(Jakt::DeprecatedString("Expected alias name"sv),span))));
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 107: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::Requires>();
utility::Span const& span = __jakt_match_value.value;
{
TRY((((*this).error(Jakt::DeprecatedString("Expected alias name"sv),span))));
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 108: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::Trait>();
utility::Span const& span = __jakt_match_value.value;
{
TRY((((*this).error(Jakt::DeprecatedString("Expected alias name"sv),span))));
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 109: {
auto&& __jakt_match_value = __jakt_match_variant.template get<lexer::Token::Garbage>();utility::Span const& span = __jakt_match_value.span;
{
TRY((((*this).error(Jakt::DeprecatedString("Expected alias name"sv),span))));
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
default: VERIFY_NOT_REACHED();}/*switch end*/
}()
));
}
return (alias);
}
}

lexer::Token parser::Parser::current() const {
{
return (((*this).peek(static_cast<size_t>(0ULL))));
}
}

ErrorOr<NonnullRefPtr<typename parser::ParsedExpression>> parser::Parser::parse_expression(bool const allow_assignments,bool const allow_newlines) {
{
JaktInternal::DynamicArray<NonnullRefPtr<typename parser::ParsedExpression>> expr_stack = (TRY((DynamicArray<NonnullRefPtr<typename parser::ParsedExpression>>::create_with({}))));
i64 last_precedence = static_cast<i64>(1000000LL);
NonnullRefPtr<typename parser::ParsedExpression> const lhs = TRY((((*this).parse_operand())));
TRY((((expr_stack).push(lhs))));
for (;;){
if (allow_newlines){
if ((((*this).eof()) || ((((*this).current())).index() == 10 /* LCurly */))){
break;
}
((*this).skip_newlines());
}
else {
if (((*this).eol())){
break;
}
}

NonnullRefPtr<typename parser::ParsedExpression> const parsed_operator = TRY((((*this).parse_operator(allow_assignments))));
if (((parsed_operator)->index() == 28 /* Garbage */)){
break;
}
i64 const precedence = ((parsed_operator)->precedence());
((*this).skip_newlines());
NonnullRefPtr<typename parser::ParsedExpression> const rhs = TRY((((*this).parse_operand())));
while (((precedence <= last_precedence) && (((expr_stack).size()) > static_cast<size_t>(1ULL)))){
NonnullRefPtr<typename parser::ParsedExpression> const rhs = (((expr_stack).pop()).value());
NonnullRefPtr<typename parser::ParsedExpression> const op = (((expr_stack).pop()).value());
(last_precedence = ((op)->precedence()));
if ((last_precedence < precedence)){
TRY((((expr_stack).push(op))));
TRY((((expr_stack).push(rhs))));
break;
}
NonnullRefPtr<typename parser::ParsedExpression> const lhs = (((expr_stack).pop()).value());
JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_AT_LOOP(([&]() -> JaktInternal::ExplicitValueOrControlFlow<void, ErrorOr<NonnullRefPtr<typename parser::ParsedExpression>>>{
auto&& __jakt_match_variant = *op;
switch(__jakt_match_variant.index()) {
case 13: {
auto&& __jakt_match_value = __jakt_match_variant.template get<parser::ParsedExpression::Operator>();parser::BinaryOperator const& op = __jakt_match_value.op;
utility::Span const& span = __jakt_match_value.span;
{
utility::Span const new_span = TRY((parser::merge_spans(((lhs)->span()),((rhs)->span()))));
TRY((((expr_stack).push(TRY((parser::ParsedExpression::template create<typename parser::ParsedExpression::BinaryOp>(lhs,op,rhs,new_span)))))));
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
default: {
{
TRY((((((*this).compiler))->panic(Jakt::DeprecatedString("operator is not an operator"sv)))));
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
}/*switch end*/
}()
));
}
TRY((((expr_stack).push(parsed_operator))));
TRY((((expr_stack).push(rhs))));
(last_precedence = precedence);
}
while ((((expr_stack).size()) > static_cast<size_t>(1ULL))){
NonnullRefPtr<typename parser::ParsedExpression> const rhs = (((expr_stack).pop()).value());
NonnullRefPtr<typename parser::ParsedExpression> const parsed_operator = (((expr_stack).pop()).value());
NonnullRefPtr<typename parser::ParsedExpression> const lhs = (((expr_stack).pop()).value());
JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_AT_LOOP(([&]() -> JaktInternal::ExplicitValueOrControlFlow<void, ErrorOr<NonnullRefPtr<typename parser::ParsedExpression>>>{
auto&& __jakt_match_variant = *parsed_operator;
switch(__jakt_match_variant.index()) {
case 13: {
auto&& __jakt_match_value = __jakt_match_variant.template get<parser::ParsedExpression::Operator>();parser::BinaryOperator const& op = __jakt_match_value.op;
utility::Span const& span = __jakt_match_value.span;
{
utility::Span const new_span = TRY((parser::merge_spans(((lhs)->span()),((rhs)->span()))));
TRY((((expr_stack).push(TRY((parser::ParsedExpression::template create<typename parser::ParsedExpression::BinaryOp>(lhs,op,rhs,new_span)))))));
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
default: {
{
TRY((((((*this).compiler))->panic(Jakt::DeprecatedString("operator is not an operator"sv)))));
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
}/*switch end*/
}()
));
}
return (((expr_stack)[static_cast<i64>(0LL)]));
}
}

lexer::Token parser::Parser::peek(size_t const steps) const {
{
if ((((*this).eof()) || ((JaktInternal::checked_add<size_t>(steps,((*this).index))) >= ((((*this).tokens)).size())))){
return ((((((*this).tokens)).last()).value()));
}
return (((((*this).tokens))[(JaktInternal::checked_add<size_t>(((*this).index),steps))]));
}
}

ErrorOr<NonnullRefPtr<typename parser::ParsedType>> parser::Parser::parse_type_shorthand() {
{
return (JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<NonnullRefPtr<typename parser::ParsedType>, ErrorOr<NonnullRefPtr<typename parser::ParsedType>>>{
auto&& __jakt_match_variant = ((*this).current());
switch(__jakt_match_variant.index()) {
case 12: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::LSquare>();
return JaktInternal::ExplicitValue(TRY((((*this).parse_type_shorthand_array_or_dictionary()))));
};/*case end*/
case 10: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::LCurly>();
return JaktInternal::ExplicitValue(TRY((((*this).parse_type_shorthand_set()))));
};/*case end*/
case 8: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename lexer::Token::LParen>();
return JaktInternal::ExplicitValue(TRY((((*this).parse_type_shorthand_tuple()))));
};/*case end*/
default: {
return JaktInternal::ExplicitValue(TRY((parser::ParsedType::template create<typename parser::ParsedType::Empty>())));
};/*case end*/
}/*switch end*/
}()
)));
}
}

utility::Span parser::Parser::empty_span() const {
{
return (((*this).span(static_cast<size_t>(0ULL),static_cast<size_t>(0ULL))));
}
}

ErrorOr<parser::ParsedVarDecl> parser::Parser::parse_variable_declaration(bool const is_mutable) {
{
utility::Span const span = ((((*this).current())).span());
if (((((*this).current())).index() == 4 /* Identifier */)){
DeprecatedString const name = ((((*this).current())).get<lexer::Token::Identifier>()).name;
((((*this).index)++));
if (((((*this).current())).index() == 6 /* Colon */)){
((((*this).index)++));
}
else {
return (parser::ParsedVarDecl(name,TRY((parser::ParsedType::template create<typename parser::ParsedType::Empty>())),is_mutable,span,span));
}

NonnullRefPtr<typename parser::ParsedType> const parsed_type = TRY((((*this).parse_typename())));
if ((is_mutable && (((parsed_type)->index() == 8 /* Reference */) || ((parsed_type)->index() == 9 /* MutableReference */)))){
TRY((((*this).error(Jakt::DeprecatedString("Reference parameter can not be mutable"sv),span))));
}
return (parser::ParsedVarDecl(name,parsed_type,is_mutable,JaktInternal::OptionalNone(),span));
}
else {
return (parser::ParsedVarDecl(Jakt::DeprecatedString(""sv),TRY((parser::ParsedType::template create<typename parser::ParsedType::Empty>())),false,JaktInternal::OptionalNone(),span));
}

}
}

ErrorOr<DeprecatedString> parser::ParsedCall::debug_description() const { auto builder = MUST(DeprecatedStringBuilder::create());TRY(builder.append("ParsedCall("sv));{
JaktInternal::PrettyPrint::ScopedLevelIncrease increase_indent {};
TRY(JaktInternal::PrettyPrint::output_indentation(builder));TRY(builder.append("namespace_: "sv));TRY(builder.appendff("{}, ", namespace_));
TRY(JaktInternal::PrettyPrint::output_indentation(builder));TRY(builder.append("name: "sv));TRY(builder.appendff("\"{}\", ", name));
TRY(JaktInternal::PrettyPrint::output_indentation(builder));TRY(builder.append("args: "sv));TRY(builder.appendff("{}, ", args));
TRY(JaktInternal::PrettyPrint::output_indentation(builder));TRY(builder.append("type_args: "sv));TRY(builder.appendff("{}", type_args));
}
TRY(builder.append(")"sv));return builder.to_string(); }
parser::ParsedCall::ParsedCall(JaktInternal::DynamicArray<DeprecatedString> a_namespace_, DeprecatedString a_name, JaktInternal::DynamicArray<JaktInternal::Tuple<DeprecatedString,utility::Span,NonnullRefPtr<typename parser::ParsedExpression>>> a_args, JaktInternal::DynamicArray<NonnullRefPtr<typename parser::ParsedType>> a_type_args) :namespace_(a_namespace_), name(a_name), args(a_args), type_args(a_type_args){}

bool parser::ParsedCall::equals(parser::ParsedCall const rhs_parsed_call) const {
{
if ((((*this).name) != ((rhs_parsed_call).name))){
return (false);
}
if ((((((*this).args)).size()) != ((((rhs_parsed_call).args)).size()))){
return (false);
}
{
JaktInternal::Range<size_t> _magic = (JaktInternal::Range<size_t>{static_cast<size_t>(static_cast<size_t>(0ULL)),static_cast<size_t>(((((*this).args)).size()))});
for (;;){
JaktInternal::Optional<size_t> _magic_value = ((_magic).next());
if ((!(((_magic_value).has_value())))){
break;
}
size_t i = (_magic_value.value());
{
JaktInternal::Tuple<DeprecatedString,utility::Span,NonnullRefPtr<typename parser::ParsedExpression>> const lhs_str___lhs_expr_ = ((((*this).args))[i]);
DeprecatedString const lhs_str = ((lhs_str___lhs_expr_).template get<0>());
utility::Span const _ = ((lhs_str___lhs_expr_).template get<1>());
NonnullRefPtr<typename parser::ParsedExpression> const lhs_expr = ((lhs_str___lhs_expr_).template get<2>());

JaktInternal::Tuple<DeprecatedString,utility::Span,NonnullRefPtr<typename parser::ParsedExpression>> const rhs_str____rhs_expr_ = ((((rhs_parsed_call).args))[i]);
DeprecatedString const rhs_str = ((rhs_str____rhs_expr_).template get<0>());
utility::Span const __ = ((rhs_str____rhs_expr_).template get<1>());
NonnullRefPtr<typename parser::ParsedExpression> const rhs_expr = ((rhs_str____rhs_expr_).template get<2>());

if (((lhs_str != rhs_str) || (!(((lhs_expr)->equals(rhs_expr)))))){
return (false);
}
}

}
}

return (true);
}
}

ErrorOr<DeprecatedString> parser::ParsedNamespace::debug_description() const { auto builder = MUST(DeprecatedStringBuilder::create());TRY(builder.append("ParsedNamespace("sv));{
JaktInternal::PrettyPrint::ScopedLevelIncrease increase_indent {};
TRY(JaktInternal::PrettyPrint::output_indentation(builder));TRY(builder.append("name: "sv));TRY(builder.appendff("{}, ", name));
TRY(JaktInternal::PrettyPrint::output_indentation(builder));TRY(builder.append("name_span: "sv));TRY(builder.appendff("{}, ", name_span));
TRY(JaktInternal::PrettyPrint::output_indentation(builder));TRY(builder.append("functions: "sv));TRY(builder.appendff("{}, ", functions));
TRY(JaktInternal::PrettyPrint::output_indentation(builder));TRY(builder.append("records: "sv));TRY(builder.appendff("{}, ", records));
TRY(JaktInternal::PrettyPrint::output_indentation(builder));TRY(builder.append("traits: "sv));TRY(builder.appendff("{}, ", traits));
TRY(JaktInternal::PrettyPrint::output_indentation(builder));TRY(builder.append("external_trait_implementations: "sv));TRY(builder.appendff("{}, ", external_trait_implementations));
TRY(JaktInternal::PrettyPrint::output_indentation(builder));TRY(builder.append("namespaces: "sv));TRY(builder.appendff("{}, ", namespaces));
TRY(JaktInternal::PrettyPrint::output_indentation(builder));TRY(builder.append("aliases: "sv));TRY(builder.appendff("{}, ", aliases));
TRY(JaktInternal::PrettyPrint::output_indentation(builder));TRY(builder.append("module_imports: "sv));TRY(builder.appendff("{}, ", module_imports));
TRY(JaktInternal::PrettyPrint::output_indentation(builder));TRY(builder.append("extern_imports: "sv));TRY(builder.appendff("{}, ", extern_imports));
TRY(JaktInternal::PrettyPrint::output_indentation(builder));TRY(builder.append("import_path_if_extern: "sv));TRY(builder.appendff("{}, ", import_path_if_extern));
TRY(JaktInternal::PrettyPrint::output_indentation(builder));TRY(builder.append("generating_import_extern_before_include: "sv));TRY(builder.appendff("{}, ", generating_import_extern_before_include));
TRY(JaktInternal::PrettyPrint::output_indentation(builder));TRY(builder.append("generating_import_extern_after_include: "sv));TRY(builder.appendff("{}", generating_import_extern_after_include));
}
TRY(builder.append(")"sv));return builder.to_string(); }
ErrorOr<void> parser::ParsedNamespace::add_child_namespace(parser::ParsedNamespace const namespace_) {
{
{
JaktInternal::ArrayIterator<parser::ParsedNamespace> _magic = ((((*this).namespaces)).iterator());
for (;;){
JaktInternal::Optional<parser::ParsedNamespace> _magic_value = ((_magic).next());
if ((!(((_magic_value).has_value())))){
break;
}
parser::ParsedNamespace child_namespace = (_magic_value.value());
{
if (((child_namespace).is_equivalent_to(namespace_))){
TRY((((child_namespace).merge_with(namespace_))));
return {};
}
}

}
}

TRY((((((*this).namespaces)).push(namespace_))));
}
return {};
}

parser::ParsedNamespace::ParsedNamespace(JaktInternal::Optional<DeprecatedString> a_name, JaktInternal::Optional<utility::Span> a_name_span, JaktInternal::DynamicArray<parser::ParsedFunction> a_functions, JaktInternal::DynamicArray<parser::ParsedRecord> a_records, JaktInternal::DynamicArray<parser::ParsedTrait> a_traits, JaktInternal::DynamicArray<parser::ParsedExternalTraitImplementation> a_external_trait_implementations, JaktInternal::DynamicArray<parser::ParsedNamespace> a_namespaces, JaktInternal::DynamicArray<parser::ParsedAlias> a_aliases, JaktInternal::DynamicArray<parser::ParsedModuleImport> a_module_imports, JaktInternal::DynamicArray<parser::ParsedExternImport> a_extern_imports, JaktInternal::Optional<DeprecatedString> a_import_path_if_extern, JaktInternal::DynamicArray<parser::IncludeAction> a_generating_import_extern_before_include, JaktInternal::DynamicArray<parser::IncludeAction> a_generating_import_extern_after_include) :name(a_name), name_span(a_name_span), functions(a_functions), records(a_records), traits(a_traits), external_trait_implementations(a_external_trait_implementations), namespaces(a_namespaces), aliases(a_aliases), module_imports(a_module_imports), extern_imports(a_extern_imports), import_path_if_extern(a_import_path_if_extern), generating_import_extern_before_include(a_generating_import_extern_before_include), generating_import_extern_after_include(a_generating_import_extern_after_include){}

bool parser::ParsedNamespace::is_equivalent_to(parser::ParsedNamespace const other) const {
{
return (((((*this).name) == ((other).name)) && (((*this).import_path_if_extern) == ((other).import_path_if_extern))));
}
}

ErrorOr<void> parser::ParsedNamespace::add_extern_import(parser::ParsedExternImport const import_) {
{
{
JaktInternal::ArrayIterator<parser::ParsedExternImport> _magic = ((((*this).extern_imports)).iterator());
for (;;){
JaktInternal::Optional<parser::ParsedExternImport> _magic_value = ((_magic).next());
if ((!(((_magic_value).has_value())))){
break;
}
parser::ParsedExternImport extern_import = (_magic_value.value());
{
if (TRY((((extern_import).is_equivalent_to(import_))))){
TRY((((((extern_import).assigned_namespace)).merge_with(((import_).assigned_namespace)))));
TRY((((((extern_import).before_include)).push_values(((((import_).before_include)))))));
TRY((((((extern_import).after_include)).push_values(((((import_).after_include)))))));
return {};
}
}

}
}

TRY((((((*this).extern_imports)).push(import_))));
}
return {};
}

ErrorOr<void> parser::ParsedNamespace::add_alias(parser::ParsedAlias const alias) {
{
TRY((((((*this).aliases)).push(alias))));
}
return {};
}

ErrorOr<void> parser::ParsedNamespace::merge_with(parser::ParsedNamespace const namespace_) {
{
TRY((((((*this).functions)).push_values(((((namespace_).functions)))))));
TRY((((((*this).records)).push_values(((((namespace_).records)))))));
TRY((((((*this).module_imports)).add_capacity(((((namespace_).module_imports)).size())))));
{
JaktInternal::ArrayIterator<parser::ParsedModuleImport> _magic = ((((namespace_).module_imports)).iterator());
for (;;){
JaktInternal::Optional<parser::ParsedModuleImport> _magic_value = ((_magic).next());
if ((!(((_magic_value).has_value())))){
break;
}
parser::ParsedModuleImport import_ = (_magic_value.value());
{
TRY((((*this).add_module_import(import_))));
}

}
}

TRY((((((*this).extern_imports)).add_capacity(((((namespace_).extern_imports)).size())))));
{
JaktInternal::ArrayIterator<parser::ParsedExternImport> _magic = ((((namespace_).extern_imports)).iterator());
for (;;){
JaktInternal::Optional<parser::ParsedExternImport> _magic_value = ((_magic).next());
if ((!(((_magic_value).has_value())))){
break;
}
parser::ParsedExternImport import_ = (_magic_value.value());
{
TRY((((*this).add_extern_import(import_))));
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
parser::ParsedNamespace child_namespace = (_magic_value.value());
{
TRY((((*this).add_child_namespace(child_namespace))));
}

}
}

{
JaktInternal::ArrayIterator<parser::ParsedAlias> _magic = ((((namespace_).aliases)).iterator());
for (;;){
JaktInternal::Optional<parser::ParsedAlias> _magic_value = ((_magic).next());
if ((!(((_magic_value).has_value())))){
break;
}
parser::ParsedAlias alias = (_magic_value.value());
{
TRY((((*this).add_alias(alias))));
}

}
}

}
return {};
}

ErrorOr<void> parser::ParsedNamespace::add_module_import(parser::ParsedModuleImport const import_) {
{
{
JaktInternal::ArrayIterator<parser::ParsedModuleImport> _magic = ((((*this).module_imports)).iterator());
for (;;){
JaktInternal::Optional<parser::ParsedModuleImport> _magic_value = ((_magic).next());
if ((!(((_magic_value).has_value())))){
break;
}
parser::ParsedModuleImport module_import = (_magic_value.value());
{
if (((module_import).is_equivalent_to(import_))){
TRY((((module_import).merge_import_list(((import_).import_list)))));
return {};
}
}

}
}

TRY((((((*this).module_imports)).push(import_))));
}
return {};
}

ErrorOr<DeprecatedString> parser::ParsedName::debug_description() const { auto builder = MUST(DeprecatedStringBuilder::create());TRY(builder.append("ParsedName("sv));{
JaktInternal::PrettyPrint::ScopedLevelIncrease increase_indent {};
TRY(JaktInternal::PrettyPrint::output_indentation(builder));TRY(builder.append("name: "sv));TRY(builder.appendff("\"{}\", ", name));
TRY(JaktInternal::PrettyPrint::output_indentation(builder));TRY(builder.append("span: "sv));TRY(builder.appendff("{}", span));
}
TRY(builder.append(")"sv));return builder.to_string(); }
parser::ParsedName::ParsedName(DeprecatedString a_name, utility::Span a_span) :name(a_name), span(a_span){}

ErrorOr<DeprecatedString> parser::ParsedAlias::debug_description() const { auto builder = MUST(DeprecatedStringBuilder::create());TRY(builder.append("ParsedAlias("sv));{
JaktInternal::PrettyPrint::ScopedLevelIncrease increase_indent {};
TRY(JaktInternal::PrettyPrint::output_indentation(builder));TRY(builder.append("alias_name: "sv));TRY(builder.appendff("{}, ", alias_name));
TRY(JaktInternal::PrettyPrint::output_indentation(builder));TRY(builder.append("target: "sv));TRY(builder.appendff("{}", target));
}
TRY(builder.append(")"sv));return builder.to_string(); }
parser::ParsedAlias::ParsedAlias(JaktInternal::Optional<parser::ParsedName> a_alias_name, JaktInternal::DynamicArray<parser::ParsedNameWithGenericParameters> a_target) :alias_name(a_alias_name), target(a_target){}

ErrorOr<DeprecatedString> parser::ParsedVarDecl::debug_description() const { auto builder = MUST(DeprecatedStringBuilder::create());TRY(builder.append("ParsedVarDecl("sv));{
JaktInternal::PrettyPrint::ScopedLevelIncrease increase_indent {};
TRY(JaktInternal::PrettyPrint::output_indentation(builder));TRY(builder.append("name: "sv));TRY(builder.appendff("\"{}\", ", name));
TRY(JaktInternal::PrettyPrint::output_indentation(builder));TRY(builder.append("parsed_type: "sv));TRY(builder.appendff("{}, ", parsed_type));
TRY(JaktInternal::PrettyPrint::output_indentation(builder));TRY(builder.append("is_mutable: "sv));TRY(builder.appendff("{}, ", is_mutable));
TRY(JaktInternal::PrettyPrint::output_indentation(builder));TRY(builder.append("inlay_span: "sv));TRY(builder.appendff("{}, ", inlay_span));
TRY(JaktInternal::PrettyPrint::output_indentation(builder));TRY(builder.append("span: "sv));TRY(builder.appendff("{}", span));
}
TRY(builder.append(")"sv));return builder.to_string(); }
parser::ParsedVarDecl::ParsedVarDecl(DeprecatedString a_name, NonnullRefPtr<typename parser::ParsedType> a_parsed_type, bool a_is_mutable, JaktInternal::Optional<utility::Span> a_inlay_span, utility::Span a_span) :name(a_name), parsed_type(a_parsed_type), is_mutable(a_is_mutable), inlay_span(a_inlay_span), span(a_span){}

bool parser::ParsedVarDecl::equals(parser::ParsedVarDecl const rhs_var_decl) const {
{
return (((((*this).name) == ((rhs_var_decl).name)) && (((*this).is_mutable) == ((rhs_var_decl).is_mutable))));
}
}

ErrorOr<DeprecatedString> parser::ParsedMethod::debug_description() const { auto builder = MUST(DeprecatedStringBuilder::create());TRY(builder.append("ParsedMethod("sv));{
JaktInternal::PrettyPrint::ScopedLevelIncrease increase_indent {};
TRY(JaktInternal::PrettyPrint::output_indentation(builder));TRY(builder.append("parsed_function: "sv));TRY(builder.appendff("{}, ", parsed_function));
TRY(JaktInternal::PrettyPrint::output_indentation(builder));TRY(builder.append("visibility: "sv));TRY(builder.appendff("{}, ", visibility));
TRY(JaktInternal::PrettyPrint::output_indentation(builder));TRY(builder.append("is_virtual: "sv));TRY(builder.appendff("{}, ", is_virtual));
TRY(JaktInternal::PrettyPrint::output_indentation(builder));TRY(builder.append("is_override: "sv));TRY(builder.appendff("{}", is_override));
}
TRY(builder.append(")"sv));return builder.to_string(); }
parser::ParsedMethod::ParsedMethod(parser::ParsedFunction a_parsed_function, parser::Visibility a_visibility, bool a_is_virtual, bool a_is_override) :parsed_function(a_parsed_function), visibility(a_visibility), is_virtual(a_is_virtual), is_override(a_is_override){}

ErrorOr<DeprecatedString> parser::ParsedMatchCase::debug_description() const { auto builder = MUST(DeprecatedStringBuilder::create());TRY(builder.append("ParsedMatchCase("sv));{
JaktInternal::PrettyPrint::ScopedLevelIncrease increase_indent {};
TRY(JaktInternal::PrettyPrint::output_indentation(builder));TRY(builder.append("patterns: "sv));TRY(builder.appendff("{}, ", patterns));
TRY(JaktInternal::PrettyPrint::output_indentation(builder));TRY(builder.append("marker_span: "sv));TRY(builder.appendff("{}, ", marker_span));
TRY(JaktInternal::PrettyPrint::output_indentation(builder));TRY(builder.append("body: "sv));TRY(builder.appendff("{}", body));
}
TRY(builder.append(")"sv));return builder.to_string(); }
bool parser::ParsedMatchCase::has_equal_pattern(parser::ParsedMatchCase const rhs_match_case) const {
{
if ((((((*this).patterns)).size()) == ((((rhs_match_case).patterns)).size()))){
{
JaktInternal::Range<size_t> _magic = (JaktInternal::Range<size_t>{static_cast<size_t>(0LL),static_cast<size_t>(((((*this).patterns)).size()))});
for (;;){
JaktInternal::Optional<size_t> _magic_value = ((_magic).next());
if ((!(((_magic_value).has_value())))){
break;
}
size_t i = (_magic_value.value());
{
if ((!(((((((*this).patterns))[i])).is_equal_pattern(((((rhs_match_case).patterns))[i])))))){
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
}

bool parser::ParsedMatchCase::equals(parser::ParsedMatchCase const rhs_match_case) const {
{
if ((((((*this).patterns)).size()) == ((((rhs_match_case).patterns)).size()))){
{
JaktInternal::Range<size_t> _magic = (JaktInternal::Range<size_t>{static_cast<size_t>(0LL),static_cast<size_t>(((((*this).patterns)).size()))});
for (;;){
JaktInternal::Optional<size_t> _magic_value = ((_magic).next());
if ((!(((_magic_value).has_value())))){
break;
}
size_t i = (_magic_value.value());
{
if ((!(((((((*this).patterns))[i])).equals(((((rhs_match_case).patterns))[i])))))){
return (false);
}
}

}
}

return (((((*this).body)).equals(((rhs_match_case).body))));
}
else {
return (false);
}

}
}

parser::ParsedMatchCase::ParsedMatchCase(JaktInternal::DynamicArray<parser::ParsedMatchPattern> a_patterns, utility::Span a_marker_span, parser::ParsedMatchBody a_body) :patterns(a_patterns), marker_span(a_marker_span), body(a_body){}

ErrorOr<DeprecatedString> parser::ParsedParameter::debug_description() const { auto builder = MUST(DeprecatedStringBuilder::create());TRY(builder.append("ParsedParameter("sv));{
JaktInternal::PrettyPrint::ScopedLevelIncrease increase_indent {};
TRY(JaktInternal::PrettyPrint::output_indentation(builder));TRY(builder.append("requires_label: "sv));TRY(builder.appendff("{}, ", requires_label));
TRY(JaktInternal::PrettyPrint::output_indentation(builder));TRY(builder.append("variable: "sv));TRY(builder.appendff("{}, ", variable));
TRY(JaktInternal::PrettyPrint::output_indentation(builder));TRY(builder.append("default_argument: "sv));TRY(builder.appendff("{}, ", default_argument));
TRY(JaktInternal::PrettyPrint::output_indentation(builder));TRY(builder.append("span: "sv));TRY(builder.appendff("{}", span));
}
TRY(builder.append(")"sv));return builder.to_string(); }
bool parser::ParsedParameter::equals(parser::ParsedParameter const rhs_param) const {
{
if (((((*this).requires_label) == ((rhs_param).requires_label)) && ((((*this).variable)).equals(((rhs_param).variable))))){
if ((((((*this).default_argument)).has_value()) && ((((rhs_param).default_argument)).has_value()))){
return ((((((*this).default_argument).value()))->equals((((rhs_param).default_argument).value()))));
}
return (((!(((((*this).default_argument)).has_value()))) && (!(((((rhs_param).default_argument)).has_value())))));
}
else {
return (false);
}

}
}

parser::ParsedParameter::ParsedParameter(bool a_requires_label, parser::ParsedVariable a_variable, JaktInternal::Optional<NonnullRefPtr<typename parser::ParsedExpression>> a_default_argument, utility::Span a_span) :requires_label(a_requires_label), variable(a_variable), default_argument(a_default_argument), span(a_span){}

ErrorOr<DeprecatedString> parser::ValueEnumVariant::debug_description() const { auto builder = MUST(DeprecatedStringBuilder::create());TRY(builder.append("ValueEnumVariant("sv));{
JaktInternal::PrettyPrint::ScopedLevelIncrease increase_indent {};
TRY(JaktInternal::PrettyPrint::output_indentation(builder));TRY(builder.append("name: "sv));TRY(builder.appendff("\"{}\", ", name));
TRY(JaktInternal::PrettyPrint::output_indentation(builder));TRY(builder.append("span: "sv));TRY(builder.appendff("{}, ", span));
TRY(JaktInternal::PrettyPrint::output_indentation(builder));TRY(builder.append("value: "sv));TRY(builder.appendff("{}", value));
}
TRY(builder.append(")"sv));return builder.to_string(); }
parser::ValueEnumVariant::ValueEnumVariant(DeprecatedString a_name, utility::Span a_span, JaktInternal::Optional<NonnullRefPtr<typename parser::ParsedExpression>> a_value) :name(a_name), span(a_span), value(a_value){}

ErrorOr<DeprecatedString> parser::VisibilityRestriction::debug_description() const { auto builder = MUST(DeprecatedStringBuilder::create());TRY(builder.append("VisibilityRestriction("sv));{
JaktInternal::PrettyPrint::ScopedLevelIncrease increase_indent {};
TRY(JaktInternal::PrettyPrint::output_indentation(builder));TRY(builder.append("namespace_: "sv));TRY(builder.appendff("{}, ", namespace_));
TRY(JaktInternal::PrettyPrint::output_indentation(builder));TRY(builder.append("name: "sv));TRY(builder.appendff("\"{}\"", name));
}
TRY(builder.append(")"sv));return builder.to_string(); }
parser::VisibilityRestriction::VisibilityRestriction(JaktInternal::DynamicArray<DeprecatedString> a_namespace_, DeprecatedString a_name) :namespace_(a_namespace_), name(a_name){}

ErrorOr<DeprecatedString> parser::IncludeAction::debug_description() const {
auto builder = TRY(DeprecatedStringBuilder::create());
switch (this->index()) {case 0 /* Define */: {
[[maybe_unused]] auto const& that = this->template get<IncludeAction::Define>();
TRY(builder.append("IncludeAction::Define"sv));
TRY(builder.append("("sv));
{
JaktInternal::PrettyPrint::ScopedLevelIncrease increase_indent {};
TRY(JaktInternal::PrettyPrint::output_indentation(builder));
TRY(builder.appendff("name: \"{}\"", that.name));
TRY(builder.append(", "sv));
TRY(JaktInternal::PrettyPrint::output_indentation(builder));
TRY(builder.appendff("span: {}", that.span));
TRY(builder.append(", "sv));
TRY(JaktInternal::PrettyPrint::output_indentation(builder));
TRY(builder.appendff("value: \"{}\"", that.value));
}
TRY(builder.append(")"sv));
break;}
case 1 /* Undefine */: {
[[maybe_unused]] auto const& that = this->template get<IncludeAction::Undefine>();
TRY(builder.append("IncludeAction::Undefine"sv));
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
}
return builder.to_string();
}
ErrorOr<DeprecatedString> parser::ParsedExpression::debug_description() const {
auto builder = TRY(DeprecatedStringBuilder::create());
switch (this->index()) {case 0 /* Boolean */: {
[[maybe_unused]] auto const& that = this->template get<ParsedExpression::Boolean>();
TRY(builder.append("ParsedExpression::Boolean"sv));
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
[[maybe_unused]] auto const& that = this->template get<ParsedExpression::NumericConstant>();
TRY(builder.append("ParsedExpression::NumericConstant"sv));
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
case 2 /* QuotedString */: {
[[maybe_unused]] auto const& that = this->template get<ParsedExpression::QuotedString>();
TRY(builder.append("ParsedExpression::QuotedString"sv));
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
case 3 /* SingleQuotedString */: {
[[maybe_unused]] auto const& that = this->template get<ParsedExpression::SingleQuotedString>();
TRY(builder.append("ParsedExpression::SingleQuotedString"sv));
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
case 4 /* SingleQuotedByteString */: {
[[maybe_unused]] auto const& that = this->template get<ParsedExpression::SingleQuotedByteString>();
TRY(builder.append("ParsedExpression::SingleQuotedByteString"sv));
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
case 5 /* Call */: {
[[maybe_unused]] auto const& that = this->template get<ParsedExpression::Call>();
TRY(builder.append("ParsedExpression::Call"sv));
TRY(builder.append("("sv));
{
JaktInternal::PrettyPrint::ScopedLevelIncrease increase_indent {};
TRY(JaktInternal::PrettyPrint::output_indentation(builder));
TRY(builder.appendff("call: {}", that.call));
TRY(builder.append(", "sv));
TRY(JaktInternal::PrettyPrint::output_indentation(builder));
TRY(builder.appendff("span: {}", that.span));
}
TRY(builder.append(")"sv));
break;}
case 6 /* MethodCall */: {
[[maybe_unused]] auto const& that = this->template get<ParsedExpression::MethodCall>();
TRY(builder.append("ParsedExpression::MethodCall"sv));
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
TRY(builder.appendff("is_optional: {}", that.is_optional));
TRY(builder.append(", "sv));
TRY(JaktInternal::PrettyPrint::output_indentation(builder));
TRY(builder.appendff("span: {}", that.span));
}
TRY(builder.append(")"sv));
break;}
case 7 /* IndexedTuple */: {
[[maybe_unused]] auto const& that = this->template get<ParsedExpression::IndexedTuple>();
TRY(builder.append("ParsedExpression::IndexedTuple"sv));
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
TRY(builder.appendff("is_optional: {}", that.is_optional));
TRY(builder.append(", "sv));
TRY(JaktInternal::PrettyPrint::output_indentation(builder));
TRY(builder.appendff("span: {}", that.span));
}
TRY(builder.append(")"sv));
break;}
case 8 /* IndexedStruct */: {
[[maybe_unused]] auto const& that = this->template get<ParsedExpression::IndexedStruct>();
TRY(builder.append("ParsedExpression::IndexedStruct"sv));
TRY(builder.append("("sv));
{
JaktInternal::PrettyPrint::ScopedLevelIncrease increase_indent {};
TRY(JaktInternal::PrettyPrint::output_indentation(builder));
TRY(builder.appendff("expr: {}", that.expr));
TRY(builder.append(", "sv));
TRY(JaktInternal::PrettyPrint::output_indentation(builder));
TRY(builder.appendff("field_name: \"{}\"", that.field_name));
TRY(builder.append(", "sv));
TRY(JaktInternal::PrettyPrint::output_indentation(builder));
TRY(builder.appendff("is_optional: {}", that.is_optional));
TRY(builder.append(", "sv));
TRY(JaktInternal::PrettyPrint::output_indentation(builder));
TRY(builder.appendff("span: {}", that.span));
}
TRY(builder.append(")"sv));
break;}
case 9 /* Var */: {
[[maybe_unused]] auto const& that = this->template get<ParsedExpression::Var>();
TRY(builder.append("ParsedExpression::Var"sv));
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
case 10 /* IndexedExpression */: {
[[maybe_unused]] auto const& that = this->template get<ParsedExpression::IndexedExpression>();
TRY(builder.append("ParsedExpression::IndexedExpression"sv));
TRY(builder.append("("sv));
{
JaktInternal::PrettyPrint::ScopedLevelIncrease increase_indent {};
TRY(JaktInternal::PrettyPrint::output_indentation(builder));
TRY(builder.appendff("base: {}", that.base));
TRY(builder.append(", "sv));
TRY(JaktInternal::PrettyPrint::output_indentation(builder));
TRY(builder.appendff("index: {}", that.index));
TRY(builder.append(", "sv));
TRY(JaktInternal::PrettyPrint::output_indentation(builder));
TRY(builder.appendff("span: {}", that.span));
}
TRY(builder.append(")"sv));
break;}
case 11 /* UnaryOp */: {
[[maybe_unused]] auto const& that = this->template get<ParsedExpression::UnaryOp>();
TRY(builder.append("ParsedExpression::UnaryOp"sv));
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
}
TRY(builder.append(")"sv));
break;}
case 12 /* BinaryOp */: {
[[maybe_unused]] auto const& that = this->template get<ParsedExpression::BinaryOp>();
TRY(builder.append("ParsedExpression::BinaryOp"sv));
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
}
TRY(builder.append(")"sv));
break;}
case 13 /* Operator */: {
[[maybe_unused]] auto const& that = this->template get<ParsedExpression::Operator>();
TRY(builder.append("ParsedExpression::Operator"sv));
TRY(builder.append("("sv));
{
JaktInternal::PrettyPrint::ScopedLevelIncrease increase_indent {};
TRY(JaktInternal::PrettyPrint::output_indentation(builder));
TRY(builder.appendff("op: {}", that.op));
TRY(builder.append(", "sv));
TRY(JaktInternal::PrettyPrint::output_indentation(builder));
TRY(builder.appendff("span: {}", that.span));
}
TRY(builder.append(")"sv));
break;}
case 14 /* OptionalSome */: {
[[maybe_unused]] auto const& that = this->template get<ParsedExpression::OptionalSome>();
TRY(builder.append("ParsedExpression::OptionalSome"sv));
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
case 15 /* OptionalNone */: {
[[maybe_unused]] auto const& that = this->template get<ParsedExpression::OptionalNone>();
TRY(builder.append("ParsedExpression::OptionalNone"sv));
TRY(builder.appendff("({})", that.value));
break;}
case 16 /* JaktArray */: {
[[maybe_unused]] auto const& that = this->template get<ParsedExpression::JaktArray>();
TRY(builder.append("ParsedExpression::JaktArray"sv));
TRY(builder.append("("sv));
{
JaktInternal::PrettyPrint::ScopedLevelIncrease increase_indent {};
TRY(JaktInternal::PrettyPrint::output_indentation(builder));
TRY(builder.appendff("values: {}", that.values));
TRY(builder.append(", "sv));
TRY(JaktInternal::PrettyPrint::output_indentation(builder));
TRY(builder.appendff("fill_size: {}", that.fill_size));
TRY(builder.append(", "sv));
TRY(JaktInternal::PrettyPrint::output_indentation(builder));
TRY(builder.appendff("span: {}", that.span));
}
TRY(builder.append(")"sv));
break;}
case 17 /* JaktDictionary */: {
[[maybe_unused]] auto const& that = this->template get<ParsedExpression::JaktDictionary>();
TRY(builder.append("ParsedExpression::JaktDictionary"sv));
TRY(builder.append("("sv));
{
JaktInternal::PrettyPrint::ScopedLevelIncrease increase_indent {};
TRY(JaktInternal::PrettyPrint::output_indentation(builder));
TRY(builder.appendff("values: {}", that.values));
TRY(builder.append(", "sv));
TRY(JaktInternal::PrettyPrint::output_indentation(builder));
TRY(builder.appendff("span: {}", that.span));
}
TRY(builder.append(")"sv));
break;}
case 18 /* Set */: {
[[maybe_unused]] auto const& that = this->template get<ParsedExpression::Set>();
TRY(builder.append("ParsedExpression::Set"sv));
TRY(builder.append("("sv));
{
JaktInternal::PrettyPrint::ScopedLevelIncrease increase_indent {};
TRY(JaktInternal::PrettyPrint::output_indentation(builder));
TRY(builder.appendff("values: {}", that.values));
TRY(builder.append(", "sv));
TRY(JaktInternal::PrettyPrint::output_indentation(builder));
TRY(builder.appendff("span: {}", that.span));
}
TRY(builder.append(")"sv));
break;}
case 19 /* JaktTuple */: {
[[maybe_unused]] auto const& that = this->template get<ParsedExpression::JaktTuple>();
TRY(builder.append("ParsedExpression::JaktTuple"sv));
TRY(builder.append("("sv));
{
JaktInternal::PrettyPrint::ScopedLevelIncrease increase_indent {};
TRY(JaktInternal::PrettyPrint::output_indentation(builder));
TRY(builder.appendff("values: {}", that.values));
TRY(builder.append(", "sv));
TRY(JaktInternal::PrettyPrint::output_indentation(builder));
TRY(builder.appendff("span: {}", that.span));
}
TRY(builder.append(")"sv));
break;}
case 20 /* Range */: {
[[maybe_unused]] auto const& that = this->template get<ParsedExpression::Range>();
TRY(builder.append("ParsedExpression::Range"sv));
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
}
TRY(builder.append(")"sv));
break;}
case 21 /* ForcedUnwrap */: {
[[maybe_unused]] auto const& that = this->template get<ParsedExpression::ForcedUnwrap>();
TRY(builder.append("ParsedExpression::ForcedUnwrap"sv));
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
case 22 /* Match */: {
[[maybe_unused]] auto const& that = this->template get<ParsedExpression::Match>();
TRY(builder.append("ParsedExpression::Match"sv));
TRY(builder.append("("sv));
{
JaktInternal::PrettyPrint::ScopedLevelIncrease increase_indent {};
TRY(JaktInternal::PrettyPrint::output_indentation(builder));
TRY(builder.appendff("expr: {}", that.expr));
TRY(builder.append(", "sv));
TRY(JaktInternal::PrettyPrint::output_indentation(builder));
TRY(builder.appendff("cases: {}", that.cases));
TRY(builder.append(", "sv));
TRY(JaktInternal::PrettyPrint::output_indentation(builder));
TRY(builder.appendff("span: {}", that.span));
TRY(builder.append(", "sv));
TRY(JaktInternal::PrettyPrint::output_indentation(builder));
TRY(builder.appendff("marker_span: {}", that.marker_span));
}
TRY(builder.append(")"sv));
break;}
case 23 /* EnumVariantArg */: {
[[maybe_unused]] auto const& that = this->template get<ParsedExpression::EnumVariantArg>();
TRY(builder.append("ParsedExpression::EnumVariantArg"sv));
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
case 24 /* NamespacedVar */: {
[[maybe_unused]] auto const& that = this->template get<ParsedExpression::NamespacedVar>();
TRY(builder.append("ParsedExpression::NamespacedVar"sv));
TRY(builder.append("("sv));
{
JaktInternal::PrettyPrint::ScopedLevelIncrease increase_indent {};
TRY(JaktInternal::PrettyPrint::output_indentation(builder));
TRY(builder.appendff("name: \"{}\"", that.name));
TRY(builder.append(", "sv));
TRY(JaktInternal::PrettyPrint::output_indentation(builder));
TRY(builder.appendff("namespace_: {}", that.namespace_));
TRY(builder.append(", "sv));
TRY(JaktInternal::PrettyPrint::output_indentation(builder));
TRY(builder.appendff("span: {}", that.span));
}
TRY(builder.append(")"sv));
break;}
case 25 /* Function */: {
[[maybe_unused]] auto const& that = this->template get<ParsedExpression::Function>();
TRY(builder.append("ParsedExpression::Function"sv));
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
TRY(builder.appendff("is_fat_arrow: {}", that.is_fat_arrow));
TRY(builder.append(", "sv));
TRY(JaktInternal::PrettyPrint::output_indentation(builder));
TRY(builder.appendff("return_type: {}", that.return_type));
TRY(builder.append(", "sv));
TRY(JaktInternal::PrettyPrint::output_indentation(builder));
TRY(builder.appendff("block: {}", that.block));
TRY(builder.append(", "sv));
TRY(JaktInternal::PrettyPrint::output_indentation(builder));
TRY(builder.appendff("span: {}", that.span));
}
TRY(builder.append(")"sv));
break;}
case 26 /* Try */: {
[[maybe_unused]] auto const& that = this->template get<ParsedExpression::Try>();
TRY(builder.append("ParsedExpression::Try"sv));
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
}
TRY(builder.append(")"sv));
break;}
case 27 /* TryBlock */: {
[[maybe_unused]] auto const& that = this->template get<ParsedExpression::TryBlock>();
TRY(builder.append("ParsedExpression::TryBlock"sv));
TRY(builder.append("("sv));
{
JaktInternal::PrettyPrint::ScopedLevelIncrease increase_indent {};
TRY(JaktInternal::PrettyPrint::output_indentation(builder));
TRY(builder.appendff("stmt: {}", that.stmt));
TRY(builder.append(", "sv));
TRY(JaktInternal::PrettyPrint::output_indentation(builder));
TRY(builder.appendff("error_name: \"{}\"", that.error_name));
TRY(builder.append(", "sv));
TRY(JaktInternal::PrettyPrint::output_indentation(builder));
TRY(builder.appendff("error_span: {}", that.error_span));
TRY(builder.append(", "sv));
TRY(JaktInternal::PrettyPrint::output_indentation(builder));
TRY(builder.appendff("catch_block: {}", that.catch_block));
TRY(builder.append(", "sv));
TRY(JaktInternal::PrettyPrint::output_indentation(builder));
TRY(builder.appendff("span: {}", that.span));
}
TRY(builder.append(")"sv));
break;}
case 28 /* Garbage */: {
[[maybe_unused]] auto const& that = this->template get<ParsedExpression::Garbage>();
TRY(builder.append("ParsedExpression::Garbage"sv));
TRY(builder.appendff("({})", that.value));
break;}
}
return builder.to_string();
}
bool parser::ParsedExpression::equals(NonnullRefPtr<typename parser::ParsedExpression> const rhs_expression) const {
{
return (JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<bool, bool>{
auto&& __jakt_match_variant = *this;
switch(__jakt_match_variant.index()) {
case 0: {
auto&& __jakt_match_value = __jakt_match_variant.template get<parser::ParsedExpression::Boolean>();bool const& lhs_val = __jakt_match_value.val;
return JaktInternal::ExplicitValue(JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<bool, bool>{
auto&& __jakt_match_variant = *rhs_expression;
switch(__jakt_match_variant.index()) {
case 0: {
auto&& __jakt_match_value = __jakt_match_variant.template get<parser::ParsedExpression::Boolean>();bool const& rhs_val = __jakt_match_value.val;
return JaktInternal::ExplicitValue((lhs_val == rhs_val));
};/*case end*/
default: {
return JaktInternal::ExplicitValue(false);
};/*case end*/
}/*switch end*/
}()
)));
};/*case end*/
case 1: {
auto&& __jakt_match_value = __jakt_match_variant.template get<parser::ParsedExpression::NumericConstant>();parser::NumericConstant const& lhs_val = __jakt_match_value.val;
return JaktInternal::ExplicitValue(JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<bool, bool>{
auto&& __jakt_match_variant = *rhs_expression;
switch(__jakt_match_variant.index()) {
case 1: {
auto&& __jakt_match_value = __jakt_match_variant.template get<parser::ParsedExpression::NumericConstant>();parser::NumericConstant const& rhs_val = __jakt_match_value.val;
return JaktInternal::ExplicitValue((((lhs_val).to_usize()) == ((rhs_val).to_usize())));
};/*case end*/
default: {
return JaktInternal::ExplicitValue(false);
};/*case end*/
}/*switch end*/
}()
)));
};/*case end*/
case 2: {
auto&& __jakt_match_value = __jakt_match_variant.template get<parser::ParsedExpression::QuotedString>();DeprecatedString const& lhs_val = __jakt_match_value.val;
return JaktInternal::ExplicitValue(JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<bool, bool>{
auto&& __jakt_match_variant = *rhs_expression;
switch(__jakt_match_variant.index()) {
case 2: {
auto&& __jakt_match_value = __jakt_match_variant.template get<parser::ParsedExpression::QuotedString>();DeprecatedString const& rhs_val = __jakt_match_value.val;
return JaktInternal::ExplicitValue((lhs_val == rhs_val));
};/*case end*/
default: {
return JaktInternal::ExplicitValue(false);
};/*case end*/
}/*switch end*/
}()
)));
};/*case end*/
case 3: {
auto&& __jakt_match_value = __jakt_match_variant.template get<parser::ParsedExpression::SingleQuotedString>();DeprecatedString const& lhs_val = __jakt_match_value.val;
return JaktInternal::ExplicitValue(JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<bool, bool>{
auto&& __jakt_match_variant = *rhs_expression;
switch(__jakt_match_variant.index()) {
case 3: {
auto&& __jakt_match_value = __jakt_match_variant.template get<parser::ParsedExpression::SingleQuotedString>();DeprecatedString const& rhs_val = __jakt_match_value.val;
return JaktInternal::ExplicitValue((lhs_val == rhs_val));
};/*case end*/
default: {
return JaktInternal::ExplicitValue(false);
};/*case end*/
}/*switch end*/
}()
)));
};/*case end*/
case 4: {
auto&& __jakt_match_value = __jakt_match_variant.template get<parser::ParsedExpression::SingleQuotedByteString>();DeprecatedString const& lhs_val = __jakt_match_value.val;
return JaktInternal::ExplicitValue(JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<bool, bool>{
auto&& __jakt_match_variant = *rhs_expression;
switch(__jakt_match_variant.index()) {
case 4: {
auto&& __jakt_match_value = __jakt_match_variant.template get<parser::ParsedExpression::SingleQuotedByteString>();DeprecatedString const& rhs_val = __jakt_match_value.val;
return JaktInternal::ExplicitValue((lhs_val == rhs_val));
};/*case end*/
default: {
return JaktInternal::ExplicitValue(false);
};/*case end*/
}/*switch end*/
}()
)));
};/*case end*/
case 5: {
auto&& __jakt_match_value = __jakt_match_variant.template get<parser::ParsedExpression::Call>();parser::ParsedCall const& lhs_call = __jakt_match_value.call;
return JaktInternal::ExplicitValue(JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<bool, bool>{
auto&& __jakt_match_variant = *rhs_expression;
switch(__jakt_match_variant.index()) {
case 5: {
auto&& __jakt_match_value = __jakt_match_variant.template get<parser::ParsedExpression::Call>();parser::ParsedCall const& rhs_call = __jakt_match_value.call;
return JaktInternal::ExplicitValue(((lhs_call).equals(rhs_call)));
};/*case end*/
default: {
return JaktInternal::ExplicitValue(false);
};/*case end*/
}/*switch end*/
}()
)));
};/*case end*/
case 6: {
auto&& __jakt_match_value = __jakt_match_variant.template get<parser::ParsedExpression::MethodCall>();NonnullRefPtr<typename parser::ParsedExpression> const& lhs_expr = __jakt_match_value.expr;
parser::ParsedCall const& lhs_call = __jakt_match_value.call;
bool const& lhs_optional = __jakt_match_value.is_optional;
return JaktInternal::ExplicitValue(JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<bool, bool>{
auto&& __jakt_match_variant = *rhs_expression;
switch(__jakt_match_variant.index()) {
case 6: {
auto&& __jakt_match_value = __jakt_match_variant.template get<parser::ParsedExpression::MethodCall>();NonnullRefPtr<typename parser::ParsedExpression> const& rhs_expr = __jakt_match_value.expr;
parser::ParsedCall const& rhs_call = __jakt_match_value.call;
bool const& rhs_optional = __jakt_match_value.is_optional;
return JaktInternal::ExplicitValue((((lhs_optional == rhs_optional) && ((lhs_expr)->equals(rhs_expr))) && ((lhs_call).equals(rhs_call))));
};/*case end*/
default: {
return JaktInternal::ExplicitValue(false);
};/*case end*/
}/*switch end*/
}()
)));
};/*case end*/
case 7: {
auto&& __jakt_match_value = __jakt_match_variant.template get<parser::ParsedExpression::IndexedTuple>();NonnullRefPtr<typename parser::ParsedExpression> const& lhs_expr = __jakt_match_value.expr;
size_t const& lhs_index = __jakt_match_value.index;
bool const& lhs_optional = __jakt_match_value.is_optional;
return JaktInternal::ExplicitValue(JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<bool, bool>{
auto&& __jakt_match_variant = *rhs_expression;
switch(__jakt_match_variant.index()) {
case 7: {
auto&& __jakt_match_value = __jakt_match_variant.template get<parser::ParsedExpression::IndexedTuple>();NonnullRefPtr<typename parser::ParsedExpression> const& rhs_expr = __jakt_match_value.expr;
size_t const& rhs_index = __jakt_match_value.index;
bool const& rhs_optional = __jakt_match_value.is_optional;
return JaktInternal::ExplicitValue((((lhs_optional == rhs_optional) && ((lhs_expr)->equals(rhs_expr))) && (lhs_index == rhs_index)));
};/*case end*/
default: {
return JaktInternal::ExplicitValue(false);
};/*case end*/
}/*switch end*/
}()
)));
};/*case end*/
case 8: {
auto&& __jakt_match_value = __jakt_match_variant.template get<parser::ParsedExpression::IndexedStruct>();NonnullRefPtr<typename parser::ParsedExpression> const& lhs_expr = __jakt_match_value.expr;
DeprecatedString const& lhs_field = __jakt_match_value.field_name;
bool const& lhs_optional = __jakt_match_value.is_optional;
return JaktInternal::ExplicitValue(JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<bool, bool>{
auto&& __jakt_match_variant = *rhs_expression;
switch(__jakt_match_variant.index()) {
case 8: {
auto&& __jakt_match_value = __jakt_match_variant.template get<parser::ParsedExpression::IndexedStruct>();NonnullRefPtr<typename parser::ParsedExpression> const& rhs_expr = __jakt_match_value.expr;
DeprecatedString const& rhs_field = __jakt_match_value.field_name;
bool const& rhs_optional = __jakt_match_value.is_optional;
return JaktInternal::ExplicitValue((((lhs_optional == rhs_optional) && ((lhs_expr)->equals(rhs_expr))) && (lhs_field == rhs_field)));
};/*case end*/
default: {
return JaktInternal::ExplicitValue(false);
};/*case end*/
}/*switch end*/
}()
)));
};/*case end*/
case 9: {
auto&& __jakt_match_value = __jakt_match_variant.template get<parser::ParsedExpression::Var>();DeprecatedString const& lhs_name = __jakt_match_value.name;
return JaktInternal::ExplicitValue(JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<bool, bool>{
auto&& __jakt_match_variant = *rhs_expression;
switch(__jakt_match_variant.index()) {
case 9: {
auto&& __jakt_match_value = __jakt_match_variant.template get<parser::ParsedExpression::Var>();DeprecatedString const& rhs_name = __jakt_match_value.name;
return JaktInternal::ExplicitValue((lhs_name == rhs_name));
};/*case end*/
default: {
return JaktInternal::ExplicitValue(false);
};/*case end*/
}/*switch end*/
}()
)));
};/*case end*/
case 10: {
auto&& __jakt_match_value = __jakt_match_variant.template get<parser::ParsedExpression::IndexedExpression>();NonnullRefPtr<typename parser::ParsedExpression> const& lhs_base = __jakt_match_value.base;
NonnullRefPtr<typename parser::ParsedExpression> const& lhs_index = __jakt_match_value.index;
return JaktInternal::ExplicitValue(JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<bool, bool>{
auto&& __jakt_match_variant = *rhs_expression;
switch(__jakt_match_variant.index()) {
case 10: {
auto&& __jakt_match_value = __jakt_match_variant.template get<parser::ParsedExpression::IndexedExpression>();NonnullRefPtr<typename parser::ParsedExpression> const& rhs_base = __jakt_match_value.base;
NonnullRefPtr<typename parser::ParsedExpression> const& rhs_index = __jakt_match_value.index;
return JaktInternal::ExplicitValue((((lhs_base)->equals(rhs_base)) && ((lhs_index)->equals(rhs_index))));
};/*case end*/
default: {
return JaktInternal::ExplicitValue(false);
};/*case end*/
}/*switch end*/
}()
)));
};/*case end*/
case 11: {
auto&& __jakt_match_value = __jakt_match_variant.template get<parser::ParsedExpression::UnaryOp>();NonnullRefPtr<typename parser::ParsedExpression> const& lhs_expr = __jakt_match_value.expr;
parser::UnaryOperator const& lhs_op = __jakt_match_value.op;
return JaktInternal::ExplicitValue(JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<bool, bool>{
auto&& __jakt_match_variant = *rhs_expression;
switch(__jakt_match_variant.index()) {
case 11: {
auto&& __jakt_match_value = __jakt_match_variant.template get<parser::ParsedExpression::UnaryOp>();NonnullRefPtr<typename parser::ParsedExpression> const& rhs_expr = __jakt_match_value.expr;
parser::UnaryOperator const& rhs_op = __jakt_match_value.op;
return JaktInternal::ExplicitValue((((lhs_expr)->equals(rhs_expr)) && ((lhs_op).equals(rhs_op))));
};/*case end*/
default: {
return JaktInternal::ExplicitValue(false);
};/*case end*/
}/*switch end*/
}()
)));
};/*case end*/
case 12: {
auto&& __jakt_match_value = __jakt_match_variant.template get<parser::ParsedExpression::BinaryOp>();NonnullRefPtr<typename parser::ParsedExpression> const& lhs_lhs = __jakt_match_value.lhs;
parser::BinaryOperator const& lhs_op = __jakt_match_value.op;
NonnullRefPtr<typename parser::ParsedExpression> const& lhs_rhs = __jakt_match_value.rhs;
return JaktInternal::ExplicitValue(JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<bool, bool>{
auto&& __jakt_match_variant = *rhs_expression;
switch(__jakt_match_variant.index()) {
case 12: {
auto&& __jakt_match_value = __jakt_match_variant.template get<parser::ParsedExpression::BinaryOp>();NonnullRefPtr<typename parser::ParsedExpression> const& rhs_lhs = __jakt_match_value.lhs;
parser::BinaryOperator const& rhs_op = __jakt_match_value.op;
NonnullRefPtr<typename parser::ParsedExpression> const& rhs_rhs = __jakt_match_value.rhs;
return JaktInternal::ExplicitValue(((((lhs_lhs)->equals(rhs_lhs)) && ((lhs_op).equals(rhs_op))) && ((lhs_rhs)->equals(rhs_rhs))));
};/*case end*/
default: {
return JaktInternal::ExplicitValue(false);
};/*case end*/
}/*switch end*/
}()
)));
};/*case end*/
case 13: {
auto&& __jakt_match_value = __jakt_match_variant.template get<parser::ParsedExpression::Operator>();parser::BinaryOperator const& lhs_op = __jakt_match_value.op;
return JaktInternal::ExplicitValue(JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<bool, bool>{
auto&& __jakt_match_variant = *rhs_expression;
switch(__jakt_match_variant.index()) {
case 13: {
auto&& __jakt_match_value = __jakt_match_variant.template get<parser::ParsedExpression::Operator>();parser::BinaryOperator const& rhs_op = __jakt_match_value.op;
return JaktInternal::ExplicitValue(((lhs_op).equals(rhs_op)));
};/*case end*/
default: {
return JaktInternal::ExplicitValue(false);
};/*case end*/
}/*switch end*/
}()
)));
};/*case end*/
case 14: {
auto&& __jakt_match_value = __jakt_match_variant.template get<parser::ParsedExpression::OptionalSome>();NonnullRefPtr<typename parser::ParsedExpression> const& lhs_expr = __jakt_match_value.expr;
return JaktInternal::ExplicitValue(JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<bool, bool>{
auto&& __jakt_match_variant = *rhs_expression;
switch(__jakt_match_variant.index()) {
case 14: {
auto&& __jakt_match_value = __jakt_match_variant.template get<parser::ParsedExpression::OptionalSome>();NonnullRefPtr<typename parser::ParsedExpression> const& rhs_expr = __jakt_match_value.expr;
return JaktInternal::ExplicitValue(((lhs_expr)->equals(rhs_expr)));
};/*case end*/
default: {
return JaktInternal::ExplicitValue(false);
};/*case end*/
}/*switch end*/
}()
)));
};/*case end*/
case 15: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename parser::ParsedExpression::OptionalNone>();
return JaktInternal::ExplicitValue(((rhs_expression)->index() == 15 /* OptionalNone */));
};/*case end*/
case 16: {
auto&& __jakt_match_value = __jakt_match_variant.template get<parser::ParsedExpression::JaktArray>();JaktInternal::DynamicArray<NonnullRefPtr<typename parser::ParsedExpression>> const& lhs_values = __jakt_match_value.values;
JaktInternal::Optional<NonnullRefPtr<typename parser::ParsedExpression>> const& lhs_fill_size = __jakt_match_value.fill_size;
return JaktInternal::ExplicitValue(JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<bool, bool>{
auto&& __jakt_match_variant = *rhs_expression;
switch(__jakt_match_variant.index()) {
case 16: {
auto&& __jakt_match_value = __jakt_match_variant.template get<parser::ParsedExpression::JaktArray>();JaktInternal::DynamicArray<NonnullRefPtr<typename parser::ParsedExpression>> const& rhs_values = __jakt_match_value.values;
JaktInternal::Optional<NonnullRefPtr<typename parser::ParsedExpression>> const& rhs_fill_size = __jakt_match_value.fill_size;
return JaktInternal::ExplicitValue(({ Optional<bool> __jakt_var_103; {
if ((!(((lhs_fill_size).has_value())))){
if (((rhs_fill_size).has_value())){
return (false);
}
}
else {
if ((!(((rhs_fill_size).has_value())))){
return (false);
}
if ((!((((lhs_fill_size.value()))->equals((rhs_fill_size.value())))))){
return (false);
}
}

__jakt_var_103 = JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<bool,bool>{
auto __jakt_enum_value = ((((lhs_values).size()) == ((rhs_values).size())));
if (__jakt_enum_value == true) {
return JaktInternal::ExplicitValue(({ Optional<bool> __jakt_var_104; {
{
JaktInternal::Range<size_t> _magic = (JaktInternal::Range<size_t>{static_cast<size_t>(static_cast<size_t>(0ULL)),static_cast<size_t>(((lhs_values).size()))});
for (;;){
JaktInternal::Optional<size_t> _magic_value = ((_magic).next());
if ((!(((_magic_value).has_value())))){
break;
}
size_t i = (_magic_value.value());
{
if ((!(((((lhs_values)[i]))->equals(((rhs_values)[i])))))){
return (false);
}
}

}
}

__jakt_var_104 = true; goto __jakt_label_101;

}
__jakt_label_101:; __jakt_var_104.release_value(); }));
}
else {
{
return (false);
}
}
}()))
; goto __jakt_label_100;

}
__jakt_label_100:; __jakt_var_103.release_value(); }));
};/*case end*/
default: {
return JaktInternal::ExplicitValue(false);
};/*case end*/
}/*switch end*/
}()
)));
};/*case end*/
case 17: {
auto&& __jakt_match_value = __jakt_match_variant.template get<parser::ParsedExpression::JaktDictionary>();JaktInternal::DynamicArray<JaktInternal::Tuple<NonnullRefPtr<typename parser::ParsedExpression>,NonnullRefPtr<typename parser::ParsedExpression>>> const& lhs_values = __jakt_match_value.values;
return JaktInternal::ExplicitValue(JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<bool, bool>{
auto&& __jakt_match_variant = *rhs_expression;
switch(__jakt_match_variant.index()) {
case 17: {
auto&& __jakt_match_value = __jakt_match_variant.template get<parser::ParsedExpression::JaktDictionary>();JaktInternal::DynamicArray<JaktInternal::Tuple<NonnullRefPtr<typename parser::ParsedExpression>,NonnullRefPtr<typename parser::ParsedExpression>>> const& rhs_values = __jakt_match_value.values;
return JaktInternal::ExplicitValue(({ Optional<bool> __jakt_var_105; {
__jakt_var_105 = JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<bool,bool>{
auto __jakt_enum_value = ((((lhs_values).size()) == ((rhs_values).size())));
if (__jakt_enum_value == true) {
return JaktInternal::ExplicitValue(({ Optional<bool> __jakt_var_106; {
{
JaktInternal::Range<size_t> _magic = (JaktInternal::Range<size_t>{static_cast<size_t>(static_cast<size_t>(0ULL)),static_cast<size_t>(((lhs_values).size()))});
for (;;){
JaktInternal::Optional<size_t> _magic_value = ((_magic).next());
if ((!(((_magic_value).has_value())))){
break;
}
size_t i = (_magic_value.value());
{
if ((!((((((((lhs_values)[i])).template get<0>()))->equals(((((rhs_values)[i])).template get<0>()))) && ((((((lhs_values)[i])).template get<1>()))->equals(((((rhs_values)[i])).template get<1>()))))))){
return (false);
}
}

}
}

__jakt_var_106 = true; goto __jakt_label_103;

}
__jakt_label_103:; __jakt_var_106.release_value(); }));
}
else {
{
return (false);
}
}
}()))
; goto __jakt_label_102;

}
__jakt_label_102:; __jakt_var_105.release_value(); }));
};/*case end*/
default: {
return JaktInternal::ExplicitValue(false);
};/*case end*/
}/*switch end*/
}()
)));
};/*case end*/
case 18: {
auto&& __jakt_match_value = __jakt_match_variant.template get<parser::ParsedExpression::Set>();JaktInternal::DynamicArray<NonnullRefPtr<typename parser::ParsedExpression>> const& lhs_values = __jakt_match_value.values;
return JaktInternal::ExplicitValue(JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<bool, bool>{
auto&& __jakt_match_variant = *rhs_expression;
switch(__jakt_match_variant.index()) {
case 18: {
auto&& __jakt_match_value = __jakt_match_variant.template get<parser::ParsedExpression::Set>();JaktInternal::DynamicArray<NonnullRefPtr<typename parser::ParsedExpression>> const& rhs_values = __jakt_match_value.values;
return JaktInternal::ExplicitValue(({ Optional<bool> __jakt_var_107; {
__jakt_var_107 = JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<bool,bool>{
auto __jakt_enum_value = ((((lhs_values).size()) == ((rhs_values).size())));
if (__jakt_enum_value == true) {
return JaktInternal::ExplicitValue(({ Optional<bool> __jakt_var_108; {
{
JaktInternal::Range<size_t> _magic = (JaktInternal::Range<size_t>{static_cast<size_t>(static_cast<size_t>(0ULL)),static_cast<size_t>(((lhs_values).size()))});
for (;;){
JaktInternal::Optional<size_t> _magic_value = ((_magic).next());
if ((!(((_magic_value).has_value())))){
break;
}
size_t i = (_magic_value.value());
{
if ((!(((((lhs_values)[i]))->equals(((rhs_values)[i])))))){
return (false);
}
}

}
}

__jakt_var_108 = true; goto __jakt_label_105;

}
__jakt_label_105:; __jakt_var_108.release_value(); }));
}
else {
{
return (false);
}
}
}()))
; goto __jakt_label_104;

}
__jakt_label_104:; __jakt_var_107.release_value(); }));
};/*case end*/
default: {
return JaktInternal::ExplicitValue(false);
};/*case end*/
}/*switch end*/
}()
)));
};/*case end*/
case 19: {
auto&& __jakt_match_value = __jakt_match_variant.template get<parser::ParsedExpression::JaktTuple>();JaktInternal::DynamicArray<NonnullRefPtr<typename parser::ParsedExpression>> const& lhs_values = __jakt_match_value.values;
return JaktInternal::ExplicitValue(JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<bool, bool>{
auto&& __jakt_match_variant = *rhs_expression;
switch(__jakt_match_variant.index()) {
case 19: {
auto&& __jakt_match_value = __jakt_match_variant.template get<parser::ParsedExpression::JaktTuple>();JaktInternal::DynamicArray<NonnullRefPtr<typename parser::ParsedExpression>> const& rhs_values = __jakt_match_value.values;
return JaktInternal::ExplicitValue(({ Optional<bool> __jakt_var_109; {
__jakt_var_109 = JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<bool,bool>{
auto __jakt_enum_value = ((((lhs_values).size()) == ((rhs_values).size())));
if (__jakt_enum_value == true) {
return JaktInternal::ExplicitValue(({ Optional<bool> __jakt_var_110; {
{
JaktInternal::Range<size_t> _magic = (JaktInternal::Range<size_t>{static_cast<size_t>(static_cast<size_t>(0ULL)),static_cast<size_t>(((lhs_values).size()))});
for (;;){
JaktInternal::Optional<size_t> _magic_value = ((_magic).next());
if ((!(((_magic_value).has_value())))){
break;
}
size_t i = (_magic_value.value());
{
if ((!(((((lhs_values)[i]))->equals(((rhs_values)[i])))))){
return (false);
}
}

}
}

__jakt_var_110 = true; goto __jakt_label_107;

}
__jakt_label_107:; __jakt_var_110.release_value(); }));
}
else {
{
return (false);
}
}
}()))
; goto __jakt_label_106;

}
__jakt_label_106:; __jakt_var_109.release_value(); }));
};/*case end*/
default: {
return JaktInternal::ExplicitValue(false);
};/*case end*/
}/*switch end*/
}()
)));
};/*case end*/
case 20: {
auto&& __jakt_match_value = __jakt_match_variant.template get<parser::ParsedExpression::Range>();JaktInternal::Optional<NonnullRefPtr<typename parser::ParsedExpression>> const& lhs_from = __jakt_match_value.from;
JaktInternal::Optional<NonnullRefPtr<typename parser::ParsedExpression>> const& lhs_to = __jakt_match_value.to;
return JaktInternal::ExplicitValue(JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<bool, bool>{
auto&& __jakt_match_variant = *rhs_expression;
switch(__jakt_match_variant.index()) {
case 20: {
auto&& __jakt_match_value = __jakt_match_variant.template get<parser::ParsedExpression::Range>();JaktInternal::Optional<NonnullRefPtr<typename parser::ParsedExpression>> const& rhs_from = __jakt_match_value.from;
JaktInternal::Optional<NonnullRefPtr<typename parser::ParsedExpression>> const& rhs_to = __jakt_match_value.to;
return JaktInternal::ExplicitValue(({ Optional<bool> __jakt_var_111; {
bool equal = false;
if (((((lhs_from).has_value()) == ((rhs_from).has_value())) && (((lhs_to).has_value()) == ((rhs_to).has_value())))){
if ((((lhs_from).has_value()) && ((lhs_to).has_value()))){
(equal = ((((lhs_from.value()))->equals((rhs_from.value()))) && (((lhs_to.value()))->equals((rhs_to.value())))));
}
else {
(equal = true);
}

}
__jakt_var_111 = equal; goto __jakt_label_108;

}
__jakt_label_108:; __jakt_var_111.release_value(); }));
};/*case end*/
default: {
return JaktInternal::ExplicitValue(false);
};/*case end*/
}/*switch end*/
}()
)));
};/*case end*/
case 21: {
auto&& __jakt_match_value = __jakt_match_variant.template get<parser::ParsedExpression::ForcedUnwrap>();NonnullRefPtr<typename parser::ParsedExpression> const& lhs_expr = __jakt_match_value.expr;
return JaktInternal::ExplicitValue(JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<bool, bool>{
auto&& __jakt_match_variant = *rhs_expression;
switch(__jakt_match_variant.index()) {
case 21: {
auto&& __jakt_match_value = __jakt_match_variant.template get<parser::ParsedExpression::ForcedUnwrap>();NonnullRefPtr<typename parser::ParsedExpression> const& rhs_expr = __jakt_match_value.expr;
return JaktInternal::ExplicitValue(((lhs_expr)->equals(rhs_expr)));
};/*case end*/
default: {
return JaktInternal::ExplicitValue(false);
};/*case end*/
}/*switch end*/
}()
)));
};/*case end*/
case 22: {
auto&& __jakt_match_value = __jakt_match_variant.template get<parser::ParsedExpression::Match>();NonnullRefPtr<typename parser::ParsedExpression> const& lhs_expr = __jakt_match_value.expr;
JaktInternal::DynamicArray<parser::ParsedMatchCase> const& lhs_cases = __jakt_match_value.cases;
return JaktInternal::ExplicitValue(JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<bool, bool>{
auto&& __jakt_match_variant = *rhs_expression;
switch(__jakt_match_variant.index()) {
case 22: {
auto&& __jakt_match_value = __jakt_match_variant.template get<parser::ParsedExpression::Match>();NonnullRefPtr<typename parser::ParsedExpression> const& rhs_expr = __jakt_match_value.expr;
JaktInternal::DynamicArray<parser::ParsedMatchCase> const& rhs_cases = __jakt_match_value.cases;
{
if ((((lhs_expr)->equals(rhs_expr)) && (((lhs_cases).size()) == ((rhs_cases).size())))){
{
JaktInternal::Range<size_t> _magic = (JaktInternal::Range<size_t>{static_cast<size_t>(0LL),static_cast<size_t>(((lhs_cases).size()))});
for (;;){
JaktInternal::Optional<size_t> _magic_value = ((_magic).next());
if ((!(((_magic_value).has_value())))){
break;
}
size_t i = (_magic_value.value());
{
bool current_case_has_match = false;
{
JaktInternal::Range<size_t> _magic = (JaktInternal::Range<size_t>{static_cast<size_t>(0LL),static_cast<size_t>(((rhs_cases).size()))});
for (;;){
JaktInternal::Optional<size_t> _magic_value = ((_magic).next());
if ((!(((_magic_value).has_value())))){
break;
}
size_t k = (_magic_value.value());
{
if (((((lhs_cases)[i])).equals(((rhs_cases)[k])))){
(current_case_has_match = true);
break;
}
}

}
}

if (current_case_has_match){
}
else {
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
};/*case end*/
default: {
return JaktInternal::ExplicitValue(false);
};/*case end*/
}/*switch end*/
}()
)));
};/*case end*/
case 23: {
auto&& __jakt_match_value = __jakt_match_variant.template get<parser::ParsedExpression::EnumVariantArg>();NonnullRefPtr<typename parser::ParsedExpression> const& lhs_expr = __jakt_match_value.expr;
return JaktInternal::ExplicitValue(JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<bool, bool>{
auto&& __jakt_match_variant = *rhs_expression;
switch(__jakt_match_variant.index()) {
case 23: {
auto&& __jakt_match_value = __jakt_match_variant.template get<parser::ParsedExpression::EnumVariantArg>();NonnullRefPtr<typename parser::ParsedExpression> const& rhs_expr = __jakt_match_value.expr;
return JaktInternal::ExplicitValue(((lhs_expr)->equals(rhs_expr)));
};/*case end*/
default: {
return JaktInternal::ExplicitValue(false);
};/*case end*/
}/*switch end*/
}()
)));
};/*case end*/
case 24: {
auto&& __jakt_match_value = __jakt_match_variant.template get<parser::ParsedExpression::NamespacedVar>();DeprecatedString const& lhs_name = __jakt_match_value.name;
JaktInternal::DynamicArray<DeprecatedString> const& lhs_namespace = __jakt_match_value.namespace_;
return JaktInternal::ExplicitValue(JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<bool, bool>{
auto&& __jakt_match_variant = *rhs_expression;
switch(__jakt_match_variant.index()) {
case 24: {
auto&& __jakt_match_value = __jakt_match_variant.template get<parser::ParsedExpression::NamespacedVar>();DeprecatedString const& rhs_name = __jakt_match_value.name;
JaktInternal::DynamicArray<DeprecatedString> const& rhs_namespace = __jakt_match_value.namespace_;
return JaktInternal::ExplicitValue(({ Optional<bool> __jakt_var_112; {
if ((((lhs_namespace).size()) != ((rhs_namespace).size()))){
return (false);
}
{
JaktInternal::Range<size_t> _magic = (JaktInternal::Range<size_t>{static_cast<size_t>(static_cast<size_t>(0ULL)),static_cast<size_t>(((lhs_namespace).size()))});
for (;;){
JaktInternal::Optional<size_t> _magic_value = ((_magic).next());
if ((!(((_magic_value).has_value())))){
break;
}
size_t i = (_magic_value.value());
{
if ((((lhs_namespace)[i]) != ((rhs_namespace)[i]))){
return (false);
}
}

}
}

__jakt_var_112 = (lhs_name == rhs_name); goto __jakt_label_109;

}
__jakt_label_109:; __jakt_var_112.release_value(); }));
};/*case end*/
default: {
return JaktInternal::ExplicitValue(false);
};/*case end*/
}/*switch end*/
}()
)));
};/*case end*/
case 26: {
auto&& __jakt_match_value = __jakt_match_variant.template get<parser::ParsedExpression::Try>();NonnullRefPtr<typename parser::ParsedExpression> const& lhs_expr = __jakt_match_value.expr;
JaktInternal::Optional<parser::ParsedBlock> const& lhs_catch_block = __jakt_match_value.catch_block;
return JaktInternal::ExplicitValue(JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<bool, bool>{
auto&& __jakt_match_variant = *rhs_expression;
switch(__jakt_match_variant.index()) {
case 26: {
auto&& __jakt_match_value = __jakt_match_variant.template get<parser::ParsedExpression::Try>();NonnullRefPtr<typename parser::ParsedExpression> const& rhs_expr = __jakt_match_value.expr;
JaktInternal::Optional<parser::ParsedBlock> const& rhs_catch_block = __jakt_match_value.catch_block;
return JaktInternal::ExplicitValue(({ Optional<bool> __jakt_var_113; {
bool equals = ((lhs_expr)->equals(rhs_expr));
if (equals){
if (((lhs_catch_block).has_value())){
if (((rhs_catch_block).has_value())){
(equals = (((lhs_catch_block.value())).equals((rhs_catch_block.value()))));
}
else {
(equals = false);
}

}
else {
(equals = (!(((rhs_catch_block).has_value()))));
}

}
__jakt_var_113 = equals; goto __jakt_label_110;

}
__jakt_label_110:; __jakt_var_113.release_value(); }));
};/*case end*/
default: {
return JaktInternal::ExplicitValue(false);
};/*case end*/
}/*switch end*/
}()
)));
};/*case end*/
case 27: {
auto&& __jakt_match_value = __jakt_match_variant.template get<parser::ParsedExpression::TryBlock>();NonnullRefPtr<typename parser::ParsedStatement> const& lhs_stmt = __jakt_match_value.stmt;
DeprecatedString const& lhs_error_name = __jakt_match_value.error_name;
parser::ParsedBlock const& lhs_catch_block = __jakt_match_value.catch_block;
return JaktInternal::ExplicitValue(JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<bool, bool>{
auto&& __jakt_match_variant = *rhs_expression;
switch(__jakt_match_variant.index()) {
case 27: {
auto&& __jakt_match_value = __jakt_match_variant.template get<parser::ParsedExpression::TryBlock>();NonnullRefPtr<typename parser::ParsedStatement> const& rhs_stmt = __jakt_match_value.stmt;
DeprecatedString const& rhs_error_name = __jakt_match_value.error_name;
parser::ParsedBlock const& rhs_catch_block = __jakt_match_value.catch_block;
return JaktInternal::ExplicitValue(((((lhs_stmt)->equals(rhs_stmt)) && (lhs_error_name == rhs_error_name)) && ((lhs_catch_block).equals(rhs_catch_block))));
};/*case end*/
default: {
return JaktInternal::ExplicitValue(false);
};/*case end*/
}/*switch end*/
}()
)));
};/*case end*/
case 25: {
auto&& __jakt_match_value = __jakt_match_variant.template get<parser::ParsedExpression::Function>();JaktInternal::DynamicArray<parser::ParsedCapture> const& lhs_captures = __jakt_match_value.captures;
JaktInternal::DynamicArray<parser::ParsedParameter> const& lhs_params = __jakt_match_value.params;
bool const& lhs_can_throw = __jakt_match_value.can_throw;
NonnullRefPtr<typename parser::ParsedType> const& lhs_return_type = __jakt_match_value.return_type;
return JaktInternal::ExplicitValue(JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<bool, bool>{
auto&& __jakt_match_variant = *rhs_expression;
switch(__jakt_match_variant.index()) {
case 25: {
auto&& __jakt_match_value = __jakt_match_variant.template get<parser::ParsedExpression::Function>();JaktInternal::DynamicArray<parser::ParsedCapture> const& rhs_captures = __jakt_match_value.captures;
JaktInternal::DynamicArray<parser::ParsedParameter> const& rhs_params = __jakt_match_value.params;
bool const& rhs_can_throw = __jakt_match_value.can_throw;
NonnullRefPtr<typename parser::ParsedType> const& rhs_return_type = __jakt_match_value.return_type;
{
if ((((lhs_return_type)->equals(rhs_return_type)) && ((lhs_can_throw == rhs_can_throw) && ((((lhs_captures).size()) == ((rhs_captures).size())) && (((lhs_params).size()) == ((rhs_params).size())))))){
{
JaktInternal::Range<size_t> _magic = (JaktInternal::Range<size_t>{static_cast<size_t>(0LL),static_cast<size_t>(((lhs_captures).size()))});
for (;;){
JaktInternal::Optional<size_t> _magic_value = ((_magic).next());
if ((!(((_magic_value).has_value())))){
break;
}
size_t i = (_magic_value.value());
{
if ((!((((((lhs_captures)[i])).name()) == ((((rhs_captures)[i])).name()))))){
return (false);
}
}

}
}

{
JaktInternal::Range<size_t> _magic = (JaktInternal::Range<size_t>{static_cast<size_t>(0LL),static_cast<size_t>(((lhs_params).size()))});
for (;;){
JaktInternal::Optional<size_t> _magic_value = ((_magic).next());
if ((!(((_magic_value).has_value())))){
break;
}
size_t i = (_magic_value.value());
{
if ((!(((((lhs_params)[i])).equals(((rhs_params)[i])))))){
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
};/*case end*/
default: {
return JaktInternal::ExplicitValue(false);
};/*case end*/
}/*switch end*/
}()
)));
};/*case end*/
case 28: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename parser::ParsedExpression::Garbage>();
return JaktInternal::ExplicitValue(((rhs_expression)->index() == 28 /* Garbage */));
};/*case end*/
default: VERIFY_NOT_REACHED();}/*switch end*/
}()
)));
}
}

utility::Span parser::ParsedExpression::span() const {
{
return (JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<utility::Span, utility::Span>{
auto&& __jakt_match_variant = *this;
switch(__jakt_match_variant.index()) {
case 0: {
auto&& __jakt_match_value = __jakt_match_variant.template get<parser::ParsedExpression::Boolean>();utility::Span const& span = __jakt_match_value.span;
return JaktInternal::ExplicitValue(span);
};/*case end*/
case 1: {
auto&& __jakt_match_value = __jakt_match_variant.template get<parser::ParsedExpression::NumericConstant>();utility::Span const& span = __jakt_match_value.span;
return JaktInternal::ExplicitValue(span);
};/*case end*/
case 2: {
auto&& __jakt_match_value = __jakt_match_variant.template get<parser::ParsedExpression::QuotedString>();utility::Span const& span = __jakt_match_value.span;
return JaktInternal::ExplicitValue(span);
};/*case end*/
case 3: {
auto&& __jakt_match_value = __jakt_match_variant.template get<parser::ParsedExpression::SingleQuotedString>();utility::Span const& span = __jakt_match_value.span;
return JaktInternal::ExplicitValue(span);
};/*case end*/
case 4: {
auto&& __jakt_match_value = __jakt_match_variant.template get<parser::ParsedExpression::SingleQuotedByteString>();utility::Span const& span = __jakt_match_value.span;
return JaktInternal::ExplicitValue(span);
};/*case end*/
case 5: {
auto&& __jakt_match_value = __jakt_match_variant.template get<parser::ParsedExpression::Call>();utility::Span const& span = __jakt_match_value.span;
return JaktInternal::ExplicitValue(span);
};/*case end*/
case 6: {
auto&& __jakt_match_value = __jakt_match_variant.template get<parser::ParsedExpression::MethodCall>();utility::Span const& span = __jakt_match_value.span;
return JaktInternal::ExplicitValue(span);
};/*case end*/
case 7: {
auto&& __jakt_match_value = __jakt_match_variant.template get<parser::ParsedExpression::IndexedTuple>();utility::Span const& span = __jakt_match_value.span;
return JaktInternal::ExplicitValue(span);
};/*case end*/
case 8: {
auto&& __jakt_match_value = __jakt_match_variant.template get<parser::ParsedExpression::IndexedStruct>();utility::Span const& span = __jakt_match_value.span;
return JaktInternal::ExplicitValue(span);
};/*case end*/
case 9: {
auto&& __jakt_match_value = __jakt_match_variant.template get<parser::ParsedExpression::Var>();utility::Span const& span = __jakt_match_value.span;
return JaktInternal::ExplicitValue(span);
};/*case end*/
case 10: {
auto&& __jakt_match_value = __jakt_match_variant.template get<parser::ParsedExpression::IndexedExpression>();utility::Span const& span = __jakt_match_value.span;
return JaktInternal::ExplicitValue(span);
};/*case end*/
case 11: {
auto&& __jakt_match_value = __jakt_match_variant.template get<parser::ParsedExpression::UnaryOp>();utility::Span const& span = __jakt_match_value.span;
return JaktInternal::ExplicitValue(span);
};/*case end*/
case 12: {
auto&& __jakt_match_value = __jakt_match_variant.template get<parser::ParsedExpression::BinaryOp>();utility::Span const& span = __jakt_match_value.span;
return JaktInternal::ExplicitValue(span);
};/*case end*/
case 13: {
auto&& __jakt_match_value = __jakt_match_variant.template get<parser::ParsedExpression::Operator>();utility::Span const& span = __jakt_match_value.span;
return JaktInternal::ExplicitValue(span);
};/*case end*/
case 14: {
auto&& __jakt_match_value = __jakt_match_variant.template get<parser::ParsedExpression::OptionalSome>();utility::Span const& span = __jakt_match_value.span;
return JaktInternal::ExplicitValue(span);
};/*case end*/
case 15: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename parser::ParsedExpression::OptionalNone>();
utility::Span const& span = __jakt_match_value.value;
return JaktInternal::ExplicitValue(span);
};/*case end*/
case 16: {
auto&& __jakt_match_value = __jakt_match_variant.template get<parser::ParsedExpression::JaktArray>();utility::Span const& span = __jakt_match_value.span;
return JaktInternal::ExplicitValue(span);
};/*case end*/
case 17: {
auto&& __jakt_match_value = __jakt_match_variant.template get<parser::ParsedExpression::JaktDictionary>();utility::Span const& span = __jakt_match_value.span;
return JaktInternal::ExplicitValue(span);
};/*case end*/
case 18: {
auto&& __jakt_match_value = __jakt_match_variant.template get<parser::ParsedExpression::Set>();utility::Span const& span = __jakt_match_value.span;
return JaktInternal::ExplicitValue(span);
};/*case end*/
case 19: {
auto&& __jakt_match_value = __jakt_match_variant.template get<parser::ParsedExpression::JaktTuple>();utility::Span const& span = __jakt_match_value.span;
return JaktInternal::ExplicitValue(span);
};/*case end*/
case 20: {
auto&& __jakt_match_value = __jakt_match_variant.template get<parser::ParsedExpression::Range>();utility::Span const& span = __jakt_match_value.span;
return JaktInternal::ExplicitValue(span);
};/*case end*/
case 21: {
auto&& __jakt_match_value = __jakt_match_variant.template get<parser::ParsedExpression::ForcedUnwrap>();utility::Span const& span = __jakt_match_value.span;
return JaktInternal::ExplicitValue(span);
};/*case end*/
case 22: {
auto&& __jakt_match_value = __jakt_match_variant.template get<parser::ParsedExpression::Match>();utility::Span const& span = __jakt_match_value.span;
return JaktInternal::ExplicitValue(span);
};/*case end*/
case 23: {
auto&& __jakt_match_value = __jakt_match_variant.template get<parser::ParsedExpression::EnumVariantArg>();utility::Span const& span = __jakt_match_value.span;
return JaktInternal::ExplicitValue(span);
};/*case end*/
case 24: {
auto&& __jakt_match_value = __jakt_match_variant.template get<parser::ParsedExpression::NamespacedVar>();utility::Span const& span = __jakt_match_value.span;
return JaktInternal::ExplicitValue(span);
};/*case end*/
case 25: {
auto&& __jakt_match_value = __jakt_match_variant.template get<parser::ParsedExpression::Function>();utility::Span const& span = __jakt_match_value.span;
return JaktInternal::ExplicitValue(span);
};/*case end*/
case 26: {
auto&& __jakt_match_value = __jakt_match_variant.template get<parser::ParsedExpression::Try>();utility::Span const& span = __jakt_match_value.span;
return JaktInternal::ExplicitValue(span);
};/*case end*/
case 27: {
auto&& __jakt_match_value = __jakt_match_variant.template get<parser::ParsedExpression::TryBlock>();utility::Span const& span = __jakt_match_value.span;
return JaktInternal::ExplicitValue(span);
};/*case end*/
case 28: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename parser::ParsedExpression::Garbage>();
utility::Span const& span = __jakt_match_value.value;
return JaktInternal::ExplicitValue(span);
};/*case end*/
default: VERIFY_NOT_REACHED();}/*switch end*/
}()
)));
}
}

i64 parser::ParsedExpression::precedence() const {
{
return (JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<i64, i64>{
auto&& __jakt_match_variant = *this;
switch(__jakt_match_variant.index()) {
case 13: {
auto&& __jakt_match_value = __jakt_match_variant.template get<parser::ParsedExpression::Operator>();parser::BinaryOperator const& op = __jakt_match_value.op;
utility::Span const& span = __jakt_match_value.span;
return JaktInternal::ExplicitValue(JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<i64, i64>{
auto&& __jakt_match_variant = op;
switch(__jakt_match_variant.index()) {
case 2: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename parser::BinaryOperator::Multiply>();
return JaktInternal::ExplicitValue(static_cast<i64>(100LL));
};/*case end*/
case 4: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename parser::BinaryOperator::Modulo>();
return JaktInternal::ExplicitValue(static_cast<i64>(100LL));
};/*case end*/
case 3: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename parser::BinaryOperator::Divide>();
return JaktInternal::ExplicitValue(static_cast<i64>(100LL));
};/*case end*/
case 0: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename parser::BinaryOperator::Add>();
return JaktInternal::ExplicitValue(static_cast<i64>(90LL));
};/*case end*/
case 1: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename parser::BinaryOperator::Subtract>();
return JaktInternal::ExplicitValue(static_cast<i64>(90LL));
};/*case end*/
case 14: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename parser::BinaryOperator::BitwiseLeftShift>();
return JaktInternal::ExplicitValue(static_cast<i64>(85LL));
};/*case end*/
case 15: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename parser::BinaryOperator::BitwiseRightShift>();
return JaktInternal::ExplicitValue(static_cast<i64>(85LL));
};/*case end*/
case 16: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename parser::BinaryOperator::ArithmeticLeftShift>();
return JaktInternal::ExplicitValue(static_cast<i64>(85LL));
};/*case end*/
case 17: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename parser::BinaryOperator::ArithmeticRightShift>();
return JaktInternal::ExplicitValue(static_cast<i64>(85LL));
};/*case end*/
case 5: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename parser::BinaryOperator::LessThan>();
return JaktInternal::ExplicitValue(static_cast<i64>(80LL));
};/*case end*/
case 6: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename parser::BinaryOperator::LessThanOrEqual>();
return JaktInternal::ExplicitValue(static_cast<i64>(80LL));
};/*case end*/
case 7: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename parser::BinaryOperator::GreaterThan>();
return JaktInternal::ExplicitValue(static_cast<i64>(80LL));
};/*case end*/
case 8: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename parser::BinaryOperator::GreaterThanOrEqual>();
return JaktInternal::ExplicitValue(static_cast<i64>(80LL));
};/*case end*/
case 9: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename parser::BinaryOperator::Equal>();
return JaktInternal::ExplicitValue(static_cast<i64>(80LL));
};/*case end*/
case 10: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename parser::BinaryOperator::NotEqual>();
return JaktInternal::ExplicitValue(static_cast<i64>(80LL));
};/*case end*/
case 11: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename parser::BinaryOperator::BitwiseAnd>();
return JaktInternal::ExplicitValue(static_cast<i64>(73LL));
};/*case end*/
case 12: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename parser::BinaryOperator::BitwiseXor>();
return JaktInternal::ExplicitValue(static_cast<i64>(72LL));
};/*case end*/
case 13: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename parser::BinaryOperator::BitwiseOr>();
return JaktInternal::ExplicitValue(static_cast<i64>(71LL));
};/*case end*/
case 18: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename parser::BinaryOperator::LogicalAnd>();
return JaktInternal::ExplicitValue(static_cast<i64>(70LL));
};/*case end*/
case 19: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename parser::BinaryOperator::LogicalOr>();
return JaktInternal::ExplicitValue(static_cast<i64>(69LL));
};/*case end*/
case 20: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename parser::BinaryOperator::NoneCoalescing>();
return JaktInternal::ExplicitValue(static_cast<i64>(69LL));
};/*case end*/
case 21: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename parser::BinaryOperator::Assign>();
return JaktInternal::ExplicitValue(static_cast<i64>(50LL));
};/*case end*/
case 22: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename parser::BinaryOperator::BitwiseAndAssign>();
return JaktInternal::ExplicitValue(static_cast<i64>(50LL));
};/*case end*/
case 23: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename parser::BinaryOperator::BitwiseOrAssign>();
return JaktInternal::ExplicitValue(static_cast<i64>(50LL));
};/*case end*/
case 24: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename parser::BinaryOperator::BitwiseXorAssign>();
return JaktInternal::ExplicitValue(static_cast<i64>(50LL));
};/*case end*/
case 25: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename parser::BinaryOperator::BitwiseLeftShiftAssign>();
return JaktInternal::ExplicitValue(static_cast<i64>(50LL));
};/*case end*/
case 26: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename parser::BinaryOperator::BitwiseRightShiftAssign>();
return JaktInternal::ExplicitValue(static_cast<i64>(50LL));
};/*case end*/
case 27: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename parser::BinaryOperator::AddAssign>();
return JaktInternal::ExplicitValue(static_cast<i64>(50LL));
};/*case end*/
case 28: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename parser::BinaryOperator::SubtractAssign>();
return JaktInternal::ExplicitValue(static_cast<i64>(50LL));
};/*case end*/
case 29: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename parser::BinaryOperator::MultiplyAssign>();
return JaktInternal::ExplicitValue(static_cast<i64>(50LL));
};/*case end*/
case 30: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename parser::BinaryOperator::ModuloAssign>();
return JaktInternal::ExplicitValue(static_cast<i64>(50LL));
};/*case end*/
case 31: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename parser::BinaryOperator::DivideAssign>();
return JaktInternal::ExplicitValue(static_cast<i64>(50LL));
};/*case end*/
case 32: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename parser::BinaryOperator::NoneCoalescingAssign>();
return JaktInternal::ExplicitValue(static_cast<i64>(50LL));
};/*case end*/
default: {
return JaktInternal::ExplicitValue(static_cast<i64>(0LL));
};/*case end*/
}/*switch end*/
}()
)));
};/*case end*/
default: {
return JaktInternal::ExplicitValue(static_cast<i64>(0LL));
};/*case end*/
}/*switch end*/
}()
)));
}
}

ErrorOr<DeprecatedString> parser::ImportList::debug_description() const {
auto builder = TRY(DeprecatedStringBuilder::create());
switch (this->index()) {case 0 /* List */: {
[[maybe_unused]] auto const& that = this->template get<ImportList::List>();
TRY(builder.append("ImportList::List"sv));
TRY(builder.appendff("({})", that.value));
break;}
case 1 /* All */: {
[[maybe_unused]] auto const& that = this->template get<ImportList::All>();
TRY(builder.append("ImportList::All"sv));
break;}
}
return builder.to_string();
}
ErrorOr<void> parser::ImportList::add(parser::ImportName const name) {
{
JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<void, ErrorOr<void>>{
auto&& __jakt_match_variant = *this;
switch(__jakt_match_variant.index()) {
case 0: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename parser::ImportList::List>();
JaktInternal::DynamicArray<parser::ImportName> const& names = __jakt_match_value.value;
{
JaktInternal::DynamicArray<parser::ImportName> mutable_names = names;
TRY((((mutable_names).push(name))));
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 1: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename parser::ImportList::All>();
{
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
default: VERIFY_NOT_REACHED();}/*switch end*/
}()
));
}
return {};
}

bool parser::ImportList::is_empty() const {
{
return (JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<bool, bool>{
auto&& __jakt_match_variant = *this;
switch(__jakt_match_variant.index()) {
case 0: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename parser::ImportList::List>();
JaktInternal::DynamicArray<parser::ImportName> const& names = __jakt_match_value.value;
return JaktInternal::ExplicitValue(((names).is_empty()));
};/*case end*/
case 1: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename parser::ImportList::All>();
return JaktInternal::ExplicitValue(false);
};/*case end*/
default: VERIFY_NOT_REACHED();}/*switch end*/
}()
)));
}
}

ErrorOr<DeprecatedString> parser::ParsedCapture::debug_description() const {
auto builder = TRY(DeprecatedStringBuilder::create());
switch (this->index()) {case 0 /* ByValue */: {
[[maybe_unused]] auto const& that = this->template get<ParsedCapture::ByValue>();
TRY(builder.append("ParsedCapture::ByValue"sv));
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
[[maybe_unused]] auto const& that = this->template get<ParsedCapture::ByReference>();
TRY(builder.append("ParsedCapture::ByReference"sv));
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
[[maybe_unused]] auto const& that = this->template get<ParsedCapture::ByMutableReference>();
TRY(builder.append("ParsedCapture::ByMutableReference"sv));
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
[[maybe_unused]] auto const& that = this->template get<ParsedCapture::AllByReference>();
TRY(builder.append("ParsedCapture::AllByReference"sv));
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
DeprecatedString parser::ParsedCapture::name() const {
{
return (JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<DeprecatedString, DeprecatedString>{
auto&& __jakt_match_variant = *this;
switch(__jakt_match_variant.index()) {
case 0: {
auto&& __jakt_match_value = __jakt_match_variant.template get<parser::ParsedCapture::ByValue>();DeprecatedString const& name = __jakt_match_value.name;
return JaktInternal::ExplicitValue(name);
};/*case end*/
case 1: {
auto&& __jakt_match_value = __jakt_match_variant.template get<parser::ParsedCapture::ByReference>();DeprecatedString const& name = __jakt_match_value.name;
return JaktInternal::ExplicitValue(name);
};/*case end*/
case 2: {
auto&& __jakt_match_value = __jakt_match_variant.template get<parser::ParsedCapture::ByMutableReference>();DeprecatedString const& name = __jakt_match_value.name;
return JaktInternal::ExplicitValue(name);
};/*case end*/
case 3: {
auto&& __jakt_match_value = __jakt_match_variant.template get<parser::ParsedCapture::AllByReference>();return JaktInternal::ExplicitValue(Jakt::DeprecatedString(""sv));
};/*case end*/
default: VERIFY_NOT_REACHED();}/*switch end*/
}()
)));
}
}

utility::Span parser::ParsedCapture::span() const {
{
return (JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<utility::Span, utility::Span>{
auto&& __jakt_match_variant = *this;
switch(__jakt_match_variant.index()) {
case 0: {
auto&& __jakt_match_value = __jakt_match_variant.template get<parser::ParsedCapture::ByValue>();utility::Span const& span = __jakt_match_value.span;
return JaktInternal::ExplicitValue(span);
};/*case end*/
case 1: {
auto&& __jakt_match_value = __jakt_match_variant.template get<parser::ParsedCapture::ByReference>();utility::Span const& span = __jakt_match_value.span;
return JaktInternal::ExplicitValue(span);
};/*case end*/
case 2: {
auto&& __jakt_match_value = __jakt_match_variant.template get<parser::ParsedCapture::ByMutableReference>();utility::Span const& span = __jakt_match_value.span;
return JaktInternal::ExplicitValue(span);
};/*case end*/
case 3: {
auto&& __jakt_match_value = __jakt_match_variant.template get<parser::ParsedCapture::AllByReference>();utility::Span const& span = __jakt_match_value.span;
return JaktInternal::ExplicitValue(span);
};/*case end*/
default: VERIFY_NOT_REACHED();}/*switch end*/
}()
)));
}
}

ErrorOr<DeprecatedString> parser::BinaryOperator::debug_description() const {
auto builder = TRY(DeprecatedStringBuilder::create());
switch (this->index()) {case 0 /* Add */: {
[[maybe_unused]] auto const& that = this->template get<BinaryOperator::Add>();
TRY(builder.append("BinaryOperator::Add"sv));
break;}
case 1 /* Subtract */: {
[[maybe_unused]] auto const& that = this->template get<BinaryOperator::Subtract>();
TRY(builder.append("BinaryOperator::Subtract"sv));
break;}
case 2 /* Multiply */: {
[[maybe_unused]] auto const& that = this->template get<BinaryOperator::Multiply>();
TRY(builder.append("BinaryOperator::Multiply"sv));
break;}
case 3 /* Divide */: {
[[maybe_unused]] auto const& that = this->template get<BinaryOperator::Divide>();
TRY(builder.append("BinaryOperator::Divide"sv));
break;}
case 4 /* Modulo */: {
[[maybe_unused]] auto const& that = this->template get<BinaryOperator::Modulo>();
TRY(builder.append("BinaryOperator::Modulo"sv));
break;}
case 5 /* LessThan */: {
[[maybe_unused]] auto const& that = this->template get<BinaryOperator::LessThan>();
TRY(builder.append("BinaryOperator::LessThan"sv));
break;}
case 6 /* LessThanOrEqual */: {
[[maybe_unused]] auto const& that = this->template get<BinaryOperator::LessThanOrEqual>();
TRY(builder.append("BinaryOperator::LessThanOrEqual"sv));
break;}
case 7 /* GreaterThan */: {
[[maybe_unused]] auto const& that = this->template get<BinaryOperator::GreaterThan>();
TRY(builder.append("BinaryOperator::GreaterThan"sv));
break;}
case 8 /* GreaterThanOrEqual */: {
[[maybe_unused]] auto const& that = this->template get<BinaryOperator::GreaterThanOrEqual>();
TRY(builder.append("BinaryOperator::GreaterThanOrEqual"sv));
break;}
case 9 /* Equal */: {
[[maybe_unused]] auto const& that = this->template get<BinaryOperator::Equal>();
TRY(builder.append("BinaryOperator::Equal"sv));
break;}
case 10 /* NotEqual */: {
[[maybe_unused]] auto const& that = this->template get<BinaryOperator::NotEqual>();
TRY(builder.append("BinaryOperator::NotEqual"sv));
break;}
case 11 /* BitwiseAnd */: {
[[maybe_unused]] auto const& that = this->template get<BinaryOperator::BitwiseAnd>();
TRY(builder.append("BinaryOperator::BitwiseAnd"sv));
break;}
case 12 /* BitwiseXor */: {
[[maybe_unused]] auto const& that = this->template get<BinaryOperator::BitwiseXor>();
TRY(builder.append("BinaryOperator::BitwiseXor"sv));
break;}
case 13 /* BitwiseOr */: {
[[maybe_unused]] auto const& that = this->template get<BinaryOperator::BitwiseOr>();
TRY(builder.append("BinaryOperator::BitwiseOr"sv));
break;}
case 14 /* BitwiseLeftShift */: {
[[maybe_unused]] auto const& that = this->template get<BinaryOperator::BitwiseLeftShift>();
TRY(builder.append("BinaryOperator::BitwiseLeftShift"sv));
break;}
case 15 /* BitwiseRightShift */: {
[[maybe_unused]] auto const& that = this->template get<BinaryOperator::BitwiseRightShift>();
TRY(builder.append("BinaryOperator::BitwiseRightShift"sv));
break;}
case 16 /* ArithmeticLeftShift */: {
[[maybe_unused]] auto const& that = this->template get<BinaryOperator::ArithmeticLeftShift>();
TRY(builder.append("BinaryOperator::ArithmeticLeftShift"sv));
break;}
case 17 /* ArithmeticRightShift */: {
[[maybe_unused]] auto const& that = this->template get<BinaryOperator::ArithmeticRightShift>();
TRY(builder.append("BinaryOperator::ArithmeticRightShift"sv));
break;}
case 18 /* LogicalAnd */: {
[[maybe_unused]] auto const& that = this->template get<BinaryOperator::LogicalAnd>();
TRY(builder.append("BinaryOperator::LogicalAnd"sv));
break;}
case 19 /* LogicalOr */: {
[[maybe_unused]] auto const& that = this->template get<BinaryOperator::LogicalOr>();
TRY(builder.append("BinaryOperator::LogicalOr"sv));
break;}
case 20 /* NoneCoalescing */: {
[[maybe_unused]] auto const& that = this->template get<BinaryOperator::NoneCoalescing>();
TRY(builder.append("BinaryOperator::NoneCoalescing"sv));
break;}
case 21 /* Assign */: {
[[maybe_unused]] auto const& that = this->template get<BinaryOperator::Assign>();
TRY(builder.append("BinaryOperator::Assign"sv));
break;}
case 22 /* BitwiseAndAssign */: {
[[maybe_unused]] auto const& that = this->template get<BinaryOperator::BitwiseAndAssign>();
TRY(builder.append("BinaryOperator::BitwiseAndAssign"sv));
break;}
case 23 /* BitwiseOrAssign */: {
[[maybe_unused]] auto const& that = this->template get<BinaryOperator::BitwiseOrAssign>();
TRY(builder.append("BinaryOperator::BitwiseOrAssign"sv));
break;}
case 24 /* BitwiseXorAssign */: {
[[maybe_unused]] auto const& that = this->template get<BinaryOperator::BitwiseXorAssign>();
TRY(builder.append("BinaryOperator::BitwiseXorAssign"sv));
break;}
case 25 /* BitwiseLeftShiftAssign */: {
[[maybe_unused]] auto const& that = this->template get<BinaryOperator::BitwiseLeftShiftAssign>();
TRY(builder.append("BinaryOperator::BitwiseLeftShiftAssign"sv));
break;}
case 26 /* BitwiseRightShiftAssign */: {
[[maybe_unused]] auto const& that = this->template get<BinaryOperator::BitwiseRightShiftAssign>();
TRY(builder.append("BinaryOperator::BitwiseRightShiftAssign"sv));
break;}
case 27 /* AddAssign */: {
[[maybe_unused]] auto const& that = this->template get<BinaryOperator::AddAssign>();
TRY(builder.append("BinaryOperator::AddAssign"sv));
break;}
case 28 /* SubtractAssign */: {
[[maybe_unused]] auto const& that = this->template get<BinaryOperator::SubtractAssign>();
TRY(builder.append("BinaryOperator::SubtractAssign"sv));
break;}
case 29 /* MultiplyAssign */: {
[[maybe_unused]] auto const& that = this->template get<BinaryOperator::MultiplyAssign>();
TRY(builder.append("BinaryOperator::MultiplyAssign"sv));
break;}
case 30 /* ModuloAssign */: {
[[maybe_unused]] auto const& that = this->template get<BinaryOperator::ModuloAssign>();
TRY(builder.append("BinaryOperator::ModuloAssign"sv));
break;}
case 31 /* DivideAssign */: {
[[maybe_unused]] auto const& that = this->template get<BinaryOperator::DivideAssign>();
TRY(builder.append("BinaryOperator::DivideAssign"sv));
break;}
case 32 /* NoneCoalescingAssign */: {
[[maybe_unused]] auto const& that = this->template get<BinaryOperator::NoneCoalescingAssign>();
TRY(builder.append("BinaryOperator::NoneCoalescingAssign"sv));
break;}
case 33 /* Garbage */: {
[[maybe_unused]] auto const& that = this->template get<BinaryOperator::Garbage>();
TRY(builder.append("BinaryOperator::Garbage"sv));
break;}
}
return builder.to_string();
}
bool parser::BinaryOperator::equals(parser::BinaryOperator const rhs_op) const {
{
return (JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<bool, bool>{
auto&& __jakt_match_variant = *this;
switch(__jakt_match_variant.index()) {
case 0: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename parser::BinaryOperator::Add>();
return JaktInternal::ExplicitValue(((rhs_op).index() == 0 /* Add */));
};/*case end*/
case 1: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename parser::BinaryOperator::Subtract>();
return JaktInternal::ExplicitValue(((rhs_op).index() == 1 /* Subtract */));
};/*case end*/
case 2: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename parser::BinaryOperator::Multiply>();
return JaktInternal::ExplicitValue(((rhs_op).index() == 2 /* Multiply */));
};/*case end*/
case 3: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename parser::BinaryOperator::Divide>();
return JaktInternal::ExplicitValue(((rhs_op).index() == 3 /* Divide */));
};/*case end*/
case 4: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename parser::BinaryOperator::Modulo>();
return JaktInternal::ExplicitValue(((rhs_op).index() == 4 /* Modulo */));
};/*case end*/
case 5: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename parser::BinaryOperator::LessThan>();
return JaktInternal::ExplicitValue(((rhs_op).index() == 5 /* LessThan */));
};/*case end*/
case 6: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename parser::BinaryOperator::LessThanOrEqual>();
return JaktInternal::ExplicitValue(((rhs_op).index() == 6 /* LessThanOrEqual */));
};/*case end*/
case 7: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename parser::BinaryOperator::GreaterThan>();
return JaktInternal::ExplicitValue(((rhs_op).index() == 7 /* GreaterThan */));
};/*case end*/
case 8: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename parser::BinaryOperator::GreaterThanOrEqual>();
return JaktInternal::ExplicitValue(((rhs_op).index() == 8 /* GreaterThanOrEqual */));
};/*case end*/
case 9: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename parser::BinaryOperator::Equal>();
return JaktInternal::ExplicitValue(((rhs_op).index() == 9 /* Equal */));
};/*case end*/
case 10: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename parser::BinaryOperator::NotEqual>();
return JaktInternal::ExplicitValue(((rhs_op).index() == 10 /* NotEqual */));
};/*case end*/
case 11: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename parser::BinaryOperator::BitwiseAnd>();
return JaktInternal::ExplicitValue(((rhs_op).index() == 11 /* BitwiseAnd */));
};/*case end*/
case 12: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename parser::BinaryOperator::BitwiseXor>();
return JaktInternal::ExplicitValue(((rhs_op).index() == 12 /* BitwiseXor */));
};/*case end*/
case 13: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename parser::BinaryOperator::BitwiseOr>();
return JaktInternal::ExplicitValue(((rhs_op).index() == 13 /* BitwiseOr */));
};/*case end*/
case 14: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename parser::BinaryOperator::BitwiseLeftShift>();
return JaktInternal::ExplicitValue(((rhs_op).index() == 14 /* BitwiseLeftShift */));
};/*case end*/
case 15: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename parser::BinaryOperator::BitwiseRightShift>();
return JaktInternal::ExplicitValue(((rhs_op).index() == 15 /* BitwiseRightShift */));
};/*case end*/
case 16: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename parser::BinaryOperator::ArithmeticLeftShift>();
return JaktInternal::ExplicitValue(((rhs_op).index() == 16 /* ArithmeticLeftShift */));
};/*case end*/
case 17: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename parser::BinaryOperator::ArithmeticRightShift>();
return JaktInternal::ExplicitValue(((rhs_op).index() == 17 /* ArithmeticRightShift */));
};/*case end*/
case 19: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename parser::BinaryOperator::LogicalOr>();
return JaktInternal::ExplicitValue(((rhs_op).index() == 19 /* LogicalOr */));
};/*case end*/
case 18: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename parser::BinaryOperator::LogicalAnd>();
return JaktInternal::ExplicitValue(((rhs_op).index() == 18 /* LogicalAnd */));
};/*case end*/
case 20: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename parser::BinaryOperator::NoneCoalescing>();
return JaktInternal::ExplicitValue(((rhs_op).index() == 20 /* NoneCoalescing */));
};/*case end*/
case 21: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename parser::BinaryOperator::Assign>();
return JaktInternal::ExplicitValue(((rhs_op).index() == 21 /* Assign */));
};/*case end*/
case 22: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename parser::BinaryOperator::BitwiseAndAssign>();
return JaktInternal::ExplicitValue(((rhs_op).index() == 22 /* BitwiseAndAssign */));
};/*case end*/
case 23: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename parser::BinaryOperator::BitwiseOrAssign>();
return JaktInternal::ExplicitValue(((rhs_op).index() == 23 /* BitwiseOrAssign */));
};/*case end*/
case 24: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename parser::BinaryOperator::BitwiseXorAssign>();
return JaktInternal::ExplicitValue(((rhs_op).index() == 24 /* BitwiseXorAssign */));
};/*case end*/
case 25: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename parser::BinaryOperator::BitwiseLeftShiftAssign>();
return JaktInternal::ExplicitValue(((rhs_op).index() == 25 /* BitwiseLeftShiftAssign */));
};/*case end*/
case 26: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename parser::BinaryOperator::BitwiseRightShiftAssign>();
return JaktInternal::ExplicitValue(((rhs_op).index() == 26 /* BitwiseRightShiftAssign */));
};/*case end*/
case 27: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename parser::BinaryOperator::AddAssign>();
return JaktInternal::ExplicitValue(((rhs_op).index() == 27 /* AddAssign */));
};/*case end*/
case 28: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename parser::BinaryOperator::SubtractAssign>();
return JaktInternal::ExplicitValue(((rhs_op).index() == 28 /* SubtractAssign */));
};/*case end*/
case 29: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename parser::BinaryOperator::MultiplyAssign>();
return JaktInternal::ExplicitValue(((rhs_op).index() == 29 /* MultiplyAssign */));
};/*case end*/
case 30: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename parser::BinaryOperator::ModuloAssign>();
return JaktInternal::ExplicitValue(((rhs_op).index() == 30 /* ModuloAssign */));
};/*case end*/
case 31: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename parser::BinaryOperator::DivideAssign>();
return JaktInternal::ExplicitValue(((rhs_op).index() == 31 /* DivideAssign */));
};/*case end*/
case 32: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename parser::BinaryOperator::NoneCoalescingAssign>();
return JaktInternal::ExplicitValue(((rhs_op).index() == 32 /* NoneCoalescingAssign */));
};/*case end*/
case 33: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename parser::BinaryOperator::Garbage>();
return JaktInternal::ExplicitValue(((rhs_op).index() == 33 /* Garbage */));
};/*case end*/
default: VERIFY_NOT_REACHED();}/*switch end*/
}()
)));
}
}

bool parser::BinaryOperator::is_assignment() const {
{
return (JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<bool, bool>{
auto&& __jakt_match_variant = *this;
switch(__jakt_match_variant.index()) {
case 21: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename parser::BinaryOperator::Assign>();
return JaktInternal::ExplicitValue(true);
};/*case end*/
case 22: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename parser::BinaryOperator::BitwiseAndAssign>();
return JaktInternal::ExplicitValue(true);
};/*case end*/
case 23: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename parser::BinaryOperator::BitwiseOrAssign>();
return JaktInternal::ExplicitValue(true);
};/*case end*/
case 24: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename parser::BinaryOperator::BitwiseXorAssign>();
return JaktInternal::ExplicitValue(true);
};/*case end*/
case 25: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename parser::BinaryOperator::BitwiseLeftShiftAssign>();
return JaktInternal::ExplicitValue(true);
};/*case end*/
case 26: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename parser::BinaryOperator::BitwiseRightShiftAssign>();
return JaktInternal::ExplicitValue(true);
};/*case end*/
case 27: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename parser::BinaryOperator::AddAssign>();
return JaktInternal::ExplicitValue(true);
};/*case end*/
case 28: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename parser::BinaryOperator::SubtractAssign>();
return JaktInternal::ExplicitValue(true);
};/*case end*/
case 29: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename parser::BinaryOperator::MultiplyAssign>();
return JaktInternal::ExplicitValue(true);
};/*case end*/
case 30: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename parser::BinaryOperator::ModuloAssign>();
return JaktInternal::ExplicitValue(true);
};/*case end*/
case 31: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename parser::BinaryOperator::DivideAssign>();
return JaktInternal::ExplicitValue(true);
};/*case end*/
case 32: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename parser::BinaryOperator::NoneCoalescingAssign>();
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

ErrorOr<DeprecatedString> parser::FunctionType::debug_description() const {
auto builder = TRY(DeprecatedStringBuilder::create());
switch (this->index()) {case 0 /* Normal */: {
[[maybe_unused]] auto const& that = this->template get<FunctionType::Normal>();
TRY(builder.append("FunctionType::Normal"sv));
break;}
case 1 /* ImplicitConstructor */: {
[[maybe_unused]] auto const& that = this->template get<FunctionType::ImplicitConstructor>();
TRY(builder.append("FunctionType::ImplicitConstructor"sv));
break;}
case 2 /* ImplicitEnumConstructor */: {
[[maybe_unused]] auto const& that = this->template get<FunctionType::ImplicitEnumConstructor>();
TRY(builder.append("FunctionType::ImplicitEnumConstructor"sv));
break;}
case 3 /* ExternalClassConstructor */: {
[[maybe_unused]] auto const& that = this->template get<FunctionType::ExternalClassConstructor>();
TRY(builder.append("FunctionType::ExternalClassConstructor"sv));
break;}
case 4 /* Expression */: {
[[maybe_unused]] auto const& that = this->template get<FunctionType::Expression>();
TRY(builder.append("FunctionType::Expression"sv));
break;}
case 5 /* Closure */: {
[[maybe_unused]] auto const& that = this->template get<FunctionType::Closure>();
TRY(builder.append("FunctionType::Closure"sv));
break;}
}
return builder.to_string();
}
ErrorOr<DeprecatedString> parser::ParsedStatement::debug_description() const {
auto builder = TRY(DeprecatedStringBuilder::create());
switch (this->index()) {case 0 /* Expression */: {
[[maybe_unused]] auto const& that = this->template get<ParsedStatement::Expression>();
TRY(builder.append("ParsedStatement::Expression"sv));
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
[[maybe_unused]] auto const& that = this->template get<ParsedStatement::Defer>();
TRY(builder.append("ParsedStatement::Defer"sv));
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
case 2 /* UnsafeBlock */: {
[[maybe_unused]] auto const& that = this->template get<ParsedStatement::UnsafeBlock>();
TRY(builder.append("ParsedStatement::UnsafeBlock"sv));
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
case 3 /* DestructuringAssignment */: {
[[maybe_unused]] auto const& that = this->template get<ParsedStatement::DestructuringAssignment>();
TRY(builder.append("ParsedStatement::DestructuringAssignment"sv));
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
case 4 /* VarDecl */: {
[[maybe_unused]] auto const& that = this->template get<ParsedStatement::VarDecl>();
TRY(builder.append("ParsedStatement::VarDecl"sv));
TRY(builder.append("("sv));
{
JaktInternal::PrettyPrint::ScopedLevelIncrease increase_indent {};
TRY(JaktInternal::PrettyPrint::output_indentation(builder));
TRY(builder.appendff("var: {}", that.var));
TRY(builder.append(", "sv));
TRY(JaktInternal::PrettyPrint::output_indentation(builder));
TRY(builder.appendff("init: {}", that.init));
TRY(builder.append(", "sv));
TRY(JaktInternal::PrettyPrint::output_indentation(builder));
TRY(builder.appendff("span: {}", that.span));
}
TRY(builder.append(")"sv));
break;}
case 5 /* If */: {
[[maybe_unused]] auto const& that = this->template get<ParsedStatement::If>();
TRY(builder.append("ParsedStatement::If"sv));
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
case 6 /* Block */: {
[[maybe_unused]] auto const& that = this->template get<ParsedStatement::Block>();
TRY(builder.append("ParsedStatement::Block"sv));
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
case 7 /* Loop */: {
[[maybe_unused]] auto const& that = this->template get<ParsedStatement::Loop>();
TRY(builder.append("ParsedStatement::Loop"sv));
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
case 8 /* While */: {
[[maybe_unused]] auto const& that = this->template get<ParsedStatement::While>();
TRY(builder.append("ParsedStatement::While"sv));
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
case 9 /* For */: {
[[maybe_unused]] auto const& that = this->template get<ParsedStatement::For>();
TRY(builder.append("ParsedStatement::For"sv));
TRY(builder.append("("sv));
{
JaktInternal::PrettyPrint::ScopedLevelIncrease increase_indent {};
TRY(JaktInternal::PrettyPrint::output_indentation(builder));
TRY(builder.appendff("iterator_name: \"{}\"", that.iterator_name));
TRY(builder.append(", "sv));
TRY(JaktInternal::PrettyPrint::output_indentation(builder));
TRY(builder.appendff("name_span: {}", that.name_span));
TRY(builder.append(", "sv));
TRY(JaktInternal::PrettyPrint::output_indentation(builder));
TRY(builder.appendff("range: {}", that.range));
TRY(builder.append(", "sv));
TRY(JaktInternal::PrettyPrint::output_indentation(builder));
TRY(builder.appendff("block: {}", that.block));
TRY(builder.append(", "sv));
TRY(JaktInternal::PrettyPrint::output_indentation(builder));
TRY(builder.appendff("span: {}", that.span));
}
TRY(builder.append(")"sv));
break;}
case 10 /* Break */: {
[[maybe_unused]] auto const& that = this->template get<ParsedStatement::Break>();
TRY(builder.append("ParsedStatement::Break"sv));
TRY(builder.appendff("({})", that.value));
break;}
case 11 /* Continue */: {
[[maybe_unused]] auto const& that = this->template get<ParsedStatement::Continue>();
TRY(builder.append("ParsedStatement::Continue"sv));
TRY(builder.appendff("({})", that.value));
break;}
case 12 /* Return */: {
[[maybe_unused]] auto const& that = this->template get<ParsedStatement::Return>();
TRY(builder.append("ParsedStatement::Return"sv));
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
case 13 /* Throw */: {
[[maybe_unused]] auto const& that = this->template get<ParsedStatement::Throw>();
TRY(builder.append("ParsedStatement::Throw"sv));
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
case 14 /* Yield */: {
[[maybe_unused]] auto const& that = this->template get<ParsedStatement::Yield>();
TRY(builder.append("ParsedStatement::Yield"sv));
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
case 15 /* InlineCpp */: {
[[maybe_unused]] auto const& that = this->template get<ParsedStatement::InlineCpp>();
TRY(builder.append("ParsedStatement::InlineCpp"sv));
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
case 16 /* Guard */: {
[[maybe_unused]] auto const& that = this->template get<ParsedStatement::Guard>();
TRY(builder.append("ParsedStatement::Guard"sv));
TRY(builder.append("("sv));
{
JaktInternal::PrettyPrint::ScopedLevelIncrease increase_indent {};
TRY(JaktInternal::PrettyPrint::output_indentation(builder));
TRY(builder.appendff("expr: {}", that.expr));
TRY(builder.append(", "sv));
TRY(JaktInternal::PrettyPrint::output_indentation(builder));
TRY(builder.appendff("else_block: {}", that.else_block));
TRY(builder.append(", "sv));
TRY(JaktInternal::PrettyPrint::output_indentation(builder));
TRY(builder.appendff("remaining_code: {}", that.remaining_code));
TRY(builder.append(", "sv));
TRY(JaktInternal::PrettyPrint::output_indentation(builder));
TRY(builder.appendff("span: {}", that.span));
}
TRY(builder.append(")"sv));
break;}
case 17 /* Garbage */: {
[[maybe_unused]] auto const& that = this->template get<ParsedStatement::Garbage>();
TRY(builder.append("ParsedStatement::Garbage"sv));
TRY(builder.appendff("({})", that.value));
break;}
}
return builder.to_string();
}
bool parser::ParsedStatement::equals(NonnullRefPtr<typename parser::ParsedStatement> const rhs_statement) const {
{
return (JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<bool, bool>{
auto&& __jakt_match_variant = *this;
switch(__jakt_match_variant.index()) {
case 0: {
auto&& __jakt_match_value = __jakt_match_variant.template get<parser::ParsedStatement::Expression>();NonnullRefPtr<typename parser::ParsedExpression> const& lhs_expr = __jakt_match_value.expr;
return JaktInternal::ExplicitValue(JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<bool, bool>{
auto&& __jakt_match_variant = *rhs_statement;
switch(__jakt_match_variant.index()) {
case 0: {
auto&& __jakt_match_value = __jakt_match_variant.template get<parser::ParsedStatement::Expression>();NonnullRefPtr<typename parser::ParsedExpression> const& rhs_expr = __jakt_match_value.expr;
return JaktInternal::ExplicitValue(((lhs_expr)->equals(rhs_expr)));
};/*case end*/
default: {
return JaktInternal::ExplicitValue(false);
};/*case end*/
}/*switch end*/
}()
)));
};/*case end*/
case 1: {
auto&& __jakt_match_value = __jakt_match_variant.template get<parser::ParsedStatement::Defer>();NonnullRefPtr<typename parser::ParsedStatement> const& lhs_statement = __jakt_match_value.statement;
return JaktInternal::ExplicitValue(JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<bool, bool>{
auto&& __jakt_match_variant = *rhs_statement;
switch(__jakt_match_variant.index()) {
case 1: {
auto&& __jakt_match_value = __jakt_match_variant.template get<parser::ParsedStatement::Defer>();NonnullRefPtr<typename parser::ParsedStatement> const& rhs_statement = __jakt_match_value.statement;
return JaktInternal::ExplicitValue(((lhs_statement)->equals(rhs_statement)));
};/*case end*/
default: {
return JaktInternal::ExplicitValue(false);
};/*case end*/
}/*switch end*/
}()
)));
};/*case end*/
case 2: {
auto&& __jakt_match_value = __jakt_match_variant.template get<parser::ParsedStatement::UnsafeBlock>();parser::ParsedBlock const& lhs_block = __jakt_match_value.block;
return JaktInternal::ExplicitValue(JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<bool, bool>{
auto&& __jakt_match_variant = *rhs_statement;
switch(__jakt_match_variant.index()) {
case 2: {
auto&& __jakt_match_value = __jakt_match_variant.template get<parser::ParsedStatement::UnsafeBlock>();parser::ParsedBlock const& rhs_block = __jakt_match_value.block;
return JaktInternal::ExplicitValue(((lhs_block).equals(rhs_block)));
};/*case end*/
default: {
return JaktInternal::ExplicitValue(false);
};/*case end*/
}/*switch end*/
}()
)));
};/*case end*/
case 4: {
auto&& __jakt_match_value = __jakt_match_variant.template get<parser::ParsedStatement::VarDecl>();parser::ParsedVarDecl const& lhs_var = __jakt_match_value.var;
NonnullRefPtr<typename parser::ParsedExpression> const& lhs_init = __jakt_match_value.init;
return JaktInternal::ExplicitValue(JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<bool, bool>{
auto&& __jakt_match_variant = *rhs_statement;
switch(__jakt_match_variant.index()) {
case 4: {
auto&& __jakt_match_value = __jakt_match_variant.template get<parser::ParsedStatement::VarDecl>();parser::ParsedVarDecl const& rhs_var = __jakt_match_value.var;
NonnullRefPtr<typename parser::ParsedExpression> const& rhs_init = __jakt_match_value.init;
return JaktInternal::ExplicitValue((((lhs_var).equals(rhs_var)) && ((lhs_init)->equals(rhs_init))));
};/*case end*/
default: {
return JaktInternal::ExplicitValue(false);
};/*case end*/
}/*switch end*/
}()
)));
};/*case end*/
case 3: {
auto&& __jakt_match_value = __jakt_match_variant.template get<parser::ParsedStatement::DestructuringAssignment>();JaktInternal::DynamicArray<parser::ParsedVarDecl> const& lhs_vars = __jakt_match_value.vars;
NonnullRefPtr<typename parser::ParsedStatement> const& lhs_var_decl = __jakt_match_value.var_decl;
return JaktInternal::ExplicitValue(JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<bool, bool>{
auto&& __jakt_match_variant = *rhs_statement;
switch(__jakt_match_variant.index()) {
case 3: {
auto&& __jakt_match_value = __jakt_match_variant.template get<parser::ParsedStatement::DestructuringAssignment>();JaktInternal::DynamicArray<parser::ParsedVarDecl> const& rhs_vars = __jakt_match_value.vars;
NonnullRefPtr<typename parser::ParsedStatement> const& rhs_var_decl = __jakt_match_value.var_decl;
{
if ((((lhs_vars).size()) != ((rhs_vars).size()))){
return (false);
}
{
JaktInternal::Range<size_t> _magic = (JaktInternal::Range<size_t>{static_cast<size_t>(static_cast<size_t>(0ULL)),static_cast<size_t>(((lhs_vars).size()))});
for (;;){
JaktInternal::Optional<size_t> _magic_value = ((_magic).next());
if ((!(((_magic_value).has_value())))){
break;
}
size_t i = (_magic_value.value());
{
if ((!(((((lhs_vars)[i])).equals(((rhs_vars)[i])))))){
return (false);
}
}

}
}

if ((!(((lhs_var_decl)->equals(rhs_var_decl))))){
return (false);
}
return (true);
}
};/*case end*/
default: {
return JaktInternal::ExplicitValue(false);
};/*case end*/
}/*switch end*/
}()
)));
};/*case end*/
case 5: {
auto&& __jakt_match_value = __jakt_match_variant.template get<parser::ParsedStatement::If>();NonnullRefPtr<typename parser::ParsedExpression> const& lhs_condition = __jakt_match_value.condition;
parser::ParsedBlock const& lhs_then_block = __jakt_match_value.then_block;
JaktInternal::Optional<NonnullRefPtr<typename parser::ParsedStatement>> const& lhs_else_statement = __jakt_match_value.else_statement;
return JaktInternal::ExplicitValue(JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<bool, bool>{
auto&& __jakt_match_variant = *rhs_statement;
switch(__jakt_match_variant.index()) {
case 5: {
auto&& __jakt_match_value = __jakt_match_variant.template get<parser::ParsedStatement::If>();NonnullRefPtr<typename parser::ParsedExpression> const& rhs_condition = __jakt_match_value.condition;
parser::ParsedBlock const& rhs_then_block = __jakt_match_value.then_block;
JaktInternal::Optional<NonnullRefPtr<typename parser::ParsedStatement>> const& rhs_else_statement = __jakt_match_value.else_statement;
{
if ((!((((lhs_condition)->equals(rhs_condition)) && ((lhs_then_block).equals(rhs_then_block)))))){
return (false);
}
if ((!(((lhs_else_statement).has_value())))){
return ((!(((rhs_else_statement).has_value()))));
}
else {
if ((!(((rhs_else_statement).has_value())))){
return (false);
}
if ((((lhs_else_statement.value()))->equals((rhs_else_statement.value())))){
return (true);
}
return (false);
}

}
};/*case end*/
default: {
return JaktInternal::ExplicitValue(false);
};/*case end*/
}/*switch end*/
}()
)));
};/*case end*/
case 6: {
auto&& __jakt_match_value = __jakt_match_variant.template get<parser::ParsedStatement::Block>();parser::ParsedBlock const& lhs_block = __jakt_match_value.block;
return JaktInternal::ExplicitValue(JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<bool, bool>{
auto&& __jakt_match_variant = *rhs_statement;
switch(__jakt_match_variant.index()) {
case 6: {
auto&& __jakt_match_value = __jakt_match_variant.template get<parser::ParsedStatement::Block>();parser::ParsedBlock const& rhs_block = __jakt_match_value.block;
return JaktInternal::ExplicitValue(((lhs_block).equals(rhs_block)));
};/*case end*/
default: {
return JaktInternal::ExplicitValue(false);
};/*case end*/
}/*switch end*/
}()
)));
};/*case end*/
case 7: {
auto&& __jakt_match_value = __jakt_match_variant.template get<parser::ParsedStatement::Loop>();parser::ParsedBlock const& lhs_block = __jakt_match_value.block;
return JaktInternal::ExplicitValue(JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<bool, bool>{
auto&& __jakt_match_variant = *rhs_statement;
switch(__jakt_match_variant.index()) {
case 7: {
auto&& __jakt_match_value = __jakt_match_variant.template get<parser::ParsedStatement::Loop>();parser::ParsedBlock const& rhs_block = __jakt_match_value.block;
return JaktInternal::ExplicitValue(((lhs_block).equals(rhs_block)));
};/*case end*/
default: {
return JaktInternal::ExplicitValue(false);
};/*case end*/
}/*switch end*/
}()
)));
};/*case end*/
case 8: {
auto&& __jakt_match_value = __jakt_match_variant.template get<parser::ParsedStatement::While>();NonnullRefPtr<typename parser::ParsedExpression> const& lhs_condition = __jakt_match_value.condition;
parser::ParsedBlock const& lhs_block = __jakt_match_value.block;
return JaktInternal::ExplicitValue(JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<bool, bool>{
auto&& __jakt_match_variant = *rhs_statement;
switch(__jakt_match_variant.index()) {
case 8: {
auto&& __jakt_match_value = __jakt_match_variant.template get<parser::ParsedStatement::While>();NonnullRefPtr<typename parser::ParsedExpression> const& rhs_condition = __jakt_match_value.condition;
parser::ParsedBlock const& rhs_block = __jakt_match_value.block;
return JaktInternal::ExplicitValue((((lhs_condition)->equals(rhs_condition)) && ((lhs_block).equals(rhs_block))));
};/*case end*/
default: {
return JaktInternal::ExplicitValue(false);
};/*case end*/
}/*switch end*/
}()
)));
};/*case end*/
case 9: {
auto&& __jakt_match_value = __jakt_match_variant.template get<parser::ParsedStatement::For>();DeprecatedString const& lhs_iterator_name = __jakt_match_value.iterator_name;
NonnullRefPtr<typename parser::ParsedExpression> const& lhs_range = __jakt_match_value.range;
parser::ParsedBlock const& lhs_block = __jakt_match_value.block;
return JaktInternal::ExplicitValue(JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<bool, bool>{
auto&& __jakt_match_variant = *rhs_statement;
switch(__jakt_match_variant.index()) {
case 9: {
auto&& __jakt_match_value = __jakt_match_variant.template get<parser::ParsedStatement::For>();DeprecatedString const& rhs_iterator_name = __jakt_match_value.iterator_name;
NonnullRefPtr<typename parser::ParsedExpression> const& rhs_range = __jakt_match_value.range;
parser::ParsedBlock const& rhs_block = __jakt_match_value.block;
return JaktInternal::ExplicitValue(({ Optional<bool> __jakt_var_114; {
__jakt_var_114 = (((lhs_iterator_name == rhs_iterator_name) && ((lhs_range)->equals(rhs_range))) && ((lhs_block).equals(rhs_block))); goto __jakt_label_111;

}
__jakt_label_111:; __jakt_var_114.release_value(); }));
};/*case end*/
default: {
return JaktInternal::ExplicitValue(false);
};/*case end*/
}/*switch end*/
}()
)));
};/*case end*/
case 10: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename parser::ParsedStatement::Break>();
return JaktInternal::ExplicitValue(((rhs_statement)->index() == 10 /* Break */));
};/*case end*/
case 11: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename parser::ParsedStatement::Continue>();
return JaktInternal::ExplicitValue(((rhs_statement)->index() == 11 /* Continue */));
};/*case end*/
case 12: {
auto&& __jakt_match_value = __jakt_match_variant.template get<parser::ParsedStatement::Return>();JaktInternal::Optional<NonnullRefPtr<typename parser::ParsedExpression>> const& lhs_expr = __jakt_match_value.expr;
return JaktInternal::ExplicitValue(JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<bool, bool>{
auto&& __jakt_match_variant = *rhs_statement;
switch(__jakt_match_variant.index()) {
case 12: {
auto&& __jakt_match_value = __jakt_match_variant.template get<parser::ParsedStatement::Return>();JaktInternal::Optional<NonnullRefPtr<typename parser::ParsedExpression>> const& rhs_expr = __jakt_match_value.expr;
{
if ((!(((lhs_expr).has_value())))){
return ((!(((rhs_expr).has_value()))));
}
else {
if ((!(((rhs_expr).has_value())))){
return (false);
}
if ((((lhs_expr.value()))->equals((rhs_expr.value())))){
return (true);
}
return (false);
}

}
};/*case end*/
default: {
return JaktInternal::ExplicitValue(false);
};/*case end*/
}/*switch end*/
}()
)));
};/*case end*/
case 13: {
auto&& __jakt_match_value = __jakt_match_variant.template get<parser::ParsedStatement::Throw>();NonnullRefPtr<typename parser::ParsedExpression> const& lhs_expr = __jakt_match_value.expr;
return JaktInternal::ExplicitValue(JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<bool, bool>{
auto&& __jakt_match_variant = *rhs_statement;
switch(__jakt_match_variant.index()) {
case 13: {
auto&& __jakt_match_value = __jakt_match_variant.template get<parser::ParsedStatement::Throw>();NonnullRefPtr<typename parser::ParsedExpression> const& rhs_expr = __jakt_match_value.expr;
return JaktInternal::ExplicitValue(((lhs_expr)->equals(rhs_expr)));
};/*case end*/
default: {
return JaktInternal::ExplicitValue(false);
};/*case end*/
}/*switch end*/
}()
)));
};/*case end*/
case 14: {
auto&& __jakt_match_value = __jakt_match_variant.template get<parser::ParsedStatement::Yield>();NonnullRefPtr<typename parser::ParsedExpression> const& lhs_expr = __jakt_match_value.expr;
return JaktInternal::ExplicitValue(JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<bool, bool>{
auto&& __jakt_match_variant = *rhs_statement;
switch(__jakt_match_variant.index()) {
case 14: {
auto&& __jakt_match_value = __jakt_match_variant.template get<parser::ParsedStatement::Yield>();NonnullRefPtr<typename parser::ParsedExpression> const& rhs_expr = __jakt_match_value.expr;
return JaktInternal::ExplicitValue(((lhs_expr)->equals(rhs_expr)));
};/*case end*/
default: {
return JaktInternal::ExplicitValue(false);
};/*case end*/
}/*switch end*/
}()
)));
};/*case end*/
case 15: {
auto&& __jakt_match_value = __jakt_match_variant.template get<parser::ParsedStatement::InlineCpp>();parser::ParsedBlock const& lhs_block = __jakt_match_value.block;
return JaktInternal::ExplicitValue(JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<bool, bool>{
auto&& __jakt_match_variant = *rhs_statement;
switch(__jakt_match_variant.index()) {
case 15: {
auto&& __jakt_match_value = __jakt_match_variant.template get<parser::ParsedStatement::InlineCpp>();parser::ParsedBlock const& block = __jakt_match_value.block;
return JaktInternal::ExplicitValue(((lhs_block).equals(block)));
};/*case end*/
default: {
return JaktInternal::ExplicitValue(false);
};/*case end*/
}/*switch end*/
}()
)));
};/*case end*/
case 16: {
auto&& __jakt_match_value = __jakt_match_variant.template get<parser::ParsedStatement::Guard>();NonnullRefPtr<typename parser::ParsedExpression> const& lhs_expr = __jakt_match_value.expr;
parser::ParsedBlock const& lhs_else_block = __jakt_match_value.else_block;
return JaktInternal::ExplicitValue(JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<bool, bool>{
auto&& __jakt_match_variant = *rhs_statement;
switch(__jakt_match_variant.index()) {
case 16: {
auto&& __jakt_match_value = __jakt_match_variant.template get<parser::ParsedStatement::Guard>();NonnullRefPtr<typename parser::ParsedExpression> const& rhs_expr = __jakt_match_value.expr;
parser::ParsedBlock const& rhs_else_block = __jakt_match_value.else_block;
return JaktInternal::ExplicitValue((((lhs_expr)->equals(rhs_expr)) && ((lhs_else_block).equals(rhs_else_block))));
};/*case end*/
default: {
return JaktInternal::ExplicitValue(false);
};/*case end*/
}/*switch end*/
}()
)));
};/*case end*/
case 17: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename parser::ParsedStatement::Garbage>();
return JaktInternal::ExplicitValue(((rhs_statement)->index() == 17 /* Garbage */));
};/*case end*/
default: VERIFY_NOT_REACHED();}/*switch end*/
}()
)));
}
}

utility::Span parser::ParsedStatement::span() const {
{
return (JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<utility::Span, utility::Span>{
auto&& __jakt_match_variant = *this;
switch(__jakt_match_variant.index()) {
case 0: {
auto&& __jakt_match_value = __jakt_match_variant.template get<parser::ParsedStatement::Expression>();utility::Span const& span = __jakt_match_value.span;
return JaktInternal::ExplicitValue(span);
};/*case end*/
case 1: {
auto&& __jakt_match_value = __jakt_match_variant.template get<parser::ParsedStatement::Defer>();utility::Span const& span = __jakt_match_value.span;
return JaktInternal::ExplicitValue(span);
};/*case end*/
case 2: {
auto&& __jakt_match_value = __jakt_match_variant.template get<parser::ParsedStatement::UnsafeBlock>();utility::Span const& span = __jakt_match_value.span;
return JaktInternal::ExplicitValue(span);
};/*case end*/
case 3: {
auto&& __jakt_match_value = __jakt_match_variant.template get<parser::ParsedStatement::DestructuringAssignment>();utility::Span const& span = __jakt_match_value.span;
return JaktInternal::ExplicitValue(span);
};/*case end*/
case 4: {
auto&& __jakt_match_value = __jakt_match_variant.template get<parser::ParsedStatement::VarDecl>();utility::Span const& span = __jakt_match_value.span;
return JaktInternal::ExplicitValue(span);
};/*case end*/
case 5: {
auto&& __jakt_match_value = __jakt_match_variant.template get<parser::ParsedStatement::If>();utility::Span const& span = __jakt_match_value.span;
return JaktInternal::ExplicitValue(span);
};/*case end*/
case 6: {
auto&& __jakt_match_value = __jakt_match_variant.template get<parser::ParsedStatement::Block>();utility::Span const& span = __jakt_match_value.span;
return JaktInternal::ExplicitValue(span);
};/*case end*/
case 7: {
auto&& __jakt_match_value = __jakt_match_variant.template get<parser::ParsedStatement::Loop>();utility::Span const& span = __jakt_match_value.span;
return JaktInternal::ExplicitValue(span);
};/*case end*/
case 8: {
auto&& __jakt_match_value = __jakt_match_variant.template get<parser::ParsedStatement::While>();utility::Span const& span = __jakt_match_value.span;
return JaktInternal::ExplicitValue(span);
};/*case end*/
case 9: {
auto&& __jakt_match_value = __jakt_match_variant.template get<parser::ParsedStatement::For>();utility::Span const& span = __jakt_match_value.span;
return JaktInternal::ExplicitValue(span);
};/*case end*/
case 10: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename parser::ParsedStatement::Break>();
utility::Span const& span = __jakt_match_value.value;
return JaktInternal::ExplicitValue(span);
};/*case end*/
case 11: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename parser::ParsedStatement::Continue>();
utility::Span const& span = __jakt_match_value.value;
return JaktInternal::ExplicitValue(span);
};/*case end*/
case 12: {
auto&& __jakt_match_value = __jakt_match_variant.template get<parser::ParsedStatement::Return>();utility::Span const& span = __jakt_match_value.span;
return JaktInternal::ExplicitValue(span);
};/*case end*/
case 13: {
auto&& __jakt_match_value = __jakt_match_variant.template get<parser::ParsedStatement::Throw>();utility::Span const& span = __jakt_match_value.span;
return JaktInternal::ExplicitValue(span);
};/*case end*/
case 14: {
auto&& __jakt_match_value = __jakt_match_variant.template get<parser::ParsedStatement::Yield>();utility::Span const& span = __jakt_match_value.span;
return JaktInternal::ExplicitValue(span);
};/*case end*/
case 15: {
auto&& __jakt_match_value = __jakt_match_variant.template get<parser::ParsedStatement::InlineCpp>();utility::Span const& span = __jakt_match_value.span;
return JaktInternal::ExplicitValue(span);
};/*case end*/
case 16: {
auto&& __jakt_match_value = __jakt_match_variant.template get<parser::ParsedStatement::Guard>();utility::Span const& span = __jakt_match_value.span;
return JaktInternal::ExplicitValue(span);
};/*case end*/
case 17: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename parser::ParsedStatement::Garbage>();
utility::Span const& span = __jakt_match_value.value;
return JaktInternal::ExplicitValue(span);
};/*case end*/
default: VERIFY_NOT_REACHED();}/*switch end*/
}()
)));
}
}

ErrorOr<DeprecatedString> parser::ParsedMatchPattern::debug_description() const {
auto builder = TRY(DeprecatedStringBuilder::create());
switch (this->index()) {case 0 /* EnumVariant */: {
[[maybe_unused]] auto const& that = this->template get<ParsedMatchPattern::EnumVariant>();
TRY(builder.append("ParsedMatchPattern::EnumVariant"sv));
TRY(builder.append("("sv));
{
JaktInternal::PrettyPrint::ScopedLevelIncrease increase_indent {};
TRY(JaktInternal::PrettyPrint::output_indentation(builder));
TRY(builder.appendff("defaults: {}", that.defaults));
TRY(builder.append(", "sv));
TRY(JaktInternal::PrettyPrint::output_indentation(builder));
TRY(builder.appendff("variant_names: {}", that.variant_names));
TRY(builder.append(", "sv));
TRY(JaktInternal::PrettyPrint::output_indentation(builder));
TRY(builder.appendff("variant_arguments: {}", that.variant_arguments));
TRY(builder.append(", "sv));
TRY(JaktInternal::PrettyPrint::output_indentation(builder));
TRY(builder.appendff("arguments_span: {}", that.arguments_span));
}
TRY(builder.append(")"sv));
break;}
case 1 /* Expression */: {
[[maybe_unused]] auto const& that = this->template get<ParsedMatchPattern::Expression>();
TRY(builder.append("ParsedMatchPattern::Expression"sv));
TRY(builder.appendff("({})", that.value));
break;}
case 2 /* CatchAll */: {
[[maybe_unused]] auto const& that = this->template get<ParsedMatchPattern::CatchAll>();
TRY(builder.append("ParsedMatchPattern::CatchAll"sv));
TRY(builder.append("("sv));
{
JaktInternal::PrettyPrint::ScopedLevelIncrease increase_indent {};
TRY(JaktInternal::PrettyPrint::output_indentation(builder));
TRY(builder.appendff("defaults: {}", that.defaults));
TRY(builder.append(", "sv));
TRY(JaktInternal::PrettyPrint::output_indentation(builder));
TRY(builder.appendff("variant_arguments: {}", that.variant_arguments));
TRY(builder.append(", "sv));
TRY(JaktInternal::PrettyPrint::output_indentation(builder));
TRY(builder.appendff("arguments_span: {}", that.arguments_span));
}
TRY(builder.append(")"sv));
break;}
case 3 /* Invalid */: {
[[maybe_unused]] auto const& that = this->template get<ParsedMatchPattern::Invalid>();
TRY(builder.append("ParsedMatchPattern::Invalid"sv));
break;}
}
return builder.to_string();
}
bool parser::ParsedMatchPattern::equals(parser::ParsedMatchPattern const rhs_parsed_match_pattern) const {
{
if (((*this).is_equal_pattern(rhs_parsed_match_pattern))){
if (((*this).defaults_equal(((rhs_parsed_match_pattern).defaults())))){
if (((*this).index() == 0 /* EnumVariant */)){
JaktInternal::DynamicArray<parser::EnumVariantPatternArgument> const lhs_variant_arguments = ((*this).get<parser::ParsedMatchPattern::EnumVariant>()).variant_arguments;
if (((rhs_parsed_match_pattern).index() == 0 /* EnumVariant */)){
JaktInternal::DynamicArray<parser::EnumVariantPatternArgument> const rhs_variant_arguments = ((rhs_parsed_match_pattern).get<parser::ParsedMatchPattern::EnumVariant>()).variant_arguments;
if ((((lhs_variant_arguments).size()) == ((rhs_variant_arguments).size()))){
{
JaktInternal::Range<size_t> _magic = (JaktInternal::Range<size_t>{static_cast<size_t>(0LL),static_cast<size_t>(((lhs_variant_arguments).size()))});
for (;;){
JaktInternal::Optional<size_t> _magic_value = ((_magic).next());
if ((!(((_magic_value).has_value())))){
break;
}
size_t i = (_magic_value.value());
{
if ((!(((((lhs_variant_arguments)[i])).equals(((rhs_variant_arguments)[i])))))){
return (false);
}
}

}
}

}
else {
return (false);
}

}
else {
return (false);
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
}

bool parser::ParsedMatchPattern::is_equal_pattern(parser::ParsedMatchPattern const rhs_parsed_match_pattern) const {
{
return (JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<bool, bool>{
auto&& __jakt_match_variant = *this;
switch(__jakt_match_variant.index()) {
case 0: {
auto&& __jakt_match_value = __jakt_match_variant.template get<parser::ParsedMatchPattern::EnumVariant>();JaktInternal::DynamicArray<JaktInternal::Tuple<DeprecatedString,utility::Span>> const& lhs_variant_names = __jakt_match_value.variant_names;
{
if (((rhs_parsed_match_pattern).index() == 0 /* EnumVariant */)){
JaktInternal::DynamicArray<JaktInternal::Tuple<DeprecatedString,utility::Span>> const rhs_variant_names = ((rhs_parsed_match_pattern).get<parser::ParsedMatchPattern::EnumVariant>()).variant_names;
size_t namespace_count = ((lhs_variant_names).size());
if ((((rhs_variant_names).size()) < namespace_count)){
(namespace_count = ((rhs_variant_names).size()));
}
{
JaktInternal::Range<size_t> _magic = (JaktInternal::Range<size_t>{static_cast<size_t>(static_cast<size_t>(0ULL)),static_cast<size_t>(namespace_count)});
for (;;){
JaktInternal::Optional<size_t> _magic_value = ((_magic).next());
if ((!(((_magic_value).has_value())))){
break;
}
size_t i = (_magic_value.value());
{
DeprecatedString const lhs_name = ((((lhs_variant_names)[(JaktInternal::checked_sub<size_t>((JaktInternal::checked_sub<size_t>(((lhs_variant_names).size()),i)),static_cast<size_t>(1ULL)))])).template get<0>());
DeprecatedString const rhs_name = ((((rhs_variant_names)[(JaktInternal::checked_sub<size_t>((JaktInternal::checked_sub<size_t>(((rhs_variant_names).size()),i)),static_cast<size_t>(1ULL)))])).template get<0>());
if ((lhs_name == rhs_name)){
}
else {
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
};/*case end*/
case 1: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename parser::ParsedMatchPattern::Expression>();
NonnullRefPtr<typename parser::ParsedExpression> const& lhs_parsed_expression = __jakt_match_value.value;
return JaktInternal::ExplicitValue(JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<bool, bool>{
auto&& __jakt_match_variant = rhs_parsed_match_pattern;
switch(__jakt_match_variant.index()) {
case 1: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename parser::ParsedMatchPattern::Expression>();
NonnullRefPtr<typename parser::ParsedExpression> const& rhs_parsed_expression = __jakt_match_value.value;
return JaktInternal::ExplicitValue(((lhs_parsed_expression)->equals(rhs_parsed_expression)));
};/*case end*/
default: {
return JaktInternal::ExplicitValue(false);
};/*case end*/
}/*switch end*/
}()
)));
};/*case end*/
case 2: {
auto&& __jakt_match_value = __jakt_match_variant.template get<parser::ParsedMatchPattern::CatchAll>();return JaktInternal::ExplicitValue(((rhs_parsed_match_pattern).index() == 2 /* CatchAll */));
};/*case end*/
case 3: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename parser::ParsedMatchPattern::Invalid>();
return JaktInternal::ExplicitValue(((rhs_parsed_match_pattern).index() == 3 /* Invalid */));
};/*case end*/
default: VERIFY_NOT_REACHED();}/*switch end*/
}()
)));
}
}

bool parser::ParsedMatchPattern::defaults_equal(JaktInternal::Dictionary<DeprecatedString,parser::ParsedPatternDefault> const defaults) const {
{
if ((((defaults).size()) != ((((*this).defaults())).size()))){
return (false);
}
{
JaktInternal::DictionaryIterator<DeprecatedString,parser::ParsedPatternDefault> _magic = ((((*this).defaults())).iterator());
for (;;){
JaktInternal::Optional<JaktInternal::Tuple<DeprecatedString,parser::ParsedPatternDefault>> _magic_value = ((_magic).next());
if ((!(((_magic_value).has_value())))){
break;
}
JaktInternal::Tuple<DeprecatedString,parser::ParsedPatternDefault> name__default___ = (_magic_value.value());
{
JaktInternal::Tuple<DeprecatedString,parser::ParsedPatternDefault> const jakt__name__default___ = name__default___;
DeprecatedString const name = ((jakt__name__default___).template get<0>());
parser::ParsedPatternDefault const default_ = ((jakt__name__default___).template get<1>());

JaktInternal::Optional<parser::ParsedPatternDefault> const matching = ((defaults).get(name));
if ((!(((matching).has_value())))){
return (false);
}
if ((!((((((matching.value())).value))->equals(((default_).value)))))){
return (false);
}
if (((((((matching.value())).variable)).is_mutable) != ((((default_).variable)).is_mutable))){
return (false);
}
}

}
}

return (true);
}
}

ErrorOr<DeprecatedString> parser::FunctionLinkage::debug_description() const {
auto builder = TRY(DeprecatedStringBuilder::create());
switch (this->index()) {case 0 /* Internal */: {
[[maybe_unused]] auto const& that = this->template get<FunctionLinkage::Internal>();
TRY(builder.append("FunctionLinkage::Internal"sv));
break;}
case 1 /* External */: {
[[maybe_unused]] auto const& that = this->template get<FunctionLinkage::External>();
TRY(builder.append("FunctionLinkage::External"sv));
break;}
}
return builder.to_string();
}
ErrorOr<DeprecatedString> parser::ImportName::debug_description() const {
auto builder = TRY(DeprecatedStringBuilder::create());
switch (this->index()) {case 0 /* Literal */: {
[[maybe_unused]] auto const& that = this->template get<ImportName::Literal>();
TRY(builder.append("ImportName::Literal"sv));
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
case 1 /* Comptime */: {
[[maybe_unused]] auto const& that = this->template get<ImportName::Comptime>();
TRY(builder.append("ImportName::Comptime"sv));
TRY(builder.append("("sv));
{
JaktInternal::PrettyPrint::ScopedLevelIncrease increase_indent {};
TRY(JaktInternal::PrettyPrint::output_indentation(builder));
TRY(builder.appendff("expression: {}", that.expression));
}
TRY(builder.append(")"sv));
break;}
}
return builder.to_string();
}
DeprecatedString parser::ImportName::literal_name() const {
{
if (((*this).index() == 0 /* Literal */)){
DeprecatedString const name = ((*this).get<parser::ImportName::Literal>()).name;
return (name);
}
else {
utility::panic(Jakt::DeprecatedString("Cannot get literal name of non-literal import name"sv));
}

}
}

bool parser::ImportName::equals(parser::ImportName const other) const {
{
return (JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<bool, bool>{
auto&& __jakt_match_variant = *this;
switch(__jakt_match_variant.index()) {
case 0: {
auto&& __jakt_match_value = __jakt_match_variant.template get<parser::ImportName::Literal>();DeprecatedString const& name = __jakt_match_value.name;
return JaktInternal::ExplicitValue(JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<bool, bool>{
auto&& __jakt_match_variant = other;
switch(__jakt_match_variant.index()) {
case 0: {
auto&& __jakt_match_value = __jakt_match_variant.template get<parser::ImportName::Literal>();DeprecatedString const& other_name = __jakt_match_value.name;
return JaktInternal::ExplicitValue((name == other_name));
};/*case end*/
default: {
return JaktInternal::ExplicitValue(false);
};/*case end*/
}/*switch end*/
}()
)));
};/*case end*/
case 1: {
auto&& __jakt_match_value = __jakt_match_variant.template get<parser::ImportName::Comptime>();NonnullRefPtr<typename parser::ParsedExpression> const& expression = __jakt_match_value.expression;
return JaktInternal::ExplicitValue(JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<bool, bool>{
auto&& __jakt_match_variant = other;
switch(__jakt_match_variant.index()) {
case 1: {
auto&& __jakt_match_value = __jakt_match_variant.template get<parser::ImportName::Comptime>();NonnullRefPtr<typename parser::ParsedExpression> const& other_expression = __jakt_match_value.expression;
return JaktInternal::ExplicitValue(((expression)->equals(other_expression)));
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

utility::Span parser::ImportName::span() const {
{
return (JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<utility::Span, utility::Span>{
auto&& __jakt_match_variant = *this;
switch(__jakt_match_variant.index()) {
case 0: {
auto&& __jakt_match_value = __jakt_match_variant.template get<parser::ImportName::Literal>();utility::Span const& span = __jakt_match_value.span;
return JaktInternal::ExplicitValue(span);
};/*case end*/
case 1: {
auto&& __jakt_match_value = __jakt_match_variant.template get<parser::ImportName::Comptime>();NonnullRefPtr<typename parser::ParsedExpression> const& expression = __jakt_match_value.expression;
{
return (((expression)->span()));
}
};/*case end*/
default: VERIFY_NOT_REACHED();}/*switch end*/
}()
)));
}
}

ErrorOr<DeprecatedString> parser::ParsedMatchBody::debug_description() const {
auto builder = TRY(DeprecatedStringBuilder::create());
switch (this->index()) {case 0 /* Expression */: {
[[maybe_unused]] auto const& that = this->template get<ParsedMatchBody::Expression>();
TRY(builder.append("ParsedMatchBody::Expression"sv));
TRY(builder.appendff("({})", that.value));
break;}
case 1 /* Block */: {
[[maybe_unused]] auto const& that = this->template get<ParsedMatchBody::Block>();
TRY(builder.append("ParsedMatchBody::Block"sv));
TRY(builder.appendff("({})", that.value));
break;}
}
return builder.to_string();
}
bool parser::ParsedMatchBody::equals(parser::ParsedMatchBody const rhs_match_body) const {
{
return (JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<bool, bool>{
auto&& __jakt_match_variant = *this;
switch(__jakt_match_variant.index()) {
case 0: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename parser::ParsedMatchBody::Expression>();
NonnullRefPtr<typename parser::ParsedExpression> const& lhs_expr = __jakt_match_value.value;
return JaktInternal::ExplicitValue(({ Optional<bool> __jakt_var_115; {
__jakt_var_115 = JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<bool,bool>{
auto __jakt_enum_value = (((rhs_match_body).index() == 0 /* Expression */));
if (__jakt_enum_value == true) {
return JaktInternal::ExplicitValue(({ Optional<bool> __jakt_var_116; {
NonnullRefPtr<typename parser::ParsedExpression> const rhs_expr = ((rhs_match_body).get<parser::ParsedMatchBody::Expression>()).value;
__jakt_var_116 = ((lhs_expr)->equals(rhs_expr)); goto __jakt_label_113;

}
__jakt_label_113:; __jakt_var_116.release_value(); }));
}
else {
{
return (false);
}
}
}()))
; goto __jakt_label_112;

}
__jakt_label_112:; __jakt_var_115.release_value(); }));
};/*case end*/
case 1: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename parser::ParsedMatchBody::Block>();
parser::ParsedBlock const& lhs_block = __jakt_match_value.value;
return JaktInternal::ExplicitValue(({ Optional<bool> __jakt_var_117; {
__jakt_var_117 = JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<bool,bool>{
auto __jakt_enum_value = (((rhs_match_body).index() == 1 /* Block */));
if (__jakt_enum_value == true) {
return JaktInternal::ExplicitValue(({ Optional<bool> __jakt_var_118; {
parser::ParsedBlock const rhs_block = ((rhs_match_body).get<parser::ParsedMatchBody::Block>()).value;
__jakt_var_118 = ((lhs_block).equals(rhs_block)); goto __jakt_label_115;

}
__jakt_label_115:; __jakt_var_118.release_value(); }));
}
else {
{
return (false);
}
}
}()))
; goto __jakt_label_114;

}
__jakt_label_114:; __jakt_var_117.release_value(); }));
};/*case end*/
default: VERIFY_NOT_REACHED();}/*switch end*/
}()
)));
}
}

ErrorOr<DeprecatedString> parser::DefinitionLinkage::debug_description() const {
auto builder = TRY(DeprecatedStringBuilder::create());
switch (this->index()) {case 0 /* Internal */: {
[[maybe_unused]] auto const& that = this->template get<DefinitionLinkage::Internal>();
TRY(builder.append("DefinitionLinkage::Internal"sv));
break;}
case 1 /* External */: {
[[maybe_unused]] auto const& that = this->template get<DefinitionLinkage::External>();
TRY(builder.append("DefinitionLinkage::External"sv));
break;}
}
return builder.to_string();
}
ErrorOr<DeprecatedString> parser::RecordType::debug_description() const {
auto builder = TRY(DeprecatedStringBuilder::create());
switch (this->index()) {case 0 /* Struct */: {
[[maybe_unused]] auto const& that = this->template get<RecordType::Struct>();
TRY(builder.append("RecordType::Struct"sv));
TRY(builder.append("("sv));
{
JaktInternal::PrettyPrint::ScopedLevelIncrease increase_indent {};
TRY(JaktInternal::PrettyPrint::output_indentation(builder));
TRY(builder.appendff("fields: {}", that.fields));
TRY(builder.append(", "sv));
TRY(JaktInternal::PrettyPrint::output_indentation(builder));
TRY(builder.appendff("super_type: {}", that.super_type));
}
TRY(builder.append(")"sv));
break;}
case 1 /* Class */: {
[[maybe_unused]] auto const& that = this->template get<RecordType::Class>();
TRY(builder.append("RecordType::Class"sv));
TRY(builder.append("("sv));
{
JaktInternal::PrettyPrint::ScopedLevelIncrease increase_indent {};
TRY(JaktInternal::PrettyPrint::output_indentation(builder));
TRY(builder.appendff("fields: {}", that.fields));
TRY(builder.append(", "sv));
TRY(JaktInternal::PrettyPrint::output_indentation(builder));
TRY(builder.appendff("super_type: {}", that.super_type));
}
TRY(builder.append(")"sv));
break;}
case 2 /* ValueEnum */: {
[[maybe_unused]] auto const& that = this->template get<RecordType::ValueEnum>();
TRY(builder.append("RecordType::ValueEnum"sv));
TRY(builder.append("("sv));
{
JaktInternal::PrettyPrint::ScopedLevelIncrease increase_indent {};
TRY(JaktInternal::PrettyPrint::output_indentation(builder));
TRY(builder.appendff("underlying_type: {}", that.underlying_type));
TRY(builder.append(", "sv));
TRY(JaktInternal::PrettyPrint::output_indentation(builder));
TRY(builder.appendff("variants: {}", that.variants));
}
TRY(builder.append(")"sv));
break;}
case 3 /* SumEnum */: {
[[maybe_unused]] auto const& that = this->template get<RecordType::SumEnum>();
TRY(builder.append("RecordType::SumEnum"sv));
TRY(builder.append("("sv));
{
JaktInternal::PrettyPrint::ScopedLevelIncrease increase_indent {};
TRY(JaktInternal::PrettyPrint::output_indentation(builder));
TRY(builder.appendff("is_boxed: {}", that.is_boxed));
TRY(builder.append(", "sv));
TRY(JaktInternal::PrettyPrint::output_indentation(builder));
TRY(builder.appendff("fields: {}", that.fields));
TRY(builder.append(", "sv));
TRY(JaktInternal::PrettyPrint::output_indentation(builder));
TRY(builder.appendff("variants: {}", that.variants));
}
TRY(builder.append(")"sv));
break;}
case 4 /* Garbage */: {
[[maybe_unused]] auto const& that = this->template get<RecordType::Garbage>();
TRY(builder.append("RecordType::Garbage"sv));
break;}
}
return builder.to_string();
}
DeprecatedString parser::RecordType::record_type_name() const {
{
return (JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<DeprecatedString, DeprecatedString>{
auto&& __jakt_match_variant = *this;
switch(__jakt_match_variant.index()) {
case 0: {
auto&& __jakt_match_value = __jakt_match_variant.template get<parser::RecordType::Struct>();return JaktInternal::ExplicitValue(Jakt::DeprecatedString("struct"sv));
};/*case end*/
case 1: {
auto&& __jakt_match_value = __jakt_match_variant.template get<parser::RecordType::Class>();return JaktInternal::ExplicitValue(Jakt::DeprecatedString("class"sv));
};/*case end*/
case 2: {
auto&& __jakt_match_value = __jakt_match_variant.template get<parser::RecordType::ValueEnum>();return JaktInternal::ExplicitValue(Jakt::DeprecatedString("value enum"sv));
};/*case end*/
case 3: {
auto&& __jakt_match_value = __jakt_match_variant.template get<parser::RecordType::SumEnum>();return JaktInternal::ExplicitValue(Jakt::DeprecatedString("sum enum"sv));
};/*case end*/
case 4: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename parser::RecordType::Garbage>();
return JaktInternal::ExplicitValue(Jakt::DeprecatedString("<garbage record type>"sv));
};/*case end*/
default: VERIFY_NOT_REACHED();}/*switch end*/
}()
)));
}
}

ErrorOr<DeprecatedString> parser::Visibility::debug_description() const {
auto builder = TRY(DeprecatedStringBuilder::create());
switch (this->index()) {case 0 /* Public */: {
[[maybe_unused]] auto const& that = this->template get<Visibility::Public>();
TRY(builder.append("Visibility::Public"sv));
break;}
case 1 /* Private */: {
[[maybe_unused]] auto const& that = this->template get<Visibility::Private>();
TRY(builder.append("Visibility::Private"sv));
break;}
case 2 /* Restricted */: {
[[maybe_unused]] auto const& that = this->template get<Visibility::Restricted>();
TRY(builder.append("Visibility::Restricted"sv));
TRY(builder.append("("sv));
{
JaktInternal::PrettyPrint::ScopedLevelIncrease increase_indent {};
TRY(JaktInternal::PrettyPrint::output_indentation(builder));
TRY(builder.appendff("whitelist: {}", that.whitelist));
TRY(builder.append(", "sv));
TRY(JaktInternal::PrettyPrint::output_indentation(builder));
TRY(builder.appendff("span: {}", that.span));
}
TRY(builder.append(")"sv));
break;}
}
return builder.to_string();
}
ErrorOr<DeprecatedString> parser::ParsedType::debug_description() const {
auto builder = TRY(DeprecatedStringBuilder::create());
switch (this->index()) {case 0 /* Name */: {
[[maybe_unused]] auto const& that = this->template get<ParsedType::Name>();
TRY(builder.append("ParsedType::Name"sv));
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
case 1 /* NamespacedName */: {
[[maybe_unused]] auto const& that = this->template get<ParsedType::NamespacedName>();
TRY(builder.append("ParsedType::NamespacedName"sv));
TRY(builder.append("("sv));
{
JaktInternal::PrettyPrint::ScopedLevelIncrease increase_indent {};
TRY(JaktInternal::PrettyPrint::output_indentation(builder));
TRY(builder.appendff("name: \"{}\"", that.name));
TRY(builder.append(", "sv));
TRY(JaktInternal::PrettyPrint::output_indentation(builder));
TRY(builder.appendff("namespaces: {}", that.namespaces));
TRY(builder.append(", "sv));
TRY(JaktInternal::PrettyPrint::output_indentation(builder));
TRY(builder.appendff("params: {}", that.params));
TRY(builder.append(", "sv));
TRY(JaktInternal::PrettyPrint::output_indentation(builder));
TRY(builder.appendff("span: {}", that.span));
}
TRY(builder.append(")"sv));
break;}
case 2 /* GenericType */: {
[[maybe_unused]] auto const& that = this->template get<ParsedType::GenericType>();
TRY(builder.append("ParsedType::GenericType"sv));
TRY(builder.append("("sv));
{
JaktInternal::PrettyPrint::ScopedLevelIncrease increase_indent {};
TRY(JaktInternal::PrettyPrint::output_indentation(builder));
TRY(builder.appendff("name: \"{}\"", that.name));
TRY(builder.append(", "sv));
TRY(JaktInternal::PrettyPrint::output_indentation(builder));
TRY(builder.appendff("generic_parameters: {}", that.generic_parameters));
TRY(builder.append(", "sv));
TRY(JaktInternal::PrettyPrint::output_indentation(builder));
TRY(builder.appendff("span: {}", that.span));
}
TRY(builder.append(")"sv));
break;}
case 3 /* JaktArray */: {
[[maybe_unused]] auto const& that = this->template get<ParsedType::JaktArray>();
TRY(builder.append("ParsedType::JaktArray"sv));
TRY(builder.append("("sv));
{
JaktInternal::PrettyPrint::ScopedLevelIncrease increase_indent {};
TRY(JaktInternal::PrettyPrint::output_indentation(builder));
TRY(builder.appendff("inner: {}", that.inner));
TRY(builder.append(", "sv));
TRY(JaktInternal::PrettyPrint::output_indentation(builder));
TRY(builder.appendff("span: {}", that.span));
}
TRY(builder.append(")"sv));
break;}
case 4 /* Dictionary */: {
[[maybe_unused]] auto const& that = this->template get<ParsedType::Dictionary>();
TRY(builder.append("ParsedType::Dictionary"sv));
TRY(builder.append("("sv));
{
JaktInternal::PrettyPrint::ScopedLevelIncrease increase_indent {};
TRY(JaktInternal::PrettyPrint::output_indentation(builder));
TRY(builder.appendff("key: {}", that.key));
TRY(builder.append(", "sv));
TRY(JaktInternal::PrettyPrint::output_indentation(builder));
TRY(builder.appendff("value: {}", that.value));
TRY(builder.append(", "sv));
TRY(JaktInternal::PrettyPrint::output_indentation(builder));
TRY(builder.appendff("span: {}", that.span));
}
TRY(builder.append(")"sv));
break;}
case 5 /* JaktTuple */: {
[[maybe_unused]] auto const& that = this->template get<ParsedType::JaktTuple>();
TRY(builder.append("ParsedType::JaktTuple"sv));
TRY(builder.append("("sv));
{
JaktInternal::PrettyPrint::ScopedLevelIncrease increase_indent {};
TRY(JaktInternal::PrettyPrint::output_indentation(builder));
TRY(builder.appendff("types: {}", that.types));
TRY(builder.append(", "sv));
TRY(JaktInternal::PrettyPrint::output_indentation(builder));
TRY(builder.appendff("span: {}", that.span));
}
TRY(builder.append(")"sv));
break;}
case 6 /* Set */: {
[[maybe_unused]] auto const& that = this->template get<ParsedType::Set>();
TRY(builder.append("ParsedType::Set"sv));
TRY(builder.append("("sv));
{
JaktInternal::PrettyPrint::ScopedLevelIncrease increase_indent {};
TRY(JaktInternal::PrettyPrint::output_indentation(builder));
TRY(builder.appendff("inner: {}", that.inner));
TRY(builder.append(", "sv));
TRY(JaktInternal::PrettyPrint::output_indentation(builder));
TRY(builder.appendff("span: {}", that.span));
}
TRY(builder.append(")"sv));
break;}
case 7 /* Optional */: {
[[maybe_unused]] auto const& that = this->template get<ParsedType::Optional>();
TRY(builder.append("ParsedType::Optional"sv));
TRY(builder.append("("sv));
{
JaktInternal::PrettyPrint::ScopedLevelIncrease increase_indent {};
TRY(JaktInternal::PrettyPrint::output_indentation(builder));
TRY(builder.appendff("inner: {}", that.inner));
TRY(builder.append(", "sv));
TRY(JaktInternal::PrettyPrint::output_indentation(builder));
TRY(builder.appendff("span: {}", that.span));
}
TRY(builder.append(")"sv));
break;}
case 8 /* Reference */: {
[[maybe_unused]] auto const& that = this->template get<ParsedType::Reference>();
TRY(builder.append("ParsedType::Reference"sv));
TRY(builder.append("("sv));
{
JaktInternal::PrettyPrint::ScopedLevelIncrease increase_indent {};
TRY(JaktInternal::PrettyPrint::output_indentation(builder));
TRY(builder.appendff("inner: {}", that.inner));
TRY(builder.append(", "sv));
TRY(JaktInternal::PrettyPrint::output_indentation(builder));
TRY(builder.appendff("span: {}", that.span));
}
TRY(builder.append(")"sv));
break;}
case 9 /* MutableReference */: {
[[maybe_unused]] auto const& that = this->template get<ParsedType::MutableReference>();
TRY(builder.append("ParsedType::MutableReference"sv));
TRY(builder.append("("sv));
{
JaktInternal::PrettyPrint::ScopedLevelIncrease increase_indent {};
TRY(JaktInternal::PrettyPrint::output_indentation(builder));
TRY(builder.appendff("inner: {}", that.inner));
TRY(builder.append(", "sv));
TRY(JaktInternal::PrettyPrint::output_indentation(builder));
TRY(builder.appendff("span: {}", that.span));
}
TRY(builder.append(")"sv));
break;}
case 10 /* RawPtr */: {
[[maybe_unused]] auto const& that = this->template get<ParsedType::RawPtr>();
TRY(builder.append("ParsedType::RawPtr"sv));
TRY(builder.append("("sv));
{
JaktInternal::PrettyPrint::ScopedLevelIncrease increase_indent {};
TRY(JaktInternal::PrettyPrint::output_indentation(builder));
TRY(builder.appendff("inner: {}", that.inner));
TRY(builder.append(", "sv));
TRY(JaktInternal::PrettyPrint::output_indentation(builder));
TRY(builder.appendff("span: {}", that.span));
}
TRY(builder.append(")"sv));
break;}
case 11 /* WeakPtr */: {
[[maybe_unused]] auto const& that = this->template get<ParsedType::WeakPtr>();
TRY(builder.append("ParsedType::WeakPtr"sv));
TRY(builder.append("("sv));
{
JaktInternal::PrettyPrint::ScopedLevelIncrease increase_indent {};
TRY(JaktInternal::PrettyPrint::output_indentation(builder));
TRY(builder.appendff("inner: {}", that.inner));
TRY(builder.append(", "sv));
TRY(JaktInternal::PrettyPrint::output_indentation(builder));
TRY(builder.appendff("span: {}", that.span));
}
TRY(builder.append(")"sv));
break;}
case 12 /* Function */: {
[[maybe_unused]] auto const& that = this->template get<ParsedType::Function>();
TRY(builder.append("ParsedType::Function"sv));
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
TRY(builder.appendff("return_type: {}", that.return_type));
TRY(builder.append(", "sv));
TRY(JaktInternal::PrettyPrint::output_indentation(builder));
TRY(builder.appendff("span: {}", that.span));
}
TRY(builder.append(")"sv));
break;}
case 13 /* Empty */: {
[[maybe_unused]] auto const& that = this->template get<ParsedType::Empty>();
TRY(builder.append("ParsedType::Empty"sv));
break;}
}
return builder.to_string();
}
bool parser::ParsedType::equals(NonnullRefPtr<typename parser::ParsedType> const rhs_parsed_type) const {
{
return (JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<bool, bool>{
auto&& __jakt_match_variant = *this;
switch(__jakt_match_variant.index()) {
case 0: {
auto&& __jakt_match_value = __jakt_match_variant.template get<parser::ParsedType::Name>();DeprecatedString const& lhs_name = __jakt_match_value.name;
return JaktInternal::ExplicitValue(JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<bool, bool>{
auto&& __jakt_match_variant = *rhs_parsed_type;
switch(__jakt_match_variant.index()) {
case 0: {
auto&& __jakt_match_value = __jakt_match_variant.template get<parser::ParsedType::Name>();DeprecatedString const& rhs_name = __jakt_match_value.name;
return JaktInternal::ExplicitValue((lhs_name == rhs_name));
};/*case end*/
default: {
return JaktInternal::ExplicitValue(false);
};/*case end*/
}/*switch end*/
}()
)));
};/*case end*/
case 1: {
auto&& __jakt_match_value = __jakt_match_variant.template get<parser::ParsedType::NamespacedName>();DeprecatedString const& lhs_name = __jakt_match_value.name;
JaktInternal::DynamicArray<DeprecatedString> const& lhs_namespaces = __jakt_match_value.namespaces;
JaktInternal::DynamicArray<NonnullRefPtr<typename parser::ParsedType>> const& lhs_params = __jakt_match_value.params;
return JaktInternal::ExplicitValue(JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<bool, bool>{
auto&& __jakt_match_variant = *rhs_parsed_type;
switch(__jakt_match_variant.index()) {
case 1: {
auto&& __jakt_match_value = __jakt_match_variant.template get<parser::ParsedType::NamespacedName>();DeprecatedString const& rhs_name = __jakt_match_value.name;
JaktInternal::DynamicArray<DeprecatedString> const& rhs_namespaces = __jakt_match_value.namespaces;
JaktInternal::DynamicArray<NonnullRefPtr<typename parser::ParsedType>> const& rhs_params = __jakt_match_value.params;
{
if ((lhs_name != rhs_name)){
return (false);
}
if ((((lhs_namespaces).size()) != ((rhs_namespaces).size()))){
return (false);
}
{
JaktInternal::Range<size_t> _magic = (JaktInternal::Range<size_t>{static_cast<size_t>(static_cast<size_t>(0ULL)),static_cast<size_t>(((lhs_namespaces).size()))});
for (;;){
JaktInternal::Optional<size_t> _magic_value = ((_magic).next());
if ((!(((_magic_value).has_value())))){
break;
}
size_t namespace_index = (_magic_value.value());
{
if ((((lhs_namespaces)[namespace_index]) != ((rhs_namespaces)[namespace_index]))){
return (false);
}
}

}
}

if ((((lhs_params).size()) != ((rhs_params).size()))){
return (false);
}
{
JaktInternal::Range<size_t> _magic = (JaktInternal::Range<size_t>{static_cast<size_t>(static_cast<size_t>(0ULL)),static_cast<size_t>(((lhs_params).size()))});
for (;;){
JaktInternal::Optional<size_t> _magic_value = ((_magic).next());
if ((!(((_magic_value).has_value())))){
break;
}
size_t param_index = (_magic_value.value());
{
if ((!(((((lhs_params)[param_index]))->equals(((rhs_params)[param_index])))))){
return (false);
}
}

}
}

return (true);
}
};/*case end*/
default: {
return JaktInternal::ExplicitValue(false);
};/*case end*/
}/*switch end*/
}()
)));
};/*case end*/
case 2: {
auto&& __jakt_match_value = __jakt_match_variant.template get<parser::ParsedType::GenericType>();DeprecatedString const& lhs_name = __jakt_match_value.name;
JaktInternal::DynamicArray<NonnullRefPtr<typename parser::ParsedType>> const& lhs_generic_parameters = __jakt_match_value.generic_parameters;
return JaktInternal::ExplicitValue(JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<bool, bool>{
auto&& __jakt_match_variant = *rhs_parsed_type;
switch(__jakt_match_variant.index()) {
case 2: {
auto&& __jakt_match_value = __jakt_match_variant.template get<parser::ParsedType::GenericType>();DeprecatedString const& rhs_name = __jakt_match_value.name;
JaktInternal::DynamicArray<NonnullRefPtr<typename parser::ParsedType>> const& rhs_generic_parameters = __jakt_match_value.generic_parameters;
{
if ((lhs_name != rhs_name)){
return (false);
}
if ((((lhs_generic_parameters).size()) != ((rhs_generic_parameters).size()))){
return (false);
}
{
JaktInternal::Range<size_t> _magic = (JaktInternal::Range<size_t>{static_cast<size_t>(static_cast<size_t>(0ULL)),static_cast<size_t>(((lhs_generic_parameters).size()))});
for (;;){
JaktInternal::Optional<size_t> _magic_value = ((_magic).next());
if ((!(((_magic_value).has_value())))){
break;
}
size_t param_index = (_magic_value.value());
{
if ((!(((((lhs_generic_parameters)[param_index]))->equals(((rhs_generic_parameters)[param_index])))))){
return (false);
}
}

}
}

return (true);
}
};/*case end*/
default: {
return JaktInternal::ExplicitValue(false);
};/*case end*/
}/*switch end*/
}()
)));
};/*case end*/
case 3: {
auto&& __jakt_match_value = __jakt_match_variant.template get<parser::ParsedType::JaktArray>();NonnullRefPtr<typename parser::ParsedType> const& lhs_inner = __jakt_match_value.inner;
return JaktInternal::ExplicitValue(JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<bool, bool>{
auto&& __jakt_match_variant = *rhs_parsed_type;
switch(__jakt_match_variant.index()) {
case 3: {
auto&& __jakt_match_value = __jakt_match_variant.template get<parser::ParsedType::JaktArray>();NonnullRefPtr<typename parser::ParsedType> const& rhs_inner = __jakt_match_value.inner;
return JaktInternal::ExplicitValue(((lhs_inner)->equals(rhs_inner)));
};/*case end*/
default: {
return JaktInternal::ExplicitValue(false);
};/*case end*/
}/*switch end*/
}()
)));
};/*case end*/
case 4: {
auto&& __jakt_match_value = __jakt_match_variant.template get<parser::ParsedType::Dictionary>();NonnullRefPtr<typename parser::ParsedType> const& lhs_key = __jakt_match_value.key;
NonnullRefPtr<typename parser::ParsedType> const& lhs_value = __jakt_match_value.value;
return JaktInternal::ExplicitValue(JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<bool, bool>{
auto&& __jakt_match_variant = *rhs_parsed_type;
switch(__jakt_match_variant.index()) {
case 4: {
auto&& __jakt_match_value = __jakt_match_variant.template get<parser::ParsedType::Dictionary>();NonnullRefPtr<typename parser::ParsedType> const& rhs_key = __jakt_match_value.key;
NonnullRefPtr<typename parser::ParsedType> const& rhs_value = __jakt_match_value.value;
return JaktInternal::ExplicitValue((((lhs_key)->equals(rhs_key)) && ((lhs_value)->equals(rhs_value))));
};/*case end*/
default: {
return JaktInternal::ExplicitValue(false);
};/*case end*/
}/*switch end*/
}()
)));
};/*case end*/
case 5: {
auto&& __jakt_match_value = __jakt_match_variant.template get<parser::ParsedType::JaktTuple>();JaktInternal::DynamicArray<NonnullRefPtr<typename parser::ParsedType>> const& lhs_types = __jakt_match_value.types;
return JaktInternal::ExplicitValue(JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<bool, bool>{
auto&& __jakt_match_variant = *rhs_parsed_type;
switch(__jakt_match_variant.index()) {
case 5: {
auto&& __jakt_match_value = __jakt_match_variant.template get<parser::ParsedType::JaktTuple>();JaktInternal::DynamicArray<NonnullRefPtr<typename parser::ParsedType>> const& rhs_types = __jakt_match_value.types;
{
if ((((lhs_types).size()) != ((rhs_types).size()))){
return (false);
}
{
JaktInternal::Range<size_t> _magic = (JaktInternal::Range<size_t>{static_cast<size_t>(static_cast<size_t>(0ULL)),static_cast<size_t>(((lhs_types).size()))});
for (;;){
JaktInternal::Optional<size_t> _magic_value = ((_magic).next());
if ((!(((_magic_value).has_value())))){
break;
}
size_t type_index = (_magic_value.value());
{
if ((!(((((lhs_types)[type_index]))->equals(((rhs_types)[type_index])))))){
return (false);
}
}

}
}

return (true);
}
};/*case end*/
default: {
return JaktInternal::ExplicitValue(false);
};/*case end*/
}/*switch end*/
}()
)));
};/*case end*/
case 6: {
auto&& __jakt_match_value = __jakt_match_variant.template get<parser::ParsedType::Set>();NonnullRefPtr<typename parser::ParsedType> const& lhs_inner = __jakt_match_value.inner;
return JaktInternal::ExplicitValue(JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<bool, bool>{
auto&& __jakt_match_variant = *rhs_parsed_type;
switch(__jakt_match_variant.index()) {
case 6: {
auto&& __jakt_match_value = __jakt_match_variant.template get<parser::ParsedType::Set>();NonnullRefPtr<typename parser::ParsedType> const& rhs_inner = __jakt_match_value.inner;
return JaktInternal::ExplicitValue(((lhs_inner)->equals(rhs_inner)));
};/*case end*/
default: {
return JaktInternal::ExplicitValue(false);
};/*case end*/
}/*switch end*/
}()
)));
};/*case end*/
case 7: {
auto&& __jakt_match_value = __jakt_match_variant.template get<parser::ParsedType::Optional>();NonnullRefPtr<typename parser::ParsedType> const& lhs_inner = __jakt_match_value.inner;
return JaktInternal::ExplicitValue(JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<bool, bool>{
auto&& __jakt_match_variant = *rhs_parsed_type;
switch(__jakt_match_variant.index()) {
case 7: {
auto&& __jakt_match_value = __jakt_match_variant.template get<parser::ParsedType::Optional>();NonnullRefPtr<typename parser::ParsedType> const& rhs_inner = __jakt_match_value.inner;
return JaktInternal::ExplicitValue(((lhs_inner)->equals(rhs_inner)));
};/*case end*/
default: {
return JaktInternal::ExplicitValue(false);
};/*case end*/
}/*switch end*/
}()
)));
};/*case end*/
case 8: {
auto&& __jakt_match_value = __jakt_match_variant.template get<parser::ParsedType::Reference>();NonnullRefPtr<typename parser::ParsedType> const& lhs_inner = __jakt_match_value.inner;
return JaktInternal::ExplicitValue(JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<bool, bool>{
auto&& __jakt_match_variant = *rhs_parsed_type;
switch(__jakt_match_variant.index()) {
case 8: {
auto&& __jakt_match_value = __jakt_match_variant.template get<parser::ParsedType::Reference>();NonnullRefPtr<typename parser::ParsedType> const& rhs_inner = __jakt_match_value.inner;
return JaktInternal::ExplicitValue(((lhs_inner)->equals(rhs_inner)));
};/*case end*/
default: {
return JaktInternal::ExplicitValue(false);
};/*case end*/
}/*switch end*/
}()
)));
};/*case end*/
case 9: {
auto&& __jakt_match_value = __jakt_match_variant.template get<parser::ParsedType::MutableReference>();NonnullRefPtr<typename parser::ParsedType> const& lhs_inner = __jakt_match_value.inner;
return JaktInternal::ExplicitValue(JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<bool, bool>{
auto&& __jakt_match_variant = *rhs_parsed_type;
switch(__jakt_match_variant.index()) {
case 9: {
auto&& __jakt_match_value = __jakt_match_variant.template get<parser::ParsedType::MutableReference>();NonnullRefPtr<typename parser::ParsedType> const& rhs_inner = __jakt_match_value.inner;
return JaktInternal::ExplicitValue(((lhs_inner)->equals(rhs_inner)));
};/*case end*/
default: {
return JaktInternal::ExplicitValue(false);
};/*case end*/
}/*switch end*/
}()
)));
};/*case end*/
case 10: {
auto&& __jakt_match_value = __jakt_match_variant.template get<parser::ParsedType::RawPtr>();NonnullRefPtr<typename parser::ParsedType> const& lhs_inner = __jakt_match_value.inner;
return JaktInternal::ExplicitValue(JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<bool, bool>{
auto&& __jakt_match_variant = *rhs_parsed_type;
switch(__jakt_match_variant.index()) {
case 10: {
auto&& __jakt_match_value = __jakt_match_variant.template get<parser::ParsedType::RawPtr>();NonnullRefPtr<typename parser::ParsedType> const& rhs_inner = __jakt_match_value.inner;
return JaktInternal::ExplicitValue(((lhs_inner)->equals(rhs_inner)));
};/*case end*/
default: {
return JaktInternal::ExplicitValue(false);
};/*case end*/
}/*switch end*/
}()
)));
};/*case end*/
case 11: {
auto&& __jakt_match_value = __jakt_match_variant.template get<parser::ParsedType::WeakPtr>();NonnullRefPtr<typename parser::ParsedType> const& lhs_inner = __jakt_match_value.inner;
return JaktInternal::ExplicitValue(JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<bool, bool>{
auto&& __jakt_match_variant = *rhs_parsed_type;
switch(__jakt_match_variant.index()) {
case 11: {
auto&& __jakt_match_value = __jakt_match_variant.template get<parser::ParsedType::WeakPtr>();NonnullRefPtr<typename parser::ParsedType> const& rhs_inner = __jakt_match_value.inner;
return JaktInternal::ExplicitValue(((lhs_inner)->equals(rhs_inner)));
};/*case end*/
default: {
return JaktInternal::ExplicitValue(false);
};/*case end*/
}/*switch end*/
}()
)));
};/*case end*/
case 12: {
auto&& __jakt_match_value = __jakt_match_variant.template get<parser::ParsedType::Function>();JaktInternal::DynamicArray<parser::ParsedParameter> const& lhs_params = __jakt_match_value.params;
bool const& lhs_can_throw = __jakt_match_value.can_throw;
NonnullRefPtr<typename parser::ParsedType> const& lhs_return_type = __jakt_match_value.return_type;
return JaktInternal::ExplicitValue(JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<bool, bool>{
auto&& __jakt_match_variant = *rhs_parsed_type;
switch(__jakt_match_variant.index()) {
case 12: {
auto&& __jakt_match_value = __jakt_match_variant.template get<parser::ParsedType::Function>();JaktInternal::DynamicArray<parser::ParsedParameter> const& rhs_params = __jakt_match_value.params;
bool const& rhs_can_throw = __jakt_match_value.can_throw;
NonnullRefPtr<typename parser::ParsedType> const& rhs_return_type = __jakt_match_value.return_type;
{
if ((lhs_can_throw != rhs_can_throw)){
return (false);
}
if ((!(((lhs_return_type)->equals(rhs_return_type))))){
return (false);
}
if ((((lhs_params).size()) != ((rhs_params).size()))){
return (false);
}
{
JaktInternal::Range<size_t> _magic = (JaktInternal::Range<size_t>{static_cast<size_t>(static_cast<size_t>(0ULL)),static_cast<size_t>(((lhs_params).size()))});
for (;;){
JaktInternal::Optional<size_t> _magic_value = ((_magic).next());
if ((!(((_magic_value).has_value())))){
break;
}
size_t param_index = (_magic_value.value());
{
if ((!(((((lhs_params)[param_index])).equals(((rhs_params)[param_index])))))){
return (false);
}
}

}
}

return (true);
}
};/*case end*/
default: {
return JaktInternal::ExplicitValue(false);
};/*case end*/
}/*switch end*/
}()
)));
};/*case end*/
case 13: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename parser::ParsedType::Empty>();
return JaktInternal::ExplicitValue(((rhs_parsed_type)->index() == 13 /* Empty */));
};/*case end*/
default: VERIFY_NOT_REACHED();}/*switch end*/
}()
)));
}
}

utility::Span parser::ParsedType::span() const {
{
return (JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<utility::Span, utility::Span>{
auto&& __jakt_match_variant = *this;
switch(__jakt_match_variant.index()) {
case 13: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename parser::ParsedType::Empty>();
return JaktInternal::ExplicitValue(utility::Span(utility::FileId(static_cast<size_t>(0ULL)),static_cast<size_t>(0ULL),static_cast<size_t>(0ULL)));
};/*case end*/
case 0: {
auto&& __jakt_match_value = __jakt_match_variant.template get<parser::ParsedType::Name>();utility::Span const& span = __jakt_match_value.span;
return JaktInternal::ExplicitValue(span);
};/*case end*/
case 1: {
auto&& __jakt_match_value = __jakt_match_variant.template get<parser::ParsedType::NamespacedName>();utility::Span const& span = __jakt_match_value.span;
return JaktInternal::ExplicitValue(span);
};/*case end*/
case 2: {
auto&& __jakt_match_value = __jakt_match_variant.template get<parser::ParsedType::GenericType>();utility::Span const& span = __jakt_match_value.span;
return JaktInternal::ExplicitValue(span);
};/*case end*/
case 3: {
auto&& __jakt_match_value = __jakt_match_variant.template get<parser::ParsedType::JaktArray>();utility::Span const& span = __jakt_match_value.span;
return JaktInternal::ExplicitValue(span);
};/*case end*/
case 4: {
auto&& __jakt_match_value = __jakt_match_variant.template get<parser::ParsedType::Dictionary>();utility::Span const& span = __jakt_match_value.span;
return JaktInternal::ExplicitValue(span);
};/*case end*/
case 5: {
auto&& __jakt_match_value = __jakt_match_variant.template get<parser::ParsedType::JaktTuple>();utility::Span const& span = __jakt_match_value.span;
return JaktInternal::ExplicitValue(span);
};/*case end*/
case 6: {
auto&& __jakt_match_value = __jakt_match_variant.template get<parser::ParsedType::Set>();utility::Span const& span = __jakt_match_value.span;
return JaktInternal::ExplicitValue(span);
};/*case end*/
case 7: {
auto&& __jakt_match_value = __jakt_match_variant.template get<parser::ParsedType::Optional>();utility::Span const& span = __jakt_match_value.span;
return JaktInternal::ExplicitValue(span);
};/*case end*/
case 8: {
auto&& __jakt_match_value = __jakt_match_variant.template get<parser::ParsedType::Reference>();utility::Span const& span = __jakt_match_value.span;
return JaktInternal::ExplicitValue(span);
};/*case end*/
case 9: {
auto&& __jakt_match_value = __jakt_match_variant.template get<parser::ParsedType::MutableReference>();utility::Span const& span = __jakt_match_value.span;
return JaktInternal::ExplicitValue(span);
};/*case end*/
case 10: {
auto&& __jakt_match_value = __jakt_match_variant.template get<parser::ParsedType::RawPtr>();utility::Span const& span = __jakt_match_value.span;
return JaktInternal::ExplicitValue(span);
};/*case end*/
case 11: {
auto&& __jakt_match_value = __jakt_match_variant.template get<parser::ParsedType::WeakPtr>();utility::Span const& span = __jakt_match_value.span;
return JaktInternal::ExplicitValue(span);
};/*case end*/
case 12: {
auto&& __jakt_match_value = __jakt_match_variant.template get<parser::ParsedType::Function>();utility::Span const& span = __jakt_match_value.span;
return JaktInternal::ExplicitValue(span);
};/*case end*/
default: VERIFY_NOT_REACHED();}/*switch end*/
}()
)));
}
}

ErrorOr<DeprecatedString> parser::TypeCast::debug_description() const {
auto builder = TRY(DeprecatedStringBuilder::create());
switch (this->index()) {case 0 /* Fallible */: {
[[maybe_unused]] auto const& that = this->template get<TypeCast::Fallible>();
TRY(builder.append("TypeCast::Fallible"sv));
TRY(builder.appendff("({})", that.value));
break;}
case 1 /* Infallible */: {
[[maybe_unused]] auto const& that = this->template get<TypeCast::Infallible>();
TRY(builder.append("TypeCast::Infallible"sv));
TRY(builder.appendff("({})", that.value));
break;}
}
return builder.to_string();
}
NonnullRefPtr<typename parser::ParsedType> parser::TypeCast::parsed_type() const {
{
return (JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<NonnullRefPtr<typename parser::ParsedType>, NonnullRefPtr<typename parser::ParsedType>>{
auto&& __jakt_match_variant = *this;
switch(__jakt_match_variant.index()) {
case 0: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename parser::TypeCast::Fallible>();
NonnullRefPtr<typename parser::ParsedType> const& parsed_type = __jakt_match_value.value;
return JaktInternal::ExplicitValue(parsed_type);
};/*case end*/
case 1: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename parser::TypeCast::Infallible>();
NonnullRefPtr<typename parser::ParsedType> const& parsed_type = __jakt_match_value.value;
return JaktInternal::ExplicitValue(parsed_type);
};/*case end*/
default: VERIFY_NOT_REACHED();}/*switch end*/
}()
)));
}
}

ErrorOr<DeprecatedString> parser::NumericConstant::debug_description() const {
auto builder = TRY(DeprecatedStringBuilder::create());
switch (this->index()) {case 0 /* I8 */: {
[[maybe_unused]] auto const& that = this->template get<NumericConstant::I8>();
TRY(builder.append("NumericConstant::I8"sv));
TRY(builder.appendff("({})", that.value));
break;}
case 1 /* I16 */: {
[[maybe_unused]] auto const& that = this->template get<NumericConstant::I16>();
TRY(builder.append("NumericConstant::I16"sv));
TRY(builder.appendff("({})", that.value));
break;}
case 2 /* I32 */: {
[[maybe_unused]] auto const& that = this->template get<NumericConstant::I32>();
TRY(builder.append("NumericConstant::I32"sv));
TRY(builder.appendff("({})", that.value));
break;}
case 3 /* I64 */: {
[[maybe_unused]] auto const& that = this->template get<NumericConstant::I64>();
TRY(builder.append("NumericConstant::I64"sv));
TRY(builder.appendff("({})", that.value));
break;}
case 4 /* U8 */: {
[[maybe_unused]] auto const& that = this->template get<NumericConstant::U8>();
TRY(builder.append("NumericConstant::U8"sv));
TRY(builder.appendff("({})", that.value));
break;}
case 5 /* U16 */: {
[[maybe_unused]] auto const& that = this->template get<NumericConstant::U16>();
TRY(builder.append("NumericConstant::U16"sv));
TRY(builder.appendff("({})", that.value));
break;}
case 6 /* U32 */: {
[[maybe_unused]] auto const& that = this->template get<NumericConstant::U32>();
TRY(builder.append("NumericConstant::U32"sv));
TRY(builder.appendff("({})", that.value));
break;}
case 7 /* U64 */: {
[[maybe_unused]] auto const& that = this->template get<NumericConstant::U64>();
TRY(builder.append("NumericConstant::U64"sv));
TRY(builder.appendff("({})", that.value));
break;}
case 8 /* USize */: {
[[maybe_unused]] auto const& that = this->template get<NumericConstant::USize>();
TRY(builder.append("NumericConstant::USize"sv));
TRY(builder.appendff("({})", that.value));
break;}
case 9 /* F32 */: {
[[maybe_unused]] auto const& that = this->template get<NumericConstant::F32>();
TRY(builder.append("NumericConstant::F32"sv));
TRY(builder.appendff("({})", that.value));
break;}
case 10 /* F64 */: {
[[maybe_unused]] auto const& that = this->template get<NumericConstant::F64>();
TRY(builder.append("NumericConstant::F64"sv));
TRY(builder.appendff("({})", that.value));
break;}
case 11 /* UnknownSigned */: {
[[maybe_unused]] auto const& that = this->template get<NumericConstant::UnknownSigned>();
TRY(builder.append("NumericConstant::UnknownSigned"sv));
TRY(builder.appendff("({})", that.value));
break;}
case 12 /* UnknownUnsigned */: {
[[maybe_unused]] auto const& that = this->template get<NumericConstant::UnknownUnsigned>();
TRY(builder.append("NumericConstant::UnknownUnsigned"sv));
TRY(builder.appendff("({})", that.value));
break;}
}
return builder.to_string();
}
size_t parser::NumericConstant::to_usize() const {
{
return (JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<size_t, size_t>{
auto&& __jakt_match_variant = *this;
switch(__jakt_match_variant.index()) {
case 0: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename parser::NumericConstant::I8>();
i8 const& num = __jakt_match_value.value;
return JaktInternal::ExplicitValue((infallible_integer_cast<size_t>((num))));
};/*case end*/
case 1: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename parser::NumericConstant::I16>();
i16 const& num = __jakt_match_value.value;
return JaktInternal::ExplicitValue((infallible_integer_cast<size_t>((num))));
};/*case end*/
case 2: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename parser::NumericConstant::I32>();
i32 const& num = __jakt_match_value.value;
return JaktInternal::ExplicitValue((infallible_integer_cast<size_t>((num))));
};/*case end*/
case 3: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename parser::NumericConstant::I64>();
i64 const& num = __jakt_match_value.value;
return JaktInternal::ExplicitValue((infallible_integer_cast<size_t>((num))));
};/*case end*/
case 4: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename parser::NumericConstant::U8>();
u8 const& num = __jakt_match_value.value;
return JaktInternal::ExplicitValue((infallible_integer_cast<size_t>((num))));
};/*case end*/
case 5: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename parser::NumericConstant::U16>();
u16 const& num = __jakt_match_value.value;
return JaktInternal::ExplicitValue((infallible_integer_cast<size_t>((num))));
};/*case end*/
case 6: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename parser::NumericConstant::U32>();
u32 const& num = __jakt_match_value.value;
return JaktInternal::ExplicitValue((infallible_integer_cast<size_t>((num))));
};/*case end*/
case 7: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename parser::NumericConstant::U64>();
u64 const& num = __jakt_match_value.value;
return JaktInternal::ExplicitValue((infallible_integer_cast<size_t>((num))));
};/*case end*/
case 8: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename parser::NumericConstant::USize>();
u64 const& num = __jakt_match_value.value;
return JaktInternal::ExplicitValue((infallible_integer_cast<size_t>((num))));
};/*case end*/
case 11: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename parser::NumericConstant::UnknownSigned>();
i64 const& num = __jakt_match_value.value;
return JaktInternal::ExplicitValue((infallible_integer_cast<size_t>((num))));
};/*case end*/
case 12: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename parser::NumericConstant::UnknownUnsigned>();
u64 const& num = __jakt_match_value.value;
return JaktInternal::ExplicitValue((infallible_integer_cast<size_t>((num))));
};/*case end*/
default: {
return JaktInternal::ExplicitValue((infallible_integer_cast<size_t>((static_cast<i64>(0LL)))));
};/*case end*/
}/*switch end*/
}()
)));
}
}

ErrorOr<DeprecatedString> parser::UnaryOperator::debug_description() const {
auto builder = TRY(DeprecatedStringBuilder::create());
switch (this->index()) {case 0 /* PreIncrement */: {
[[maybe_unused]] auto const& that = this->template get<UnaryOperator::PreIncrement>();
TRY(builder.append("UnaryOperator::PreIncrement"sv));
break;}
case 1 /* PostIncrement */: {
[[maybe_unused]] auto const& that = this->template get<UnaryOperator::PostIncrement>();
TRY(builder.append("UnaryOperator::PostIncrement"sv));
break;}
case 2 /* PreDecrement */: {
[[maybe_unused]] auto const& that = this->template get<UnaryOperator::PreDecrement>();
TRY(builder.append("UnaryOperator::PreDecrement"sv));
break;}
case 3 /* PostDecrement */: {
[[maybe_unused]] auto const& that = this->template get<UnaryOperator::PostDecrement>();
TRY(builder.append("UnaryOperator::PostDecrement"sv));
break;}
case 4 /* Negate */: {
[[maybe_unused]] auto const& that = this->template get<UnaryOperator::Negate>();
TRY(builder.append("UnaryOperator::Negate"sv));
break;}
case 5 /* Dereference */: {
[[maybe_unused]] auto const& that = this->template get<UnaryOperator::Dereference>();
TRY(builder.append("UnaryOperator::Dereference"sv));
break;}
case 6 /* RawAddress */: {
[[maybe_unused]] auto const& that = this->template get<UnaryOperator::RawAddress>();
TRY(builder.append("UnaryOperator::RawAddress"sv));
break;}
case 7 /* Reference */: {
[[maybe_unused]] auto const& that = this->template get<UnaryOperator::Reference>();
TRY(builder.append("UnaryOperator::Reference"sv));
break;}
case 8 /* MutableReference */: {
[[maybe_unused]] auto const& that = this->template get<UnaryOperator::MutableReference>();
TRY(builder.append("UnaryOperator::MutableReference"sv));
break;}
case 9 /* LogicalNot */: {
[[maybe_unused]] auto const& that = this->template get<UnaryOperator::LogicalNot>();
TRY(builder.append("UnaryOperator::LogicalNot"sv));
break;}
case 10 /* BitwiseNot */: {
[[maybe_unused]] auto const& that = this->template get<UnaryOperator::BitwiseNot>();
TRY(builder.append("UnaryOperator::BitwiseNot"sv));
break;}
case 11 /* TypeCast */: {
[[maybe_unused]] auto const& that = this->template get<UnaryOperator::TypeCast>();
TRY(builder.append("UnaryOperator::TypeCast"sv));
TRY(builder.appendff("({})", that.value));
break;}
case 12 /* Is */: {
[[maybe_unused]] auto const& that = this->template get<UnaryOperator::Is>();
TRY(builder.append("UnaryOperator::Is"sv));
TRY(builder.appendff("({})", that.value));
break;}
case 13 /* IsEnumVariant */: {
[[maybe_unused]] auto const& that = this->template get<UnaryOperator::IsEnumVariant>();
TRY(builder.append("UnaryOperator::IsEnumVariant"sv));
TRY(builder.append("("sv));
{
JaktInternal::PrettyPrint::ScopedLevelIncrease increase_indent {};
TRY(JaktInternal::PrettyPrint::output_indentation(builder));
TRY(builder.appendff("inner: {}", that.inner));
TRY(builder.append(", "sv));
TRY(JaktInternal::PrettyPrint::output_indentation(builder));
TRY(builder.appendff("bindings: {}", that.bindings));
}
TRY(builder.append(")"sv));
break;}
}
return builder.to_string();
}
bool parser::UnaryOperator::equals(parser::UnaryOperator const rhs_op) const {
{
return (JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<bool, bool>{
auto&& __jakt_match_variant = *this;
switch(__jakt_match_variant.index()) {
case 0: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename parser::UnaryOperator::PreIncrement>();
return JaktInternal::ExplicitValue(((rhs_op).index() == 0 /* PreIncrement */));
};/*case end*/
case 1: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename parser::UnaryOperator::PostIncrement>();
return JaktInternal::ExplicitValue(((rhs_op).index() == 1 /* PostIncrement */));
};/*case end*/
case 2: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename parser::UnaryOperator::PreDecrement>();
return JaktInternal::ExplicitValue(((rhs_op).index() == 2 /* PreDecrement */));
};/*case end*/
case 3: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename parser::UnaryOperator::PostDecrement>();
return JaktInternal::ExplicitValue(((rhs_op).index() == 3 /* PostDecrement */));
};/*case end*/
case 4: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename parser::UnaryOperator::Negate>();
return JaktInternal::ExplicitValue(((rhs_op).index() == 4 /* Negate */));
};/*case end*/
case 5: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename parser::UnaryOperator::Dereference>();
return JaktInternal::ExplicitValue(((rhs_op).index() == 5 /* Dereference */));
};/*case end*/
case 6: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename parser::UnaryOperator::RawAddress>();
return JaktInternal::ExplicitValue(((rhs_op).index() == 6 /* RawAddress */));
};/*case end*/
case 7: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename parser::UnaryOperator::Reference>();
return JaktInternal::ExplicitValue(((rhs_op).index() == 7 /* Reference */));
};/*case end*/
case 8: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename parser::UnaryOperator::MutableReference>();
return JaktInternal::ExplicitValue(((rhs_op).index() == 8 /* MutableReference */));
};/*case end*/
case 9: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename parser::UnaryOperator::LogicalNot>();
return JaktInternal::ExplicitValue(((rhs_op).index() == 9 /* LogicalNot */));
};/*case end*/
case 10: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename parser::UnaryOperator::BitwiseNot>();
return JaktInternal::ExplicitValue(((rhs_op).index() == 10 /* BitwiseNot */));
};/*case end*/
case 11: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename parser::UnaryOperator::TypeCast>();
parser::TypeCast const& lhs_type_cast = __jakt_match_value.value;
return JaktInternal::ExplicitValue(JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<bool, bool>{
auto&& __jakt_match_variant = rhs_op;
switch(__jakt_match_variant.index()) {
case 11: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename parser::UnaryOperator::TypeCast>();
parser::TypeCast const& rhs_type_cast = __jakt_match_value.value;
return JaktInternal::ExplicitValue(((((lhs_type_cast).parsed_type()))->equals(((rhs_type_cast).parsed_type()))));
};/*case end*/
default: {
return JaktInternal::ExplicitValue(false);
};/*case end*/
}/*switch end*/
}()
)));
};/*case end*/
case 12: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename parser::UnaryOperator::Is>();
NonnullRefPtr<typename parser::ParsedType> const& lhs_type = __jakt_match_value.value;
return JaktInternal::ExplicitValue(JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<bool, bool>{
auto&& __jakt_match_variant = rhs_op;
switch(__jakt_match_variant.index()) {
case 12: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename parser::UnaryOperator::Is>();
NonnullRefPtr<typename parser::ParsedType> const& rhs_type = __jakt_match_value.value;
return JaktInternal::ExplicitValue(((lhs_type)->equals(rhs_type)));
};/*case end*/
default: {
return JaktInternal::ExplicitValue(false);
};/*case end*/
}/*switch end*/
}()
)));
};/*case end*/
case 13: {
auto&& __jakt_match_value = __jakt_match_variant.template get<parser::UnaryOperator::IsEnumVariant>();NonnullRefPtr<typename parser::ParsedType> const& lhs_inner_type = __jakt_match_value.inner;
JaktInternal::DynamicArray<parser::EnumVariantPatternArgument> const& lhs_bindings = __jakt_match_value.bindings;
return JaktInternal::ExplicitValue(JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<bool, bool>{
auto&& __jakt_match_variant = rhs_op;
switch(__jakt_match_variant.index()) {
case 13: {
auto&& __jakt_match_value = __jakt_match_variant.template get<parser::UnaryOperator::IsEnumVariant>();NonnullRefPtr<typename parser::ParsedType> const& rhs_inner_type = __jakt_match_value.inner;
JaktInternal::DynamicArray<parser::EnumVariantPatternArgument> const& rhs_bindings = __jakt_match_value.bindings;
return JaktInternal::ExplicitValue(({ Optional<bool> __jakt_var_119; {
bool equal = false;
if ((((lhs_inner_type)->equals(rhs_inner_type)) && (((lhs_bindings).size()) == ((rhs_bindings).size())))){
bool bindings_equal = true;
{
JaktInternal::Range<size_t> _magic = (JaktInternal::Range<size_t>{static_cast<size_t>(0LL),static_cast<size_t>(((lhs_bindings).size()))});
for (;;){
JaktInternal::Optional<size_t> _magic_value = ((_magic).next());
if ((!(((_magic_value).has_value())))){
break;
}
size_t i = (_magic_value.value());
{
if ((!(((((lhs_bindings)[i])).equals(((rhs_bindings)[i])))))){
(bindings_equal = false);
break;
}
}

}
}

if (bindings_equal){
(equal = true);
}
}
__jakt_var_119 = equal; goto __jakt_label_116;

}
__jakt_label_116:; __jakt_var_119.release_value(); }));
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

}
} // namespace Jakt
