#include <unistd.h>
#include <stdio.h>
#include <sys/sendfile.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
int main()
{
    unsigned long word;
    char source[256], destination[256];
    ssize_t nr, nw;
    int pos;
    int fd = open("/home/ubuntu/miho/os_practice/ch2/cc.txt", O_RDONLY | O_CREAT, 0777);
    int fe = open("/home/ubuntu/miho/os_practice/ch2/dd.txt", O_RDWR | O_CREAT, 0777);

    pos = lseek(fd, 0, SEEK_END);
    scanf("%s %s", source, destination);
    nr = read(fd, &word, pos);
    nw = write(fe, &word, pos);

    printf("%s, %s\n", source, destination);
    printf("read: %ld\nwritten:%ld\n", nr, nw);
}
