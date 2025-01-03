/* memory management whitebox test - %MEM %ERR */

int main() {

	puts("Hello, mtrac!");

	char *c = strdup(";-)");
	*(c-sizeof(mtrac)) = 0;

	mtrac_check();

	puts("done.");
}
