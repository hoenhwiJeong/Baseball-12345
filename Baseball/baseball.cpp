#include <string>
#include <stdexcept>
using namespace std;


struct GuessResult {
    bool solved;
    int strikes;
    int balls;
};

class Baseball {
public:
    explicit Baseball(const string& qeustion)
        : question{ qeustion } {}

    GuessResult guess(const string& guessNumber){
        assertIllegalArgument(guessNumber);
        if (guessNumber == question)
            return { true, 3, 0 };

        return { false, 0,0 };
    }
private:
    string question;

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