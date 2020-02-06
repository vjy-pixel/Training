main(){
	char *s = "main() {\n\tchar *s=%c%s%c;\n\t printf(s,34,s,34);\n}\n"; 
	printf(s,34,s,34);
}
