#include <gtest/gtest.h>
#include "string_soma.h"

TEST (Soma, PosNum){
    EXPECT_EQ (5, soma_string("3,2\n"));
    EXPECT_EQ (3, soma_string("1,2\n"));
    EXPECT_EQ (6, soma_string("3,2,1\n"));
}

TEST (Valido, LimiteLinha){
    EXPECT_EQ (3, soma_string("\n1,2\n"));
    EXPECT_EQ (6, soma_string("1,2,3\n"));
    EXPECT_EQ (10, soma_string("1,2,3\n,4\n"));
    EXPECT_EQ (6, soma_string("1\n,2\n,3\n"));
}

TEST(Soma, ManyLines){
    EXPECT_EQ (3, soma_string("1\n,2\n"));
    EXPECT_EQ (3, soma_string("1\n\n\n,2\n"));
    EXPECT_EQ (3, soma_string("1\n\n\n,\n\n\n2\n"));
}


//testes falhos

TEST (Invalido, LimiteLinha){
    EXPECT_EQ (-1, soma_string("1,2,3,4\n"));
}

TEST (Invalido, SingNum){
    EXPECT_EQ (-1, soma_string("1,\n"));
    EXPECT_EQ (-1, soma_string(",2\n"));
}

TEST (Invalido, Virgulas){
    EXPECT_EQ(-1, soma_string("1,,2\n"));
    EXPECT_EQ (-1, soma_string(",\n"));
}

TEST (Invalido, DelimFalso){
    EXPECT_EQ(-1, soma_string("1;2\n"));
}

TEST (Invalido, SemFim){
    EXPECT_EQ (-1, soma_string("1,2"));
}

TEST (Invalido, Espaco){
    EXPECT_EQ (-1, soma_string("1,2 \n"));
}

TEST (Invalido, NumNegativo){
    EXPECT_EQ (-1, soma_string("1,2,-3\n"));
    EXPECT_EQ (-1, soma_string("-1,2\n"));
    EXPECT_EQ (-1, soma_string("-1,-2\n"));
    EXPECT_EQ (-1, soma_string("1,-2\n"));
    EXPECT_EQ (-1, soma_string("1\n,-2\n"));
}

TEST (Ignorar, MaiorMil){
    EXPECT_EQ (1, soma_string("1,2000\n"));
    EXPECT_EQ (3, soma_string("3,5000\n"));
    EXPECT_EQ (5, soma_string("3000,5\n"));
    EXPECT_EQ (3, soma_string("3\n,5000\n"));
    EXPECT_EQ (5, soma_string("3\n,2\n,5000\n"));

}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}