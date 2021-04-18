#include "RunAction.h"

bool RunAction::isExtras() {
  return !(runType == RunType::NON_BOUNDARY || runType == RunType::FOUR ||
           runType == RunType::SIX);
}
