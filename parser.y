%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function declarations
void yyerror(const char* s);
int yylex(void);
extern int line_num;
extern FILE *yyin;

// Symbol table structure
typedef struct {
    char* name;
    int type;
    int scope;
    int is_initialized;
    int is_used;
    int is_function;
    int is_parameter;
} Symbol;

#define MAX_SYMBOLS 1000
Symbol symbol_table[MAX_SYMBOLS];
int symbol_count = 0;
int error_count = 0;
void report_error(const char* msg, int line, int col);

// Function to add symbol to table
void add_symbol(char* name, int type, int scope, int is_function) {
    if (symbol_count >= MAX_SYMBOLS) {
        report_error("Symbol table overflow", 0, 0);
        return;
    }
    symbol_table[symbol_count] = (Symbol){
        .name = strdup(name), .type = type, .scope = scope, 
        .is_initialized = 0, .is_used = 0, .is_function = is_function, .is_parameter = 0
    };
    symbol_count++;
}

// Function to find symbol
Symbol* find_symbol(char* name, int scope) {
    for (int i = symbol_count - 1; i >= 0; i--) {
        if (strcmp(symbol_table[i].name, name) == 0 && 
            (symbol_table[i].scope == scope || symbol_table[i].scope < scope)) {
            return &symbol_table[i];
        }
    }
    return NULL;
}

// Function to check for unused variables (but not functions or parameters)
void check_unused_symbols() {
    for (int i = 0; i < symbol_count; i++) {
        if (!symbol_table[i].is_function && !symbol_table[i].is_parameter && !symbol_table[i].is_used)
            report_error("Unused variable", line_num, 0);
    }
}
%}

%union { int int_val; float float_val; char char_val; char* string_val; }

%token <string_val> IDENTIFIER <int_val> INTEGER_LITERAL <float_val> FLOAT_LITERAL 
%token <char_val> CHAR_LITERAL <string_val> STRING_LITERAL

%token INT CHAR VOID FLOAT_TYPE
%token IF ELSE WHILE FOR RETURN STRUCT TYPEDEF CONST STATIC EXTERN SIZEOF
%token PLUS MINUS MULTIPLY DIVIDE MODULO ASSIGN EQUAL NOT_EQUAL
%token LESS LESS_EQUAL GREATER GREATER_EQUAL AND OR NOT
%token BITWISE_AND BITWISE_OR BITWISE_XOR BITWISE_NOT LEFT_SHIFT RIGHT_SHIFT
%token INCREMENT DECREMENT ARROW DOT SEMICOLON COMMA
%token LEFT_PAREN RIGHT_PAREN LEFT_BRACE RIGHT_BRACE LEFT_BRACKET RIGHT_BRACKET
%token COLON QUESTION

%type <int_val> type_specifier expression statement compound_statement declaration
%type <int_val> function_definition external_declaration program declaration_list
%type <int_val> statement_list expression_statement selection_statement
%type <int_val> iteration_statement jump_statement
%type <int_val> assignment_expression logical_or_expression logical_and_expression
%type <int_val> equality_expression relational_expression additive_expression
%type <int_val> multiplicative_expression unary_expression postfix_expression
%type <int_val> primary_expression

%start program

%%

program
    : external_declaration { $$ = $1; }
    | program external_declaration { $$ = $2; }
    ;

external_declaration
    : function_definition { $$ = $1; } | declaration { $$ = $1; }
    ;

type_specifier
    : INT { $$ = 1; } | CHAR { $$ = 2; } | VOID { $$ = 3; } | FLOAT_TYPE { $$ = 4; }
    ;

// Only allow main function
function_definition
    : type_specifier IDENTIFIER LEFT_PAREN RIGHT_PAREN compound_statement {
        if (strcmp($2, "main") != 0) 
            report_error("Only main function is allowed", line_num, 0);
        $$ = $1;
    }
    ;

declaration
    : type_specifier IDENTIFIER SEMICOLON
    {
        // Check for variable redefinition
        Symbol* sym = find_symbol($2, 0);
        if (sym != NULL) {
            report_error("Variable redefinition", line_num, 0);
            // Continue parsing even if variable is redefined
        } else {
            add_symbol($2, $1, 0, 0);  // Add variable
        }
        $$ = $1;
    }
    | type_specifier IDENTIFIER ASSIGN expression SEMICOLON
    {
        Symbol* sym = find_symbol($2, 0);
        if (sym != NULL) {
            report_error("Variable redefinition", line_num, 0);
        } else {
            add_symbol($2, $1, 0, 0);  // Mark as variable
            // Mark the symbol as initialized
            sym = find_symbol($2, 0);
            if (sym) {
                sym->is_initialized = 1;
                sym->is_used = 1;
            }
            
            if ($4 != 0 && $1 != $4) {
                if ($1 == 1 && $4 == 4)      // int = float
                    report_error("Type mismatch: assigning float to int", line_num, 0);
                else if ($1 == 4 && $4 == 1) // float = int, allowed with implicit conversion
                    {}  
                else
                    report_error("Type mismatch in assignment", line_num, 0);
            }
        }
        $$ = $1;
    }
    ;

compound_statement
    : LEFT_BRACE declaration_list statement_list RIGHT_BRACE { $$ = 0; }
    ;

declaration_list
    : declaration { $$ = $1; } | declaration_list declaration { $$ = $2; } | /* empty */ { $$ = 0; }
    ;

statement_list
    : statement { $$ = $1; } | statement_list statement { $$ = $2; } | /* empty */ { $$ = 0; }
    ;

statement
    : expression_statement { $$ = $1; } | compound_statement { $$ = $1; } 
    | selection_statement { $$ = $1; } | iteration_statement { $$ = $1; } | jump_statement { $$ = $1; }
    ;

expression_statement
    : expression SEMICOLON { $$ = $1; } | SEMICOLON { $$ = 0; }
    ;

selection_statement
    : IF LEFT_PAREN expression RIGHT_PAREN statement { $$ = $3; }
    | IF LEFT_PAREN expression RIGHT_PAREN statement ELSE statement { $$ = $3; }
    ;

iteration_statement
    : WHILE LEFT_PAREN expression RIGHT_PAREN statement { $$ = $3; }
    | FOR LEFT_PAREN expression_statement expression_statement expression RIGHT_PAREN statement { $$ = $5; }
    ;

jump_statement
    : RETURN expression SEMICOLON { $$ = $2; } | RETURN SEMICOLON { $$ = 0; }
    ;

expression
    : assignment_expression { $$ = $1; } | expression COMMA assignment_expression { $$ = $3; }
    ;

assignment_expression
    : logical_or_expression { $$ = $1; }
    | IDENTIFIER ASSIGN assignment_expression {
        Symbol* sym = find_symbol($1, 0);
        if (sym == NULL) {
            report_error("Undefined variable", line_num, 0);
        } else {
            if (sym->type != $3 && sym->type != 0 && $3 != 0) {
                if (sym->type == 1 && $3 == 4)      // int = float
                    report_error("Type mismatch: assigning float to int", line_num, 0);
                else if (sym->type == 4 && $3 == 1) // float = int, allowed with implicit conversion
                    {}  
                else
                    report_error("Type mismatch in assignment", line_num, 0);
            }
            sym->is_initialized = 1;
        }
        $$ = $3;
    }
    ;

logical_or_expression
    : logical_and_expression { $$ = $1; }
    | logical_or_expression OR logical_and_expression { $$ = $1; }
    ;

logical_and_expression
    : equality_expression { $$ = $1; }
    | logical_and_expression AND equality_expression { $$ = $1; }
    ;

equality_expression
    : relational_expression { $$ = $1; }
    | equality_expression EQUAL relational_expression { $$ = $1; }
    | equality_expression NOT_EQUAL relational_expression { $$ = $1; }
    ;

relational_expression
    : additive_expression { $$ = $1; }
    | relational_expression LESS additive_expression { $$ = $1; }
    | relational_expression GREATER additive_expression { $$ = $1; }
    | relational_expression LESS_EQUAL additive_expression { $$ = $1; }
    | relational_expression GREATER_EQUAL additive_expression { $$ = $1; }
    ;

additive_expression
    : multiplicative_expression { $$ = $1; }
    | additive_expression PLUS multiplicative_expression { $$ = $1; }
    | additive_expression MINUS multiplicative_expression { $$ = $1; }
    ;

multiplicative_expression
    : unary_expression { $$ = $1; }
    | multiplicative_expression MULTIPLY unary_expression { $$ = $1; }
    | multiplicative_expression DIVIDE unary_expression { $$ = $1; }
    | multiplicative_expression MODULO unary_expression { $$ = $1; }
    ;

unary_expression
    : postfix_expression { $$ = $1; }
    | PLUS unary_expression { $$ = $2; } | MINUS unary_expression { $$ = $2; } 
    | NOT unary_expression { $$ = $2; } | BITWISE_NOT unary_expression { $$ = $2; }
    ;

postfix_expression
    : primary_expression { $$ = $1; }
    | postfix_expression LEFT_BRACKET expression RIGHT_BRACKET { $$ = $1; }
    | postfix_expression LEFT_PAREN RIGHT_PAREN { $$ = $1; }
    | postfix_expression DOT IDENTIFIER { $$ = $1; }
    | postfix_expression ARROW IDENTIFIER { $$ = $1; }
    | postfix_expression INCREMENT { $$ = $1; } | postfix_expression DECREMENT { $$ = $1; }
    ;

primary_expression
    : IDENTIFIER {
        Symbol* sym = find_symbol($1, 0);
        if (sym == NULL) {
            report_error("Undefined variable", line_num, 0);
        } else {
            sym->is_used = 1;
            if (!sym->is_initialized) report_error("Uninitialized variable", line_num, 0);
        }
        $$ = sym ? sym->type : 0;
    }
    | INTEGER_LITERAL { $$ = 1; }  /* INT type */ | FLOAT_LITERAL { $$ = 4; }    /* FLOAT type */
    | CHAR_LITERAL { $$ = 2; }     /* CHAR type */ | STRING_LITERAL { $$ = 2; }   /* CHAR* type */
    | LEFT_PAREN expression RIGHT_PAREN { $$ = $2; }
    ;
%%

void report_error(const char* msg, int line, int col) {
    (void)col;  // Explicitly acknowledge unused parameter
    fprintf(stderr, "Error at line %d: %s\n", line, msg);
    error_count++;
}

void yyerror(const char* s) {
    fprintf(stderr, "Error: %s\n", s);
    error_count++;
}

int main(int argc, char** argv) {
    if (argc > 1 && !(yyin = fopen(argv[1], "r"))) {
        perror(argv[1]); return 1;
    }
    yyparse();
    check_unused_symbols(); // Report unused variables
    return error_count;
}