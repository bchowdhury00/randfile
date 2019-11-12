#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <fcntl.h>
#include <stdlib.h>

int main(){
  int hold[10];
  int fD = open("/dev/random",O_RDWR,0644);
  if (fD < 0){
    printf("%s\n",strerror(errno));
    return 0;
  }
  int read1,read2,write1;
  read1 = read(fD,hold,80);
  if (read1 < 0){
    printf("%s\n",strerror(errno));
    return 0;
  }
  int fD2 = open("newFile.txt",O_CREAT | O_RDWR,0644);
  if (fD2 < 0){
    printf("%s\n",strerror(errno));
    return 0;
  }
  write1 = write(fD2,hold,80);
  if (write1 < 0){
    printf("%s\n",strerror(errno));
    return 0;
  }
  int ans[10];
  read2 = read(fD2,ans,80);
  if (read2 < 0){
    printf("%s\n",strerror(errno));
    return 0;
  }
  int increment;
  printf("Printing integers written from dev/random\n");
  for (increment = 0;increment < 10; increment++){
    printf("%d\n",hold[increment]);
  }

  printf("Printing integers written into second file\n");
  for (increment = 0;increment < 10; increment++){
    printf("%d\n",ans[increment]);
  }
  close(fD);
  close(fD2);
  return 0;
}


