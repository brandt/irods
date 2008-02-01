/*** Copyright (c), The Regents of the University of California            ***
 *** For more information please refer to files in the COPYRIGHT directory ***/

/* miscServerFunct.h - header file for miscServerFunct.c
 */



#ifndef MISC_SERVER_FUNCT_H
#define MISC_SERVER_FUNCT_H

#include <sys/types.h>

#ifndef _WIN32
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#endif

#include "rods.h"
#include "rcConnect.h"
#include "initServer.h"
#include "fileOpen.h"
#include "dataObjInpOut.h"
#include "dataCopy.h"

typedef struct PortalTransferInp {
    rsComm_t *rsComm;
    int destFd;
    int srcFd;
    int destRescTypeInx;
    int srcRescTypeInx;
    int threadNum;
    rodsLong_t size;
    rodsLong_t offset;
    rodsLong_t bytesWritten;
    int flags;
    int status;
    dataOprInp_t *dataOprInp;
} portalTransferInp_t;

int
svrToSvrConnect (rsComm_t *rsComm, rodsServerHost_t *rodsServerHost);
int
svrToSvrConnectNoLogin (rsComm_t *rsComm, rodsServerHost_t *rodsServerHost);
int
createSrvPortal (rsComm_t *rsComm, portList_t *thisPortList);
int
acceptSrvPortal (rsComm_t *rsComm, portList_t *thisPortList);
int
svrPortalPutGet (rsComm_t *rsComm);
void
partialDataPut (portalTransferInp_t *myInput);
void
partialDataGet (portalTransferInp_t *myInput);
int
fillPortalTransferInp (portalTransferInp_t *myInput, rsComm_t *rsComm,
int srcFd, int destFd, int destRescTypeInx, int srcRescTypeInx,
int threadNum, rodsLong_t size, rodsLong_t offset, int flags);
int
sameHostCopy (rsComm_t *rsComm, dataCopyInp_t *dataCopyInp);
void
sameHostPartialCopy (portalTransferInp_t *myInput);
int
remLocCopy (rsComm_t *rsComm, dataCopyInp_t *dataCopyInp);
void
remToLocPartialCopy (portalTransferInp_t *myInput);
void
locToRemPartialCopy (portalTransferInp_t *myInput);
int
isUserPrivileged(rsComm_t *rsComm);
#if !defined(solaris_platform)
char *regcmp (char *pat, char *end);
char *regex (char *rec, char *text, ...);
#endif
int intNoSupport();
rodsLong_t longNoSupport();
#endif	/* MISC_SERVER_FUNCT_H */
