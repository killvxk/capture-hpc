/* soapStub.h
   Generated by gSOAP 2.7.10 from captureGSOAP.h
   Copyright(C) 2000-2008, Robert van Engelen, Genivia Inc. All Rights Reserved.
   This part of the software is released under one of the following licenses:
   GPL, the gSOAP public license, or Genivia's license for commercial use.
*/

#ifndef soapStub_H
#define soapStub_H
#include "stdsoap2.h"

/******************************************************************************\
 *                                                                            *
 * Enumerations                                                               *
 *                                                                            *
\******************************************************************************/


/******************************************************************************\
 *                                                                            *
 * Classes and Structs                                                        *
 *                                                                            *
\******************************************************************************/


#if 0 /* volatile type: do not redeclare here */

#endif

#ifndef SOAP_TYPE_ns__regkey
#define SOAP_TYPE_ns__regkey (7)
/* ns:regkey */
struct ns__regkey
{
public:
	char *created_at;	/* optional element of type xsd:string */
	char *event_type;	/* optional element of type xsd:string */
	int pid;	/* required element of type xsd:int */
	char *proc_name;	/* optional element of type xsd:string */
	char *name;	/* optional element of type xsd:string */
	char *value_name;	/* optional element of type xsd:string */
	char *value_type;	/* optional element of type xsd:string */
	char *value;	/* optional element of type xsd:string */
};
#endif

#ifndef SOAP_TYPE_ns__processFile
#define SOAP_TYPE_ns__processFile (8)
/* ns:processFile */
struct ns__processFile
{
public:
	char *created_at;	/* optional element of type xsd:string */
	char *event_type;	/* optional element of type xsd:string */
	int pid;	/* required element of type xsd:int */
	char *proc_name;	/* optional element of type xsd:string */
	char *name;	/* optional element of type xsd:string */
};
#endif

#ifndef SOAP_TYPE_ns__osProcess
#define SOAP_TYPE_ns__osProcess (9)
/* ns:osProcess */
struct ns__osProcess
{
public:
	char *created_at;	/* optional element of type xsd:string */
	char *event_type;	/* optional element of type xsd:string */
	int parent_pid;	/* required element of type xsd:int */
	char *parent_name;	/* optional element of type xsd:string */
	int pid;	/* required element of type xsd:int */
	char *name;	/* optional element of type xsd:string */
};
#endif

#ifndef SOAP_TYPE_ns__dynRegArray
#define SOAP_TYPE_ns__dynRegArray (10)
/* Sequence of ns:dynRegArray schema type: */
struct ns__dynRegArray
{
public:
	struct ns__regkey *__ptr;
	int __size;
};
#endif

#ifndef SOAP_TYPE_ns__dynFileArray
#define SOAP_TYPE_ns__dynFileArray (12)
/* Sequence of ns:dynFileArray schema type: */
struct ns__dynFileArray
{
public:
	struct ns__processFile *__ptr;
	int __size;
};
#endif

#ifndef SOAP_TYPE_ns__dynProcArray
#define SOAP_TYPE_ns__dynProcArray (14)
/* Sequence of ns:dynProcArray schema type: */
struct ns__dynProcArray
{
public:
	struct ns__osProcess *__ptr;
	int __size;
};
#endif

#ifndef SOAP_TYPE_a1
#define SOAP_TYPE_a1 (16)
/* a1 */
struct a1
{
public:
	struct ns__dynRegArray *regkeys;	/* optional element of type ns:dynRegArray */
	struct ns__dynFileArray *process_files;	/* optional element of type ns:dynFileArray */
	struct ns__dynProcArray *os_processes;	/* optional element of type ns:dynProcArray */
};
#endif

#ifndef SOAP_TYPE_s1
#define SOAP_TYPE_s1 (21)
/* s1 */
struct s1
{
public:
	char *data;	/* optional element of type xsd:string */
	unsigned int encodedLength;	/* required element of type xsd:unsignedInt */
	unsigned int decodedLength;	/* required element of type xsd:unsignedInt */
};
#endif

#ifndef SOAP_TYPE_ns__pingResponse
#define SOAP_TYPE_ns__pingResponse (26)
/* ns:pingResponse */
struct ns__pingResponse
{
public:
	char **result;	/* SOAP 1.2 RPC return element (when namespace qualified) */	/* optional element of type xsd:string */
};
#endif

#ifndef SOAP_TYPE_ns__ping
#define SOAP_TYPE_ns__ping (27)
/* ns:ping */
struct ns__ping
{
public:
	char *a;	/* optional element of type xsd:string */
};
#endif

#ifndef SOAP_TYPE_ns__visitURLResponse
#define SOAP_TYPE_ns__visitURLResponse (30)
/* ns:visitURLResponse */
struct ns__visitURLResponse
{
public:
	int result;	/* SOAP 1.2 RPC return element (when namespace qualified) */	/* required element of type xsd:int */
};
#endif

#ifndef SOAP_TYPE_ns__visitURL
#define SOAP_TYPE_ns__visitURL (31)
/* ns:visitURL */
struct ns__visitURL
{
public:
	char *URL;	/* optional element of type xsd:string */
};
#endif

#ifndef SOAP_TYPE_ns__sendFileBase64Response
#define SOAP_TYPE_ns__sendFileBase64Response (33)
/* ns:sendFileBase64Response */
struct ns__sendFileBase64Response
{
public:
	int result;	/* SOAP 1.2 RPC return element (when namespace qualified) */	/* required element of type xsd:int */
};
#endif

#ifndef SOAP_TYPE_ns__sendFileBase64
#define SOAP_TYPE_ns__sendFileBase64 (34)
/* ns:sendFileBase64 */
struct ns__sendFileBase64
{
public:
	char *fileName;	/* optional element of type xsd:string */
	char *data;	/* optional element of type xsd:string */
	unsigned int encodedLength;	/* required element of type xsd:unsignedInt */
	unsigned int decodedLength;	/* required element of type xsd:unsignedInt */
};
#endif

#ifndef SOAP_TYPE_ns__receiveFileBase64Response
#define SOAP_TYPE_ns__receiveFileBase64Response (38)
/* ns:receiveFileBase64Response */
struct ns__receiveFileBase64Response
{
public:
	struct s1 **result;	/* SOAP 1.2 RPC return element (when namespace qualified) */	/* optional element of type ns:receiveFileStruct */
};
#endif

#ifndef SOAP_TYPE_ns__receiveFileBase64
#define SOAP_TYPE_ns__receiveFileBase64 (39)
/* ns:receiveFileBase64 */
struct ns__receiveFileBase64
{
public:
	char *fileName;	/* optional element of type xsd:string */
};
#endif

#ifndef SOAP_TYPE_ns__openDocumentResponse
#define SOAP_TYPE_ns__openDocumentResponse (41)
/* ns:openDocumentResponse */
struct ns__openDocumentResponse
{
public:
	int result;	/* SOAP 1.2 RPC return element (when namespace qualified) */	/* required element of type xsd:int */
};
#endif

#ifndef SOAP_TYPE_ns__openDocument
#define SOAP_TYPE_ns__openDocument (42)
/* ns:openDocument */
struct ns__openDocument
{
public:
	char *fileName;	/* optional element of type xsd:string */
	int waitTimeMillisec;	/* required element of type xsd:int */
};
#endif

#ifndef SOAP_TYPE_ns__returnRegistryEventsResponse
#define SOAP_TYPE_ns__returnRegistryEventsResponse (45)
/* ns:returnRegistryEventsResponse */
struct ns__returnRegistryEventsResponse
{
public:
	struct ns__dynRegArray **result;	/* SOAP 1.2 RPC return element (when namespace qualified) */	/* optional element of type ns:dynRegArray */
};
#endif

#ifndef SOAP_TYPE_ns__returnRegistryEvents
#define SOAP_TYPE_ns__returnRegistryEvents (46)
/* ns:returnRegistryEvents */
struct ns__returnRegistryEvents
{
public:
	int maxEventsToReturn;	/* required element of type xsd:int */
};
#endif

#ifndef SOAP_TYPE_ns__returnFileEventsResponse
#define SOAP_TYPE_ns__returnFileEventsResponse (49)
/* ns:returnFileEventsResponse */
struct ns__returnFileEventsResponse
{
public:
	struct ns__dynFileArray **result;	/* SOAP 1.2 RPC return element (when namespace qualified) */	/* optional element of type ns:dynFileArray */
};
#endif

#ifndef SOAP_TYPE_ns__returnFileEvents
#define SOAP_TYPE_ns__returnFileEvents (50)
/* ns:returnFileEvents */
struct ns__returnFileEvents
{
public:
	int maxEventsToReturn;	/* required element of type xsd:int */
};
#endif

#ifndef SOAP_TYPE_ns__returnProcessEventsResponse
#define SOAP_TYPE_ns__returnProcessEventsResponse (53)
/* ns:returnProcessEventsResponse */
struct ns__returnProcessEventsResponse
{
public:
	struct ns__dynProcArray **result;	/* SOAP 1.2 RPC return element (when namespace qualified) */	/* optional element of type ns:dynProcArray */
};
#endif

#ifndef SOAP_TYPE_ns__returnProcessEvents
#define SOAP_TYPE_ns__returnProcessEvents (54)
/* ns:returnProcessEvents */
struct ns__returnProcessEvents
{
public:
	int maxEventsToReturn;	/* required element of type xsd:int */
};
#endif

#ifndef SOAP_TYPE_ns__returnEventsResponse
#define SOAP_TYPE_ns__returnEventsResponse (58)
/* ns:returnEventsResponse */
struct ns__returnEventsResponse
{
public:
	struct a1 **result;	/* SOAP 1.2 RPC return element (when namespace qualified) */	/* optional element of type ns:allEvents */
};
#endif

#ifndef SOAP_TYPE_ns__returnEvents
#define SOAP_TYPE_ns__returnEvents (59)
/* ns:returnEvents */
struct ns__returnEvents
{
public:
	int maxEventsToReturn;	/* required element of type xsd:int */
};
#endif

#ifndef SOAP_TYPE_ns__sendMIMEResponse
#define SOAP_TYPE_ns__sendMIMEResponse (61)
/* ns:sendMIMEResponse */
struct ns__sendMIMEResponse
{
public:
	int result;	/* SOAP 1.2 RPC return element (when namespace qualified) */	/* required element of type xsd:int */
};
#endif

#ifndef SOAP_TYPE_ns__sendMIME
#define SOAP_TYPE_ns__sendMIME (62)
/* ns:sendMIME */
struct ns__sendMIME
{
public:
	int magicNumber;	/* required element of type xsd:int */
};
#endif

#ifndef SOAP_TYPE_SOAP_ENV__Header
#define SOAP_TYPE_SOAP_ENV__Header (63)
/* SOAP Header: */
struct SOAP_ENV__Header
{
#ifdef WITH_NOEMPTYSTRUCT
private:
	char dummy;	/* dummy member to enable compilation */
#endif
};
#endif

#ifndef SOAP_TYPE_SOAP_ENV__Code
#define SOAP_TYPE_SOAP_ENV__Code (64)
/* SOAP Fault Code: */
struct SOAP_ENV__Code
{
public:
	char *SOAP_ENV__Value;	/* optional element of type xsd:QName */
	struct SOAP_ENV__Code *SOAP_ENV__Subcode;	/* optional element of type SOAP-ENV:Code */
};
#endif

#ifndef SOAP_TYPE_SOAP_ENV__Detail
#define SOAP_TYPE_SOAP_ENV__Detail (66)
/* SOAP-ENV:Detail */
struct SOAP_ENV__Detail
{
public:
	int __type;	/* any type of element <fault> (defined below) */
	void *fault;	/* transient */
	char *__any;
};
#endif

#ifndef SOAP_TYPE_SOAP_ENV__Reason
#define SOAP_TYPE_SOAP_ENV__Reason (69)
/* SOAP-ENV:Reason */
struct SOAP_ENV__Reason
{
public:
	char *SOAP_ENV__Text;	/* optional element of type xsd:string */
};
#endif

#ifndef SOAP_TYPE_SOAP_ENV__Fault
#define SOAP_TYPE_SOAP_ENV__Fault (70)
/* SOAP Fault: */
struct SOAP_ENV__Fault
{
public:
	char *faultcode;	/* optional element of type xsd:QName */
	char *faultstring;	/* optional element of type xsd:string */
	char *faultactor;	/* optional element of type xsd:string */
	struct SOAP_ENV__Detail *detail;	/* optional element of type SOAP-ENV:Detail */
	struct SOAP_ENV__Code *SOAP_ENV__Code;	/* optional element of type SOAP-ENV:Code */
	struct SOAP_ENV__Reason *SOAP_ENV__Reason;	/* optional element of type SOAP-ENV:Reason */
	char *SOAP_ENV__Node;	/* optional element of type xsd:string */
	char *SOAP_ENV__Role;	/* optional element of type xsd:string */
	struct SOAP_ENV__Detail *SOAP_ENV__Detail;	/* optional element of type SOAP-ENV:Detail */
};
#endif

/******************************************************************************\
 *                                                                            *
 * Types with Custom Serializers                                              *
 *                                                                            *
\******************************************************************************/


/******************************************************************************\
 *                                                                            *
 * Typedefs                                                                   *
 *                                                                            *
\******************************************************************************/

#ifndef SOAP_TYPE__QName
#define SOAP_TYPE__QName (5)
typedef char *_QName;
#endif

#ifndef SOAP_TYPE__XML
#define SOAP_TYPE__XML (6)
typedef char *_XML;
#endif

#ifndef SOAP_TYPE_ns__allEvents
#define SOAP_TYPE_ns__allEvents (20)
typedef struct a1 ns__allEvents;
#endif

#ifndef SOAP_TYPE_ns__receiveFileStruct
#define SOAP_TYPE_ns__receiveFileStruct (23)
typedef struct s1 ns__receiveFileStruct;
#endif


/******************************************************************************\
 *                                                                            *
 * Typedef Synonyms                                                           *
 *                                                                            *
\******************************************************************************/


/******************************************************************************\
 *                                                                            *
 * Externals                                                                  *
 *                                                                            *
\******************************************************************************/


/******************************************************************************\
 *                                                                            *
 * Service Operations                                                         *
 *                                                                            *
\******************************************************************************/


SOAP_FMAC5 int SOAP_FMAC6 ns__ping(struct soap*, char *a, char **result);

SOAP_FMAC5 int SOAP_FMAC6 ns__visitURL(struct soap*, char *URL, int &result);

SOAP_FMAC5 int SOAP_FMAC6 ns__sendFileBase64(struct soap*, char *fileName, char *data, unsigned int encodedLength, unsigned int decodedLength, int &result);

SOAP_FMAC5 int SOAP_FMAC6 ns__receiveFileBase64(struct soap*, char *fileName, struct s1 **result);

SOAP_FMAC5 int SOAP_FMAC6 ns__openDocument(struct soap*, char *fileName, int waitTimeMillisec, int &result);

SOAP_FMAC5 int SOAP_FMAC6 ns__returnRegistryEvents(struct soap*, int maxEventsToReturn, struct ns__dynRegArray **result);

SOAP_FMAC5 int SOAP_FMAC6 ns__returnFileEvents(struct soap*, int maxEventsToReturn, struct ns__dynFileArray **result);

SOAP_FMAC5 int SOAP_FMAC6 ns__returnProcessEvents(struct soap*, int maxEventsToReturn, struct ns__dynProcArray **result);

SOAP_FMAC5 int SOAP_FMAC6 ns__returnEvents(struct soap*, int maxEventsToReturn, struct a1 **result);

SOAP_FMAC5 int SOAP_FMAC6 ns__sendMIME(struct soap*, int magicNumber, int &result);

/******************************************************************************\
 *                                                                            *
 * Stubs                                                                      *
 *                                                                            *
\******************************************************************************/


SOAP_FMAC5 int SOAP_FMAC6 soap_call_ns__ping(struct soap *soap, const char *soap_endpoint, const char *soap_action, char *a, char **result);

SOAP_FMAC5 int SOAP_FMAC6 soap_call_ns__visitURL(struct soap *soap, const char *soap_endpoint, const char *soap_action, char *URL, int &result);

SOAP_FMAC5 int SOAP_FMAC6 soap_call_ns__sendFileBase64(struct soap *soap, const char *soap_endpoint, const char *soap_action, char *fileName, char *data, unsigned int encodedLength, unsigned int decodedLength, int &result);

SOAP_FMAC5 int SOAP_FMAC6 soap_call_ns__receiveFileBase64(struct soap *soap, const char *soap_endpoint, const char *soap_action, char *fileName, struct s1 **result);

SOAP_FMAC5 int SOAP_FMAC6 soap_call_ns__openDocument(struct soap *soap, const char *soap_endpoint, const char *soap_action, char *fileName, int waitTimeMillisec, int &result);

SOAP_FMAC5 int SOAP_FMAC6 soap_call_ns__returnRegistryEvents(struct soap *soap, const char *soap_endpoint, const char *soap_action, int maxEventsToReturn, struct ns__dynRegArray **result);

SOAP_FMAC5 int SOAP_FMAC6 soap_call_ns__returnFileEvents(struct soap *soap, const char *soap_endpoint, const char *soap_action, int maxEventsToReturn, struct ns__dynFileArray **result);

SOAP_FMAC5 int SOAP_FMAC6 soap_call_ns__returnProcessEvents(struct soap *soap, const char *soap_endpoint, const char *soap_action, int maxEventsToReturn, struct ns__dynProcArray **result);

SOAP_FMAC5 int SOAP_FMAC6 soap_call_ns__returnEvents(struct soap *soap, const char *soap_endpoint, const char *soap_action, int maxEventsToReturn, struct a1 **result);

SOAP_FMAC5 int SOAP_FMAC6 soap_call_ns__sendMIME(struct soap *soap, const char *soap_endpoint, const char *soap_action, int magicNumber, int &result);

/******************************************************************************\
 *                                                                            *
 * Skeletons                                                                  *
 *                                                                            *
\******************************************************************************/

SOAP_FMAC5 int SOAP_FMAC6 soap_serve(struct soap*);

SOAP_FMAC5 int SOAP_FMAC6 soap_serve_request(struct soap*);

SOAP_FMAC5 int SOAP_FMAC6 soap_serve_ns__ping(struct soap*);

SOAP_FMAC5 int SOAP_FMAC6 soap_serve_ns__visitURL(struct soap*);

SOAP_FMAC5 int SOAP_FMAC6 soap_serve_ns__sendFileBase64(struct soap*);

SOAP_FMAC5 int SOAP_FMAC6 soap_serve_ns__receiveFileBase64(struct soap*);

SOAP_FMAC5 int SOAP_FMAC6 soap_serve_ns__openDocument(struct soap*);

SOAP_FMAC5 int SOAP_FMAC6 soap_serve_ns__returnRegistryEvents(struct soap*);

SOAP_FMAC5 int SOAP_FMAC6 soap_serve_ns__returnFileEvents(struct soap*);

SOAP_FMAC5 int SOAP_FMAC6 soap_serve_ns__returnProcessEvents(struct soap*);

SOAP_FMAC5 int SOAP_FMAC6 soap_serve_ns__returnEvents(struct soap*);

SOAP_FMAC5 int SOAP_FMAC6 soap_serve_ns__sendMIME(struct soap*);

#endif

/* End of soapStub.h */
