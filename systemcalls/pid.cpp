#include <bits/stdc++.h>
#include <sys/types.h>
#include <sys/wait.h> // Include the correct header for wait()
using namespace std;

void childProcess(pid_t pid)
{
  cout << "Child Process: " << pid << endl;
}

void parentProcess(pid_t pid)
{
  int status;                                     // Variable to store the status of the child process
  waitpid(pid, &status, 0);                       // Correctly wait for the specific child process
  cout << "Parent process: " << getpid() << endl; // Use getpid() to get the parent's PID
}

int main()
{
  pid_t pid;
  cout << "Starting program..." << endl;
  pid = fork();
  if (pid == 0)
  {
    // Child process
    childProcess(getpid()); // Pass the child's PID
  }
  else if (pid > 0)
  {
    // Parent process
    parentProcess(pid); // Pass the child's PID
  }
  else
  {
    // Fork failed
    cerr << "Fork failed." << endl;
    return 1;
  }

  return 0;
}
