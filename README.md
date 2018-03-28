# structure-build-test

All the files related to a little talk I gave at EPITECH Paris with a friend about writing C code and testing it with the Criterion framework.

## The project

  The project is a little guessing game. The sources are in the `srcs/` and `includes/` directories.

## The tests

  The tests are written using Criterion in the `tests/` folder.

## The build

  There are a few Makefiles in the repo but you shall only use the one at the root of the repository. The revelant targets are :

  * **my_guess** Build the project
  * **tests** Build and run the tests, in verbose mode
  * **clean** Remove the temporary binary files
  * **fclean** What clean does, plus remove the binary
  * **re** What fclean plus my_guess do
