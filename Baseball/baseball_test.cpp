#include "gmock/gmock.h"
#include "baseball.cpp"
#include <string>
#include <iostream>
using std::cout;
using std::string;

using namespace testing;
class BaseballFixture : public testing::Test {
public:
    Baseball game{ "123" };
    void assertIllegalArgument(string guessNumber) {
        try {
            game.guess(guessNumber);
            FAIL();
        }
        catch (exception e) {
            //pass
        }
    }

    void GameStart(string guessNumber, GuessResult expectedGameReuslt) {
        GuessResult result = game.guess(guessNumber);
        EXPECT_EQ(expectedGameReuslt.solved, result.solved);
        EXPECT_EQ(expectedGameReuslt.strikes, result.strikes);
        EXPECT_EQ(expectedGameReuslt.balls, result.balls);
    }
};

TEST_F(BaseballFixture, ThrowExceptionWhenInvalidCase) {
    assertIllegalArgument("12");
    assertIllegalArgument("12s");
    assertIllegalArgument("121");
}

TEST_F(BaseballFixture, ReturnSolvedResultIfMatchedNumber) {
    GuessResult expectedGameReuslt = { true, 3, 0 };
    GameStart("123", expectedGameReuslt);
}

TEST_F(BaseballFixture, Return2S0BResult) {
    GuessResult expectedGameReuslt = { false, 2, 0 };
    GameStart("124", expectedGameReuslt);
}

TEST_F(BaseballFixture, Return1S2BResult) {
    GuessResult expectedGameReuslt = { false, 1, 2 };
    GameStart("132", expectedGameReuslt);
}

TEST_F(BaseballFixture, Return1S1BResult) {
    GuessResult expectedGameReuslt = { false, 1, 1 };
    GameStart("152", expectedGameReuslt);
}

TEST_F(BaseballFixture, Return1S0BResult) {
    GuessResult expectedGameReuslt = { false, 1, 0 };
    GameStart("157", expectedGameReuslt);
}

TEST_F(BaseballFixture, Return1S0BResult2) {
    GuessResult expectedGameReuslt = { false, 1, 0 };
    GameStart("827", expectedGameReuslt);
}


int main() {
    ::testing::InitGoogleMock();
    return RUN_ALL_TESTS();
}