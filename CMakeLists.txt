project(TP3)

set(CMAKE_C_STANDARD 99)

set(SOURCE_FILES main.c arbre.c arbre.h pile.c pile.h helpers.h dico.c dico.h)
add_executable(TP3 ${SOURCE_FILES})

set(TEST_SOURCE_FILES tests.c tests.h cutest.h arbre.c arbre.h pile.c pile.h dico.c dico.h)
add_executable(TP3_TEST ${TEST_SOURCE_FILES})
