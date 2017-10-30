#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <string.h>
#include <errno.h>

// Print array
void print_array(int nums[]) {
  int i = 0;
  for (; i < 10; i++) {
    printf("nums[%d]: %d\n", i, nums[i]);
  }
}

int main() {

  int fd = open("/dev/random", O_RDONLY);

  if (fd < 0) {
    printf("Error: %s\n", strerror(errno));
    return 0;
  }

  int nums[10];
  int nums2[10];
  
  if (read(fd, nums, sizeof(nums)) < 0) {
    printf("Error: %s\n", strerror(errno));
  }
  if (close(fd) < 0) {
    printf("Error: %s\n", strerror(errno));
  }
  
  printf("Generating random numbers...\n");
  print_array(nums);

  printf("\nWriting numbers to file...\n\n");

  // Create and Write
  fd = open("foo", O_CREAT | O_WRONLY, 0644);

  if (fd < 0) {
    printf("Error: %s\n", strerror(errno));
    return 0;
  }

  if (write(fd, nums, sizeof(nums)) < 0) {
    printf("Error: %s\n", strerror(errno));
  }
  if (close(fd) < 0) {
    printf("Error: %s\n", strerror(errno));
  }
  
  printf("Reading numbers from file...\n\n");

  // Read
  fd = open("foo", O_RDONLY);

  if (fd < 0) {
    printf("Error: %s\n", strerror(errno));
    return 0;
  }

  if (read(fd, nums2, sizeof(nums2)) < 0) {
    printf("Error: %s\n", strerror(errno));
  }
  if (close(fd) < 0) {
    printf("Error: %s\n", strerror(errno));
  }
    
  printf("Verification that written values are the same:\n");
  print_array(nums2);
  
  return 0;
}
