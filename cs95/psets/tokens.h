/* Vinod Halaharvi
 * HUID: 80778287
 * vinod.halaharvi@gmail.com, (904)-200-1070
 * */

#ifndef _PROBLEMSET1
#define _PROBLEMSET1 1

/* type of the token, enum type comes from parser */
typedef int yytokentype; 

/* used only for pretty printing, insignificant otherwise */
typedef struct _token_to_string {
	yytokentype token; 
	char * tok_string; 
} token_to_string;

/* This is defined by me to implement string tokens
 * As mentioned in the class, we cannot rely on '\0' 
 * to represent the end of the string. I am also returning the 
 * string len (yystringlen) which should be used to determine the extent of the string 
 * instead */
extern int yystringlen; 
extern char *yystring; 

/* This struct is used a map datastructure to 
 * convert from token enum type to string for "pretty" printing */
token_to_string token_to_strings[] = { 
	{IDENTIFIER, "IDENTIFIER"},
	{NUMBER, "NUMBER"},
	{STRING, "STRING"},
	{BREAK, "BREAK"},
	{CHAR, "CHAR"},
	{CONTINUE, "CONTINUE"},
	{DO, "DO"},
	{ELSE, "ELSE"},
	{FOR, "FOR"},
	{GOTO, "GOTO"},
	{IF, "IF"},
	{INT, "INT"},
	{LONG, "LONG"},
	{RETURN, "RETURN"},
	{SHORT, "SHORT"},
	{SIGNED, "SIGNED"},
	{UNSIGNED, "UNSIGNED"},
	{VOID, "VOID"},
	{WHILE, "WHILE"},
	{LEFT_PAREN, "LEFT_PAREN"},
	{RIGHT_PAREN, "RIGHT_PAREN"},
	{LEFT_SQUARE, "LEFT_SQUARE"},
	{RIGHT_SQUARE, "RIGHT_SQUARE"},
	{LEFT_CURLY, "LEFT_CURLY"},
	{RIGHT_CURLY, "RIGHT_CURLY"},
	{AMPERSAND, "AMPERSAND"},
	{ASTERISK, "ASTERISK"},
	{CARET, "CARET"},
	{COLON, "COLON"},
	{COMMA, "COMMA"},
	{EQUAL, "EQUAL"},
	{EXCLAMATION, "EXCLAMATION"},
	{GREATER, "GREATER"},
	{LESS, "LESS"},
	{MINUS, "MINUS"},
	{PERCENT, "PERCENT"},
	{PLUS, "PLUS"},
	{SEMICOLON, "SEMICOLON"},
	{SLASH, "SLASH"},
	{QUESTION, "QUESTION"},
	{TILDE, "TILDE"},
	{VBAR, "VBAR"},
	{AMPERSAND_AMPERSAND, "AMPERSAND_AMPERSAND"},
	{AMPERSAND_EQUAL, "AMPERSAND_EQUAL"},
	{ASTERISK_EQUAL, "ASTERISK_EQUAL"},
	{CARET_EQUAL, "CARET_EQUAL"},
	{EQUAL_EQUAL, "EQUAL_EQUAL"},
	{EXCLAMATION_EQUAL, "EXCLAMATION_EQUAL"},
	{GREATER_EQUAL, "GREATER_EQUAL"},
	{GREATER_GREATER, "GREATER_GREATER"},
	{GREATER_GREATER_EQUAL, "GREATER_GREATER_EQUAL"},
	{LESS_EQUAL, "LESS_EQUAL"},
	{LESS_LESS, "LESS_LESS"},
	{LESS_LESS_EQUAL, "LESS_LESS_EQUAL"},
	{MINUS_EQUAL, "MINUS_EQUAL"},
	{MINUS_MINUS, "MINUS_MINUS"},
	{PERCENT_EQUAL, "PERCENT_EQUAL"},
	{PLUS_EQUAL, "PLUS_EQUAL"},
	{PLUS_PLUS, "PLUS_PLUS"},
	{SLASH_EQUAL, "SLASH_EQUAL"},
	{VBAR_EQUAL, "VBAR_EQUAL"},
	{VBAR_VBAR, "VBAR_VBAR"} 
     };


/* Helper function  to print token information by looking
 * into the token_to_strings which is an array of structs.
 * a lookup is made on the token enumerator and the token name is 
 * obtained. For STRING and NUMBER type additional information
 * is obtained from global values. These values are defined in scanner.l and hence scanner.c*/
void  print_token_info(yytokentype token){
	unsigned int i; 
	if (-1 == token) 
		fprintf(stdout, "(ERROR: Unidentified Token at line:%d: %s, '%s')\n", yylineno, "Error", 
				yytext);
	for ( i = 0; i < sizeof(token_to_strings)/sizeof(token_to_string); i++) {
		if(token_to_strings[i].token == token) {
			/* is this token a number? */
			if (token == NUMBER) {
				fprintf(stdout, "(<lineno=%d>, <token_type=%s>, <token_text='%s'>, <token_value=%ld>)\n", \
					yylineno, token_to_strings[i].tok_string, yytext, yylval->data.number.value); 
			} else if (token == STRING) {
				/* if this token is a string then print using yystringlen and yystring global variables */
				char * temp = (char *) malloc(sizeof(char) * yystringlen + 1); 
				strncpy(temp, yystring, yystringlen); 
				fprintf(stdout, "(<lineno=%d>, <token_type=%s>, <token_text='%s'>)\n", \
					yylineno, token_to_strings[i].tok_string, temp); 
					free(temp);
			} else {
				fprintf(stdout, "(<lineno=%d>, <token_type=%s>, <token_text='%s'>)\n", \
					yylineno, token_to_strings[i].tok_string, yytext); 
			}
		}
	}
}
#endif
