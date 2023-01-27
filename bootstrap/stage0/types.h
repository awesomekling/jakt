#pragma once
#include "__unified_forward.h"
#include "parser.h"
#include "utility.h"
#include "compiler.h"
namespace Jakt {
namespace types {
struct ModuleId {
  public:
size_t id;ModuleId(size_t a_id);

bool equals(types::ModuleId const rhs) const;
ErrorOr<DeprecatedString> debug_description() const;
};struct StructId {
  public:
types::ModuleId module;size_t id;bool equals(types::StructId const rhs) const;
StructId(types::ModuleId a_module, size_t a_id);

ErrorOr<DeprecatedString> debug_description() const;
};struct VarId {
  public:
types::ModuleId module;size_t id;VarId(types::ModuleId a_module, size_t a_id);

ErrorOr<DeprecatedString> debug_description() const;
};struct FieldRecord {
  public:
types::StructId struct_id;types::VarId field_id;FieldRecord(types::StructId a_struct_id, types::VarId a_field_id);

ErrorOr<DeprecatedString> debug_description() const;
};struct TypeId {
  public:
types::ModuleId module;size_t id;ErrorOr<DeprecatedString> to_string() const;
static JaktInternal::Optional<types::TypeId> none();
bool equals(types::TypeId const rhs) const;
TypeId(types::ModuleId a_module, size_t a_id);

static ErrorOr<types::TypeId> from_string(DeprecatedString const type_id_string);
ErrorOr<DeprecatedString> debug_description() const;
};namespace CheckedTypeCast_Details {
struct Fallible{
types::TypeId value;
template<typename _MemberT0>
Fallible(_MemberT0&& member_0):
value{ forward<_MemberT0>(member_0)}
{}
};
struct Infallible{
types::TypeId value;
template<typename _MemberT0>
Infallible(_MemberT0&& member_0):
value{ forward<_MemberT0>(member_0)}
{}
};
}
struct CheckedTypeCast : public Variant<CheckedTypeCast_Details::Fallible, CheckedTypeCast_Details::Infallible> {
using Variant<CheckedTypeCast_Details::Fallible, CheckedTypeCast_Details::Infallible>::Variant;
    using Fallible = CheckedTypeCast_Details::Fallible;
    using Infallible = CheckedTypeCast_Details::Infallible;
ErrorOr<DeprecatedString> debug_description() const;
types::TypeId type_id() const;
};
struct EnumId {
  public:
types::ModuleId module;size_t id;bool equals(types::EnumId const rhs) const;
EnumId(types::ModuleId a_module, size_t a_id);

ErrorOr<DeprecatedString> debug_description() const;
};namespace CheckedEnumVariant_Details {
struct Untyped {
types::EnumId enum_id;
DeprecatedString name;
utility::Span span;
template<typename _MemberT0, typename _MemberT1, typename _MemberT2>
Untyped(_MemberT0&& member_0, _MemberT1&& member_1, _MemberT2&& member_2):
enum_id{ forward<_MemberT0>(member_0)},
name{ forward<_MemberT1>(member_1)},
span{ forward<_MemberT2>(member_2)}
{}
};
struct Typed {
types::EnumId enum_id;
DeprecatedString name;
types::TypeId type_id;
utility::Span span;
template<typename _MemberT0, typename _MemberT1, typename _MemberT2, typename _MemberT3>
Typed(_MemberT0&& member_0, _MemberT1&& member_1, _MemberT2&& member_2, _MemberT3&& member_3):
enum_id{ forward<_MemberT0>(member_0)},
name{ forward<_MemberT1>(member_1)},
type_id{ forward<_MemberT2>(member_2)},
span{ forward<_MemberT3>(member_3)}
{}
};
struct WithValue {
types::EnumId enum_id;
DeprecatedString name;
NonnullRefPtr<typename types::CheckedExpression> expr;
utility::Span span;
template<typename _MemberT0, typename _MemberT1, typename _MemberT2, typename _MemberT3>
WithValue(_MemberT0&& member_0, _MemberT1&& member_1, _MemberT2&& member_2, _MemberT3&& member_3):
enum_id{ forward<_MemberT0>(member_0)},
name{ forward<_MemberT1>(member_1)},
expr{ forward<_MemberT2>(member_2)},
span{ forward<_MemberT3>(member_3)}
{}
};
struct StructLike {
types::EnumId enum_id;
DeprecatedString name;
JaktInternal::DynamicArray<types::VarId> fields;
utility::Span span;
template<typename _MemberT0, typename _MemberT1, typename _MemberT2, typename _MemberT3>
StructLike(_MemberT0&& member_0, _MemberT1&& member_1, _MemberT2&& member_2, _MemberT3&& member_3):
enum_id{ forward<_MemberT0>(member_0)},
name{ forward<_MemberT1>(member_1)},
fields{ forward<_MemberT2>(member_2)},
span{ forward<_MemberT3>(member_3)}
{}
};
}
struct CheckedEnumVariant : public Variant<CheckedEnumVariant_Details::Untyped, CheckedEnumVariant_Details::Typed, CheckedEnumVariant_Details::WithValue, CheckedEnumVariant_Details::StructLike> {
using Variant<CheckedEnumVariant_Details::Untyped, CheckedEnumVariant_Details::Typed, CheckedEnumVariant_Details::WithValue, CheckedEnumVariant_Details::StructLike>::Variant;
    using Untyped = CheckedEnumVariant_Details::Untyped;
    using Typed = CheckedEnumVariant_Details::Typed;
    using WithValue = CheckedEnumVariant_Details::WithValue;
    using StructLike = CheckedEnumVariant_Details::StructLike;
ErrorOr<DeprecatedString> debug_description() const;
types::EnumId enum_id() const;
DeprecatedString name() const;
bool equals(types::CheckedEnumVariant const other) const;
utility::Span span() const;
};
namespace CheckedUnaryOperator_Details {
struct PreIncrement {
};
struct PostIncrement {
};
struct PreDecrement {
};
struct PostDecrement {
};
struct Negate {
};
struct Dereference {
};
struct RawAddress {
};
struct Reference {
};
struct MutableReference {
};
struct LogicalNot {
};
struct BitwiseNot {
};
struct TypeCast{
types::CheckedTypeCast value;
template<typename _MemberT0>
TypeCast(_MemberT0&& member_0):
value{ forward<_MemberT0>(member_0)}
{}
};
struct Is{
types::TypeId value;
template<typename _MemberT0>
Is(_MemberT0&& member_0):
value{ forward<_MemberT0>(member_0)}
{}
};
struct IsEnumVariant {
types::CheckedEnumVariant enum_variant;
JaktInternal::DynamicArray<types::CheckedEnumVariantBinding> bindings;
types::TypeId type_id;
template<typename _MemberT0, typename _MemberT1, typename _MemberT2>
IsEnumVariant(_MemberT0&& member_0, _MemberT1&& member_1, _MemberT2&& member_2):
enum_variant{ forward<_MemberT0>(member_0)},
bindings{ forward<_MemberT1>(member_1)},
type_id{ forward<_MemberT2>(member_2)}
{}
};
}
struct CheckedUnaryOperator : public Variant<CheckedUnaryOperator_Details::PreIncrement, CheckedUnaryOperator_Details::PostIncrement, CheckedUnaryOperator_Details::PreDecrement, CheckedUnaryOperator_Details::PostDecrement, CheckedUnaryOperator_Details::Negate, CheckedUnaryOperator_Details::Dereference, CheckedUnaryOperator_Details::RawAddress, CheckedUnaryOperator_Details::Reference, CheckedUnaryOperator_Details::MutableReference, CheckedUnaryOperator_Details::LogicalNot, CheckedUnaryOperator_Details::BitwiseNot, CheckedUnaryOperator_Details::TypeCast, CheckedUnaryOperator_Details::Is, CheckedUnaryOperator_Details::IsEnumVariant> {
using Variant<CheckedUnaryOperator_Details::PreIncrement, CheckedUnaryOperator_Details::PostIncrement, CheckedUnaryOperator_Details::PreDecrement, CheckedUnaryOperator_Details::PostDecrement, CheckedUnaryOperator_Details::Negate, CheckedUnaryOperator_Details::Dereference, CheckedUnaryOperator_Details::RawAddress, CheckedUnaryOperator_Details::Reference, CheckedUnaryOperator_Details::MutableReference, CheckedUnaryOperator_Details::LogicalNot, CheckedUnaryOperator_Details::BitwiseNot, CheckedUnaryOperator_Details::TypeCast, CheckedUnaryOperator_Details::Is, CheckedUnaryOperator_Details::IsEnumVariant>::Variant;
    using PreIncrement = CheckedUnaryOperator_Details::PreIncrement;
    using PostIncrement = CheckedUnaryOperator_Details::PostIncrement;
    using PreDecrement = CheckedUnaryOperator_Details::PreDecrement;
    using PostDecrement = CheckedUnaryOperator_Details::PostDecrement;
    using Negate = CheckedUnaryOperator_Details::Negate;
    using Dereference = CheckedUnaryOperator_Details::Dereference;
    using RawAddress = CheckedUnaryOperator_Details::RawAddress;
    using Reference = CheckedUnaryOperator_Details::Reference;
    using MutableReference = CheckedUnaryOperator_Details::MutableReference;
    using LogicalNot = CheckedUnaryOperator_Details::LogicalNot;
    using BitwiseNot = CheckedUnaryOperator_Details::BitwiseNot;
    using TypeCast = CheckedUnaryOperator_Details::TypeCast;
    using Is = CheckedUnaryOperator_Details::Is;
    using IsEnumVariant = CheckedUnaryOperator_Details::IsEnumVariant;
ErrorOr<DeprecatedString> debug_description() const;
};
namespace BlockControlFlow_Details {
struct AlwaysReturns {
};
struct AlwaysTransfersControl {
bool might_break;
template<typename _MemberT0>
AlwaysTransfersControl(_MemberT0&& member_0):
might_break{ forward<_MemberT0>(member_0)}
{}
};
struct NeverReturns {
};
struct MayReturn {
};
struct PartialAlwaysReturns {
bool might_break;
template<typename _MemberT0>
PartialAlwaysReturns(_MemberT0&& member_0):
might_break{ forward<_MemberT0>(member_0)}
{}
};
struct PartialAlwaysTransfersControl {
bool might_break;
template<typename _MemberT0>
PartialAlwaysTransfersControl(_MemberT0&& member_0):
might_break{ forward<_MemberT0>(member_0)}
{}
};
struct PartialNeverReturns {
bool might_break;
template<typename _MemberT0>
PartialNeverReturns(_MemberT0&& member_0):
might_break{ forward<_MemberT0>(member_0)}
{}
};
}
struct BlockControlFlow : public Variant<BlockControlFlow_Details::AlwaysReturns, BlockControlFlow_Details::AlwaysTransfersControl, BlockControlFlow_Details::NeverReturns, BlockControlFlow_Details::MayReturn, BlockControlFlow_Details::PartialAlwaysReturns, BlockControlFlow_Details::PartialAlwaysTransfersControl, BlockControlFlow_Details::PartialNeverReturns> {
using Variant<BlockControlFlow_Details::AlwaysReturns, BlockControlFlow_Details::AlwaysTransfersControl, BlockControlFlow_Details::NeverReturns, BlockControlFlow_Details::MayReturn, BlockControlFlow_Details::PartialAlwaysReturns, BlockControlFlow_Details::PartialAlwaysTransfersControl, BlockControlFlow_Details::PartialNeverReturns>::Variant;
    using AlwaysReturns = BlockControlFlow_Details::AlwaysReturns;
    using AlwaysTransfersControl = BlockControlFlow_Details::AlwaysTransfersControl;
    using NeverReturns = BlockControlFlow_Details::NeverReturns;
    using MayReturn = BlockControlFlow_Details::MayReturn;
    using PartialAlwaysReturns = BlockControlFlow_Details::PartialAlwaysReturns;
    using PartialAlwaysTransfersControl = BlockControlFlow_Details::PartialAlwaysTransfersControl;
    using PartialNeverReturns = BlockControlFlow_Details::PartialNeverReturns;
ErrorOr<DeprecatedString> debug_description() const;
bool always_transfers_control() const;
types::BlockControlFlow partial() const;
bool always_returns() const;
types::BlockControlFlow updated(types::BlockControlFlow const second) const;
bool may_break() const;
bool is_reachable() const;
bool never_returns() const;
types::BlockControlFlow definitive() const;
bool may_return() const;
types::BlockControlFlow branch_unify_with(types::BlockControlFlow const second) const;
types::BlockControlFlow unify_with(types::BlockControlFlow const second) const;
};
struct ResolvedNamespace {
  public:
DeprecatedString name;JaktInternal::Optional<DeprecatedString> external_name;JaktInternal::Optional<JaktInternal::DynamicArray<types::TypeId>> generic_parameters;ResolvedNamespace(DeprecatedString a_name, JaktInternal::Optional<DeprecatedString> a_external_name, JaktInternal::Optional<JaktInternal::DynamicArray<types::TypeId>> a_generic_parameters);

ErrorOr<DeprecatedString> debug_description() const;
};namespace NumberConstant_Details {
struct Signed{
i64 value;
template<typename _MemberT0>
Signed(_MemberT0&& member_0):
value{ forward<_MemberT0>(member_0)}
{}
};
struct Unsigned{
u64 value;
template<typename _MemberT0>
Unsigned(_MemberT0&& member_0):
value{ forward<_MemberT0>(member_0)}
{}
};
struct Floating{
f64 value;
template<typename _MemberT0>
Floating(_MemberT0&& member_0):
value{ forward<_MemberT0>(member_0)}
{}
};
}
struct NumberConstant : public Variant<NumberConstant_Details::Signed, NumberConstant_Details::Unsigned, NumberConstant_Details::Floating> {
using Variant<NumberConstant_Details::Signed, NumberConstant_Details::Unsigned, NumberConstant_Details::Floating>::Variant;
    using Signed = NumberConstant_Details::Signed;
    using Unsigned = NumberConstant_Details::Unsigned;
    using Floating = NumberConstant_Details::Floating;
ErrorOr<DeprecatedString> debug_description() const;
size_t to_usize() const;
bool can_fit_number(types::TypeId const type_id, NonnullRefPtr<types::CheckedProgram> const program) const;
};
struct ScopeId {
  public:
types::ModuleId module_id;size_t id;ErrorOr<DeprecatedString> to_string() const;
bool equals(types::ScopeId const other) const;
ScopeId(types::ModuleId a_module_id, size_t a_id);

ErrorOr<DeprecatedString> debug_description() const;
};struct CheckedNamespace {
  public:
DeprecatedString name;types::ScopeId scope;CheckedNamespace(DeprecatedString a_name, types::ScopeId a_scope);

ErrorOr<DeprecatedString> debug_description() const;
};struct CheckedStruct {
  public:
DeprecatedString name;utility::Span name_span;JaktInternal::DynamicArray<types::CheckedGenericParameter> generic_parameters;JaktInternal::DynamicArray<types::CheckedField> fields;types::ScopeId scope_id;parser::DefinitionLinkage definition_linkage;JaktInternal::Dictionary<DeprecatedString,JaktInternal::Tuple<types::TraitId,JaktInternal::DynamicArray<types::TypeId>>> trait_implementations;parser::RecordType record_type;types::TypeId type_id;JaktInternal::Optional<types::StructId> super_struct_id;JaktInternal::Optional<DeprecatedString> external_name;CheckedStruct(DeprecatedString a_name, utility::Span a_name_span, JaktInternal::DynamicArray<types::CheckedGenericParameter> a_generic_parameters, JaktInternal::DynamicArray<types::CheckedField> a_fields, types::ScopeId a_scope_id, parser::DefinitionLinkage a_definition_linkage, JaktInternal::Dictionary<DeprecatedString,JaktInternal::Tuple<types::TraitId,JaktInternal::DynamicArray<types::TypeId>>> a_trait_implementations, parser::RecordType a_record_type, types::TypeId a_type_id, JaktInternal::Optional<types::StructId> a_super_struct_id, JaktInternal::Optional<DeprecatedString> a_external_name);

DeprecatedString name_for_codegen() const;
ErrorOr<DeprecatedString> debug_description() const;
};namespace FunctionGenericParameterKind_Details {
struct InferenceGuide {
};
struct Parameter {
};
}
struct FunctionGenericParameterKind : public Variant<FunctionGenericParameterKind_Details::InferenceGuide, FunctionGenericParameterKind_Details::Parameter> {
using Variant<FunctionGenericParameterKind_Details::InferenceGuide, FunctionGenericParameterKind_Details::Parameter>::Variant;
    using InferenceGuide = FunctionGenericParameterKind_Details::InferenceGuide;
    using Parameter = FunctionGenericParameterKind_Details::Parameter;
ErrorOr<DeprecatedString> debug_description() const;
};
namespace MaybeResolvedScope_Details {
struct Resolved{
types::ScopeId value;
template<typename _MemberT0>
Resolved(_MemberT0&& member_0):
value{ forward<_MemberT0>(member_0)}
{}
};
struct Unresolved {
NonnullRefPtr<typename types::MaybeResolvedScope> parent_scope;
DeprecatedString relative_name;
template<typename _MemberT0, typename _MemberT1>
Unresolved(_MemberT0&& member_0, _MemberT1&& member_1):
parent_scope{ forward<_MemberT0>(member_0)},
relative_name{ forward<_MemberT1>(member_1)}
{}
};
}
struct MaybeResolvedScope : public Variant<MaybeResolvedScope_Details::Resolved, MaybeResolvedScope_Details::Unresolved>, public RefCounted<MaybeResolvedScope> {
using Variant<MaybeResolvedScope_Details::Resolved, MaybeResolvedScope_Details::Unresolved>::Variant;
    using Resolved = MaybeResolvedScope_Details::Resolved;
    using Unresolved = MaybeResolvedScope_Details::Unresolved;
template<typename V, typename... Args> static auto create(Args&&... args) {
return adopt_nonnull_ref_or_enomem(new (nothrow) MaybeResolvedScope(V(forward<Args>(args)...)));
}
ErrorOr<DeprecatedString> debug_description() const;
ErrorOr<NonnullRefPtr<typename types::MaybeResolvedScope>> try_resolve(NonnullRefPtr<types::CheckedProgram> const program) const;
};
struct CheckedEnumVariantBinding {
  public:
JaktInternal::Optional<DeprecatedString> name;DeprecatedString binding;types::TypeId type_id;utility::Span span;CheckedEnumVariantBinding(JaktInternal::Optional<DeprecatedString> a_name, DeprecatedString a_binding, types::TypeId a_type_id, utility::Span a_span);

ErrorOr<DeprecatedString> debug_description() const;
};struct CheckedBlock {
  public:
JaktInternal::DynamicArray<NonnullRefPtr<typename types::CheckedStatement>> statements;types::ScopeId scope_id;types::BlockControlFlow control_flow;JaktInternal::Optional<types::TypeId> yielded_type;bool yielded_none;CheckedBlock(JaktInternal::DynamicArray<NonnullRefPtr<typename types::CheckedStatement>> a_statements, types::ScopeId a_scope_id, types::BlockControlFlow a_control_flow, JaktInternal::Optional<types::TypeId> a_yielded_type, bool a_yielded_none);

ErrorOr<DeprecatedString> debug_description() const;
};namespace CheckedVisibility_Details {
struct Public {
};
struct Private {
};
struct Restricted {
JaktInternal::DynamicArray<NonnullRefPtr<typename types::MaybeResolvedScope>> scopes;
utility::Span span;
template<typename _MemberT0, typename _MemberT1>
Restricted(_MemberT0&& member_0, _MemberT1&& member_1):
scopes{ forward<_MemberT0>(member_0)},
span{ forward<_MemberT1>(member_1)}
{}
};
}
struct CheckedVisibility : public Variant<CheckedVisibility_Details::Public, CheckedVisibility_Details::Private, CheckedVisibility_Details::Restricted> {
using Variant<CheckedVisibility_Details::Public, CheckedVisibility_Details::Private, CheckedVisibility_Details::Restricted>::Variant;
    using Public = CheckedVisibility_Details::Public;
    using Private = CheckedVisibility_Details::Private;
    using Restricted = CheckedVisibility_Details::Restricted;
ErrorOr<DeprecatedString> debug_description() const;
};
class CheckedVariable : public RefCounted<CheckedVariable>, public Weakable<CheckedVariable> {
  public:
virtual ~CheckedVariable() = default;
DeprecatedString name;types::TypeId type_id;bool is_mutable;utility::Span definition_span;JaktInternal::Optional<utility::Span> type_span;types::CheckedVisibility visibility;JaktInternal::Optional<types::ScopeId> owner_scope;ErrorOr<NonnullRefPtr<types::CheckedVariable>> map_types(Function<ErrorOr<types::TypeId>(types::TypeId)> const& map) const;
protected:
explicit CheckedVariable(DeprecatedString&& a_name, types::TypeId&& a_type_id, bool&& a_is_mutable, utility::Span&& a_definition_span, JaktInternal::Optional<utility::Span>&& a_type_span, types::CheckedVisibility&& a_visibility, JaktInternal::Optional<types::ScopeId>&& a_owner_scope);
public:
static ErrorOr<NonnullRefPtr<CheckedVariable>> create(DeprecatedString name, types::TypeId type_id, bool is_mutable, utility::Span definition_span, JaktInternal::Optional<utility::Span> type_span, types::CheckedVisibility visibility, JaktInternal::Optional<types::ScopeId> owner_scope);

ErrorOr<DeprecatedString> debug_description() const;
};struct CheckedParameter {
  public:
bool requires_label;NonnullRefPtr<types::CheckedVariable> variable;JaktInternal::Optional<NonnullRefPtr<typename types::CheckedExpression>> default_value;ErrorOr<types::CheckedParameter> map_types(Function<ErrorOr<types::TypeId>(types::TypeId)> const& map) const;
CheckedParameter(bool a_requires_label, NonnullRefPtr<types::CheckedVariable> a_variable, JaktInternal::Optional<NonnullRefPtr<typename types::CheckedExpression>> a_default_value);

ErrorOr<DeprecatedString> debug_description() const;
};struct FunctionId {
  public:
types::ModuleId module;size_t id;bool equals(types::FunctionId const rhs) const;
FunctionId(types::ModuleId a_module, size_t a_id);

ErrorOr<DeprecatedString> debug_description() const;
};struct Value {
  public:
NonnullRefPtr<typename types::ValueImpl> impl;utility::Span span;ErrorOr<types::Value> copy() const;
Value(NonnullRefPtr<typename types::ValueImpl> a_impl, utility::Span a_span);

ErrorOr<types::Value> cast(types::Value const expected, utility::Span const span) const;
DeprecatedString type_name() const;
ErrorOr<DeprecatedString> debug_description() const;
};namespace ValueImpl_Details {
struct Void {
};
struct Bool{
bool value;
template<typename _MemberT0>
Bool(_MemberT0&& member_0):
value{ forward<_MemberT0>(member_0)}
{}
};
struct U8{
u8 value;
template<typename _MemberT0>
U8(_MemberT0&& member_0):
value{ forward<_MemberT0>(member_0)}
{}
};
struct U16{
u16 value;
template<typename _MemberT0>
U16(_MemberT0&& member_0):
value{ forward<_MemberT0>(member_0)}
{}
};
struct U32{
u32 value;
template<typename _MemberT0>
U32(_MemberT0&& member_0):
value{ forward<_MemberT0>(member_0)}
{}
};
struct U64{
u64 value;
template<typename _MemberT0>
U64(_MemberT0&& member_0):
value{ forward<_MemberT0>(member_0)}
{}
};
struct I8{
i8 value;
template<typename _MemberT0>
I8(_MemberT0&& member_0):
value{ forward<_MemberT0>(member_0)}
{}
};
struct I16{
i16 value;
template<typename _MemberT0>
I16(_MemberT0&& member_0):
value{ forward<_MemberT0>(member_0)}
{}
};
struct I32{
i32 value;
template<typename _MemberT0>
I32(_MemberT0&& member_0):
value{ forward<_MemberT0>(member_0)}
{}
};
struct I64{
i64 value;
template<typename _MemberT0>
I64(_MemberT0&& member_0):
value{ forward<_MemberT0>(member_0)}
{}
};
struct F32{
f32 value;
template<typename _MemberT0>
F32(_MemberT0&& member_0):
value{ forward<_MemberT0>(member_0)}
{}
};
struct F64{
f64 value;
template<typename _MemberT0>
F64(_MemberT0&& member_0):
value{ forward<_MemberT0>(member_0)}
{}
};
struct USize{
size_t value;
template<typename _MemberT0>
USize(_MemberT0&& member_0):
value{ forward<_MemberT0>(member_0)}
{}
};
struct JaktString{
DeprecatedString value;
template<typename _MemberT0>
JaktString(_MemberT0&& member_0):
value{ forward<_MemberT0>(member_0)}
{}
};
struct StringView{
DeprecatedString value;
template<typename _MemberT0>
StringView(_MemberT0&& member_0):
value{ forward<_MemberT0>(member_0)}
{}
};
struct CChar{
char value;
template<typename _MemberT0>
CChar(_MemberT0&& member_0):
value{ forward<_MemberT0>(member_0)}
{}
};
struct CInt{
int value;
template<typename _MemberT0>
CInt(_MemberT0&& member_0):
value{ forward<_MemberT0>(member_0)}
{}
};
struct Struct {
JaktInternal::DynamicArray<types::Value> fields;
types::StructId struct_id;
JaktInternal::Optional<types::FunctionId> constructor;
template<typename _MemberT0, typename _MemberT1, typename _MemberT2>
Struct(_MemberT0&& member_0, _MemberT1&& member_1, _MemberT2&& member_2):
fields{ forward<_MemberT0>(member_0)},
struct_id{ forward<_MemberT1>(member_1)},
constructor{ forward<_MemberT2>(member_2)}
{}
};
struct Class {
JaktInternal::DynamicArray<types::Value> fields;
types::StructId struct_id;
JaktInternal::Optional<types::FunctionId> constructor;
template<typename _MemberT0, typename _MemberT1, typename _MemberT2>
Class(_MemberT0&& member_0, _MemberT1&& member_1, _MemberT2&& member_2):
fields{ forward<_MemberT0>(member_0)},
struct_id{ forward<_MemberT1>(member_1)},
constructor{ forward<_MemberT2>(member_2)}
{}
};
struct Enum {
JaktInternal::DynamicArray<types::Value> fields;
types::EnumId enum_id;
types::FunctionId constructor;
template<typename _MemberT0, typename _MemberT1, typename _MemberT2>
Enum(_MemberT0&& member_0, _MemberT1&& member_1, _MemberT2&& member_2):
fields{ forward<_MemberT0>(member_0)},
enum_id{ forward<_MemberT1>(member_1)},
constructor{ forward<_MemberT2>(member_2)}
{}
};
struct JaktArray {
JaktInternal::DynamicArray<types::Value> values;
types::TypeId type_id;
template<typename _MemberT0, typename _MemberT1>
JaktArray(_MemberT0&& member_0, _MemberT1&& member_1):
values{ forward<_MemberT0>(member_0)},
type_id{ forward<_MemberT1>(member_1)}
{}
};
struct JaktDictionary {
JaktInternal::DynamicArray<types::Value> keys;
JaktInternal::DynamicArray<types::Value> values;
types::TypeId type_id;
template<typename _MemberT0, typename _MemberT1, typename _MemberT2>
JaktDictionary(_MemberT0&& member_0, _MemberT1&& member_1, _MemberT2&& member_2):
keys{ forward<_MemberT0>(member_0)},
values{ forward<_MemberT1>(member_1)},
type_id{ forward<_MemberT2>(member_2)}
{}
};
struct JaktSet {
JaktInternal::DynamicArray<types::Value> values;
types::TypeId type_id;
template<typename _MemberT0, typename _MemberT1>
JaktSet(_MemberT0&& member_0, _MemberT1&& member_1):
values{ forward<_MemberT0>(member_0)},
type_id{ forward<_MemberT1>(member_1)}
{}
};
struct RawPtr{
NonnullRefPtr<typename types::ValueImpl> value;
template<typename _MemberT0>
RawPtr(_MemberT0&& member_0):
value{ forward<_MemberT0>(member_0)}
{}
};
struct OptionalSome {
types::Value value;
template<typename _MemberT0>
OptionalSome(_MemberT0&& member_0):
value{ forward<_MemberT0>(member_0)}
{}
};
struct OptionalNone {
};
struct JaktTuple {
JaktInternal::DynamicArray<types::Value> fields;
types::TypeId type_id;
template<typename _MemberT0, typename _MemberT1>
JaktTuple(_MemberT0&& member_0, _MemberT1&& member_1):
fields{ forward<_MemberT0>(member_0)},
type_id{ forward<_MemberT1>(member_1)}
{}
};
struct Function {
JaktInternal::Dictionary<DeprecatedString,types::Value> captures;
JaktInternal::Dictionary<DeprecatedString,JaktInternal::Tuple<types::TypeId,JaktInternal::Optional<NonnullRefPtr<typename types::CheckedExpression>>>> params;
types::TypeId return_type_id;
types::TypeId type_id;
types::CheckedBlock block;
bool can_throw;
JaktInternal::DynamicArray<types::CheckedParameter> checked_params;
template<typename _MemberT0, typename _MemberT1, typename _MemberT2, typename _MemberT3, typename _MemberT4, typename _MemberT5, typename _MemberT6>
Function(_MemberT0&& member_0, _MemberT1&& member_1, _MemberT2&& member_2, _MemberT3&& member_3, _MemberT4&& member_4, _MemberT5&& member_5, _MemberT6&& member_6):
captures{ forward<_MemberT0>(member_0)},
params{ forward<_MemberT1>(member_1)},
return_type_id{ forward<_MemberT2>(member_2)},
type_id{ forward<_MemberT3>(member_3)},
block{ forward<_MemberT4>(member_4)},
can_throw{ forward<_MemberT5>(member_5)},
checked_params{ forward<_MemberT6>(member_6)}
{}
};
}
struct ValueImpl : public Variant<ValueImpl_Details::Void, ValueImpl_Details::Bool, ValueImpl_Details::U8, ValueImpl_Details::U16, ValueImpl_Details::U32, ValueImpl_Details::U64, ValueImpl_Details::I8, ValueImpl_Details::I16, ValueImpl_Details::I32, ValueImpl_Details::I64, ValueImpl_Details::F32, ValueImpl_Details::F64, ValueImpl_Details::USize, ValueImpl_Details::JaktString, ValueImpl_Details::StringView, ValueImpl_Details::CChar, ValueImpl_Details::CInt, ValueImpl_Details::Struct, ValueImpl_Details::Class, ValueImpl_Details::Enum, ValueImpl_Details::JaktArray, ValueImpl_Details::JaktDictionary, ValueImpl_Details::JaktSet, ValueImpl_Details::RawPtr, ValueImpl_Details::OptionalSome, ValueImpl_Details::OptionalNone, ValueImpl_Details::JaktTuple, ValueImpl_Details::Function>, public RefCounted<ValueImpl> {
using Variant<ValueImpl_Details::Void, ValueImpl_Details::Bool, ValueImpl_Details::U8, ValueImpl_Details::U16, ValueImpl_Details::U32, ValueImpl_Details::U64, ValueImpl_Details::I8, ValueImpl_Details::I16, ValueImpl_Details::I32, ValueImpl_Details::I64, ValueImpl_Details::F32, ValueImpl_Details::F64, ValueImpl_Details::USize, ValueImpl_Details::JaktString, ValueImpl_Details::StringView, ValueImpl_Details::CChar, ValueImpl_Details::CInt, ValueImpl_Details::Struct, ValueImpl_Details::Class, ValueImpl_Details::Enum, ValueImpl_Details::JaktArray, ValueImpl_Details::JaktDictionary, ValueImpl_Details::JaktSet, ValueImpl_Details::RawPtr, ValueImpl_Details::OptionalSome, ValueImpl_Details::OptionalNone, ValueImpl_Details::JaktTuple, ValueImpl_Details::Function>::Variant;
    using Void = ValueImpl_Details::Void;
    using Bool = ValueImpl_Details::Bool;
    using U8 = ValueImpl_Details::U8;
    using U16 = ValueImpl_Details::U16;
    using U32 = ValueImpl_Details::U32;
    using U64 = ValueImpl_Details::U64;
    using I8 = ValueImpl_Details::I8;
    using I16 = ValueImpl_Details::I16;
    using I32 = ValueImpl_Details::I32;
    using I64 = ValueImpl_Details::I64;
    using F32 = ValueImpl_Details::F32;
    using F64 = ValueImpl_Details::F64;
    using USize = ValueImpl_Details::USize;
    using JaktString = ValueImpl_Details::JaktString;
    using StringView = ValueImpl_Details::StringView;
    using CChar = ValueImpl_Details::CChar;
    using CInt = ValueImpl_Details::CInt;
    using Struct = ValueImpl_Details::Struct;
    using Class = ValueImpl_Details::Class;
    using Enum = ValueImpl_Details::Enum;
    using JaktArray = ValueImpl_Details::JaktArray;
    using JaktDictionary = ValueImpl_Details::JaktDictionary;
    using JaktSet = ValueImpl_Details::JaktSet;
    using RawPtr = ValueImpl_Details::RawPtr;
    using OptionalSome = ValueImpl_Details::OptionalSome;
    using OptionalNone = ValueImpl_Details::OptionalNone;
    using JaktTuple = ValueImpl_Details::JaktTuple;
    using Function = ValueImpl_Details::Function;
template<typename V, typename... Args> static auto create(Args&&... args) {
return adopt_nonnull_ref_or_enomem(new (nothrow) ValueImpl(V(forward<Args>(args)...)));
}
ErrorOr<DeprecatedString> debug_description() const;
bool equals(NonnullRefPtr<typename types::ValueImpl> const other) const;
ErrorOr<NonnullRefPtr<typename types::ValueImpl>> copy() const;
};
class CheckedFunction : public RefCounted<CheckedFunction>, public Weakable<CheckedFunction> {
  public:
virtual ~CheckedFunction() = default;
DeprecatedString name;utility::Span name_span;types::CheckedVisibility visibility;types::TypeId return_type_id;JaktInternal::Optional<utility::Span> return_type_span;JaktInternal::DynamicArray<types::CheckedParameter> params;NonnullRefPtr<types::FunctionGenerics> generics;types::CheckedBlock block;bool can_throw;parser::FunctionType type;parser::FunctionLinkage linkage;types::ScopeId function_scope_id;JaktInternal::Optional<types::StructId> struct_id;bool is_instantiated;JaktInternal::Optional<parser::ParsedFunction> parsed_function;bool is_comptime;bool is_virtual;bool is_override;JaktInternal::Optional<types::ScopeId> owner_scope;JaktInternal::Optional<DeprecatedString> external_name;JaktInternal::Optional<DeprecatedString> deprecated_message;ErrorOr<bool> signature_matches(NonnullRefPtr<types::CheckedFunction> const other) const;
bool is_static() const;
protected:
explicit CheckedFunction(DeprecatedString&& a_name, utility::Span&& a_name_span, types::CheckedVisibility&& a_visibility, types::TypeId&& a_return_type_id, JaktInternal::Optional<utility::Span>&& a_return_type_span, JaktInternal::DynamicArray<types::CheckedParameter>&& a_params, NonnullRefPtr<types::FunctionGenerics>&& a_generics, types::CheckedBlock&& a_block, bool&& a_can_throw, parser::FunctionType&& a_type, parser::FunctionLinkage&& a_linkage, types::ScopeId&& a_function_scope_id, JaktInternal::Optional<types::StructId>&& a_struct_id, bool&& a_is_instantiated, JaktInternal::Optional<parser::ParsedFunction>&& a_parsed_function, bool&& a_is_comptime, bool&& a_is_virtual, bool&& a_is_override, JaktInternal::Optional<types::ScopeId>&& a_owner_scope, JaktInternal::Optional<DeprecatedString>&& a_external_name, JaktInternal::Optional<DeprecatedString>&& a_deprecated_message);
public:
static ErrorOr<NonnullRefPtr<CheckedFunction>> create(DeprecatedString name, utility::Span name_span, types::CheckedVisibility visibility, types::TypeId return_type_id, JaktInternal::Optional<utility::Span> return_type_span, JaktInternal::DynamicArray<types::CheckedParameter> params, NonnullRefPtr<types::FunctionGenerics> generics, types::CheckedBlock block, bool can_throw, parser::FunctionType type, parser::FunctionLinkage linkage, types::ScopeId function_scope_id, JaktInternal::Optional<types::StructId> struct_id, bool is_instantiated, JaktInternal::Optional<parser::ParsedFunction> parsed_function, bool is_comptime, bool is_virtual, bool is_override, JaktInternal::Optional<types::ScopeId> owner_scope, JaktInternal::Optional<DeprecatedString> external_name, JaktInternal::Optional<DeprecatedString> deprecated_message);

parser::ParsedFunction to_parsed_function() const;
bool is_specialized_for_types(JaktInternal::DynamicArray<types::TypeId> const types) const;
ErrorOr<NonnullRefPtr<types::CheckedFunction>> copy() const;
ErrorOr<void> add_param(types::CheckedParameter const checked_param);
ErrorOr<void> map_types(Function<ErrorOr<types::TypeId>(types::TypeId)> const& map);
bool is_mutating() const;
DeprecatedString name_for_codegen() const;
ErrorOr<void> set_params(JaktInternal::DynamicArray<types::CheckedParameter> const checked_params);
ErrorOr<DeprecatedString> debug_description() const;
};class Module : public RefCounted<Module>, public Weakable<Module> {
  public:
virtual ~Module() = default;
types::ModuleId id;DeprecatedString name;JaktInternal::DynamicArray<NonnullRefPtr<types::CheckedFunction>> functions;JaktInternal::DynamicArray<types::CheckedStruct> structures;JaktInternal::DynamicArray<types::CheckedEnum> enums;JaktInternal::DynamicArray<NonnullRefPtr<types::Scope>> scopes;JaktInternal::DynamicArray<NonnullRefPtr<typename types::Type>> types;JaktInternal::DynamicArray<NonnullRefPtr<types::CheckedTrait>> traits;JaktInternal::DynamicArray<NonnullRefPtr<types::CheckedVariable>> variables;JaktInternal::DynamicArray<types::ModuleId> imports;DeprecatedString resolved_import_path;bool is_root;protected:
explicit Module(types::ModuleId&& a_id, DeprecatedString&& a_name, JaktInternal::DynamicArray<NonnullRefPtr<types::CheckedFunction>>&& a_functions, JaktInternal::DynamicArray<types::CheckedStruct>&& a_structures, JaktInternal::DynamicArray<types::CheckedEnum>&& a_enums, JaktInternal::DynamicArray<NonnullRefPtr<types::Scope>>&& a_scopes, JaktInternal::DynamicArray<NonnullRefPtr<typename types::Type>>&& a_types, JaktInternal::DynamicArray<NonnullRefPtr<types::CheckedTrait>>&& a_traits, JaktInternal::DynamicArray<NonnullRefPtr<types::CheckedVariable>>&& a_variables, JaktInternal::DynamicArray<types::ModuleId>&& a_imports, DeprecatedString&& a_resolved_import_path, bool&& a_is_root);
public:
static ErrorOr<NonnullRefPtr<Module>> create(types::ModuleId id, DeprecatedString name, JaktInternal::DynamicArray<NonnullRefPtr<types::CheckedFunction>> functions, JaktInternal::DynamicArray<types::CheckedStruct> structures, JaktInternal::DynamicArray<types::CheckedEnum> enums, JaktInternal::DynamicArray<NonnullRefPtr<types::Scope>> scopes, JaktInternal::DynamicArray<NonnullRefPtr<typename types::Type>> types, JaktInternal::DynamicArray<NonnullRefPtr<types::CheckedTrait>> traits, JaktInternal::DynamicArray<NonnullRefPtr<types::CheckedVariable>> variables, JaktInternal::DynamicArray<types::ModuleId> imports, DeprecatedString resolved_import_path, bool is_root);

ErrorOr<types::TypeId> new_type_variable(JaktInternal::Optional<JaktInternal::DynamicArray<types::TypeId>> const implemented_traits);
ErrorOr<types::FunctionId> add_function(NonnullRefPtr<types::CheckedFunction> const checked_function);
bool is_prelude() const;
ErrorOr<types::VarId> add_variable(NonnullRefPtr<types::CheckedVariable> const checked_variable);
types::FunctionId next_function_id() const;
ErrorOr<DeprecatedString> debug_description() const;
};namespace StringLiteral_Details {
struct Static{
DeprecatedString value;
template<typename _MemberT0>
Static(_MemberT0&& member_0):
value{ forward<_MemberT0>(member_0)}
{}
};
}
struct StringLiteral : public Variant<StringLiteral_Details::Static> {
using Variant<StringLiteral_Details::Static>::Variant;
    using Static = StringLiteral_Details::Static;
ErrorOr<DeprecatedString> debug_description() const;
DeprecatedString to_string() const;
};
namespace CheckedMatchBody_Details {
struct Expression{
NonnullRefPtr<typename types::CheckedExpression> value;
template<typename _MemberT0>
Expression(_MemberT0&& member_0):
value{ forward<_MemberT0>(member_0)}
{}
};
struct Block{
types::CheckedBlock value;
template<typename _MemberT0>
Block(_MemberT0&& member_0):
value{ forward<_MemberT0>(member_0)}
{}
};
}
struct CheckedMatchBody : public Variant<CheckedMatchBody_Details::Expression, CheckedMatchBody_Details::Block> {
using Variant<CheckedMatchBody_Details::Expression, CheckedMatchBody_Details::Block>::Variant;
    using Expression = CheckedMatchBody_Details::Expression;
    using Block = CheckedMatchBody_Details::Block;
ErrorOr<DeprecatedString> debug_description() const;
};
namespace CheckedMatchCase_Details {
struct EnumVariant {
JaktInternal::DynamicArray<NonnullRefPtr<typename types::CheckedStatement>> defaults;
DeprecatedString name;
JaktInternal::DynamicArray<parser::EnumVariantPatternArgument> args;
types::TypeId subject_type_id;
size_t index;
types::ScopeId scope_id;
types::CheckedMatchBody body;
utility::Span marker_span;
template<typename _MemberT0, typename _MemberT1, typename _MemberT2, typename _MemberT3, typename _MemberT4, typename _MemberT5, typename _MemberT6, typename _MemberT7>
EnumVariant(_MemberT0&& member_0, _MemberT1&& member_1, _MemberT2&& member_2, _MemberT3&& member_3, _MemberT4&& member_4, _MemberT5&& member_5, _MemberT6&& member_6, _MemberT7&& member_7):
defaults{ forward<_MemberT0>(member_0)},
name{ forward<_MemberT1>(member_1)},
args{ forward<_MemberT2>(member_2)},
subject_type_id{ forward<_MemberT3>(member_3)},
index{ forward<_MemberT4>(member_4)},
scope_id{ forward<_MemberT5>(member_5)},
body{ forward<_MemberT6>(member_6)},
marker_span{ forward<_MemberT7>(member_7)}
{}
};
struct Expression {
JaktInternal::DynamicArray<NonnullRefPtr<typename types::CheckedStatement>> defaults;
NonnullRefPtr<typename types::CheckedExpression> expression;
types::CheckedMatchBody body;
utility::Span marker_span;
template<typename _MemberT0, typename _MemberT1, typename _MemberT2, typename _MemberT3>
Expression(_MemberT0&& member_0, _MemberT1&& member_1, _MemberT2&& member_2, _MemberT3&& member_3):
defaults{ forward<_MemberT0>(member_0)},
expression{ forward<_MemberT1>(member_1)},
body{ forward<_MemberT2>(member_2)},
marker_span{ forward<_MemberT3>(member_3)}
{}
};
struct CatchAll {
JaktInternal::DynamicArray<NonnullRefPtr<typename types::CheckedStatement>> defaults;
bool has_arguments;
types::CheckedMatchBody body;
utility::Span marker_span;
template<typename _MemberT0, typename _MemberT1, typename _MemberT2, typename _MemberT3>
CatchAll(_MemberT0&& member_0, _MemberT1&& member_1, _MemberT2&& member_2, _MemberT3&& member_3):
defaults{ forward<_MemberT0>(member_0)},
has_arguments{ forward<_MemberT1>(member_1)},
body{ forward<_MemberT2>(member_2)},
marker_span{ forward<_MemberT3>(member_3)}
{}
};
}
struct CheckedMatchCase : public Variant<CheckedMatchCase_Details::EnumVariant, CheckedMatchCase_Details::Expression, CheckedMatchCase_Details::CatchAll> {
using Variant<CheckedMatchCase_Details::EnumVariant, CheckedMatchCase_Details::Expression, CheckedMatchCase_Details::CatchAll>::Variant;
    using EnumVariant = CheckedMatchCase_Details::EnumVariant;
    using Expression = CheckedMatchCase_Details::Expression;
    using CatchAll = CheckedMatchCase_Details::CatchAll;
ErrorOr<DeprecatedString> debug_description() const;
JaktInternal::DynamicArray<NonnullRefPtr<typename types::CheckedStatement>> const& defaults() const { switch(this->index()) {case 0 /* EnumVariant */: return this->template get<CheckedMatchCase::EnumVariant>().defaults;
case 1 /* Expression */: return this->template get<CheckedMatchCase::Expression>().defaults;
case 2 /* CatchAll */: return this->template get<CheckedMatchCase::CatchAll>().defaults;
default: VERIFY_NOT_REACHED();
}
}
};
struct CheckedGenericParameter {
  public:
types::TypeId type_id;JaktInternal::DynamicArray<types::TraitId> constraints;utility::Span span;CheckedGenericParameter(types::TypeId a_type_id, JaktInternal::DynamicArray<types::TraitId> a_constraints, utility::Span a_span);

static ErrorOr<types::CheckedGenericParameter> make(types::TypeId const type_id, utility::Span const span);
ErrorOr<DeprecatedString> debug_description() const;
};namespace CheckedStatement_Details {
struct Expression {
NonnullRefPtr<typename types::CheckedExpression> expr;
utility::Span span;
template<typename _MemberT0, typename _MemberT1>
Expression(_MemberT0&& member_0, _MemberT1&& member_1):
expr{ forward<_MemberT0>(member_0)},
span{ forward<_MemberT1>(member_1)}
{}
};
struct Defer {
NonnullRefPtr<typename types::CheckedStatement> statement;
utility::Span span;
template<typename _MemberT0, typename _MemberT1>
Defer(_MemberT0&& member_0, _MemberT1&& member_1):
statement{ forward<_MemberT0>(member_0)},
span{ forward<_MemberT1>(member_1)}
{}
};
struct DestructuringAssignment {
JaktInternal::DynamicArray<NonnullRefPtr<typename types::CheckedStatement>> vars;
NonnullRefPtr<typename types::CheckedStatement> var_decl;
utility::Span span;
template<typename _MemberT0, typename _MemberT1, typename _MemberT2>
DestructuringAssignment(_MemberT0&& member_0, _MemberT1&& member_1, _MemberT2&& member_2):
vars{ forward<_MemberT0>(member_0)},
var_decl{ forward<_MemberT1>(member_1)},
span{ forward<_MemberT2>(member_2)}
{}
};
struct VarDecl {
types::VarId var_id;
NonnullRefPtr<typename types::CheckedExpression> init;
utility::Span span;
template<typename _MemberT0, typename _MemberT1, typename _MemberT2>
VarDecl(_MemberT0&& member_0, _MemberT1&& member_1, _MemberT2&& member_2):
var_id{ forward<_MemberT0>(member_0)},
init{ forward<_MemberT1>(member_1)},
span{ forward<_MemberT2>(member_2)}
{}
};
struct If {
NonnullRefPtr<typename types::CheckedExpression> condition;
types::CheckedBlock then_block;
JaktInternal::Optional<NonnullRefPtr<typename types::CheckedStatement>> else_statement;
utility::Span span;
template<typename _MemberT0, typename _MemberT1, typename _MemberT2, typename _MemberT3>
If(_MemberT0&& member_0, _MemberT1&& member_1, _MemberT2&& member_2, _MemberT3&& member_3):
condition{ forward<_MemberT0>(member_0)},
then_block{ forward<_MemberT1>(member_1)},
else_statement{ forward<_MemberT2>(member_2)},
span{ forward<_MemberT3>(member_3)}
{}
};
struct Block {
types::CheckedBlock block;
utility::Span span;
template<typename _MemberT0, typename _MemberT1>
Block(_MemberT0&& member_0, _MemberT1&& member_1):
block{ forward<_MemberT0>(member_0)},
span{ forward<_MemberT1>(member_1)}
{}
};
struct Loop {
types::CheckedBlock block;
utility::Span span;
template<typename _MemberT0, typename _MemberT1>
Loop(_MemberT0&& member_0, _MemberT1&& member_1):
block{ forward<_MemberT0>(member_0)},
span{ forward<_MemberT1>(member_1)}
{}
};
struct While {
NonnullRefPtr<typename types::CheckedExpression> condition;
types::CheckedBlock block;
utility::Span span;
template<typename _MemberT0, typename _MemberT1, typename _MemberT2>
While(_MemberT0&& member_0, _MemberT1&& member_1, _MemberT2&& member_2):
condition{ forward<_MemberT0>(member_0)},
block{ forward<_MemberT1>(member_1)},
span{ forward<_MemberT2>(member_2)}
{}
};
struct Return {
JaktInternal::Optional<NonnullRefPtr<typename types::CheckedExpression>> val;
JaktInternal::Optional<utility::Span> span;
template<typename _MemberT0, typename _MemberT1>
Return(_MemberT0&& member_0, _MemberT1&& member_1):
val{ forward<_MemberT0>(member_0)},
span{ forward<_MemberT1>(member_1)}
{}
};
struct Break{
utility::Span value;
template<typename _MemberT0>
Break(_MemberT0&& member_0):
value{ forward<_MemberT0>(member_0)}
{}
};
struct Continue{
utility::Span value;
template<typename _MemberT0>
Continue(_MemberT0&& member_0):
value{ forward<_MemberT0>(member_0)}
{}
};
struct Throw {
NonnullRefPtr<typename types::CheckedExpression> expr;
utility::Span span;
template<typename _MemberT0, typename _MemberT1>
Throw(_MemberT0&& member_0, _MemberT1&& member_1):
expr{ forward<_MemberT0>(member_0)},
span{ forward<_MemberT1>(member_1)}
{}
};
struct Yield {
NonnullRefPtr<typename types::CheckedExpression> expr;
utility::Span span;
template<typename _MemberT0, typename _MemberT1>
Yield(_MemberT0&& member_0, _MemberT1&& member_1):
expr{ forward<_MemberT0>(member_0)},
span{ forward<_MemberT1>(member_1)}
{}
};
struct InlineCpp {
JaktInternal::DynamicArray<DeprecatedString> lines;
utility::Span span;
template<typename _MemberT0, typename _MemberT1>
InlineCpp(_MemberT0&& member_0, _MemberT1&& member_1):
lines{ forward<_MemberT0>(member_0)},
span{ forward<_MemberT1>(member_1)}
{}
};
struct Garbage{
utility::Span value;
template<typename _MemberT0>
Garbage(_MemberT0&& member_0):
value{ forward<_MemberT0>(member_0)}
{}
};
}
struct CheckedStatement : public Variant<CheckedStatement_Details::Expression, CheckedStatement_Details::Defer, CheckedStatement_Details::DestructuringAssignment, CheckedStatement_Details::VarDecl, CheckedStatement_Details::If, CheckedStatement_Details::Block, CheckedStatement_Details::Loop, CheckedStatement_Details::While, CheckedStatement_Details::Return, CheckedStatement_Details::Break, CheckedStatement_Details::Continue, CheckedStatement_Details::Throw, CheckedStatement_Details::Yield, CheckedStatement_Details::InlineCpp, CheckedStatement_Details::Garbage>, public RefCounted<CheckedStatement> {
using Variant<CheckedStatement_Details::Expression, CheckedStatement_Details::Defer, CheckedStatement_Details::DestructuringAssignment, CheckedStatement_Details::VarDecl, CheckedStatement_Details::If, CheckedStatement_Details::Block, CheckedStatement_Details::Loop, CheckedStatement_Details::While, CheckedStatement_Details::Return, CheckedStatement_Details::Break, CheckedStatement_Details::Continue, CheckedStatement_Details::Throw, CheckedStatement_Details::Yield, CheckedStatement_Details::InlineCpp, CheckedStatement_Details::Garbage>::Variant;
    using Expression = CheckedStatement_Details::Expression;
    using Defer = CheckedStatement_Details::Defer;
    using DestructuringAssignment = CheckedStatement_Details::DestructuringAssignment;
    using VarDecl = CheckedStatement_Details::VarDecl;
    using If = CheckedStatement_Details::If;
    using Block = CheckedStatement_Details::Block;
    using Loop = CheckedStatement_Details::Loop;
    using While = CheckedStatement_Details::While;
    using Return = CheckedStatement_Details::Return;
    using Break = CheckedStatement_Details::Break;
    using Continue = CheckedStatement_Details::Continue;
    using Throw = CheckedStatement_Details::Throw;
    using Yield = CheckedStatement_Details::Yield;
    using InlineCpp = CheckedStatement_Details::InlineCpp;
    using Garbage = CheckedStatement_Details::Garbage;
template<typename V, typename... Args> static auto create(Args&&... args) {
return adopt_nonnull_ref_or_enomem(new (nothrow) CheckedStatement(V(forward<Args>(args)...)));
}
ErrorOr<DeprecatedString> debug_description() const;
static JaktInternal::Optional<NonnullRefPtr<typename types::CheckedStatement>> none();
JaktInternal::Optional<utility::Span> span() const;
};
class Scope : public RefCounted<Scope>, public Weakable<Scope> {
  public:
virtual ~Scope() = default;
JaktInternal::Optional<DeprecatedString> namespace_name;JaktInternal::Optional<DeprecatedString> external_name;JaktInternal::Dictionary<DeprecatedString,types::VarId> vars;JaktInternal::Dictionary<DeprecatedString,types::Value> comptime_bindings;JaktInternal::Dictionary<DeprecatedString,types::StructId> structs;JaktInternal::Dictionary<DeprecatedString,JaktInternal::DynamicArray<types::FunctionId>> functions;JaktInternal::Dictionary<DeprecatedString,types::EnumId> enums;JaktInternal::Dictionary<DeprecatedString,types::TypeId> types;JaktInternal::Dictionary<DeprecatedString,types::TraitId> traits;JaktInternal::Dictionary<DeprecatedString,types::ModuleId> imports;JaktInternal::Dictionary<DeprecatedString,types::ScopeId> aliases;JaktInternal::Optional<types::ScopeId> parent;JaktInternal::Optional<types::ScopeId> alias_scope;JaktInternal::DynamicArray<types::ScopeId> children;bool can_throw;JaktInternal::Optional<DeprecatedString> import_path_if_extern;JaktInternal::Optional<JaktInternal::DynamicArray<types::ResolvedNamespace>> alias_path;JaktInternal::DynamicArray<parser::IncludeAction> after_extern_include;JaktInternal::DynamicArray<parser::IncludeAction> before_extern_include;DeprecatedString debug_name;JaktInternal::DynamicArray<types::ScopeId> resolution_mixins;protected:
explicit Scope(JaktInternal::Optional<DeprecatedString>&& a_namespace_name, JaktInternal::Optional<DeprecatedString>&& a_external_name, JaktInternal::Dictionary<DeprecatedString,types::VarId>&& a_vars, JaktInternal::Dictionary<DeprecatedString,types::Value>&& a_comptime_bindings, JaktInternal::Dictionary<DeprecatedString,types::StructId>&& a_structs, JaktInternal::Dictionary<DeprecatedString,JaktInternal::DynamicArray<types::FunctionId>>&& a_functions, JaktInternal::Dictionary<DeprecatedString,types::EnumId>&& a_enums, JaktInternal::Dictionary<DeprecatedString,types::TypeId>&& a_types, JaktInternal::Dictionary<DeprecatedString,types::TraitId>&& a_traits, JaktInternal::Dictionary<DeprecatedString,types::ModuleId>&& a_imports, JaktInternal::Dictionary<DeprecatedString,types::ScopeId>&& a_aliases, JaktInternal::Optional<types::ScopeId>&& a_parent, JaktInternal::Optional<types::ScopeId>&& a_alias_scope, JaktInternal::DynamicArray<types::ScopeId>&& a_children, bool&& a_can_throw, JaktInternal::Optional<DeprecatedString>&& a_import_path_if_extern, JaktInternal::Optional<JaktInternal::DynamicArray<types::ResolvedNamespace>>&& a_alias_path, JaktInternal::DynamicArray<parser::IncludeAction>&& a_after_extern_include, JaktInternal::DynamicArray<parser::IncludeAction>&& a_before_extern_include, DeprecatedString&& a_debug_name, JaktInternal::DynamicArray<types::ScopeId>&& a_resolution_mixins);
public:
static ErrorOr<NonnullRefPtr<Scope>> create(JaktInternal::Optional<DeprecatedString> namespace_name, JaktInternal::Optional<DeprecatedString> external_name, JaktInternal::Dictionary<DeprecatedString,types::VarId> vars, JaktInternal::Dictionary<DeprecatedString,types::Value> comptime_bindings, JaktInternal::Dictionary<DeprecatedString,types::StructId> structs, JaktInternal::Dictionary<DeprecatedString,JaktInternal::DynamicArray<types::FunctionId>> functions, JaktInternal::Dictionary<DeprecatedString,types::EnumId> enums, JaktInternal::Dictionary<DeprecatedString,types::TypeId> types, JaktInternal::Dictionary<DeprecatedString,types::TraitId> traits, JaktInternal::Dictionary<DeprecatedString,types::ModuleId> imports, JaktInternal::Dictionary<DeprecatedString,types::ScopeId> aliases, JaktInternal::Optional<types::ScopeId> parent, JaktInternal::Optional<types::ScopeId> alias_scope, JaktInternal::DynamicArray<types::ScopeId> children, bool can_throw, JaktInternal::Optional<DeprecatedString> import_path_if_extern, JaktInternal::Optional<JaktInternal::DynamicArray<types::ResolvedNamespace>> alias_path, JaktInternal::DynamicArray<parser::IncludeAction> after_extern_include, JaktInternal::DynamicArray<parser::IncludeAction> before_extern_include, DeprecatedString debug_name, JaktInternal::DynamicArray<types::ScopeId> resolution_mixins);

ErrorOr<DeprecatedString> debug_description() const;
};class CheckedProgram : public RefCounted<CheckedProgram>, public Weakable<CheckedProgram> {
  public:
virtual ~CheckedProgram() = default;
NonnullRefPtr<compiler::Compiler> compiler;JaktInternal::DynamicArray<NonnullRefPtr<types::Module>> modules;JaktInternal::Dictionary<DeprecatedString,types::LoadedModule> loaded_modules;bool is_floating(types::TypeId const type_id) const;
ErrorOr<JaktInternal::Optional<JaktInternal::Tuple<JaktInternal::DynamicArray<types::FunctionId>,types::ScopeId>>> find_scoped_functions_with_name_in_scope(types::ScopeId const parent_scope_id, DeprecatedString const function_name) const;
bool is_signed(types::TypeId const type_id) const;
ErrorOr<JaktInternal::Optional<types::StructId>> find_struct_in_scope(types::ScopeId const scope_id, DeprecatedString const name) const;
ErrorOr<void> set_loaded_module(DeprecatedString const module_name, types::LoadedModule const loaded_module);
bool is_integer(types::TypeId const type_id) const;
ErrorOr<types::ScopeId> create_scope(JaktInternal::Optional<types::ScopeId> const parent_scope_id, bool const can_throw, DeprecatedString const debug_name, types::ModuleId const module_id);
NonnullRefPtr<types::Module> get_module(types::ModuleId const id) const;
ErrorOr<JaktInternal::Optional<bool>> for_each_scope_accessible_unqualified_from_scope_impl(types::ScopeId const scope_id, Function<ErrorOr<typename utility::IterationDecision<bool>>(types::ScopeId, JaktInternal::Optional<DeprecatedString>, bool)> const& callback) const;
ErrorOr<bool> is_scope_directly_accessible_from(types::ScopeId const check_scope_id, types::ScopeId const scope_id) const;
ErrorOr<types::TypeId> substitute_typevars_in_type_helper(types::TypeId const type_id, types::GenericInferences const generic_inferences, types::ModuleId const module_id);
bool is_string(types::TypeId const type_id) const;
types::ScopeId prelude_scope_id() const;
protected:
explicit CheckedProgram(NonnullRefPtr<compiler::Compiler>&& a_compiler, JaktInternal::DynamicArray<NonnullRefPtr<types::Module>>&& a_modules, JaktInternal::Dictionary<DeprecatedString,types::LoadedModule>&& a_loaded_modules);
public:
static ErrorOr<NonnullRefPtr<CheckedProgram>> create(NonnullRefPtr<compiler::Compiler> compiler, JaktInternal::DynamicArray<NonnullRefPtr<types::Module>> modules, JaktInternal::Dictionary<DeprecatedString,types::LoadedModule> loaded_modules);

NonnullRefPtr<types::CheckedFunction> get_function(types::FunctionId const id) const;
ErrorOr<JaktInternal::Optional<types::Value>> find_comptime_binding_in_scope(types::ScopeId const scope_id, DeprecatedString const name) const;
i64 get_bits(types::TypeId const type_id) const;
NonnullRefPtr<typename types::Type> get_type(types::TypeId const id) const;
ErrorOr<types::TypeId> find_or_add_type_id(NonnullRefPtr<typename types::Type> const type, types::ModuleId const module_id);
ErrorOr<types::StructId> find_struct_in_prelude(DeprecatedString const name) const;
ErrorOr<JaktInternal::Optional<JaktInternal::Tuple<types::ScopeId,bool>>> find_namespace_in_scope(types::ScopeId const scope_id, DeprecatedString const name, bool const treat_aliases_as_imports) const;
types::CheckedEnum get_enum(types::EnumId const id) const;
template <typename T>
ErrorOr<JaktInternal::Optional<T>> for_each_scope_accessible_unqualified_from_scope(types::ScopeId const scope_id,Function<ErrorOr<typename utility::IterationDecision<T>>(types::ScopeId, JaktInternal::Optional<DeprecatedString>, bool)> const& callback) const {
{
JaktInternal::Optional<T> result = JaktInternal::OptionalNone();
TRY((((*this).for_each_scope_accessible_unqualified_from_scope_impl(scope_id,(([&callback, &result](types::ScopeId scope_id, JaktInternal::Optional<DeprecatedString> name_override, bool is_alias) -> ErrorOr<typename utility::IterationDecision<bool>> {
{
JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(([&]() -> JaktInternal::ExplicitValueOrControlFlow<void,ErrorOr<typename utility::IterationDecision<bool>>>{
auto&& __jakt_enum_value = JaktInternal::deref_if_ref_pointer(TRY((callback(scope_id,name_override,is_alias))));
if (__jakt_enum_value.index() == 0 /* Break */) {
auto& __jakt_match_value = __jakt_enum_value.template get<typename JaktInternal::RemoveRefPtr<utility::IterationDecision<T>>::Break>();
auto& value = __jakt_match_value.value;
{
(result = value);
return ( typename utility::IterationDecision<bool> { typename utility::IterationDecision<bool>::Break(true) } );
}
return JaktInternal::ExplicitValue<void>();
}
if (__jakt_enum_value.index() == 1 /* Continue */) {
auto& __jakt_match_value = __jakt_enum_value.template get<typename JaktInternal::RemoveRefPtr<utility::IterationDecision<T>>::Continue>();
{
return ( typename utility::IterationDecision<bool> { typename utility::IterationDecision<bool>::Continue() } );
}
return JaktInternal::ExplicitValue<void>();
}
return JaktInternal::ExplicitValue<void>();
}()))
;
}
}
))))));
return (result);
}
}
ErrorOr<JaktInternal::Optional<types::TraitId>> find_trait_in_scope(types::ScopeId const scope_id, DeprecatedString const name) const;
NonnullRefPtr<types::CheckedTrait> get_trait(types::TraitId const id) const;
ErrorOr<DeprecatedString> type_name(types::TypeId const type_id, bool const debug_mode) const;
ErrorOr<JaktInternal::Optional<JaktInternal::DynamicArray<types::FunctionId>>> find_functions_with_name_in_scope(types::ScopeId const parent_scope_id, DeprecatedString const function_name) const;
ErrorOr<JaktInternal::Optional<NonnullRefPtr<types::CheckedVariable>>> find_var_in_scope(types::ScopeId const scope_id, DeprecatedString const var) const;
types::CheckedStruct get_struct(types::StructId const id) const;
ErrorOr<JaktInternal::Optional<types::StructId>> check_and_extract_weak_ptr(types::StructId const struct_id, JaktInternal::DynamicArray<types::TypeId> const args) const;
ErrorOr<JaktInternal::Optional<types::EnumId>> find_enum_in_scope(types::ScopeId const scope_id, DeprecatedString const name) const;
JaktInternal::Optional<types::LoadedModule> get_loaded_module(DeprecatedString const module_name) const;
bool is_numeric(types::TypeId const type_id) const;
NonnullRefPtr<types::CheckedVariable> get_variable(types::VarId const id) const;
ErrorOr<types::TypeId> substitute_typevars_in_type(types::TypeId const type_id, types::GenericInferences const generic_inferences, types::ModuleId const module_id);
ErrorOr<NonnullRefPtr<types::Scope>> get_scope(types::ScopeId const id) const;
ErrorOr<DeprecatedString> debug_description() const;
};struct CheckedCall {
  public:
JaktInternal::DynamicArray<types::ResolvedNamespace> namespace_;DeprecatedString name;JaktInternal::DynamicArray<JaktInternal::Tuple<DeprecatedString,NonnullRefPtr<typename types::CheckedExpression>>> args;JaktInternal::DynamicArray<types::TypeId> type_args;JaktInternal::Optional<types::FunctionId> function_id;types::TypeId return_type;bool callee_throws;JaktInternal::Optional<DeprecatedString> external_name;CheckedCall(JaktInternal::DynamicArray<types::ResolvedNamespace> a_namespace_, DeprecatedString a_name, JaktInternal::DynamicArray<JaktInternal::Tuple<DeprecatedString,NonnullRefPtr<typename types::CheckedExpression>>> a_args, JaktInternal::DynamicArray<types::TypeId> a_type_args, JaktInternal::Optional<types::FunctionId> a_function_id, types::TypeId a_return_type, bool a_callee_throws, JaktInternal::Optional<DeprecatedString> a_external_name);

DeprecatedString name_for_codegen() const;
ErrorOr<DeprecatedString> debug_description() const;
};struct LoadedModule {
  public:
types::ModuleId module_id;utility::FileId file_id;LoadedModule(types::ModuleId a_module_id, utility::FileId a_file_id);

ErrorOr<DeprecatedString> debug_description() const;
};struct FunctionGenericParameter {
  public:
types::FunctionGenericParameterKind kind;types::CheckedGenericParameter checked_parameter;static ErrorOr<types::FunctionGenericParameter> parameter(types::TypeId const type_id, utility::Span const span);
types::TypeId type_id() const;
FunctionGenericParameter(types::FunctionGenericParameterKind a_kind, types::CheckedGenericParameter a_checked_parameter);

ErrorOr<DeprecatedString> debug_description() const;
};struct CheckedEnum {
  public:
DeprecatedString name;utility::Span name_span;JaktInternal::DynamicArray<types::CheckedGenericParameter> generic_parameters;JaktInternal::DynamicArray<types::CheckedEnumVariant> variants;JaktInternal::DynamicArray<types::CheckedField> fields;types::ScopeId scope_id;parser::DefinitionLinkage definition_linkage;JaktInternal::Dictionary<DeprecatedString,JaktInternal::Tuple<types::TraitId,JaktInternal::DynamicArray<types::TypeId>>> trait_implementations;parser::RecordType record_type;types::TypeId underlying_type_id;types::TypeId type_id;bool is_boxed;CheckedEnum(DeprecatedString a_name, utility::Span a_name_span, JaktInternal::DynamicArray<types::CheckedGenericParameter> a_generic_parameters, JaktInternal::DynamicArray<types::CheckedEnumVariant> a_variants, JaktInternal::DynamicArray<types::CheckedField> a_fields, types::ScopeId a_scope_id, parser::DefinitionLinkage a_definition_linkage, JaktInternal::Dictionary<DeprecatedString,JaktInternal::Tuple<types::TraitId,JaktInternal::DynamicArray<types::TypeId>>> a_trait_implementations, parser::RecordType a_record_type, types::TypeId a_underlying_type_id, types::TypeId a_type_id, bool a_is_boxed);

ErrorOr<DeprecatedString> debug_description() const;
};struct GenericInferences {
  public:
JaktInternal::Dictionary<DeprecatedString,DeprecatedString> values;DeprecatedString map_name(DeprecatedString const type) const;
GenericInferences(JaktInternal::Dictionary<DeprecatedString,DeprecatedString> a_values);

void restore(JaktInternal::Dictionary<DeprecatedString,DeprecatedString> const checkpoint);
ErrorOr<types::TypeId> map(types::TypeId const type_id) const;
JaktInternal::Dictionary<DeprecatedString,DeprecatedString> iterator() const;
ErrorOr<void> set(DeprecatedString const key, DeprecatedString const value);
ErrorOr<void> set_all(JaktInternal::DynamicArray<types::CheckedGenericParameter> const keys, JaktInternal::DynamicArray<types::TypeId> const values);
ErrorOr<void> set_from(JaktInternal::Dictionary<DeprecatedString,DeprecatedString> const checkpoint);
JaktInternal::Optional<DeprecatedString> get(DeprecatedString const key) const;
ErrorOr<JaktInternal::Dictionary<DeprecatedString,DeprecatedString>> perform_checkpoint(bool const reset);
ErrorOr<DeprecatedString> debug_description() const;
};class CheckedTrait : public RefCounted<CheckedTrait>, public Weakable<CheckedTrait> {
  public:
virtual ~CheckedTrait() = default;
DeprecatedString name;utility::Span name_span;JaktInternal::Dictionary<DeprecatedString,types::FunctionId> methods;JaktInternal::DynamicArray<types::CheckedGenericParameter> generic_parameters;types::ScopeId scope_id;protected:
explicit CheckedTrait(DeprecatedString&& a_name, utility::Span&& a_name_span, JaktInternal::Dictionary<DeprecatedString,types::FunctionId>&& a_methods, JaktInternal::DynamicArray<types::CheckedGenericParameter>&& a_generic_parameters, types::ScopeId&& a_scope_id);
public:
static ErrorOr<NonnullRefPtr<CheckedTrait>> create(DeprecatedString name, utility::Span name_span, JaktInternal::Dictionary<DeprecatedString,types::FunctionId> methods, JaktInternal::DynamicArray<types::CheckedGenericParameter> generic_parameters, types::ScopeId scope_id);

ErrorOr<DeprecatedString> debug_description() const;
};namespace CheckedNumericConstant_Details {
struct I8{
i8 value;
template<typename _MemberT0>
I8(_MemberT0&& member_0):
value{ forward<_MemberT0>(member_0)}
{}
};
struct I16{
i16 value;
template<typename _MemberT0>
I16(_MemberT0&& member_0):
value{ forward<_MemberT0>(member_0)}
{}
};
struct I32{
i32 value;
template<typename _MemberT0>
I32(_MemberT0&& member_0):
value{ forward<_MemberT0>(member_0)}
{}
};
struct I64{
i64 value;
template<typename _MemberT0>
I64(_MemberT0&& member_0):
value{ forward<_MemberT0>(member_0)}
{}
};
struct U8{
u8 value;
template<typename _MemberT0>
U8(_MemberT0&& member_0):
value{ forward<_MemberT0>(member_0)}
{}
};
struct U16{
u16 value;
template<typename _MemberT0>
U16(_MemberT0&& member_0):
value{ forward<_MemberT0>(member_0)}
{}
};
struct U32{
u32 value;
template<typename _MemberT0>
U32(_MemberT0&& member_0):
value{ forward<_MemberT0>(member_0)}
{}
};
struct U64{
u64 value;
template<typename _MemberT0>
U64(_MemberT0&& member_0):
value{ forward<_MemberT0>(member_0)}
{}
};
struct USize{
u64 value;
template<typename _MemberT0>
USize(_MemberT0&& member_0):
value{ forward<_MemberT0>(member_0)}
{}
};
struct F32{
f32 value;
template<typename _MemberT0>
F32(_MemberT0&& member_0):
value{ forward<_MemberT0>(member_0)}
{}
};
struct F64{
f64 value;
template<typename _MemberT0>
F64(_MemberT0&& member_0):
value{ forward<_MemberT0>(member_0)}
{}
};
}
struct CheckedNumericConstant : public Variant<CheckedNumericConstant_Details::I8, CheckedNumericConstant_Details::I16, CheckedNumericConstant_Details::I32, CheckedNumericConstant_Details::I64, CheckedNumericConstant_Details::U8, CheckedNumericConstant_Details::U16, CheckedNumericConstant_Details::U32, CheckedNumericConstant_Details::U64, CheckedNumericConstant_Details::USize, CheckedNumericConstant_Details::F32, CheckedNumericConstant_Details::F64> {
using Variant<CheckedNumericConstant_Details::I8, CheckedNumericConstant_Details::I16, CheckedNumericConstant_Details::I32, CheckedNumericConstant_Details::I64, CheckedNumericConstant_Details::U8, CheckedNumericConstant_Details::U16, CheckedNumericConstant_Details::U32, CheckedNumericConstant_Details::U64, CheckedNumericConstant_Details::USize, CheckedNumericConstant_Details::F32, CheckedNumericConstant_Details::F64>::Variant;
    using I8 = CheckedNumericConstant_Details::I8;
    using I16 = CheckedNumericConstant_Details::I16;
    using I32 = CheckedNumericConstant_Details::I32;
    using I64 = CheckedNumericConstant_Details::I64;
    using U8 = CheckedNumericConstant_Details::U8;
    using U16 = CheckedNumericConstant_Details::U16;
    using U32 = CheckedNumericConstant_Details::U32;
    using U64 = CheckedNumericConstant_Details::U64;
    using USize = CheckedNumericConstant_Details::USize;
    using F32 = CheckedNumericConstant_Details::F32;
    using F64 = CheckedNumericConstant_Details::F64;
ErrorOr<DeprecatedString> debug_description() const;
JaktInternal::Optional<types::NumberConstant> number_constant() const;
};
struct CheckedStringLiteral {
  public:
types::StringLiteral value;types::TypeId type_id;bool may_throw;DeprecatedString to_string() const;
CheckedStringLiteral(types::StringLiteral a_value, types::TypeId a_type_id, bool a_may_throw);

ErrorOr<DeprecatedString> debug_description() const;
};namespace CheckedExpression_Details {
struct Boolean {
bool val;
utility::Span span;
template<typename _MemberT0, typename _MemberT1>
Boolean(_MemberT0&& member_0, _MemberT1&& member_1):
val{ forward<_MemberT0>(member_0)},
span{ forward<_MemberT1>(member_1)}
{}
};
struct NumericConstant {
types::CheckedNumericConstant val;
utility::Span span;
types::TypeId type_id;
template<typename _MemberT0, typename _MemberT1, typename _MemberT2>
NumericConstant(_MemberT0&& member_0, _MemberT1&& member_1, _MemberT2&& member_2):
val{ forward<_MemberT0>(member_0)},
span{ forward<_MemberT1>(member_1)},
type_id{ forward<_MemberT2>(member_2)}
{}
};
struct QuotedString {
types::CheckedStringLiteral val;
utility::Span span;
template<typename _MemberT0, typename _MemberT1>
QuotedString(_MemberT0&& member_0, _MemberT1&& member_1):
val{ forward<_MemberT0>(member_0)},
span{ forward<_MemberT1>(member_1)}
{}
};
struct ByteConstant {
DeprecatedString val;
utility::Span span;
template<typename _MemberT0, typename _MemberT1>
ByteConstant(_MemberT0&& member_0, _MemberT1&& member_1):
val{ forward<_MemberT0>(member_0)},
span{ forward<_MemberT1>(member_1)}
{}
};
struct CharacterConstant {
DeprecatedString val;
utility::Span span;
template<typename _MemberT0, typename _MemberT1>
CharacterConstant(_MemberT0&& member_0, _MemberT1&& member_1):
val{ forward<_MemberT0>(member_0)},
span{ forward<_MemberT1>(member_1)}
{}
};
struct UnaryOp {
NonnullRefPtr<typename types::CheckedExpression> expr;
types::CheckedUnaryOperator op;
utility::Span span;
types::TypeId type_id;
template<typename _MemberT0, typename _MemberT1, typename _MemberT2, typename _MemberT3>
UnaryOp(_MemberT0&& member_0, _MemberT1&& member_1, _MemberT2&& member_2, _MemberT3&& member_3):
expr{ forward<_MemberT0>(member_0)},
op{ forward<_MemberT1>(member_1)},
span{ forward<_MemberT2>(member_2)},
type_id{ forward<_MemberT3>(member_3)}
{}
};
struct BinaryOp {
NonnullRefPtr<typename types::CheckedExpression> lhs;
parser::BinaryOperator op;
NonnullRefPtr<typename types::CheckedExpression> rhs;
utility::Span span;
types::TypeId type_id;
template<typename _MemberT0, typename _MemberT1, typename _MemberT2, typename _MemberT3, typename _MemberT4>
BinaryOp(_MemberT0&& member_0, _MemberT1&& member_1, _MemberT2&& member_2, _MemberT3&& member_3, _MemberT4&& member_4):
lhs{ forward<_MemberT0>(member_0)},
op{ forward<_MemberT1>(member_1)},
rhs{ forward<_MemberT2>(member_2)},
span{ forward<_MemberT3>(member_3)},
type_id{ forward<_MemberT4>(member_4)}
{}
};
struct JaktTuple {
JaktInternal::DynamicArray<NonnullRefPtr<typename types::CheckedExpression>> vals;
utility::Span span;
types::TypeId type_id;
template<typename _MemberT0, typename _MemberT1, typename _MemberT2>
JaktTuple(_MemberT0&& member_0, _MemberT1&& member_1, _MemberT2&& member_2):
vals{ forward<_MemberT0>(member_0)},
span{ forward<_MemberT1>(member_1)},
type_id{ forward<_MemberT2>(member_2)}
{}
};
struct Range {
JaktInternal::Optional<NonnullRefPtr<typename types::CheckedExpression>> from;
JaktInternal::Optional<NonnullRefPtr<typename types::CheckedExpression>> to;
utility::Span span;
types::TypeId type_id;
template<typename _MemberT0, typename _MemberT1, typename _MemberT2, typename _MemberT3>
Range(_MemberT0&& member_0, _MemberT1&& member_1, _MemberT2&& member_2, _MemberT3&& member_3):
from{ forward<_MemberT0>(member_0)},
to{ forward<_MemberT1>(member_1)},
span{ forward<_MemberT2>(member_2)},
type_id{ forward<_MemberT3>(member_3)}
{}
};
struct JaktArray {
JaktInternal::DynamicArray<NonnullRefPtr<typename types::CheckedExpression>> vals;
JaktInternal::Optional<NonnullRefPtr<typename types::CheckedExpression>> repeat;
utility::Span span;
types::TypeId type_id;
types::TypeId inner_type_id;
template<typename _MemberT0, typename _MemberT1, typename _MemberT2, typename _MemberT3, typename _MemberT4>
JaktArray(_MemberT0&& member_0, _MemberT1&& member_1, _MemberT2&& member_2, _MemberT3&& member_3, _MemberT4&& member_4):
vals{ forward<_MemberT0>(member_0)},
repeat{ forward<_MemberT1>(member_1)},
span{ forward<_MemberT2>(member_2)},
type_id{ forward<_MemberT3>(member_3)},
inner_type_id{ forward<_MemberT4>(member_4)}
{}
};
struct JaktSet {
JaktInternal::DynamicArray<NonnullRefPtr<typename types::CheckedExpression>> vals;
utility::Span span;
types::TypeId type_id;
types::TypeId inner_type_id;
template<typename _MemberT0, typename _MemberT1, typename _MemberT2, typename _MemberT3>
JaktSet(_MemberT0&& member_0, _MemberT1&& member_1, _MemberT2&& member_2, _MemberT3&& member_3):
vals{ forward<_MemberT0>(member_0)},
span{ forward<_MemberT1>(member_1)},
type_id{ forward<_MemberT2>(member_2)},
inner_type_id{ forward<_MemberT3>(member_3)}
{}
};
struct JaktDictionary {
JaktInternal::DynamicArray<JaktInternal::Tuple<NonnullRefPtr<typename types::CheckedExpression>,NonnullRefPtr<typename types::CheckedExpression>>> vals;
utility::Span span;
types::TypeId type_id;
types::TypeId key_type_id;
types::TypeId value_type_id;
template<typename _MemberT0, typename _MemberT1, typename _MemberT2, typename _MemberT3, typename _MemberT4>
JaktDictionary(_MemberT0&& member_0, _MemberT1&& member_1, _MemberT2&& member_2, _MemberT3&& member_3, _MemberT4&& member_4):
vals{ forward<_MemberT0>(member_0)},
span{ forward<_MemberT1>(member_1)},
type_id{ forward<_MemberT2>(member_2)},
key_type_id{ forward<_MemberT3>(member_3)},
value_type_id{ forward<_MemberT4>(member_4)}
{}
};
struct IndexedExpression {
NonnullRefPtr<typename types::CheckedExpression> expr;
NonnullRefPtr<typename types::CheckedExpression> index;
utility::Span span;
types::TypeId type_id;
template<typename _MemberT0, typename _MemberT1, typename _MemberT2, typename _MemberT3>
IndexedExpression(_MemberT0&& member_0, _MemberT1&& member_1, _MemberT2&& member_2, _MemberT3&& member_3):
expr{ forward<_MemberT0>(member_0)},
index{ forward<_MemberT1>(member_1)},
span{ forward<_MemberT2>(member_2)},
type_id{ forward<_MemberT3>(member_3)}
{}
};
struct IndexedDictionary {
NonnullRefPtr<typename types::CheckedExpression> expr;
NonnullRefPtr<typename types::CheckedExpression> index;
utility::Span span;
types::TypeId type_id;
template<typename _MemberT0, typename _MemberT1, typename _MemberT2, typename _MemberT3>
IndexedDictionary(_MemberT0&& member_0, _MemberT1&& member_1, _MemberT2&& member_2, _MemberT3&& member_3):
expr{ forward<_MemberT0>(member_0)},
index{ forward<_MemberT1>(member_1)},
span{ forward<_MemberT2>(member_2)},
type_id{ forward<_MemberT3>(member_3)}
{}
};
struct IndexedTuple {
NonnullRefPtr<typename types::CheckedExpression> expr;
size_t index;
utility::Span span;
bool is_optional;
types::TypeId type_id;
template<typename _MemberT0, typename _MemberT1, typename _MemberT2, typename _MemberT3, typename _MemberT4>
IndexedTuple(_MemberT0&& member_0, _MemberT1&& member_1, _MemberT2&& member_2, _MemberT3&& member_3, _MemberT4&& member_4):
expr{ forward<_MemberT0>(member_0)},
index{ forward<_MemberT1>(member_1)},
span{ forward<_MemberT2>(member_2)},
is_optional{ forward<_MemberT3>(member_3)},
type_id{ forward<_MemberT4>(member_4)}
{}
};
struct IndexedStruct {
NonnullRefPtr<typename types::CheckedExpression> expr;
DeprecatedString index;
utility::Span span;
bool is_optional;
types::TypeId type_id;
template<typename _MemberT0, typename _MemberT1, typename _MemberT2, typename _MemberT3, typename _MemberT4>
IndexedStruct(_MemberT0&& member_0, _MemberT1&& member_1, _MemberT2&& member_2, _MemberT3&& member_3, _MemberT4&& member_4):
expr{ forward<_MemberT0>(member_0)},
index{ forward<_MemberT1>(member_1)},
span{ forward<_MemberT2>(member_2)},
is_optional{ forward<_MemberT3>(member_3)},
type_id{ forward<_MemberT4>(member_4)}
{}
};
struct IndexedCommonEnumMember {
NonnullRefPtr<typename types::CheckedExpression> expr;
DeprecatedString index;
utility::Span span;
bool is_optional;
types::TypeId type_id;
template<typename _MemberT0, typename _MemberT1, typename _MemberT2, typename _MemberT3, typename _MemberT4>
IndexedCommonEnumMember(_MemberT0&& member_0, _MemberT1&& member_1, _MemberT2&& member_2, _MemberT3&& member_3, _MemberT4&& member_4):
expr{ forward<_MemberT0>(member_0)},
index{ forward<_MemberT1>(member_1)},
span{ forward<_MemberT2>(member_2)},
is_optional{ forward<_MemberT3>(member_3)},
type_id{ forward<_MemberT4>(member_4)}
{}
};
struct Match {
NonnullRefPtr<typename types::CheckedExpression> expr;
JaktInternal::DynamicArray<types::CheckedMatchCase> match_cases;
utility::Span span;
types::TypeId type_id;
bool all_variants_constant;
template<typename _MemberT0, typename _MemberT1, typename _MemberT2, typename _MemberT3, typename _MemberT4>
Match(_MemberT0&& member_0, _MemberT1&& member_1, _MemberT2&& member_2, _MemberT3&& member_3, _MemberT4&& member_4):
expr{ forward<_MemberT0>(member_0)},
match_cases{ forward<_MemberT1>(member_1)},
span{ forward<_MemberT2>(member_2)},
type_id{ forward<_MemberT3>(member_3)},
all_variants_constant{ forward<_MemberT4>(member_4)}
{}
};
struct EnumVariantArg {
NonnullRefPtr<typename types::CheckedExpression> expr;
types::CheckedEnumVariantBinding arg;
types::CheckedEnumVariant enum_variant;
utility::Span span;
template<typename _MemberT0, typename _MemberT1, typename _MemberT2, typename _MemberT3>
EnumVariantArg(_MemberT0&& member_0, _MemberT1&& member_1, _MemberT2&& member_2, _MemberT3&& member_3):
expr{ forward<_MemberT0>(member_0)},
arg{ forward<_MemberT1>(member_1)},
enum_variant{ forward<_MemberT2>(member_2)},
span{ forward<_MemberT3>(member_3)}
{}
};
struct Call {
types::CheckedCall call;
utility::Span span;
types::TypeId type_id;
template<typename _MemberT0, typename _MemberT1, typename _MemberT2>
Call(_MemberT0&& member_0, _MemberT1&& member_1, _MemberT2&& member_2):
call{ forward<_MemberT0>(member_0)},
span{ forward<_MemberT1>(member_1)},
type_id{ forward<_MemberT2>(member_2)}
{}
};
struct MethodCall {
NonnullRefPtr<typename types::CheckedExpression> expr;
types::CheckedCall call;
utility::Span span;
bool is_optional;
types::TypeId type_id;
template<typename _MemberT0, typename _MemberT1, typename _MemberT2, typename _MemberT3, typename _MemberT4>
MethodCall(_MemberT0&& member_0, _MemberT1&& member_1, _MemberT2&& member_2, _MemberT3&& member_3, _MemberT4&& member_4):
expr{ forward<_MemberT0>(member_0)},
call{ forward<_MemberT1>(member_1)},
span{ forward<_MemberT2>(member_2)},
is_optional{ forward<_MemberT3>(member_3)},
type_id{ forward<_MemberT4>(member_4)}
{}
};
struct NamespacedVar {
JaktInternal::DynamicArray<types::CheckedNamespace> namespaces;
NonnullRefPtr<types::CheckedVariable> var;
utility::Span span;
template<typename _MemberT0, typename _MemberT1, typename _MemberT2>
NamespacedVar(_MemberT0&& member_0, _MemberT1&& member_1, _MemberT2&& member_2):
namespaces{ forward<_MemberT0>(member_0)},
var{ forward<_MemberT1>(member_1)},
span{ forward<_MemberT2>(member_2)}
{}
};
struct Var {
NonnullRefPtr<types::CheckedVariable> var;
utility::Span span;
template<typename _MemberT0, typename _MemberT1>
Var(_MemberT0&& member_0, _MemberT1&& member_1):
var{ forward<_MemberT0>(member_0)},
span{ forward<_MemberT1>(member_1)}
{}
};
struct OptionalNone {
utility::Span span;
types::TypeId type_id;
template<typename _MemberT0, typename _MemberT1>
OptionalNone(_MemberT0&& member_0, _MemberT1&& member_1):
span{ forward<_MemberT0>(member_0)},
type_id{ forward<_MemberT1>(member_1)}
{}
};
struct OptionalSome {
NonnullRefPtr<typename types::CheckedExpression> expr;
utility::Span span;
types::TypeId type_id;
template<typename _MemberT0, typename _MemberT1, typename _MemberT2>
OptionalSome(_MemberT0&& member_0, _MemberT1&& member_1, _MemberT2&& member_2):
expr{ forward<_MemberT0>(member_0)},
span{ forward<_MemberT1>(member_1)},
type_id{ forward<_MemberT2>(member_2)}
{}
};
struct ForcedUnwrap {
NonnullRefPtr<typename types::CheckedExpression> expr;
utility::Span span;
types::TypeId type_id;
template<typename _MemberT0, typename _MemberT1, typename _MemberT2>
ForcedUnwrap(_MemberT0&& member_0, _MemberT1&& member_1, _MemberT2&& member_2):
expr{ forward<_MemberT0>(member_0)},
span{ forward<_MemberT1>(member_1)},
type_id{ forward<_MemberT2>(member_2)}
{}
};
struct Block {
types::CheckedBlock block;
utility::Span span;
types::TypeId type_id;
template<typename _MemberT0, typename _MemberT1, typename _MemberT2>
Block(_MemberT0&& member_0, _MemberT1&& member_1, _MemberT2&& member_2):
block{ forward<_MemberT0>(member_0)},
span{ forward<_MemberT1>(member_1)},
type_id{ forward<_MemberT2>(member_2)}
{}
};
struct Function {
JaktInternal::DynamicArray<types::CheckedCapture> captures;
JaktInternal::DynamicArray<types::CheckedParameter> params;
bool can_throw;
types::TypeId return_type_id;
types::CheckedBlock block;
utility::Span span;
types::TypeId type_id;
JaktInternal::Optional<types::FunctionId> pseudo_function_id;
template<typename _MemberT0, typename _MemberT1, typename _MemberT2, typename _MemberT3, typename _MemberT4, typename _MemberT5, typename _MemberT6, typename _MemberT7>
Function(_MemberT0&& member_0, _MemberT1&& member_1, _MemberT2&& member_2, _MemberT3&& member_3, _MemberT4&& member_4, _MemberT5&& member_5, _MemberT6&& member_6, _MemberT7&& member_7):
captures{ forward<_MemberT0>(member_0)},
params{ forward<_MemberT1>(member_1)},
can_throw{ forward<_MemberT2>(member_2)},
return_type_id{ forward<_MemberT3>(member_3)},
block{ forward<_MemberT4>(member_4)},
span{ forward<_MemberT5>(member_5)},
type_id{ forward<_MemberT6>(member_6)},
pseudo_function_id{ forward<_MemberT7>(member_7)}
{}
};
struct Try {
NonnullRefPtr<typename types::CheckedExpression> expr;
JaktInternal::Optional<types::CheckedBlock> catch_block;
JaktInternal::Optional<DeprecatedString> catch_name;
utility::Span span;
types::TypeId type_id;
types::TypeId inner_type_id;
template<typename _MemberT0, typename _MemberT1, typename _MemberT2, typename _MemberT3, typename _MemberT4, typename _MemberT5>
Try(_MemberT0&& member_0, _MemberT1&& member_1, _MemberT2&& member_2, _MemberT3&& member_3, _MemberT4&& member_4, _MemberT5&& member_5):
expr{ forward<_MemberT0>(member_0)},
catch_block{ forward<_MemberT1>(member_1)},
catch_name{ forward<_MemberT2>(member_2)},
span{ forward<_MemberT3>(member_3)},
type_id{ forward<_MemberT4>(member_4)},
inner_type_id{ forward<_MemberT5>(member_5)}
{}
};
struct TryBlock {
NonnullRefPtr<typename types::CheckedStatement> stmt;
types::CheckedBlock catch_block;
DeprecatedString error_name;
utility::Span error_span;
utility::Span span;
types::TypeId type_id;
template<typename _MemberT0, typename _MemberT1, typename _MemberT2, typename _MemberT3, typename _MemberT4, typename _MemberT5>
TryBlock(_MemberT0&& member_0, _MemberT1&& member_1, _MemberT2&& member_2, _MemberT3&& member_3, _MemberT4&& member_4, _MemberT5&& member_5):
stmt{ forward<_MemberT0>(member_0)},
catch_block{ forward<_MemberT1>(member_1)},
error_name{ forward<_MemberT2>(member_2)},
error_span{ forward<_MemberT3>(member_3)},
span{ forward<_MemberT4>(member_4)},
type_id{ forward<_MemberT5>(member_5)}
{}
};
struct Garbage{
utility::Span value;
template<typename _MemberT0>
Garbage(_MemberT0&& member_0):
value{ forward<_MemberT0>(member_0)}
{}
};
}
struct CheckedExpression : public Variant<CheckedExpression_Details::Boolean, CheckedExpression_Details::NumericConstant, CheckedExpression_Details::QuotedString, CheckedExpression_Details::ByteConstant, CheckedExpression_Details::CharacterConstant, CheckedExpression_Details::UnaryOp, CheckedExpression_Details::BinaryOp, CheckedExpression_Details::JaktTuple, CheckedExpression_Details::Range, CheckedExpression_Details::JaktArray, CheckedExpression_Details::JaktSet, CheckedExpression_Details::JaktDictionary, CheckedExpression_Details::IndexedExpression, CheckedExpression_Details::IndexedDictionary, CheckedExpression_Details::IndexedTuple, CheckedExpression_Details::IndexedStruct, CheckedExpression_Details::IndexedCommonEnumMember, CheckedExpression_Details::Match, CheckedExpression_Details::EnumVariantArg, CheckedExpression_Details::Call, CheckedExpression_Details::MethodCall, CheckedExpression_Details::NamespacedVar, CheckedExpression_Details::Var, CheckedExpression_Details::OptionalNone, CheckedExpression_Details::OptionalSome, CheckedExpression_Details::ForcedUnwrap, CheckedExpression_Details::Block, CheckedExpression_Details::Function, CheckedExpression_Details::Try, CheckedExpression_Details::TryBlock, CheckedExpression_Details::Garbage>, public RefCounted<CheckedExpression> {
using Variant<CheckedExpression_Details::Boolean, CheckedExpression_Details::NumericConstant, CheckedExpression_Details::QuotedString, CheckedExpression_Details::ByteConstant, CheckedExpression_Details::CharacterConstant, CheckedExpression_Details::UnaryOp, CheckedExpression_Details::BinaryOp, CheckedExpression_Details::JaktTuple, CheckedExpression_Details::Range, CheckedExpression_Details::JaktArray, CheckedExpression_Details::JaktSet, CheckedExpression_Details::JaktDictionary, CheckedExpression_Details::IndexedExpression, CheckedExpression_Details::IndexedDictionary, CheckedExpression_Details::IndexedTuple, CheckedExpression_Details::IndexedStruct, CheckedExpression_Details::IndexedCommonEnumMember, CheckedExpression_Details::Match, CheckedExpression_Details::EnumVariantArg, CheckedExpression_Details::Call, CheckedExpression_Details::MethodCall, CheckedExpression_Details::NamespacedVar, CheckedExpression_Details::Var, CheckedExpression_Details::OptionalNone, CheckedExpression_Details::OptionalSome, CheckedExpression_Details::ForcedUnwrap, CheckedExpression_Details::Block, CheckedExpression_Details::Function, CheckedExpression_Details::Try, CheckedExpression_Details::TryBlock, CheckedExpression_Details::Garbage>::Variant;
    using Boolean = CheckedExpression_Details::Boolean;
    using NumericConstant = CheckedExpression_Details::NumericConstant;
    using QuotedString = CheckedExpression_Details::QuotedString;
    using ByteConstant = CheckedExpression_Details::ByteConstant;
    using CharacterConstant = CheckedExpression_Details::CharacterConstant;
    using UnaryOp = CheckedExpression_Details::UnaryOp;
    using BinaryOp = CheckedExpression_Details::BinaryOp;
    using JaktTuple = CheckedExpression_Details::JaktTuple;
    using Range = CheckedExpression_Details::Range;
    using JaktArray = CheckedExpression_Details::JaktArray;
    using JaktSet = CheckedExpression_Details::JaktSet;
    using JaktDictionary = CheckedExpression_Details::JaktDictionary;
    using IndexedExpression = CheckedExpression_Details::IndexedExpression;
    using IndexedDictionary = CheckedExpression_Details::IndexedDictionary;
    using IndexedTuple = CheckedExpression_Details::IndexedTuple;
    using IndexedStruct = CheckedExpression_Details::IndexedStruct;
    using IndexedCommonEnumMember = CheckedExpression_Details::IndexedCommonEnumMember;
    using Match = CheckedExpression_Details::Match;
    using EnumVariantArg = CheckedExpression_Details::EnumVariantArg;
    using Call = CheckedExpression_Details::Call;
    using MethodCall = CheckedExpression_Details::MethodCall;
    using NamespacedVar = CheckedExpression_Details::NamespacedVar;
    using Var = CheckedExpression_Details::Var;
    using OptionalNone = CheckedExpression_Details::OptionalNone;
    using OptionalSome = CheckedExpression_Details::OptionalSome;
    using ForcedUnwrap = CheckedExpression_Details::ForcedUnwrap;
    using Block = CheckedExpression_Details::Block;
    using Function = CheckedExpression_Details::Function;
    using Try = CheckedExpression_Details::Try;
    using TryBlock = CheckedExpression_Details::TryBlock;
    using Garbage = CheckedExpression_Details::Garbage;
template<typename V, typename... Args> static auto create(Args&&... args) {
return adopt_nonnull_ref_or_enomem(new (nothrow) CheckedExpression(V(forward<Args>(args)...)));
}
ErrorOr<DeprecatedString> debug_description() const;
bool can_throw() const;
utility::Span span() const;
JaktInternal::Optional<types::NumberConstant> to_number_constant(NonnullRefPtr<types::CheckedProgram> const program) const;
types::TypeId type() const;
types::BlockControlFlow control_flow() const;
bool is_mutable(NonnullRefPtr<types::CheckedProgram> const program) const;
};
struct CheckedField {
  public:
types::VarId variable_id;JaktInternal::Optional<NonnullRefPtr<typename types::CheckedExpression>> default_value;JaktInternal::Optional<NonnullRefPtr<typename parser::ParsedExpression>> default_value_expression;CheckedField(types::VarId a_variable_id, JaktInternal::Optional<NonnullRefPtr<typename types::CheckedExpression>> a_default_value, JaktInternal::Optional<NonnullRefPtr<typename parser::ParsedExpression>> a_default_value_expression);

ErrorOr<DeprecatedString> debug_description() const;
};namespace SafetyMode_Details {
struct Safe {
};
struct Unsafe {
};
}
struct SafetyMode : public Variant<SafetyMode_Details::Safe, SafetyMode_Details::Unsafe> {
using Variant<SafetyMode_Details::Safe, SafetyMode_Details::Unsafe>::Variant;
    using Safe = SafetyMode_Details::Safe;
    using Unsafe = SafetyMode_Details::Unsafe;
ErrorOr<DeprecatedString> debug_description() const;
};
class FunctionGenerics : public RefCounted<FunctionGenerics>, public Weakable<FunctionGenerics> {
  public:
virtual ~FunctionGenerics() = default;
types::ScopeId base_scope_id;JaktInternal::DynamicArray<types::CheckedParameter> base_params;JaktInternal::DynamicArray<types::FunctionGenericParameter> params;JaktInternal::DynamicArray<JaktInternal::DynamicArray<types::TypeId>> specializations;protected:
explicit FunctionGenerics(types::ScopeId&& a_base_scope_id, JaktInternal::DynamicArray<types::CheckedParameter>&& a_base_params, JaktInternal::DynamicArray<types::FunctionGenericParameter>&& a_params, JaktInternal::DynamicArray<JaktInternal::DynamicArray<types::TypeId>>&& a_specializations);
public:
static ErrorOr<NonnullRefPtr<FunctionGenerics>> create(types::ScopeId base_scope_id, JaktInternal::DynamicArray<types::CheckedParameter> base_params, JaktInternal::DynamicArray<types::FunctionGenericParameter> params, JaktInternal::DynamicArray<JaktInternal::DynamicArray<types::TypeId>> specializations);

bool is_specialized_for_types(JaktInternal::DynamicArray<types::TypeId> const types) const;
ErrorOr<DeprecatedString> debug_description() const;
};namespace CheckedCapture_Details {
struct ByValue {
DeprecatedString name;
utility::Span span;
template<typename _MemberT0, typename _MemberT1>
ByValue(_MemberT0&& member_0, _MemberT1&& member_1):
name{ forward<_MemberT0>(member_0)},
span{ forward<_MemberT1>(member_1)}
{}
};
struct ByReference {
DeprecatedString name;
utility::Span span;
template<typename _MemberT0, typename _MemberT1>
ByReference(_MemberT0&& member_0, _MemberT1&& member_1):
name{ forward<_MemberT0>(member_0)},
span{ forward<_MemberT1>(member_1)}
{}
};
struct ByMutableReference {
DeprecatedString name;
utility::Span span;
template<typename _MemberT0, typename _MemberT1>
ByMutableReference(_MemberT0&& member_0, _MemberT1&& member_1):
name{ forward<_MemberT0>(member_0)},
span{ forward<_MemberT1>(member_1)}
{}
};
struct AllByReference {
utility::Span span;
template<typename _MemberT0>
AllByReference(_MemberT0&& member_0):
span{ forward<_MemberT0>(member_0)}
{}
};
}
struct CheckedCapture : public Variant<CheckedCapture_Details::ByValue, CheckedCapture_Details::ByReference, CheckedCapture_Details::ByMutableReference, CheckedCapture_Details::AllByReference> {
using Variant<CheckedCapture_Details::ByValue, CheckedCapture_Details::ByReference, CheckedCapture_Details::ByMutableReference, CheckedCapture_Details::AllByReference>::Variant;
    using ByValue = CheckedCapture_Details::ByValue;
    using ByReference = CheckedCapture_Details::ByReference;
    using ByMutableReference = CheckedCapture_Details::ByMutableReference;
    using AllByReference = CheckedCapture_Details::AllByReference;
ErrorOr<DeprecatedString> debug_description() const;
DeprecatedString name() const;
utility::Span span() const;
};
struct TraitId {
  public:
types::ModuleId module;size_t id;bool equals(types::TraitId const other) const;
TraitId(types::ModuleId a_module, size_t a_id);

ErrorOr<DeprecatedString> debug_description() const;
};namespace StructLikeId_Details {
struct Struct{
JaktInternal::Optional<JaktInternal::DynamicArray<types::TypeId>> generic_arguments;
types::StructId value;
template<typename _MemberT0, typename _MemberT1>
Struct(_MemberT0&& member_0, _MemberT1&& member_1):
generic_arguments{ forward<_MemberT0>(member_0)},
value{ forward<_MemberT1>(member_1)}
{}
};
struct Enum{
JaktInternal::Optional<JaktInternal::DynamicArray<types::TypeId>> generic_arguments;
types::EnumId value;
template<typename _MemberT0, typename _MemberT1>
Enum(_MemberT0&& member_0, _MemberT1&& member_1):
generic_arguments{ forward<_MemberT0>(member_0)},
value{ forward<_MemberT1>(member_1)}
{}
};
struct Trait{
JaktInternal::Optional<JaktInternal::DynamicArray<types::TypeId>> generic_arguments;
types::TraitId value;
template<typename _MemberT0, typename _MemberT1>
Trait(_MemberT0&& member_0, _MemberT1&& member_1):
generic_arguments{ forward<_MemberT0>(member_0)},
value{ forward<_MemberT1>(member_1)}
{}
};
}
struct StructLikeId : public Variant<StructLikeId_Details::Struct, StructLikeId_Details::Enum, StructLikeId_Details::Trait> {
using Variant<StructLikeId_Details::Struct, StructLikeId_Details::Enum, StructLikeId_Details::Trait>::Variant;
    using Struct = StructLikeId_Details::Struct;
    using Enum = StructLikeId_Details::Enum;
    using Trait = StructLikeId_Details::Trait;
ErrorOr<DeprecatedString> debug_description() const;
JaktInternal::Optional<JaktInternal::DynamicArray<types::TypeId>> const& generic_arguments() const { switch(this->index()) {case 0 /* Struct */: return this->template get<StructLikeId::Struct>().generic_arguments;
case 1 /* Enum */: return this->template get<StructLikeId::Enum>().generic_arguments;
case 2 /* Trait */: return this->template get<StructLikeId::Trait>().generic_arguments;
default: VERIFY_NOT_REACHED();
}
}
ErrorOr<JaktInternal::DynamicArray<types::TypeId>> generic_parameters(NonnullRefPtr<types::CheckedProgram> const& program) const;
};
namespace BuiltinType_Details {
struct Void {
};
struct Bool {
};
struct U8 {
};
struct U16 {
};
struct U32 {
};
struct U64 {
};
struct I8 {
};
struct I16 {
};
struct I32 {
};
struct I64 {
};
struct F32 {
};
struct F64 {
};
struct Usize {
};
struct JaktString {
};
struct CChar {
};
struct CInt {
};
struct Unknown {
};
struct Never {
};
}
struct BuiltinType : public Variant<BuiltinType_Details::Void, BuiltinType_Details::Bool, BuiltinType_Details::U8, BuiltinType_Details::U16, BuiltinType_Details::U32, BuiltinType_Details::U64, BuiltinType_Details::I8, BuiltinType_Details::I16, BuiltinType_Details::I32, BuiltinType_Details::I64, BuiltinType_Details::F32, BuiltinType_Details::F64, BuiltinType_Details::Usize, BuiltinType_Details::JaktString, BuiltinType_Details::CChar, BuiltinType_Details::CInt, BuiltinType_Details::Unknown, BuiltinType_Details::Never> {
using Variant<BuiltinType_Details::Void, BuiltinType_Details::Bool, BuiltinType_Details::U8, BuiltinType_Details::U16, BuiltinType_Details::U32, BuiltinType_Details::U64, BuiltinType_Details::I8, BuiltinType_Details::I16, BuiltinType_Details::I32, BuiltinType_Details::I64, BuiltinType_Details::F32, BuiltinType_Details::F64, BuiltinType_Details::Usize, BuiltinType_Details::JaktString, BuiltinType_Details::CChar, BuiltinType_Details::CInt, BuiltinType_Details::Unknown, BuiltinType_Details::Never>::Variant;
    using Void = BuiltinType_Details::Void;
    using Bool = BuiltinType_Details::Bool;
    using U8 = BuiltinType_Details::U8;
    using U16 = BuiltinType_Details::U16;
    using U32 = BuiltinType_Details::U32;
    using U64 = BuiltinType_Details::U64;
    using I8 = BuiltinType_Details::I8;
    using I16 = BuiltinType_Details::I16;
    using I32 = BuiltinType_Details::I32;
    using I64 = BuiltinType_Details::I64;
    using F32 = BuiltinType_Details::F32;
    using F64 = BuiltinType_Details::F64;
    using Usize = BuiltinType_Details::Usize;
    using JaktString = BuiltinType_Details::JaktString;
    using CChar = BuiltinType_Details::CChar;
    using CInt = BuiltinType_Details::CInt;
    using Unknown = BuiltinType_Details::Unknown;
    using Never = BuiltinType_Details::Never;
ErrorOr<DeprecatedString> debug_description() const;
size_t id() const;
};
struct CheckedVarDecl {
  public:
DeprecatedString name;bool is_mutable;utility::Span span;types::TypeId type_id;CheckedVarDecl(DeprecatedString a_name, bool a_is_mutable, utility::Span a_span, types::TypeId a_type_id);

ErrorOr<DeprecatedString> debug_description() const;
};namespace Type_Details {
struct Void {
};
struct Bool {
};
struct U8 {
};
struct U16 {
};
struct U32 {
};
struct U64 {
};
struct I8 {
};
struct I16 {
};
struct I32 {
};
struct I64 {
};
struct F32 {
};
struct F64 {
};
struct Usize {
};
struct JaktString {
};
struct CChar {
};
struct CInt {
};
struct Unknown {
};
struct Never {
};
struct TypeVariable {
DeprecatedString name;
JaktInternal::DynamicArray<types::TypeId> trait_implementations;
template<typename _MemberT0, typename _MemberT1>
TypeVariable(_MemberT0&& member_0, _MemberT1&& member_1):
name{ forward<_MemberT0>(member_0)},
trait_implementations{ forward<_MemberT1>(member_1)}
{}
};
struct GenericInstance {
types::StructId id;
JaktInternal::DynamicArray<types::TypeId> args;
template<typename _MemberT0, typename _MemberT1>
GenericInstance(_MemberT0&& member_0, _MemberT1&& member_1):
id{ forward<_MemberT0>(member_0)},
args{ forward<_MemberT1>(member_1)}
{}
};
struct GenericEnumInstance {
types::EnumId id;
JaktInternal::DynamicArray<types::TypeId> args;
template<typename _MemberT0, typename _MemberT1>
GenericEnumInstance(_MemberT0&& member_0, _MemberT1&& member_1):
id{ forward<_MemberT0>(member_0)},
args{ forward<_MemberT1>(member_1)}
{}
};
struct GenericTraitInstance {
types::TraitId id;
JaktInternal::DynamicArray<types::TypeId> args;
template<typename _MemberT0, typename _MemberT1>
GenericTraitInstance(_MemberT0&& member_0, _MemberT1&& member_1):
id{ forward<_MemberT0>(member_0)},
args{ forward<_MemberT1>(member_1)}
{}
};
struct GenericResolvedType {
types::StructId id;
JaktInternal::DynamicArray<types::TypeId> args;
template<typename _MemberT0, typename _MemberT1>
GenericResolvedType(_MemberT0&& member_0, _MemberT1&& member_1):
id{ forward<_MemberT0>(member_0)},
args{ forward<_MemberT1>(member_1)}
{}
};
struct Struct{
types::StructId value;
template<typename _MemberT0>
Struct(_MemberT0&& member_0):
value{ forward<_MemberT0>(member_0)}
{}
};
struct Enum{
types::EnumId value;
template<typename _MemberT0>
Enum(_MemberT0&& member_0):
value{ forward<_MemberT0>(member_0)}
{}
};
struct RawPtr{
types::TypeId value;
template<typename _MemberT0>
RawPtr(_MemberT0&& member_0):
value{ forward<_MemberT0>(member_0)}
{}
};
struct Trait{
types::TraitId value;
template<typename _MemberT0>
Trait(_MemberT0&& member_0):
value{ forward<_MemberT0>(member_0)}
{}
};
struct Reference{
types::TypeId value;
template<typename _MemberT0>
Reference(_MemberT0&& member_0):
value{ forward<_MemberT0>(member_0)}
{}
};
struct MutableReference{
types::TypeId value;
template<typename _MemberT0>
MutableReference(_MemberT0&& member_0):
value{ forward<_MemberT0>(member_0)}
{}
};
struct Function {
JaktInternal::DynamicArray<types::TypeId> params;
bool can_throw;
types::TypeId return_type_id;
types::FunctionId pseudo_function_id;
template<typename _MemberT0, typename _MemberT1, typename _MemberT2, typename _MemberT3>
Function(_MemberT0&& member_0, _MemberT1&& member_1, _MemberT2&& member_2, _MemberT3&& member_3):
params{ forward<_MemberT0>(member_0)},
can_throw{ forward<_MemberT1>(member_1)},
return_type_id{ forward<_MemberT2>(member_2)},
pseudo_function_id{ forward<_MemberT3>(member_3)}
{}
};
struct Self {
};
}
struct Type : public Variant<Type_Details::Void, Type_Details::Bool, Type_Details::U8, Type_Details::U16, Type_Details::U32, Type_Details::U64, Type_Details::I8, Type_Details::I16, Type_Details::I32, Type_Details::I64, Type_Details::F32, Type_Details::F64, Type_Details::Usize, Type_Details::JaktString, Type_Details::CChar, Type_Details::CInt, Type_Details::Unknown, Type_Details::Never, Type_Details::TypeVariable, Type_Details::GenericInstance, Type_Details::GenericEnumInstance, Type_Details::GenericTraitInstance, Type_Details::GenericResolvedType, Type_Details::Struct, Type_Details::Enum, Type_Details::RawPtr, Type_Details::Trait, Type_Details::Reference, Type_Details::MutableReference, Type_Details::Function, Type_Details::Self>, public RefCounted<Type> {
using Variant<Type_Details::Void, Type_Details::Bool, Type_Details::U8, Type_Details::U16, Type_Details::U32, Type_Details::U64, Type_Details::I8, Type_Details::I16, Type_Details::I32, Type_Details::I64, Type_Details::F32, Type_Details::F64, Type_Details::Usize, Type_Details::JaktString, Type_Details::CChar, Type_Details::CInt, Type_Details::Unknown, Type_Details::Never, Type_Details::TypeVariable, Type_Details::GenericInstance, Type_Details::GenericEnumInstance, Type_Details::GenericTraitInstance, Type_Details::GenericResolvedType, Type_Details::Struct, Type_Details::Enum, Type_Details::RawPtr, Type_Details::Trait, Type_Details::Reference, Type_Details::MutableReference, Type_Details::Function, Type_Details::Self>::Variant;
    using Void = Type_Details::Void;
    using Bool = Type_Details::Bool;
    using U8 = Type_Details::U8;
    using U16 = Type_Details::U16;
    using U32 = Type_Details::U32;
    using U64 = Type_Details::U64;
    using I8 = Type_Details::I8;
    using I16 = Type_Details::I16;
    using I32 = Type_Details::I32;
    using I64 = Type_Details::I64;
    using F32 = Type_Details::F32;
    using F64 = Type_Details::F64;
    using Usize = Type_Details::Usize;
    using JaktString = Type_Details::JaktString;
    using CChar = Type_Details::CChar;
    using CInt = Type_Details::CInt;
    using Unknown = Type_Details::Unknown;
    using Never = Type_Details::Never;
    using TypeVariable = Type_Details::TypeVariable;
    using GenericInstance = Type_Details::GenericInstance;
    using GenericEnumInstance = Type_Details::GenericEnumInstance;
    using GenericTraitInstance = Type_Details::GenericTraitInstance;
    using GenericResolvedType = Type_Details::GenericResolvedType;
    using Struct = Type_Details::Struct;
    using Enum = Type_Details::Enum;
    using RawPtr = Type_Details::RawPtr;
    using Trait = Type_Details::Trait;
    using Reference = Type_Details::Reference;
    using MutableReference = Type_Details::MutableReference;
    using Function = Type_Details::Function;
    using Self = Type_Details::Self;
template<typename V, typename... Args> static auto create(Args&&... args) {
return adopt_nonnull_ref_or_enomem(new (nothrow) Type(V(forward<Args>(args)...)));
}
ErrorOr<DeprecatedString> debug_description() const;
bool equals(NonnullRefPtr<typename types::Type> const rhs) const;
i64 get_bits() const;
i64 specificity(NonnullRefPtr<types::CheckedProgram> const program, i64 const base_specificity) const;
bool is_concrete() const;
bool is_builtin() const;
ErrorOr<types::TypeId> flip_signedness() const;
u64 max() const;
DeprecatedString constructor_name() const;
i64 min() const;
bool is_signed() const;
};
}
} // namespace Jakt
template<>struct Jakt::Formatter<Jakt::types::ModuleId> : Jakt::Formatter<Jakt::StringView>{
Jakt::ErrorOr<void> format(Jakt::FormatBuilder& builder, Jakt::types::ModuleId const& value) {
JaktInternal::PrettyPrint::ScopedEnable pretty_print_enable { m_alternative_form };Jakt::ErrorOr<void> format_error = Jakt::Formatter<Jakt::StringView>::format(builder, MUST(value.debug_description()));return format_error;}
};
namespace Jakt {
} // namespace Jakt
template<>struct Jakt::Formatter<Jakt::types::StructId> : Jakt::Formatter<Jakt::StringView>{
Jakt::ErrorOr<void> format(Jakt::FormatBuilder& builder, Jakt::types::StructId const& value) {
JaktInternal::PrettyPrint::ScopedEnable pretty_print_enable { m_alternative_form };Jakt::ErrorOr<void> format_error = Jakt::Formatter<Jakt::StringView>::format(builder, MUST(value.debug_description()));return format_error;}
};
namespace Jakt {
} // namespace Jakt
template<>struct Jakt::Formatter<Jakt::types::VarId> : Jakt::Formatter<Jakt::StringView>{
Jakt::ErrorOr<void> format(Jakt::FormatBuilder& builder, Jakt::types::VarId const& value) {
JaktInternal::PrettyPrint::ScopedEnable pretty_print_enable { m_alternative_form };Jakt::ErrorOr<void> format_error = Jakt::Formatter<Jakt::StringView>::format(builder, MUST(value.debug_description()));return format_error;}
};
namespace Jakt {
} // namespace Jakt
template<>struct Jakt::Formatter<Jakt::types::FieldRecord> : Jakt::Formatter<Jakt::StringView>{
Jakt::ErrorOr<void> format(Jakt::FormatBuilder& builder, Jakt::types::FieldRecord const& value) {
JaktInternal::PrettyPrint::ScopedEnable pretty_print_enable { m_alternative_form };Jakt::ErrorOr<void> format_error = Jakt::Formatter<Jakt::StringView>::format(builder, MUST(value.debug_description()));return format_error;}
};
namespace Jakt {
} // namespace Jakt
template<>struct Jakt::Formatter<Jakt::types::TypeId> : Jakt::Formatter<Jakt::StringView>{
Jakt::ErrorOr<void> format(Jakt::FormatBuilder& builder, Jakt::types::TypeId const& value) {
JaktInternal::PrettyPrint::ScopedEnable pretty_print_enable { m_alternative_form };Jakt::ErrorOr<void> format_error = Jakt::Formatter<Jakt::StringView>::format(builder, MUST(value.debug_description()));return format_error;}
};
namespace Jakt {
} // namespace Jakt
template<>struct Jakt::Formatter<Jakt::types::CheckedTypeCast> : Jakt::Formatter<Jakt::StringView>{
Jakt::ErrorOr<void> format(Jakt::FormatBuilder& builder, Jakt::types::CheckedTypeCast const& value) {
JaktInternal::PrettyPrint::ScopedEnable pretty_print_enable { m_alternative_form };Jakt::ErrorOr<void> format_error = Jakt::Formatter<Jakt::StringView>::format(builder, MUST(value.debug_description()));return format_error;}
};
namespace Jakt {
} // namespace Jakt
template<>struct Jakt::Formatter<Jakt::types::EnumId> : Jakt::Formatter<Jakt::StringView>{
Jakt::ErrorOr<void> format(Jakt::FormatBuilder& builder, Jakt::types::EnumId const& value) {
JaktInternal::PrettyPrint::ScopedEnable pretty_print_enable { m_alternative_form };Jakt::ErrorOr<void> format_error = Jakt::Formatter<Jakt::StringView>::format(builder, MUST(value.debug_description()));return format_error;}
};
namespace Jakt {
} // namespace Jakt
template<>struct Jakt::Formatter<Jakt::types::CheckedEnumVariant> : Jakt::Formatter<Jakt::StringView>{
Jakt::ErrorOr<void> format(Jakt::FormatBuilder& builder, Jakt::types::CheckedEnumVariant const& value) {
JaktInternal::PrettyPrint::ScopedEnable pretty_print_enable { m_alternative_form };Jakt::ErrorOr<void> format_error = Jakt::Formatter<Jakt::StringView>::format(builder, MUST(value.debug_description()));return format_error;}
};
namespace Jakt {
} // namespace Jakt
template<>struct Jakt::Formatter<Jakt::types::CheckedUnaryOperator> : Jakt::Formatter<Jakt::StringView>{
Jakt::ErrorOr<void> format(Jakt::FormatBuilder& builder, Jakt::types::CheckedUnaryOperator const& value) {
JaktInternal::PrettyPrint::ScopedEnable pretty_print_enable { m_alternative_form };Jakt::ErrorOr<void> format_error = Jakt::Formatter<Jakt::StringView>::format(builder, MUST(value.debug_description()));return format_error;}
};
namespace Jakt {
} // namespace Jakt
template<>struct Jakt::Formatter<Jakt::types::BlockControlFlow> : Jakt::Formatter<Jakt::StringView>{
Jakt::ErrorOr<void> format(Jakt::FormatBuilder& builder, Jakt::types::BlockControlFlow const& value) {
JaktInternal::PrettyPrint::ScopedEnable pretty_print_enable { m_alternative_form };Jakt::ErrorOr<void> format_error = Jakt::Formatter<Jakt::StringView>::format(builder, MUST(value.debug_description()));return format_error;}
};
namespace Jakt {
} // namespace Jakt
template<>struct Jakt::Formatter<Jakt::types::ResolvedNamespace> : Jakt::Formatter<Jakt::StringView>{
Jakt::ErrorOr<void> format(Jakt::FormatBuilder& builder, Jakt::types::ResolvedNamespace const& value) {
JaktInternal::PrettyPrint::ScopedEnable pretty_print_enable { m_alternative_form };Jakt::ErrorOr<void> format_error = Jakt::Formatter<Jakt::StringView>::format(builder, MUST(value.debug_description()));return format_error;}
};
namespace Jakt {
} // namespace Jakt
template<>struct Jakt::Formatter<Jakt::types::NumberConstant> : Jakt::Formatter<Jakt::StringView>{
Jakt::ErrorOr<void> format(Jakt::FormatBuilder& builder, Jakt::types::NumberConstant const& value) {
JaktInternal::PrettyPrint::ScopedEnable pretty_print_enable { m_alternative_form };Jakt::ErrorOr<void> format_error = Jakt::Formatter<Jakt::StringView>::format(builder, MUST(value.debug_description()));return format_error;}
};
namespace Jakt {
} // namespace Jakt
template<>struct Jakt::Formatter<Jakt::types::ScopeId> : Jakt::Formatter<Jakt::StringView>{
Jakt::ErrorOr<void> format(Jakt::FormatBuilder& builder, Jakt::types::ScopeId const& value) {
JaktInternal::PrettyPrint::ScopedEnable pretty_print_enable { m_alternative_form };Jakt::ErrorOr<void> format_error = Jakt::Formatter<Jakt::StringView>::format(builder, MUST(value.debug_description()));return format_error;}
};
namespace Jakt {
} // namespace Jakt
template<>struct Jakt::Formatter<Jakt::types::CheckedNamespace> : Jakt::Formatter<Jakt::StringView>{
Jakt::ErrorOr<void> format(Jakt::FormatBuilder& builder, Jakt::types::CheckedNamespace const& value) {
JaktInternal::PrettyPrint::ScopedEnable pretty_print_enable { m_alternative_form };Jakt::ErrorOr<void> format_error = Jakt::Formatter<Jakt::StringView>::format(builder, MUST(value.debug_description()));return format_error;}
};
namespace Jakt {
} // namespace Jakt
template<>struct Jakt::Formatter<Jakt::types::CheckedStruct> : Jakt::Formatter<Jakt::StringView>{
Jakt::ErrorOr<void> format(Jakt::FormatBuilder& builder, Jakt::types::CheckedStruct const& value) {
JaktInternal::PrettyPrint::ScopedEnable pretty_print_enable { m_alternative_form };Jakt::ErrorOr<void> format_error = Jakt::Formatter<Jakt::StringView>::format(builder, MUST(value.debug_description()));return format_error;}
};
namespace Jakt {
} // namespace Jakt
template<>struct Jakt::Formatter<Jakt::types::FunctionGenericParameterKind> : Jakt::Formatter<Jakt::StringView>{
Jakt::ErrorOr<void> format(Jakt::FormatBuilder& builder, Jakt::types::FunctionGenericParameterKind const& value) {
JaktInternal::PrettyPrint::ScopedEnable pretty_print_enable { m_alternative_form };Jakt::ErrorOr<void> format_error = Jakt::Formatter<Jakt::StringView>::format(builder, MUST(value.debug_description()));return format_error;}
};
namespace Jakt {
} // namespace Jakt
template<>struct Jakt::Formatter<Jakt::types::MaybeResolvedScope> : Jakt::Formatter<Jakt::StringView>{
Jakt::ErrorOr<void> format(Jakt::FormatBuilder& builder, Jakt::types::MaybeResolvedScope const& value) {
JaktInternal::PrettyPrint::ScopedEnable pretty_print_enable { m_alternative_form };Jakt::ErrorOr<void> format_error = Jakt::Formatter<Jakt::StringView>::format(builder, MUST(value.debug_description()));return format_error;}
};
namespace Jakt {
} // namespace Jakt
template<>struct Jakt::Formatter<Jakt::types::CheckedEnumVariantBinding> : Jakt::Formatter<Jakt::StringView>{
Jakt::ErrorOr<void> format(Jakt::FormatBuilder& builder, Jakt::types::CheckedEnumVariantBinding const& value) {
JaktInternal::PrettyPrint::ScopedEnable pretty_print_enable { m_alternative_form };Jakt::ErrorOr<void> format_error = Jakt::Formatter<Jakt::StringView>::format(builder, MUST(value.debug_description()));return format_error;}
};
namespace Jakt {
} // namespace Jakt
template<>struct Jakt::Formatter<Jakt::types::CheckedBlock> : Jakt::Formatter<Jakt::StringView>{
Jakt::ErrorOr<void> format(Jakt::FormatBuilder& builder, Jakt::types::CheckedBlock const& value) {
JaktInternal::PrettyPrint::ScopedEnable pretty_print_enable { m_alternative_form };Jakt::ErrorOr<void> format_error = Jakt::Formatter<Jakt::StringView>::format(builder, MUST(value.debug_description()));return format_error;}
};
namespace Jakt {
} // namespace Jakt
template<>struct Jakt::Formatter<Jakt::types::CheckedVisibility> : Jakt::Formatter<Jakt::StringView>{
Jakt::ErrorOr<void> format(Jakt::FormatBuilder& builder, Jakt::types::CheckedVisibility const& value) {
JaktInternal::PrettyPrint::ScopedEnable pretty_print_enable { m_alternative_form };Jakt::ErrorOr<void> format_error = Jakt::Formatter<Jakt::StringView>::format(builder, MUST(value.debug_description()));return format_error;}
};
namespace Jakt {
} // namespace Jakt
template<>struct Jakt::Formatter<Jakt::types::CheckedVariable> : Jakt::Formatter<Jakt::StringView>{
Jakt::ErrorOr<void> format(Jakt::FormatBuilder& builder, Jakt::types::CheckedVariable const& value) {
JaktInternal::PrettyPrint::ScopedEnable pretty_print_enable { m_alternative_form };Jakt::ErrorOr<void> format_error = Jakt::Formatter<Jakt::StringView>::format(builder, MUST(value.debug_description()));return format_error;}
};
namespace Jakt {
} // namespace Jakt
template<>struct Jakt::Formatter<Jakt::types::CheckedParameter> : Jakt::Formatter<Jakt::StringView>{
Jakt::ErrorOr<void> format(Jakt::FormatBuilder& builder, Jakt::types::CheckedParameter const& value) {
JaktInternal::PrettyPrint::ScopedEnable pretty_print_enable { m_alternative_form };Jakt::ErrorOr<void> format_error = Jakt::Formatter<Jakt::StringView>::format(builder, MUST(value.debug_description()));return format_error;}
};
namespace Jakt {
} // namespace Jakt
template<>struct Jakt::Formatter<Jakt::types::FunctionId> : Jakt::Formatter<Jakt::StringView>{
Jakt::ErrorOr<void> format(Jakt::FormatBuilder& builder, Jakt::types::FunctionId const& value) {
JaktInternal::PrettyPrint::ScopedEnable pretty_print_enable { m_alternative_form };Jakt::ErrorOr<void> format_error = Jakt::Formatter<Jakt::StringView>::format(builder, MUST(value.debug_description()));return format_error;}
};
namespace Jakt {
} // namespace Jakt
template<>struct Jakt::Formatter<Jakt::types::Value> : Jakt::Formatter<Jakt::StringView>{
Jakt::ErrorOr<void> format(Jakt::FormatBuilder& builder, Jakt::types::Value const& value) {
JaktInternal::PrettyPrint::ScopedEnable pretty_print_enable { m_alternative_form };Jakt::ErrorOr<void> format_error = Jakt::Formatter<Jakt::StringView>::format(builder, MUST(value.debug_description()));return format_error;}
};
namespace Jakt {
} // namespace Jakt
template<>struct Jakt::Formatter<Jakt::types::ValueImpl> : Jakt::Formatter<Jakt::StringView>{
Jakt::ErrorOr<void> format(Jakt::FormatBuilder& builder, Jakt::types::ValueImpl const& value) {
JaktInternal::PrettyPrint::ScopedEnable pretty_print_enable { m_alternative_form };Jakt::ErrorOr<void> format_error = Jakt::Formatter<Jakt::StringView>::format(builder, MUST(value.debug_description()));return format_error;}
};
namespace Jakt {
} // namespace Jakt
template<>struct Jakt::Formatter<Jakt::types::CheckedFunction> : Jakt::Formatter<Jakt::StringView>{
Jakt::ErrorOr<void> format(Jakt::FormatBuilder& builder, Jakt::types::CheckedFunction const& value) {
JaktInternal::PrettyPrint::ScopedEnable pretty_print_enable { m_alternative_form };Jakt::ErrorOr<void> format_error = Jakt::Formatter<Jakt::StringView>::format(builder, MUST(value.debug_description()));return format_error;}
};
namespace Jakt {
} // namespace Jakt
template<>struct Jakt::Formatter<Jakt::types::Module> : Jakt::Formatter<Jakt::StringView>{
Jakt::ErrorOr<void> format(Jakt::FormatBuilder& builder, Jakt::types::Module const& value) {
JaktInternal::PrettyPrint::ScopedEnable pretty_print_enable { m_alternative_form };Jakt::ErrorOr<void> format_error = Jakt::Formatter<Jakt::StringView>::format(builder, MUST(value.debug_description()));return format_error;}
};
namespace Jakt {
} // namespace Jakt
template<>struct Jakt::Formatter<Jakt::types::StringLiteral> : Jakt::Formatter<Jakt::StringView>{
Jakt::ErrorOr<void> format(Jakt::FormatBuilder& builder, Jakt::types::StringLiteral const& value) {
JaktInternal::PrettyPrint::ScopedEnable pretty_print_enable { m_alternative_form };Jakt::ErrorOr<void> format_error = Jakt::Formatter<Jakt::StringView>::format(builder, MUST(value.debug_description()));return format_error;}
};
namespace Jakt {
} // namespace Jakt
template<>struct Jakt::Formatter<Jakt::types::CheckedMatchBody> : Jakt::Formatter<Jakt::StringView>{
Jakt::ErrorOr<void> format(Jakt::FormatBuilder& builder, Jakt::types::CheckedMatchBody const& value) {
JaktInternal::PrettyPrint::ScopedEnable pretty_print_enable { m_alternative_form };Jakt::ErrorOr<void> format_error = Jakt::Formatter<Jakt::StringView>::format(builder, MUST(value.debug_description()));return format_error;}
};
namespace Jakt {
} // namespace Jakt
template<>struct Jakt::Formatter<Jakt::types::CheckedMatchCase> : Jakt::Formatter<Jakt::StringView>{
Jakt::ErrorOr<void> format(Jakt::FormatBuilder& builder, Jakt::types::CheckedMatchCase const& value) {
JaktInternal::PrettyPrint::ScopedEnable pretty_print_enable { m_alternative_form };Jakt::ErrorOr<void> format_error = Jakt::Formatter<Jakt::StringView>::format(builder, MUST(value.debug_description()));return format_error;}
};
namespace Jakt {
} // namespace Jakt
template<>struct Jakt::Formatter<Jakt::types::CheckedGenericParameter> : Jakt::Formatter<Jakt::StringView>{
Jakt::ErrorOr<void> format(Jakt::FormatBuilder& builder, Jakt::types::CheckedGenericParameter const& value) {
JaktInternal::PrettyPrint::ScopedEnable pretty_print_enable { m_alternative_form };Jakt::ErrorOr<void> format_error = Jakt::Formatter<Jakt::StringView>::format(builder, MUST(value.debug_description()));return format_error;}
};
namespace Jakt {
} // namespace Jakt
template<>struct Jakt::Formatter<Jakt::types::CheckedStatement> : Jakt::Formatter<Jakt::StringView>{
Jakt::ErrorOr<void> format(Jakt::FormatBuilder& builder, Jakt::types::CheckedStatement const& value) {
JaktInternal::PrettyPrint::ScopedEnable pretty_print_enable { m_alternative_form };Jakt::ErrorOr<void> format_error = Jakt::Formatter<Jakt::StringView>::format(builder, MUST(value.debug_description()));return format_error;}
};
namespace Jakt {
} // namespace Jakt
template<>struct Jakt::Formatter<Jakt::types::Scope> : Jakt::Formatter<Jakt::StringView>{
Jakt::ErrorOr<void> format(Jakt::FormatBuilder& builder, Jakt::types::Scope const& value) {
JaktInternal::PrettyPrint::ScopedEnable pretty_print_enable { m_alternative_form };Jakt::ErrorOr<void> format_error = Jakt::Formatter<Jakt::StringView>::format(builder, MUST(value.debug_description()));return format_error;}
};
namespace Jakt {
} // namespace Jakt
template<>struct Jakt::Formatter<Jakt::types::CheckedProgram> : Jakt::Formatter<Jakt::StringView>{
Jakt::ErrorOr<void> format(Jakt::FormatBuilder& builder, Jakt::types::CheckedProgram const& value) {
JaktInternal::PrettyPrint::ScopedEnable pretty_print_enable { m_alternative_form };Jakt::ErrorOr<void> format_error = Jakt::Formatter<Jakt::StringView>::format(builder, MUST(value.debug_description()));return format_error;}
};
namespace Jakt {
} // namespace Jakt
template<>struct Jakt::Formatter<Jakt::types::CheckedCall> : Jakt::Formatter<Jakt::StringView>{
Jakt::ErrorOr<void> format(Jakt::FormatBuilder& builder, Jakt::types::CheckedCall const& value) {
JaktInternal::PrettyPrint::ScopedEnable pretty_print_enable { m_alternative_form };Jakt::ErrorOr<void> format_error = Jakt::Formatter<Jakt::StringView>::format(builder, MUST(value.debug_description()));return format_error;}
};
namespace Jakt {
} // namespace Jakt
template<>struct Jakt::Formatter<Jakt::types::LoadedModule> : Jakt::Formatter<Jakt::StringView>{
Jakt::ErrorOr<void> format(Jakt::FormatBuilder& builder, Jakt::types::LoadedModule const& value) {
JaktInternal::PrettyPrint::ScopedEnable pretty_print_enable { m_alternative_form };Jakt::ErrorOr<void> format_error = Jakt::Formatter<Jakt::StringView>::format(builder, MUST(value.debug_description()));return format_error;}
};
namespace Jakt {
} // namespace Jakt
template<>struct Jakt::Formatter<Jakt::types::FunctionGenericParameter> : Jakt::Formatter<Jakt::StringView>{
Jakt::ErrorOr<void> format(Jakt::FormatBuilder& builder, Jakt::types::FunctionGenericParameter const& value) {
JaktInternal::PrettyPrint::ScopedEnable pretty_print_enable { m_alternative_form };Jakt::ErrorOr<void> format_error = Jakt::Formatter<Jakt::StringView>::format(builder, MUST(value.debug_description()));return format_error;}
};
namespace Jakt {
} // namespace Jakt
template<>struct Jakt::Formatter<Jakt::types::CheckedEnum> : Jakt::Formatter<Jakt::StringView>{
Jakt::ErrorOr<void> format(Jakt::FormatBuilder& builder, Jakt::types::CheckedEnum const& value) {
JaktInternal::PrettyPrint::ScopedEnable pretty_print_enable { m_alternative_form };Jakt::ErrorOr<void> format_error = Jakt::Formatter<Jakt::StringView>::format(builder, MUST(value.debug_description()));return format_error;}
};
namespace Jakt {
} // namespace Jakt
template<>struct Jakt::Formatter<Jakt::types::GenericInferences> : Jakt::Formatter<Jakt::StringView>{
Jakt::ErrorOr<void> format(Jakt::FormatBuilder& builder, Jakt::types::GenericInferences const& value) {
JaktInternal::PrettyPrint::ScopedEnable pretty_print_enable { m_alternative_form };Jakt::ErrorOr<void> format_error = Jakt::Formatter<Jakt::StringView>::format(builder, MUST(value.debug_description()));return format_error;}
};
namespace Jakt {
} // namespace Jakt
template<>struct Jakt::Formatter<Jakt::types::CheckedTrait> : Jakt::Formatter<Jakt::StringView>{
Jakt::ErrorOr<void> format(Jakt::FormatBuilder& builder, Jakt::types::CheckedTrait const& value) {
JaktInternal::PrettyPrint::ScopedEnable pretty_print_enable { m_alternative_form };Jakt::ErrorOr<void> format_error = Jakt::Formatter<Jakt::StringView>::format(builder, MUST(value.debug_description()));return format_error;}
};
namespace Jakt {
} // namespace Jakt
template<>struct Jakt::Formatter<Jakt::types::CheckedNumericConstant> : Jakt::Formatter<Jakt::StringView>{
Jakt::ErrorOr<void> format(Jakt::FormatBuilder& builder, Jakt::types::CheckedNumericConstant const& value) {
JaktInternal::PrettyPrint::ScopedEnable pretty_print_enable { m_alternative_form };Jakt::ErrorOr<void> format_error = Jakt::Formatter<Jakt::StringView>::format(builder, MUST(value.debug_description()));return format_error;}
};
namespace Jakt {
} // namespace Jakt
template<>struct Jakt::Formatter<Jakt::types::CheckedStringLiteral> : Jakt::Formatter<Jakt::StringView>{
Jakt::ErrorOr<void> format(Jakt::FormatBuilder& builder, Jakt::types::CheckedStringLiteral const& value) {
JaktInternal::PrettyPrint::ScopedEnable pretty_print_enable { m_alternative_form };Jakt::ErrorOr<void> format_error = Jakt::Formatter<Jakt::StringView>::format(builder, MUST(value.debug_description()));return format_error;}
};
namespace Jakt {
} // namespace Jakt
template<>struct Jakt::Formatter<Jakt::types::CheckedExpression> : Jakt::Formatter<Jakt::StringView>{
Jakt::ErrorOr<void> format(Jakt::FormatBuilder& builder, Jakt::types::CheckedExpression const& value) {
JaktInternal::PrettyPrint::ScopedEnable pretty_print_enable { m_alternative_form };Jakt::ErrorOr<void> format_error = Jakt::Formatter<Jakt::StringView>::format(builder, MUST(value.debug_description()));return format_error;}
};
namespace Jakt {
} // namespace Jakt
template<>struct Jakt::Formatter<Jakt::types::CheckedField> : Jakt::Formatter<Jakt::StringView>{
Jakt::ErrorOr<void> format(Jakt::FormatBuilder& builder, Jakt::types::CheckedField const& value) {
JaktInternal::PrettyPrint::ScopedEnable pretty_print_enable { m_alternative_form };Jakt::ErrorOr<void> format_error = Jakt::Formatter<Jakt::StringView>::format(builder, MUST(value.debug_description()));return format_error;}
};
namespace Jakt {
} // namespace Jakt
template<>struct Jakt::Formatter<Jakt::types::SafetyMode> : Jakt::Formatter<Jakt::StringView>{
Jakt::ErrorOr<void> format(Jakt::FormatBuilder& builder, Jakt::types::SafetyMode const& value) {
JaktInternal::PrettyPrint::ScopedEnable pretty_print_enable { m_alternative_form };Jakt::ErrorOr<void> format_error = Jakt::Formatter<Jakt::StringView>::format(builder, MUST(value.debug_description()));return format_error;}
};
namespace Jakt {
} // namespace Jakt
template<>struct Jakt::Formatter<Jakt::types::FunctionGenerics> : Jakt::Formatter<Jakt::StringView>{
Jakt::ErrorOr<void> format(Jakt::FormatBuilder& builder, Jakt::types::FunctionGenerics const& value) {
JaktInternal::PrettyPrint::ScopedEnable pretty_print_enable { m_alternative_form };Jakt::ErrorOr<void> format_error = Jakt::Formatter<Jakt::StringView>::format(builder, MUST(value.debug_description()));return format_error;}
};
namespace Jakt {
} // namespace Jakt
template<>struct Jakt::Formatter<Jakt::types::CheckedCapture> : Jakt::Formatter<Jakt::StringView>{
Jakt::ErrorOr<void> format(Jakt::FormatBuilder& builder, Jakt::types::CheckedCapture const& value) {
JaktInternal::PrettyPrint::ScopedEnable pretty_print_enable { m_alternative_form };Jakt::ErrorOr<void> format_error = Jakt::Formatter<Jakt::StringView>::format(builder, MUST(value.debug_description()));return format_error;}
};
namespace Jakt {
} // namespace Jakt
template<>struct Jakt::Formatter<Jakt::types::TraitId> : Jakt::Formatter<Jakt::StringView>{
Jakt::ErrorOr<void> format(Jakt::FormatBuilder& builder, Jakt::types::TraitId const& value) {
JaktInternal::PrettyPrint::ScopedEnable pretty_print_enable { m_alternative_form };Jakt::ErrorOr<void> format_error = Jakt::Formatter<Jakt::StringView>::format(builder, MUST(value.debug_description()));return format_error;}
};
namespace Jakt {
} // namespace Jakt
template<>struct Jakt::Formatter<Jakt::types::StructLikeId> : Jakt::Formatter<Jakt::StringView>{
Jakt::ErrorOr<void> format(Jakt::FormatBuilder& builder, Jakt::types::StructLikeId const& value) {
JaktInternal::PrettyPrint::ScopedEnable pretty_print_enable { m_alternative_form };Jakt::ErrorOr<void> format_error = Jakt::Formatter<Jakt::StringView>::format(builder, MUST(value.debug_description()));return format_error;}
};
namespace Jakt {
} // namespace Jakt
template<>struct Jakt::Formatter<Jakt::types::BuiltinType> : Jakt::Formatter<Jakt::StringView>{
Jakt::ErrorOr<void> format(Jakt::FormatBuilder& builder, Jakt::types::BuiltinType const& value) {
JaktInternal::PrettyPrint::ScopedEnable pretty_print_enable { m_alternative_form };Jakt::ErrorOr<void> format_error = Jakt::Formatter<Jakt::StringView>::format(builder, MUST(value.debug_description()));return format_error;}
};
namespace Jakt {
} // namespace Jakt
template<>struct Jakt::Formatter<Jakt::types::CheckedVarDecl> : Jakt::Formatter<Jakt::StringView>{
Jakt::ErrorOr<void> format(Jakt::FormatBuilder& builder, Jakt::types::CheckedVarDecl const& value) {
JaktInternal::PrettyPrint::ScopedEnable pretty_print_enable { m_alternative_form };Jakt::ErrorOr<void> format_error = Jakt::Formatter<Jakt::StringView>::format(builder, MUST(value.debug_description()));return format_error;}
};
namespace Jakt {
} // namespace Jakt
template<>struct Jakt::Formatter<Jakt::types::Type> : Jakt::Formatter<Jakt::StringView>{
Jakt::ErrorOr<void> format(Jakt::FormatBuilder& builder, Jakt::types::Type const& value) {
JaktInternal::PrettyPrint::ScopedEnable pretty_print_enable { m_alternative_form };Jakt::ErrorOr<void> format_error = Jakt::Formatter<Jakt::StringView>::format(builder, MUST(value.debug_description()));return format_error;}
};
namespace Jakt {
} // namespace Jakt
