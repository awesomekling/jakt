#pragma once
#include "__unified_forward.h"
#include "error.h"
#include "lexer.h"
#include "parser.h"
#include "types.h"
#include "types.h"
#include "utility.h"
#include "jakt__path.h"
#include "compiler.h"
#include "interpreter.h"
namespace Jakt {
namespace typechecker {
struct Typechecker {
  public:
NonnullRefPtr<compiler::Compiler> compiler;NonnullRefPtr<types::CheckedProgram> program;types::ModuleId current_module_id;JaktInternal::Optional<types::TypeId> current_struct_type_id;JaktInternal::Optional<types::FunctionId> current_function_id;bool inside_defer;size_t checkidx;bool ignore_errors;bool dump_type_hints;bool dump_try_hints;u64 lambda_count;types::GenericInferences generic_inferences;JaktInternal::Optional<types::TypeId> self_type_id;DeprecatedString root_module_name;ErrorOr<void> typecheck_namespace_predecl(parser::ParsedNamespace const parsed_namespace, types::ScopeId const scope_id);
bool is_struct(types::TypeId const type_id) const;
ErrorOr<void> dump_try_hint(utility::Span const span) const;
ErrorOr<NonnullRefPtr<typename types::CheckedExpression>> typecheck_call(parser::ParsedCall const call, types::ScopeId const caller_scope_id, utility::Span const span, JaktInternal::Optional<NonnullRefPtr<typename types::CheckedExpression>> const this_expr, JaktInternal::Optional<types::StructLikeId> const parent_id, types::SafetyMode const safety_mode, JaktInternal::Optional<types::TypeId> type_hint, bool const must_be_enum_constructor);
ErrorOr<NonnullRefPtr<typename types::CheckedExpression>> typecheck_namespaced_var_or_simple_enum_constructor_call(DeprecatedString const name, JaktInternal::DynamicArray<DeprecatedString> const namespace_, types::ScopeId const scope_id, types::SafetyMode const safety_mode, JaktInternal::Optional<types::TypeId> const type_hint, utility::Span const span);
NonnullRefPtr<types::Module> current_module() const;
ErrorOr<NonnullRefPtr<typename types::Type>> unwrap_type_from_optional_if_needed(NonnullRefPtr<typename types::Type> const type) const;
ErrorOr<void> typecheck_trait(parser::ParsedTrait const parsed_trait, types::TraitId const trait_id, types::ScopeId const scope_id);
ErrorOr<NonnullRefPtr<typename types::CheckedExpression>> typecheck_indexed_tuple(NonnullRefPtr<typename parser::ParsedExpression> const expr, size_t const index, types::ScopeId const scope_id, bool const is_optional, types::SafetyMode const safety_mode, utility::Span const span);
ErrorOr<NonnullRefPtr<typename types::CheckedExpression>> typecheck_match(NonnullRefPtr<typename parser::ParsedExpression> const expr, JaktInternal::DynamicArray<parser::ParsedMatchCase> const cases, utility::Span const span, types::ScopeId const scope_id, types::SafetyMode const safety_mode, JaktInternal::Optional<types::TypeId> const type_hint);
ErrorOr<void> typecheck_module(parser::ParsedNamespace const parsed_namespace, types::ScopeId const scope_id);
ErrorOr<JaktInternal::DynamicArray<JaktInternal::DynamicArray<types::TypeId>>> find_all_implementations_of_trait(types::TypeId const type_id, types::TraitId const trait_id);
ErrorOr<types::TypeId> substitute_typevars_in_type(types::TypeId const type_id, types::GenericInferences const generic_inferences);
ErrorOr<types::StructId> find_struct_in_prelude(DeprecatedString const name) const;
ErrorOr<void> typecheck_module_import(parser::ParsedModuleImport const import_, types::ScopeId const scope_id);
ErrorOr<types::TypeId> typecheck_binary_operation(NonnullRefPtr<typename types::CheckedExpression> const checked_lhs, parser::BinaryOperator const op, NonnullRefPtr<typename types::CheckedExpression> const checked_rhs, types::ScopeId const scope_id, utility::Span const span);
ErrorOr<JaktInternal::Optional<types::StructId>> find_struct_in_scope(types::ScopeId const scope_id, DeprecatedString const name) const;
ErrorOr<void> typecheck_function(parser::ParsedFunction const parsed_function, types::ScopeId const parent_scope_id);
ErrorOr<void> check_type_argument_requirements(types::TypeId const generic_argument, JaktInternal::DynamicArray<types::TraitId> const constraints, utility::Span const arg_span);
ErrorOr<NonnullRefPtr<typename types::CheckedStatement>> typecheck_inline_cpp(parser::ParsedBlock const block, utility::Span const span, types::SafetyMode const safety_mode);
bool is_class(types::TypeId const type_id) const;
ErrorOr<void> typecheck_struct_fields(parser::ParsedRecord const record, types::StructId const struct_id);
ErrorOr<NonnullRefPtr<typename types::CheckedStatement>> typecheck_block_statement(parser::ParsedBlock const parsed_block, types::ScopeId const scope_id, types::SafetyMode const safety_mode, utility::Span const span);
Typechecker(NonnullRefPtr<compiler::Compiler> a_compiler, NonnullRefPtr<types::CheckedProgram> a_program, types::ModuleId a_current_module_id, JaktInternal::Optional<types::TypeId> a_current_struct_type_id, JaktInternal::Optional<types::FunctionId> a_current_function_id, bool a_inside_defer, size_t a_checkidx, bool a_ignore_errors, bool a_dump_type_hints, bool a_dump_try_hints, u64 a_lambda_count, types::GenericInferences a_generic_inferences, JaktInternal::Optional<types::TypeId> a_self_type_id, DeprecatedString a_root_module_name);

bool is_subclass_of(types::TypeId const ancestor_type_id, types::TypeId const child_type_id) const;
ErrorOr<JaktInternal::Tuple<NonnullRefPtr<typename parser::ParsedExpression>,JaktInternal::Optional<parser::ParsedBlock>,JaktInternal::Optional<NonnullRefPtr<typename parser::ParsedStatement>>>> expand_context_for_bindings(NonnullRefPtr<typename parser::ParsedExpression> const condition, JaktInternal::Optional<NonnullRefPtr<typename parser::ParsedExpression>> const acc, JaktInternal::Optional<parser::ParsedBlock> const then_block, JaktInternal::Optional<NonnullRefPtr<typename parser::ParsedStatement>> const else_statement, utility::Span const span);
ErrorOr<JaktInternal::Optional<types::CheckedEnumVariant>> get_enum_variant(types::CheckedEnum const enum_, DeprecatedString const variant_name);
ErrorOr<void> check_implicit_constructor_argument_access(types::ScopeId const caller_scope_id, parser::ParsedCall const call, types::CheckedStruct const struct_);
ErrorOr<NonnullRefPtr<typename types::CheckedExpression>> typecheck_array(types::ScopeId const scope_id, JaktInternal::DynamicArray<NonnullRefPtr<typename parser::ParsedExpression>> const values, JaktInternal::Optional<NonnullRefPtr<typename parser::ParsedExpression>> const fill_size, utility::Span const span, types::SafetyMode const safety_mode, JaktInternal::Optional<types::TypeId> const type_hint);
ErrorOr<NonnullRefPtr<types::Scope>> get_scope(types::ScopeId const id) const;
ErrorOr<bool> check_types_for_compat(types::TypeId const lhs_type_id, types::TypeId const rhs_type_id, types::GenericInferences& generic_inferences, utility::Span const span);
ErrorOr<NonnullRefPtr<typename types::CheckedExpression>> typecheck_lambda(JaktInternal::DynamicArray<parser::ParsedCapture> const captures, JaktInternal::DynamicArray<parser::ParsedParameter> const params, bool const can_throw, bool const is_fat_arrow, NonnullRefPtr<typename parser::ParsedType> const return_type, parser::ParsedBlock const block, utility::Span const span, types::ScopeId const scope_id, types::SafetyMode const safety_mode);
types::CheckedStruct get_struct(types::StructId const id) const;
ErrorOr<NonnullRefPtr<typename types::CheckedStatement>> typecheck_return(JaktInternal::Optional<NonnullRefPtr<typename parser::ParsedExpression>> const expr, utility::Span const span, types::ScopeId const scope_id, types::SafetyMode const safety_mode);
ErrorOr<void> check_that_type_doesnt_contain_reference(types::TypeId const type_id, utility::Span const span);
ErrorOr<void> typecheck_and_specialize_generic_function(types::FunctionId const function_id, JaktInternal::DynamicArray<types::TypeId> const generic_arguments, types::ScopeId const parent_scope_id, JaktInternal::Optional<types::TypeId> const this_type_id, types::GenericInferences const generic_substitutions, JaktInternal::DynamicArray<NonnullRefPtr<typename parser::ParsedType>> const type_args, utility::Span const call_span);
ErrorOr<types::TypeId> strip_optional_from_type(types::TypeId const type_id);
ErrorOr<bool> is_scope_directly_accessible_from(types::ScopeId const scope_id, types::ScopeId const from_scope_id) const;
ErrorOr<void> specialize_trait(types::TraitId const trait_id, JaktInternal::DynamicArray<types::TypeId> const generic_parameters);
NonnullRefPtr<types::CheckedTrait> get_trait(types::TraitId const id) const;
NonnullRefPtr<types::CheckedFunction> get_function(types::FunctionId const id) const;
ErrorOr<JaktInternal::Optional<types::FunctionId>> typecheck_method(parser::ParsedFunction const func, types::StructLikeId const parent_id);
ErrorOr<NonnullRefPtr<typename types::CheckedStatement>> typecheck_var_decl(parser::ParsedVarDecl const var, NonnullRefPtr<typename parser::ParsedExpression> const init, types::ScopeId const scope_id, types::SafetyMode const safety_mode, utility::Span const span);
ErrorOr<JaktInternal::Optional<parser::ParsedNamespace>> lex_and_parse_file_contents(utility::FileId const file_id);
ErrorOr<types::TypeId> resolve_type_var(types::TypeId const type_var_type_id, types::ScopeId const scope_id) const;
ErrorOr<JaktInternal::Optional<types::TraitId>> find_trait_in_scope(types::ScopeId const scope_id, DeprecatedString const name) const;
ErrorOr<bool> find_and_import_name_from_scope(DeprecatedString const from_name, utility::Span const from_span, DeprecatedString const to_name, utility::Span const to_span, types::ScopeId const from_scope_id, types::ScopeId const into_scope_id, typechecker::ImportRestrictions const allow);
ErrorOr<void> typecheck_extern_import(parser::ParsedExternImport const import_, types::ScopeId const scope_id);
ErrorOr<NonnullRefPtr<typename types::CheckedExpression>> typecheck_try(NonnullRefPtr<typename parser::ParsedExpression> const expr, JaktInternal::Optional<parser::ParsedBlock> const catch_block, JaktInternal::Optional<DeprecatedString> const catch_name, types::ScopeId const scope_id, types::SafetyMode const safety_mode, utility::Span const span, JaktInternal::Optional<types::TypeId> const type_hint);
ErrorOr<void> error(DeprecatedString const message, utility::Span const span);
ErrorOr<JaktInternal::DynamicArray<types::FunctionId>> resolve_call(parser::ParsedCall const call, JaktInternal::DynamicArray<types::ResolvedNamespace> namespaces, utility::Span const span, types::ScopeId const scope_id, bool const must_be_enum_constructor);
static ErrorOr<NonnullRefPtr<types::CheckedProgram>> typecheck(NonnullRefPtr<compiler::Compiler> compiler, parser::ParsedNamespace const parsed_namespace);
ErrorOr<bool> add_enum_to_scope(types::ScopeId const scope_id, DeprecatedString const name, types::EnumId const enum_id, utility::Span const span);
ErrorOr<JaktInternal::Optional<JaktInternal::Tuple<JaktInternal::DynamicArray<types::FunctionId>,types::ScopeId>>> find_scoped_functions_with_name_in_scope(types::ScopeId const parent_scope_id, DeprecatedString const function_name) const;
ErrorOr<NonnullRefPtr<typename types::CheckedStatement>> typecheck_if(NonnullRefPtr<typename parser::ParsedExpression> const condition, parser::ParsedBlock const then_block, JaktInternal::Optional<NonnullRefPtr<typename parser::ParsedStatement>> const else_statement, types::ScopeId const scope_id, types::SafetyMode const safety_mode, utility::Span const span);
ErrorOr<types::CheckedVisibility> typecheck_visibility(parser::Visibility const visibility, types::ScopeId const scope_id);
types::ScopeId prelude_scope_id() const;
ErrorOr<JaktInternal::Optional<types::TypeId>> find_type_in_scope(types::ScopeId const scope_id, DeprecatedString const name) const;
ErrorOr<JaktInternal::Optional<types::FieldRecord>> lookup_struct_field(types::StructId const struct_id, DeprecatedString const name) const;
ErrorOr<types::ScopeId> create_scope(JaktInternal::Optional<types::ScopeId> const parent_scope_id, bool const can_throw, DeprecatedString const debug_name);
types::CheckedEnum get_enum(types::EnumId const id) const;
ErrorOr<NonnullRefPtr<typename types::CheckedExpression>> typecheck_try_block(NonnullRefPtr<typename parser::ParsedStatement> const stmt, DeprecatedString const error_name, utility::Span const error_span, parser::ParsedBlock const catch_block, types::ScopeId const scope_id, types::SafetyMode const safety_mode, utility::Span const span);
ErrorOr<types::CheckedUnaryOperator> typecheck_is_enum_variant(NonnullRefPtr<typename types::CheckedExpression> const checked_expr, NonnullRefPtr<typename parser::ParsedType> const inner, JaktInternal::DynamicArray<parser::EnumVariantPatternArgument> const bindings, types::ScopeId const scope_id);
ErrorOr<types::TypeId> find_type_in_prelude(DeprecatedString const name) const;
types::TypeId infer_function_return_type(types::CheckedBlock const block) const;
ErrorOr<JaktInternal::Optional<types::Value>> find_comptime_binding_in_scope(types::ScopeId const scope_id, DeprecatedString const name) const;
ErrorOr<NonnullRefPtr<typename types::CheckedStatement>> typecheck_statement(NonnullRefPtr<typename parser::ParsedStatement> const statement, types::ScopeId const scope_id, types::SafetyMode const safety_mode, JaktInternal::Optional<types::TypeId> const type_hint);
ErrorOr<JaktInternal::DynamicArray<JaktInternal::Tuple<DeprecatedString,utility::Span,NonnullRefPtr<typename types::CheckedExpression>>>> resolve_default_params(JaktInternal::DynamicArray<types::CheckedParameter> const params, JaktInternal::DynamicArray<JaktInternal::Tuple<DeprecatedString,utility::Span,NonnullRefPtr<typename parser::ParsedExpression>>> const args, types::ScopeId const scope_id, types::SafetyMode const safety_mode, size_t const arg_offset, utility::Span const span);
ErrorOr<NonnullRefPtr<typename types::CheckedExpression>> typecheck_expression(NonnullRefPtr<typename parser::ParsedExpression> const expr, types::ScopeId const scope_id, types::SafetyMode const safety_mode, JaktInternal::Optional<types::TypeId> const type_hint);
ErrorOr<void> typecheck_struct_constructor(parser::ParsedRecord const parsed_record, types::StructId const struct_id, types::ScopeId const scope_id);
ErrorOr<void> typecheck_enum_predecl_initial(parser::ParsedRecord const parsed_record, size_t const enum_index, size_t const module_enum_len, types::ScopeId const scope_id);
ErrorOr<JaktInternal::Optional<JaktInternal::DynamicArray<types::FunctionId>>> find_functions_with_name_in_scope(types::ScopeId const parent_scope_id, DeprecatedString const function_name) const;
ErrorOr<types::CheckedParameter> typecheck_parameter(parser::ParsedParameter const parameter, types::ScopeId const scope_id, bool const first, JaktInternal::Optional<types::TypeId> const this_arg_type_id, JaktInternal::Optional<types::ScopeId> const check_scope);
ErrorOr<types::TypeId> typecheck_generic_resolved_type(DeprecatedString const name, JaktInternal::DynamicArray<types::TypeId> const checked_inner_types, types::ScopeId const scope_id, utility::Span const span);
types::BlockControlFlow maybe_statement_control_flow(JaktInternal::Optional<NonnullRefPtr<typename types::CheckedStatement>> const statement, types::BlockControlFlow const other_branch) const;
ErrorOr<void> typecheck_jakt_main(parser::ParsedFunction const parsed_function, types::ScopeId const parent_scope_id);
ErrorOr<NonnullRefPtr<typename types::CheckedStatement>> typecheck_for(DeprecatedString const iterator_name, utility::Span const name_span, NonnullRefPtr<typename parser::ParsedExpression> const range, parser::ParsedBlock const block, types::ScopeId const scope_id, types::SafetyMode const safety_mode, utility::Span const span);
ErrorOr<void> typecheck_namespace_constructors(parser::ParsedNamespace const parsed_namespace, types::ScopeId const scope_id);
bool is_floating(types::TypeId const type_id) const;
ErrorOr<JaktInternal::Tuple<types::CheckedMatchBody,JaktInternal::Optional<types::TypeId>>> typecheck_match_body(parser::ParsedMatchBody const body, types::ScopeId const scope_id, types::SafetyMode const safety_mode, types::GenericInferences& generic_inferences, JaktInternal::Optional<types::TypeId> const final_result_type, utility::Span const span);
ErrorOr<NonnullRefPtr<typename types::CheckedStatement>> typecheck_throw(NonnullRefPtr<typename parser::ParsedExpression> const expr, types::ScopeId const scope_id, types::SafetyMode const safety_mode, utility::Span const span);
ErrorOr<NonnullRefPtr<typename types::CheckedExpression>> typecheck_set(JaktInternal::DynamicArray<NonnullRefPtr<typename parser::ParsedExpression>> const values, utility::Span const span, types::ScopeId const scope_id, types::SafetyMode const safety_mode, JaktInternal::Optional<types::TypeId> const type_hint);
bool is_integer(types::TypeId const type_id) const;
ErrorOr<void> typecheck_namespace_aliases(parser::ParsedNamespace const parsed_namespace, types::ScopeId const scope_id, typechecker::ImportRestrictions const allow);
ErrorOr<NonnullRefPtr<typename types::CheckedStatement>> typecheck_guard(NonnullRefPtr<typename parser::ParsedExpression> const expr, parser::ParsedBlock const else_block, parser::ParsedBlock const remaining_code, types::ScopeId const scope_id, types::SafetyMode const safety_mode, utility::Span const span);
ErrorOr<bool> add_comptime_binding_to_scope(types::ScopeId const scope_id, DeprecatedString const name, types::Value const value, utility::Span const span);
ErrorOr<bool> add_trait_to_scope(types::ScopeId const scope_id, DeprecatedString const trait_name, types::TraitId const trait_id, utility::Span const span);
ErrorOr<bool> signatures_match(types::TypeId const self_type_id, NonnullRefPtr<types::CheckedFunction> const first, NonnullRefPtr<types::CheckedFunction> const second);
ErrorOr<DeprecatedString> type_name(types::TypeId const type_id, bool const debug_mode) const;
ErrorOr<JaktInternal::Tuple<JaktInternal::Optional<DeprecatedString>,types::CheckedMatchCase,JaktInternal::Optional<types::TypeId>>> typecheck_match_variant(parser::ParsedMatchCase const case_, types::TypeId const subject_type_id, size_t const variant_index, JaktInternal::Optional<types::TypeId> const final_result_type, types::CheckedEnumVariant const variant, JaktInternal::DynamicArray<parser::EnumVariantPatternArgument> const variant_arguments, JaktInternal::Dictionary<DeprecatedString,parser::ParsedPatternDefault> const default_bindings, utility::Span const arguments_span, types::ScopeId const scope_id, types::SafetyMode const safety_mode);
ErrorOr<void> error_with_hint(DeprecatedString const message, utility::Span const span, DeprecatedString const hint, utility::Span const hint_span);
ErrorOr<JaktInternal::Optional<typechecker::TraitImplementationDescriptor>> find_singular_trait_implementation(types::TypeId const type_id, DeprecatedString const trait_name, types::ScopeId const scope_id, utility::Span const span);
ErrorOr<types::TypeId> find_or_add_type_id(NonnullRefPtr<typename types::Type> const type);
ErrorOr<JaktInternal::Optional<JaktInternal::Tuple<types::ScopeId,bool>>> find_namespace_in_scope(types::ScopeId const scope_id, DeprecatedString const name, bool const treat_aliases_as_imports) const;
ErrorOr<void> typecheck_enum_predecl(parser::ParsedRecord const parsed_record, types::EnumId const enum_id, types::ScopeId const scope_id);
types::ScopeId root_scope_id() const;
ErrorOr<NonnullRefPtr<typename types::CheckedExpression>> typecheck_unary_operation(NonnullRefPtr<typename types::CheckedExpression> const checked_expr, types::CheckedUnaryOperator const checked_op, utility::Span const span, types::ScopeId const scope_id, types::SafetyMode const safety_mode);
ErrorOr<types::TypeId> final_type_resolution_form(types::TypeId const type_id, types::ScopeId const scope_id) const;
ErrorOr<void> typecheck_namespace_declarations(parser::ParsedNamespace const parsed_namespace, types::ScopeId const scope_id);
ErrorOr<JaktInternal::Optional<typechecker::TraitImplementationDescriptor>> find_any_singular_trait_implementation(types::TypeId const type_id, JaktInternal::DynamicArray<DeprecatedString> const trait_names, types::ScopeId const scope_id, utility::Span const span);
ErrorOr<NonnullRefPtr<typename types::CheckedStatement>> typecheck_defer(NonnullRefPtr<typename parser::ParsedStatement> const statement, types::ScopeId const scope_id, types::SafetyMode const safety_mode, utility::Span const span);
ErrorOr<NonnullRefPtr<typename types::CheckedExpression>> cast_to_underlying(NonnullRefPtr<typename parser::ParsedExpression> const expr, types::ScopeId const scope_id, NonnullRefPtr<typename parser::ParsedType> const parsed_type);
ErrorOr<NonnullRefPtr<typename types::CheckedStatement>> typecheck_destructuring_assignment(JaktInternal::DynamicArray<parser::ParsedVarDecl> const vars, NonnullRefPtr<typename parser::ParsedStatement> const var_decl, types::ScopeId const scope_id, types::SafetyMode const safety_mode, utility::Span const span);
ErrorOr<void> typecheck_struct_default_fields(parser::ParsedRecord const parsed_record, types::StructId const struct_id, types::ScopeId const scope_id);
ErrorOr<void> check_method_access(types::ScopeId const accessor, types::ScopeId const accessee, NonnullRefPtr<types::CheckedFunction> const method, utility::Span const span);
ErrorOr<types::CheckedBlock> typecheck_block(parser::ParsedBlock const parsed_block, types::ScopeId const parent_scope_id, types::SafetyMode const safety_mode, JaktInternal::Optional<types::TypeId> const yield_type_hint);
ErrorOr<NonnullRefPtr<typename types::CheckedStatement>> typecheck_loop(parser::ParsedBlock const parsed_block, types::ScopeId const scope_id, types::SafetyMode const safety_mode, utility::Span const span);
ErrorOr<bool> check_restricted_access(types::ScopeId const accessor, DeprecatedString const accessee_kind, types::ScopeId const accessee, DeprecatedString const name, JaktInternal::DynamicArray<NonnullRefPtr<typename types::MaybeResolvedScope>> const whitelist, utility::Span const span);
ErrorOr<JaktInternal::Optional<JaktInternal::DynamicArray<types::TypeId>>> get_type_ids_from_type_hint_if_struct_ids_match(JaktInternal::Optional<types::TypeId> const type_hint, types::StructId const expected_struct_id) const;
ErrorOr<JaktInternal::DynamicArray<types::StructId>> struct_inheritance_chain(types::StructId const struct_id) const;
ErrorOr<bool> add_function_to_scope(types::ScopeId const parent_scope_id, DeprecatedString const name, JaktInternal::DynamicArray<types::FunctionId> const overload_set, utility::Span const span);
ErrorOr<NonnullRefPtr<typename types::CheckedExpression>> typecheck_expression_and_dereference_if_needed(NonnullRefPtr<typename parser::ParsedExpression> const expr, types::ScopeId const scope_id, types::SafetyMode const safety_mode, JaktInternal::Optional<types::TypeId> const type_hint, utility::Span const span);
ErrorOr<jakt__path::Path> get_root_path() const;
ErrorOr<bool> scope_can_access(types::ScopeId const accessor, types::ScopeId const accessee) const;
ErrorOr<void> dump_type_hint(types::TypeId const type_id, utility::Span const span) const;
ErrorOr<void> typecheck_namespace_default_fields(parser::ParsedNamespace const parsed_namespace, types::ScopeId const scope_id);
ErrorOr<void> typecheck_namespace_imports(parser::ParsedNamespace const parsed_namespace, types::ScopeId const scope_id);
ErrorOr<types::TypeId> typecheck_typename(NonnullRefPtr<typename parser::ParsedType> const parsed_type, types::ScopeId const scope_id, JaktInternal::Optional<DeprecatedString> const name);
ErrorOr<JaktInternal::Optional<types::TypeId>> unify(types::TypeId const lhs, utility::Span const lhs_span, types::TypeId const rhs, utility::Span const rhs_span);
bool is_numeric(types::TypeId const type_id) const;
ErrorOr<bool> add_type_to_scope(types::ScopeId const scope_id, DeprecatedString const type_name, types::TypeId const type_id, utility::Span const span);
ErrorOr<bool> add_var_to_scope(types::ScopeId const scope_id, DeprecatedString const name, types::VarId const var_id, utility::Span const span);
ErrorOr<NonnullRefPtr<typename types::CheckedExpression>> typecheck_generic_arguments_method_call(NonnullRefPtr<typename types::CheckedExpression> const checked_expr, parser::ParsedCall const call, types::ScopeId const scope_id, utility::Span const span, bool const is_optional, types::SafetyMode const safety_mode);
ErrorOr<typechecker::FunctionMatchResult> match_function_and_resolve_args(parser::ParsedCall const call, types::ScopeId const caller_scope_id, types::FunctionId const candidate, types::SafetyMode const safety_mode, utility::Span const span, JaktInternal::Optional<NonnullRefPtr<typename types::CheckedExpression>> const this_expr);
ErrorOr<void> include_prelude();
ErrorOr<void> typecheck_namespace_fields(parser::ParsedNamespace const parsed_namespace, types::ScopeId const scope_id);
ErrorOr<NonnullRefPtr<typename types::CheckedStatement>> typecheck_while(NonnullRefPtr<typename parser::ParsedExpression> const condition, parser::ParsedBlock const block, types::ScopeId const scope_id, types::SafetyMode const safety_mode, utility::Span const span);
ErrorOr<void> fill_trait_implementation_list(JaktInternal::DynamicArray<parser::ParsedNameWithGenericParameters> const parsed_impl_list, JaktInternal::Dictionary<DeprecatedString,JaktInternal::Tuple<types::TraitId,JaktInternal::DynamicArray<types::TypeId>>>& trait_implementations, types::ScopeId const scope_id, JaktInternal::Optional<types::ScopeId> const trait_name_scope_id_override);
NonnullRefPtr<types::CheckedVariable> get_variable(types::VarId const id) const;
ErrorOr<void> typecheck_struct_predecl(parser::ParsedRecord const parsed_record, types::StructId const struct_id, types::ScopeId const scope_id);
ErrorOr<JaktInternal::Optional<JaktInternal::Tuple<types::TypeId,types::ScopeId>>> find_type_scope(types::ScopeId const scope_id, DeprecatedString const name) const;
ErrorOr<void> check_member_access(types::ScopeId const accessor, types::ScopeId const accessee, NonnullRefPtr<types::CheckedVariable> const member, utility::Span const span);
ErrorOr<bool> add_struct_to_scope(types::ScopeId const scope_id, DeprecatedString const name, types::StructId const struct_id, utility::Span const span);
ErrorOr<NonnullRefPtr<typename types::CheckedExpression>> infer_unsigned_int(u64 const val, utility::Span const span, JaktInternal::Optional<types::TypeId> const type_hint);
ErrorOr<NonnullRefPtr<typename types::CheckedExpression>> typecheck_unary_negate(NonnullRefPtr<typename types::CheckedExpression> const expr, utility::Span const span, types::TypeId const type_id);
ErrorOr<NonnullRefPtr<typename types::CheckedExpression>> typecheck_dictionary(JaktInternal::DynamicArray<JaktInternal::Tuple<NonnullRefPtr<typename parser::ParsedExpression>,NonnullRefPtr<typename parser::ParsedExpression>>> const values, utility::Span const span, types::ScopeId const scope_id, types::SafetyMode const safety_mode, JaktInternal::Optional<types::TypeId> const type_hint);
ErrorOr<void> typecheck_alias(parser::ParsedAlias const alias, types::ScopeId const scope_id, typechecker::ImportRestrictions const allow);
ErrorOr<types::TypeId> unify_with_type(types::TypeId const found_type, JaktInternal::Optional<types::TypeId> const expected_type, utility::Span const span);
ErrorOr<void> typecheck_trait_predecl(parser::ParsedTrait const parsed_trait, types::ScopeId const scope_id);
types::BlockControlFlow statement_control_flow(NonnullRefPtr<typename types::CheckedStatement> const statement) const;
ErrorOr<JaktInternal::Optional<types::FunctionId>> find_function_matching_signature_in_scope(types::ScopeId const parent_scope_id, parser::ParsedFunction const prototype) const;
ErrorOr<void> map_generic_arguments(types::TypeId const type_id, JaktInternal::DynamicArray<types::TypeId> const args);
ErrorOr<bool> validate_argument_label(types::CheckedParameter const param, DeprecatedString const label, utility::Span const span, NonnullRefPtr<typename parser::ParsedExpression> const expr, JaktInternal::Optional<NonnullRefPtr<typename types::CheckedExpression>> const default_value);
ErrorOr<NonnullRefPtr<typename types::CheckedExpression>> infer_signed_int(i64 const val, utility::Span const span, JaktInternal::Optional<types::TypeId> const type_hint);
NonnullRefPtr<typename types::Type> get_type(types::TypeId const id) const;
ErrorOr<NonnullRefPtr<typename types::CheckedExpression>> typecheck_indexed_struct(NonnullRefPtr<typename parser::ParsedExpression> const expr, DeprecatedString const field_name, types::ScopeId const scope_id, bool const is_optional, types::SafetyMode const safety_mode, utility::Span const span);
ErrorOr<void> typecheck_function_predecl(parser::ParsedFunction const parsed_function, types::ScopeId const parent_scope_id, JaktInternal::Optional<types::TypeId> const this_arg_type_id, JaktInternal::Optional<NonnullRefPtr<types::FunctionGenerics>> generics);
ErrorOr<types::ModuleId> create_module(DeprecatedString const name, bool const is_root, JaktInternal::Optional<DeprecatedString> const path);
ErrorOr<void> set_owner_scope_if_needed(types::ScopeId const parent_scope_id, JaktInternal::DynamicArray<types::FunctionId> const overload_set);
ErrorOr<void> set_owner_scope_if_needed(types::ScopeId const parent_scope_id, types::VarId const var_id);
ErrorOr<void> typecheck_namespace_function_predecl(parser::ParsedNamespace const parsed_namespace, types::ScopeId const scope_id);
ErrorOr<void> typecheck_enum_constructor(parser::ParsedRecord const record, types::EnumId const enum_id, types::ScopeId const parent_scope_id);
ErrorOr<void> typecheck_enum(parser::ParsedRecord const record, types::EnumId const enum_id, types::ScopeId const parent_scope_id);
ErrorOr<JaktInternal::Optional<JaktInternal::DynamicArray<types::CheckedEnumVariantBinding>>> typecheck_enum_variant_bindings(types::CheckedEnumVariant const variant, JaktInternal::DynamicArray<parser::EnumVariantPatternArgument> const bindings, utility::Span const span);
ErrorOr<bool> implements_trait(types::TypeId const type_id, types::TraitId const trait_id, JaktInternal::Optional<JaktInternal::DynamicArray<types::TypeId>> const generic_arguments);
ErrorOr<JaktInternal::Optional<NonnullRefPtr<types::CheckedVariable>>> find_var_in_scope(types::ScopeId const scope_id, DeprecatedString const var) const;
ErrorOr<void> typecheck_struct(parser::ParsedRecord const record, types::StructId const struct_id, types::ScopeId const parent_scope_id);
ErrorOr<void> typecheck_struct_predecl_initial(parser::ParsedRecord const parsed_record, size_t const struct_index, size_t const module_struct_len, types::ScopeId const scope_id);
ErrorOr<void> fill_trait_requirements(JaktInternal::DynamicArray<parser::ParsedNameWithGenericParameters> const names, JaktInternal::DynamicArray<types::TraitId>& trait_requirements, JaktInternal::DynamicArray<types::TypeId>& trait_implementations, types::ScopeId const scope_id);
ErrorOr<DeprecatedString> debug_description() const;
};struct TraitImplementationDescriptor {
  public:
types::TraitId trait_id;DeprecatedString trait_name;JaktInternal::DynamicArray<types::TypeId> implemented_type_args;TraitImplementationDescriptor(types::TraitId a_trait_id, DeprecatedString a_trait_name, JaktInternal::DynamicArray<types::TypeId> a_implemented_type_args);

ErrorOr<DeprecatedString> debug_description() const;
};struct AlreadyImplementedFor {
  public:
DeprecatedString trait_name;utility::Span encounter_span;AlreadyImplementedFor(DeprecatedString a_trait_name, utility::Span a_encounter_span);

ErrorOr<DeprecatedString> debug_description() const;
};namespace FunctionMatchResult_Details {
struct MatchSuccess {
JaktInternal::DynamicArray<NonnullRefPtr<typename types::CheckedExpression>> args;
JaktInternal::Optional<types::TypeId> maybe_this_type_id;
JaktInternal::Dictionary<DeprecatedString,DeprecatedString> used_generic_inferences;
i64 specificity;
template<typename _MemberT0, typename _MemberT1, typename _MemberT2, typename _MemberT3>
MatchSuccess(_MemberT0&& member_0, _MemberT1&& member_1, _MemberT2&& member_2, _MemberT3&& member_3):
args{ forward<_MemberT0>(member_0)},
maybe_this_type_id{ forward<_MemberT1>(member_1)},
used_generic_inferences{ forward<_MemberT2>(member_2)},
specificity{ forward<_MemberT3>(member_3)}
{}
};
struct MatchError {
JaktInternal::DynamicArray<error::JaktError> errors;
template<typename _MemberT0>
MatchError(_MemberT0&& member_0):
errors{ forward<_MemberT0>(member_0)}
{}
};
}
struct FunctionMatchResult : public Variant<FunctionMatchResult_Details::MatchSuccess, FunctionMatchResult_Details::MatchError> {
using Variant<FunctionMatchResult_Details::MatchSuccess, FunctionMatchResult_Details::MatchError>::Variant;
    using MatchSuccess = FunctionMatchResult_Details::MatchSuccess;
    using MatchError = FunctionMatchResult_Details::MatchError;
ErrorOr<DeprecatedString> debug_description() const;
};
struct TraitImplCheck {
  public:
JaktInternal::Dictionary<DeprecatedString,JaktInternal::Dictionary<DeprecatedString,types::FunctionId>> missing_methods;JaktInternal::Dictionary<DeprecatedString,JaktInternal::Dictionary<DeprecatedString,utility::Span>> unmatched_signatures;JaktInternal::Dictionary<DeprecatedString,JaktInternal::Dictionary<DeprecatedString,utility::Span>> private_matching_methods;JaktInternal::Dictionary<DeprecatedString,typechecker::AlreadyImplementedFor> already_implemented_for;ErrorOr<void> ensure_capacity(size_t const count);
static ErrorOr<typechecker::TraitImplCheck> make();
TraitImplCheck(JaktInternal::Dictionary<DeprecatedString,JaktInternal::Dictionary<DeprecatedString,types::FunctionId>> a_missing_methods, JaktInternal::Dictionary<DeprecatedString,JaktInternal::Dictionary<DeprecatedString,utility::Span>> a_unmatched_signatures, JaktInternal::Dictionary<DeprecatedString,JaktInternal::Dictionary<DeprecatedString,utility::Span>> a_private_matching_methods, JaktInternal::Dictionary<DeprecatedString,typechecker::AlreadyImplementedFor> a_already_implemented_for);

ErrorOr<void> register_trait(types::TraitId const trait_id, DeprecatedString const trait_name, JaktInternal::Dictionary<DeprecatedString,types::FunctionId> const trait_methods);
ErrorOr<void> register_method(types::TypeId const self_type_id, DeprecatedString const method_name, types::FunctionId const method_id, typechecker::Typechecker& typechecker);
ErrorOr<void> throw_errors(utility::Span const record_decl_span, typechecker::Typechecker& typechecker);
ErrorOr<DeprecatedString> debug_description() const;
};struct ImportRestrictions {
  public:
bool functions;bool structs;bool enums;bool types;bool traits;bool namespaces;ImportRestrictions(bool a_functions, bool a_structs, bool a_enums, bool a_types, bool a_traits, bool a_namespaces);

static typechecker::ImportRestrictions all();
ErrorOr<DeprecatedString> debug_description() const;
};}
} // namespace Jakt
template<>struct Jakt::Formatter<Jakt::typechecker::Typechecker> : Jakt::Formatter<Jakt::StringView>{
Jakt::ErrorOr<void> format(Jakt::FormatBuilder& builder, Jakt::typechecker::Typechecker const& value) {
JaktInternal::PrettyPrint::ScopedEnable pretty_print_enable { m_alternative_form };Jakt::ErrorOr<void> format_error = Jakt::Formatter<Jakt::StringView>::format(builder, MUST(value.debug_description()));return format_error;}
};
namespace Jakt {
} // namespace Jakt
template<>struct Jakt::Formatter<Jakt::typechecker::TraitImplementationDescriptor> : Jakt::Formatter<Jakt::StringView>{
Jakt::ErrorOr<void> format(Jakt::FormatBuilder& builder, Jakt::typechecker::TraitImplementationDescriptor const& value) {
JaktInternal::PrettyPrint::ScopedEnable pretty_print_enable { m_alternative_form };Jakt::ErrorOr<void> format_error = Jakt::Formatter<Jakt::StringView>::format(builder, MUST(value.debug_description()));return format_error;}
};
namespace Jakt {
} // namespace Jakt
template<>struct Jakt::Formatter<Jakt::typechecker::AlreadyImplementedFor> : Jakt::Formatter<Jakt::StringView>{
Jakt::ErrorOr<void> format(Jakt::FormatBuilder& builder, Jakt::typechecker::AlreadyImplementedFor const& value) {
JaktInternal::PrettyPrint::ScopedEnable pretty_print_enable { m_alternative_form };Jakt::ErrorOr<void> format_error = Jakt::Formatter<Jakt::StringView>::format(builder, MUST(value.debug_description()));return format_error;}
};
namespace Jakt {
} // namespace Jakt
template<>struct Jakt::Formatter<Jakt::typechecker::FunctionMatchResult> : Jakt::Formatter<Jakt::StringView>{
Jakt::ErrorOr<void> format(Jakt::FormatBuilder& builder, Jakt::typechecker::FunctionMatchResult const& value) {
JaktInternal::PrettyPrint::ScopedEnable pretty_print_enable { m_alternative_form };Jakt::ErrorOr<void> format_error = Jakt::Formatter<Jakt::StringView>::format(builder, MUST(value.debug_description()));return format_error;}
};
namespace Jakt {
} // namespace Jakt
template<>struct Jakt::Formatter<Jakt::typechecker::TraitImplCheck> : Jakt::Formatter<Jakt::StringView>{
Jakt::ErrorOr<void> format(Jakt::FormatBuilder& builder, Jakt::typechecker::TraitImplCheck const& value) {
JaktInternal::PrettyPrint::ScopedEnable pretty_print_enable { m_alternative_form };Jakt::ErrorOr<void> format_error = Jakt::Formatter<Jakt::StringView>::format(builder, MUST(value.debug_description()));return format_error;}
};
namespace Jakt {
} // namespace Jakt
template<>struct Jakt::Formatter<Jakt::typechecker::ImportRestrictions> : Jakt::Formatter<Jakt::StringView>{
Jakt::ErrorOr<void> format(Jakt::FormatBuilder& builder, Jakt::typechecker::ImportRestrictions const& value) {
JaktInternal::PrettyPrint::ScopedEnable pretty_print_enable { m_alternative_form };Jakt::ErrorOr<void> format_error = Jakt::Formatter<Jakt::StringView>::format(builder, MUST(value.debug_description()));return format_error;}
};
namespace Jakt {
} // namespace Jakt
