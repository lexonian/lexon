/* memory management whitebox test - %MEM %ERR */

int main() {

	puts("Hello, mtrac!");

	char *c = strdup(";-)");

	mtrac_verbose = true;
	mtrac_check();

	puts("done.");
}
