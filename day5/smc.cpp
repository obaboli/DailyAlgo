#include <functional>
#include <iostream>
#include <random>

enum STATE { IDLE,
    STUFF_HAPPENS,
    SUCCESS,
    ERROR };

enum STATEOUTPUT { OK,
    TRY_AGAIN,
    FAIL };

struct transitions {
    STATE currentState;
    STATEOUTPUT response;
    STATE nextState;
};

static STATEOUTPUT idleState();
static STATEOUTPUT stuffHappensState();
static STATEOUTPUT successState();
static STATEOUTPUT errorState();

static std::random_device m_rd;
static std::mt19937 m_rng(m_rd());

static uint32_t upper = 5;
static uint8_t retryLogic = 0;
static constexpr uint8_t MAX_RETRY = 5;

class SMC {
public:
    SMC();
    void start();

private:
    STATE nextState(STATE currState, STATEOUTPUT response);

    STATEOUTPUT (*stateFunctions[4])();
    transitions transitionTable[7];
};

SMC::SMC()
    : stateFunctions{ &idleState, &stuffHappensState, &successState, &errorState }
    , transitionTable{ { IDLE, OK, STUFF_HAPPENS },
        { IDLE, FAIL, ERROR },
        { STUFF_HAPPENS, FAIL, ERROR },
        { STUFF_HAPPENS, TRY_AGAIN, STUFF_HAPPENS },
        { STUFF_HAPPENS, OK, SUCCESS },
        { SUCCESS, OK, IDLE },
        { ERROR, OK, IDLE } }
{
}

void SMC::start()
{
    STATE currentState = IDLE;
    STATEOUTPUT rc = FAIL;
    STATEOUTPUT (*currentStateF)(void);

    for (;;) {
        currentStateF = stateFunctions[currentState];
        rc = currentStateF();
        currentState = nextState(currentState, rc);
    }
}

static STATEOUTPUT idleState()
{
    retryLogic = 0;
    return OK;
}

static STATEOUTPUT stuffHappensState()
{
    std::cout << "\n0 -> " << upper << " \n";

    std::uniform_int_distribution<int> randomizer(0, upper);

    int i = 0;
    std::cin >> i;

    if (i != randomizer(m_rng)) {
        if (retryLogic < MAX_RETRY) {
            retryLogic++;
            return TRY_AGAIN;
        } else {
            return FAIL;
        }
    }

    return OK;
}

static STATEOUTPUT successState()
{
    std::cout << "Success\n";

    //bump upper on each success
    upper += 5;
    return OK;
}

static STATEOUTPUT errorState()
{
    upper = 5;
    std::cout << "Sorry you're not good at guessing random numbers\n";
    return OK;
}

STATE SMC::nextState(STATE currState, STATEOUTPUT response)
{
    size_t maxSize = sizeof(transitionTable) / sizeof(transitionTable[0]);
    for (size_t i = 0; i < maxSize; i++) {
        if (transitionTable[i].currentState == currState && transitionTable[i].response == response) {
            return transitionTable[i].nextState;
        }
    }

    return ERROR;
}

int main()
{
    std::cout << "Guess the number bewteen the bounds\n"
              << "You have 5 tries to guess it\n"
              << "-if you're correct upper increase by 5\n"
              << "-otherwise you reset\n";
    SMC randomGame;
    //Much like a scheduler you'll never get past this
    randomGame.start();

    return 0;
}
