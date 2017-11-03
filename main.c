#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/stat.h>

int main(){
  
  DIR *dir = opendir(".");
  struct stat buffer;
  struct dirent *file = readdir(dir);

  int total_size = 0;
  while (file){
    stat(file->d_name, &buffer);
    if (file->d_type == DT_DIR) printf("Directory Name: %s \n", file->d_name);
    else printf("File Name: %s \n", file->d_name);
    total_size += buffer.st_size;
    file = readdir(dir);
  }

  closedir(dir);
  printf("\nTotal Size: %d\n",total_size);
}
