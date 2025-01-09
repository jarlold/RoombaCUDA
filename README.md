# Genetic Algorithm Roombas: Now CUDA Friendly!
The main goal of this repository is to re-create the effects
of [this repository](https://github.com/jarlold/RoombaSim) but 
in C++ and using a CUDA friendly architecture, so that I can
parallelize my Roomba and search WAAAY more. Once I've caught
up with the Java version I may experiment with PPO, although
maybe by then I'll be sick of Roombas and will move onto a
different problem.

# Some Extra Goals
C++ is famous for being a nightmare. I think it will be fun to try in vain to
fix this issue. So throughout this project I am going to try and:
- Write my code with as little `malloc` and friends as possible. This will still
  be a lot because CUDA demands it.
- Write thing in such a way as to avoid namespaces and header files. Yeah that's
  right.
- Like all good C++ devs, I will pretend I'm writing in C.
- Never use templates until they fix the many compiler problems around
  templates.
- Try to write operating system and CPU architecture indifferent code.
- Keep thing simple.
