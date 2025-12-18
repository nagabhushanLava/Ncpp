#include <iostream>
#include <unistd.h>
#include <cstring>
using namespace std;

class PipeIPC {
private:
    int fd[2]; // fd[0] = read, fd[1] = write

public:
    PipeIPC() {
        if (pipe(fd) == -1) {
            perror("Pipe creation failed");
            exit(1);
        }
    }

    pid_t createProcess() {
        pid_t pid = fork();
        if (pid < 0) {
            perror("Fork failed");
            exit(1);
        }
        return pid;
    }

    void writeToPipe(const string& msg) {
        close(fd[0]); // Close read end
        write(fd[1], msg.c_str(), msg.size() + 1); // Include null terminator
        close(fd[1]);
    }

    string readFromPipe() {
        close(fd[1]); // Close write end
        char buffer[100];
        read(fd[0], buffer, sizeof(buffer));
        close(fd[0]);
        return string(buffer);
    }
};

int main() {
    PipeIPC ipc;

    pid_t pid = ipc.createProcess();

    if (pid == 0) {
        // Child
        string msg = ipc.readFromPipe();
        cout << "Child received: " << msg << endl;
    } else {
        // Parent
        ipc.writeToPipe("Hello from Parent");
    }

    return 0;
}
