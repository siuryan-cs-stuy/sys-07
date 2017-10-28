#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>

// Print array
void print_array(int nums[]) {
  int i = 0;
  for (; i < 10; i++) {
    printf("nums[%d]: %d\n", i, nums[i]);
  }
}

int main() {

  int fd = open("/dev/random", O_RDONLY);
  int nums[10];
  int nums2[10];
  
  read(fd, nums, sizeof(nums));
  close(fd);
  
  printf("Generating random numbers...\n");
  print_array(nums);

  printf("\nWriting numbers to file...\n\n");

  // Create and Write
  fd = open("foo", O_CREAT | O_WRONLY, 0644);
  write(fd, nums, sizeof(nums));
  close(fd);
  
  printf("Reading numbers from file...\n\n");

  // Read
  fd = open("foo", O_RDONLY);
  read(fd, nums2, sizeof(nums2));
  close(fd);
    
  printf("Verification that written values are the same:\n");
  print_array(nums2);
  
  return 0;
}
