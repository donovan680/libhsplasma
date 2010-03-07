#ifndef _PNSHA1_H
#define _PNSHA1_H

#include "Util/plString.h"

DllStruct pnSha1Hash {
    unsigned int fData[5];

    void fromString(const plString& src);
    plString toString() const;

    static pnSha1Hash Sha0(const void* src, size_t len);
    static pnSha1Hash Sha1(const void* src, size_t len);
};

DllExport pnSha1Hash NCHashPassword(const plString& userName,
                                    const plString& password);

DllExport pnSha1Hash NCHashLoginInfo(const plString& userName,
                                     const plString& password,
                                     hsUint32 serverChallenge,
                                     hsUint32 clientChallenge);

#endif