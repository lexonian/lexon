/* memory management whitebox test - %MEM %ERR */

int main() {

	puts("Hello, mtrac!");

	char *c = strdup(";-)");
	*(c-sizeof(mtrac)) = 0;
	free(c);

	mtrac_verbose = true;
	mtrac_check();

	puts("done.");
}
