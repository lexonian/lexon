/* memory management whitebox test - %MEM */

int main() {

	puts("Hello, mtrac!");

	char *c = strdup(";-)");
	free(c);

	mtrac_verbose = true;
	mtrac_check();

	puts("done.");
}
