/* memory management whitebox test - %MEM %ERR */

int main() {

	puts("Hello, mtrac!");

	char *c = strdup(";-)");
	*(c+strlen(c)+1) = 0;
	*(c-sizeof(mtrac)) = 0;
	*(c-1) = 0;

	mtrac_check();

	puts("done.");
}
