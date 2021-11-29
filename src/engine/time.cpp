#include <chrono>
#include "include/engine/time.h"

using namespace std;
using namespace chrono;

long int Catcher::Survivor::timeSinceEpoch()
{
    system_clock::time_point now = system_clock::now();
    return duration_cast<milliseconds>(now.time_since_epoch()).count();
}
