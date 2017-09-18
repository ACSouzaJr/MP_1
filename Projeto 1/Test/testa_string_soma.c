#include <gtest/gtest.h>
#include "string_soma.h"

TEST (Valido, Delimitador){
    EXPECT_EQ(8, soma_string("//[;]\n2,3;3\n"));
    EXPECT_EQ(9, soma_string("//[**]\n2,4\n**3\n"));
    EXPECT_EQ(6, soma_string("//[;]\n1\n\n,2\n\n;3\n"));
    EXPECT_EQ(6, soma_string("//[;]\n\n1,2;3\n"));
    EXPECT_EQ(9, soma_string("//[;]\n1,5;3\n"));
    EXPECT_EQ (1, soma_string("//[;]\n1;2000\n"));
    EXPECT_EQ (1, soma_string("//[;]\n1\n;2000\n"));
    EXPECT_EQ (10, soma_string("//[;][***][&&]\n1;2***3\n&&4\n"));
    EXPECT_EQ (5, soma_string("//[;]\n2;3\n"));
    EXPECT_EQ (-1, soma_string("//[;]\n2;3"));
    EXPECT_EQ (9, soma_string("//[***]\n2***3***4\n"));
    EXPECT_EQ (-1, soma_string("//[;]2;3\n"));
}

TEST (Invalido, Delimitador){
    EXPECT_EQ (-1, soma_string("//[;]\n1;-2\n"));
}

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

TEST (Invalido, SemFim){
    EXPECT_EQ (-1, soma_string("1,2"));
    EXPECT_EQ (-1, soma_string("1\n,2"));
    EXPECT_EQ (-1, soma_string("1\n,2\n,3"));
}

TEST (Invalido, Espaco){
    EXPECT_EQ (-1, soma_string("1,2 \n"));
}

TEST (Invalido, Virgulas){
    EXPECT_EQ(-1, soma_string("1,,2\n"));
}

TEST (Invalido, DelimFalso){
    EXPECT_EQ(-1, soma_string("1;2\n"));
}


TEST (Invalido, LimiteLinha){
    EXPECT_EQ (-1, soma_string("1,2,3,4\n"));
    EXPECT_EQ (-1, soma_string("1,2\n,3,4,5,6\n"));
}

TEST (Invalido, SingNum){
    EXPECT_EQ (-1, soma_string("1,\n"));
    EXPECT_EQ (-1, soma_string(",2\n"));
    EXPECT_EQ (-1, soma_string(",\n"));
}



int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}