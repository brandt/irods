/*** Copyright (c), The Regents of the University of California            ***
 *** For more information please refer to files in the COPYRIGHT directory ***/
/* fileOpen.h - This file may be generated by a program or script
 */

#ifndef FILE_OPEN_H
#define FILE_OPEN_H

/* This is a low level file type API call */

#include "rods.h"
#include "rcMisc.h"
#include "procApiRequest.h"
#include "apiNumber.h"
#include "initServer.h"

#include "fileDriver.h"

/* definition for otherFlags */

#define CHK_PERM_FLAG		0x1
#define UNIQUE_REM_COMM_FLAG	0x2
#define FORCE_FLAG		0x4

typedef struct {
    fileDriverType_t fileType;
    int otherFlags;	/* for chkPerm, uniqueRemoteConn */
    rodsHostAddr_t addr;
    char fileName[MAX_NAME_LEN];
    int flags;
    int mode;
    rodsLong_t dataSize;
} fileOpenInp_t;
    
#define fileOpenInp_PI "int fileType; int otherFlags; struct RHostAddr_PI; str fileName[MAX_NAME_LEN]; int flags; int mode; double dataSize;"

#if defined(RODS_SERVER)
#define RS_FILE_OPEN rsFileOpen
/* prototype for the server handler */
int
rsFileOpen (rsComm_t *rsComm, fileOpenInp_t *fileOpenInp);
int
rsFileOpenByHost (rsComm_t *rsComm, fileOpenInp_t *fileOpenInp,
rodsServerHost_t *rodsServerHost);
int
_rsFileOpen (rsComm_t *rsComm, fileOpenInp_t *fileOpenInp);
int
remoteFileOpen (rsComm_t *rsComm, fileOpenInp_t *fileOpenInp,
rodsServerHost_t *rodsServerHost);
#else
#define RS_FILE_OPEN NULL
#endif

/* prototype for the client call */
int
rcFileOpen (rcComm_t *conn, fileOpenInp_t *fileOpenInp);

#endif	/* FILE_OPEN_H */
