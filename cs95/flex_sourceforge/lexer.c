%x str

%%
	 char string_buf[100];
	 char *string_buf_ptr;
\"      string_buf_ptr = string_buf; BEGIN(str);
<str>\"       { /* saw closing quote - all done */
 BEGIN(INITIAL);
 *string_buf_ptr = '\0';
	 /* return string constant token type and
	  * value to parser
	  */
 }

<str>\n        {
	 /* error - unterminated string constant */
	 /* generate error message */
 }
<str>\\n  *string_buf_ptr++ = '\n';
<str>\\t  *string_buf_ptr++ = '\t';
<str>\\r  *string_buf_ptr++ = '\r';
<str>\\b  *string_buf_ptr++ = '\b';
<str>\\f  *string_buf_ptr++ = '\f';
<str>\\(.|\n)  *string_buf_ptr++ = yytext[1];
<str>[^\\\n\"]+        {
	 char *yptr = yytext;
	 while ( *yptr )
		 *string_buf_ptr++ = *yptr++;
	}
