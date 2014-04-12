typedef union {
    char str[256];
}YYSTYPE;

extern YYSTYPE yylval;

enum {
	UNUSED=257,
	ERROR_TOKEN,
	IF,
	ELSE,
	PRINT,
	INPUT,
	ASSIGN,     // assign
	EQUAL,      // test if equal
	CONCAT,     // string-concatenate
	END_STMT,   // end of statement
	OPEN_PAR,   // opening parenthesis
	CLOSE_PAR,  // closing parenthesis
	BEGIN_CS,   // begin compound statement
	END_CS,     // end   compound statement
	ID,         // identifier
	STRING      // string constant
};
