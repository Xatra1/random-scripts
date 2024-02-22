// Header inclusions
#include <stdio.h>
#include <sys/stat.h> //For mkdir func

void encrypt(FILE *Original, FILE *Encrypted, FILE *Key)
{
  int encryptionkey, i;
  char realtextholder, encryptedtextholder;
  Original = fopen("original.txt", "r");
  Key = fopen("key.txt", "r");
  if (Original != NULL)
  {
    if (Key != NULL)
    {
      fscanf(Key, "%d", &encryptionkey);
      fseek(Original, 0L, SEEK_END);
      int res = ftell(Original);
      fclose(Original);
      Original = fopen("original.txt", "r");
      Encrypted = fopen("./results/cryptic.txt", "w");
      int progress = 0;
      for (i = 0; i < res; i++)
      {
        printf("\e[?25l");
        fread(&realtextholder, sizeof(char), 1, Original);
        encryptedtextholder = realtextholder + encryptionkey;
        fwrite(&encryptedtextholder, sizeof(char), 1, Encrypted);
        ++progress;
        printf("\rProgress: %d bytes out of %d bytes encrypted.", progress, res);
      }
      printf("\e[?25h");
      printf("\n");
      printf("Done!\n\a");
      fclose(Original);
      fclose(Key);
      fclose(Encrypted);
    }
    else
    {
      printf("You need to create a file named key.txt with the encryption key you wish to use, and place it in the same directory as this program.\n");
    }
  }
  else
  {
    printf("You need to create a file named output.txt with the string you want to encrypt, and place it in the same directory as this program.\n");
  }
}

void decrypt(FILE *Encrypted, FILE *NewOriginal, FILE *Key)
{
  int encryptionkey, i;
  char passwordreader, realtextholder;
  Encrypted = fopen("./results/cryptic.txt", "r");
  Key = fopen("key.txt", "r");
  if (Encrypted != NULL)
  {
    if (Key != NULL)
    {
      NewOriginal = fopen("./results/decrypted.txt", "w");
      fscanf(Key, "%d", &encryptionkey);
      fseek(Encrypted, 0L, SEEK_END);
      int res = ftell(Encrypted);
      fclose(Encrypted);
      Encrypted = fopen("./results/cryptic.txt", "r");
      int progress = 0;
      for (i = 0; i < res; i++)
      {
        printf("\e[?25l");
        fread(&passwordreader, sizeof(char), 1, Encrypted);
        realtextholder = passwordreader - encryptionkey;
        fwrite(&realtextholder, sizeof(char), 1, NewOriginal);
        ++progress;
        printf("\rProgress: %d bytes out of %d bytes decrypted.", progress, res);
      }
      printf("\e[?25h");
      printf("\n");
      printf("Done!\n\a");
      fclose(Encrypted);
      fclose(NewOriginal);
      fclose(Key);
    }
    else
    {
      printf("You are missing the required encryption key. Please make a file with the name 'key.txt' with the key you want to use for decryption, and palce it in the same directory as this program.\n");
    }
  }
  else
  {
    printf("You do not have a file that needs decrypted. Please make a file named 'cryptic.txt' with the string you wish to decrypt, and place it in the 'results' directory.");
  }
}

int main(FILE *Original, FILE *Encrypted, FILE *Key)
{
  FILE *MyOriginalFile, *MyEncryptedFile, *MyKeyFile, *MyNewOriginalFile;
  char answer;
  printf("Do you wish to encrypt or decrypt? (e/d/c):\n");
  scanf("%c*", &answer);
  switch (answer)
  {
  case 'e':
    mkdir("results", 0700);
    encrypt(MyOriginalFile, MyEncryptedFile, MyKeyFile);
    break;
  case 'd':
    mkdir("results", 0700);
    decrypt(MyEncryptedFile, MyNewOriginalFile, MyKeyFile);
    break;
  case 'c':
    printf("Cancelled.\n");
    break;
  }
  return 0;
}
