#include <iostream>
#include <string>
#include <thread>
#include <vector>
#include "md5.hpp"
#include "timer.hpp"
#include "io.hpp"

const int CHUNK { 100 }, THREADS { 2 };

int main (int argc, char* argv []) {
  bool part2 { argc == 2 };
  std::string input { io::as_string (std::cin) };
  std::vector <std::thread> threads;
  std::mutex printLock;
  auto task = [&] (int tid) {
    for (int index { CHUNK * tid }, off { 0 } ; true; printLock.lock(), index += CHUNK * THREADS, printLock.unlock())
      for (int i { 1 }; i <= CHUNK ; ++i)
        if (off = md5 (input + std::to_string (index + i)).find_first_not_of ('0'), (part2 && off >= 6) || (!part2 && off >= 5))
          printLock.lock(), std::cout << (index + i) << std::endl, exit (0);
  };
  for (int t { 0 }; t < THREADS; ++t)
    threads.emplace_back (task, t);
  for (auto & t : threads)
    t.join();
  return 0;
}
