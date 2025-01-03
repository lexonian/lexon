/* memory management whitebox test - %MEM */

int main() {

	puts("Hello, mtrac!");

	char *c = malloc(2);
	mtrac_dump();
	free(c);

	mtrac_check();
	mtrac_stats();
	mtrac_dump();

	puts("done.");
}
