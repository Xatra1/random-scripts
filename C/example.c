// Header inclusions
#include <stdio.h>
#include <sys/stat.h> //struct on line 16
#include <unistd.h> //rmdir function
#include "funcs.h" //fileread and createbigstr

// Variables, pointers, etc
struct hello
{
  char *str;
  char *bigstr;
};
int age = 400, favNum = 7496;
float dec = 3.5;
const char readonly[] = "I am a read-only variable!";
struct stat st = {0};
// Functions
void main()
{
  printf("Creating file...\n");
  if (stat("./logs", &st) == -1) {
    mkdir("./logs", 0700);
  } else {
    rmdir("./logs");
    mkdir("./logs", 0700);
  }
  FILE *fptr;
  fptr = fopen("./logs/info.txt", "w"); // Create new file and open in write mode
  struct hello h;
  h.str = "Hello World!";
  fprintf(fptr, "%s I am %d years old.\n", h.str, age);
  fprintf(fptr, "My favorite number is %d.\n", favNum);
  int sum = favNum + age;
  fprintf(fptr, "My favorite number plus my age is %d.\n", sum);
  fprintf(fptr, "A float! %f\n", dec);
  fprintf(fptr, "A precise float! %.1f.\n", dec);
  fprintf(fptr, "%s\n", readonly);
  fprintf(fptr, "Size of h.str in memory: %lu\n", sizeof(h.str));
  fprintf(fptr, "Size of age in memory: %lu\n", sizeof(age));
  fprintf(fptr, "Size of favnum in memory: %lu\n", sizeof(favNum));
  fprintf(fptr, "Size of sum in memory: %lu\n", sizeof(sum));
  fprintf(fptr, "Size of dec in memory: %lu\n", sizeof(dec));
  fprintf(fptr, "Size of readonly in memory: %lu\n", sizeof(readonly));
  createbigstr(fptr);
  fclose(fptr);
  fptr = fopen("./logs/info.txt", "r"); // Reopen file in read mode
  fileread(fptr);
}

void createbigstr(FILE *fptr)
{
  struct hello h;
  fprintf(fptr, "Creating h.bigstr...\n");
  h.bigstr = "Hello world! I am a big string! Pretty cool, right?";
  fprintf(fptr, "%s\n", h.bigstr);
  fprintf(fptr, "Size of h.bigstr in memory: %lu\n", sizeof(h.bigstr));
}

int fileread(FILE *fptr)
{
  char answer;
  printf("Would you like to output the file contents to the console? (y/n): ");
  scanf("%c*", &answer);
  switch (answer)
  {
  case 'y':
    char contents[100];
    while (fgets(contents, 100, fptr))
    {
      printf("%s", contents); // Print all contents of the file to the console.
    }
    return 0;
  case 'n':
    return 0;
  }
}
