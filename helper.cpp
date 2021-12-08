#include "helper.h"

int checkCommand(Trigger* trigger) {
    if (trigger->getCommand() == ""){
        return 0;
    }
    else {
        return 1;
    }
}