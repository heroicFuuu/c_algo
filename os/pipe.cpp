// pipe_demo.cpp
#include <cstring>
#include <iostream>
#include <unistd.h>

int main() {
    int fd[2]; // fd[0]=read, fd[1]=write
    std::cout << "fd[0] : " << fd[0] << ", fd[1] : " << fd[1] << std::endl;
    if (pipe(fd) == -1)
        return 1;
    std::cout << "fd[0] : " << fd[0] << ", fd[1] : " << fd[1] << std::endl;

    pid_t pid = fork();
    if (pid == 0) {
        // child: writer
        close(fd[0]); // close read end
        const char* msg = "hello from child";

        while (1) {
            char ch = getchar();
            // if child dont send message the parent process will block
            // if (ch == '\n')
            //     std::cout << std::endl;
            // else
            //     std::cout << ch << " ";
            if (ch == 'q')
                break;
        }

        write(fd[1], msg, std::strlen(msg));
        close(fd[1]); // close wirte end
    } else {
        // parent: reader
        close(fd[1]);    // close wirte end
        char buf[128]{}; // close read end
        ssize_t n = read(fd[0], buf, sizeof(buf) - 1);
        if (n > 0)
            std::cout << "parent got: " << buf << "\n";
        close(fd[0]);
    }
}
