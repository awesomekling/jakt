#pragma once
#include <lib.h>
#ifdef _WIN32
extern "C" __cdecl int SetConsoleOutputCP(unsigned int code_page);
const unsigned int CP_UTF8 = 65001;
#endif
namespace Jakt {
namespace jakt__prelude__iteration {
}
namespace jakt__prelude__string {
}
namespace jakt__prelude__prelude {
}
namespace jakt__arguments {
struct ArgsParser;
}
namespace jakt__platform {
struct Target;



ErrorOr<JaktInternal::DynamicArray<DeprecatedString>> add_to_each(JaktInternal::DynamicArray<DeprecatedString> const strings, DeprecatedString const prefix, DeprecatedString const suffix);

JaktInternal::Optional<size_t> last_namespace_separator(DeprecatedString const name);





ErrorOr<JaktInternal::DynamicArray<DeprecatedString>> platform_import_names();

}
namespace jakt__platform__unknown_path {


}
namespace jakt__path {
struct Path;
}
namespace jakt__platform__unknown_fs {
class DirectoryIterator;
ErrorOr<void> make_directory(DeprecatedString const path);

ErrorOr<DeprecatedString> current_directory();

}
namespace jakt__file_iterator {
class RecursiveFileIterator;
}
namespace utility {
struct Span;
struct FileId;
namespace IterationDecision_Details {
template<typename T>
struct Break;
template<typename T>
struct Continue;
}
template<typename T>
struct IterationDecision;

bool is_ascii_binary(u8 const c);

bool is_ascii_alpha(u8 const c);

template <typename T>
ErrorOr<JaktInternal::DynamicArray<T>> add_arrays(JaktInternal::DynamicArray<T> const a, JaktInternal::DynamicArray<T> const b);

bool is_whitespace(u8 const byte);

template <typename T>
T* null();

ErrorOr<JaktInternal::DynamicArray<DeprecatedString>> prepend_to_each(JaktInternal::DynamicArray<DeprecatedString> const strings, DeprecatedString const prefix);

bool is_ascii_digit(u8 const c);

void todo(DeprecatedString const message);

bool is_ascii_alphanumeric(u8 const c);

ErrorOr<DeprecatedString> interpret_escapes(DeprecatedString const s);

ErrorOr<JaktInternal::DynamicArray<DeprecatedString>> append_to_each(JaktInternal::DynamicArray<DeprecatedString> const strings, DeprecatedString const suffix);

ErrorOr<void> write_to_file(DeprecatedString const data, DeprecatedString const output_filename);

DeprecatedString join(JaktInternal::DynamicArray<DeprecatedString> const strings, DeprecatedString const separator);

bool is_ascii_octdigit(u8 const c);

bool is_ascii_hexdigit(u8 const c);

[[noreturn]] void panic(DeprecatedString const message);

ErrorOr<DeprecatedString> escape_for_quotes(DeprecatedString const s);

template <typename T>
T* allocate(size_t const count);

}
namespace error {
namespace JaktError_Details {
struct Message;
struct MessageWithHint;
}
struct JaktError;

namespace MessageSeverity_Details {
struct Hint;
struct Error;
}
struct MessageSeverity;

ErrorOr<void> print_error_json(DeprecatedString const file_name, error::JaktError const error);

ErrorOr<JaktInternal::DynamicArray<JaktInternal::Tuple<size_t,size_t>>> gather_line_spans(JaktInternal::DynamicArray<u8> const file_contents);

ErrorOr<void> display_message_with_span(error::MessageSeverity const severity, DeprecatedString const file_name, JaktInternal::Optional<JaktInternal::DynamicArray<u8>> const contents, DeprecatedString const message, utility::Span const span);

ErrorOr<void> print_source_line(error::MessageSeverity const severity, JaktInternal::DynamicArray<u8> const file_contents, JaktInternal::Tuple<size_t,size_t> const file_span, utility::Span const error_span, size_t const line_number, size_t const largest_line_number);

ErrorOr<void> display_message_with_span_json(error::MessageSeverity const severity, DeprecatedString const file_name, DeprecatedString const message, utility::Span const span);

ErrorOr<void> print_error(DeprecatedString const file_name, JaktInternal::Optional<JaktInternal::DynamicArray<u8>> const file_contents, error::JaktError const error);

}
namespace compiler {
class Compiler;
}
namespace lexer {
struct Lexer;
namespace LiteralSuffix_Details {
struct None;
struct UZ;
struct U8;
struct U16;
struct U32;
struct U64;
struct I8;
struct I16;
struct I32;
struct I64;
struct F32;
struct F64;
}
struct LiteralSuffix;

namespace Token_Details {
struct SingleQuotedString;
struct SingleQuotedByteString;
struct QuotedString;
struct Number;
struct Identifier;
struct Semicolon;
struct Colon;
struct ColonColon;
struct LParen;
struct RParen;
struct LCurly;
struct RCurly;
struct LSquare;
struct RSquare;
struct PercentSign;
struct Plus;
struct Minus;
struct Equal;
struct PlusEqual;
struct PlusPlus;
struct MinusEqual;
struct MinusMinus;
struct AsteriskEqual;
struct ForwardSlashEqual;
struct PercentSignEqual;
struct NotEqual;
struct DoubleEqual;
struct GreaterThan;
struct GreaterThanOrEqual;
struct LessThan;
struct LessThanOrEqual;
struct LeftArithmeticShift;
struct LeftShift;
struct LeftShiftEqual;
struct RightShift;
struct RightArithmeticShift;
struct RightShiftEqual;
struct Asterisk;
struct Ampersand;
struct AmpersandEqual;
struct AmpersandAmpersand;
struct Pipe;
struct PipeEqual;
struct PipePipe;
struct Caret;
struct CaretEqual;
struct Dollar;
struct Tilde;
struct ForwardSlash;
struct ExclamationPoint;
struct QuestionMark;
struct QuestionMarkQuestionMark;
struct QuestionMarkQuestionMarkEqual;
struct Comma;
struct Dot;
struct DotDot;
struct Eol;
struct Eof;
struct FatArrow;
struct Arrow;
struct And;
struct Anon;
struct As;
struct Boxed;
struct Break;
struct Catch;
struct Class;
struct Continue;
struct Cpp;
struct Defer;
struct Else;
struct Enum;
struct Extern;
struct False;
struct For;
struct Function;
struct Comptime;
struct If;
struct Import;
struct In;
struct Is;
struct Let;
struct Loop;
struct Match;
struct Mut;
struct Namespace;
struct Not;
struct Or;
struct Override;
struct Private;
struct Public;
struct Raw;
struct Return;
struct Restricted;
struct Struct;
struct This;
struct Throw;
struct Throws;
struct True;
struct Try;
struct Unsafe;
struct Virtual;
struct Weak;
struct While;
struct Yield;
struct Guard;
struct Implements;
struct Requires;
struct Trait;
struct Garbage;
}
struct Token;

namespace LiteralPrefix_Details {
struct None;
struct Hexadecimal;
struct Octal;
struct Binary;
}
struct LiteralPrefix;

}
namespace parser {
struct ParsedGenericParameter;
struct ParsedField;
struct EnumVariantPatternArgument;
struct ParsedPatternDefault;
struct ParsedRecord;
struct ParsedExternalTraitImplementation;
struct ParsedFunction;
struct ParsedExternImport;
struct ParsedModuleImport;
struct ParsedVariable;
struct ParsedNameWithGenericParameters;
struct SumEnumVariant;
struct ParsedBlock;
struct ParsedAttributeArgument;
struct ParsedAttribute;
struct ParsedTrait;
struct Parser;
struct ParsedCall;
struct ParsedNamespace;
struct ParsedName;
struct ParsedAlias;
struct ParsedVarDecl;
struct ParsedMethod;
struct ParsedMatchCase;
struct ParsedParameter;
struct ValueEnumVariant;
struct VisibilityRestriction;
namespace IncludeAction_Details {
struct Define;
struct Undefine;
}
struct IncludeAction;

namespace ParsedExpression_Details {
struct Boolean;
struct NumericConstant;
struct QuotedString;
struct SingleQuotedString;
struct SingleQuotedByteString;
struct Call;
struct MethodCall;
struct IndexedTuple;
struct IndexedStruct;
struct Var;
struct IndexedExpression;
struct UnaryOp;
struct BinaryOp;
struct Operator;
struct OptionalSome;
struct OptionalNone;
struct JaktArray;
struct JaktDictionary;
struct Set;
struct JaktTuple;
struct Range;
struct ForcedUnwrap;
struct Match;
struct EnumVariantArg;
struct NamespacedVar;
struct Function;
struct Try;
struct TryBlock;
struct Garbage;
}
struct ParsedExpression;

namespace ImportList_Details {
struct List;
struct All;
}
struct ImportList;

namespace ParsedCapture_Details {
struct ByValue;
struct ByReference;
struct ByMutableReference;
struct AllByReference;
}
struct ParsedCapture;

namespace BinaryOperator_Details {
struct Add;
struct Subtract;
struct Multiply;
struct Divide;
struct Modulo;
struct LessThan;
struct LessThanOrEqual;
struct GreaterThan;
struct GreaterThanOrEqual;
struct Equal;
struct NotEqual;
struct BitwiseAnd;
struct BitwiseXor;
struct BitwiseOr;
struct BitwiseLeftShift;
struct BitwiseRightShift;
struct ArithmeticLeftShift;
struct ArithmeticRightShift;
struct LogicalAnd;
struct LogicalOr;
struct NoneCoalescing;
struct Assign;
struct BitwiseAndAssign;
struct BitwiseOrAssign;
struct BitwiseXorAssign;
struct BitwiseLeftShiftAssign;
struct BitwiseRightShiftAssign;
struct AddAssign;
struct SubtractAssign;
struct MultiplyAssign;
struct ModuloAssign;
struct DivideAssign;
struct NoneCoalescingAssign;
struct Garbage;
}
struct BinaryOperator;

namespace FunctionType_Details {
struct Normal;
struct ImplicitConstructor;
struct ImplicitEnumConstructor;
struct ExternalClassConstructor;
struct Expression;
struct Closure;
}
struct FunctionType;

namespace ParsedStatement_Details {
struct Expression;
struct Defer;
struct UnsafeBlock;
struct DestructuringAssignment;
struct VarDecl;
struct If;
struct Block;
struct Loop;
struct While;
struct For;
struct Break;
struct Continue;
struct Return;
struct Throw;
struct Yield;
struct InlineCpp;
struct Guard;
struct Garbage;
}
struct ParsedStatement;

namespace ParsedMatchPattern_Details {
struct EnumVariant;
struct Expression;
struct CatchAll;
struct Invalid;
}
struct ParsedMatchPattern;

namespace FunctionLinkage_Details {
struct Internal;
struct External;
}
struct FunctionLinkage;

namespace ImportName_Details {
struct Literal;
struct Comptime;
}
struct ImportName;

namespace ParsedMatchBody_Details {
struct Expression;
struct Block;
}
struct ParsedMatchBody;

namespace DefinitionLinkage_Details {
struct Internal;
struct External;
}
struct DefinitionLinkage;

namespace RecordType_Details {
struct Struct;
struct Class;
struct ValueEnum;
struct SumEnum;
struct Garbage;
}
struct RecordType;

namespace Visibility_Details {
struct Public;
struct Private;
struct Restricted;
}
struct Visibility;

namespace ParsedType_Details {
struct Name;
struct NamespacedName;
struct GenericType;
struct JaktArray;
struct Dictionary;
struct JaktTuple;
struct Set;
struct Optional;
struct Reference;
struct MutableReference;
struct RawPtr;
struct WeakPtr;
struct Function;
struct Empty;
}
struct ParsedType;

namespace TypeCast_Details {
struct Fallible;
struct Infallible;
}
struct TypeCast;

namespace NumericConstant_Details {
struct I8;
struct I16;
struct I32;
struct I64;
struct U8;
struct U16;
struct U32;
struct U64;
struct USize;
struct F32;
struct F64;
struct UnknownSigned;
struct UnknownUnsigned;
}
struct NumericConstant;

namespace UnaryOperator_Details {
struct PreIncrement;
struct PostIncrement;
struct PreDecrement;
struct PostDecrement;
struct Negate;
struct Dereference;
struct RawAddress;
struct Reference;
struct MutableReference;
struct LogicalNot;
struct BitwiseNot;
struct TypeCast;
struct Is;
struct IsEnumVariant;
}
struct UnaryOperator;

ErrorOr<utility::Span> merge_spans(utility::Span const start, utility::Span const end);

f32 f64_to_f32(f64 const number);

template <typename T>
T u64_to_float(u64 const number);

}
namespace types {
class FunctionGenerics;
struct CheckedStringLiteral;
struct GenericInferences;
struct CheckedStruct;
class CheckedVariable;
class CheckedProgram;
struct Value;
struct VarId;
struct CheckedParameter;
struct CheckedCall;
struct CheckedVarDecl;
struct CheckedNamespace;
struct CheckedGenericParameter;
struct CheckedBlock;
struct TraitId;
struct FunctionId;
class Module;
class CheckedTrait;
class CheckedFunction;
struct EnumId;
struct StructId;
struct ScopeId;
struct LoadedModule;
struct CheckedEnum;
struct FunctionGenericParameter;
struct ResolvedNamespace;
class Scope;
struct TypeId;
struct FieldRecord;
struct ModuleId;
struct CheckedEnumVariantBinding;
struct CheckedField;
namespace FunctionGenericParameterKind_Details {
struct InferenceGuide;
struct Parameter;
}
struct FunctionGenericParameterKind;

namespace Type_Details {
struct Void;
struct Bool;
struct U8;
struct U16;
struct U32;
struct U64;
struct I8;
struct I16;
struct I32;
struct I64;
struct F32;
struct F64;
struct Usize;
struct JaktString;
struct CChar;
struct CInt;
struct Unknown;
struct Never;
struct TypeVariable;
struct GenericInstance;
struct GenericEnumInstance;
struct GenericTraitInstance;
struct GenericResolvedType;
struct Struct;
struct Enum;
struct RawPtr;
struct Trait;
struct Reference;
struct MutableReference;
struct Function;
struct Self;
}
struct Type;

namespace CheckedMatchBody_Details {
struct Expression;
struct Block;
}
struct CheckedMatchBody;

namespace CheckedStatement_Details {
struct Expression;
struct Defer;
struct DestructuringAssignment;
struct VarDecl;
struct If;
struct Block;
struct Loop;
struct While;
struct Return;
struct Break;
struct Continue;
struct Throw;
struct Yield;
struct InlineCpp;
struct Garbage;
}
struct CheckedStatement;

namespace ValueImpl_Details {
struct Void;
struct Bool;
struct U8;
struct U16;
struct U32;
struct U64;
struct I8;
struct I16;
struct I32;
struct I64;
struct F32;
struct F64;
struct USize;
struct JaktString;
struct StringView;
struct CChar;
struct CInt;
struct Struct;
struct Class;
struct Enum;
struct JaktArray;
struct JaktDictionary;
struct JaktSet;
struct RawPtr;
struct OptionalSome;
struct OptionalNone;
struct JaktTuple;
struct Function;
}
struct ValueImpl;

namespace CheckedEnumVariant_Details {
struct Untyped;
struct Typed;
struct WithValue;
struct StructLike;
}
struct CheckedEnumVariant;

namespace CheckedMatchCase_Details {
struct EnumVariant;
struct Expression;
struct CatchAll;
}
struct CheckedMatchCase;

namespace CheckedTypeCast_Details {
struct Fallible;
struct Infallible;
}
struct CheckedTypeCast;

namespace NumberConstant_Details {
struct Signed;
struct Unsigned;
struct Floating;
}
struct NumberConstant;

namespace CheckedUnaryOperator_Details {
struct PreIncrement;
struct PostIncrement;
struct PreDecrement;
struct PostDecrement;
struct Negate;
struct Dereference;
struct RawAddress;
struct Reference;
struct MutableReference;
struct LogicalNot;
struct BitwiseNot;
struct TypeCast;
struct Is;
struct IsEnumVariant;
}
struct CheckedUnaryOperator;

namespace BlockControlFlow_Details {
struct AlwaysReturns;
struct AlwaysTransfersControl;
struct NeverReturns;
struct MayReturn;
struct PartialAlwaysReturns;
struct PartialAlwaysTransfersControl;
struct PartialNeverReturns;
}
struct BlockControlFlow;

namespace CheckedCapture_Details {
struct ByValue;
struct ByReference;
struct ByMutableReference;
struct AllByReference;
}
struct CheckedCapture;

namespace SafetyMode_Details {
struct Safe;
struct Unsafe;
}
struct SafetyMode;

namespace MaybeResolvedScope_Details {
struct Resolved;
struct Unresolved;
}
struct MaybeResolvedScope;

namespace CheckedExpression_Details {
struct Boolean;
struct NumericConstant;
struct QuotedString;
struct ByteConstant;
struct CharacterConstant;
struct UnaryOp;
struct BinaryOp;
struct JaktTuple;
struct Range;
struct JaktArray;
struct JaktSet;
struct JaktDictionary;
struct IndexedExpression;
struct IndexedDictionary;
struct IndexedTuple;
struct IndexedStruct;
struct IndexedCommonEnumMember;
struct Match;
struct EnumVariantArg;
struct Call;
struct MethodCall;
struct NamespacedVar;
struct Var;
struct OptionalNone;
struct OptionalSome;
struct ForcedUnwrap;
struct Block;
struct Function;
struct Try;
struct TryBlock;
struct Garbage;
}
struct CheckedExpression;

namespace StringLiteral_Details {
struct Static;
}
struct StringLiteral;

namespace StructLikeId_Details {
struct Struct;
struct Enum;
struct Trait;
}
struct StructLikeId;

namespace CheckedVisibility_Details {
struct Public;
struct Private;
struct Restricted;
}
struct CheckedVisibility;

namespace CheckedNumericConstant_Details {
struct I8;
struct I16;
struct I32;
struct I64;
struct U8;
struct U16;
struct U32;
struct U64;
struct USize;
struct F32;
struct F64;
}
struct CheckedNumericConstant;

namespace BuiltinType_Details {
struct Void;
struct Bool;
struct U8;
struct U16;
struct U32;
struct U64;
struct I8;
struct I16;
struct I32;
struct I64;
struct F32;
struct F64;
struct Usize;
struct JaktString;
struct CChar;
struct CInt;
struct Unknown;
struct Never;
}
struct BuiltinType;

types::TypeId builtin(types::BuiltinType const builtin);

types::TypeId void_type_id();

types::TypeId unknown_type_id();

types::TypeId never_type_id();

}
namespace interpreter {
class Interpreter;
class InterpreterScope;
namespace StatementResult_Details {
struct Return;
struct Throw;
struct Yield;
struct Continue;
struct Break;
struct JustValue;
}
struct StatementResult;

namespace ExecutionResult_Details {
struct Return;
struct Throw;
}
struct ExecutionResult;

namespace Deferred_Details {
struct Expression;
struct Statement;
}
struct Deferred;

enum class InterpretError: i32;
ErrorOr<types::Value> cast_value_to_type(types::Value const this_value, types::TypeId const type_id, NonnullRefPtr<interpreter::Interpreter> const interpreter, bool const saturating);

ErrorOr<NonnullRefPtr<typename types::CheckedExpression>> value_to_checked_expression(types::Value const this_value, NonnullRefPtr<interpreter::Interpreter> interpreter);

}
namespace typechecker {
struct TraitImplementationDescriptor;
struct AlreadyImplementedFor;
struct ImportRestrictions;
struct Typechecker;
struct TraitImplCheck;
namespace FunctionMatchResult_Details {
struct MatchSuccess;
struct MatchError;
}
struct FunctionMatchResult;

}
namespace codegen {
struct LineSpan;
struct CodegenDebugInfo;
struct CodeGenerator;
struct ControlFlowState;
namespace AllowedControlExits_Details {
struct Nothing;
struct JustReturn;
struct AtLoop;
}
struct AllowedControlExits;

bool are_loop_exits_allowed(codegen::AllowedControlExits const allowed_control_exits);

bool is_return_allowed(codegen::AllowedControlExits const allowed_control_exits);

}
namespace formatter {
struct FormattedToken;
struct ReflowState;
struct Formatter;
struct Stage0;
namespace BreakablePoint_Details {
struct Paren;
struct Curly;
struct Square;
struct Logical;
}
struct BreakablePoint;

namespace State_Details {
struct Toplevel;
struct Import;
struct ImportList;
struct EntityDeclaration;
struct ParameterList;
struct RestrictionList;
struct EntityDefinition;
struct StatementContext;
struct MatchPattern;
struct VariableDeclaration;
struct GenericCallTypeParams;
struct TypeContext;
struct FunctionTypeContext;
}
struct State;

namespace Entity_Details {
struct Struct;
struct Enum;
struct Namespace;
struct Function;
}
struct Entity;

namespace ExpressionMode_Details {
struct OutsideExpression;
struct BeforeExpressions;
struct AtExpressionStart;
struct InExpression;
}
struct ExpressionMode;

template <typename T>
JaktInternal::Optional<T> collapse(JaktInternal::Optional<JaktInternal::Optional<T>> const x);

template <typename T>
ErrorOr<JaktInternal::DynamicArray<T>> concat(JaktInternal::DynamicArray<T> const xs, T const y);

void bubble_sort(JaktInternal::DynamicArray<DeprecatedString> values);

template <typename T>
ErrorOr<JaktInternal::DynamicArray<T>> init(JaktInternal::DynamicArray<T> const xs);

}
namespace jakt__libc__io {
}
namespace repl {
struct Editor;
struct REPL;
namespace LineResult_Details {
struct Line;
struct Eof;
}
struct LineResult;

DeprecatedString serialize_unary_operation(types::CheckedUnaryOperator const op, DeprecatedString const expr);

ErrorOr<DeprecatedString> serialize_ast_node(NonnullRefPtr<typename types::CheckedExpression> const node);

}
namespace project {
struct Project;
}
namespace ide {
struct JaktSymbol;
namespace Mutability_Details {
struct DoesNotApply;
struct Immutable;
struct Mutable;
}
struct Mutability;

namespace Usage_Details {
struct Variable;
struct Call;
struct Typename;
struct NameSet;
struct EnumVariant;
}
struct Usage;

namespace VarType_Details {
struct Variable;
struct Field;
}
struct VarType;

namespace VarVisibility_Details {
struct DoesNotApply;
struct Public;
struct Private;
struct Restricted;
}
struct VarVisibility;

ErrorOr<ide::JaktSymbol> record_to_symbol(parser::ParsedRecord const record);

ErrorOr<JaktInternal::Optional<DeprecatedString>> find_typename_in_program(NonnullRefPtr<types::CheckedProgram> const program, utility::Span const span);

ErrorOr<JaktInternal::DynamicArray<DeprecatedString>> completions_for_type_id(NonnullRefPtr<types::CheckedProgram> const program, types::TypeId const type_id);

ErrorOr<ide::Usage> get_enum_variant_usage_from_type_id_and_name(NonnullRefPtr<types::CheckedProgram> const program, types::TypeId const type_id, DeprecatedString const name);

ErrorOr<DeprecatedString> get_enum_variant_signature_from_type_id_and_name(NonnullRefPtr<types::CheckedProgram> const program, types::TypeId const type_id, DeprecatedString const name);

ErrorOr<DeprecatedString> get_type_signature(NonnullRefPtr<types::CheckedProgram> const program, types::TypeId const type_id);

ErrorOr<JaktInternal::Optional<ide::Usage>> find_span_in_scope(NonnullRefPtr<types::CheckedProgram> const program, NonnullRefPtr<types::Scope> const scope, utility::Span const span);

ErrorOr<DeprecatedString> get_constructor_signature(NonnullRefPtr<types::CheckedProgram> const program, types::FunctionId const function_id);

ErrorOr<JaktInternal::DynamicArray<DeprecatedString>> find_dot_completions(NonnullRefPtr<types::CheckedProgram> const program, utility::Span const span);

ErrorOr<utility::Span> find_definition_in_program(NonnullRefPtr<types::CheckedProgram> const program, utility::Span const span);

ErrorOr<DeprecatedString> get_var_signature(NonnullRefPtr<types::CheckedProgram> const program, DeprecatedString const name, types::TypeId const var_type_id, ide::Mutability const mutability, ide::VarType const var_type, ide::VarVisibility const visibility, JaktInternal::Optional<types::TypeId> const struct_type_id);

ErrorOr<JaktInternal::DynamicArray<JaktInternal::Tuple<JaktInternal::Optional<DeprecatedString>,types::TypeId>>> enum_variant_fields(NonnullRefPtr<types::CheckedProgram> const program, types::CheckedEnumVariant const checked_enum_variant);

ErrorOr<utility::Span> find_type_definition_in_program(NonnullRefPtr<types::CheckedProgram> const program, utility::Span const span);

ErrorOr<JaktInternal::Optional<ide::Usage>> find_span_in_expression(NonnullRefPtr<types::CheckedProgram> const program, NonnullRefPtr<typename types::CheckedExpression> const expr, utility::Span const span);

ErrorOr<JaktInternal::Optional<ide::Usage>> find_span_in_block(NonnullRefPtr<types::CheckedProgram> const program, types::CheckedBlock const block, utility::Span const span);

ErrorOr<JaktInternal::Optional<ide::Usage>> find_span_in_program(NonnullRefPtr<types::CheckedProgram> const program, utility::Span const span);

ErrorOr<JaktInternal::DynamicArray<DeprecatedString>> find_function_completions_in_scope(NonnullRefPtr<types::Scope> const scope, NonnullRefPtr<types::CheckedProgram> const program);

ErrorOr<JaktInternal::DynamicArray<ide::JaktSymbol>> find_symbols_in_namespace(parser::ParsedNamespace const namespace_);

ErrorOr<JaktInternal::Optional<ide::Usage>> find_span_in_function(NonnullRefPtr<types::CheckedProgram> const program, NonnullRefPtr<types::CheckedFunction> const checked_function, utility::Span const span);

ErrorOr<utility::Span> find_type_definition_for_type_id(NonnullRefPtr<types::CheckedProgram> const program, types::TypeId const type_id, utility::Span const span);

ErrorOr<DeprecatedString> get_enum_variant_signature(NonnullRefPtr<types::CheckedProgram> const program, DeprecatedString const name, types::TypeId const type_id, JaktInternal::DynamicArray<JaktInternal::Tuple<JaktInternal::Optional<DeprecatedString>,types::TypeId>> const variants, JaktInternal::Optional<types::NumberConstant> const number_constant);

ErrorOr<JaktInternal::Optional<ide::Usage>> find_span_in_enum(NonnullRefPtr<types::CheckedProgram> const program, types::CheckedEnum const checked_enum, utility::Span const span);

ErrorOr<ide::JaktSymbol> function_to_symbol(parser::ParsedFunction const function_, DeprecatedString const kind);

ErrorOr<JaktInternal::Optional<ide::Usage>> find_span_in_statement(NonnullRefPtr<types::CheckedProgram> const program, NonnullRefPtr<typename types::CheckedStatement> const statement, utility::Span const span);

ErrorOr<JaktInternal::Optional<ide::Usage>> find_span_in_struct(NonnullRefPtr<types::CheckedProgram> const program, types::CheckedStruct const checked_struct, utility::Span const span);

ErrorOr<DeprecatedString> get_function_signature(NonnullRefPtr<types::CheckedProgram> const program, types::FunctionId const function_id);

}
namespace jakt__platform__unknown_process {
struct Process;
struct ExitPollResult;
ErrorOr<jakt__platform__unknown_process::Process> start_background_process(JaktInternal::DynamicArray<DeprecatedString> const args);

ErrorOr<JaktInternal::Tuple<JaktInternal::Optional<size_t>,jakt__platform__unknown_process::ExitPollResult>> wait_for_some_set_of_processes_that_at_least_includes(JaktInternal::Dictionary<size_t,jakt__platform__unknown_process::Process> const& processes);

ErrorOr<jakt__platform__unknown_process::ExitPollResult> wait_for_process(jakt__platform__unknown_process::Process const& process);

ErrorOr<void> forcefully_kill_process(jakt__platform__unknown_process::Process const& process);

ErrorOr<JaktInternal::Optional<jakt__platform__unknown_process::ExitPollResult>> poll_process_exit(jakt__platform__unknown_process::Process const& process);

}
namespace build {
struct Builder;
struct ParallelExecutionPool;
}
namespace jakt__platform__unknown_compiler {
ErrorOr<JaktInternal::DynamicArray<DeprecatedString>> run_compiler(DeprecatedString const cxx_compiler_path, DeprecatedString const cpp_filename, DeprecatedString const output_filename, DeprecatedString const runtime_path, JaktInternal::DynamicArray<DeprecatedString> const extra_include_paths, JaktInternal::DynamicArray<DeprecatedString> const extra_lib_paths, JaktInternal::DynamicArray<DeprecatedString> const extra_link_libs, bool const optimize, JaktInternal::DynamicArray<DeprecatedString> const extra_compiler_flags);

}
struct FormatRange;
ErrorOr<void> format_output(jakt__path::Path const file_path, JaktInternal::DynamicArray<lexer::Token> const tokens, JaktInternal::Optional<FormatRange> const format_range, bool const format_debug, bool const format_inplace);

ErrorOr<DeprecatedString> indent(size_t const level);

DeprecatedString help();

DeprecatedString usage();

ErrorOr<JaktInternal::Optional<FormatRange>> parse_format_range(DeprecatedString const range, size_t const input_file_length);

template <typename T>
ErrorOr<T> value_or_throw(JaktInternal::Optional<T> const maybe);

} // namespace Jakt
