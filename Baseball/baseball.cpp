#include <string>
#include <stdexcept>
#include <iostream>
using namespace std;

const int MAX_INPUT_NUM = 3;
 struct GuessResult {
    bool solved;
    int strikes;
    int balls;
};

class Baseball {
public:
    explicit Baseball(const string& qeustion)
        : CorrectNum{ qeustion } {}

    GuessResult guess(const string& guessNumber) {
        assertIllegalArgument(guessNumber);
        GuessResult result = countGuessScore(guessNumber);

        return result;
    }
private:
    string CorrectNum;

    GuessResult countGuessScore(const std::string& guessNumber)
    {
        GuessResult result = { false, 0, 0 };

        result.strikes = countStrike(guessNumber);
        result.balls = countBall(guessNumber);

        if (result.strikes == 3)
            result.solved = true;

        return result;
    }

    int countStrike(const string& guessNumber) {
        int strikeCount = 0;
        for (int i = 0; i < MAX_INPUT_NUM; i++)
        {
            if (CorrectNum[i] == guessNumber[i])
                strikeCount++;
        }
        return strikeCount;
    }

    int countBall(const string& guessNumber) {
        int ballCount = 0;
        for (int i = 0; i < MAX_INPUT_NUM; i++) {
            for (int j = 0; j < MAX_INPUT_NUM; j++) {
                if (i == j) continue;

                if (guessNumber[i] == CorrectNum[j]) {
                    ballCount++;
                    break;
                }
            }
        }
        return ballCount;
    }

    void assertIllegalArgument(const std::string& guessNumber)
    {
        if (guessNumber.length() != 3) {
            throw length_error("Must be three letters");
        }

        for (auto ch : guessNumber) {
            if (ch >= '0' && ch <= '9') continue;

            throw invalid_argument("Must be Number");
        }

        if (isDuplicatedNum(guessNumber))
        {
            throw invalid_argument("Must have not same Number");
        }
    }
    bool isDuplicatedNum(const std::string& guessNumber)
    {
        return guessNumber[0] == guessNumber[1] || guessNumber[0] == guessNumber[2]
            || guessNumber[1] == guessNumber[2];
    }
};