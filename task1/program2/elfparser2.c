#include <stdio.h>
#include <elf.h>
#include <stdlib.h>
#include <stdint.h>

#define FILE_PATH "/home/abdallah/tasks/task2/elfparser.o"  

int main(int argc, char* argv[]) {  

    // Open the file
    FILE* file = fopen(FILE_PATH, "r");
    if (file == NULL) {  // Check if the file was opened successfully
        perror("Error opening file");
        return EXIT_FAILURE;
    }

    // Read ELF header
    Elf64_Ehdr header;
    size_t read_size = fread(&header, sizeof(header), 1, file);
    if (read_size != 1) {  // Check if fread succeeded
        perror("Error reading file");
        fclose(file);
        return EXIT_FAILURE;
    }

    
    printf("ELF Header:\nMagic: ");
    for (int i = 0; i < EI_NIDENT; i++) {  
        printf("%02x ", header.e_ident[i]);
    }
    printf("\n");
    printf("  Class:                             ");
    switch (header.e_ident[EI_CLASS]) {
        case ELFCLASS32: printf("ELF32\n"); break;
        case ELFCLASS64: printf("ELF64\n"); break;
        default: printf("Unknown\n"); break;
    }
    printf("  Data:                              ");
    switch (header.e_ident[EI_DATA]) {
        case ELFDATA2LSB: printf("2's complement, little endian\n"); break;
        case ELFDATA2MSB: printf("2's complement, big endian\n"); break;
        default: printf("Unknown\n"); break;
    }
    printf("  Version:                           %d (current)\n", header.e_ident[EI_VERSION]);
    printf("  OS/ABI:                            ");
    switch (header.e_ident[EI_OSABI]) {
        case ELFOSABI_SYSV: printf("UNIX System V ABI\n"); break;
        case ELFOSABI_LINUX: printf("Linux ABI\n"); break;
        // Add more cases as needed
        default: printf("Unknown\n"); break;
    }
    printf("  Type:                              ");
    switch (header.e_type) {
        case ET_NONE: printf("None\n"); break;
        case ET_REL: printf("Relocatable\n"); break;
        case ET_EXEC: printf("Executable\n"); break;
        case ET_DYN: printf("Shared object\n"); break;
        case ET_CORE: printf("Core\n"); break;
        default: printf("Unknown\n"); break;
    }
    printf("  Machine:                           ");
    switch (header.e_machine) {
        case EM_X86_64: printf("AMD x86-64\n"); break;
        case EM_ARM: printf("ARM\n"); break;
        // Add more cases as needed
        default: printf("Unknown\n"); break;
    }
    printf("  Version:                           0x%x\n", header.e_version);
    printf("  Entry point address:               0x%lx\n", header.e_entry);
    printf("  Start of program headers:          %ld (bytes into file)\n", header.e_phoff);
    printf("  Start of section headers:          %ld (bytes into file)\n", header.e_shoff);
    printf("  Flags:                             0x%x\n", header.e_flags);
    printf("  Size of this header:               %d (bytes)\n", header.e_ehsize);
    printf("  Size of program headers:           %d (bytes)\n", header.e_phentsize);
    printf("  Number of program headers:         %d\n", header.e_phnum);
    printf("  Size of section headers:           %d (bytes)\n", header.e_shentsize);
    printf("  Number of section headers:         %d\n", header.e_shnum);
    printf("  Section header string table index: %d\n", header.e_shstrndx);
    // Close the file
    fclose(file);
    return EXIT_SUCCESS;
}
