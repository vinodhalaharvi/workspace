%option noyywrap
	int num = 0 ;
%x STRING
%%
\"	{ BEGIN(STRING); }
<STRING>[^"] ECHO;  
<STRING>\"  { BEGIN(INITIAL);  printf(" %d\n", ++num); }
"\n"
.
