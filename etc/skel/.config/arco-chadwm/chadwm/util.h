/* See LICENSE file for copyright and license details. */

#define MAX(A, B)               ((A) > (B) ? (A) : (B))         // Macro to get the maximum of two values
#define MIN(A, B)               ((A) < (B) ? (A) : (B))         // Macro to get the minimum of two values
#define BETWEEN(X, A, B)        ((A) <= (X) && (X) <= (B))      // Macro to check if a value is between two other values

void die(const char *fmt, ...);                                 // Function to print an error message and exit
void *ecalloc(size_t nmemb, size_t size);                       // Function to allocate memory and check for allocation failure
