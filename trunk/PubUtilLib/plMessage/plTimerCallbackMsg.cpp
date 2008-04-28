#include "plTimerCallbackMsg.h"

plTimerCallbackMsg::plTimerCallbackMsg() : fID(0), fTime(0.0f) { }
plTimerCallbackMsg::~plTimerCallbackMsg() { }

IMPLEMENT_CREATABLE(plTimerCallbackMsg, kTimerCallbackMsg, plMessage)

void plTimerCallbackMsg::read(hsStream* S, plResManager* mgr) {
    plMessage::read(S, mgr);
    fID = S->readInt();
    fTime = S->readFloat();
}

void plTimerCallbackMsg::write(hsStream* S, plResManager* mgr) {
    plMessage::write(S, mgr);
    S->writeInt(fID);
    S->writeFloat(fTime);
}

void plTimerCallbackMsg::IPrcWrite(pfPrcHelper* prc) {
    plMessage::IPrcWrite(prc);

    prc->startTag("TimerCallback");
    prc->writeParam("ID", fID);
    prc->writeParam("Time", fTime);
    prc->endTag(true);
}