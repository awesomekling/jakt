#include "codegen.h"
namespace Jakt {
namespace codegen {
bool are_loop_exits_allowed(codegen::AllowedControlExits const allowed_control_exits) {
{
return (((allowed_control_exits).index() == 2 /* AtLoop */));
}
}

bool is_return_allowed(codegen::AllowedControlExits const allowed_control_exits) {
{
return ((!(((allowed_control_exits).index() == 0 /* Nothing */))));
}
}

ErrorOr<DeprecatedString> codegen::LineSpan::debug_description() const { auto builder = MUST(DeprecatedStringBuilder::create());TRY(builder.append("LineSpan("sv));{
JaktInternal::PrettyPrint::ScopedLevelIncrease increase_indent {};
TRY(JaktInternal::PrettyPrint::output_indentation(builder));TRY(builder.append("start: "sv));TRY(builder.appendff("{}, ", start));
TRY(JaktInternal::PrettyPrint::output_indentation(builder));TRY(builder.append("end: "sv));TRY(builder.appendff("{}", end));
}
TRY(builder.append(")"sv));return builder.to_string(); }
codegen::LineSpan::LineSpan(size_t a_start, size_t a_end) :start(a_start), end(a_end){}

ErrorOr<DeprecatedString> codegen::CodegenDebugInfo::debug_description() const { auto builder = MUST(DeprecatedStringBuilder::create());TRY(builder.append("CodegenDebugInfo("sv));{
JaktInternal::PrettyPrint::ScopedLevelIncrease increase_indent {};
TRY(JaktInternal::PrettyPrint::output_indentation(builder));TRY(builder.append("compiler: "sv));TRY(builder.appendff("{}, ", *compiler));
TRY(JaktInternal::PrettyPrint::output_indentation(builder));TRY(builder.append("line_spans: "sv));TRY(builder.appendff("{}, ", line_spans));
TRY(JaktInternal::PrettyPrint::output_indentation(builder));TRY(builder.append("statement_span_comments: "sv));TRY(builder.appendff("{}", statement_span_comments));
}
TRY(builder.append(")"sv));return builder.to_string(); }
ErrorOr<void> codegen::CodegenDebugInfo::gather_line_spans() {
{
{
JaktInternal::DictionaryIterator<DeprecatedString,utility::FileId> _magic = ((((((*this).compiler))->file_ids)).iterator());
for (;;){
JaktInternal::Optional<JaktInternal::Tuple<DeprecatedString,utility::FileId>> _magic_value = ((_magic).next());
if ((!(((_magic_value).has_value())))){
break;
}
JaktInternal::Tuple<DeprecatedString,utility::FileId> file = (_magic_value.value());
{
if ((((file).template get<0>()) == Jakt::DeprecatedString("__prelude__"sv))){
continue;
}
((((*this).compiler))->set_current_file(((file).template get<1>())));
size_t const file_idx = ((((file).template get<1>())).id);
JaktInternal::DynamicArray<codegen::LineSpan> const empty_array = (TRY((DynamicArray<codegen::LineSpan>::create_with({}))));
TRY((((((*this).line_spans)).set(file_idx,empty_array))));
size_t idx = static_cast<size_t>(0ULL);
size_t start = idx;
while ((idx < ((((((*this).compiler))->current_file_contents)).size()))){
if ((((((((*this).compiler))->current_file_contents))[idx]) == '\n')){
TRY((((((((*this).line_spans))[file_idx])).push(codegen::LineSpan(start,idx)))));
(start = (JaktInternal::checked_add<size_t>(idx,static_cast<size_t>(1ULL))));
}
({auto& _jakt_ref = idx;_jakt_ref = JaktInternal::checked_add<size_t>(_jakt_ref, static_cast<size_t>(1ULL));});
}
if ((start < idx)){
TRY((((((((*this).line_spans))[file_idx])).push(codegen::LineSpan(start,idx)))));
}
}

}
}

}
return {};
}

ErrorOr<DeprecatedString> codegen::CodegenDebugInfo::span_to_source_location(utility::Span const span) {
{
if (((((*this).line_spans)).is_empty())){
TRY((((*this).gather_line_spans())));
}
size_t const file_idx = ((((span).file_id)).id);
if ((!(((((*this).line_spans)).contains(file_idx))))){
return (Jakt::DeprecatedString(""sv));
}
size_t line_index = static_cast<size_t>(0ULL);
while ((line_index < ((((((*this).line_spans))[file_idx])).size()))){
if (((((span).start) >= ((((((((*this).line_spans))[file_idx]))[line_index])).start)) && (((span).start) <= ((((((((*this).line_spans))[file_idx]))[line_index])).end)))){
size_t const column_index = (JaktInternal::checked_sub<size_t>(((span).start),((((((((*this).line_spans))[file_idx]))[line_index])).start)));
return (TRY((__jakt_format(Jakt::DeprecatedString("{} \"{}\""sv),(JaktInternal::checked_add<size_t>(line_index,static_cast<size_t>(1ULL))),(((TRY((((((*this).compiler))->get_file_path(((span).file_id))))).value())).to_string())))));
}
({auto& _jakt_ref = line_index;_jakt_ref = JaktInternal::checked_add<size_t>(_jakt_ref, static_cast<size_t>(1ULL));});
}
utility::panic(Jakt::DeprecatedString("Reached end of file and could not find index"sv));
}
}

codegen::CodegenDebugInfo::CodegenDebugInfo(NonnullRefPtr<compiler::Compiler> a_compiler, JaktInternal::Dictionary<size_t,JaktInternal::DynamicArray<codegen::LineSpan>> a_line_spans, bool a_statement_span_comments) :compiler(a_compiler), line_spans(a_line_spans), statement_span_comments(a_statement_span_comments){}

ErrorOr<DeprecatedString> codegen::CodeGenerator::debug_description() const { auto builder = MUST(DeprecatedStringBuilder::create());TRY(builder.append("CodeGenerator("sv));{
JaktInternal::PrettyPrint::ScopedLevelIncrease increase_indent {};
TRY(JaktInternal::PrettyPrint::output_indentation(builder));TRY(builder.append("compiler: "sv));TRY(builder.appendff("{}, ", *compiler));
TRY(JaktInternal::PrettyPrint::output_indentation(builder));TRY(builder.append("program: "sv));TRY(builder.appendff("{}, ", *program));
TRY(JaktInternal::PrettyPrint::output_indentation(builder));TRY(builder.append("control_flow_state: "sv));TRY(builder.appendff("{}, ", control_flow_state));
TRY(JaktInternal::PrettyPrint::output_indentation(builder));TRY(builder.append("entered_yieldable_blocks: "sv));TRY(builder.appendff("{}, ", entered_yieldable_blocks));
TRY(JaktInternal::PrettyPrint::output_indentation(builder));TRY(builder.append("deferred_output: "sv));TRY(builder.appendff("\"{}\", ", deferred_output));
TRY(JaktInternal::PrettyPrint::output_indentation(builder));TRY(builder.append("current_function: "sv));TRY(builder.appendff("{}, ", current_function));
TRY(JaktInternal::PrettyPrint::output_indentation(builder));TRY(builder.append("inside_defer: "sv));TRY(builder.appendff("{}, ", inside_defer));
TRY(JaktInternal::PrettyPrint::output_indentation(builder));TRY(builder.append("debug_info: "sv));TRY(builder.appendff("{}, ", debug_info));
TRY(JaktInternal::PrettyPrint::output_indentation(builder));TRY(builder.append("namespace_stack: "sv));TRY(builder.appendff("{}, ", namespace_stack));
TRY(JaktInternal::PrettyPrint::output_indentation(builder));TRY(builder.append("fresh_var_counter: "sv));TRY(builder.appendff("{}, ", fresh_var_counter));
TRY(JaktInternal::PrettyPrint::output_indentation(builder));TRY(builder.append("fresh_label_counter: "sv));TRY(builder.appendff("{}", fresh_label_counter));
}
TRY(builder.append(")"sv));return builder.to_string(); }
ErrorOr<DeprecatedString> codegen::CodeGenerator::codegen_function(NonnullRefPtr<types::CheckedFunction> const function_,bool const as_method) {
{
if (((function_)->is_comptime)){
return (Jakt::DeprecatedString(""sv));
}
return (TRY((((*this).codegen_function_in_namespace(function_,JaktInternal::OptionalNone(),as_method)))));
}
}

ErrorOr<DeprecatedString> codegen::CodeGenerator::codegen_generic_type_instance(types::StructId const id,JaktInternal::DynamicArray<types::TypeId> const args,bool const as_namespace) const {
{
DeprecatedString output = Jakt::DeprecatedString(""sv);
NonnullRefPtr<types::Module> const type_module = ((((*this).program))->get_module(((id).module)));
DeprecatedString namespace_ = Jakt::DeprecatedString(""sv);
if (((type_module)->is_prelude())){
(namespace_ += Jakt::DeprecatedString("JaktInternal::"sv));
}
JaktInternal::Optional<types::StructId> const inner_weak_ptr_struct_id = TRY((((((*this).program))->check_and_extract_weak_ptr(id,args))));
if (((inner_weak_ptr_struct_id).has_value())){
(output += Jakt::DeprecatedString("WeakPtr<"sv));
(output += namespace_);
types::StructId const inner_struct_id = ((inner_weak_ptr_struct_id).value());
types::CheckedStruct const struct_ = ((((*this).program))->get_struct(inner_struct_id));
(output += TRY((((*this).codegen_namespace_qualifier(((struct_).scope_id),true,JaktInternal::OptionalNone())))));
(output += ((struct_).name_for_codegen()));
(output += Jakt::DeprecatedString(">"sv));
}
else {
types::CheckedStruct const struct_ = ((((*this).program))->get_struct(id));
bool const acquired_by_ref = ((!(as_namespace)) && ((((struct_).record_type)).index() == 1 /* Class */));
if (acquired_by_ref){
(output += Jakt::DeprecatedString("NonnullRefPtr<"sv));
}
(output += namespace_);
(output += TRY((((*this).codegen_namespace_qualifier(((struct_).scope_id),true,JaktInternal::OptionalNone())))));
(output += ((struct_).name_for_codegen()));
(output += Jakt::DeprecatedString("<"sv));
bool first = true;
{
JaktInternal::ArrayIterator<types::TypeId> _magic = ((args).iterator());
for (;;){
JaktInternal::Optional<types::TypeId> _magic_value = ((_magic).next());
if ((!(((_magic_value).has_value())))){
break;
}
types::TypeId type_id = (_magic_value.value());
{
if ((!(first))){
(output += Jakt::DeprecatedString(","sv));
}
else {
(first = false);
}

(output += TRY((((*this).codegen_type(type_id)))));
}

}
}

(output += Jakt::DeprecatedString(">"sv));
if (acquired_by_ref){
(output += Jakt::DeprecatedString(">"sv));
}
}

return (output);
}
}

ErrorOr<JaktInternal::DynamicArray<types::ModuleId>> codegen::CodeGenerator::topologically_sort_modules() const {
{
JaktInternal::Dictionary<size_t,i64> in_degrees = (TRY((Dictionary<size_t, i64>::create_with_entries({}))));
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
JaktInternal::ArrayIterator<types::ModuleId> _magic = ((((module)->imports)).iterator());
for (;;){
JaktInternal::Optional<types::ModuleId> _magic_value = ((_magic).next());
if ((!(((_magic_value).has_value())))){
break;
}
types::ModuleId imported_module = (_magic_value.value());
{
i64 const existing = ((in_degrees).get(((imported_module).id))).value_or_lazy_evaluated([&] { return static_cast<i64>(0LL); });
TRY((((in_degrees).set(((imported_module).id),(JaktInternal::checked_add<i64>(existing,static_cast<i64>(1LL)))))));
}

}
}

if ((!(((in_degrees).contains(((((module)->id)).id)))))){
TRY((((in_degrees).set(((((module)->id)).id),static_cast<i64>(0LL)))));
}
}

}
}

JaktInternal::DynamicArray<types::ModuleId> stack = (TRY((DynamicArray<types::ModuleId>::create_with({}))));
{
JaktInternal::ArrayIterator<NonnullRefPtr<types::Module>> _magic = ((((((*this).program))->modules)).iterator());
for (;;){
JaktInternal::Optional<NonnullRefPtr<types::Module>> _magic_value = ((_magic).next());
if ((!(((_magic_value).has_value())))){
break;
}
NonnullRefPtr<types::Module> module = (_magic_value.value());
{
if ((((in_degrees)[((((module)->id)).id)]) == static_cast<i64>(0LL))){
TRY((((stack).push(((module)->id)))));
}
}

}
}

JaktInternal::DynamicArray<types::ModuleId> sorted_modules = (TRY((DynamicArray<types::ModuleId>::create_with({}))));
while ((!(((stack).is_empty())))){
types::ModuleId const id = (((stack).pop()).value());
TRY((((sorted_modules).push(id))));
{
JaktInternal::ArrayIterator<types::ModuleId> _magic = ((((((((((*this).program))->modules))[((id).id)]))->imports)).iterator());
for (;;){
JaktInternal::Optional<types::ModuleId> _magic_value = ((_magic).next());
if ((!(((_magic_value).has_value())))){
break;
}
types::ModuleId imported_module = (_magic_value.value());
{
i64 const module_in_degrees = ((in_degrees)[((imported_module).id)]);
TRY((((in_degrees).set(((imported_module).id),(JaktInternal::checked_sub<i64>(module_in_degrees,static_cast<i64>(1LL)))))));
if ((module_in_degrees == static_cast<i64>(1LL))){
TRY((((stack).push(types::ModuleId(((imported_module).id))))));
}
}

}
}

}
if ((((sorted_modules).size()) == ((((((*this).program))->modules)).size()))){
return (sorted_modules);
}
utility::panic(Jakt::DeprecatedString("Cyclic module imports"sv));
}
}

ErrorOr<DeprecatedString> codegen::CodeGenerator::codegen_debug_description_getter(types::CheckedStruct const struct_,bool const is_inline) {
{
DeprecatedString output = Jakt::DeprecatedString(""sv);
if (((!(is_inline)) && (!(((((struct_).generic_parameters)).is_empty()))))){
(output += Jakt::DeprecatedString("template <"sv));
bool first = true;
{
JaktInternal::ArrayIterator<types::CheckedGenericParameter> _magic = ((((struct_).generic_parameters)).iterator());
for (;;){
JaktInternal::Optional<types::CheckedGenericParameter> _magic_value = ((_magic).next());
if ((!(((_magic_value).has_value())))){
break;
}
types::CheckedGenericParameter param = (_magic_value.value());
{
if (first){
(first = false);
}
else {
(output += Jakt::DeprecatedString(","sv));
}

(output += Jakt::DeprecatedString("typename "sv));
(output += TRY((((*this).codegen_type(((param).type_id))))));
}

}
}

(output += Jakt::DeprecatedString(">\n"sv));
}
(output += Jakt::DeprecatedString("ErrorOr<DeprecatedString> "sv));
if ((!(is_inline))){
(output += TRY((((*this).codegen_type_possibly_as_namespace(((struct_).type_id),true)))));
(output += Jakt::DeprecatedString("::"sv));
}
(output += Jakt::DeprecatedString("debug_description() const { "sv));
(output += Jakt::DeprecatedString("auto builder = MUST(DeprecatedStringBuilder::create());"sv));
(output += TRY((__jakt_format(Jakt::DeprecatedString("TRY(builder.append(\"{}(\"sv));"sv),((struct_).name_for_codegen())))));
(output += Jakt::DeprecatedString("{\n"sv));
(output += Jakt::DeprecatedString("JaktInternal::PrettyPrint::ScopedLevelIncrease increase_indent {};\n"sv));
size_t i = static_cast<size_t>(0ULL);
{
JaktInternal::ArrayIterator<types::CheckedField> _magic = ((((struct_).fields)).iterator());
for (;;){
JaktInternal::Optional<types::CheckedField> _magic_value = ((_magic).next());
if ((!(((_magic_value).has_value())))){
break;
}
types::CheckedField field = (_magic_value.value());
{
NonnullRefPtr<types::CheckedVariable> const field_var = ((((*this).program))->get_variable(((field).variable_id)));
(output += Jakt::DeprecatedString("TRY(JaktInternal::PrettyPrint::output_indentation(builder));"sv));
(output += TRY((__jakt_format(Jakt::DeprecatedString("TRY(builder.append(\"{}: \"sv));"sv),((field_var)->name)))));
(output += Jakt::DeprecatedString("TRY(builder.appendff(\""sv));
if (((((*this).program))->is_string(((field_var)->type_id)))){
(output += Jakt::DeprecatedString("\\\"{}\\\""sv));
}
else {
(output += Jakt::DeprecatedString("{}"sv));
}

if ((i != (JaktInternal::checked_sub<size_t>(((((struct_).fields)).size()),static_cast<size_t>(1ULL))))){
(output += Jakt::DeprecatedString(", "sv));
}
(output += Jakt::DeprecatedString("\", "sv));
(output += JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_AT_LOOP(([&]() -> JaktInternal::ExplicitValueOrControlFlow<DeprecatedString, ErrorOr<DeprecatedString>>{
auto&& __jakt_match_variant = *((((*this).program))->get_type(((field_var)->type_id)));
switch(__jakt_match_variant.index()) {
case 23: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::Type::Struct>();
types::StructId const& struct_id = __jakt_match_value.value;
return JaktInternal::ExplicitValue(JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_AT_LOOP_NESTED_MATCH(([&]() -> JaktInternal::ExplicitValueOrControlFlow<DeprecatedString, ErrorOr<DeprecatedString>>{
auto&& __jakt_match_variant = ((((((*this).program))->get_struct(struct_id))).record_type);
switch(__jakt_match_variant.index()) {
case 1: {
auto&& __jakt_match_value = __jakt_match_variant.template get<parser::RecordType::Class>();return JaktInternal::ExplicitValue(Jakt::DeprecatedString("*"sv));
};/*case end*/
default: {
return JaktInternal::ExplicitValue(Jakt::DeprecatedString(""sv));
};/*case end*/
}/*switch end*/
}()
)));
};/*case end*/
default: {
return JaktInternal::ExplicitValue(Jakt::DeprecatedString(""sv));
};/*case end*/
}/*switch end*/
}()
)));
(output += (((field_var)->name) + Jakt::DeprecatedString("));\n"sv)));
((i++));
}

}
}

(output += Jakt::DeprecatedString("}\n"sv));
(output += Jakt::DeprecatedString("TRY(builder.append(\")\"sv));"sv));
(output += Jakt::DeprecatedString("return builder.to_string();"sv));
(output += Jakt::DeprecatedString(" }\n"sv));
return (output);
}
}

ErrorOr<DeprecatedString> codegen::CodeGenerator::codegen_expression_and_deref_if_generic_and_needed(NonnullRefPtr<typename types::CheckedExpression> const expression) {
{
return (JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<DeprecatedString, ErrorOr<DeprecatedString>>{
auto&& __jakt_match_variant = *((((*this).program))->get_type(((expression)->type())));
switch(__jakt_match_variant.index()) {
case 18: {
auto&& __jakt_match_value = __jakt_match_variant.template get<types::Type::TypeVariable>();return JaktInternal::ExplicitValue(({ Optional<DeprecatedString> __jakt_var_447; {
DeprecatedString const contents = TRY((((*this).codegen_expression(expression))));
__jakt_var_447 = TRY((__jakt_format(Jakt::DeprecatedString("(*([]<typename V>(V&& value) {{ if constexpr (IsSpecializationOf<V, NonnullRefPtr>) return &*value; else return &value; }})({}))"sv),contents))); goto __jakt_label_397;

}
__jakt_label_397:; __jakt_var_447.release_value(); }));
};/*case end*/
default: {
return JaktInternal::ExplicitValue(TRY((((*this).codegen_expression(expression)))));
};/*case end*/
}/*switch end*/
}()
)));
}
}

ErrorOr<DeprecatedString> codegen::CodeGenerator::codegen_namespace(NonnullRefPtr<types::Scope> const scope,NonnullRefPtr<types::Module> const current_module,bool const as_forward) {
{
if ((((((scope)->alias_path)).has_value()) || ((((scope)->import_path_if_extern)).has_value()))){
return (Jakt::DeprecatedString(""sv));
}
JaktInternal::Set<DeprecatedString> seen_types = (TRY((Set<DeprecatedString>::create_with_values({}))));
if (as_forward){
DeprecatedString output = Jakt::DeprecatedString(""sv);
if (((((scope)->namespace_name)).has_value())){
(output += ((Jakt::DeprecatedString("namespace "sv) + (((scope)->namespace_name).value())) + Jakt::DeprecatedString(" {\n"sv)));
}
JaktInternal::Dictionary<DeprecatedString,JaktInternal::DynamicArray<DeprecatedString>> const encoded_dependency_graph = TRY((((*this).produce_codegen_dependency_graph(scope))));
{
JaktInternal::DictionaryIterator<DeprecatedString,JaktInternal::DynamicArray<DeprecatedString>> _magic = ((encoded_dependency_graph).iterator());
for (;;){
JaktInternal::Optional<JaktInternal::Tuple<DeprecatedString,JaktInternal::DynamicArray<DeprecatedString>>> _magic_value = ((_magic).next());
if ((!(((_magic_value).has_value())))){
break;
}
JaktInternal::Tuple<DeprecatedString,JaktInternal::DynamicArray<DeprecatedString>> entry = (_magic_value.value());
{
JaktInternal::DynamicArray<types::TypeId> const traversal = (TRY((DynamicArray<types::TypeId>::create_with({}))));
TRY((((*this).postorder_traversal(((entry).template get<0>()),seen_types,encoded_dependency_graph,traversal))));
{
JaktInternal::ArrayIterator<types::TypeId> _magic = ((traversal).iterator());
for (;;){
JaktInternal::Optional<types::TypeId> _magic_value = ((_magic).next());
if ((!(((_magic_value).has_value())))){
break;
}
types::TypeId type_id = (_magic_value.value());
{
NonnullRefPtr<typename types::Type> const type_ = ((((*this).program))->get_type(type_id));
JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_AT_LOOP(([&]() -> JaktInternal::ExplicitValueOrControlFlow<void, ErrorOr<DeprecatedString>>{
auto&& __jakt_match_variant = *type_;
switch(__jakt_match_variant.index()) {
case 24: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::Type::Enum>();
types::EnumId const& enum_id = __jakt_match_value.value;
{
if ((!(((((enum_id).module)).equals(((current_module)->id)))))){
return JaktInternal::LoopContinue{};
}
types::CheckedEnum const enum_ = ((((*this).program))->get_enum(enum_id));
DeprecatedString const enum_output = TRY((((*this).codegen_enum(enum_))));
if ((!(((enum_output).is_empty())))){
(output += enum_output);
}
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 23: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::Type::Struct>();
types::StructId const& struct_id = __jakt_match_value.value;
{
if ((!(((((struct_id).module)).equals(((current_module)->id)))))){
return JaktInternal::LoopContinue{};
}
types::CheckedStruct const struct_ = ((((*this).program))->get_struct(struct_id));
DeprecatedString const struct_output = TRY((((*this).codegen_struct(struct_))));
if ((!(((struct_output).is_empty())))){
(output += struct_output);
}
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 26: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::Type::Trait>();
{
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
default: {
{
utility::panic(TRY((__jakt_format(Jakt::DeprecatedString("Unexpected type in dependency graph: {}"sv),type_))));
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
}/*switch end*/
}()
));
TRY((((seen_types).add(TRY((((type_id).to_string())))))));
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
JaktInternal::Tuple<DeprecatedString,types::StructId> ___struct_id__ = (_magic_value.value());
{
JaktInternal::Tuple<DeprecatedString,types::StructId> const jakt_____struct_id__ = ___struct_id__;
DeprecatedString const _ = ((jakt_____struct_id__).template get<0>());
types::StructId const struct_id = ((jakt_____struct_id__).template get<1>());

if ((!(((((struct_id).module)).equals(((current_module)->id)))))){
continue;
}
types::CheckedStruct const struct_ = ((((*this).program))->get_struct(struct_id));
if (((seen_types).contains(TRY((((((struct_).type_id)).to_string())))))){
continue;
}
(output += TRY((((*this).codegen_struct(struct_)))));
(output += Jakt::DeprecatedString("\n"sv));
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
JaktInternal::Tuple<DeprecatedString,types::EnumId> ___enum_id__ = (_magic_value.value());
{
JaktInternal::Tuple<DeprecatedString,types::EnumId> const jakt_____enum_id__ = ___enum_id__;
DeprecatedString const _ = ((jakt_____enum_id__).template get<0>());
types::EnumId const enum_id = ((jakt_____enum_id__).template get<1>());

if ((!(((((enum_id).module)).equals(((current_module)->id)))))){
continue;
}
types::CheckedEnum const enum_ = ((((*this).program))->get_enum(enum_id));
if (((seen_types).contains(TRY((((((enum_).type_id)).to_string())))))){
continue;
}
(output += TRY((((*this).codegen_enum(enum_)))));
(output += Jakt::DeprecatedString("\n"sv));
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
if ((!(((((function_id).module)).equals(((current_module)->id)))))){
continue;
}
NonnullRefPtr<types::CheckedFunction> const function_ = ((((*this).program))->get_function(function_id));
JaktInternal::Optional<NonnullRefPtr<types::CheckedFunction>> const previous_function = ((*this).current_function);
(((*this).current_function) = function_);
ScopeGuard __jakt_var_448([&] {
(((*this).current_function) = previous_function);
});
if (((((((function_)->linkage)).index() == 1 /* External */) || ((((function_)->type)).index() == 1 /* ImplicitConstructor */)) || ((((function_)->type)).index() == 2 /* ImplicitEnumConstructor */))){
continue;
}
if ((!(((((((function_)->generics))->params)).is_empty())))){
(output += TRY((((*this).codegen_function(function_,false)))));
(output += Jakt::DeprecatedString("\n"sv));
}
}

}
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
types::ScopeId child_scope_id = (_magic_value.value());
{
NonnullRefPtr<types::Scope> const child_scope = TRY((((((*this).program))->get_scope(child_scope_id))));
if (((((child_scope)->namespace_name)).has_value())){
DeprecatedString const name = (((child_scope)->namespace_name).value());
TRY((((((*this).namespace_stack)).push(name))));
(output += TRY((((*this).codegen_namespace(child_scope,current_module,as_forward)))));
JaktInternal::Optional<DeprecatedString> const dummy = ((((*this).namespace_stack)).pop());
}
}

}
}

if (((((scope)->namespace_name)).has_value())){
(output += Jakt::DeprecatedString("}\n"sv));
}
return (output);
}
DeprecatedString output = Jakt::DeprecatedString(""sv);
if (((((scope)->namespace_name)).has_value())){
(output += ((Jakt::DeprecatedString("namespace "sv) + (((scope)->namespace_name).value())) + Jakt::DeprecatedString(" {\n"sv)));
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
if ((!(((((function_id).module)).equals(((current_module)->id)))))){
continue;
}
NonnullRefPtr<types::CheckedFunction> const function_ = ((((*this).program))->get_function(function_id));
JaktInternal::Optional<NonnullRefPtr<types::CheckedFunction>> const previous_function = ((*this).current_function);
(((*this).current_function) = function_);
ScopeGuard __jakt_var_449([&] {
(((*this).current_function) = previous_function);
});
if (((((((function_)->linkage)).index() == 1 /* External */) || ((((function_)->type)).index() == 1 /* ImplicitConstructor */)) || ((((function_)->type)).index() == 2 /* ImplicitEnumConstructor */))){
continue;
}
if (((((((function_)->generics))->params)).is_empty())){
(output += TRY((((*this).codegen_function(function_,false)))));
(output += Jakt::DeprecatedString("\n"sv));
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
JaktInternal::Tuple<DeprecatedString,types::StructId> ___struct_id__ = (_magic_value.value());
{
JaktInternal::Tuple<DeprecatedString,types::StructId> const jakt_____struct_id__ = ___struct_id__;
DeprecatedString const _ = ((jakt_____struct_id__).template get<0>());
types::StructId const struct_id = ((jakt_____struct_id__).template get<1>());

if ((!(((((struct_id).module)).equals(((current_module)->id)))))){
continue;
}
types::CheckedStruct const struct_ = ((((*this).program))->get_struct(struct_id));
if (((((struct_).definition_linkage)).index() == 1 /* External */)){
continue;
}
if ((!(((((struct_).generic_parameters)).is_empty())))){
continue;
}
(output += TRY((((*this).codegen_debug_description_getter(struct_,false)))));
NonnullRefPtr<types::Scope> const scope = TRY((((((*this).program))->get_scope(((struct_).scope_id)))));
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
NonnullRefPtr<types::CheckedFunction> const function_ = ((((*this).program))->get_function(function_id));
JaktInternal::Optional<NonnullRefPtr<types::CheckedFunction>> const previous_function = ((*this).current_function);
(((*this).current_function) = function_);
ScopeGuard __jakt_var_450([&] {
(((*this).current_function) = previous_function);
});
if (((((function_)->type)).index() == 1 /* ImplicitConstructor */)){
(output += TRY((((*this).codegen_constructor(function_,false)))));
(output += Jakt::DeprecatedString("\n"sv));
}
else if (((!(((((function_)->type)).index() == 2 /* ImplicitEnumConstructor */))) && ((!(((function_)->is_comptime))) && ((((((function_)->generics))->params)).is_empty())))){
(output += TRY((((*this).codegen_function_in_namespace(function_,((struct_).type_id),false)))));
(output += Jakt::DeprecatedString("\n"sv));
}
}

}
}

}

}
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
JaktInternal::Tuple<DeprecatedString,types::EnumId> ___enum_id__ = (_magic_value.value());
{
JaktInternal::Tuple<DeprecatedString,types::EnumId> const jakt_____enum_id__ = ___enum_id__;
DeprecatedString const _ = ((jakt_____enum_id__).template get<0>());
types::EnumId const enum_id = ((jakt_____enum_id__).template get<1>());

if ((!(((((enum_id).module)).equals(((current_module)->id)))))){
continue;
}
types::CheckedEnum const enum_ = ((((*this).program))->get_enum(enum_id));
if (((((enum_).definition_linkage)).index() == 1 /* External */)){
continue;
}
if ((!(((((enum_).generic_parameters)).is_empty())))){
continue;
}
if (((((enum_).underlying_type_id)).equals(types::void_type_id()))){
(output += TRY((((*this).codegen_enum_debug_description_getter(enum_,false)))));
}
NonnullRefPtr<types::Scope> const scope = TRY((((((*this).program))->get_scope(((enum_).scope_id)))));
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
NonnullRefPtr<types::CheckedFunction> const function_ = ((((*this).program))->get_function(function_id));
JaktInternal::Optional<NonnullRefPtr<types::CheckedFunction>> const previous_function = ((*this).current_function);
(((*this).current_function) = function_);
ScopeGuard __jakt_var_451([&] {
(((*this).current_function) = previous_function);
});
if (((!(((((function_)->type)).index() == 1 /* ImplicitConstructor */))) && ((!(((((function_)->type)).index() == 2 /* ImplicitEnumConstructor */))) && (!(((function_)->is_comptime)))))){
(output += TRY((((*this).codegen_function_in_namespace(function_,((enum_).type_id),false)))));
(output += Jakt::DeprecatedString("\n"sv));
}
}

}
}

}

}
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
types::ScopeId child_scope_id = (_magic_value.value());
{
NonnullRefPtr<types::Scope> const child_scope = TRY((((((*this).program))->get_scope(child_scope_id))));
if (((((child_scope)->namespace_name)).has_value())){
DeprecatedString const name = (((child_scope)->namespace_name).value());
TRY((((((*this).namespace_stack)).push(name))));
(output += TRY((((*this).codegen_namespace(child_scope,current_module,as_forward)))));
JaktInternal::Optional<DeprecatedString> const dummy = ((((*this).namespace_stack)).pop());
}
}

}
}

if (((((scope)->namespace_name)).has_value())){
(output += Jakt::DeprecatedString("}\n"sv));
}
return (output);
}
}

ErrorOr<DeprecatedString> codegen::CodeGenerator::codegen_unchecked_binary_op(NonnullRefPtr<typename types::CheckedExpression> const lhs,NonnullRefPtr<typename types::CheckedExpression> const rhs,parser::BinaryOperator const op,types::TypeId const type_id) {
{
DeprecatedString output = Jakt::DeprecatedString("static_cast<"sv);
(output += TRY((((*this).codegen_type(type_id)))));
(output += Jakt::DeprecatedString(">("sv));
(output += TRY((((*this).codegen_expression(lhs)))));
(output += JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<DeprecatedString, ErrorOr<DeprecatedString>>{
auto&& __jakt_match_variant = op;
switch(__jakt_match_variant.index()) {
case 0: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename parser::BinaryOperator::Add>();
return JaktInternal::ExplicitValue(Jakt::DeprecatedString(" + "sv));
};/*case end*/
case 1: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename parser::BinaryOperator::Subtract>();
return JaktInternal::ExplicitValue(Jakt::DeprecatedString(" - "sv));
};/*case end*/
case 2: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename parser::BinaryOperator::Multiply>();
return JaktInternal::ExplicitValue(Jakt::DeprecatedString(" * "sv));
};/*case end*/
case 3: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename parser::BinaryOperator::Divide>();
return JaktInternal::ExplicitValue(Jakt::DeprecatedString(" / "sv));
};/*case end*/
case 4: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename parser::BinaryOperator::Modulo>();
return JaktInternal::ExplicitValue(Jakt::DeprecatedString(" % "sv));
};/*case end*/
default: {
{
utility::panic(TRY((__jakt_format(Jakt::DeprecatedString("Checked binary operation codegen is not supported for BinaryOperator::{}"sv),op))));
}
};/*case end*/
}/*switch end*/
}()
)));
(output += TRY((((*this).codegen_expression(rhs)))));
(output += Jakt::DeprecatedString(")"sv));
return (output);
}
}

ErrorOr<JaktInternal::Dictionary<DeprecatedString,JaktInternal::DynamicArray<DeprecatedString>>> codegen::CodeGenerator::produce_codegen_dependency_graph(NonnullRefPtr<types::Scope> const scope) const {
{
JaktInternal::Dictionary<DeprecatedString,JaktInternal::DynamicArray<DeprecatedString>> dependency_graph = (TRY((Dictionary<DeprecatedString, JaktInternal::DynamicArray<DeprecatedString>>::create_with_entries({}))));
{
JaktInternal::DictionaryIterator<DeprecatedString,types::TypeId> _magic = ((((scope)->types)).iterator());
for (;;){
JaktInternal::Optional<JaktInternal::Tuple<DeprecatedString,types::TypeId>> _magic_value = ((_magic).next());
if ((!(((_magic_value).has_value())))){
break;
}
JaktInternal::Tuple<DeprecatedString,types::TypeId> type_ = (_magic_value.value());
{
TRY((((dependency_graph).set(TRY((((((type_).template get<1>())).to_string()))),TRY((((*this).extract_dependencies_from(((type_).template get<1>()),dependency_graph,true))))))));
}

}
}

return (dependency_graph);
}
}

ErrorOr<DeprecatedString> codegen::CodeGenerator::codegen_unchecked_binary_op_assignment(NonnullRefPtr<typename types::CheckedExpression> const lhs,NonnullRefPtr<typename types::CheckedExpression> const rhs,parser::BinaryOperator const op,types::TypeId const type_id) {
{
DeprecatedString output = Jakt::DeprecatedString(""sv);
(output += Jakt::DeprecatedString("{"sv));
(output += Jakt::DeprecatedString("auto& _jakt_ref = "sv));
(output += TRY((((*this).codegen_expression(lhs)))));
(output += Jakt::DeprecatedString(";"sv));
(output += Jakt::DeprecatedString("_jakt_ref = static_cast<"sv));
(output += TRY((((*this).codegen_type(type_id)))));
(output += Jakt::DeprecatedString(">(_jakt_ref "sv));
(output += JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<DeprecatedString, ErrorOr<DeprecatedString>>{
auto&& __jakt_match_variant = op;
switch(__jakt_match_variant.index()) {
case 27: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename parser::BinaryOperator::AddAssign>();
return JaktInternal::ExplicitValue(Jakt::DeprecatedString(" + "sv));
};/*case end*/
case 28: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename parser::BinaryOperator::SubtractAssign>();
return JaktInternal::ExplicitValue(Jakt::DeprecatedString(" - "sv));
};/*case end*/
case 29: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename parser::BinaryOperator::MultiplyAssign>();
return JaktInternal::ExplicitValue(Jakt::DeprecatedString(" * "sv));
};/*case end*/
case 31: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename parser::BinaryOperator::DivideAssign>();
return JaktInternal::ExplicitValue(Jakt::DeprecatedString(" / "sv));
};/*case end*/
case 30: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename parser::BinaryOperator::ModuloAssign>();
return JaktInternal::ExplicitValue(Jakt::DeprecatedString(" % "sv));
};/*case end*/
default: {
{
utility::panic(TRY((__jakt_format(Jakt::DeprecatedString("Checked binary operation assignment codegen is not supported for BinaryOperator::{}"sv),op))));
}
};/*case end*/
}/*switch end*/
}()
)));
(output += TRY((((*this).codegen_expression(rhs)))));
(output += Jakt::DeprecatedString(");"sv));
(output += Jakt::DeprecatedString("}"sv));
return (output);
}
}

ErrorOr<DeprecatedString> codegen::CodeGenerator::codegen_statement(NonnullRefPtr<typename types::CheckedStatement> const statement) {
{
bool add_newline = true;
DeprecatedString output = Jakt::DeprecatedString(""sv);
if ((((((*this).debug_info)).statement_span_comments) && (((((statement)->span())).has_value()) && add_newline))){
(output += TRY((__jakt_format(Jakt::DeprecatedString("\n#line {}\n"sv),TRY((((((*this).debug_info)).span_to_source_location((((statement)->span()).value())))))))));
}
(output += JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<DeprecatedString, ErrorOr<DeprecatedString>>{
auto&& __jakt_match_variant = *statement;
switch(__jakt_match_variant.index()) {
case 11: {
auto&& __jakt_match_value = __jakt_match_variant.template get<types::CheckedStatement::Throw>();NonnullRefPtr<typename types::CheckedExpression> const& expr = __jakt_match_value.expr;
return JaktInternal::ExplicitValue(((Jakt::DeprecatedString("return "sv) + TRY((((*this).codegen_expression(expr))))) + Jakt::DeprecatedString(";"sv)));
};/*case end*/
case 10: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::CheckedStatement::Continue>();
return JaktInternal::ExplicitValue(JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<DeprecatedString,ErrorOr<DeprecatedString>>{
auto __jakt_enum_value = (((((*this).control_flow_state)).passes_through_match));
if (__jakt_enum_value == true) {
return JaktInternal::ExplicitValue(Jakt::DeprecatedString("return JaktInternal::LoopContinue{};"sv));
}
else {
return JaktInternal::ExplicitValue(Jakt::DeprecatedString("continue;"sv));
}
}()))
);
};/*case end*/
case 9: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::CheckedStatement::Break>();
return JaktInternal::ExplicitValue(JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<DeprecatedString,ErrorOr<DeprecatedString>>{
auto __jakt_enum_value = (((((*this).control_flow_state)).passes_through_match));
if (__jakt_enum_value == true) {
return JaktInternal::ExplicitValue(Jakt::DeprecatedString("return JaktInternal::LoopBreak{};"sv));
}
else {
return JaktInternal::ExplicitValue(Jakt::DeprecatedString("break;"sv));
}
}()))
);
};/*case end*/
case 0: {
auto&& __jakt_match_value = __jakt_match_variant.template get<types::CheckedStatement::Expression>();NonnullRefPtr<typename types::CheckedExpression> const& expr = __jakt_match_value.expr;
return JaktInternal::ExplicitValue((TRY((((*this).codegen_expression(expr)))) + Jakt::DeprecatedString(";"sv)));
};/*case end*/
case 1: {
auto&& __jakt_match_value = __jakt_match_variant.template get<types::CheckedStatement::Defer>();NonnullRefPtr<typename types::CheckedStatement> const& statement = __jakt_match_value.statement;
return JaktInternal::ExplicitValue(({ Optional<DeprecatedString> __jakt_var_452; {
DeprecatedString output = Jakt::DeprecatedString(""sv);
(output += Jakt::DeprecatedString("ScopeGuard "sv));
(output += TRY((((*this).fresh_var()))));
(output += Jakt::DeprecatedString("([&] {\n"sv));
codegen::ControlFlowState const last_control_flow = ((*this).control_flow_state);
bool const old_inside_defer = ((*this).inside_defer);
(((((*this).control_flow_state)).passes_through_match) = false);
(((*this).inside_defer) = true);
(output += TRY((((*this).codegen_statement(statement)))));
(output += Jakt::DeprecatedString("});"sv));
(((*this).control_flow_state) = last_control_flow);
(((*this).inside_defer) = old_inside_defer);
__jakt_var_452 = output; goto __jakt_label_398;

}
__jakt_label_398:; __jakt_var_452.release_value(); }));
};/*case end*/
case 8: {
auto&& __jakt_match_value = __jakt_match_variant.template get<types::CheckedStatement::Return>();JaktInternal::Optional<NonnullRefPtr<typename types::CheckedExpression>> const& val = __jakt_match_value.val;
return JaktInternal::ExplicitValue(JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<DeprecatedString,ErrorOr<DeprecatedString>>{
auto __jakt_enum_value = (((val).has_value()));
if (__jakt_enum_value == true) {
return JaktInternal::ExplicitValue(((Jakt::DeprecatedString("return ("sv) + TRY((((*this).codegen_expression((val.value())))))) + Jakt::DeprecatedString(");"sv)));
}
else {
return JaktInternal::ExplicitValue(({ Optional<DeprecatedString> __jakt_var_453; {
__jakt_var_453 = JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<DeprecatedString,ErrorOr<DeprecatedString>>{
auto __jakt_enum_value = ((((((*this).current_function).value()))->can_throw));
if (__jakt_enum_value == true) {
return JaktInternal::ExplicitValue(Jakt::DeprecatedString("return {};"sv));
}
else {
return JaktInternal::ExplicitValue(Jakt::DeprecatedString("return;"sv));
}
}()))
; goto __jakt_label_399;

}
__jakt_label_399:; __jakt_var_453.release_value(); }));
}
}()))
);
};/*case end*/
case 6: {
auto&& __jakt_match_value = __jakt_match_variant.template get<types::CheckedStatement::Loop>();types::CheckedBlock const& block = __jakt_match_value.block;
return JaktInternal::ExplicitValue(({ Optional<DeprecatedString> __jakt_var_454; {
DeprecatedString output = Jakt::DeprecatedString(""sv);
if ((((((*this).debug_info)).statement_span_comments) && ((((statement)->span())).has_value()))){
(output += TRY((__jakt_format(Jakt::DeprecatedString("\n#line {}\n"sv),TRY((((((*this).debug_info)).span_to_source_location((((statement)->span()).value())))))))));
}
(output += Jakt::DeprecatedString("for (;;)"sv));
(add_newline = false);
codegen::ControlFlowState const last_control_flow = ((*this).control_flow_state);
(((*this).control_flow_state) = ((last_control_flow).enter_loop()));
DeprecatedString const block_str = TRY((((*this).codegen_block(block))));
(((*this).control_flow_state) = last_control_flow);
(output += block_str);
__jakt_var_454 = output; goto __jakt_label_400;

}
__jakt_label_400:; __jakt_var_454.release_value(); }));
};/*case end*/
case 7: {
auto&& __jakt_match_value = __jakt_match_variant.template get<types::CheckedStatement::While>();NonnullRefPtr<typename types::CheckedExpression> const& condition = __jakt_match_value.condition;
types::CheckedBlock const& block = __jakt_match_value.block;
return JaktInternal::ExplicitValue(({ Optional<DeprecatedString> __jakt_var_455; {
DeprecatedString output = Jakt::DeprecatedString(""sv);
if ((((((*this).debug_info)).statement_span_comments) && ((((statement)->span())).has_value()))){
(output += TRY((__jakt_format(Jakt::DeprecatedString("\n#line {}\n"sv),TRY((((((*this).debug_info)).span_to_source_location((((statement)->span()).value())))))))));
}
(output += Jakt::DeprecatedString("while ("sv));
(output += TRY((((*this).codegen_expression(condition)))));
(output += Jakt::DeprecatedString(")"sv));
{
codegen::ControlFlowState const last_control_flow = ((*this).control_flow_state);
(((*this).control_flow_state) = ((last_control_flow).enter_loop()));
DeprecatedString const code = TRY((((*this).codegen_block(block))));
(((*this).control_flow_state) = last_control_flow);
(output += code);
}

(add_newline = false);
__jakt_var_455 = output; goto __jakt_label_401;

}
__jakt_label_401:; __jakt_var_455.release_value(); }));
};/*case end*/
case 5: {
auto&& __jakt_match_value = __jakt_match_variant.template get<types::CheckedStatement::Block>();types::CheckedBlock const& block = __jakt_match_value.block;
return JaktInternal::ExplicitValue(TRY((((*this).codegen_block(block)))));
};/*case end*/
case 14: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::CheckedStatement::Garbage>();
{
utility::panic(Jakt::DeprecatedString("Garbage statement in codegen"sv));
}
};/*case end*/
case 2: {
auto&& __jakt_match_value = __jakt_match_variant.template get<types::CheckedStatement::DestructuringAssignment>();JaktInternal::DynamicArray<NonnullRefPtr<typename types::CheckedStatement>> const& vars = __jakt_match_value.vars;
NonnullRefPtr<typename types::CheckedStatement> const& var_decl = __jakt_match_value.var_decl;
return JaktInternal::ExplicitValue(({ Optional<DeprecatedString> __jakt_var_456; {
DeprecatedString output = Jakt::DeprecatedString(""sv);
(output += TRY((((*this).codegen_statement(var_decl)))));
{
JaktInternal::ArrayIterator<NonnullRefPtr<typename types::CheckedStatement>> _magic = ((vars).iterator());
for (;;){
JaktInternal::Optional<NonnullRefPtr<typename types::CheckedStatement>> _magic_value = ((_magic).next());
if ((!(((_magic_value).has_value())))){
break;
}
NonnullRefPtr<typename types::CheckedStatement> v = (_magic_value.value());
{
(output += TRY((((*this).codegen_statement(v)))));
}

}
}

__jakt_var_456 = output; goto __jakt_label_402;

}
__jakt_label_402:; __jakt_var_456.release_value(); }));
};/*case end*/
case 3: {
auto&& __jakt_match_value = __jakt_match_variant.template get<types::CheckedStatement::VarDecl>();types::VarId const& var_id = __jakt_match_value.var_id;
NonnullRefPtr<typename types::CheckedExpression> const& init = __jakt_match_value.init;
return JaktInternal::ExplicitValue(({ Optional<DeprecatedString> __jakt_var_457; {
NonnullRefPtr<types::CheckedVariable> const var = ((((*this).program))->get_variable(var_id));
DeprecatedString output = Jakt::DeprecatedString(""sv);
NonnullRefPtr<typename types::Type> const var_type = ((((*this).program))->get_type(((var)->type_id)));
(output += TRY((((*this).codegen_type(((var)->type_id))))));
(output += Jakt::DeprecatedString(" "sv));
if (((!(((var)->is_mutable))) && (!((((var_type)->index() == 27 /* Reference */) || ((var_type)->index() == 28 /* MutableReference */)))))){
(output += Jakt::DeprecatedString("const "sv));
}
(output += ((var)->name));
(output += Jakt::DeprecatedString(" = "sv));
(output += TRY((((*this).codegen_expression(init)))));
(output += Jakt::DeprecatedString(";"sv));
__jakt_var_457 = output; goto __jakt_label_403;

}
__jakt_label_403:; __jakt_var_457.release_value(); }));
};/*case end*/
case 13: {
auto&& __jakt_match_value = __jakt_match_variant.template get<types::CheckedStatement::InlineCpp>();JaktInternal::DynamicArray<DeprecatedString> const& lines = __jakt_match_value.lines;
return JaktInternal::ExplicitValue(({ Optional<DeprecatedString> __jakt_var_458; {
DeprecatedString output = Jakt::DeprecatedString(""sv);
{
JaktInternal::ArrayIterator<DeprecatedString> _magic = ((lines).iterator());
for (;;){
JaktInternal::Optional<DeprecatedString> _magic_value = ((_magic).next());
if ((!(((_magic_value).has_value())))){
break;
}
DeprecatedString line = (_magic_value.value());
{
DeprecatedString escaped_line = line;
(escaped_line = ((escaped_line).replace(Jakt::DeprecatedString("\\\""sv),Jakt::DeprecatedString("\""sv))));
(escaped_line = ((escaped_line).replace(Jakt::DeprecatedString("\\\\"sv),Jakt::DeprecatedString("\\"sv))));
(output += escaped_line);
}

}
}

__jakt_var_458 = output; goto __jakt_label_404;

}
__jakt_label_404:; __jakt_var_458.release_value(); }));
};/*case end*/
case 4: {
auto&& __jakt_match_value = __jakt_match_variant.template get<types::CheckedStatement::If>();NonnullRefPtr<typename types::CheckedExpression> const& condition = __jakt_match_value.condition;
types::CheckedBlock const& then_block = __jakt_match_value.then_block;
JaktInternal::Optional<NonnullRefPtr<typename types::CheckedStatement>> const& else_statement = __jakt_match_value.else_statement;
return JaktInternal::ExplicitValue(({ Optional<DeprecatedString> __jakt_var_459; {
DeprecatedString output = Jakt::DeprecatedString(""sv);
if ((((((*this).debug_info)).statement_span_comments) && ((((statement)->span())).has_value()))){
(output += TRY((__jakt_format(Jakt::DeprecatedString("\n#line {}\n"sv),TRY((((((*this).debug_info)).span_to_source_location((((statement)->span()).value())))))))));
}
(output += Jakt::DeprecatedString("if ("sv));
(output += TRY((((*this).codegen_expression(condition)))));
(output += Jakt::DeprecatedString(")"sv));
(output += TRY((((*this).codegen_block(then_block)))));
(output += JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<DeprecatedString,ErrorOr<DeprecatedString>>{
auto __jakt_enum_value = (((else_statement).has_value()));
if (__jakt_enum_value == true) {
return JaktInternal::ExplicitValue((Jakt::DeprecatedString("else "sv) + TRY((((*this).codegen_statement((else_statement.value())))))));
}
else {
return JaktInternal::ExplicitValue(Jakt::DeprecatedString(""sv));
}
}()))
);
(add_newline = false);
__jakt_var_459 = output; goto __jakt_label_405;

}
__jakt_label_405:; __jakt_var_459.release_value(); }));
};/*case end*/
case 12: {
auto&& __jakt_match_value = __jakt_match_variant.template get<types::CheckedStatement::Yield>();NonnullRefPtr<typename types::CheckedExpression> const& expr = __jakt_match_value.expr;
utility::Span const& span = __jakt_match_value.span;
return JaktInternal::ExplicitValue(({ Optional<DeprecatedString> __jakt_var_460; {
DeprecatedString output = Jakt::DeprecatedString(""sv);
if ((((((*this).entered_yieldable_blocks)).size()) == static_cast<size_t>(0ULL))){
utility::panic(Jakt::DeprecatedString("Must be in a block to yield"sv));
}
JaktInternal::Tuple<DeprecatedString,DeprecatedString> const var_name_end_label_ = (((((*this).entered_yieldable_blocks)).last()).value());
DeprecatedString const var_name = ((var_name_end_label_).template get<0>());
DeprecatedString const end_label = ((var_name_end_label_).template get<1>());

(output += var_name);
(output += Jakt::DeprecatedString(" = "sv));
(output += TRY((((*this).codegen_expression(expr)))));
(output += Jakt::DeprecatedString("; goto "sv));
(output += end_label);
(output += Jakt::DeprecatedString(";\n"sv));
__jakt_var_460 = output; goto __jakt_label_406;

}
__jakt_label_406:; __jakt_var_460.release_value(); }));
};/*case end*/
default: VERIFY_NOT_REACHED();}/*switch end*/
}()
)));
if (add_newline){
(output += Jakt::DeprecatedString("\n"sv));
}
return (output);
}
}

ErrorOr<DeprecatedString> codegen::CodeGenerator::codegen_enum(types::CheckedEnum const enum_) {
{
DeprecatedString output = Jakt::DeprecatedString(""sv);
if ((!(((((enum_).underlying_type_id)).equals(types::void_type_id()))))){
if (((((*this).program))->is_integer(((enum_).underlying_type_id)))){
(output += ((((Jakt::DeprecatedString("enum class "sv) + ((enum_).name)) + Jakt::DeprecatedString(": "sv)) + TRY((((*this).codegen_type(((enum_).underlying_type_id)))))) + Jakt::DeprecatedString(" {\n"sv)));
{
JaktInternal::ArrayIterator<types::CheckedEnumVariant> _magic = ((((enum_).variants)).iterator());
for (;;){
JaktInternal::Optional<types::CheckedEnumVariant> _magic_value = ((_magic).next());
if ((!(((_magic_value).has_value())))){
break;
}
types::CheckedEnumVariant variant = (_magic_value.value());
{
(output += JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_AT_LOOP(([&]() -> JaktInternal::ExplicitValueOrControlFlow<DeprecatedString, ErrorOr<DeprecatedString>>{
auto&& __jakt_match_variant = variant;
switch(__jakt_match_variant.index()) {
case 2: {
auto&& __jakt_match_value = __jakt_match_variant.template get<types::CheckedEnumVariant::WithValue>();DeprecatedString const& name = __jakt_match_value.name;
NonnullRefPtr<typename types::CheckedExpression> const& expr = __jakt_match_value.expr;
return JaktInternal::ExplicitValue((((name + Jakt::DeprecatedString(" = "sv)) + TRY((((*this).codegen_expression(expr))))) + Jakt::DeprecatedString(",\n"sv)));
};/*case end*/
default: {
return JaktInternal::ExplicitValue(({ Optional<DeprecatedString> __jakt_var_461; {
utility::todo(TRY((__jakt_format(Jakt::DeprecatedString("codegen_enum can't generate variant: {}"sv),variant))));
__jakt_var_461 = Jakt::DeprecatedString(""sv); goto __jakt_label_407;

}
__jakt_label_407:; __jakt_var_461.release_value(); }));
};/*case end*/
}/*switch end*/
}()
)));
}

}
}

return ((output + Jakt::DeprecatedString("};\n"sv)));
}
else {
utility::todo(Jakt::DeprecatedString("Enums with a non-integer underlying type"sv));
}

}
bool const is_generic = (!(((((enum_).generic_parameters)).is_empty())));
JaktInternal::DynamicArray<DeprecatedString> generic_parameter_names = (TRY((DynamicArray<DeprecatedString>::create_with({}))));
{
JaktInternal::ArrayIterator<types::CheckedGenericParameter> _magic = ((((enum_).generic_parameters)).iterator());
for (;;){
JaktInternal::Optional<types::CheckedGenericParameter> _magic_value = ((_magic).next());
if ((!(((_magic_value).has_value())))){
break;
}
types::CheckedGenericParameter generic_parameter = (_magic_value.value());
{
if (((((((*this).program))->get_type(((generic_parameter).type_id))))->index() == 18 /* TypeVariable */)){
DeprecatedString const name = ((((((*this).program))->get_type(((generic_parameter).type_id))))->get<types::Type::TypeVariable>()).name;
TRY((((generic_parameter_names).push(name))));
}
}

}
}

DeprecatedString template_args = utility::join(TRY((utility::prepend_to_each(generic_parameter_names,Jakt::DeprecatedString("typename "sv)))),Jakt::DeprecatedString(", "sv));
JaktInternal::DynamicArray<JaktInternal::Tuple<DeprecatedString,DeprecatedString>> common_fields = (TRY((DynamicArray<JaktInternal::Tuple<DeprecatedString,DeprecatedString>>::create_with({}))));
{
JaktInternal::ArrayIterator<types::CheckedField> _magic = ((((enum_).fields)).iterator());
for (;;){
JaktInternal::Optional<types::CheckedField> _magic_value = ((_magic).next());
if ((!(((_magic_value).has_value())))){
break;
}
types::CheckedField field = (_magic_value.value());
{
NonnullRefPtr<types::CheckedVariable> const variable = ((((*this).program))->get_variable(((field).variable_id)));
TRY((((common_fields).push((Tuple{((variable)->name), TRY((((*this).codegen_type(((variable)->type_id)))))})))));
}

}
}

(output += ((Jakt::DeprecatedString("namespace "sv) + ((enum_).name)) + Jakt::DeprecatedString("_Details {\n"sv)));
{
JaktInternal::ArrayIterator<types::CheckedEnumVariant> _magic = ((((enum_).variants)).iterator());
for (;;){
JaktInternal::Optional<types::CheckedEnumVariant> _magic_value = ((_magic).next());
if ((!(((_magic_value).has_value())))){
break;
}
types::CheckedEnumVariant variant = (_magic_value.value());
{
JaktInternal::DynamicArray<JaktInternal::Tuple<DeprecatedString,DeprecatedString>> const fields = JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_AT_LOOP(([&]() -> JaktInternal::ExplicitValueOrControlFlow<JaktInternal::DynamicArray<JaktInternal::Tuple<DeprecatedString,DeprecatedString>>, ErrorOr<DeprecatedString>>{
auto&& __jakt_match_variant = variant;
switch(__jakt_match_variant.index()) {
case 0: {
auto&& __jakt_match_value = __jakt_match_variant.template get<types::CheckedEnumVariant::Untyped>();DeprecatedString const& name = __jakt_match_value.name;
return JaktInternal::ExplicitValue(({ Optional<JaktInternal::DynamicArray<JaktInternal::Tuple<DeprecatedString,DeprecatedString>>> __jakt_var_462; {
if (is_generic){
(output += ((Jakt::DeprecatedString("template<"sv) + template_args) + Jakt::DeprecatedString(">\n"sv)));
}
(output += ((Jakt::DeprecatedString("struct "sv) + name) + Jakt::DeprecatedString(" {\n"sv)));
__jakt_var_462 = common_fields; goto __jakt_label_408;

}
__jakt_label_408:; __jakt_var_462.release_value(); }));
};/*case end*/
case 3: {
auto&& __jakt_match_value = __jakt_match_variant.template get<types::CheckedEnumVariant::StructLike>();DeprecatedString const& name = __jakt_match_value.name;
JaktInternal::DynamicArray<types::VarId> const& own_fields = __jakt_match_value.fields;
return JaktInternal::ExplicitValue(({ Optional<JaktInternal::DynamicArray<JaktInternal::Tuple<DeprecatedString,DeprecatedString>>> __jakt_var_463; {
JaktInternal::DynamicArray<JaktInternal::Tuple<DeprecatedString,DeprecatedString>> fields = (TRY((DynamicArray<JaktInternal::Tuple<DeprecatedString,DeprecatedString>>::create_with({}))));
{
JaktInternal::ArrayIterator<types::VarId> _magic = ((own_fields).iterator());
for (;;){
JaktInternal::Optional<types::VarId> _magic_value = ((_magic).next());
if ((!(((_magic_value).has_value())))){
break;
}
types::VarId field = (_magic_value.value());
{
NonnullRefPtr<types::CheckedVariable> const variable = ((((*this).program))->get_variable(field));
TRY((((fields).push((Tuple{((variable)->name), TRY((((*this).codegen_type(((variable)->type_id)))))})))));
}

}
}

if (is_generic){
(output += ((Jakt::DeprecatedString("template<"sv) + template_args) + Jakt::DeprecatedString(">\n"sv)));
}
(output += ((Jakt::DeprecatedString("struct "sv) + name) + Jakt::DeprecatedString(" {\n"sv)));
__jakt_var_463 = fields; goto __jakt_label_409;

}
__jakt_label_409:; __jakt_var_463.release_value(); }));
};/*case end*/
case 1: {
auto&& __jakt_match_value = __jakt_match_variant.template get<types::CheckedEnumVariant::Typed>();DeprecatedString const& name = __jakt_match_value.name;
types::TypeId const& type_id = __jakt_match_value.type_id;
return JaktInternal::ExplicitValue(({ Optional<JaktInternal::DynamicArray<JaktInternal::Tuple<DeprecatedString,DeprecatedString>>> __jakt_var_464; {
JaktInternal::DynamicArray<JaktInternal::Tuple<DeprecatedString,DeprecatedString>> fields = (TRY((DynamicArray<JaktInternal::Tuple<DeprecatedString,DeprecatedString>>::create_with({}))));
{
JaktInternal::ArrayIterator<JaktInternal::Tuple<DeprecatedString,DeprecatedString>> _magic = ((common_fields).iterator());
for (;;){
JaktInternal::Optional<JaktInternal::Tuple<DeprecatedString,DeprecatedString>> _magic_value = ((_magic).next());
if ((!(((_magic_value).has_value())))){
break;
}
JaktInternal::Tuple<DeprecatedString,DeprecatedString> field = (_magic_value.value());
{
TRY((((fields).push(field))));
}

}
}

TRY((((fields).push((Tuple{Jakt::DeprecatedString("value"sv), TRY((((*this).codegen_type(type_id))))})))));
if (is_generic){
(output += ((Jakt::DeprecatedString("template<"sv) + template_args) + Jakt::DeprecatedString(">\n"sv)));
}
(output += ((Jakt::DeprecatedString("struct "sv) + name) + Jakt::DeprecatedString("{\n"sv)));
__jakt_var_464 = fields; goto __jakt_label_410;

}
__jakt_label_410:; __jakt_var_464.release_value(); }));
};/*case end*/
default: {
return JaktInternal::ExplicitValue(({ Optional<JaktInternal::DynamicArray<JaktInternal::Tuple<DeprecatedString,DeprecatedString>>> __jakt_var_465; {
utility::todo(TRY((__jakt_format(Jakt::DeprecatedString("codegen enum variant: {}"sv),variant))));
__jakt_var_465 = (TRY((DynamicArray<JaktInternal::Tuple<DeprecatedString,DeprecatedString>>::create_with({})))); goto __jakt_label_411;

}
__jakt_label_411:; __jakt_var_465.release_value(); }));
};/*case end*/
}/*switch end*/
}()
));
{
JaktInternal::ArrayIterator<JaktInternal::Tuple<DeprecatedString,DeprecatedString>> _magic = ((fields).iterator());
for (;;){
JaktInternal::Optional<JaktInternal::Tuple<DeprecatedString,DeprecatedString>> _magic_value = ((_magic).next());
if ((!(((_magic_value).has_value())))){
break;
}
JaktInternal::Tuple<DeprecatedString,DeprecatedString> name__type__ = (_magic_value.value());
{
JaktInternal::Tuple<DeprecatedString,DeprecatedString> const jakt__name__type__ = name__type__;
DeprecatedString const name = ((jakt__name__type__).template get<0>());
DeprecatedString const type = ((jakt__name__type__).template get<1>());

(output += TRY((__jakt_format(Jakt::DeprecatedString("{} {};\n"sv),type,name))));
}

}
}

if ((!(((fields).is_empty())))){
(output += Jakt::DeprecatedString("template<"sv));
JaktInternal::DynamicArray<DeprecatedString> generic_typenames = (TRY((DynamicArray<DeprecatedString>::create_with({}))));
JaktInternal::DynamicArray<DeprecatedString> generic_argument_types = (TRY((DynamicArray<DeprecatedString>::create_with({}))));
JaktInternal::DynamicArray<DeprecatedString> initializers = (TRY((DynamicArray<DeprecatedString>::create_with({}))));
{
JaktInternal::Range<size_t> _magic = (JaktInternal::Range<size_t>{static_cast<size_t>(static_cast<size_t>(0ULL)),static_cast<size_t>(((fields).size()))});
for (;;){
JaktInternal::Optional<size_t> _magic_value = ((_magic).next());
if ((!(((_magic_value).has_value())))){
break;
}
size_t i = (_magic_value.value());
{
TRY((((generic_typenames).push(TRY((__jakt_format(Jakt::DeprecatedString("typename _MemberT{}"sv),i)))))));
TRY((((generic_argument_types).push(TRY((__jakt_format(Jakt::DeprecatedString("_MemberT{}&& member_{}"sv),i,i)))))));
DeprecatedString initializer = (((((fields)[i])).template get<0>()) + Jakt::DeprecatedString("{ forward<_MemberT"sv));
(initializer += (TRY((__jakt_format(Jakt::DeprecatedString("{}>(member_{}"sv),i,i))) + Jakt::DeprecatedString(")}"sv)));
TRY((((initializers).push(initializer))));
}

}
}

(output += utility::join(generic_typenames,Jakt::DeprecatedString(", "sv)));
(output += Jakt::DeprecatedString(">\n"sv));
(output += (((((variant).name()) + Jakt::DeprecatedString("("sv)) + utility::join(generic_argument_types,Jakt::DeprecatedString(", "sv))) + Jakt::DeprecatedString("):\n"sv)));
(output += (utility::join(initializers,Jakt::DeprecatedString(",\n"sv)) + Jakt::DeprecatedString("\n{}\n"sv)));
}
(output += Jakt::DeprecatedString("};\n"sv));
}

}
}

(output += Jakt::DeprecatedString("}\n"sv));
if (is_generic){
(output += ((Jakt::DeprecatedString("template<"sv) + template_args) + Jakt::DeprecatedString(">\n"sv)));
}
JaktInternal::DynamicArray<DeprecatedString> variant_names = (TRY((DynamicArray<DeprecatedString>::create_with({}))));
JaktInternal::DynamicArray<DeprecatedString> variant_arguments_array = (TRY((DynamicArray<DeprecatedString>::create_with({}))));
{
JaktInternal::ArrayIterator<types::CheckedEnumVariant> _magic = ((((enum_).variants)).iterator());
for (;;){
JaktInternal::Optional<types::CheckedEnumVariant> _magic_value = ((_magic).next());
if ((!(((_magic_value).has_value())))){
break;
}
types::CheckedEnumVariant variant = (_magic_value.value());
{
DeprecatedString argument = ((((enum_).name) + Jakt::DeprecatedString("_Details::"sv)) + ((variant).name()));
if (is_generic){
(argument += TRY((__jakt_format(Jakt::DeprecatedString("<{}>"sv),utility::join(generic_parameter_names,Jakt::DeprecatedString(", "sv))))));
}
TRY((((variant_arguments_array).push(argument))));
TRY((((variant_names).push(((variant).name())))));
}

}
}

DeprecatedString const variant_args = utility::join(variant_arguments_array,Jakt::DeprecatedString(", "sv));
(output += TRY((__jakt_format(Jakt::DeprecatedString("struct {} : public Variant<{}>"sv),((enum_).name),variant_args))));
if (((enum_).is_boxed)){
(output += TRY((__jakt_format(Jakt::DeprecatedString(", public RefCounted<{}"sv),((enum_).name)))));
if (is_generic){
(output += TRY((__jakt_format(Jakt::DeprecatedString("<{}>"sv),utility::join(generic_parameter_names,Jakt::DeprecatedString(", "sv))))));
}
(output += Jakt::DeprecatedString(">"sv));
}
(output += Jakt::DeprecatedString(" {\n"sv));
(output += ((Jakt::DeprecatedString("using Variant<"sv) + variant_args) + Jakt::DeprecatedString(">::Variant;\n"sv)));
{
JaktInternal::ArrayIterator<DeprecatedString> _magic = ((variant_names).iterator());
for (;;){
JaktInternal::Optional<DeprecatedString> _magic_value = ((_magic).next());
if ((!(((_magic_value).has_value())))){
break;
}
DeprecatedString name = (_magic_value.value());
{
(output += (((((Jakt::DeprecatedString("    using "sv) + name) + Jakt::DeprecatedString(" = "sv)) + ((enum_).name)) + Jakt::DeprecatedString("_Details::"sv)) + name));
if (is_generic){
(output += Jakt::DeprecatedString("<"sv));
(output += utility::join(generic_parameter_names,Jakt::DeprecatedString(", "sv)));
(output += Jakt::DeprecatedString(">"sv));
}
(output += Jakt::DeprecatedString(";\n"sv));
}

}
}

if (((enum_).is_boxed)){
DeprecatedString fully_instantiated_name = ((enum_).name);
if (is_generic){
(fully_instantiated_name += TRY((__jakt_format(Jakt::DeprecatedString("<{}>"sv),utility::join(generic_parameter_names,Jakt::DeprecatedString(", "sv))))));
}
(output += Jakt::DeprecatedString("template<typename V, typename... Args> static auto create(Args&&... args) {\n"sv));
(output += TRY((__jakt_format(Jakt::DeprecatedString("return adopt_nonnull_ref_or_enomem(new (nothrow) {}(V(forward<Args>(args)...)));\n"sv),fully_instantiated_name))));
(output += Jakt::DeprecatedString("}\n"sv));
}
if (((((enum_).generic_parameters)).is_empty())){
(output += Jakt::DeprecatedString("ErrorOr<DeprecatedString> debug_description() const;\n"sv));
}
else {
(output += TRY((((*this).codegen_enum_debug_description_getter(enum_,true)))));
}

{
JaktInternal::ArrayIterator<JaktInternal::Tuple<DeprecatedString,DeprecatedString>> _magic = ((common_fields).iterator());
for (;;){
JaktInternal::Optional<JaktInternal::Tuple<DeprecatedString,DeprecatedString>> _magic_value = ((_magic).next());
if ((!(((_magic_value).has_value())))){
break;
}
JaktInternal::Tuple<DeprecatedString,DeprecatedString> field_name__type__ = (_magic_value.value());
{
JaktInternal::Tuple<DeprecatedString,DeprecatedString> const jakt__field_name__type__ = field_name__type__;
DeprecatedString const field_name = ((jakt__field_name__type__).template get<0>());
DeprecatedString const type = ((jakt__field_name__type__).template get<1>());

(output += TRY((__jakt_format(Jakt::DeprecatedString("{} const& {}() const {{ switch(this->index()) {{"sv),type,field_name))));
{
JaktInternal::Range<size_t> _magic = (JaktInternal::Range<size_t>{static_cast<size_t>(static_cast<size_t>(0ULL)),static_cast<size_t>(((((enum_).variants)).size()))});
for (;;){
JaktInternal::Optional<size_t> _magic_value = ((_magic).next());
if ((!(((_magic_value).has_value())))){
break;
}
size_t i = (_magic_value.value());
{
types::CheckedEnumVariant const variant = ((((enum_).variants))[i]);
DeprecatedString const name = ((variant).name());
(output += TRY((__jakt_format(Jakt::DeprecatedString("case {} /* {} */: "sv),i,name))));
(output += TRY((__jakt_format(Jakt::DeprecatedString("return this->template get<{}::{}>().{};\n"sv),((enum_).name),name,field_name))));
}

}
}

(output += Jakt::DeprecatedString("default: VERIFY_NOT_REACHED();\n"sv));
(output += Jakt::DeprecatedString("}\n}\n"sv));
}

}
}

NonnullRefPtr<types::Scope> const enum_scope = TRY((((((*this).program))->get_scope(((enum_).scope_id)))));
{
JaktInternal::DictionaryIterator<DeprecatedString,JaktInternal::DynamicArray<types::FunctionId>> _magic = ((((enum_scope)->functions)).iterator());
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
NonnullRefPtr<types::CheckedFunction> const function_ = ((((*this).program))->get_function(function_id));
JaktInternal::Optional<NonnullRefPtr<types::CheckedFunction>> const previous_function_id = ((*this).current_function);
(((*this).current_function) = static_cast<JaktInternal::Optional<NonnullRefPtr<types::CheckedFunction>>>(function_));
ScopeGuard __jakt_var_466([&] {
(((*this).current_function) = previous_function_id);
});
if ((!(((((function_)->type)).index() == 2 /* ImplicitEnumConstructor */)))){
if ((((((enum_).generic_parameters)).is_empty()) && ((((((function_)->generics))->params)).is_empty()))){
(output += TRY((((*this).codegen_function_predecl(function_,true)))));
}
else {
(output += TRY((((*this).codegen_function(function_,true)))));
}

}
}

}
}

}

}
}

(output += Jakt::DeprecatedString("};\n"sv));
(((*this).deferred_output) += TRY((((*this).codegen_ak_formatter(((enum_).name),generic_parameter_names)))));
return (output);
}
}

ErrorOr<DeprecatedString> codegen::CodeGenerator::codegen_struct_type(types::StructId const id,bool const as_namespace) const {
{
DeprecatedString output = Jakt::DeprecatedString(""sv);
NonnullRefPtr<types::Module> const type_module = ((((*this).program))->get_module(((id).module)));
types::CheckedStruct const checked_struct = ((((*this).program))->get_struct(id));
if (((!(as_namespace)) && ((((checked_struct).record_type)).index() == 1 /* Class */))){
(output += Jakt::DeprecatedString("NonnullRefPtr<"sv));
(output += TRY((((*this).codegen_namespace_qualifier(((checked_struct).scope_id),true,JaktInternal::OptionalNone())))));
(output += ((checked_struct).name_for_codegen()));
(output += Jakt::DeprecatedString(">"sv));
}
else {
(output += TRY((((*this).codegen_namespace_qualifier(((checked_struct).scope_id),true,JaktInternal::OptionalNone())))));
(output += ((checked_struct).name_for_codegen()));
}

return (output);
}
}

ErrorOr<DeprecatedString> codegen::CodeGenerator::codegen_struct_predecl(types::CheckedStruct const struct_) {
{
if (((((struct_).definition_linkage)).index() == 1 /* External */)){
return (Jakt::DeprecatedString(""sv));
}
DeprecatedString output = Jakt::DeprecatedString(""sv);
if ((!(((((struct_).generic_parameters)).is_empty())))){
(output += Jakt::DeprecatedString("template <"sv));
bool first = true;
{
JaktInternal::ArrayIterator<types::CheckedGenericParameter> _magic = ((((struct_).generic_parameters)).iterator());
for (;;){
JaktInternal::Optional<types::CheckedGenericParameter> _magic_value = ((_magic).next());
if ((!(((_magic_value).has_value())))){
break;
}
types::CheckedGenericParameter generic_parameter = (_magic_value.value());
{
if (first){
(first = false);
}
else {
(output += Jakt::DeprecatedString(","sv));
}

(output += Jakt::DeprecatedString("typename "sv));
(output += TRY((((*this).codegen_type(((generic_parameter).type_id))))));
}

}
}

(output += Jakt::DeprecatedString(">"sv));
}
(output += JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<DeprecatedString, ErrorOr<DeprecatedString>>{
auto&& __jakt_match_variant = ((struct_).record_type);
switch(__jakt_match_variant.index()) {
case 1: {
auto&& __jakt_match_value = __jakt_match_variant.template get<parser::RecordType::Class>();return JaktInternal::ExplicitValue(Jakt::DeprecatedString("class "sv));
};/*case end*/
case 0: {
auto&& __jakt_match_value = __jakt_match_variant.template get<parser::RecordType::Struct>();return JaktInternal::ExplicitValue(Jakt::DeprecatedString("struct "sv));
};/*case end*/
default: {
return JaktInternal::ExplicitValue(Jakt::DeprecatedString(""sv));
};/*case end*/
}/*switch end*/
}()
)));
(output += ((struct_).name_for_codegen()));
(output += Jakt::DeprecatedString(";"sv));
return (output);
}
}

ErrorOr<DeprecatedString> codegen::CodeGenerator::codegen_generic_match(NonnullRefPtr<typename types::CheckedExpression> const expr,JaktInternal::DynamicArray<types::CheckedMatchCase> const cases,types::TypeId const return_type_id,bool const all_variants_constant) {
{
DeprecatedString output = Jakt::DeprecatedString(""sv);
bool is_generic_enum = false;
{
JaktInternal::ArrayIterator<types::CheckedMatchCase> _magic = ((cases).iterator());
for (;;){
JaktInternal::Optional<types::CheckedMatchCase> _magic_value = ((_magic).next());
if ((!(((_magic_value).has_value())))){
break;
}
types::CheckedMatchCase case_ = (_magic_value.value());
{
if (((case_).index() == 0 /* EnumVariant */)){
(is_generic_enum = true);
break;
}
}

}
}

bool const match_values_all_constant = (all_variants_constant && (!(is_generic_enum)));
(output += ((((*this).control_flow_state)).choose_control_flow_macro()));
(output += (TRY((__jakt_format(Jakt::DeprecatedString("(([&]() -> JaktInternal::ExplicitValueOrControlFlow<{},{}>"sv),TRY((((*this).codegen_type(return_type_id)))),TRY((((*this).codegen_function_return_type((((*this).current_function).value())))))))) + Jakt::DeprecatedString("{\n"sv)));
if (is_generic_enum){
(output += Jakt::DeprecatedString("auto&& __jakt_enum_value = JaktInternal::deref_if_ref_pointer("sv));
}
else {
(output += Jakt::DeprecatedString("auto __jakt_enum_value = ("sv));
}

(output += TRY((((*this).codegen_expression(expr)))));
(output += Jakt::DeprecatedString(");\n"sv));
bool has_default = false;
bool first = true;
{
JaktInternal::ArrayIterator<types::CheckedMatchCase> _magic = ((cases).iterator());
for (;;){
JaktInternal::Optional<types::CheckedMatchCase> _magic_value = ((_magic).next());
if ((!(((_magic_value).has_value())))){
break;
}
types::CheckedMatchCase case_ = (_magic_value.value());
{
JaktInternal::DynamicArray<NonnullRefPtr<typename types::CheckedStatement>> const defaults = ((case_).defaults());
JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_AT_LOOP(([&]() -> JaktInternal::ExplicitValueOrControlFlow<void, ErrorOr<DeprecatedString>>{
auto&& __jakt_match_variant = case_;
switch(__jakt_match_variant.index()) {
case 0: {
auto&& __jakt_match_value = __jakt_match_variant.template get<types::CheckedMatchCase::EnumVariant>();DeprecatedString const& name = __jakt_match_value.name;
JaktInternal::DynamicArray<parser::EnumVariantPatternArgument> const& args = __jakt_match_value.args;
types::TypeId const& subject_type_id = __jakt_match_value.subject_type_id;
types::ScopeId const& scope_id = __jakt_match_value.scope_id;
types::CheckedMatchBody const& body = __jakt_match_value.body;
{
types::CheckedEnum const enum_ = ((((*this).program))->get_enum(JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_AT_LOOP_NESTED_MATCH(([&]() -> JaktInternal::ExplicitValueOrControlFlow<types::EnumId, ErrorOr<DeprecatedString>>{
auto&& __jakt_match_variant = *((((*this).program))->get_type(subject_type_id));
switch(__jakt_match_variant.index()) {
case 24: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::Type::Enum>();
types::EnumId const& enum_id = __jakt_match_value.value;
return JaktInternal::ExplicitValue(enum_id);
};/*case end*/
case 20: {
auto&& __jakt_match_value = __jakt_match_variant.template get<types::Type::GenericEnumInstance>();types::EnumId const& id = __jakt_match_value.id;
return JaktInternal::ExplicitValue(id);
};/*case end*/
default: {
{
utility::panic(TRY((__jakt_format(Jakt::DeprecatedString("Unexpected type in IsEnumVariant: {}"sv),((((*this).program))->get_type(subject_type_id))))));
}
};/*case end*/
}/*switch end*/
}()
))));
i64 variant_index = static_cast<i64>(0LL);
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
break;
}
((variant_index++));
}

}
}

(output += TRY((__jakt_format(Jakt::DeprecatedString("if (__jakt_enum_value.index() == {} /* {} */) {{\n"sv),variant_index,name))));
DeprecatedString variant_type_name = Jakt::DeprecatedString(""sv);
DeprecatedString const qualifier = TRY((((*this).codegen_type_possibly_as_namespace(subject_type_id,true))));
if ((!(((qualifier).is_empty())))){
(variant_type_name += Jakt::DeprecatedString("typename JaktInternal::RemoveRefPtr<"sv));
(variant_type_name += qualifier);
(variant_type_name += Jakt::DeprecatedString(">::"sv));
}
(variant_type_name += name);
(output += Jakt::DeprecatedString("auto& __jakt_match_value = __jakt_enum_value.template get<"sv));
(output += variant_type_name);
(output += Jakt::DeprecatedString(">();\n"sv));
{
JaktInternal::ArrayIterator<parser::EnumVariantPatternArgument> _magic = ((args).iterator());
for (;;){
JaktInternal::Optional<parser::EnumVariantPatternArgument> _magic_value = ((_magic).next());
if ((!(((_magic_value).has_value())))){
break;
}
parser::EnumVariantPatternArgument arg = (_magic_value.value());
{
(output += Jakt::DeprecatedString("auto& "sv));
(output += ((arg).binding));
(output += Jakt::DeprecatedString(" = __jakt_match_value."sv));
(output += ((arg).name).value_or_lazy_evaluated([&] { return Jakt::DeprecatedString("value"sv); }));
(output += Jakt::DeprecatedString(";\n"sv));
}

}
}

{
JaktInternal::ArrayIterator<NonnullRefPtr<typename types::CheckedStatement>> _magic = ((defaults).iterator());
for (;;){
JaktInternal::Optional<NonnullRefPtr<typename types::CheckedStatement>> _magic_value = ((_magic).next());
if ((!(((_magic_value).has_value())))){
break;
}
NonnullRefPtr<typename types::CheckedStatement> default_ = (_magic_value.value());
{
(output += TRY((((*this).codegen_statement(default_)))));
}

}
}

(output += TRY((((*this).codegen_match_body(body,return_type_id)))));
(output += Jakt::DeprecatedString("}\n"sv));
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 2: {
auto&& __jakt_match_value = __jakt_match_variant.template get<types::CheckedMatchCase::CatchAll>();bool const& has_arguments = __jakt_match_value.has_arguments;
types::CheckedMatchBody const& body = __jakt_match_value.body;
utility::Span const& marker_span = __jakt_match_value.marker_span;
{
if (has_arguments){
utility::panic(Jakt::DeprecatedString("Bindings should not be present in a generic else"sv));
}
(has_default = true);
if (first){
(output += Jakt::DeprecatedString("{"sv));
}
else {
(output += Jakt::DeprecatedString("else {\n"sv));
}

{
JaktInternal::ArrayIterator<NonnullRefPtr<typename types::CheckedStatement>> _magic = ((defaults).iterator());
for (;;){
JaktInternal::Optional<NonnullRefPtr<typename types::CheckedStatement>> _magic_value = ((_magic).next());
if ((!(((_magic_value).has_value())))){
break;
}
NonnullRefPtr<typename types::CheckedStatement> default_ = (_magic_value.value());
{
(output += TRY((((*this).codegen_statement(default_)))));
}

}
}

(output += TRY((((*this).codegen_match_body(body,return_type_id)))));
(output += Jakt::DeprecatedString("}\n"sv));
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 1: {
auto&& __jakt_match_value = __jakt_match_variant.template get<types::CheckedMatchCase::Expression>();NonnullRefPtr<typename types::CheckedExpression> const& expression = __jakt_match_value.expression;
types::CheckedMatchBody const& body = __jakt_match_value.body;
utility::Span const& marker_span = __jakt_match_value.marker_span;
{
if ((!(first))){
(output += Jakt::DeprecatedString("else "sv));
}
if (((expression)->index() == 8 /* Range */)){
JaktInternal::Optional<NonnullRefPtr<typename types::CheckedExpression>> const from = ((expression)->get<types::CheckedExpression::Range>()).from;
JaktInternal::Optional<NonnullRefPtr<typename types::CheckedExpression>> const to = ((expression)->get<types::CheckedExpression::Range>()).to;
(output += Jakt::DeprecatedString("if (__jakt_enum_value"sv));
if (((from).has_value())){
(output += Jakt::DeprecatedString(" >= "sv));
(output += TRY((((*this).codegen_expression((from.value()))))));
}
if (((to).has_value())){
if (((from).has_value())){
(output += Jakt::DeprecatedString("&& __jakt_enum_value "sv));
}
(output += Jakt::DeprecatedString("< "sv));
(output += TRY((((*this).codegen_expression((to.value()))))));
}
}
else {
(output += Jakt::DeprecatedString("if (__jakt_enum_value == "sv));
(output += TRY((((*this).codegen_expression(expression)))));
}

(output += Jakt::DeprecatedString(") {\n"sv));
(output += TRY((((*this).codegen_match_body(body,return_type_id)))));
(output += Jakt::DeprecatedString("}\n"sv));
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
default: VERIFY_NOT_REACHED();}/*switch end*/
}()
));
(first = false);
}

}
}

if ((((return_type_id).equals(types::void_type_id())) || ((return_type_id).equals(types::unknown_type_id())))){
(output += Jakt::DeprecatedString("return JaktInternal::ExplicitValue<void>();\n"sv));
}
else if ((!(has_default))){
(output += Jakt::DeprecatedString("VERIFY_NOT_REACHED();\n"sv));
}
(output += Jakt::DeprecatedString("}()))\n"sv));
return (output);
}
}

ErrorOr<DeprecatedString> codegen::CodeGenerator::codegen_checked_binary_op(NonnullRefPtr<typename types::CheckedExpression> const lhs,NonnullRefPtr<typename types::CheckedExpression> const rhs,parser::BinaryOperator const op,types::TypeId const type_id) {
{
DeprecatedString output = Jakt::DeprecatedString(""sv);
(output += Jakt::DeprecatedString("JaktInternal::"sv));
(output += JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<DeprecatedString, ErrorOr<DeprecatedString>>{
auto&& __jakt_match_variant = op;
switch(__jakt_match_variant.index()) {
case 0: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename parser::BinaryOperator::Add>();
return JaktInternal::ExplicitValue(Jakt::DeprecatedString("checked_add"sv));
};/*case end*/
case 1: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename parser::BinaryOperator::Subtract>();
return JaktInternal::ExplicitValue(Jakt::DeprecatedString("checked_sub"sv));
};/*case end*/
case 2: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename parser::BinaryOperator::Multiply>();
return JaktInternal::ExplicitValue(Jakt::DeprecatedString("checked_mul"sv));
};/*case end*/
case 3: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename parser::BinaryOperator::Divide>();
return JaktInternal::ExplicitValue(Jakt::DeprecatedString("checked_div"sv));
};/*case end*/
case 4: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename parser::BinaryOperator::Modulo>();
return JaktInternal::ExplicitValue(Jakt::DeprecatedString("checked_mod"sv));
};/*case end*/
default: {
{
utility::panic(TRY((__jakt_format(Jakt::DeprecatedString("Checked binary operation codegen is not supported for BinaryOperator::{}"sv),op))));
}
};/*case end*/
}/*switch end*/
}()
)));
(output += Jakt::DeprecatedString("<"sv));
(output += TRY((((*this).codegen_type(type_id)))));
(output += Jakt::DeprecatedString(">("sv));
(output += TRY((((*this).codegen_expression(lhs)))));
(output += Jakt::DeprecatedString(","sv));
(output += TRY((((*this).codegen_expression(rhs)))));
(output += Jakt::DeprecatedString(")"sv));
return (output);
}
}

ErrorOr<JaktInternal::DynamicArray<DeprecatedString>> codegen::CodeGenerator::extract_dependencies_from_enum(types::EnumId const enum_id,JaktInternal::Dictionary<DeprecatedString,JaktInternal::DynamicArray<DeprecatedString>> const dependency_graph,bool const top_level) const {
{
JaktInternal::DynamicArray<DeprecatedString> dependencies = (TRY((DynamicArray<DeprecatedString>::create_with({}))));
types::CheckedEnum const enum_ = ((((*this).program))->get_enum(enum_id));
if (((((enum_).definition_linkage)).index() == 1 /* External */)){
return (dependencies);
}
if ((((enum_).is_boxed) && (!(top_level)))){
return (dependencies);
}
TRY((((dependencies).push(TRY((((((enum_).type_id)).to_string())))))));
if ((!(((((enum_).underlying_type_id)).equals(types::unknown_type_id()))))){
JaktInternal::DynamicArray<DeprecatedString> const inner_dependencies = TRY((((*this).extract_dependencies_from(((enum_).underlying_type_id),dependency_graph,false))));
{
JaktInternal::ArrayIterator<DeprecatedString> _magic = ((inner_dependencies).iterator());
for (;;){
JaktInternal::Optional<DeprecatedString> _magic_value = ((_magic).next());
if ((!(((_magic_value).has_value())))){
break;
}
DeprecatedString dependency = (_magic_value.value());
{
TRY((((dependencies).push(dependency))));
}

}
}

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
JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_AT_LOOP(([&]() -> JaktInternal::ExplicitValueOrControlFlow<void, ErrorOr<JaktInternal::DynamicArray<DeprecatedString>>>{
auto&& __jakt_match_variant = variant;
switch(__jakt_match_variant.index()) {
case 1: {
auto&& __jakt_match_value = __jakt_match_variant.template get<types::CheckedEnumVariant::Typed>();types::TypeId const& type_id = __jakt_match_value.type_id;
{
JaktInternal::DynamicArray<DeprecatedString> const inner_dependencies = TRY((((*this).extract_dependencies_from(type_id,dependency_graph,false))));
{
JaktInternal::ArrayIterator<DeprecatedString> _magic = ((inner_dependencies).iterator());
for (;;){
JaktInternal::Optional<DeprecatedString> _magic_value = ((_magic).next());
if ((!(((_magic_value).has_value())))){
break;
}
DeprecatedString dependency = (_magic_value.value());
{
TRY((((dependencies).push(dependency))));
}

}
}

}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 3: {
auto&& __jakt_match_value = __jakt_match_variant.template get<types::CheckedEnumVariant::StructLike>();JaktInternal::DynamicArray<types::VarId> const& fields = __jakt_match_value.fields;
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
types::TypeId const type_id = ((((((*this).program))->get_variable(field)))->type_id);
JaktInternal::DynamicArray<DeprecatedString> const inner_dependencies = TRY((((*this).extract_dependencies_from(type_id,dependency_graph,false))));
{
JaktInternal::ArrayIterator<DeprecatedString> _magic = ((inner_dependencies).iterator());
for (;;){
JaktInternal::Optional<DeprecatedString> _magic_value = ((_magic).next());
if ((!(((_magic_value).has_value())))){
break;
}
DeprecatedString dependency = (_magic_value.value());
{
TRY((((dependencies).push(dependency))));
}

}
}

}

}
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
}

}
}

return (dependencies);
}
}

ErrorOr<DeprecatedString> codegen::CodeGenerator::codegen_expression(NonnullRefPtr<typename types::CheckedExpression> const expression) {
{
return (JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<DeprecatedString, ErrorOr<DeprecatedString>>{
auto&& __jakt_match_variant = *expression;
switch(__jakt_match_variant.index()) {
case 8: {
auto&& __jakt_match_value = __jakt_match_variant.template get<types::CheckedExpression::Range>();JaktInternal::Optional<NonnullRefPtr<typename types::CheckedExpression>> const& from = __jakt_match_value.from;
JaktInternal::Optional<NonnullRefPtr<typename types::CheckedExpression>> const& to = __jakt_match_value.to;
types::TypeId const& type_id = __jakt_match_value.type_id;
return JaktInternal::ExplicitValue(({ Optional<DeprecatedString> __jakt_var_467; {
DeprecatedString output = Jakt::DeprecatedString(""sv);
NonnullRefPtr<typename types::Type> const type = ((((*this).program))->get_type(type_id));
types::TypeId const index_type = JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<types::TypeId, ErrorOr<DeprecatedString>>{
auto&& __jakt_match_variant = *type;
switch(__jakt_match_variant.index()) {
case 19: {
auto&& __jakt_match_value = __jakt_match_variant.template get<types::Type::GenericInstance>();types::StructId const& id = __jakt_match_value.id;
JaktInternal::DynamicArray<types::TypeId> const& args = __jakt_match_value.args;
return JaktInternal::ExplicitValue(((args)[static_cast<i64>(0LL)]));
};/*case end*/
default: {
{
utility::panic(Jakt::DeprecatedString("Internal error: range expression doesn't have Range type"sv));
}
};/*case end*/
}/*switch end*/
}()
));
(output += Jakt::DeprecatedString("("sv));
(output += TRY((((*this).codegen_type(type_id)))));
(output += Jakt::DeprecatedString("{"sv));
(output += Jakt::DeprecatedString("static_cast<"sv));
(output += TRY((((*this).codegen_type(index_type)))));
(output += Jakt::DeprecatedString(">("sv));
if (((from).has_value())){
(output += TRY((((*this).codegen_expression((from.value()))))));
}
else {
(output += Jakt::DeprecatedString("0LL"sv));
}

(output += Jakt::DeprecatedString("),static_cast<"sv));
(output += TRY((((*this).codegen_type(index_type)))));
(output += Jakt::DeprecatedString(">("sv));
if (((to).has_value())){
(output += TRY((((*this).codegen_expression((to.value()))))));
}
else {
(output += Jakt::DeprecatedString("9223372036854775807LL"sv));
}

(output += Jakt::DeprecatedString(")})"sv));
__jakt_var_467 = output; goto __jakt_label_412;

}
__jakt_label_412:; __jakt_var_467.release_value(); }));
};/*case end*/
case 23: {
auto&& __jakt_match_value = __jakt_match_variant.template get<types::CheckedExpression::OptionalNone>();return JaktInternal::ExplicitValue(Jakt::DeprecatedString("JaktInternal::OptionalNone()"sv));
};/*case end*/
case 24: {
auto&& __jakt_match_value = __jakt_match_variant.template get<types::CheckedExpression::OptionalSome>();NonnullRefPtr<typename types::CheckedExpression> const& expr = __jakt_match_value.expr;
types::TypeId const& type_id = __jakt_match_value.type_id;
return JaktInternal::ExplicitValue(((((Jakt::DeprecatedString("static_cast<"sv) + TRY((((*this).codegen_type(type_id))))) + Jakt::DeprecatedString(">("sv)) + TRY((((*this).codegen_expression(expr))))) + Jakt::DeprecatedString(")"sv)));
};/*case end*/
case 25: {
auto&& __jakt_match_value = __jakt_match_variant.template get<types::CheckedExpression::ForcedUnwrap>();NonnullRefPtr<typename types::CheckedExpression> const& expr = __jakt_match_value.expr;
types::TypeId const& type_id = __jakt_match_value.type_id;
return JaktInternal::ExplicitValue(((Jakt::DeprecatedString("("sv) + TRY((((*this).codegen_expression(expr))))) + Jakt::DeprecatedString(".value())"sv)));
};/*case end*/
case 2: {
auto&& __jakt_match_value = __jakt_match_variant.template get<types::CheckedExpression::QuotedString>();types::CheckedStringLiteral const& val = __jakt_match_value.val;
return JaktInternal::ExplicitValue(({ Optional<DeprecatedString> __jakt_var_468; {
DeprecatedString const original_string = ((val).to_string());
DeprecatedString const escaped_value = ((original_string).replace(Jakt::DeprecatedString("\n"sv),Jakt::DeprecatedString("\\n"sv)));
__jakt_var_468 = JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<DeprecatedString,ErrorOr<DeprecatedString>>{
auto __jakt_enum_value = (((((val).type_id)).equals(types::builtin( types::BuiltinType { typename types::BuiltinType::JaktString() } ))));
if (__jakt_enum_value == true) {
return JaktInternal::ExplicitValue(((Jakt::DeprecatedString("Jakt::DeprecatedString(\""sv) + escaped_value) + Jakt::DeprecatedString("\"sv)"sv)));
}
else {
return JaktInternal::ExplicitValue(({ Optional<DeprecatedString> __jakt_var_469; {
DeprecatedString const error_handler = JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<DeprecatedString,ErrorOr<DeprecatedString>>{
auto __jakt_enum_value = (((val).may_throw));
if (__jakt_enum_value == true) {
return JaktInternal::ExplicitValue(Jakt::DeprecatedString("TRY"sv));
}
else {
return JaktInternal::ExplicitValue(Jakt::DeprecatedString(""sv));
}
}()))
;
__jakt_var_469 = TRY((__jakt_format(Jakt::DeprecatedString("{}({}::from_string_literal(\"{}\"sv))"sv),error_handler,TRY((((*this).codegen_type(((val).type_id))))),escaped_value))); goto __jakt_label_414;

}
__jakt_label_414:; __jakt_var_469.release_value(); }));
}
}()))
; goto __jakt_label_413;

}
__jakt_label_413:; __jakt_var_468.release_value(); }));
};/*case end*/
case 3: {
auto&& __jakt_match_value = __jakt_match_variant.template get<types::CheckedExpression::ByteConstant>();DeprecatedString const& val = __jakt_match_value.val;
return JaktInternal::ExplicitValue(((Jakt::DeprecatedString("'"sv) + val) + Jakt::DeprecatedString("'"sv)));
};/*case end*/
case 4: {
auto&& __jakt_match_value = __jakt_match_variant.template get<types::CheckedExpression::CharacterConstant>();DeprecatedString const& val = __jakt_match_value.val;
return JaktInternal::ExplicitValue(((Jakt::DeprecatedString("'"sv) + val) + Jakt::DeprecatedString("'"sv)));
};/*case end*/
case 22: {
auto&& __jakt_match_value = __jakt_match_variant.template get<types::CheckedExpression::Var>();NonnullRefPtr<types::CheckedVariable> const& var = __jakt_match_value.var;
return JaktInternal::ExplicitValue(JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<DeprecatedString,ErrorOr<DeprecatedString>>{
auto __jakt_enum_value = (((var)->name));
if (__jakt_enum_value == Jakt::DeprecatedString("this"sv)) {
return JaktInternal::ExplicitValue(Jakt::DeprecatedString("*this"sv));
}
else {
return JaktInternal::ExplicitValue(((var)->name));
}
}()))
);
};/*case end*/
case 12: {
auto&& __jakt_match_value = __jakt_match_variant.template get<types::CheckedExpression::IndexedExpression>();NonnullRefPtr<typename types::CheckedExpression> const& expr = __jakt_match_value.expr;
NonnullRefPtr<typename types::CheckedExpression> const& index = __jakt_match_value.index;
return JaktInternal::ExplicitValue(((((Jakt::DeprecatedString("(("sv) + TRY((((*this).codegen_expression(expr))))) + Jakt::DeprecatedString(")["sv)) + TRY((((*this).codegen_expression(index))))) + Jakt::DeprecatedString("])"sv)));
};/*case end*/
case 13: {
auto&& __jakt_match_value = __jakt_match_variant.template get<types::CheckedExpression::IndexedDictionary>();NonnullRefPtr<typename types::CheckedExpression> const& expr = __jakt_match_value.expr;
NonnullRefPtr<typename types::CheckedExpression> const& index = __jakt_match_value.index;
return JaktInternal::ExplicitValue(((((Jakt::DeprecatedString("(("sv) + TRY((((*this).codegen_expression(expr))))) + Jakt::DeprecatedString(")["sv)) + TRY((((*this).codegen_expression(index))))) + Jakt::DeprecatedString("])"sv)));
};/*case end*/
case 14: {
auto&& __jakt_match_value = __jakt_match_variant.template get<types::CheckedExpression::IndexedTuple>();NonnullRefPtr<typename types::CheckedExpression> const& expr = __jakt_match_value.expr;
size_t const& index = __jakt_match_value.index;
bool const& is_optional = __jakt_match_value.is_optional;
return JaktInternal::ExplicitValue(JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<DeprecatedString,ErrorOr<DeprecatedString>>{
auto __jakt_enum_value = (is_optional);
if (__jakt_enum_value == true) {
return JaktInternal::ExplicitValue(TRY((__jakt_format(Jakt::DeprecatedString("(({}).map([](auto& _value) {{ return _value.template get<{}>(); }}))"sv),TRY((((*this).codegen_expression(expr)))),index))));
}
else {
return JaktInternal::ExplicitValue(TRY((__jakt_format(Jakt::DeprecatedString("(({}).template get<{}>())"sv),TRY((((*this).codegen_expression(expr)))),index))));
}
}()))
);
};/*case end*/
case 15: {
auto&& __jakt_match_value = __jakt_match_variant.template get<types::CheckedExpression::IndexedStruct>();NonnullRefPtr<typename types::CheckedExpression> const& expr = __jakt_match_value.expr;
DeprecatedString const& index = __jakt_match_value.index;
bool const& is_optional = __jakt_match_value.is_optional;
return JaktInternal::ExplicitValue(({ Optional<DeprecatedString> __jakt_var_470; {
DeprecatedString output = Jakt::DeprecatedString(""sv);
DeprecatedString const object = TRY((((*this).codegen_expression(expr))));
(output += Jakt::DeprecatedString("(("sv));
(output += object);
(output += Jakt::DeprecatedString(")"sv));
NonnullRefPtr<typename types::Type> const expression_type = ((((*this).program))->get_type(((expr)->type())));
JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<void, ErrorOr<DeprecatedString>>{
auto&& __jakt_match_variant = *expression_type;
switch(__jakt_match_variant.index()) {
case 25: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::Type::RawPtr>();
{
(output += Jakt::DeprecatedString("->"sv));
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 23: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::Type::Struct>();
types::StructId const& id = __jakt_match_value.value;
{
types::CheckedStruct const structure = ((((*this).program))->get_struct(id));
if ((((((structure).record_type)).index() == 1 /* Class */) && (object != Jakt::DeprecatedString("*this"sv)))){
(output += Jakt::DeprecatedString("->"sv));
}
else {
(output += Jakt::DeprecatedString("."sv));
}

}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 19: {
auto&& __jakt_match_value = __jakt_match_variant.template get<types::Type::GenericInstance>();types::StructId const& id = __jakt_match_value.id;
{
types::CheckedStruct const structure = ((((*this).program))->get_struct(id));
if ((((((structure).record_type)).index() == 1 /* Class */) && (object != Jakt::DeprecatedString("*this"sv)))){
(output += Jakt::DeprecatedString("->"sv));
}
else {
(output += Jakt::DeprecatedString("."sv));
}

}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
default: {
{
(output += Jakt::DeprecatedString("."sv));
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
}/*switch end*/
}()
));
if (is_optional){
(output += Jakt::DeprecatedString("map([](auto& _value) { return _value"sv));
DeprecatedString access_operator = Jakt::DeprecatedString("."sv);
if (((expression_type)->index() == 19 /* GenericInstance */)){
JaktInternal::DynamicArray<types::TypeId> const args = ((expression_type)->get<types::Type::GenericInstance>()).args;
if ((((args).size()) > static_cast<size_t>(0ULL))){
JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<void, ErrorOr<DeprecatedString>>{
auto&& __jakt_match_variant = *((((*this).program))->get_type(((args)[static_cast<i64>(0LL)])));
switch(__jakt_match_variant.index()) {
case 23: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::Type::Struct>();
types::StructId const& id = __jakt_match_value.value;
{
if (((((((((*this).program))->get_struct(id))).record_type)).index() == 1 /* Class */)){
(access_operator = Jakt::DeprecatedString("->"sv));
}
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 19: {
auto&& __jakt_match_value = __jakt_match_variant.template get<types::Type::GenericInstance>();types::StructId const& id = __jakt_match_value.id;
{
if (((((((((*this).program))->get_struct(id))).record_type)).index() == 1 /* Class */)){
(access_operator = Jakt::DeprecatedString("->"sv));
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
}
}
(output += access_operator);
(output += index);
(output += Jakt::DeprecatedString("; })"sv));
}
else {
(output += index);
}

(output += Jakt::DeprecatedString(")"sv));
__jakt_var_470 = output; goto __jakt_label_415;

}
__jakt_label_415:; __jakt_var_470.release_value(); }));
};/*case end*/
case 16: {
auto&& __jakt_match_value = __jakt_match_variant.template get<types::CheckedExpression::IndexedCommonEnumMember>();NonnullRefPtr<typename types::CheckedExpression> const& expr = __jakt_match_value.expr;
DeprecatedString const& index = __jakt_match_value.index;
bool const& is_optional = __jakt_match_value.is_optional;
return JaktInternal::ExplicitValue(({ Optional<DeprecatedString> __jakt_var_471; {
DeprecatedString output = Jakt::DeprecatedString(""sv);
DeprecatedString const object = TRY((((*this).codegen_expression(expr))));
(output += Jakt::DeprecatedString("(("sv));
(output += object);
(output += Jakt::DeprecatedString(")"sv));
JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<void, ErrorOr<DeprecatedString>>{
auto&& __jakt_match_variant = *((((*this).program))->get_type(((expr)->type())));
switch(__jakt_match_variant.index()) {
case 25: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::Type::RawPtr>();
{
(output += Jakt::DeprecatedString("->"sv));
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 24: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::Type::Enum>();
types::EnumId const& id = __jakt_match_value.value;
{
types::CheckedEnum const structure = ((((*this).program))->get_enum(id));
if (((((structure).record_type)).index() == 3 /* SumEnum */)){
bool const is_boxed = ((((structure).record_type)).get<parser::RecordType::SumEnum>()).is_boxed;
if ((is_boxed && (object != Jakt::DeprecatedString("*this"sv)))){
(output += Jakt::DeprecatedString("->"sv));
}
else {
(output += Jakt::DeprecatedString("."sv));
}

}
else {
(output += Jakt::DeprecatedString("."sv));
}

}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 20: {
auto&& __jakt_match_value = __jakt_match_variant.template get<types::Type::GenericEnumInstance>();types::EnumId const& id = __jakt_match_value.id;
{
types::CheckedEnum const structure = ((((*this).program))->get_enum(id));
if (((((structure).record_type)).index() == 3 /* SumEnum */)){
bool const is_boxed = ((((structure).record_type)).get<parser::RecordType::SumEnum>()).is_boxed;
if ((is_boxed && (object != Jakt::DeprecatedString("*this"sv)))){
(output += Jakt::DeprecatedString("->"sv));
}
else {
(output += Jakt::DeprecatedString("."sv));
}

}
else {
(output += Jakt::DeprecatedString("."sv));
}

}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
default: {
{
(output += Jakt::DeprecatedString("."sv));
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
}/*switch end*/
}()
));
if (is_optional){
(output += Jakt::DeprecatedString("map([](auto& _value) { return _value."sv));
(output += index);
(output += Jakt::DeprecatedString("(); })"sv));
}
else {
(output += (index + Jakt::DeprecatedString("()"sv)));
}

(output += Jakt::DeprecatedString(")"sv));
__jakt_var_471 = output; goto __jakt_label_416;

}
__jakt_label_416:; __jakt_var_471.release_value(); }));
};/*case end*/
case 26: {
auto&& __jakt_match_value = __jakt_match_variant.template get<types::CheckedExpression::Block>();types::CheckedBlock const& block = __jakt_match_value.block;
return JaktInternal::ExplicitValue(TRY((((*this).codegen_block(block)))));
};/*case end*/
case 19: {
auto&& __jakt_match_value = __jakt_match_variant.template get<types::CheckedExpression::Call>();types::CheckedCall const& call = __jakt_match_value.call;
return JaktInternal::ExplicitValue(TRY((((*this).codegen_call(call)))));
};/*case end*/
case 20: {
auto&& __jakt_match_value = __jakt_match_variant.template get<types::CheckedExpression::MethodCall>();NonnullRefPtr<typename types::CheckedExpression> const& expr = __jakt_match_value.expr;
types::CheckedCall const& call = __jakt_match_value.call;
bool const& is_optional = __jakt_match_value.is_optional;
return JaktInternal::ExplicitValue(TRY((((*this).codegen_method_call(expr,call,is_optional)))));
};/*case end*/
case 0: {
auto&& __jakt_match_value = __jakt_match_variant.template get<types::CheckedExpression::Boolean>();bool const& val = __jakt_match_value.val;
return JaktInternal::ExplicitValue(JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<DeprecatedString,ErrorOr<DeprecatedString>>{
auto __jakt_enum_value = (val);
if (__jakt_enum_value == true) {
return JaktInternal::ExplicitValue(Jakt::DeprecatedString("true"sv));
}
else {
return JaktInternal::ExplicitValue(Jakt::DeprecatedString("false"sv));
}
}()))
);
};/*case end*/
case 5: {
auto&& __jakt_match_value = __jakt_match_variant.template get<types::CheckedExpression::UnaryOp>();NonnullRefPtr<typename types::CheckedExpression> const& expr = __jakt_match_value.expr;
types::CheckedUnaryOperator const& op = __jakt_match_value.op;
types::TypeId const& type_id = __jakt_match_value.type_id;
return JaktInternal::ExplicitValue(({ Optional<DeprecatedString> __jakt_var_472; {
DeprecatedString output = Jakt::DeprecatedString("("sv);
(output += JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<DeprecatedString, ErrorOr<DeprecatedString>>{
auto&& __jakt_match_variant = op;
switch(__jakt_match_variant.index()) {
case 0: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::CheckedUnaryOperator::PreIncrement>();
return JaktInternal::ExplicitValue(Jakt::DeprecatedString("++"sv));
};/*case end*/
case 2: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::CheckedUnaryOperator::PreDecrement>();
return JaktInternal::ExplicitValue(Jakt::DeprecatedString("--"sv));
};/*case end*/
case 4: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::CheckedUnaryOperator::Negate>();
return JaktInternal::ExplicitValue(Jakt::DeprecatedString("-"sv));
};/*case end*/
case 5: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::CheckedUnaryOperator::Dereference>();
return JaktInternal::ExplicitValue(JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<DeprecatedString, ErrorOr<DeprecatedString>>{
auto&& __jakt_match_variant = *((((*this).program))->get_type(((expr)->type())));
switch(__jakt_match_variant.index()) {
case 25: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::Type::RawPtr>();
return JaktInternal::ExplicitValue(Jakt::DeprecatedString("*"sv));
};/*case end*/
default: {
return JaktInternal::ExplicitValue(Jakt::DeprecatedString(""sv));
};/*case end*/
}/*switch end*/
}()
)));
};/*case end*/
case 6: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::CheckedUnaryOperator::RawAddress>();
return JaktInternal::ExplicitValue((((Jakt::DeprecatedString("const_cast<"sv) + TRY((((*this).codegen_type(type_id))))) + Jakt::DeprecatedString(">("sv)) + Jakt::DeprecatedString("&"sv)));
};/*case end*/
case 9: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::CheckedUnaryOperator::LogicalNot>();
return JaktInternal::ExplicitValue(Jakt::DeprecatedString("!"sv));
};/*case end*/
case 10: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::CheckedUnaryOperator::BitwiseNot>();
return JaktInternal::ExplicitValue(Jakt::DeprecatedString("~"sv));
};/*case end*/
case 12: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::CheckedUnaryOperator::Is>();
types::TypeId const& type_id = __jakt_match_value.value;
return JaktInternal::ExplicitValue(({ Optional<DeprecatedString> __jakt_var_473; {
DeprecatedString const is_type = JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<DeprecatedString, ErrorOr<DeprecatedString>>{
auto&& __jakt_match_variant = *((((*this).program))->get_type(type_id));
switch(__jakt_match_variant.index()) {
case 23: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::Type::Struct>();
types::StructId const& id = __jakt_match_value.value;
return JaktInternal::ExplicitValue(({ Optional<DeprecatedString> __jakt_var_474; {
NonnullRefPtr<types::Module> const type_module = ((((*this).program))->get_module(((id).module)));
__jakt_var_474 = ((((((*this).program))->get_struct(id))).name_for_codegen()); goto __jakt_label_419;

}
__jakt_label_419:; __jakt_var_474.release_value(); }));
};/*case end*/
default: {
return JaktInternal::ExplicitValue(TRY((((*this).codegen_type(type_id)))));
};/*case end*/
}/*switch end*/
}()
));
__jakt_var_473 = ((Jakt::DeprecatedString("is<"sv) + is_type) + Jakt::DeprecatedString(">("sv)); goto __jakt_label_418;

}
__jakt_label_418:; __jakt_var_473.release_value(); }));
};/*case end*/
case 11: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::CheckedUnaryOperator::TypeCast>();
types::CheckedTypeCast const& cast = __jakt_match_value.value;
return JaktInternal::ExplicitValue(({ Optional<DeprecatedString> __jakt_var_475; {
types::TypeId final_type_id = ((cast).type_id());
DeprecatedString const cast_type = JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<DeprecatedString, ErrorOr<DeprecatedString>>{
auto&& __jakt_match_variant = cast;
switch(__jakt_match_variant.index()) {
case 0: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::CheckedTypeCast::Fallible>();
return JaktInternal::ExplicitValue(({ Optional<DeprecatedString> __jakt_var_476; {
NonnullRefPtr<typename types::Type> const ty = ((((*this).program))->get_type(((cast).type_id())));
types::TypeId const type_id = JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<types::TypeId, ErrorOr<DeprecatedString>>{
auto&& __jakt_match_variant = *ty;
switch(__jakt_match_variant.index()) {
case 19: {
auto&& __jakt_match_value = __jakt_match_variant.template get<types::Type::GenericInstance>();JaktInternal::DynamicArray<types::TypeId> const& args = __jakt_match_value.args;
return JaktInternal::ExplicitValue(((args)[static_cast<i64>(0LL)]));
};/*case end*/
default: {
{
utility::panic(Jakt::DeprecatedString("Fallible type cast must have Optional result."sv));
}
};/*case end*/
}/*switch end*/
}()
));
DeprecatedString cast_type = Jakt::DeprecatedString("dynamic_cast"sv);
if (((((*this).program))->is_integer(type_id))){
(final_type_id = type_id);
(cast_type = Jakt::DeprecatedString("fallible_integer_cast"sv));
}
__jakt_var_476 = cast_type; goto __jakt_label_421;

}
__jakt_label_421:; __jakt_var_476.release_value(); }));
};/*case end*/
case 1: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::CheckedTypeCast::Infallible>();
return JaktInternal::ExplicitValue(({ Optional<DeprecatedString> __jakt_var_477; {
DeprecatedString cast_type = Jakt::DeprecatedString("verify_cast"sv);
if (((((*this).program))->is_integer(type_id))){
(cast_type = Jakt::DeprecatedString("infallible_integer_cast"sv));
}
__jakt_var_477 = cast_type; goto __jakt_label_422;

}
__jakt_label_422:; __jakt_var_477.release_value(); }));
};/*case end*/
default: VERIFY_NOT_REACHED();}/*switch end*/
}()
));
__jakt_var_475 = (((cast_type + Jakt::DeprecatedString("<"sv)) + TRY((((*this).codegen_type(final_type_id))))) + Jakt::DeprecatedString(">("sv)); goto __jakt_label_420;

}
__jakt_label_420:; __jakt_var_475.release_value(); }));
};/*case end*/
default: {
return JaktInternal::ExplicitValue(Jakt::DeprecatedString(""sv));
};/*case end*/
}/*switch end*/
}()
)));
(output += Jakt::DeprecatedString("("sv));
DeprecatedString const object = TRY((((*this).codegen_expression(expr))));
(output += object);
(output += JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<DeprecatedString, ErrorOr<DeprecatedString>>{
auto&& __jakt_match_variant = op;
switch(__jakt_match_variant.index()) {
case 1: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::CheckedUnaryOperator::PostIncrement>();
return JaktInternal::ExplicitValue(Jakt::DeprecatedString("++)"sv));
};/*case end*/
case 3: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::CheckedUnaryOperator::PostDecrement>();
return JaktInternal::ExplicitValue(Jakt::DeprecatedString("--)"sv));
};/*case end*/
case 11: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::CheckedUnaryOperator::TypeCast>();
return JaktInternal::ExplicitValue(Jakt::DeprecatedString("))"sv));
};/*case end*/
case 12: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::CheckedUnaryOperator::Is>();
return JaktInternal::ExplicitValue(Jakt::DeprecatedString("))"sv));
};/*case end*/
case 13: {
auto&& __jakt_match_value = __jakt_match_variant.template get<types::CheckedUnaryOperator::IsEnumVariant>();types::CheckedEnumVariant const& enum_variant = __jakt_match_value.enum_variant;
types::TypeId const& enum_type_id = __jakt_match_value.type_id;
return JaktInternal::ExplicitValue(({ Optional<DeprecatedString> __jakt_var_478; {
DeprecatedString const name = ((enum_variant).name());
DeprecatedString suffix = Jakt::DeprecatedString(")"sv);
types::CheckedEnum const enum_ = ((((*this).program))->get_enum(JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<types::EnumId, ErrorOr<DeprecatedString>>{
auto&& __jakt_match_variant = *((((*this).program))->get_type(enum_type_id));
switch(__jakt_match_variant.index()) {
case 24: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::Type::Enum>();
types::EnumId const& enum_id = __jakt_match_value.value;
return JaktInternal::ExplicitValue(enum_id);
};/*case end*/
case 20: {
auto&& __jakt_match_value = __jakt_match_variant.template get<types::Type::GenericEnumInstance>();types::EnumId const& id = __jakt_match_value.id;
return JaktInternal::ExplicitValue(id);
};/*case end*/
default: {
{
utility::panic(TRY((__jakt_format(Jakt::DeprecatedString("Unexpected type in IsEnumVariant: {}"sv),((((*this).program))->get_type(enum_type_id))))));
}
};/*case end*/
}/*switch end*/
}()
))));
bool const is_boxed = ((enum_).is_boxed);
if ((is_boxed && (object != Jakt::DeprecatedString("*this"sv)))){
(suffix += Jakt::DeprecatedString("->"sv));
}
else {
(suffix += Jakt::DeprecatedString("."sv));
}

i64 variant_index = static_cast<i64>(0LL);
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
break;
}
((variant_index++));
}

}
}

(suffix += TRY((__jakt_format(Jakt::DeprecatedString("index() == {} /* {} */"sv),variant_index,name))));
__jakt_var_478 = suffix; goto __jakt_label_423;

}
__jakt_label_423:; __jakt_var_478.release_value(); }));
};/*case end*/
case 6: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::CheckedUnaryOperator::RawAddress>();
return JaktInternal::ExplicitValue(Jakt::DeprecatedString("))"sv));
};/*case end*/
default: {
return JaktInternal::ExplicitValue(Jakt::DeprecatedString(")"sv));
};/*case end*/
}/*switch end*/
}()
)));
(output += Jakt::DeprecatedString(")"sv));
__jakt_var_472 = output; goto __jakt_label_417;

}
__jakt_label_417:; __jakt_var_472.release_value(); }));
};/*case end*/
case 6: {
auto&& __jakt_match_value = __jakt_match_variant.template get<types::CheckedExpression::BinaryOp>();NonnullRefPtr<typename types::CheckedExpression> const& lhs = __jakt_match_value.lhs;
NonnullRefPtr<typename types::CheckedExpression> const& rhs = __jakt_match_value.rhs;
parser::BinaryOperator const& op = __jakt_match_value.op;
types::TypeId const& type_id = __jakt_match_value.type_id;
return JaktInternal::ExplicitValue(TRY((((*this).codegen_binary_expression(expression,type_id,lhs,rhs,op)))));
};/*case end*/
case 1: {
auto&& __jakt_match_value = __jakt_match_variant.template get<types::CheckedExpression::NumericConstant>();types::CheckedNumericConstant const& val = __jakt_match_value.val;
types::TypeId const& type_id = __jakt_match_value.type_id;
return JaktInternal::ExplicitValue(({ Optional<DeprecatedString> __jakt_var_479; {
DeprecatedString const suffix = JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<DeprecatedString, ErrorOr<DeprecatedString>>{
auto&& __jakt_match_variant = val;
switch(__jakt_match_variant.index()) {
case 3: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::CheckedNumericConstant::I64>();
return JaktInternal::ExplicitValue(Jakt::DeprecatedString("LL"sv));
};/*case end*/
case 7: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::CheckedNumericConstant::U64>();
return JaktInternal::ExplicitValue(Jakt::DeprecatedString("ULL"sv));
};/*case end*/
case 8: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::CheckedNumericConstant::USize>();
return JaktInternal::ExplicitValue(Jakt::DeprecatedString("ULL"sv));
};/*case end*/
default: {
return JaktInternal::ExplicitValue(Jakt::DeprecatedString(""sv));
};/*case end*/
}/*switch end*/
}()
));
DeprecatedString const type_name = JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<DeprecatedString, ErrorOr<DeprecatedString>>{
auto&& __jakt_match_variant = val;
switch(__jakt_match_variant.index()) {
case 8: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::CheckedNumericConstant::USize>();
return JaktInternal::ExplicitValue(Jakt::DeprecatedString("size_t"sv));
};/*case end*/
default: {
return JaktInternal::ExplicitValue(TRY((((*this).codegen_type(type_id)))));
};/*case end*/
}/*switch end*/
}()
));
__jakt_var_479 = JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<DeprecatedString, ErrorOr<DeprecatedString>>{
auto&& __jakt_match_variant = val;
switch(__jakt_match_variant.index()) {
case 9: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::CheckedNumericConstant::F32>();
f32 const& val = __jakt_match_value.value;
return JaktInternal::ExplicitValue(TRY((__jakt_format(Jakt::DeprecatedString("static_cast<{}>({}{})"sv),type_name,val,suffix))));
};/*case end*/
case 10: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::CheckedNumericConstant::F64>();
f64 const& val = __jakt_match_value.value;
return JaktInternal::ExplicitValue(TRY((__jakt_format(Jakt::DeprecatedString("static_cast<{}>({}{})"sv),type_name,val,suffix))));
};/*case end*/
case 0: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::CheckedNumericConstant::I8>();
i8 const& val = __jakt_match_value.value;
return JaktInternal::ExplicitValue(TRY((__jakt_format(Jakt::DeprecatedString("static_cast<{}>({}{})"sv),type_name,val,suffix))));
};/*case end*/
case 1: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::CheckedNumericConstant::I16>();
i16 const& val = __jakt_match_value.value;
return JaktInternal::ExplicitValue(TRY((__jakt_format(Jakt::DeprecatedString("static_cast<{}>({}{})"sv),type_name,val,suffix))));
};/*case end*/
case 2: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::CheckedNumericConstant::I32>();
i32 const& val = __jakt_match_value.value;
return JaktInternal::ExplicitValue(TRY((__jakt_format(Jakt::DeprecatedString("static_cast<{}>({}{})"sv),type_name,val,suffix))));
};/*case end*/
case 3: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::CheckedNumericConstant::I64>();
i64 const& val = __jakt_match_value.value;
return JaktInternal::ExplicitValue(TRY((__jakt_format(Jakt::DeprecatedString("static_cast<{}>({}{})"sv),type_name,val,suffix))));
};/*case end*/
case 4: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::CheckedNumericConstant::U8>();
u8 const& val = __jakt_match_value.value;
return JaktInternal::ExplicitValue(TRY((__jakt_format(Jakt::DeprecatedString("static_cast<{}>({}{})"sv),type_name,val,suffix))));
};/*case end*/
case 5: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::CheckedNumericConstant::U16>();
u16 const& val = __jakt_match_value.value;
return JaktInternal::ExplicitValue(TRY((__jakt_format(Jakt::DeprecatedString("static_cast<{}>({}{})"sv),type_name,val,suffix))));
};/*case end*/
case 6: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::CheckedNumericConstant::U32>();
u32 const& val = __jakt_match_value.value;
return JaktInternal::ExplicitValue(TRY((__jakt_format(Jakt::DeprecatedString("static_cast<{}>({}{})"sv),type_name,val,suffix))));
};/*case end*/
case 7: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::CheckedNumericConstant::U64>();
u64 const& val = __jakt_match_value.value;
return JaktInternal::ExplicitValue(TRY((__jakt_format(Jakt::DeprecatedString("static_cast<{}>({}{})"sv),type_name,val,suffix))));
};/*case end*/
case 8: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::CheckedNumericConstant::USize>();
u64 const& val = __jakt_match_value.value;
return JaktInternal::ExplicitValue(TRY((__jakt_format(Jakt::DeprecatedString("static_cast<{}>({}{})"sv),type_name,val,suffix))));
};/*case end*/
default: VERIFY_NOT_REACHED();}/*switch end*/
}()
)); goto __jakt_label_424;

}
__jakt_label_424:; __jakt_var_479.release_value(); }));
};/*case end*/
case 21: {
auto&& __jakt_match_value = __jakt_match_variant.template get<types::CheckedExpression::NamespacedVar>();JaktInternal::DynamicArray<types::CheckedNamespace> const& namespaces = __jakt_match_value.namespaces;
NonnullRefPtr<types::CheckedVariable> const& var = __jakt_match_value.var;
return JaktInternal::ExplicitValue(({ Optional<DeprecatedString> __jakt_var_480; {
DeprecatedString output = Jakt::DeprecatedString(""sv);
if (((((var)->owner_scope)).has_value())){
(output = TRY((((*this).codegen_namespace_qualifier((((var)->owner_scope).value()),false,JaktInternal::OptionalNone())))));
}
else {
{
JaktInternal::ArrayIterator<types::CheckedNamespace> _magic = ((namespaces).iterator());
for (;;){
JaktInternal::Optional<types::CheckedNamespace> _magic_value = ((_magic).next());
if ((!(((_magic_value).has_value())))){
break;
}
types::CheckedNamespace ns = (_magic_value.value());
{
(output += (((ns).name) + Jakt::DeprecatedString("::"sv)));
}

}
}

}

__jakt_var_480 = (output + ((var)->name)); goto __jakt_label_425;

}
__jakt_label_425:; __jakt_var_480.release_value(); }));
};/*case end*/
case 17: {
auto&& __jakt_match_value = __jakt_match_variant.template get<types::CheckedExpression::Match>();NonnullRefPtr<typename types::CheckedExpression> const& expr = __jakt_match_value.expr;
JaktInternal::DynamicArray<types::CheckedMatchCase> const& match_cases = __jakt_match_value.match_cases;
types::TypeId const& type_id = __jakt_match_value.type_id;
bool const& all_variants_constant = __jakt_match_value.all_variants_constant;
return JaktInternal::ExplicitValue(TRY((((*this).codegen_match(expr,match_cases,type_id,all_variants_constant)))));
};/*case end*/
case 18: {
auto&& __jakt_match_value = __jakt_match_variant.template get<types::CheckedExpression::EnumVariantArg>();NonnullRefPtr<typename types::CheckedExpression> const& expr = __jakt_match_value.expr;
types::CheckedEnumVariantBinding const& arg = __jakt_match_value.arg;
types::CheckedEnumVariant const& enum_variant = __jakt_match_value.enum_variant;
return JaktInternal::ExplicitValue(({ Optional<DeprecatedString> __jakt_var_481; {
DeprecatedString const var_name = TRY((((*this).codegen_expression(expr))));
DeprecatedString const enum_type = TRY((((*this).codegen_type_possibly_as_namespace(((expr)->type()),true))));
DeprecatedString const variant_name = ((enum_variant).name());
DeprecatedString arg_name = Jakt::DeprecatedString("value"sv);
if (((enum_variant).index() == 3 /* StructLike */)){
(arg_name = ((arg).name).value_or_lazy_evaluated([&] { return ((arg).binding); }));
}
DeprecatedString const cpp_deref_operator = JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<DeprecatedString,ErrorOr<DeprecatedString>>{
auto __jakt_enum_value = (((((((*this).program))->get_enum(((enum_variant).enum_id())))).is_boxed));
if (__jakt_enum_value == true) {
return JaktInternal::ExplicitValue(Jakt::DeprecatedString("->"sv));
}
else {
return JaktInternal::ExplicitValue(Jakt::DeprecatedString("."sv));
}
}()))
;
__jakt_var_481 = TRY((__jakt_format(Jakt::DeprecatedString("(({}){}get<{}::{}>()).{}"sv),var_name,cpp_deref_operator,enum_type,variant_name,arg_name))); goto __jakt_label_426;

}
__jakt_label_426:; __jakt_var_481.release_value(); }));
};/*case end*/
case 9: {
auto&& __jakt_match_value = __jakt_match_variant.template get<types::CheckedExpression::JaktArray>();JaktInternal::DynamicArray<NonnullRefPtr<typename types::CheckedExpression>> const& vals = __jakt_match_value.vals;
JaktInternal::Optional<NonnullRefPtr<typename types::CheckedExpression>> const& repeat = __jakt_match_value.repeat;
utility::Span const& span = __jakt_match_value.span;
types::TypeId const& type_id = __jakt_match_value.type_id;
types::TypeId const& inner_type_id = __jakt_match_value.inner_type_id;
return JaktInternal::ExplicitValue(({ Optional<DeprecatedString> __jakt_var_482; {
DeprecatedString output = Jakt::DeprecatedString(""sv);
if (((repeat).has_value())){
NonnullRefPtr<typename types::CheckedExpression> const repeat_val = ((repeat).value());
(output += Jakt::DeprecatedString("("sv));
(output += TRY((((*this).current_error_handler()))));
(output += Jakt::DeprecatedString("((DynamicArray<"sv));
(output += TRY((((*this).codegen_type(inner_type_id)))));
(output += Jakt::DeprecatedString(">::filled("sv));
(output += TRY((((*this).codegen_expression(repeat_val)))));
(output += Jakt::DeprecatedString(", "sv));
(output += TRY((((*this).codegen_expression(((vals)[static_cast<i64>(0LL)]))))));
(output += Jakt::DeprecatedString("))))"sv));
}
else {
(output += Jakt::DeprecatedString("("sv));
(output += TRY((((*this).current_error_handler()))));
(output += Jakt::DeprecatedString("((DynamicArray<"sv));
(output += TRY((((*this).codegen_type(inner_type_id)))));
(output += Jakt::DeprecatedString(">::create_with({"sv));
bool first = true;
{
JaktInternal::ArrayIterator<NonnullRefPtr<typename types::CheckedExpression>> _magic = ((vals).iterator());
for (;;){
JaktInternal::Optional<NonnullRefPtr<typename types::CheckedExpression>> _magic_value = ((_magic).next());
if ((!(((_magic_value).has_value())))){
break;
}
NonnullRefPtr<typename types::CheckedExpression> val = (_magic_value.value());
{
if ((!(first))){
(output += Jakt::DeprecatedString(", "sv));
}
else {
(first = false);
}

(output += TRY((((*this).codegen_expression(val)))));
}

}
}

(output += Jakt::DeprecatedString("}))))"sv));
}

__jakt_var_482 = output; goto __jakt_label_427;

}
__jakt_label_427:; __jakt_var_482.release_value(); }));
};/*case end*/
case 11: {
auto&& __jakt_match_value = __jakt_match_variant.template get<types::CheckedExpression::JaktDictionary>();JaktInternal::DynamicArray<JaktInternal::Tuple<NonnullRefPtr<typename types::CheckedExpression>,NonnullRefPtr<typename types::CheckedExpression>>> const& vals = __jakt_match_value.vals;
utility::Span const& span = __jakt_match_value.span;
types::TypeId const& type_id = __jakt_match_value.type_id;
types::TypeId const& key_type_id = __jakt_match_value.key_type_id;
types::TypeId const& value_type_id = __jakt_match_value.value_type_id;
return JaktInternal::ExplicitValue(({ Optional<DeprecatedString> __jakt_var_483; {
DeprecatedString output = TRY((__jakt_format(Jakt::DeprecatedString("({}((Dictionary<{}, {}>::create_with_entries({{"sv),TRY((((*this).current_error_handler()))),TRY((((*this).codegen_type(key_type_id)))),TRY((((*this).codegen_type(value_type_id)))))));
bool first = true;
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

if ((!(first))){
(output += Jakt::DeprecatedString(", "sv));
}
else {
(first = false);
}

(output += Jakt::DeprecatedString("{"sv));
(output += TRY((((*this).codegen_expression(key)))));
(output += Jakt::DeprecatedString(", "sv));
(output += TRY((((*this).codegen_expression(value)))));
(output += Jakt::DeprecatedString("}"sv));
}

}
}

(output += Jakt::DeprecatedString("}))))"sv));
__jakt_var_483 = output; goto __jakt_label_428;

}
__jakt_label_428:; __jakt_var_483.release_value(); }));
};/*case end*/
case 10: {
auto&& __jakt_match_value = __jakt_match_variant.template get<types::CheckedExpression::JaktSet>();JaktInternal::DynamicArray<NonnullRefPtr<typename types::CheckedExpression>> const& vals = __jakt_match_value.vals;
utility::Span const& span = __jakt_match_value.span;
types::TypeId const& type_id = __jakt_match_value.type_id;
types::TypeId const& inner_type_id = __jakt_match_value.inner_type_id;
return JaktInternal::ExplicitValue(({ Optional<DeprecatedString> __jakt_var_484; {
DeprecatedString output = Jakt::DeprecatedString(""sv);
(output += TRY((__jakt_format(Jakt::DeprecatedString("({}((Set<{}>::create_with_values({{"sv),TRY((((*this).current_error_handler()))),TRY((((*this).codegen_type(inner_type_id))))))));
bool first = true;
{
JaktInternal::ArrayIterator<NonnullRefPtr<typename types::CheckedExpression>> _magic = ((vals).iterator());
for (;;){
JaktInternal::Optional<NonnullRefPtr<typename types::CheckedExpression>> _magic_value = ((_magic).next());
if ((!(((_magic_value).has_value())))){
break;
}
NonnullRefPtr<typename types::CheckedExpression> value = (_magic_value.value());
{
if ((!(first))){
(output += Jakt::DeprecatedString(", "sv));
}
else {
(first = false);
}

(output += TRY((((*this).codegen_expression(value)))));
}

}
}

(output += Jakt::DeprecatedString("}))))"sv));
__jakt_var_484 = output; goto __jakt_label_429;

}
__jakt_label_429:; __jakt_var_484.release_value(); }));
};/*case end*/
case 7: {
auto&& __jakt_match_value = __jakt_match_variant.template get<types::CheckedExpression::JaktTuple>();JaktInternal::DynamicArray<NonnullRefPtr<typename types::CheckedExpression>> const& vals = __jakt_match_value.vals;
utility::Span const& span = __jakt_match_value.span;
types::TypeId const& type_id = __jakt_match_value.type_id;
return JaktInternal::ExplicitValue(({ Optional<DeprecatedString> __jakt_var_485; {
DeprecatedString output = Jakt::DeprecatedString(""sv);
(output += Jakt::DeprecatedString("(Tuple{"sv));
bool first = true;
{
JaktInternal::ArrayIterator<NonnullRefPtr<typename types::CheckedExpression>> _magic = ((vals).iterator());
for (;;){
JaktInternal::Optional<NonnullRefPtr<typename types::CheckedExpression>> _magic_value = ((_magic).next());
if ((!(((_magic_value).has_value())))){
break;
}
NonnullRefPtr<typename types::CheckedExpression> val = (_magic_value.value());
{
if ((!(first))){
(output += Jakt::DeprecatedString(", "sv));
}
else {
(first = false);
}

(output += TRY((((*this).codegen_expression(val)))));
}

}
}

(output += Jakt::DeprecatedString("})"sv));
__jakt_var_485 = output; goto __jakt_label_430;

}
__jakt_label_430:; __jakt_var_485.release_value(); }));
};/*case end*/
case 27: {
auto&& __jakt_match_value = __jakt_match_variant.template get<types::CheckedExpression::Function>();JaktInternal::DynamicArray<types::CheckedCapture> const& captures = __jakt_match_value.captures;
JaktInternal::DynamicArray<types::CheckedParameter> const& params = __jakt_match_value.params;
bool const& can_throw = __jakt_match_value.can_throw;
types::CheckedBlock const& block = __jakt_match_value.block;
types::TypeId const& return_type_id = __jakt_match_value.return_type_id;
JaktInternal::Optional<types::FunctionId> const& pseudo_function_id = __jakt_match_value.pseudo_function_id;
return JaktInternal::ExplicitValue(({ Optional<DeprecatedString> __jakt_var_486; {
JaktInternal::DynamicArray<DeprecatedString> generated_captures = (TRY((DynamicArray<DeprecatedString>::create_with({}))));
{
JaktInternal::ArrayIterator<types::CheckedCapture> _magic = ((captures).iterator());
for (;;){
JaktInternal::Optional<types::CheckedCapture> _magic_value = ((_magic).next());
if ((!(((_magic_value).has_value())))){
break;
}
types::CheckedCapture capture = (_magic_value.value());
{
TRY((((generated_captures).push(JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_AT_LOOP(([&]() -> JaktInternal::ExplicitValueOrControlFlow<DeprecatedString, ErrorOr<DeprecatedString>>{
auto&& __jakt_match_variant = capture;
switch(__jakt_match_variant.index()) {
case 0: {
auto&& __jakt_match_value = __jakt_match_variant.template get<types::CheckedCapture::ByValue>();return JaktInternal::ExplicitValue(((capture).name()));
};/*case end*/
case 1: {
auto&& __jakt_match_value = __jakt_match_variant.template get<types::CheckedCapture::ByReference>();return JaktInternal::ExplicitValue(TRY((__jakt_format(Jakt::DeprecatedString("&{}"sv),((capture).name())))));
};/*case end*/
case 2: {
auto&& __jakt_match_value = __jakt_match_variant.template get<types::CheckedCapture::ByMutableReference>();return JaktInternal::ExplicitValue(TRY((__jakt_format(Jakt::DeprecatedString("&{}"sv),((capture).name())))));
};/*case end*/
case 3: {
auto&& __jakt_match_value = __jakt_match_variant.template get<types::CheckedCapture::AllByReference>();return JaktInternal::ExplicitValue(Jakt::DeprecatedString("&"sv));
};/*case end*/
default: VERIFY_NOT_REACHED();}/*switch end*/
}()
))))));
}

}
}

JaktInternal::DynamicArray<DeprecatedString> generated_params = (TRY((DynamicArray<DeprecatedString>::create_with({}))));
{
JaktInternal::ArrayIterator<types::CheckedParameter> _magic = ((params).iterator());
for (;;){
JaktInternal::Optional<types::CheckedParameter> _magic_value = ((_magic).next());
if ((!(((_magic_value).has_value())))){
break;
}
types::CheckedParameter param = (_magic_value.value());
{
TRY((((generated_params).push(TRY((__jakt_format(Jakt::DeprecatedString("{} {}"sv),TRY((((*this).codegen_type(((((param).variable))->type_id))))),((((param).variable))->name))))))));
}

}
}

DeprecatedString const return_type = JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<DeprecatedString,ErrorOr<DeprecatedString>>{
auto __jakt_enum_value = (can_throw);
if (__jakt_enum_value == true) {
return JaktInternal::ExplicitValue(TRY((__jakt_format(Jakt::DeprecatedString("ErrorOr<{}>"sv),TRY((((*this).codegen_type(return_type_id))))))));
}
else {
return JaktInternal::ExplicitValue(TRY((((*this).codegen_type(return_type_id)))));
}
}()))
;
DeprecatedString block_output = Jakt::DeprecatedString(""sv);
if (((pseudo_function_id).has_value())){
NonnullRefPtr<types::CheckedFunction> const function_ = ((((*this).program))->get_function((pseudo_function_id.value())));
JaktInternal::Optional<NonnullRefPtr<types::CheckedFunction>> const previous_function = ((*this).current_function);
(((*this).current_function) = function_);
ScopeGuard __jakt_var_487([&] {
(((*this).current_function) = previous_function);
});
(block_output = TRY((((*this).codegen_lambda_block(can_throw,block,return_type_id)))));
}
else {
(block_output = TRY((((*this).codegen_lambda_block(can_throw,block,return_type_id)))));
}

__jakt_var_486 = TRY((__jakt_format(Jakt::DeprecatedString("[{}]({}) -> {} {}"sv),utility::join(generated_captures,Jakt::DeprecatedString(", "sv)),utility::join(generated_params,Jakt::DeprecatedString(", "sv)),return_type,block_output))); goto __jakt_label_431;

}
__jakt_label_431:; __jakt_var_486.release_value(); }));
};/*case end*/
case 29: {
auto&& __jakt_match_value = __jakt_match_variant.template get<types::CheckedExpression::TryBlock>();NonnullRefPtr<typename types::CheckedStatement> const& stmt = __jakt_match_value.stmt;
DeprecatedString const& error_name = __jakt_match_value.error_name;
types::CheckedBlock const& catch_block = __jakt_match_value.catch_block;
utility::Span const& span = __jakt_match_value.span;
return JaktInternal::ExplicitValue(({ Optional<DeprecatedString> __jakt_var_488; {
DeprecatedString output = Jakt::DeprecatedString(""sv);
DeprecatedString const try_var = TRY((((*this).fresh_var())));
(output += Jakt::DeprecatedString("auto "sv));
(output += try_var);
(output += Jakt::DeprecatedString(" = [&]() -> ErrorOr<void> {"sv));
codegen::ControlFlowState const last_control_flow = ((*this).control_flow_state);
(((((*this).control_flow_state)).passes_through_match) = false);
(((((*this).control_flow_state)).passes_through_try) = true);
(output += TRY((((*this).codegen_statement(stmt)))));
(output += Jakt::DeprecatedString(";"sv));
(output += Jakt::DeprecatedString("return {};"sv));
(output += Jakt::DeprecatedString("}();\n"sv));
(output += Jakt::DeprecatedString("if ("sv));
(output += try_var);
(output += Jakt::DeprecatedString(".is_error()) {"sv));
if ((!(((error_name).is_empty())))){
(output += Jakt::DeprecatedString("auto "sv));
(output += error_name);
(output += Jakt::DeprecatedString(" = "sv));
(output += try_var);
(output += Jakt::DeprecatedString(".release_error();"sv));
}
(output += TRY((((*this).codegen_block(catch_block)))));
(((*this).control_flow_state) = last_control_flow);
(output += Jakt::DeprecatedString("}"sv));
__jakt_var_488 = output; goto __jakt_label_432;

}
__jakt_label_432:; __jakt_var_488.release_value(); }));
};/*case end*/
case 28: {
auto&& __jakt_match_value = __jakt_match_variant.template get<types::CheckedExpression::Try>();NonnullRefPtr<typename types::CheckedExpression> const& expr = __jakt_match_value.expr;
JaktInternal::Optional<types::CheckedBlock> const& catch_block = __jakt_match_value.catch_block;
JaktInternal::Optional<DeprecatedString> const& catch_name = __jakt_match_value.catch_name;
utility::Span const& span = __jakt_match_value.span;
types::TypeId const& type_id = __jakt_match_value.type_id;
types::TypeId const& inner_type_id = __jakt_match_value.inner_type_id;
return JaktInternal::ExplicitValue(({ Optional<DeprecatedString> __jakt_var_489; {
DeprecatedString output = Jakt::DeprecatedString(""sv);
DeprecatedString const fresh_var = TRY((((*this).fresh_var())));
bool const is_void = ((inner_type_id).equals(types::void_type_id()));
DeprecatedString const try_var = TRY((((*this).fresh_var())));
codegen::ControlFlowState const last_control_flow = ((*this).control_flow_state);
(((((*this).control_flow_state)).passes_through_match) = false);
(((((*this).control_flow_state)).passes_through_try) = true);
ScopeGuard __jakt_var_490([&] {
{
(((*this).control_flow_state) = last_control_flow);
}

});
if ((!(is_void))){
(output += Jakt::DeprecatedString("({ Optional<"sv));
(output += TRY((((*this).codegen_type(inner_type_id)))));
(output += Jakt::DeprecatedString("> "sv));
(output += fresh_var);
(output += Jakt::DeprecatedString(";\n"sv));
}
(output += Jakt::DeprecatedString("auto "sv));
(output += try_var);
(output += Jakt::DeprecatedString(" = [&]() -> ErrorOr<"sv));
(output += TRY((((*this).codegen_type(inner_type_id)))));
(output += Jakt::DeprecatedString("> { return "sv));
(output += TRY((((*this).codegen_expression(expr)))));
if (is_void){
(output += Jakt::DeprecatedString(", ErrorOr<void>{}"sv));
}
(output += Jakt::DeprecatedString("; }();\n"sv));
if (((catch_block).has_value())){
(output += Jakt::DeprecatedString("if ("sv));
(output += try_var);
(output += Jakt::DeprecatedString(".is_error()) {"sv));
if (((catch_name).has_value())){
(output += Jakt::DeprecatedString("auto "sv));
(output += (catch_name.value()));
(output += Jakt::DeprecatedString(" = "sv));
(output += try_var);
(output += Jakt::DeprecatedString(".release_error();\n"sv));
}
if ((((((catch_block.value())).yielded_type)).has_value())){
(output += fresh_var);
(output += Jakt::DeprecatedString(" = ("sv));
(output += TRY((((*this).codegen_block((catch_block.value()))))));
(output += Jakt::DeprecatedString(");\n"sv));
}
else {
(output += TRY((((*this).codegen_block((catch_block.value()))))));
}

if ((!(is_void))){
(output += Jakt::DeprecatedString("} else {"sv));
(output += fresh_var);
(output += Jakt::DeprecatedString(" = "sv));
(output += try_var);
(output += Jakt::DeprecatedString(".release_value();\n"sv));
}
(output += Jakt::DeprecatedString("}\n"sv));
}
else if ((!(is_void))){
(output += Jakt::DeprecatedString("if (!"sv));
(output += try_var);
(output += Jakt::DeprecatedString(".is_error()) "sv));
(output += fresh_var);
(output += Jakt::DeprecatedString(" = "sv));
(output += try_var);
(output += Jakt::DeprecatedString(".release_value();\n"sv));
}
if ((!(is_void))){
(output += fresh_var);
if (((catch_block).has_value())){
(output += Jakt::DeprecatedString(".release_value()"sv));
}
(output += Jakt::DeprecatedString("; })"sv));
}
__jakt_var_489 = output; goto __jakt_label_433;

}
__jakt_label_433:; __jakt_var_489.release_value(); }));
};/*case end*/
case 30: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::CheckedExpression::Garbage>();
utility::Span const& span = __jakt_match_value.value;
return JaktInternal::ExplicitValue(({ Optional<DeprecatedString> __jakt_var_491; {
utility::todo(TRY((__jakt_format(Jakt::DeprecatedString("codegen_expression of bad AST node in {} at {}..{}"sv),TRY((((((*this).compiler))->get_file_path(((span).file_id))))),((span).start),((span).end)))));
__jakt_var_491 = Jakt::DeprecatedString(""sv); goto __jakt_label_434;

}
__jakt_label_434:; __jakt_var_491.release_value(); }));
};/*case end*/
default: VERIFY_NOT_REACHED();}/*switch end*/
}()
)));
}
}

ErrorOr<JaktInternal::DynamicArray<DeprecatedString>> codegen::CodeGenerator::extract_dependencies_from_struct(types::StructId const struct_id,JaktInternal::Dictionary<DeprecatedString,JaktInternal::DynamicArray<DeprecatedString>> const dependency_graph,bool const top_level,JaktInternal::DynamicArray<types::TypeId> const args) const {
{
JaktInternal::DynamicArray<DeprecatedString> dependencies = (TRY((DynamicArray<DeprecatedString>::create_with({}))));
types::CheckedStruct const struct_ = ((((*this).program))->get_struct(struct_id));
if ((((((struct_).definition_linkage)).index() == 1 /* External */) && (((struct_).name) != Jakt::DeprecatedString("Optional"sv)))){
return (dependencies);
}
if ((((((struct_).record_type)).index() == 1 /* Class */) && (!(top_level)))){
return (dependencies);
}
if ((!(((args).is_empty())))){
{
JaktInternal::ArrayIterator<types::TypeId> _magic = ((args).iterator());
for (;;){
JaktInternal::Optional<types::TypeId> _magic_value = ((_magic).next());
if ((!(((_magic_value).has_value())))){
break;
}
types::TypeId inner_type = (_magic_value.value());
{
JaktInternal::DynamicArray<DeprecatedString> const inner_dependencies = JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_AT_LOOP(([&]() -> JaktInternal::ExplicitValueOrControlFlow<JaktInternal::DynamicArray<DeprecatedString>, ErrorOr<JaktInternal::DynamicArray<DeprecatedString>>>{
auto&& __jakt_match_variant = *((((*this).program))->get_type(inner_type));
switch(__jakt_match_variant.index()) {
case 24: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::Type::Enum>();
return JaktInternal::ExplicitValue(TRY((((*this).extract_dependencies_from(inner_type,dependency_graph,false)))));
};/*case end*/
case 23: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::Type::Struct>();
return JaktInternal::ExplicitValue(TRY((((*this).extract_dependencies_from(inner_type,dependency_graph,false)))));
};/*case end*/
default: {
return JaktInternal::ExplicitValue((TRY((DynamicArray<DeprecatedString>::create_with({})))));
};/*case end*/
}/*switch end*/
}()
));
{
JaktInternal::ArrayIterator<DeprecatedString> _magic = ((inner_dependencies).iterator());
for (;;){
JaktInternal::Optional<DeprecatedString> _magic_value = ((_magic).next());
if ((!(((_magic_value).has_value())))){
break;
}
DeprecatedString dependency = (_magic_value.value());
{
TRY((((dependencies).push(dependency))));
}

}
}

}

}
}

}
JaktInternal::Optional<types::StructId> super_struct_id = ((struct_).super_struct_id);
while (((super_struct_id).has_value())){
types::CheckedStruct const super_struct = ((((*this).program))->get_struct((super_struct_id.value())));
TRY((((dependencies).push(TRY((((((super_struct).type_id)).to_string())))))));
(super_struct_id = ((super_struct).super_struct_id));
}
TRY((((dependencies).push(TRY((((((struct_).type_id)).to_string())))))));
{
JaktInternal::ArrayIterator<types::CheckedField> _magic = ((((struct_).fields)).iterator());
for (;;){
JaktInternal::Optional<types::CheckedField> _magic_value = ((_magic).next());
if ((!(((_magic_value).has_value())))){
break;
}
types::CheckedField field = (_magic_value.value());
{
types::TypeId const type_id = ((((((*this).program))->get_variable(((field).variable_id))))->type_id);
JaktInternal::DynamicArray<DeprecatedString> const inner_dependencies = TRY((((*this).extract_dependencies_from(type_id,dependency_graph,false))));
{
JaktInternal::ArrayIterator<DeprecatedString> _magic = ((inner_dependencies).iterator());
for (;;){
JaktInternal::Optional<DeprecatedString> _magic_value = ((_magic).next());
if ((!(((_magic_value).has_value())))){
break;
}
DeprecatedString dependency = (_magic_value.value());
{
TRY((((dependencies).push(dependency))));
}

}
}

}

}
}

return (dependencies);
}
}

ErrorOr<DeprecatedString> codegen::CodeGenerator::codegen_function_in_namespace(NonnullRefPtr<types::CheckedFunction> const function_,JaktInternal::Optional<types::TypeId> const containing_struct,bool const as_method) {
{
if ((!(((((((function_)->generics))->params)).is_empty())))){
if (((((function_)->linkage)).index() == 1 /* External */)){
return (Jakt::DeprecatedString(""sv));
}
}
DeprecatedString output = Jakt::DeprecatedString(""sv);
(output += TRY((((*this).codegen_function_generic_parameters(function_)))));
bool const is_main = ((((function_)->name_for_codegen()) == Jakt::DeprecatedString("main"sv)) && (!(((containing_struct).has_value()))));
if (((((function_)->return_type_id)).equals(types::never_type_id()))){
(output += Jakt::DeprecatedString("[[noreturn]] "sv));
}
if (is_main){
(output += Jakt::DeprecatedString("ErrorOr<int>"sv));
}
else {
if ((as_method && ((function_)->is_static()))){
(output += Jakt::DeprecatedString("static "sv));
}
(output += JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<DeprecatedString,ErrorOr<DeprecatedString>>{
auto __jakt_enum_value = (((function_)->can_throw));
if (__jakt_enum_value == true) {
return JaktInternal::ExplicitValue(TRY((__jakt_format(Jakt::DeprecatedString("ErrorOr<{}>"sv),TRY((((*this).codegen_type(((function_)->return_type_id)))))))));
}
else {
return JaktInternal::ExplicitValue(TRY((((*this).codegen_type(((function_)->return_type_id))))));
}
}()))
);
}

(output += Jakt::DeprecatedString(" "sv));
if (is_main){
(output += Jakt::DeprecatedString("main"sv));
}
else {
DeprecatedString const qualifier = JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<DeprecatedString,ErrorOr<DeprecatedString>>{
auto __jakt_enum_value = (((containing_struct).has_value()));
if (__jakt_enum_value == true) {
return JaktInternal::ExplicitValue(TRY((((*this).codegen_type_possibly_as_namespace((containing_struct.value()),true)))));
}
else {
return JaktInternal::ExplicitValue(Jakt::DeprecatedString(""sv));
}
}()))
;
if ((!(((qualifier).is_empty())))){
(output += qualifier);
(output += Jakt::DeprecatedString("::"sv));
}
(output += ((function_)->name_for_codegen()));
}

(output += Jakt::DeprecatedString("("sv));
if ((is_main && ((((function_)->params)).is_empty()))){
(output += Jakt::DeprecatedString("DynamicArray<DeprecatedString>"sv));
}
bool first = true;
{
JaktInternal::ArrayIterator<types::CheckedParameter> _magic = ((((function_)->params)).iterator());
for (;;){
JaktInternal::Optional<types::CheckedParameter> _magic_value = ((_magic).next());
if ((!(((_magic_value).has_value())))){
break;
}
types::CheckedParameter param = (_magic_value.value());
{
NonnullRefPtr<types::CheckedVariable> const variable = ((param).variable);
if ((((variable)->name) == Jakt::DeprecatedString("this"sv))){
continue;
}
if ((!(first))){
(output += Jakt::DeprecatedString(","sv));
}
else {
(first = false);
}

NonnullRefPtr<typename types::Type> const variable_type = ((((*this).program))->get_type(((variable)->type_id)));
(output += TRY((((*this).codegen_type(((variable)->type_id))))));
(output += Jakt::DeprecatedString(" "sv));
if (((!(((variable)->is_mutable))) && (!((((variable_type)->index() == 27 /* Reference */) || ((variable_type)->index() == 28 /* MutableReference */)))))){
(output += Jakt::DeprecatedString("const "sv));
}
(output += ((variable)->name));
}

}
}

(output += Jakt::DeprecatedString(")"sv));
if (((!(((function_)->is_static()))) && (!(((function_)->is_mutating()))))){
(output += Jakt::DeprecatedString(" const"sv));
}
(output += Jakt::DeprecatedString(" {\n"sv));
if (is_main){
(output += Jakt::DeprecatedString("\n\n            #ifdef _WIN32\n            SetConsoleOutputCP(CP_UTF8);\n            // Enable buffering to prevent VS from chopping up UTF-8 byte sequences\n            setvbuf(stdout, nullptr, _IOFBF, 1000);\n            #endif\n"sv));
}
codegen::ControlFlowState const last_control_flow = ((*this).control_flow_state);
(((*this).control_flow_state) = ((last_control_flow).enter_function()));
DeprecatedString const block = TRY((((*this).codegen_block(((function_)->block)))));
(((*this).control_flow_state) = last_control_flow);
(output += block);
if (is_main){
(output += Jakt::DeprecatedString("return 0;\n"sv));
}
else {
if ((((function_)->can_throw) && ((((function_)->return_type_id)).equals(types::builtin( types::BuiltinType { typename types::BuiltinType::Void() } ))))){
(output += Jakt::DeprecatedString("return {};\n"sv));
}
}

(output += Jakt::DeprecatedString("}\n"sv));
return (output);
}
}

ErrorOr<DeprecatedString> codegen::CodeGenerator::codegen_method_call(NonnullRefPtr<typename types::CheckedExpression> const expr,types::CheckedCall const call,bool const is_optional) {
{
DeprecatedString output = Jakt::DeprecatedString(""sv);
if (((call).callee_throws)){
(output += TRY((((*this).current_error_handler()))));
(output += Jakt::DeprecatedString("(("sv));
}
DeprecatedString const object = TRY((((*this).codegen_expression_and_deref_if_generic_and_needed(expr))));
(output += Jakt::DeprecatedString("(("sv));
(output += object);
(output += Jakt::DeprecatedString(")"sv));
NonnullRefPtr<typename types::Type> const expression_type = ((((*this).program))->get_type(((expr)->type())));
JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<void, ErrorOr<DeprecatedString>>{
auto&& __jakt_match_variant = *expression_type;
switch(__jakt_match_variant.index()) {
case 25: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::Type::RawPtr>();
{
(output += Jakt::DeprecatedString("->"sv));
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 23: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::Type::Struct>();
types::StructId const& id = __jakt_match_value.value;
{
types::CheckedStruct const struct_ = ((((*this).program))->get_struct(id));
if ((((((struct_).record_type)).index() == 1 /* Class */) && (object != Jakt::DeprecatedString("*this"sv)))){
(output += Jakt::DeprecatedString("->"sv));
}
else {
(output += Jakt::DeprecatedString("."sv));
}

}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 19: {
auto&& __jakt_match_value = __jakt_match_variant.template get<types::Type::GenericInstance>();types::StructId const& id = __jakt_match_value.id;
{
types::CheckedStruct const struct_ = ((((*this).program))->get_struct(id));
if ((((((struct_).record_type)).index() == 1 /* Class */) && (object != Jakt::DeprecatedString("*this"sv)))){
(output += Jakt::DeprecatedString("->"sv));
}
else {
(output += Jakt::DeprecatedString("."sv));
}

}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 24: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::Type::Enum>();
types::EnumId const& id = __jakt_match_value.value;
{
types::CheckedEnum const enum_ = ((((*this).program))->get_enum(id));
if ((((enum_).is_boxed) && (object != Jakt::DeprecatedString("*this"sv)))){
(output += Jakt::DeprecatedString("->"sv));
}
else {
(output += Jakt::DeprecatedString("."sv));
}

}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
default: {
{
(output += Jakt::DeprecatedString("."sv));
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
}/*switch end*/
}()
));
if (is_optional){
(output += Jakt::DeprecatedString("map([&](auto& _value) { return _value"sv));
DeprecatedString access_operator = Jakt::DeprecatedString("."sv);
if (((expression_type)->index() == 19 /* GenericInstance */)){
JaktInternal::DynamicArray<types::TypeId> const args = ((expression_type)->get<types::Type::GenericInstance>()).args;
if ((((args).size()) > static_cast<size_t>(0ULL))){
JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<void, ErrorOr<DeprecatedString>>{
auto&& __jakt_match_variant = *((((*this).program))->get_type(((args)[static_cast<i64>(0LL)])));
switch(__jakt_match_variant.index()) {
case 23: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::Type::Struct>();
types::StructId const& id = __jakt_match_value.value;
{
if (((((((((*this).program))->get_struct(id))).record_type)).index() == 1 /* Class */)){
(access_operator = Jakt::DeprecatedString("->"sv));
}
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 19: {
auto&& __jakt_match_value = __jakt_match_variant.template get<types::Type::GenericInstance>();types::StructId const& id = __jakt_match_value.id;
{
if (((((((((*this).program))->get_struct(id))).record_type)).index() == 1 /* Class */)){
(access_operator = Jakt::DeprecatedString("->"sv));
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
}
}
(output += access_operator);
}
JaktInternal::DynamicArray<types::TypeId> const generic_parameters = ((call).type_args);
if ((!(((generic_parameters).is_empty())))){
(output += Jakt::DeprecatedString("template "sv));
}
(output += ((call).name_for_codegen()));
if ((!(((generic_parameters).is_empty())))){
JaktInternal::DynamicArray<DeprecatedString> types = (TRY((DynamicArray<DeprecatedString>::create_with({}))));
{
JaktInternal::ArrayIterator<types::TypeId> _magic = ((generic_parameters).iterator());
for (;;){
JaktInternal::Optional<types::TypeId> _magic_value = ((_magic).next());
if ((!(((_magic_value).has_value())))){
break;
}
types::TypeId gen_param = (_magic_value.value());
{
TRY((((types).push(TRY((((*this).codegen_type_possibly_as_namespace(gen_param,false))))))));
}

}
}

(output += TRY((__jakt_format(Jakt::DeprecatedString("<{}>"sv),utility::join(types,Jakt::DeprecatedString(", "sv))))));
}
(output += Jakt::DeprecatedString("("sv));
bool first = true;
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

if (first){
(first = false);
}
else {
(output += Jakt::DeprecatedString(","sv));
}

(output += TRY((((*this).codegen_expression(expr)))));
}

}
}

(output += Jakt::DeprecatedString(")"sv));
if (is_optional){
(output += Jakt::DeprecatedString("; })"sv));
}
(output += Jakt::DeprecatedString(")"sv));
if (((call).callee_throws)){
(output += Jakt::DeprecatedString("))"sv));
}
return (output);
}
}

codegen::CodeGenerator::CodeGenerator(NonnullRefPtr<compiler::Compiler> a_compiler, NonnullRefPtr<types::CheckedProgram> a_program, codegen::ControlFlowState a_control_flow_state, JaktInternal::DynamicArray<JaktInternal::Tuple<DeprecatedString,DeprecatedString>> a_entered_yieldable_blocks, DeprecatedString a_deferred_output, JaktInternal::Optional<NonnullRefPtr<types::CheckedFunction>> a_current_function, bool a_inside_defer, codegen::CodegenDebugInfo a_debug_info, JaktInternal::DynamicArray<DeprecatedString> a_namespace_stack, size_t a_fresh_var_counter, size_t a_fresh_label_counter) :compiler(a_compiler), program(a_program), control_flow_state(a_control_flow_state), entered_yieldable_blocks(a_entered_yieldable_blocks), deferred_output(a_deferred_output), current_function(a_current_function), inside_defer(a_inside_defer), debug_info(a_debug_info), namespace_stack(a_namespace_stack), fresh_var_counter(a_fresh_var_counter), fresh_label_counter(a_fresh_label_counter){}

ErrorOr<DeprecatedString> codegen::CodeGenerator::codegen_struct(types::CheckedStruct const struct_) {
{
DeprecatedString output = Jakt::DeprecatedString(""sv);
if (((((struct_).definition_linkage)).index() == 1 /* External */)){
return (Jakt::DeprecatedString(""sv));
}
JaktInternal::DynamicArray<DeprecatedString> generic_parameter_names = (TRY((DynamicArray<DeprecatedString>::create_with({}))));
if ((!(((((struct_).generic_parameters)).is_empty())))){
{
JaktInternal::ArrayIterator<types::CheckedGenericParameter> _magic = ((((struct_).generic_parameters)).iterator());
for (;;){
JaktInternal::Optional<types::CheckedGenericParameter> _magic_value = ((_magic).next());
if ((!(((_magic_value).has_value())))){
break;
}
types::CheckedGenericParameter generic_parameter = (_magic_value.value());
{
TRY((((generic_parameter_names).push(TRY((((*this).codegen_type(((generic_parameter).type_id)))))))));
}

}
}

(output += TRY((__jakt_format(Jakt::DeprecatedString("template <{}>"sv),utility::join(TRY((utility::prepend_to_each(generic_parameter_names,Jakt::DeprecatedString("typename "sv)))),Jakt::DeprecatedString(", "sv))))));
}
JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<void, ErrorOr<DeprecatedString>>{
auto&& __jakt_match_variant = ((struct_).record_type);
switch(__jakt_match_variant.index()) {
case 1: {
auto&& __jakt_match_value = __jakt_match_variant.template get<parser::RecordType::Class>();{
DeprecatedString class_name_with_generics = Jakt::DeprecatedString(""sv);
(class_name_with_generics += ((struct_).name_for_codegen()));
bool first = true;
{
JaktInternal::ArrayIterator<types::CheckedGenericParameter> _magic = ((((struct_).generic_parameters)).iterator());
for (;;){
JaktInternal::Optional<types::CheckedGenericParameter> _magic_value = ((_magic).next());
if ((!(((_magic_value).has_value())))){
break;
}
types::CheckedGenericParameter generic_parameter = (_magic_value.value());
{
if ((!(first))){
(class_name_with_generics += Jakt::DeprecatedString(", "sv));
}
else {
(class_name_with_generics += Jakt::DeprecatedString("<"sv));
(first = false);
}

(class_name_with_generics += TRY((((*this).codegen_type(((generic_parameter).type_id))))));
}

}
}

if ((!(((((struct_).generic_parameters)).is_empty())))){
(class_name_with_generics += Jakt::DeprecatedString(">"sv));
}
if (((((struct_).super_struct_id)).has_value())){
(output += TRY((__jakt_format(Jakt::DeprecatedString("class {}: public {} {{\n"sv),((struct_).name_for_codegen()),TRY((((*this).codegen_struct_type((((struct_).super_struct_id).value()),true))))))));
}
else {
(output += TRY((__jakt_format(Jakt::DeprecatedString("class {} : public RefCounted<{}>, public Weakable<{}> {{\n"sv),((struct_).name_for_codegen()),class_name_with_generics,class_name_with_generics))));
}

(output += Jakt::DeprecatedString("  public:\n"sv));
(output += TRY((__jakt_format(Jakt::DeprecatedString("virtual ~{}() = default;\n"sv),((struct_).name_for_codegen())))));
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 0: {
auto&& __jakt_match_value = __jakt_match_variant.template get<parser::RecordType::Struct>();{
(output += TRY((__jakt_format(Jakt::DeprecatedString("struct {}"sv),((struct_).name_for_codegen())))));
(output += Jakt::DeprecatedString(" {\n"sv));
(output += Jakt::DeprecatedString("  public:\n"sv));
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 3: {
auto&& __jakt_match_value = __jakt_match_variant.template get<parser::RecordType::SumEnum>();{
utility::todo(Jakt::DeprecatedString("codegen_struct SumEnum"sv));
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 2: {
auto&& __jakt_match_value = __jakt_match_variant.template get<parser::RecordType::ValueEnum>();{
utility::todo(Jakt::DeprecatedString("codegen_struct ValueEnum"sv));
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
{
JaktInternal::ArrayIterator<types::CheckedField> _magic = ((((struct_).fields)).iterator());
for (;;){
JaktInternal::Optional<types::CheckedField> _magic_value = ((_magic).next());
if ((!(((_magic_value).has_value())))){
break;
}
types::CheckedField field = (_magic_value.value());
{
NonnullRefPtr<types::CheckedVariable> const variable = ((((*this).program))->get_variable(((field).variable_id)));
(output += TRY((((*this).codegen_type(((variable)->type_id))))));
(output += Jakt::DeprecatedString(" "sv));
(output += ((variable)->name));
(output += Jakt::DeprecatedString(";"sv));
}

}
}

NonnullRefPtr<types::Scope> const scope = TRY((((((*this).program))->get_scope(((struct_).scope_id)))));
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
JaktInternal::Optional<NonnullRefPtr<types::CheckedFunction>> const previous_function_id = ((*this).current_function);
NonnullRefPtr<types::CheckedFunction> const function_ = ((((*this).program))->get_function(function_id));
(((*this).current_function) = static_cast<JaktInternal::Optional<NonnullRefPtr<types::CheckedFunction>>>(function_));
ScopeGuard __jakt_var_492([&] {
(((*this).current_function) = previous_function_id);
});
if (((((function_)->type)).index() == 1 /* ImplicitConstructor */)){
if (((((struct_).generic_parameters)).is_empty())){
(output += TRY((((*this).codegen_constructor_predecl(function_)))));
}
else {
(output += TRY((((*this).codegen_constructor(function_,true)))));
}

(output += Jakt::DeprecatedString("\n"sv));
}
else {
if ((((((struct_).generic_parameters)).is_empty()) && ((((((function_)->generics))->params)).is_empty()))){
(output += TRY((((*this).codegen_function_predecl(function_,true)))));
}
else {
(output += TRY((((*this).codegen_function(function_,true)))));
}

}

}

}
}

}

}
}

if (((((struct_).generic_parameters)).is_empty())){
(output += Jakt::DeprecatedString("ErrorOr<DeprecatedString> debug_description() const;\n"sv));
}
else {
(output += TRY((((*this).codegen_debug_description_getter(struct_,true)))));
}

(output += Jakt::DeprecatedString("};"sv));
(((*this).deferred_output) += TRY((((*this).codegen_ak_formatter(((struct_).name_for_codegen()),generic_parameter_names)))));
return (output);
}
}

ErrorOr<DeprecatedString> codegen::CodeGenerator::codegen_enum_predecl(types::CheckedEnum const enum_) {
{
DeprecatedString output = Jakt::DeprecatedString(""sv);
if ((!(((((enum_).underlying_type_id)).equals(types::void_type_id()))))){
if (((((*this).program))->is_integer(((enum_).underlying_type_id)))){
return (TRY((__jakt_format(Jakt::DeprecatedString("enum class {}: {};"sv),((enum_).name),TRY((((*this).codegen_type(((enum_).underlying_type_id)))))))));
}
else {
utility::todo(Jakt::DeprecatedString("Enums with a non-integer underlying type"sv));
}

}
bool const is_generic = (!(((((enum_).generic_parameters)).is_empty())));
JaktInternal::DynamicArray<DeprecatedString> template_args_array = (TRY((DynamicArray<DeprecatedString>::create_with({}))));
{
JaktInternal::ArrayIterator<types::CheckedGenericParameter> _magic = ((((enum_).generic_parameters)).iterator());
for (;;){
JaktInternal::Optional<types::CheckedGenericParameter> _magic_value = ((_magic).next());
if ((!(((_magic_value).has_value())))){
break;
}
types::CheckedGenericParameter generic_parameter = (_magic_value.value());
{
if (((((((*this).program))->get_type(((generic_parameter).type_id))))->index() == 18 /* TypeVariable */)){
DeprecatedString const name = ((((((*this).program))->get_type(((generic_parameter).type_id))))->get<types::Type::TypeVariable>()).name;
TRY((((template_args_array).push((Jakt::DeprecatedString("typename "sv) + name)))));
}
}

}
}

DeprecatedString template_args = utility::join(template_args_array,Jakt::DeprecatedString(", "sv));
(output += (TRY((__jakt_format(Jakt::DeprecatedString("namespace {}_Details"sv),((enum_).name)))) + Jakt::DeprecatedString(" {\n"sv)));
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
auto&& __jakt_match_value = __jakt_match_variant.template get<types::CheckedEnumVariant::Untyped>();DeprecatedString const& name = __jakt_match_value.name;
{
if (is_generic){
(output += TRY((__jakt_format(Jakt::DeprecatedString("template<{}>\n"sv),template_args))));
}
(output += TRY((__jakt_format(Jakt::DeprecatedString("struct {};\n"sv),name))));
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 3: {
auto&& __jakt_match_value = __jakt_match_variant.template get<types::CheckedEnumVariant::StructLike>();DeprecatedString const& name = __jakt_match_value.name;
{
if (is_generic){
(output += TRY((__jakt_format(Jakt::DeprecatedString("template<{}>\n"sv),template_args))));
}
(output += TRY((__jakt_format(Jakt::DeprecatedString("struct {};\n"sv),name))));
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 1: {
auto&& __jakt_match_value = __jakt_match_variant.template get<types::CheckedEnumVariant::Typed>();DeprecatedString const& name = __jakt_match_value.name;
{
if (is_generic){
(output += TRY((__jakt_format(Jakt::DeprecatedString("template<{}>\n"sv),template_args))));
}
(output += TRY((__jakt_format(Jakt::DeprecatedString("struct {};\n"sv),name))));
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

}
}

(output += Jakt::DeprecatedString("}\n"sv));
if (is_generic){
(output += TRY((__jakt_format(Jakt::DeprecatedString("template<{}>\n"sv),template_args))));
}
(output += TRY((__jakt_format(Jakt::DeprecatedString("struct {};\n"sv),((enum_).name)))));
return (output);
}
}

ErrorOr<DeprecatedString> codegen::CodeGenerator::codegen_binary_expression(NonnullRefPtr<typename types::CheckedExpression> const expression,types::TypeId const type_id,NonnullRefPtr<typename types::CheckedExpression> const lhs,NonnullRefPtr<typename types::CheckedExpression> const rhs,parser::BinaryOperator const op) {
{
if (((op).index() == 20 /* NoneCoalescing */)){
types::TypeId const rhs_type_id = ((rhs)->type());
NonnullRefPtr<typename types::Type> const rhs_type = ((((*this).program))->get_type(rhs_type_id));
bool const rhs_can_throw = ((rhs)->can_throw());
DeprecatedString output = Jakt::DeprecatedString(""sv);
if (rhs_can_throw){
(output += TRY((((*this).current_error_handler()))));
(output += Jakt::DeprecatedString("(("sv));
}
(output += TRY((((*this).codegen_expression(lhs)))));
if (((rhs_type)->index() == 19 /* GenericInstance */)){
types::StructId const id = ((rhs_type)->get<types::Type::GenericInstance>()).id;
if ((((((((*this).program))->get_struct(id))).name_for_codegen()) == Jakt::DeprecatedString("Optional"sv))){
if (rhs_can_throw){
(output += Jakt::DeprecatedString(".try_value_or_lazy_evaluated_optional"sv));
}
else {
(output += Jakt::DeprecatedString(".value_or_lazy_evaluated_optional"sv));
}

}
else {
if (rhs_can_throw){
(output += Jakt::DeprecatedString(".try_value_or_lazy_evaluated"sv));
}
else {
(output += Jakt::DeprecatedString(".value_or_lazy_evaluated"sv));
}

}

}
else {
if (rhs_can_throw){
(output += Jakt::DeprecatedString(".try_value_or_lazy_evaluated"sv));
}
else {
(output += Jakt::DeprecatedString(".value_or_lazy_evaluated"sv));
}

}

if (rhs_can_throw){
(output += Jakt::DeprecatedString("([&]() -> ErrorOr<"sv));
(output += TRY((((*this).codegen_type(rhs_type_id)))));
(output += Jakt::DeprecatedString("> { return "sv));
}
else {
(output += Jakt::DeprecatedString("([&] { return "sv));
}

(output += TRY((((*this).codegen_expression(rhs)))));
(output += Jakt::DeprecatedString("; })"sv));
if (rhs_can_throw){
(output += Jakt::DeprecatedString("))"sv));
}
return (output);
}
if (((op).index() == 32 /* NoneCoalescingAssign */)){
DeprecatedString output = TRY((((*this).codegen_expression(lhs))));
(output += Jakt::DeprecatedString(".lazy_emplace([&] { return "sv));
(output += TRY((((*this).codegen_expression(rhs)))));
(output += Jakt::DeprecatedString("; })"sv));
return (output);
}
if (((op).index() == 17 /* ArithmeticRightShift */)){
DeprecatedString output = Jakt::DeprecatedString("JaktInternal::arithmetic_shift_right("sv);
(output += TRY((((*this).codegen_expression(lhs)))));
(output += Jakt::DeprecatedString(","sv));
(output += TRY((((*this).codegen_expression(rhs)))));
(output += Jakt::DeprecatedString(")"sv));
return (output);
}
if ((((op).index() == 21 /* Assign */) && ((lhs)->index() == 13 /* IndexedDictionary */))){
NonnullRefPtr<typename types::CheckedExpression> const expr = ((lhs)->get<types::CheckedExpression::IndexedDictionary>()).expr;
NonnullRefPtr<typename types::CheckedExpression> const index = ((lhs)->get<types::CheckedExpression::IndexedDictionary>()).index;
return (TRY((__jakt_format(Jakt::DeprecatedString("{}({}.set({}, {}))"sv),TRY((((*this).current_error_handler()))),TRY((((*this).codegen_expression(expr)))),TRY((((*this).codegen_expression(index)))),TRY((((*this).codegen_expression(rhs))))))));
}
if (((((*this).program))->is_integer(type_id))){
JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<void, ErrorOr<DeprecatedString>>{
auto&& __jakt_match_variant = op;
switch(__jakt_match_variant.index()) {
case 0: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename parser::BinaryOperator::Add>();
{
if (((((*this).compiler))->optimize)){
return (((Jakt::DeprecatedString("("sv) + TRY((((*this).codegen_unchecked_binary_op(lhs,rhs,op,type_id))))) + Jakt::DeprecatedString(")"sv)));
}
else {
return (((Jakt::DeprecatedString("("sv) + TRY((((*this).codegen_checked_binary_op(lhs,rhs,op,type_id))))) + Jakt::DeprecatedString(")"sv)));
}

}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 1: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename parser::BinaryOperator::Subtract>();
{
if (((((*this).compiler))->optimize)){
return (((Jakt::DeprecatedString("("sv) + TRY((((*this).codegen_unchecked_binary_op(lhs,rhs,op,type_id))))) + Jakt::DeprecatedString(")"sv)));
}
else {
return (((Jakt::DeprecatedString("("sv) + TRY((((*this).codegen_checked_binary_op(lhs,rhs,op,type_id))))) + Jakt::DeprecatedString(")"sv)));
}

}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 2: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename parser::BinaryOperator::Multiply>();
{
if (((((*this).compiler))->optimize)){
return (((Jakt::DeprecatedString("("sv) + TRY((((*this).codegen_unchecked_binary_op(lhs,rhs,op,type_id))))) + Jakt::DeprecatedString(")"sv)));
}
else {
return (((Jakt::DeprecatedString("("sv) + TRY((((*this).codegen_checked_binary_op(lhs,rhs,op,type_id))))) + Jakt::DeprecatedString(")"sv)));
}

}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 3: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename parser::BinaryOperator::Divide>();
{
if (((((*this).compiler))->optimize)){
return (((Jakt::DeprecatedString("("sv) + TRY((((*this).codegen_unchecked_binary_op(lhs,rhs,op,type_id))))) + Jakt::DeprecatedString(")"sv)));
}
else {
return (((Jakt::DeprecatedString("("sv) + TRY((((*this).codegen_checked_binary_op(lhs,rhs,op,type_id))))) + Jakt::DeprecatedString(")"sv)));
}

}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 4: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename parser::BinaryOperator::Modulo>();
{
if (((((*this).compiler))->optimize)){
return (((Jakt::DeprecatedString("("sv) + TRY((((*this).codegen_unchecked_binary_op(lhs,rhs,op,type_id))))) + Jakt::DeprecatedString(")"sv)));
}
else {
return (((Jakt::DeprecatedString("("sv) + TRY((((*this).codegen_checked_binary_op(lhs,rhs,op,type_id))))) + Jakt::DeprecatedString(")"sv)));
}

}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 27: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename parser::BinaryOperator::AddAssign>();
{
if (((((*this).compiler))->optimize)){
return (((Jakt::DeprecatedString("("sv) + TRY((((*this).codegen_unchecked_binary_op_assignment(lhs,rhs,op,type_id))))) + Jakt::DeprecatedString(")"sv)));
}
else {
return (((Jakt::DeprecatedString("("sv) + TRY((((*this).codegen_checked_binary_op_assignment(lhs,rhs,op,type_id))))) + Jakt::DeprecatedString(")"sv)));
}

}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 28: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename parser::BinaryOperator::SubtractAssign>();
{
if (((((*this).compiler))->optimize)){
return (((Jakt::DeprecatedString("("sv) + TRY((((*this).codegen_unchecked_binary_op_assignment(lhs,rhs,op,type_id))))) + Jakt::DeprecatedString(")"sv)));
}
else {
return (((Jakt::DeprecatedString("("sv) + TRY((((*this).codegen_checked_binary_op_assignment(lhs,rhs,op,type_id))))) + Jakt::DeprecatedString(")"sv)));
}

}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 29: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename parser::BinaryOperator::MultiplyAssign>();
{
if (((((*this).compiler))->optimize)){
return (((Jakt::DeprecatedString("("sv) + TRY((((*this).codegen_unchecked_binary_op_assignment(lhs,rhs,op,type_id))))) + Jakt::DeprecatedString(")"sv)));
}
else {
return (((Jakt::DeprecatedString("("sv) + TRY((((*this).codegen_checked_binary_op_assignment(lhs,rhs,op,type_id))))) + Jakt::DeprecatedString(")"sv)));
}

}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 31: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename parser::BinaryOperator::DivideAssign>();
{
if (((((*this).compiler))->optimize)){
return (((Jakt::DeprecatedString("("sv) + TRY((((*this).codegen_unchecked_binary_op_assignment(lhs,rhs,op,type_id))))) + Jakt::DeprecatedString(")"sv)));
}
else {
return (((Jakt::DeprecatedString("("sv) + TRY((((*this).codegen_checked_binary_op_assignment(lhs,rhs,op,type_id))))) + Jakt::DeprecatedString(")"sv)));
}

}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 30: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename parser::BinaryOperator::ModuloAssign>();
{
if (((((*this).compiler))->optimize)){
return (((Jakt::DeprecatedString("("sv) + TRY((((*this).codegen_unchecked_binary_op_assignment(lhs,rhs,op,type_id))))) + Jakt::DeprecatedString(")"sv)));
}
else {
return (((Jakt::DeprecatedString("("sv) + TRY((((*this).codegen_checked_binary_op_assignment(lhs,rhs,op,type_id))))) + Jakt::DeprecatedString(")"sv)));
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
}
DeprecatedString output = Jakt::DeprecatedString("("sv);
(output += TRY((((*this).codegen_expression(lhs)))));
(output += JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<DeprecatedString, ErrorOr<DeprecatedString>>{
auto&& __jakt_match_variant = op;
switch(__jakt_match_variant.index()) {
case 0: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename parser::BinaryOperator::Add>();
return JaktInternal::ExplicitValue(Jakt::DeprecatedString(" + "sv));
};/*case end*/
case 1: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename parser::BinaryOperator::Subtract>();
return JaktInternal::ExplicitValue(Jakt::DeprecatedString(" - "sv));
};/*case end*/
case 2: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename parser::BinaryOperator::Multiply>();
return JaktInternal::ExplicitValue(Jakt::DeprecatedString(" * "sv));
};/*case end*/
case 4: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename parser::BinaryOperator::Modulo>();
return JaktInternal::ExplicitValue(Jakt::DeprecatedString(" % "sv));
};/*case end*/
case 3: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename parser::BinaryOperator::Divide>();
return JaktInternal::ExplicitValue(Jakt::DeprecatedString(" / "sv));
};/*case end*/
case 21: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename parser::BinaryOperator::Assign>();
return JaktInternal::ExplicitValue(Jakt::DeprecatedString(" = "sv));
};/*case end*/
case 27: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename parser::BinaryOperator::AddAssign>();
return JaktInternal::ExplicitValue(Jakt::DeprecatedString(" += "sv));
};/*case end*/
case 28: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename parser::BinaryOperator::SubtractAssign>();
return JaktInternal::ExplicitValue(Jakt::DeprecatedString(" -= "sv));
};/*case end*/
case 29: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename parser::BinaryOperator::MultiplyAssign>();
return JaktInternal::ExplicitValue(Jakt::DeprecatedString(" *= "sv));
};/*case end*/
case 30: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename parser::BinaryOperator::ModuloAssign>();
return JaktInternal::ExplicitValue(Jakt::DeprecatedString(" %= "sv));
};/*case end*/
case 31: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename parser::BinaryOperator::DivideAssign>();
return JaktInternal::ExplicitValue(Jakt::DeprecatedString(" /= "sv));
};/*case end*/
case 22: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename parser::BinaryOperator::BitwiseAndAssign>();
return JaktInternal::ExplicitValue(Jakt::DeprecatedString(" &= "sv));
};/*case end*/
case 23: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename parser::BinaryOperator::BitwiseOrAssign>();
return JaktInternal::ExplicitValue(Jakt::DeprecatedString(" |= "sv));
};/*case end*/
case 24: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename parser::BinaryOperator::BitwiseXorAssign>();
return JaktInternal::ExplicitValue(Jakt::DeprecatedString(" ^= "sv));
};/*case end*/
case 25: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename parser::BinaryOperator::BitwiseLeftShiftAssign>();
return JaktInternal::ExplicitValue(Jakt::DeprecatedString(" <<= "sv));
};/*case end*/
case 26: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename parser::BinaryOperator::BitwiseRightShiftAssign>();
return JaktInternal::ExplicitValue(Jakt::DeprecatedString(" >>= "sv));
};/*case end*/
case 9: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename parser::BinaryOperator::Equal>();
return JaktInternal::ExplicitValue(Jakt::DeprecatedString(" == "sv));
};/*case end*/
case 10: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename parser::BinaryOperator::NotEqual>();
return JaktInternal::ExplicitValue(Jakt::DeprecatedString(" != "sv));
};/*case end*/
case 5: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename parser::BinaryOperator::LessThan>();
return JaktInternal::ExplicitValue(Jakt::DeprecatedString(" < "sv));
};/*case end*/
case 6: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename parser::BinaryOperator::LessThanOrEqual>();
return JaktInternal::ExplicitValue(Jakt::DeprecatedString(" <= "sv));
};/*case end*/
case 7: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename parser::BinaryOperator::GreaterThan>();
return JaktInternal::ExplicitValue(Jakt::DeprecatedString(" > "sv));
};/*case end*/
case 8: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename parser::BinaryOperator::GreaterThanOrEqual>();
return JaktInternal::ExplicitValue(Jakt::DeprecatedString(" >= "sv));
};/*case end*/
case 18: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename parser::BinaryOperator::LogicalAnd>();
return JaktInternal::ExplicitValue(Jakt::DeprecatedString(" && "sv));
};/*case end*/
case 19: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename parser::BinaryOperator::LogicalOr>();
return JaktInternal::ExplicitValue(Jakt::DeprecatedString(" || "sv));
};/*case end*/
case 11: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename parser::BinaryOperator::BitwiseAnd>();
return JaktInternal::ExplicitValue(Jakt::DeprecatedString(" & "sv));
};/*case end*/
case 13: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename parser::BinaryOperator::BitwiseOr>();
return JaktInternal::ExplicitValue(Jakt::DeprecatedString(" | "sv));
};/*case end*/
case 12: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename parser::BinaryOperator::BitwiseXor>();
return JaktInternal::ExplicitValue(Jakt::DeprecatedString(" ^ "sv));
};/*case end*/
case 16: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename parser::BinaryOperator::ArithmeticLeftShift>();
return JaktInternal::ExplicitValue(Jakt::DeprecatedString(" << "sv));
};/*case end*/
case 14: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename parser::BinaryOperator::BitwiseLeftShift>();
return JaktInternal::ExplicitValue(Jakt::DeprecatedString(" << "sv));
};/*case end*/
case 15: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename parser::BinaryOperator::BitwiseRightShift>();
return JaktInternal::ExplicitValue(Jakt::DeprecatedString(" >> "sv));
};/*case end*/
default: {
return JaktInternal::ExplicitValue(({ Optional<DeprecatedString> __jakt_var_493; {
utility::todo(TRY((__jakt_format(Jakt::DeprecatedString("codegen_binary_expression {}"sv),op))));
__jakt_var_493 = Jakt::DeprecatedString(""sv); goto __jakt_label_435;

}
__jakt_label_435:; __jakt_var_493.release_value(); }));
};/*case end*/
}/*switch end*/
}()
)));
(output += TRY((((*this).codegen_expression(rhs)))));
(output += Jakt::DeprecatedString(")"sv));
return (output);
}
}

ErrorOr<DeprecatedString> codegen::CodeGenerator::codegen_namespace_predecl(NonnullRefPtr<types::Scope> const scope,NonnullRefPtr<types::Module> const current_module) {
{
if ((((((scope)->alias_path)).has_value()) || ((((scope)->import_path_if_extern)).has_value()))){
return (Jakt::DeprecatedString(""sv));
}
DeprecatedString output = Jakt::DeprecatedString(""sv);
if (((((scope)->namespace_name)).has_value())){
(output += Jakt::DeprecatedString("namespace "sv));
(output += (((scope)->namespace_name).value()));
(output += Jakt::DeprecatedString(" {\n"sv));
}
{
JaktInternal::DictionaryIterator<DeprecatedString,types::StructId> _magic = ((((scope)->structs)).iterator());
for (;;){
JaktInternal::Optional<JaktInternal::Tuple<DeprecatedString,types::StructId>> _magic_value = ((_magic).next());
if ((!(((_magic_value).has_value())))){
break;
}
JaktInternal::Tuple<DeprecatedString,types::StructId> ___struct_id__ = (_magic_value.value());
{
JaktInternal::Tuple<DeprecatedString,types::StructId> const jakt_____struct_id__ = ___struct_id__;
DeprecatedString const _ = ((jakt_____struct_id__).template get<0>());
types::StructId const struct_id = ((jakt_____struct_id__).template get<1>());

if ((!(((((struct_id).module)).equals(((current_module)->id)))))){
continue;
}
types::CheckedStruct const struct_ = ((((*this).program))->get_struct(struct_id));
(output += TRY((((*this).codegen_struct_predecl(struct_)))));
(output += Jakt::DeprecatedString("\n"sv));
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
JaktInternal::Tuple<DeprecatedString,types::EnumId> ___enum_id__ = (_magic_value.value());
{
JaktInternal::Tuple<DeprecatedString,types::EnumId> const jakt_____enum_id__ = ___enum_id__;
DeprecatedString const _ = ((jakt_____enum_id__).template get<0>());
types::EnumId const enum_id = ((jakt_____enum_id__).template get<1>());

if ((!(((((enum_id).module)).equals(((current_module)->id)))))){
continue;
}
types::CheckedEnum const enum_ = ((((*this).program))->get_enum(enum_id));
(output += TRY((((*this).codegen_enum_predecl(enum_)))));
(output += Jakt::DeprecatedString("\n"sv));
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
(output += TRY((((*this).codegen_namespace_predecl(TRY((((((*this).program))->get_scope(child)))),current_module)))));
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
if ((!(((((function_id).module)).equals(((current_module)->id)))))){
continue;
}
NonnullRefPtr<types::CheckedFunction> const function_ = ((((*this).program))->get_function(function_id));
if (((((function_)->type)).index() == 2 /* ImplicitEnumConstructor */)){
continue;
}
JaktInternal::Optional<NonnullRefPtr<types::CheckedFunction>> const previous_function_id = ((*this).current_function);
(((*this).current_function) = static_cast<JaktInternal::Optional<NonnullRefPtr<types::CheckedFunction>>>(function_));
ScopeGuard __jakt_var_494([&] {
(((*this).current_function) = previous_function_id);
});
if (((!(((((function_)->type)).index() == 1 /* ImplicitConstructor */))) && (((function_)->name_for_codegen()) != Jakt::DeprecatedString("main"sv)))){
(output += TRY((((*this).codegen_function_predecl(function_,false)))));
(output += Jakt::DeprecatedString("\n"sv));
}
}

}
}

}

}
}

if (((((scope)->namespace_name)).has_value())){
(output += Jakt::DeprecatedString("}\n"sv));
}
return (output);
}
}

ErrorOr<DeprecatedString> codegen::CodeGenerator::current_error_handler() const {
{
if ((((*this).inside_defer) || ((((((*this).current_function)).has_value()) && (((((((*this).current_function).value()))->return_type_id)).equals(types::never_type_id()))) && (!(((((*this).control_flow_state)).passes_through_try)))))){
return (Jakt::DeprecatedString("MUST"sv));
}
return (Jakt::DeprecatedString("TRY"sv));
}
}

ErrorOr<DeprecatedString> codegen::CodeGenerator::codegen_namespace_qualifier(types::ScopeId const scope_id,bool const skip_current,JaktInternal::Optional<DeprecatedString> const possible_constructor_name) const {
{
DeprecatedString output = Jakt::DeprecatedString(""sv);
JaktInternal::Optional<types::ScopeId> current_scope_id = JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<JaktInternal::Optional<types::ScopeId>,ErrorOr<DeprecatedString>>{
auto __jakt_enum_value = (skip_current);
if (__jakt_enum_value == true) {
return JaktInternal::ExplicitValue(((TRY((((((*this).program))->get_scope(scope_id)))))->parent));
}
else {
return JaktInternal::ExplicitValue(scope_id);
}
}()))
;
bool first = true;
while (((current_scope_id).has_value())){
NonnullRefPtr<types::Scope> const scope = TRY((((((*this).program))->get_scope((current_scope_id.value())))));
ScopeGuard __jakt_var_495([&] {
{
(first = false);
(current_scope_id = ((scope)->parent));
}

});
JaktInternal::Optional<DeprecatedString> const name = ((scope)->external_name).value_or_lazy_evaluated_optional([&] { return ((scope)->namespace_name); });
if (((name).has_value())){
if ((first && (possible_constructor_name == name))){
continue;
}
(output = TRY((__jakt_format(Jakt::DeprecatedString("{}::{}"sv),(name.value()),output))));
}
}
return (output);
}
}

ErrorOr<DeprecatedString> codegen::CodeGenerator::codegen_namespace_path(types::CheckedCall const call) const {
{
if (((((call).function_id)).has_value())){
JaktInternal::Optional<types::ScopeId> const scope = ((((((*this).program))->get_function((((call).function_id).value()))))->owner_scope);
if (((scope).has_value())){
return (TRY((((*this).codegen_namespace_qualifier((scope.value()),false,((call).name_for_codegen()))))));
}
}
DeprecatedString output = Jakt::DeprecatedString(""sv);
size_t index = static_cast<size_t>(0ULL);
{
JaktInternal::ArrayIterator<types::ResolvedNamespace> _magic = ((((call).namespace_)).iterator());
for (;;){
JaktInternal::Optional<types::ResolvedNamespace> _magic_value = ((_magic).next());
if ((!(((_magic_value).has_value())))){
break;
}
types::ResolvedNamespace namespace_ = (_magic_value.value());
{
if (((index == (JaktInternal::checked_sub<size_t>(((((call).namespace_)).size()),static_cast<size_t>(1ULL)))) && (((namespace_).name) == ((call).name)))){
break;
}
(output += ((namespace_).external_name).value_or_lazy_evaluated([&] { return ((namespace_).name); }));
if (((((namespace_).generic_parameters)).has_value())){
(output += Jakt::DeprecatedString("<"sv));
size_t i = static_cast<size_t>(0ULL);
{
JaktInternal::ArrayIterator<types::TypeId> _magic = (((((namespace_).generic_parameters).value())).iterator());
for (;;){
JaktInternal::Optional<types::TypeId> _magic_value = ((_magic).next());
if ((!(((_magic_value).has_value())))){
break;
}
types::TypeId param = (_magic_value.value());
{
(output += TRY((((*this).codegen_type(param)))));
if ((i != (JaktInternal::checked_sub<size_t>((((((namespace_).generic_parameters).value())).size()),static_cast<size_t>(1ULL))))){
(output += Jakt::DeprecatedString(","sv));
}
(++(i));
}

}
}

(output += Jakt::DeprecatedString(">"sv));
}
(output += Jakt::DeprecatedString("::"sv));
(++(index));
}

}
}

return (output);
}
}

ErrorOr<DeprecatedString> codegen::CodeGenerator::codegen_type_possibly_as_namespace(types::TypeId const type_id,bool const as_namespace) const {
{
return (JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<DeprecatedString, ErrorOr<DeprecatedString>>{
auto&& __jakt_match_variant = *((((*this).program))->get_type(type_id));
switch(__jakt_match_variant.index()) {
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
return JaktInternal::ExplicitValue(Jakt::DeprecatedString("size_t"sv));
};/*case end*/
case 13: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::Type::JaktString>();
return JaktInternal::ExplicitValue(Jakt::DeprecatedString("DeprecatedString"sv));
};/*case end*/
case 14: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::Type::CChar>();
return JaktInternal::ExplicitValue(Jakt::DeprecatedString("char"sv));
};/*case end*/
case 15: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::Type::CInt>();
return JaktInternal::ExplicitValue(Jakt::DeprecatedString("int"sv));
};/*case end*/
case 17: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::Type::Never>();
return JaktInternal::ExplicitValue(Jakt::DeprecatedString("void"sv));
};/*case end*/
case 25: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::Type::RawPtr>();
types::TypeId const& type_id = __jakt_match_value.value;
return JaktInternal::ExplicitValue((TRY((((*this).codegen_type(type_id)))) + Jakt::DeprecatedString("*"sv)));
};/*case end*/
case 27: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::Type::Reference>();
types::TypeId const& type_id = __jakt_match_value.value;
return JaktInternal::ExplicitValue((TRY((((*this).codegen_type(type_id)))) + Jakt::DeprecatedString(" const&"sv)));
};/*case end*/
case 28: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::Type::MutableReference>();
types::TypeId const& type_id = __jakt_match_value.value;
return JaktInternal::ExplicitValue((TRY((((*this).codegen_type(type_id)))) + Jakt::DeprecatedString("&"sv)));
};/*case end*/
case 22: {
auto&& __jakt_match_value = __jakt_match_variant.template get<types::Type::GenericResolvedType>();types::StructId const& id = __jakt_match_value.id;
JaktInternal::DynamicArray<types::TypeId> const& args = __jakt_match_value.args;
return JaktInternal::ExplicitValue(TRY((((*this).codegen_generic_type_instance(id,args,as_namespace)))));
};/*case end*/
case 19: {
auto&& __jakt_match_value = __jakt_match_variant.template get<types::Type::GenericInstance>();types::StructId const& id = __jakt_match_value.id;
JaktInternal::DynamicArray<types::TypeId> const& args = __jakt_match_value.args;
return JaktInternal::ExplicitValue(TRY((((*this).codegen_generic_type_instance(id,args,as_namespace)))));
};/*case end*/
case 23: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::Type::Struct>();
types::StructId const& id = __jakt_match_value.value;
return JaktInternal::ExplicitValue(TRY((((*this).codegen_struct_type(id,as_namespace)))));
};/*case end*/
case 24: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::Type::Enum>();
types::EnumId const& id = __jakt_match_value.value;
return JaktInternal::ExplicitValue(TRY((((*this).codegen_enum_type(id,as_namespace)))));
};/*case end*/
case 20: {
auto&& __jakt_match_value = __jakt_match_variant.template get<types::Type::GenericEnumInstance>();types::EnumId const& id = __jakt_match_value.id;
JaktInternal::DynamicArray<types::TypeId> const& args = __jakt_match_value.args;
return JaktInternal::ExplicitValue(TRY((((*this).codegen_generic_enum_instance(id,args,as_namespace)))));
};/*case end*/
case 18: {
auto&& __jakt_match_value = __jakt_match_variant.template get<types::Type::TypeVariable>();DeprecatedString const& name = __jakt_match_value.name;
return JaktInternal::ExplicitValue(name);
};/*case end*/
case 29: {
auto&& __jakt_match_value = __jakt_match_variant.template get<types::Type::Function>();JaktInternal::DynamicArray<types::TypeId> const& params = __jakt_match_value.params;
bool const& can_throw = __jakt_match_value.can_throw;
types::TypeId const& return_type_id = __jakt_match_value.return_type_id;
return JaktInternal::ExplicitValue(({ Optional<DeprecatedString> __jakt_var_496; {
DeprecatedString output = Jakt::DeprecatedString("Function<"sv);
if (can_throw){
(output += Jakt::DeprecatedString("ErrorOr<"sv));
}
(output += TRY((((*this).codegen_type(return_type_id)))));
if (can_throw){
(output += Jakt::DeprecatedString(">"sv));
}
(output += Jakt::DeprecatedString("("sv));
bool first = true;
{
JaktInternal::ArrayIterator<types::TypeId> _magic = ((params).iterator());
for (;;){
JaktInternal::Optional<types::TypeId> _magic_value = ((_magic).next());
if ((!(((_magic_value).has_value())))){
break;
}
types::TypeId param = (_magic_value.value());
{
if (first){
(first = false);
}
else {
(output += Jakt::DeprecatedString(", "sv));
}

(output += TRY((((*this).codegen_type(param)))));
}

}
}

(output += Jakt::DeprecatedString(")>"sv));
__jakt_var_496 = output; goto __jakt_label_436;

}
__jakt_label_436:; __jakt_var_496.release_value(); }));
};/*case end*/
case 21: {
auto&& __jakt_match_value = __jakt_match_variant.template get<types::Type::GenericTraitInstance>();{
utility::panic(Jakt::DeprecatedString("Generic trait instance in codegen"sv));
}
};/*case end*/
default: {
return JaktInternal::ExplicitValue(({ Optional<DeprecatedString> __jakt_var_497; {
__jakt_var_497 = Jakt::DeprecatedString("auto"sv); goto __jakt_label_437;

}
__jakt_label_437:; __jakt_var_497.release_value(); }));
};/*case end*/
}/*switch end*/
}()
)));
}
}

ErrorOr<JaktInternal::DynamicArray<DeprecatedString>> codegen::CodeGenerator::extract_dependencies_from(types::TypeId const type_id,JaktInternal::Dictionary<DeprecatedString,JaktInternal::DynamicArray<DeprecatedString>> const dependency_graph,bool const top_level) const {
{
JaktInternal::DynamicArray<DeprecatedString> dependencies = (TRY((DynamicArray<DeprecatedString>::create_with({}))));
if (((dependency_graph).contains(TRY((((type_id).to_string())))))){
{
JaktInternal::ArrayIterator<DeprecatedString> _magic = (((((dependency_graph).get(TRY((((type_id).to_string()))))).value())).iterator());
for (;;){
JaktInternal::Optional<DeprecatedString> _magic_value = ((_magic).next());
if ((!(((_magic_value).has_value())))){
break;
}
DeprecatedString dependency = (_magic_value.value());
{
TRY((((dependencies).push(dependency))));
}

}
}

return (dependencies);
}
NonnullRefPtr<typename types::Type> const type_ = ((((*this).program))->get_type(type_id));
JaktInternal::DynamicArray<DeprecatedString> const inner_dependencies = JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<JaktInternal::DynamicArray<DeprecatedString>, ErrorOr<JaktInternal::DynamicArray<DeprecatedString>>>{
auto&& __jakt_match_variant = *type_;
switch(__jakt_match_variant.index()) {
case 24: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::Type::Enum>();
types::EnumId const& enum_id = __jakt_match_value.value;
return JaktInternal::ExplicitValue(TRY((((*this).extract_dependencies_from_enum(enum_id,dependency_graph,top_level)))));
};/*case end*/
case 20: {
auto&& __jakt_match_value = __jakt_match_variant.template get<types::Type::GenericEnumInstance>();types::EnumId const& id = __jakt_match_value.id;
return JaktInternal::ExplicitValue(TRY((((*this).extract_dependencies_from_enum(id,dependency_graph,top_level)))));
};/*case end*/
case 23: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::Type::Struct>();
types::StructId const& id = __jakt_match_value.value;
return JaktInternal::ExplicitValue(TRY((((*this).extract_dependencies_from_struct(id,dependency_graph,top_level,(TRY((DynamicArray<types::TypeId>::create_with({})))))))));
};/*case end*/
case 19: {
auto&& __jakt_match_value = __jakt_match_variant.template get<types::Type::GenericInstance>();types::StructId const& id = __jakt_match_value.id;
JaktInternal::DynamicArray<types::TypeId> const& args = __jakt_match_value.args;
return JaktInternal::ExplicitValue(TRY((((*this).extract_dependencies_from_struct(id,dependency_graph,top_level,args)))));
};/*case end*/
default: {
return JaktInternal::ExplicitValue((TRY((DynamicArray<DeprecatedString>::create_with({})))));
};/*case end*/
}/*switch end*/
}()
));
{
JaktInternal::ArrayIterator<DeprecatedString> _magic = ((inner_dependencies).iterator());
for (;;){
JaktInternal::Optional<DeprecatedString> _magic_value = ((_magic).next());
if ((!(((_magic_value).has_value())))){
break;
}
DeprecatedString dependency = (_magic_value.value());
{
TRY((((dependencies).push(dependency))));
}

}
}

return (dependencies);
}
}

ErrorOr<DeprecatedString> codegen::CodeGenerator::codegen_match_body(types::CheckedMatchBody const body,types::TypeId const return_type_id) {
{
DeprecatedString output = Jakt::DeprecatedString(""sv);
JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<void, ErrorOr<DeprecatedString>>{
auto&& __jakt_match_variant = body;
switch(__jakt_match_variant.index()) {
case 1: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::CheckedMatchBody::Block>();
types::CheckedBlock const& block = __jakt_match_value.value;
{
(output += TRY((((*this).codegen_block(block)))));
if ((((return_type_id).equals(types::void_type_id())) || ((return_type_id).equals(types::unknown_type_id())))){
(output += Jakt::DeprecatedString("return JaktInternal::ExplicitValue<void>();\n"sv));
}
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 0: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::CheckedMatchBody::Expression>();
NonnullRefPtr<typename types::CheckedExpression> const& expr = __jakt_match_value.value;
{
if ((((((expr)->type())).equals(types::void_type_id())) || (((((expr)->type())).equals(types::unknown_type_id())) && (!(((expr)->index() == 23 /* OptionalNone */)))))){
(output += Jakt::DeprecatedString("return ("sv));
(output += TRY((((*this).codegen_expression(expr)))));
(output += Jakt::DeprecatedString("), JaktInternal::ExplicitValue<void>();\n"sv));
}
else {
(output += Jakt::DeprecatedString("return JaktInternal::ExplicitValue("sv));
(output += TRY((((*this).codegen_expression(expr)))));
(output += Jakt::DeprecatedString(");\n"sv));
}

}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
default: VERIFY_NOT_REACHED();}/*switch end*/
}()
));
return (output);
}
}

ErrorOr<DeprecatedString> codegen::CodeGenerator::codegen_function_predecl(NonnullRefPtr<types::CheckedFunction> const function_,bool const as_method) {
{
DeprecatedString output = Jakt::DeprecatedString(""sv);
if (((!(((((((function_)->generics))->params)).is_empty()))) && ((((function_)->linkage)).index() == 1 /* External */))){
return (Jakt::DeprecatedString(""sv));
}
if (((function_)->is_comptime)){
return (Jakt::DeprecatedString(""sv));
}
if (((((function_)->type)).index() == 1 /* ImplicitConstructor */)){
return (Jakt::DeprecatedString(""sv));
}
if (((((function_)->linkage)).index() == 1 /* External */)){
(output += Jakt::DeprecatedString("extern "sv));
}
(output += TRY((((*this).codegen_function_generic_parameters(function_)))));
if (((((function_)->return_type_id)).equals(types::never_type_id()))){
(output += Jakt::DeprecatedString("[[noreturn]] "sv));
}
if ((((function_)->name_for_codegen()) == Jakt::DeprecatedString("main"sv))){
(output += Jakt::DeprecatedString("ErrorOr<int>"sv));
}
else {
if ((as_method && ((function_)->is_static()))){
(output += Jakt::DeprecatedString("static "sv));
}
if (((function_)->is_virtual)){
(output += Jakt::DeprecatedString("virtual "sv));
}
DeprecatedString const naked_return_type = TRY((((*this).codegen_type(((function_)->return_type_id)))));
DeprecatedString const return_type = JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<DeprecatedString,ErrorOr<DeprecatedString>>{
auto __jakt_enum_value = (((function_)->can_throw));
if (__jakt_enum_value == true) {
return JaktInternal::ExplicitValue(TRY((__jakt_format(Jakt::DeprecatedString("ErrorOr<{}>"sv),naked_return_type))));
}
else {
return JaktInternal::ExplicitValue(naked_return_type);
}
}()))
;
(output += return_type);
}

(output += Jakt::DeprecatedString(" "sv));
(output += ((function_)->name_for_codegen()));
(output += Jakt::DeprecatedString("("sv));
bool first = true;
{
JaktInternal::ArrayIterator<types::CheckedParameter> _magic = ((((function_)->params)).iterator());
for (;;){
JaktInternal::Optional<types::CheckedParameter> _magic_value = ((_magic).next());
if ((!(((_magic_value).has_value())))){
break;
}
types::CheckedParameter param = (_magic_value.value());
{
if ((first && (((((param).variable))->name) == Jakt::DeprecatedString("this"sv)))){
continue;
}
if (first){
(first = false);
}
else {
(output += Jakt::DeprecatedString(", "sv));
}

NonnullRefPtr<typename types::Type> const param_type = ((((*this).program))->get_type(((((param).variable))->type_id)));
(output += TRY((((*this).codegen_type(((((param).variable))->type_id))))));
(output += Jakt::DeprecatedString(" "sv));
if (((!(((((param).variable))->is_mutable))) && (!((((param_type)->index() == 27 /* Reference */) || ((param_type)->index() == 28 /* MutableReference */)))))){
(output += Jakt::DeprecatedString("const "sv));
}
(output += ((((param).variable))->name));
}

}
}

(output += Jakt::DeprecatedString(")"sv));
if (((!(((function_)->is_static()))) && (!(((function_)->is_mutating()))))){
(output += Jakt::DeprecatedString(" const"sv));
}
if (((function_)->is_override)){
(output += Jakt::DeprecatedString(" override"sv));
}
(output += Jakt::DeprecatedString(";"sv));
(output += Jakt::DeprecatedString("\n"sv));
return (output);
}
}

ErrorOr<DeprecatedString> codegen::CodeGenerator::fresh_var() {
{
return (TRY((__jakt_format(Jakt::DeprecatedString("__jakt_var_{}"sv),((((*this).fresh_var_counter)++))))));
}
}

ErrorOr<DeprecatedString> codegen::CodeGenerator::codegen_block(types::CheckedBlock const block) {
{
DeprecatedString output = Jakt::DeprecatedString(""sv);
if (((((block).yielded_type)).has_value())){
types::TypeId const yielded_type = (((block).yielded_type).value());
DeprecatedString const type_output = TRY((((*this).codegen_type(yielded_type))));
DeprecatedString const fresh_var = TRY((((*this).fresh_var())));
DeprecatedString const fresh_label = TRY((((*this).fresh_label())));
TRY((((((*this).entered_yieldable_blocks)).push((Tuple{fresh_var, fresh_label})))));
(output += Jakt::DeprecatedString("({ Optional<"sv));
(output += type_output);
(output += Jakt::DeprecatedString("> "sv));
(output += fresh_var);
(output += Jakt::DeprecatedString("; "sv));
}
(output += Jakt::DeprecatedString("{\n"sv));
{
JaktInternal::ArrayIterator<NonnullRefPtr<typename types::CheckedStatement>> _magic = ((((block).statements)).iterator());
for (;;){
JaktInternal::Optional<NonnullRefPtr<typename types::CheckedStatement>> _magic_value = ((_magic).next());
if ((!(((_magic_value).has_value())))){
break;
}
NonnullRefPtr<typename types::CheckedStatement> statement = (_magic_value.value());
{
(output += TRY((((*this).codegen_statement(statement)))));
}

}
}

(output += Jakt::DeprecatedString("}\n"sv));
if (((((block).yielded_type)).has_value())){
JaktInternal::Tuple<DeprecatedString,DeprecatedString> const var_label_ = (((((*this).entered_yieldable_blocks)).pop()).value());
DeprecatedString const var = ((var_label_).template get<0>());
DeprecatedString const label = ((var_label_).template get<1>());

(output += label);
(output += Jakt::DeprecatedString(":; "sv));
(output += var);
if ((!(((block).yielded_none)))){
(output += Jakt::DeprecatedString(".release_value()"sv));
}
(output += Jakt::DeprecatedString("; })"sv));
}
return (output);
}
}

ErrorOr<DeprecatedString> codegen::CodeGenerator::codegen_checked_binary_op_assignment(NonnullRefPtr<typename types::CheckedExpression> const lhs,NonnullRefPtr<typename types::CheckedExpression> const rhs,parser::BinaryOperator const op,types::TypeId const type_id) {
{
DeprecatedString output = Jakt::DeprecatedString(""sv);
(output += Jakt::DeprecatedString("{"sv));
(output += Jakt::DeprecatedString("auto& _jakt_ref = "sv));
(output += TRY((((*this).codegen_expression(lhs)))));
(output += Jakt::DeprecatedString(";"sv));
(output += Jakt::DeprecatedString("_jakt_ref = JaktInternal::"sv));
(output += JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<DeprecatedString, ErrorOr<DeprecatedString>>{
auto&& __jakt_match_variant = op;
switch(__jakt_match_variant.index()) {
case 27: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename parser::BinaryOperator::AddAssign>();
return JaktInternal::ExplicitValue(Jakt::DeprecatedString("checked_add"sv));
};/*case end*/
case 28: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename parser::BinaryOperator::SubtractAssign>();
return JaktInternal::ExplicitValue(Jakt::DeprecatedString("checked_sub"sv));
};/*case end*/
case 29: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename parser::BinaryOperator::MultiplyAssign>();
return JaktInternal::ExplicitValue(Jakt::DeprecatedString("checked_mul"sv));
};/*case end*/
case 31: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename parser::BinaryOperator::DivideAssign>();
return JaktInternal::ExplicitValue(Jakt::DeprecatedString("checked_div"sv));
};/*case end*/
case 30: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename parser::BinaryOperator::ModuloAssign>();
return JaktInternal::ExplicitValue(Jakt::DeprecatedString("checked_mod"sv));
};/*case end*/
default: {
{
utility::panic(TRY((__jakt_format(Jakt::DeprecatedString("Checked binary operation assignment codegen is not supported for BinaryOperator::{}"sv),op))));
}
};/*case end*/
}/*switch end*/
}()
)));
(output += Jakt::DeprecatedString("<"sv));
(output += TRY((((*this).codegen_type(type_id)))));
(output += Jakt::DeprecatedString(">(_jakt_ref, "sv));
(output += TRY((((*this).codegen_expression(rhs)))));
(output += Jakt::DeprecatedString(");"sv));
(output += Jakt::DeprecatedString("}"sv));
return (output);
}
}

ErrorOr<DeprecatedString> codegen::CodeGenerator::codegen_enum_type(types::EnumId const id,bool const as_namespace) const {
{
DeprecatedString output = Jakt::DeprecatedString(""sv);
NonnullRefPtr<types::Module> const type_module = ((((*this).program))->get_module(((id).module)));
types::CheckedEnum const checked_enum = ((((*this).program))->get_enum(id));
if (((!(as_namespace)) && ((checked_enum).is_boxed))){
(output += Jakt::DeprecatedString("NonnullRefPtr<"sv));
DeprecatedString const qualifier = TRY((((*this).codegen_namespace_qualifier(((checked_enum).scope_id),true,JaktInternal::OptionalNone()))));
if ((!(((qualifier).is_empty())))){
(output += Jakt::DeprecatedString("typename "sv));
(output += qualifier);
}
(output += ((checked_enum).name));
(output += Jakt::DeprecatedString(">"sv));
}
else {
DeprecatedString const qualifier = TRY((((*this).codegen_namespace_qualifier(((checked_enum).scope_id),true,JaktInternal::OptionalNone()))));
if ((!(((qualifier).is_empty())))){
(output += qualifier);
}
(output += ((checked_enum).name));
}

return (output);
}
}

ErrorOr<DeprecatedString> codegen::CodeGenerator::codegen_constructor(NonnullRefPtr<types::CheckedFunction> const function_,bool const is_inline) {
{
types::TypeId const type_id = ((function_)->return_type_id);
NonnullRefPtr<typename types::Type> const type_ = ((((*this).program))->get_type(type_id));
if (((type_)->index() == 23 /* Struct */)){
types::StructId const struct_id = ((type_)->get<types::Type::Struct>()).value;
types::CheckedStruct const structure = ((((*this).program))->get_struct(struct_id));
DeprecatedString const qualified_name = TRY((((*this).codegen_type_possibly_as_namespace(type_id,true))));
DeprecatedString output = Jakt::DeprecatedString(""sv);
if (((!(is_inline)) && (!(((((structure).generic_parameters)).is_empty()))))){
(output += Jakt::DeprecatedString("template <"sv));
bool first = true;
{
JaktInternal::ArrayIterator<types::CheckedGenericParameter> _magic = ((((structure).generic_parameters)).iterator());
for (;;){
JaktInternal::Optional<types::CheckedGenericParameter> _magic_value = ((_magic).next());
if ((!(((_magic_value).has_value())))){
break;
}
types::CheckedGenericParameter param = (_magic_value.value());
{
if (first){
(first = false);
}
else {
(output += Jakt::DeprecatedString(","sv));
}

(output += Jakt::DeprecatedString("typename "sv));
(output += TRY((((*this).codegen_type(((param).type_id))))));
}

}
}

(output += Jakt::DeprecatedString(">\n"sv));
}
if (((((structure).record_type)).index() == 1 /* Class */)){
if (is_inline){
(output += ((function_)->name_for_codegen()));
(output += Jakt::DeprecatedString("("sv));
}
else {
(output += TRY((__jakt_format(Jakt::DeprecatedString("{}::{}("sv),qualified_name,((function_)->name_for_codegen())))));
}

bool first = true;
{
JaktInternal::ArrayIterator<types::CheckedParameter> _magic = ((((function_)->params)).iterator());
for (;;){
JaktInternal::Optional<types::CheckedParameter> _magic_value = ((_magic).next());
if ((!(((_magic_value).has_value())))){
break;
}
types::CheckedParameter param = (_magic_value.value());
{
if ((!(first))){
(output += Jakt::DeprecatedString(", "sv));
}
else {
(first = false);
}

types::TypeId const param_type_id = ((((param).variable))->type_id);
(output += TRY((((*this).codegen_type(param_type_id)))));
(output += Jakt::DeprecatedString("&& a_"sv));
(output += ((((param).variable))->name));
}

}
}

(output += Jakt::DeprecatedString(")"sv));
if ((!(((((function_)->params)).is_empty())))){
(output += Jakt::DeprecatedString(": "sv));
JaktInternal::DynamicArray<DeprecatedString> initializers = (TRY((DynamicArray<DeprecatedString>::create_with({}))));
size_t const parent_constructor_parameter_count = (JaktInternal::checked_sub<size_t>(((((function_)->params)).size()),((((structure).fields)).size())));
if ((parent_constructor_parameter_count > static_cast<size_t>(0ULL))){
DeprecatedString parent_initializer = Jakt::DeprecatedString(""sv);
(parent_initializer += ((((((*this).program))->get_struct((((structure).super_struct_id).value())))).name_for_codegen()));
(parent_initializer += Jakt::DeprecatedString("("sv));
JaktInternal::DynamicArray<DeprecatedString> strings = (TRY((DynamicArray<DeprecatedString>::create_with({}))));
{
JaktInternal::ArrayIterator<types::CheckedParameter> _magic = ((((((function_)->params))[(JaktInternal::Range<size_t>{static_cast<size_t>(static_cast<size_t>(0ULL)),static_cast<size_t>(parent_constructor_parameter_count)})])).iterator());
for (;;){
JaktInternal::Optional<types::CheckedParameter> _magic_value = ((_magic).next());
if ((!(((_magic_value).has_value())))){
break;
}
types::CheckedParameter param = (_magic_value.value());
{
TRY((((strings).push(((Jakt::DeprecatedString("move(a_"sv) + ((((param).variable))->name)) + Jakt::DeprecatedString(")"sv))))));
}

}
}

(parent_initializer += utility::join(strings,Jakt::DeprecatedString(", "sv)));
(parent_initializer += Jakt::DeprecatedString(")"sv));
TRY((((initializers).push(parent_initializer))));
}
{
JaktInternal::Range<size_t> _magic = (JaktInternal::Range<size_t>{static_cast<size_t>(parent_constructor_parameter_count),static_cast<size_t>(((((function_)->params)).size()))});
for (;;){
JaktInternal::Optional<size_t> _magic_value = ((_magic).next());
if ((!(((_magic_value).has_value())))){
break;
}
size_t i = (_magic_value.value());
{
types::CheckedParameter const param = ((((function_)->params))[i]);
TRY((((initializers).push((((((((param).variable))->name) + Jakt::DeprecatedString("(move(a_"sv)) + ((((param).variable))->name)) + Jakt::DeprecatedString("))"sv))))));
}

}
}

(output += utility::join(initializers,Jakt::DeprecatedString(", "sv)));
}
(output += Jakt::DeprecatedString("{}\n"sv));
DeprecatedString class_name_with_generics = Jakt::DeprecatedString(""sv);
(class_name_with_generics += ((structure).name_for_codegen()));
(first = true);
{
JaktInternal::ArrayIterator<types::CheckedGenericParameter> _magic = ((((structure).generic_parameters)).iterator());
for (;;){
JaktInternal::Optional<types::CheckedGenericParameter> _magic_value = ((_magic).next());
if ((!(((_magic_value).has_value())))){
break;
}
types::CheckedGenericParameter generic_parameter = (_magic_value.value());
{
if ((!(first))){
(class_name_with_generics += Jakt::DeprecatedString(", "sv));
}
else {
(class_name_with_generics += Jakt::DeprecatedString("<"sv));
(first = false);
}

(class_name_with_generics += TRY((((*this).codegen_type(((generic_parameter).type_id))))));
}

}
}

if ((!(((((structure).generic_parameters)).is_empty())))){
(class_name_with_generics += Jakt::DeprecatedString(">"sv));
}
if (is_inline){
(output += Jakt::DeprecatedString("static "sv));
}
DeprecatedString const qualified_namespace = JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<DeprecatedString,ErrorOr<DeprecatedString>>{
auto __jakt_enum_value = (is_inline);
if (__jakt_enum_value == true) {
return JaktInternal::ExplicitValue(Jakt::DeprecatedString(""sv));
}
else {
return JaktInternal::ExplicitValue((qualified_name + Jakt::DeprecatedString("::"sv)));
}
}()))
;
(output += TRY((__jakt_format(Jakt::DeprecatedString("ErrorOr<NonnullRefPtr<{}>> {}create"sv),class_name_with_generics,qualified_namespace))));
(output += Jakt::DeprecatedString("("sv));
(first = true);
{
JaktInternal::ArrayIterator<types::CheckedParameter> _magic = ((((function_)->params)).iterator());
for (;;){
JaktInternal::Optional<types::CheckedParameter> _magic_value = ((_magic).next());
if ((!(((_magic_value).has_value())))){
break;
}
types::CheckedParameter param = (_magic_value.value());
{
if ((!(first))){
(output += Jakt::DeprecatedString(", "sv));
}
else {
(first = false);
}

(output += TRY((((*this).codegen_type(((((param).variable))->type_id))))));
(output += Jakt::DeprecatedString(" "sv));
(output += ((((param).variable))->name));
}

}
}

(output += TRY((__jakt_format(Jakt::DeprecatedString(") {{ auto o = {}(adopt_nonnull_ref_or_enomem(new (nothrow) {} ("sv),TRY((((*this).current_error_handler()))),class_name_with_generics))));
(first = true);
{
JaktInternal::ArrayIterator<types::CheckedParameter> _magic = ((((function_)->params)).iterator());
for (;;){
JaktInternal::Optional<types::CheckedParameter> _magic_value = ((_magic).next());
if ((!(((_magic_value).has_value())))){
break;
}
types::CheckedParameter param = (_magic_value.value());
{
if ((!(first))){
(output += Jakt::DeprecatedString(", "sv));
}
else {
(first = false);
}

(output += Jakt::DeprecatedString("move("sv));
(output += ((((param).variable))->name));
(output += Jakt::DeprecatedString(")"sv));
}

}
}

(output += Jakt::DeprecatedString("))); return o; }"sv));
return (output);
}
if ((!(is_inline))){
(output += qualified_name);
(output += Jakt::DeprecatedString("::"sv));
}
(output += ((function_)->name_for_codegen()));
(output += Jakt::DeprecatedString("("sv));
bool first = true;
{
JaktInternal::ArrayIterator<types::CheckedParameter> _magic = ((((function_)->params)).iterator());
for (;;){
JaktInternal::Optional<types::CheckedParameter> _magic_value = ((_magic).next());
if ((!(((_magic_value).has_value())))){
break;
}
types::CheckedParameter param = (_magic_value.value());
{
if ((!(first))){
(output += Jakt::DeprecatedString(", "sv));
}
else {
(first = false);
}

(output += TRY((((*this).codegen_type(((((param).variable))->type_id))))));
(output += Jakt::DeprecatedString(" a_"sv));
(output += ((((param).variable))->name));
}

}
}

(output += Jakt::DeprecatedString(") "sv));
if ((!(((((function_)->params)).is_empty())))){
(output += Jakt::DeprecatedString(":"sv));
}
(first = true);
{
JaktInternal::ArrayIterator<types::CheckedParameter> _magic = ((((function_)->params)).iterator());
for (;;){
JaktInternal::Optional<types::CheckedParameter> _magic_value = ((_magic).next());
if ((!(((_magic_value).has_value())))){
break;
}
types::CheckedParameter param = (_magic_value.value());
{
if ((!(first))){
(output += Jakt::DeprecatedString(", "sv));
}
else {
(first = false);
}

(output += ((((param).variable))->name));
(output += Jakt::DeprecatedString("(a_"sv));
(output += ((((param).variable))->name));
(output += Jakt::DeprecatedString(")"sv));
}

}
}

(output += Jakt::DeprecatedString("{}\n"sv));
return (output);
}
else {
utility::panic(Jakt::DeprecatedString("internal error: call to a constructor, but not a struct/class type"sv));
}

}
}

ErrorOr<DeprecatedString> codegen::CodeGenerator::codegen_enum_debug_description_getter(types::CheckedEnum const enum_,bool const is_inline) {
{
DeprecatedString output = Jakt::DeprecatedString(""sv);
if (((!(is_inline)) && (!(((((enum_).generic_parameters)).is_empty()))))){
(output += Jakt::DeprecatedString("template <"sv));
bool first = true;
{
JaktInternal::ArrayIterator<types::CheckedGenericParameter> _magic = ((((enum_).generic_parameters)).iterator());
for (;;){
JaktInternal::Optional<types::CheckedGenericParameter> _magic_value = ((_magic).next());
if ((!(((_magic_value).has_value())))){
break;
}
types::CheckedGenericParameter param = (_magic_value.value());
{
if (first){
(first = false);
}
else {
(output += Jakt::DeprecatedString(","sv));
}

(output += Jakt::DeprecatedString("typename "sv));
(output += TRY((((*this).codegen_type(((param).type_id))))));
}

}
}

(output += Jakt::DeprecatedString(">\n"sv));
}
(output += Jakt::DeprecatedString("ErrorOr<DeprecatedString> "sv));
if ((!(is_inline))){
(output += TRY((((*this).codegen_type_possibly_as_namespace(((enum_).type_id),true)))));
(output += Jakt::DeprecatedString("::"sv));
}
(output += Jakt::DeprecatedString("debug_description() const {\n"sv));
(output += Jakt::DeprecatedString("auto builder = TRY(DeprecatedStringBuilder::create());\n"sv));
(output += Jakt::DeprecatedString("switch (this->index()) {"sv));
{
JaktInternal::Range<size_t> _magic = (JaktInternal::Range<size_t>{static_cast<size_t>(static_cast<size_t>(0ULL)),static_cast<size_t>(((((enum_).variants)).size()))});
for (;;){
JaktInternal::Optional<size_t> _magic_value = ((_magic).next());
if ((!(((_magic_value).has_value())))){
break;
}
size_t i = (_magic_value.value());
{
types::CheckedEnumVariant const variant = ((((enum_).variants))[i]);
DeprecatedString const name = ((variant).name());
(output += TRY((__jakt_format(Jakt::DeprecatedString("case {} /* {} */: {{\n"sv),i,name))));
(output += TRY((__jakt_format(Jakt::DeprecatedString("[[maybe_unused]] auto const& that = this->template get<{}::{}>();\n"sv),((enum_).name),name))));
(output += TRY((__jakt_format(Jakt::DeprecatedString("TRY(builder.append(\"{}::{}\"sv));\n"sv),((enum_).name),name))));
JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_AT_LOOP(([&]() -> JaktInternal::ExplicitValueOrControlFlow<void, ErrorOr<DeprecatedString>>{
auto&& __jakt_match_variant = variant;
switch(__jakt_match_variant.index()) {
case 3: {
auto&& __jakt_match_value = __jakt_match_variant.template get<types::CheckedEnumVariant::StructLike>();JaktInternal::DynamicArray<types::VarId> const& fields = __jakt_match_value.fields;
{
(output += Jakt::DeprecatedString("TRY(builder.append(\"(\"sv));\n"sv));
(output += Jakt::DeprecatedString("{\n"sv));
(output += Jakt::DeprecatedString("JaktInternal::PrettyPrint::ScopedLevelIncrease increase_indent {};\n"sv));
size_t i = static_cast<size_t>(0ULL);
{
JaktInternal::ArrayIterator<types::VarId> _magic = ((fields).iterator());
for (;;){
JaktInternal::Optional<types::VarId> _magic_value = ((_magic).next());
if ((!(((_magic_value).has_value())))){
break;
}
types::VarId field = (_magic_value.value());
{
(output += Jakt::DeprecatedString("TRY(JaktInternal::PrettyPrint::output_indentation(builder));\n"sv));
NonnullRefPtr<types::CheckedVariable> const var = ((((*this).program))->get_variable(field));
if (((((*this).program))->is_string(((var)->type_id)))){
(output += TRY((__jakt_format(Jakt::DeprecatedString("TRY(builder.appendff(\"{}: \\\"{{}}\\\"\", that.{}));\n"sv),((var)->name),((var)->name)))));
}
else {
(output += TRY((__jakt_format(Jakt::DeprecatedString("TRY(builder.appendff(\"{}: {{}}\", that.{}));\n"sv),((var)->name),((var)->name)))));
}

if ((i != (JaktInternal::checked_sub<size_t>(((fields).size()),static_cast<size_t>(1ULL))))){
(output += Jakt::DeprecatedString("TRY(builder.append(\", \"sv));\n"sv));
}
((i++));
}

}
}

(output += Jakt::DeprecatedString("}\n"sv));
(output += Jakt::DeprecatedString("TRY(builder.append(\")\"sv));\n"sv));
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 1: {
auto&& __jakt_match_value = __jakt_match_variant.template get<types::CheckedEnumVariant::Typed>();types::TypeId const& type_id = __jakt_match_value.type_id;
{
if (((((*this).program))->is_string(type_id))){
(output += Jakt::DeprecatedString("TRY(builder.appendff(\"(\\\"{}\\\")\", that.value));\n"sv));
}
else {
(output += Jakt::DeprecatedString("TRY(builder.appendff(\"({})\", that.value));\n"sv));
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
(output += Jakt::DeprecatedString("break;}\n"sv));
}

}
}

(output += Jakt::DeprecatedString("}\nreturn builder.to_string();\n}\n"sv));
return (output);
}
}

ErrorOr<DeprecatedString> codegen::CodeGenerator::codegen_enum_match(types::CheckedEnum const enum_,NonnullRefPtr<typename types::CheckedExpression> const expr,JaktInternal::DynamicArray<types::CheckedMatchCase> const match_cases,types::TypeId const type_id,bool const all_variants_constant) {
{
DeprecatedString output = Jakt::DeprecatedString(""sv);
(output += ((((*this).control_flow_state)).choose_control_flow_macro()));
DeprecatedString const subject = TRY((((*this).codegen_expression(expr))));
bool const needs_deref = (((enum_).is_boxed) && (subject != Jakt::DeprecatedString("*this"sv)));
if (((((enum_).underlying_type_id)).equals(types::void_type_id()))){
(output += Jakt::DeprecatedString("(([&]() -> JaktInternal::ExplicitValueOrControlFlow<"sv));
(output += TRY((((*this).codegen_type(type_id)))));
(output += Jakt::DeprecatedString(", "sv));
(output += TRY((((*this).codegen_function_return_type((((*this).current_function).value()))))));
(output += Jakt::DeprecatedString(">{\n"sv));
(output += Jakt::DeprecatedString("auto&& __jakt_match_variant = "sv));
if (needs_deref){
(output += Jakt::DeprecatedString("*"sv));
}
(output += (TRY((((*this).codegen_expression(expr)))) + Jakt::DeprecatedString(";\n"sv)));
(output += Jakt::DeprecatedString("switch(__jakt_match_variant.index()) {\n"sv));
bool has_default = false;
{
JaktInternal::ArrayIterator<types::CheckedMatchCase> _magic = ((match_cases).iterator());
for (;;){
JaktInternal::Optional<types::CheckedMatchCase> _magic_value = ((_magic).next());
if ((!(((_magic_value).has_value())))){
break;
}
types::CheckedMatchCase match_case = (_magic_value.value());
{
JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_AT_LOOP(([&]() -> JaktInternal::ExplicitValueOrControlFlow<void, ErrorOr<DeprecatedString>>{
auto&& __jakt_match_variant = match_case;
switch(__jakt_match_variant.index()) {
case 0: {
auto&& __jakt_match_value = __jakt_match_variant.template get<types::CheckedMatchCase::EnumVariant>();DeprecatedString const& name = __jakt_match_value.name;
JaktInternal::DynamicArray<parser::EnumVariantPatternArgument> const& args = __jakt_match_value.args;
types::TypeId const& subject_type_id = __jakt_match_value.subject_type_id;
size_t const& index = __jakt_match_value.index;
types::ScopeId const& scope_id = __jakt_match_value.scope_id;
types::CheckedMatchBody const& body = __jakt_match_value.body;
{
NonnullRefPtr<typename types::Type> const enum_type = ((((*this).program))->get_type(subject_type_id));
types::EnumId const enum_id = JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_AT_LOOP_NESTED_MATCH(([&]() -> JaktInternal::ExplicitValueOrControlFlow<types::EnumId, ErrorOr<DeprecatedString>>{
auto&& __jakt_match_variant = *enum_type;
switch(__jakt_match_variant.index()) {
case 24: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::Type::Enum>();
types::EnumId const& id = __jakt_match_value.value;
return JaktInternal::ExplicitValue(id);
};/*case end*/
default: {
{
utility::panic(Jakt::DeprecatedString("Expected enum type"sv));
}
};/*case end*/
}/*switch end*/
}()
));
types::CheckedEnum const match_case_enum = ((((*this).program))->get_enum(enum_id));
types::CheckedEnumVariant const variant = ((((match_case_enum).variants))[index]);
(output += (TRY((__jakt_format(Jakt::DeprecatedString("case {}: "sv),index))) + Jakt::DeprecatedString("{\n"sv)));
JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_AT_LOOP_NESTED_MATCH(([&]() -> JaktInternal::ExplicitValueOrControlFlow<void, ErrorOr<DeprecatedString>>{
auto&& __jakt_match_variant = variant;
switch(__jakt_match_variant.index()) {
case 0: {
auto&& __jakt_match_value = __jakt_match_variant.template get<types::CheckedEnumVariant::Untyped>();DeprecatedString const& name = __jakt_match_value.name;
{
(output += TRY((__jakt_format(Jakt::DeprecatedString("auto&& __jakt_match_value = __jakt_match_variant.template get<typename {}::{}>();\n"sv),TRY((((*this).codegen_type_possibly_as_namespace(subject_type_id,true)))),name))));
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 1: {
auto&& __jakt_match_value = __jakt_match_variant.template get<types::CheckedEnumVariant::Typed>();DeprecatedString const& name = __jakt_match_value.name;
types::TypeId const& type_id = __jakt_match_value.type_id;
{
(output += TRY((__jakt_format(Jakt::DeprecatedString("auto&& __jakt_match_value = __jakt_match_variant.template get<typename {}::{}>();\n"sv),TRY((((*this).codegen_type_possibly_as_namespace(subject_type_id,true)))),name))));
if ((!(((args).is_empty())))){
parser::EnumVariantPatternArgument const arg = ((args)[static_cast<i64>(0LL)]);
NonnullRefPtr<types::CheckedVariable> const var = (TRY((((((*this).program))->find_var_in_scope(scope_id,((arg).binding))))).value());
(output += TRY((((*this).codegen_type(((var)->type_id))))));
if ((!(((var)->is_mutable)))){
(output += Jakt::DeprecatedString(" const"sv));
}
(output += Jakt::DeprecatedString("& "sv));
(output += ((arg).binding));
(output += Jakt::DeprecatedString(" = __jakt_match_value.value;\n"sv));
}
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 3: {
auto&& __jakt_match_value = __jakt_match_variant.template get<types::CheckedEnumVariant::StructLike>();DeprecatedString const& name = __jakt_match_value.name;
JaktInternal::DynamicArray<types::VarId> const& fields = __jakt_match_value.fields;
{
(output += TRY((__jakt_format(Jakt::DeprecatedString("auto&& __jakt_match_value = __jakt_match_variant.template get<{}::{}>();"sv),TRY((((*this).codegen_type_possibly_as_namespace(subject_type_id,true)))),name))));
if ((!(((args).is_empty())))){
{
JaktInternal::ArrayIterator<parser::EnumVariantPatternArgument> _magic = ((args).iterator());
for (;;){
JaktInternal::Optional<parser::EnumVariantPatternArgument> _magic_value = ((_magic).next());
if ((!(((_magic_value).has_value())))){
break;
}
parser::EnumVariantPatternArgument arg = (_magic_value.value());
{
NonnullRefPtr<types::CheckedVariable> const var = (TRY((((((*this).program))->find_var_in_scope(scope_id,((arg).binding))))).value());
(output += TRY((((*this).codegen_type(((var)->type_id))))));
if ((!(((var)->is_mutable)))){
(output += Jakt::DeprecatedString(" const"sv));
}
(output += Jakt::DeprecatedString("& "sv));
(output += ((arg).binding));
(output += Jakt::DeprecatedString(" = __jakt_match_value."sv));
(output += ((((arg).name)).value_or(((arg).binding))));
(output += Jakt::DeprecatedString(";\n"sv));
}

}
}

}
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
default: {
{
utility::todo(TRY((__jakt_format(Jakt::DeprecatedString("codegen_enum_match match variant else: {}"sv),variant))));
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
}/*switch end*/
}()
));
{
JaktInternal::ArrayIterator<NonnullRefPtr<typename types::CheckedStatement>> _magic = ((((match_case).defaults())).iterator());
for (;;){
JaktInternal::Optional<NonnullRefPtr<typename types::CheckedStatement>> _magic_value = ((_magic).next());
if ((!(((_magic_value).has_value())))){
break;
}
NonnullRefPtr<typename types::CheckedStatement> default_ = (_magic_value.value());
{
(output += TRY((((*this).codegen_statement(default_)))));
}

}
}

(output += TRY((((*this).codegen_match_body(body,type_id)))));
(output += Jakt::DeprecatedString("};/*case end*/\n"sv));
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 2: {
auto&& __jakt_match_value = __jakt_match_variant.template get<types::CheckedMatchCase::CatchAll>();types::CheckedMatchBody const& body = __jakt_match_value.body;
{
(has_default = true);
(output += Jakt::DeprecatedString("default: {\n"sv));
{
JaktInternal::ArrayIterator<NonnullRefPtr<typename types::CheckedStatement>> _magic = ((((match_case).defaults())).iterator());
for (;;){
JaktInternal::Optional<NonnullRefPtr<typename types::CheckedStatement>> _magic_value = ((_magic).next());
if ((!(((_magic_value).has_value())))){
break;
}
NonnullRefPtr<typename types::CheckedStatement> default_ = (_magic_value.value());
{
(output += TRY((((*this).codegen_statement(default_)))));
}

}
}

(output += TRY((((*this).codegen_match_body(body,type_id)))));
(output += Jakt::DeprecatedString("};/*case end*/\n"sv));
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
default: {
{
utility::panic(Jakt::DeprecatedString("Matching enum subject with non-enum value"sv));
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
}/*switch end*/
}()
));
}

}
}

if ((!(has_default))){
if ((((((enum_).variants)).size()) != ((match_cases).size()))){
utility::panic(Jakt::DeprecatedString("Inexhaustive match statement"sv));
}
(output += Jakt::DeprecatedString("default: VERIFY_NOT_REACHED();"sv));
}
(output += Jakt::DeprecatedString("}/*switch end*/\n"sv));
(output += Jakt::DeprecatedString("}()\n))"sv));
}
else {
utility::todo(Jakt::DeprecatedString("underlying type enum match"sv));
}

return (output);
}
}

ErrorOr<DeprecatedString> codegen::CodeGenerator::codegen_lambda_block(bool const can_throw,types::CheckedBlock const block,types::TypeId const return_type_id) {
{
DeprecatedString output = Jakt::DeprecatedString("{\n"sv);
(output += TRY((((*this).codegen_block(block)))));
if ((can_throw && ((return_type_id).equals(types::builtin( types::BuiltinType { typename types::BuiltinType::Void() } ))))){
(output += Jakt::DeprecatedString("return {};\n"sv));
}
(output += Jakt::DeprecatedString("}\n"sv));
return (output);
}
}

ErrorOr<DeprecatedString> codegen::CodeGenerator::codegen_match(NonnullRefPtr<typename types::CheckedExpression> const expr,JaktInternal::DynamicArray<types::CheckedMatchCase> const match_cases,types::TypeId const type_id,bool const all_variants_constant) {
{
codegen::ControlFlowState const last_control_flow = ((*this).control_flow_state);
(((*this).control_flow_state) = ((((*this).control_flow_state)).enter_match()));
DeprecatedString output = Jakt::DeprecatedString(""sv);
NonnullRefPtr<typename types::Type> const expr_type = ((((*this).program))->get_type(((expr)->type())));
if (((expr_type)->index() == 24 /* Enum */)){
types::EnumId const enum_id = ((expr_type)->get<types::Type::Enum>()).value;
(output += TRY((((*this).codegen_enum_match(((((*this).program))->get_enum(enum_id)),expr,match_cases,type_id,all_variants_constant)))));
}
else {
(output += TRY((((*this).codegen_generic_match(expr,match_cases,type_id,all_variants_constant)))));
}

(((*this).control_flow_state) = last_control_flow);
return (output);
}
}

ErrorOr<DeprecatedString> codegen::CodeGenerator::codegen_function_return_type(NonnullRefPtr<types::CheckedFunction> const function_) {
{
if ((((function_)->is_static()) && (((function_)->name_for_codegen()) == Jakt::DeprecatedString("main"sv)))){
return (Jakt::DeprecatedString("ErrorOr<int>"sv));
}
DeprecatedString const type_name = TRY((((*this).codegen_type(((function_)->return_type_id)))));
if (((function_)->can_throw)){
return (TRY((__jakt_format(Jakt::DeprecatedString("ErrorOr<{}>"sv),type_name))));
}
return (type_name);
}
}

ErrorOr<JaktInternal::Dictionary<DeprecatedString,JaktInternal::Tuple<DeprecatedString,DeprecatedString>>> codegen::CodeGenerator::generate(NonnullRefPtr<compiler::Compiler> const compiler,NonnullRefPtr<types::CheckedProgram> const program,bool const debug_info) {
{
codegen::CodeGenerator generator = codegen::CodeGenerator(compiler,program,codegen::ControlFlowState( codegen::AllowedControlExits { typename codegen::AllowedControlExits::Nothing() } ,false,false,static_cast<size_t>(0ULL)),(TRY((DynamicArray<JaktInternal::Tuple<DeprecatedString,DeprecatedString>>::create_with({})))),Jakt::DeprecatedString(""sv),JaktInternal::OptionalNone(),false,codegen::CodegenDebugInfo(compiler,(TRY((Dictionary<size_t, JaktInternal::DynamicArray<codegen::LineSpan>>::create_with_entries({})))),debug_info),(TRY((DynamicArray<DeprecatedString>::create_with({})))),static_cast<size_t>(0ULL),static_cast<size_t>(0ULL));
JaktInternal::Dictionary<DeprecatedString,JaktInternal::Tuple<DeprecatedString,DeprecatedString>> result = (TRY((Dictionary<DeprecatedString, JaktInternal::Tuple<DeprecatedString,DeprecatedString>>::create_with_entries({}))));
DeprecatedString output = Jakt::DeprecatedString(""sv);
(output += Jakt::DeprecatedString("#pragma once\n"sv));
(output += Jakt::DeprecatedString("#include <lib.h>\n"sv));
(output += Jakt::DeprecatedString("#ifdef _WIN32\n"sv));
(output += Jakt::DeprecatedString("extern \"C\" __cdecl int SetConsoleOutputCP(unsigned int code_page);\n"sv));
(output += Jakt::DeprecatedString("const unsigned int CP_UTF8 = 65001;\n"sv));
(output += Jakt::DeprecatedString("#endif\n"sv));
JaktInternal::DynamicArray<types::ModuleId> const sorted_modules = TRY((((generator).topologically_sort_modules())));
(output += Jakt::DeprecatedString("namespace Jakt {\n"sv));
{
JaktInternal::Range<size_t> _magic = (JaktInternal::Range<size_t>{static_cast<size_t>(((sorted_modules).size())),static_cast<size_t>(static_cast<size_t>(0ULL))});
for (;;){
JaktInternal::Optional<size_t> _magic_value = ((_magic).next());
if ((!(((_magic_value).has_value())))){
break;
}
size_t idx = (_magic_value.value());
{
size_t const i = ((((sorted_modules)[(JaktInternal::checked_sub<size_t>(idx,static_cast<size_t>(1ULL)))])).id);
if ((i == static_cast<size_t>(0ULL))){
continue;
}
NonnullRefPtr<types::Module> const module = ((((((generator).program))->modules))[i]);
((((generator).compiler))->dbg_println(TRY((__jakt_format(Jakt::DeprecatedString("generate: module idx: {}, module.name {}"sv),i,((module)->name))))));
types::ScopeId const scope_id = types::ScopeId(((module)->id),static_cast<size_t>(0ULL));
NonnullRefPtr<types::Scope> const scope = TRY((((((generator).program))->get_scope(scope_id))));
(output += TRY((((generator).codegen_namespace_predecl(scope,module)))));
}

}
}

(output += Jakt::DeprecatedString("} // namespace Jakt\n"sv));
TRY((((result).set(Jakt::DeprecatedString("__unified_forward.h"sv),(Tuple{output, (((((compiler)->current_file_path()).value())).to_string())})))));
{
JaktInternal::ArrayIterator<bool> _magic = (((TRY((DynamicArray<bool>::create_with({true, false}))))).iterator());
for (;;){
JaktInternal::Optional<bool> _magic_value = ((_magic).next());
if ((!(((_magic_value).has_value())))){
break;
}
bool as_forward = (_magic_value.value());
{
{
JaktInternal::Range<size_t> _magic = (JaktInternal::Range<size_t>{static_cast<size_t>(((sorted_modules).size())),static_cast<size_t>(static_cast<size_t>(0ULL))});
for (;;){
JaktInternal::Optional<size_t> _magic_value = ((_magic).next());
if ((!(((_magic_value).has_value())))){
break;
}
size_t idx = (_magic_value.value());
{
size_t const i = ((((sorted_modules)[(JaktInternal::checked_sub<size_t>(idx,static_cast<size_t>(1ULL)))])).id);
if ((i == static_cast<size_t>(0ULL))){
continue;
}
NonnullRefPtr<types::Module> const module = ((((((generator).program))->modules))[i]);
((((generator).compiler))->dbg_println(TRY((__jakt_format(Jakt::DeprecatedString("generate: module idx: {}, module.name {} - forward: {}"sv),i,((module)->name),as_forward)))));
DeprecatedString const header_name = TRY((__jakt_format(Jakt::DeprecatedString("{}.h"sv),((module)->name))));
DeprecatedString const impl_name = TRY((__jakt_format(Jakt::DeprecatedString("{}.cpp"sv),((module)->name))));
if (as_forward){
(output = Jakt::DeprecatedString("#pragma once\n"sv));
(output += Jakt::DeprecatedString("#include \"__unified_forward.h\"\n"sv));
}
else {
(output = TRY((__jakt_format(Jakt::DeprecatedString("#include \"{}\"\n"sv),header_name))));
}

types::ScopeId const scope_id = types::ScopeId(((module)->id),static_cast<size_t>(0ULL));
NonnullRefPtr<types::Scope> const scope = TRY((((((generator).program))->get_scope(scope_id))));
if (as_forward){
{
JaktInternal::ArrayIterator<types::ScopeId> _magic = ((((scope)->children)).iterator());
for (;;){
JaktInternal::Optional<types::ScopeId> _magic_value = ((_magic).next());
if ((!(((_magic_value).has_value())))){
break;
}
types::ScopeId child_scope = (_magic_value.value());
{
NonnullRefPtr<types::Scope> const scope = TRY((((((generator).program))->get_scope(child_scope))));
if (((((scope)->import_path_if_extern)).has_value())){
bool const has_name = ((((scope)->namespace_name)).has_value());
if (has_name){
(output += TRY((__jakt_format(Jakt::DeprecatedString("namespace {} {{\n"sv),(((scope)->namespace_name).value())))));
}
{
JaktInternal::ArrayIterator<parser::IncludeAction> _magic = ((((scope)->before_extern_include)).iterator());
for (;;){
JaktInternal::Optional<parser::IncludeAction> _magic_value = ((_magic).next());
if ((!(((_magic_value).has_value())))){
break;
}
parser::IncludeAction action = (_magic_value.value());
{
JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_AT_LOOP(([&]() -> JaktInternal::ExplicitValueOrControlFlow<void, ErrorOr<JaktInternal::Dictionary<DeprecatedString,JaktInternal::Tuple<DeprecatedString,DeprecatedString>>>>{
auto&& __jakt_match_variant = action;
switch(__jakt_match_variant.index()) {
case 0: {
auto&& __jakt_match_value = __jakt_match_variant.template get<parser::IncludeAction::Define>();DeprecatedString const& name = __jakt_match_value.name;
DeprecatedString const& value = __jakt_match_value.value;
{
(output += TRY((__jakt_format(Jakt::DeprecatedString("#ifdef {}\n"sv),name))));
(output += TRY((__jakt_format(Jakt::DeprecatedString("#undef {}\n"sv),name))));
(output += Jakt::DeprecatedString("#endif\n"sv));
(output += TRY((__jakt_format(Jakt::DeprecatedString("#define {} {}\n"sv),name,value))));
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 1: {
auto&& __jakt_match_value = __jakt_match_variant.template get<parser::IncludeAction::Undefine>();DeprecatedString const& name = __jakt_match_value.name;
{
(output += TRY((__jakt_format(Jakt::DeprecatedString("#ifdef {}\n"sv),name))));
(output += TRY((__jakt_format(Jakt::DeprecatedString("#undef {}\n"sv),name))));
(output += Jakt::DeprecatedString("#endif\n"sv));
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
default: VERIFY_NOT_REACHED();}/*switch end*/
}()
));
}

}
}

(output += TRY((__jakt_format(Jakt::DeprecatedString("#include <{}>\n"sv),(((scope)->import_path_if_extern).value())))));
{
JaktInternal::ArrayIterator<parser::IncludeAction> _magic = ((((scope)->after_extern_include)).iterator());
for (;;){
JaktInternal::Optional<parser::IncludeAction> _magic_value = ((_magic).next());
if ((!(((_magic_value).has_value())))){
break;
}
parser::IncludeAction action = (_magic_value.value());
{
JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_AT_LOOP(([&]() -> JaktInternal::ExplicitValueOrControlFlow<void, ErrorOr<JaktInternal::Dictionary<DeprecatedString,JaktInternal::Tuple<DeprecatedString,DeprecatedString>>>>{
auto&& __jakt_match_variant = action;
switch(__jakt_match_variant.index()) {
case 0: {
auto&& __jakt_match_value = __jakt_match_variant.template get<parser::IncludeAction::Define>();DeprecatedString const& name = __jakt_match_value.name;
DeprecatedString const& value = __jakt_match_value.value;
{
(output += TRY((__jakt_format(Jakt::DeprecatedString("#ifdef {}\n"sv),name))));
(output += TRY((__jakt_format(Jakt::DeprecatedString("#undef {}\n"sv),name))));
(output += Jakt::DeprecatedString("#endif\n"sv));
(output += TRY((__jakt_format(Jakt::DeprecatedString("#define {} {}\n"sv),name,value))));
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 1: {
auto&& __jakt_match_value = __jakt_match_variant.template get<parser::IncludeAction::Undefine>();DeprecatedString const& name = __jakt_match_value.name;
{
(output += TRY((__jakt_format(Jakt::DeprecatedString("#ifdef {}\n"sv),name))));
(output += TRY((__jakt_format(Jakt::DeprecatedString("#undef {}\n"sv),name))));
(output += Jakt::DeprecatedString("#endif\n"sv));
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
default: VERIFY_NOT_REACHED();}/*switch end*/
}()
));
}

}
}

if (has_name){
(output += ((Jakt::DeprecatedString(" } // namespace "sv) + (((scope)->namespace_name).value())) + Jakt::DeprecatedString("\n"sv)));
}
}
}

}
}

{
JaktInternal::ArrayIterator<types::ModuleId> _magic = ((((module)->imports)).iterator());
for (;;){
JaktInternal::Optional<types::ModuleId> _magic_value = ((_magic).next());
if ((!(((_magic_value).has_value())))){
break;
}
types::ModuleId id = (_magic_value.value());
{
NonnullRefPtr<types::Module> const module = ((((((generator).program))->modules))[((id).id)]);
(output += TRY((__jakt_format(Jakt::DeprecatedString("#include \"{}.h\"\n"sv),((module)->name)))));
}

}
}

}
(output += Jakt::DeprecatedString("namespace Jakt {\n"sv));
if ((!(((module)->is_root)))){
TRY((((((generator).namespace_stack)).push(((module)->name)))));
}
(output += TRY((((generator).codegen_namespace(scope,module,as_forward)))));
if ((!(((module)->is_root)))){
JaktInternal::Optional<DeprecatedString> const dummy = ((((generator).namespace_stack)).pop());
}
(output += ((generator).deferred_output));
(((generator).deferred_output) = Jakt::DeprecatedString(""sv));
(output += Jakt::DeprecatedString("} // namespace Jakt\n"sv));
if (as_forward){
TRY((((result).set(header_name,(Tuple{output, ((module)->resolved_import_path)})))));
}
else {
TRY((((result).set(impl_name,(Tuple{output, ((module)->resolved_import_path)})))));
}

}

}
}

}

}
}

return (result);
}
}

ErrorOr<DeprecatedString> codegen::CodeGenerator::codegen_call(types::CheckedCall const call) {
{
DeprecatedString output = Jakt::DeprecatedString(""sv);
if (((call).callee_throws)){
(output += TRY((((*this).current_error_handler()))));
(output += Jakt::DeprecatedString("(("sv));
}
JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<void,ErrorOr<DeprecatedString>>{
auto __jakt_enum_value = (((call).name));
if (__jakt_enum_value == Jakt::DeprecatedString("print"sv)) {
{
DeprecatedString const helper = JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<DeprecatedString,ErrorOr<DeprecatedString>>{
auto __jakt_enum_value = (((call).name));
if (__jakt_enum_value == Jakt::DeprecatedString("print"sv)) {
return JaktInternal::ExplicitValue(Jakt::DeprecatedString("out"sv));
}
else if (__jakt_enum_value == Jakt::DeprecatedString("println"sv)) {
return JaktInternal::ExplicitValue(Jakt::DeprecatedString("outln"sv));
}
else if (__jakt_enum_value == Jakt::DeprecatedString("eprint"sv)) {
return JaktInternal::ExplicitValue(Jakt::DeprecatedString("warn"sv));
}
else if (__jakt_enum_value == Jakt::DeprecatedString("eprintln"sv)) {
return JaktInternal::ExplicitValue(Jakt::DeprecatedString("warnln"sv));
}
else if (__jakt_enum_value == Jakt::DeprecatedString("format"sv)) {
return JaktInternal::ExplicitValue(Jakt::DeprecatedString("__jakt_format"sv));
}
else {
return JaktInternal::ExplicitValue(Jakt::DeprecatedString(""sv));
}
}()))
;
(output += helper);
(output += Jakt::DeprecatedString("("sv));
{
JaktInternal::Range<size_t> _magic = (JaktInternal::Range<size_t>{static_cast<size_t>(static_cast<size_t>(0ULL)),static_cast<size_t>(((((call).args)).size()))});
for (;;){
JaktInternal::Optional<size_t> _magic_value = ((_magic).next());
if ((!(((_magic_value).has_value())))){
break;
}
size_t i = (_magic_value.value());
{
JaktInternal::Tuple<DeprecatedString,NonnullRefPtr<typename types::CheckedExpression>> const __expr_ = ((((call).args))[i]);
DeprecatedString const _ = ((__expr_).template get<0>());
NonnullRefPtr<typename types::CheckedExpression> const expr = ((__expr_).template get<1>());

(output += TRY((((*this).codegen_expression(expr)))));
if ((i != (JaktInternal::checked_sub<size_t>(((((call).args)).size()),static_cast<size_t>(1ULL))))){
(output += Jakt::DeprecatedString(","sv));
}
}

}
}

(output += Jakt::DeprecatedString(")"sv));
}
return JaktInternal::ExplicitValue<void>();
}
else if (__jakt_enum_value == Jakt::DeprecatedString("println"sv)) {
{
DeprecatedString const helper = JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<DeprecatedString,ErrorOr<DeprecatedString>>{
auto __jakt_enum_value = (((call).name));
if (__jakt_enum_value == Jakt::DeprecatedString("print"sv)) {
return JaktInternal::ExplicitValue(Jakt::DeprecatedString("out"sv));
}
else if (__jakt_enum_value == Jakt::DeprecatedString("println"sv)) {
return JaktInternal::ExplicitValue(Jakt::DeprecatedString("outln"sv));
}
else if (__jakt_enum_value == Jakt::DeprecatedString("eprint"sv)) {
return JaktInternal::ExplicitValue(Jakt::DeprecatedString("warn"sv));
}
else if (__jakt_enum_value == Jakt::DeprecatedString("eprintln"sv)) {
return JaktInternal::ExplicitValue(Jakt::DeprecatedString("warnln"sv));
}
else if (__jakt_enum_value == Jakt::DeprecatedString("format"sv)) {
return JaktInternal::ExplicitValue(Jakt::DeprecatedString("__jakt_format"sv));
}
else {
return JaktInternal::ExplicitValue(Jakt::DeprecatedString(""sv));
}
}()))
;
(output += helper);
(output += Jakt::DeprecatedString("("sv));
{
JaktInternal::Range<size_t> _magic = (JaktInternal::Range<size_t>{static_cast<size_t>(static_cast<size_t>(0ULL)),static_cast<size_t>(((((call).args)).size()))});
for (;;){
JaktInternal::Optional<size_t> _magic_value = ((_magic).next());
if ((!(((_magic_value).has_value())))){
break;
}
size_t i = (_magic_value.value());
{
JaktInternal::Tuple<DeprecatedString,NonnullRefPtr<typename types::CheckedExpression>> const __expr_ = ((((call).args))[i]);
DeprecatedString const _ = ((__expr_).template get<0>());
NonnullRefPtr<typename types::CheckedExpression> const expr = ((__expr_).template get<1>());

(output += TRY((((*this).codegen_expression(expr)))));
if ((i != (JaktInternal::checked_sub<size_t>(((((call).args)).size()),static_cast<size_t>(1ULL))))){
(output += Jakt::DeprecatedString(","sv));
}
}

}
}

(output += Jakt::DeprecatedString(")"sv));
}
return JaktInternal::ExplicitValue<void>();
}
else if (__jakt_enum_value == Jakt::DeprecatedString("eprintln"sv)) {
{
DeprecatedString const helper = JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<DeprecatedString,ErrorOr<DeprecatedString>>{
auto __jakt_enum_value = (((call).name));
if (__jakt_enum_value == Jakt::DeprecatedString("print"sv)) {
return JaktInternal::ExplicitValue(Jakt::DeprecatedString("out"sv));
}
else if (__jakt_enum_value == Jakt::DeprecatedString("println"sv)) {
return JaktInternal::ExplicitValue(Jakt::DeprecatedString("outln"sv));
}
else if (__jakt_enum_value == Jakt::DeprecatedString("eprint"sv)) {
return JaktInternal::ExplicitValue(Jakt::DeprecatedString("warn"sv));
}
else if (__jakt_enum_value == Jakt::DeprecatedString("eprintln"sv)) {
return JaktInternal::ExplicitValue(Jakt::DeprecatedString("warnln"sv));
}
else if (__jakt_enum_value == Jakt::DeprecatedString("format"sv)) {
return JaktInternal::ExplicitValue(Jakt::DeprecatedString("__jakt_format"sv));
}
else {
return JaktInternal::ExplicitValue(Jakt::DeprecatedString(""sv));
}
}()))
;
(output += helper);
(output += Jakt::DeprecatedString("("sv));
{
JaktInternal::Range<size_t> _magic = (JaktInternal::Range<size_t>{static_cast<size_t>(static_cast<size_t>(0ULL)),static_cast<size_t>(((((call).args)).size()))});
for (;;){
JaktInternal::Optional<size_t> _magic_value = ((_magic).next());
if ((!(((_magic_value).has_value())))){
break;
}
size_t i = (_magic_value.value());
{
JaktInternal::Tuple<DeprecatedString,NonnullRefPtr<typename types::CheckedExpression>> const __expr_ = ((((call).args))[i]);
DeprecatedString const _ = ((__expr_).template get<0>());
NonnullRefPtr<typename types::CheckedExpression> const expr = ((__expr_).template get<1>());

(output += TRY((((*this).codegen_expression(expr)))));
if ((i != (JaktInternal::checked_sub<size_t>(((((call).args)).size()),static_cast<size_t>(1ULL))))){
(output += Jakt::DeprecatedString(","sv));
}
}

}
}

(output += Jakt::DeprecatedString(")"sv));
}
return JaktInternal::ExplicitValue<void>();
}
else if (__jakt_enum_value == Jakt::DeprecatedString("eprint"sv)) {
{
DeprecatedString const helper = JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<DeprecatedString,ErrorOr<DeprecatedString>>{
auto __jakt_enum_value = (((call).name));
if (__jakt_enum_value == Jakt::DeprecatedString("print"sv)) {
return JaktInternal::ExplicitValue(Jakt::DeprecatedString("out"sv));
}
else if (__jakt_enum_value == Jakt::DeprecatedString("println"sv)) {
return JaktInternal::ExplicitValue(Jakt::DeprecatedString("outln"sv));
}
else if (__jakt_enum_value == Jakt::DeprecatedString("eprint"sv)) {
return JaktInternal::ExplicitValue(Jakt::DeprecatedString("warn"sv));
}
else if (__jakt_enum_value == Jakt::DeprecatedString("eprintln"sv)) {
return JaktInternal::ExplicitValue(Jakt::DeprecatedString("warnln"sv));
}
else if (__jakt_enum_value == Jakt::DeprecatedString("format"sv)) {
return JaktInternal::ExplicitValue(Jakt::DeprecatedString("__jakt_format"sv));
}
else {
return JaktInternal::ExplicitValue(Jakt::DeprecatedString(""sv));
}
}()))
;
(output += helper);
(output += Jakt::DeprecatedString("("sv));
{
JaktInternal::Range<size_t> _magic = (JaktInternal::Range<size_t>{static_cast<size_t>(static_cast<size_t>(0ULL)),static_cast<size_t>(((((call).args)).size()))});
for (;;){
JaktInternal::Optional<size_t> _magic_value = ((_magic).next());
if ((!(((_magic_value).has_value())))){
break;
}
size_t i = (_magic_value.value());
{
JaktInternal::Tuple<DeprecatedString,NonnullRefPtr<typename types::CheckedExpression>> const __expr_ = ((((call).args))[i]);
DeprecatedString const _ = ((__expr_).template get<0>());
NonnullRefPtr<typename types::CheckedExpression> const expr = ((__expr_).template get<1>());

(output += TRY((((*this).codegen_expression(expr)))));
if ((i != (JaktInternal::checked_sub<size_t>(((((call).args)).size()),static_cast<size_t>(1ULL))))){
(output += Jakt::DeprecatedString(","sv));
}
}

}
}

(output += Jakt::DeprecatedString(")"sv));
}
return JaktInternal::ExplicitValue<void>();
}
else if (__jakt_enum_value == Jakt::DeprecatedString("format"sv)) {
{
DeprecatedString const helper = JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<DeprecatedString,ErrorOr<DeprecatedString>>{
auto __jakt_enum_value = (((call).name));
if (__jakt_enum_value == Jakt::DeprecatedString("print"sv)) {
return JaktInternal::ExplicitValue(Jakt::DeprecatedString("out"sv));
}
else if (__jakt_enum_value == Jakt::DeprecatedString("println"sv)) {
return JaktInternal::ExplicitValue(Jakt::DeprecatedString("outln"sv));
}
else if (__jakt_enum_value == Jakt::DeprecatedString("eprint"sv)) {
return JaktInternal::ExplicitValue(Jakt::DeprecatedString("warn"sv));
}
else if (__jakt_enum_value == Jakt::DeprecatedString("eprintln"sv)) {
return JaktInternal::ExplicitValue(Jakt::DeprecatedString("warnln"sv));
}
else if (__jakt_enum_value == Jakt::DeprecatedString("format"sv)) {
return JaktInternal::ExplicitValue(Jakt::DeprecatedString("__jakt_format"sv));
}
else {
return JaktInternal::ExplicitValue(Jakt::DeprecatedString(""sv));
}
}()))
;
(output += helper);
(output += Jakt::DeprecatedString("("sv));
{
JaktInternal::Range<size_t> _magic = (JaktInternal::Range<size_t>{static_cast<size_t>(static_cast<size_t>(0ULL)),static_cast<size_t>(((((call).args)).size()))});
for (;;){
JaktInternal::Optional<size_t> _magic_value = ((_magic).next());
if ((!(((_magic_value).has_value())))){
break;
}
size_t i = (_magic_value.value());
{
JaktInternal::Tuple<DeprecatedString,NonnullRefPtr<typename types::CheckedExpression>> const __expr_ = ((((call).args))[i]);
DeprecatedString const _ = ((__expr_).template get<0>());
NonnullRefPtr<typename types::CheckedExpression> const expr = ((__expr_).template get<1>());

(output += TRY((((*this).codegen_expression(expr)))));
if ((i != (JaktInternal::checked_sub<size_t>(((((call).args)).size()),static_cast<size_t>(1ULL))))){
(output += Jakt::DeprecatedString(","sv));
}
}

}
}

(output += Jakt::DeprecatedString(")"sv));
}
return JaktInternal::ExplicitValue<void>();
}
else {
{
bool close_enum_type_wrapper = false;
if (((((call).function_id)).has_value())){
types::FunctionId const function_id = (((call).function_id).value());
NonnullRefPtr<types::CheckedFunction> const function_ = ((((*this).program))->get_function(function_id));
NonnullRefPtr<types::Module> const type_module = ((((*this).program))->get_module(((function_id).module)));
if ((((((function_)->type)).index() == 1 /* ImplicitConstructor */) || ((((function_)->type)).index() == 3 /* ExternalClassConstructor */))){
types::TypeId const type_id = ((call).return_type);
NonnullRefPtr<typename types::Type> const type = ((((*this).program))->get_type(type_id));
(output += TRY((((*this).codegen_namespace_path(call)))));
JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<void, ErrorOr<DeprecatedString>>{
auto&& __jakt_match_variant = *type;
switch(__jakt_match_variant.index()) {
case 23: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::Type::Struct>();
types::StructId const& struct_id = __jakt_match_value.value;
{
types::CheckedStruct const struct_ = ((((*this).program))->get_struct(struct_id));
if (((((struct_).record_type)).index() == 1 /* Class */)){
(output += ((call).name_for_codegen()));
(output += Jakt::DeprecatedString("::"sv));
(output += Jakt::DeprecatedString("create"sv));
}
else {
(output += ((call).name_for_codegen()));
}

}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 19: {
auto&& __jakt_match_value = __jakt_match_variant.template get<types::Type::GenericInstance>();types::StructId const& id = __jakt_match_value.id;
JaktInternal::DynamicArray<types::TypeId> const& args = __jakt_match_value.args;
{
types::CheckedStruct const struct_ = ((((*this).program))->get_struct(id));
if (((((struct_).record_type)).index() == 1 /* Class */)){
(output += TRY((((*this).codegen_namespace_qualifier(((struct_).scope_id),true,JaktInternal::OptionalNone())))));
(output += ((struct_).name_for_codegen()));
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

(output += TRY((((*this).codegen_type(arg)))));
}

}
}

(output += Jakt::DeprecatedString(">::create"sv));
}
else {
(output += ((call).name_for_codegen()));
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

(output += TRY((((*this).codegen_type(arg)))));
}

}
}

(output += Jakt::DeprecatedString(">"sv));
}

}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
default: {
{
utility::panic(Jakt::DeprecatedString("Should be unreachable"sv));
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
}/*switch end*/
}()
));
}
else if (((((function_)->type)).index() == 2 /* ImplicitEnumConstructor */)){
JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<void, ErrorOr<DeprecatedString>>{
auto&& __jakt_match_variant = *((((*this).program))->get_type(((function_)->return_type_id)));
switch(__jakt_match_variant.index()) {
case 24: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename types::Type::Enum>();
types::EnumId const& enum_id = __jakt_match_value.value;
{
types::CheckedEnum const enum_ = ((((*this).program))->get_enum(enum_id));
NonnullRefPtr<types::Module> const enum_type_module = ((((*this).program))->get_module(((enum_id).module)));
if (((enum_).is_boxed)){
(output += TRY((((*this).codegen_namespace_path(call)))));
(output += Jakt::DeprecatedString("template create<typename "sv));
(output += TRY((((*this).codegen_type_possibly_as_namespace(((call).return_type),true)))));
(output += ((Jakt::DeprecatedString("::"sv) + ((call).name_for_codegen())) + Jakt::DeprecatedString(">"sv)));
}
else {
(output += (Jakt::DeprecatedString(" "sv) + TRY((((*this).codegen_type(((call).return_type)))))));
(output += Jakt::DeprecatedString(" { "sv));
(output += Jakt::DeprecatedString("typename "sv));
(output += TRY((((*this).codegen_type_possibly_as_namespace(((call).return_type),true)))));
(output += Jakt::DeprecatedString("::"sv));
(output += ((call).name_for_codegen()));
(close_enum_type_wrapper = true);
}

}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
case 20: {
auto&& __jakt_match_value = __jakt_match_variant.template get<types::Type::GenericEnumInstance>();types::EnumId const& id = __jakt_match_value.id;
{
utility::todo(Jakt::DeprecatedString("codegen generic enum instance"sv));
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
default: {
{
utility::panic(Jakt::DeprecatedString("constructor expected enum type"sv));
}
return JaktInternal::ExplicitValue<void>();
};/*case end*/
}/*switch end*/
}()
));
}
else {
(output += TRY((((*this).codegen_namespace_path(call)))));
(output += ((call).name_for_codegen()));
}

}
else {
(output += TRY((((*this).codegen_namespace_path(call)))));
(output += ((call).name_for_codegen()));
}

JaktInternal::DynamicArray<types::TypeId> const generic_parameters = ((call).type_args);
if ((!(((generic_parameters).is_empty())))){
JaktInternal::DynamicArray<DeprecatedString> types = (TRY((DynamicArray<DeprecatedString>::create_with({}))));
{
JaktInternal::ArrayIterator<types::TypeId> _magic = ((generic_parameters).iterator());
for (;;){
JaktInternal::Optional<types::TypeId> _magic_value = ((_magic).next());
if ((!(((_magic_value).has_value())))){
break;
}
types::TypeId gen_param = (_magic_value.value());
{
TRY((((types).push(TRY((((*this).codegen_type_possibly_as_namespace(gen_param,false))))))));
}

}
}

(output += TRY((__jakt_format(Jakt::DeprecatedString("<{}>"sv),utility::join(types,Jakt::DeprecatedString(", "sv))))));
}
JaktInternal::DynamicArray<DeprecatedString> arguments = (TRY((DynamicArray<DeprecatedString>::create_with({}))));
{
JaktInternal::ArrayIterator<JaktInternal::Tuple<DeprecatedString,NonnullRefPtr<typename types::CheckedExpression>>> _magic = ((((call).args)).iterator());
for (;;){
JaktInternal::Optional<JaktInternal::Tuple<DeprecatedString,NonnullRefPtr<typename types::CheckedExpression>>> _magic_value = ((_magic).next());
if ((!(((_magic_value).has_value())))){
break;
}
JaktInternal::Tuple<DeprecatedString,NonnullRefPtr<typename types::CheckedExpression>> arg = (_magic_value.value());
{
TRY((((arguments).push(TRY((((*this).codegen_expression(((arg).template get<1>())))))))));
}

}
}

(output += TRY((__jakt_format(Jakt::DeprecatedString("({})"sv),utility::join(arguments,Jakt::DeprecatedString(","sv))))));
if (close_enum_type_wrapper){
(output += Jakt::DeprecatedString(" } "sv));
}
}
return JaktInternal::ExplicitValue<void>();
}
return JaktInternal::ExplicitValue<void>();
}()))
;
if (((call).callee_throws)){
(output += Jakt::DeprecatedString("))"sv));
}
return (output);
}
}

ErrorOr<DeprecatedString> codegen::CodeGenerator::codegen_generic_enum_instance(types::EnumId const id,JaktInternal::DynamicArray<types::TypeId> const args,bool const as_namespace) const {
{
DeprecatedString output = Jakt::DeprecatedString(""sv);
bool close_tag = false;
types::CheckedEnum const enum_ = ((((*this).program))->get_enum(id));
if (((!(as_namespace)) && ((enum_).is_boxed))){
(output += Jakt::DeprecatedString("NonnullRefPtr<"sv));
DeprecatedString const qualifier = TRY((((*this).codegen_namespace_qualifier(((enum_).scope_id),true,JaktInternal::OptionalNone()))));
if ((!(((qualifier).is_empty())))){
(output += Jakt::DeprecatedString("typename "sv));
(output += qualifier);
}
(output += ((enum_).name));
(close_tag = true);
}
else {
DeprecatedString const qualifier = TRY((((*this).codegen_namespace_qualifier(((enum_).scope_id),true,JaktInternal::OptionalNone()))));
if ((!(((qualifier).is_empty())))){
if ((!(as_namespace))){
(output += Jakt::DeprecatedString("typename "sv));
}
(output += qualifier);
}
(output += ((enum_).name));
}

(output += Jakt::DeprecatedString("<"sv));
bool first = true;
{
JaktInternal::ArrayIterator<types::TypeId> _magic = ((args).iterator());
for (;;){
JaktInternal::Optional<types::TypeId> _magic_value = ((_magic).next());
if ((!(((_magic_value).has_value())))){
break;
}
types::TypeId type_id = (_magic_value.value());
{
if ((!(first))){
(output += Jakt::DeprecatedString(", "sv));
}
else {
(first = false);
}

(output += TRY((((*this).codegen_type(type_id)))));
}

}
}

(output += Jakt::DeprecatedString(">"sv));
if (close_tag){
(output += Jakt::DeprecatedString(">"sv));
}
return (output);
}
}

ErrorOr<DeprecatedString> codegen::CodeGenerator::codegen_function_generic_parameters(NonnullRefPtr<types::CheckedFunction> const function_) {
{
DeprecatedString output = Jakt::DeprecatedString(""sv);
if ((!(((((((function_)->generics))->params)).is_empty())))){
(output += Jakt::DeprecatedString("template <"sv));
bool first = true;
{
JaktInternal::ArrayIterator<types::FunctionGenericParameter> _magic = ((((((function_)->generics))->params)).iterator());
for (;;){
JaktInternal::Optional<types::FunctionGenericParameter> _magic_value = ((_magic).next());
if ((!(((_magic_value).has_value())))){
break;
}
types::FunctionGenericParameter generic_parameter = (_magic_value.value());
{
if (first){
(first = false);
}
else {
(output += Jakt::DeprecatedString(","sv));
}

(output += Jakt::DeprecatedString("typename "sv));
(output += TRY((((*this).codegen_type(((generic_parameter).type_id()))))));
}

}
}

(output += Jakt::DeprecatedString(">\n"sv));
}
return (output);
}
}

ErrorOr<DeprecatedString> codegen::CodeGenerator::codegen_ak_formatter(DeprecatedString const name,JaktInternal::DynamicArray<DeprecatedString> const generic_parameter_names) {
{
DeprecatedString output = Jakt::DeprecatedString(""sv);
DeprecatedString const template_args = utility::join(TRY((utility::prepend_to_each(generic_parameter_names,Jakt::DeprecatedString("typename "sv)))),Jakt::DeprecatedString(", "sv));
DeprecatedString const generic_type_args = utility::join(generic_parameter_names,Jakt::DeprecatedString(", "sv));
DeprecatedString qualified_name = Jakt::DeprecatedString(""sv);
{
JaktInternal::ArrayIterator<DeprecatedString> _magic = ((((*this).namespace_stack)).iterator());
for (;;){
JaktInternal::Optional<DeprecatedString> _magic_value = ((_magic).next());
if ((!(((_magic_value).has_value())))){
break;
}
DeprecatedString namespace_ = (_magic_value.value());
{
(qualified_name += TRY((__jakt_format(Jakt::DeprecatedString("{}::"sv),namespace_))));
}

}
}

(qualified_name += name);
if ((!(((generic_parameter_names).is_empty())))){
(qualified_name += TRY((__jakt_format(Jakt::DeprecatedString("<{}>\n"sv),generic_type_args))));
}
(output += Jakt::DeprecatedString("} // namespace Jakt\n"sv));
(output += TRY((__jakt_format(Jakt::DeprecatedString("template<{}>"sv),template_args))));
(output += TRY((__jakt_format(Jakt::DeprecatedString("struct Jakt::Formatter<Jakt::{}> : Jakt::Formatter<Jakt::StringView>"sv),qualified_name))));
(output += Jakt::DeprecatedString("{\n"sv));
(output += TRY((__jakt_format(Jakt::DeprecatedString("Jakt::ErrorOr<void> format(Jakt::FormatBuilder& builder, Jakt::{} const& value) {{\n"sv),qualified_name))));
(output += Jakt::DeprecatedString("JaktInternal::PrettyPrint::ScopedEnable pretty_print_enable { m_alternative_form };"sv));
(output += Jakt::DeprecatedString("Jakt::ErrorOr<void> format_error = Jakt::Formatter<Jakt::StringView>::format(builder, MUST(value.debug_description()));"sv));
(output += Jakt::DeprecatedString("return format_error;"sv));
(output += Jakt::DeprecatedString("}\n"sv));
(output += Jakt::DeprecatedString("};\n"sv));
return ((output + Jakt::DeprecatedString("namespace Jakt {\n"sv)));
}
}

ErrorOr<DeprecatedString> codegen::CodeGenerator::codegen_constructor_predecl(NonnullRefPtr<types::CheckedFunction> const function_) {
{
types::TypeId const type_id = ((function_)->return_type_id);
NonnullRefPtr<typename types::Type> const type_ = ((((*this).program))->get_type(type_id));
if (((type_)->index() == 23 /* Struct */)){
types::StructId const struct_id = ((type_)->get<types::Type::Struct>()).value;
types::CheckedStruct const structure = ((((*this).program))->get_struct(struct_id));
if (((((structure).record_type)).index() == 1 /* Class */)){
DeprecatedString output = Jakt::DeprecatedString(""sv);
(output += Jakt::DeprecatedString("protected:\n"sv));
(output += TRY((__jakt_format(Jakt::DeprecatedString("explicit {}("sv),((function_)->name_for_codegen())))));
bool first = true;
{
JaktInternal::ArrayIterator<types::CheckedParameter> _magic = ((((function_)->params)).iterator());
for (;;){
JaktInternal::Optional<types::CheckedParameter> _magic_value = ((_magic).next());
if ((!(((_magic_value).has_value())))){
break;
}
types::CheckedParameter param = (_magic_value.value());
{
if ((!(first))){
(output += Jakt::DeprecatedString(", "sv));
}
else {
(first = false);
}

types::TypeId const param_type_id = ((((param).variable))->type_id);
(output += TRY((((*this).codegen_type(param_type_id)))));
(output += Jakt::DeprecatedString("&& a_"sv));
(output += ((((param).variable))->name));
}

}
}

(output += Jakt::DeprecatedString(");\n"sv));
DeprecatedString class_name_with_generics = Jakt::DeprecatedString(""sv);
(class_name_with_generics += ((structure).name_for_codegen()));
(first = true);
{
JaktInternal::ArrayIterator<types::CheckedGenericParameter> _magic = ((((structure).generic_parameters)).iterator());
for (;;){
JaktInternal::Optional<types::CheckedGenericParameter> _magic_value = ((_magic).next());
if ((!(((_magic_value).has_value())))){
break;
}
types::CheckedGenericParameter generic_parameter = (_magic_value.value());
{
if ((!(first))){
(class_name_with_generics += Jakt::DeprecatedString(", "sv));
}
else {
(class_name_with_generics += Jakt::DeprecatedString("<"sv));
(first = false);
}

(class_name_with_generics += TRY((((*this).codegen_type(((generic_parameter).type_id))))));
}

}
}

if ((!(((((structure).generic_parameters)).is_empty())))){
(class_name_with_generics += Jakt::DeprecatedString(">"sv));
}
(output += Jakt::DeprecatedString("public:\n"sv));
(output += TRY((__jakt_format(Jakt::DeprecatedString("static ErrorOr<NonnullRefPtr<{}>> create"sv),class_name_with_generics))));
(output += Jakt::DeprecatedString("("sv));
(first = true);
{
JaktInternal::ArrayIterator<types::CheckedParameter> _magic = ((((function_)->params)).iterator());
for (;;){
JaktInternal::Optional<types::CheckedParameter> _magic_value = ((_magic).next());
if ((!(((_magic_value).has_value())))){
break;
}
types::CheckedParameter param = (_magic_value.value());
{
if ((!(first))){
(output += Jakt::DeprecatedString(", "sv));
}
else {
(first = false);
}

(output += TRY((((*this).codegen_type(((((param).variable))->type_id))))));
(output += Jakt::DeprecatedString(" "sv));
(output += ((((param).variable))->name));
}

}
}

(output += Jakt::DeprecatedString(");\n"sv));
return (output);
}
DeprecatedString output = Jakt::DeprecatedString(""sv);
(output += ((function_)->name_for_codegen()));
(output += Jakt::DeprecatedString("("sv));
bool first = true;
{
JaktInternal::ArrayIterator<types::CheckedParameter> _magic = ((((function_)->params)).iterator());
for (;;){
JaktInternal::Optional<types::CheckedParameter> _magic_value = ((_magic).next());
if ((!(((_magic_value).has_value())))){
break;
}
types::CheckedParameter param = (_magic_value.value());
{
if ((!(first))){
(output += Jakt::DeprecatedString(", "sv));
}
else {
(first = false);
}

(output += TRY((((*this).codegen_type(((((param).variable))->type_id))))));
(output += Jakt::DeprecatedString(" a_"sv));
(output += ((((param).variable))->name));
}

}
}

(output += Jakt::DeprecatedString(");\n"sv));
return (output);
}
else {
utility::panic(Jakt::DeprecatedString("internal error: call to a constructor, but not a struct/class type"sv));
}

}
}

ErrorOr<DeprecatedString> codegen::CodeGenerator::codegen_type(types::TypeId const type_id) const {
{
return (TRY((((*this).codegen_type_possibly_as_namespace(type_id,false)))));
}
}

ErrorOr<void> codegen::CodeGenerator::postorder_traversal(DeprecatedString const encoded_type_id,JaktInternal::Set<DeprecatedString> visited,JaktInternal::Dictionary<DeprecatedString,JaktInternal::DynamicArray<DeprecatedString>> const encoded_dependency_graph,JaktInternal::DynamicArray<types::TypeId> output) const {
{
types::TypeId const type_id = TRY((types::TypeId::from_string(encoded_type_id)));
if (((visited).contains(TRY((((type_id).to_string())))))){
return {};
}
TRY((((visited).add(TRY((((type_id).to_string())))))));
if (((encoded_dependency_graph).contains(encoded_type_id))){
{
JaktInternal::ArrayIterator<DeprecatedString> _magic = (((((encoded_dependency_graph).get(encoded_type_id)).value())).iterator());
for (;;){
JaktInternal::Optional<DeprecatedString> _magic_value = ((_magic).next());
if ((!(((_magic_value).has_value())))){
break;
}
DeprecatedString dependency = (_magic_value.value());
{
TRY((((*this).postorder_traversal(dependency,visited,encoded_dependency_graph,output))));
}

}
}

}
TRY((((output).push(type_id))));
}
return {};
}

ErrorOr<DeprecatedString> codegen::CodeGenerator::fresh_label() {
{
return (TRY((__jakt_format(Jakt::DeprecatedString("__jakt_label_{}"sv),((((*this).fresh_label_counter)++))))));
}
}

ErrorOr<DeprecatedString> codegen::ControlFlowState::debug_description() const { auto builder = MUST(DeprecatedStringBuilder::create());TRY(builder.append("ControlFlowState("sv));{
JaktInternal::PrettyPrint::ScopedLevelIncrease increase_indent {};
TRY(JaktInternal::PrettyPrint::output_indentation(builder));TRY(builder.append("allowed_exits: "sv));TRY(builder.appendff("{}, ", allowed_exits));
TRY(JaktInternal::PrettyPrint::output_indentation(builder));TRY(builder.append("passes_through_match: "sv));TRY(builder.appendff("{}, ", passes_through_match));
TRY(JaktInternal::PrettyPrint::output_indentation(builder));TRY(builder.append("passes_through_try: "sv));TRY(builder.appendff("{}, ", passes_through_try));
TRY(JaktInternal::PrettyPrint::output_indentation(builder));TRY(builder.append("match_nest_level: "sv));TRY(builder.appendff("{}", match_nest_level));
}
TRY(builder.append(")"sv));return builder.to_string(); }
codegen::ControlFlowState codegen::ControlFlowState::enter_function() const {
{
return (codegen::ControlFlowState( codegen::AllowedControlExits { typename codegen::AllowedControlExits::JustReturn() } ,false,false,((*this).match_nest_level)));
}
}

codegen::ControlFlowState codegen::ControlFlowState::enter_loop() const {
{
return (codegen::ControlFlowState( codegen::AllowedControlExits { typename codegen::AllowedControlExits::AtLoop() } ,false,((*this).passes_through_try),static_cast<size_t>(0ULL)));
}
}

codegen::ControlFlowState codegen::ControlFlowState::no_control_flow() {
{
return (codegen::ControlFlowState( codegen::AllowedControlExits { typename codegen::AllowedControlExits::Nothing() } ,false,false,static_cast<size_t>(0ULL)));
}
}

bool codegen::ControlFlowState::is_match_nested() const {
{
return ((((*this).match_nest_level) != static_cast<size_t>(0ULL)));
}
}

DeprecatedString codegen::ControlFlowState::choose_control_flow_macro() const {
{
if (codegen::are_loop_exits_allowed(((*this).allowed_exits))){
if (((*this).is_match_nested())){
return (Jakt::DeprecatedString("JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_AT_LOOP_NESTED_MATCH"sv));
}
return (Jakt::DeprecatedString("JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_AT_LOOP"sv));
}
return (Jakt::DeprecatedString("JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY"sv));
}
}

codegen::ControlFlowState codegen::ControlFlowState::enter_match() const {
{
size_t level = ((*this).match_nest_level);
if (((*this).passes_through_match)){
(level = (JaktInternal::checked_add<size_t>(((*this).match_nest_level),static_cast<size_t>(1ULL))));
}
return (codegen::ControlFlowState(((((*this).allowed_exits)).allow_return()),true,((*this).passes_through_try),level));
}
}

codegen::ControlFlowState::ControlFlowState(codegen::AllowedControlExits a_allowed_exits, bool a_passes_through_match, bool a_passes_through_try, size_t a_match_nest_level) :allowed_exits(a_allowed_exits), passes_through_match(a_passes_through_match), passes_through_try(a_passes_through_try), match_nest_level(a_match_nest_level){}

ErrorOr<DeprecatedString> codegen::AllowedControlExits::debug_description() const {
auto builder = TRY(DeprecatedStringBuilder::create());
switch (this->index()) {case 0 /* Nothing */: {
[[maybe_unused]] auto const& that = this->template get<AllowedControlExits::Nothing>();
TRY(builder.append("AllowedControlExits::Nothing"sv));
break;}
case 1 /* JustReturn */: {
[[maybe_unused]] auto const& that = this->template get<AllowedControlExits::JustReturn>();
TRY(builder.append("AllowedControlExits::JustReturn"sv));
break;}
case 2 /* AtLoop */: {
[[maybe_unused]] auto const& that = this->template get<AllowedControlExits::AtLoop>();
TRY(builder.append("AllowedControlExits::AtLoop"sv));
break;}
}
return builder.to_string();
}
codegen::AllowedControlExits codegen::AllowedControlExits::allow_return() const {
{
return (JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<codegen::AllowedControlExits, codegen::AllowedControlExits>{
auto&& __jakt_match_variant = *this;
switch(__jakt_match_variant.index()) {
case 0: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename codegen::AllowedControlExits::Nothing>();
return JaktInternal::ExplicitValue( codegen::AllowedControlExits { typename codegen::AllowedControlExits::JustReturn() } );
};/*case end*/
case 1: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename codegen::AllowedControlExits::JustReturn>();
return JaktInternal::ExplicitValue( codegen::AllowedControlExits { typename codegen::AllowedControlExits::JustReturn() } );
};/*case end*/
case 2: {
auto&& __jakt_match_value = __jakt_match_variant.template get<typename codegen::AllowedControlExits::AtLoop>();
return JaktInternal::ExplicitValue( codegen::AllowedControlExits { typename codegen::AllowedControlExits::AtLoop() } );
};/*case end*/
default: VERIFY_NOT_REACHED();}/*switch end*/
}()
)));
}
}

}
} // namespace Jakt
