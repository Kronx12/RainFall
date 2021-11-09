int main(int argc, char *argv[]);


/** address: 0x08048480 */
int main(int argc, char *argv[])
{
    char *eax; 		// r24
    char local0; 		// m[esp - 68]

    eax = gets(&local0);
    return eax;
}
