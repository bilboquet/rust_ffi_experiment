#include <stdio.h>
#include <dlfcn.h>

// Note: we may want to #include "rust_ffi.h" and link against the library
// rather than using dlsym


int main() {
    // Load the shared library
    void* handle = dlopen("../rust_ffi/target/debug/librust_ffi.so", RTLD_LAZY);
    if (!handle) {
        fprintf(stderr, "%s\n", dlerror());
        return 1;
    }

    // Clear any existing error
    dlerror();

    // Get the function `add`
    int (*add)(int, int) = dlsym(handle, "add");
    char* error = dlerror();
    if (error != NULL) {
        fprintf(stderr, "%s\n", error);
        return 1;
    }

    // Call the function `add`
    int result = add(35, 34);
    printf("Result from external addition of 35 and 34: %d\n", result);

    // Get the function `concatenate_strings`
    char* (*concatenate_strings)(char*, char*) = dlsym(handle, "concatenate_strings");
    error = dlerror();
    if (error != NULL) {
        fprintf(stderr, "%s\n", error);
        return 1;
    }

    // Call and concat
    char* s1 = "Hello, ";
    char* s2 = "world!";
    char* concatenated = concatenate_strings(s1, s2);
    printf("%s\n", concatenated);

    // Get the function `free_concatenated_string`
    void (*free_concatenated_string)(char*) = dlsym(handle, "free_concatenated_string");
    error = dlerror();
    if (error != NULL) {
        fprintf(stderr, "%s\n", error);
        return 1;
    }

    // Free memory
    free_concatenated_string(concatenated);

    // Close the library
    dlclose(handle);

    return 0;
}